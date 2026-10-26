#!/usr/bin/env python3
import json

base = r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph'

with open(base + '/call_graph.json', encoding='utf-8') as f:
    cg = json.load(f)
with open(base + '/callers.json', encoding='utf-8') as f:
    cr = json.load(f)
with open(base + '/functions.json', encoding='utf-8') as f:
    fn = json.load(f)

# All unique callee addresses across all seeds
seeds = {
    '0x004b6c90': ['Model/Scene File Loader', 'docs/20-math-utilities.md'],
    '0x00516c7b': ['ControllerStateMachine', 'docs/06-session-race-logic.md'],
    '0x0059b07a': ['Single Function Call Wrapper', 'docs/01-engine-architecture.md'],
    '0x0059b208': ['Single Byte Write via Stream', 'docs/08-file-formats.md'],
    '0x00490d00': ['SpatialHashReindex', 'docs/17-physics-collision.md'],
    '0x0045f390': ['RunCollisionDetectionLoop', 'docs/17-physics-collision.md'],
    '0x004326e0': ['Player Name Setup', 'docs/10-vehicle-physics.md'],
    '0x00415780': ['Vehicle List Builder from Global Array', 'docs/08-file-formats.md'],
    '0x00415c40': ['Scene List Builder from Global Array', 'docs/08-file-formats.md'],
    '0x004c7ca0': ['Network Message Receive and Dispatch', 'docs/21-audio-network-internals.md'],
    '0x0041a170': ['AI Vehicle Damage Event', 'docs/02-ai-system.md'],
}

all_addrs = set()
for s in seeds:
    if s in cg:
        for c in cg[s]:
            all_addrs.add(c['callee'])
            # Get callee's callees too (1 more level)
            if c['callee'] in cg:
                for c2 in cg[c['callee']]:
                    all_addrs.add(c2['callee'])
                    if c2['callee'] in cg:
                        for c3 in cg[c2['callee']]:
                            all_addrs.add(c3['callee'])
                            if c3['callee'] in cg:
                                for c4 in cg[c3['callee']]:
                                    all_addrs.add(c4['callee'])

print(f'Total unique addresses to look up: {len(all_addrs)}')

# Look up each address
for addr in sorted(all_addrs):
    if addr in fn:
        fdata = fn[addr]
        summary = (fdata.get("summary","?") or "?")[:80]
        summary = summary.encode('ascii', errors='replace').decode('ascii')
        docfile = fdata.get("doc_file","?") or "?"
        print(f'{addr}: {summary} | doc={docfile} | callers={len(cr.get(addr,[]))} | callees={len(cg.get(addr,[]))}')
