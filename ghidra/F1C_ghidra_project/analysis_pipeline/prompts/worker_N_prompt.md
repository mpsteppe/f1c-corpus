# WORKER N — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker N of 20, items 2510–2702.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_N.md

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

2510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050df95__thunk_FUN_0050df88.c
   [category: Thunk | target: docs/20-math-utilities.md | lines: 16 | prior triage: thunk via indirect jump (DAT_005d7878)]
2511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551390__FUN_00551390.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 43 | prior triage: Per-entity data block copy from parameter table]
2512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552ff0__FUN_00552ff0.c
   [category: Data/ParamSet | target: docs/20-math-utilities.md | lines: 29 | prior triage: Switch-based parameter field set with flags]
2513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554c30__FUN_00554c30.c
   [category: Game/State | target: docs/01-engine-architecture.md | lines: 36 | prior triage: State flag iteration across entries]
2514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005570c0__FUN_005570c0.c
   [category: Data/NestedTraversal | target: docs/20-math-utilities.md | lines: 22 | prior triage: Nested linked list traversal]
2515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559a40__FUN_00559a40.c
   [category: Mem/BufferInit | target: docs/01-engine-architecture.md | lines: 24 | prior triage: Large buffer zero-init (0x60 dwords)]
2516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d2e0__FUN_0055d2e0.c
   [category: Data/Flag | target: docs/20-math-utilities.md | lines: 12 | prior triage: Clear byte flag, return 0]
2517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560eb0__FUN_00560eb0.c
   [category: Data/List | target: docs/20-math-utilities.md | lines: 35 | prior triage: Append node to doubly-linked list tail]
2518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562c90__FUN_00562c90.c
   [category: Render | target: docs/19-renderer.md | lines: 32 | prior triage: Device initialization with state setup]
2519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564650__FUN_00564650.c
   [category: Threading/Sleep | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Sleep wrapper]
2520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565ef0__FUN_00565ef0.c
   [category: String | target: docs/01-engine-architecture.md | lines: 38 | prior triage: Reverse path search for backslash separator]
2521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567a00__FUN_00567a00.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 24 | prior triage: Struct zero-init (9 words + loop)]
2522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569860__FUN_00569860.c
   [category: Physics | target: docs/18-physics-dynamics.md | lines: 34 | prior triage: 3D position delta→body-frame vector transform]
2523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a0c0__FUN_0057a0c0.c
   [category: Memory/Cmp | target: docs/01-engine-architecture.md | lines: 22 | prior triage: 16-byte memory comparison for equality]
2524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a850__FUN_0057a850.c
   [category: Engine/VTableCheck | target: docs/01-engine-architecture.md | lines: 15 | prior triage: VTable bool check (inverted)]
2525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b550__FUN_0057b550.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 36 | prior triage: Ring buffer push with wrap check]
2526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e760__FUN_0057e760.c
   [category: Sync/Mutex | target: docs/01-engine-architecture.md | lines: 39 | prior triage: Mutex-protected linked list flush/destroy]
2527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583050__FUN_00583050.c
   [category: Memory/Cleanup | target: docs/01-engine-architecture.md | lines: 37 | prior triage: Destroy linked list with SEH, call destructors]
2528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585030__FUN_00585030.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Allocation wrapper]
2529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586170__FUN_00586170.c
   [category: Sync/Handle | target: docs/01-engine-architecture.md | lines: 33 | prior triage: Handle close & linked list cleanup]
2530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f10__FUN_00586f10.c
   [category: Dispatch | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
2531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587620__FUN_00587620.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Buffer write with params]
2532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058801d__FUN_0058801d.c
   [category: IO/StreamRead | target: docs/08-file-formats.md | lines: 20 | prior triage: String/stream read with mask check]
2533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589fcc__FUN_00589fcc.c
   [category: I/O/Stream | target: docs/20-math-utilities.md | lines: 25 | prior triage: Stream getc with underflow handler]
2534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a935___malloc.c
   [category: Library | target: docs/20-math-utilities.md | lines: 19 | prior triage: _malloc — wrapper for __nh_malloc]
2535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c1b1__FUN_0058c1b1.c
   [category: I/O/Stream | target: docs/20-math-utilities.md | lines: 16 | prior triage: Stream buffer lock via critical section]
2536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dfea__FUN_0058dfea.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 31 | prior triage: Critical section lazy init + enter]
2537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591ca1__FUN_00591ca1.c
   [category: Data/Lookup | target: docs/20-math-utilities.md | lines: 23 | prior triage: ID-to-value table lookup in constant table]
