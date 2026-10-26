# WORKER T — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker T of 20, items 3668–3860.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_T.md

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

3668. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8c0__thunk_FUN_0052d990.c
   [category: Sys/Thunk | target: docs/20-math-utilities.md | lines: 16 | prior triage: Thunk: VTable call with null check]
3669. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551790__FUN_00551790.c
   [category: Data/Search | target: docs/20-math-utilities.md | lines: 47 | prior triage: String comparison during linked list traversal]
3670. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005539f0__FUN_005539f0.c
   [category: Game/Resource | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Resource cleanup with cascade]
3671. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556440__FUN_00556440.c
   [category: Time | target: docs/01-engine-architecture.md | lines: 31 | prior triage: Timer reset via QueryPerformanceCounter]
3672. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00558c60__FUN_00558c60.c
   [category: Render | target: docs/19-renderer.md | lines: 20 | prior triage: Texture layer flag set]
3673. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bbf0__FUN_0055bbf0.c
   [category: Audio/Call | target: docs/21-audio-network-internals.md | lines: 12 | prior triage: Single function call wrapper]
3674. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d590__FUN_0055d590.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 21 | prior triage: Multi-field getter (3 values)]
3675. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005619f1__FUN_005619f1.c
   [category: Graphics/Fill | target: docs/19-renderer.md | lines: 18 | prior triage: 16-bit short array fill with value]
3676. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005633d0__FUN_005633d0.c
   [category: Render | target: docs/19-renderer.md | lines: 16 | prior triage: Display mode query wrapper]
3677. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564890__FUN_00564890.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Indirect call via function pointer]
3678. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566c00__FUN_00566c00.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 16 | prior triage: File write with backend dispatch]
3679. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568ba0__FUN_00568ba0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 28 | prior triage: Struct zero-init (17 fields)]
3680. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a240__FUN_0056a240.c
   [category: Physics | target: docs/18-physics-dynamics.md | lines: 46 | prior triage: 3D tensor-vector transform with inertia rotation]
3681. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a270__FUN_0057a270.c
   [category: Data/Serialization | target: docs/08-file-formats.md | lines: 23 | prior triage: Struct field serialization/deserialization]
3682. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a950__FUN_0057a950.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Cleanup wrapper with SEH]
3683. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b7f0__FUN_0057b7f0.c
   [category: Data/VTableInit | target: docs/20-math-utilities.md | lines: 13 | prior triage: VTable pointer init]
3684. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005818e0__FUN_005818e0.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 31 | prior triage: List destruction with handle close]
3685. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583570__FUN_00583570.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 34 | prior triage: Linked list destruction with COM release]
3686. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585680__FUN_00585680.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 52 | prior triage: Thread resume with mutex wait/lock]
3687. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586500__FUN_00586500.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 29 | prior triage: Mutex create/recreate]
3688. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587090__FUN_00587090.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 17 | prior triage: Object copy-construct from source]
3689. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005879f0__FUN_005879f0.c
   [category: Data/ConstSet | target: docs/20-math-utilities.md | lines: 15 | prior triage: Field constants initialization]
3690. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005887b1__FUN_005887b1.c
   [category: IO/FormatNested | target: docs/08-file-formats.md | lines: 19 | prior triage: String format with nested I/O calls]
3691. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2ef__FUN_0058a2ef.c
   [category: Sys/SEHUnwind | target: docs/20-math-utilities.md | lines: 15 | prior triage: SEH unwind with indirect jump]
3692. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058af5c__FUN_0058af5c.c
   [category: Error | target: docs/01-engine-architecture.md | lines: 40 | prior triage: Error ID lookup table with range checks]
3693. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c789__FUN_0058c789.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 37 | prior triage: File seek via SetFilePointer]
3694. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ef2e__FUN_0058ef2e.c
   [category: IO | target: docs/08-file-formats.md | lines: 23 | prior triage: Buffered byte reader with refill on underflow]
3695. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059247a__FUN_0059247a.c
   [category: Sync/CriticalSection | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Critical section guarded call]
3696. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059557d__FUN_0059557d.c
   [category: String | target: docs/01-engine-architecture.md | lines: 15 | prior triage: String parse with format validation]
3697. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598600__FUN_00598600.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 23 | prior triage: String alloc+copy (strlen+malloc)]
3698. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598cc1__FUN_00598cc1.c
   [category: Locale/Init | target: docs/20-math-utilities.md | lines: 13 | prior triage: Set locale vtable and call cleanup]
