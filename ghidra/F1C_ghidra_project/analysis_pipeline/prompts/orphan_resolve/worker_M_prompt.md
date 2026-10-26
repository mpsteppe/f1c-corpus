# WORKER M — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker M of 15, items 304–328.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_M.md

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

304. 0x0040b360  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b360__FUN_0040b360.c
   doc: docs/20-math-utilities.md  |  summary: — Virtual Dispatch Chain
        no cross-references found in .c files

305. 0x0044c9e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c9e0__FUN_0044c9e0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Struct Init (Block 0xB, unit default)
        no cross-references found in .c files

306. 0x0044cf80  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cf80__FUN_0044cf80.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

307. 0x0044d520  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d520__FUN_0044d520.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStateInit_17
        no cross-references found in .c files

308. 0x0044dac0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dac0__FUN_0044dac0.c
   doc: docs/17-physics-collision.md  |  summary: — ConstraintSolverInit1
        no cross-references found in .c files

309. 0x0044e060  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e060__FUN_0044e060.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStateClear
        no cross-references found in .c files

310. 0x0044e600  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e600__FUN_0044e600.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Init (Set 0x53)
        no cross-references found in .c files

311. 0x0044eba0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eba0__FUN_0044eba0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStateInit_62
        no cross-references found in .c files

312. 0x0046b310  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b310__FUN_0046b310.c
   doc: docs/20-math-utilities.md  |  summary: � Offset Accessor (+0x174)
        no cross-references found in .c files

313. 0x004862e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004862e0__FUN_004862e0.c
   doc: docs/19-renderer.md  |  summary: — UI String Accessor (+0x48)
        no cross-references found in .c files

314. 0x00499c10  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499c10__FUN_00499c10.c
   doc: docs/20-math-utilities.md  |  summary: — Short Computation / Struct Copy with Rotation
        no cross-references found in .c files

315. 0x004f8c50  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c50__FUN_004f8c50.c
   doc: docs/20-math-utilities.md  |  summary: — [PARTIAL] Unknown
        no cross-references found in .c files

316. 0x0050cdf9  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cdf9__thunk_FUN_0050cdec.c
   doc: docs/20-math-utilities.md  |  summary: — Thunk via Global Function Pointer
        no cross-references found in .c files

317. 0x0050e760  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e760__FUN_0050e760.c
   doc: docs/20-math-utilities.md  |  summary: — 4-Component Vector × 4×3 Matrix Transform
        no cross-references found in .c files

318. 0x0051bcfc  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bcfc__FUN_0051bcfc.c
   doc: docs/06-session-race-logic.md  |  summary: — RenderCommandDispatch
        no cross-references found in .c files

319. 0x00538a90  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00538a90__FUN_00538a90.c
   doc: docs/08-file-formats.md  |  summary: — Bit Buffer Writer (Variable-Length Coding)
        no cross-references found in .c files

320. 0x0055ef88  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ef88__FUN_0055ef88.c
   doc: docs/20-math-utilities.md  |  summary: — 4x4 Matrix Multiply
        no cross-references found in .c files

321. 0x0057a260  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a260__FUN_0057a260.c
   doc: docs/20-math-utilities.md  |  summary: — Byte Field + Offset Getter
        no cross-references found in .c files

322. 0x00589d62  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d62__ExitProcess.c
   doc: docs/20-math-utilities.md  |  summary: — ExitProcess Stub
        no cross-references found in .c files

323. 0x0058fb90  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fb90___strcmp.c
   doc: docs/06-session-race-logic.md  |  summary: @ 0x0058fb90
        no cross-references found in .c files

324. 0x0059865a  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059865a__closesocket.c
   doc: docs/21-audio-network-internals.md  |  summary: — closesocket (Winsock Wrapper)
        no cross-references found in .c files

325. 0x00599475  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599475___Gninc.c
   doc: docs/20-math-utilities.md  |  summary: — MSVC streambuf::_Gninc (Get Pointer Increment)
        no cross-references found in .c files

326. 0x0059c7e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7e0__Unwind_0059c7e0.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
        no cross-references found in .c files

327. 0x0059cf86  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf86__Unwind_0059cf86.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind (Call FUN_00585f30)
        no cross-references found in .c files

328. 0x0059d558  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d558__Unwind_0059d558.c
   doc: docs/08-file-formats.md  |  summary: SEH unwind handler -- destructs an exception object at stack offset EBP-0x14 during exception unwinding.
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