2538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00594b76__FUN_00594b76.c
   [category: Mem/HeapCheck | target: docs/01-engine-architecture.md | lines: 30 | prior triage: Memory region validation & heap lookup]
2539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059750a__FUN_0059750a.c
   [category: Algo/LinearSearch | target: docs/20-math-utilities.md | lines: 28 | prior triage: Array-of-struct linear search by ID]
2540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598b5d__FUN_00598b5d.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 27 | prior triage: Object constructor with SEH + vtable init]
2541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005993eb__FUN_005993eb.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 21 | prior triage: Object init with vtable + flag set]
2542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998cf__FUN_005998cf.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Cleanup wrapper]
2543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a428__FUN_0059a428.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Double indirect counter update]
2544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ac3f__FUN_0059ac3f.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Vtable pointer setter]
2545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bcd2__FUN_0059bcd2.c
   [category: I/O/Stream | target: docs/20-math-utilities.md | lines: 16 | prior triage: Stream read wrapper with lock/unlock]
2546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c504__Unwind_0059c504.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
2547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c634__Unwind_0059c634.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
2548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c790__Unwind_0059c790.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
2549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8d8__Unwind_0059c8d8.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
2550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cae0__Unwind_0059cae0.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ccc0__Unwind_0059ccc0.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ce9a__Unwind_0059ce9a.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
2553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cff6__Unwind_0059cff6.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
2554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d15b__Unwind_0059d15b.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
2555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d338__Unwind_0059d338.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind release locale refcount]
2556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d544__Unwind_0059d544.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
2557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004010b0__FUN_004010b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 35 | prior triage: short computation]
2558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d20__FUN_00404d20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004058d0__FUN_004058d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406ba0__FUN_00406ba0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 70 | prior triage: memory allocation]
2561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408220__FUN_00408220.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ac00__FUN_0040ac00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
2563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c8d0__FUN_0040c8d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 24 | prior triage: short computation]
2564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dd30__FUN_0040dd30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: short computation]
2565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040eec0__FUN_0040eec0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 35 | prior triage: short computation]
2566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b80__FUN_00410b80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 26 | prior triage: short computation]
2567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414210__FUN_00414210.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 65 | prior triage: memory allocation]
2568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004186a0__FUN_004186a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 30 | prior triage: short computation]
2569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ed20__FUN_0041ed20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
2570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004214a0__FUN_004214a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 59 | prior triage: short computation]
2571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421af0__FUN_00421af0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429fd0__FUN_00429fd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 83 | prior triage: Windows API call]
2573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456060__FUN_00456060.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582c0__FUN_004582c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb00__FUN_0045bb00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: float computation]
2576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c3d0__FUN_0045c3d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5b0__FUN_0045e5b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004618d0__FUN_004618d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 31 | prior triage: unidentified]
2579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462460__FUN_00462460.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: unidentified]
2580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463e00__FUN_00463e00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464c10__FUN_00464c10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 62 | prior triage: unidentified]
2582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466250__FUN_00466250.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00468610__FUN_00468610.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c030__FUN_0046c030.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e6f0__FUN_0046e6f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
2586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004702a0__FUN_004702a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472040__FUN_00472040.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473e50__FUN_00473e50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475570__FUN_00475570.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477ee0__FUN_00477ee0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
2591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478e80__FUN_00478e80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004799e0__FUN_004799e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a260__FUN_0047a260.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be70__FUN_0047be70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f1f0__FUN_0047f1f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485870__FUN_00485870.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified]
2597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486480__FUN_00486480.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487250__FUN_00487250.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487ed0__FUN_00487ed0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489480__FUN_00489480.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: unidentified]
2601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b8f0__FUN_0048b8f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d2b0__FUN_0048d2b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 46 | prior triage: unidentified]
2603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e650__FUN_0048e650.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fc80__FUN_0048fc80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490660__FUN_00490660.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 36 | prior triage: unidentified]
2606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491760__FUN_00491760.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491f60__FUN_00491f60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495120__FUN_00495120.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004963c0__FUN_004963c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979b0__thunk_FUN_00495b30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: trampoline/thunk]
2611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d20__FUN_00498d20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499280__FUN_00499280.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
2613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a30__FUN_00499a30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e50__FUN_00499e50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a330__FUN_0049a330.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049aec0__FUN_0049aec0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified]
2617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e170__FUN_0049e170.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 36 | prior triage: unidentified]
2618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f710__FUN_0049f710.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0fb0__FUN_004a0fb0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
2620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a21d0__FUN_004a21d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
2621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4050__FUN_004a4050.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
2622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8b10__FUN_004a8b10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a50__FUN_004b1a50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b25d0__FUN_004b25d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: unidentified logic]
2625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b60__FUN_004b2b60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4360__FUN_004b4360.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5380__FUN_004b5380.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: unidentified logic]
2628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9cd0__FUN_004b9cd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba820__FUN_004ba820.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb200__FUN_004bb200.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: memory allocation]
2631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc320__FUN_004bc320.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be1d0__FUN_004be1d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2760__FUN_004c2760.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fb0__FUN_004c2fb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7774__FUN_004c7774.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: arithmetic/comparison]
2636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8580__FUN_004c8580.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9260__FUN_004c9260.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cad30__FUN_004cad30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
2639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cf010__FUN_004cf010.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
2640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47a0__FUN_004d47a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5ea0__FUN_004d5ea0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
2642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7e30__FUN_004d7e30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
2643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d90d0__FUN_004d90d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbde0__FUN_004dbde0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
2645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd10__FUN_004dcd10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: utility function]
2646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd6a0__FUN_004dd6a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: unidentified logic]
2647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e16c0__FUN_004e16c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ec050__FUN_004ec050.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6b80__FUN_004f6b80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8c90__FUN_004f8c90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9b70__FUN_004f9b70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
2652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc9c0__FUN_004fc9c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: unidentified logic]
2653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500680__FUN_00500680.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502c28__FUN_00502c28.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: unidentified logic]
2655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00504f5a__FUN_00504f5a.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 34 | prior triage: unidentified logic]
2656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae3e__FUN_0050ae3e.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b462__FUN_0050b462.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c20d__FUN_0050c20d.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d563__FUN_0050d563.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e0d3__FUN_0050e0d3.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f904__FUN_0050f904.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
2662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511869__FUN_00511869.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00512850__FUN_00512850.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
2664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005158af__FUN_005158af.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051664f__FUN_0051664f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517e85__FUN_00517e85.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051aefc__FUN_0051aefc.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
2668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005215db__FUN_005215db.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: unidentified logic]
2669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052803a__FUN_0052803a.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052df90__FUN_0052df90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
2671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005351d0__FUN_005351d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537000__FUN_00537000.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: unidentified logic]
2673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b160__FUN_0053b160.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
2674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c210__FUN_0053c210.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d130__FUN_0053d130.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540050__FUN_00540050.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
2677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005423e0__FUN_005423e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543a60__FUN_00543a60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005470a0__FUN_005470a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547920__FUN_00547920.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: unidentified logic]
2681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005492f0__FUN_005492f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: memory allocation]
2682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bc60__FUN_0054bc60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
2683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054ee90__FUN_0054ee90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550ac0__FUN_00550ac0.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Call wrapper returning 0]
2685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005573f0__FUN_005573f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: calls FUN_0053b160() and FUN_004b0170()]
2686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c9b0__FUN_0055c9b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter at +0x1550]
2687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005644a0__FUN_005644a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter: short at +0x4]
2688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567740__FUN_00567740.c
   [category: Math | target: docs/20-math-utilities.md | lines: 13 | prior triage: FPU control word mask extract]
