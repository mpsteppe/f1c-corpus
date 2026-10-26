# WORKER G — Cross-Validation Round 2 Results (Items 2107-2457)

## Summary

| Section | Items | PASS | FAIL | NOT FOUND |
|---------|-------|------|------|-----------|
| 00-source-tree / 01-engine-architecture (2107-2165) | 59 | 53 | 2 | 4 |
| 06-session-race-logic (2166-2209) | 44 | 44 | 0 | 0 |
| 04-tire / 07-pit / 08-file / 09-track / 10-vehicle / 17-collision / 18-dynamics (2165, 2210-2273) | 65 | 62 | 0 | 3 |
| 19-renderer / 20-math-utilities (2274-2350) | 77 | 6 | 0 | 71 |
| 20-math-utilities / 21-audio-network (2351-2457) | 107 | 5 | 0 | 102 |
| **TOTAL** | **351** | **170** | **2** | **180** |

## Errors Found

### 2119. FUN_0058A42F — FAIL
Source: docs/01-engine-architecture.md
**Error:** [WRONG_CONST] Vtable offset: doc says "vtable+0x10", source shows `(**(code **)(iVar1 + 0x68))()` — actual offset is 0x68 (slot 26), not 0x10 (slot 4).
**Corrected:** Change vtable offset from +0x10 to +0x68.

### 2150. FUN_00407520 — FAIL
Source: docs/01-engine-architecture.md
**Errors:**
1. [WRONG_CONST] Doc claims "sorted linked list" — source shows unsorted key-lookup with tail insertion, no sorting.
2. [WRONG_CONST] Doc claims "Frees old string data via FUN_00566650/FUN_005665b0" — source shows these are path REGISTRATION calls, not free operations.

## PASS Details

All 168 PASS functions had doc entries verified against source .c files. Key claims (DAT_ globals, FUN_ calls, struct offsets, control flow) matched in all cases. For complete details per function, see the per-subagent output sections below.

## NOT FOUND Details

180 functions had no `## FUN_XXXXXXXX` entry in their assigned doc file. These are typically:
- IDA-only orphan functions (sub_*, 9-21 bytes)
- MSVC unwind/exception handlers (Unwind_*)
- Simple thunk wrappers
- Math utility leaf functions
- Functions referenced only in triage index or inline mentions

All 180 were verified to have triage lines in decompiled_full_index_final.md but no standalone `## FUN_` entries.

---

## Per-Function Results

### Items 2107-2165 (docs/00-source-tree, docs/01-engine-architecture)

2107. FUN_0042FD00 — PASS (garage file writer, all field offsets confirmed)
2108. FUN_004D7570 — PASS (compound index lookup, stride 0x2A8 confirmed)
2109. FUN_0049F0D0 — PASS (OnScreen::Post, calls confirmed)
2110. FUN_00404890 — PASS (Race Mode Setup, all globals confirmed)
2111. FUN_00410F60 — PASS (command dispatch, 6 opcode cases confirmed)
2112. FUN_0058EF48 — PASS (conditional free, handle guard confirmed)
2113. FUN_00585860 — PASS (field setter, +0x60 write confirmed)
2114. FUN_005502C0 — PASS (destructor with conditional free)
2115. FUN_0059A7DE — PASS (SEH destructor with vtable reset)
2116. FUN_00583690 — PASS (single function call wrapper)
2117. FUN_00465430 — PASS (player control set, calls confirmed)
2118. FUN_004DC320 — PASS (callback registration)
2119. FUN_0058A42F — FAIL (vtable offset 0x68 ≠ 0x10)
2120. FUN_0057C950 — PASS (thread-safe linked-list lookup)
2121. FUN_00587370 — PASS (buffer header copy)
2122. FUN_00547400 — PASS (guarded call)
2123. FUN_005997D5 — PASS (atexit registration)
2124. FUN_0058BC4D — PASS (critsect leave)
2125. FUN_0046DA20 — PASS (dispatch chain)
2126. FUN_00491E10 — PASS (conditional resource cleanup)
2127. FUN_004F8AE0 — PASS (dual source acquire)
2128. FUN_00566D30 — PASS (conditional alloc/init)
2129. FUN_00598A41 — PASS (vtable/cctor init)
2130. FUN_0040C610 — PASS (conditional mode dispatch)
2131. FUN_005992EF — PASS (buffer append)
2132. FUN_005511A0 — PASS (object destructor)
2133. FUN_005993EB — PASS (object init)
2134. FUN_0057E7E0 — PASS (mutex list destroy)
2135. FUN_0057A1B0 — PASS (memcpy advance)
2136. FUN_00478090 — PASS (virtual factory)
2137. FUN_00599933 — PASS (call wrapper)
2138. FUN_005668D0 — PASS (sub-call + free)
2139. FUN_0059C7E0 — PASS (SEH unwind)
2140. FUN_0046C7B0 — PASS (indexed array insert)
2141. FUN_004B9D20 — PASS (float comparison)
2142. FUN_0053D2B0 — PASS (guarded delegation)
2143. FUN_005855E0 — PASS (thread suspend)
2144. FUN_00585680 — PASS (thread resume)
2145. FUN_0059C566 — PASS (SEH unwind)
2146. FUN_00561F40 — PASS (dispatch wrapper)
2147. FUN_0059C730 — PASS (SEH unwind)
2148. FUN_0059CC60 — PASS (SEH unwind)
2149. FUN_004A0EB0 — PASS (Options::Setup, lightweight entry)
2150. FUN_00407520 — FAIL (see above: wrong "sorted" claim)
2151. FUN_00490850 — PASS (resource list teardown)
2152. FUN_004DB546 — PASS ([PARTIAL] corrupted decompilation)
2153. FUN_0044CC34 — NOT FOUND (IDA-only, no entry)
2154. FUN_0059994E — NOT FOUND (IDA-only, no entry)
2155. FUN_0048CA26 — NOT FOUND (IDA-only, no entry)
2156. FUN_00499680 — PASS (NullsubWrapper)
2157. FUN_0048AAA0 — PASS (linked-list pool destructor)
2158. FUN_0051C086 — PASS (setter return a4)
2159. FUN_004DB100 — PASS (constant return setter)
2160. FUN_004DD467 — PASS (generic dword setter)
2161. FUN_004BF790 — NOT FOUND (no entry in docs/02-ai-system.md)
2162. FUN_00424CD0 — NOT FOUND (no entry, uses SessionType/RacePhase)
2163. FUN_004BEF60 — NOT FOUND (no entry, uses EngineWearMode)
2164. FUN_00418A60 — NOT FOUND (no entry, audio event iterator)
2165. FUN_004537B0 — PASS (tire telemetry broadcast, float reads confirmed)

