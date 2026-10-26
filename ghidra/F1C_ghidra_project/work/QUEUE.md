# Work Queue — F1C Reverse Engineering

Last verified: 2026-07-14 (post-restructure).

> **New:** `work/PLAN_source_recovery.md` — source-level knowledge recovery tracks (rF1 SDK mapping,
> assert source map, console symbol harvest, binary diffing, signature matching). Track order in that
> file is authoritative for that workstream.

---

## Current State (as of 2026-07-14)

```
Directory layout (restructured 2026-07-14):
  analyzed/           903 .c files  — have ## FUN_ entry in docs/
  not_analyzed/     5,213 .c files  — work queue for DeepSeek workers
  decompiled_all/     656 .c files  — string-anchored, mostly documented

Triage index (docs/decompiled_full_index_final.md):
  Total unique addresses: 5,373
    math_util:      1,846
    unknown:        1,038   <- needs reclassification
    game_logic:       918   <- highest value; 621 still lack ## FUN_ entry
    collision:        360
    physics_math:     165
    non-standard:   1,046   <- from old merged batch, need category remap

not_analyzed/ breakdown:
  worthy (>=2KB):     426   <- worker priority
  stubs  (<2KB):    4,787   <- low priority, skip unless time permits

Worker queues (5 workers x ~85 files):
  work/worker_queue_1.txt .. work/worker_queue_5.txt
  Regenerate: python scripts/assign_batches.py --workers 5 --priority-only
```

---

## Priority 1 — Second-pass classify "unknown" triage entries

**Who:** DS V4 Flash (roles/WORKER.md)

918 entries are tagged `game_logic` in the index but have NO full `## FUN_` entry yet.
1,038 are tagged `unknown` — need reclassification with deeper read.

**How:**
1. Open `docs/decompiled_full_index_final.md`
2. For each `game_logic = yes` row with `Doc = --`: read the .c file in `decompiled_full/`, write a full `## FUN_` entry in the appropriate doc file (01–21)
3. For each `unknown` row: re-read the .c file, reclassify, upgrade if game_logic

Start with the 918 confirmed game_logic rows — highest signal.

---

## Priority 2 — Analyze 115 large unanalyzed files

**Who:** DS V4 Flash (roles/WORKER.md)

These files have NOT been triaged at all and are large enough to contain important game subsystems.

**How:**
```
python -c "
import os, re, subprocess
from collections import defaultdict

analyzed_dir = '%USERPROFILE%/Desktop/F1C_ghidra_project/decompiled_full'
result = subprocess.run(['grep', '-rh', '^## FUN_',
    '%USERPROFILE%/Desktop/F1C_ghidra_project/docs/',
    '%USERPROFILE%/Desktop/F1C_ghidra_project/work/'],
    capture_output=True, text=True)
analyzed = set(re.findall(r'## FUN_([0-9a-fA-F]+)', result.stdout))
all_files = [f for f in os.listdir(analyzed_dir) if f.endswith('.c')]
def addr(f): m = re.search(r'FUN_([0-9a-fA-F]+)', f); return m.group(1) if m else None
large = sorted([(os.path.getsize(os.path.join(analyzed_dir,f)),f) for f in all_files
                if addr(f) not in analyzed and os.path.getsize(os.path.join(analyzed_dir,f))>5000],
               reverse=True)
for sz, f in large: print(f'{sz:6d}  {f}')
"
```

Top 5 unanalyzed by size (2026-07-14):
| File | Size | Address range | Likely subsystem |
|------|------|---------------|-----------------|
| 0x004270a0__FUN_004270a0.c | 50KB | 0x004270a0 | AI / session manager |
| 0x0052b561__FUN_0052b561.c | 49KB | 0x0052b561 | Engine internals |
| 0x00532aa0__FUN_00532aa0.c | 49KB | 0x00532aa0 | Vehicle setup / engine |
| 0x0052e6f0__FUN_0052e6f0.c | 43KB | 0x0052e6f0 | Engine / damage |
| 0x0043f7f0__FUN_0043f7f0.c | 35KB | 0x0043f7f0 | Core game loop / AI |

**Output:** For each large file — triage line in `decompiled_full_index_final.md` + full `## FUN_` entry in appropriate doc if game_logic.

