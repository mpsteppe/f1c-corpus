import json

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json', 'r', encoding='utf-8') as f:
    cg = json.load(f)

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json', 'r', encoding='utf-8') as f:
    callers = json.load(f)

# Additional targets
more_targets = ['0x004f24f0','0x004f6bf0','0x004f4270','0x004f2b10','0x004f3040',
                '0x004f31f0','0x004f3190','0x004f68b0','0x004f6a50','0x0054b420',
                '0x004ee150','0x0054f830','0x004dd7c0','0x0059da3a',
                '0x004e5f60','0x004390a0','0x00430600',
                '0x0043e050','0x00464a10','0x0042c690','0x0049d5d0']

# Check callers for these
for t in more_targets:
    if t in callers:
        print(f'\nCallers of {t}:')
        for c in callers[t]:
            print(f"  {c['caller']}: {c.get('caller_name','')} - {c.get('description','')}")

# Check call graph for key functions
key_funcs = ['0x004f24f0','0x004f6bf0','0x004f69e0','0x004f68b0','0x004f6a50',
             '0x004f4270','0x004e5f60','0x004390a0','0x00430600']
for t in key_funcs:
    if t in cg:
        print(f'\n{t} calls:')
        for callee in cg[t]:
            desc = callee.get('description','')
            print(f"  -> {callee.get('callee','')}: {desc}")
