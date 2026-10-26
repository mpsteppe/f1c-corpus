# Implementation Spec: Math Utilities

Source: docs/20-math-utilities.md  |  Functions: ~1,414 (+ ~4,000 pure math)  |  Date: 2026-07-15

---

## Overview

The Math Utilities subsystem is the engine's mathematical foundation — a collection of ~5,400 pure computation functions that perform vector/matrix/quaternion arithmetic, geometry operations, interpolation, numeric conversions, memory management, file I/O, string formatting, data structure manipulation, thread synchronization, and MSVC CRT runtime support.

**When it runs:** These functions have no single execution context. They are called:
- Per-frame (60Hz): from physics integration, render transforms, AI pathfinding — ~3,000 calls/frame estimated
- Per-tick (10Hz): from game tick, AI state updates
- On event: file loading, scene parsing, collision handling
- On init/shutdown: memory pool setup, CRT init, constructor/destructor chains
- On exception: SEH unwind handlers

**Data structures owned:**
- No single owning struct. Functions take caller-provided struct pointers (param_1 = `this`, param_2+ = output/input).
- Memory allocators own global state: buddy allocator bitmap at `DAT_008d48f0/DAT_008d48f8/DAT_008d48fc`, stack allocator at `DAT_008d5a54/DAT_008d5a50`, VM page counter `DAT_008d41b8`.

**Global state written by this system:**
- `DAT_008afea0/DAT_008afea8` — SessionTime (accumulated by FUN_004f9ad0 per tick)
- `DAT_008d48f0/DAT_008d48f8/DAT_008d48fc` — buddy allocator state (alloc/free updates)
- `DAT_008d5a54/DAT_008d5a50` — stack allocator state
- `DAT_008d41b8` — live virtual memory page counter
- `DAT_008aae70/DAT_008aae74` — random ring buffer (read/advance by FUN_00448300)
- `DAT_008b8f24` — renderer transform vtable (read by FUN_0055EBA0)

**Interface with other systems:**
- **Physics (docs/10, 18):** Vector/matrix ops compute tire forces, suspension displacement, aero loads. Reads vehicle struct offsets (+0x1330 LifetimeAvg, etc.).
- **Renderer (docs/19):** 4×4 matrix/quaternion ops for view/projection transforms. Vertex color modulation for D3D vertex buffers.
- **AI (docs/02):** Random scaling of ability parameters (QualifyingAbility +0x1130, RaceAbility +0x1138).
- **Audio (docs/21):** Buffer allocation, encoding helpers for sound stream processing.
- **File I/O (docs/08):** CRT wrappers, buffer allocators for scene/setup file parsing.

---

## Data Structures

Math utilities operate on caller-provided structs with no single structural definition. Key multi-function structures:

### Buffer Descriptor (param_2 / param_1 — multiple functions)

| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | CurrentPtr | int32* | Current write position in buffer |
| +0x04 | RemainingCount | int32 | Bytes left before flush needed |
| +0x18 | MatrixA | float[12] | 3×4 matrix (via FUN_0056c3a0) |
| +0x28 | BufferStart | ? | Start of buffer (wrap target) |
| +0x2c | BufferEnd | ? | End of buffer (wrap limit) |
| +0x30 | ReadPtr | ? | Current read position |
| +0x34 | EndPtr | ? | Buffer end pointer |
| +0x38 | Callback | ? | Optional callback function |
| +0x3c | CallbackCtx | ? | Callback context |
| +0x78 | ExtraInt1 | int | Written from param_5 |
| +0x7c | ExtraInt2 | int | Written from param_3 |
| +0x80 | ExtraByte | byte | Written from param_4 |

### Timer/Performance State (param_1 — FUN_00568be0, FUN_00569da0)

| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | FrequencyLowPart | uint | QPC frequency low DWORD |
| +0x08 | InvFrequencyScaled | double | scaling_constant / freq |
| +0x10–+0x14 | AccLow/AccHigh | uint | Zeroed accumulators |
| +0x18–+0x1c | CounterLow/CounterHigh | uint | QPC init sample |
| +0x20–+0x24 | LastSampleLow/High | uint | Copy of init sample |
| +0x28–+0x2c | Acc/Overflow | uint | Zeroed |
| +0x48 | Mode | uint | Timer mode flags |

### Linked List Node (generic, used by ~50 functions)

| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Key / ID | int32 | Match key or pointer |
| +0x04 | NextPtr | int32* | Next node in list |

### Dynamic Array Container (param_1)

| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | Capacity | int | Current capacity (elements) |
| +0x10 | Count | int | Current element count |
| +0x14 | Data | ptr | Array data pointer |

### BitStreamWriter (param_1 — FUN_00539690, FUN_00537f30, FUN_00539720)

| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x008 | OutputBufferPtr | byte* | Destination buffer |
| +0x014 | BufferPosition | int | Current write offset |
| +0x16ab | BitAccumLow | ushort | Pending bits / char byte |
| +0x16ac | BitAccumHigh | byte | Pending high bits |
| +0x16ad | BitCount | int | Valid bits count |

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_008afea0 | float | SessionTime | Accumulated per-tick by FUN_004f9ad0 |
| DAT_008afea8 | float | SessionTimeAlt | Secondary accumulated time |
| DAT_008d48f0 | int | BuddyAllocBitmap0 | Buddy allocator bitmap/state |
| DAT_008d48f8 | int | BuddyAllocBitmap1 | Buddy allocator free list |
| DAT_008d48fc | int | BuddyAllocBitmap2 | Buddy allocator size classes |
| DAT_008d5a54 | int | StackAllocPtr | Stack allocator current pointer |
| DAT_008d5a50 | int | StackAllocCapacity | Stack allocator capacity |
| DAT_008d41b8 | int | LivePageCount | Virtual memory live page counter |
| DAT_008aae70 | int | RingBufferCounter | Random noise ring buffer index (advances per read) |
| DAT_008aae74 | int | RingBufferCounter2 | Random noise ring buffer secondary |
| DAT_008b8f24 | ptr | D3DDeviceWrapperPtr | Renderer transform vtable |
| DAT_008d5a58 | int | ReentrancyGuard | Thread-safe I/O guard counter |

---

## Public API — Entry Points

Math utilities have no single entry point. They are called from every engine subsystem. The notable entry-point functions are:

### FUN_004f9ad0 — Time Accumulation Entry

**Inferred signature:** `void TimeAccumulate(void* param_1)`
**Called from:** Game loop per tick
**Called by (from callers.json):** FUN_004a0eb0 (options menu), FUN_0042d8a0 (game post) transitively

**What it does:**
1. Queries timer via `FUN_00556730`
2. Accumulates delta into `DAT_008afea0/DAT_008afea8`
3. Called per-tick, provides global session time reference

**Side effects:**
- Writes: DAT_008afea0, DAT_008afea8

### FUN_00448300 — RandomScaledValue

**Inferred signature:** `void RandomScale(RandomState* this)`
**Called from:** Physics/AI noise functions

**What it does:**
1. Draws random value from ring buffer (`DAT_008aae70`, `DAT_008aae74`)
2. Multiplies `this[2]` (at +8) by random value
3. Stores at `this+0x14`

**Side effects:**
- Reads: DAT_008aae70, DAT_008aae74
- Advances: RingBufferCounter

### FUN_0059416f — Buddy/Slab Memory Allocator

**Inferred signature:** `int* BuddyAlloc(uint* size)`
**Called from:** File I/O, string processing, renderer (hundreds of callers)

**What it does:**
1. Searches two-level bitmap for free slot matching requested size
2. Splits/coalesces blocks as needed
3. Manages size classes with linked lists (prev/next at offsets +4, +8)
4. Modifies bitmap bits on alloc/free
5. Returns pointer to usable memory
6. On OOM: calls `FUN_00594478` to expand pool

**Side effects:**
- Writes: DAT_008d48f0/DAT_008d48f8/DAT_008d48fc

### FUN_0059B490 — Dynamic Buffer Reallocation

**Inferred signature:** `int BufferGrow(void** buffer, int neededSize)`
**Called from:** String processing, data loading

**What it does:**
1. If neededSize > oldLen * 8: compute growth unit from param_1[6]
2. Loop: newLen = growthUnit + oldLen, until newLen >= 0x1f400 (128KB max)
3. `operator_new(newLen)` — allocate new buffer
4. Copy old data: dword loop (oldLen>>2) + byte remainder (oldLen&3)
5. `FUN_00587bcf(oldBuffer)` — free old buffer
6. Update *buffer = newBuffer, param_1[1] = newLen

