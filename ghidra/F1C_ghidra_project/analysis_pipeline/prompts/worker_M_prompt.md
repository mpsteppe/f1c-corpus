# WORKER M — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker M of 20, items 2317–2509.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_M.md

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

2317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050dd3a__thunk_FUN_0050dd0c.c
   [category: thunk | target: docs/20-math-utilities.md | lines: 14 | prior triage: trampoline to thunk_FUN_0050dd0c]
2318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005511a0__FUN_005511a0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 33 | prior triage: Object destructor with array cleanup]
2319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552fc0__FUN_00552fc0.c
   [category: Data/FieldSet | target: docs/20-math-utilities.md | lines: 12 | prior triage: Field set]
2320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554b20__FUN_00554b20.c
   [category: Game/Resource | target: docs/01-engine-architecture.md | lines: 38 | prior triage: Resource creation via VTable dispatch]
2321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005569f0__FUN_005569f0.c
   [category: Game/State | target: docs/01-engine-architecture.md | lines: 48 | prior triage: State flags init & propagation]
2322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559760__FUN_00559760.c
   [category: Data/Search | target: docs/20-math-utilities.md | lines: 46 | prior triage: String search in linked list]
2323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d2a0__FUN_0055d2a0.c
   [category: String | target: docs/01-engine-architecture.md | lines: 24 | prior triage: String copy with field union]
2324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560e50__FUN_00560e50.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 31 | prior triage: Multi-field object destructor with cleanup calls]
2325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562c80__FUN_00562c80.c
   [category: Render | target: docs/19-renderer.md | lines: 12 | prior triage: Init wrapper passing default param]
2326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564640__GetTickCount.c
   [category: Thunk/Win32 | target: docs/20-math-utilities.md | lines: 16 | prior triage: GetTickCount import stub]
2327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565ed0__FUN_00565ed0.c
   [category: Data/ListPeek | target: docs/20-math-utilities.md | lines: 16 | prior triage: Linked list peek with null check]
2328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005679c0__FUN_005679c0.c
   [category: Data/Search | target: docs/20-math-utilities.md | lines: 28 | prior triage: String-keyed linked list search]
2329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005697f0__FUN_005697f0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 22 | prior triage: Triple buffer allocation with operator_new]
2330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a070__FUN_0057a070.c
   [category: String/Transform | target: docs/20-math-utilities.md | lines: 23 | prior triage: Copy string with bytewise OR transform]
2331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a830__FUN_0057a830.c
   [category: UI/Check | target: docs/01-engine-architecture.md | lines: 14 | prior triage: vtable boolean test wrapper]
2332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b530__FUN_0057b530.c
   [category: Buffer/Reset | target: docs/20-math-utilities.md | lines: 13 | prior triage: Reset ring buffer head/tail to 0]
2333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e6e0__FUN_0057e6e0.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 38 | prior triage: Linked list destruction with mutex protection]
2334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582f60__FUN_00582f60.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 37 | prior triage: SEH-wrapped linked list destruction with vtable release call]
2335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00584ff0__FUN_00584ff0.c
   [category: String | target: docs/01-engine-architecture.md | lines: 16 | prior triage: String copy with length cap]
2336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585fb0__FUN_00585fb0.c
   [category: Data/ListCleanup | target: docs/20-math-utilities.md | lines: 29 | prior triage: Linked list cleanup with sub-object delete]
2337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586de0__FUN_00586de0.c
   [category: Algo/Bitmask | target: docs/20-math-utilities.md | lines: 31 | prior triage: Bitmask generation from bit array]
2338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005875c0__FUN_005875c0.c
   [category: Memory/Buffer | target: docs/01-engine-architecture.md | lines: 38 | prior triage: Reallocate buffer, copy data, free old]
2339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587f90__FUN_00587f90.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 41 | prior triage: File tell/position query]
2340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d74__FUN_00589d74.c
   [category: Sync/CriticalSection | target: docs/01-engine-architecture.md | lines: 12 | prior triage: CritSect leave (slot 0xd)]
2341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a770___longjmp.c
   [category: Sys/CRT | target: docs/20-math-utilities.md | lines: 38 | prior triage: _longjmp implementation (MSVC CRT)]
2342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c0d0__FUN_0058c0d0.c
   [category: String/Edit | target: docs/20-math-utilities.md | lines: 17 | prior triage: Shift string content by offset]
2343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058df5c__FUN_0058df5c.c
   [category: Math/Check | target: docs/20-math-utilities.md | lines: 32 | prior triage: Double classification: integer/divisible check]
2344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591c79__FUN_00591c79.c
   [category: Error/Code | target: docs/20-math-utilities.md | lines: 22 | prior triage: Set error code based on input value]
