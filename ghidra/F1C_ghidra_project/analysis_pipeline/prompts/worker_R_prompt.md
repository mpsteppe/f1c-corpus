# WORKER R — F1 Challenge 99-02 Deep Dive Documentation

You are building a complete consensus map of every function in F1 Challenge 99-02's engine.
Worker R of 20, items 3282–3474.

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
  %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_R.md

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

3282. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513cd3__thunk_FUN_00517ec8.c
   [category: thunk | target: docs/20-math-utilities.md | lines: 14 | prior triage: trampoline to thunk_FUN_00517ec8]
3283. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005514c0__FUN_005514c0.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 35 | prior triage: Timer-based state update with cap]
3284. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553630__FUN_00553630.c
   [category: Entity | target: docs/01-engine-architecture.md | lines: 13 | prior triage: Two-field setter]
3285. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556330__FUN_00556330.c
   [category: Time | target: docs/01-engine-architecture.md | lines: 30 | prior triage: Timer accumulate via QueryPerformanceCounter]
3286. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557630__FUN_00557630.c
   [category: Graphics/Flag | target: docs/19-renderer.md | lines: 31 | prior triage: Texture flag bit test, dispatch cleanup path]
3287. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bb70__FUN_0055bb70.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Struct zero-init]
3288. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d530__FUN_0055d530.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 14 | prior triage: State field setter with global flag]
3289. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561940__FUN_00561940.c
   [category: Game/FieldCleanup | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Field cleanup with null check]
3290. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005631d0__FUN_005631d0.c
   [category: Audio/Search | target: docs/21-audio-network-internals.md | lines: 25 | prior triage: Audio note/param index search loop]
3291. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564780__FUN_00564780.c
   [category: Engine/CallWithRetry | target: docs/01-engine-architecture.md | lines: 20 | prior triage: Function pointer call with error handling]
3292. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005668d0__FUN_005668d0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Sub-call + conditional field free]
3293. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005685b0__FUN_005685b0.c
   [category: Text/Parse | target: docs/20-math-utilities.md | lines: 36 | prior triage: Check if string starts with +~XX prefix pattern]
3294. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569ad0__FUN_00569ad0.c
   [category: Physics/Accum | target: docs/18-physics-dynamics.md | lines: 35 | prior triage: Accumulate angular momentum with cross product]
3295. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a200__FUN_0057a200.c
   [category: Data | target: docs/01-engine-architecture.md | lines: 26 | prior triage: memcpy-like copy with byte/word split + size store]
3296. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a910__FUN_0057a910.c
   [category: Dispatch | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Single function call wrapper]
3297. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b7b0__FUN_0057b7b0.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 15 | prior triage: Conditional free based on flag bit]
3298. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581780__FUN_00581780.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 17 | prior triage: Linked list node advance]
3299. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005834c0__FUN_005834c0.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 31 | prior triage: List destruction with virtual release]
3300. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585550__FUN_00585550.c
   [category: Threading | target: docs/01-engine-architecture.md | lines: 39 | prior triage: Thread termination with wait cleanup]
3301. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586460__FUN_00586460.c
   [category: Memory/Cleanup | target: docs/01-engine-architecture.md | lines: 34 | prior triage: Destroy linked list with vtable destructor dispatch]
3302. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587030__FUN_00587030.c
   [category: DataStructure | target: docs/01-engine-architecture.md | lines: 18 | prior triage: Object init with vtable setup]
3303. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587710__FUN_00587710.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 12 | prior triage: Field setter]
3304. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005884ed___rand.c
   [category: Math/CRT | target: docs/20-math-utilities.md | lines: 22 | prior triage: _rand() LCG random number generator]
3305. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a2a6____amsg_exit.c
   [category: Sys/CRT | target: docs/20-math-utilities.md | lines: 21 | prior triage: CRT __amsg_exit (error exit)]
3306. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058abf1__FUN_0058abf1.c
   [category: Sync/CriticalSection | target: docs/01-engine-architecture.md | lines: 12 | prior triage: CritSect leave (slot 9)]
3307. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c411____freebuf.c
   [category: crt_util | target: docs/20-math-utilities.md | lines: 24 | prior triage: --]
