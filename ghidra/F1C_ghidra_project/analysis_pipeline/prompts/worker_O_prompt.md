# WORKER O — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker O of 20, items 2703–2895.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_O.md

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

2703. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e198__thunk_FUN_0050e174.c
   [category: thunk | target: docs/20-math-utilities.md | lines: 14 | prior triage: trampoline to thunk_FUN_0050e174]
2704. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551440__FUN_00551440.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Flag set + sub-init chain call]
2705. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553050__FUN_00553050.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Two-field setter]
2706. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554d70__FUN_00554d70.c
   [category: UI/Cleanup | target: docs/01-engine-architecture.md | lines: 37 | prior triage: Iterate UI items, call dispose vtable, clear flags]
2707. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557410__FUN_00557410.c
   [category: Data/Struct | target: docs/20-math-utilities.md | lines: 32 | prior triage: Struct field zero-init with defaults]
2708. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559a70__FUN_00559a70.c
   [category: IO | target: docs/08-file-formats.md | lines: 35 | prior triage: Line reader from buffer with newline terminator]
2709. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d3f0__FUN_0055d3f0.c
   [category: Data/BitExtract | target: docs/20-math-utilities.md | lines: 12 | prior triage: Byte extraction from uint]
2710. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560f40__FUN_00560f40.c
   [category: Data/List | target: docs/20-math-utilities.md | lines: 44 | prior triage: Doubly-linked node removal & global re-insert]
2711. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562fe0__FUN_00562fe0.c
   [category: Audio/Call | target: docs/21-audio-network-internals.md | lines: 13 | prior triage: Set value and call audio function]
2712. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564690__FUN_00564690.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 36 | prior triage: String malloc+copy]
2713. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565f20__FUN_00565f20.c
   [category: Data/ListPeek | target: docs/20-math-utilities.md | lines: 24 | prior triage: Linked list node peek]
2714. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005684a0__FUN_005684a0.c
   [category: Game/ObjectLookup | target: docs/01-engine-architecture.md | lines: 45 | prior triage: Object ID lookup across 9 arrays]
2715. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005698e0__FUN_005698e0.c
   [category: Math/BufferEntry | target: docs/20-math-utilities.md | lines: 21 | prior triage: Buffer entry append with matrix init]
2716. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a0f0__FUN_0057a0f0.c
   [category: Mem/Copy | target: docs/01-engine-architecture.md | lines: 26 | prior triage: Byte-aligned memory copy with offset]
2717. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a880__FUN_0057a880.c
   [category: UI | target: docs/01-engine-architecture.md | lines: 21 | prior triage: Vtable query with stack buffer result]
2718. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b5c0__FUN_0057b5c0.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 32 | prior triage: Ring buffer pop with wrap check]
2719. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057e7e0__FUN_0057e7e0.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 38 | prior triage: Mutex-protected linked list destruction]
2720. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005830c0__FUN_005830c0.c
   [category: Data/SafeAlloc | target: docs/20-math-utilities.md | lines: 31 | prior triage: Object allocation with SEH (exception)]
2721. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585220__FUN_00585220.c
   [category: Engine/StatusCheck | target: docs/01-engine-architecture.md | lines: 25 | prior triage: Status check via VTable dispatch]
2722. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005861e0__FUN_005861e0.c
   [category: System | target: docs/01-engine-architecture.md | lines: 19 | prior triage: CloseHandle wrapper (dup, offset 0x54)]
2723. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f20__FUN_00586f20.c
   [category: Engine/Call | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
2724. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587690__FUN_00587690.c
   [category: Memory/Free | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Free callback registered cleanup]
2725. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058815f__FUN_0058815f.c
   [category: IO/Format | target: docs/08-file-formats.md | lines: 29 | prior triage: String format with buffer overflow check]
2726. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a02c__FUN_0058a02c.c
   [category: Memory/Check | target: docs/01-engine-architecture.md | lines: 21 | prior triage: Memory block validation check]
2727. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058aa39__FUN_0058aa39.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Mutex unlock wrapper]
2728. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c1e0__FUN_0058c1e0.c
   [category: Sync/CriticalSection | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Critical section enter]
2729. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e04b__FUN_0058e04b.c
   [category: Sync/CriticalSection | target: docs/01-engine-architecture.md | lines: 12 | prior triage: CritSect leave (generic)]
2730. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591cc6__FUN_00591cc6.c
   [category: Decode/BitFlags | target: docs/20-math-utilities.md | lines: 32 | prior triage: Bit flag decoder via bit tests]
2731. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005951be__FUN_005951be.c
   [category: Utility/Bitfield | target: docs/20-math-utilities.md | lines: 29 | prior triage: Check if bit range is clear across dwords]
2732. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597568_____add_12.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 31 | prior triage: --]
2733. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598bbc__FUN_00598bbc.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 28 | prior triage: Object constructor with SEH + vtable init chain]
2734. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599465__FUN_00599465.c
   [category: Data/RefCount | target: docs/20-math-utilities.md | lines: 13 | prior triage: Ref count inc/dec]
