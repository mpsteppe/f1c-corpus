# WORKER C — F1C Orphan Function Resolution

You are classifying 26 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker C of 15, items 53–78.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_C.md

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

53. 0x004059f0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004059f0__FUN_004059f0.c
   doc: docs/21-audio-network-internals.md  |  summary: — Short Computation (Audio Sample Reset)
        no cross-references found in .c files

54. 0x0044c620  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c620__FUN_0044c620.c
   doc: docs/17-physics-collision.md  |  summary: — Collision State Init (Slot 1)
        no cross-references found in .c files

55. 0x0044cbc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cbc0__FUN_0044cbc0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGlobalInitF
        no cross-references found in .c files

56. 0x0044d160  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d160__FUN_0044d160.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Struct Init (Block 0x6C, unit default)
        no cross-references found in .c files

57. 0x0044d700  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d700__FUN_0044d700.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Init (Set 0x16)
        no cross-references found in .c files

58. 0x0044dca0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dca0__FUN_0044dca0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStateInit_32
        no cross-references found in .c files

59. 0x0044e240  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e240__FUN_0044e240.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

60. 0x0044e7e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e7e0__FUN_0044e7e0.c
   doc: docs/17-physics-collision.md  |  summary: — Initialize Collision Globals C
        no cross-references found in .c files

61. 0x0044efc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044efc0__FUN_0044efc0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision struct copy
        no cross-references found in .c files

62. 0x004780b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004780b0__FUN_004780b0.c
   doc: docs/10-vehicle-physics.md  |  summary: — Physics/Vehicle Object Reference Store
        no cross-references found in .c files

63. 0x0048d380  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d380__FUN_0048d380.c
   doc: docs/20-math-utilities.md  |  summary: — Bounds-Checked Index Setter
        no cross-references found in .c files

64. 0x004a40b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40b0__FUN_004a40b0.c
   doc: docs/20-math-utilities.md  |  summary: — Empty Stub
        no cross-references found in .c files

65. 0x0050c15e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c15e__FUN_0050c15e.c
   doc: docs/20-math-utilities.md  |  summary: — Hermite/Cubic Spline Interpolation
        no cross-references found in .c files

66. 0x0050d748  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d748__FUN_0050d748.c
   doc: docs/20-math-utilities.md  |  summary: — Axis-Angle to 4x4 Rotation Matrix
        no cross-references found in .c files

67. 0x0050ff84  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ff84__FUN_0050ff84.c
   doc: docs/20-math-utilities.md  |  summary: — Unidentified Logic (State Init with Virtual Calls)
        no cross-references found in .c files

68. 0x00528bd0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528bd0__FUN_00528bd0.c
   doc: docs/20-math-utilities.md  |  summary: — Empty Stub
        no cross-references found in .c files

69. 0x0053bde0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bde0__FUN_0053bde0.c
   doc: docs/20-math-utilities.md  |  summary: — 4-Element Dot Product
        no cross-references found in .c files

70. 0x005608f6  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005608f6__FUN_005608f6.c
   doc: docs/20-math-utilities.md  |  summary: ```
        no cross-references found in .c files

71. 0x00586d70  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586d70__FUN_00586d70.c
   doc: docs/19-renderer.md  |  summary: — Test Bitmap Bits in Texture Region
        no cross-references found in .c files

72. 0x0058a947  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a947____nh_malloc.c
   doc: docs/20-math-utilities.md  |  summary: — __nh_malloc (MSVC CRT)
        no cross-references found in .c files

73. 0x00595733  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595733__FUN_00595733.c
   doc: docs/20-math-utilities.md  |  summary: — __amsg_exit Runtime Error (CRT)
        no cross-references found in .c files

74. 0x00598678  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598678__connect.c
   doc: docs/21-audio-network-internals.md  |  summary: — connect (import thunk)
        no cross-references found in .c files

75. 0x0059aaa2  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aaa2__FUN_0059aaa2.c
   doc: docs/20-math-utilities.md  |  summary: — Empty Stub
        no cross-references found in .c files

76. 0x0059c9f0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c9f0__Unwind_0059c9f0.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind (Call FUN_0057b7f0)
        no cross-references found in .c files

77. 0x0059d1a8  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1a8__Unwind_0059d1a8.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Release Locale Refcount
        no cross-references found in .c files

78. 0x0059d5bc  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5bc__Unwind_0059d5bc.c
   doc: docs/20-math-utilities.md  |  summary: SEH unwind handler -- destructs an exception object during stack unwinding.
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
