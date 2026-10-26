#!/usr/bin/env python3
"""Group struct offset observations from 20-math-utilities.md into consolidated struct definitions."""
import json, re
from collections import defaultdict

with open("%USERPROFILE%\\Desktop\\F1C_ghidra_project\\analysis_pipeline\\output\\struct_synth\\extracted_offsets_20.json", "r") as f:
    observations = json.load(f)

def parse_offset_hex(ohex):
    """Extract numeric value from offset hex string."""
    cleaned = ohex.replace("\u2013", "-").replace("\u2014", "-").replace("+0x", "").replace(" ", "")
    # Take first offset in range
    parts = re.split(r'[-/]', cleaned)
    try:
        return int(parts[0], 16)
    except:
        return 999999

def get_qualifier_category(qual):
    """Categorize the qualifier into a struct type."""
    q = qual.strip().lower()
    if "list" in q and ("contain" in q or "head" in q or "control" in q or "node" in q):
        return "linked_list"
    if "buffer" in q:
        return "buffer"
    if "timer" in q:
        return "timer"
    if "array" in q:
        return "array_container"
    if "ring" in q:
        return "ring_buffer"
    if "stream" in q:
        return "stream"
    if "string" in q:
        return "string_object"
    if "file" in q or "file" in q:
        return "file_handle"
    if "node" in q or "entry" in q:
        return "node_entry"
    if "resource" in q:
        return "resource_list"
    if "dynamic" in q:
        return "dynamic_array"
    if "element" in q or "per " in q:
        return "element"
    if "vehicle" in q:
        return "vehicle_struct"
    if q in ("param_1", "param_2", "this", "", "indirect", "returned descriptor", "*param_1", "param_1 / this"):
        return "generic"
    return "generic"

struct_groups = defaultdict(list)

for obs in observations:
    if not obs.get("offsets") or len(obs["offsets"]) == 0:
        continue
    
    qual = obs.get("qualifier", "")
    sname = obs.get("section_type", "Struct offsets")
    offsets = obs["offsets"]
    fun_addr = obs["fun_address"]
    
    # Compute category
    cat = get_qualifier_category(qual)
    
    # For generic structs, derive key from offset pattern
    if cat == "generic":
        # Get sorted starting offsets
        start_vals = sorted([parse_offset_hex(o["offset_hex"]) for o in offsets])
        sig = "+".join([f"+0x{v:x}" for v in start_vals[:4]])
        struct_key = f"generic_{sig}"
    elif cat == "linked_list":
        struct_key = f"linked_list_{qual}"
    elif cat == "timer":
        struct_key = "timer_struct"
    elif cat == "buffer":
        struct_key = "buffer_descriptor"
    elif cat == "array_container":
        struct_key = "array_container"
    elif cat == "vehicle_struct":
        struct_key = "vehicle_struct"
    elif cat == "file_handle":
        struct_key = "file_handle"
    elif cat == "stream":
        struct_key = "stream_object"
    elif cat == "node_entry":
        struct_key = "node_entry"
    elif cat == "resource_list":
        struct_key = "resource_list"
    elif cat == "dynamic_array":
        struct_key = "dynamic_array"
    else:
        start_vals = sorted([parse_offset_hex(o["offset_hex"]) for o in offsets])
        sig = "+".join([f"+0x{v:x}" for v in start_vals[:4]])
        struct_key = f"other_{sig}"
    
    struct_groups[struct_key].append(obs)

# Print stats
print(f"Total observations: {len(observations)}")
print(f"Total struct groups: {len(struct_groups)}")
for key, group in sorted(struct_groups.items()):
    total_offsets = sum(len(o["offsets"]) for o in group)
    funs = set(o["fun_address"] for o in group)
    print(f"  {key}: {len(group)} obs, {total_offsets} offsets, {len(funs)} functions")

# Step 2: For each group, consolidate offset observations
output_lines = []
output_lines.append("# Consolidated Struct Definitions from docs/20-math-utilities.md")
output_lines.append("")
output_lines.append(f"Generated from {len(observations)} struct offset observations across {len([o for o in observations if o.get('offsets')])} function entries.")
output_lines.append("")

# Process: significant groups (multi-function or with clear identity)
# Filter and sort groups by importance
important_groups = []
unique_generic = []

