# WORKER K — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker K of 15, items 254–278.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_K.md

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

254. 0x0040a890  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a890__FUN_0040a890.c
   doc: docs/20-math-utilities.md  |  summary: — Multi-Field Membership Check
        no cross-references found in .c files

255. 0x0044c920  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c920__FUN_0044c920.c
   doc: docs/17-physics-collision.md  |  summary: — Collision global init (single group with 1.0)
        no cross-references found in .c files

256. 0x0044cec0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cec0__FUN_0044cec0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGridInit37
        no cross-references found in .c files

257. 0x0044d460  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d460__FUN_0044d460.c
   doc: docs/17-physics-collision.md  |  summary: — Global State Initializer (Collision Set 1)
        no cross-references found in .c files

258. 0x0044da00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044da00__FUN_0044da00.c
   doc: docs/17-physics-collision.md  |  summary: — Collision State Init 1
        no cross-references found in .c files

259. 0x0044dfa0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dfa0__FUN_0044dfa0.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

260. 0x0044e540  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e540__FUN_0044e540.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionTableInit_51
        no cross-references found in .c files

261. 0x0044eae0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044eae0__FUN_0044eae0.c
   doc: docs/17-physics-collision.md  |  summary: — Global State Initializer (Collision Set 4)
        no cross-references found in .c files

262. 0x00466030  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466030__FUN_00466030.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionFlagInit
        no cross-references found in .c files

263. 0x0047f180  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f180__FUN_0047f180.c
   doc: docs/20-math-utilities.md  |  summary: — Doubly-Linked List Append
        no cross-references found in .c files

264. 0x00498940  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498940__FUN_00498940.c
   doc: docs/20-math-utilities.md  |  summary: Forwards call to another function. No additional logic.
        no cross-references found in .c files

265. 0x004d5c40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c40__FUN_004d5c40.c
   doc: docs/20-math-utilities.md  |  summary: — Short Computation (Global Zero Pair)
        no cross-references found in .c files

266. 0x0050c9a9  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c9a9__FUN_0050c9a9.c
   doc: docs/20-math-utilities.md  |  summary: — Bilinear Interp 4-Component
        no cross-references found in .c files

267. 0x0050e0d3  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e0d3__FUN_0050e0d3.c
   doc: docs/20-math-utilities.md  |  summary: Indirect jump through DAT_005d78a8.
        no cross-references found in .c files

268. 0x0051941d  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051941d__FUN_0051941d.c
   doc: docs/19-renderer.md  |  summary: — Texture Row Copy
        no cross-references found in .c files

269. 0x00534ae6  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ae6__AVIFileRelease.c
   doc: docs/20-math-utilities.md  |  summary: — Import Trampoline
        no cross-references found in .c files

270. 0x0055eeaf  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055eeaf__FUN_0055eeaf.c
   doc: docs/20-math-utilities.md  |  summary: � 4x3 Matrix 3D Vector Transform
        no cross-references found in .c files

271. 0x0056f818  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056f818__FUN_0056f818.c
   doc: docs/20-math-utilities.md  |  summary: ```
        no cross-references found in .c files

272. 0x00588931  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588931____NLG_Notify1.c
   doc: docs/06-session-race-logic.md  |  summary: @ 0x00588931
        no cross-references found in .c files

273. 0x0058dd4b  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd4b____math_exit.c
   doc: docs/20-math-utilities.md  |  summary: — __math_exit (MSVC CRT Math Error Handler)
        no cross-references found in .c files

274. 0x0059864e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059864e__recvfrom.c
   doc: docs/21-audio-network-internals.md  |  summary: — recvfrom (Winsock Thunk)
        no cross-references found in .c files

275. 0x00598cdc  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598cdc__uflow.c
   doc: docs/20-math-utilities.md  |  summary: — std::basic_streambuf::uflow (Stream Underflow)
        no cross-references found in .c files

276. 0x0059c6de  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6de__Unwind_0059c6de.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind Handler
        no cross-references found in .c files

277. 0x0059ced7  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ced7__Unwind_0059ced7.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
        no cross-references found in .c files

278. 0x0059d4c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d4c0__Unwind_0059d4c0.c
   doc: docs/20-math-utilities.md  |  summary: — Unwind Thunk to 0x00598c70
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
