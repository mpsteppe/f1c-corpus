r"""
merge_xbin_delta.py — merge the batch_gui "Sibling Delta" mode output.

Reads analysis_pipeline/output/xbin_delta/worker_*.md, routes each entry by its
game-qualified target comment `<!-- target: <game>/<doc>.md -->` to
source_material/<game>/docs/<doc>.md. Triage lines -> per-game decompiled_index.md.
Dedups by '## sub_' header, moves processed .c to that game's analyzed/, archives.

Run: python cross_binary/scripts/merge_xbin_delta.py
"""
import os, re, glob, shutil, time

ROOT = r'%USERPROFILE%\Desktop\F1C_ghidra_project'
OUTDIR = os.path.join(ROOT, 'analysis_pipeline', 'output', 'xbin_delta')
GAMES = {
    'f1_2002':  'F1 2002',
    'nascar03': 'Nascar Thunder 2003',
    'nascar04': 'Nascar Thunder 2004',
    'scgt':     'Sports Car GT',
}

def read(p):
    for enc in ('utf-8', 'utf-8-sig', 'cp1252', 'latin-1'):
        try: return open(p, encoding=enc, errors='replace').read()
        except OSError: return ''
    return ''

def gdir(game): return os.path.join(ROOT, 'source_material', GAMES[game])
def existing(path):
    if not os.path.exists(path): return set()
    return set(m.lower() for m in re.findall(r'^#{2,3} sub_([0-9a-fA-F]{8})', read(path), re.M))

def build_addr_game_map():
    """addr -> set(games) it belongs to (from each game's decompiled corpus)."""
    m = {}
    for key, sub in GAMES.items():
        for p in glob.glob(os.path.join(ROOT, 'source_material', sub, 'decompiled', '*.c')):
            g = re.search(r'0x([0-9a-fA-F]+)__', os.path.basename(p))
            if g:
                m.setdefault('0x' + g.group(1).lower().zfill(8), set()).add(key)
    return m

def infer_worker_game(text, amap):
    """single-game workers: pick the game holding the plurality of this file's addrs."""
    votes = {}
    for a in re.findall(r'^#{2,3} sub_([0-9a-fA-F]{8})', text, re.M):
        for g in amap.get('0x' + a.lower(), ()):
            votes[g] = votes.get(g, 0) + 1
    # also count explicit game-qualified targets present
    for g in re.findall(r'<!-- target:\s*([a-z0-9_]+)/', text):
        if g in GAMES:
            votes[g] = votes.get(g, 0) + 5
    return max(votes, key=votes.get) if votes else None

VALID_ADDR = re.compile(r'^[0-9a-fA-F]{8}$')

def main():
    amap = build_addr_game_map()
    tri, full, bad_addr, salvaged = 0, 0, [], 0
    for wf in sorted(glob.glob(os.path.join(OUTDIR, 'worker_*.md'))):
        content = read(wf)
        wgame = infer_worker_game(content, amap)   # this worker's single game
        head, _, tail = content.partition('=== FULL ENTRIES ===')
        # triage lines -> per-game index; game from last col, else worker game
        for line in re.findall(r'^\| 0x[0-9a-fA-F]+.*$', head, re.M):
            m = re.search(r'\|\s*([a-z0-9_]+)/[\w\-.]+\.md\s*\|?\s*$', line)
            game = m.group(1) if m and m.group(1) in GAMES else wgame
            if game:
                open(os.path.join(gdir(game), 'docs', 'decompiled_index.md'), 'a',
                     encoding='utf-8').write(line.rstrip() + '\n'); tri += 1
        # full entries: split on ANY target marker (game-qualified OR bare docs/)
        parts = re.split(r'<!-- target:\s*(?:([a-z0-9_]+)/)?([\w\-.]+\.md)\s*-->', tail)
        i = 1
        while i + 2 <= len(parts):
            game, doc, text = parts[i], parts[i+1], parts[i+2]
            i += 3
            if game not in GAMES:            # bare docs/NN.md -> infer from worker
                game = wgame
                if game:
                    salvaged += len(re.findall(r'^#{2,3} sub_', text, re.M))
            if game not in GAMES:
                continue
            doc = os.path.basename(doc)      # strip any docs/ prefix
            docpath = os.path.join(gdir(game), 'docs', doc)
            have = existing(docpath)
            for m in re.finditer(r'(^#{2,3} sub_([0-9a-fA-F]+).*?)(?=^#{2,3} sub_|\Z)', text, re.M | re.S):
                addr = m.group(2).lower()
                if not VALID_ADDR.match(addr):
                    bad_addr.append((os.path.basename(wf), addr)); continue
                if addr in have:
                    continue
                os.makedirs(os.path.dirname(docpath), exist_ok=True)
                open(docpath, 'a', encoding='utf-8').write('\n\n' + m.group(1).rstrip() + '\n')
                have.add(addr); full += 1
                for c in glob.glob(os.path.join(gdir(game), 'pipeline', 'not_analyzed', f'0x{addr}__*.c')):
                    dst = os.path.join(gdir(game), 'pipeline', 'analyzed')
                    os.makedirs(dst, exist_ok=True)
                    shutil.move(c, os.path.join(dst, os.path.basename(c)))
        arch = os.path.join(OUTDIR, 'archive', time.strftime('%Y%m%d_%H%M%S'))
        os.makedirs(arch, exist_ok=True)
        shutil.move(wf, os.path.join(arch, os.path.basename(wf)))
    print(f'merged: +{tri} triage, +{full} full entries ({salvaged} salvaged from bare docs/ targets)')
    if bad_addr:
        print(f'SKIPPED {len(bad_addr)} malformed addresses (manual review): {bad_addr[:10]}')

if __name__ == '__main__':
    main()