2345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593db8__FUN_00593db8.c
   [category: Engine/GlobalCallback | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Global callback with null check]
2346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597359__FUN_00597359.c
   [category: Sys/CodePtr | target: docs/20-math-utilities.md | lines: 14 | prior triage: Code pointer validation (IsBadCodePtr)]
2347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598af5__FUN_00598af5.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 32 | prior triage: Object constructor with vtable setup + SEH]
2348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599348__FUN_00599348.c
   [category: Mem/Buffer | target: docs/01-engine-architecture.md | lines: 33 | prior triage: Buffer truncation/shrink]
2349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998a1__FUN_005998a1.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Vtable fixup]
2350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a418__Gninc.c
   [category: I/O/CRT | target: docs/20-math-utilities.md | lines: 21 | prior triage: std::_Gninc stream buffer pointer increment]
2351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059abcd__FUN_0059abcd.c
   [category: Data/ObjectInit | target: docs/20-math-utilities.md | lines: 32 | prior triage: Object constructor with vtable & string init]
2352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bbaf__FUN_0059bbaf.c
   [category: IO | target: docs/08-file-formats.md | lines: 16 | prior triage: Three-step stream query (init, query, cleanup)]
2353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4e6__Unwind_0059c4e6.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
2354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c62a__Unwind_0059c62a.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
2355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c750__Unwind_0059c750.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
2356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8d0__Unwind_0059c8d0.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
2357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cac0__Unwind_0059cac0.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
2358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cc9e__Unwind_0059cc9e.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
2359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce8c__Unwind_0059ce8c.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfe8__Unwind_0059cfe8.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d150__Unwind_0059d150.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
2362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d328__Unwind_0059d328.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with exception cleanup call]
2363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d52f__Unwind_0059d52f.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401090__FUN_00401090.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d10__FUN_00404d10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004058a0__FUN_004058a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406b80__FUN_00406b80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408210__FUN_00408210.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040a890__FUN_0040a890.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 34 | prior triage: short computation]
2370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c890__FUN_0040c890.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 24 | prior triage: short computation]
2371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dcd0__FUN_0040dcd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 29 | prior triage: short computation]
2372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ec70__FUN_0040ec70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 33 | prior triage: short computation]
2373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b60__FUN_00410b60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414200__FUN_00414200.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004184f0__FUN_004184f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 28 | prior triage: short computation]
2376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041e840__FUN_0041e840.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 24 | prior triage: short computation]
2377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421480__FUN_00421480.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421ad0__FUN_00421ad0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426cc0__FUN_00426cc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: short computation]
2380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456040__FUN_00456040.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582a0__FUN_004582a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ba60__FUN_0045ba60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 64 | prior triage: unidentified]
2383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c3c0__FUN_0045c3c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e590__FUN_0045e590.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004615f0__FUN_004615f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
2386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462410__FUN_00462410.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified]
2387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463dc0__FUN_00463dc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464bd0__FUN_00464bd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004661b0__FUN_004661b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 30 | prior triage: float computation]
2390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004685f0__FUN_004685f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046b5e0__FUN_0046b5e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e5c0__FUN_0046e5c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470250__FUN_00470250.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471b20__FUN_00471b20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473dd0__FUN_00473dd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475530__FUN_00475530.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: references global state]
2397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477ea0__FUN_00477ea0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478e10__FUN_00478e10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004799a0__FUN_004799a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a230__FUN_0047a230.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be00__FUN_0047be00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 31 | prior triage: unidentified]
2402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f180__FUN_0047f180.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 37 | prior triage: unidentified]
2403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485720__FUN_00485720.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486460__FUN_00486460.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487220__FUN_00487220.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487e70__FUN_00487e70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
2407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489450__FUN_00489450.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b810__FUN_0048b810.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 69 | prior triage: unidentified]
2409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d230__FUN_0048d230.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 31 | prior triage: short computation]
2410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e5c0__FUN_0048e5c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: unidentified]
2411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fc50__FUN_0048fc50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490640__FUN_00490640.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491740__FUN_00491740.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491ee0__FUN_00491ee0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: unidentified]
2415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495110__FUN_00495110.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
2416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496280__FUN_00496280.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497940__FUN_00497940.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d00__FUN_00498d00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499260__FUN_00499260.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a20__FUN_00499a20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e40__FUN_00499e40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a2f0__FUN_0049a2f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
2423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ae40__FUN_0049ae40.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 40 | prior triage: unidentified]
2424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049da60__FUN_0049da60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
2425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f6a0__FUN_0049f6a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: unidentified]
2426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0df0__FUN_004a0df0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: unidentified logic]
2427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1fd0__FUN_004a1fd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4030__FUN_004a4030.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8af0__FUN_004a8af0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a30__FUN_004b1a30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2580__FUN_004b2580.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b40__FUN_004b2b40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
2433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b42e0__FUN_004b42e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b52a0__FUN_004b52a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: unidentified logic]
2435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9c80__FUN_004b9c80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba7a0__FUN_004ba7a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
2437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb150__FUN_004bb150.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: memory allocation]
2438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc2f0__FUN_004bc2f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be180__FUN_004be180.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2300__FUN_004c2300.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: unidentified logic]
2441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fa0__FUN_004c2fa0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6760__FUN_004c6760.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8560__FUN_004c8560.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c91d0__FUN_004c91d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca430__FUN_004ca430.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
2446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cefe0__FUN_004cefe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
2447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4790__FUN_004d4790.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5c70__FUN_004d5c70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 40 | prior triage: unidentified logic]
2449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7e00__FUN_004d7e00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9030__FUN_004d9030.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: unidentified logic]
2451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbc90__FUN_004dbc90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
2452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcc90__FUN_004dcc90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: unidentified logic]
2453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd550__FUN_004dd550.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified logic]
2454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0d70__FUN_004e0d70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ec020__FUN_004ec020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6af0__FUN_004f6af0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c70__FUN_004f8c70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9b30__FUN_004f9b30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc9a0__FUN_004fc9a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005001f0__FUN_005001f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502bf4__FUN_00502bf4.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504640__FUN_00504640.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: memory allocation]
2463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae22__FUN_0050ae22.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b446__FUN_0050b446.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c15e__FUN_0050c15e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
2466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d4d9__FUN_0050d4d9.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e04f__FUN_0050e04f.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f86a__FUN_0050f86a.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
2469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051184f__FUN_0051184f.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005125c9__FUN_005125c9.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: unidentified logic]
2471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515303__FUN_00515303.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
2472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516531__FUN_00516531.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517e43__FUN_00517e43.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ad93__FUN_0051ad93.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
2475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052156f__FUN_0052156f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: unidentified logic]
2476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00527f21__FUN_00527f21.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: unidentified logic]
2477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052df70__FUN_0052df70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
2478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00534ee0__FUN_00534ee0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: unidentified logic]
2479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536fd0__FUN_00536fd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b130__FUN_0053b130.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c200__FUN_0053c200.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ced0__FUN_0053ced0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: unidentified logic]
2483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053fed0__FUN_0053fed0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
2484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005423c0__FUN_005423c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543920__FUN_00543920.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547040__FUN_00547040.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005478b0__FUN_005478b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: unidentified logic]
2488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005492b0__FUN_005492b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b530__FUN_0054b530.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
2490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eb40__FUN_0054eb40.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: unidentified logic]
2491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550870__FUN_00550870.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: Init struct to 0, set param_1[1]=1.0f (0x3f800000)]
2492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005573a0__FUN_005573a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: Complex struct initializer — calls 3 init functions, sets default values]
2493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c9a0__FUN_0055c9a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter: uint at +0x13a8 masked w/ 0xf1000]
2494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564480__FUN_00564480.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter: (int)*(short*)(param_1 + 6)]
2495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005676c0__FUN_005676c0.c
   [category: Math | target: docs/20-math-utilities.md | lines: 18 | prior triage: Float-to-int conversion with remainder calc]
