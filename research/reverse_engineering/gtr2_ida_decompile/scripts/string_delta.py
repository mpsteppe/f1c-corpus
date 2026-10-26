# Diff GTR2 vs F1C string tables: source-file names (__FILE__) and new strings.
import json, re, os, sys
g = json.load(open('strings_index.json', encoding='utf-8'))
f = json.load(open('%USERPROFILE%/Desktop/F1/f1c_ida_decompiled/strings_index.json', encoding='utf-8'))
T = lambda d: {v['s'] for v in d['strings'].values()}
gs, fs = T(g), T(f)
def cpp(S):
    return {os.path.basename(x.replace(chr(92), '/')).lower() for x in S if re.search(r'\.(cpp|h)$', x, re.I)}
gc, fc = cpp(gs), cpp(fs)
new = sorted(s for s in gs - fs if len(s) >= 6 and re.match(r'^[A-Za-z][\w %:.\-/()=,\[\]]+$', s))
json.dump({"gtr2_src": sorted(gc), "f1c_src": sorted(fc), "new_src": sorted(gc - fc),
           "new_strings": new}, open('string_delta.json', 'w', encoding='utf-8'), indent=0)
print('src GTR2', len(gc), 'F1C', len(fc), 'new', sorted(gc - fc))
print('new strings', len(new))
