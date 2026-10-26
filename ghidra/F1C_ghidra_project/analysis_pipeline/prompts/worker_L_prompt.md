# WORKER L — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker L of 20, items 2124–2316.

These functions are the "tissue" connecting already-documented game systems. Even the
smallest utility becomes meaningful when linked back to the system that uses it.
Write a full entry for EVERY function. No exceptions. Nothing is too small.

---

## STEP 1 — LOAD REFERENCE FILES BEFORE STARTING

Read these files FIRST and keep them in context throughout your session:

1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Complete named global list. Every DAT_ address you encounter: look it up here.
     Use the known name in your entry, not the raw address.

2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md`
   — Known struct field names by offset. Every struct access you document: check here first.
     Write "VehicleStruct.TireSlipAngle (+0x48)" not just "+0x48".

3. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\decompiled_full_index_final.md`
   — Master triage index. Use it to look up what called functions do (if they appear here).

These three files are your primary cross-reference tools. Use them for every entry.

---

## STEP 2 — YOUR OUTPUT FILE

Write ALL output to:
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_L.md

Exact structure:

```
=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00AAAAAA — First Function Name
...
```

Leave `=== TRIAGE LINES ===` EMPTY — entries already exist in the master index.
Write `<!-- target: docs/XX-name.md -->` immediately before EVERY `## FUN_` block.
Write to disk after EVERY function. No batching.

---

## STEP 3 — YOUR FILES (193 functions)

2124. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d0bc__thunk_FUN_0050d0af.c
   [category: Sys/Thunk | target: docs/20-math-utilities.md | lines: 16 | prior triage: Thunk: indirect jump via global pointer]
2125. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550820__FUN_00550820.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 26 | prior triage: Array-of-struct cleanup with countdown loop]
2126. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552f20__FUN_00552f20.c
   [category: Graphics/Texture | target: docs/19-renderer.md | lines: 45 | prior triage: Texture path parse & dimension calc]
2127. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554700__FUN_00554700.c
   [category: UI/Property | target: docs/01-engine-architecture.md | lines: 36 | prior triage: Set property value, trigger refresh if changed]
2128. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556980__FUN_00556980.c
   [category: Animation/Dispatch | target: docs/01-engine-architecture.md | lines: 32 | prior triage: Iterate objects, call animation handler per item]
2129. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005596e0__FUN_005596e0.c
   [category: Engine/Dispatch | target: docs/01-engine-architecture.md | lines: 31 | prior triage: Function pointer dispatch via linked traversal]
2130. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d200__FUN_0055d200.c
   [category: Data/StructInit | target: docs/20-math-utilities.md | lines: 21 | prior triage: Struct zero-init]
2131. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560c00__FUN_00560c00.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 13 | prior triage: State flag setter]
2132. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005628f0__FUN_005628f0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 27 | prior triage: Large stack struct zero-init + vtable call]
2133. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564580__FUN_00564580.c
   [category: Audio/Mixer | target: docs/21-audio-network-internals.md | lines: 19 | prior triage: Audio mixer sample get with fallback]
2134. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565dc0__FUN_00565dc0.c
   [category: Memory/Alloc | target: docs/01-engine-architecture.md | lines: 30 | prior triage: Allocate struct, init default values]
2135. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005679a5__FUN_005679a5.c
   [category: Data/ListTraverse | target: docs/20-math-utilities.md | lines: 23 | prior triage: List traversal with early exit]
2136. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005697a0__FUN_005697a0.c
   [category: Math/Reciprocal | target: docs/20-math-utilities.md | lines: 30 | prior triage: Struct copy with reciprocal division]
2137. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a040__FUN_0057a040.c
   [category: Engine/Wrapper | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Pass-through wrapper]
2138. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a810__FUN_0057a810.c
   [category: Engine/Call | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
2139. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b0d0__FUN_0057b0d0.c
   [category: Data/List | target: docs/20-math-utilities.md | lines: 25 | prior triage: Indexed linked-list node getter by position]
2140. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057dff0__FUN_0057dff0.c
   [category: Threading/Sync | target: docs/01-engine-architecture.md | lines: 49 | prior triage: Mutex-protected linked-list lookup by ID]
2141. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582eb0__FUN_00582eb0.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 47 | prior triage: Linked-list node removal with cleanup callback]
2142. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584f90__FUN_00584f90.c
   [category: Sync/MutexTimer | target: docs/01-engine-architecture.md | lines: 21 | prior triage: Mutex-guarded timer read]
