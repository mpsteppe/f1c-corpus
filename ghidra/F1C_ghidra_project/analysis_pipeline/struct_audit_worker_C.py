"""
Struct Confidence Audit — Worker C (Sections 31-45)
Verifies docs/13-struct-offsets.md offset types against analyzed/ .c files.
"""
import subprocess, re, os, sys

ANALYZED = r"%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed"
DOCS13 = r"%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md"
OUTPUT = r"%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_C.md"

def rg_count(pattern):
    """Count files matching regex pattern in analyzed/."""
    result = subprocess.run(
        ["rg", "-c", pattern, ANALYZED],
        capture_output=True, text=True, timeout=120
    )
    if result.returncode not in (0, 1):
        return 0, f"error: {result.stderr[:200]}"
    lines = [l for l in result.stdout.strip().split('\n') if l.strip()]
    count = len(lines)
    return count, lines[:5]  # return count + first 5 matches

def rg_type_check(offset_hex):
    """Check what types are used for a given offset."""
    off_full = "0x" + offset_hex
    # Check for float pointers
    result_float = subprocess.run(
        ["rg", "-c", rf'\*\(float \*\)\([^)]*\+ {off_full}', ANALYZED],
        capture_output=True, text=True, timeout=120
    )
    # Check for int pointers
    result_int = subprocess.run(
        ["rg", "-c", rf'\*\(int \*\)\([^)]*\+ {off_full}', ANALYZED],
        capture_output=True, text=True, timeout=120
    )
    # Check for double pointers
    result_double = subprocess.run(
        ["rg", "-c", rf'\*\(double \*\)\([^)]*\+ {off_full}', ANALYZED],
        capture_output=True, text=True, timeout=120
    )
    # Check for undefined4/byte/char pointers
    result_undef = subprocess.run(
        ["rg", "-c", rf'\*\((undefined[0-9]*|byte|char) \*\)\([^)]*\+ {off_full}', ANALYZED],
        capture_output=True, text=True, timeout=120
    )
    # Check for ptr/pointer patterns
    result_ptr = subprocess.run(
        ["rg", "-c", rf'param_1\[0x[0-9a-f]*\] = \*\([^)]*\)\([^)]*\+ {off_full}', ANALYZED],
        capture_output=True, text=True, timeout=120
    )
    # Check for param_1[index] style
    try:
        byte_off = int(offset_hex, 16)
        if byte_off % 4 == 0:
            idx = byte_off // 4
            result_idx = subprocess.run(
                ["rg", "-c", rf'param_1\[0x{idx:x}\]', ANALYZED],
                capture_output=True, text=True, timeout=120
            )
        else:
            result_idx = subprocess.run(["rg", "-c", rf'param_1\[{byte_off}\]', ANALYZED],
                                        capture_output=True, text=True, timeout=120)
    except:
        result_idx = subprocess.run(["rg", "-c", "", ANALYZED],
                                    capture_output=True, text=True, timeout=5)
    
    types = {}
    for label, r in [("float", result_float), ("int", result_int), 
                     ("double", result_double), ("undef", result_undef),
                     ("index", result_idx)]:
        if r.returncode in (0, 1):
            cnt = len([l for l in r.stdout.strip().split('\n') if l.strip()])
            if cnt > 0:
                types[label] = cnt
    return types

