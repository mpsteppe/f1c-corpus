"""
Cross-validation v2: more accurate, filters noise, finds real errors.
"""
import re, os, json

prompt_path = r'%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\prompts\cross_validate_2\worker_N_prompt.md'
cg_path = r'%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json'
d12_path = r'%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md'

# Load call graph
cg = {}
try:
    with open(cg_path, encoding='utf-8') as f:
        cg = json.load(f)
except:
    pass

# Parse functions from prompt
functions = []
with open(prompt_path, encoding='utf-8') as f:
    content = f.read()

pattern = r'(\d+)\.\s*(FUN_[0-9A-Fa-f]+)\s*\n\s*doc:\s*(docs/\S+)\s*\n\s*source:\s*(\S+)'
for m in re.finditer(pattern, content):
    num, func, doc_path, source_path = m.groups()
    functions.append({
        'num': int(num),
        'func': func,
        'doc': doc_path,
        'source': source_path
    })

def get_func_section(doc_content, func_name):
    """Find the section for a function in a doc file."""
    addr_lower = func_name[4:].lower()
    # Try various heading patterns with lowercase (most docs use lowercase hex)
    patterns = [
        rf'^## +FUN_{addr_lower} +',
        rf'^### +FUN_{addr_lower} +',
        rf'^#### +FUN_{addr_lower} +',
        rf'^## +FUN_{addr_lower}$',
        rf'^### +FUN_{addr_lower}$',
        rf'^#### +FUN_{addr_lower}$',
    ]
    
    for pat in patterns:
        m = re.search(pat, doc_content, re.MULTILINE | re.IGNORECASE)
        if m:
            start = m.start()
            # Search for NEXT section heading (any level) starting AFTER this heading
            after_heading = doc_content[m.end():]
            end_m = re.search(r'^#+\s', after_heading, re.MULTILINE)
            if end_m:
                end = m.end() + end_m.start()
            else:
                end = len(doc_content)
            section = doc_content[start:end]
            return section
    return None

def extract_calls_from_source(code):
    """Extract FUN_ calls from source, excluding self-references."""
    func_name = ''
    m = re.search(r'FUN_([0-9A-Fa-f]{8})', code[:100])
    if m:
        func_name = f'FUN_{m.group(1).upper()}'
    
    calls = set()
    for cm in re.finditer(r'(FUN_[0-9A-Fa-f]{8})', code):
        calls.add(cm.group(1).upper())
    
    # Remove self-reference
    calls.discard(func_name)
    return calls

def extract_calls_from_section(section):
    """Extract FUN_ calls mentioned in doc section."""
    calls = set()
    for cm in re.finditer(r'(FUN_[0-9A-Fa-f]{8})', section):
        calls.add(cm.group(1).upper())
    return calls

def extract_globals_from_source(code):
    """Extract DAT_ globals from source."""
    globals_found = set()
    for gm in re.finditer(r'(DAT_[0-9A-Fa-f]{8})', code):
        g = gm.group(1).upper()
        # Skip debug strings
        if g not in {'DAT_008AD25C', 'DAT_005C56A4', 'DAT_005C5734', 'DAT_005C3590', 
                     'DAT_005C3628', 'DAT_005BE958', 'DAT_005BE980'}:
            globals_found.add(g)
    return globals_found

def extract_globals_from_section(section):
    """Extract DAT_ globals mentioned in doc section."""
    globals_found = set()
    for gm in re.finditer(r'(DAT_[0-9A-Fa-f]{8})', section):
        g = gm.group(1).upper()
        if g not in {'DAT_008AD25C', 'DAT_005C56A4', 'DAT_005C5734', 'DAT_005C3590',
                     'DAT_005C3628', 'DAT_005BE958', 'DAT_005BE980'}:
            globals_found.add(g)
    return globals_found

# Process functions
errors_found = []
extras_found = []

