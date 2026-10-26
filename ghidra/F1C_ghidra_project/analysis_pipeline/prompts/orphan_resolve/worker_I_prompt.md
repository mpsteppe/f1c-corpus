# WORKER I — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker I of 15, items 204–228.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_I.md

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

204. 0x004070e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004070e0__FUN_004070e0.c
   doc: docs/17-physics-collision.md  |  summary: — Spatial Query with Weighted Distance Selection
        no cross-references found in .c files

205. 0x0044c860  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c860__FUN_0044c860.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Coefficients Set 5 (ID 7, 1.0f)
        no cross-references found in .c files

206. 0x0044ce00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ce00__FUN_0044ce00.c
   doc: docs/17-physics-collision.md  |  summary: — Spatial Node Init (index 35, radius -1.0)
        no cross-references found in .c files

207. 0x0044d3a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d3a0__FUN_0044d3a0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Broadphase Reset (Slot 0xD)
        no cross-references found in .c files

208. 0x0044d940  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d940__FUN_0044d940.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGlobalInitC
        no cross-references found in .c files

209. 0x0044dee0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dee0__FUN_0044dee0.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

210. 0x0044e480  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e480__FUN_0044e480.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Region Init 3 (Type 79)
        no cross-references found in .c files

211. 0x0044ea20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea20__FUN_0044ea20.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Broadphase Reset (Slot 0x5E)
        no cross-references found in .c files

212. 0x00463c80  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463c80__FUN_00463c80.c
   doc: docs/08-file-formats.md  |  summary: — Vehicle Description Accessor
        no cross-references found in .c files

213. 0x00478690  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478690__FUN_00478690.c
   doc: docs/20-math-utilities.md  |  summary: — Short Computation (Conditional Virtual Dispatch)
        no cross-references found in .c files

214. 0x004967d0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004967d0__FUN_004967d0.c
   doc: docs/19-renderer.md  |  summary: — Doubly-Linked List Append (Render Layer)
        no cross-references found in .c files

215. 0x004c9820  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9820__FUN_004c9820.c
   doc: docs/20-math-utilities.md  |  summary: — Virtual State Check via Index
        no cross-references found in .c files

216. 0x0050c78c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c78c__FUN_0050c78c.c
   doc: docs/20-math-utilities.md  |  summary: — Unidentified Logic / Catmull-Rom Spline Interpolation
        no cross-references found in .c files

217. 0x0050df95  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050df95__thunk_FUN_0050df88.c
   doc: docs/20-math-utilities.md  |  summary: — Thunk via Indirect Jump (DAT_005d7878)
        no cross-references found in .c files

218. 0x00513daf  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513daf__FUN_00513daf.c
   doc: docs/20-math-utilities.md  |  summary: — Batch Clamp to Max
        no cross-references found in .c files

219. 0x00534aac  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534aac___AIL_shutdown_0.c
   doc: docs/21-audio-network-internals.md  |  summary: � Miles Sound System AIL_shutdown Thunk
        no cross-references found in .c files

220. 0x0055685a  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055685a__FUN_0055685a.c
   doc: docs/20-math-utilities.md  |  summary: — Return Constant 1
        no cross-references found in .c files

221. 0x00567af0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567af0__thunk_FUN_00567b10.c
   doc: docs/06-session-race-logic.md  |  summary: @ 0x00567af0
        no cross-references found in .c files

222. 0x00588864  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588864____global_unwind2.c
   doc: docs/20-math-utilities.md  |  summary: — __global_unwind2 (MSVC CRT SEH Unwind)
        no cross-references found in .c files

223. 0x0058dad7  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dad7____trandisp2.c
   doc: docs/06-session-race-logic.md  |  summary: @ 0x0058dad7
        no cross-references found in .c files

224. 0x00598642  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598642__htonl.c
   doc: docs/21-audio-network-internals.md  |  summary: — htonl (Winsock Wrapper)
        no cross-references found in .c files

225. 0x0059869c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059869c__WSAStartup.c
   doc: docs/21-audio-network-internals.md  |  summary: — WSAStartup (Winsock Wrapper)
        no cross-references found in .c files

226. 0x0059c5ee  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5ee__Unwind_0059c5ee.c
   doc: docs/20-math-utilities.md  |  summary: — Exception Unwind Handler (Free at +8)
        no cross-references found in .c files

227. 0x0059cdc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cdc0__Unwind_0059cdc0.c
   doc: docs/20-math-utilities.md  |  summary: — Unwind Thunk to 0x00581880
        no cross-references found in .c files

228. 0x0059d498  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d498__Unwind_0059d498.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind (exception destructor)
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
