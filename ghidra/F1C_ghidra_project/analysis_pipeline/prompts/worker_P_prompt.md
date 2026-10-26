# WORKER P — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker P of 20, items 2896–3088.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_P.md

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

2896. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e3da__thunk_FUN_0050e3cd.c
   [category: thunk | target: docs/20-math-utilities.md | lines: 14 | prior triage: trampoline to thunk_FUN_0050e3cd]
2897. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551480__FUN_00551480.c
   [category: Audio/Flag | target: docs/21-audio-network-internals.md | lines: 13 | prior triage: Set audio flag bits, call update]
2898. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005532a0__FUN_005532a0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 40 | prior triage: Object allocation with zero-init]
2899. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005550a0__FUN_005550a0.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Single vtable getter call]
2900. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557480__FUN_00557480.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 25 | prior triage: Flag-conditional branch dispatch]
2901. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055baf0__FUN_0055baf0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 20 | prior triage: Small struct init (9 uint32 fields)]
2902. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d410__FUN_0055d410.c
   [category: UI/Property | target: docs/01-engine-architecture.md | lines: 29 | prior triage: Set UI property value with chained update]
2903. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560fd0__FUN_00560fd0.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 12 | prior triage: State flag bit clear]
2904. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563000__FUN_00563000.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Polling loop with process call until flag clears]
2905. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005646d0__FUN_005646d0.c
   [category: Memory/Alloc | target: docs/01-engine-architecture.md | lines: 32 | prior triage: Allocate int array, fill via factory function]
2906. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565f50__FUN_00565f50.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 20 | prior triage: Linked list pop front]
2907. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00568540__FUN_00568540.c
   [category: File/IO | target: docs/08-file-formats.md | lines: 15 | prior triage: Set file attributes + existence check]
2908. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569990__FUN_00569990.c
   [category: Math/Transform | target: docs/20-math-utilities.md | lines: 38 | prior triage: 3D vector transform into buffer with metadata]
2909. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a1b0__FUN_0057a1b0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 26 | prior triage: Memcpy with advance pointer]
2910. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a8b0__FUN_0057a8b0.c
   [category: Engine/VTable | target: docs/01-engine-architecture.md | lines: 14 | prior triage: VTable call via offset 0x7c]
2911. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b630__FUN_0057b630.c
   [category: Buffer/Circular | target: docs/20-math-utilities.md | lines: 33 | prior triage: Read bytes from circular buffer with wrap-around]
2912. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ee80__FUN_0057ee80.c
   [category: Sync/Mutex | target: docs/01-engine-architecture.md | lines: 43 | prior triage: Thread-safe mutex queue with timed wait]
2913. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583210__FUN_00583210.c
   [category: Data/List | target: docs/20-math-utilities.md | lines: 41 | prior triage: Linked list node alloc & prepend]
2914. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585320__FUN_00585320.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 34 | prior triage: Linked-list walk with input dispatch per node]
2915. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586210__FUN_00586210.c
   [category: System | target: docs/01-engine-architecture.md | lines: 20 | prior triage: CloseHandle + cleanup call]
2916. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586f40__FUN_00586f40.c
   [category: Graphics/Bitmap | target: docs/19-renderer.md | lines: 25 | prior triage: Compute bitmask from bitmap entry count]
2917. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005876c0__FUN_005876c0.c
   [category: Engine/Call | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
2918. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005881c0__FUN_005881c0.c
   [category: System | target: docs/01-engine-architecture.md | lines: 22 | prior triage: Stack probe/alloca for large stack frames]
2919. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a05a__FUN_0058a05a.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 33 | prior triage: Buffer flush/write with position tracking]
2920. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058aad9__FUN_0058aad9.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Semaphore release (slot 9)]
2921. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c232__FUN_0058c232.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 16 | prior triage: Critical section leave]
2922. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e060__FUN_0058e060.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 30 | prior triage: TLS allocation + thread ID init]
2923. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591d05__FUN_00591d05.c
   [category: Math/BitFloat | target: docs/20-math-utilities.md | lines: 14 | prior triage: Float bit manipulation]
2924. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595207__FUN_00595207.c
   [category: Algo/Bitset | target: docs/20-math-utilities.md | lines: 29 | prior triage: Bitset clear operation from bit position]
2925. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597cc0__FUN_00597cc0.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 49 | prior triage: Bit-packed data decode via lookup table (3-bit chunks)]
2926. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c1c__FUN_00598c1c.c
   [category: Locale/Refcount | target: docs/20-math-utilities.md | lines: 18 | prior triage: Locale refcount acquire under lock]
2927. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599495__FUN_00599495.c
   [category: FileSystem | target: docs/08-file-formats.md | lines: 20 | prior triage: File close wrapper with status]
2928. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599913__FUN_00599913.c
   [category: Memory/Free | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Free callback registered cleanup]
2929. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a44c__FUN_0059a44c.c
   [category: Engine/CallbackCheck | target: docs/01-engine-architecture.md | lines: 20 | prior triage: Conditional callback with null check]
