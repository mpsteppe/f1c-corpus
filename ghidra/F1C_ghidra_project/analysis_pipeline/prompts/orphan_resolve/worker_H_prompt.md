# WORKER H — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker H of 15, items 179–203.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_H.md

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

179. 0x00407070  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407070__FUN_00407070.c
   doc: docs/01-engine-architecture.md  |  summary: — Array + Linked-List Virtual Dispatch Iterator
        no cross-references found in .c files

180. 0x0044c800  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c800__FUN_0044c800.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Region Init 5 (Type 6, -1.0f)
        no cross-references found in .c files

181. 0x0044cda0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cda0__FUN_0044cda0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision State Init (Slot 0x22, Scale 1.0)
        no cross-references found in .c files

182. 0x0044d340  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d340__FUN_0044d340.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGlobalInitG
        no cross-references found in .c files

183. 0x0044d8e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d8e0__FUN_0044d8e0.c
   doc: docs/17-physics-collision.md  |  summary: — Initialize Collision Globals A
        no cross-references found in .c files

184. 0x0044de80  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de80__FUN_0044de80.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Init (Set 0x37)
        no cross-references found in .c files

185. 0x0044e420  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e420__FUN_0044e420.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStateInit_4e
        no cross-references found in .c files

186. 0x0044e9c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e9c0__FUN_0044e9c0.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

187. 0x00462410  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462410__FUN_00462410.c
   doc: docs/20-math-utilities.md  |  summary: — Struct Array Copy at Stride 0x8C
        no cross-references found in .c files

188. 0x004782c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004782c0__FUN_004782c0.c
   doc: docs/20-math-utilities.md  |  summary: — State Sync with Dirty Flag
        no cross-references found in .c files

189. 0x00494600  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494600__FUN_00494600.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Global Zeroing
        no cross-references found in .c files

190. 0x004c9310  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9310__FUN_004c9310.c
   doc: docs/19-renderer.md  |  summary: — Resource Release Triple Dispatch
        no cross-references found in .c files

191. 0x0050c4bb  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c4bb__FUN_0050c4bb.c
   doc: docs/20-math-utilities.md  |  summary: — Bilinear Interpolation (3D)
        no cross-references found in .c files

192. 0x0050dd40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd40__FUN_0050dd40.c
   doc: docs/20-math-utilities.md  |  summary: — Euler Angles to Quaternion
        no cross-references found in .c files

193. 0x005111d3  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005111d3__FUN_005111d3.c
   doc: docs/20-math-utilities.md  |  summary: — JPEG Marker Reader
        no cross-references found in .c files

194. 0x0052e520  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e520__FUN_0052e520.c
   doc: docs/20-math-utilities.md  |  summary: — Halt/Assert Handler
        no cross-references found in .c files

195. 0x005567e1  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567e1__FUN_005567e1.c
   doc: docs/20-math-utilities.md  |  summary: — Float Scale and Round to Int
        no cross-references found in .c files

196. 0x005667b0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005667b0__FUN_005667b0.c
   doc: docs/20-math-utilities.md  |  summary: — In-Place String Shift (Subset Memmove)
        no cross-references found in .c files

197. 0x00588640  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588640___strncmp.c
   doc: docs/06-session-race-logic.md  |  summary: @ 0x00588640
        no cross-references found in .c files

198. 0x0058da70  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058da70____trandisp1.c
   doc: docs/20-math-utilities.md  |  summary: — __trandisp1 (CRT)
        no cross-references found in .c files

199. 0x0059863c  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059863c__bind.c
   doc: docs/21-audio-network-internals.md  |  summary: — bind() Wrapper
        no cross-references found in .c files

200. 0x00598696  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598696__inet_ntoa.c
   doc: docs/21-audio-network-internals.md  |  summary: — inet_ntoa (import thunk)
        no cross-references found in .c files

201. 0x0059c5e4  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5e4__Unwind_0059c5e4.c
   doc: docs/20-math-utilities.md  |  summary: — SEH Unwind Handler
        no cross-references found in .c files

202. 0x0059cd00  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd00__Unwind_0059cd00.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Cleanup
        no cross-references found in .c files

203. 0x0059d484  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d484__Unwind_0059d484.c
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
