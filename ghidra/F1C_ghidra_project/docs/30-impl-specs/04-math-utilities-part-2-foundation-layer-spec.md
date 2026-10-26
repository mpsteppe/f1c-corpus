# Implementation Spec: Math Utilities — Part 2 (Foundation Layer)

Source: docs/20-math-utilities.md  |  Functions: ~1,414 (documented)  |  Date: 2026-07-15

---

## Overview

The Math Utilities Foundation Layer (Part 2) is the game engine's "standard library" — ~1,414 tiny reusable functions called by every other subsystem. Unlike dedicated subsystems (physics, renderer, AI), these functions have no single owner. They are scattered across the binary as inline helpers, vtable stubs, accessor methods, and glue code.

The system runs at any timescale — per-frame, per-tick, on init, or during shutdown — depending on the calling context. These functions are stateless leaf utilities: they read inputs from parameters, write results to output pointers, and never branch on game globals.

**Primary function clusters:**
- Memory & Container Management (~200 functions) — linked lists, ring buffers, merge sort, pool allocators
- 3D Math Library (~80 functions) — vector/matrix/quaternion ops, SIMD (SSE/3DNow!), spline interpolation
- Data Conversion (~60 functions) — float↔int, short↔float, pixel format, nibble decode
- CRT / Runtime Infrastructure (~100 functions) — `_nh_malloc`, `_longjmp`, TLS, stream I/O, locale
- SEH / Exception Handling (~70 functions) — MSVC compiler-generated unwind helpers
- String Manipulation (~40 functions) — path normalizer, sanitizer, hash, formatting
- Synchronization / Threading (~20 functions) — critsec, mutex, TLS, InterlockedDecrement
- UI Text Rendering (~25 functions) — multi-layer HUD text, timestamps, colored overlays
- Lookup / Search Algorithms (~30 functions) — linear search, stride arrays, hash tables, binary search
- Bitfield / Bit Array Operations (~20 functions) — bitmap clear, bit test, decode/enum conversion
- Configuration / Initialization (~80 functions) — constructor pattern, sentinel pattern, struct init
- Delegation / Callback Registration (~30 functions) — atexit-like via FUN_00587b3e, indirect thunks

**Data flow:**
- Inputs: struct pointers (param_1 = `this`), global float constants (DAT_0059eXXX), global state variables (DAT_008afea0 session time, DAT_007cd8c0 game command dispatch)
- Processing: pure arithmetic, data structure operations, format conversions
- Outputs: caller-provided output pointers, return values (0=success, -1=error)

---

## Data Structures

### Linked List Node (generic — 4 layouts commonly observed)

**Layout A** (singly-linked, used by ~50 functions):
```
+0x00  Key/ID     int32    Match key or pointer
+0x04  NextPtr    ptr      Next node in list
```

**Layout B** (doubly-linked, cleanup pattern):
```
+0x00  DataPtr    ptr      Pointer to data with vtable
+0x04  NextPtr    ptr      Next node
+0x08  Flags      byte     Cleanup flags (bit 0 = has vtable destructor)
```

### Simple Buffer Descriptor (param_2)
```
+0x00  CurrentPtr    int32*  Current write position
+0x04  Remaining     int32   Bytes remaining before flush
+0x28  BufferStart   ptr     Wrap target
+0x2c  BufferEnd     ptr     Wrap limit
+0x30  ReadPtr       ptr     Current read position
+0x34  EndPtr        ptr     Buffer end
+0x38  Callback      func    Optional callback function
+0x3c  CallbackCtx   ptr     Callback context
```

### Timer/Performance State (param_1)
```
+0x00  FrequencyLowPart   uint   QPC frequency low dword
+0x08  InvFrequencyScaled double scaling_constant / freq
+0x10  AccLow             uint   Accumulator low
+0x14  AccHigh            uint   Accumulator high
+0x18  CounterLow         uint   QPC init sample low
+0x1c  CounterHigh        uint   QPC init sample high
+0x20  LastSampleLow      uint   Copy of init low
+0x24  LastSampleHigh     uint   Copy of init high
+0x28  Acc/Overflow       uint   Zeroed
+0x48  Mode               uint   Timer mode flags (bit0=QPC, bit1=alternate)
```

