# WORKER E — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker E of 15, items 104–128.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_E.md

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

104. 0x00405e60  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405e60__FUN_00405e60.c
   doc: docs/17-physics-collision.md  |  summary: — Physics Collision Response Computation
        no cross-references found in .c files

105. 0x0044c6e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c6e0__FUN_0044c6e0.c
   doc: docs/17-physics-collision.md  |  summary: — Global State Initializer (Collision Material 1)
        no cross-references found in .c files

106. 0x0044cc80  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc80__FUN_0044cc80.c
   doc: docs/17-physics-collision.md  |  summary: — Collision State Init 4
        no cross-references found in .c files

107. 0x0044d220  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d220__FUN_0044d220.c
   doc: docs/17-physics-collision.md  |  summary: — InitMouseAbsAxisY
        no cross-references found in .c files

108. 0x0044d7c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d7c0__FUN_0044d7c0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStaticInit_18 (init 0x007ccc08)
        no cross-references found in .c files

109. 0x0044dd60  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd60__FUN_0044dd60.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Coefficients Set 2 (ID 0x34)
        no cross-references found in .c files

110. 0x0044e300  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e300__FUN_0044e300.c
   doc: docs/17-physics-collision.md  |  summary: — Spatial Node Init (index 75, distance 9000)
        no cross-references found in .c files

111. 0x0044e8a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e8a0__FUN_0044e8a0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Globals Init #3 (DAT_007ca534)
        no cross-references found in .c files

112. 0x0044f6f0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f6f0__FUN_0044f6f0.c
   doc: docs/17-physics-collision.md  |  summary: — Spring-Damper Controller Update
        no cross-references found in .c files

113. 0x00478200  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478200__FUN_00478200.c
   doc: docs/01-engine-architecture.md  |  summary: — Short Computation / Game Command Dispatch
        no cross-references found in .c files

114. 0x0048f330  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048f330__FUN_0048f330.c
   doc: docs/20-math-utilities.md  |  summary: — Field Setter with VTable Dispatch
        no cross-references found in .c files

115. 0x004b9cc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9cc0__FUN_004b9cc0.c
   doc: docs/06-session-race-logic.md  |  summary: — Vehicle Speed Accessor
        no cross-references found in .c files

116. 0x0050c2b3  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2b3__thunk_FUN_0050c2a6.c
   doc: docs/20-math-utilities.md  |  summary: — Thunk to (indirect via DAT_005d77e4)
        no cross-references found in .c files

117. 0x0050d85d  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d85d__FUN_0050d85d.c
   doc: docs/20-math-utilities.md  |  summary: — Quaternion to Rotation Matrix
        no cross-references found in .c files

118. 0x0051030d  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051030d__FUN_0051030d.c
   doc: docs/19-renderer.md  |  summary: — Unidentified Logic / Bitmap Decompression (RLE-like)
        no cross-references found in .c files

119. 0x0052d8b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8b0__DirectInput8Create.c
   doc: docs/20-math-utilities.md  |  summary: — DirectInput8Create Import Stub
        no cross-references found in .c files

120. 0x00556790  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556790__FUN_00556790.c
   doc: docs/20-math-utilities.md  |  summary: — Fixed-Point Multiply with Rounding
        no cross-references found in .c files

121. 0x00564640  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564640__GetTickCount.c
   doc: docs/20-math-utilities.md  |  summary: — GetTickCount Win32 Stub
        no cross-references found in .c files

122. 0x00587c03  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587c03__operator_new.c
   doc: docs/01-engine-architecture.md  |  summary: — operator new(uint) → __nh_malloc Wrapper
        no cross-references found in .c files

123. 0x0058b59f  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b59f__FUN_0058b59f.c
   doc: docs/01-engine-architecture.md  |  summary: — GetSystemTimeAsFileTime to 64-bit Tick
        no cross-references found in .c files

124. 0x00596840  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596840____allshl.c
   doc: docs/20-math-utilities.md  |  summary: — CRT __allshl (64-bit Left Shift)
        no cross-references found in .c files

125. 0x00598684  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598684__recv.c
   doc: docs/21-audio-network-internals.md  |  summary: — recv (import thunk)
        no cross-references found in .c files

126. 0x0059bfc3  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bfc3____CxxThrowException_8.c
   doc: docs/20-math-utilities.md  |  summary: — __CxxThrowException_8
        no cross-references found in .c files

127. 0x0059cb48  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb48__Unwind_0059cb48.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
        no cross-references found in .c files

128. 0x0059d308  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d308__Unwind_0059d308.c
   doc: docs/20-math-utilities.md  |  summary: — MSVC Exception Handler Unwind
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