2143. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585f90__FUN_00585f90.c
   [category: Threading/Sync | target: docs/01-engine-architecture.md | lines: 17 | prior triage: ReleaseMutex wrapper returning success]
2144. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586d70__FUN_00586d70.c
   [category: Graphics/Bitmap | target: docs/19-renderer.md | lines: 31 | prior triage: Test bitmap bits in texture region]
2145. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587580__FUN_00587580.c
   [category: Memory/Buffer | target: docs/01-engine-architecture.md | lines: 18 | prior triage: Buffer query: return ptr+size if valid]
2146. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587f64__FUN_00587f64.c
   [category: IO/Format | target: docs/08-file-formats.md | lines: 16 | prior triage: String format wrapper]
2147. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d6b__FUN_00589d6b.c
   [category: Threading/Lock | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Lock acquire by index]
2148. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a755__FUN_0058a755.c
   [category: Except | target: docs/01-engine-architecture.md | lines: 17 | prior triage: Conditional callback dispatch with SEH]
2149. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c07f____cfltcvt.c
   [category: Sys/CRT | target: docs/20-math-utilities.md | lines: 29 | prior triage: CRT float conversion dispatch (_cfltcvt)]
2150. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd4b____math_exit.c
   [category: Math/CRT | target: docs/20-math-utilities.md | lines: 24 | prior triage: __math_exit CRT math error handler]
2151. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059163b__FUN_0059163b.c
   [category: Math/Dispatch | target: docs/20-math-utilities.md | lines: 21 | prior triage: Math function dispatch with error fallback]
2152. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593cfd__FUN_00593cfd.c
   [category: Sys/SEH | target: docs/20-math-utilities.md | lines: 27 | prior triage: SEH-guarded function pointer call with cleanup]
2153. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059733d__FUN_0059733d.c
   [category: Memory/Check | target: docs/01-engine-architecture.md | lines: 14 | prior triage: IsBadWritePtr memory validation wrapper]
2154. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598aea__FUN_00598aea.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Vtable set + sub-call]
2155. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005992ef__FUN_005992ef.c
   [category: Mem/Buffer | target: docs/01-engine-architecture.md | lines: 26 | prior triage: Buffer append with memset fill]