2930. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ac7f__FUN_0059ac7f.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 39 | prior triage: Object teardown with iterator cleanup loop]
2931. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059befd__FUN_0059befd.c
   [category: Data/Dtor | target: docs/20-math-utilities.md | lines: 15 | prior triage: Exception destructor with flag]
2932. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c518__Unwind_0059c518.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at -0x40]
2933. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c648__Unwind_0059c648.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
2934. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7d0__Unwind_0059c7d0.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2935. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c902__Unwind_0059c902.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: --]
2936. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb28__Unwind_0059cb28.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind free object at +4]
2937. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cce0__Unwind_0059cce0.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
2938. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cead__Unwind_0059cead.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2939. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d012__Unwind_0059d012.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 12 | prior triage: Unwind handler (SEH)]
2940. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d17b__Unwind_0059d17b.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
2941. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d368__Unwind_0059d368.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: --]
2942. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d56c__Unwind_0059d56c.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind destroy exception object]
2943. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004034d0__FUN_004034d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 31 | prior triage: short computation]
2944. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404d40__FUN_00404d40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2945. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405b00__FUN_00405b00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 27 | prior triage: short computation]
2946. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406f90__FUN_00406f90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 45 | prior triage: short computation]
2947. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408260__FUN_00408260.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2948. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040acd0__FUN_0040acd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 38 | prior triage: short computation]
2949. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040cd60__FUN_0040cd60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 34 | prior triage: short computation]
2950. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e170__FUN_0040e170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 23 | prior triage: short computation]
2951. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f100__FUN_0040f100.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
2952. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411570__FUN_00411570.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 56 | prior triage: short computation]
2953. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414380__FUN_00414380.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 60 | prior triage: short computation]
2954. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418940__FUN_00418940.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2955. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ef00__FUN_0041ef00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 29 | prior triage: short computation]
2956. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421890__FUN_00421890.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 49 | prior triage: short computation]
2957. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423250__FUN_00423250.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 118 | prior triage: Windows API call]
2958. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004472b0__FUN_004472b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 196 | prior triage: CRT math helper]
2959. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004560a0__FUN_004560a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2960. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004584a0__FUN_004584a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2961. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb50__thunk_FUN_0045b400.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: trampoline/thunk]
2962. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c750__FUN_0045c750.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2963. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5f0__FUN_0045e5f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2964. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461cd0__FUN_00461cd0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
2965. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462760__FUN_00462760.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2966. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464670__FUN_00464670.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2967. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464e90__FUN_00464e90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2968. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466290__FUN_00466290.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2969. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00469857__FUN_00469857.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
2970. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c710__FUN_0046c710.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 33 | prior triage: unidentified]
2971. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046e7f0__FUN_0046e7f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: unidentified]
2972. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470670__FUN_00470670.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: references global state]
2973. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472400__FUN_00472400.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: references global state]
2974. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473f50__FUN_00473f50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
2975. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00475cc0__FUN_00475cc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2976. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478090__FUN_00478090.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
2977. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004795e0__FUN_004795e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2978. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479a40__FUN_00479a40.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2979. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a550__FUN_0047a550.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2980. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047beb0__FUN_0047beb0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 37 | prior triage: unidentified]
2981. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f370__FUN_0047f370.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: unidentified]
2982. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485900__FUN_00485900.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: unidentified]
2983. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486500__FUN_00486500.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
2984. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487330__FUN_00487330.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 64 | prior triage: unidentified]
2985. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487f30__FUN_00487f30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
2986. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489500__FUN_00489500.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
2987. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b950__FUN_0048b950.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 40 | prior triage: unidentified]
2988. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d380__FUN_0048d380.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2989. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e6a0__FUN_0048e6a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
2990. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fd80__FUN_0048fd80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
2991. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490930__FUN_00490930.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
2992. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004917c0__FUN_004917c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 79 | prior triage: unidentified]
2993. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00492030__FUN_00492030.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: unidentified]
2994. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495150__FUN_00495150.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
2995. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496750__FUN_00496750.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 36 | prior triage: unidentified]
2996. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004979d0__FUN_004979d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
2997. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498d90__FUN_00498d90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: unidentified]
2998. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499360__FUN_00499360.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 25 | prior triage: short computation]
2999. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ab0__FUN_00499ab0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3000. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e70__FUN_00499e70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3001. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a3b0__FUN_0049a3b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 42 | prior triage: unidentified]
3002. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afa0__FUN_0049afa0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3003. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e410__FUN_0049e410.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
3004. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f790__FUN_0049f790.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 66 | prior triage: unidentified]
3005. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a11d0__FUN_004a11d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3006. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2770__FUN_004a2770.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3007. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40c0__FUN_004a40c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3008. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004aa170__FUN_004aa170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3009. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1a90__FUN_004b1a90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3010. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2750__FUN_004b2750.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
3011. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b90__FUN_004b2b90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3012. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4450__FUN_004b4450.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3013. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b54a0__FUN_004b54a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: arithmetic/comparison]
3014. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9cf0__FUN_004b9cf0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3015. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba8c0__FUN_004ba8c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3016. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb3d0__FUN_004bb3d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3017. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc390__FUN_004bc390.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3018. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bea10__FUN_004bea10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3019. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2810__FUN_004c2810.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3020. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2ff0__FUN_004c2ff0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3021. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c00__FUN_004c7c00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3022. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c85c0__FUN_004c85c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3023. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c92b0__FUN_004c92b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
3024. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb4f0__FUN_004cb4f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3025. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0030__FUN_004d0030.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3026. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d47e0__FUN_004d47e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3027. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7020__FUN_004d7020.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3028. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7f20__FUN_004d7f20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3029. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9280__FUN_004d9280.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3030. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbf90__FUN_004dbf90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
3031. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcd80__FUN_004dcd80.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: short computation]
3032. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd8f0__FUN_004dd8f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: unidentified logic]
3033. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e23d0__FUN_004e23d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
3034. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ed750__FUN_004ed750.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: unidentified logic]
3035. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6d60__FUN_004f6d60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3036. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8ce0__FUN_004f8ce0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3037. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f30__FUN_004f9f30.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: utility function]
3038. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd6f0__FUN_004fd6f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: unidentified logic]
3039. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005006d5__FUN_005006d5.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 7 | prior triage: utility function]
3040. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503533__FUN_00503533.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified logic]
3041. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005063a5__FUN_005063a5.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3042. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050ae76__FUN_0050ae76.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3043. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b743__FUN_0050b743.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3044. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2a6__FUN_0050c2a6.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3045. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d5f9__FUN_0050d5f9.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3046. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e281__FUN_0050e281.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3047. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fa0e__FUN_0050fa0e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3048. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051189c__FUN_0051189c.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
3049. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513a56__FUN_00513a56.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3050. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515917__FUN_00515917.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3051. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516853__FUN_00516853.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3052. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517ee1__FUN_00517ee1.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3053. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c5a3__FUN_0051c5a3.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 32 | prior triage: unidentified logic]
3054. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052179f__FUN_0052179f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
3055. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00528f00__FUN_00528f00.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: unidentified logic]
3056. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e080__FUN_0052e080.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3057. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005352b0__FUN_005352b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3058. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537ce0__FUN_00537ce0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3059. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b1d0__FUN_0053b1d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3060. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c2c0__FUN_0053c2c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3061. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d1f0__FUN_0053d1f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
3062. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540150__FUN_00540150.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3063. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542460__FUN_00542460.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3064. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544f50__FUN_00544f50.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: unidentified logic]
3065. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547140__FUN_00547140.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: unidentified logic]
3066. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005487a0__FUN_005487a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3067. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005493b0__FUN_005493b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: memory allocation]
3068. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bda0__FUN_0054bda0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3069. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc10__FUN_0054fc10.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 7 | prior triage: arithmetic/comparison]
3070. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00552fd0__FUN_00552fd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: Struct setter — masks two uint fields at +0x4c/+0x50 with 0x20/0xc0]
3071. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559350__FUN_00559350.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: String copy with struct field initializer]
3072. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055ceb0__FUN_0055ceb0.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: RGBA byte extraction from packed uint]
3073. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005647d0__FUN_005647d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: Network-style operation — calls function ptr, checks -1 return, calls FUN_005648b0]
3074. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005679a0__thunk_FUN_0059d6a9.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 18 | prior triage: Null-check wrapper: returns 0 if param_1==0, else calls FUN_005679a5]
3075. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a260__FUN_0057a260.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: struct field getter: byte at +0x2c + 0x29]
3076. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b6a0__FUN_0057b6a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: returns param_1 + 0x10]
3077. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585810__FUN_00585810.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: WaitForSingleObject/ReleaseMutex wrapper with worker call]
3078. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587490__FUN_00587490.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 23 | prior triage: Init struct to 0, call FUN_00587580 parse routine]
3079. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588821__FUN_00588821.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: File operation wrapper using DAT_005e6768 buffer]
3080. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ac95__FUN_0058ac95.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 29 | prior triage: String format wrapper with overflow guard]
3081. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005904c1__FUN_005904c1.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 20 | prior triage: Windows NT version check — GetVersionExA, dwPlatformId==2]
3082. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595621__FUN_00595621.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 31 | prior triage: Locale-aware string formatting helper]
3083. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987c1__FUN_005987c1.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Factory wrapper]
3084. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599c58__FUN_00599c58.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: C++ constructor with vtable setup]
3085. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c127__FUN_0059c127.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: Thread-safe wrapper — lock (FUN_0058c1b1), call FUN_0059c156, unlock]
3086. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c93a__Unwind_0059c93a.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00581750]
3087. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d020__Unwind_0059d020.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_00586210]
3088. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d99e__FUN_0059d99e.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: thunk to FUN_004e94a3]

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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_P.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