**Key constants:**
- 0x1f400 = 128KB max buffer size
- 8 = geometric growth multiplier

### FUN_00587bcf — Memory Dealloc / Free (most-called function)

**Inferred signature:** `void Free(void* ptr)`
**Called from:** ~500+ functions across all subsystems

**What it does:**
1. If ptr is NULL: return immediately
2. Frees memory (likely calls `operator delete` or `HeapFree`)
3. Called as the universal deallocation function — the engine's primary `free`

### FUN_00587b3e — Callback Registration (atexit-like)

**Inferred signature:** `void RegisterCallback(void (*func)(void))`
**Called from:** Module init/deinit functions (~40 callers)

**What it does:**
1. Registers function pointer for deferred/during-unwind execution
2. Similar to `_atexit` — used for module cleanup registration

### FUN_005677b0 — Gaussian Elimination Solver (Linear Algebra)

**Inferred signature:** `int GaussSolve(double* matrix)`
**Called from:** Physics constraint solver

**What it does:**
1. Performs LU decomposition on matrix (flat double array)
2. Pivots rows with zero diagonals
3. Scales rows by reciprocal pivot
4. Eliminates below-diagonal entries
5. Returns -1 if singular, 0 on success

**Key constants:** None — operates on caller data only

### FUN_0056aa60 — Multi-Phase Finite-Element Matrix Assembly

**Inferred signature:** `void MatrixAssembly(void* param_1)`
**Size:** 2922 bytes — largest pure math function
**Called from:** Physics integration

**What it does:**
1. Three constraint groups at param_1+0x22c, +0x234, +0x23c
2. 22 double-precision variables for cross-element coupling
3. Double-nested loops: outer (count_22c), inner (count_22c × count_234 × count_23c)
4. Matrix reads at param_1+0xb4, +0xec–+0x124, +0x228 (matrix block pointer)
5. Stride 0x38 between outer loop elements, stride 0x84 for middle group, stride 0x58 for inner group
6. Branching on param_2 field at +0x34: same-group vs cross-group accumulation
7. Accumulates into result matrix at **(param_1+0x228) with element pointer indirection

**Side effects:**
- Writes: Result matrix at param_1+0x228

### FUN_0055EBA0 — 3D Lighting/Reflection Vector Compute

**Inferred signature:** `void ComputeReflectionVectors(void* vertexData, float* lightPos)`
**Called from:** Renderer per-vertex lighting

**What it does:**
1. Reads vertex count from param_1+8
2. Stride detection: flag at *(param_1+0x18)+0x14 has bit 0x800000? stride 0x10, else 0x0c
3. Per vertex: read position via vtable dispatch (DAT_008b8f24), compute direction to light
4. Compute reflection: NdotL = n·dir, reflect = 2*NdotL*n - dir*invLen
5. Store result in array at param_1[0x20] with stride 0x40

**Key constants:**
- _DAT_0059e43c = 1.0f (constant)
- _DAT_0059e450 = 0.5f (scale/bias)

### FUN_00566380 — Linked-List Merge Sort

**Inferred signature:** `Node* ListMergeSort(Node* head)`
**Called from:** UI rendering, AI sorting

**What it does:**
1. Finds list midpoint via traversal
2. Recursively sorts both halves
3. Merges using comparison function or key comparison

### FUN_00567b00 (thunk) / FUN_00567b10 — Path Comparison

**Inferred signature:** `int PathCompare(char* path1, char* path2)`
**Called from:** File system, scene loading

**What it does:**
1. Compares two file paths
2. Returns 0 (equal) or 1 (not equal)

### FUN_005567f5 — CPU Feature Detection

**Inferred signature:** `void DetectCPU(uint* features, uint* vendor)`
**Called from:** Startup initialization

**What it does:**
1. Tests EFLAGS ID bit toggling (CPUID support)
2. Uses RDTSC for timestamp
3. Returns CPUID vendor string and feature flags

### FUN_00594AB4 — OS Virtual Memory Page Free

**Inferred signature:** `void FreeVMPages(int pageCount)`
**Called from:** Memory manager on cleanup

**What it does:**
1. Walks linked list at PTR_LOOP_005e796c
2. For each allocation block: walks page entries (stride -0x1000)
3. If page status at +0x2010 == 0xf0: `VirtualFree(address, 0x1000, MEM_RELEASE)`
4. Decrements DAT_008d41b8 (live page count)
5. If all pages in block freed: frees the whole block