---

## Priority 3 — Upgrade ~470 table-row entries in docs/ (decompiled_all)

**Who:** DS V4 Flash (roles/WORKER.md, Mode 1)

470 functions in docs/ exist as one-liner table rows only. Upgrade each to `### FUN_` format with 2–4 key logic bullets and calls list.

Find them:
```
grep -rn "^| 0x\|^| FUN_" docs/*.md
```

Work by file, largest first:
1. `docs/08-file-formats.md`
2. `docs/06-session-race-logic.md`
3. `docs/09-track-system.md`
4. `docs/10-vehicle-physics.md`
5. Remaining (01–05, 07)

---

## Priority 4 — Write architecture narratives in docs/17–21

**Who:** DS V4 Flash after Priority 1–2 reveal more functions

Files exist but contain only indexed entries (## FUN_ blocks), no narrative architecture sections yet:
- `docs/17-physics-collision.md` — collision pipeline call graph
- `docs/18-physics-dynamics.md` — integration loop, tire model structure
- `docs/19-renderer.md` — D3D render loop, material system
- `docs/21-audio-network-internals.md` — sound triggers, network packet format

Use representative ## FUN_ entries already in each file to write a system-level narrative at the top.

---

## Priority 5 — Lead: Document confirmed game-logic functions

**Who:** GLM-5.2 (roles/LEAD.md), Phase 2

After Priority 1 surfaces game_logic entries, Lead expands them with human-readable commentary.

Known confirmed game-logic (high priority):

| Address | Evidence |
|---------|----------|
| 0x00424e70 | DAT_007c56a8 (RacePhase), calls FUN_0042a180 (AI rain) |
| 0x00425920 | DAT_007c56a4 (SessionType), AI overtaking state machine |
| 0x0041c0f0 | DAT_005c329c (VehicleCount), commentary trigger |
| 0x00424790 | DAT_007c56a4, calls FUN_00424080 (AI loader), AI init |

---

## Backlog — Physics constant tracing

Low priority. Only after coverage is substantially complete.

- Trace `DAT_0059e4xx` constants (engine power scaling, tire grip limits)
- Identify `DAT_008afee8` / `DAT_008afeec` (aero/tire parameter blocks)
- Find computation source for reference speed `DAT_005ea3d8`

---

## Priority 0 — RE Line Playback Mod (2026-07-20)

**Who:** Architect (interactive session with live game)

Press hotkey → specific race engineer line plays in-game. Commentary controller fully
decoded at `0x005EA618`. Poke-test event injection into queue, then build hotkey DLL.
See `work/HANDOFF_2026-07-20_live-audit-commentary.md` Priority 1 for details.

---

## Priority 0b — Poke-Prove Engine Blowup in Race

**Who:** Architect (interactive session, must be in race SessionType==7)

Write FinishState=2 + ReasonCode=1 to player vehicle. facts.json at
`mods/engine_blowup/facts.json`. If poke works, build SPACE hotkey DLL from
`ai_pit_retire` skeleton.

---

## Completed (do not re-assign)

- All 656 `decompiled_all` functions categorized
- 4,308 `decompiled_full` functions triaged into index (math_util/collision/physics/game_logic/unknown)
- 17 domain docs written (docs/01–16) covering all major game systems
- All known moddable fields → `docs/16-moddable-fields.md`
- All known globals → `docs/12-globals-reference.md`
- All known struct offsets → `docs/13-struct-offsets.md`
- Live memory audit: 13 confirmed offsets, 7 disproven claims → `docs/38-confirmed-offsets.md` (2026-07-20)
- Commentary system fully decoded: 295 events, 42 generators, SDT clip mapping (2026-07-20)
- Engine internals doc files created: 17-physics-collision, 18-physics-dynamics, 19-renderer, 20-math-utilities, 21-audio-network-internals
- 399 full-review entries from `docs/22-full-review-findings.md` routed to permanent doc files (2026-07-14)
  - 18-physics-dynamics: +20, 19-renderer: +20, 21-audio-network-internals: +42
  - 20-math-utilities: +180, 08-file-formats: +49, 06-session-race-logic: +88