3308. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e12e__FUN_0058e12e.c
   [category: String | target: docs/01-engine-architecture.md | lines: 38 | prior triage: Encoding/locale detection from parse result]
3309. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591e89__FUN_00591e89.c
   [category: Sys/Nop | target: docs/20-math-utilities.md | lines: 13 | prior triage: No-op function (size 86)]
3310. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595310__FUN_00595310.c
   [category: Data/ZeroCheck | target: docs/20-math-utilities.md | lines: 21 | prior triage: Array-of-3 zero check]
3311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005982f8__FUN_005982f8.c
   [category: String | target: docs/01-engine-architecture.md | lines: 21 | prior triage: Bounded string length with cap]
3312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598c70__FUN_00598c70.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 19 | prior triage: Null check with virtual dispatch]
3313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599534__FUN_00599534.c
   [category: Memory | target: docs/01-engine-architecture.md | lines: 20 | prior triage: Buffer boundary marker check + set]
3314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599ad9__FUN_00599ad9.c
   [category: GameLogic | target: docs/01-engine-architecture.md | lines: 25 | prior triage: Ref count decrement with check]
3315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a4c9__FUN_0059a4c9.c
   [category: Data/Init | target: docs/20-math-utilities.md | lines: 23 | prior triage: Self-referential pointer ring init]
3316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ae07__FUN_0059ae07.c
   [category: Sys/Throw | target: docs/20-math-utilities.md | lines: 15 | prior triage: C++ throw with exception]
3317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bfc3____CxxThrowException_8.c
   [category: Exception/CRT | target: docs/01-engine-architecture.md | lines: 35 | prior triage: __CxxThrowException@8 raise C++ exception via SEH]
3318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c53e__Unwind_0059c53e.c
   [category: Sys/Unwind | target: docs/20-math-utilities.md | lines: 14 | prior triage: Unwind handler (SEH)]
3319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c666__Unwind_0059c666.c
   [category: System | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind with field free]
3320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7e0__Unwind_0059c7e0.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c91e__Unwind_0059c91e.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb48__Unwind_0059cb48.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd00__Unwind_0059cd00.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ced7__Unwind_0059ced7.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
3325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d036__Unwind_0059d036.c
   [category: System | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind with single call]
3326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d1a8__Unwind_0059d1a8.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 14 | prior triage: SEH unwind release locale refcount]
3327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3cc__Unwind_0059d3cc.c
   [category: System | target: docs/01-engine-architecture.md | lines: 17 | prior triage: SEH unwind handler for EH cleanup]
3328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d5a8__Unwind_0059d5a8.c
   [category: Exception/Unwind | target: docs/01-engine-architecture.md | lines: 12 | prior triage: SEH unwind cleanup call]
