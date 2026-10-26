#!/usr/bin/env python3
"""Extract all ## FUN_ sections after line 960 from 01-engine-architecture.md"""

import re
import json
from collections import defaultdict, OrderedDict

FILE_PATH = r"%USERPROFILE%\Desktop\F1C_ghidra_project\docs\01-engine-architecture.md"

with open(FILE_PATH, "r", encoding="utf-8") as f:
    lines = f.readlines()

# Parse sections
sections = []
current = None
in_key_logic = False
key_logic_lines = []

def flush_current():
    global current, in_key_logic, key_logic_lines
    if current is not None:
        # Only set key_logic_summary from key_logic_lines if we have content
        if key_logic_lines:
            current["key_logic_summary"] = " ".join(key_logic_lines).strip()
        sections.append(current)
    current = None
    in_key_logic = False
    key_logic_lines = []

for i, line in enumerate(lines):
    stripped = line.rstrip()
    line_num = i + 1
    
    # Check for ## FUN_ or ## Unwind_ (non-standard)
    fun_match = re.match(r'^## (FUN_[0-9a-fA-F]+)\s', stripped)
    unwind_match = re.match(r'^## (Unwind_[0-9a-fA-F]+)\s', stripped)
    thunk_match = re.match(r'^## (thunk_FUN_[0-9a-fA-F]+)\s', stripped)
    
    if fun_match or unwind_match or thunk_match:
        flush_current()
        m = fun_match or unwind_match or thunk_match
        addr = m.group(1)
        # Extract description after the em dash or separator
        rest = stripped[m.end():].strip()
        # Remove leading em dash / bullet chars
        desc = re.sub(r'^[—–\-�?\s]+', '', rest).strip()
        
        current = {
            "line": line_num,
            "address": addr,
            "description": desc,
            "key_logic_raw": [],
            "key_logic_summary": "",
            "globals": [],
            "target": "",
            "calls": "",
            "moddability": "",
            "source": ""
        }
        continue
    
    if current is None:
        continue
    
    # Capture Source line
    src_match = re.match(r'^Source:\s*(.*)', stripped)
    if src_match and not current["source"]:
        current["source"] = src_match.group(1).strip()
    
    # Detect Key logic section start
    if stripped.startswith("**Key logic:**") or stripped.startswith("**Key logic**"):
        in_key_logic = True
        key_logic_lines = []
        continue
    
    if in_key_logic:
        # Check if we exited key logic (next bold header or globals/calls/moddability)
        if stripped.startswith("**Globals:**") or stripped.startswith("**Calls:**") or stripped.startswith("**Moddability:") or stripped.startswith("**Struct offsets") or stripped.startswith("**Used by"):
            in_key_logic = False
            # Don't save here — flush_current will do it
        else:
            # Clean the line
            cleaned = stripped.lstrip('- ').strip()
            if cleaned:
                key_logic_lines.append(cleaned)
    
    # Capture Globals
    if stripped.startswith("**Globals:**"):
        # Read next lines until next bold header
        j = i + 1
        while j < len(lines):
            gline = lines[j].rstrip()
            if gline.startswith("**") or gline.startswith("<!--") or gline.startswith("## "):
                break
            gmatch = re.match(r'^[-*]\s*`(DAT_[0-9a-fA-F]+)`', gline)
            if gmatch:
                current["globals"].append(gmatch.group(1))
            else:
                gmatch2 = re.match(r'^[-*]\s*`([^`]+)`', gline)
                if gmatch2:
                    current["globals"].append(gmatch2.group(1))
            j += 1
    
    # Capture target
    tgt_match = re.match(r'^<!-- target:\s*(.*)\s*-->', stripped)
    if tgt_match:
        current["target"] = tgt_match.group(1).strip()
    
    # Capture Calls
    if stripped.startswith("**Calls:**"):
        calls_text = stripped[len("**Calls:**"):].strip()
        # Also read continuation lines
        j = i + 1
        while j < len(lines):
            cline = lines[j].rstrip()
            if cline.startswith("**") or cline.startswith("<!--") or cline.startswith("## "):
                break
            if cline.strip():
                calls_text += " " + cline.strip()
            j += 1
        current["calls"] = calls_text
    
    # Capture Moddability
    if stripped.startswith("**Moddability:**"):
        mod_val = stripped[len("**Moddability:**"):].strip()
        current["moddability"] = mod_val