2156. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059988b__FUN_0059988b.c
   [category: Engine/Call | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
2157. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a407__FUN_0059a407.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Pointer offset adjuster]
2158. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ab83__FUN_0059ab83.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 29 | prior triage: Object destructor with SEH + vtable release call]
2159. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bae8__FUN_0059bae8.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 12 | prior triage: File I/O forwarding wrapper]
2160. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4d2__Unwind_0059c4d2.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at -0x1c]
2161. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c616__Unwind_0059c616.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
2162. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c710__Unwind_0059c710.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
2163. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8b2__Unwind_0059c8b2.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2164. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059caa0__Unwind_0059caa0.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
2165. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc80__Unwind_0059cc80.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2166. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce76__Unwind_0059ce76.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2167. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfcc__Unwind_0059cfcc.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2168. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d118__Unwind_0059d118.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2169. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d318__Unwind_0059d318.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
2170. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d51c__Unwind_0059d51c.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2171. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401080__FUN_00401080.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2172. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d00__FUN_00404d00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2173. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405880__FUN_00405880.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2174. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406ab0__FUN_00406ab0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 39 | prior triage: short computation]
2175. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004081e0__FUN_004081e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
2176. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a610__FUN_0040a610.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 35 | prior triage: short computation]
2177. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c870__FUN_0040c870.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 24 | prior triage: short computation]
2178. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dbe0__FUN_0040dbe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2179. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ebd0__FUN_0040ebd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 33 | prior triage: short computation]
2180. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b40__FUN_00410b40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2181. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004141f0__FUN_004141f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2182. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004184b0__FUN_004184b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
2183. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b970__FUN_0041b970.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2184. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421470__FUN_00421470.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2185. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421ab0__FUN_00421ab0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2186. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004263eb__FUN_004263eb.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2187. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456010__FUN_00456010.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2188. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00458020__FUN_00458020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2189. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b9c0__FUN_0045b9c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 42 | prior triage: unidentified]
2190. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c0a0__FUN_0045c0a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2191. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e570__FUN_0045e570.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2192. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004615c0__FUN_004615c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2193. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004623e0__FUN_004623e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2194. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463d50__FUN_00463d50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
2195. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464bb0__FUN_00464bb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
2196. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466160__FUN_00466160.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: trig/math computation]
2197. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004685b0__FUN_004685b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2198. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b5c0__FUN_0046b5c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2199. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e590__FUN_0046e590.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2200. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470230__FUN_00470230.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2201. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471a00__FUN_00471a00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2202. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473cc0__FUN_00473cc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2203. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475140__FUN_00475140.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2204. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477810__FUN_00477810.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2205. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478bc0__FUN_00478bc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2206. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479970__FUN_00479970.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2207. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a210__FUN_0047a210.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2208. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047bd90__FUN_0047bd90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
2209. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f080__FUN_0047f080.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2210. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004856f0__FUN_004856f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2211. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486400__FUN_00486400.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 31 | prior triage: unidentified]
2212. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487160__FUN_00487160.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2213. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487e10__FUN_00487e10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: unidentified]
2214. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489440__FUN_00489440.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2215. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b7e0__FUN_0048b7e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2216. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d1a0__FUN_0048d1a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2217. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e360__FUN_0048e360.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2218. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fc10__FUN_0048fc10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2219. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004903f0__FUN_004903f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
2220. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491710__FUN_00491710.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2221. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491e80__FUN_00491e80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2222. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004950e0__FUN_004950e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2223. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495b60__FUN_00495b60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: unidentified]
2224. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497890__FUN_00497890.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 42 | prior triage: unidentified]
2225. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498940__FUN_00498940.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
2226. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004991e0__FUN_004991e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2227. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004999e0__FUN_004999e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2228. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e30__FUN_00499e30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2229. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2e0__FUN_0049a2e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2230. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049adc0__FUN_0049adc0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 38 | prior triage: unidentified]
2231. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d8b0__FUN_0049d8b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 45 | prior triage: unidentified]
2232. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f150__FUN_0049f150.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2233. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0de0__FUN_004a0de0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2234. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1fb0__FUN_004a1fb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2235. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4000__FUN_004a4000.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2236. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a7010__FUN_004a7010.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2237. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a10__FUN_004b1a10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2238. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2480__FUN_004b2480.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
2239. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b10__FUN_004b2b10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2240. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b41c0__FUN_004b41c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2241. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b50c0__FUN_004b50c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2242. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9ac0__FUN_004b9ac0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: unidentified logic]
2243. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba790__FUN_004ba790.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2244. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb0c0__FUN_004bb0c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
2245. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc2d0__FUN_004bc2d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2246. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be010__FUN_004be010.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2247. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c22a0__FUN_004c22a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: utility function]
2248. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2f20__FUN_004c2f20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
2249. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c5de0__FUN_004c5de0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: unidentified logic]
2250. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c84a0__FUN_004c84a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: memory allocation]
2251. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9060__FUN_004c9060.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2252. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca410__FUN_004ca410.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2253. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cefa0__FUN_004cefa0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
2254. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4780__FUN_004d4780.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2255. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c50__FUN_004d5c50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2256. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7de0__FUN_004d7de0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2257. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8fb0__FUN_004d8fb0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: unidentified logic]
2258. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbab0__FUN_004dbab0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2259. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcba0__FUN_004dcba0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
2260. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd4e0__FUN_004dd4e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
2261. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dfca0__FUN_004dfca0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2262. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ea930__FUN_004ea930.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2263. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f62e6__FUN_004f62e6.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2264. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c50__FUN_004f8c50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2265. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9b20__FUN_004f9b20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
2266. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc910__FUN_004fc910.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: unidentified logic]
2267. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005001b0__FUN_005001b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2268. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502bea__FUN_00502bea.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2269. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005043c9__FUN_005043c9.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: unidentified logic]
2270. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ab35__FUN_0050ab35.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2271. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b42a__FUN_0050b42a.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2272. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c134__FUN_0050c134.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2273. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d44f__FUN_0050d44f.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2274. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050df88__FUN_0050df88.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2275. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f6f7__FUN_0050f6f7.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
2276. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051177c__FUN_0051177c.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: arithmetic/comparison]
2277. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005124d5__FUN_005124d5.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2278. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005151af__FUN_005151af.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
2279. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005164a6__FUN_005164a6.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
2280. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ac5__FUN_00517ac5.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2281. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051a87e__FUN_0051a87e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520fc6__FUN_00520fc6.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified logic]
2283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00527eed__FUN_00527eed.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052df10__FUN_0052df10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534e70__FUN_00534e70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: unidentified logic]
2286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536e90__FUN_00536e90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
2287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b110__FUN_0053b110.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c1b0__FUN_0053c1b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053cb90__FUN_0053cb90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
2290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053fc30__FUN_0053fc30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541f60__FUN_00541f60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: unidentified logic]
2292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005435c0__FUN_005435c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546fe0__FUN_00546fe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547860__FUN_00547860.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005491d0__FUN_005491d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: memory allocation]
2296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b4d0__FUN_0054b4d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eb20__FUN_0054eb20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550810__FUN_00550810.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: destructor/free wrapper: FUN_00587bcf(param_1+4)]
2299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557350__FUN_00557350.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: Struct default initializer (1.0f, 100.0f, 0x10002 flags)]
2300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c7b0__FUN_0055c7b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: Calls FUN_0055c450 with field at param_1+0x13e8 (large offset)]
2301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564220__FUN_00564220.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 34 | prior triage: String tokenizer (strtok-like) using DAT_008cfae4 state]
2302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567010__FUN_00567010.c
   [category: Math | target: docs/20-math-utilities.md | lines: 13 | prior triage: Dual math call wrapper]