2689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a160__FUN_0057a160.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: Constructor: sets vtable PTR_LAB_005b8a00, calls FUN_0057a1e0]
2690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b2e0__FUN_0057b2e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter at +0x24]
2691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585440__FUN_00585440.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: Clamp/min — stores min(FUN_00587890(), param_2) to param_1+0x80]
2692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005873f0__FUN_005873f0.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Call wrapper]
2693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588570__FUN_00588570.c
   [category: Math | target: docs/20-math-utilities.md | lines: 15 | prior triage: Float-convert wrapper + sub-call]
2694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a9da__FUN_0058a9da.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: thunk to FUN_0058e04b(9)]
2695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e4a8__FUN_0058e4a8.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: Clear struct fields if param_2 byte flag (0x10) set]
2696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059553a__FUN_0059553a.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with static data arg]
2697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598750__FUN_00598750.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with fixed args (0,1)]
2698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599942__FUN_00599942.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: callback registration: FUN_00587b3e(&LAB_0059994e)]
2699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bf19__FUN_0059bf19.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: String copy constructor: malloc+strlen+strcpy, set refcount=1]
2700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8a4__Unwind_0059c8a4.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581ee0]
2701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cf94__Unwind_0059cf94.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581750]
2702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d806__FUN_0059d806.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Call wrapper]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_N.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
