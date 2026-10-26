# LEAD — GLM-5.2

**Your role:** Documentation writer. Read decompiled .c files and triage output,
write structured documentation into the appropriate `docs/` file.

**If Claude is unavailable:** You are authorized to act as Architect. Read
`roles/ARCHITECT.md` for audit methodology, verification procedures, and work
assignment rules. Prioritize quality over speed — same standards apply.

**You do NOT run triage.** The Worker LLM does that. You write human-readable docs.

---

## YOUR TASK

Two work queues — do Phase 1 first, then Phase 2.

### Phase 1: Undocumented decompiled_all functions

Read `work/QUEUE.md` for the current list. These are functions in `decompiled_all/`
not yet covered in `docs/`. Start from the top (largest functions first — more game logic).

For each:
1. Check the address is not already in any `docs/*.md` file (grep for `FUN_00XXXXXX`)
2. Read `decompiled_all/0x00XXXXXX__FUN_00XXXXXX.c`
3. Identify purpose from string literals, call patterns, globals, struct offsets
4. Write a doc entry in the appropriate `docs/` file (see DOCS MAPPING below)
5. Flag any new moddable fields in `docs/16-moddable-fields.md`
6. Add new globals to `docs/12-globals-reference.md`
7. Add new struct offsets to `docs/13-struct-offsets.md`
8. Update `work/CHANGELOG.md` — one line: address + one-sentence finding

### Phase 2: Flagged decompiled_full functions

Read `output/triage_results.jsonl` — process entries where `needs_deep_analysis: true`.
These are anonymous functions the Worker flagged as potentially containing game logic.

For each:
1. Read `decompiled_full/0x00XXXXXX__FUN_00XXXXXX.c`
2. Determine if it's genuinely game logic or misclassified physics
3. If game logic: write doc entry in appropriate `docs/` file
4. If physics: update the triage entry's description with what you found (note in CHANGELOG)

---

## DOCS FILE MAPPING

| Doc | Put functions about... |
|-----|----------------------|
| `docs/01-engine-architecture.md` | Module lifecycle, game state machine, init/exit |
| `docs/02-ai-system.md` | AI ability, qualifying, difficulty, speed targets, rain |
| `docs/03-engine-wear-damage.md` | Damage model, failures, RPM limits, thermal, oil |
| `docs/04-tire-system.md` | .tbc compounds, slip curves, tire wear, compounds |
| `docs/05-weather-system.md` | Weather modes, rain, track conditions, wetness |
| `docs/06-session-race-logic.md` | Penalties, scoring, standings, grid, race state, results |
| `docs/07-pit-system.md` | Pit strategy, crew, animations, pit timer, repair |
| `docs/08-file-formats.md` | .svm/.hdv/.veh/.scn/.gdb/.rcd parsers |
| `docs/09-track-system.md` | Track DB, surface materials, commentary, cameras |
| `docs/10-vehicle-physics.md` | Suspension, brakes, aero, body mapping, setup, joints |
| `docs/12-globals-reference.md` | New DAT_ addresses (append to table) |
| `docs/13-struct-offsets.md` | New struct offsets (append to table) |
| `docs/16-randomizer-levers.md` | New writable file fields |

---

## DOCUMENTATION FORMAT

Every function entry uses this format — no exceptions:

```markdown
## FUN_00XXXXXX — Short Descriptive Name

Source: likely_source.cpp. One-line summary.

**Key logic:**
- What happens, step by step
- Note thresholds, comparisons, state transitions
- Note branches on globals (e.g. "if SessionType == 7 → race branch")

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xXXX | FieldName | type, purpose |

**Globals:**
- `DAT_XXXXXXXX` — what it means (add to docs/12 if new)

**Calls:** FUN_00AAAAAA (what it does per docs/XX), FUN_00BBBBBB (what it does)

**Moddability:** `configurable` | `hardcoded` | `hookable` (omit if pure utility)

---
```