### Thread-Safe Read Struct
```
+0xec  SharedValue    int      Value read under mutex
+0xf0  MutexHandle    HANDLE   Win32 mutex
+0xf4  WaitTimeout    DWORD    ms timeout
```

### Mutex Management Struct
```
+0x54  MutexHandle    HANDLE   Win32 mutex handle
+0x5c  MutexValidFlag byte     1 = mutex exists
```

### Linked List Container (destroy pattern)
```
+0x00  HeadPtr    ptr     Linked list head
+0x04  TailPtr    ptr     Linked list tail  
+0x08  Count      int     Node count
+0x0c  Capacity   int     Node capacity
```

---

## Global Variables Owned by This System

None — these are pure utility functions. They read constants and state but do NOT own globals. Key constants read:

| Global | Type | Description |
|--------|------|-------------|
| DAT_0059e440 | float | ZeroThreshold (~0.0f) — epsilon for physics comparisons |
| DAT_0059e43c | float | 1.0f constant |
| DAT_0059e450 | float | 0.5f constant |
| DAT_008aae70 | uint | Ring buffer counter (random noise index) |
| DAT_008aae74 | float[256] | Random noise table |
| DAT_008afea0 | double | Session time (read by FUN_0049ba10, FUN_004f9ad0) |
| DAT_007cd8c0 | ptr | Game command dispatch interface (read by FUN_0046e170, FUN_00477fa0) |
| DAT_008b8dc8 | ptr | Render context (read by FUN_004d7e40) |
| DAT_008d48f0 | various | Buddy allocator state (DAT_008d48f0/8/fc) |
| DAT_008d5a54 | various | Stack allocator state |
| DAT_008d41b8 | int | VM page counter |
| DAT_008d4920 | struct | Critical section array (stride 0x24) |

---

## Public API — Entry Points

These are the functions called from the game loop, module lifecycle, or system init — not leaf utilities called by other code:

### FUN_004F9AD0 — Time Accumulation Entry

**Inferred signature:** `void TimeAccumulate(void)`
**Called from:** Game::Post per-frame, AI/physics tick functions
**Called by:** ~10 callers from input, rendering, physics, and steward modules

**What it does:**
- Updates DAT_008afea0 (session time in seconds) and DAT_008afea8 from timer queries
- Calls FUN_00556730 for raw QPC timer reads
- Used as the engine's single authoritative time source

---

### FUN_0049DA60 — HUD Timestamp Render Entry

**Inferred signature:** `void HUDTimestampRender(void)`
**Called from:** OnScreen::Post per-frame

**What it does:**
- Renders formatted time overlay using DAT_005ccbc0 and DAT_007ce238 globals
- Calls FUN_00553070 for core text draw

---

### FUN_004A0DF0 — Session State Dispatch Entry

**Inferred signature:** `void SessionStateDispatch(int state)`
**Called from:** When session state changes (e.g., quali→race transition)

**What it does:**
- Dispatches game commands via DAT_007cd8c0+0x1c (virtual method at vtable offset 0x1c)
- Uses command IDs: 0x9, 0xb, 0xc, 0xd, 0xe, 0x10, 0x11, 0x12, 0x13, 0x15, 0x16, 0x18, 0x19, 0x1a, 0x1b, 0x24

---

### FUN_004DBC90 — 7-Layer Text Renderer

**Inferred signature:** `void MultiLayerTextRender(params...)`
**Called from:** UI rendering per-frame

**What it does:**
- Renders text in 7 layers with different colors
- Each layer calls FUN_004d7e40 with different color/mode params
- Colors are hardcoded (0xffff00 yellow, 0xffffff white)

---

### FUN_004DBE60 — 4-Layer Conditional Text Renderer

**Inferred signature:** `void ConditionalTextRender(params...)`
**Called from:** UI rendering per-frame

**What it does:**
- Renders text in 4 layers with conditional visibility
- Each layer calls FUN_0049c8f0 (text init) → FUN_004d7e40 (render) → FUN_00553070 (core draw)

---

### FUN_00596175 — Format String Dispatcher

**Inferred signature:** `int FormatDispatch(int formatID, ...)`
**Called from:** Multiple systems needing formatted output

