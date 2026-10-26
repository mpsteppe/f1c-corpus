import re

INPUT = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\01-engine-architecture.md'

with open(INPUT, 'r', encoding='utf-8') as f:
    lines = f.readlines()

# Debug: check lines 935-960
print("=== Lines 935-960 ===")
for i in range(935, 960):
    line = lines[i]
    print(f'{i}: {line.rstrip()}')

print("\n=== Test regex ===")
line942 = lines[942].strip()
print(f'Line 942 stripped: "{line942}"')
m = re.match(r'^\*\*Struct offsets', line942)
print(f'Struct offsets match: {bool(m)}')

print("\n=== FUN_ headers around 920-960 ===")
for i in range(920, 960):
    m = re.match(r'^#{2,3}\s+(FUN_[0-9A-Fa-f]{8}|Unwind_[0-9A-Fa-f]+)\s*[:\-?\u2014]\s*(.*)', lines[i])
    if m:
        print(f'  FUN at {i}: {m.group(1)} - "{m.group(2).strip()}"')

# Check if the issue is with the em dash character
print("\n=== Check separators on FUN_ headers ===")
for i in [931, 956, 971, 990, 1009]:
    line = lines[i]
    print(f'{i}: hex bytes: {line[:50].encode("utf-8").hex()}')
    print(f'  text: {line[:80].rstrip()}')
