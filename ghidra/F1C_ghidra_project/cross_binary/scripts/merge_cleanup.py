r"""
merge_cleanup.py — apply xbin_cleanup worker patches to per-game docs.

Reads analysis_pipeline/output/xbin_cleanup/worker_*.md, each patch:
  <!-- patch: <game>/<doc> sub_XXXXXXXX -->
  **F1C status:** ...
  **Port:** ...
Finds the matching entry in source_material/<game>/docs/<doc> and appends the
field line(s) at the END of that entry (only if not already present).

Run: python cross_binary/scripts/merge_cleanup.py
"""
import os, re, glob, shutil, time

ROOT = r'%USERPROFILE%\Desktop\F1C_ghidra_project'
OUTDIR = os.path.join(ROOT, 'analysis_pipeline', 'output', 'xbin_cleanup')
GAMES = {'f1_2002': 'F1 2002', 'nascar03': 'Nascar Thunder 2003',
         'nascar04': 'Nascar Thunder 2004', 'scgt': 'Sports Car GT'}

def read(p):
    for enc in ('utf-8', 'utf-8-sig', 'cp1252', 'latin-1'):
        try: return open(p, encoding=enc, errors='replace').read()
        except OSError: return ''
    return ''

def main():
    applied, skipped = 0, 0
    for wf in sorted(glob.glob(os.path.join(OUTDIR, 'worker_*.md'))):
        txt = read(wf)
        # each patch: header + following field lines up to next patch/### or EOF
        blocks = re.split(r'<!-- patch:\s*([a-z0-9_]+)/([\w\-.]+\.md)\s+sub_([0-9a-fA-F]{8})\s*-->', txt)
        i = 1
        while i + 3 <= len(blocks):
            game, doc, addr, body = blocks[i], blocks[i+1], blocks[i+2].lower(), blocks[i+3]
            i += 4
            if game not in GAMES:
                continue
            fields = re.findall(r'^\s*(\*\*(?:F1C status|Port)[^\n]*)', body, re.M)
            if not fields:
                continue
            docpath = os.path.join(ROOT, 'source_material', GAMES[game], 'docs', os.path.basename(doc))
            if not os.path.exists(docpath):
                skipped += 1; continue
            content = read(docpath)
            parts = re.split(r'(?m)(?=^## sub_[0-9a-fA-F]{8})', content)
            changed = False
            for k, p in enumerate(parts):
                if re.match(rf'## sub_{addr}', p):
                    add = []
                    for f in fields:
                        key = 'F1C status' if 'F1C status' in f else 'Port'
                        if key not in p:
                            add.append(f.rstrip())
                    if add:
                        parts[k] = p.rstrip() + '\n' + '\n'.join(add) + '\n'
                        changed = True; applied += 1
                    break
            if changed:
                open(docpath, 'w', encoding='utf-8').write(''.join(parts))
        arch = os.path.join(OUTDIR, 'archive', time.strftime('%Y%m%d_%H%M%S'))
        os.makedirs(arch, exist_ok=True)
        shutil.move(wf, os.path.join(arch, os.path.basename(wf)))
    print(f'cleanup: applied {applied} field patches ({skipped} skipped)')

if __name__ == '__main__':
    main()
