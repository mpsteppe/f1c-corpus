"""
Cross-validation analyzer: reads script output, filters noise, identifies real issues.
"""
import re, os, json

# Common false-positive globals (debug boilerplate)
FP_GLOBALS = {'DAT_008AD25C', 'DAT_005C56A4', 'DAT_005C5734', 'DAT_005C3590', 'DAT_005C3628',
              'DAT_005BE958', 'DAT_005BE980', 'DAT_005C56C0', 'DAT_005C56A4', 'DAT_005C5734',
              'DAT_005BE704', 'DAT_005C32C8', 'DAT_007CFBB4'}

# Load call graph to help filter
cg_path = r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json'
cg = {}
try:
    with open(cg_path, encoding='utf-8') as f:
        cg = json.load(f)
except:
    pass

# Read the script's output (from the saved file)
results_path = r'%USERPROFILE%\.local\share\opencode\tool-output\tool_f6700bc9200117DfRRgmHTc25G'
with open(results_path, encoding='utf-8', errors='replace') as f:
    output = f.read()

# Parse ISSUES sections
issues = re.findall(r'## (FUN_[0-9A-Fa-f]+) — ISSUES FOUND\nSource: ([^\n]+)\n((?:(?:  [A-Z_]+: [^\n]+\n?)*))', output)

print(f"Functions with issues flagged: {len(issues)}")
print()

def analyze_func(func_name, doc_path, details):
    missing_calls = set()
    extra_calls = set()
    missing_globals = set()
    extra_globals = set()
    
    for line in details.split('\n'):
        line = line.strip()
        if line.startswith('MISSING_CALLS:'):
            calls_str = line.split(':', 1)[1].strip()
            for c in re.findall(r'FUN_[0-9A-Fa-f]{8}', calls_str):
                missing_calls.add(c)
        elif line.startswith('EXTRA_CALLS:'):
            calls_str = line.split(':', 1)[1].strip()
            for c in re.findall(r'FUN_[0-9A-Fa-f]{8}', calls_str):
                extra_calls.add(c)
        elif line.startswith('MISSING_GLOBALS:'):
            gs_str = line.split(':', 1)[1].strip()
            for g in re.findall(r'DAT_[0-9A-Fa-f]{8}', gs_str):
                if g not in FP_GLOBALS:
                    missing_globals.add(g)
        elif line.startswith('EXTRA_GLOBALS:'):
            gs_str = line.split(':', 1)[1].strip()
            for g in re.findall(r'DAT_[0-9A-Fa-f]{8}', gs_str):
                if g not in FP_GLOBALS:
                    extra_globals.add(g)
    
    # Filter self-references
    missing_calls = {c for c in missing_calls if c != func_name}
    extra_calls = {c for c in extra_calls if c != func_name}
    
    # Count real issues (excluding noise)
    real_missing_calls = {c for c in missing_calls 
                         if c not in ['FUN_004d7a50', 'FUN_004d7aa0'] 
                         and c.upper() != func_name.upper()}
    
    # Score: how concerning is this?
    score = len(real_missing_calls) + len(extra_calls) * 3 + len(missing_globals) * 0.5
    
    return {
        'func': func_name,
        'doc': doc_path,
        'missing_calls': real_missing_calls,
        'extra_calls': extra_calls,
        'missing_globals': missing_globals,
        'extra_globals': extra_globals,
        'score': score
    }

results = []
for func_name, doc_path, details in issues:
    r = analyze_func(func_name, doc_path, details)
    results.append(r)

# Sort by score (highest concern first)
results.sort(key=lambda x: -x['score'])

print("=== TOP POTENTIAL ISSUES (sorted by concern) ===\n")
for r in results[:30]:
    if r['score'] < 1:
        break
    print(f"{r['func']} (score={r['score']:.0f}) — {r['doc']}")
    if r['extra_calls']:
        print(f"  EXTRA_CALLS (in doc but not in source): {', '.join(sorted(r['extra_calls'])[:5])}")
    if r['missing_calls']:
        c = sorted(r['missing_calls'])[:5]
        print(f"  MISSING_CALLS: {', '.join(c)}")
    if r['missing_globals']:
        g = sorted(r['missing_globals'])[:3]
        print(f"  MISSING_GLOBALS: {', '.join(g)}")
    if r['extra_globals']:
        e = sorted(r['extra_globals'])[:3]
        print(f"  EXTRA_GLOBALS: {', '.join(e)}")
    print()

print("=== ALL EXTRA_CALLS (most likely real errors) ===\n")
for r in results:
    if r['extra_calls']:
        print(f"{r['func']}: {', '.join(sorted(r['extra_calls']))}")
        
print("\n=== FUNCTIONS WITH BOTH MISSING+GLOBALS AND EXTRA_CALLS ===\n")
for r in results:
    if r['extra_calls'] and r['missing_globals']:
        print(f"{r['func']} — extra calls + missing globals")