**Key constants:**
- 0xf0 = freeable page status
- 0x1000 = page size
- 0x400 = page entries per block

---

## Internal Call Graph

```
PhysicsIntegration (docs/18)
  +-- FUN_0056aa60 — matrix assembly (~2922B, 22 double vars, 3 constraint groups)
  |     reads param_1+0x22c/0x234/0x23c (counts), +0x228 (matrix base)
  |     stride 0x38/0x84/0x58 per element group
  +-- FUN_0056c640 — 3D vector cross product + normalize (double)
  +-- FUN_0056bde0 — axis-angle rotation matrix (Rodrigues formula) + Euler extraction

RendererTransform (docs/19)
  +-- FUN_00566f40 — quaternion-to-3x3 rotation matrix
  +-- FUN_0056c740 — 3×3 matrix multiply (double, 9 elements)
  +-- FUN_0055EBA0 — per-vertex reflection vector (virtual dispatch per vertex)
  +-- FUN_0050a92d — vertex color pack RGB→16-bit
  +-- FUN_0055eb30 — vertex color modulation (packed short multiply, RGBA blend)

CRT FormatString
  +-- FUN_00596175 — format ID→handler dispatch (IDs 1-8)
        +-- FUN_0058bdcd — float-to-string (double→decimal)
        |     +-- FUN_00595621 — double parse→buffer
        |     +-- FUN_005955aa — decimal string with carry rounding
        |     +-- FUN_0058be2e — final string render
        +-- FUN_0058bccf — direct double→decimal

FileRead (docs/08)
  +-- FUN_0058806e — buffered file read (param_1 buffer, param_2 size, param_3 count)
  |     +-- FUN_0058c9b4 — buffer refill on underflow
  +-- FUN_0058e22b — file write with handle validation
        +-- FUN_0058e290 — WriteFile + \n→\r\n conversion (text mode)

MemoryAlloc
  +-- FUN_0059416f — buddy allocator (bitmap search + split/coalesce)
  |     +-- FUN_00594478 — expand pool on OOM
  +-- FUN_0059B490 — dynamic buffer realloc (geometric growth, 128KB cap)
        +-- operator_new + memcpy + FUN_00587bcf (free)
  +-- FUN_00594AB4 — OS VM page free (VirtualFree per page)

SEH Unwind (exception-paths only)
  +-- Unwind_0059c684 → FUN_00587bcf(stack_var)
  +-- Unwind_0059cd1e → FUN_00587bcf(stack_var)
  +-- Unwind_0059c770 → FUN_005867b0 (linked list cleanup)
  +-- Unwind_0059d524 → FUN_0059a9c2 (destructor dispatch)

Linked List (UI/data cleanup)
  +-- FUN_005819c0 — list destroy with vtable destructor call
  |     walks head/next, calls (**(*data+4))(1), frees node
  +-- FUN_005832e0 — node removal by key (doubly-linked)
  +-- FUN_0059a980 — free two lists at +0x18/+0x1c
  +-- FUN_00566380 — merge-sort (recursive split, merge by key)

Time/Timer
  +-- FUN_005564b0 — QPC timer read (two modes: direct QPC or alternate)
  +-- FUN_00568be0 — QPC init (frequency, scale, accumulators)
  +-- FUN_004f9ad0 — per-tick accumulation → DAT_008afea0
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0x1f400 (128KB) | FUN_0059B490 | Max dynamic buffer growth cap |
| 8 | FUN_0059B490 | Geometric growth multiplier |
| 32 (0x1f rounding) | FUN_0059964a | Buffer size alignment |
| 0xf0 | FUN_00594AB4 | Page status = freeable |
| 0x1000 | FUN_00594AB4 | VM page size |
| 0x400 | FUN_00594AB4 | Page entries per block |
| 0x38 | FUN_0056aa60 | Outer constraint group stride |
| 0x84 | FUN_0056aa60 | Middle constraint group stride |
| 0x58 | FUN_0056aa60 | Inner constraint group stride |
| 0x10 / 0x0c | FUN_0055EBA0 | Vertex stride (flag-dependent) |
| 0x40 | FUN_0055EBA0 | Output array stride |
| 0.5f | _DAT_0059e450 | Half constant (scale/bias) |
| 1.0f | _DAT_0059e43c | One constant |
| 0.0f | _DAT_0059e440 | Zero sentinel / near-zero threshold |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_008afea0` (SessionTime) — read by FUN_0049ba10, FUN_004f9ad0 (time-scaled functions)
- `DAT_008b8f24` (D3DDeviceWrapperPtr) — read by FUN_0055EBA0 for vertex transforms
- `DAT_008aae70` (RingBufferCounter) — read/advance by FUN_00448300
- `DAT_008d41b8` (LivePageCount) — read/write by FUN_00594AB4
- `DAT_0059e440` (ZeroThreshold) — read by ~18 physics comparison functions
- `DAT_0059e43c` (1.0f constant) — read by ~12 math functions
- `DAT_0059e450` (0.5f Half constant) — read by ~8 functions