2735. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998e5__FUN_005998e5.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Vtable set + sub-call]
2736. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a43c__FUN_0059a43c.c
   [category: I/O/CRT | target: docs/20-math-utilities.md | lines: 13 | prior triage: Stream buffer pointer increment/decrement]
2737. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ac63__FUN_0059ac63.c
   [category: Exception/Dtor | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Exception destructor with conditional free]
2738. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bde9__FUN_0059bde9.c
   [category: IO/Format | target: docs/08-file-formats.md | lines: 16 | prior triage: I/O format wrapper]
2739. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c50e__Unwind_0059c50e.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
2740. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c63e__Unwind_0059c63e.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at +8]
2741. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7b0__Unwind_0059c7b0.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at -0x10]
2742. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8e6__Unwind_0059c8e6.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2743. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb20__Unwind_0059cb20.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2744. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ccc8__Unwind_0059ccc8.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
2745. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cea2__Unwind_0059cea2.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
2746. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d004__Unwind_0059d004.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
2747. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d170__Unwind_0059d170.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2748. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d348__Unwind_0059d348.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
2749. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d558__Unwind_0059d558.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with ~exception destructor]
2750. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401130__FUN_00401130.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
2751. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d30__FUN_00404d30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2752. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004059f0__FUN_004059f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: short computation]
2753. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406cc0__FUN_00406cc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 47 | prior triage: short computation]
2754. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408250__FUN_00408250.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2755. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ac40__FUN_0040ac40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2756. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c910__FUN_0040c910.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2757. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040dd80__FUN_0040dd80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 34 | prior triage: short computation]
2758. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f0d0__FUN_0040f0d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2759. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411330__FUN_00411330.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 49 | prior triage: short computation]
2760. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414370__FUN_00414370.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2761. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418900__FUN_00418900.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2762. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ed30__FUN_0041ed30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 36 | prior triage: short computation]
2763. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421570__FUN_00421570.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 77 | prior triage: memory allocation]
2764. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423060__FUN_00423060.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2765. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e1f0__FUN_0042e1f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 47 | prior triage: CRT math helper]
2766. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456080__FUN_00456080.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2767. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004582e0__FUN_004582e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 47 | prior triage: unidentified]
2768. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb40__FUN_0045bb40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2769. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c400__FUN_0045c400.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 80 | prior triage: unidentified]
2770. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5d0__FUN_0045e5d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2771. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461c70__FUN_00461c70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2772. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462530__FUN_00462530.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2773. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464600__FUN_00464600.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: unidentified]
2774. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464d30__FUN_00464d30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 74 | prior triage: unidentified]
2775. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466270__FUN_00466270.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2776. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004692a0__FUN_004692a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2777. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c6f0__FUN_0046c6f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2778. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e7d0__FUN_0046e7d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2779. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004702f0__FUN_004702f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2780. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472340__FUN_00472340.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2781. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473ed0__FUN_00473ed0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2782. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475c80__FUN_00475c80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2783. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477fa0__FUN_00477fa0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
2784. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479320__FUN_00479320.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 45 | prior triage: unidentified]
2785. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479a10__FUN_00479a10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2786. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a3a0__FUN_0047a3a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2787. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047be90__FUN_0047be90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2788. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f210__FUN_0047f210.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2789. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004858e0__FUN_004858e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2790. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004864c0__FUN_004864c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2791. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487260__FUN_00487260.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 64 | prior triage: unidentified]
2792. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487f10__FUN_00487f10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2793. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004894d0__FUN_004894d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: unidentified]
2794. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b910__FUN_0048b910.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2795. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d360__FUN_0048d360.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2796. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e670__FUN_0048e670.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2797. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fd60__FUN_0048fd60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2798. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490920__FUN_00490920.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2799. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491770__FUN_00491770.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: unidentified]
2800. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491fb0__FUN_00491fb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
2801. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495140__FUN_00495140.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
2802. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004966e0__FUN_004966e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: unidentified]
2803. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979c0__FUN_004979c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2804. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d70__FUN_00498d70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2805. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004992e0__FUN_004992e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: unidentified]
2806. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499a50__FUN_00499a50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2807. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e60__FUN_00499e60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2808. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a360__FUN_0049a360.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified]
2809. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049af30__FUN_0049af30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
2810. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e3e0__FUN_0049e3e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2811. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f750__FUN_0049f750.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2812. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a11b0__FUN_004a11b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2813. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2220__FUN_004a2220.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
2814. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40b0__FUN_004a40b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
2815. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a8b30__FUN_004a8b30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2816. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a70__FUN_004b1a70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2817. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b26d0__FUN_004b26d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
2818. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b80__FUN_004b2b80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
2819. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b43e0__FUN_004b43e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: unidentified logic]
2820. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5460__FUN_004b5460.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: arithmetic/comparison]
2821. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9ce0__FUN_004b9ce0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2822. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba830__FUN_004ba830.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
2823. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb2e0__FUN_004bb2e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: unidentified logic]
2824. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc330__FUN_004bc330.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2825. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be6f0__FUN_004be6f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2826. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2780__FUN_004c2780.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
2827. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fe0__FUN_004c2fe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2828. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7b20__FUN_004c7b20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
2829. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c85a0__FUN_004c85a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2830. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9280__FUN_004c9280.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
2831. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004caed0__FUN_004caed0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 119 | prior triage: unidentified logic]
2832. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cf040__FUN_004cf040.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2833. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47c0__FUN_004d47c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2834. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d6830__FUN_004d6830.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: unidentified logic]
2835. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7e40__FUN_004d7e40.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
2836. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d91e0__FUN_004d91e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 34 | prior triage: unidentified logic]
2837. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbe60__FUN_004dbe60.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
2838. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd60__FUN_004dcd60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2839. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd7c0__FUN_004dd7c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: unidentified logic]
2840. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e21d0__FUN_004e21d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2841. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed710__FUN_004ed710.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
2842. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6bc0__FUN_004f6bc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: arithmetic/comparison]
2843. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8cd0__FUN_004f8cd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2844. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f00__FUN_004f9f00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
2845. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd6d0__FUN_004fd6d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2846. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005006a4__FUN_005006a4.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 2 | prior triage: utility function]
2847. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502ee5__FUN_00502ee5.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
2848. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005053ec__FUN_005053ec.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: memory allocation]
2849. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae5a__FUN_0050ae5a.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2850. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b727__FUN_0050b727.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2851. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c23c__FUN_0050c23c.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
2852. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d57f__FUN_0050d57f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: unidentified logic]
2853. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e174__FUN_0050e174.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2854. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f9ab__FUN_0050f9ab.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2855. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511887__FUN_00511887.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2856. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513374__FUN_00513374.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
2857. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005158e3__FUN_005158e3.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
2858. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516772__FUN_00516772.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
2859. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ec8__FUN_00517ec8.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2860. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c3e2__FUN_0051c3e2.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: unidentified logic]
2861. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00521712__FUN_00521712.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: unidentified logic]
2862. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528bd0__FUN_00528bd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 1 | prior triage: unidentified logic]
2863. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e060__FUN_0052e060.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
2864. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535220__FUN_00535220.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
2865. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537070__FUN_00537070.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
2866. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b170__FUN_0053b170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
2867. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c2a0__FUN_0053c2a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
2868. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d1d0__FUN_0053d1d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
2869. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005400c0__FUN_005400c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
2870. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542420__FUN_00542420.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 3 | prior triage: utility function]
2871. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543a80__FUN_00543a80.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: memory allocation]
2872. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547100__FUN_00547100.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
2873. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547af0__FUN_00547af0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: arithmetic/comparison]
2874. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549380__FUN_00549380.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
2875. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bcd0__FUN_0054bcd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
2876. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fb90__FUN_0054fb90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: unidentified logic]
2877. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005528b0__FUN_005528b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 19 | prior triage: Check flag at +0x24 (0x20000), free resource at +0xc]
2878. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557470__FUN_00557470.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 11 | prior triage: Empty function (no-op)]
2879. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c9c0__FUN_0055c9c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: Float array value setter with stride 0x44]
2880. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005645b0__FUN_005645b0.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 23 | prior triage: String hash with weighted accumulation]
2881. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005678f0__FUN_005678f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: checks if byte < 0x21 (33)]
2882. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a180__FUN_0057a180.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: Dword-aligned memory copy]
2883. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b680__FUN_0057b680.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: 16-byte struct copy (4 dwords)]
2884. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005857c0__FUN_005857c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: Mutex-protected field write with WaitForSingleObject]
2885. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587400__FUN_00587400.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Delegation with static arg]
2886. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005887ed__FUN_005887ed.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 21 | prior triage: strlen + format call wrapper]
2887. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ac7a__FUN_0058ac7a.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: thunk to FUN_0058e04b(9)]
2888. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fb7e__FUN_0058fb7e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: stub returning 0]
2889. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595550__FUN_00595550.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: Buffer format helper — calls FUN_00596245/FUN_00595524]
2890. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987a1__FUN_005987a1.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: callback registration: FUN_00587b3e(&LAB_005987ad)]
2891. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599b1c__FUN_00599b1c.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: C++ EH frame setup — vtable pointer assignment with ExceptionList]
2892. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bfa0___exception.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: MSVC ~exception destructor (CRT library)]
2893. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8f4__Unwind_0059c8f4.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581820]
2894. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfda__Unwind_0059cfda.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00586170]
2895. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d928__FUN_0059d928.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Single delegation call]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_O.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
