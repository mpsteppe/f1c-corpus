# WORKER F — F1C Orphan Function Resolution

You are classifying 25 orphan functions — functions with NO known callers and NO
known callees in the call graph. Your job: find HOW each function gets called and
WHY it has no documented edges.

Worker F of 15, items 129–153.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges. Orphans have no entry here.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges. Orphans have no entry here either.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals. Use to identify whether orphan touches game state.

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\orphan_resolve\worker_F.md

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

129. 0x004066c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004066c0__FUN_004066c0.c
   doc: docs/01-engine-architecture.md  |  summary: — Mutex-Protected Value Read with Timeout
        no cross-references found in .c files

130. 0x0044c740  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c740__FUN_0044c740.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionGridInit4
        no cross-references found in .c files

131. 0x0044cce0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cce0__FUN_0044cce0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Material Init (Type 0x20)
        no cross-references found in .c files

132. 0x0044d280  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d280__FUN_0044d280.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Subsystem Init (DAT_007ca57c)
        no cross-references found in .c files

133. 0x0044d820  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d820__FUN_0044d820.c
   doc: docs/17-physics-collision.md  |  summary: — InitKeyboardAxis0
        no cross-references found in .c files

134. 0x0044ddc0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ddc0__FUN_0044ddc0.c
   doc: docs/17-physics-collision.md  |  summary: — CollisionTableInit_35
        no cross-references found in .c files

135. 0x0044e360  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e360__FUN_0044e360.c
   doc: not documented  |  summary: collision detection
        no cross-references found in .c files

136. 0x0044e900  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e900__FUN_0044e900.c
   doc: docs/17-physics-collision.md  |  summary: — Collision State Init 3
        no cross-references found in .c files

137. 0x0044fbb0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fbb0__FUN_0044fbb0.c
   doc: docs/17-physics-collision.md  |  summary: — Collision Data Copy
        no cross-references found in .c files

138. 0x00478220  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478220__FUN_00478220.c
   doc: docs/20-math-utilities.md  |  summary: — Monitors Changed Selection
        no cross-references found in .c files

139. 0x0048fc10  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fc10__FUN_0048fc10.c
   doc: docs/20-math-utilities.md  |  summary: General utility function. See decompiled code for exact behavior.
        no cross-references found in .c files

140. 0x004c1660  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1660__thunk_FUN_004c0f60.c
   doc: docs/20-math-utilities.md  |  summary: @ 0x004c1660 — NOT FOUND
        no cross-references found in .c files

141. 0x0050c2e3  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2e3__FUN_0050c2e3.c
   doc: docs/18-physics-dynamics.md  |  summary: — Cubic Bezier/Interpolation (3D)
        no cross-references found in .c files

142. 0x0050dcb0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dcb0__FUN_0050dcb0.c
   doc: docs/19-renderer.md  |  summary: Compute rotation matrix from axis vector and angle.
        no cross-references found in .c files

143. 0x00510975  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510975__FUN_00510975.c
   doc: docs/21-audio-network-internals.md  |  summary: â€” Byte-Stream Event Decompressor
        no cross-references found in .c files

144. 0x0052d8c0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8c0__thunk_FUN_0052d990.c
   doc: docs/20-math-utilities.md  |  summary: — VTable Destructor Wrapper with Null Check
        no cross-references found in .c files

145. 0x005567a9  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005567a9__FUN_005567a9.c
   doc: docs/20-math-utilities.md  |  summary: — Fixed-Point Division with Sign Handling
        no cross-references found in .c files

146. 0x00564680  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564680__WSACleanup.c
   doc: docs/21-audio-network-internals.md  |  summary: — WSACleanup Thunk
        no cross-references found in .c files

147. 0x00587dd0  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587dd0___strncpy.c
   doc: docs/20-math-utilities.md  |  summary: � MSVC CRT _strncpy
        no cross-references found in .c files

148. 0x0058bb10  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bb10___memset.c
   doc: docs/20-math-utilities.md  |  summary: @ 0x0058bb10 — NOT FOUND
        no cross-references found in .c files

149. 0x00598630  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598630__ntohs.c
   doc: docs/21-audio-network-internals.md  |  summary: — ntohs (Winsock Thunk)
        no cross-references found in .c files

150. 0x0059868a  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059868a__setsockopt.c
   doc: docs/21-audio-network-internals.md  |  summary: — setsockopt Wrapper
        no cross-references found in .c files

151. 0x0059c464  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c464__Unwind_0059c464.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind (Free EBP-0x30)
        no cross-references found in .c files

152. 0x0059cbe8  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cbe8__Unwind_0059cbe8.c
   doc: docs/20-math-utilities.md  |  summary: — C++ Unwind Helper (Thunk to FUN_005819c0)
        no cross-references found in .c files

153. 0x0059d3cc  —  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3cc__Unwind_0059d3cc.c
   doc: docs/01-engine-architecture.md  |  summary: — SEH Unwind Conditional Cleanup
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
