import json
with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json', 'r', encoding='utf-8') as f:
    callers = json.load(f)

for t in ['0x004f3c80','0x0043ef20','0x004f24f0','0x004f6bf0','0x004bb730','0x004537b0','0x00454350','0x004d36d0','0x004d38f0','0x004d4600','0x0047eb70','0x0043bc20']:
    if t in callers:
        print('Callers of {}:'.format(t))
        for c in callers[t]:
            print('  {}: {} - {}'.format(c['caller'], c.get('caller_name',''), c.get('description','')))
    else:
        print('{} not found in callers'.format(t))
