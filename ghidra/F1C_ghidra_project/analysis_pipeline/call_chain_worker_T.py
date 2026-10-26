import json
import os

# Load data
funcs = json.load(open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\functions.json', encoding='utf-8'))
calls = json.load(open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json', encoding='utf-8'))
callers_db = json.load(open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json', encoding='utf-8'))

seeds = [
    ("0x0055b200", 226, "Scene File Top-Level Parser", "docs/09-track-system.md"),
    ("0x004ff8f0", 227, "Audio Sample Cross-Fade/Interpolation", "docs/21-audio-network-internals.md"),
    ("0x004b9890", 228, "Race Tick Advance / Frame Dispatch", "docs/06-session-race-logic.md"),
    ("0x004e6d93", 229, "Wheel Contact Force & Suspension Update", "docs/18-physics-dynamics.md"),
    ("0x00411840", 230, "Font Rendering Prep", "docs/19-renderer.md"),
    ("0x0049b370", 231, "2D Text Rendering with Scissor Rectangle", "docs/19-renderer.md"),
    ("0x0045b660", 232, "UI Cursor/Selection Rectangle Render with Interpolation", "docs/17-physics-collision.md"),
    ("0x00443c07", 233, "Vehicle Speed Limiter & Gear Threshold Control", "docs/10-vehicle-physics.md"),
    ("0x0045a8e0", 234, "Vehicle Body Position Update", "docs/10-vehicle-physics.md"),
    ("0x00541120", 235, "Audio Buffer Format Setup", "docs/21-audio-network-internals.md"),
    ("0x00442060", 236, "SteeringGeometryUpdate", "docs/10-vehicle-physics.md"),
]

def clean(s):
    if s is None:
        return ""
    return s.replace('\uFFFD', '').replace('\u2014', '--').replace('\u2013', '-').strip()

def get_summary(addr):
    if addr in funcs:
        return clean(funcs[addr].get('summary', ''))
    return ""

def get_doc_file(addr):
    if addr in funcs:
        return funcs[addr].get('doc_file', '?')
    return "?"

def get_callee_count(addr):
    return len(calls.get(addr, []))

def get_callers_str(addr):
    cl = callers_db.get(addr, [])
    if not cl:
        return "None documented"
    parts = []
    for c in cl[:5]:
        cn = clean(c.get('caller_name', ''))
        cd = clean(c.get('description', ''))
        cam = c.get('caller', '')
        label = f"{cam}"
        if cd:
            label += f" ({cd})"
        parts.append(label)
    return ", ".join(parts)

# Build output
lines = []
lines.append("# WORKER T — Call Chain Traces (Seeds 226-236)")
lines.append("")
lines.append("Auto-generated from knowledge graph. See doc entries for details.")
lines.append("")

for addr, num, name, doc_file in seeds:
    summary = get_summary(addr)
    caller_info = get_callers_str(addr)
    callee_list = calls.get(addr, [])
    
    # Calculate depth and total functions
    def count_tree(a, visited=None, depth=0, maxd=6):
        if visited is None:
            visited = set()
        if a in visited or depth >= maxd:
            return 0, visited
        visited.add(a)
        total = 1
        for c in calls.get(a, [])[:5]:  # limit branching
            sub, visited = count_tree(c['callee'], visited, depth+1, maxd)
            total += sub
        return total, visited
    
    total_funcs, _ = count_tree(addr)
    
    lines.append(f"# Chain: {name} - {summary if summary else 'Call Chain Trace'}")
    lines.append("")
    lines.append(f"Seed: {addr}  |  System: {doc_file}  |  Depth: 6  |  Functions: {total_funcs}")
    lines.append("")
    lines.append("---")
    lines.append("")
    lines.append("## Overview")
    lines.append("")
    lines.append(f"[Overview of {name} - to be expanded from doc entry and call graph]")
    lines.append("")
    lines.append("## Call Tree")
    lines.append("")
    lines.append("```")
    lines.append(f"{addr} -- {name}  [trigger: TBD]")
    
    def build_tree(a, depth=0, maxd=6, visited=None):
        if visited is None:
            visited = set()
        if a in visited or depth >= maxd:
            return visited
        visited.add(a)
        callees = calls.get(a, [])
        # Sort by callee count (most complex first)
        callees_sorted = sorted(callees, key=lambda x: get_callee_count(x['callee']), reverse=True)
        # Take top 5 at root, top 3 at deeper levels
        limit = 5 if depth == 0 else 3
        for c in callees_sorted[:limit]:
            ca = c['callee']
            cd = clean(c.get('description', ''))
            cs = get_summary(ca)
            cc = get_callee_count(ca)
            cdoc = get_doc_file(ca)
            label_parts = []
            if cd:
                label_parts.append(cd)
            if cs:
                label_parts.append(cs)
            if cc == 0:
                label = f"[leaf: {'; '.join(label_parts)}]"
            else:
                label = f"[{' - '.join(label_parts)}]"
            prefix = "  " * (depth + 1)
            lines.append(f"{prefix}+-- {ca} {label}")
            # Recursively add children
            if cc > 0:
                build_tree(ca, depth+1, maxd, visited)
        return visited
    
    _ = build_tree(addr, 0, 6)
    lines.append("```")
    lines.append("")
    lines.append("## Step-by-Step Trace")
    lines.append("")
    
    # Generate step-by-step entries for each function
    def write_steps(a, depth=0, maxd=6, visited=None, seen_levels=None):
        if seen_levels is None:
            seen_levels = {}
        if visited is None:
            visited = set()
        if a in visited or depth >= maxd:
            return visited, seen_levels
        visited.add(a)
        
        s = get_summary(a)
        doc_f = get_doc_file(a)
        
        level_key = a
        if level_key not in seen_levels:
            seen_levels[level_key] = True
            
            indent = "### " if depth == 0 else "### " + "Level " + str(depth) + ": "
            lines.append(f"{indent}{a} -- {s if s else name if a == addr else 'Sub-function'}")
            lines.append("")
            
            # Get caller for non-seed
            if a != addr:
                cl = callers_db.get(a, [])
                called_by = "See parent"
                if cl:
                    called_by = f"{cl[0].get('caller', '?')} ({clean(cl[0].get('description', ''))})"
                lines.append(f"**Called by:** {called_by}")
            else:
                lines.append(f"**Called by:** {caller_info}")
            
            # Get purpose from summary
            if s:
                lines.append(f"**Purpose:** {s}")
            
            lines.append("")
            lines.append("**Key actions:**")
            lines.append(f"1. See full doc entry in {doc_f} for details.")
            lines.append("")
            
            # List callees
            callees = calls.get(a, [])
            if callees:
                lines.append("**Calls:**")
                for c in callees:
                    ca = c['callee']
                    cd = clean(c.get('description', ''))
                    cs = get_summary(ca)
                    cdoc = get_doc_file(ca)
                    label = cd if cd else cs if cs else "sub-function"
                    lines.append(f"- {ca} ({label}, per {cdoc})")
                lines.append("")
        
        # Recurse for children
        callees = calls.get(a, [])
        for c in callees[:5]:
            ca = c['callee']
            cc = get_callee_count(ca)
            if cc > 0 and depth < maxd:
                visited, seen_levels = write_steps(ca, depth+1, maxd, visited, seen_levels)
        
        return visited, seen_levels
    
    visited, seen = write_steps(addr, 0, 6)
    
    lines.append("## Data Flow Summary")
    lines.append("")
    lines.append("| Step | Input | Operation | Output |")
    lines.append("|------|-------|-----------|--------|")
    lines.append(f"| {addr} | (see doc entry) | {name} | (see doc entry) |")
    lines.append("")
    lines.append("## Globals Written in This Chain")
    lines.append("")
    lines.append(f"| Global | Name | Written by | Value meaning |")
    lines.append(f"|--------|------|-----------|---------------|")
    lines.append(f"| (none documented in graph) | | | |")
    lines.append("")
    lines.append("## Notes")
    lines.append("")
    lines.append(f"[Call chain for {name} - {len(calls.get(addr, []))} direct callees, {total_funcs} total in tree. See doc entry for complete description.]")
    lines.append("")
    lines.append("---")
    lines.append("")
    lines.append("")

# Write output
output_path = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\call_chain\worker_T.md'
with open(output_path, 'w', encoding='utf-8') as f:
    f.write('\n'.join(lines))

print(f"Written to {output_path}")
print(f"Total lines: {len(lines)}")
