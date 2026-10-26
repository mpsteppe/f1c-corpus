import json, sys
sys.stdout.reconfigure(encoding='utf-8')
def safe(s):
    if s is None: return '?'
    s = str(s)
    return s.encode('ascii', errors='replace').decode('ascii')

with open(r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\functions.json', 'r', encoding='utf-8') as f:
    funcs = json.load(f)

# All callees from all 12 seeds
callees = set()

# Seed 121 callees
callees.update(['0x004b0170','0x00548e00','0x0054bd30','0x00544d30','0x00545f50','0x005487a0','0x00548810','0x00544740','0x00545a10','0x00545a40','0x00545bb0','0x00557280','0x00557240','0x00548850','0x00486720','0x005414e0','0x0053ced0','0x0053c9c0','0x00587bcf'])
# Seed 122 callees
callees.update(['0x004b33b0','0x004b2310','0x004b2480','0x004b25d0','0x004b2750','0x004b2840','0x004b2930','0x004b29b0','0x004b2a10','0x004b2a40','0x004b2aa0','0x004b2b10','0x004b2b60','0x004c7c00','0x004b2ae0'])
# Seed 123 callees
callees.update(['0x004e9630','0x004fd7e0','0x004472b0','0x004e16f0','0x004ed750','0x004ce380','0x004ce3e0','0x004ce8f0','0x004ce930','0x004ee230','0x0044c4c0','0x004b9ce0','0x004cce90'])
# Seed 124 callees
callees.update(['0x004c8d00','0x004cfff0','0x004b0170','0x00455f00','0x0042ca70','0x004ba770','0x0049f120','0x004fad00','0x00464670','0x0042d350','0x004a1930'])
# Seed 125 callees
callees.update(['0x004c11d0','0x004c11e0','0x004c55b0','0x004c54f0','0x004c0850','0x004c1370','0x004ef5a0','0x004b1190','0x00566650','0x00415730'])
# Seed 126 callees
callees.update(['0x004144d0','0x004f0050','0x004d7c10','0x004d1ad0','0x004189b0','0x004189f0','0x00418a20','0x004144f0','0x00418560'])
# Seed 127 callees
callees.update(['0x00587bcf','0x00565dc0','0x00565f80','0x00565f50','0x005662d0','0x00565f20','0x00565e20','0x00404e60'])
# Seed 128 callees
callees.update(['0x0049b950','0x0049b900','0x0049b8f0','0x004db6f0','0x004db9a0','0x0049b7a0','0x004db7f0'])
# Seed 129 callees
callees.update(['0x004dd550','0x0054c230','0x0054e100','0x0054e120','0x0054b420','0x0054b3b0','0x0040e1f0'])
# Seed 130 callees
callees.update(['0x0058ba36','0x005668b0','0x00566a70','0x00566940','0x00566b90','0x005668d0'])
# Seed 131 callees
callees.update(['0x0054c230','0x004dd550','0x0054b420','0x0054e100','0x0054e120'])
# Seed 132 callees
callees.update(['0x00564930','0x005648b0','0x0058b130','0x00564960'])

# Also get sub-callees for deeper levels
# 123 sub-callees
callees.update(['0x004e8010','0x004e8b80','0x004e8ce0','0x004e3d00','0x0044c620'])
# 124 sub-callees (sound exit, etc)
callees.update(['0x004c8630','0x004c7dd0','0x004c7ca0','0x004c8ca0','0x004ba1f0','0x0049f150','0x004d82a0','0x004b4030'])
# 125 sub-callees
callees.update(['0x004c7980','0x004e1970','0x004b8da0','0x004c1370','0x004ef5a0'])
# 127 sub-callees
callees.update(['0x0058aa6f','0x00566650'])
# 128 sub-callees
callees.update(['0x0049b8a0','0x0049ba50'])
# 129 sub-callees
callees.update(['0x0040d290','0x0040e1d0'])
# 130 sub-callees
callees.update(['0x00587b3e','0x00587bcf'])
# 132 sub-callees
callees.update(['0x0058b5d4','0x0058b130'])

print(f"Looking up {len(callees)} callee functions...")
for addr in sorted(callees):
    if addr in funcs:
        d = funcs[addr]
        summary = safe(d.get("summary","?"))
        doc = safe(d.get("doc_file","?"))
        print(f"{addr} | {summary} | {doc} | call_count={d.get('call_count','?')}")
    else:
        print(f"{addr} | NOT IN FUNCTIONS.JSON | ?")
