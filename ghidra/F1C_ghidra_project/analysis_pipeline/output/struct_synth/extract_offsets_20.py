#!/usr/bin/env python3
"""
Extract ALL struct offset observations from docs/20-math-utilities.md
Output structured JSON to extracted_offsets_20.json
"""

import re
import json
import os

INPUT_FILE = r"%USERPROFILE%\Desktop\F1C_ghidra_project\docs\20-math-utilities.md"
OUTPUT_FILE = r"%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_synth\extracted_offsets_20.json"

def parse_table_rows(lines, start_idx, header_cols):
    """
    Parse markdown table rows starting at start_idx.
    header_cols: dict mapping column name to index (0-based).
    Returns list of row dicts and the index after the table.
    """
    rows = []
    i = start_idx
    # Skip separator line if present (|----|----|...)
    if i < len(lines) and re.match(r'^\|[\s\-:]+\|', lines[i]):
        i += 1
    
    while i < len(lines):
        line = lines[i].rstrip()
        # Stop if empty line or next heading
        if not line or line.startswith('**') or line.startswith('#'):
            break
        # Stop if not a table row
        if not line.startswith('|'):
            break
        
        cells = [c.strip() for c in line.split('|')]
        # Remove leading/trailing empty cells from split
        if cells and cells[0] == '':
            cells = cells[1:]
        if cells and cells[-1] == '':
            cells = cells[:-1]
        
        if len(cells) >= 2:
            row = {}
            for col_name, col_idx in header_cols.items():
                if col_idx < len(cells):
                    row[col_name] = cells[col_idx]
                else:
                    row[col_name] = ''
            rows.append(row)
        i += 1
    
    return rows, i


def extract_offset_entries_from_row(row, header_cols):
    """
    Extract individual offset entries from a parsed table row.
    Returns list of offset dicts. Handles multiple patterns:
    - "+0x75/79/7d" → three individual offsets
    - "+0x10–+0x14" → range offset (kept as-is)
    - "AccLow/AccHigh" → split into separate fields when paired with multiple offsets
    - "+0x04 OriginX/Y/Z double[3]" → single entry with combined name
    """
    results = []
    
    offset_str = row.get('offset_hex', row.get('offset', '')).strip()
    field_str = row.get('field_name', row.get('field', row.get('Field', ''))).strip()
    type_str = row.get('type', row.get('Type', '')).strip()
    notes_str = row.get('notes', row.get('Notes', '')).strip()
    ptr_str = row.get('ptr', row.get('Ptr', '')).strip()
    
    if not offset_str and not field_str:
        return results
    
    # Detect offset pattern: is it 3-in-1 like "+0x75/79/7d"?
    # Pattern matches: +0xHEX/HEX[/HEX] where each HEX is 1-8 hex digits
    multi_offset_match = re.match(r'^(\+0x[0-9a-fA-F]+)/([0-9a-fA-F][0-9a-fA-F/]*)$', offset_str)
    
    # Detect range pattern like "+0x10–+0x14" (contains en-dash or hyphen between two hex offsets)
    range_offset_match = re.match(r'^(\+0x[0-9a-fA-F]+)\s*[–\-]\s*(\+0x[0-9a-fA-F]+)$', offset_str)
    
    # Check if offset is a composite like "+0x10–+0x14"
    # or a simple offset like "+0x2c"
    if multi_offset_match:
        # Pattern: +0x75/79/7d (absolute parts) or +0x34e0/4/8 (relative parts)
        base = multi_offset_match.group(1)
        base_match = re.match(r'^\+0x([0-9a-fA-F]+)$', base)
        if base_match:
            base_val = int(base_match.group(1), 16)
            parts = multi_offset_match.group(2).split('/')
            offset_parts = [base]
            for p in parts:
                p = p.strip()
                if p:
                    try:
                        if re.match(r'^[0-9a-fA-F]+$', p):
                            val = int(p, 16)
                            # Heuristic: if part value < base value, treat as relative offset
                            # (e.g. +0x34e0/4/8 → 0x34e0, 0x34e4, 0x34e8)
                            # Otherwise treat as absolute (e.g. +0x75/79/7d → 0x75, 0x79, 0x7d)
                            if val < base_val:
                                abs_val = base_val + val
                                offset_parts.append(f'+0x{abs_val:x}')
                            else:
                                offset_parts.append(f'+0x{val:x}')
                        else:
                            offset_parts.append(base)
                    except ValueError:
                        offset_parts.append(base)
        else:
            offset_parts = [offset_str]
    else:
        # Keep as single offset (could be range like "+0x10–+0x14" or simple "+0x2c")
        offset_parts = [offset_str] if offset_str else []
    
    # Parse field name - split by "/" only if there are multiple offset parts to match
    field_parts = []
    if field_str and '/' in field_str and not field_str.startswith('+0x'):
        # Only split fields if offset has multiple parts (we need to align them)
        if len(offset_parts) > 1:
            field_parts = [f.strip() for f in field_str.split('/')]
        else:
            # Single offset, keep combined field name as-is
            field_parts = [field_str]
    else:
        field_parts = [field_str] if field_str else ['']
    
    # Build entries - one per offset/field pair
    max_len = max(len(offset_parts), len(field_parts))
    
    for i in range(max_len):
        off = offset_parts[i] if i < len(offset_parts) else (offset_parts[-1] if offset_parts else '')
        fld = field_parts[i] if i < len(field_parts) else (field_parts[-1] if field_parts else '')
        
        entry = {
            'offset_hex': off,
            'field_name': fld,
            'type': type_str if type_str else None,
            'notes': notes_str if notes_str else None,
            'ptr': ptr_str if ptr_str else None
        }
        results.append(entry)
    
    return results