3699. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599615__FUN_00599615.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Buffer write with capacity check + null-term]
3700. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599be5__FUN_00599be5.c
   [category: Locale/Init | target: docs/20-math-utilities.md | lines: 13 | prior triage: Set locale vtable and call dtor]
3701. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a70b__FUN_0059a70b.c
   [category: Sys/Throw | target: docs/20-math-utilities.md | lines: 15 | prior triage: C++ throw with exception]
3702. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059aeda__FUN_0059aeda.c
   [category: Sys/ExceptionDtor | target: docs/20-math-utilities.md | lines: 22 | prior triage: Exception destructor]
3703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c400__Unwind_0059c400.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at -0x54]
3704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c56e__Unwind_0059c56e.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
3705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c67a__Unwind_0059c67a.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
3706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c804__Unwind_0059c804.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
3707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c948__Unwind_0059c948.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
3708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb80__Unwind_0059cb80.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
3709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd13__Unwind_0059cd13.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
3710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ceed__Unwind_0059ceed.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
3711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d050__Unwind_0059d050.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
3712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1d8__Unwind_0059d1d8.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
3713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d414__Unwind_0059d414.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
3714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d6a9__FUN_0059d6a9.c
   [category: Engine/NullCheckCall | target: docs/01-engine-architecture.md | lines: 17 | prior triage: Null-checked call wrapper]
