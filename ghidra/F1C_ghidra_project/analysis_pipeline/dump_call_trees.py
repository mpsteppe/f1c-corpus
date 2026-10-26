# -*- coding: utf-8 -*-
import json, sys

funcs = json.load(open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\functions.json', encoding='utf-8'))
calls = json.load(open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json', encoding='utf-8'))
callers_db = json.load(open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json', encoding='utf-8'))

addresses = [
    "0x0055b200", "0x004ff8f0", "0x004b9890", "0x004e6d93",
    "0x00411840", "0x0049b370", "0x0045b660", "0x00443c07",
    "0x0045a8e0", "0x00541120", "0x00442060"
]

def clean(s):
    if s is None: return ""
    return s.replace('\ufffd','?').replace('\u2014','--').replace('\u2013','-').strip()[:80]

def get_func_info(addr):
    if addr in funcs:
        f = funcs[addr]
        return clean(f.get('summary','')), f.get('doc_file','?')
    return "unknown","?"

for addr in addresses:
    s, doc = get_func_info(addr)
    print(f"=== {addr} - {s} [{doc}] ===")
    print(f"Callers: {len(callers_db.get(addr,[]))}")
    for c in callers_db.get(addr,[])[:3]:
        print(f"  <- {c['caller']} ({clean(c.get('description',''))})")
    print(f"Callees: {len(calls.get(addr,[]))}")
    for c in calls.get(addr,[]):
        ca = c['callee']
        cs, cdoc = get_func_info(ca)
        cc = len(calls.get(ca,[]))
        print(f"  -> {ca} - {clean(c.get('description',''))} | {cs} [{cdoc}] sub:{cc}")
    print()
    # Also dump sub-callees for ones with many children
    for c in calls.get(addr,[]):
        ca = c['callee']
        sub = calls.get(ca,[])
        if len(sub) > 2:
            print(f"  --- Sub-callees of {ca} ({len(sub)} total) ---")
            for sc in sub[:5]:
                sca = sc['callee']
                scs, scdoc = get_func_info(sca)
                scc = len(calls.get(sca,[]))
                print(f"    -> {sca} - {clean(sc.get('description',''))} | {scs} [{scdoc}] sub:{scc}")
            if len(sub) > 5:
                print(f"    ... ({len(sub)-5} more)")
            print()
    print()