def parse_inline_offsets(text):
    """
    Parse inline struct offset entries from text like:
    "+0x1000 ReadCursor short, +0x1002 AvailableData ushort"
    or
    "+0x04 OriginX/Y/Z double[3], +0x1c Matrix[3][3] double[9]"
    
    Returns list of offset dicts.
    """
    results = []
    
    # Pattern: +0xXXXX fieldname type, +0xXXXX ...
    # Split by comma first
    parts = re.split(r',(?=\s*\+0x)', text)
    if len(parts) == 1:
        # Maybe split by semicolon
        parts = re.split(r';(?=\s*\+0x)', text)
    
    for part in parts:
        part = part.strip()
        if not part or not re.search(r'\+0x', part):
            continue
        
        # Parse: "+0x1000 ReadCursor short"
        m = re.match(r'(\+0x[0-9a-fA-F]+)\s+(.*)', part)
        if m:
            offset_hex = m.group(1)
            rest = m.group(2).strip()
            
            # Try to split rest into field_name and type
            # Type is typically: int, short, ushort, byte, float, double, int*, int[], etc.
            # Or patterns like "double[3]", "int32", "int32*"
            type_patterns = [
                r'\b(int\d*\*?|uint\d*\*?|short\*?|ushort\*?|byte\*?|char\*?|float\*?|double\*?|bool\*?)\s*(\[.*?\])?\s*$',
                r'\b(int\d*\*?|uint\d*\*?|short\*?|ushort\*?|byte\*?|char\*?|float\*?|double\*?|bool\*?)\s*$',
            ]
            
            field_name = rest
            field_type = None
            
            for tp in type_patterns:
                tm = re.search(tp, rest, re.IGNORECASE)
                if tm:
                    field_type = tm.group(0).strip()
                    field_name = rest[:tm.start()].strip()
                    break
            
            # Also handle field name with trailing notes in parens
            notes = None
            paren_m = re.search(r'\(([^)]*)\)\s*$', field_name)
            if paren_m:
                notes = paren_m.group(1)
                field_name = field_name[:paren_m.start()].strip()
            
            # Handle combined fields like "OriginX/Y/Z"
            # If field_name is "OriginX/Y/Z" and it's a single entry
            if '/' in field_name and not re.search(r'[+\-]', field_name):
                # Split into sub-fields but they all share the same offset
                # Actually for "OriginX/Y/Z double[3]" the offset is +0x04 and it's one field
                # Only split if there's no type indicating it's an array
                if not field_type or '[' not in field_type:
                    sub_fields = [f.strip() for f in field_name.split('/')]
                    for sf in sub_fields:
                        results.append({
                            'offset_hex': offset_hex,
                            'field_name': sf,
                            'type': field_type,
                            'notes': notes
                        })
                    continue
            
            results.append({
                'offset_hex': offset_hex,
                'field_name': field_name,
                'type': field_type,
                'notes': notes
            })
    
    return results


