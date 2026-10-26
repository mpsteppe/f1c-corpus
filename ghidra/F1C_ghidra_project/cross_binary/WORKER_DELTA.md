# WORKER — Cross-Binary Delta Documentation (DeepSeek V4)

Document functions that exist in an isiMotor1 sibling game (NASCAR Thunder 03/04,
F1 2002, Sports Car GT) but do **NOT** exist in F1 Challenge 99-02. These are the
"bricks F1C is missing." Same rigor as the F1C documentation.

═══════════════════════════════════════════════════════════════════════
## HARD RULES — violating any of these breaks the merge. Read twice.
═══════════════════════════════════════════════════════════════════════

1. **WRITE ONLY to your `pipeline/output/worker_<LETTER>.md` file.**
   NEVER open, edit, or write any file under `docs/`. The merge script moves your
   entries into `docs/` later. If you write to `docs/` directly you corrupt the docs.
2. **One function = one write, immediately.** After you analyze a function, append its
   entry to your output file BEFORE reading the next. Never hold entries in memory to
   "write at the end." Never end with entries "ready to insert."
3. **NEVER spawn a subagent / task / helper.** You do the work directly. No delegation.
4. **Every entry header is exactly `## sub_XXXXXXXX`** (h2, lowercase `sub_`, 8 hex
   digits, the address from the filename). NOT `## FUN_`, NOT `## Unwind_`, NOT
   `## thunk_`, NOT a function's guessed name. The 8-hex address is in the `.c` filename:
   `0x0042e540__sub_42E540.c` → header `## sub_0042e540`.
5. **Target comment is exactly** `<!-- target: docs/40-gameplay.md -->` — one `.md`,
   never `.md.md`, path relative like that. Put it once before each group of entries
   going to the same doc.
6. Read `.c` files ONLY from the numbered list in this prompt. Never read `analyzed/`.
   Never move or delete files.
7. Do not stop early. Process EVERY numbered function in your list.

═══════════════════════════════════════════════════════════════════════
## SOURCE FORMAT — IDA Hex-Rays (not Ghidra)
═══════════════════════════════════════════════════════════════════════

| Pattern | Meaning |
|---------|---------|
| `sub_XXXXXX` | a function |
| `__thiscall` / `this` | C++ method + object pointer |
| `dword_XXXX` `off_XXXX` `unk_XXXX` `flt_XXXX` | globals |
| `a2, a3` / `v5, v6` | params / locals |
| `*(_DWORD *)(this + 0x1234)` | struct field at byte offset 0x1234 |
| `*(float *)(this + 0x40)` | float field at +0x40 |
| `operator new(0xNN)` | object allocation; 0xNN = struct size |
| `aSomeString` | reference to a string literal named after its content |

═══════════════════════════════════════════════════════════════════════
## OUTPUT FILE STRUCTURE
═══════════════════════════════════════════════════════════════════════

Your `worker_<LETTER>.md` must look exactly like this:

```
=== TRIAGE LINES ===
| 0x0042e540 | 42 | game_mode | driving-school MAS loader | yes | docs/40-gameplay.md |
| 0x00447fc0 | 190 | physics_math | HAT terrain tree build | merge | docs/41-engine.md |
...one line per function...

=== FULL ENTRIES ===
<!-- target: docs/40-gameplay.md -->
## sub_0042e540 — Driving School: MAS Content Loader
...full entry...

## sub_00xxxxxx — Next Name
...

<!-- target: docs/41-engine.md -->
## sub_00447fc0 — HAT Terrain Tree Builder
...
```

Group full entries under the right `<!-- target -->` comment by category:
- game modes / race control / career / penalties → `docs/40-gameplay.md`
- physics / collision / math → `docs/41-engine.md`
- renderer / audio / UI / HUD → `docs/42-presentation.md`
- network / replay / file I/O → `docs/43-io.md`

Triage categories: `game_mode` `race_control` `career` `penalty` `physics_math`
`collision` `renderer` `audio` `ui` `network` `replay` `file_parser` `math_util` `unknown`

`port?` column and **Port:** field enum: `yes`(drop-in) / `merge` / `data-driven` / `no`.

═══════════════════════════════════════════════════════════════════════
## GOLD-STANDARD EXAMPLE — copy this shape exactly
═══════════════════════════════════════════════════════════════════════

For `0x004c9a50__sub_4C9A50.c` (NASCAR 03), the correct entry is:

```
## sub_004c9a50 — Flag / Caution State Machine

Source: NASCAR 2003 (0x004c9a50). raceevent.cpp. Full-course flag/caution state
transition handler — no F1C equivalent (F1C is green-flag only).

**Key logic:**
- `this+300` = current flag state (int). `a2` = requested new state.
- Entering/leaving state 7 → `sub_4EA350(0)` (flag broadcast).
- `a2==1` (raise caution): loops vehicle array `dword_611360[i]`, zeroes each car's
  caution field `+14336`, clears global `off_5BD508+3584`, resets caution sub-objects
  `this+344` / `this+428` via `sub_4C81B0`.
- Builds a 125-byte status-banner buffer.

**Struct offsets (this = Session):**
| Offset | Field | Notes |
|--------|-------|-------|
| +300 | flagState | int |
| +340 | cautionActiveByte | |
| +344 | cautionData A | sub-object |

**Globals:** `dword_611360` vehicle array base · `off_5BD508` global race state
**Calls:** sub_4EA350 (flag broadcast), sub_413E70 (flag-change notify), sub_4C81B0 (reset caution obj)
**F1C status:** absent — no full-course-yellow state in F1C.
**Port:** yes — self-contained flag machine; re-map vehicle/session offsets to F1C layout.
```

Match that depth: name from strings/behavior, key-logic bullets with real offsets &
globals, a struct-offset table when it touches object fields, the called subs, an
honest F1C-status and Port verdict. If a function is a tiny helper with no anchors,
a 2-line entry + triage line is fine — but still `## sub_` and still in the output file.