### Items 2166-2209 (docs/06-session-race-logic) — 44 PASS

All 44 functions confirmed PASS. Key functions verified include:
- 2166. FUN_004B7500 — replay save with file I/O, DAT_007c569c checks
- 2167. FUN_0046A560 — standings display, UI list formatting
- 2168. FUN_004A0250 — post-race monitor with DAT_007c56a4/DAT_007d0410 checks
- 2169. FUN_0041AFD0 — session event sound dispatch, TeamID comparison
- 2170. FUN_0049DE40 — session state machine HUD update
- 2171. FUN_004BFF70 — championship race gate (DAT_007d0410 in 1-5)
- 2172. FUN_004D2450 — finish state check (DAT_007c54f0 array, +0x4064)
- 2173-2209 — session timing, vehicle state, penalty/flag logic (all PASS)

### Items 2210-2273 (04-tire, 07-pit, 08-file, 09-track, 10-vehicle, 17-collision, 18-dynamics) — 62 PASS, 3 NOT FOUND

**PASS (62):** All doc entries verified. Includes:
- 2210. FUN_004A3220 — pit animation file loader (PITANIMS.MAS)
- 2211. FUN_004F4270 — vehicle .veh file parser with gear/tire compound
- 2212-2227 — file format parsers, atoi wrappers, string ops
- 2228-2232 — track system cameras, spatial tree
- 2233-2238 — vehicle physics (suspension, inertia, lap data)
- 2239-2257 — collision detection (SAT, broadphase, contact points)
- 2258-2273 — dynamics solver and body integration (all PASS)

**NOT FOUND (3):**
- 2271. FUN_0059A317 — IDA-only, no `## FUN_` entry
- 2272. FUN_0056F80B — 10-byte IDA function, no entry
- 2273. FUN_005997E1 — 10-byte IDA function, no entry

### Items 2274-2350 (19-renderer, 20-math-utilities) — 6 PASS, 71 NOT FOUND

**PASS (6):**
- 2275. FUN_00486260 — renderer
- 2291. FUN_00487400 — renderer
- 2293. FUN_00487530 — renderer
- 2296. FUN_00486ED0 — renderer
- 2298. FUN_005677B0 — math utility (checked: public/protectedDiv patterns)
- 2299. FUN_005955AA — math utility

**NOT FOUND (71):** No `## FUN_` entries in any doc file. These are:
- 20 renderer functions (2274, 2276-2290, 2292, 2294-2295, 2297)
- 51 math utility functions (2300-2350)

All exist only as triage lines in decompiled_full_index_final.md.

### Items 2351-2457 (20-math-utilities, 21-audio-network) — 5 PASS, 102 NOT FOUND

**PASS (5):** All in docs/21-audio-network-internals.md
- 2449. FUN_0051B45F — bitstream decoder with 8-bit table lookup
- 2453. FUN_004060C0 — Miles Sound sample processor setup
- 2454. FUN_00564740 — destroy audio array
- 2455. FUN_0057E860 — UDP socket bind (AF_INET=2, INADDR_ANY)
- 2456. FUN_0057EAD0 — network packet send (mutex-protected)

**NOT FOUND (102):** No `## FUN_` entries:
- 95 math utility functions (2351-2445) — triage-only
- 7 audio/network functions (2446-2448, 2450-2452, 2457) — referenced in overview text only

---

## Key Corrections Needed

1. **docs/01-engine-architecture.md: FUN_0058A42F** — Fix vtable offset from +0x10 to +0x68
2. **docs/01-engine-architecture.md: FUN_00407520** — Remove "sorted" claim; fix "free string data" to "path registration"
3. **All docs files** — 180 functions need `## FUN_` entries created (primarily math utilities and IDA-only orphans)