for i, f in enumerate(functions):
    if i >= 350:
        break
    
    func_name_upper = f['func'].upper()
    addr = func_name_upper.replace('FUN_', '0x')
    
    # Read source
    source_path = f['source']
    if not os.path.exists(source_path):
        continue
    
    try:
        with open(source_path, encoding='utf-8', errors='replace') as fp:
            code = fp.read()
    except:
        continue
    
    actual_calls = extract_calls_from_source(code)
    actual_globals = extract_globals_from_source(code)
    
    # Read doc and find section
    doc_full_path = rf'%USERPROFILE%\Desktop\F1C_ghidra_project\{f["doc"]}'
    if not os.path.exists(doc_full_path):
        continue
    
    try:
        with open(doc_full_path, encoding='utf-8', errors='replace') as fp:
            doc_content = fp.read()
    except:
        continue
    
    section = get_func_section(doc_content, func_name_upper)
    if not section:
        # Try case-insensitive by lowering both
        section = get_func_section(doc_content.lower(), func_name_upper.lower())
    if not section:
        # Final fallback: IGNORECASE search for any heading with this address
        addr_lower = func_name_upper[4:].lower()
        m = re.search(rf'^#+\s+FUN_{addr_lower}\s', doc_content, re.MULTILINE | re.IGNORECASE)
        if m:
            start = m.start()
            rest = doc_content[start+1:]
            end_m = re.search(r'^##?\s', rest, re.MULTILINE)
            if end_m:
                end = start + 1 + end_m.start()
            else:
                end = len(doc_content)
            section = doc_content[start:end]
    if not section:
        continue
    
    doc_calls = extract_calls_from_section(section)
    doc_globals = extract_globals_from_section(section)
    
    # Find what's in source but not in doc
    missing_calls = actual_calls - doc_calls
    extra_calls = doc_calls - actual_calls
    missing_globals = actual_globals - doc_globals
    extra_globals = doc_globals - actual_globals
    
    # Filter out thunk pointer references (like PTR_FUN_ or &FUN_ patterns)
    extra_calls = {c for c in extra_calls if c[:4] == 'FUN_'}
    
    # Built a concern score
    concern = len(extra_calls) * 5 + len(missing_calls) * 0.5 + len(extra_globals) * 3 + len(missing_globals) * 0.3
    
    if extra_calls or extra_globals or concern > 5:
        entry = {
            'func': func_name_upper,
            'doc': f['doc'],
            'missing_calls': missing_calls,
            'extra_calls': extra_calls,
            'missing_globals': missing_globals,
            'extra_globals': extra_globals,
            'concern': concern,
            'actual_calls_count': len(actual_calls),
            'doc_calls_count': len(doc_calls),
        }
        errors_found.append(entry)
        if extra_calls or extra_globals:
            extras_found.append(entry)

errors_found.sort(key=lambda x: -x['concern'])

print(f"Functions processed: {len(functions)}")
print(f"Functions with issues: {len(errors_found)}")
print(f"Functions with EXTRAS (likely real errors): {len(extras_found)}")
print()

print("=== HIGHEST CONCERN (likely real errors) ===\n")
for e in errors_found[:25]:
    print(f"{e['func']} (concern={e['concern']:.0f}) — {e['doc']}")
    if e['extra_calls']:
        print(f"  CALLS IN DOC NOT IN SOURCE: {', '.join(sorted(e['extra_calls']))}")
    if e['extra_globals']:
        print(f"  GLOBALS IN DOC NOT IN SOURCE: {', '.join(sorted(e['extra_globals']))}")
    if e['missing_calls'] and e['concern'] > 3:
        mc = list(e['missing_calls'])[:3]
        print(f"  MISSING FROM DOC: {', '.join(mc)}")
    if e['missing_globals'] and e['concern'] > 3:
        mg = list(e['missing_globals'])[:3]
        print(f"  GLOBALS MISSING FROM DOC: {', '.join(mg)}")
    print(f"  Source calls: {e['actual_calls_count']}, Doc lists: {e['doc_calls_count']}")
    print()

print("=== EXTRA CALLS SUMMARY ===\n")
for e in extras_found:
    print(f"{e['func']}: extra calls = {', '.join(sorted(e['extra_calls']))}")
