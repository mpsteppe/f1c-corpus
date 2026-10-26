# WORKER S — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker S of 20, items 3475–3667.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_S.md

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

3475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8b0__DirectInput8Create.c
   [category: Library | target: docs/20-math-utilities.md | lines: 14 | prior triage: DirectInput8Create stub]
3476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551760__FUN_00551760.c
   [category: Data/ListTraverse | target: docs/20-math-utilities.md | lines: 18 | prior triage: Linked list traversal with conditional call]
3477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553980__FUN_00553980.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 33 | prior triage: Object constructor with heap alloc + sub-init calls]
3478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005563e0__FUN_005563e0.c
   [category: Timing | target: docs/01-engine-architecture.md | lines: 22 | prior triage: Timer start via QueryPerformanceCounter]
3479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558990__FUN_00558990.c
   [category: Memory/Cleanup | target: docs/01-engine-architecture.md | lines: 43 | prior triage: Free sub-resources, clear flags, reset state array]
3480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bba0__FUN_0055bba0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 25 | prior triage: Linked-list free with traversal + nulling]
3481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d560__FUN_0055d560.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 26 | prior triage: Field getter by index (1/2/3)]
3482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005619af__FUN_005619af.c
   [category: Render | target: docs/19-renderer.md | lines: 27 | prior triage: Pixel fill with stride/step calculation]
3483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563230__FUN_00563230.c
   [category: Algo/StrideSearch | target: docs/20-math-utilities.md | lines: 25 | prior triage: Array-of-struct stride search by ID]
3484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564860__FUN_00564860.c
   [category: Mem/BatchFree | target: docs/01-engine-architecture.md | lines: 22 | prior triage: Batch loop with memory cleanup]
3485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566b90__FUN_00566b90.c
   [category: IO | target: docs/08-file-formats.md | lines: 28 | prior triage: Conditional file handle close with flag-based dispatch]
3486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568750__FUN_00568750.c
   [category: Input | target: docs/01-engine-architecture.md | lines: 48 | prior triage: ASCII char code validation (printable vs special)]
3487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569b70__FUN_00569b70.c
   [category: Math/Vector | target: docs/20-math-utilities.md | lines: 35 | prior triage: 3D vector subtract with cross product]
3488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a230__FUN_0057a230.c
   [category: Mem/Copy | target: docs/01-engine-architecture.md | lines: 32 | prior triage: Byte-aligned memory copy from struct]
3489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a920__FUN_0057a920.c
   [category: Engine/Call | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
3490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b7d0__FUN_0057b7d0.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 14 | prior triage: Object copy-init with vtable]
3491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581880__FUN_00581880.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 27 | prior triage: Linked-list destruction with vtable release call]
3492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583530__FUN_00583530.c
   [category: Memory/Init | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Zero-fill memory region with step]
3493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005855e0__FUN_005855e0.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 45 | prior triage: Thread suspend with mutex wait/lock]
3494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005864e0__FUN_005864e0.c
   [category: Data/NodeCleanup | target: docs/20-math-utilities.md | lines: 17 | prior triage: Conditional list node cleanup]
3495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587070__FUN_00587070.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Sub-call + conditional free (dup)]
3496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587930__FUN_00587930.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 49 | prior triage: Buffer copy via virtual type dispatch]
3497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588678__FUN_00588678.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 16 | prior triage: File read wrapper with lock]
3498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2cb__FUN_0058a2cb.c
   [category: Error/Exit | target: docs/20-math-utilities.md | lines: 16 | prior triage: Error handler with optional cleanup then exit]
3499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ace6__FUN_0058ace6.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 16 | prior triage: File size query wrapper]
3500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c6f0____allmul.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: --]
3501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e1b0___strlen.c
   [category: Library | target: docs/20-math-utilities.md | lines: 45 | prior triage: strlen — aligned word-scan string length]
3502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005921c5__FUN_005921c5.c
   [category: System | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Lazy-init singleton with flag guard]
3503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595524__FUN_00595524.c
   [category: String | target: docs/01-engine-architecture.md | lines: 12 | prior triage: String parse via delegate]
3504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598502__FUN_00598502.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 43 | prior triage: Null-terminated int array copy with alloc]
3505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c88__FUN_00598c88.c
   [category: Locale/Refcount | target: docs/20-math-utilities.md | lines: 20 | prior triage: Decrement locale refcount, return if dead]
3506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005995e5__FUN_005995e5.c
   [category: String/Free | target: docs/20-math-utilities.md | lines: 20 | prior triage: Conditional string free with length check]