**Calls into:**
- No calls into game-logic subsystems — this is a pure utility layer
- Calls Win32 API: VirtualFree, CreateMutexA, CloseHandle, QueryPerformanceCounter, WaitForSingleObject, ReleaseMutex, GetEnvironmentStringsW/A, GetLocaleInfoW/A, WideCharToMultiByte

**Called by:** Every subsystem (docs/02, 03, 04, 05, 06, 07, 08, 09, 10, 17, 18, 19, 21)

---

## Reimplementation Notes

1. **No central dispatcher:** Unlike subsystem modules that follow the lifecycle pattern, math utilities have no single owning class. Each is called independently by whoever needs it. Reimplementation can keep them as a `util/` namespace of free functions.

2. **FUN_00587bcf is the universal deallocator:** This is the most-called function in the entire engine (~500+ callers). It wraps `operator delete` or `HeapFree`. Must be present in any reimplementation.

3. **FUN_00587b3e is the registration callback:** Used for module-level atexit cleanup. Stores function pointers for deferred execution during DLL unload or exception unwind. Can be replaced with `std::atexit` or a custom cleanup registry.

4. **FUN_0056aa60 (matrix assembly) is the most complex function:** 2922 bytes, 22 double-precision variables, 3 constraint groups with stride 0x38/0x84/0x58, nested loops, sparse matrix accumulation. Requires precise reimplementation of the cross-element coupling logic.

5. **Buffer growth has a 128KB hard cap:** `FUN_0059B490` loops until `newLen >= 0x1f400`, then clamps. This prevents unbounded memory growth in string/file operations.

6. **VM page management uses custom linked list:** `FUN_00594AB4` owns a linked list at `PTR_LOOP_005e796c` with stride -0x1000 per page entry and status byte at +0x2010. This is a custom virtual memory manager on top of `VirtualAlloc`/`VirtualFree`.

7. **Geometric growth multiplier is 8×:** When dynamic buffer needs to grow, the new size is `oldLen * 8`, not the typical 2×. This minimizes reallocations at the cost of higher peak memory.

8. **All MSVC CRT helpers are present:** Functions like `__aulldiv`, `__aullshr`, `__ftol2`, `__frnd`, `_strncpy` are included because Ghidra decompiled the entire binary. A modern reimplementation should use `<cmath>` and standard library equivalents.

9. **SEH unwind handlers are compiler-generated:** The ~60 `Unwind_0059XXXX` functions are MSVC artifacts for C++ exception handling with stack-allocated objects. A modern reimplementation using RAII and smart pointers will not need these.

10. **Random number generator is ring-buffer based:** `DAT_008aae70/DAT_008aae74` form a noise ring buffer consumed by `FUN_00448300`. The buffer is pre-filled (likely at startup) and advanced per read. Replace with `std::mt19937` or similar.

11. **Vertex stride is flag-dependent:** In `FUN_0055EBA0`, stride is 0x10 or 0x0c based on flag bit 0x800000 at `*(param_1+0x18)+0x14`. This matches D3D flexible vertex format (FVF) stride patterns.

12. **Timer has two modes:** `FUN_005564b0` supports direct `QueryPerformanceCounter` (bit 0) and alternate timer source (bit 1). Mode selection via `param_1[0x48]`. The alternate source likely handles timer wrapping or high-latency environments.

---

## Completeness

- Full specs written: ~25 major / ~5,400 total documented functions
- Thunks/empty stubs omitted: ~5,350 (mostly trivial: single-call wrappers, getters, SEH handlers, CRT helpers)
- Confidence: high (major structures and call chains captured; leaf functions follow uniform patterns)