for key, group in sorted(struct_groups.items()):
    total_offsets = sum(len(o["offsets"]) for o in group)
    funs = sorted(set(o["fun_address"] for o in group))
    
    if key.startswith("generic_"):
        if len(funs) >= 2:
            important_groups.append((key, group, "multi"))
        else:
            unique_generic.append((key, group))
    else:
        important_groups.append((key, group, "named"))

# Write important groups first
for key, group, gtype in important_groups:
    total_offsets = sum(len(o["offsets"]) for o in group)
    funs = sorted(set(o["fun_address"] for o in group))
    fun_names = [o["fun_name"] for o in group]
    name_map = {}
    for o in group:
        name_map[o["fun_address"]] = o["fun_name"]
    
    qual = group[0].get("qualifier", "")
    section_type = group[0].get("section_type", "Struct offsets")
    
    output_lines.append(f"## {section_type}: {group[0].get('qualifier', 'generic')} — {qual}")
    desc = "; ".join(sorted(set(name_map.values())))
    output_lines.append(f"Based on {len(group)} observations from {len(funs)} functions.")
    output_lines.append(f"Functions: {', '.join(sorted(name_map.keys()))}")
    output_lines.append(f"Confidence: {'high' if len(funs) >= 3 else 'medium' if len(funs) >= 2 else 'low'}")
    output_lines.append("")
    
    # Merge all offset entries
    offset_map = defaultdict(list)
    for obs in group:
        fun_addr = obs["fun_address"]
        for off in obs["offsets"]:
            ohex = off["offset_hex"]
            field = off.get("field_name", "?")
            typ = off.get("type", "?")
            notes = off.get("notes", "")
            offset_map[(ohex, field)].append((fun_addr, typ, notes))
    
    output_lines.append("| Offset | Field | Type | Notes | Observed in |")
    output_lines.append("|--------|-------|------|-------|-------------|")
    
    for (ohex, field), entries in sorted(offset_map.items(), key=lambda x: parse_offset_hex(x[0][0])):
        types = set(e[1] for e in entries)
        notes_set = set(e[2] for e in entries if e[2])
        funs_obs = set(e[0] for e in entries)
        
        typ_str = ", ".join(sorted(types)) if len(types) > 1 else (next(iter(types)) if types else "?")
        if len(types) > 1:
            typ_str += " **CONFLICT**"
        notes_str = "; ".join(sorted(notes_set)) if notes_set else ""
        funs_str = ", ".join(sorted(funs_obs))
        
        output_lines.append(f"| {ohex} | {field} | {typ_str} | {notes_str} | {funs_str} |")
    output_lines.append("")

# Count unique generic single-function structs
output_lines.append(f"---")
output_lines.append(f"Additionally, {len(unique_generic)} single-function generic struct observations exist but are not consolidated above (each function uses a unique struct layout).")
output_lines.append(f"Total unique offset entries across all observations: {sum(len(o['offsets']) for o in observations)}")
output_lines.append("")

# Vehicle/AI struct offsets 
output_lines.append("## Vehicle/AI Struct Offsets (high offset ranges)")
output_lines.append("These offsets suggest vehicle or AI struct access rather than utility struct access.\n")
vehicle_entries = []
for obs in observations:
    if not obs.get("offsets"):
        continue
    for off in obs["offsets"]:
        ohex = off["offset_hex"]
        try:
            val = parse_offset_hex(ohex)
            if val >= 0x1000 or val in [0x32bc, 0x3450, 0x3a9c, 0x3d64, 0x4354]:
                vehicle_entries.append((obs, off, val))
        except:
            pass

if vehicle_entries:
    output_lines.append("| Offset | Field | Type | Notes | Function |")
    output_lines.append("|--------|-------|------|-------|----------|")
    for obs, off, val in sorted(vehicle_entries, key=lambda x: x[2]):
        output_lines.append(f"| {off['offset_hex']} | {off.get('field_name','?')} | {off.get('type','?')} | {off.get('notes','')} | {obs['fun_address']} ({obs['fun_name']}) |")
else:
    output_lines.append("No vehicle/AI struct offsets found in 20-math-utilities.md.")

output = "\n".join(output_lines)
output_path = "%USERPROFILE%\\Desktop\\F1C_ghidra_project\\analysis_pipeline\\output\\struct_synth\\worker_B.md"
with open(output_path, "w") as f:
    f.write(output)

print(f"\n\nWritten to {output_path}")
print(f"Total lines: {len(output_lines)}")