3329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004038e0__FUN_004038e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: memory allocation]
3330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404ef0__FUN_00404ef0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405e60__FUN_00405e60.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 58 | prior triage: short computation]
3332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004070e0__FUN_004070e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 52 | prior triage: memory allocation]
3333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408290__FUN_00408290.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040ad90__FUN_0040ad90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d090__FUN_0040d090.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1d0__FUN_0040e1d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f1c0__FUN_0040f1c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 58 | prior triage: short computation]
3338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411680__FUN_00411680.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414490__FUN_00414490.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004189b0__FUN_004189b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f040__FUN_0041f040.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004218f0__FUN_004218f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423490__FUN_00423490.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00452700__FUN_00452700.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
3345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004560e0__FUN_004560e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459830__FUN_00459830.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 61 | prior triage: float computation]
3347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bb90__FUN_0045bb90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 19 | prior triage: short computation]
3348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c7a0__FUN_0045c7a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ebd0__FUN_0045ebd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 61 | prior triage: unidentified]
3350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461dc0__FUN_00461dc0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462a00__FUN_00462a00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004646f0__FUN_004646f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464f50__FUN_00464f50.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 25 | prior triage: unidentified]
3354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004662e0__FUN_004662e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004698c0__FUN_004698c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 16 | prior triage: short computation]
3356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c7b0__FUN_0046c7b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: unidentified]
3357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046eec0__FUN_0046eec0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: short computation]
3358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470af0__FUN_00470af0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00472720__FUN_00472720.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 40 | prior triage: unidentified]
3360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004742a0__FUN_004742a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476080__FUN_00476080.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004780d0__FUN_004780d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004796c0__FUN_004796c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479c00__FUN_00479c00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a5b0__FUN_0047a5b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c0d0__FUN_0047c0d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f3f0__FUN_0047f3f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 20 | prior triage: short computation]
3368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485a70__FUN_00485a70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486580__FUN_00486580.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 42 | prior triage: unidentified]
3370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487530__FUN_00487530.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 21 | prior triage: short computation]
3371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004881b0__FUN_004881b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489560__FUN_00489560.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 17 | prior triage: short computation]
3373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048bc70__FUN_0048bc70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d3e0__FUN_0048d3e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e890__FUN_0048e890.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fdf0__FUN_0048fdf0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490aa0__FUN_00490aa0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 35 | prior triage: unidentified]
3378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491960__FUN_00491960.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494620__FUN_00494620.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004952e0__FUN_004952e0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: short computation]
3381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00496840__FUN_00496840.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 22 | prior triage: short computation]
3382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497d00__FUN_00497d00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: short computation]
3383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498e30__FUN_00498e30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: short computation]
3384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499520__FUN_00499520.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 14 | prior triage: short computation]
3385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499af0__FUN_00499af0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 18 | prior triage: short computation]
3386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499e90__FUN_00499e90.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: short computation]
3387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a490__FUN_0049a490.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 27 | prior triage: unidentified]
3388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afe0__FUN_0049afe0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 15 | prior triage: short computation]
3389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e760__FUN_0049e760.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: unidentified]
3390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049feb0__FUN_0049feb0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 82 | prior triage: float computation]
3391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1367__FUN_004a1367.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 14 | prior triage: unidentified logic]
3392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2800__FUN_004a2800.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a40f0__FUN_004a40f0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0170__FUN_004b0170.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1ac0__FUN_004b1ac0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2840__FUN_004b2840.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2c20__FUN_004b2c20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4470__FUN_004b4470.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 6 | prior triage: arithmetic/comparison]
3399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5760__FUN_004b5760.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: unidentified logic]
3400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9d20__FUN_004b9d20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 13 | prior triage: arithmetic/comparison]
3401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba950__FUN_004ba950.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb460__FUN_004bb460.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bd7a0__FUN_004bd7a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf640__FUN_004bf640.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 8 | prior triage: arithmetic/comparison]
3405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2850__FUN_004c2850.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c3030__FUN_004c3030.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7c30__FUN_004c7c30.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8630__FUN_004c8630.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9360__FUN_004c9360.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: arithmetic/comparison]
3410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb5a0__FUN_004cb5a0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 10 | prior triage: arithmetic/comparison]
3411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0060__FUN_004d0060.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d4840__FUN_004d4840.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7920__FUN_004d7920.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7fa0__FUN_004d7fa0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: utility function]
3415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d93e0__FUN_004d93e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 10 | prior triage: utility function]
3416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc1a0__FUN_004dc1a0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dcdd0__FUN_004dcdd0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 43 | prior triage: unidentified logic]
3418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ddf70__FUN_004ddf70.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2a00__FUN_004e2a00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
3420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004efb20__FUN_004efb20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 21 | prior triage: unidentified logic]
3421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6f00__FUN_004f6f00.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 9 | prior triage: arithmetic/comparison]
3422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8d20__FUN_004f8d20.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f70__FUN_004f9f70.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 2 | prior triage: utility function]
3424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fd840__FUN_004fd840.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005007ef__FUN_005007ef.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
3426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050368a__FUN_0050368a.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: unidentified logic]
3427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005064cf__FUN_005064cf.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: unidentified logic]
3428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050af3b__FUN_0050af3b.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b77b__FUN_0050b77b.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c391__FUN_0050c391.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d690__FUN_0050d690.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e302__FUN_0050e302.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 5 | prior triage: short computation]
3433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050fb3b__FUN_0050fb3b.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 8 | prior triage: unidentified logic]
3434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511b5c__FUN_00511b5c.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513b36__FUN_00513b36.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: short computation]
3436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051593f__FUN_0051593f.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 16 | prior triage: unidentified logic]
3437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516937__FUN_00516937.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 3 | prior triage: arithmetic/comparison]
3438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f35__FUN_00517f35.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: arithmetic/comparison]
3439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c6be__FUN_0051c6be.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005219e1__FUN_005219e1.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 57 | prior triage: unidentified logic]
3441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005295e0__FUN_005295e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: unidentified logic]
3442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e1c0__thunk_FUN_0052d9b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 17 | prior triage: Thunk — sets vtable to PTR_FUN_005b47e8, checks byte flag at +0x93b]
3443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535390__FUN_00535390.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 9 | prior triage: unidentified logic]
3444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005388d0__FUN_005388d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: unidentified logic]
3445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b240__FUN_0053b240.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 37 | prior triage: unidentified logic]
3446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c4d0__FUN_0053c4d0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 6 | prior triage: unidentified logic]
3447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d2b0__FUN_0053d2b0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 4 | prior triage: utility function]
3448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00540240__FUN_00540240.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 1 | prior triage: short computation]
3449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005424c0__FUN_005424c0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: short computation]
3450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005450e0__FUN_005450e0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 5 | prior triage: unidentified logic]
3451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005471d0__FUN_005471d0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: arithmetic/comparison]
3452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548810__FUN_00548810.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 11 | prior triage: arithmetic/comparison]
3453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054a160__FUN_0054a160.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c0b0__FUN_0054c0b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 2 | prior triage: arithmetic/comparison]
3455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc50__FUN_0054fc50.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 4 | prior triage: arithmetic/comparison]
3456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553a20__FUN_00553a20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 28 | prior triage: Float-to-int conversion chain with flag bit check]
3457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559a30__FUN_00559a30.c
   [category: Utility | target: docs/20-math-utilities.md | lines: 12 | prior triage: Single delegation call]
