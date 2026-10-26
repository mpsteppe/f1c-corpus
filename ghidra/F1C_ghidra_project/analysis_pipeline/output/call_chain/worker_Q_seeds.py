#!/usr/bin/env python3
import json

seeds = ['0x004b6c90', '0x00516c7b', '0x0059b07a', '0x0059b208', '0x00490d00', '0x0045f390', '0x004326e0', '0x00415780', '0x00415c40', '0x004c7ca0', '0x0041a170']

base = r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph'

with open(base + '/call_graph.json', encoding='utf-8') as f:
    cg = json.load(f)
with open(base + '/callers.json', encoding='utf-8') as f:
    cr = json.load(f)
with open(base + '/functions.json', encoding='utf-8') as f:
    fn = json.load(f)

for s in seeds:
    print(f'=== {s} ===')
    if s in fn:
        print(f'  Summary: {fn[s].get("summary", "?")}')
        print(f'  Doc: {fn[s].get("doc_file", "?")}')
        print(f'  Call count: {fn[s].get("call_count", 0)}')
        print(f'  Global count: {fn[s].get("global_count", 0)}')
        print(f'  Struct offset count: {fn[s].get("struct_offset_count", 0)}')
    if s in cg:
        print(f'  Callees ({len(cg[s])}):')
        for c in cg[s]:
            desc = c.get('description', '?') or '?'
            print(f'    {c["callee"]}: {desc[:120]}')
    if s in cr:
        print(f'  Callers ({len(cr[s])}):')
        for c in cr[s]:
            desc = c.get('description', '?') or '?'
            print(f'    {c["caller"]}: {desc[:120]}')
    print()