**What it does:**
- Maps format IDs (1-8) to handler operations
- Handlers: float-to-string (FUN_0058bdcd), int64-to-string (FUN_0058bef0), decimal formatting (FUN_005955aa)
- Double-to-decimal string conversion via FUN_0058bccf

---

## Internal Call Graph

```
TimeAccumulate (FUN_004f9ad0)
  +-- FUN_00556730 — QPC timer read
  +-- Writes DAT_008afea0/008afea8

MultiLayerText (FUN_004dbc90)
  +-- FUN_004d7e40 (×6-7) — Text render with color/mode
        +-- FUN_00553070 — Core text draw

TextRender (FUN_004dbe60)
  +-- FUN_0049c8f0 — Text buffer init
  +-- FUN_004d7e40 — Text render
        +-- FUN_00553070 — Core text draw

Linked list destroy (FUN_005819c0)
  +-- Virtual destructor at vtable+4 (per node)
  +-- FUN_00587bcf — free(node)

Merge sort (FUN_004c6810, FUN_00465d70)
  +-- Recursive split at midpoint
  +-- Merge with comparator
  +-- FUN_004c5d30 — Float comparator

SIMD normalize (FUN_00520fc6)
  +-- FUN_00529000 — sqrt approx (SSE)
  +-- Newton-Raphson refinement

SIMD 3DNow! (FUN_0052179f)
  +-- FUN_005215db — Packed float math

Constructor pattern
  +-- FUN_00507496(size, type) — allocation
  +-- vtable = PTR_FUN_005adXXX — vtable set

SEH Unwind
  +-- FUN_0059cXXX → FUN_00587bcf(EBP-N) — free stack object
  +-- FUN_0059c770 → FUN_005867b0 — linked list cleanup

FormatDispatch (FUN_00596175)
  +-- FUN_0058bdcd — float-to-string
  |     +-- FUN_00595621 — double parse → buffer
  |     +-- FUN_005955aa — decimal → string with carry rounding
  |     +-- FUN_0058be2e — final string render
  +-- FUN_0058bccf — direct double→decimal

File I/O delegation
  +-- FUN_0058803f — thread-safe read
        +-- FUN_0058c1b1 — lock stream
        +-- FUN_0058806e — raw read
              +-- FUN_0058c9b4 — buffer refill
        +-- FUN_0058c203 — unlock stream

Buddy allocator (FUN_0059416f)
  +-- Bitmap search (two-level)
  +-- Split/coalesce logic
  +-- FUN_00594478 — expand pool on OOM

Dynamic buffer (FUN_0059b490)
  +-- operator_new + memcpy + FUN_00587bcf (free)
  +-- Geometric growth (8× multiplier)
  +-- 128KB max cap

Thread-safe int read (FUN_00585770)
  +-- WaitForSingleObject(mutex)
  +-- Read value at +0xec
  +-- ReleaseMutex(mutex)

Mutex create (FUN_00586560)
  +-- CloseHandle(existing)
  +-- CreateMutexA(NULL, FALSE, NULL)
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0x0059e440 | Multiple | ZeroThreshold (~0.0f) — epsilon for comparisons |
| 0x0059e43c | Multiple | 1.0f constant |
| 0x0059e450 | Multiple | 0.5f constant |
| 0x01010101 | Render fill | Default render state fill value |
| 0xffff00 | UI text | Yellow text color |
| 0xffffff | UI text | White text color |
| 8× | FUN_0059b490 | Geometric growth multiplier for dynamic buffers |
| 128KB | FUN_0059b490 | Max dynamic buffer capacity |
| -1 | Multiple | Return value for error/not-found |
| 0 | Multiple | Return value for success |
| 32 | FUN_0059964a | Buffer size rounding alignment |
| 0x100 (256) | Lookup tables | Common table size (sine table, noise table) |
| 0x14 | TableLookupByIndex | Stride of driver data table |
| 0x68 (104) | Max grid entries | Vehicle grid iteration limit |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- DAT_0059e440 (ZeroThreshold) — from docs/12 — epsilon for physics comparisons
- DAT_008aae70 (RingBufferCounter) — from docs/12 — random noise index
- DAT_008afea0 (SessionTime) — from docs/12 — time source for time-dependent utilities
- DAT_007cd8c0 (GameCommandDispatch) — from docs/12 — command dispatch for session transitions
- DAT_008b8dc8 (RenderContext) — from docs/19 — renderer context for text rendering
- DAT_008d48f0/8/fc (BuddyAllocator) — from docs/20 — buddy allocator state
- DAT_008d4920 (CriticalSectionArray) — from docs/12 — thread sync primitives

**Calls into:**
- docs/08-file-formats.md: FUN_00587bcf (free/operator delete), FUN_00587b3e (atexit registration), FUN_0058806e (buffered read)
- docs/09-track-system.md: FUN_00587bcf (free)
- docs/19-renderer.md: FUN_00553070 (core text draw)
- docs/06-session-race-logic.md: FUN_0058b5d4 (memory reallocation)
- docs/20-math-utilities.md: Most functions are self-contained — they call no other system

**Called by:**
- docs/10-vehicle-physics.md: FUN_0056aa60 (matrix assembly), FUN_0056c740 (matrix multiply)
- docs/18-physics-dynamics.md: FUN_0056c640 (cross+normalize), FUN_0056bde0 (axis-angle rotation)
- docs/19-renderer.md: FUN_00566f40 (quaternion→3x3), FUN_0050a92d (vertex color pack)
- docs/02-ai-system.md: Random scaling functions
- docs/21-audio-network-internals.md: Buffer allocation, encoding helpers
- docs/01-engine-architecture.md: Timer reads, memory management, text rendering

---

## Reimplementation Notes

1. **Call graph is flat:** These functions rarely call each other. When they do, it's A→B delegation (not deep chains). The exception is the format string pipeline (4 deep) and SEH unwind handlers (2 deep).

2. **FUN_00587bcf is critical:** This is the most-called function in Part 2 (~500+ references). It wraps operator delete (free). Every destructor, cleanup, and teardown path calls it. Implement as `void operator delete(void* ptr)`.

3. **FUN_00587b3e is atexit registration:** ~30 functions register cleanup callbacks via this function. It's MSVC's `_atexit` equivalent — stores function pointers for deferred execution during DLL unload or process exit.

4. **Memory allocators are custom:** The buddy allocator (FUN_0059416f) uses a two-level bitmap with splitting/coalescing. The stack allocator (FUN_00587ac0) supports thread-safe push/pop. The dynamic buffer (FUN_0059b490) uses 8× geometric growth. These replace/corralent the CRT heap for performance-critical paths.

5. **SIMD math has two code paths:** SSE (FUN_00520fc6 — vector normalize with Newton-Raphson sqrt refinement) and 3DNow! (FUN_0052179f — packed float blend). The CPUID check in FUN_005567f5 selects which path to use.

6. **UI text rendering pipeline:** FUN_004d7e40 → FUN_00553070 is the core path. Colors are hardcoded. The 7-layer and 4-layer renderers (FUN_004dbc90, FUN_004dbe60) call the same core with different color/mode params.

7. **Linked list merge sort** appears in 3+ implementations (FUN_004c6810, FUN_004c2e20, FUN_00465d70, FUN_00566380). All use the same recursive split-at-midpoint pattern with different comparators (float, int, or string). The comparison key format: top 3 bits = type, bits 12-17 = sub-type, low 8 bits = priority.

8. **SEH unwind handlers** are MSVC compiler-generated. Each corresponds to a C++ try/catch with stack-allocated objects. They are not manually written game code. Pattern: read pointer at EBP±N, call FUN_00587bcf (free) or FUN_005867b0 (linked list cleanup).

9. **Constructor pattern:** FUN_00507496(size, type) allocates memory, then vtable = PTR_FUN_005adXXX. This pattern repeats identically for ~15 renderer/UI widgets. The sentinel pattern: fields alternating 0 and -1 with a vtable pointer.

10. **Bit operations:** The 96-bit bitmap operations (FUN_00595207, FUN_0059525d) use borrow-propagation for clear operations across dword boundaries. This is designed for large bit pool management, likely in the memory allocator.

---

## Completeness

- Full specs written: 15 clusters / ~1,414 documented functions
- Thunks/empty stubs omitted: ~50 (single-call wrappers, no-op stubs, SEH unwind handlers)
- Confidence: high — well-understood utility layer with clear patterns and no game-logic state
