import json

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\globals_usage.json', encoding='utf-8') as f:
    data = json.load(f)

my_globals = [
    'DAT_0059e450','DAT_0059e46c','DAT_005ef9a0','DAT_0059e970','DAT_007c5690','DAT_0059e7d8','DAT_0059f118',
    'DAT_005d31ec','DAT_007c73f8','DAT_007ce26c','DAT_008afeec','DAT_0059e48c','DAT_0059e928','DAT_0059ed20',
    'DAT_0059f0b0','DAT_005acc84','DAT_005acf38','DAT_005ad224','DAT_005af970','DAT_005be8f8','DAT_005cc1f8',
    'DAT_005d76c8','DAT_005d91f0','DAT_005ea4e8','DAT_005f073c','DAT_007c54e4','DAT_007c91b4','DAT_007ca480',
    'DAT_007cc9ec','DAT_007cccdc','DAT_007cce2c','DAT_007ccf34','DAT_007cd130','DAT_007cd9c8','DAT_007ce684',
    'DAT_007cf764','DAT_007d0a20','DAT_007d2044','DAT_008B8F24','DAT_008acfa0','DAT_008b0108','DAT_008b8f3c',
    'DAT_008d42a0','DAT_008d73f8'
]

for g in my_globals:
    gu = g.upper()
    found = False
    for k, v in data.items():
        if k.upper() == gu:
            found = True
            name_val = v.get('name', '') if v.get('name') else '(unnamed)'
            module_val = v.get('module', '') if v.get('module') else '(unknown)'
            print('--- ' + k + ' ---')
            print('  name: ' + name_val.encode('ascii', errors='replace').decode('ascii'))
            print('  module: ' + module_val.encode('ascii', errors='replace').decode('ascii'))
            funcs = v.get('functions', [])
            print('  used_by: ' + str(len(funcs)) + ' functions')
            for f in funcs[:5]:
                fn = f.get('function_name', '?')
                ac = f.get('access', '?')
                print('    ' + f['function'] + ' (' + fn + ') - ' + ac)
            break
    if not found:
        print(g + ': NOT FOUND in globals_usage.json')
