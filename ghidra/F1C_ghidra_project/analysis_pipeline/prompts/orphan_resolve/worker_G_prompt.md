# WORKER G — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker G of 15, items 154–178.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_G.md

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

154. 0x00406f90  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406f90__FUN_00406f90.c
   doc: docs/20-math-utilities.md  |  summary: — Object Array + Linked-List Walk
        no cross-references found in .c files

155. 0x0044c7a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c7a0__FUN_0044c7a0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionStateInit_Alpha
        no cross-references found in .c files

156. 0x0044cd40  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd40__FUN_0044cd40.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGlobalsInit
        no cross-references found in .c files

157. 0x0044d2e0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d2e0__FUN_0044d2e0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGlobalsInit
        no cross-references found in .c files

158. 0x0044d880  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d880__FUN_0044d880.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Subsystem Init (DAT_007ccc38)
        no cross-references found in .c files

159. 0x0044de20  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de20__FUN_0044de20.c
   doc: docs/17-physics-collision.md  |  summary: — Collision global init (group 0x36)
        no cross-references found in .c files

160. 0x0044e3c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e3c0__FUN_0044e3c0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGridInit77
        no cross-references found in .c files

161. 0x0044e960  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e960__FUN_0044e960.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

162. 0x0045bf90  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf90__FUN_0045bf90.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Mutex Initialization
        no cross-references found in .c files

163. 0x004782a0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004782a0__FUN_004782a0.c
   doc: docs/20-math-utilities.md  |  summary: — Resource Alloc + Store
        no cross-references found in .c files

164. 0x0048fe30  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fe30__FUN_0048fe30.c
   doc: docs/20-math-utilities.md  |  summary: � Virtual Dispatch on Sub-Object
        no cross-references found in .c files

165. 0x004c8ee0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8ee0__FUN_004c8ee0.c
   doc: docs/20-math-utilities.md  |  summary: — Singleton Init
        no cross-references found in .c files

166. 0x0050c3bb  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c3bb__FUN_0050c3bb.c
   doc: docs/20-math-utilities.md  |  summary: � Cubic Bezier Interpolation (3D)
        no cross-references found in .c files

167. 0x0050dd3a  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd3a__thunk_FUN_0050dd0c.c
   doc: docs/20-math-utilities.md  |  summary: — Thunk via Function Pointer
        no cross-references found in .c files

168. 0x00510f89  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510f89__FUN_00510f89.c
   doc: docs/20-math-utilities.md  |  summary: — Stream Read: 2-Byte Token Parser
        no cross-references found in .c files

169. 0x0052e1c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e1c0__thunk_FUN_0052d9b0.c
   doc: docs/01-engine-architecture.md  |  summary: — Thunk with VTable + Flag Check
        no cross-references found in .c files

170. 0x005567d3  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567d3__FUN_005567d3.c
   doc: docs/20-math-utilities.md  |  summary: — Float Round to Int
        no cross-references found in .c files

171. 0x005653f0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005653f0__thunk_FUN_00565400.c
   doc: not documented  |  summary: --
        no cross-references found in .c files

172. 0x005884ed  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005884ed___rand.c
   doc: docs/20-math-utilities.md  |  summary: — _rand() LCG Random Number Generator
        no cross-references found in .c files

173. 0x0058c6f0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c6f0____allmul.c
   doc: docs/20-math-utilities.md  |  summary: — __allmul (64-bit Integer Multiply)
        no cross-references found in .c files

174. 0x00598636  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598636__getsockname.c
   doc: docs/21-audio-network-internals.md  |  summary: — getsockname (import thunk)
        no cross-references found in .c files

175. 0x00598690  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598690____WSAFDIsSet.c
   doc: docs/21-audio-network-internals.md  |  summary: — __WSAFDIsSet (Winsock Thunk)
        no cross-references found in .c files

176. 0x0059c53e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c53e__Unwind_0059c53e.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind (Free EBP-0x14)
        no cross-references found in .c files

177. 0x0059cc1e  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc1e__Unwind_0059cc1e.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind: Free at -0x1C
        no cross-references found in .c files

178. 0x0059d470  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d470__Unwind_0059d470.c
   doc: docs/01-engine-architecture.md  |  summary: SEH unwind handler -- destructs an exception object at stack offset EBP-0x14 during exception unwinding.
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