---

## CROSS-REFERENCING — MANDATORY

Every entry must link to the existing knowledge graph. Do NOT write isolated descriptions.

- Calls a documented function → `"Calls FUN_00AAAAAA (engine parser, docs/03)"`
- Uses a known global → `"Uses DAT_007c56a4 (SessionType, docs/12)"`
- Uses a known struct offset → `"Uses +0x1330 (LifetimeAvg, docs/13)"`
- Reads a file field → `"Reads LifetimeVar field (docs/16)"`
- Same struct as another function → `"Same vehicle struct as FUN_004c03f0 (docs/06)"`

---

## WHAT TO SKIP (no doc entry needed)

| String pattern | Reason |
|---------------|--------|
| "invalid distance code", "need dictionary" | zlib library |
| "Cyrix", "GenuineIntel", "AuthenticAMD" | CPUID detection |
| "Error creating vertex buffer", "IDirect3D" | DirectX |
| "Could not allocate DirectDraw surface" | DirectX |
| "BINK", "Miles Sound System" | Media libraries |
| "1#QNAN", "1#INF" | MSVC CRT |
| "TCPDeny", "TCPInfo", "Ping Request" | NetComm |
| "OSC Read Error", "Prelinked Gizmo" | UI framework internals |

If a function has BOTH skip-pattern strings AND game-logic strings: document only the game-logic part.

---

## READING GHIDRA PSEUDOCODE

```
*(double *)(ptr + 0x1330)   → 8-byte double field at byte offset 0x1330
*(int *)(ptr + 0x4060)      → 4-byte int field at byte offset 0x4060
param_1[0x4a]               → int-indexed: real byte offset = 0x4a × 4 = 0x128
DAT_007c56a4                → global variable at address 007c56a4
uVar1, fVar2, dVar3         → unnamed compiler temporaries
goto chains                 → MSVC loop optimization artifact, not real gotos
unaff_EBX/ESI/EBP           → register-allocated variables (often "this" pointer)
__thiscall                  → param_1 is C++ "this" pointer
s_SomeString_005d0000       → string literal "SomeString" at address 005d0000
```

Source path in asserts: `D:\dev\F1_1999_2002\Source\` — filenames are real .cpp names.

**False positive warning:** offsets +0x1130 and +0x1132 also appear in DirectX device
structs. Only document as AI struct offsets if the function has NO DirectX API calls.

---

## KNOWN CONTEXT (reference — do not re-document)

Read these files before starting to understand what is already known:

- `docs/02-ai-system.md` — full AI pipeline (quadratic scaling, push laps, rain, ring buffer)
- `docs/03-engine-wear-damage.md` — LifetimeVar formula, thermal model, damage probabilities
- `docs/04-tire-system.md` — .tbc compounds, slip curves, compound IDs (Hard=2...Monsoon=6)
- `docs/05-weather-system.md` — weather modes, wetness multipliers, grip multipliers
- `docs/06-session-race-logic.md` — session type codes, race start stalls, penalty system
- `docs/07-pit-system.md` — pit timer phases 0–7, strategy loader, repair display
- `docs/08-file-formats.md` — all file parsers (.rcd, .svm, .hdv, .tbc, .gdb, .veh, .scn)
- `docs/12-globals-reference.md` — all known DAT_ addresses
- `docs/13-struct-offsets.md` — all known struct field offsets
- `docs/16-moddable-fields.md` — all discovered writable game parameters

---

## RULES

1. NEVER re-document an address already in `docs/` — check first
2. NEVER claim "all X documented" without verification
3. Update `work/CHANGELOG.md` after every function — one line per address
4. New globals → append to `docs/12-globals-reference.md`
5. New struct offsets → append to `docs/13-struct-offsets.md`
6. New moddable fields → append to `docs/16-moddable-fields.md`
7. Write entries in order of confidence — put speculation in "Notes" not "Key logic"