3507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599b86__FUN_00599b86.c
   [category: Data/ObjectCtor | target: docs/20-math-utilities.md | lines: 27 | prior triage: Object constructor with vtable setup]
3508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a541__FUN_0059a541.c
   [category: Memory/Free | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Free callback registered cleanup]
3509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ae24__FUN_0059ae24.c
   [category: Exception/Dtor | target: docs/01-engine-architecture.md | lines: 22 | prior triage: Exception destructor SEH wrapper]
3510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c156__FUN_0059c156.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 44 | prior triage: File seek with mode flag validation]
3511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c566__Unwind_0059c566.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c670__Unwind_0059c670.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at +8]
3513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7ee__Unwind_0059c7ee.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
3514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c92c__Unwind_0059c92c.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
3515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb60__Unwind_0059cb60.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
3516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd08__Unwind_0059cd08.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
3517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cedf__Unwind_0059cedf.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d03e__Unwind_0059d03e.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1b8__Unwind_0059d1b8.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
3520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3f0__Unwind_0059d3f0.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 17 | prior triage: SEH unwind handler conditional destroy]
3521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5bc__Unwind_0059d5bc.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
3522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403f70__FUN_00403f70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
3523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404f00__FUN_00404f00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405f80__FUN_00405f80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 32 | prior triage: short computation]
3525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407810__FUN_00407810.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 44 | prior triage: short computation]
3526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004082b0__FUN_004082b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 55 | prior triage: string/hash lookup]
3527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b360__FUN_0040b360.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: short computation]
3528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d0b0__FUN_0040d0b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 31 | prior triage: short computation]
3529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1f0__FUN_0040e1f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 42 | prior triage: short computation]
3530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f300__FUN_0040f300.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 29 | prior triage: short computation]
3531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004116b0__FUN_004116b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144a0__FUN_004144a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004189f0__FUN_004189f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 31 | prior triage: short computation]
3534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f070__FUN_0041f070.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 43 | prior triage: short computation]
3535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421910__FUN_00421910.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004234a0__FUN_004234a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452740__FUN_00452740.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456110__FUN_00456110.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459990__FUN_00459990.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
3540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bbe0__FUN_0045bbe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c850__FUN_0045c850.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: short computation]
3542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460710__FUN_00460710.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
3543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461ed0__FUN_00461ed0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: references global state]
3544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462d30__FUN_00462d30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
3545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464720__FUN_00464720.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464f90__FUN_00464f90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
3547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466300__FUN_00466300.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
3548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a220__FUN_0046a220.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046cb00__FUN_0046cb00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
3550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046efe0__FUN_0046efe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470cc0__FUN_00470cc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472a80__FUN_00472a80.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: references global state]
3553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474440__FUN_00474440.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004760d0__FUN_004760d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
3555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478110__FUN_00478110.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479700__FUN_00479700.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479c30__FUN_00479c30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a5e0__FUN_0047a5e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c6c0__FUN_0047c6c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047fb10__FUN_0047fb10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified]
3561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485a90__FUN_00485a90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486600__FUN_00486600.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004875f0__FUN_004875f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004881f0__FUN_004881f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 65 | prior triage: unidentified]
3565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004895b0__FUN_004895b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c070__FUN_0048c070.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
3567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d3f0__FUN_0048d3f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ea20__FUN_0048ea20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fe30__FUN_0048fe30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490b00__FUN_00490b00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 45 | prior triage: unidentified]
3571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004919c0__FUN_004919c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 41 | prior triage: unidentified]
3572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494690__FUN_00494690.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 60 | prior triage: float computation]
3573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495300__FUN_00495300.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 68 | prior triage: unidentified]
3574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496e20__FUN_00496e20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497e80__FUN_00497e80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498e40__FUN_00498e40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
3577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499540__FUN_00499540.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499b10__FUN_00499b10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: unidentified]
3579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ea0__FUN_00499ea0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a520__FUN_0049a520.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: unidentified]
3581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b020__FUN_0049b020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e8f0__FUN_0049e8f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: unidentified]
3583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ffc0__FUN_0049ffc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1830__FUN_004a1830.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2840__FUN_004a2840.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
3586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a46f0__FUN_004a46f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b01b0__FUN_004b01b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1c20__FUN_004b1c20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b28f0__FUN_004b28f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2c50__FUN_004b2c50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: arithmetic/comparison]
3591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b44a0__FUN_004b44a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5e30__FUN_004b5e30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
3593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d80__FUN_004b9d80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba980__FUN_004ba980.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: memory allocation]
3595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb490__FUN_004bb490.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd7b0__FUN_004bd7b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf730__FUN_004bf730.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2990__FUN_004c2990.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
3599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3050__FUN_004c3050.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 48 | prior triage: unidentified logic]
3600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c40__FUN_004c7c40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8830__FUN_004c8830.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c94d0__FUN_004c94d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb5e0__FUN_004cb5e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: arithmetic/comparison]
3604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0080__FUN_004d0080.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
3605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4860__FUN_004d4860.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7930__FUN_004d7930.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7fe0__FUN_004d7fe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9f80__FUN_004d9f80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc220__FUN_004dc220.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcee0__FUN_004dcee0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: utility function]
3611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004de5d0__FUN_004de5d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2a60__FUN_004e2a60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 2 | prior triage: unidentified logic]
3613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efee0__FUN_004efee0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6f20__FUN_004f6f20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8d40__FUN_004f8d40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: arithmetic/comparison]
3616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9fc0__FUN_004f9fc0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: utility function]
3617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fde00__FUN_004fde00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
3618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005008e4__FUN_005008e4.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
3619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503772__FUN_00503772.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 100 | prior triage: unidentified logic]
3620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506538__FUN_00506538.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050afc6__FUN_0050afc6.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b797__FUN_0050b797.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c3bb__FUN_0050c3bb.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
3624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d6ac__FUN_0050d6ac.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: unidentified logic]
3625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e342__FUN_0050e342.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fc58__FUN_0050fc58.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511f23__FUN_00511f23.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: arithmetic/comparison]
3628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b51__FUN_00513b51.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
3629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515986__FUN_00515986.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516959__FUN_00516959.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f58__FUN_00517f58.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c813__FUN_0051c813.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 129 | prior triage: unidentified logic]
3633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522b22__FUN_00522b22.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
3634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529700__FUN_00529700.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
3635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e4e0__FUN_0052e4e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
3636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005354e0__FUN_005354e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: unidentified logic]
3637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539670__FUN_00539670.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
3638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b330__FUN_0053b330.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c590__FUN_0053c590.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d2e0__FUN_0053d2e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
3641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540760__FUN_00540760.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
3642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005424e0__FUN_005424e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005454a0__FUN_005454a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: utility function]
3644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547240__FUN_00547240.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548850__FUN_00548850.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a1c0__FUN_0054a1c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
3647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c0e0__FUN_0054c0e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc70__FUN_0054fc70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3649. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553d00__FUN_00553d00.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 20 | prior triage: 2D range swap + grid fill call]
3650. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559f00__FUN_00559f00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 49 | prior triage: PRNG — 4 uniform ints from seed via FUN_00589278, base 10]
3651. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055eeaf__FUN_0055eeaf.c
   [category: Math | target: docs/20-math-utilities.md | lines: 45 | prior triage: 4x3 matrix 3D vector transform]