flush_current()

# Filter sections after line 960
after_960 = [s for s in sections if s["line"] > 960]

print(f"Total ## FUN_ sections (incl Unwind_/thunk_): {len(sections)}")
print(f"Sections after line 960: {len(after_960)}")

# Group by target doc
by_target = defaultdict(list)
for s in after_960:
    tgt = s["target"] if s["target"] else "no-target"
    by_target[tgt].append(s)

print("\n=== DISTRIBUTION BY TARGET DOC ===")
for tgt, entries in sorted(by_target.items(), key=lambda x: -len(x[1])):
    print(f"  {tgt}: {len(entries)} entries")

# Group by subsystem category (based on description keywords)
categories = defaultdict(list)
for s in after_960:
    desc_lower = s["description"].lower()
    addr_parts = s["address"].split("_")
    addr_str = addr_parts[-1] if len(addr_parts) > 1 else addr_parts[0]
    addr_int = int(addr_str, 16) if addr_str else 0
    
    # Categorize
    cat = "unknown"
    desc_lower = s["description"].lower() + " " + s["address"].lower()
    if any(kw in desc_lower for kw in ["seh unwind", "exception", "unwind handler", "cleanup"]):
        cat = "seh_exception_handling"
    elif any(kw in desc_lower for kw in ["mutex", "critical section", "semaphore", "thread", "lock", "tls"]):
        cat = "threading_synchronization"
    elif any(kw in desc_lower for kw in ["linked list", "list node", "list destruction", "list traversal"]):
        cat = "linked_list_operations"
    elif any(kw in desc_lower for kw in ["vtable", "virtual dispatch", "virtual function", "virtual call"]):
        cat = "vtable_dispatch"
    elif any(kw in desc_lower for kw in ["free", "alloc", "malloc", "cleanup", "destructor", "destroy", "dealloc"]):
        cat = "memory_cleanup"
    elif any(kw in desc_lower for kw in ["buffer", "memcpy", "memory copy", "copy", "zero-init", "zero fill"]):
        cat = "memory_operations"
    elif any(kw in desc_lower for kw in ["function call wrapper", "call wrapper", "wrapper", "pass-through"]):
        cat = "call_wrappers"
    elif any(kw in desc_lower for kw in ["timer", "queryperformancecounter", "qpc", "performance counter"]):
        cat = "timing_performance"
    elif any(kw in desc_lower for kw in ["callback", "registration", "register"]):
        cat = "callback_registration"
    elif any(kw in desc_lower for kw in ["string", "strcmp", "strdup"]):
        cat = "string_operations"
    elif any(kw in desc_lower for kw in ["render", "bitmap", "scene", "camera"]):
        cat = "rendering_camera"
    elif any(kw in desc_lower for kw in ["input", "mouse", "keyboard", "joystick"]):
        cat = "input_handling"
    elif any(kw in desc_lower for kw in ["sound", "audio"]):
        cat = "audio"
    elif any(kw in desc_lower for kw in ["network", "socket", "netcomm", "dispatch"]):
        cat = "network"
    elif any(kw in desc_lower for kw in ["game state", "state machine", "session", "race mode", "game loop"]):
        cat = "game_state_machine"
    elif any(kw in desc_lower for kw in ["file", "path", "config", "directory"]):
        cat = "file_config"
    elif any(kw in desc_lower for kw in ["sort", "search", "lookup", "find"]):
        cat = "algorithms_sorting_search"
    elif any(kw in desc_lower for kw in ["setter", "getter", "field set", "flag set"]):
        cat = "field_accessors"
    elif any(kw in desc_lower for kw in ["flag", "state field", "state flag"]):
        cat = "state_flags"
    elif any(kw in desc_lower for kw in ["ui", "screen", "menu", "onscreen"]):
        cat = "ui_rendering"
    elif any(kw in desc_lower for kw in ["math", "float", "threshold", "mapper", "sin", "cos"]):
        cat = "math_utilities"
    elif any(kw in desc_lower for kw in ["physics", "dynamics", "vehicle", "collision"]):
        cat = "physics_dynamics"
    elif any(kw in desc_lower for kw in ["constructor", "object init", "object copy"]):
        cat = "object_lifecycle"
    elif any(kw in desc_lower for kw in ["dispatch", "command dispatch"]) and "unwind" not in desc_lower:
        cat = "dispatch_routing"
    elif any(kw in desc_lower for kw in ["handle", "closehandle"]):
        cat = "handle_management"
    
    categories[cat].append(s)

