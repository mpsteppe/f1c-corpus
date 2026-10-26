import json
with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json', 'r', encoding='utf-8') as f:
    callers = json.load(f)

for t in ['0x0043ef20','0x004f24f0','0x004f6bf0']:
    if t in callers:
        print('Callers of {}:'.format(t))
        for c in callers[t]:
            print('  {}: {} - {}'.format(c['caller'], c.get('caller_name',''), c.get('description','')))
    else:
        print('{} not found in callers'.format(t))
