import json

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json', 'r', encoding='utf-8') as f:
    cg = json.load(f)

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json', 'r', encoding='utf-8') as f:
    callers = json.load(f)

targets = ['0x004f3c80','0x004e6d93','0x0043bc20','0x0049db80','0x004bb730',
           '0x0043c250','0x004f24f0','0x004f6bf0','0x0043ef20','0x004ed960',
           '0x004f69e0','0x0041ac50','0x004b3ce0','0x005881f0','0x004d21d0',
           '0x004e8010','0x004f4270','0x004f34e0','0x0049e170','0x004f6950',
           '0x0049db00','0x00423a00','0x0049f6a0','0x004bb950']

# Print callers first
print('=== CALLERS ===')
for t in targets:
    if t in callers:
        print(f'\n{t}:')
        for c in callers[t]:
            print(f"  Called by {c['caller']}: {c.get('caller_name','')} - {c.get('description','')}")

print('\n\n=== CALL GRAPH ===')
for t in targets:
    if t in cg:
        print(f'\n{t}:')
        for callee in cg[t]:
            desc = callee.get('description','')
            print(f"  -> {callee.get('callee','')}: {desc}")