def main():
    # Read entire file, handling null bytes
    print(f"Reading {INPUT_FILE}...")
    with open(INPUT_FILE, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()
    
    # Replace null bytes
    content = content.replace('\0', '')
    
    lines = content.split('\n')
    print(f"Total lines: {len(lines)}")
    
    observations = []
    
    # State tracking
    current_fun_address = None
    current_fun_name = None
    current_target_doc = None
    
    # Pattern for FUN_ heading
    fun_heading_re = re.compile(r'^## (FUN_[0-9a-fA-F]+)\s*(?:[—–-]\s*(.*))?')
    target_re = re.compile(r'<!--\s*target:\s*(docs/\S+)\s*-->')
    struct_offsets_re = re.compile(r'^\*\*(Struct offsets|Node layout)\s*(?:\(([^)]*)\))?\s*:\*{0,2}\s*(.*)')
    
    i = 0
    found_count = 0
    skip_count = 0
    
    while i < len(lines):
        line = lines[i]
        
        # Check for FUN_ heading
        fun_m = fun_heading_re.match(line)
        if fun_m:
            current_fun_address = fun_m.group(1)
            current_fun_name = (fun_m.group(2) or '').strip()
            i += 1
            continue
        
        # Check for target comment
        target_m = target_re.match(line)
        if target_m:
            current_target_doc = target_m.group(1)
            i += 1
            continue
        
        # Check for **Struct offsets** or **Node layout**
        so_m = struct_offsets_re.match(line)
        if so_m:
            section_type = so_m.group(1).strip()  # "Struct offsets" or "Node layout"
            paren_qualifier = so_m.group(2) or ''  # e.g. "param_1"
            inline_content = so_m.group(3).strip()  # text after ":**"
            
            # Check if there's inline content on the same line
            if inline_content and re.search(r'\+0x', inline_content):
                # Inline format
                offsets = parse_inline_offsets(inline_content)
                if offsets:
                    obs = {
                        'fun_address': current_fun_address,
                        'fun_name': current_fun_name,
                        'target_doc': current_target_doc if current_target_doc else 'unknown',
                        'section_type': section_type,
                        'qualifier': paren_qualifier,
                        'offsets': []
                    }
                    for off in offsets:
                        entry = {}
                        if off['offset_hex']:
                            entry['offset_hex'] = off['offset_hex']
                        if off['field_name']:
                            entry['field_name'] = off['field_name']
                        if off['type']:
                            entry['type'] = off['type']
                        if off['notes']:
                            entry['notes'] = off['notes']
                        if off.get('ptr'):
                            entry['ptr'] = off['ptr']
                        obs['offsets'].append(entry)
                    observations.append(obs)
                    found_count += 1
                    i += 1
                    continue
            
            # Check next lines for table format
            # Look ahead for table rows
            next_i = i + 1
            table_rows = []
            table_header_cols = None
            
            while next_i < len(lines):
                next_line = lines[next_i].rstrip()
                if not next_line or next_line.startswith('**') or next_line.startswith('#'):
                    break
                
                # Check for table header
                if next_line.startswith('|') and 'Offset' in next_line and 'Field' in next_line:
                    # Parse header to determine column layout
                    cells = [c.strip().lower() for c in next_line.split('|')]
                    cells = [c for c in cells if c]  # Remove empty
                    
                    header_cols = {}
                    for idx, cell in enumerate(cells):
                        if cell in ('offset', 'offset_hex'):
                            header_cols['offset'] = idx
                        elif cell in ('field', 'field_name'):
                            header_cols['field_name'] = idx
                        elif cell in ('type',):
                            header_cols['type'] = idx
                        elif cell in ('notes',):
                            header_cols['notes'] = idx
                        elif cell in ('ptr',):
                            header_cols['ptr'] = idx
                    
                    if header_cols:
                        table_header_cols = header_cols
                        next_i += 1
                        break
                
                next_i += 1
            
            if table_header_cols:
                # Parse table rows
                parsed_rows, end_i = parse_table_rows(lines, next_i, table_header_cols)
                
                if parsed_rows:
                    obs = {
                        'fun_address': current_fun_address,
                        'fun_name': current_fun_name,
                        'target_doc': current_target_doc if current_target_doc else 'unknown',
                        'section_type': section_type,
                        'qualifier': paren_qualifier,
                        'offsets': []
                    }
                    
                    for row in parsed_rows:
                        entries = extract_offset_entries_from_row(row, table_header_cols)
                        for entry in entries:
                            e = {}
                            if entry['offset_hex']:
                                e['offset_hex'] = entry['offset_hex']
                            if entry['field_name']:
                                e['field_name'] = entry['field_name']
                            if entry['type']:
                                e['type'] = entry['type']
                            if entry['notes']:
                                e['notes'] = entry['notes']
                            if entry.get('ptr'):
                                e['ptr'] = entry['ptr']
                            obs['offsets'].append(e)
                    
                    if obs['offsets']:
                        observations.append(obs)
                        found_count += 1
                    
                    i = end_i
                    continue
            
            # If we got here but didn't find table or inline, it's an empty struct offsets
            # Still record it
            obs = {
                'fun_address': current_fun_address,
                'fun_name': current_fun_name,
                'target_doc': current_target_doc if current_target_doc else 'unknown',
                'section_type': section_type,
                'qualifier': paren_qualifier,
                'offsets': []
            }
            observations.append(obs)
            found_count += 1
            skip_count += 1
            i += 1
            continue
        
        i += 1
    
    print(f"\nTotal observations found: {len(observations)}")
    print(f"  - With offset entries: {found_count - skip_count}")
    print(f"  - Empty (heading only): {skip_count}")
    
    # Count total offset entries
    total_offsets = sum(len(obs['offsets']) for obs in observations)
    print(f"Total individual offset entries: {total_offsets}")
    
    # Write output
    os.makedirs(os.path.dirname(OUTPUT_FILE), exist_ok=True)
    with open(OUTPUT_FILE, 'w', encoding='utf-8') as f:
        json.dump(observations, f, indent=2, ensure_ascii=False)
    
    print(f"\nOutput written to: {OUTPUT_FILE}")
    
    # Summary stats
    with_offsets = [o for o in observations if o['offsets']]
    empty = [o for o in observations if not o['offsets']]
    print(f"\nStats:")
    print(f"  Observations with offset data: {len(with_offsets)}")
    print(f"  Empty observations (heading only): {len(empty)}")
    print(f"  Unique FUN_ addresses: {len(set(o['fun_address'] for o in observations if o['fun_address']))}")
    print(f"  Unique targets: {len(set(o['target_doc'] for o in observations))}")

if __name__ == '__main__':
    main()
