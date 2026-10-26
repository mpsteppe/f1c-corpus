# WORKER N — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker N of 15, items 329–353.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_N.md

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

329. 0x0040b5a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b5a0__FUN_0040b5a0.c
   doc: docs/20-math-utilities.md  |  summary: — VTable Switch with Virtual Call
        no cross-references found in .c files

330. 0x0044ca40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ca40__FUN_0044ca40.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStaticInit_12 (init 0x007cca7c)
        no cross-references found in .c files

331. 0x0044cfe0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cfe0__FUN_0044cfe0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Coefficients Set 6 (ID 40, 1.0f)
        no cross-references found in .c files

332. 0x0044d580  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d580__FUN_0044d580.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Region Init 1 (Type 18)
        no cross-references found in .c files

333. 0x0044db20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db20__FUN_0044db20.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Broadphase Reset (Slot 0x2E)
        no cross-references found in .c files

334. 0x0044e0c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e0c0__FUN_0044e0c0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGlobalInitD
        no cross-references found in .c files

335. 0x0044e660  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e660__FUN_0044e660.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

336. 0x0044ec00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ec00__FUN_0044ec00.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Region Init 4 (Type 99)
        no cross-references found in .c files

337. 0x0046c710  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c710__FUN_0046c710.c
   doc: docs/20-math-utilities.md  |  summary: — Global Array Scan for Negative
        no cross-references found in .c files

338. 0x00486300  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486300__FUN_00486300.c
   doc: docs/19-renderer.md  |  summary: — UI String Accessor (+0x50)
        no cross-references found in .c files

339. 0x0049a110  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a110__FUN_0049a110.c
   doc: docs/20-math-utilities.md  |  summary: — Short Computation (Linked List Node Count)
        no cross-references found in .c files

340. 0x00500161  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500161__FUN_00500161.c
   doc: docs/20-math-utilities.md  |  summary: � Parameter Reorder Wrapper
        no cross-references found in .c files

341. 0x0050d0bc  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0bc__thunk_FUN_0050d0af.c
   doc: docs/20-math-utilities.md  |  summary: — Thunk to FUN_0050d0af via Global Pointer
        no cross-references found in .c files

342. 0x0050e84b  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e84b__FUN_0050e84b.c
   doc: docs/20-math-utilities.md  |  summary: — Arithmetic/Comparison / 2x2 Matrix Multiply
        no cross-references found in .c files

343. 0x0051bd61  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bd61__FUN_0051bd61.c
   doc: docs/06-session-race-logic.md  |  summary: — Audio Ring Buffer Manager
        no cross-references found in .c files

344. 0x0053aeb0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053aeb0__FUN_0053aeb0.c
   doc: docs/19-renderer.md  |  summary: � Vertex Batch Transform (Dual Matrix)
        no cross-references found in .c files

345. 0x005604c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005604c0__FUN_005604c0.c
   doc: docs/19-renderer.md  |  summary: — Pixel Buffer Blit with Short-to-Int Conversion
        no cross-references found in .c files

346. 0x0057aa50  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aa50__FUN_0057aa50.c
   doc: docs/06-session-race-logic.md  |  summary: @ 0x0057aa50
        no cross-references found in .c files

347. 0x0058a2a6  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2a6____amsg_exit.c
   doc: docs/20-math-utilities.md  |  summary: — CRT __amsg_exit (Error Exit)
        no cross-references found in .c files

348. 0x0059086e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059086e____fload.c
   doc: docs/20-math-utilities.md  |  summary: — CRT __fload (float load)
        no cross-references found in .c files

349. 0x00598660  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598660__gethostbyname.c
   doc: docs/21-audio-network-internals.md  |  summary: — gethostbyname (import thunk)
        no cross-references found in .c files

350. 0x00599689  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599689__Catch_00599689.c
   doc: docs/20-math-utilities.md  |  summary: — Catch Block with Buffer Allocation
        no cross-references found in .c files

351. 0x0059c86a  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c86a__Unwind_0059c86a.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind Handler (Calls FUN_00581750)
        no cross-references found in .c files

352. 0x0059cf94  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf94__Unwind_0059cf94.c
   doc: docs/20-math-utilities.md  |  summary: C++ unwind helper - thunk to FUN_00581750.
        no cross-references found in .c files

353. 0x0059d56c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d56c__Unwind_0059d56c.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind: Destroy Exception Object
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
