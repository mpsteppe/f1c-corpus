# WORKER D — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker D of 15, items 79–103.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_D.md

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

79. 0x00405b50  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b50__FUN_00405b50.c
   doc: docs/21-audio-network-internals.md  |  summary: — Audio Sample Status Check
        no cross-references found in .c files

80. 0x0044c680  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c680__FUN_0044c680.c
   doc: docs/17-physics-collision.md  |  summary: — Spatial Node Init (index 2, radius -1.0)
        no cross-references found in .c files

81. 0x0044cc20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cc20__FUN_0044cc20.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Globals Init #4 (DAT_007ca3b8)
        no cross-references found in .c files

82. 0x0044d1c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d1c0__FUN_0044d1c0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStaticInit_6d (init 0x007ccfa0)
        no cross-references found in .c files

83. 0x0044d760  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d760__FUN_0044d760.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Struct Init (Block 0x17)
        no cross-references found in .c files

84. 0x0044dd00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dd00__FUN_0044dd00.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Region Init 2 (Type 51)
        no cross-references found in .c files

85. 0x0044e2a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e2a0__FUN_0044e2a0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Broadphase Reset (Slot 0x4A)
        no cross-references found in .c files

86. 0x0044e840  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e840__FUN_0044e840.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGlobalInitE
        no cross-references found in .c files

87. 0x0044f010  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f010__FUN_0044f010.c
   doc: docs/17-physics-collision.md  |  summary: — Store negated absolute values
        no cross-references found in .c files

88. 0x00478180  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478180__FUN_00478180.c
   doc: docs/06-session-race-logic.md  |  summary: — Command Dispatch (0x11)
        no cross-references found in .c files

89. 0x0048ea40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ea40__FUN_0048ea40.c
   doc: docs/20-math-utilities.md  |  summary: — 4-Field Setter
        no cross-references found in .c files

90. 0x004b44e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b44e0__FUN_004b44e0.c
   doc: docs/06-session-race-logic.md  |  summary: â€” Fixed-Block Memory Pool Init
        no cross-references found in .c files

91. 0x0050c23c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c23c__FUN_0050c23c.c
   doc: docs/20-math-utilities.md  |  summary: — Bilinear Interpolation (2D)
        no cross-references found in .c files

92. 0x0050d857  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d857__thunk_FUN_0050d84a.c
   doc: docs/20-math-utilities.md  |  summary: — Thunk to Indirect Call via _DAT_005d7860
        no cross-references found in .c files

93. 0x00510012  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510012__FUN_00510012.c
   doc: docs/08-file-formats.md  |  summary: — Image Format Stream Decoder
        no cross-references found in .c files

94. 0x00528cc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528cc0__FUN_00528cc0.c
   doc: docs/19-renderer.md  |  summary: â€” Color Space Transformation (3D LUT / Gamma)
        no cross-references found in .c files

95. 0x0054fe00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fe00__FUN_0054fe00.c
   doc: docs/20-math-utilities.md  |  summary: — Inverse Scale
        no cross-references found in .c files

96. 0x00561acf  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561acf__FUN_00561acf.c
   doc: docs/20-math-utilities.md  |  summary: — Array Fill with Value
        no cross-references found in .c files

97. 0x00587bdc  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587bdc____ftol.c
   doc: docs/20-math-utilities.md  |  summary: — CRT __ftol (Float-to-Long)
        no cross-references found in .c files

98. 0x0058b050  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b050___strrchr.c
   doc: docs/20-math-utilities.md  |  summary: — CRT _strrchr
        no cross-references found in .c files

99. 0x00596100  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596100____aullrem.c
   doc: docs/20-math-utilities.md  |  summary: unknown
        no cross-references found in .c files

100. 0x0059867e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059867e__send.c
   doc: docs/21-audio-network-internals.md  |  summary: — send (Winsock Wrapper)
        no cross-references found in .c files

101. 0x0059b250  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b250__Direct3DCreate8.c
   doc: docs/19-renderer.md  |  summary: — Direct3DCreate8 (import thunk)
        no cross-references found in .c files

102. 0x0059ca10  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca10__Unwind_0059ca10.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind (Free EBP-0x10)
        no cross-references found in .c files

103. 0x0059d2b4  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d2b4__Unwind_0059d2b4.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind (Call FUN_00598c70)
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
