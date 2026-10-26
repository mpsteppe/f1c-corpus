r"""
gen_worker_prompts.py — chunk each game's staged delta .c files into N worker
prompts (F1C-grade WORKER_DELTA pipeline). Also seeds the per-game docs/ skeleton.

Usage: python cross_binary/scripts/gen_worker_prompts.py [workers_per_game]
"""
import os, sys, glob, math

ROOT = r'%USERPROFILE%\Desktop\F1C_ghidra_project'
ROLE = os.path.join(ROOT, 'cross_binary', 'WORKER_DELTA.md')
GAMES = {
  'f1_2002': 'source_material/F1 2002',
  'nascar03': 'source_material/Nascar Thunder 2003',
  'nascar04': 'source_material/Nascar Thunder 2004',
  'scgt': 'source_material/Sports Car GT',
}
DOCS = {
  '40-gameplay.md':     '# 40 — Gameplay / Race Control / Career (sibling-exclusive)\n\nFunctions present in this game but absent from F1C. See ../../../cross_binary/WORKER_DELTA.md.\n',
  '41-engine.md':       '# 41 — Physics / Collision / Math (sibling-exclusive)\n',
  '42-presentation.md': '# 42 — Renderer / Audio / UI (sibling-exclusive)\n',
  '43-io.md':           '# 43 — Network / Replay / File I/O (sibling-exclusive)\n',
  'decompiled_index.md': '# Delta triage index — functions absent from F1C\n\n| Addr | Lines | Category | Purpose | Port? | Doc |\n|------|-------|----------|---------|-------|-----|\n',
}

RULES = """## HARD RULES (violating any breaks the merge)
1. WRITE ONLY to your output file below. NEVER touch any file under docs/.
2. One function = one write, immediately. Never batch at the end. Do all listed.
3. NEVER spawn a subagent/task. Do the work yourself.
4. Header is exactly `## sub_XXXXXXXX` (lowercase, 8 hex from the filename). Not FUN_/Unwind_/thunk_.
5. Target comment exactly `<!-- target: docs/40-gameplay.md -->` (one .md). Group entries by target.
6. Source is IDA Hex-Rays. Full role spec + GOLD-STANDARD EXAMPLE: read it first.
7. Route: gameplay/race-control/career/penalty->docs/40-gameplay.md ; physics/collision/math->docs/41-engine.md ; renderer/audio/ui/hud->docs/42-presentation.md ; network/replay/file->docs/43-io.md
"""

def allocate(counts, total):
    """largest-remainder proportional allocation, min 1 per game."""
    s = sum(counts.values())
    raw = {g: max(1, c / s * total) for g, c in counts.items()}
    base = {g: int(v) for g, v in raw.items()}
    rem = total - sum(base.values())
    for g in sorted(raw, key=lambda g: raw[g] - base[g], reverse=True):
        if rem <= 0: break
        base[g] += 1; rem -= 1
    return base

def main():
    total = int(sys.argv[1]) if len(sys.argv) > 1 else 20
    letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    filemap = {}
    for game, gdir in GAMES.items():
        files = sorted(glob.glob(os.path.join(gdir, 'pipeline', 'not_analyzed', '*.c')))
        if files:
            filemap[game] = files
        docsdir = os.path.join(gdir, 'docs'); os.makedirs(docsdir, exist_ok=True)
        for fn, hdr in DOCS.items():
            p = os.path.join(docsdir, fn)
            if not os.path.exists(p):
                open(p, 'w', encoding='utf-8').write(hdr)
    alloc = allocate({g: len(f) for g, f in filemap.items()}, total)
    li = 0
    for game, files in filemap.items():
        gdir = GAMES[game]; nw = alloc[game]
        per = math.ceil(len(files) / nw)
        promptdir = os.path.join(gdir, 'pipeline', 'prompts'); os.makedirs(promptdir, exist_ok=True)
        made = 0
        for i in range(nw):
            chunk = files[i*per:(i+1)*per]
            if not chunk:
                break
            L = letters[li]; li += 1; made += 1
            out = os.path.join(gdir, 'pipeline', 'output', f'worker_{L}.md')
            lines = [
                f'# Worker {L} — {game} delta documentation ({len(chunk)} functions)',
                '', f'ROLE SPEC (read first, has the gold-standard example): `{ROLE}`',
                '', f'WRITE OUTPUT ONLY TO: `{out}`', '', RULES, '',
                f'## Your {len(chunk)} assigned functions — read each, write one `## sub_` entry:', '',
            ]
            for j, f in enumerate(chunk, 1):
                lines.append(f'{j}. {f}')
            open(os.path.join(promptdir, f'worker_{L}_prompt.md'), 'w', encoding='utf-8').write('\n'.join(lines))
        print(f'{game}: {len(files)} funcs -> workers {letters[li-made:li]} (~{per} each)')

if __name__ == '__main__':
    main()