def parse_sections():
    """Parse docs/13-struct-offsets.md and extract section boundaries."""
    with open(DOCS13, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    
    sections = []
    current_name = None
    current_start = None
    
    for i, line in enumerate(lines):
        m = re.match(r'^## (.+)', line)
        if m:
            if current_name and current_start is not None:
                sections.append((current_name, current_start, i-1))
            current_name = m.group(1).strip()
            current_start = i
    
    if current_name and current_start is not None:
        sections.append((current_name, current_start, len(lines)-1))
    
    return lines, sections

def extract_offsets(lines, start, end):
    """Extract offset rows from a section."""
    offsets = []
    for i in range(start, end):
        line = lines[i]
        m = re.match(r'^\| \+0x([0-9a-fA-F]+)', line)
        if m:
            offset_hex = m.group(1)
            # Try to extract type from the table
            type_m = re.search(r'\| (float|int|double|ptr|byte|short|char|uint|void\*)', line)
            field_type = type_m.group(1) if type_m else "unknown"
            
            # Get field name
            name_m = re.search(r'\| [^\|]+\| ([^\|]+) \|', line)
            field_name = name_m.group(1).strip() if name_m else "???"
            
            offsets.append({
                'offset': offset_hex,
                'type': field_type,
                'name': field_name,
                'line': line.strip()
            })
    return offsets

# Parse sections
lines, sections = parse_sections()

# Find my sections (31-45)
my_sections = [
    "VehicleStruct (param_1 — vehicle struct)",
    "VehicleTelemetryBroadcast (param_1 — telemetry)",
    "3. LinkedListNode (inferred)",
    "VehiclePhysicsState (inferred)",
    "SparseParamArray",
    "WheelSuspensionData (inferred)",
    "Player File Struct",
    "UI Dialog/Property Page Struct",
    "Screen-Space Tile Renderer (inferred)",
    "CollisionLinkedNode (inferred — generic collision/proxy linked list node)",
    "CollisionDataBlock (inferred — param_1 in FUN_0044fbb0)",
    "1. Track Material Struct (inferred)",
    "AudioChannelInitStruct (inferred)",
    "Struct 4: Driver Data Entry (stride 0x20 = 32 bytes = 8 ints)",
    "WeatherState (inferred)"
]

# Process each section
output_lines = []
output_lines.append("=== AUDIT RESULTS ===\n")

for sect_name, sect_start, sect_end in sections:
    # Check if this section is in my list
    matched = None
    for ms in my_sections:
        if ms in sect_name or sect_name in ms:
            matched = ms
            break
    if not matched:
        continue
    
    offsets = extract_offsets(lines, sect_start, sect_end)
    
    output_lines.append(f"## {sect_name}")
    output_lines.append(f"")
    output_lines.append(f"Total offsets in section: {len(offsets)}")
    output_lines.append(f"")
    output_lines.append(f"| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |")
    output_lines.append(f"|--------|-------------|--------------|-------------|-------------|------------|")
    
    for off in offsets:
        offset_val = off['offset']
        # Pad to 4 digits
        if len(offset_val) < 4:
            offset_val = offset_val.zfill(4)
        
        types = rg_type_check(offset_val)
        
        n_float = types.get('float', 0)
        n_int = types.get('int', 0)
        n_double = types.get('double', 0)
        n_undef = types.get('undef', 0)
        n_ptr = types.get('ptr', 0)
        n_index = types.get('index', 0)
        
        total = n_float + n_int + n_double + n_undef + n_ptr + n_index
        
        # Determine primary .c type
        type_counts = {"float": n_float, "int": n_int, "double": n_double, "undef": n_undef, "ptr": n_ptr, "index": n_index}
        primary_type = max(type_counts, key=type_counts.get) if total > 0 else "none"
        
        # Match check
        claimed = off['type'].lower()
        type_match = "OK"
        if total == 0:
            type_match = "NO_FILES"
        elif claimed in ("ptr", "void*") and primary_type in ("int", "ptr", "index"):
            type_match = "OK(ptr)"
        elif claimed == "unknown":
            type_match = "?"
        elif claimed == "byte" and primary_type in ("undef", "index"):
            type_match = "OK(byte)"
        elif claimed == "short" and primary_type in ("int", "undef", "index"):
            type_match = "OK(short)"
        elif claimed != primary_type and primary_type != "none":
            # Check if there's at least one match
            if type_counts.get(claimed, 0) > 0:
                type_match = "OK(mixed)"
            else:
                type_match = f"CONFLICT(claimed={claimed},found={primary_type})"
        
        # Confidence
        if total >= 5:
            confidence = "HIGH"
        elif total >= 2:
            confidence = "MEDIUM"
        elif total == 1:
            confidence = "LOW"
        else:
            confidence = "NO_EVIDENCE"
        
        type_str = f"float:{n_float} int:{n_int} double:{n_double} undef:{n_undef} ptr:{n_ptr} idx:{n_index}"
        
        output_lines.append(f"| +0x{offset_val} | {off['type']} | {off['name'][:40]} | {total} files | {type_str} | {confidence} |")
    
    output_lines.append(f"\n---\n")

# Add NEW OFFSETS DISCOVERED section
output_lines.append("\n=== NEW OFFSETS DISCOVERED ===\n")
output_lines.append("| Struct | Offset | Type | Found In | Notes |\n")
output_lines.append("|--------|--------|------|----------|-------|\n")
# (New offsets discovered would need to be manually checked - this script doesn't discover new ones automatically)
output_lines.append("(None — script did not scan for new offsets)\n")

result = '\n'.join(output_lines)

# Write to disk
os.makedirs(os.path.dirname(OUTPUT), exist_ok=True)
with open(OUTPUT, 'w', encoding='utf-8') as f:
    f.write(result)

print(f"Written to {OUTPUT}")
print(f"Total lines: {len(result.split(chr(10)))}")
