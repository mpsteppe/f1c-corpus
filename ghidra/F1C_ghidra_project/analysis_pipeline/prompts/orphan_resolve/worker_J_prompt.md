# WORKER J — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker J of 15, items 229–253.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_J.md

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

229. 0x00407d40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407d40__FUN_00407d40.c
   doc: docs/20-math-utilities.md  |  summary: — Short Computation (Trigonometric/Angle Vector Math)
        no cross-references found in .c files

230. 0x0044c8c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c8c0__FUN_0044c8c0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionFrictionInit_8
        no cross-references found in .c files

231. 0x0044ce60  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce60__FUN_0044ce60.c
   doc: docs/17-physics-collision.md  |  summary: — Global State Initializer (Collision Material 2)
        no cross-references found in .c files

232. 0x0044d400  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d400__FUN_0044d400.c
   doc: docs/17-physics-collision.md  |  summary: — Spatial Node Init (index 14)
        no cross-references found in .c files

233. 0x0044d9a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d9a0__FUN_0044d9a0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Globals Init #1 (DAT_007ccf30)
        no cross-references found in .c files

234. 0x0044df40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044df40__FUN_0044df40.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStaticInit_39 (init 0x007ccbc4)
        no cross-references found in .c files

235. 0x0044e4e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e4e0__FUN_0044e4e0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Coefficients Set 3 (ID 0x50)
        no cross-references found in .c files

236. 0x0044ea80  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea80__FUN_0044ea80.c
   doc: docs/17-physics-collision.md  |  summary: — Spatial Node Init (index 95, distance 9000)
        no cross-references found in .c files

237. 0x00465fd0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465fd0__FUN_00465fd0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Distance Reset
        no cross-references found in .c files

238. 0x0047b1b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b1b0__FUN_0047b1b0.c
   doc: docs/20-math-utilities.md  |  summary: — Triple Virtual Call Dispatch
        no cross-references found in .c files

239. 0x004979b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979b0__thunk_FUN_00495b30.c
   doc: docs/20-math-utilities.md  |  summary: Thunk/delegation with polling loop - calls FUN_00498f70 until it returns != 1.
        no cross-references found in .c files

240. 0x004c9960  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9960__FUN_004c9960.c
   doc: docs/20-math-utilities.md  |  summary: — Short Computation (Virtual Call + Pointer Clear)
        no cross-references found in .c files

241. 0x0050c887  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c887__FUN_0050c887.c
   doc: docs/20-math-utilities.md  |  summary: — Catmull-Rom Spline Interpolation (4-Point, 3D)
        no cross-references found in .c files

242. 0x0050e04f  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e04f__FUN_0050e04f.c
   doc: docs/20-math-utilities.md  |  summary: — Indirect Jump Thunk
        no cross-references found in .c files

243. 0x00515986  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515986__FUN_00515986.c
   doc: docs/20-math-utilities.md  |  summary: � Bitfield-Controlled Memory Copy
        no cross-references found in .c files

244. 0x00534ae0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ae0__AVIFileExit.c
   doc: docs/20-math-utilities.md  |  summary: — AVIFileExit Stub
        no cross-references found in .c files

245. 0x0055ee20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ee20__FUN_0055ee20.c
   doc: docs/20-math-utilities.md  |  summary: (0x0055ee20)
        no cross-references found in .c files

246. 0x00567b00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567b00__thunk_FUN_00567b10.c
   doc: docs/20-math-utilities.md  |  summary: ```
        no cross-references found in .c files

247. 0x0058890e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058890e____abnormal_termination.c
   doc: docs/20-math-utilities.md  |  summary: — CRT __abnormal_termination
        no cross-references found in .c files

248. 0x0058dce5  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dce5____fload_withFB.c
   doc: docs/20-math-utilities.md  |  summary: — __fload_withFB — Float Load with NaN Check
        no cross-references found in .c files

249. 0x00598648  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598648__socket.c
   doc: docs/21-audio-network-internals.md  |  summary: — socket (import thunk)
        no cross-references found in .c files

250. 0x005986a2  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986a2__WSACleanup.c
   doc: docs/21-audio-network-internals.md  |  summary: — WSACleanup Thunk
        no cross-references found in .c files

251. 0x0059c666  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c666__Unwind_0059c666.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind (Free EBP+8)
        no cross-references found in .c files

252. 0x0059ce00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce00__Unwind_0059ce00.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind (Call FUN_005819c0)
        no cross-references found in .c files

253. 0x0059d4ac  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4ac__Unwind_0059d4ac.c
   doc: docs/20-math-utilities.md  |  summary: — MSVC Exception Handler (exception destructor)
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
