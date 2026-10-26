# WORKER A — F1C Orphan Function Resolution

You are classifying 26 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker A of 15, items 1–26.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_A.md

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

## YOUR ORPHAN FUNCTIONS (26)

Each entry lists:
- The orphan's .c source file path
- Pre-computed cross-references: OTHER .c files that mention this address
- The orphan's current doc entry (if any) in docs/

1. 0x00527f21  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00527f21__FUN_00527f21.c
   doc: docs/20-math-utilities.md  |  summary: — Checksum/CRC Computation
   1 cross-refs found:
     - %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005179e0__FUN_005179e0.c

2. 0x00418db0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418db0__FUN_00418db0.c
   doc: docs/20-math-utilities.md  |  summary: — Global Variable Zero-Init
        no cross-references found in .c files

3. 0x0044cb00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb00__FUN_0044cb00.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Subsystem Init (DAT_007ccfdc)
        no cross-references found in .c files

4. 0x0044d0a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d0a0__FUN_0044d0a0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision global init (single group with 1.0)
        no cross-references found in .c files

5. 0x0044d640  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d640__FUN_0044d640.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionTableInit_14
        no cross-references found in .c files

6. 0x0044dbe0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dbe0__FUN_0044dbe0.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

7. 0x0044e180  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e180__FUN_0044e180.c
   doc: docs/17-physics-collision.md  |  summary: — Collision State Init 2
        no cross-references found in .c files

8. 0x0044e720  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e720__FUN_0044e720.c
   doc: docs/17-physics-collision.md  |  summary: — InitMouseAxis
        no cross-references found in .c files

9. 0x0044ecc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ecc0__FUN_0044ecc0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionTableInit_65
        no cross-references found in .c files

10. 0x00476fc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476fc0__FUN_00476fc0.c
   doc: docs/06-session-race-logic.md  |  summary: — Driver Name Copy from Global Array
        no cross-references found in .c files

11. 0x00488bd0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488bd0__FUN_00488bd0.c
   doc: docs/20-math-utilities.md  |  summary: — Field Setter (+0xE4)
        no cross-references found in .c files

12. 0x004a0000  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0000__FUN_004a0000.c
   doc: docs/20-math-utilities.md  |  summary: — Empty Stub
        no cross-references found in .c files

13. 0x0050b27c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b27c__FUN_0050b27c.c
   doc: docs/06-session-race-logic.md  |  summary: — Texture Dimension Setup
        no cross-references found in .c files

14. 0x0050d615  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d615__FUN_0050d615.c
   doc: docs/18-physics-dynamics.md  |  summary: — Rotation Matrix Y-Axis (3D)
        no cross-references found in .c files

15. 0x0050f0bf  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f0bf__FUN_0050f0bf.c
   doc: docs/19-renderer.md  |  summary: Apply reflection transform to a 4x4 matrix using quaternion/plane parameters.
        no cross-references found in .c files

16. 0x0051cc8e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cc8e__FUN_0051cc8e.c
   doc: docs/10-vehicle-physics.md  |  summary: — Wheel Geometry Data Initialization
        no cross-references found in .c files

17. 0x0053bb30  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bb30__FUN_0053bb30.c
   doc: docs/06-session-race-logic.md  |  summary: — Force vector computation with accumulator
        no cross-references found in .c files

18. 0x0056068e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056068e__FUN_0056068e.c
   doc: docs/20-math-utilities.md  |  summary: (0x0056068e)
        no cross-references found in .c files

19. 0x00582340  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582340__FUN_00582340.c
   doc: docs/01-engine-architecture.md  |  summary: — VTable Call with Flag Check
        no cross-references found in .c files

20. 0x0058a870  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a870____aullshr.c
   doc: docs/20-math-utilities.md  |  summary: � MSVC 64-bit Unsigned Shift Right
        no cross-references found in .c files

21. 0x00593c50  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593c50____CallSettingFrame_12.c
   doc: docs/01-engine-architecture.md  |  summary: � CRT __CallSettingFrame@12
        no cross-references found in .c files

22. 0x0059866c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059866c__htons.c
   doc: docs/21-audio-network-internals.md  |  summary: — htons Wrapper
        no cross-references found in .c files

23. 0x0059a0d5  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a0d5__FUN_0059a0d5.c
   doc: docs/20-math-utilities.md  |  summary: � Buffer Read Through VTable with Bounds Check
        no cross-references found in .c files

24. 0x0059c8a4  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8a4__Unwind_0059c8a4.c
   doc: docs/20-math-utilities.md  |  summary: C++ unwind helper - thunk to FUN_00581ee0.
        no cross-references found in .c files

25. 0x0059d09c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d09c__Unwind_0059d09c.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
        no cross-references found in .c files

26. 0x0059d594  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d594__Unwind_0059d594.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind: Destroy Exception Object
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
