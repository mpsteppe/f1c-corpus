# WORKER B — F1C Orphan Function Resolution

You are classifying 26 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker B of 15, items 27–52.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_B.md

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

27. 0x00585ea0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585ea0__FUN_00585ea0.c
   doc: docs/21-audio-network-internals.md  |  summary: — Mutex Pair Initializer
   1 cross-refs found:
     - %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005837f0__FUN_005837f0.c

28. 0x004328c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004328c0__FUN_004328c0.c
   doc: docs/08-file-formats.md  |  summary: — Path Accessor (+8)
        no cross-references found in .c files

29. 0x0044cb60  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb60__FUN_0044cb60.c
   doc: docs/17-physics-collision.md  |  summary: — Initialize Collision Globals D
        no cross-references found in .c files

30. 0x0044d100  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d100__FUN_0044d100.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Init (Set 0x6b, -1.0f)
        no cross-references found in .c files

31. 0x0044d6a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d6a0__FUN_0044d6a0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision global init (group 0x15)
        no cross-references found in .c files

32. 0x0044dc40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dc40__FUN_0044dc40.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGridInit49x49
        no cross-references found in .c files

33. 0x0044e1e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e1e0__FUN_0044e1e0.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

34. 0x0044e780  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e780__FUN_0044e780.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Subsystem Init (DAT_007ccfec)
        no cross-references found in .c files

35. 0x0044ee00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ee00__FUN_0044ee00.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Node Next-Child Accessor
        no cross-references found in .c files

36. 0x00478090  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478090__FUN_00478090.c
   doc: docs/01-engine-architecture.md  |  summary: — Virtual Factory + Store
        no cross-references found in .c files

37. 0x0048d1a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d1a0__FUN_0048d1a0.c
   doc: docs/20-math-utilities.md  |  summary: General utility function. See decompiled code for exact behavior.
        no cross-references found in .c files

38. 0x004a1b20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1b20__FUN_004a1b20.c
   doc: docs/20-math-utilities.md  |  summary: — Arithmetic/Comparison (String Prefix Copy)
        no cross-references found in .c files

39. 0x0050c0a6  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c0a6__FUN_0050c0a6.c
   doc: docs/20-math-utilities.md  |  summary: — Unidentified Logic (Cubic Bezier Interpolation)
        no cross-references found in .c files

40. 0x0050d6ac  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d6ac__FUN_0050d6ac.c
   doc: docs/20-math-utilities.md  |  summary: � 2D Rotation Matrix (Z-axis, 4x4)
        no cross-references found in .c files

41. 0x0050f6f2  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f6f2__thunk_FUN_00516959.c
   doc: docs/01-engine-architecture.md  |  summary: — VTable Dtor + Null Fields
        no cross-references found in .c files

42. 0x005289e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005289e0__FUN_005289e0.c
   doc: docs/19-renderer.md  |  summary: — RGBA Color Space Conversion
        no cross-references found in .c files

43. 0x0053bce0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bce0__FUN_0053bce0.c
   doc: docs/20-math-utilities.md  |  summary: — Force/Scale Calculation
        no cross-references found in .c files

44. 0x005607c1  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005607c1__FUN_005607c1.c
   doc: docs/19-renderer.md  |  summary: unknown
        no cross-references found in .c files

45. 0x00586c90  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586c90__FUN_00586c90.c
   doc: docs/01-engine-architecture.md  |  summary: — Counter Increment with Cap Check
        no cross-references found in .c files

46. 0x0058a935  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a935___malloc.c
   doc: docs/20-math-utilities.md  |  summary: — _malloc — Wrapper for __nh_malloc
        no cross-references found in .c files

47. 0x00594ff0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594ff0____aulldiv.c
   doc: docs/20-math-utilities.md  |  summary: ```
        no cross-references found in .c files

48. 0x00598672  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598672__sendto.c
   doc: docs/21-audio-network-internals.md  |  summary: — sendto (Winsock Thunk)
        no cross-references found in .c files

49. 0x0059a418  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a418__Gninc.c
   doc: docs/20-math-utilities.md  |  summary: — std::_Gninc (Stream Buffer Get Pointer Increment)
        no cross-references found in .c files

50. 0x0059c91e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c91e__Unwind_0059c91e.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
        no cross-references found in .c files

51. 0x0059d0c8  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0c8__Unwind_0059d0c8.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind (Call FUN_0047aa60)
        no cross-references found in .c files

52. 0x0059d5a8  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5a8__Unwind_0059d5a8.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
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
