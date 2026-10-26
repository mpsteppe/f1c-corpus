import json, sys
sys.stdout.reconfigure(encoding='utf-8')
def safe(s):
    if s is None: return '?'
    s = str(s)
    return s.encode('ascii', errors='replace').decode('ascii')

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\functions.json', 'r', encoding='utf-8') as f:
    funcs = json.load(f)

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json', 'r', encoding='utf-8') as f:
    call_graph = json.load(f)

seeds = [
    ('0x00543fa0', '121 - Vertex Buffer Resource Allocation', 'docs/19-renderer.md'),
    ('0x004c71c0', '122 - SetupCarLightingAndRender', 'docs/19-renderer.md'),
    ('0x004ee2d0', '123 - Vehicle Dynamics Update', 'docs/18-physics-dynamics.md'),
    ('0x0042db20', '124 - Game::Exit()', 'docs/01-engine-architecture.md'),
    ('0x004c1050', '125 - InitAllDrivers', 'docs/06-session-race-logic.md'),
    ('0x0041b3c0', '126 - Pit Selection State Machine', 'docs/07-pit-system.md'),
    ('0x00404d50', '127 - Resource List Cleanup', 'docs/08-file-formats.md'),
    ('0x004db550', '128 - Conditional Dispatch', 'docs/01-engine-architecture.md'),
    ('0x0040e2b0', '129 - Audio/Physics Mix with Lerp', 'docs/20-math-utilities.md'),
    ('0x00409770', '130 - File Resource Processing', 'docs/20-math-utilities.md'),
    ('0x004c9fb0', '131 - ParticleCollisionSpawn', 'docs/17-physics-collision.md'),
    ('0x005648d0', '132 - Audio Stack Push with Overflow Realloc', 'docs/21-audio-network-internals.md')
]

for addr, name, sys in seeds:
    print(f'\n=== {name} ({addr}) ===')
    if addr in funcs:
        d = funcs[addr]
        print(f'doc_file: {d.get("doc_file","?")}')
        print(f'summary: {safe(d.get("summary","?"))}')
        print(f'heading_level: {d.get("heading_level","?")}')
        print(f'call_count: {d.get("call_count","?")}')
        print(f'triage_category: {d.get("triage_category","?")}')
        print(f'is_game_logic: {d.get("is_game_logic","?")}')
        print(f'moddability: {d.get("moddability","?")}')
    else:
        print('NOT FOUND in functions.json')
    
    if addr in call_graph:
        cg = call_graph[addr]
        print(f'callees in call_graph: {len(cg)}')
        for c in cg[:5]:
            print(f'  -> {c.get("callee","?")} - {safe(c.get("description","?"))}')
        if len(cg) > 5:
            print(f'  ... and {len(cg)-5} more')
    else:
        print('No callees in call_graph.json (leaf function)')
    
    print()
