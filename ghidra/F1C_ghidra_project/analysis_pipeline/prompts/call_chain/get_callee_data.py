import json, sys

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json', 'r', encoding='utf-8') as f:
    cg = json.load(f)

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\functions.json', 'r', encoding='utf-8') as f:
    fn = json.load(f)

# Chain seeds and their callees
chains = {
    '97_VidMan_Enter': {
        'addr': '0x004fa000',
        'callees': ['0x004d7a50','0x004d7aa0','0x00568be0','0x0053d470','0x0053d890','0x0053d8e0','0x004f9160','0x004f91b0','0x004a1200','0x0053c680','0x005408f0','0x004f9420','0x004f9310','0x004f9f00','0x005434a0','0x0055c060','0x004f9f30','0x00494690','0x00422be0']
    },
    '98_Telemetry': {
        'addr': '0x004d4a80',
        'callees': ['0x004d5be0','0x0042bc10','0x004d5840','0x00587db0','0x00588678','0x004ceef0','0x004f34e0','0x0042e320','0x004f4270','0x004b3c60','0x00568a60','0x00566650','0x00588410','0x0042ddd0','0x004d5af0']
    },
    '99_Camera_Director': {
        'addr': '0x0040ca30',
        'callees': ['0x0040c7a0','0x0040c910','0x00409890','0x00542460','0x00542420','0x004d8860','0x0040be70','0x0040c070','0x0040c5b0','0x004f0d20','0x0040c870','0x0053d450','0x004ccdc0']
    },
    '100_Bezier': {
        'addr': '0x0044b370',
        'callees': ['0x004492b0','0x004492d0','0x004493a0','0x00448ee0','0x00449340','0x00449700','0x0044b110','0x0044b040','0x0044af20','0x0044af60','0x00449a80','0x00587bcf']
    },
    '101_AI_Driver_Count': {
        'addr': '0x004bfd90',
        'callees': ['0x004bf630','0x0042bc10','0x004b3c60','0x0042bc80','0x004bf790','0x004ef5a0','0x004bfd40','0x004c78f0','0x004c6960','0x004c3f80']
    },
    '102_Scoring_Display': {
        'addr': '0x0041e320',
        'callees': ['0x004144d0','0x004c2850','0x004c11d0','0x0041f340','0x0041f5d0','0x00415550','0x004144f0','0x00418560','0x00420cf0']
    },
    '103_Pit_Anim': {
        'addr': '0x004a3220',
        'callees': ['0x004a29a0','0x00566650','0x0053c800','0x0053cbc0','0x004a2a90','0x0053ce40','0x0053c900','0x00587bcf']
    },
    '104_Game_Setup': {
        'addr': '0x0042d5d0',
        'callees': ['0x004f9160','0x004a0eb0','0x004b1870','0x00455c60','0x004c8ab0','0x0049ef70','0x004fa2f0']
    },
    '105_Aero_Engine': {
        'addr': '0x004f18c0',
        'callees': ['0x004d7570','0x004a4830','0x004e2370','0x004d6ae0','0x004d5ea0','0x004e8010','0x0043da10']
    },
    '106_Physics_Frame': {
        'addr': '0x00441600',
        'callees': ['0x004412f0','0x0043f7f0','0x0056ecf0','0x0056ee40','0x0056f090','0x00441450']
    },
    '107_Collision_Overlay': {
        'addr': '0x00494a70',
        'callees': ['0x00543250','0x00553650','0x004f9f00','0x00553700','0x004f9f30']
    },
    '108_Audio_Mixer': {
        'addr': '0x00564271',
        'callees': ['0x005647d0','0x005648b0','0x00564690','0x00564780']
    }
}

# Collect all unique callee addresses
all_callees = set()
for chain in chains.values():
    all_callees.update(chain['callees'])

# Look up each callee in functions.json
callee_data = {}
for addr in sorted(all_callees):
    entry = fn.get(addr, {})
    callee_data[addr] = {
        'summary': entry.get('summary', '[undocumented]'),
        'doc_file': entry.get('doc_file', ''),
        'call_count': entry.get('call_count', 0),
        'heading_level': entry.get('heading_level', 0)
    }
    # Also get their callees (next level) - up to 5 deepest
    sub_callees = cg.get(addr, [])
    callee_data[addr]['sub_callee_count'] = len(sub_callees)
    callee_data[addr]['sub_callees'] = [c['callee'] for c in sub_callees[:5]]

for addr, data in sorted(callee_data.items()):
    hl = '##' if data['heading_level'] == 2 else '###'
    print('{}: [{}] {} {} | calls={} subcallees={}'.format(
        addr, data['doc_file'], hl, data['summary'],
        data['call_count'], data['sub_callee_count']))
    if data['sub_callees']:
        print('  -> {}'.format(data['sub_callees']))
