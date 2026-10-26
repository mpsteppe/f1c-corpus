# WORKER O — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker O of 15, items 354–378.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_O.md

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

354. 0x0040be20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040be20__FUN_0040be20.c
   doc: docs/20-math-utilities.md  |  summary: — Conditional Virtual Call Triplet (Cleanup)
        no cross-references found in .c files

355. 0x0044caa0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044caa0__FUN_0044caa0.c
   doc: docs/17-physics-collision.md  |  summary: — InitMouseAbsAxisX
        no cross-references found in .c files

356. 0x0044d040  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d040__FUN_0044d040.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionFrictionInit_29
        no cross-references found in .c files

357. 0x0044d5e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d5e0__FUN_0044d5e0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Coefficients Set 1 (ID 0x13)
        no cross-references found in .c files

358. 0x0044db80  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db80__FUN_0044db80.c
   doc: docs/17-physics-collision.md  |  summary: — Spatial Node Init (index 47)
        no cross-references found in .c files

359. 0x0044e120  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e120__FUN_0044e120.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Globals Init #2 (DAT_007cd1a8)
        no cross-references found in .c files

360. 0x0044e6c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e6c0__FUN_0044e6c0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStaticInit_55 (init 0x007cd064)
        no cross-references found in .c files

361. 0x0044ec60  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec60__FUN_0044ec60.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Coefficients Set 4 (ID 100)
        no cross-references found in .c files

362. 0x00474c80  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474c80__FUN_00474c80.c
   doc: docs/20-math-utilities.md  |  summary: — Switch: Maps 0x1a2-0x1ac to Bitmask
        no cross-references found in .c files

363. 0x004888f0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004888f0__FUN_004888f0.c
   doc: docs/06-session-race-logic.md  |  summary: — Byte Field Setter
        no cross-references found in .c files

364. 0x0049b050  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b050__FUN_0049b050.c
   doc: docs/20-math-utilities.md  |  summary: — Empty Stub
        no cross-references found in .c files

365. 0x0050696c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050696c__thunk_FUN_0050653e.c
   doc: docs/19-renderer.md  |  summary: — Thunk to FUN_0050653e (D3D Object Destructor)
        no cross-references found in .c files

366. 0x0050d57f  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d57f__FUN_0050d57f.c
   doc: docs/20-math-utilities.md  |  summary: — Y-Axis Rotation Matrix
        no cross-references found in .c files

367. 0x0050edd2  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050edd2__FUN_0050edd2.c
   doc: docs/20-math-utilities.md  |  summary: — Two-Thunk Wrapper
        no cross-references found in .c files

368. 0x0051bdf1  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bdf1__FUN_0051bdf1.c
   doc: docs/06-session-race-logic.md  |  summary: — BufferedDataReader
        no cross-references found in .c files

369. 0x0053b110  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b110__FUN_0053b110.c
   doc: docs/20-math-utilities.md  |  summary: — [PARTIAL] Unknown
        no cross-references found in .c files

370. 0x00560547  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560547__FUN_00560547.c
   doc: docs/19-renderer.md  |  summary: unknown
        no cross-references found in .c files

371. 0x0057e410  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e410__FUN_0057e410.c
   doc: docs/01-engine-architecture.md  |  summary: — Windows Message Pump
        no cross-references found in .c files

372. 0x0058a7ec  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a7ec____setjmp3.c
   doc: docs/20-math-utilities.md  |  summary: MSVC CRT __setjmp3 implementation -- saves register state and exception handler chain into a jmp_buf for longjmp.
        no cross-references found in .c files

373. 0x00591cf3  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591cf3____frnd.c
   doc: docs/20-math-utilities.md  |  summary: — __frnd — MSVC CRT Rounding
        no cross-references found in .c files

374. 0x00598666  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598666__inet_addr.c
   doc: docs/21-audio-network-internals.md  |  summary: — inet_addr wrapper
        no cross-references found in .c files

375. 0x00599d31  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599d31__uflow.c
   doc: docs/20-math-utilities.md  |  summary: — MSVC streambuf uflow
        no cross-references found in .c files

376. 0x0059c878  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c878__Unwind_0059c878.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind (Call FUN_00582650)
        no cross-references found in .c files

377. 0x0059d036  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d036__Unwind_0059d036.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
        no cross-references found in .c files

378. 0x0059d580  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d580__Unwind_0059d580.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind: Destroy exception Object
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
