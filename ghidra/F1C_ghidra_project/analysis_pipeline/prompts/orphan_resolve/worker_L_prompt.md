# WORKER L — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker L of 15, items 279–303.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_L.md

Structure:
```
=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
...

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Name
...
```

Write to disk after every 10 functions. Do not accumulate in memory.

---

## YOUR ORPHAN FUNCTIONS (25)

Each entry lists:
- The orphan's .c source file path
- Pre-computed cross-references: OTHER .c files that mention this address
- The orphan's current doc entry (if any) in docs/

279. 0x0040ac40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ac40__FUN_0040ac40.c
   doc: docs/20-math-utilities.md  |  summary: — VTable Switch
        no cross-references found in .c files

280. 0x0044c980  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c980__FUN_0044c980.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Init (Set 10, -1.0f)
        no cross-references found in .c files

281. 0x0044cf20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf20__FUN_0044cf20.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStateInit_Alpha2
        no cross-references found in .c files

282. 0x0044d4c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d4c0__FUN_0044d4c0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGridInit16x16
        no cross-references found in .c files

283. 0x0044da60  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da60__FUN_0044da60.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Init (Type 0x2c)
        no cross-references found in .c files

284. 0x0044e000  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e000__FUN_0044e000.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Subsystem Init (DAT_007ccd80)
        no cross-references found in .c files

285. 0x0044e5a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e5a0__FUN_0044e5a0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision global init (group 0x52)
        no cross-references found in .c files

286. 0x0044eb40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eb40__FUN_0044eb40.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGridInit97
        no cross-references found in .c files

287. 0x004694b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004694b0__FUN_004694b0.c
   doc: docs/08-file-formats.md  |  summary: — Filename From Linked List (No Extension Strip)
        no cross-references found in .c files

288. 0x0047f210  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f210__FUN_0047f210.c
   doc: docs/20-math-utilities.md  |  summary: — Short Computation (Conditional VTable Call)
        no cross-references found in .c files

289. 0x00499520  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499520__FUN_00499520.c
   doc: docs/01-engine-architecture.md  |  summary: — Linked List Virtual Dispatch
        no cross-references found in .c files

290. 0x004e2130  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2130__FUN_004e2130.c
   doc: docs/06-session-race-logic.md  |  summary: — ChassisWorldTransform
        no cross-references found in .c files

291. 0x0050cbb6  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cbb6__FUN_0050cbb6.c
   doc: docs/20-math-utilities.md  |  summary: — 4x4 Matrix Multiply
        no cross-references found in .c files

292. 0x0050e19e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e19e__FUN_0050e19e.c
   doc: docs/20-math-utilities.md  |  summary: — Quaternion Slerp
        no cross-references found in .c files

293. 0x005196b8  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005196b8__FUN_005196b8.c
   doc: docs/06-session-race-logic.md  |  summary: — Buffered Data Stream Write
        no cross-references found in .c files

294. 0x00537d10  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537d10__FUN_00537d10.c
   doc: docs/21-audio-network-internals.md  |  summary: â€” Adler-32 Checksum
        no cross-references found in .c files

295. 0x0055ef24  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ef24__FUN_0055ef24.c
   doc: docs/20-math-utilities.md  |  summary: — 3x3 Matrix × Float3 Vector Multiply
        no cross-references found in .c files

296. 0x00575882  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00575882__FUN_00575882.c
   doc: docs/20-math-utilities.md  |  summary: (0x00575882)
        no cross-references found in .c files

297. 0x00588a19  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588a19__FUN_00588a19.c
   doc: docs/20-math-utilities.md  |  summary: — Local Unwind Wrapper (SEH)
        no cross-references found in .c files

298. 0x0058e1b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e1b0___strlen.c
   doc: docs/20-math-utilities.md  |  summary: — _strlen (Aligned Word-Scan Implementation)
        no cross-references found in .c files

299. 0x00598654  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598654__select.c
   doc: docs/21-audio-network-internals.md  |  summary: — select (import thunk)
        no cross-references found in .c files

300. 0x00599081  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599081__FUN_00599081.c
   doc: docs/08-file-formats.md  |  summary: — Buffered Stream Read with Fallback Vtable Call
        no cross-references found in .c files

301. 0x0059c6e8  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6e8__Unwind_0059c6e8.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind
        no cross-references found in .c files

302. 0x0059cf70  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf70__Unwind_0059cf70.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind Handler (Array Dtor)
        no cross-references found in .c files

303. 0x0059d4d8  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4d8__Unwind_0059d4d8.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind (Call FUN_0059a5e9)
        no cross-references found in .c files

---

## CLASSIFICATION TASK

For each orphan:

### Step A — Read the orphan's .c source
Note: globals referenced, parameters, return type, struct offsets accessed.
Does it touch game globals (SessionType, RacePhase, etc.)? → NOT dead code.

### Step B — Check cross-references (pre-computed, given above)
If other .c files reference this address:
  - Read those files to understand context
  - Is the address assigned to a function pointer field? → `callback`
  - Does it appear in a table of addresses (vtable pattern)? → `vtable_member`
  - Is it passed as a parameter to a registration function? → `callback`

### Step C — Classify into one of:
  - `vtable_member`    — address appears in vtable / virtual dispatch table
  - `callback`         — assigned as function pointer / registered via callback mechanism
  - `entry_point`      — DLL export, exception handler, or thread entry
  - `game_logic_isolated` — references game globals, real game code, just missing edges
  - `utility_isolated` — pure math/utility, no game globals, no cross-refs found
  - `dead_code`        — no game globals, no cross-refs, appears unreachable

### Step D — Write classification line:
```
| 0x00XXXXXX | vtable_member | HIGH | address at offset +0x14 in FUN_00YYYYYY vtable | FUN_00YYYYYY |
```

### Step E — Update doc entry ONLY if classification reveals new call relationships
If you found that `FUN_00AAAAAAAA` calls this orphan via vtable/callback:
  - Write an updated `## FUN_` entry with the new caller documented
  - Target it to the same doc file where the function currently lives

If classification is `dead_code` or `utility_isolated` with no new info: skip the full entry.

---

## CLASSIFICATION TABLE FORMAT

```
=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x00XXXXXX | vtable_member | HIGH | found at [FUN_YYYYYY+0x1c], called via `*(vtbl+0x1c)(this)` | FUN_00YYYYYY |
| 0x00AAAAAA | dead_code | HIGH | no game globals, no cross-refs, 3-line no-op body | — |
| 0x00BBBBBB | game_logic_isolated | MEDIUM | reads SessionType + RacePhase but no callers found in .c files | — |
```

---

## RULES

0. NEVER move, rename, or delete any files.
1. Classify EVERY orphan in your list — no skipping.
2. Write the classification line before the full entry (if any).
3. Only write a full `## FUN_` entry if new call relationships are discovered.
4. confidence = HIGH if cross-ref evidence is found; MEDIUM if inferred from code shape; LOW if guessed.
5. For vtable_member: quote the exact offset in the vtable struct.
6. For callbacks: name the registration function.
7. Leave `=== FULL ENTRIES ===` empty if no new relationships found.