2496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a000__FUN_0057a000.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: callback registration: FUN_00587b3e(&LAB_0057a010)]
2497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ae40__FUN_0057ae40.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Single delegation call (with arg)]
2498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585400__FUN_00585400.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: Vtable dispatch with FUN_00586d00() check, two branches]
2499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587260__FUN_00587260.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 47 | prior triage: Decompression decode — read encoded bytes into ushort buffer]
2500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005883e5__FUN_005883e5.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: Float rounding check — compares ROUND result against original]
2501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a947____nh_malloc.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: MSVC __nh_malloc allocation with retry]
2502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e0b4__FUN_0058e0b4.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: Initializer: sets struct+0x50 to DAT_005e7810, struct+0x14 to 1]
2503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059532b__FUN_0059532b.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 45 | prior triage: Big-integer bit shift right — 3-word rotate with carry]
2504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598731__FUN_00598731.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: Constructor: sets vtable PTR_LAB_005b9ba4, calls FUN_00598aea]
2505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599904__FUN_00599904.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with fixed args (0,1)]
2506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059baa3__FUN_0059baa3.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: Exception/destructor stub — sets type_info vtable, free/destroy pattern]
2507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c86a__Unwind_0059c86a.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581750]
2508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf70__Unwind_0059cf70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler: calls FUN_0058a5f7]
2509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d7ea__FUN_0059d7ea.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: thunk to FUN_00443c07]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_M.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