3652. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564a00__FUN_00564a00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: Calls FUN_005890aa with struct fields (index 5,0,2)]
3653. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567cc0__FUN_00567cc0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: Recursive tree destructor — traverses children at +4/+8/+0xc, frees]
3654. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a590__FUN_0057a590.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Single delegation call]
3655. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b800__FUN_0057b800.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: Calls FUN_00587370, copies field+0x1c between structs]
3656. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e50__FUN_00585e50.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Call wrapper]
3657. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587680__FUN_00587680.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Single delegation call]
3658. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005891fe__FUN_005891fe.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 24 | prior triage: Range partitioning with callback comparator + action]
3659. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b9ff__FUN_0058b9ff.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: GetDriveTypeA check: return 0 for invalid/removable]
3660. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005912bc__FUN_005912bc.c
   [category: Math | target: docs/20-math-utilities.md | lines: 25 | prior triage: Float modulus with denormal/edge-case handling]
3661. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596888__FUN_00596888.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 40 | prior triage: Decompression push — buffer decrement-write with flag checks]
3662. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598e07__FUN_00598e07.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: Copy 6 dwords from FUN_0059942b(0xffffffff) source]
3663. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a0d5__FUN_0059a0d5.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: Buffer read through vtable with bounds check]
3664. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4aa__Unwind_0059c4aa.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
3665. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca30__Unwind_0059ca30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_0047aa60]
3666. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0e0__Unwind_0059d0e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_005870d0]
3667. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059db5b__FUN_0059db5b.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: thunk to FUN_004a13d9]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_S.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