3458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d2f0__FUN_0055d2f0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 22 | prior triage: Bit flag setter — sets/clears bit 7 of *param_1, calls FUN_005416a0]
3459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005648b0__FUN_005648b0.c
   [category: math_util | target: docs/20-math-utilities.md | lines: 12 | prior triage: Linear interpolation: *(int*)(param_1+8) * param_2 + *(int*)(param_1+0x14)]
3460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567a90__FUN_00567a90.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 29 | prior triage: Recursive tree traversal: free child nodes, then self]
3461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a560__FUN_0057a560.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 12 | prior triage: Extracts byte at *param_1+0x5d combined with shifted high byte]
3462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b6c0__FUN_0057b6c0.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: Setter: writes param_2 to struct+0x24]
3463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585e20__FUN_00585e20.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: callback registration: FUN_00587b3e(&LAB_00585e30)]
3464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587510__FUN_00587510.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 38 | prior triage: Memory copy — memcpy-like with word-aligned fast path]
3465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058890e____abnormal_termination.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 24 | prior triage: MSVC __abnormal_termination CRT function]
3466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b050___strrchr.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 45 | prior triage: --]
3467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059086e____fload.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: --]
3468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005957bd__FUN_005957bd.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 30 | prior triage: Memory buffer allocator init (malloc 0x1000)]
3469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598994__FUN_00598994.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 26 | prior triage: Decrement DAT_005e9ef4 counter, cleanup when 0]
3470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599e71__FUN_00599e71.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 34 | prior triage: C++ destructor with vtable chain cleanup]
3471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c464__Unwind_0059c464.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
3472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca10__Unwind_0059ca10.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 15 | prior triage: MSVC exception handler unwind trampoline]
3473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d09c__Unwind_0059d09c.c
   [category: unknown | target: docs/20-math-utilities.md | lines: 13 | prior triage: C++ unwind helper — thunk to FUN_0047aa60]
3474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059dab7__FUN_0059dab7.c
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
4. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\worker_R.md after each entry — never accumulate in memory.
5. Leave `=== TRIAGE LINES ===` EMPTY.
6. Resolve every DAT_ address to its known name via docs/12.
7. Resolve every struct offset to its known field name via docs/13.
8. For every called function: check the triage index for its one-line description.
9. Every function must have a "Used by system" field — even if it is an inference.
10. Thunks and empty stubs still require the full entry format above.