2303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00579fb0__FUN_00579fb0.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Single delegation call]
2304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae30__FUN_0057ae30.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Call wrapper]
2305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005853b0__FUN_005853b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: Vtable dispatch with FUN_00586e50 copy and FUN_00584e30 check]
2306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587220__FUN_00587220.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter at +0x10]
2307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005881f0__FUN_005881f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: Passes two x87 floats (ST0,ST1) to FUN_00588212]
2308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a8a3__FUN_0058a8a3.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 39 | prior triage: Float NaN/inf classification — decode exponent bits, return type code]
2309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dd3e__FUN_0058dd3e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: empty void stub — no-op]
2310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595304__FUN_00595304.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: zeroes 3 consecutive ints (vector zero)]
2311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059870c__FUN_0059870c.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: thunk to FUN_00598b5d(0,1)]
2312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998c0__FUN_005998c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: thunk to FUN_00599b86(0,1)]
2313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ba1d__FUN_0059ba1d.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 37 | prior triage: Windows dir/env API — SetCurrentDirectoryA + SetEnvironmentVariableA]
2314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c830__Unwind_0059c830.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581a20]
2315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf2f__Unwind_0059cf2f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581750]
2316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d7d1__FUN_0059d7d1.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: ExitProcess wrapper — writes DAT_008d3eb0 before termination]

---

## FULL ENTRY FORMAT

```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Descriptive Name

Source: filename.cpp | Confidence: high/medium/low
One-line summary of what this function does.

**Key logic:**
- What it does step by step
- All constants, thresholds, formulas with exact values
- All branches and what triggers each path
- For math: name the algorithm (dot product, cross product, lerp, clamp, normalize,
  matrix multiply, quaternion op, euler angles, bezier, PID, etc.)
- For wrappers: what CRT/Win32/library function is wrapped and why

**Struct offsets (param_1):**
| Offset | Field name (from docs/13 if known) | Type | Notes |
|--------|-------------------------------------|------|-------|
| +0xXXX | VehicleStruct.FieldName or unknown  | float/int/double | purpose |

**Globals:**
- `DAT_007c56a4` (SessionType) — read/written [use known name from docs/12]

**Calls:**
- FUN_00AAAAAA — [look up in triage index or docs/; cite name if known] what it does
- FUN_00BBBBBB — what it does

**Used by system:** docs/XX-name.md — [which documented game system likely calls this;
  infer from: what the function does, what globals/structs it touches, what it calls,
  and what nearby documented functions (same address range) belong to]

**Algorithm family:** [math_util only] e.g. "3D vector math", "quaternion ops",
  "matrix transform", "spline/bezier", "PID controller", "audio DSP", "collision geometry"

**Moddability:** configurable | hardcoded | hookable
```

