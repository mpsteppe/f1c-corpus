import re

INPUT = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\01-engine-architecture.md'

with open(INPUT, 'r', encoding='utf-8') as f:
    lines = f.readlines()

# Test exactly line 941
line941 = lines[940]  # 0-indexed vs 1-indexed
print(f'Line 941 raw: [{line941}]')
print(f'Line 941 stripped: [{line941.strip()}]')
print(f'Match **Struct offsets: {bool(re.match(r"^\*\*Struct offsets", line941.strip()))}')

# Count how many lines match **Struct offsets
count = 0
for i, line in enumerate(lines):
    if re.match(r'^\*\*Struct offsets', line.strip()):
        count += 1
        if count <= 5:
            print(f'  Match at line {i+1}: {line.strip()[:60]}')
print(f'\nTotal **Struct offsets matches: {count}')

# Count FUN_ headers
count2 = 0
for i, line in enumerate(lines):
    m = re.match(r'^#{2,3}\s+(FUN_[0-9A-Fa-f]{8}|Unwind_[0-9A-Fa-f]+)\s*[:\-?\u2014]\s*(.*)', line)
    if m:
        count2 += 1
print(f'Total FUN_ headers: {count2}')

# Check fun_headers building
fun_headers = []
for i, line in enumerate(lines):
    m = re.match(r'^#{2,3}\s+(FUN_[0-9A-Fa-f]{8}|Unwind_[0-9A-Fa-f]+)\s*[:\-?\u2014]\s*(.*)', line)
    if m:
        fun_headers.append((i, m.group(1), m.group(2).strip()))
        
# Check if line 941 finds a function
def find_fun_for_line(ln):
    best = None
    for fn_ln, addr, name in fun_headers:
        if fn_ln <= ln:
            best = (addr, name, fn_ln)
        else:
            break
    return best

result = find_fun_for_line(940)  # 0-indexed line 941
print(f'\nfind_fun_for_line(940) = {result}')
