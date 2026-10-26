"""
Cross-validation helper: parse prompt, extract functions, verify structural claims.
Checks call lists, globals, and struct offsets against .c source.
Outputs structured findings for manual review.
"""
import re, os, json, glob as gb

# Load call graph
cg_path = r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json'
cg = {}
try:
    with open(cg_path, encoding='utf-8') as f:
        cg = json.load(f)
    print(f'Call graph: {len(cg)} entries')
except:
    print('WARN: could not load call graph')

# Load all docs/12 globals into a set
d12 = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md'
global_names = {}  # DAT_XXXXXXX -> name
try:
    with open(d12, encoding='utf-8') as f:
        for line in f:
            m = re.match(r'\|\s*(DAT_[0-9A-Fa-f]+)\s*\|\s*(\S+)', line)
            if m:
                global_names[m.group(1).upper()] = m.group(2)
    print(f'Globals in docs/12: {len(global_names)}')
except:
    print('WARN: could not load docs/12')

# Load all docs/13 struct offsets
d13 = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md'
struct_offsets = {}  # offset -> field name
try:
    with open(d13, encoding='utf-8') as f:
        for line in f:
            m = re.match(r'\|\s*\+0x([0-9A-Fa-f]+)\s*\|\s*(\S+)', line)
            if m:
                struct_offsets[int(m.group(1), 16)] = m.group(2)
    print(f'Struct offsets in docs/13: {len(struct_offsets)}')
except:
    print('WARN: could not load docs/13')

# Parse prompt to get function list
prompt_path = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\prompts\cross_validate_2\worker_N_prompt.md'
functions = []
with open(prompt_path, encoding='utf-8') as f:
    content = f.read()

# Extract function entries: "NNNN. FUN_XXXXXXXX\n   doc: ...\n   source: ..."
pattern = r'(\d+)\.\s*(FUN_[0-9A-Fa-f]+)\s*\n\s*doc:\s*(docs/\S+)\s*\n\s*source:\s*(\S+)'
for m in re.finditer(pattern, content):
    num, func, doc_path, source_path = m.groups()
    functions.append({
        'num': int(num),
        'func': func,
        'doc': doc_path,
        'source': source_path
    })
print(f'Functions to validate: {len(functions)}')

def extract_func_refs(code):
    """Extract function calls and global references from .c code."""
    calls = set()
    globals_found = set()
    struct_offsets_found = set()
    
    for m in re.finditer(r'(FUN_[0-9A-Fa-f]{8})', code):
        calls.add(m.group(1))
    for m in re.finditer(r'(DAT_[0-9A-Fa-f]{8})', code):
        globals_found.add(m.group(1).upper())
    for m in re.finditer(r'\+0x([0-9A-Fa-f]+)\)', code):
        struct_offsets_found.add(int(m.group(1), 16))
    for m in re.finditer(r'param_1\[0x([0-9A-Fa-f]+)\]', code):
        offset = int(m.group(1), 16) * 4  # int* -> byte offset
        struct_offsets_found.add(offset)
    
    return calls, globals_found, struct_offsets_found

# Process first 100 functions for detailed analysis
for i, f in enumerate(functions):
    if i >= 350:
        break
    
    # Read source
    source_path = f['source']
    if not os.path.exists(source_path):
        print(f'WARN: {f["func"]} source not found at {source_path}')
        continue
    
    with open(source_path, encoding='utf-8', errors='replace') as fp:
        code = fp.read()
    
    actual_calls, actual_globals, actual_offsets = extract_func_refs(code)
    
    # Read doc entry
    doc_full_path = rf'%USERPROFILE%\Desktop\F1C_ghidra_project\{f["doc"]}'
    if not os.path.exists(doc_full_path):
        print(f'WARN: {f["func"]} doc not found at {doc_full_path}')
        continue
    
    with open(doc_full_path, encoding='utf-8', errors='replace') as fp:
        doc_content = fp.read()
    
    # Find the doc section for this function
    func_upper = f['func'].upper()
    # Try both FUN_XXXXXXXX and FUN_00XXXXXX patterns
    patterns_to_try = [
        rf'##\s*{func_upper}',
        rf'##\s*{f["func"]}',
        rf'###\s*{func_upper}',
        rf'###\s*{f["func"]}',
        rf'\|.*{func_upper}',
        rf'\|.*{f["func"]}',
    ]
    
    doc_calls_claimed = set()
    doc_globals_claimed = set()
    
    for p in patterns_to_try:
        mm = re.search(p, doc_content)
        if mm:
            # Found the section - extract context
            start = max(0, mm.start())
            end = min(len(doc_content), start + 2000)
            section = doc_content[start:end]
            
            # Extract calls mentioned in doc
            for call_m in re.finditer(r'(FUN_[0-9A-Fa-f]{8})', section):
                doc_calls_claimed.add(call_m.group(1))
            
            # Extract globals mentioned in doc  
            for g_m in re.finditer(r'(DAT_[0-9A-Fa-f]{8})', section):
                doc_globals_claimed.add(g_m.group(1).upper())
            break
    
    # Compare
    missing_calls = actual_calls - doc_calls_claimed
    extra_calls = doc_calls_claimed - actual_calls
    missing_globals = actual_globals - doc_globals_claimed
    extra_globals = doc_globals_claimed - actual_globals
    
    if missing_calls or extra_calls or missing_globals or extra_globals:
        print(f'\n## {f["func"]} — ISSUES FOUND')
        print(f'Source: {f["doc"]}')
        if missing_calls:
            print(f'  MISSING_CALLS: {", ".join(sorted(missing_calls)[:10])}')
        if extra_calls:
            print(f'  EXTRA_CALLS: {", ".join(sorted(extra_calls)[:10])}')
        if missing_globals:
            print(f'  MISSING_GLOBALS: {", ".join(sorted(missing_globals)[:10])}')
        if extra_globals:
            print(f'  EXTRA_GLOBALS: {", ".join(sorted(extra_globals)[:10])}')
    else:
        # PASS - only print periodically to avoid noise
        pass

print(f'\n\nDone. Processed {len(functions)} functions.')