---

## SOURCE FILE INFERENCE

Functions compiled from the same .cpp file cluster in consecutive address ranges.
To infer source file for a function at address 0x00XXXXXX:
1. Check for assert strings in the code — they contain the real source path directly.
2. Look at nearby documented functions (same 0x00XX__ prefix) in docs/ or the triage
   index — if they have a known source, this function likely shares it.
3. Use what the function does + what it calls to guess the module
   (tire math → tire_model.cpp, network packet → NetSocket.cpp, etc.).
4. If none of the above: write `Source: unknown`.

---

## RULES BY PRIOR CATEGORY

`math_util` — Name the algorithm. Document input/output types and all constants.
  Even "returns param_1 + 100": what is 100? An offset? A bias? An enum base?
  Tag the algorithm family so related functions can be clustered later.

`unknown` — Read the code mechanically. List every struct access, every called function,
  every constant. Write what you observe. Include a confidence level. Even "unknown purpose,
  reads +0x3C and +0x40 from param_1, multiplies by 0.5" is valuable for consensus.

`crt_util` / library wrappers — Name the wrapped function. Note calling convention,
  parameter forwarding, and why this wrapper exists at this address in the binary.

Thunks (unconditional jmp to another function):
```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Thunk to FUN_YYYYYYYY

Source: unknown | Confidence: high
Trampoline — unconditional jmp to FUN_YYYYYYYY. No local logic.

**Key logic:**
- Single jmp instruction; address 0x00XXXXXX appears in a vtable, IAT, or call stub
- Call target: FUN_YYYYYYYY [look up its name in docs/ or triage index if available]

**Calls:** FUN_YYYYYYYY (target — [name if known])

**Used by system:** [infer from what FUN_YYYYYYYY does]

**Moddability:** hardcoded
```

Empty stubs (body is return only):
```
<!-- target: docs/XX-name.md -->
## FUN_00XXXXXX — Empty Stub

Source: unknown | Confidence: high
Returns immediately with no logic. Placeholder or stripped virtual method.

**Key logic:**
- No operations — bare return
- Address 0x00XXXXXX is referenced somewhere (vtable slot, callback registration)
- Likely a virtual method that was never implemented or was stripped at link time

**Used by system:** [infer from address range neighbors]

**Moddability:** hardcoded
```

Non-standard category labels (GameLogic, Render, Physics, Entity, etc.):
treat as the equivalent standard category.

---

## GHIDRA PATTERN DECODING

- `*(double *)(ptr + 0x1330)` → offset +0x1330, type double — check docs/13
- `param_1[0x4a]` → int-indexed: byte offset = 0x4a × 4 = 0x128 — check docs/13
- `unaff_EBX` / `unaff_ESI` / `unaff_EBP` → register-allocated `this` pointer
- `goto` chains → MSVC loop artifact — ignore the goto, document the loop logic
- `thunk_FUN_XXXXXX` → trampoline wrapper — document as thunk
- `DAT_XXXXXXXX` → global variable — resolve name from docs/12 before writing

---

## TARGET ROUTING

Use the suggested target in your file list. Override only if the code clearly
belongs to a different system:
- game_logic / entity / engine → docs/01 through 10 (match the system)
- collision → docs/17-physics-collision.md
- physics_math / dynamics → docs/18-physics-dynamics.md
- renderer / graphics → docs/19-renderer.md
- math_util / unknown / CRT / misc → docs/20-math-utilities.md
- audio / network → docs/21-audio-network-internals.md
- file I/O / formats → docs/08-file-formats.md

---

## RULES

0. NEVER move, rename, or delete .c files.
1. Read docs/12, docs/13, and the triage index BEFORE processing any function.
2. Write a full ## FUN_ entry for EVERY file — no exceptions, no one-liners.
3. Write `<!-- target: docs/XX-name.md -->` before EVERY `## FUN_` block.
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_L.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