3715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00403fc0__FUN_00403fc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 26 | prior triage: short computation]
3716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404f10__FUN_00404f10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406020__FUN_00406020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
3718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004078a0__FUN_004078a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 44 | prior triage: short computation]
3719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004083e0__FUN_004083e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
3720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b450__FUN_0040b450.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 30 | prior triage: short computation]
3721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d100__FUN_0040d100.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 36 | prior triage: short computation]
3722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e2b0__FUN_0040e2b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 78 | prior triage: memory allocation]
3723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f380__FUN_0040f380.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 58 | prior triage: short computation]
3724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004116c0__FUN_004116c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 32 | prior triage: short computation]
3725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004144d0__FUN_004144d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418a20__FUN_00418a20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f100__FUN_0041f100.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421930__FUN_00421930.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004234c0__FUN_004234c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452780__FUN_00452780.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456130__FUN_00456130.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459a40__FUN_00459a40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 42 | prior triage: float computation]
3733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bc00__FUN_0045bc00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c8b0__FUN_0045c8b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: unidentified]
3735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00460770__FUN_00460770.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
3736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461f70__FUN_00461f70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462ff0__FUN_00462ff0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 39 | prior triage: trig/math computation]
3738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464740__FUN_00464740.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 53 | prior triage: unidentified]
3739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464fd0__FUN_00464fd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004668e0__FUN_004668e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a270__FUN_0046a270.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046cb10__FUN_0046cb10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
3743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046f490__FUN_0046f490.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470d30__FUN_00470d30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472bc0__FUN_00472bc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474900__FUN_00474900.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004761a0__FUN_004761a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478140__FUN_00478140.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479730__FUN_00479730.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479c80__FUN_00479c80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a620__FUN_0047a620.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c6e0__FUN_0047c6e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047fba0__FUN_0047fba0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485ae0__FUN_00485ae0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486630__FUN_00486630.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487640__FUN_00487640.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004883a0__FUN_004883a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489940__FUN_00489940.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
3759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048c0d0__FUN_0048c0d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d4b0__FUN_0048d4b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 29 | prior triage: float computation]
3761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ea40__FUN_0048ea40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fe60__FUN_0048fe60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490b90__FUN_00490b90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 84 | prior triage: unidentified]
3764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491a40__FUN_00491a40.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 53 | prior triage: unidentified]
3765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494a30__FUN_00494a30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495790__FUN_00495790.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
3767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496e40__FUN_00496e40.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: unidentified]
3768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497ec0__FUN_00497ec0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 58 | prior triage: unidentified]
3769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498e50__FUN_00498e50.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: unidentified]
3770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499560__FUN_00499560.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499b50__FUN_00499b50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
3772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499eb0__FUN_00499eb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a580__FUN_0049a580.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b050__FUN_0049b050.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
3775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e930__FUN_0049e930.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified]
3776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ffd0__FUN_0049ffd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1a00__FUN_004a1a00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: unidentified logic]
3778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2980__FUN_004a2980.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a48c0__FUN_004a48c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0220__FUN_004b0220.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1d90__FUN_004b1d90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2930__FUN_004b2930.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2c80__FUN_004b2c80.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
3784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b45e0__FUN_004b45e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b72a0__FUN_004b72a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
3786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d90__FUN_004b9d90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba9f0__FUN_004ba9f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: arithmetic/comparison]
3788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb4f0__FUN_004bb4f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
3789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd7d0__FUN_004bd7d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bfd40__FUN_004bfd40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c29b0__FUN_004c29b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
3792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3130__FUN_004c3130.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c70__FUN_004c7c70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c88a0__FUN_004c88a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9600__FUN_004c9600.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cbdd0__FUN_004cbdd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: unidentified logic]
3797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0b00__FUN_004d0b00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4870__FUN_004d4870.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: arithmetic/comparison]
3799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7a50__FUN_004d7a50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7ff0__FUN_004d7ff0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: unidentified logic]
3801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004da9c0__FUN_004da9c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc290__FUN_004dc290.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcf20__FUN_004dcf20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004de5f0__FUN_004de5f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2ad0__FUN_004e2ad0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified logic]
3806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004effd0__FUN_004effd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: unidentified logic]
3807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8030__FUN_004f8030.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 66 | prior triage: unidentified logic]
3808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8ea0__FUN_004f8ea0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: unidentified logic]
3809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fad80__FUN_004fad80.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 50 | prior triage: unidentified logic]
3810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004feaa0__FUN_004feaa0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
3811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050099c__FUN_0050099c.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: unidentified logic]
3812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503888__FUN_00503888.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: utility function]
3813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050653e__FUN_0050653e.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b1d4__FUN_0050b1d4.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b7af__FUN_0050b7af.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c48c__FUN_0050c48c.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d728__FUN_0050d728.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e3cd__FUN_0050e3cd.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fd16__FUN_0050fd16.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511f70__FUN_00511f70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 11 | prior triage: unidentified logic]
3821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b8a__FUN_00513b8a.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005159a8__FUN_005159a8.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516974__FUN_00516974.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051923d__FUN_0051923d.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
3825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051cb6d__FUN_0051cb6d.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
3826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00522ce2__FUN_00522ce2.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 45 | prior triage: unidentified logic]
3827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00529af8__FUN_00529af8.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e520__FUN_0052e520.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535550__FUN_00535550.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005397a0__FUN_005397a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: unidentified logic]
3831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b350__FUN_0053b350.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: arithmetic/comparison]
3832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c5b0__FUN_0053c5b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d310__FUN_0053d310.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
3834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540d40__FUN_00540d40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542520__FUN_00542520.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005458d0__FUN_005458d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547280__FUN_00547280.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005489a0__FUN_005489a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a200__FUN_0054a200.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
3840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c190__FUN_0054c190.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc80__FUN_0054fc80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005545e0__FUN_005545e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: Setter with notification via DAT_008b89a0 — sets param_1[0xb] if changed]
3843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559fb0__FUN_00559fb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 48 | prior triage: PRNG — 4 uniform floats from seed via FUN_0058b077]
3844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560f10__FUN_00560f10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: Doubly-linked list node unlink]
3845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564a20__FUN_00564a20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 36 | prior triage: Buffer index computation with stride-based division]
3846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567d00__FUN_00567d00.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 39 | prior triage: String hash via weighted char sum modulo 9]
3847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a680__FUN_0057a680.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: COM vtable call via +0x60 (indirect jump)]
3848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ef20__FUN_0057ef20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: SEH-wrapped constructor calling operator_new]
3849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e60__FUN_00585e60.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with static arg]
3850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005876d0__FUN_005876d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: callback registration: FUN_00587b3e(&LAB_005876e0)]
3851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589278__FUN_00589278.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: Wrapper: calls FUN_0058928f(param_1,param_2,param_3,0)]
3852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058babb__FUN_0058babb.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: Write string to file via FUN_0058c1b1/FUN_0058e41b]
3853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059168f__FUN_0059168f.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 27 | prior triage: Math function with conditional branch on DAT_005e9ad0 flag]
3854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596bf3__FUN_00596bf3.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: Conversion helper — special-cases param_3==10 && param_1<0, calls FUN_00596c20]
3855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598e2e__FUN_00598e2e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: vtable/function-pointer setup: *param_1 = &PTR_FUN_005b9bcc]
3856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a3f3__FUN_0059a3f3.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: Pointer adjustment — subtracts from **(p+0x2c), adds 2× to **(p+0x1c)]
3857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4f0__Unwind_0059c4f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
3858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb00__Unwind_0059cb00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_005870d0]
3859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d130__Unwind_0059d130.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00585fb0]
3860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059db88__FUN_0059db88.c
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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_T.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
