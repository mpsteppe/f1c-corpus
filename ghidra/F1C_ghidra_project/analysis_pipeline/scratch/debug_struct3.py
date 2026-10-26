import re

INPUT = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\01-engine-architecture.md'

with open(INPUT, 'r', encoding='utf-8') as f:
    lines = f.readlines()

# Find line containing "Struct offsets (param_1)" 
for i, line in enumerate(lines):
    if 'Struct offsets (param_1)' in line:
        print(f'Python idx {i} (1-indexed {i+1}): [{line.rstrip()}]')
        # Check what comes before
        for j in range(max(0,i-5), i):
            print(f'  {j}: [{lines[j].rstrip()[:80]}]')
        print(f'  => {i}: [{line.rstrip()}]')
        # Check what FUN_ header is before it
        for j in range(i, max(0,i-20), -1):
            m = re.match(r'^#{2,3}\s+(FUN_[0-9A-Fa-f]{8}|Unwind_[0-9A-Fa-f]+)\s*[:\-?\u2014]\s*(.*)', lines[j])
            if m:
                print(f'  FUN at {j}: {m.group(1)} - {m.group(2).strip()[:60]}')
                break
        break

# Also check what's at the known positions from grep
print("\n=== Checking lines around 941 (1-indexed) ===")
for i in range(940, 945):
    idx = i - 1  # convert to 0-indexed
    if idx < len(lines):
        print(f'Python idx {idx}: [{lines[idx].rstrip()[:80]}]')

# Check line 941 specifically
print(f'\nlines[940] repr: {repr(lines[940][:80])}')