print("\n=== DISTRIBUTION BY SUBSYSTEM CATEGORY ===")
for cat, entries in sorted(categories.items(), key=lambda x: -len(x[1])):
    print(f"  {cat}: {len(entries)} entries")
    # Show first 3 as sample
    for e in entries[:3]:
        print(f"    {e['address']} — {e['description'][:60]}")
    if len(entries) > 3:
        print(f"    ... and {len(entries)-3} more")

# Now output full structured data as JSON for the user
print("\n\n=== FULL STRUCTURED DATA (JSON) ===")
output = {
    "file": "01-engine-architecture.md",
    "total_fun_sections": len(sections),
    "total_after_line_960": len(after_960),
    "by_target_doc": {tgt: len(entries) for tgt, entries in sorted(by_target.items(), key=lambda x: -len(x[1]))},
    "by_category": {cat: len(entries) for cat, entries in sorted(categories.items(), key=lambda x: -len(x[1]))},
    "entries": after_960
}

# Output as JSON (but we'll also create a markdown summary)
with open(r"%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\_extracted_fun_data.json", "w", encoding="utf-8") as f:
    json.dump(output, f, indent=2, ensure_ascii=False)

print(f"\nJSON written to _extracted_fun_data.json")

# Create a markdown summary grouped by target doc with all details
md_lines = []
md_lines.append("# Structured Breakdown of 01-engine-architecture.md ## FUN_ Entries (After Line 960)")
md_lines.append(f"\n**Total ## FUN_ sections in file:** {len(sections)}")
md_lines.append(f"**Total after line 960:** {len(after_960)}")
md_lines.append(f"\n## Distribution by Target Doc")
for tgt, entries in sorted(by_target.items(), key=lambda x: -len(x[1])):
    md_lines.append(f"\n### {tgt} ({len(entries)} entries)")
    for e in entries:
        md_lines.append(f"\n#### {e['address']} — {e['description']}")
        if e["source"]:
            md_lines.append(f"- **Source:** {e['source']}")
        md_lines.append(f"- **Key Logic:** {e['key_logic_summary'][:200]}{'...' if len(e['key_logic_summary']) > 200 else ''}")
        if e["globals"]:
            md_lines.append(f"- **Globals:** {', '.join(e['globals'])}")
        if e["calls"]:
            md_lines.append(f"- **Calls:** {e['calls'][:150]}{'...' if len(e['calls']) > 150 else ''}")
        if e["moddability"]:
            md_lines.append(f"- **Moddability:** {e['moddability']}")
        md_lines.append(f"- **Target:** {e['target']}")

md_lines.append(f"\n## Distribution by Subsystem Category")
for cat, entries in sorted(categories.items(), key=lambda x: -len(x[1])):
    md_lines.append(f"\n### {cat} ({len(entries)} entries)")
    md_lines.append(f"| Address | Name | Key Logic | Globals | Target |")
    md_lines.append(f"|---------|------|-----------|---------|--------|")
    for e in entries:
        logic_short = e['key_logic_summary'][:100].replace('|', '/')
        globs = ', '.join(e['globals'][:3]) if e['globals'] else '—'
        md_lines.append(f"| {e['address']} | {e['description'][:60]} | {logic_short} | {globs} | {e['target']} |")

with open(r"%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\_fun_breakdown_report.md", "w", encoding="utf-8") as f:
    f.write("\n".join(md_lines))

print("Markdown report written to _fun_breakdown_report.md")

# Also generate a compact table by category for the user to use in implementation spec
print("\n\n=== COMPACT TABLE BY CATEGORY ===")
for cat, entries in sorted(categories.items(), key=lambda x: -len(x[1])):
    print(f"\n{'='*80}")
    print(f"CATEGORY: {cat} ({len(entries)} functions)")
    print(f"{'='*80}")
    for e in entries:
        logic_first = e['key_logic_summary'][:120].replace('\n', ' ')
        globs_str = ', '.join(e['globals'][:5]) if e['globals'] else '—'
        print(f"  {e['address']} | {e['description'][:70]}")
        print(f"    Logic: {logic_first}")
        print(f"    Globals: {globs_str} | Target: {e['target']} | Mod: {e['moddability']}")
        print()
