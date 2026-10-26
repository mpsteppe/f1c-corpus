## System Overview

The Math Utilities subsystem is the engine's mathematical foundation — a collection of ~4,000 pure computation functions that perform vector/matrix/quaternion arithmetic, geometry operations, interpolation, and numeric conversions. Every other engine subsystem (physics, renderer, AI, audio) depends on these leaf functions. They are stateless: they read inputs from struct pointer parameters, write results to output pointers, and never branch on game globals (`SessionType`, `RacePhase`, etc.) or vehicle identity.

A secondary role of this subsystem is providing engine-wide infrastructure: MSVC CRT runtime helpers (`__aulldiv`, `__aullshr`, `__ftol`, `__frnd`), low-level memory allocators (buddy allocator, slab allocator, pool allocator), file I/O wrappers, string formatting/conversion, linked-list and tree data structures, thread synchronization primitives, SEH unwind handlers, and callback registration. These runtime utilities operate at the boundary between game code and the Windows OS layer, buffering the game engine from platform details.

The approximately 6,000 functions documented under this subsystem divide into two tiers: ~4,005 pure `math_util` leaf functions (no branching on game state) and ~1,794 `physics_math` functions that perform physics-related computation such as force accumulation, integration steps, and constraint solving. The latter category is documented fully in docs/18-physics-dynamics.md rather than here.

## Subsystem Structure

### Pure Vector/Matrix Math (0x0040XXXX range, ~2,000 functions)

The largest cluster. Functions operate on 3-component vectors (consecutive float/double reads at x/y/z offsets), 4×4 matrices (16 float reads/writes, no branching), and quaternions (4 floats + dot product + scale).

**Key functions:**
- `FUN_0056bde0` — 3×3 rotation matrix from axis-angle via Rodrigues formula + Euler angle extraction
- `FUN_0056c740` — 3×3 matrix multiply, double precision (9 explicit result elements)
- `FUN_0056c640` — 3D vector cross product + normalize (double precision)
- `FUN_00566f40` — 3×3 rotation matrix from quaternion
- `FUN_0056ec70` — matrix identity initialization (8-byte doubles)
- `FUN_0050c9a9` — 4-component bilinear interpolation
- `FUN_0053bde0` — 4-element weighted dot product
- `FUN_0055ee20` — light/environment reflection vector computation (virtual dispatch per vertex)

These are pure computation — no branching, no globals, single-entry single-exit. The CPU does the same work regardless of game state.

### MSVC CRT Runtime Helpers (0x00594XXX–0x0059DXXX, ~400 functions)

Compiler intrinsic implementations and runtime support functions linked from MSVCRT. These are identical across all MSVC-compiled games of this era.

**Key functions:**
- `FUN_00594ff0` — `__aulldiv`: 64-bit unsigned integer division
- `FUN_0058a870` — `__aullshr`: 64-bit unsigned shift right
- `FUN_0058850f` — `__ftol2`: float-to-long with SSE/FPU rounding
- `FUN_00591cf3` — `__frnd`: extended-precision rounding (x87 ROUND)
- `FUN_0058dce5` — `__fload_withFB`: float load with NaN/infinity classification
- `FUN_0059325D` — CRT heap initialization
- `FUN_00593446` — CRT low-level I/O dispatcher
- `FUN_00587DD0` — `_strncpy`: standard C strncpy

These functions contain no game logic. They are included because Ghidra decompiled the executable as a whole, and they appear in the `decompiled_full/` corpus.

### Memory Management (0x0058XXXX–0x0059XXXX, ~200 functions)

Custom memory allocators supplementing the CRT heap. Used for performance-critical allocation patterns (small fixed-size blocks, temporary stack frames, page granularity).

**Key functions:**
- `FUN_0059416f` — buddy/slab allocator: bitmap-indexed free list, two-level bitmap search, splitting/coalescing, size-class linked lists
- `FUN_0059B490` — dynamic buffer reallocation: geometric growth (8× multiplier), 128KB max cap, operator_new + memcpy + free
- `FUN_00587ac0` — stack-based memory allocator push: thread-safe, capacity check, reallocation via FUN_0058b5d4
- `FUN_00594AB4` — OS virtual memory page free loop: linked list of allocation blocks, VirtualFree per page, live page counter at DAT_008d41b8
- `FUN_00595801` — file handle table slot allocator: bitmap search, block expansion
- `FUN_00582650`, `FUN_00582a10` — pool allocator destructors: free busy nodes + free list with virtual dispatch

**Data flow:** These allocators manage global state (`DAT_008d48f0/DAT_008d48f8/DAT_008d48fc` for buddy allocator, `DAT_008d5a54/DAT_008d5a50` for stack allocator, `DAT_008d41b8` for VM page counter) and are called from file I/O, string processing, and renderer resource management.

### File I/O Wrappers (0x0058XXXX–0x0059XXXX, ~150 functions)

Buffered file read/write layer with text/binary mode handling, codepage conversion, and handle table management.

**Key functions:**
- `FUN_0058806e` — buffered file read: intermediate buffer for unbuffered reads, partial read handling
- `FUN_0058e290` — WriteFile wrapper with text-mode `\n`→`\r\n` conversion for pipes
- `FUN_0059b650` — file handle duplication via `DuplicateHandle`
- `FUN_0058c824` — file position calculation with CR/LF line-ending translation
- `FUN_0059bbd9` — file putc with buffer management (text/binary, Unicode-aware)
- `FUN_0058e22b` — file write with handle validation (slot check in handle table)
- `FUN_0059c30e` — file stream byte read with buffer refill via FUN_0058c9b4
- `FUN_00599ed6` — stream write with encoding/translation: Unicode BOM, codepage conversion, virtual codec dispatch

### String & Numeric Formatting (0x0058XXXX–0x0059XXXX, ~120 functions)

Integer-to-string, float-to-string, decimal rounding, locale-aware formatting. Feeds the UI system's text rendering pipeline.

**Key functions:**
- `FUN_0058bdcd` — float-to-string with sign, width, and precision
- `FUN_0058bef0` — int64-to-string + screen position draw (combines FUN_00595621 + FUN_005955aa + FUN_0058bf45)
- `FUN_005955aa` — decimal string formatting with carry rounding ('9'→'0' + increment)
- `FUN_0058bccf` — double-to-decimal string (CRT float-to-string)
- `FUN_00596175` — format string dispatch: maps format IDs (1-8) to handler operations
- `FUN_0058c674` — character encoding conversion via lookup table + multibyte fallback
- `FUN_0058b465` — case-insensitive char conversion: ASCII toupper or locale-aware dispatch via FUN_0058b4d4

### Data Structures: Linked Lists & Trees (scattered, ~150 functions)

Generic linked-list and tree node manipulation, merge-sort, keyed search, node pools.

**Key functions:**
- `FUN_00566380` — linked-list merge-sort: recursive split at midpoint, merge with comparison
- `FUN_005664a0` — recursive merge-sort on singly-linked list
- `FUN_00565bb0` — list comparison dispatch: mode 1 (string compare), mode 2/3 (FileTime compare)
- `FUN_005832e0` — linked list node removal by key (doubly-linked, optional flag clear)
- `FUN_00582b10` — linked list element removal with sub-object cleanup via FUN_005867b0/FUN_00587bcf
- `FUN_00547670` — categorized linked list append: flag-based counter selection
- `FUN_00549110` — recursive node deletion with shutdown check and refcount
- `FUN_0058a55a` — binary interval search: backward walk through 0x14-stride interval array, N-match count
- `FUN_00564ab0` — generic array search with callback predicate and configurable stride

### Threading & Synchronization (scattered, ~50 functions)

Win32 synchronization wrappers, thread-safe I/O, queue-user-APC, thread mailbox.

**Key functions:**
- `FUN_005862c0` — Win32 mutex creation with handle management (CloseHandle existing, CreateMutexA)
- `FUN_0057acb0` — queue user callback via `QueueUserAPC` (async thread callback)
- `FUN_0058a32a` — LOCK/UNLOCK around indirect call via jump table
- `FUN_0059b092` — thread-safe I/O wrapper: `InterlockedIncrement` + critsec + dispatch
- `FUN_00585130` — thread mailbox: signals completion event, dispatches callback to main thread

### MSVC SEH Unwind Handlers (0x0059CXXX–0x0059DXXX, ~60 functions)

Compiler-generated exception handling trampolines that free stack-allocated objects during C++ exception unwinding. Each is a trivial wrapper reading a pointer from a fixed offset on `unaff_EBP` and calling `FUN_00587bcf` (operator delete).

**Key functions:**
- `Unwind_0059c684` — frees pointer at EBP+8
- `Unwind_0059cd1e` — frees pointer at EBP-0x10
- `Unwind_0059c770` — thunk to FUN_005867b0 (linked list cleanup)
- `Unwind_0059d594` — calls `exception::~exception()` during unwind

These are not meaningful for game-logic understanding — they are MSVC compiler artifacts.

### OS/Platform Wrappers (scattered, ~80 functions)

Thin wrappers around Win32 API calls for environment query, hardware detection, locale, and time.

**Key functions:**
- `FUN_005567f5` — CPU feature detection via CPUID: EFLAGS ID bit toggling, RDTSC timestamp, vendor string
- `FUN_00592dfa` — environment block via `GetEnvironmentStringsW/A`, Unicode→MultiByte conversion
- `FUN_00597e4f` — locale info query: wraps `GetLocaleInfoW/A` with Unicode/ANSI detection
- `FUN_005565b0` — high-precision timer: `QueryPerformanceCounter` wrapper with 64-bit tick delta and frequency normalization
- `FUN_00564c70` — Base64 decode (4 chars→3 bytes)
- `FUN_00595135` — DirectDraw surface flag translation (DDSD flags 0x1/0x2/0x4/0x8/0x10/0x30000/0x40000/0x80000)

### Callback & Event Registration (~40 functions)

Tiny wrapper functions that register cleanup or notification callbacks via `FUN_00587b3e`. Each is 5-15 bytes, typically:
```c
void FUN_0053c150(void) { FUN_00587b3e(&LAB_0053c160); }
```
Examples: FUN_00586ee0, FUN_00587aa0, FUN_0053c150, FUN_0054eac0, FUN_00534ac0.

### Renderer-Adjacent Math (scattered in 0x0050XXXX range, ~60 functions)

Texture creation, pixel format handling, color conversion, image downscaling. These functions are pure computation but their outputs feed the D3D render pipeline.

**Key functions:**
- `FUN_00562250` — texture creation wrapper: allocate + init width/height/format
- `FUN_0055eb30` — vertex color modulation: packed short multiply with saturation, per-channel RGBA blend
- `FUN_0055EBA0` — 3D lighting/reflection vector compute: per-vertex direction + specular reflection
- `FUN_00501992` — DDS texture header parsing + pixel loading
- `FUN_00503f75` — 2×2 box downscale (pixel averaging filter)
- `FUN_005111d3` — JPEG marker reader from byte stream
- `FUN_0050c9a9` — 4-component bilinear interpolation

### Compression (scattered, ~20 functions)

- `FUN_0051a5ea` — Huffman/compression tree builder: symbol frequency→code length→decode table (0x100 entries)
- `FUN_0052e550` — bounds-checked byte setter (9-element array guard)

## Data Flow

**Inputs to math utilities:**
- Struct pointers from caller (param_1, param_2, etc.) — the caller owns the data
- Global constants (`_DAT_0059e430` zero-threshold, `_DAT_0059e43c` 1.0f, `_DAT_0059e450` 0.5f) — hardcoded float constants used as epsilon/bias values in geometry and physics math
- Random ring buffer (`DAT_008aae70/DAT_008aae74`) — consumed by `FUN_00448300` and `FUN_0054b450` for random-noise operations

**Transformation pipeline (typical):**

1. Caller (physics solver, AI pathfinder, renderer) passes pointers to vector/matrix structs
2. Math utility reads consecutive struct fields as float/double operands
3. Computes result via pure arithmetic (no branching)
4. Writes result to output pointer

No chaining through system-global intermediate buffers — each call is self-contained.

**Outputs:**
- Written to caller-provided output struct pointers (no system-global accumulation)
- Some write to caller struct fields at known offsets (e.g., +0x14 for scaled random result in FUN_00448300)
- Memory allocators write to global pointer tables (DAT_008d48f0, DAT_008d41b8, etc.)

**Interfaces with other systems:**
- **Physics (docs/10, 18):** Vector math functions compute tire forces, suspension displacement, aerodynamic loads. Physics callers provide vehicle struct pointers, math utilities compute on double-precision fields at offsets like +0x1330 (LifetimeAvg), +0x1338 (LifetimeVar).
- **Renderer (docs/19):** 4×4 matrix and quaternion operations driven by view/projection transforms. Vertex color modulation feeds D3D vertex buffers.
- **AI (docs/02):** Random scaling of ability parameters (QualifyingAbility +0x1130, RaceAbility +0x1138).
- **Audio (docs/21):** Buffer allocation and encoding helpers for sound stream processing.
- **OS/Platform:** CRT helper functions invoked by almost every compiled C++ translation unit (operator new, memcpy, float conversions).

## Key Entry Points

Math utilities have no single entry point — they are called from every engine subsystem. The notable callers that invoke large numbers of math utilities are:

- **Physics integration tick** (called 60-300×/second): invokes vector math, force accumulation, matrix solves. Large dense function `FUN_0056aa60` (~2922 bytes) performs a multi-phase finite-element style matrix assembly with 22 double-precision variables and cross-element coupling — likely the suspension/chassis compliance solver.
- **Renderer per-frame update:** calls 4×4 matrix multiply (`FUN_0056c740`), quaternion transform (`FUN_00566f40`), vertex transforms, color packing. `FUN_0055EBA0` calculates per-vertex lighting vectors.
- **File loader** (scene load, setup load): calls CRT wrappers, buffer allocators, string formatters. `FUN_0058c824` adjusts file positions for line-ending translation during `.scn`/`.gdb` file parsing.
- **SEH frame teardown** (any exception): calls Unwind_ handlers that free stack objects.
- **Initialization** (startup): calls `FUN_0059325D` (CRT heap init), `FUN_005567f5` (CPUID), `FUN_00592dfa` (environment), `FUN_005565b0` (timer calibration).

## Call Graph Summary

```
PhysicsIntegration (docs/18)
  → FUN_0056aa60 (matrix assembly, ~2922B, double-precision finite-element solve)
    → multiple sub-blocks for 3 constraint groups: 0x22c, 0x234, 0x23c counts
    → reads from param_1+0x228 (matrix blocks), writes coupled results
  → FUN_0056c640 (vector cross+normalize)
  → FUN_0056bde0 (axis-angle rotation matrix)

RendererTransformSet (docs/19)
  → FUN_00566f40 (quaternion-to-3x3)
  → FUN_0056c740 (3x3 multiply)
  → FUN_0050a92d (vertex color pack RGB→16-bit)
  → FUN_0055EBA0 (per-vertex reflection, virtual-dispatch per vertex)

CRT FormatString
  → FUN_00596175 (format ID→handler dispatch)
    → FUN_0058bdcd (float-to-string, double→decimal)
      → FUN_00595621 (double parse→buffer)
      → FUN_005955aa (decimal→string with carry rounding)
      → FUN_0058be2e (final string render)
    → FUN_0058bccf (direct double→decimal)

FileRead (docs/08)
  → FUN_0058806e (buffered read)
    → FUN_0058c9b4 (buffer refill)
  → FUN_0058e22b (write with handle validation)
    → FUN_0058e290 (WriteFile + \n→\r\n conversion)

MemoryAlloc
  → FUN_0059416f (buddy allocator)
    → FUN_00594478 (expand pool on OOM)
  → FUN_0059B490 (dynamic buffer realloc)
    → operator_new + memcpy + FUN_00587bcf (free)

SEH unwind (when exception thrown)
  → Unwind_0059c684 → FUN_00587bcf(EBP+8)
  → Unwind_0059cd1e → FUN_00587bcf(EBP-0x10)
  → Unwind_0059c770 → FUN_005867b0 (linked list cleanup)
```

## Part 2 — Utility Foundation Layer

## System Overview

This document catalogs ~1,414 leaf/small utility functions from across the entire F1 Challenge 99-02 engine. Unlike dedicated subsystems (physics, renderer, AI), these functions represent the "standard library" of the game — tiny reusable operations called by virtually every other system. They are not owned by a single module but are scattered across the binary as inline helpers, vtable stubs, accessor methods, and glue code.

The functions here serve as the **foundation layer** of the engine: memory management wrappers, 3D vector math, linked list operations, data format conversion, CRT stubs, SEH unwind handlers, string manipulation, and simple accessor/getter patterns. They execute in any context — per-frame, per-tick, on init, or during shutdown — and typically have no global state dependencies of their own. The system they form is not a pipeline but a **toolkit**: any higher-level function can call these utilities without going through a central dispatcher.

## Subsystem Structure

The 1,414 functions cluster into ~15 logical groups. The largest are cataloged here; hundreds of additional trivial getters/setters/stubs are omitted for brevity.

### Memory & Container Management (~200 functions)

The largest single cluster. Operations on singly-linked and doubly-linked lists dominate: node creation, append/prepend, removal by key, recursive merge sort (FUN_004bb2e0), list destruction with sub-object cleanup, and ring buffer read/write (FUN_0057b630, FUN_00516531). Multi-level allocators (FUN_005276C5, FUN_00537070) allocate header+data+work buffers through virtual allocator callbacks. FUN_004bafc0 builds linked lists of 0x7f0-byte data blocks in a pool pattern. The cleanup pattern `FUN_004b0170 (release) + FUN_00587bcf (free)` recurs across ~50 destructor functions.

### 3D Math Library (~80 functions)

Pure math leaf functions: vector addition (FUN_004ec020, FUN_004ed710), subtraction (FUN_004EA930), cross product (FUN_004ed750), dot product, 2D cross/perp-dot (FUN_0054ee90). Matrix operations: quaternion-to-3x3 (FUN_00566f40), identity init (FUN_0056ec70), 3x3 transform (FUN_004e23d0), Y-axis rotation (FUN_0050d57f). Spline interpolation: cubic Bezier (FUN_0050c0a6), cubic Hermite (FUN_0050c15e, FUN_004d6830), bilinear (FUN_0050c23c). SIMD variants use 3DNow! (FUN_0052179f, FUN_00528f00) and SSE (FUN_00520FC6) for vector normalization with Newton-Raphson refinement.

### Data Conversion (~60 functions)

Float-to-int conversion via `__ftol` (dozens of callers), float-to-short with clamping (FUN_004b2750), short-to-float unpack with scaling (FUN_004b2580, FUN_004b2800), nibble-to-float decode (FUN_0051512c), pixel format conversion RGB↔BGR (FUN_005123e0) and quantized (FUN_00515303), color packing to 24-bit RGB (FUN_005423e0), hex string parsing (FUN_004cad30), FourCC sound format decoding (FUN_005006a4).

### CRT / Runtime Infrastructure (~100 functions)

MSVC C Runtime stubs and wrappers: `_nh_malloc` (FUN_0058a947), `malloc` wrapper (FUN_0058a935), `_longjmp` (FUN_0058a770), `__exception` destructor (FUN_0059bfa0), `type_info` destructor (FUN_0059baa3), stream `getc` with underflow (FUN_00589fcc), stream buffer lock (FUN_0058c1b1). TLS management (FUN_0058e0c7, FUN_005884e0). 128-bit integer addition (FUN_00597568). FPU control word queries (FUN_00567740, FUN_00591e66). Locale management with thread-safe refcounting (FUN_00598c1c).

### SEH / Exception Handling (~70 functions)

MSVC Structured Exception Handling unwind helpers. Each thunks to a cleanup function (list destructor, free of stack variable, `CloseHandle`, or `exception::~exception`). Pattern: FUN_0059cXXX / Unwind_0059XXXX → FUN_00587bcf (free stack object at EBP-N) or FUN_00583ae0 (linked list destruction). Generated by MSVC compiler for C++ try/catch blocks with stack-allocated objects.

### String Manipulation (~40 functions)

String shift by offset (FUN_0058c0d0), path backslash normalizer (FUN_00421890), file extension stripper (FUN_0047beb0), character sanitization (FUN_00568560), wide-string linked-list search (FUN_00559760, FUN_00544f50), hash computation (FUN_005645b0), char-to-index mapping A-Z (FUN_0049a330), string copy with bytewise OR transform (FUN_0057a070), locale-aware formatting (FUN_00595621).

### Synchronization / Threading (~20 functions)

Critical section enter/leave by index (FUN_0058dfea, FUN_0058e04b), stream buffer lock (FUN_0058c1b1), mutex-protected field write (FUN_005857c0), TLS get/set wrappers, InterlockedDecrement usage (FUN_005487a0). `_Gninc` stream buffer pointer increment (FUN_0059a418).

### UI Text Rendering (~25 functions)

Multi-layer HUD/text rendering: FUN_0049da60 (timestamped overlay), FUN_004dbc90 (7-layer text with colors), FUN_004dbe60 (4-layer conditional text), FUN_004d7e40 (UI text with scale), FUN_004dbde0 (text+shadow). All use FUN_00553070 as the core render call with FUN_0049cXXX string buffer management functions. Colors are hardcoded (0xffff00 yellow, 0xffffff white).

### Lookup / Search Algorithms (~30 functions)

Linear searches: strided array with stride 0xA0 (FUN_0040ad60), stride 0x6C (FUN_004cf010), stride 0x9 (FUN_00500680). Linked list string searches (FUN_005679c0, FUN_00547920). Hash table bucket chain lookup (FUN_0049a360). Binary tree/trie traversal (FUN_005477f0). Recursive tree search (FUN_0054bc60). ID-to-value tables (FUN_0051ca1, FUN_0059750a). Nearest-neighbor search by float distance (FUN_0040acd0).

### Bitfield / Bit Array Operations (~20 functions)

Bit set/clear (FUN_00586f70), 96-bit bitmap clear with borrow propagation (FUN_00595207, FUN_0059525d), bit range test across dwords (FUN_005951be), bitmask generation from bit array (FUN_00586de0), bit-packed decode via lookup table (FUN_00597cc0, FUN_00512850), bit flag decode to enum (FUN_0051cc6), bitfield extract/set at specific positions (FUN_004b2b00, FUN_004b2b60, FUN_004b2b80).

### Configuration / Initialization (~80 functions)

Two dominant patterns: (1) **Constructor pattern**: `FUN_00507496(param_2, size, 1) + vtable = PTR_FUN_005adXXX` — used by ~15 renderer/UI widget constructors (FUN_0050ab19, FUN_0050ae22, etc.). (2) **Sentinel pattern**: `[1]=0, [2]=0xFFFFFFFF` alternating zero/-1 with vtable — used by ~20 object constructors (FUN_0048a8f0, FUN_004b1a30, FUN_004b1a50). Large struct zero-inits with fixed float defaults (FUN_005ca430, FUN_0053b130).

### Delegation / Callback Registration (~30 functions)

Thin wrappers calling `FUN_00587b3e(&LAB_XXXXXXXX)` — atexit-like static registration for module init/deinit callbacks (FUN_00401090, FUN_00414200, FUN_00421480, etc.). Indirection thunks via global function pointer tables DAT_005d78XX (FUN_0050dd3a, FUN_0050dff5, FUN_0050e198). These form the engine's plugin/callback dispatch mechanism.

## Data Flow

These utility functions operate on data passed by caller through these channels:

1. **param_1 (struct pointer)**: The dominant pattern — ~80% of functions take a struct pointer in param_1 (unaff_EBX/ESI/EBP in register-rich Ghidra output). They read/write fields at fixed offsets (+0x08, +0x14, +0x30, etc.) without owning the struct. This is standard C++ member function convention (the `this` pointer).

2. **Global constants (DAT_0059eXXX)**: A set of ~30 global float constants (ZeroThreshold 0x0059e440, physics bounds, scale factors) are read by math utilities. These serve as the engine's "magic number" repository — all hardcoded, never modified at runtime.

3. **Global state variables (DAT_007cXXXX, DAT_008bXXXX)**: A smaller number of functions read global state: DAT_008afea0 (session time, FUN_0049ba10, FUN_004f9ad0), DAT_007cd8c0 (game command dispatch, FUN_0046e170, FUN_00477fa0), DAT_008b8dc8 (render context, FUN_004d7e40). These represent the boundary between pure utility and game-logic-aware code.

4. **Output parameters**: Functions like FUN_00406a90, FUN_0054b4a0, FUN_00456080 write results through caller-provided output pointers (param_2, param_3). This is a C-style "return multiple values via out-params" pattern.

5. **Return value**: Simple getters return the field value directly. Many return status codes: 0 = success, -1 = error, 0x101 = some special condition.

## Key Entry Points

Most functions in this document are **leaf utilities** — they are called by other functions, not the other way around. True entry points (called from the game loop or module init) are few:

- **FUN_004f9ad0** — Time accumulation entry. Called per-tick to update DAT_008afea0/008afea8 from timer queries via FUN_00556730.
- **FUN_0049da60** — HUD timestamp render entry. Renders formatted time overlay each frame with DAT_005ccbc0 and DAT_007ce238 globals.
- **FUN_0049e170** — Batch format string display entry. 14-pair format+render sequence for UI text output.
- **FUN_004a0df0** — Session state dispatch entry. Called when session state changes, dispatches game commands via DAT_007cd8c0+0x1c.
- **FUN_00464600** — Conditional scene processing entry. Called per-frame when DAT_007ce260 (scene active flag) is non-zero.
- **FUN_0059c4e6** through **FUN_0059d594** — SEH unwind handlers driven by C++ exception propagation, not explicit game code.

## Call Graph Summary

The call graph is **almost entirely flat** — these functions call into each other rarely, and when they do, it's a simple A→B delegation. Key call chains:

- **Linked list destruction chain**: `FUN_0049af30 → FUN_00587bcf (free each node)` or `FUN_0065ed50 → FUN_00587bcf`. The same FREEDEALLOC (FUN_00587bcf) is the most-called function in the entire document (~500+ references).

- **3D math → SIMD**: `FUN_00520FC6 (SSE normalize) → FUN_00529000 (sqrt approx)` and `FUN_0052179f (3DNow! blend) → FUN_005215db (packed math)`. SIMD entry points call into the packed floating-point primitives.

- **UI text render call chain**: `FUN_004dbe60 → FUN_0049c8f0 (text init) → FUN_004d7e40 (render) → FUN_00553070 (core draw)`. The 7-layer renderer FUN_004dbc90 calls FUN_004d7e40 six times with different color/mode params.

- **Constructor chain pattern**: `FUN_005669(X) → FUN_00507496 (size+type) → vtable = PTR_FUN_005adXXX`. This pattern repeats identically for ~15 renderer/UI widgets.

- **File I/O delegation**: `FUN_0058803f (thread-safe read) → FUN_0058c1b1 (lock) → FUN_0058806e (raw read) → FUN_0058c203 (unlock)`. Stream reads wrap locking around a raw read function.

- **SEH unwind chains**: `[C++ code] → exception → FUN_0059cXXX → FUN_00587bcf (free) or FUN_0058XX (cleanup)`. These are compiler-generated, not manually written.

---

# Math Utilities — Index

Pure math functions used by physics, renderer, and AI subsystems.
These are leaf functions with no game-logic globals or state access.

This file is an index only — individual entries live in
`decompiled_full_index.md` (triage table). No full `## FUN_` entries
are written here unless a function turns out to have game-logic connections.

---

## Categories (from Haiku triage)

| Category | Count | Description |
|----------|-------|-------------|
| math_util | ~4,005 | Vector/matrix ops, quaternion math, interpolation, sqrt/trig |
| physics_math | ~1,794 | Force computation, integration steps, constraint solving |

---

## Common Patterns

- **3-component vector ops:** read x/y/z at consecutive offsets, write result
- **4x4 matrix multiply:** 16 float reads, 16 float writes, no branching
- **Quaternion normalize/multiply:** 4 floats, dot product + scale
- **Lerp/slerp:** two inputs + blend factor, one output
- **Cross product:** 3 multiplies, 3 subtracts

These functions take struct pointers but never check game globals, session state,
or vehicle identity. They are pure computation.

---

## FUN_0041ef40 — Object Comparison with Tiebreak

Source: utility. Compares objects by +0x19c, ties broken by random.

**Key logic:**
- Returns smaller +0x19c value
- On equal: up to VehicleCount random draws, return winner or draw

**Globals:** DAT_005c329c

**Calls:** FUN_0041efe0

**Moddability:** pure utility

---

## FUN_004b33b0 — ProgressBarEventEncode

Source: math_utilities. Encodes parameters into hash/key for progress bar.

**Key logic:**
- Packs SessionType + param_2..7 into key integer
- Stores secondary value, sets sentinel

**Moddability:** N/A — utility

---

## FUN_004144c0 — TableLookupByIndex

Source: utility. Returns pointer from table at stride 0x14 by index.

**Key logic:**
- Reads `DAT_005bf9b0 + param_1 * 0x14`
- Single read, no branching, no validation

**Moddability:** pure utility

---

## FUN_00448300 — RandomScaledValue

Source: math_utilities. Applies random noise multiplier to float at param_1+8.

**Key logic:**
- Draws random from ring buffer (`DAT_008aae70`, `DAT_008aae74`)
- Multiplies param_1[2] (at +8) by random value
- Stores at param_1+0x14

**Globals:** DAT_008aae70, DAT_008aae74 (random ring buffer)

**Moddability:** pure utility — random scaling

---


## FUN_00596100
- Address: 0x00596100
- Size: — (FILE NOT FOUND)
- Lines: —
- Category: MISSING
- Algorithm/Purpose: FILE NOT FOUND in decompiled_full
## FUN_0059416f @ 0x0059416f — 777 bytes

**Signature:** `int * FUN_0059416f(uint *param_1)`

**Analysis:** Custom memory allocator (buddy allocator or slab allocator). Manages a bitmap-indexed free list via DAT_008d48f0/DAT_008d48f8/DAT_008d48fc globals. Allocates fixed-size blocks by searching a two-level bitmap for free slots, splitting/coalescing blocks. Tracks size classes with linked lists (prev/next at offsets 4, 8). Modifies bitmap bits on alloc/free. Returns pointer to usable memory. Handles out-of-memory by calling FUN_00594478 to expand.

```c
int * FUN_0059416f(uint *param_1)
{
  // Bitmap search for free slot matching requested size
  // Update free lists and bitmap
  // Return aligned pointer to allocated block
}
```
## FUN_00587DD0 � MSVC CRT _strncpy

Source: MSVC CRT library | Confidence: high
Standard C strncpy implementation from Visual Studio 1998/2003.

**Key logic:**
- Copies up to _Count characters from _Source to _Dest
- Null-pads remainder of _Dest
- Optimized for aligned word copying
- Handles overlapping and edge cases per C standard

**Moddability:** N/A (CRT function)

<!-- target: docs/08-file-formats.md -->

## FUN_0058c824 @ 0x0058c824 — 400 bytes

**Signature:** `ulonglong FUN_0058c824(char *param_1)`

**Analysis:** File position calculation with line-ending translation. Computes logical file offset accounting for CR/LF conversion. Handles text mode (\n counting), binary mode, and Unicode detection. Uses file handle table (DAT_008d4920) for per-handle flags. Delegates to FUN_00595f11 for low-level seek/tell. Complex logic for partial buffer reads with embedded newlines. Returns 64-bit position offset.

```c
ulonglong FUN_0058c824(char *param_1)
{
  // Get file handle + mode flags from param_1 struct
  // If text mode: count \n in buffer for offset adjustment
  // Use FUN_00595f11 for raw position queries
  // Return adjusted 64-bit offset
}
```
## FUN_00550f70 @ 0x00550f70 — 384 bytes

**Signature:** `undefined4 __fastcall FUN_00550f70(uint *param_1)`

**Analysis:** Resource manager destructor. Two modes based on flag bit 2 vs bit 1. Mode bit 1: iterates array of ref-counted objects at param_1[4] (0x2c stride), decrements refcounts via FUN_005507d0, frees via FUN_00587bcf. Mode bit 2: iterates array of sub-arrays at param_1[6] (0xc stride), frees inner arrays then outer. Recursively cleans up nested resource structures.

```c
undefined4 __fastcall FUN_00550f70(uint *param_1)
{
  // Check mode flag (bit 0x1 vs 0x2)
  // Free all sub-resources
  // Free container itself
  return 0;
}
```
## FUN_00596a2e @ 0x00596a2e — 423 bytes

**Signature:** `BOOL FUN_00596a2e(DWORD param_1, LPCWSTR param_2, int param_3, LPWORD param_4, UINT param_5, LCID param_6)`

**Analysis:** Unicode string type classification with charset detection. Tests if system supports WideChar (GetStringTypeW) or falls back to ANSI (GetStringTypeA). When DBCS: converts wide to multi-byte via WideCharToMultiByte, then runs GetStringTypeA on the converted buffer. Handles codepage and locale selection (param_5/param_6 with defaults from globals DAT_008d3f48/DAT_008d3f38). Writes char type classification array to param_4. Returns BOOL success.

```c
BOOL FUN_00596a2e(DWORD param_1,LPCWSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6)
{
  // Detect system charset support (Unicode vs ANSI)
  // If DBCS: convert W->MB, then classify
  // If Unicode: direct GetStringTypeW
  // Write classification to param_4
}
```
## FUN_005666b0 @ 0x005666b0 — 247 bytes

**Signature:** `undefined4 __thiscall FUN_005666b0(int *param_1, int param_2, char *param_3, int param_4)`

**Analysis:** String insertion into dynamic buffer. Inserts param_3 at position param_2. Handles reallocation via operator_new when capacity exceeded. Shifts existing content, copies new string. Returns 0 success, -1 out-of-range.
## FUN_00592dfa @ 0x00592dfa — 306 bytes

**Signature:** `LPSTR FUN_00592dfa(void)`

**Analysis:** Environment block retrieval via GetEnvironmentStringsW/A. Detects Unicode vs ANSI support. For Unicode: converts to MultiByte. Returns malloc'd copy. Frees original.
## FUN_005934e1 @ 0x005934e1 — 435 bytes

**Signature:** `void FUN_005934e1(int *param_1, int param_2, undefined4 param_3, undefined4 param_4, int param_5, char param_6, undefined4 param_7, undefined4 param_8)`

**Analysis:** Exception dispatcher with structured exception handling. Checks magic number (-0x1f928c9d/3/0x19930520) for exception record validation. Iterates handler table via FUN_0058a55a to find matching range, then dispatches to FUN_00593839. Falls through to FUN_00593694 or FUN_00593c9c based on param_6 flag.
## FUN_005677b0 @ 0x005677b0 — 314 bytes

**Signature:** `undefined4 __fastcall FUN_005677b0(int param_1, int param_2)`

**Analysis:** Gaussian elimination solver (linear algebra). Performs LU decomposition on a matrix. Pivots rows with zero diagonals, scales rows by reciprocal pivot. Eliminates below-diagonal entries. Operates on doubles stored as flat array. Returns -1 if singular, 0 on success.
## FUN_00589e6c @ 0x00589e6c — 352 bytes

**Signature:** `int * FUN_00589e6c(int *param_1)`

**Analysis:** DateTime/timestamp conversion. Converts a time value (seconds-based) into broken-down components (second/minute/hour/day/month/year/day-of-week). Handles leap years (DAT_005e7760 adjustment), month boundaries, and weekdays. Modular arithmetic with 0x3c (60), 0x18 (24). Uses FUN_00592787/FUN_0059247a for normalization.
## FUN_00563870 @ 0x00563870 — 447 bytes

**Signature:** `int __fastcall FUN_00563870(int param_1, int param_2)`

**Analysis:** Three-phase device mode detection. State machine: phase 0 - reads device info (strncpy + FUN_00587f59 hash), stores results; phase 1 - reads more data into DAT_008cfa90 array; phase 2 - formats final output with path separators (0x5c). Calls FUN_00563a70 for raw reads, FUN_00564690 for string dup, virtual dispatch at offset +0x78.
## FUN_0058de2c @ 0x0058de2c — 304 bytes

**Signature:** `undefined4 FUN_0058de2c(int param_1, int param_2, double param_3, double *param_4)`

**Analysis:** Math boundary function — computes scalar for transcendental range reduction. Checks IEEE 754 special values (Inf, NaN, zero). Compares against constants _DAT_005b8cc8, _DAT_005b8c80. Returns status 0/1 and output value in param_4. Used by math library (likely pow/exp).
## FUN_00599ed6 @ 0x00599ed6 — 328 bytes

**Signature:** `uint __thiscall FUN_00599ed6(int param_1, uint param_2)`

**Analysis:** Stream write with encoding/translation. Handles Unicode byte order, buffer management, codepage conversion. Calls FUN_0059bbaf for char mapping, FUN_00588678 for file write with lock. Virtual dispatch for codec. Returns written count or 0xffff on error.
## FUN_0058806e @ 0x0058806e — 232 bytes

**Signature:** `uint FUN_0058806e(undefined1 *param_1, uint param_2, uint param_3, int *param_4)`

**Analysis:** Buffered file read. Reads param_3 elements of size param_2 into param_1 buffer. Uses intermediate buffer for unbuffered reads (FUN_0058c9b4). Handles partial reads.
```
## FUN_004c1660 @ 0x004c1660 — NOT FOUND
## FUN_005567f5 @ 0x005567f5 — 101 bytes

**Signature:** `undefined8 __fastcall FUN_005567f5(undefined4 param_1, undefined4 param_2, int *param_3, uint *param_4, undefined4 *param_5)`

**Analysis:** CPU feature detection via CPUID. Tests EFLAGS ID bit toggling. Uses RDTSC for timestamp. Returns CPUID vendor string. Core CPU detection.
## FUN_0055eb30 @ 0x0055eb30 — 104 bytes

**Signature:** `void __fastcall FUN_0055eb30(int param_1)`

**Analysis:** Vertex color modulation. Packed short multiply with saturation clamping. Uses DAT_008b6c20/DAT_008b8e40 as blend factors. Per-channel RGBA blend.
## FUN_0059b650 @ 0x0059b650 — 264 bytes

**Signature:** `uint FUN_0059b650(uint param_1)`

**Analysis:** File handle duplication via DuplicateHandle. Duplicates handle to new slot in file table.
## FUN_00595801 @ 0x00595801 — 291 bytes

**Signature:** `int FUN_00595801(void)`

**Analysis:** File handle table slot allocator. Searches bitmap for free slot, allocates new block if full.
## FUN_00597e4f @ 0x00597e4f — 275 bytes

**Signature:** `int FUN_00597e4f(LCID param_1, LCTYPE param_2, LPSTR param_3, int param_4, UINT param_5)`

**Analysis:** Locale info query. Wraps GetLocaleInfoW/A with Unicode/ANSI detection. Converts to MBCS.
```
## FUN_00591d88 @ 0x00591d88 — 193 bytes

**Signature:** `float10 FUN_00591d88(uint param_1, uint param_2, int *param_3)`

**Analysis:** Double-precision frexp (fraction + exponent). Decomposes IEEE 754 double into mantissa [0.5, 1.0) and integer exponent. Handles zero, denormals. Normalizes and calls FUN_00591d05 for final scaling.
## FUN_00594AB4 � OS Virtual Memory Page Free Loop

Source: OS memory manager | Confidence: high
Frees virtual memory pages from a linked list of allocation blocks. Decrements global page counter.

**Key logic:**
- Walk linked list starting at PTR_LOOP_005e796c
- For each node with +0x10 != -1 (has allocation):
  - Walk page entries (stride -0x1000, 0x3ff000 entries � 4095 pages)
  - If page status at +0x2010 == 0xf0 (freeable):
    - VirtualFree(address, 0x1000, MEM_RELEASE) � release page
    - Mark status = -1
    - DAT_008d41b8-- � decrement live page count
    - Update free list pointer at +0xc
    - If freed enough pages (param_1 count reached): break
  - If param_1 pages freed AND +0x18 == -1 (all pages free):
    - Check if all 0x400 page entries are -1
    - If yes: call FUN_00594a5e(puVar4) � free the whole block

**Globals:**
- PTR_LOOP_005e796c � linked list head for allocation blocks
- DAT_008d41b8 � live page counter

**Calls:** VirtualFree, FUN_00594a5e (free block)

**Moddability:** N/A (OS memory)

<!-- target: docs/08-file-formats.md -->

## FUN_00596175 @ 0x00596175 — 208 bytes

**Signature:** `void FUN_00596175(int param_1, int *param_2, ushort *param_3)`

**Analysis:** Format string dispatch. Maps format IDs (1-8) to handler ops. Calls FUN_005919da for conversion, FUN_00591727 for processing. Handles special cases for 0x10/0x16/0x1d modes. Fallback via FUN_00591c79.
## FUN_00582a10 @ 0x00582a10 — 248 bytes

**Signature:** `void __fastcall FUN_00582a10(undefined4 *param_1)`

**Analysis:** Pool destructor (complement to FUN_005828b0). Frees busy pool nodes with FUN_005867b0. Frees free pool with FUN_0058a5f7 callback. Handles linked list cleanup.
## FUN_0059c30e @ 0x0059c30e — 231 bytes

**Signature:** `undefined2 FUN_0059c30e(undefined4 *param_1)`

**Analysis:** File stream byte read. Manages buffer refill via FUN_0058c9b4. Handles text/binary mode flag checks. Returns one character (0xffff on EOF/error). Tracks buffer position.
```
## FUN_0058bb10 @ 0x0058bb10 — NOT FOUND
## FUN_00599560 @ 0x00599560 — 133 bytes

**Signature:** `undefined4 __thiscall FUN_00599560(int param_1, uint param_2, char param_3)`

**Analysis:** Reference-counted buffer management. Checks refcount at puVar2[-1]. Allocates buffer via FUN_0059964a. Decrements refcount on free. Flushes via FUN_005993af.
## FUN_00582650 @ 0x00582650 — 207 bytes

**Signature:** `void __fastcall FUN_00582650(undefined4 *param_1)`

**Analysis:** Pool destructor (complement to matching allocator). Frees busy nodes with virtual method call(1), free nodes with virtual method call(3). Linked list cleanup via FUN_00587bcf.
## FUN_005955aa @ 0x005955aa — 119 bytes

**Signature:** `void FUN_005955aa(char *param_1, int param_2, int param_3)`

**Analysis:** Decimal string formatting with rounding. Formats number into string with leading '0'. Handles carry rounding ('9' -> '0' + increment). Uses FUN_0058b130 for memcpy.
## FUN_005832e0 @ 0x005832e0 — 122 bytes

**Signature:** `undefined4 __thiscall FUN_005832e0(int *param_1, int param_2, char param_3)`

**Analysis:** Linked list node removal by key. Finds node matching param_2. Unlinks from doubly-linked list. Optionally clears flag. Calls virtual method if flag set. Frees via FUN_00587bcf.
## FUN_00595135 @ 0x00595135 — 137 bytes

**Signature:** `uint FUN_00595135(uint param_1)`

**Analysis:** DirectDraw surface flag translation. Maps DDSD flags (0x1, 0x2, 0x4, 0x8, 0x10, 0x30000, 0x40000, 0x80000) to internal representation.
## FUN_0055ed10 @ 0x0055ed10 — 264 bytes

**Signature:** `void __thiscall FUN_0055ed10(int param_1, int param_2, int param_3, int param_4)`

**Analysis:** Proximity/lights query. Checks octree-style linked list for nearby objects. Uses distance^2 <= radius^2 test. Collects up to 8 nearby items into array at param_3+0x110.
## FUN_0058b465 @ 0x0058b465 — 111 bytes

**Signature:** `int FUN_0058b465(int param_1)`

**Analysis:** Case-insensitive char conversion. If locale not set: ASCII-range toupper (0x40-0x5a -> +0x20). If locale set: thread-safe dispatch to FUN_0058b4d4 with critsec.
## FUN_00587ac0 @ 0x00587ac0 — 126 bytes

**Signature:** `undefined4 FUN_00587ac0(undefined4 param_1)`

**Analysis:** Stack-based memory allocator push. Checks capacity of stack at DAT_008d5a54/DAT_008d5a50. Reallocates via FUN_0058b5d4 if needed. Pushes param_1 value onto stack. Thread-safe via FUN_00589d6b/FUN_00589d74.
## FUN_0059b092 @ 0x0059b092 — 99 bytes

**Signature:** `undefined4 FUN_0059b092(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5)`

**Analysis:** Thread-safe I/O wrapper. Uses InterlockedIncrement/DAT_008d5a58 reentrancy guard. Dispatches to FUN_0059b0f5. Critsec protection.
## FUN_00596716 @ 0x00596716 — 93 bytes

**Signature:** `undefined4 FUN_00596716(undefined4 param_1, undefined4 param_2, undefined4 param_3)`

**Analysis:** Thread-safe I/O wrapper. Same pattern as 0x59b092. Dispatches to FUN_00596773 with critsec protection.
```
## FUN_0058e22b @ 0x0058e22b — 101 bytes

**Signature:** `undefined4 FUN_0058e22b(uint param_1, undefined4 param_2, undefined4 param_3)`

**Analysis:** File write with handle validation. Checks handle table for valid slot. Calls FUN_0058e290 for actual write. Handles error codes.
## FUN_00593e1b @ 0x00593e1b — 43 bytes

**Signature:** `uint FUN_00593e1b(int param_1)`

**Analysis:** Heap region lookup. Walks region table (stride 0x14). Checks if param_1 falls within 0x100000-byte region. Returns region base or 0.
## FUN_00556760 @ 0x00556760 — 45 bytes

**Signature:** `float10 FUN_00556760(int param_1)`

**Analysis:** Timer threshold gate. If param_1 within range of DAT_008b8e48, returns timer value from FUN_00556650. Returns 0.0 otherwise.
## FUN_00579f89 @ 0x00579f89 — 23 bytes

**Signature:** `undefined4 * __fastcall FUN_00579f89(int param_1)`

**Analysis:** Global pointer getter. Returns DAT_008d3984 for param_1==0, DAT_008d3980 for param_1==1. NULL otherwise.
## FUN_00589bf3 @ 0x00589bf3 — 40 bytes

**Signature:** `uint FUN_00589bf3(int param_1)`

**Analysis:** Character type query. If DBCS (DAT_005e6bd4 > 1): uses FUN_0058c674. Otherwise: table lookup into PTR_DAT_005e69c8.
## FUN_0058BC68 � Modulo Comparison / Heap Utility Check

Source: CRT heap utility | Confidence: high
Returns 1 if a value is less than a modulo remainder � memory/size boundary check.

**Key logic:**
- Returns 1 if _DAT_005b8c80 < (_DAT_005b8d48 % _DAT_005b8d50)
- Otherwise returns 0

**Globals:**
- _DAT_005b8c80, _DAT_005b8d48, _DAT_005b8d50 � CRT heap boundary globals

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0056aa60

```
// Function: FUN_0056aa60 @ 0056aa60
// Size (bytes): 2922

void __fastcall FUN_0056aa60(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  int iVar23;
  int iVar24;
  double *pdVar25;
  int iVar26;
  undefined4 local_a4;
  undefined4 local_58;
  undefined4 local_54;
  
  iVar26 = *(int *)(param_1 + 0x22c);
  local_54 = 0;
  if (0 < iVar26) {
    local_a4 = 0;
    do {
      iVar23 = *(int *)(param_1 + 0x230) + local_a4;
      cVar1 = *(char *)(iVar23 + 0x34);
      iVar2 = *(int *)(iVar23 + 0x30);
      dVar5 = *(double *)(*(int *)(param_1 + 0x230) + 0x28 + local_a4) *
              *(double *)(param_1 + 0x104) -
              *(double *)(iVar23 + 0x20) * *(double *)(param_1 + 0x11c);
      dVar6 = *(double *)(param_1 + 0x10c) * *(double *)(iVar23 + 0x28) -
              *(double *)(param_1 + 0x124) * *(double *)(iVar23 + 0x20);
      dVar7 = *(double *)(param_1 + 0x114) * *(double *)(iVar23 + 0x28) -
              *(double *)(param_1 + 300) * *(double *)(iVar23 + 0x20);
      dVar8 = *(double *)(iVar23 + 0x18) * *(double *)(param_1 + 0x11c) -
              *(double *)(param_1 + 0xec) * *(double *)(iVar23 + 0x28);
      dVar9 = *(double *)(param_1 + 0x124) * *(double *)(iVar23 + 0x18) -
              *(double *)(param_1 + 0xf4) * *(double *)(iVar23 + 0x28);
      dVar10 = *(double *)(param_1 + 300) * *(double *)(iVar23 + 0x18) -
               *(double *)(param_1 + 0xfc) * *(double *)(iVar23 + 0x28);
      dVar11 = *(double *)(param_1 + 0xec) * *(double *)(iVar23 + 0x20) -
               *(double *)(iVar23 + 0x18) * *(double *)(param_1 + 0x104);
      dVar12 = *(double *)(param_1 + 0xf4) * *(double *)(iVar23 + 0x20) -
               *(double *)(iVar23 + 0x18) * *(double *)(param_1 + 0x10c);
      dVar13 = *(double *)(param_1 + 0xfc) * *(double *)(iVar23 + 0x20) -
               *(double *)(param_1 + 0x114) * *(double *)(iVar23 + 0x18);
      if (local_54 < iVar26) {
        local_58 = local_a4;
        iVar26 = local_54;
        do {
          iVar23 = *(int *)(param_1 + 0x230) + local_58;
          dVar14 = (dVar6 * *(double *)(*(int *)(param_1 + 0x230) + 0x28 + local_58) -
                   dVar7 * *(double *)(iVar23 + 0x20)) + *(double *)(param_1 + 0xb4);
          dVar15 = dVar9 * *(double *)(iVar23 + 0x28) - dVar10 * *(double *)(iVar23 + 0x20);
          dVar16 = (dVar10 * *(double *)(iVar23 + 0x18) - dVar8 * *(double *)(iVar23 + 0x28)) +
                   *(double *)(param_1 + 0xb4);
          dVar17 = dVar12 * *(double *)(iVar23 + 0x28) - dVar13 * *(double *)(iVar23 + 0x20);
          dVar18 = dVar13 * *(double *)(iVar23 + 0x18) - dVar11 * *(double *)(iVar23 + 0x28);
          dVar19 = (dVar11 * *(double *)(iVar23 + 0x20) - dVar12 * *(double *)(iVar23 + 0x18)) +
                   *(double *)(param_1 + 0xb4);
          if (local_54 == iVar26) {
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
            *(double *)(iVar23 + iVar2 * 8) = dVar14 + *(double *)(iVar23 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar23 + iVar2 * 8) = dVar15 + *(double *)(iVar23 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar23 + 8 + iVar2 * 8) = dVar16 + *(double *)(iVar23 + 8 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            *(double *)(iVar23 + iVar2 * 8) = dVar17 + *(double *)(iVar23 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            *(double *)(iVar23 + 8 + iVar2 * 8) = dVar18 + *(double *)(iVar23 + 8 + iVar2 * 8);
            iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
LAB_0056b02e:
            pdVar25 = (double *)(iVar23 + 0x10 + iVar2 * 8);
LAB_0056b032:
            dVar19 = dVar19 + *pdVar25;
          }
          else {
            iVar3 = *(int *)(iVar23 + 0x30);
            dVar20 = dVar7 * *(double *)(iVar23 + 0x18) - dVar5 * *(double *)(iVar23 + 0x28);
            dVar21 = dVar5 * *(double *)(iVar23 + 0x20) - dVar6 * *(double *)(iVar23 + 0x18);
            iVar4 = *(int *)(param_1 + 0x228);
            dVar22 = dVar8 * *(double *)(iVar23 + 0x20) - dVar9 * *(double *)(iVar23 + 0x18);
            if (*(char *)(iVar23 + 0x34) == cVar1) {
              if (iVar2 <= iVar3) {
                iVar23 = *(int *)(iVar4 + iVar3 * 4);
                *(double *)(iVar23 + iVar2 * 8) = dVar14 + *(double *)(iVar23 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
                *(double *)(iVar23 + 8 + iVar2 * 8) = dVar15 + *(double *)(iVar23 + 8 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
                *(double *)(iVar23 + 0x10 + iVar2 * 8) = dVar17 + *(double *)(iVar23 + 0x10 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
                *(double *)(iVar23 + iVar2 * 8) = dVar20 + *(double *)(iVar23 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
                *(double *)(iVar23 + 8 + iVar2 * 8) = dVar16 + *(double *)(iVar23 + 8 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
                *(double *)(iVar23 + 0x10 + iVar2 * 8) = dVar18 + *(double *)(iVar23 + 0x10 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
                *(double *)(iVar23 + iVar2 * 8) = dVar21 + *(double *)(iVar23 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
                *(double *)(iVar23 + 8 + iVar2 * 8) = dVar22 + *(double *)(iVar23 + 8 + iVar2 * 8);
                iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
                goto LAB_0056b02e;
              }
              iVar23 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = dVar14 + *(double *)(iVar23 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = dVar20 + *(double *)(iVar23 + 8 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar23 + 0x10 + iVar3 * 8) = dVar21 + *(double *)(iVar23 + 0x10 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = dVar15 + *(double *)(iVar23 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = dVar16 + *(double *)(iVar23 + 8 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + 0x10 + iVar3 * 8) = dVar22 + *(double *)(iVar23 + 0x10 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = dVar17 + *(double *)(iVar23 + iVar3 * 8);
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = dVar18 + *(double *)(iVar23 + 8 + iVar3 * 8);
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4) + 0x10 + iVar3 * 8);
              goto LAB_0056b032;
            }
            if (iVar3 < iVar2) {
              iVar23 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = *(double *)(iVar23 + iVar3 * 8) - dVar14;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = *(double *)(iVar23 + 8 + iVar3 * 8) - dVar20;
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + 0x10 + iVar3 * 8);
              *pdVar25 = *pdVar25 - dVar21;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = *(double *)(iVar23 + iVar3 * 8) - dVar15;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = *(double *)(iVar23 + 8 + iVar3 * 8) - dVar16;
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + 0x10 + iVar3 * 8);
              *pdVar25 = *pdVar25 - dVar22;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + iVar3 * 8) = *(double *)(iVar23 + iVar3 * 8) - dVar17;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar23 + 8 + iVar3 * 8) = *(double *)(iVar23 + 8 + iVar3 * 8) - dVar18;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              pdVar25 = (double *)(iVar23 + 0x10 + iVar3 * 8);
              dVar19 = *(double *)(iVar23 + 0x10 + iVar3 * 8) - dVar19;
            }
            else {
              iVar23 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar23 + iVar2 * 8) = *(double *)(iVar23 + iVar2 * 8) - dVar14;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar23 + 8 + iVar2 * 8) = *(double *)(iVar23 + 8 + iVar2 * 8) - dVar15;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar23 + 0x10 + iVar2 * 8) = *(double *)(iVar23 + 0x10 + iVar2 * 8) - dVar17;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
              *(double *)(iVar23 + iVar2 * 8) = *(double *)(iVar23 + iVar2 * 8) - dVar20;
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4) + 8 + iVar2 * 8);
              *pdVar25 = *pdVar25 - dVar16;
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4) + 0x10 + iVar2 * 8);
              *pdVar25 = *pdVar25 - dVar18;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
              *(double *)(iVar23 + iVar2 * 8) = *(double *)(iVar23 + iVar2 * 8) - dVar21;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
              *(double *)(iVar23 + 8 + iVar2 * 8) = *(double *)(iVar23 + 8 + iVar2 * 8) - dVar22;
              iVar23 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar3 * 4);
              pdVar25 = (double *)(iVar23 + 0x10 + iVar2 * 8);
              dVar19 = *(double *)(iVar23 + 0x10 + iVar2 * 8) - dVar19;
            }
          }
          *pdVar25 = dVar19;
          iVar26 = iVar26 + 1;
          local_58 = local_58 + 0x38;
        } while (iVar26 < *(int *)(param_1 + 0x22c));
      }
      iVar26 = 0;
      if (0 < *(int *)(param_1 + 0x234)) {
        iVar23 = 0;
        do {
          iVar24 = *(int *)(param_1 + 0x238) + iVar23;
          iVar3 = *(int *)(iVar24 + 0x7c);
          dVar14 = dVar6 * *(double *)(iVar24 + 0x50) + dVar7 * *(double *)(iVar24 + 0x58) + dVar5 * *(double *)(*(int *)(param_1 + 0x238) + 0x48 + iVar23);
          dVar15 = dVar9 * *(double *)(iVar24 + 0x50) + dVar10 * *(double *)(iVar24 + 0x58) + dVar8 * *(double *)(iVar24 + 0x48);
          dVar16 = dVar12 * *(double *)(iVar24 + 0x50) + dVar13 * *(double *)(iVar24 + 0x58) + dVar11 * *(double *)(iVar24 + 0x48);
          dVar17 = dVar6 * *(double *)(iVar24 + 0x68) + dVar7 * *(double *)(iVar24 + 0x70) + dVar5 * *(double *)(iVar24 + 0x60);
          dVar18 = dVar9 * *(double *)(iVar24 + 0x68) + dVar10 * *(double *)(iVar24 + 0x70) + dVar8 * *(double *)(iVar24 + 0x60);
          dVar19 = dVar12 * *(double *)(iVar24 + 0x68) + dVar13 * *(double *)(iVar24 + 0x70) + dVar11 * *(double *)(iVar24 + 0x60);
          iVar4 = *(int *)(param_1 + 0x228);
          if (*(char *)(iVar24 + 0x80) == cVar1) {
            if (iVar3 < iVar2) {
              iVar4 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar14 + *(double *)(iVar4 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4);
              *(double *)(iVar4 + 8 + iVar3 * 8) = dVar17 + *(double *)(iVar4 + 8 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar15 + *(double *)(iVar4 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar4 + 8 + iVar3 * 8) = dVar18 + *(double *)(iVar4 + 8 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar16 + *(double *)(iVar4 + iVar3 * 8);
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4) + 8 + iVar3 * 8);
            }
            else {
              iVar4 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar14 + *(double *)(iVar4 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar4 + 8 + iVar2 * 8) = dVar15 + *(double *)(iVar4 + 8 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar4 + 0x10 + iVar2 * 8) = dVar16 + *(double *)(iVar4 + 0x10 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar17 + *(double *)(iVar4 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
              *(double *)(iVar4 + 8 + iVar2 * 8) = dVar18 + *(double *)(iVar4 + 8 + iVar2 * 8);
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4) + 0x10 + iVar2 * 8);
            }
            dVar19 = dVar19 + *pdVar25;
          }
          else if (iVar3 < iVar2) {
            iVar4 = *(int *)(iVar4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar2 * 4) + 8 + iVar3 * 8);
            *pdVar25 = *pdVar25 - dVar17;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar15;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
            *(double *)(iVar4 + 8 + iVar3 * 8) = *(double *)(iVar4 + 8 + iVar3 * 8) - dVar18;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar16;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            pdVar25 = (double *)(iVar4 + 8 + iVar3 * 8);
            dVar19 = *(double *)(iVar4 + 8 + iVar3 * 8) - dVar19;
          }
          else {
            iVar4 = *(int *)(iVar4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 8 + iVar2 * 8);
            *pdVar25 = *pdVar25 - dVar15;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
            *(double *)(iVar4 + 0x10 + iVar2 * 8) = *(double *)(iVar4 + 0x10 + iVar2 * 8) - dVar16;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar17;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            *(double *)(iVar4 + 8 + iVar2 * 8) = *(double *)(iVar4 + 8 + iVar2 * 8) - dVar18;
            iVar3 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar3 * 4);
            pdVar25 = (double *)(iVar3 + 0x10 + iVar2 * 8);
            dVar19 = *(double *)(iVar3 + 0x10 + iVar2 * 8) - dVar19;
          }
          *pdVar25 = dVar19;
          iVar26 = iVar26 + 1;
          iVar23 = iVar23 + 0x84;
        } while (iVar26 < *(int *)(param_1 + 0x234));
      }
      iVar26 = 0;
      if (0 < *(int *)(param_1 + 0x23c)) {
        iVar23 = 0;
        do {
          iVar24 = *(int *)(param_1 + 0x240) + iVar23;
          iVar3 = *(int *)(iVar24 + 0x30);
          dVar14 = (dVar7 * *(double *)(iVar24 + 0x18) - dVar5 * *(double *)(iVar24 + 0x28)) *
                   *(double *)(iVar24 + 0x48) +
                   ((dVar6 * *(double *)(*(int *)(param_1 + 0x240) + 0x28 + iVar23) -
                    dVar7 * *(double *)(iVar24 + 0x20)) + *(double *)(param_1 + 0xb4)) *
                   *(double *)(iVar24 + 0x40) +
                   (dVar5 * *(double *)(iVar24 + 0x20) - dVar6 * *(double *)(iVar24 + 0x18)) *
                   *(double *)(iVar24 + 0x50);
          dVar15 = ((dVar10 * *(double *)(iVar24 + 0x18) - dVar8 * *(double *)(iVar24 + 0x28)) +
                   *(double *)(param_1 + 0xb4)) * *(double *)(iVar24 + 0x48) +
                   (dVar9 * *(double *)(iVar24 + 0x28) - dVar10 * *(double *)(iVar24 + 0x20)) *
                   *(double *)(iVar24 + 0x40) +
                   (dVar8 * *(double *)(iVar24 + 0x20) - dVar9 * *(double *)(iVar24 + 0x18)) *
                   *(double *)(iVar24 + 0x50);
          iVar4 = *(int *)(param_1 + 0x228);
          dVar16 = (dVar13 * *(double *)(iVar24 + 0x18) - dVar11 * *(double *)(iVar24 + 0x28)) *
                   *(double *)(iVar24 + 0x48) +
                   (dVar12 * *(double *)(iVar24 + 0x28) - dVar13 * *(double *)(iVar24 + 0x20)) *
                   *(double *)(iVar24 + 0x40) +
                   ((dVar11 * *(double *)(iVar24 + 0x20) - dVar12 * *(double *)(iVar24 + 0x18)) +
                   *(double *)(param_1 + 0xb4)) * *(double *)(iVar24 + 0x50);
          if (*(char *)(iVar24 + 0x34) == cVar1) {
            if (iVar3 < iVar2) {
              iVar4 = *(int *)(iVar4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar14 + *(double *)(iVar4 + iVar3 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4);
              *(double *)(iVar4 + iVar3 * 8) = dVar15 + *(double *)(iVar4 + iVar3 * 8);
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4) + iVar3 * 8);
            }
            else {
              iVar4 = *(int *)(iVar4 + iVar3 * 4);
              *(double *)(iVar4 + iVar2 * 8) = dVar14 + *(double *)(iVar4 + iVar2 * 8);
              iVar4 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
              *(double *)(iVar4 + 8 + iVar2 * 8) = dVar15 + *(double *)(iVar4 + 8 + iVar2 * 8);
              pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 0x10 + iVar2 * 8);
            }
            dVar16 = dVar16 + *pdVar25;
          }
          else if (iVar3 < iVar2) {
            iVar4 = *(int *)(iVar4 + iVar2 * 4);
            *(double *)(iVar4 + iVar3 * 8) = *(double *)(iVar4 + iVar3 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + 4 + iVar2 * 4) + iVar3 * 8);
            *pdVar25 = *pdVar25 - dVar15;
            iVar4 = *(int *)(*(int *)(param_1 + 0x228) + 8 + iVar2 * 4);
            pdVar25 = (double *)(iVar4 + iVar3 * 8);
            dVar16 = *(double *)(iVar4 + iVar3 * 8) - dVar16;
          }
          else {
            iVar4 = *(int *)(iVar4 + iVar3 * 4);
            *(double *)(iVar4 + iVar2 * 8) = *(double *)(iVar4 + iVar2 * 8) - dVar14;
            pdVar25 = (double *)(*(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4) + 8 + iVar2 * 8);
            *pdVar25 = *pdVar25 - dVar15;
            iVar3 = *(int *)(*(int *)(param_1 + 0x228) + iVar3 * 4);
            pdVar25 = (double *)(iVar3 + 0x10 + iVar2 * 8);
            dVar16 = *(double *)(iVar3 + 0x10 + iVar2 * 8) - dVar16;
          }
          *pdVar25 = dVar16;
          iVar26 = iVar26 + 1;
          iVar23 = iVar23 + 0x58;
        } while (iVar26 < *(int *)(param_1 + 0x23c));
      }
      iVar26 = *(int *)(param_1 + 0x22c);
      local_54 = local_54 + 1;
      local_a4 = local_a4 + 0x38;
    } while (local_54 < iVar26);
  }
  return;
}
```
## FUN_00596c80

```
// Function: FUN_00596c80 @ 00596c80
// Size (bytes): 257
// strncmp with locale-aware case folding (single-byte or multi-byte code page)
## FUN_00566380

```
// Function: FUN_00566380 @ 00566380
// Size (bytes): 287
// Linked-list merge-sort — splits list at midpoint, recursively sorts, merges
## FUN_00556e70

```
// Function: FUN_00556e70 @ 00556e70
// Size (bytes): 578
// Animation/scene graph update — walks object/light/camera trees, applies transforms
## FUN_0058e290

```
// Function: FUN_0058e290 @ 0058e290
// Size (bytes): 395
// WriteFile wrapper with text-mode \n -> \r\n conversion for pipes
## FUN_00586aa0

```
// Function: FUN_00586aa0 @ 00586aa0
// Size (bytes): 486
// Bitmap blit/copy — processes color planes with bitmask per channel
## FUN_0056bde0

```
// Function: FUN_0056bde0 @ 0056bde0
// Size (bytes): 566
// 3x3 rotation matrix from axis-angle (Rodrigues formula) + Euler extraction
## FUN_005664a0

```
// Function: FUN_005664a0 @ 005664a0
// Size (bytes): 260
// Recursive merge-sort on singly-linked list (returns sorted head)
```
## FUN_00582780

```
// Function: FUN_00582780 @ 00582780
// Size (bytes): 299 / 90 lines
// Thread-pool task queue — allocates work items, links them
## FUN_0059bbd9

```
// Function: FUN_0059bbd9 @ 0059bbd9
// Size (bytes): 249 / 87 lines
// File putc with buffer management (text/binary mode, Unicode-aware)
## FUN_0058fcb0

```
// Function: FUN_0058fcb0 @ 0058fcb0
// Size (bytes): 224 / 81 lines
// strncpy replacement — copies N chars, null-terminates
## FUN_0059be0c

```
// Function: FUN_0059be0c @ 0059be0c
// Size (bytes): 241 / 78 lines
// File read — reads from file handle into buffer, locks/unlocks
## FUN_00592924

```
// Function: FUN_00592924 @ 00592924
// Size (bytes): 318 / 77 lines
// SEH exception filter — handles crash dumps, error dialogs
## FUN_005608f6

```
// Function: FUN_005608f6 @ 005608f6
// Size (bytes): 167 / 74 lines
// Time conversion — converts time struct to float seconds
## FUN_0056c3a0

```
// Function: FUN_0056c3a0 @ 0056c3a0
// Size (bytes): 416 / 71 lines
// 3D uniform directional light transform — rotates light direction by quaternion
<!-- target: docs/20-math-utilities.md -->


## FUN_00585130

```
// Function: FUN_00585130 @ 00585130
// Size (bytes): 236 / 70 lines
// Thread mailbox — signals completion event, dispatches callback to main thread
## FUN_00556d60

```
// Function: FUN_00556d60 @ 00556d60
// Size (bytes): 270 / 68 lines
// Animation/rig update — walks bone list, applies local transforms
## FUN_00567b00

```
// Function: thunk_FUN_00567b10 @ 00567b00
// Size (bytes): 5 / 68 lines
// thunk — compares two paths, returns 0 or 1
## FUN_0055EBA0 � 3D Lighting/Reflection Vector Compute

Source: unknown | Confidence: medium
Computes reflection/lighting direction vectors for a set of vertices. Uses virtual dispatch for vertex data access and applies specular-like reflection formula.

**Key logic:**
- If param_2 != 0:
  - Read vertex count from param_1 + 8
  - Determine vertex stride: if flag  x800000 at *(param_1+0x18)+0x14 set ? stride 0x10, else stride 0xc
  - Loop per vertex:
    - Virtual call at DAT_008b8f24[1] � read unmodified position from *(param_1+0x18)+0x1a0
    - Virtual call at *DAT_008b8f24 � read modified position from *(param_1+0x18)+0x114
    - Compute dirX = local_x + param_2[0x24], dirY = local_y + param_2[0x28], dirZ = local_z + param_2[0x2c]
    - invLen = 1.0 / SQRT(dirX� + dirY� + dirZ�)
    - Compute reflection: NdotL = nx*dirX + ny*dirY + nz*dirZ; 
eflect = 2*NdotL
    - 
esult = (n*reflect - dir*invLen) * _DAT_0059e450 + _DAT_0059e450
    - Store result in array at param_1[0x20] with stride 0x40

**Globals:**
- DAT_008b8f24 � virtual function table for vertex data access
- _DAT_0059e43c � 1.0f constant
- _DAT_0059e450 � 0.5f scaling/bias constant

**Calls:** virtual dispatch via DAT_008b8f24

**Moddability:** hookable

<!-- target: docs/19-renderer.md -->

## FUN_00554f80

```
// Function: FUN_00554f80 @ 00554f80
// Size (bytes): 279 / 64 lines
// UI item lookup — finds named UI element in tree, returns handle
## FUN_00584130

```
// Function: FUN_00584130 @ 00584130
// Size (bytes): 254 / 63 lines
// File I/O — reads a struct/record from file handle with size check
## FUN_005609de

```
// Function: FUN_005609de @ 005609de
// Size (bytes): 153 / 61 lines
// Time format — converts uint seconds to hours:minutes:seconds
## FUN_0058aa6f

```
// Function: FUN_0058aa6f @ 0058aa6f
// Size (bytes): 215 / 61 lines
// Heap free with guard — frees memory through HeapFree with validation
```
## FUN_0056c640

```
// Function: FUN_0056c640 @ 0056c640
// Size (bytes): 248 / 59 lines
// 3D vector cross product + normalize (double)
<!-- target: docs/20-math-utilities.md -->


## FUN_0058c255

```
// Function: FUN_0058c255 @ 0058c255
// Size (bytes): 220 / 56 lines
// Stream getc with underflow — reads byte from buffer, refills if empty
## FUN_00594ff0

```
// Function: __aulldiv @ 00594ff0
// Size (bytes): 104 / 55 lines
// CRT 64-bit unsigned integer division (__aulldiv)
## FUN_00583430

```
// Function: FUN_00583430 @ 00583430
// Size (bytes): 132 / 54 lines
// Allocate + zero-fill task/worker struct
## FUN_0058e41b

```
// Function: FUN_0058e41b @ 0058e41b
// Size (bytes): NA / 52 lines
// Secure CRT _mbscmp — multi-byte string comparison with locale
## FUN_00564c70

```
// Function: FUN_00564c70 @ 00564c70
// Size (bytes): NA / 51 lines
// Base64 decode — decodes 4 Base64 chars into 3 bytes
## FUN_0059B490 � Dynamic Buffer Reallocation

Source: unknown | Confidence: high
Grows a dynamically-allocated buffer when capacity is insufficient. Copies old data to new allocation, frees old buffer.

**Key logic:**
- If 
eededSize = oldLen * 8 < dataEnd + param_2 (current capacity insufficient):
  - growthUnit = param_1[6] � base growth increment
  - 
ewLen = growthUnit + oldLen
  - Loop while 
ewLen < 0x1f400 (128KB max):
    - If capacity >= neededSize break
    - 
ewLen += growthUnit
  - operator_new(newLen) � allocate new buffer
  - If alloc fails: return 0
  - Copy old data: dword loop (oldLen >> 2) + byte remainder (oldLen & 3)
  - FUN_00587bcf(*param_1) � free old buffer
  - Update *param_1 = newBuffer, param_1[1] = newLen
- Return 1 on success (or no resize needed)

**Calls:** operator_new, FUN_00587bcf (free)

**Moddability:** hardcoded (max 0x1f400 bytes)

## FUN_00599dd9

```
// Function: FUN_00599dd9 @ 00599dd9
// Size (bytes): NA / 50 lines
// CRT stream xsgetn — reads block from stream with lock
## FUN_0057acb0

```
// Function: FUN_0057acb0 @ 0057acb0
// Size (bytes): NA / 46 lines
// Queue user callback — posts async callback to thread via QueueUserAPC
## FUN_0055d320

```
// Function: FUN_0055d320 @ 0055d320
// Size (bytes): NA / 42 lines
// UI layout calc — computes text bounding box for layout
## FUN_00590246

```
// Function: FUN_00590246 @ 00590246
// Size (bytes): NA / 41 lines
// CRT strcoll — locale-aware string collation
## FUN_0058bccf

```
// Function: FUN_0058bccf @ 0058bccf
// Size (bytes): NA / 36 lines
// CRT float-to-string — converts double to decimal string
## FUN_0058dd89

```
// Function: FUN_0058dd89 @ 0058dd89
// Size (bytes): NA / 34 lines
// CRT math helper — adjusts FPU rounding mode for transcendentals
## FUN_0058850f

```
// Function: FUN_0058850f @ 0058850f
// Size (bytes): NA / 32 lines
// CRT _ftol2 — float-to-long with SSE/FPU rounding
## FUN_0059325D � CRT Heap Initialization

Source: MSVC CRT startup | Confidence: high
Creates a process heap, checks OS version, initializes I/O or locale subsystem.

**Key logic:**
- HeapCreate(0, 0x1000, 0) � create private heap (growable)
- If heap valid:
  - FUN_00593115() � get OS version
  - If version == 3 (NT): FUN_00593dd3(0x3f8) � init I/O
  - If version == 2 (9x): FUN_0059491a() � init locale
  - If init fails: HeapDestroy the heap, return 0
  - Returns 1 on success

**Globals:**
- DAT_008d4904 � heap handle
- DAT_008d4908 � OS version

**Calls:** HeapCreate, HeapDestroy, FUN_00593115 (OS version), FUN_00593dd3 (I/O init), FUN_0059491a (locale init)

**Moddability:** N/A (CRT startup)

<!-- target: docs/08-file-formats.md -->

## FUN_00554560

```
// Function: FUN_00554560 @ 00554560
// Size (bytes): NA / 27 lines
// UI animation — interpolates widget property (position/alpha) over time
## FUN_0058c331

```
// Function: FUN_0058c331 @ 0058c331
// Size (bytes): NA / 25 lines
// CRT stream close — flushes and closes file handle
## FUN_00595f11

```
// Function: FUN_00595f11 @ 00595f11
// Size (bytes): NA / 25 lines
// CRT file seek — sets file position via SetFilePointer
## FUN_0058eef7

```
// Function: FUN_0058eef7 @ 0058eef7
// Size (bytes): NA / 22 lines
// CRT heap validate — checks heap integrity, returns status
## FUN_0058dfc1

```
// Function: FUN_0058dfc1 @ 0058dfc1
// Size (bytes): NA / 15 lines
// CRT fclose — closes FILE stream, flushes buffers
```
## FUN_0059807b

```
// Function: FUN_0059807b @ 0059807b
// Size (bytes): 597

int FUN_0059807b(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
                UINT param_7)
{
  undefined1 *puVar1;
  int iVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  int iVar5;
  _cpinfo local_40;
  undefined1 *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005b9b88;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffb0;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffb0;
  if (DAT_008d4208 == 0) {
    ExceptionList = &local_14;
    iVar2 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringA(0,0,(PCNZCH)&DAT_007cd8bc,1,(PCNZCH)&DAT_007cd8bc,1);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_008d4208 = 2;
      puVar1 = local_1c;
    }
    else {
      DAT_008d4208 = 1;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  if (0 < param_4) {
    param_4 = FUN_005982f8(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_005982f8(param_5,param_6);
  }
  if (DAT_008d4208 == 2) {
    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar2;
  }
  if (DAT_008d4208 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_008d3f48;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        ExceptionList = local_14;
        return 2;
      }
      if (1 < param_6) {
        ExceptionList = local_14;
        return 1;
      }
      if (1 < param_4) {
        ExceptionList = local_14;
        return 3;
      }
      BVar3 = GetCPInfo(param_7,&local_40);
      if (BVar3 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (0 < param_4) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 3;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 3;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 3;
      }
      if (0 < param_6) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 1;
      }
    }
    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      FUN_005881c0();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x50) &&
         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,
         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,
                                     local_20), iVar2 != 0)) {
        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          local_8 = 1;
          local_24 = iVar2;
          FUN_005881c0();
          local_8 = 0xffffffff;
          if ((&stack0x00000000 != (undefined1 *)0x50) &&
             (local_2c = &stack0xffffffb0, local_1c = &stack0xffffffb0,
             iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,(LPWSTR)&stack0xffffffb0,
                                         iVar2), iVar5 != 0)) {
            iVar2 = CompareStringW(param_1,param_2,local_28,local_20,(PCNZWCH)&stack0xffffffb0,iVar2
                                  );
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}
```
## FUN_0056f818

```
// Function: FUN_0056f818 @ 0056f818
// Size (bytes): 638

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0056f818(int *param_1,double *param_2)
{
  short *psVar1;
  int *piVar2;
  int iVar3;
  short local_bc [84];
  int *local_14;
  int local_10;
  int local_a;
  bool local_5;
  
  iVar3 = 1;
  piVar2 = (int *)0x0;
  local_bc[0] = 2; local_bc[1] = 2; local_bc[2] = 1; local_bc[3] = 0xb;
  local_bc[4] = 4; local_bc[5] = 0xe; local_bc[6] = 0; local_bc[7] = 2;
  local_bc[8] = 1; local_bc[9] = 0xb; local_bc[10] = 4; local_bc[0xb] = 0x11;
  local_bc[0xc] = 1; local_bc[0xd] = 0xb; local_bc[0xe] = 4; local_bc[0xf] = 0xe;
  local_bc[0x10] = 1; local_bc[0x11] = 1; local_bc[0x12] = 1; local_bc[0x13] = 0xe;
  local_bc[0x14] = 4; local_bc[0x15] = 9; local_bc[0x16] = 0; local_bc[0x17] = 1;
  local_bc[0x18] = 1; local_bc[0x19] = 0xe; local_bc[0x1a] = 4; local_bc[0x1b] = 0xb;
  local_bc[0x1c] = 1; local_bc[0x1d] = 0xe; local_bc[0x1e] = 4; local_bc[0x1f] = 9;
  local_bc[0x20] = 0; local_bc[0x21] = 0xb; local_bc[0x22] = 4; local_bc[0x23] = 0x1a;
  local_bc[0x24] = 4; local_bc[0x25] = 0xe; local_bc[0x26] = 0; local_bc[0x27] = 0xe;
  local_bc[0x28] = 4; local_bc[0x29] = 0x18; local_bc[0x2a] = 4; local_bc[0x2b] = 9;
  local_bc[0x2c] = 1; local_bc[0x2d] = 2; local_bc[0x2e] = 1; local_bc[0x2f] = 0xb;
  local_bc[0x30] = 4; local_bc[0x31] = 4; local_bc[0x32] = 0; local_bc[0x33] = 2;
  local_bc[0x34] = 1; local_bc[0x35] = 0xb; local_bc[0x36] = 4; local_bc[0x37] = 7;
  local_bc[0x38] = 1; local_bc[0x39] = 0xb; local_bc[0x3a] = 4; local_bc[0x3b] = 4;
  local_bc[0x3c] = 1; local_bc[0x3d] = 1; local_bc[0x3e] = 1; local_bc[0x3f] = 0xe;
  local_bc[0x40] = 5; local_bc[0x41] = 1; local_bc[0x42] = 1; local_bc[0x43] = 0xe;
  local_bc[0x44] = 4; local_bc[0x45] = 1; local_bc[0x46] = 1; local_bc[0x47] = 0xe;
  local_bc[0x48] = 5; local_bc[0x49] = 0xb; local_bc[0x4a] = 4; local_bc[0x4b] = 0x10;
  local_bc[0x4c] = 4; local_bc[0x4d] = 4; local_bc[0x4e] = 0; local_bc[0x4f] = 0xe;
  local_bc[0x50] = 4; local_bc[0x51] = 0xe; local_bc[0x52] = 0xc2;
  local_a = 0;
  local_10 = 0;
  local_5 = true;
  if (param_2 == (double *)0x28) {
    local_14 = param_1;
    piVar2 = param_1;
    do {
      if (iVar3 < 0x28) {
        param_2 = (double *)(*local_14 + iVar3 * 8);
        param_1 = (int *)iVar3;
        do {
          piVar2 = (int *)(uint)(byte)(local_5 ^ *param_2 != _DAT_0059e430);
          if (piVar2 == (int *)0x0) { local_a = local_a + 1; }
          else {
            if (0x52 < local_10) goto LAB_0056fa80;
            psVar1 = local_bc + local_10;
            piVar2 = (int *)CONCAT22((short)((uint)local_10 >> 0x10),*psVar1);
            local_10 = local_10 + 1;
            if ((short)local_a != *psVar1) goto LAB_0056fa80;
            local_a = 0;
            piVar2 = (int *)CONCAT31((int3)((uint)piVar2 >> 8),local_5 == false);
            local_5 = local_5 == false;
          }
          param_1 = (int *)((int)param_1 + 1);
          param_2 = param_2 + 1;
        } while ((int)param_1 < 0x28);
      }
      local_14 = local_14 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x29);
    if (local_10 == 0x52) {
      return (uint)((short)local_a == 0xc2);
    }
  }
LAB_0056fa80:
  return (uint)piVar2 & 0xffffff00;
}
```
## FUN_0059b760

```
// Function: FUN_0059b760 @ 0059b760
// Size (bytes): 659

undefined4 FUN_0059b760(uint param_1,uint *param_2)
{
  int *piVar1; uint *puVar2; DWORD DVar3; undefined4 *puVar4; BOOL BVar5;
  uint uVar6; int iVar7;
  _BY_HANDLE_FILE_INFORMATION local_54;
  _SYSTEMTIME local_20;
  _FILETIME local_10;
  undefined4 local_8;
  
  local_8 = 0;
  if (DAT_008d4a20 <= param_1) {
LAB_0059b9e1:
    puVar4 = (undefined4 *)FUN_0058afcf();
    *puVar4 = 9;
    return 0xffffffff;
  }
  piVar1 = &DAT_008d4920 + ((int)param_1 >> 5);
  iVar7 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)(*piVar1 + 4 + iVar7) & 1) == 0) goto LAB_0059b9e1;
  FUN_00595a61(param_1);
  DVar3 = GetFileType(*(HANDLE *)(*piVar1 + iVar7));
  puVar2 = param_2;
  uVar6 = DVar3 & 0xffff7fff;
  if (uVar6 != 1) {
    if (uVar6 == 2) { *(undefined2 *)((int)param_2 + 6) = 0x2000; }
    else {
      if (uVar6 != 3) {
        if (uVar6 == 0) { puVar4 = (undefined4 *)FUN_0058afcf(); *puVar4 = 9; goto LAB_0059b7db; }
        goto LAB_0059b887;
      }
      *(undefined2 *)((int)param_2 + 6) = 0x1000;
    }
    *(undefined2 *)(param_2 + 2) = 1;
    *param_2 = param_1;
    param_2[4] = param_1;
    *(undefined2 *)(param_2 + 1) = 0;
    *(undefined2 *)(param_2 + 3) = 0;
    *(undefined2 *)((int)param_2 + 10) = 0;
    param_2[8] = 0; param_2[7] = 0; param_2[6] = 0;
    if (uVar6 == 2) { param_2[5] = 0; }
    else {
      BVar5 = PeekNamedPipe(*(HANDLE *)(*piVar1 + iVar7),(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPDWORD)&param_2,(LPDWORD)0x0);
      if (BVar5 == 0) { puVar2[5] = 0; }
      else { puVar2[5] = (uint)param_2; }
    }
    goto LAB_0059b7df;
  }
  *(undefined2 *)((int)param_2 + 6) = 0;
  *(undefined2 *)(param_2 + 3) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0;
  *(undefined2 *)(param_2 + 1) = 0;
  *(undefined2 *)(param_2 + 2) = 1;
  BVar5 = GetFileInformationByHandle(*(HANDLE *)(*piVar1 + iVar7),&local_54);
  if (BVar5 == 0) {
LAB_0059b887:
    DVar3 = GetLastError();
    FUN_0058af5c(DVar3);
  }
  else {
    if (((byte)local_54.dwFileAttributes & 1) == 0) {
      *(ushort *)((int)puVar2 + 6) = *(ushort *)((int)puVar2 + 6) | 0x1b6;
    }
    else {
      *(ushort *)((int)puVar2 + 6) = *(ushort *)((int)puVar2 + 6) | 0x124;
    }
    BVar5 = FileTimeToLocalFileTime(&local_54.ftLastWriteTime,&local_10);
    if ((BVar5 != 0) && (BVar5 = FileTimeToSystemTime(&local_10,&local_20), BVar5 != 0)) {
      uVar6 = FUN_00591edf(local_20.wYear,local_20.wMonth,local_20.wDay,local_20.wHour,
                           local_20.wMinute,local_20.wSecond,0xffffffff);
      puVar2[7] = uVar6;
      if ((local_54.ftLastAccessTime.dwLowDateTime == 0) &&
         (local_54.ftLastAccessTime.dwHighDateTime == 0)) {
LAB_0059b965:
        puVar2[6] = uVar6;
        if ((local_54.ftCreationTime.dwLowDateTime == 0) &&
           (local_54.ftCreationTime.dwHighDateTime == 0)) {
          uVar6 = puVar2[7];
        }
        else {
          BVar5 = FileTimeToLocalFileTime(&local_54.ftCreationTime,&local_10);
          if ((BVar5 == 0) || (BVar5 = FileTimeToSystemTime(&local_10,&local_20), BVar5 == 0))
          goto LAB_0059b9d9;
          uVar6 = FUN_00591edf(local_20.wYear,local_20.wMonth,local_20.wDay,local_20.wHour,
                               local_20.wMinute,local_20.wSecond,0xffffffff);
        }
        *(byte *)((int)puVar2 + 7) = *(byte *)((int)puVar2 + 7) | 0x80;
        puVar2[8] = uVar6;
        *puVar2 = 0;
        puVar2[5] = local_54.nFileSizeLow;
        puVar2[4] = 0;
      }
      else {
        BVar5 = FileTimeToLocalFileTime(&local_54.ftLastAccessTime,&local_10);
        if ((BVar5 != 0) && (BVar5 = FileTimeToSystemTime(&local_10,&local_20), BVar5 != 0)) {
          uVar6 = FUN_00591edf(local_20.wYear,local_20.wMonth,local_20.wDay,local_20.wHour,
                               local_20.wMinute,local_20.wSecond,0xffffffff);
          goto LAB_0059b965;
        }
LAB_0059b9d9:
        local_8 = 0xffffffff;
      }
      goto LAB_0059b7df;
    }
  }
LAB_0059b7db:
  local_8 = 0xffffffff;
LAB_0059b7df:
  FUN_00595ac0(param_1);
  return local_8;
}
```
## FUN_0058928f

```
// Function: FUN_0058928f @ 0058928f
// Size (bytes): 517

uint FUN_0058928f(byte *param_1,int *param_2,uint param_3,uint param_4)
{
  byte *pbVar1; uint uVar2; uint uVar3; int iVar4; undefined4 *puVar5;
  byte bVar6; uint uVar7; uint local_c; byte *local_8;
  
  local_c = 0;
  bVar6 = *param_1;
  pbVar1 = param_1;
  while( true ) {
    local_8 = pbVar1 + 1;
    if (DAT_005e6bd4 < 2) { uVar2 = (byte)PTR_DAT_005e69c8[(uint)bVar6 * 2] & 8; }
    else { uVar2 = FUN_0058c674(bVar6,8); }
    if (uVar2 == 0) break;
    bVar6 = *local_8;
    pbVar1 = local_8;
  }
  if (bVar6 == 0x2d) {
    param_4 = param_4 | 2;
LAB_005892ea:
    bVar6 = *local_8;
    local_8 = pbVar1 + 2;
  }
  else if (bVar6 == 0x2b) goto LAB_005892ea;
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (int *)0x0) { *param_2 = (int)param_1; }
    return 0;
  }
  if (param_3 == 0) {
    if (bVar6 != 0x30) { param_3 = 10; goto LAB_00589354; }
    if ((*local_8 != 0x78) && (*local_8 != 0x58)) { param_3 = 8; goto LAB_00589354; }
    param_3 = 0x10;
  }
  if (((param_3 == 0x10) && (bVar6 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58)))) {
    bVar6 = local_8[1];
    local_8 = local_8 + 2;
  }
LAB_00589354:
  uVar2 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    uVar7 = (uint)bVar6;
    if (DAT_005e6bd4 < 2) { uVar3 = (byte)PTR_DAT_005e69c8[uVar7 * 2] & 4; }
    else { uVar3 = FUN_0058c674(uVar7,4); }
    if (uVar3 == 0) {
      if (DAT_005e6bd4 < 2) { uVar7 = *(ushort *)(PTR_DAT_005e69c8 + uVar7 * 2) & 0x103; }
      else { uVar7 = FUN_0058c674(uVar7,0x103); }
      if (uVar7 == 0) {
LAB_00589400:
        local_8 = local_8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (int *)0x0) { local_8 = param_1; }
          local_c = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 && ((((param_4 & 2) != 0 && (0x80000000 < local_c)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < local_c)))))))) {
          puVar5 = (undefined4 *)FUN_0058afcf();
          *puVar5 = 0x22;
          if ((param_4 & 1) == 0) { local_c = ((param_4 & 2) != 0) + 0x7fffffff; }
          else { local_c = 0xffffffff; }
        }
        if (param_2 != (int *)0x0) { *param_2 = (int)local_8; }
        if ((param_4 & 2) == 0) { return local_c; }
        return -local_c;
      }
      iVar4 = FUN_00589a35((int)(char)bVar6);
      uVar7 = iVar4 - 0x37;
    }
    else { uVar7 = (int)(char)bVar6 - 0x30; }
    if (param_3 <= uVar7) goto LAB_00589400;
    if ((local_c < uVar2) || ((local_c == uVar2 && (uVar7 <= (uint)(0xffffffff % (ulonglong)param_3))))) {
      local_c = local_c * param_3 + uVar7;
      param_4 = param_4 | 8;
    }
    else { param_4 = param_4 | 0xc; }
    bVar6 = *local_8;
    local_8 = local_8 + 1;
  } while( true );
}
```
## FUN_0058f939

```
// Function: FUN_0058f939 @ 0058f939
// Size (bytes): 581

undefined4 FUN_0058f939(void)
{
  BYTE *pBVar1; byte bVar2; int iVar3; undefined2 *puVar4; BOOL BVar5;
  BYTE *pBVar6; uint uVar7; undefined2 *puVar8; undefined4 uVar9;
  _cpinfo local_28;
  undefined2 *local_14; undefined2 *local_10; undefined2 *local_c; void *local_8;
  
  uVar9 = 0;
  local_8 = (void *)0x0; local_c = (undefined2 *)0x0;
  if (DAT_008d3f38 == 0) {
    PTR_DAT_005e69c8 = &DAT_005e69d2;
    PTR_DAT_005e69cc = &DAT_005e69d2;
    FUN_0058aa6f(DAT_008d3f6c); FUN_0058aa6f(DAT_008d3f70);
    DAT_008d3f6c = (undefined2 *)0x0; DAT_008d3f70 = (undefined2 *)0x0;
    return 0;
  }
  if ((DAT_008d3f48 != 0) || (iVar3 = FUN_005968f6(0,DAT_008d3f80,0x1004,&DAT_008d3f48), iVar3 == 0)) {
    puVar4 = _malloc(0x202); local_14 = puVar4;
    local_10 = _malloc(0x202); local_8 = _malloc(0x101); local_c = _malloc(0x202);
    if ((puVar4 != (undefined2 *)0x0) &&
       (((local_10 != (undefined2 *)0x0 && (local_8 != (void *)0x0)) && (local_c != (undefined2 *)0x0)))) {
      iVar3 = 0;
      do { *(char *)(iVar3 + (int)local_8) = (char)iVar3; iVar3 = iVar3 + 1; } while (iVar3 < 0x100);
      BVar5 = GetCPInfo(DAT_008d3f48,&local_28);
      if ((BVar5 != 0) && (local_28.MaxCharSize < 3)) {
        DAT_005e6bd4 = local_28.MaxCharSize & 0xffff;
        if ((1 < DAT_005e6bd4) && (local_28.LeadByte[0] != '\0')) {
          pBVar6 = local_28.LeadByte + 1;
          do {
            bVar2 = *pBVar6;
            if (bVar2 == 0) break;
            for (uVar7 = (uint)pBVar6[-1]; (int)uVar7 <= (int)(uint)bVar2; uVar7 = uVar7 + 1) {
              *(undefined1 *)(uVar7 + (int)local_8) = 0;
              bVar2 = *pBVar6;
            }
            pBVar1 = pBVar6 + 1; pBVar6 = pBVar6 + 2;
          } while (*pBVar1 != 0);
        }
        iVar3 = FUN_00595dc8(1,local_8,0x100,puVar4 + 1,0,0,0);
        if (iVar3 != 0) {
          *puVar4 = 0;
          iVar3 = 0;
          puVar4 = local_c;
          do { *puVar4 = (short)iVar3; puVar4 = puVar4 + 1; iVar3 = iVar3 + 1; } while (iVar3 < 0x100);
          puVar4 = local_10 + 1;
          iVar3 = FUN_00596a2e(1,local_c,0x100,puVar4,0,0);
          if (iVar3 != 0) {
            *local_10 = 0;
            if ((1 < (int)DAT_005e6bd4) && (local_28.LeadByte[0] != '\0')) {
              pBVar6 = local_28.LeadByte + 1;
              do {
                if (*pBVar6 == 0) break;
                uVar7 = (uint)pBVar6[-1];
                if (uVar7 <= *pBVar6) {
                  puVar8 = local_14 + uVar7 + 1;
                  do { *puVar8 = 0x8000; uVar7 = uVar7 + 1; puVar8 = puVar8 + 1; }
                  while ((int)uVar7 <= (int)(uint)*pBVar6);
                }
                pBVar1 = pBVar6 + 1; pBVar6 = pBVar6 + 2;
              } while (*pBVar1 != 0);
            }
            PTR_DAT_005e69c8 = (undefined *)(local_14 + 1);
            PTR_DAT_005e69cc = (undefined *)puVar4;
            if (DAT_008d3f6c != (undefined2 *)0x0) { FUN_0058aa6f(DAT_008d3f6c); }
            DAT_008d3f6c = local_14;
            if (DAT_008d3f70 != (undefined2 *)0x0) { FUN_0058aa6f(DAT_008d3f70); }
            DAT_008d3f70 = local_10;
            goto LAB_0058fb17;
          }
        }
      }
    }
  }
  FUN_0058aa6f(local_14); FUN_0058aa6f(local_10);
  uVar9 = 1;
LAB_0058fb17:
  FUN_0058aa6f(local_8); FUN_0058aa6f(local_c);
  return uVar9;
}
```
## FUN_0055cf50

```
// Function: FUN_0055cf50 @ 0055cf50
// Size (bytes): 687

void __thiscall FUN_0055cf50(undefined4 *param_1,int param_2,byte *param_3)
{
  int iVar1; undefined4 uVar2; int iVar3; int iVar4; int iVar5; int iVar6;
  undefined4 unaff_retaddr; undefined4 uVar7; int iStack_4c;
  undefined1 local_40 [32]; undefined4 uStack_20; undefined4 uStack_1c; int iStack_14;
  
  iVar1 = *(int *)(param_3 + 4);
  FUN_00553db0();
  if (param_1[0x4f3] != 0) {
    param_1[0x4f3] = 0;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x94))((int *)param_1[0x440],0x100,param_1 + 0x503);
    *param_1 = uVar2;
  }
  if (param_1[0x53c] != 0) {
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x1c,1);
    *param_1 = uVar2;
  }
  if (param_1[0x4f1] != 1) {
    param_1[0x4f1] = 1;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x88,1);
    *param_1 = uVar2;
  }
  FUN_00554be0(1);
  param_1[0x45c] = 0x100;
  if ((*(byte *)(iVar1 + 0x9c) & 0x20) != 0) {
    FUN_00554be0(0);
    param_1[0x45c] = param_1[0x45c] | 0x800;
  }
  if ((*(byte *)(iVar1 + 0x9c) & 0x40) != 0) {
    param_1[0x45c] = param_1[0x45c] | 0x400;
  }
  if (*(char *)(*(int *)(iVar1 + 0xa8) + 0x40) < '\0') {
    param_1[0x45c] = param_1[0x45c] | 1;
  }
  FUN_00554790(param_1[0x45c],*(undefined4 *)(iVar1 + 0xac),
               *(undefined4 *)(*(int *)(iVar1 + 0xa8) + 0x84));
  iVar5 = *(int *)(iVar1 + 0xa4);
  iVar4 = 0;
  iStack_4c = 0;
  if (0 < iVar5) {
    do {
      iVar6 = 0;
      if (iVar4 < iVar5) {
        iVar5 = iVar4 * 0x94;
        do {
          if ((int)param_1[0x4ec] <= iVar6) break;
          iVar4 = FUN_005504d0(0,iVar4);
          if (iVar4 == 0) { uStack_20 = 0; iStack_14 = 0; }
          else {
            iVar3 = FUN_00554f80(param_2,iVar4);
            if (iVar3 == 0) { return; }
            uStack_20 = 7; uStack_1c = 2; iStack_14 = iVar4;
            if ((char)*(undefined4 *)(*(int *)(iVar1 + 0xa8) + 0x40 + iVar5) < '\0') {
              uStack_1c = 3;
            }
          }
          FUN_005546a0(local_40,iVar6);
          iVar4 = iStack_4c + 1;
          iVar5 = iVar5 + 0x94;
          iVar6 = iVar6 + 1;
          iStack_4c = iVar4;
        } while (iVar4 < *(int *)(iVar1 + 0xa4));
      }
      FUN_00553fa0(iVar6);
      FUN_00554700(*(undefined4 *)(param_3 + 0x1c));
      uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x154))
                        ((int *)param_1[0x440],*(undefined4 *)(*(int *)(param_3 + 0x24) + 0x18),
                         *(undefined4 *)(param_3 + 0x2c));
      *param_1 = uVar2;
      if ((*param_3 & 0x10) == 0) { iVar5 = param_2 / 3; uVar2 = *(undefined4 *)(param_3 + 0x30); uVar7 = 4; }
      else { iVar5 = param_2 / 2; uVar2 = *(undefined4 *)(param_3 + 0x30); uVar7 = 2; }
      uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                        ((int *)param_1[0x440],uVar7,0,unaff_retaddr,uVar2,iVar5);
      *param_1 = uVar2;
      iVar5 = *(int *)(iVar1 + 0xa4);
    } while (iVar4 < iVar5);
  }
  if (param_1[0x53c] != 0) {
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x1c,0);
    *param_1 = uVar2;
  }
  return;
}
```# Worker 5 — Full Review Entries
## FUN_00557ce0 (0x00557ce0)
- **Size:** 1581 bytes
- **Source:** decompiled_full/0x00557ce0__FUN_00557ce0.c

```c
undefined4 __thiscall FUN_00557ce0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  void *pvVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  
  iVar2 = FUN_00545f40();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_005474d0(param_2,*(undefined4 *)(param_2 + 0x58),*(undefined4 *)(param_2 + 0x5c),
                       param_2 + 0x70,param_2 + 0x90,*(undefined4 *)(param_2 + 0x68));
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_005487a0();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  iVar2 = *(int *)(param_2 + 0x24);
  if (0 < iVar2) {
    *(int *)(param_1 + 0x2c) = iVar2;
    piVar3 = operator_new(iVar2 * 0x80 + 4);
    if (piVar3 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = piVar3 + 1;
      *piVar3 = iVar2;
      if (-1 < iVar2 + -1) {
        do {
          FUN_005573a0();
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    *(int **)(param_1 + 0x34) = piVar4;
    pcVar5 = param_2;
    do {
      cVar1 = *pcVar5;
      pcVar5[param_1 - (int)param_2] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(param_1);
    pvVar6 = operator_new(*(int *)(param_1 + 0x2c) << 2);
    *(void **)(param_1 + 0x40) = pvVar6;
    pvVar6 = operator_new(*(int *)(param_1 + 0x2c) << 2);
    *(void **)(param_1 + 0x3c) = pvVar6;
    if ((param_2[0x58] & 0x20U) == 0) {
      param_2[100] = '\x02';
      param_2[0x65] = '\0';
      param_2[0x66] = '\x01';
      param_2[0x67] = '\0';
    }
    *(undefined4 *)(param_1 + 0x4c) = 1;
    puVar7 = operator_new(0x44);
    if (puVar7 == (undefined4 *)0x0) {
      puVar12 = (undefined4 *)0x0;
    }
    else {
      puVar12 = puVar7 + 1;
      *puVar7 = 1;
      FUN_0053c2a0();
    }
    *(undefined4 **)(param_1 + 0x50) = puVar12;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    uVar8 = FUN_00548890(param_1);
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 4) = uVar8;
    if (*(int *)(*(int *)(param_1 + 0x50) + 4) != 0) {
      FUN_005473c0();
      FUN_00547240(*(uint *)(param_2 + 100) & 0xffff,*(undefined2 *)(param_2 + 0x66));
      if (0 < *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 4) + 0xa4)) {
        FUN_0054fcb0(*(undefined4 *)(param_2 + 0x68));
        FUN_0054fcc0(*(undefined4 *)(param_2 + 0x6c));
      }
    }
    **(undefined4 **)(param_1 + 0x50) = 0;
    if ((param_2[0x58] & 8U) != 0) {
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 1;
    }
    if ((param_2[0x58] & 0x10U) != 0) {
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 2;
    }
    if ((param_2[0x20] & 0x10U) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x210;
    }
    if ((param_2[0x20] & 0x20U) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x220;
    }
    if ((*(uint *)(param_2 + 0x20) & 0x200) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x200;
    }
    uVar10 = *(uint *)(param_2 + 0x20);
    if ((uVar10 & 1) == 0) {
      if ((uVar10 & 4) != 0) {
        return 0xffffffff;
      }
      if ((uVar10 & 2) != 0) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 2;
        *(undefined4 *)(param_1 + 0x24) = 8;
        if ((**(byte **)(param_1 + 0x50) & 0x10) == 0) {
          *(undefined4 *)(param_1 + 0x28) = 0x24;
        }
        else {
          *(undefined4 *)(param_1 + 0x28) = 0x30;
        }
        *(int *)(*(byte **)(param_1 + 0x50) + 8) = *(int *)(param_1 + 0x2c) << 3;
        *(int *)(*(int *)(param_1 + 0x50) + 0x10) =
             *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x28);
        if ((param_2[0x20] & 0x80U) == 0) {
          iVar2 = *(int *)(param_1 + 0x24);
        }
        else {
          iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 8);
        }
        pvVar6 = operator_new(iVar2 * 0x24);
        *(void **)(*(int *)(param_1 + 0x50) + 0xc) = pvVar6;
        pvVar6 = operator_new(*(int *)(*(int *)(param_1 + 0x50) + 0x10) << 1);
        *(void **)(*(int *)(param_1 + 0x50) + 0x14) = pvVar6;
        uVar10 = *(uint *)(param_2 + 0x60);
        if ((uVar10 & 0xff000000) == 0) {
          uVar10 = uVar10 | 0xff000000;
        }
        if ((param_2[0x20] & 0x80U) == 0) {
          puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x50) + 0xc);
          puVar7[6] = uVar10;
          puVar7[1] = 0x3d4ccccd;
          *puVar7 = 0xbd4ccccd;
          puVar7[2] = 0xbd4ccccd;
          puVar7[9] = 0xbd4ccccd;
          puVar7[10] = 0xbd4ccccd;
          puVar7[0xb] = 0xbd4ccccd;
          puVar7[0xf] = uVar10;
          puVar7[0x12] = 0x3d4ccccd;
          puVar7[0x13] = 0xbd4ccccd;
          puVar7[0x14] = 0xbd4ccccd;
          puVar7[0x18] = uVar10;
          puVar7[0x1b] = 0x3d4ccccd;
          puVar7[0x1c] = 0x3d4ccccd;
          puVar7[0x1d] = 0xbd4ccccd;
          puVar7[0x21] = uVar10;
          puVar7[0x24] = 0xbd4ccccd;
          puVar7[0x25] = 0x3d4ccccd;
          puVar7[0x26] = 0x3d4ccccd;
          puVar7[0x2a] = uVar10;
          puVar7[0x2d] = 0xbd4ccccd;
          puVar7[0x2e] = 0xbd4ccccd;
          puVar7[0x2f] = 0x3d4ccccd;
          puVar7[0x33] = uVar10;
          puVar7[0x36] = 0x3d4ccccd;
          puVar7[0x37] = 0xbd4ccccd;
          puVar7[0x38] = 0x3d4ccccd;
          puVar7[0x3c] = uVar10;
          puVar7[0x3f] = 0x3d4ccccd;
          puVar7[0x40] = 0x3d4ccccd;
          puVar7[0x41] = 0x3d4ccccd;
          puVar7[0x45] = uVar10;
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x2c)) {
            iVar11 = 0;
            do {
              *(int *)(*(int *)(param_1 + 0x34) + 4 + iVar11) = iVar2;
              *(uint *)(*(int *)(param_1 + 0x34) + 0xc + iVar11) = uVar10;
              iVar2 = iVar2 + 1;
              iVar11 = iVar11 + 0x80;
            } while (iVar2 < *(int *)(param_1 + 0x2c));
          }
        }
        else {
          iVar2 = 0;
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x80;
          if (0 < *(int *)(param_1 + 0x2c)) {
            param_2 = (char *)0x0;
            do {
              iVar9 = *(int *)(param_1 + 0x24) * iVar2;
              iVar11 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
              *(undefined4 *)(iVar11 + iVar9 * 0x24) = 0xbf000000;
              *(undefined4 *)(iVar11 + 4 + iVar9 * 0x24) = 0x3f000000;
              *(undefined4 *)(iVar11 + 8 + iVar9 * 0x24) = 0xbf000000;
              *(uint *)(iVar11 + 0x18 + iVar9 * 0x24) = uVar10;
              iVar11 = iVar11 + iVar9 * 0x24;
              *(undefined4 *)(iVar11 + 0x24) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x28) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x2c) = 0xbf000000;
              *(uint *)(iVar11 + 0x3c) = uVar10;
              *(undefined4 *)(iVar11 + 0x48) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x4c) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x50) = 0xbf000000;
              *(uint *)(iVar11 + 0x60) = uVar10;
              *(undefined4 *)(iVar11 + 0x6c) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x70) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x74) = 0xbf000000;
              *(uint *)(iVar11 + 0x84) = uVar10;
              *(undefined4 *)(iVar11 + 0x90) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x94) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x98) = 0x3f000000;
              *(uint *)(iVar11 + 0xa8) = uVar10;
              *(undefined4 *)(iVar11 + 0xb4) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0xb8) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0xbc) = 0x3f000000;
              *(uint *)(iVar11 + 0xcc) = uVar10;
              *(undefined4 *)(iVar11 + 0xd8) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0xdc) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0xe0) = 0x3f000000;
              *(uint *)(iVar11 + 0xf0) = uVar10;
              *(undefined4 *)(iVar11 + 0xfc) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x100) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x104) = 0x3f000000;
              *(uint *)(iVar11 + 0x114) = uVar10;
              *(int *)((int)param_2 + 4 + *(int *)(param_1 + 0x34)) = iVar2;
              *(uint *)((int)param_2 + 0xc + *(int *)(param_1 + 0x34)) = uVar10;
              param_2 = (char *)((int)param_2 + 0x80);
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(int *)(param_1 + 0x2c));
          }
        }
      }
    }
    else {
      uVar10 = *(uint *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar10 | 1;
      *(undefined4 *)(param_1 + 0x24) = 4;
      if ((uVar10 & 0x200) == 0) {
        *(undefined4 *)(param_1 + 0x28) = 0xc;
      }
      else {
        *(undefined4 *)(param_1 + 0x28) = 6;
      }
      *(int *)(*(int *)(param_1 + 0x50) + 8) = *(int *)(param_1 + 0x2c) << 2;
      *(int *)(*(int *)(param_1 + 0x50) + 0x10) =
           *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x28);
      if ((param_2[0x20] & 0x80U) == 0) {
        pvVar6 = operator_new(0x90);
        *(void **)(*(int *)(param_1 + 0x50) + 0xc) = pvVar6;
      }
      else {
        pvVar6 = operator_new(*(int *)(*(int *)(param_1 + 0x50) + 8) * 0x24);
        *(void **)(*(int *)(param_1 + 0x50) + 0xc) = pvVar6;
      }
      pvVar6 = operator_new(*(int *)(*(int *)(param_1 + 0x50) + 0x10) << 1);
      *(void **)(*(int *)(param_1 + 0x50) + 0x14) = pvVar6;
      uVar10 = *(uint *)(param_2 + 0x60);
      if ((uVar10 & 0xff000000) == 0) {
        uVar10 = uVar10 | 0xff000000;
      }
      if ((param_2[0x20] & 0x80U) == 0) {
        puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x50) + 0xc);
        puVar7[6] = uVar10;
        puVar7[1] = 0x3f000000;
        puVar7[2] = 0;
        *puVar7 = 0xbf000000;
        puVar7[9] = 0xbf000000;
        puVar7[10] = 0xbf000000;
        puVar7[0xb] = 0;
        puVar7[0xf] = uVar10;
        puVar7[0x12] = 0x3f000000;
        puVar7[0x13] = 0xbf000000;
        puVar7[0x14] = 0;
        puVar7[0x18] = uVar10;
        puVar7[0x1b] = 0x3f000000;
        puVar7[0x1c] = 0x3f000000;
        puVar7[0x1d] = 0;
        puVar7[0x21] = uVar10;
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x2c)) {
          iVar11 = 0;
          do {
            *(int *)(*(int *)(param_1 + 0x34) + 4 + iVar11) = iVar2;
            *(uint *)(*(int *)(param_1 + 0x34) + 0xc + iVar11) = uVar10;
            iVar2 = iVar2 + 1;
            iVar11 = iVar11 + 0x80;
          } while (iVar2 < *(int *)(param_1 + 0x2c));
        }
      }
      else {
        iVar2 = 0;
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x80;
        if (0 < *(int *)(param_1 + 0x2c)) {
          param_2 = (char *)0x0;
          do {
            iVar9 = *(int *)(param_1 + 0x24) * iVar2;
            iVar11 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
            *(undefined4 *)(iVar11 + iVar9 * 0x24) = 0xbf000000;
            *(undefined4 *)(iVar11 + 4 + iVar9 * 0x24) = 0x3f000000;
            *(uint *)(iVar11 + 0x18 + iVar9 * 0x24) = uVar10;
            iVar11 = iVar11 + iVar9 * 0x24;
            *(undefined4 *)(iVar11 + 8) = 0;
            *(undefined4 *)(iVar11 + 0x24) = 0xbf000000;
            *(undefined4 *)(iVar11 + 0x28) = 0xbf000000;
            *(undefined4 *)(iVar11 + 0x2c) = 0;
            *(uint *)(iVar11 + 0x3c) = uVar10;
            *(undefined4 *)(iVar11 + 0x48) = 0x3f000000;
            *(undefined4 *)(iVar11 + 0x4c) = 0xbf000000;
            *(undefined4 *)(iVar11 + 0x50) = 0;
            *(uint *)(iVar11 + 0x60) = uVar10;
            *(undefined4 *)(iVar11 + 0x6c) = 0x3f000000;
            *(undefined4 *)(iVar11 + 0x70) = 0x3f000000;
            *(undefined4 *)(iVar11 + 0x74) = 0;
            *(uint *)(iVar11 + 0x84) = uVar10;
            *(int *)(*(int *)(param_1 + 0x34) + 4 + (int)param_2) = iVar2;
            *(uint *)(*(int *)(param_1 + 0x34) + 0xc + (int)param_2) = uVar10;
            param_2 = (char *)((int)param_2 + 0x80);
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_1 + 0x2c));
        }
      }
    }
    pvVar6 = operator_new(*(int *)(param_1 + 0x4c) << 2);
    *(void **)(param_1 + 0x44) = pvVar6;
    pvVar6 = operator_new(*(int *)(param_1 + 0x4c) << 2);
    *(void **)(param_1 + 0x48) = pvVar6;
    return 0;
  }
  return 0xffffffff;
}
```
## FUN_0056f100 (0x0056f100)
- **Size:** 1367 bytes
- **Source:** decompiled_full/0x0056f100__FUN_0056f100.c

```c
void __thiscall FUN_0056f100(uint *param_1,undefined4 *param_2,double *param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  uint uVar2, uVar3, uVar4;
  double dVar5, dVar6, dVar7;
  bool bVar8;
  int iVar9;
  uint uVar12, uVar15, uVar16;
  double local_1b8, local_1b0, local_1a0, local_198, local_190;
  char local_140 [32];
  double local_120, local_118, local_110, local_108, local_100, local_f8;
  double local_e8, local_e0, local_d8, local_d0, local_c8;
  double local_c0, local_b8, local_b0, local_a8, local_a0, local_98;
  double local_90 [2], local_80, local_78, local_70, local_68, local_60, local_50;
  undefined1 local_48 [72];
  
  if (param_5 == '\0') {
    for (uVar15 = *param_1; (int)uVar15 > 0; uVar15--) local_140[uVar15-1] = 1;
  } else {
    for (uVar15 = *param_1; (int)uVar15 > 0; uVar15--) local_140[uVar15-1] = 0;
    for (iVar9 = 0; iVar9 < (int)*param_1; iVar9++)
      if (param_2 == (undefined4 *)param_1[1]) { local_140[iVar9]=1; break; }
    // Fixpoint propagation loop
    do {
      bVar8 = false;
      for (int lc = 0; lc < iVar9; lc++) {
        uVar3 = *(uint *)(base + 4); uVar4 = *(uint *)(base + 0xc);
        for (int k = 0; k < (int)*param_1; k++)
          if (local_140[k] && ((uVar3==param_1[1]+k*0x244)||(uVar4==param_1[1]+k*0x244)))
            for (int m = 0; m < (int)*param_1; m++)
              if (uVar16 == param_1[1]) { bVar8|=local_140[m]==0; local_140[m]=1; break; }
      }
    } while (bVar8);
  }
  // Copy transform params & rotation matrix
  FUN_0056bd40(param_4);
  FUN_0056c740(local_48);
  for (int idx = 0; idx < (int)*param_1; idx++) {
    if (local_140[idx]) {
      puVar17 = (undefined4 *)(param_1[1] + idx*0x244);
      dVar5 = *(double *)(puVar17 + 1) - local_108;
      dVar7 = *(double *)(puVar17 + 3) - local_100;
      dVar6 = *(double *)(puVar17 + 5) - local_f8;
      local_1b8 = mat[0]*dVar5 + mat[1]*dVar7 + mat[2]*dVar6;
      local_1b0 = mat[3]*dVar5 + mat[4]*dVar7 + mat[5]*dVar6;
      dVar5 = mat[6]*dVar5 + mat[7]*dVar7 + mat[8]*dVar6;
      local_e8 = local_c0*local_1b8 + local_b8*local_1b0 + local_b0*dVar5;
      local_e0 = local_a8*local_1b8 + local_a0*local_1b0 + local_98*dVar5;
      local_120 = local_d8*local_1b8 + local_d0*local_1b0 + local_c8*dVar5 + *param_3;
      local_118 = local_e8 + param_3[1];
      local_110 = local_e0 + param_3[2];
      FUN_0056c740(local_90);
      FUN_005691d0(&local_1a0);
    }
  }
}
```
## FUN_00575882 (0x00575882)
- **Size:** 827 bytes
- **Source:** decompiled_full/0x00575882__FUN_00575882.c

```c
// Function: FUN_00575882 @ 00575882
// Size (bytes): 827


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00575882(int *param_1,double *param_2)

{
  short *psVar1;
  uint uVar2;
  short local_f0 [108];
  uint local_18;
  int *local_14;
  int local_10;
  int local_a;
  bool local_5;
  
  uVar2 = 0;
  local_f0[0] = 9;
  local_f0[1] = 4;
  local_f0[2] = 2;
  local_f0[3] = 2;
  local_f0[4] = 0;
  local_f0[5] = 0xb;
  local_f0[6] = 7;
  local_f0[7] = 4;
  local_f0[8] = 2;
  local_f0[9] = 2;
  local_f0[10] = 0;
  local_f0[0xb] = 0xb;
  local_f0[0xc] = 6;
  local_f0[0xd] = 4;
  local_f0[0xe] = 2;
  local_f0[0xf] = 2;
  local_f0[0x10] = 0;
  local_f0[0x11] = 0xb;
  local_f0[0x12] = 5;
  local_f0[0x13] = 4;
  local_f0[0x14] = 2;
  local_f0[0x15] = 2;
  local_f0[0x16] = 0;
  local_f0[0x17] = 0xb;
  local_f0[0x18] = 4;
  local_f0[0x19] = 4;
  local_f0[0x1a] = 2;
  local_f0[0x1b] = 2;
  local_f0[0x1c] = 0;
  local_f0[0x1d] = 0xb;
  local_f0[0x1e] = 3;
  local_f0[0x1f] = 4;
  local_f0[0x20] = 2;
  local_f0[0x21] = 2;
  local_f0[0x22] = 0;
  local_f0[0x23] = 0xb;
  local_f0[0x24] = 2;
  local_f0[0x25] = 4;
  local_f0[0x26] = 2;
  local_f0[0x27] = 2;
  local_f0[0x28] = 0;
  local_f0[0x29] = 0xb;
  local_f0[0x2a] = 1;
  local_f0[0x2b] = 4;
  local_f0[0x2c] = 2;
  local_f0[0x2d] = 2;
  local_f0[0x2e] = 0;
  local_f0[0x2f] = 0xb;
  local_f0[0x30] = 0;
  local_f0[0x31] = 4;
  local_f0[0x32] = 2;
  local_f0[0x33] = 2;
  local_f0[0x34] = 0;
  local_f0[0x35] = 0x10;
  local_f0[0x36] = 2;
  local_f0[0x37] = 2;
  local_f0[0x38] = 0;
  local_f0[0x39] = 0xb;
  local_f0[0x3a] = 3;
  local_f0[0x3b] = 8;
  local_f0[0x3c] = 4;
  local_f0[0x3d] = 4;
  local_f0[0x3e] = 2;
  local_f0[0x3f] = 8;
  local_f0[0x40] = 4;
  local_f0[0x41] = 4;
  local_f0[0x42] = 1;
  local_f0[0x43] = 8;
  local_f0[0x44] = 4;
  local_f0[0x45] = 4;
  local_f0[0x46] = 0;
  local_f0[0x47] = 8;
  local_f0[0x48] = 4;
  local_f0[0x49] = 0xd;
  local_f0[0x4a] = 4;
  local_f0[0x4b] = 4;
  local_f0[0x4c] = 1;
  local_f0[0x4d] = 2;
  local_f0[0x4e] = 0;
  local_f0[0x4f] = 1;
  local_f0[0x50] = 10;
  local_f0[0x51] = 2;
  local_f0[0x52] = 0;
  local_f0[0x53] = 1;
  local_f0[0x54] = 9;
  local_f0[0x55] = 2;
  local_f0[0x56] = 0;
  local_f0[0x57] = 1;
  local_f0[0x58] = 0xb;
  local_f0[0x59] = 0;
  local_f0[0x5a] = 1;
  local_f0[0x5b] = 4;
  local_f0[0x5c] = 5;
  local_f0[0x5d] = 0;
  local_f0[0x5e] = 1;
  local_f0[0x5f] = 4;
  local_f0[0x60] = 4;
  local_f0[0x61] = 0;
  local_f0[0x62] = 1;
  local_f0[99] = 4;
  local_f0[100] = 4;
  local_f0[0x65] = 1;
  local_f0[0x66] = 10;
  local_f0[0x67] = 4;
  local_f0[0x68] = 4;
  local_f0[0x69] = 4;
  local_f0[0x6a] = 0x31;
  local_a = 0;
  local_10 = 0;
  local_5 = true;
  if (param_2 == (double *)0x22) {
    local_18 = 1;
    local_14 = param_1;
    do {
      if ((int)local_18 < 0x22) {
        param_2 = (double *)(*local_14 + local_18 * 8);
        param_1 = (int *)local_18;
        do {
          uVar2 = (uint)(byte)(local_5 ^ *param_2 != _DAT_0059e430);
          if (uVar2 == 0) {
            local_a = local_a + 1;
          }
          else {
            if (0x6a < local_10) goto LAB_00575ba9;
            psVar1 = local_f0 + local_10;
            uVar2 = CONCAT22((short)((uint)local_10 >> 0x10),*psVar1);
            local_10 = local_10 + 1;
            if ((short)local_a != *psVar1) goto LAB_00575ba9;
            local_a = 0;
            local_5 = local_5 == false;
          }
          param_1 = (int *)((int)param_1 + 1);
          param_2 = param_2 + 1;
        } while ((int)param_1 < 0x22);
      }
      local_14 = local_14 + 1;
      uVar2 = local_18 + 1;
      local_18 = uVar2;
    } while ((int)uVar2 < 0x23);
    if (local_10 == 0x6a) {
      return (uint)((short)local_a == 0x31);
    }
  }
LAB_00575ba9:
  return uVar2 & 0xffffff00;
}
```
## FUN_00558e70 (0x00558e70)
- **Size:** 889 bytes
- **Source:** decompiled_full/0x00558e70__FUN_00558e70.c

```c
// Function: FUN_00558e70 @ 00558e70
// Size (bytes): 889


void __thiscall FUN_00558e70(int param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  float *pfVar7;
  float local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  float local_98;
  float local_94;
  uint *local_90;
  uint uStack_8c;
  int local_88;
  float local_84;
  float fStack_80;
  int local_7c;
  int local_78;
  uint *local_74;
  short sStack_70;
  uint uStack_6c;
  uint local_40 [10];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int iStack_8;
  
  if (*(char *)(param_1 + 0x20) < '\0') {
    if (*(int *)(param_1 + 0x30) != 0) {
      iStack_8 = 0;
      iStack_c = 0x5591d1;
      FUN_00558d80();
      iStack_8 = *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x30);
      iStack_c = *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x30);
      uStack_10 = *(undefined4 *)(param_1 + 0x50);
      uStack_14 = param_2;
      uStack_18 = 0x5591f5;
      FUN_0055cf50();
    }
    return;
  }
  if (*(int *)(param_1 + 0x30) == 0) {
    return;
  }
  FUN_0053b130();
  if ((*(uint *)(param_1 + 0x20) & 0x20) == 0) {
    if ((*(uint *)(param_1 + 0x20) & 0x10) == 0) goto LAB_00558f27;
    FUN_00542490(&local_94,&local_a8,&local_98);
    local_98 = -local_98;
    local_94 = -local_94;
  }
  else {
    FUN_00542490(&local_94,&local_a8,&local_98);
    local_98 = 0.0;
    local_94 = 0.0;
  }
  FUN_0053b240(local_94,-local_a8,local_98);
LAB_00558f27:
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x44) + iVar3 * 4) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x48) + iVar3 * 4) = 0;
      FUN_00558d10(iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x4c));
  }
  puVar2 = *(uint **)(param_1 + 0x38);
  pfVar7 = &local_84;
  uVar6 = 2;
  local_90 = puVar2;
  FUN_005457c0(0);
  FUN_0055d560(uVar6,pfVar7);
  while (puVar2 != (uint *)0x0) {
    if ((*(byte *)(param_1 + 0x20) & 0x30) != 0) {
      puVar4 = local_40;
      puVar5 = puVar2 + 0xe;
      for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_0053b170(&local_a0,&local_9c,&local_a4);
      FUN_0053b200(local_a0,local_9c,local_a4);
    }
    if ((*puVar2 & 0x4000) != 0) {
      FUN_0053b1d0(&local_a0,&local_9c,&local_a4);
      FUN_0053b330(local_a0,local_9c,local_a4);
    }
    FUN_0053b350();
    local_78 = 0;
    if (0 < *(int *)(param_1 + 0x4c)) {
      local_88 = 0;
      do {
        iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 0xc + local_88);
        iVar1 = *(int *)(param_1 + 0x50) + local_88;
        local_7c = 0;
        if (0 < *(int *)(iVar1 + 8)) {
          local_74 = puVar2 + 0xe;
          iVar1 = *(int *)(*(int *)(param_1 + 0x44) + local_78 * 4) * 0x40 + *(int *)(iVar1 + 0x20);
          do {
            (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,iVar3,iVar1,local_74);
            *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar3 + 0x1c);
            *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar3 + 0x20);
            uStack_8c = puVar2[3];
            uStack_6c = *(uint *)(iVar3 + 0x18);
            fStack_80 = (float)(uStack_8c >> 0x18) * local_84;
            sStack_70 = (short)ROUND(fStack_80);
            iVar3 = iVar3 + 0x24;
            *(int *)(iVar1 + 0x18) =
                 ((((int)(((uStack_6c >> 0x10 & 0xff) + 1) * (uStack_8c >> 0x10 & 0xff)) >> 8) +
                  sStack_70 * 0x100) * 0x100 +
                 ((int)(((uStack_6c >> 8 & 0xff) + 1) * (uStack_8c >> 8 & 0xff)) >> 8)) * 0x100 +
                 ((int)(((uStack_6c & 0xff) + 1) * (uStack_8c & 0xff)) >> 8);
            local_7c = local_7c + 1;
            puVar2 = local_90;
            iVar1 = iVar1 + 0x40;
          } while (local_7c < *(int *)(local_88 + 8 + *(int *)(param_1 + 0x50)));
        }
        *(int *)(*(int *)(param_1 + 0x44) + local_78 * 4) =
             *(int *)(*(int *)(param_1 + 0x44) + local_78 * 4) +
             *(int *)(local_88 + 8 + *(int *)(param_1 + 0x50));
        *(int *)(*(int *)(param_1 + 0x48) + local_78 * 4) =
             *(int *)(*(int *)(param_1 + 0x48) + local_78 * 4) +
             *(int *)(local_88 + 0x10 + *(int *)(param_1 + 0x50));
        local_78 = local_78 + 1;
        local_88 = local_88 + 0x40;
      } while (local_78 < *(int *)(param_1 + 0x4c));
    }
    puVar2 = (uint *)puVar2[0x1f];
    local_90 = puVar2;
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    iVar1 = 0;
    do {
      FUN_00558d80(iVar3);
      FUN_0055cf50(param_2,*(int *)(param_1 + 0x50) + iVar1,
                   *(undefined4 *)(*(int *)(param_1 + 0x44) + iVar3 * 4),
                   *(undefined4 *)(*(int *)(param_1 + 0x48) + iVar3 * 4));
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x40;
    } while (iVar3 < *(int *)(param_1 + 0x4c));
  }
  FUN_0053b160();
  return;
}
```
## FUN_0055c450 (0x0055c450)
- **Size:** 477 bytes
- **Source:** decompiled_full/0x0055c450__FUN_0055c450.c

```c
// Function: FUN_0055c450 @ 0055c450
// Size (bytes): 477


void FUN_0055c450(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (0x28 < param_1) {
    if (param_1 < 0x33545845) {
      if (param_1 == 0x33545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 0xb;
        return;
      }
      if (param_1 == 0x29) goto LAB_0055c580;
      if (param_1 == 0x31545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 9;
        return;
      }
      if (param_1 == 0x32545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 10;
        return;
      }
    }
    else {
      if (param_1 == 0x34545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 0xc;
        return;
      }
      if (param_1 == 0x35545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 0xd;
        return;
      }
    }
switchD_0055c46f_default:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *param_3 = 0;
    return;
  }
  if (param_1 == 0x28) {
LAB_0055c580:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 8;
    }
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *param_3 = 4;
    return;
  }
  switch(param_1) {
  case 0x14:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x18;
    }
    goto LAB_0055c4b7;
  case 0x15:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x20;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 8;
      return;
    }
    break;
  case 0x16:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x20;
    }
LAB_0055c4b7:
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 7;
      return;
    }
    break;
  case 0x17:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x10;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 6;
      return;
    }
    break;
  case 0x18:
  case 0x19:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x10;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 5;
      return;
    }
    break;
  default:
    goto switchD_0055c46f_default;
  }
  return;
}
```
## FUN_0058ca19 (0x0058ca19)
- **Size:** 473 bytes
- **Source:** decompiled_full/0x0058ca19__FUN_0058ca19.c

```c
// Function: FUN_0058ca19 @ 0058ca19
// Size (bytes): 473


int FUN_0058ca19(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  BOOL BVar5;
  DWORD DVar6;
  undefined4 *puVar7;
  char *pcVar8;
  int iVar9;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_008d4920 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_008d4920)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
        param_3 = (char *)((int)param_3 - 1);
        *param_2 = cVar3;
        pcVar8 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar9) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),pcVar8,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          puVar7 = (undefined4 *)FUN_0058afcf();
          *puVar7 = 9;
          puVar7 = (undefined4 *)FUN_0058afd8();
          *puVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_0058af5c(DVar6);
        }
        return -1;
      }
      bVar4 = *(byte *)(*piVar1 + 4 + iVar9);
      if ((bVar4 & 0x80) == 0) {
        return (int)local_c + local_10;
      }
      if ((local_10 == 0) || (*param_2 != '\n')) {
        bVar4 = bVar4 & 0xfb;
      }
      else {
        bVar4 = bVar4 | 4;
      }
      *(byte *)(*piVar1 + 4 + iVar9) = bVar4;
      param_3 = param_2;
      local_c = param_2 + (int)local_c + local_10;
      pcVar8 = param_2;
      if (param_2 < local_c) {
        do {
          cVar3 = *param_3;
          if (cVar3 == '\x1a') {
            pbVar2 = (byte *)(*piVar1 + 4 + iVar9);
            bVar4 = *pbVar2;
            if ((bVar4 & 0x40) == 0) {
              *pbVar2 = bVar4 | 2;
            }
            break;
          }
          if (cVar3 == '\r') {
            if (param_3 < local_c + -1) {
              if (param_3[1] == '\n') {
                param_3 = param_3 + 2;
                goto LAB_0058cba4;
              }
              *pcVar8 = '\r';
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
            else {
              param_3 = param_3 + 1;
              BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),&local_5,1,&local_10,(LPOVERLAPPED)0x0);
              if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_0058cbbe:
                *pcVar8 = '\r';
LAB_0058cbc1:
                pcVar8 = pcVar8 + 1;
              }
              else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_0058cba4:
                  *pcVar8 = '\n';
                  goto LAB_0058cbc1;
                }
                FUN_0058c789(param_1,0xffffffff,1);
                if (local_5 != '\n') goto LAB_0058cbbe;
              }
              else {
                if (local_5 == '\n') goto LAB_0058cba4;
                *pcVar8 = '\r';
                pcVar8 = pcVar8 + 1;
                *(char *)(*piVar1 + 5 + iVar9) = local_5;
              }
            }
          }
          else {
            *pcVar8 = cVar3;
            pcVar8 = pcVar8 + 1;
            param_3 = param_3 + 1;
          }
        } while (param_3 < local_c);
      }
      return (int)pcVar8 - (int)param_2;
    }
  }
  return 0;
}
```
## FUN_00553fc0 (0x00553fc0)
- **Size:** 620 bytes
- **Source:** decompiled_full/0x00553fc0__FUN_00553fc0.c

```c
// Function: FUN_00553fc0 @ 00553fc0
// Size (bytes): 620


void __thiscall FUN_00553fc0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_2 == -1) {
    return;
  }
  if (param_2 == param_1[9]) {
    return;
  }
  switch(param_2) {
  case 0:
    piVar1 = param_1 + 1;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00553fe4_caseD_3;
    uVar4 = 1;
    *piVar1 = 1;
    uVar3 = 1;
    goto LAB_00554212;
  case 1:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,2);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    piVar1 = param_1 + 3;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00553fe4_caseD_3;
    *piVar1 = 1;
    break;
  case 2:
  case 8:
    iVar2 = FUN_00554260(1,7);
    if (iVar2 != 0) {
      uVar4 = 7;
LAB_005541c8:
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,uVar4);
    }
    goto LAB_005541db;
  default:
    goto switchD_00553fe4_caseD_3;
  case 4:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 4)) {
      *piVar1 = 4;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,4);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    piVar1 = param_1 + 3;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 1)) goto switchD_00553fe4_caseD_3;
    *piVar1 = 1;
    break;
  case 5:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,2);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 3)) goto switchD_00553fe4_caseD_3;
    uVar4 = 3;
    *piVar1 = 3;
    uVar3 = 2;
    goto LAB_00554212;
  case 6:
    piVar1 = param_1 + 1;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 4)) {
      *piVar1 = 4;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,1,4);
    }
    piVar1 = param_1 + 2;
    if ((piVar1 != (int *)0x0) && (*piVar1 != 2)) {
      *piVar1 = 2;
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    piVar1 = param_1 + 3;
    if ((piVar1 == (int *)0x0) || (*piVar1 == 3)) goto switchD_00553fe4_caseD_3;
    *piVar1 = 3;
    uVar4 = 3;
    goto LAB_00554210;
  case 7:
  case 0xc:
    iVar2 = FUN_00554260(1,4);
    if (iVar2 != 0) {
      uVar4 = 4;
      goto LAB_005541c8;
    }
LAB_005541db:
    iVar2 = FUN_00554260(2,2);
    if (iVar2 != 0) {
      (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,2,2);
    }
    iVar2 = FUN_00554260(3,1);
    if (iVar2 == 0) goto switchD_00553fe4_caseD_3;
  }
  uVar4 = 1;
LAB_00554210:
  uVar3 = 3;
LAB_00554212:
  (**(code **)(*DAT_008b89a0 + 0xfc))(DAT_008b89a0,*param_1,uVar3,uVar4);
switchD_00553fe4_caseD_3:
  param_1[9] = param_2;
  return;
}
```
## FUN_005919da (0x005919da)
- **Size:** 535 bytes
- **Source:** decompiled_full/0x005919da__FUN_005919da.c

```c
// Function: FUN_005919da @ 005919da
// Size (bytes): 535


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_005919da(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  float10 fVar5;
  undefined8 local_10;
  int local_8;
  
  uVar3 = param_1 & 0x1f;
  bVar2 = true;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_00591e89(1);
    uVar3 = param_1 & 0x17;
    goto LAB_00591bcf;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_00591e89(4);
    uVar3 = param_1 & 0x1b;
    goto LAB_00591bcf;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar4 = (param_1 & 0x10) != 0;
      if (*param_2 != _DAT_005b8cc8) {
        fVar5 = (float10)FUN_00591d88(*param_2,&local_8);
        local_8 = local_8 + -0x600;
        if (local_8 < -0x432) {
          local_10 = 0.0;
          bVar4 = bVar2;
        }
        else {
          local_10 = (double)(ulonglong)
                             (SUB87((double)fVar5,0) & 0xfffffffffffff | 0x10000000000000);
          if (local_8 < -0x3fd) {
            local_8 = -0x3fd - local_8;
            do {
              if ((((ulonglong)local_10 & 1) != 0) && (!bVar4)) {
                bVar4 = bVar2;
              }
              uVar3 = (uint)local_10 >> 1;
              if (((ulonglong)local_10 & 0x100000000) != 0) {
                local_10._3_1_ = (byte)((ulonglong)local_10 >> 0x18) >> 1;
                local_10._0_3_ = (undefined3)uVar3;
                local_10._0_4_ = CONCAT13(local_10._3_1_,(undefined3)local_10) | 0x80000000;
                uVar3 = (uint)local_10;
              }
              local_10._0_4_ = uVar3;
              local_10 = (double)CONCAT44(local_10._4_4_ >> 1,(uint)local_10);
              local_8 = local_8 + -1;
            } while (local_8 != 0);
          }
          if ((double)fVar5 < _DAT_005b8cc8) {
            local_10 = -local_10;
          }
        }
        *param_2 = local_10;
        bVar2 = bVar4;
      }
      if (bVar2) {
        FUN_00591e89(0x10);
      }
      uVar3 = param_1 & 0x1d;
    }
    goto LAB_00591bcf;
  }
  FUN_00591e89(8);
  uVar3 = param_3 & 0xc00;
  dVar1 = _DAT_005e7718;
  if (uVar3 == 0) {
    if (*param_2 <= _DAT_005b8cc8) {
      dVar1 = -_DAT_005e7718;
    }
LAB_00591aef:
    *param_2 = dVar1;
  }
  else {
    if (uVar3 == 0x400) {
      dVar1 = _DAT_005e7728;
      if (*param_2 <= _DAT_005b8cc8) {
        dVar1 = -_DAT_005e7718;
      }
      goto LAB_00591aef;
    }
    if (uVar3 == 0x800) {
      if (*param_2 <= _DAT_005b8cc8) {
        dVar1 = -_DAT_005e7728;
      }
      goto LAB_00591aef;
    }
    if (uVar3 == 0xc00) {
      dVar1 = _DAT_005e7728;
      if (*param_2 <= _DAT_005b8cc8) {
        dVar1 = -_DAT_005e7728;
      }
      goto LAB_00591aef;
    }
  }
  uVar3 = param_1 & 0x1e;
LAB_00591bcf:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_00591e89(0x20);
    uVar3 = uVar3 & 0xffffffef;
  }
  return uVar3 == 0;
}
```
## FUN_00592f2c (0x00592f2c)
- **Size:** 444 bytes
- **Source:** decompiled_full/0x00592f2c__FUN_00592f2c.c

```c
// Function: FUN_00592f2c @ 00592f2c
// Size (bytes): 444


void FUN_00592f2c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int iVar6;
  uint uVar7;
  UINT UVar8;
  UINT UVar9;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  puVar2 = _malloc(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_008d4a20 = 0x20;
  DAT_008d4920 = puVar2;
  for (; puVar2 < DAT_008d4920 + 0x120; puVar2 = puVar2 + 9) {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = 0xffffffff;
    puVar2[2] = 0;
    *(undefined1 *)((int)puVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_8 = (byte *)((int)pUVar5 + UVar8);
    if (0x7ff < (int)UVar8) {
      UVar8 = 0x800;
    }
    UVar9 = UVar8;
    if ((int)DAT_008d4a20 < (int)UVar8) {
      puVar2 = &DAT_008d4924;
      do {
        puVar3 = _malloc(0x480);
        UVar9 = DAT_008d4a20;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_008d4a20 = DAT_008d4a20 + 0x20;
        *puVar2 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar2;
        }
        puVar2 = puVar2 + 1;
        UVar9 = UVar8;
      } while ((int)DAT_008d4a20 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_008d4920)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)local_8;
          *(byte *)(puVar2 + 1) = (byte)*pUVar5;
        }
        local_8 = local_8 + 4;
        uVar7 = uVar7 + 1;
        pUVar5 = (UINT *)((int)pUVar5 + 1);
      } while ((int)uVar7 < (int)UVar9);
    }
  }
  iVar6 = 0;
  do {
    puVar2 = DAT_008d4920 + iVar6 * 9;
    if (DAT_008d4920[iVar6 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;
          }
          goto LAB_005930d1;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_005930d1:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_008d4a20);
      return;
    }
  } while( true );
}
```
## FUN_00594e1a (0x00594e1a)
- **Size:** 292 bytes
- **Source:** decompiled_full/0x00594e1a__FUN_00594e1a.c

```c
// Function: FUN_00594e1a @ 00594e1a
// Size (bytes): 292


int FUN_00594e1a(int *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)*param_1;
  pbVar1 = (byte *)(param_1 + 0x3e);
  bVar3 = (byte)param_3;
  if ((uint)param_1[1] < param_3) {
    pbVar6 = pbVar2;
    if (pbVar2[param_1[1]] != 0) {
      pbVar6 = pbVar2 + param_1[1];
    }
    while( true ) {
      while( true ) {
        if (pbVar1 <= pbVar6 + param_3) {
          pbVar6 = (byte *)(param_1 + 2);
          while( true ) {
            while( true ) {
              if (pbVar2 <= pbVar6) {
                return 0;
              }
              if (pbVar1 <= pbVar6 + param_3) {
                return 0;
              }
              if (*pbVar6 == 0) break;
              pbVar6 = pbVar6 + *pbVar6;
            }
            uVar5 = 1;
            pbVar4 = pbVar6;
            while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {
              uVar5 = uVar5 + 1;
            }
            if (param_3 <= uVar5) break;
            param_2 = param_2 - uVar5;
            pbVar6 = pbVar4;
            if (param_2 < param_3) {
              return 0;
            }
          }
          if (pbVar6 + param_3 < pbVar1) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            param_1[1] = 0;
            *param_1 = (int)(param_1 + 2);
          }
          *pbVar6 = bVar3;
          pbVar2 = pbVar6 + 8;
          goto LAB_00594f2d;
        }
        if (*pbVar6 == 0) break;
        pbVar6 = pbVar6 + *pbVar6;
      }
      uVar5 = 1;
      pbVar4 = pbVar6;
      while (pbVar4 = pbVar4 + 1, *pbVar4 == 0) {
        uVar5 = uVar5 + 1;
      }
      if (param_3 <= uVar5) break;
      if (pbVar6 == pbVar2) {
        param_1[1] = uVar5;
        pbVar6 = pbVar4;
      }
      else {
        param_2 = param_2 - uVar5;
        pbVar6 = pbVar4;
        if (param_2 < param_3) {
          return 0;
        }
      }
    }
    if (pbVar6 + param_3 < pbVar1) {
      *param_1 = (int)(pbVar6 + param_3);
      param_1[1] = uVar5 - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    *pbVar6 = bVar3;
    pbVar2 = pbVar6 + 8;
  }
  else {
    *pbVar2 = bVar3;
    if (pbVar2 + param_3 < pbVar1) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    pbVar2 = pbVar2 + 8;
  }
LAB_00594f2d:
  return (int)pbVar2 * 0x10 + (int)param_1 * -0xf;
}
```
## FUN_00553700 (0x00553700)
- **Size:** 633 bytes
- **Source:** decompiled_full/0x00553700__FUN_00553700.c

```c
// Function: FUN_00553700 @ 00553700
// Size (bytes): 633


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00553700(uint *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 local_1fc [5];
  undefined4 local_1e8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined1 local_1bc [444];
  
  if (0 < (int)param_1[1]) {
    uVar1 = *param_1;
    if ((char)(uVar1 >> 8) < '\0') {
      *param_1 = uVar1 & 0xffff7fff;
      if ((uVar1 & 1) == 0) {
        if ((uVar1 & 2) != 0) {
          iVar2 = FUN_00540f00(param_1[5],0x60,0,0);
          iVar5 = 0;
          if (0 < (int)param_1[1]) {
            iVar4 = 0;
            puVar3 = (undefined4 *)(iVar2 + 8);
            do {
              puVar3[-2] = *(undefined4 *)(iVar4 + param_1[6]);
              puVar3[-1] = *(undefined4 *)(iVar4 + 4 + param_1[6]);
              *puVar3 = *(undefined4 *)(iVar4 + 8 + param_1[6]);
              puVar3[1] = *(undefined4 *)(iVar4 + 0xc + param_1[6]);
              puVar3[3] = *(undefined4 *)(iVar4 + 0x14 + param_1[6]);
              puVar3[4] = *(undefined4 *)(iVar4 + 0x18 + param_1[6]);
              puVar3[2] = *(undefined4 *)(iVar4 + 0x10 + param_1[6]);
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 0x1c;
              puVar3 = puVar3 + 7;
            } while (iVar5 < (int)param_1[1]);
          }
        }
      }
      else {
        iVar2 = FUN_00540f00(param_1[5],0x60,0,0);
        iVar5 = 0;
        if (0 < (int)param_1[1]) {
          iVar4 = 0;
          puVar3 = (undefined4 *)(iVar2 + 8);
          do {
            puVar3[-2] = *(undefined4 *)(iVar4 + param_1[6]);
            puVar3[-1] = *(undefined4 *)(iVar4 + 4 + param_1[6]);
            *puVar3 = *(undefined4 *)(iVar4 + 8 + param_1[6]);
            puVar3[2] = *(undefined4 *)(iVar4 + 0x10 + param_1[6]);
            puVar3[3] = *(undefined4 *)(iVar4 + 0x14 + param_1[6]);
            puVar3[1] = *(undefined4 *)(iVar4 + 0xc + param_1[6]);
            iVar5 = iVar5 + 1;
            iVar4 = iVar4 + 0x18;
            puVar3 = puVar3 + 6;
          } while (iVar5 < (int)param_1[1]);
        }
      }
      FUN_00540f90(param_1[5]);
    }
    if (DAT_008b8df0 == 0) {
      FUN_005550a0();
    }
    if (param_2 != DAT_008b8dc8) {
      FUN_0055cdf0();
      FUN_0053b130();
      FUN_0055ca40(2,local_1fc);
      local_1fc[0] = 0x3f22f983;
      local_1e8 = 0x3f22f983;
      local_1d4 = 0x3de38e39;
      local_1d0 = 0x3f800000;
      local_1c4 = 0xbc360b61;
      local_1c0 = 0;
      FUN_0055ca40(4,local_1fc);
      FUN_0055ca90(param_2,1);
      FUN_0053b160();
    }
    if (1 < DAT_008b8cec) {
      FUN_005418b0();
      FUN_00542200(_DAT_008b8cf0,0,_DAT_008b8cf4,0x3f800000,0);
      FUN_0055cc20(local_1bc);
      FUN_00557470();
    }
    FUN_00541120(DAT_008b8f28,param_1[5],0,param_1[1],param_1[4],param_1[2],param_1[3],3,2);
    if (DAT_008b8df0 == 0) {
      FUN_005550c0();
    }
    if (param_2 != DAT_008b8dc8) {
      FUN_0055ca90(DAT_008b8dc8,1);
      FUN_0055ce50();
    }
  }
  return;
}
```
## FUN_00552910 (0x00552910)
- **Size:** 646 bytes
- **Source:** decompiled_full/0x00552910__FUN_00552910.c

```c
// Function: FUN_00552910 @ 00552910
// Size (bytes): 646


undefined1 __thiscall
FUN_00552910(int param_1,byte param_2,int param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  float *pfVar14;
  
  if ((0x1f < param_2) && (uVar12 = (uint)param_2, (int)uVar12 < *(int *)(param_1 + 0x44))) {
    iVar11 = (int)*(short *)(param_1 + -0x98 + uVar12 * 8);
    iVar13 = (int)*(short *)(param_1 + -0x96 + uVar12 * 8);
    iVar9 = *(int *)(param_1 + 0x34) + -1;
    iVar10 = *(int *)(param_1 + 0x38) + -1;
    if ((*(uint *)(param_1 + 0x24) & 0x10000) != 0) {
      FUN_00543250(iVar11,iVar13 + 1,param_5,param_3,param_4,iVar9,*(int *)(param_1 + 0x38) + -2,
                   *(undefined4 *)(param_1 + 0x2c),0);
      return *(undefined1 *)(param_1 + -0x94 + uVar12 * 8);
    }
    fVar1 = (float)param_3 * *(float *)(param_1 + 0x5c);
    fVar2 = (float)param_4 * *(float *)(param_1 + 0x60);
    fVar3 = (float)(iVar9 + param_3) * *(float *)(param_1 + 0x5c);
    fVar4 = (float)(iVar10 + param_4) * *(float *)(param_1 + 0x60);
    fVar6 = (float)*(int *)(*(int *)(param_1 + 100) + 0x1c);
    fVar5 = (float)iVar11 / fVar6;
    fVar7 = (float)*(int *)(*(int *)(param_1 + 100) + 0x20);
    fVar8 = (float)iVar13 / fVar7;
    fVar6 = (float)iVar9 / fVar6 + fVar5;
    fVar7 = (float)iVar10 / fVar7 + fVar8;
    **(float **)(param_1 + 0x10) = fVar1;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar5;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar8;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar1;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar5;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar7;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar3;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar6;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar7;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar3;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar6;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar7;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar3;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar6;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar8;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar1;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar5;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar8;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 0x1c;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 6;
    return *(undefined1 *)(param_1 + -0x94 + uVar12 * 8);
  }
  return 0;
}
```
## FUN_00598323 (0x00598323)
- **Size:** 391 bytes
- **Source:** decompiled_full/0x00598323__FUN_00598323.c

```c
// Function: FUN_00598323 @ 00598323
// Size (bytes): 391


undefined4 FUN_00598323(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  LPCSTR lpName;
  int *piVar5;
  bool bVar6;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar1 = (char *)FUN_00598569(param_1,0x3d);
  if (pcVar1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pcVar1) {
    return 0xffffffff;
  }
  bVar6 = pcVar1[1] == '\0';
  if (DAT_008d3e90 == DAT_008d3e94) {
    DAT_008d3e90 = (int *)FUN_00598502(DAT_008d3e90);
  }
  if (DAT_008d3e90 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_008d3e98 == (undefined4 *)0x0)) {
      if (bVar6) {
        return 0;
      }
      DAT_008d3e90 = _malloc(4);
      if (DAT_008d3e90 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_008d3e90 = 0;
      if (DAT_008d3e98 == (undefined4 *)0x0) {
        DAT_008d3e98 = _malloc(4);
        if (DAT_008d3e98 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_008d3e98 = 0;
      }
    }
    else {
      iVar2 = FUN_00597fac();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_008d3e90;
  iVar2 = FUN_005984aa(param_1,(int)pcVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar6) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = (int *)FUN_0058b5d4(piVar3,iVar2 * 4 + 8);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar6) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_00598457;
    }
    piVar5 = piVar3 + iVar2;
    FUN_0058aa6f(piVar3[iVar2]);
    for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
      iVar2 = iVar2 + 1;
      *piVar5 = piVar5[1];
    }
    piVar3 = (int *)FUN_0058b5d4(piVar3,iVar2 << 2);
    if (piVar3 == (int *)0x0) goto LAB_00598457;
  }
  DAT_008d3e90 = piVar3;
LAB_00598457:
  if (param_2 != 0) {
    sVar4 = _strlen(param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (LPCSTR)0x0) {
      FUN_0058fca0(lpName,param_1);
      pcVar1[(int)lpName - (int)param_1] = '\0';
      SetEnvironmentVariableA
                (lpName,(LPCSTR)(~-(uint)bVar6 & (uint)(pcVar1 + ((int)lpName - (int)param_1) + 1)))
      ;
      FUN_0058aa6f(lpName);
    }
  }
  return 0;
}
```
## FUN_00560c10 (0x00560c10)
- **Size:** 567 bytes
- **Source:** decompiled_full/0x00560c10__FUN_00560c10.c

```c
// Function: FUN_00560c10 @ 00560c10
// Size (bytes): 567


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00560c10(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float *pfVar6;
  float fVar7;
  undefined4 uVar8;
  float local_10c;
  undefined1 local_108 [4];
  float local_104;
  undefined1 local_100 [256];
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x138) + 0x40);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x230) == 0)) {
    if ((*(byte *)(param_1 + 0x24) & 1) != 0) goto LAB_00560e11;
    FUN_0058815f(local_100,s_FSHADOWVIEW__3d_005dd84b + 1,*(undefined4 *)(param_1 + 0x28));
    pvVar3 = operator_new(0x1bc);
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_005418b0();
    }
    *(undefined4 **)(param_1 + 0xc) = puVar4;
    *puVar4 = param_2;
    FUN_005418e0(local_100);
    fVar7 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x24);
    *(uint *)(param_1 + 0x24) = uVar2 | 4;
    if ((uVar2 & 1) != 0) goto LAB_00560e11;
    FUN_0058815f(local_100,s_FSHADOWVIEW__3d_005dd84b + 1,*(undefined4 *)(param_1 + 0x28));
    pvVar3 = operator_new(0x1bc);
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_005418b0();
    }
    *(undefined4 **)(param_1 + 0xc) = puVar4;
    *puVar4 = param_2;
    FUN_005418e0(local_100);
    fVar7 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
  }
  FUN_005423c0(_DAT_005dd848 - (fVar7 + fVar7),_DAT_005dd848 + fVar7 + fVar7);
  FUN_005423e0(0,0,0);
  FUN_005457c0(0);
  pfVar6 = &local_10c;
  FUN_0055d590(pfVar6,local_108,&local_104);
  uVar8 = 0;
  fVar5 = (float10)fpatan(-(float10)local_10c,(float10)local_104);
  fVar7 = (float)fVar5;
  fVar5 = (float10)FUN_00588570(pfVar6,fVar7,0);
  FUN_00541db0((float)fVar5,fVar7,uVar8);
  fVar5 = (float10)fpatan((float10)*(float *)(*(int *)(param_1 + 0x18) + 0x18) *
                          (float10)_DAT_005b8998,(float10)_DAT_005dd848);
  fVar7 = (float)(ABS(fVar5) + ABS(fVar5));
  FUN_00542050(fVar7,fVar7,1);
  FUN_00542200(0,0,(float)DAT_008b8df4,(float)DAT_008b8df4,1);
  pvVar3 = operator_new(0x4c);
  if (pvVar3 == (void *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_00556220();
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar8;
  FUN_00556260(1);
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_00560b60(0x400);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar8;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 1;
LAB_00560e11:
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00560c10(param_2,1);
  }
  if ((*(int *)(param_1 + 0x34) != 0) && (param_3 != 0)) {
    FUN_00560c10(param_2,1);
  }
  return 0;
}
```
## FUN_00552ba0 (0x00552ba0)
- **Size:** 457 bytes
- **Source:** decompiled_full/0x00552ba0__FUN_00552ba0.c

```c
// Function: FUN_00552ba0 @ 00552ba0
// Size (bytes): 457


void __fastcall FUN_00552ba0(int param_1)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int local_14;
  char *local_10;
  
  uVar3 = (*(int *)(*(int *)(param_1 + 100) + 0x30) != 5) - 1 & 0x8000;
  puVar4 = (ushort *)FUN_00543210(*(undefined4 *)(*(int *)(param_1 + 100) + 0x18),0);
  iVar9 = *(int *)(param_1 + 100);
  iVar5 = *(int *)(iVar9 + 0x20);
  iVar12 = *(int *)(iVar9 + 0x28) >> 1;
  iVar7 = (iVar5 + -2) * iVar12 + *(int *)(iVar9 + 0x1c);
  *(uint *)(param_1 + 0x28) = (uint)puVar4[iVar7 + -1];
  *(uint *)(param_1 + 0x2c) = (uint)puVar4[iVar7 + -2];
  *(uint *)(param_1 + 0x30) = (uint)puVar4[iVar7 + -3];
  iVar7 = 1;
  do {
    iVar11 = iVar7;
    iVar7 = iVar11 + 1;
  } while ((uint)*(ushort *)((int)puVar4 + iVar11 * 2 + *(int *)(iVar9 + 0x28)) !=
           *(uint *)(param_1 + 0x28));
  *(int *)(param_1 + 0x34) = iVar11;
  puVar8 = puVar4 + iVar12 + 1;
  *(int *)(param_1 + 0x3c) = *(int *)(iVar9 + 0x1c) / iVar11;
  iVar9 = 1;
  do {
    iVar7 = iVar9;
    uVar2 = *puVar8;
    puVar8 = puVar8 + iVar12;
    iVar9 = iVar7 + 1;
  } while ((uint)uVar2 != *(uint *)(param_1 + 0x28));
  iVar5 = iVar5 / iVar7;
  *(int *)(param_1 + 0x38) = iVar7;
  iVar9 = *(int *)(param_1 + 0x3c) * iVar5;
  *(int *)(param_1 + 0x40) = iVar5;
  *(int *)(param_1 + 0x44) = iVar9 + 0x20;
  local_14 = 0;
  if (0 < iVar9) {
    local_10 = (char *)(param_1 + 0x6d);
    do {
      iVar12 = *(int *)(param_1 + 0x34) * (local_14 % *(int *)(param_1 + 0x3c)) + 1;
      iVar11 = *(int *)(param_1 + 0x38) * (local_14 / *(int *)(param_1 + 0x3c)) + 1;
      iVar7 = *(int *)(*(int *)(param_1 + 100) + 0x28) * iVar11;
      uVar2 = *(ushort *)((int)puVar4 + iVar12 * 2 + iVar7);
      iVar5 = 0;
      while (((uint)uVar2 != *(uint *)(param_1 + 0x30) &&
             (iVar6 = iVar5 + 1, iVar6 < *(int *)(param_1 + 0x34)))) {
        uVar2 = *(ushort *)((int)puVar4 + iVar6 * 2 + iVar12 * 2 + iVar7);
        iVar5 = iVar6;
      }
      local_10[-1] = (char)iVar5;
      *local_10 = *(char *)(param_1 + 0x38) + -1;
      *(short *)(local_10 + -5) = (short)iVar12;
      local_14 = local_14 + 1;
      *(short *)(local_10 + -3) = (short)iVar11;
      local_10 = local_10 + 8;
    } while (local_14 < iVar9);
  }
  iVar9 = *(int *)(*(int *)(param_1 + 100) + 0x20) * *(int *)(*(int *)(param_1 + 100) + 0x1c);
  if (0 < iVar9) {
    do {
      uVar10 = (uint)*puVar4;
      uVar2 = (ushort)uVar3;
      if (((uVar10 == *(uint *)(param_1 + 0x30)) || (uVar10 == *(uint *)(param_1 + 0x28))) ||
         (uVar10 == *(uint *)(param_1 + 0x2c))) {
        *puVar4 = ~uVar2 & *(ushort *)(param_1 + 0x2c);
        puVar1 = (uint *)(*(int *)(param_1 + 100) + 0x18);
        *puVar1 = *puVar1 | 0x800;
      }
      else {
        *puVar4 = *puVar4 | uVar2;
      }
      puVar4 = puVar4 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & ~uVar3;
  FUN_00543230(*(undefined4 *)(*(int *)(param_1 + 100) + 0x18),0);
  return;
}
```
## FUN_005939f9 (0x005939f9)
- **Size:** 440 bytes
- **Source:** decompiled_full/0x005939f9__FUN_005939f9.c

```c
// Function: FUN_005939f9 @ 005939f9
// Size (bytes): 440


void FUN_005939f9(int param_1,int param_2,byte *param_3,byte *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_005b9968;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  if (*(int *)(param_3 + 4) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_3 + 4) + 8) == '\0') {
    return;
  }
  if (*(int *)(param_3 + 8) == 0) {
    return;
  }
  piVar1 = (int *)(*(int *)(param_3 + 8) + 0xc + param_2);
  local_8 = 0;
  if ((*param_3 & 8) == 0) {
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        ExceptionList = &local_14;
        iVar2 = FUN_00597321(*(undefined4 *)(param_1 + 0x18),1);
        if ((iVar2 != 0) && (iVar2 = FUN_0059733d(piVar1,1), iVar2 != 0)) {
          uVar3 = FUN_00593c24(*(undefined4 *)(param_1 + 0x18),param_4 + 8,
                               *(undefined4 *)(param_4 + 0x14));
          FUN_0058b130(piVar1,uVar3);
          ExceptionList = local_14;
          return;
        }
      }
      else {
        ExceptionList = &local_14;
        iVar2 = FUN_00597321(*(undefined4 *)(param_1 + 0x18),1);
        if (((iVar2 != 0) && (iVar2 = FUN_0059733d(piVar1,1), iVar2 != 0)) &&
           (iVar2 = FUN_00597359(*(undefined4 *)(param_4 + 0x18)), iVar2 != 0)) {
          if ((*param_4 & 4) != 0) {
            uVar3 = FUN_00593c24(*(undefined4 *)(param_1 + 0x18),param_4 + 8,1);
            FUN_0058a32a(piVar1,*(undefined4 *)(param_4 + 0x18),uVar3);
            ExceptionList = local_14;
            return;
          }
          uVar3 = FUN_00593c24(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
          FUN_0058a323(piVar1,*(undefined4 *)(param_4 + 0x18),uVar3);
          ExceptionList = local_14;
          return;
        }
      }
    }
    else {
      ExceptionList = &local_14;
      iVar2 = FUN_00597321(*(undefined4 *)(param_1 + 0x18),1);
      if ((iVar2 != 0) && (iVar2 = FUN_0059733d(piVar1,1), iVar2 != 0)) {
        FUN_0058b130(piVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          ExceptionList = local_14;
          return;
        }
        iVar2 = *piVar1;
        if (iVar2 == 0) {
          ExceptionList = local_14;
          return;
        }
        goto LAB_00593a87;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    iVar2 = FUN_00597321(*(undefined4 *)(param_1 + 0x18),1);
    if ((iVar2 != 0) && (iVar2 = FUN_0059733d(piVar1,1), iVar2 != 0)) {
      iVar2 = *(int *)(param_1 + 0x18);
      *piVar1 = iVar2;
LAB_00593a87:
      iVar2 = FUN_00593c24(iVar2,param_4 + 8);
      *piVar1 = iVar2;
      ExceptionList = local_14;
      return;
    }
  }
  FUN_00593cfd();
  ExceptionList = local_14;
  return;
}
```
## FUN_00583ae0 (0x00583ae0)
- **Size:** 602 bytes
- **Source:** decompiled_full/0x00583ae0__FUN_00583ae0.c

```c
// Function: FUN_00583ae0 @ 00583ae0
// Size (bytes): 602


void __fastcall FUN_00583ae0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  BOOL BVar3;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0059d046;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_005b8b60;
  piVar1 = (int *)param_1[0x47];
  local_4 = 0xc;
  param_1[0x49] = piVar1;
  if ((piVar1 != (int *)0x0) && (iVar2 = *piVar1, iVar2 != 0)) {
    while( true ) {
      FUN_00583210(iVar2,0);
      if (param_1[0x49] == 0) break;
      piVar1 = *(int **)(param_1[0x49] + 4);
      param_1[0x49] = piVar1;
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) break;
    }
  }
  local_4 = CONCAT31(local_4._1_3_,0xb);
  if ((*(char *)(param_1 + 0x192) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[400]), BVar3 != 0)) {
    param_1[400] = 0;
  }
  FUN_005870d0();
  if ((*(char *)(param_1 + 0x188) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x186]), BVar3 != 0)) {
    param_1[0x186] = 0;
  }
  if ((*(char *)(param_1 + 0x170) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x16e]), BVar3 != 0)) {
    param_1[0x16e] = 0;
  }
  local_4._0_1_ = 8;
  if ((*(char *)(param_1 + 0x16c) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x16a]), BVar3 != 0)) {
    param_1[0x16a] = 0;
  }
  FUN_005833e0();
  local_4._0_1_ = 7;
  if ((*(char *)(param_1 + 0x165) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x163]), BVar3 != 0)) {
    param_1[0x163] = 0;
  }
  FUN_005833e0();
  local_4._0_1_ = 6;
  if ((*(char *)(param_1 + 0x15e) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x15c]), BVar3 != 0)) {
    param_1[0x15c] = 0;
  }
  FUN_005833e0();
  local_4._0_1_ = 0xd;
  FUN_00582310();
  local_4._0_1_ = 5;
  FUN_005833e0();
  local_4._0_1_ = 4;
  FUN_004b0170();
  local_4._0_1_ = 3;
  FUN_00585fb0();
  local_4._0_1_ = 0xf;
  FUN_00585fb0();
  local_4._0_1_ = 0xe;
  FUN_00585fb0();
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00586460();
  if ((*(char *)(param_1 + 0x3e) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x3c]), BVar3 != 0)) {
    param_1[0x3c] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  if ((*(char *)(param_1 + 0x37) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x35]), BVar3 != 0)) {
    param_1[0x35] = 0;
  }
  FUN_00583650();
  local_4 = 0xffffffff;
  FUN_0058a5f7(param_1 + 1,0x28,1,FUN_00583aa0);
  ExceptionList = local_c;
  return;
}
```
## FUN_005890aa (0x005890aa)
- **Size:** 340 bytes
- **Source:** decompiled_full/0x005890aa__FUN_005890aa.c

```c
// Function: FUN_005890aa @ 005890aa
// Size (bytes): 340


void FUN_005890aa(uint *param_1,uint *param_2,uint param_3,code *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_fc [30];
  uint local_84 [30];
  uint local_c;
  int local_8;
  
  if ((param_2 < 2) || (param_3 == 0)) {
    return;
  }
  local_8 = 0;
  iVar4 = (int)param_2 - 1;
  param_2 = local_fc;
  uVar5 = iVar4 * param_3 + (int)param_1;
  uVar3 = (uint)param_1;
  param_1 = local_84;
LAB_005890e9:
  uVar2 = (uVar5 - uVar3) / param_3 + 1;
  if (8 < uVar2) {
    FUN_0058924c((uVar2 >> 1) * param_3 + uVar3,uVar3,param_3);
    uVar2 = param_3 + uVar5;
    local_c = uVar3;
LAB_00589140:
    local_c = local_c + param_3;
    if (local_c <= uVar5) goto code_r0x0058914d;
    goto LAB_00589158;
  }
  FUN_005891fe(uVar3,uVar5,param_3,param_4);
  goto LAB_00589108;
code_r0x0058914d:
  iVar4 = (*param_4)(local_c,uVar3);
  if (iVar4 < 1) goto LAB_00589140;
LAB_00589158:
  do {
    uVar2 = uVar2 - param_3;
    if (uVar2 <= uVar3) break;
    iVar4 = (*param_4)(uVar2,uVar3);
  } while (-1 < iVar4);
  if (local_c <= uVar2) {
    FUN_0058924c(local_c,uVar2,param_3);
    goto LAB_00589140;
  }
  FUN_0058924c(uVar3,uVar2,param_3);
  uVar1 = local_c;
  if ((int)((uVar2 - uVar3) + -1) < (int)(uVar5 - local_c)) {
    if (local_c < uVar5) {
      local_8 = local_8 + 1;
      *param_2 = local_c;
      *param_1 = uVar5;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if (param_3 + uVar3 < uVar2) {
      uVar5 = uVar2 - param_3;
      goto LAB_005890e9;
    }
  }
  else {
    if (uVar3 + param_3 < uVar2) {
      local_8 = local_8 + 1;
      *param_2 = uVar3;
      *param_1 = uVar2 - param_3;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    uVar3 = uVar1;
    if (uVar1 < uVar5) goto LAB_005890e9;
  }
LAB_00589108:
  local_8 = local_8 + -1;
  param_2 = param_2 + -1;
  param_1 = param_1 + -1;
  if (local_8 < 0) {
    return;
  }
  uVar5 = *param_1;
  uVar3 = *param_2;
  goto LAB_005890e9;
}
```
## FUN_00582ba0 (0x00582ba0)
- **Size:** 305 bytes
- **Source:** decompiled_full/0x00582ba0__FUN_00582ba0.c

```c
// Function: FUN_00582ba0 @ 00582ba0
// Size (bytes): 305


void __fastcall FUN_00582ba0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cd76;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = operator_new(4);
  puVar5 = (undefined4 *)0x0;
  local_4 = 0;
  if (local_14 == (int *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    puVar2 = operator_new(0x26c);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (puVar2 != (undefined4 *)0x0) {
      puVar5 = puVar2 + 1;
      *puVar2 = 2;
      FUN_0058a6eb(puVar5,0x134,2,FUN_00581e80,FUN_0057bc70);
    }
    *local_14 = (int)puVar5;
  }
  iVar4 = 0;
  local_4 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    puVar5 = operator_new(0xc);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = local_14;
      puVar5[1] = 0;
      *(undefined1 *)(puVar5 + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)puVar5;
      param_1[2] = (int)puVar5;
      param_1[1] = (int)puVar5;
      param_1[3] = param_1[3] + 1;
    }
    else {
      *(undefined4 **)(param_1[1] + 4) = puVar5;
      param_1[1] = (int)puVar5;
      param_1[3] = param_1[3] + 1;
    }
  }
  do {
    iVar1 = *local_14;
    if (iVar1 + iVar4 != 0) {
      piVar3 = operator_new(0xc);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        *piVar3 = iVar1 + iVar4;
        piVar3[1] = 0;
        *(undefined1 *)(piVar3 + 2) = 0;
      }
      if (param_1[4] == 0) {
        param_1[5] = (int)piVar3;
        param_1[6] = (int)piVar3;
      }
      else {
        piVar3[1] = param_1[4];
      }
      param_1[4] = (int)piVar3;
      param_1[7] = param_1[7] + 1;
    }
    iVar4 = iVar4 + 0x134;
  } while (iVar4 < 0x268);
  ExceptionList = local_c;
  return;
}
```
## FUN_005665b0 (0x005665b0)
- **Size:** 157 bytes
- **Source:** decompiled_full/0x005665b0__FUN_005665b0.c

```c
// Function: FUN_005665b0 @ 005665b0
// Size (bytes): 157


void __thiscall FUN_005665b0(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  
  if (param_2 != (char *)0x0) {
    if ((char *)*param_1 == (char *)0x0) {
      FUN_00566650(param_2);
      return;
    }
    uVar3 = 0xffffffff;
    pcVar5 = (char *)*param_1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar5 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar7 = ~uVar3 + (~uVar4 - 2);
    if ((int)param_1[1] < iVar7) {
      pcVar2 = operator_new(iVar7 + 1);
      pcVar5 = (char *)*param_1;
      pcVar6 = pcVar2;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        *pcVar6 = cVar1;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00587bcf(*param_1);
      *param_1 = pcVar2;
      param_1[1] = iVar7;
    }
    uVar3 = 0xffffffff;
    do {
      pcVar5 = param_2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar5 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar5;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar7 = -1;
    pcVar6 = (char *)*param_1;
    do {
      pcVar2 = pcVar6;
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pcVar2 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar2;
    } while (cVar1 != '\0');
    pcVar5 = pcVar5 + -uVar3;
    pcVar6 = pcVar2 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  return;
}
```
## FUN_0056a5d0 (0x0056a5d0)
- **Size:** 617 bytes
- **Source:** decompiled_full/0x0056a5d0__FUN_0056a5d0.c

```c
// Function: FUN_0056a5d0 @ 0056a5d0
// Size (bytes): 617


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056a5d0(int param_1,double *param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double *pdVar7;
  int iVar8;
  int local_90;
  int local_8c;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  undefined1 local_38 [24];
  undefined1 local_20 [28];
  
  dVar4 = _DAT_005e5240 * *(double *)(param_1 + 0x7c) + *param_2;
  dVar5 = _DAT_005e5240 * *(double *)(param_1 + 0x84) + param_2[1];
  dVar6 = _DAT_005e5240 * *(double *)(param_1 + 0x8c) + param_2[2];
  local_8c = 0;
  if (0 < *(int *)(param_1 + 0x234)) {
    local_90 = 0;
    do {
      iVar8 = *(int *)(param_1 + 0x238) + local_90;
      iVar1 = *(int *)(iVar8 + 0x78);
      iVar2 = *(int *)(iVar8 + 0x7c);
      dVar3 = (*(double *)(*(int *)(param_1 + 0x238) + 0x70 + local_90) * *(double *)(iVar8 + 0x50)
              - *(double *)(iVar8 + 0x68) * *(double *)(iVar8 + 0x58)) * *(double *)(param_1 + 0x7c)
              + (*(double *)(iVar8 + 0x60) * *(double *)(iVar8 + 0x58) -
                *(double *)(iVar8 + 0x70) * *(double *)(iVar8 + 0x48)) * *(double *)(param_1 + 0x84)
                + (*(double *)(iVar8 + 0x68) * *(double *)(iVar8 + 0x48) -
                  *(double *)(iVar8 + 0x60) * *(double *)(iVar8 + 0x50)) *
                  *(double *)(param_1 + 0x8c);
      local_40 = *(double *)(iVar8 + 0x48) * *(double *)(param_1 + 0x7c) +
                 *(double *)(param_1 + 0x84) * *(double *)(iVar8 + 0x50) +
                 *(double *)(param_1 + 0x8c) * *(double *)(iVar8 + 0x58);
      local_48 = *(double *)(iVar8 + 0x60) * *(double *)(param_1 + 0x7c) +
                 *(double *)(iVar8 + 0x68) * *(double *)(param_1 + 0x84) +
                 *(double *)(iVar8 + 0x70) * *(double *)(param_1 + 0x8c);
      if (*(char *)(iVar8 + 0x80) == '\0') {
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + iVar2 * 8);
        *pdVar7 = ((dVar5 * *(double *)(iVar8 + 0x50) +
                   dVar6 * *(double *)(iVar8 + 0x58) + dVar4 * *(double *)(iVar8 + 0x48)) -
                  local_48 * dVar3) + *pdVar7;
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + 8 + iVar2 * 8);
        dVar3 = local_40 * dVar3 +
                dVar4 * *(double *)(iVar8 + 0x60) +
                dVar5 * *(double *)(iVar8 + 0x68) + dVar6 * *(double *)(iVar8 + 0x70) + *pdVar7;
      }
      else {
        FUN_00435e00(iVar8,local_38);
        FUN_00435e00(*(undefined4 *)(iVar1 + 0x10),local_20);
        FUN_0056c540(&local_60);
        local_60 = local_60 * _DAT_005e5238;
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + iVar2 * 8);
        local_58 = local_58 * _DAT_005e5238;
        local_50 = local_50 * _DAT_005e5238;
        *pdVar7 = *pdVar7 - (((local_58 + dVar5) * *(double *)(iVar8 + 0x50) +
                             (local_50 + dVar6) * *(double *)(iVar8 + 0x58) +
                             (local_60 + dVar4) * *(double *)(iVar8 + 0x48)) - local_48 * dVar3);
        pdVar7 = (double *)(*(int *)(param_1 + 0x224) + 8 + iVar2 * 8);
        dVar3 = *pdVar7 - (local_40 * dVar3 +
                          (local_60 + dVar4) * *(double *)(iVar8 + 0x60) +
                          (local_58 + dVar5) * *(double *)(iVar8 + 0x68) +
                          (local_50 + dVar6) * *(double *)(iVar8 + 0x70));
      }
      *pdVar7 = dVar3;
      local_8c = local_8c + 1;
      local_90 = local_90 + 0x84;
    } while (local_8c < *(int *)(param_1 + 0x234));
  }
  return;
}
```
## FUN_0058ab58 (0x0058ab58)
- **Size:** 289 bytes
- **Source:** decompiled_full/0x0058ab58__FUN_0058ab58.c

```c
// Function: FUN_0058ab58 @ 0058ab58
// Size (bytes): 289


LPVOID FUN_0058ab58(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint _Size;
  LPVOID local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_005b8d00;
  puStack_10 = &LAB_0058895c;
  local_14 = ExceptionList;
  uVar2 = param_1 * param_2;
  uVar3 = uVar2;
  ExceptionList = &local_14;
  if (uVar2 < 0xffffffe1) {
    if (uVar2 == 0) {
      uVar3 = 1;
    }
    uVar3 = uVar3 + 0xf & 0xfffffff0;
    ExceptionList = &local_14;
  }
  do {
    local_24 = (LPVOID)0x0;
    if (uVar3 < 0xffffffe1) {
      if (DAT_008d4908 == 3) {
        if (uVar2 <= DAT_008d4900) {
          FUN_0058dfea(9);
          local_8 = 0;
          local_24 = (LPVOID)FUN_0059416f(uVar2);
          local_8 = 0xffffffff;
          FUN_0058abf1();
          _Size = uVar2;
          if (local_24 == (void *)0x0) goto LAB_0058ac45;
LAB_0058ac34:
          _memset(local_24,0,_Size);
        }
LAB_0058ac40:
        if (local_24 != (LPVOID)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((DAT_008d4908 != 2) || (DAT_005e998c < uVar3)) goto LAB_0058ac40;
        FUN_0058dfea(9);
        local_8 = 1;
        local_24 = (LPVOID)FUN_00594c12(uVar3 >> 4);
        local_8 = 0xffffffff;
        FUN_0058ac7a();
        _Size = uVar3;
        if (local_24 != (void *)0x0) goto LAB_0058ac34;
      }
LAB_0058ac45:
      local_24 = HeapAlloc(DAT_008d4904,8,uVar3);
    }
    if (local_24 != (LPVOID)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_008d41b0 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
    iVar1 = FUN_00593db8(uVar3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
  } while( true );
}
```
## FUN_0058ffec (0x0058ffec)
- **Size:** 516 bytes
- **Source:** decompiled_full/0x0058ffec__FUN_0058ffec.c

```c
// Function: FUN_0058ffec @ 0058ffec
// Size (bytes): 516


uint FUN_0058ffec(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined1 local_7c [120];
  
  iVar1 = FUN_005905dd(param_1);
  iVar2 = (*DAT_008d3fb8)(iVar1,(-(uint)(DAT_008d3f9c != 0) & 0xfffff005) + 0x1002,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_008d3fb0 = 0;
    return 1;
  }
  iVar2 = FUN_00588410(DAT_008d3fac,local_7c);
  if (iVar2 == 0) {
    iVar2 = (*DAT_008d3fb8)(iVar1,(-(uint)(DAT_008d3fa4 != 0) & 0xfffff002) + 0x1001,local_7c,0x78);
    if (iVar2 == 0) {
      DAT_008d3fb0 = 0;
      return 1;
    }
    iVar2 = FUN_00588410(DAT_008d3fa8,local_7c);
    if (iVar2 == 0) {
      DAT_008d3fb0 = DAT_008d3fb0 | 0x304;
      DAT_008d3fb4 = iVar1;
LAB_00590092:
      DAT_008d3f98 = iVar1;
    }
    else if ((DAT_008d3fb0 & 2) == 0) {
      if ((DAT_008d3fa0 == 0) ||
         (iVar2 = FUN_00596c80(DAT_008d3fa8,local_7c,DAT_008d3fa0), iVar2 != 0)) {
        if (((DAT_008d3fb0 & 1) == 0) && (iVar2 = FUN_00590440(iVar1), iVar2 != 0)) {
          DAT_008d3fb0 = DAT_008d3fb0 | 1;
          DAT_008d3fb4 = iVar1;
        }
      }
      else {
        DAT_008d3fb0 = DAT_008d3fb0 | 2;
        DAT_008d3fb4 = iVar1;
        sVar3 = _strlen(DAT_008d3fa8);
        if (sVar3 == DAT_008d3fa0) goto LAB_00590092;
      }
    }
  }
  if ((DAT_008d3fb0 & 0x300) == 0x300) goto LAB_005901dc;
  iVar2 = (*DAT_008d3fb8)(iVar1,(-(uint)(DAT_008d3fa4 != 0) & 0xfffff002) + 0x1001,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_008d3fb0 = 0;
    return 1;
  }
  iVar2 = FUN_00588410(DAT_008d3fa8,local_7c);
  if (iVar2 == 0) {
    DAT_008d3fb0 = DAT_008d3fb0 | 0x200;
    if (((DAT_008d3fa4 == 0) && (DAT_008d3fa0 != 0)) &&
       (sVar3 = _strlen(DAT_008d3fa8), sVar3 == DAT_008d3fa0)) {
      uVar4 = 1;
      goto LAB_005901bb;
    }
  }
  else {
    if (((DAT_008d3fa4 != 0) || (DAT_008d3fa0 == 0)) ||
       (iVar2 = FUN_00596c80(DAT_008d3fa8,local_7c,DAT_008d3fa0), iVar2 != 0)) goto LAB_005901dc;
    uVar4 = 0;
LAB_005901bb:
    iVar2 = FUN_0059045f(iVar1,uVar4);
    if (iVar2 == 0) goto LAB_005901dc;
  }
  DAT_008d3fb0 = DAT_008d3fb0 | 0x100;
  if (DAT_008d3f98 == 0) {
    DAT_008d3f98 = iVar1;
  }
LAB_005901dc:
  return ~DAT_008d3fb0 >> 2 & 1;
}
```
## FUN_005503a0 (0x005503a0)
- **Size:** 283 bytes
- **Source:** decompiled_full/0x005503a0__FUN_005503a0.c

```c
// Function: FUN_005503a0 @ 005503a0
// Size (bytes): 283


undefined4 __fastcall FUN_005503a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_4;
  
  for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
    if ((*(uint *)(iVar1 + 0x14) & 0x80000) != 0) {
      local_4 = *(int *)(iVar1 + 0x118);
      if (local_4 != 0) {
        piVar7 = (int *)(*(int *)(iVar1 + 0x11c) + 0x34);
        do {
          iVar5 = 0;
          if (0 < *(int *)(piVar7[-0xc] + 0xa4)) {
            piVar6 = (int *)(*(int *)(piVar7[-0xc] + 0xa8) + 0x50);
            do {
              if (1 < piVar6[-2]) {
                iVar3 = *piVar7;
                iVar2 = *piVar6;
                if ((iVar3 < iVar2) && ((*(byte *)(piVar6 + -4) & 4) != 0)) {
                  iVar4 = iVar3;
                  switch(piVar6[1] & 0xffff000f) {
                  case 1:
                    iVar4 = iVar3 + 1;
                    if (iVar2 <= iVar4) {
                      iVar4 = iVar2 - iVar4;
                    }
                    break;
                  case 2:
                    if (iVar3 < iVar2 + -1) {
                      iVar3 = iVar3 + 1;
                    }
                    iVar4 = iVar3;
                    if (iVar2 <= iVar3) {
                      iVar4 = iVar2 + -1;
                    }
                    break;
                  case 3:
                    if (iVar3 == iVar2 + -1) {
                      iVar3 = -iVar3;
                    }
                    iVar4 = iVar3 + 1;
                    break;
                  case 4:
                    iVar4 = iVar3 + 1;
                    if (iVar2 <= iVar3 + 1) {
                      FUN_0054c030(0,0,1,0);
                      iVar4 = -1;
                    }
                  }
                  *piVar7 = iVar4;
                }
              }
              piVar6 = piVar6 + 0x25;
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(int *)(piVar7[-0xc] + 0xa4));
          }
          piVar7 = piVar7 + 0x10;
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
    }
  }
  return 0;
}
```
## FUN_00595DC8 � Windows Charset/String Type Detection

Source: CRT locale | Confidence: high
Gets character type information for a string using appropriate Win32 API (WideChar or ANSI). Handles SEH and detects OS capabilities.

**Key logic:**
- Set up SEH handler (ExceptionList)
- If DAT_008d41c0 == 0 (not yet initialized):
  - Try GetStringTypeW(1, L"", 1, local_20) � test Unicode support
  - If fails: try GetStringTypeA � fallback to ANSI
  - Set DAT_008d41c0 = 1 (Wide) or 2 (ANSI)
- If WideChar mode:
  - If param_5 == 0: use default codepage DAT_008d3f48
  - MultiByteToWideChar to get buffer size + convert
  - GetStringTypeW on converted string
- If ANSI mode:
  - If param_6 == 0: use default locale DAT_008d3f38
  - GetStringTypeA directly

**Globals:**
- DAT_008d41c0 � mode flag (0=uninit, 1=Wide, 2=ANSI)
- DAT_008d3f48 � default codepage
- DAT_008d3f38 � default locale

**Calls:** GetStringTypeW, GetStringTypeA, MultiByteToWideChar

**Moddability:** N/A (OS API wrapper)

<!-- target: docs/20-math-utilities.md -->

## FUN_005574b0 (0x005574b0)
- **Size:** 312 bytes
- **Source:** decompiled_full/0x005574b0__FUN_005574b0.c

```c
// Function: FUN_005574b0 @ 005574b0
// Size (bytes): 312


undefined4 __fastcall FUN_005574b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00545f40();
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar3 + 4 + *(int *)(param_1 + 0x50));
      if (iVar1 != 0) {
        FUN_00547710(iVar1);
        *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x50)) = 0;
      }
      if ((*(byte *)(param_1 + 0x20) & 8) != 0) {
        FUN_00540cb0(*(int *)(param_1 + 0x50) + iVar3);
      }
      iVar1 = *(int *)(iVar3 + 0x14 + *(int *)(param_1 + 0x50));
      if (iVar1 != 0) {
        FUN_00587bcf(iVar1);
      }
      iVar1 = *(int *)(iVar3 + 0xc + *(int *)(param_1 + 0x50));
      if (iVar1 != 0) {
        FUN_00587bcf(iVar1);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x40;
    } while (iVar2 < *(int *)(param_1 + 0x4c));
  }
  FUN_00557630();
  iVar2 = *(int *)(param_1 + 0x50);
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + -4);
    if (-1 < iVar3 + -1) {
      do {
        FUN_004b0170();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
  }
  iVar2 = *(int *)(param_1 + 0x34);
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + -4);
    if (-1 < iVar3 + -1) {
      do {
        FUN_005573f0();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x40));
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x3c));
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x44));
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x48));
  }
  return 0;
}
```
## FUN_0056c020 (0x0056c020)
- **Size:** 673 bytes
- **Source:** decompiled_full/0x0056c020__FUN_0056c020.c

```c
// Function: FUN_0056c020 @ 0056c020
// Size (bytes): 673


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056c020(double *param_1,double *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  
  dVar1 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  if (_DAT_0059e430 < dVar1) {
    dVar1 = SQRT(dVar1);
    dVar2 = _DAT_0059e420 / dVar1;
    fVar13 = (float10)dVar2 * (float10)*param_2;
    fVar14 = (float10)dVar2 * (float10)param_2[1];
    fVar15 = (float10)dVar2 * (float10)param_2[2];
    fVar16 = (float10)fsin((float10)dVar1);
    fVar17 = (float10)fcos((float10)dVar1);
    dVar1 = (double)fVar17;
    dVar2 = (double)((float10)(double)((float10)_DAT_0059e420 - fVar17) * fVar14 * fVar13);
    fVar17 = fVar15 * (float10)(double)((float10)_DAT_0059e420 - fVar17);
    dVar3 = (double)(fVar17 * fVar13);
    dVar4 = (double)(fVar17 * fVar14);
    dVar8 = (_DAT_0059e420 - (double)(fVar13 * fVar13)) * dVar1 + (double)(fVar13 * fVar13);
    dVar10 = dVar2 - (double)(fVar16 * fVar15);
    dVar9 = dVar3 + (double)(fVar16 * fVar14);
    dVar2 = dVar2 + (double)(fVar16 * fVar15);
    dVar11 = (_DAT_0059e420 - (double)(fVar14 * fVar14)) * dVar1 + (double)(fVar14 * fVar14);
    dVar7 = dVar4 - (double)(fVar16 * fVar13);
    dVar3 = dVar3 - (double)(fVar16 * fVar14);
    dVar4 = dVar4 + (double)(fVar16 * fVar13);
    dVar12 = (_DAT_0059e420 - (double)(fVar15 * fVar15)) * dVar1 + (double)(fVar15 * fVar15);
    dVar1 = *param_1;
    dVar5 = param_1[3];
    dVar6 = param_1[6];
    *param_1 = dVar1 * dVar8 + dVar5 * dVar10 + dVar6 * dVar9;
    param_1[3] = dVar1 * dVar2 + dVar5 * dVar11 + dVar7 * dVar6;
    param_1[6] = dVar1 * dVar3 + dVar5 * dVar4 + dVar6 * dVar12;
    dVar1 = param_1[1];
    dVar5 = param_1[4];
    dVar6 = param_1[7];
    param_1[1] = dVar1 * dVar8 + dVar5 * dVar10 + dVar6 * dVar9;
    param_1[4] = dVar1 * dVar2 + dVar5 * dVar11 + dVar7 * dVar6;
    param_1[7] = dVar1 * dVar3 + dVar5 * dVar4 + dVar6 * dVar12;
    dVar1 = param_1[2];
    dVar5 = param_1[5];
    dVar6 = param_1[8];
    param_1[2] = dVar1 * dVar8 + dVar5 * dVar10 + dVar6 * dVar9;
    param_1[5] = dVar1 * dVar2 + dVar5 * dVar11 + dVar6 * dVar7;
    param_1[8] = dVar1 * dVar3 + dVar5 * dVar4 + dVar6 * dVar12;
    return;
  }
  return;
}
```
## FUN_00592787 (0x00592787)
- **Size:** 266 bytes
- **Source:** decompiled_full/0x00592787__FUN_00592787.c

```c
// Function: FUN_00592787 @ 00592787
// Size (bytes): 266


int * FUN_00592787(int *param_1)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  
  iVar4 = *param_1;
  bVar1 = false;
  iVar2 = FUN_0058e0c7();
  if (iVar4 < 0) {
    return (int *)0x0;
  }
  if (*(int *)(iVar2 + 0x40) == 0) {
    pvVar3 = _malloc(0x24);
    *(void **)(iVar2 + 0x40) = pvVar3;
    piVar5 = (int *)&DAT_008d4080;
    if (pvVar3 == (void *)0x0) goto LAB_005927c1;
  }
  piVar5 = *(int **)(iVar2 + 0x40);
LAB_005927c1:
  iVar7 = iVar4 % 0x7861f80;
  iVar4 = (iVar4 / 0x7861f80) * 4;
  iVar2 = iVar4 + 0x46;
  iVar8 = iVar7;
  if (0x1e1337f < iVar7) {
    iVar8 = iVar7 + -0x1e13380;
    iVar2 = iVar4 + 0x47;
    if (0x1e1337f < iVar8) {
      iVar8 = iVar7 + -0x3c26700;
      iVar2 = iVar4 + 0x48;
      if (iVar8 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar2 = iVar4 + 0x49;
        iVar8 = iVar7 + -0x5a4ec00;
      }
    }
  }
  piVar5[5] = iVar2;
  piVar9 = (int *)&DAT_005e9ad4;
  piVar5[7] = iVar8 / 0x15180;
  if (!bVar1) {
    piVar9 = (int *)&DAT_005e9b08;
  }
  iVar4 = 1;
  piVar6 = piVar9;
  while (piVar6 = piVar6 + 1, *piVar6 < piVar5[7]) {
    iVar4 = iVar4 + 1;
  }
  piVar5[4] = iVar4 + -1;
  piVar5[3] = piVar5[7] - piVar9[iVar4 + -1];
  piVar5[6] = (*param_1 / 0x15180 + 4) % 7;
  piVar5[2] = (iVar8 % 0x15180) / 0xe10;
  iVar4 = (iVar8 % 0x15180) % 0xe10;
  piVar5[1] = iVar4 / 0x3c;
  piVar5[8] = 0;
  *piVar5 = iVar4 % 0x3c;
  return piVar5;
}
```
## FUN_00589901 (0x00589901)
- **Size:** 308 bytes
- **Source:** decompiled_full/0x00589901__FUN_00589901.c

```c
// Function: FUN_00589901 @ 00589901
// Size (bytes): 308


char * FUN_00589901(char *param_1)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  void *local_c;
  
  local_c = (void *)0x0;
  if (DAT_008d3f38 == 0) {
    cVar1 = *param_1;
    pcVar3 = param_1;
    while (cVar1 != '\0') {
      cVar1 = *pcVar3;
      if (('`' < cVar1) && (cVar1 < '{')) {
        *pcVar3 = cVar1 + -0x20;
      }
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  else {
    InterlockedIncrement(&DAT_008d5a5c);
    bVar4 = DAT_008d5a58 == 0;
    if (!bVar4) {
      InterlockedDecrement(&DAT_008d5a5c);
      FUN_0058dfea(0x13);
    }
    if (DAT_008d3f38 == 0) {
      if (bVar4) {
        InterlockedDecrement(&DAT_008d5a5c);
      }
      else {
        FUN_0058e04b(0x13);
      }
      cVar1 = *param_1;
      pcVar3 = param_1;
      while (cVar1 != '\0') {
        cVar1 = *pcVar3;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *pcVar3 = cVar1 + -0x20;
        }
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
    }
    else {
      _Size = FUN_00591fa1(DAT_008d3f38,0x200,param_1,0xffffffff,0,0,0,1);
      if (((_Size != 0) && (local_c = _malloc(_Size), local_c != (void *)0x0)) &&
         (iVar2 = FUN_00591fa1(DAT_008d3f38,0x200,param_1,0xffffffff,local_c,_Size,0,1), iVar2 != 0)
         ) {
        FUN_0058fca0(param_1,local_c);
      }
      if (bVar4) {
        InterlockedDecrement(&DAT_008d5a5c);
      }
      else {
        FUN_0058e04b(0x13);
      }
      FUN_0058aa6f(local_c);
    }
  }
  return param_1;
}
```
## FUN_0057abb0 (0x0057abb0)
- **Size:** 248 bytes
- **Source:** decompiled_full/0x0057abb0__FUN_0057abb0.c

```c
// Function: FUN_0057abb0 @ 0057abb0
// Size (bytes): 248


undefined4 FUN_0057abb0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char cStack00000034;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puVar5 = _cStack00000034;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c79b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *_cStack00000034 = 0;
  _cStack00000034 = (undefined4 *)((uint)_cStack00000034 & 0xffffff00);
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0057a420(&stack0x00000004,&stack0x00000034);
  }
  local_4 = 0xffffffff;
  if ((cStack00000034 == '\0') && (iVar3 = (**(code **)(*(int *)*puVar2 + 0x48))(), iVar3 == 0)) {
    puVar4 = (undefined4 *)FUN_00585cc0();
    (**(code **)*puVar4)();
    FUN_004b0170();
    *puVar5 = puVar2;
    puVar5 = operator_new(0x10);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = puVar2;
      puVar5[1] = 0;
      puVar5[2] = 0;
      *(undefined1 *)(puVar5 + 3) = 1;
    }
    puVar2 = puVar5;
    puVar4 = puVar5;
    if (DAT_008d3bfc != (undefined4 *)0x0) {
      DAT_008d3c00[1] = puVar5;
      puVar5[2] = DAT_008d3c00;
      puVar2 = DAT_008d3bfc;
      puVar4 = DAT_008d3c04;
    }
    DAT_008d3c04 = puVar4;
    DAT_008d3bfc = puVar2;
    DAT_008d3c08 = DAT_008d3c08 + 1;
    uVar6 = 0;
    DAT_008d3c00 = puVar5;
  }
  else {
    uVar6 = 1;
  }
  ExceptionList = local_c;
  return uVar6;
}
```
## FUN_00564f10 (0x00564f10)
- **Size:** 366 bytes
- **Source:** decompiled_full/0x00564f10__FUN_00564f10.c

```c
// Function: FUN_00564f10 @ 00564f10
// Size (bytes): 366


void __fastcall FUN_00564f10(int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = *(uint *)(param_1 + 0x4cc);
  iVar4 = *(int *)(param_1 + 0x4c0);
  uVar7 = *(uint *)(param_1 + 0x4c8);
  puVar1 = param_2 + param_3;
  uVar3 = *(uint *)(param_1 + 0x4c4);
  while (param_2 < puVar1) {
    if (uVar5 < 0x10000) {
      puVar6 = (uint *)(param_1 + 0x440 + iVar4 * 4);
      do {
        iVar2 = uVar3 + uVar5;
        puVar6[0x10] = uVar5;
        uVar7 = uVar7 + iVar2;
        uVar5 = uVar5 * 2;
        uVar3 = iVar2 + uVar7;
        *puVar6 = uVar7;
        puVar6[-0x10] = uVar3;
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 1;
        uVar3 = uVar3 ^ *(uint *)(param_1 + (uVar3 & 0xff) * 4);
        uVar7 = (uVar7 * 0x1000000 | uVar7 >> 8) ^ *(uint *)(param_1 + (uVar7 >> 8 & 0xff) * 4);
        uVar8 = uVar7 >> 8;
        uVar9 = uVar3 >> 0x18;
        uVar3 = (uVar9 | uVar3 << 8) ^ *(uint *)(param_1 + uVar9 * 4);
        uVar7 = (uVar7 << 0x18 | uVar8) ^ *(uint *)(param_1 + (uVar8 & 0xff) * 4);
        uVar3 = uVar3 >> 0x18 | uVar3 << 8;
      } while (uVar5 < 0x10000);
    }
    *param_2 = uVar7 ^ uVar3;
    param_2 = param_2 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    uVar5 = *(uint *)(param_1 + 0x440 + iVar4 * 4);
    uVar7 = ~*(uint *)(param_1 + 0x400 + iVar4 * 4);
    uVar3 = uVar7 >> 8;
    uVar7 = (uVar7 << 0x18 | uVar3) ^ *(uint *)(param_1 + (uVar3 & 0xff) * 4);
    uVar3 = uVar7 >> 8;
    uVar5 = uVar5 ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
    uVar8 = uVar5 >> 0x18;
    uVar3 = (uVar7 << 0x18 | uVar3) ^ *(uint *)(param_1 + (uVar3 & 0xff) * 4);
    uVar5 = (uVar8 | uVar5 << 8) ^ *(uint *)(param_1 + uVar8 * 4);
    uVar7 = uVar5 >> 0x18 | uVar5 << 8;
    uVar5 = *(int *)(param_1 + 0x480 + iVar4 * 4) * 2 + 1;
  }
  *(uint *)(param_1 + 0x4c8) = uVar7;
  *(uint *)(param_1 + 0x4cc) = uVar5;
  *(int *)(param_1 + 0x4c0) = iVar4;
  *(uint *)(param_1 + 0x4c4) = uVar3;
  return;
}
```
## FUN_0059070a (0x0059070a)
- **Size:** 305 bytes
- **Source:** decompiled_full/0x0059070a__FUN_0059070a.c

```c
// Function: FUN_0059070a @ 0059070a
// Size (bytes): 305


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059070a(void)

{
  char cVar1;
  ushort uVar2;
  int unaff_EBP;
  ushort in_FPUStatusWord;
  float10 in_ST0;
  
  if (DAT_008d3e40 != 0) {
    return;
  }
  *(double *)(unaff_EBP + -0x2d0) = (double)in_ST0;
  cVar1 = *(char *)(unaff_EBP + -0x90);
  if (cVar1 != '\0') {
    if ((cVar1 != -1) && (cVar1 != -2)) {
      if (cVar1 == '\0') {
        return;
      }
      *(int *)(unaff_EBP + -0x8e) = (int)cVar1;
      goto LAB_005907d9;
    }
    uVar2 = *(ushort *)(unaff_EBP + -0x2ca) & 0x7ff0;
    if (uVar2 == 0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 4;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_005b94f8);
      if (ABS(in_ST0) < (float10)_DAT_005b94e8) {
        in_ST0 = in_ST0 * (float10)_DAT_005b9508;
      }
      goto LAB_005907d9;
    }
    if (uVar2 == 0x7ff0) {
      *(undefined4 *)(unaff_EBP + -0x8e) = 3;
      in_ST0 = (float10)fscale(in_ST0,(float10)_DAT_005b94f0);
      if ((float10)_DAT_005b94e0 < ABS(in_ST0)) {
        in_ST0 = in_ST0 * (float10)_DAT_005b9500;
      }
      goto LAB_005907d9;
    }
  }
  if ((*(ushort *)(unaff_EBP + -0xa4) & 0x20) != 0) {
    return;
  }
  if ((in_FPUStatusWord & 0x20) == 0) {
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x8e) = 8;
LAB_005907d9:
  *(int *)(unaff_EBP + -0x8a) = *(int *)(unaff_EBP + -0x94) + 1;
  if ((*(byte *)(unaff_EBP + -0x2c8) & 1) == 0) {
    *(undefined4 *)(unaff_EBP + -0x86) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x82) = *(undefined4 *)(unaff_EBP + 0xc);
    if (*(char *)(*(int *)(unaff_EBP + -0x94) + 0xd) != '\x01') {
      *(undefined4 *)(unaff_EBP + -0x7e) = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x7a) = *(undefined4 *)(unaff_EBP + 0x14);
    }
  }
  *(double *)(unaff_EBP + -0x76) = (double)in_ST0;
  FUN_00596175((int)*(char *)(*(int *)(unaff_EBP + -0x94) + 0xe),unaff_EBP + -0x8e,unaff_EBP + -0xa4
              );
  return;
}
```
## FUN_00558b30 (0x00558b30)
- **Size:** 296 bytes
- **Source:** decompiled_full/0x00558b30__FUN_00558b30.c

```c
// Function: FUN_00558b30 @ 00558b30
// Size (bytes): 296


void __thiscall FUN_00558b30(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  
  if (((0 < *(int *)(param_1 + 0x30)) && (param_2 < *(int *)(param_1 + 0x2c))) &&
     (puVar5 = (uint *)(param_2 * 0x80 + *(int *)(param_1 + 0x34)),
     (*(byte *)(param_2 * 0x80 + *(int *)(param_1 + 0x34)) & 0x40) != 0)) {
    if (*(char *)(param_1 + 0x20) < '\0') {
      if (*(uint **)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4) != puVar5) {
        FUN_00558d10(0);
        iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0x20);
        if (iVar1 != 0) {
          iVar2 = *(int *)(param_1 + 0x24);
          puVar3 = (undefined4 *)(puVar5[1] * iVar2 * 0x40 + iVar1);
          puVar4 = (undefined4 *)
                   (*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4)
                            + 4) * iVar2 * 0x40 + iVar1);
          param_2 = 0;
          if (0 < iVar2) {
            do {
              *puVar3 = *puVar4;
              puVar3[1] = puVar4[1];
              puVar3[2] = puVar4[2];
              puVar3[6] = puVar4[6];
              puVar3 = puVar3 + 0x10;
              puVar4 = puVar4 + 0x10;
              param_2 = param_2 + 1;
            } while (param_2 < *(int *)(param_1 + 0x24));
          }
        }
        *(uint *)(*(int *)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4) + 4) =
             puVar5[1];
        *(undefined4 *)(*(int *)(param_1 + 0x3c) + puVar5[1] * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4);
        *puVar5 = *puVar5 & 0xffffffbf;
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
        return;
      }
    }
    else {
      if (puVar5[0x1e] != 0) {
        *(uint *)(puVar5[0x1e] + 0x7c) = puVar5[0x1f];
      }
      if (puVar5[0x1f] != 0) {
        *(uint *)(puVar5[0x1f] + 0x78) = puVar5[0x1e];
      }
      if (puVar5[0x1e] == 0) {
        *(uint *)(param_1 + 0x38) = puVar5[0x1f];
      }
      puVar5[0x1e] = 0;
      puVar5[0x1f] = 0;
    }
    *puVar5 = *puVar5 & 0xffffffbf;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
  }
  return;
}
```
## FUN_00567b10 (0x00567b10)
- **Size:** 146 bytes
- **Source:** decompiled_full/0x00567b10__FUN_00567b10.c

```c
// Function: FUN_00567b10 @ 00567b10
// Size (bytes): 146


uint FUN_00567b10(char *param_1,char *param_2)

{
  char cVar1;
  uint in_EAX;
  undefined1 *puVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  *param_2 = '\0';
  if (param_1 != (char *)0x0) {
    cVar1 = *param_1;
    while (cVar1 != '\0') {
      uVar6 = FUN_005678f0();
      param_1 = (char *)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 0) break;
      pcVar4 = param_1 + 1;
      param_1 = param_1 + 1;
      cVar1 = *pcVar4;
    }
    iVar5 = (int)param_2 - (int)param_1;
    do {
      cVar1 = *param_1;
      param_1[iVar5] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    puVar2 = (undefined1 *)FUN_00587c20(param_2,&DAT_005c30b8);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0;
    }
    uVar3 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = param_2 + (~uVar3 - 2);
    while (param_2 <= pcVar4) {
      uVar6 = FUN_005678f0();
      puVar2 = (undefined1 *)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 0) break;
      *puVar2 = 0;
      pcVar4 = puVar2 + -1;
    }
    iVar5 = -1;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    in_EAX = 0;
    if (iVar5 != -2) {
      return 1;
    }
  }
  return in_EAX & 0xffffff00;
}
```
## FUN_0057ca10 (0x0057ca10)
- **Size:** 308 bytes
- **Source:** decompiled_full/0x0057ca10__FUN_0057ca10.c

```c
// Function: FUN_0057ca10 @ 0057ca10
// Size (bytes): 308


undefined4 FUN_0057ca10(char *param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  char *pcVar7;
  int iVar8;
  char local_68 [7];
  undefined1 local_61;
  char local_60 [31];
  undefined1 local_41;
  char local_40 [64];
  
  local_40[0] = '\0';
  iVar8 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_40 + iVar8)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  pcVar7 = (char *)FUN_005897ca(local_40,&DAT_005c3f6c);
  if (pcVar7 != (char *)0x0) {
    local_60[0] = '\0';
    _strncpy(local_60,pcVar7,0x1f);
    local_41 = 0;
    pcVar7 = (char *)FUN_005897ca(0,&DAT_005c3f6c);
    if (pcVar7 != (char *)0x0) {
      local_68[0] = '\0';
      _strncpy(local_68,pcVar7,7);
      local_61 = 0;
      iVar8 = FUN_005897ca(local_60,&DAT_005beb48);
      if (iVar8 != 0) {
        uVar2 = FUN_00587ece(iVar8);
        iVar8 = FUN_005897ca(0,&DAT_005beb48);
        if (iVar8 != 0) {
          uVar3 = FUN_00587ece(iVar8);
          iVar8 = FUN_005897ca(0,&DAT_005beb48);
          if (iVar8 != 0) {
            uVar4 = FUN_00587ece(iVar8);
            iVar8 = FUN_005897ca(0,&DAT_005beb48);
            if (iVar8 != 0) {
              uVar5 = FUN_00587ece(iVar8);
              *(undefined1 *)(param_2 + 7) = uVar5;
              *(undefined1 *)(param_2 + 4) = uVar2;
              *(undefined1 *)(param_2 + 5) = uVar3;
              *(undefined1 *)(param_2 + 6) = uVar4;
              uVar6 = FUN_00587ece(local_68);
              *(undefined2 *)(param_2 + 2) = uVar6;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}
```
## FUN_00565bb0 (0x00565bb0)
- **Size:** 225 bytes
- **Source:** decompiled_full/0x00565bb0__FUN_00565bb0.c

```c
// Function: FUN_00565bb0 @ 00565bb0
// Size (bytes): 225


bool __thiscall FUN_00565bb0(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  LONG LVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar2 = *(int *)(*param_1 + 0x220);
  if (iVar2 == 1) {
    pbVar3 = (byte *)(param_2 + 0x30);
    pbVar5 = (byte *)(param_1 + 0xc);
    while( true ) {
      bVar1 = *pbVar5;
      bVar6 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) break;
      if (bVar1 == 0) {
        return false;
      }
      bVar1 = pbVar5[1];
      bVar6 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) break;
      pbVar5 = pbVar5 + 2;
      pbVar3 = pbVar3 + 2;
      if (bVar1 == 0) {
        return false;
      }
    }
    return 0 < (int)((1 - (uint)bVar6) - (uint)(bVar6 != 0));
  }
  if (iVar2 == 2) {
    LVar4 = CompareFileTime((FILETIME *)(param_1 + 6),(FILETIME *)(param_2 + 0x18));
    return 0 < LVar4;
  }
  if (iVar2 == 3) {
    LVar4 = CompareFileTime((FILETIME *)(param_1 + 6),(FILETIME *)(param_2 + 0x18));
    return LVar4 < 0;
  }
  pbVar3 = (byte *)(param_1 + 0xc);
  pbVar5 = (byte *)(param_2 + 0x30);
  while( true ) {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) break;
    if (bVar1 == 0) {
      return false;
    }
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) break;
    pbVar3 = pbVar3 + 2;
    pbVar5 = pbVar5 + 2;
    if (bVar1 == 0) {
      return false;
    }
  }
  return (int)((1 - (uint)bVar6) - (uint)(bVar6 != 0)) < 0;
}
```
## FUN_00551210 (0x00551210)
- **Size:** 370 bytes
- **Source:** decompiled_full/0x00551210__FUN_00551210.c

```c
// Function: FUN_00551210 @ 00551210
// Size (bytes): 370


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00551210(int param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  float *pfVar4;
  float *pfVar5;
  float local_1c;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (*(float *)(iVar1 + 8) < param_3) {
    param_3 = *(float *)(iVar1 + 8);
  }
  iVar2 = __ftol();
  *(int *)(param_1 + 8) = iVar2;
  if (iVar2 < *(int *)(iVar1 + 0x14) + -1) {
    iVar2 = iVar2 + 1;
  }
  else if (iVar2 == *(int *)(iVar1 + 0x14)) {
    iVar2 = iVar2 + -1;
    *(int *)(param_1 + 8) = iVar2;
  }
  puVar3 = *(uint **)(param_1 + 0x18);
  local_14 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    do {
      if ((*puVar3 & 0xff) < 0xff) {
        iVar1 = *(int *)((*puVar3 & 0xff) * 0x2c + 0x28 + *(int *)(*(int *)(param_1 + 0x1c) + 0x10))
        ;
        pfVar5 = (float *)(iVar2 * 0x20 + iVar1);
        pfVar4 = (float *)(*(int *)(param_1 + 8) * 0x20 + iVar1);
        if (*pfVar5 - *pfVar4 == (float)_DAT_0059e430) {
          local_1c = 0.0;
        }
        else {
          local_1c = (param_3 - *pfVar4) / (*pfVar5 - *pfVar4);
        }
        FUN_0053b490();
        FUN_0053b5b0(pfVar4 + 4,pfVar5 + 4,local_1c);
        FUN_0053b4c0(puVar3 + 1);
        puVar3[0xd] = (uint)((pfVar5[1] - pfVar4[1]) * local_1c + pfVar4[1]);
        puVar3[0xe] = (uint)((pfVar5[2] - pfVar4[2]) * local_1c + pfVar4[2]);
        puVar3[0xf] = (uint)((pfVar5[3] - pfVar4[3]) * local_1c + pfVar4[3]);
        FUN_0053b4a0();
      }
      puVar3 = puVar3 + 0x22;
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)(param_1 + 0x14));
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10000;
  if (param_2 != 0) {
    FUN_0054b330(0x40,0x20,0);
  }
  return;
}
```
## FUN_0056068e (0x0056068e)
- **Size:** 307 bytes
- **Source:** decompiled_full/0x0056068e__FUN_0056068e.c

```c
// Function: FUN_0056068e @ 0056068e
// Size (bytes): 307


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_0056068e(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,uint param_9,int param_10)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 in_EAX;
  int iVar4;
  ushort *puVar5;
  
  _DAT_005dd878 = param_10 << 5;
  DAT_005dd814 = param_6;
  puVar5 = (ushort *)(param_3 + param_5 * param_8 + param_4 * 2);
  _DAT_005dd81c = param_8 + param_6 * -2;
  _DAT_005dd818 = param_7;
  _DAT_005dd828 = ((param_9 & 0xff) >> 4) << 5;
  _DAT_005dd824 = ((param_9 >> 8 & 0xff) >> 4) << 5;
  _DAT_005dd820 = ((param_9 >> 0x10 & 0xff) >> 4) << 5;
  do {
    do {
      uVar1 = *puVar5;
      *puVar5 = (ushort)((ushort)(((uint)(byte)(&DAT_005deccc)
                                               [(uint)(byte)(&DAT_005dd8cc)
                                                            [((uVar1 & 0x1f) >> 1) + _DAT_005dd828]
                                                + _DAT_005dd878] << 0x1b) >> 0x15) |
                        (ushort)(((uint)(byte)((byte)(&DAT_005deccc)
                                                     [(uint)(byte)(&DAT_005dd8cc)
                                                                  [((uVar1 & 0x1f) >> 1) +
                                                                   _DAT_005dd828] + _DAT_005dd878]
                                               >> 5 | (&DAT_005deccc)
                                                      [(uint)(byte)(&DAT_005dd8cc)
                                                                   [((uVar1 >> 5 & 0x1f) >> 1) +
                                                                    _DAT_005dd824] + _DAT_005dd878])
                                 << 0x1b) >> 0x10)) >> 6 |
                (ushort)(byte)((byte)(&DAT_005deccc)
                                     [(uint)(byte)(&DAT_005dd8cc)
                                                  [((uVar1 >> 5 & 0x1f) >> 1) + _DAT_005dd824] +
                                      _DAT_005dd878] >> 5 |
                              (&DAT_005deccc)
                              [(uint)(byte)(&DAT_005dd8cc)
                                           [((uVar1 >> 10 & 0x1f) >> 1) + _DAT_005dd820] +
                               _DAT_005dd878]) << 10;
      iVar3 = _DAT_005dd818;
      puVar5 = puVar5 + 1;
      iVar4 = param_6 + -1;
      bVar2 = 0 < param_6;
      param_6 = iVar4;
    } while (iVar4 != 0 && bVar2);
    puVar5 = (ushort *)((int)puVar5 + _DAT_005dd81c);
    _DAT_005dd818 = _DAT_005dd818 + -1;
    param_6 = DAT_005dd814;
  } while (_DAT_005dd818 != 0 && 0 < iVar3);
  return CONCAT44(param_2,in_EAX);
}
```
## FUN_0055ee20 (0x0055ee20)
- **Size:** 143 bytes
- **Source:** decompiled_full/0x0055ee20__FUN_0055ee20.c

```c
// Function: FUN_0055ee20 @ 0055ee20
// Size (bytes): 143


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0055ee20(undefined4 param_1,undefined4 param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  bool bVar15;
  undefined4 in_EAX;
  int iVar16;
  int iVar17;
  float *pfVar18;
  float *pfVar19;
  
  _DAT_005dc470 = *(int *)(param_3 + 8);
  pfVar18 = *(float **)(param_3 + 0xc);
  pfVar19 = *(float **)(param_3 + 0x3c);
  iVar16 = _DAT_005dc470;
  do {
    fVar1 = param_4[1];
    fVar2 = *pfVar18;
    fVar3 = param_4[2];
    fVar4 = *pfVar18;
    fVar5 = param_4[5];
    fVar6 = pfVar18[1];
    fVar7 = param_4[6];
    fVar8 = pfVar18[1];
    fVar9 = param_4[9];
    fVar10 = pfVar18[2];
    fVar11 = param_4[10];
    fVar12 = pfVar18[2];
    fVar13 = param_4[0xd];
    fVar14 = param_4[0xe];
    *pfVar19 = param_4[8] * pfVar18[2] + param_4[4] * pfVar18[1] + *param_4 * *pfVar18 +
               param_4[0xc];
    pfVar19[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4 + fVar14;
    pfVar19[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2 + fVar13;
    pfVar18 = pfVar18 + 0xc;
    pfVar19 = pfVar19 + 6;
    iVar17 = iVar16 + -1;
    bVar15 = 0 < iVar16;
    iVar16 = iVar17;
  } while (iVar17 != 0 && bVar15);
  return CONCAT44(param_2,in_EAX);
}
```
## FUN_005990ae (0x005990ae)
- **Size:** 277 bytes
- **Source:** decompiled_full/0x005990ae__FUN_005990ae.c

```c
// Function: FUN_005990ae @ 005990ae
// Size (bytes): 277


uint __fastcall FUN_005990ae(basic_streambuf<char,std::char_traits<char>_> *param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  int local_c;
  byte local_5;
  
  uVar3 = **(uint **)(param_1 + 0x1c);
  if ((uVar3 != 0) && (uVar3 < **(int **)(param_1 + 0x2c) + uVar3)) {
    pbVar2 = (byte *)std::basic_streambuf<char,std::char_traits<char>_>::_Gninc(param_1);
    return (uint)*pbVar2;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      uVar3 = FUN_00589fcc(*(int *)(param_1 + 0x50));
      if (uVar3 != 0xffffffff) {
        return uVar3 & 0xff;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 0x40);
      FUN_00599348(0,DAT_005b9c38);
      while (iVar4 = FUN_00589fcc(*(undefined4 *)(param_1 + 0x50)), iVar4 != -1) {
        FUN_005992ef(1,iVar4);
        iVar4 = *(int *)(param_1 + 0x44);
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3c);
        FUN_00599534();
        iVar1 = *(int *)(param_1 + 0x44);
        local_c = *(int *)(iVar4 + 4);
        FUN_00599534();
        iVar4 = (**(code **)(**(int **)(param_1 + 0x38) + 0x10))
                          (param_1 + 0x40,*(undefined4 *)(iVar1 + 4),
                           -(uint)(local_c != 0) & *(int *)(iVar4 + 8) + local_c,local_14,&local_5,
                           &stack0xfffffffc,local_10);
        if (iVar4 == 0) goto LAB_005991ba;
        if (iVar4 != 1) {
          if (iVar4 != 3) {
            return 0xffffffff;
          }
          iVar4 = *(int *)(param_1 + 0x44);
          if (*(int *)(iVar4 + 8) != 0) {
            FUN_00599534();
            FUN_0058cc00(&local_5,*(undefined4 *)(iVar4 + 4),1);
LAB_005991ba:
            return (uint)local_5;
          }
        }
      }
    }
  }
  return 0xffffffff;
}
```
## FUN_0056a840 (0x0056a840)
- **Size:** 541 bytes
- **Source:** decompiled_full/0x0056a840__FUN_0056a840.c

```c
// Function: FUN_0056a840 @ 0056a840
// Size (bytes): 541


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0056a840(int param_1,double *param_2,double *param_3)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int local_90;
  int local_8c;
  
  local_8c = 0;
  if (0 < *(int *)(param_1 + 0x23c)) {
    local_90 = 0;
    do {
      iVar5 = *(int *)(param_1 + 0x240) + local_90;
      dVar2 = *(double *)(param_1 + 0x84) * *(double *)(*(int *)(param_1 + 0x240) + 0x28 + local_90)
              - *(double *)(param_1 + 0x8c) * *(double *)(iVar5 + 0x20);
      dVar3 = *(double *)(param_1 + 0x8c) * *(double *)(iVar5 + 0x18) -
              *(double *)(param_1 + 0x7c) * *(double *)(iVar5 + 0x28);
      dVar4 = *(double *)(param_1 + 0x7c) * *(double *)(iVar5 + 0x20) -
              *(double *)(param_1 + 0x84) * *(double *)(iVar5 + 0x18);
      dVar2 = ((double)CONCAT44(DAT_005e523c,DAT_005e5238) *
               (*(double *)(iVar5 + 0x18) + *(double *)(param_1 + 4)) + *param_3 +
               (param_2[1] * *(double *)(iVar5 + 0x28) - param_2[2] * *(double *)(iVar5 + 0x20)) +
               (dVar4 * *(double *)(param_1 + 0x84) - dVar3 * *(double *)(param_1 + 0x8c)) +
              (dVar2 + *(double *)(param_1 + 100)) * _DAT_005e5240) * *(double *)(iVar5 + 0x40) +
              ((double)CONCAT44(DAT_005e523c,DAT_005e5238) *
               (*(double *)(param_1 + 0xc) + *(double *)(iVar5 + 0x20)) + param_3[1] +
               (*(double *)(iVar5 + 0x18) * param_2[2] - *param_2 * *(double *)(iVar5 + 0x28)) +
               (dVar2 * *(double *)(param_1 + 0x8c) - dVar4 * *(double *)(param_1 + 0x7c)) +
              (dVar3 + *(double *)(param_1 + 0x6c)) * _DAT_005e5240) * *(double *)(iVar5 + 0x48) +
              ((double)CONCAT44(DAT_005e523c,DAT_005e5238) *
               (*(double *)(param_1 + 0x14) + *(double *)(iVar5 + 0x28)) +
               (*param_2 * *(double *)(iVar5 + 0x20) - *(double *)(iVar5 + 0x18) * param_2[1]) +
               (dVar3 * *(double *)(param_1 + 0x7c) - dVar2 * *(double *)(param_1 + 0x84)) +
               (dVar4 + *(double *)(param_1 + 0x74)) * _DAT_005e5240 + param_3[2]) *
              *(double *)(iVar5 + 0x50);
      if (*(char *)(iVar5 + 0x34) == '\0') {
        *(double *)(*(int *)(param_1 + 0x224) + *(int *)(iVar5 + 0x30) * 8) =
             dVar2 + *(double *)(*(int *)(param_1 + 0x224) + *(int *)(iVar5 + 0x30) * 8);
      }
      else {
        pdVar1 = (double *)(*(int *)(param_1 + 0x224) + *(int *)(iVar5 + 0x30) * 8);
        *pdVar1 = *pdVar1 - (dVar2 - (double)CONCAT44(DAT_005e523c,DAT_005e5238) *
                                     *(double *)(iVar5 + 0x38));
      }
      local_8c = local_8c + 1;
      local_90 = local_90 + 0x58;
    } while (local_8c < *(int *)(param_1 + 0x23c));
  }
  return;
}
```
## FUN_0058fc60 (0x0058fc60)
- **Size:** 58 bytes
- **Source:** decompiled_full/0x0058fc60__FUN_0058fc60.c

```c
// Function: FUN_0058fc60 @ 0058fc60
// Size (bytes): 58


byte * FUN_0058fc60(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = param_1;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    param_1 = pbVar2 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return pbVar2;
}
```
## FUN_00581b30 (0x00581b30)
- **Size:** 231 bytes
- **Source:** decompiled_full/0x00581b30__FUN_00581b30.c

```c
// Function: FUN_00581b30 @ 00581b30
// Size (bytes): 231


void __fastcall FUN_00581b30(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  BOOL BVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cb50;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((*(char *)(param_1 + 10) != '\0') &&
     (ExceptionList = &pvStack_c, BVar4 = CloseHandle((HANDLE)param_1[8]), BVar4 != 0)) {
    param_1[8] = 0;
  }
  local_4 = 1;
  piVar3 = (int *)param_1[4];
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  local_4 = 0xffffffff;
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(3);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  ExceptionList = pvStack_c;
  return;
}
```

## __setjmp3 (0x0058a7ec)
- **Size:** 123 bytes
- **Source:** decompiled_full/0x0058a7ec____setjmp3.c

```c
// Function: __setjmp3 @ 0058a7ec
// Size (bytes): 123


/* Library Function - Single Match
    __setjmp3
   
   Library: Visual Studio */

undefined4 __setjmp3(undefined4 *param_1,int param_2,void *param_3,undefined4 param_4)

{
  void *pvVar1;
  uint uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  undefined4 unaff_EDI;
  undefined4 *puVar4;
  undefined4 unaff_retaddr;
  
  *param_1 = unaff_EBP;
  param_1[1] = unaff_EBX;
  param_1[2] = unaff_EDI;
  param_1[3] = unaff_ESI;
  param_1[4] = register0x00000010;
  param_1[5] = unaff_retaddr;
  param_1[8] = 0x56433230;
  param_1[9] = 0;
  pvVar1 = ExceptionList;
  param_1[6] = ExceptionList;
  if (pvVar1 == (void *)0xffffffff) {
    param_1[7] = 0xffffffff;
  }
  else if ((param_2 == 0) || (param_1[9] = param_3, pvVar1 = param_3, param_2 == 1)) {
    param_1[7] = *(undefined4 *)((int)pvVar1 + 0xc);
  }
  else {
    param_1[7] = param_4;
    uVar2 = param_2 - 2;
    if (uVar2 != 0) {
      puVar3 = (undefined4 *)&stack0x00000014;
      puVar4 = param_1 + 10;
      if (6 < uVar2) {
        uVar2 = 6;
      }
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    }
  }
  return 0;
}
```
## FUN_00564dd0 (0x00564dd0)
- **Size:** 310 bytes
- **Source:** decompiled_full/0x00564dd0__FUN_00564dd0.c

```c
// Function: FUN_00564dd0 @ 00564dd0
// Size (bytes): 310


uint __fastcall FUN_00564dd0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = 0;
  uVar3 = 0x8000;
  iVar2 = 1;
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  uVar4 = param_2;
  do {
    uVar1 = uVar1 + uVar4 + iVar2;
    uVar4 = uVar4 + iVar2 + uVar1;
    if ((param_3 & uVar3) == 0) {
      *(uint *)(param_1 + 0x400 + *(int *)(param_1 + 0x4c0) * 4) = uVar4;
      *(uint *)(param_1 + 0x440 + *(int *)(param_1 + 0x4c0) * 4) = uVar1;
      *(int *)(param_1 + 0x480 + *(int *)(param_1 + 0x4c0) * 4) = iVar2;
      *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + 1;
      uVar4 = uVar4 ^ *(uint *)(param_1 + (uVar4 & 0xff) * 4);
      uVar1 = (uVar1 * 0x1000000 | uVar1 >> 8) ^ *(uint *)(param_1 + (uVar1 >> 8 & 0xff) * 4);
      uVar5 = uVar1 >> 8;
      uVar6 = uVar4 >> 0x18;
      uVar4 = (uVar6 | uVar4 << 8) ^ *(uint *)(param_1 + uVar6 * 4);
      uVar1 = (uVar1 << 0x18 | uVar5) ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
      uVar4 = uVar4 >> 0x18 | uVar4 << 8;
      iVar2 = iVar2 * 2;
    }
    else {
      iVar2 = iVar2 * 2 + 1;
      uVar5 = ~uVar4 >> 8;
      uVar4 = (~uVar4 << 0x18 | uVar5) ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
      uVar1 = uVar1 ^ *(uint *)(param_1 + (uVar1 & 0xff) * 4);
      uVar5 = uVar4 >> 8;
      uVar6 = uVar1 >> 0x18;
      uVar4 = (uVar4 << 0x18 | uVar5) ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
      uVar1 = (uVar6 | uVar1 << 8) ^ *(uint *)(param_1 + uVar6 * 4);
      uVar1 = uVar1 >> 0x18 | uVar1 << 8;
    }
    uVar3 = (int)uVar3 >> 1;
  } while (uVar3 != 0);
  *(uint *)(param_1 + 0x4c8) = uVar1;
  *(uint *)(param_1 + 0x4c4) = uVar4;
  *(int *)(param_1 + 0x4cc) = iVar2;
  *(uint *)(param_1 + 0x4d0) = param_2;
  return uVar1 ^ uVar4;
}
```
```


## FUN_0058f362 (0x0058f362)
- **Size:** 400 bytes
- **Source:** decompiled_full/0x0058f362__FUN_0058f362.c

```c
// Function: FUN_0058f362 @ 0058f362
// Size (bytes): 400


void FUN_0058f362(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    FUN_0058aa6f(param_1[1]);
    FUN_0058aa6f(param_1[2]);
    FUN_0058aa6f(param_1[3]);
    FUN_0058aa6f(param_1[4]);
    FUN_0058aa6f(param_1[5]);
    FUN_0058aa6f(param_1[6]);
    FUN_0058aa6f(*param_1);
    FUN_0058aa6f(param_1[8]);
    FUN_0058aa6f(param_1[9]);
    FUN_0058aa6f(param_1[10]);
    FUN_0058aa6f(param_1[0xb]);
    FUN_0058aa6f(param_1[0xc]);
    FUN_0058aa6f(param_1[0xd]);
    FUN_0058aa6f(param_1[7]);
    FUN_0058aa6f(param_1[0xe]);
    FUN_0058aa6f(param_1[0xf]);
    FUN_0058aa6f(param_1[0x10]);
    FUN_0058aa6f(param_1[0x11]);
    FUN_0058aa6f(param_1[0x12]);
    FUN_0058aa6f(param_1[0x13]);
    FUN_0058aa6f(param_1[0x14]);
    FUN_0058aa6f(param_1[0x15]);
    FUN_0058aa6f(param_1[0x16]);
    FUN_0058aa6f(param_1[0x17]);
    FUN_0058aa6f(param_1[0x18]);
    FUN_0058aa6f(param_1[0x19]);
    FUN_0058aa6f(param_1[0x1a]);
    FUN_0058aa6f(param_1[0x1b]);
    FUN_0058aa6f(param_1[0x1c]);
    FUN_0058aa6f(param_1[0x1d]);
    FUN_0058aa6f(param_1[0x1e]);
    FUN_0058aa6f(param_1[0x1f]);
    FUN_0058aa6f(param_1[0x20]);
    FUN_0058aa6f(param_1[0x21]);
    FUN_0058aa6f(param_1[0x22]);
    FUN_0058aa6f(param_1[0x23]);
    FUN_0058aa6f(param_1[0x24]);
    FUN_0058aa6f(param_1[0x25]);
    FUN_0058aa6f(param_1[0x26]);
    FUN_0058aa6f(param_1[0x27]);
    FUN_0058aa6f(param_1[0x28]);
    FUN_0058aa6f(param_1[0x29]);
    FUN_0058aa6f(param_1[0x2a]);
  }
  return;
}
```
## FUN_00589aa4 (0x00589aa4)
- **Size:** 204 bytes
- **Source:** decompiled_full/0x00589aa4__FUN_00589aa4.c

```c
// Function: FUN_00589aa4 @ 00589aa4
// Size (bytes): 204


uint FUN_00589aa4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_8;
  
  uVar1 = param_1;
  if (DAT_008d3f38 == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      uVar1 = param_1 - 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (DAT_005e6bd4 < 2) {
        uVar2 = (byte)PTR_DAT_005e69c8[param_1 * 2] & 2;
      }
      else {
        uVar2 = FUN_0058c674(param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_005e69c8[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
      uVar4 = 1;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      uVar4 = 2;
    }
    iVar3 = FUN_00591fa1(DAT_008d3f38,0x200,&param_1,uVar4,&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = local_8 & 0xff;
      }
      else {
        uVar1 = local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}
```
## FUN_005531f0 (0x005531f0)
- **Size:** 167 bytes
- **Source:** decompiled_full/0x005531f0__FUN_005531f0.c

```c
// Function: FUN_005531f0 @ 005531f0
// Size (bytes): 167


void __thiscall FUN_005531f0(int param_1,char *param_2,int *param_3,undefined4 *param_4)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  if (param_4 != (undefined4 *)0x0) {
    uVar3 = __ftol();
    *param_4 = uVar3;
  }
  if (param_3 != (int *)0x0) {
    iVar4 = -1;
    uVar6 = 0;
    *param_3 = 0;
    pcVar7 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      do {
        bVar2 = param_2[uVar6];
        if ((0x1f < bVar2) && ((int)(uint)bVar2 < *(int *)(param_1 + 0x44))) {
          *param_3 = *param_3 + (uint)*(byte *)(param_1 + -0x94 + (uint)bVar2 * 8);
        }
        uVar5 = 0xffffffff;
        uVar6 = uVar6 + 1;
        pcVar7 = param_2;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
      } while (uVar6 < ~uVar5 - 1);
    }
    iVar4 = __ftol();
    *param_3 = iVar4;
  }
  return;
}
```
## FUN_00586670 (0x00586670)
- **Size:** 132 bytes
- **Source:** decompiled_full/0x00586670__FUN_00586670.c

```c
// Function: FUN_00586670 @ 00586670
// Size (bytes): 132


undefined4 __thiscall FUN_00586670(int *param_1,int param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  uVar3 = 0;
  if (param_2 != 0) {
    piVar4 = (int *)0x0;
    piVar5 = (int *)*param_1;
    if ((int *)*param_1 != (int *)0x0) {
      while (*piVar5 != param_2) {
        piVar1 = piVar5 + 1;
        piVar4 = piVar5;
        piVar5 = (int *)*piVar1;
        if ((int *)*piVar1 == (int *)0x0) {
          return uVar3;
        }
      }
      if (piVar5 == (int *)param_1[2]) {
        param_1[2] = piVar5[1];
      }
      if (piVar4 == (int *)0x0) {
        *param_1 = piVar5[1];
      }
      else {
        piVar4[1] = piVar5[1];
      }
      if ((int *)param_1[1] == piVar5) {
        param_1[1] = (int)piVar4;
      }
      param_1[3] = param_1[3] + -1;
      if (param_3 == '\0') {
        *(undefined1 *)(piVar5 + 2) = 0;
      }
      if (((char)piVar5[2] != '\0') && (iVar2 = *piVar5, iVar2 != 0)) {
        FUN_004b0170();
        FUN_00587bcf(iVar2);
      }
      FUN_00587bcf(piVar5);
      uVar3 = 1;
    }
  }
  return uVar3;
}
```
## FUN_00567580 (0x00567580)
- **Size:** 308 bytes
- **Source:** decompiled_full/0x00567580__FUN_00567580.c

```c
// Function: FUN_00567580 @ 00567580
// Size (bytes): 308


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00567580(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  pfVar2 = param_2;
  fVar1 = param_3[1] * param_2[1] +
          *param_2 * *param_3 + param_3[2] * param_2[2] + param_3[3] * param_2[3];
  if (DAT_0059e440 <= fVar1) {
    local_10 = *param_3;
    local_c = param_3[1];
    local_8 = param_3[2];
    local_4 = param_3[3];
    param_3 = (float *)fVar1;
  }
  else {
    local_10 = -*param_3;
    local_c = -param_3[1];
    local_8 = -param_3[2];
    local_4 = -param_3[3];
    param_3 = (float *)-fVar1;
  }
  param_2 = (float *)(_DAT_0059e43c - param_4);
  if (_DAT_0059e6ec < _DAT_0059e43c - (float)param_3) {
    fVar3 = (float10)FUN_005894a0();
    fVar4 = (float10)fsin(fVar3);
    fVar5 = (float10)fsin(fVar3 * (float10)(float)param_2);
    param_2 = (float *)(float)(fVar5 * ((float10)_DAT_0059e43c / fVar4));
    fVar3 = (float10)fsin(fVar3 * (float10)param_4);
    param_4 = (float)(fVar3 * ((float10)_DAT_0059e43c / fVar4));
  }
  *param_1 = local_10 * param_4 + (float)param_2 * *pfVar2;
  param_1[1] = local_c * param_4 + (float)param_2 * pfVar2[1];
  param_1[2] = (float)param_2 * pfVar2[2] + local_8 * param_4;
  param_1[3] = (float)param_2 * pfVar2[3] + local_4 * param_4;
  return;
}
```
## FUN_005894bd (0x005894bd)
- **Size:** 174 bytes
- **Source:** decompiled_full/0x005894bd__FUN_005894bd.c

```c
// Function: FUN_005894bd @ 005894bd
// Size (bytes): 174


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005894bd(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  short in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (fVar1 = _DAT_005e6c50, param_1 != 0)) {
      fVar1 = (float10)FUN_0058dccc();
    }
LAB_0058954c:
    if (DAT_008d3e40 == 0) {
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_0058dcb5();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fVar1 = (float10)fpatan(SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)),in_ST0);
    }
    else {
      fVar1 = _DAT_005e6c50;
      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_0058954c;
      if ((param_2 & 0x80000000) == 0) {
        fVar1 = (float10)0;
      }
      else {
        fVar1 = (float10)3.141592653589793;
      }
    }
    if (DAT_008d3e40 == 0) {
      fVar1 = (float10)__math_exit();
      return fVar1;
    }
  }
  return fVar1;
}
```
## FUN_005817a0 (0x005817a0)
- **Size:** 128 bytes
- **Source:** decompiled_full/0x005817a0__FUN_005817a0.c

```c
// Function: FUN_005817a0 @ 005817a0
// Size (bytes): 128


undefined4 __thiscall FUN_005817a0(int *param_1,int param_2,char param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  uVar2 = 0;
  if (param_2 != 0) {
    piVar3 = (int *)0x0;
    piVar4 = (int *)*param_1;
    if ((int *)*param_1 != (int *)0x0) {
      while (*piVar4 != param_2) {
        piVar1 = piVar4 + 1;
        piVar3 = piVar4;
        piVar4 = (int *)*piVar1;
        if ((int *)*piVar1 == (int *)0x0) {
          return uVar2;
        }
      }
      if (piVar4 == (int *)param_1[2]) {
        param_1[2] = piVar4[1];
      }
      if (piVar3 == (int *)0x0) {
        *param_1 = piVar4[1];
      }
      else {
        piVar3[1] = piVar4[1];
      }
      if ((int *)param_1[1] == piVar4) {
        param_1[1] = (int)piVar3;
      }
      param_1[3] = param_1[3] + -1;
      if (param_3 == '\0') {
        *(undefined1 *)(piVar4 + 2) = 0;
      }
      if (((char)piVar4[2] != '\0') && (*piVar4 != 0)) {
        FUN_00587bcf(*piVar4);
      }
      FUN_00587bcf(piVar4);
      uVar2 = 1;
    }
  }
  return uVar2;
}
```
## FUN_0058f7c9 (0x0058f7c9)
- **Size:** 290 bytes
- **Source:** decompiled_full/0x0058f7c9__FUN_0058f7c9.c

```c
// Function: FUN_0058f7c9 @ 0058f7c9
// Size (bytes): 290


uint FUN_0058f7c9(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  uVar1 = DAT_008d3f88;
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = FUN_005968f6(1,DAT_008d3f88,0x15,param_1 + 0xc);
    uVar4 = FUN_005968f6(1,uVar1,0x14,param_1 + 0x10);
    uVar5 = FUN_005968f6(1,uVar1,0x16,param_1 + 0x14);
    uVar6 = FUN_005968f6(1,uVar1,0x17,param_1 + 0x18);
    uVar7 = FUN_005968f6(1,uVar1,0x18,param_1 + 0x1c);
    FUN_0058f6c7(*(undefined4 *)(param_1 + 0x1c));
    uVar8 = FUN_005968f6(1,uVar1,0x50,param_1 + 0x20);
    uVar9 = FUN_005968f6(1,uVar1,0x51,param_1 + 0x24);
    uVar10 = FUN_005968f6(0,uVar1,0x1a,param_1 + 0x28);
    uVar11 = FUN_005968f6(0,uVar1,0x19,param_1 + 0x29);
    uVar12 = FUN_005968f6(0,uVar1,0x54,param_1 + 0x2a);
    uVar13 = FUN_005968f6(0,uVar1,0x55,param_1 + 0x2b);
    uVar14 = FUN_005968f6(0,uVar1,0x56,param_1 + 0x2c);
    uVar15 = FUN_005968f6(0,uVar1,0x57,param_1 + 0x2d);
    uVar16 = FUN_005968f6(0,uVar1,0x52,param_1 + 0x2e);
    uVar2 = FUN_005968f6(0,uVar1,0x53,param_1 + 0x2f);
    uVar2 = uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12
                    | uVar13 | uVar14 | uVar15 | uVar16;
  }
  return uVar2;
}
```
## FUN_0058858d (0x0058858d)
- **Size:** 174 bytes
- **Source:** decompiled_full/0x0058858d__FUN_0058858d.c

```c
// Function: FUN_0058858d @ 0058858d
// Size (bytes): 174


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0058858d(int param_1,uint param_2)

{
  uint in_EAX;
  bool in_ZF;
  short in_FPUControlWord;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (fVar1 = _DAT_005e6c50, param_1 != 0)) {
      fVar1 = (float10)FUN_0058dccc();
    }
LAB_0058861c:
    if (DAT_008d3e40 == 0) {
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
  }
  else {
    if (in_FPUControlWord != 0x27f) {
      in_EAX = FUN_0058dcb5();
      in_ST0 = extraout_ST0;
    }
    if (in_EAX < 0x3ff00000) {
      fVar1 = (float10)fpatan(in_ST0,SQRT(((float10)1 - in_ST0) * ((float10)1 + in_ST0)));
    }
    else {
      fVar1 = _DAT_005e6c50;
      if ((0x3ff00000 < in_EAX) || ((param_2 & 0xfffff) != 0 || param_1 != 0)) goto LAB_0058861c;
      fVar1 = _DAT_005e6c5a;
      if ((param_2 & 0x80000000) != 0) {
        fVar1 = -_DAT_005e6c5a;
      }
    }
    if (DAT_008d3e40 == 0) {
      fVar1 = (float10)__math_exit();
      return fVar1;
    }
  }
  return fVar1;
}
```
## FUN_005572b0 (0x005572b0)
- **Size:** 149 bytes
- **Source:** decompiled_full/0x005572b0__FUN_005572b0.c

```c
// Function: FUN_005572b0 @ 005572b0
// Size (bytes): 149


void __fastcall FUN_005572b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1b4);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = *(int *)(param_1 + 0x1c4);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = *(int *)(param_1 + 0x1bc);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1c0) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = *(int *)(param_1 + 0x1cc);
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x1d0) + 0x208);
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x84;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}
```
## FUN_0059bb00 (0x0059bb00)
- **Size:** 175 bytes
- **Source:** decompiled_full/0x0059bb00__FUN_0059bb00.c

```c
// Function: FUN_0059bb00 @ 0059bb00
// Size (bytes): 175


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0059bb00(FILE *param_1,int *param_2,uint param_3,uint param_4)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_3 != 4) &&
     (((param_4 < 2 || (0x7fffffff < param_4)) || ((param_3 != 0 && (param_3 != 0x40)))))) {
    return 0xffffffff;
  }
  param_4 = param_4 & 0xfffffffe;
  FUN_0058c1b1(param_1);
  FUN_0058a05a(param_1);
  __freebuf(param_1);
  *(ushort *)&param_1->_flag = (ushort)param_1->_flag & 0xc2f3;
  if ((param_3 & 4) == 0) {
    if (param_2 == (int *)0x0) {
      param_2 = _malloc(param_4);
      if (param_2 == (int *)0x0) {
        _DAT_008d3ec8 = _DAT_008d3ec8 + 1;
        local_8 = 0xffffffff;
        goto LAB_0059bba0;
      }
      *(ushort *)&param_1->_flag = (ushort)param_1->_flag | 0x408;
    }
    else {
      param_1->_flag = param_1->_flag | 0x500;
    }
  }
  else {
    param_1->_flag = param_1->_flag | 4;
    param_2 = &param_1->_charbuf;
    param_4 = 2;
  }
  param_1->_cnt = 0;
  param_1->_bufsiz = param_4;
  param_1->_base = (char *)param_2;
  param_1->_ptr = (char *)param_2;
LAB_0059bba0:
  FUN_0058c203(param_1);
  return local_8;
}
```
## FUN_005895a2 (0x005895a2)
- **Size:** 207 bytes
- **Source:** decompiled_full/0x005895a2__FUN_005895a2.c

```c
// Function: FUN_005895a2 @ 005895a2
// Size (bytes): 207


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005895a2(double param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  undefined4 uVar5;
  
  uVar2 = FUN_00591e66(DAT_005e65a0,0xffff);
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = FUN_00591d2e();
    if (0 < iVar3) {
      if (iVar3 < 3) {
        FUN_00591e66(uVar2,0xffff);
        return (float10)param_1;
      }
      if (iVar3 == 3) {
        fVar4 = (float10)FUN_0059163b();
        return fVar4;
      }
    }
    dVar1 = param_1 + _DAT_005b8c80;
    uVar5 = 8;
  }
  else {
    fVar4 = (float10)__frnd(SUB84(param_1,0),(int)((ulonglong)param_1 >> 0x20));
    dVar1 = (double)fVar4;
    if ((dVar1 == param_1) || ((uVar2 & 0x20) != 0)) {
      FUN_00591e66(uVar2,0xffff);
      return (float10)dVar1;
    }
    uVar5 = 0x10;
  }
  fVar4 = (float10)FUN_0059168f(uVar5,0xb,param_1,dVar1,uVar2);
  return fVar4;
}
```
## FUN_005959a0 (0x005959a0)
- **Size:** 127 bytes
- **Source:** decompiled_full/0x005959a0__FUN_005959a0.c

```c
// Function: FUN_005959a0 @ 005959a0
// Size (bytes): 127


undefined4 FUN_005959a0(uint param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_008d4a20) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_008d4920)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_005e65b4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_005959fc;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_005959fc:
      *(undefined4 *)((&DAT_008d4920)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  puVar2 = (undefined4 *)FUN_0058afcf();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_0058afd8();
  *puVar2 = 0;
  return 0xffffffff;
}
```
## FUN_00591edf (0x00591edf)
- **Size:** 194 bytes
- **Source:** decompiled_full/0x00591edf__FUN_00591edf.c

```c
// Function: FUN_00591edf @ 00591edf
// Size (bytes): 194


int FUN_00591edf(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                )

{
  int iVar1;
  uint uVar2;
  undefined1 local_28 [8];
  int local_20;
  int local_18;
  uint local_14;
  int local_c;
  
  uVar2 = param_1 - 0x76c;
  if (((int)uVar2 < 0x46) || (0x8a < (int)uVar2)) {
    param_6 = -1;
  }
  else {
    param_3 = *(int *)(&DAT_005e9b04 + param_2 * 4) + param_3;
    if (((uVar2 & 3) == 0) && (2 < param_2)) {
      param_3 = param_3 + 1;
    }
    FUN_005921c5();
    local_20 = param_4;
    local_18 = param_2 + -1;
    param_6 = ((param_4 + (uVar2 * 0x16d + param_3 + (param_1 + -0x76d >> 2)) * 0x18) * 0x3c +
              param_5) * 0x3c + DAT_005e7758 + 0x7c558180 + param_6;
    if ((param_7 == 1) ||
       (((param_7 == -1 && (DAT_005e775c != 0)) &&
        (local_14 = uVar2, local_c = param_3, iVar1 = FUN_0059247a(local_28), iVar1 != 0)))) {
      param_6 = param_6 + DAT_005e7760;
    }
  }
  return param_6;
}
```
## FUN_00565400 (0x00565400)
- **Size:** 150 bytes
- **Source:** decompiled_full/0x00565400__FUN_00565400.c

```c
// Function: FUN_00565400 @ 00565400
// Size (bytes): 150


bool __thiscall FUN_00565400(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  
  pcVar2 = (char *)(param_1 + 0x198);
  iVar4 = param_1 - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar4] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar4 = FUN_005897ca(param_1,&DAT_005c30ac);
  *(int *)(param_1 + 0x180) = iVar4;
  while( true ) {
    if (iVar4 == 0) {
      return false;
    }
    iVar4 = FUN_00588410(*(undefined4 *)(param_1 + 0x180),param_2);
    if (iVar4 == 0) break;
    uVar3 = FUN_005897ca(0,&DAT_005c32d8);
    *(undefined4 *)(param_1 + 0x180) = uVar3;
    iVar4 = FUN_005897ca(0,&DAT_005c30ac);
    *(int *)(param_1 + 0x180) = iVar4;
  }
  iVar4 = FUN_005897ca(0,&DAT_005c32d8);
  *(int *)(param_1 + 0x180) = iVar4;
  return iVar4 != 0;
}
```
## FUN_00592bad (0x00592bad)
- **Size:** 153 bytes
- **Source:** decompiled_full/0x00592bad__FUN_00592bad.c

```c
// Function: FUN_00592bad @ 00592bad
// Size (bytes): 153


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00592bad(void)

{
  void *pvVar1;
  char *pcVar2;
  int local_c;
  int local_8;
  
  if (DAT_008d5a4c == 0) {
    FUN_00597218();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_008d40a4,0x104);
  _DAT_008d3ea0 = &DAT_008d40a4;
  pcVar2 = &DAT_008d40a4;
  if (*DAT_008d5a44 != '\0') {
    pcVar2 = DAT_008d5a44;
  }
  FUN_00592c46(pcVar2,0,0,&local_8,&local_c);
  pvVar1 = _malloc(local_c + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    __amsg_exit(8);
  }
  FUN_00592c46(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_c);
  _DAT_008d3e88 = pvVar1;
  _DAT_008d3e84 = local_8 + -1;
  return;
}
```
## FUN_0059033a (0x0059033a)
- **Size:** 134 bytes
- **Source:** decompiled_full/0x0059033a__FUN_0059033a.c

```c
// Function: FUN_0059033a @ 0059033a
// Size (bytes): 134


uint FUN_0059033a(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_7c [120];
  
  uVar1 = FUN_005905dd(param_1);
  iVar2 = (*DAT_008d3fb8)(uVar1,(-(uint)(DAT_008d3f9c != 0) & 0xfffff005) + 0x1002,local_7c,0x78);
  if (iVar2 == 0) {
    DAT_008d3fb0 = 0;
    uVar3 = 1;
  }
  else {
    iVar2 = FUN_00588410(DAT_008d3fac,local_7c);
    if (iVar2 == 0) {
      iVar2 = FUN_00590440(uVar1);
      if (iVar2 != 0) {
        DAT_008d3fb0 = DAT_008d3fb0 | 4;
        DAT_008d3f98 = uVar1;
        DAT_008d3fb4 = uVar1;
      }
    }
    uVar3 = ~DAT_008d3fb0 >> 2 & 1;
  }
  return uVar3;
}
```
## FUN_00568b00 (0x00568b00)
- **Size:** 159 bytes
- **Source:** decompiled_full/0x00568b00__FUN_00568b00.c

```c
// Function: FUN_00568b00 @ 00568b00
// Size (bytes): 159


undefined4 __fastcall FUN_00568b00(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_800 [2048];
  
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  if (iVar1 != 0) {
    iVar2 = FUN_00587db0(param_2,&DAT_005c2ab0);
    if (iVar2 != 0) {
      iVar3 = FUN_0058803f(local_800,1,0x800);
      while (0 < iVar3) {
        FUN_00588678(local_800,1,iVar3,iVar2);
        iVar3 = FUN_0058803f(local_800,1,0x800,iVar1);
      }
      FUN_00587d02(iVar1);
      FUN_00587d02(iVar2);
      return 1;
    }
    FUN_00587d02(iVar1);
  }
  return 0;
}
```
## FUN_0058ff65 (0x0058ff65)
- **Size:** 135 bytes
- **Source:** decompiled_full/0x0058ff65__FUN_0058ff65.c

```c
```
```


## FUN_0058c724 (0x0058c724)
- **Size:** 101 bytes
- **Source:** decompiled_full/0x0058c724__FUN_0058c724.c

```c
// Function: FUN_0058c724 @ 0058c724
// Size (bytes): 101


undefined4 FUN_0058c724(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 < DAT_008d4a20) &&
     ((*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00595a61(param_1);
    uVar1 = FUN_0058c789(param_1,param_2,param_3);
    FUN_00595ac0(param_1);
    return uVar1;
  }
  puVar2 = (undefined4 *)FUN_0058afcf();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_0058afd8();
  *puVar2 = 0;
  return 0xffffffff;
}
```
## FUN_00594a5e (0x00594a5e)
- **Size:** 86 bytes
- **Source:** decompiled_full/0x00594a5e__FUN_00594a5e.c

```c
// Function: FUN_00594a5e @ 00594a5e
// Size (bytes): 86


void FUN_00594a5e(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_005e9988 == param_1) {
    PTR_LOOP_005e9988 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_005e7968) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_008d4904,0,param_1);
    return;
  }
  DAT_005e7978 = 0xffffffff;
  return;
}
```
## FUN_00593dd3 (0x00593dd3)
- **Size:** 72 bytes
- **Source:** decompiled_full/0x00593dd3__FUN_00593dd3.c

```c
// Function: FUN_00593dd3 @ 00593dd3
// Size (bytes): 72


undefined4 FUN_00593dd3(undefined4 param_1)

{
  DAT_008d48fc = HeapAlloc(DAT_008d4904,0,0x140);
  if (DAT_008d48fc == (LPVOID)0x0) {
    return 0;
  }
  DAT_008d48f4 = 0;
  DAT_008d48f8 = 0;
  DAT_008d48f0 = DAT_008d48fc;
  DAT_008d4900 = param_1;
  DAT_008d48e8 = 0x10;
  return 1;
}
```
## FUN_00589057 (0x00589057)
- **Size:** 83 bytes
- **Source:** decompiled_full/0x00589057__FUN_00589057.c

```c
// Function: FUN_00589057 @ 00589057
// Size (bytes): 83


void FUN_00589057(undefined4 param_1,int param_2)

{
  FUN_0058fca0(param_1,param_2);
  if (*(char *)(param_2 + 0x40) != '\0') {
    FUN_00588f66(param_1,2,&DAT_005cc214,param_2 + 0x40);
  }
  if (*(char *)(param_2 + 0x80) != '\0') {
    FUN_00588f66(param_1,2,&DAT_005beb48,param_2 + 0x80);
  }
  return;
}
```
## FUN_00589b9e (0x00589b9e)
- **Size:** 40 bytes
- **Source:** decompiled_full/0x00589b9e__FUN_00589b9e.c

```c
// Function: FUN_00589b9e @ 00589b9e
// Size (bytes): 40


uint FUN_00589b9e(int param_1)

{
  uint uVar1;
  
  if (1 < DAT_005e6bd4) {
    uVar1 = FUN_0058c674(param_1,4);
    return uVar1;
  }
  return (byte)PTR_DAT_005e69c8[param_1 * 2] & 4;
}
```
## FUN_0059942b (0x0059942b)
- **Size:** 58 bytes
- **Source:** decompiled_full/0x0059942b__FUN_0059942b.c

```c
// Function: FUN_0059942b @ 0059942b
// Size (bytes): 58


undefined4 * __thiscall FUN_0059942b(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[2] = DAT_005b9cd8;
  param_1[3] = DAT_005b9cdc;
  FUN_0059a54d();
  param_1[4] = DAT_008d5a6c;
  FUN_0059a5e9();
  return param_1;
}
```
## FUN_005903c0 (0x005903c0)
- **Size:** 26 bytes
- **Source:** decompiled_full/0x005903c0__FUN_005903c0.c

```c
// Function: FUN_005903c0 @ 005903c0
// Size (bytes): 26


void FUN_005903c0(void)

{
  DAT_008d3fb0._0_2_ = (ushort)DAT_008d3fb0 | 0x104;
  DAT_008d3fb4 = GetUserDefaultLCID();
  DAT_008d3f98 = DAT_008d3fb4;
  return;
}
```## FUN_0054d9f0 — Bounding Box Computation

Source: likely meshcull.cpp or renderobject.cpp. Computes AABB (min/max) and center/half-extents for mesh vertex data. Handles morph target interpolation.

**Key logic:**
- Walks linked list at +0x13c (next at +0x24)
- For each mesh: reads vertex position data via function pointer at DAT_008b8f24
- Tracks per-axis min/max: local_48_x_max, local_44_x_min, local_40_y_max, local_3c_y_min, local_38_z_max, local_34_z_min
- Branch on flag at +0x14 bit 0x800000: direct read vs. blended morph (interpolates between base and target pose)
- Blending: fStack_20 = current_blend / blend_duration at +0x144
- Writes AABB results to +0x1c through +0x78 (min/max per face, center, extents)
- Computes bounding sphere radius = SQRT(extent_x² + extent_y² + extent_z²) to +0x18
- Stride 0x30 (48 bytes) per vertex, 0x88 stride per bone-set

**Globals:**
- `DAT_008b8f24` — transform function table
- `DAT_008b8f28` — global transform data
- `DAT_0059e440` — zero threshold
- `DAT_0059e450` — half constant (0.5)

**Calls:** FUN_0054e0e0 (read lock), FUN_0054e0f0 (read unlock), FUN_0055d900, FUN_0055da50, FUN_0055e320, FUN_0055eb30

**Moddability:** hardcoded

## FUN_00504b37 — COM Interface Vector Processing Method

Source: likely d3dx_interface.cpp or custom COM-like pipeline interface. Processes 4-float vectors through a pipeline stage. Returns HRESULT.

**Key logic:**
- Validates state via FUN_0058a5d8, checks dimensions at +0x1058/0x105c (width/height)
- Allocates output buffers via operator_new, uses _vector_constructor_iterator_
- Processes 4D vectors (stride 0x20 = 32 bytes = 4 floats)
- Accumulates + averages across sub-samples based on width/height
- Multiplies by _DAT_0059e7f8 (normalization factor)
- Branch on dimension: 1x1, 1xN, or NxM processing paths
- Calls vtable methods at offsets +4 and +8 on COM objects

**Calls:** FUN_0058a5d8, FUN_00587bcf, FUN_00503f75, FUN_00503659, FUN_005038ef, FUN_00503920, FUN_00503a70, FUN_00503b94, FUN_00503ce3, FUN_00503e36, FUN_00504010, FUN_0050415c, FUN_0050427d, FUN_005043c9, _vector_constructor_iterator_

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004b6c90 — Model/Scene File Loader

Source: likely modelloader.cpp or sceneloader.cpp. Reads binary model data from file stream, constructs object and component linked lists.

**Key logic:**
- Reads strings via FUN_00566650 (name strings)
- Reads flags: +0xf1c (visibility?), +0xf20, +0xf24 (object count)
- Reads local_104 objects: creates new nodes per object, stores in param_1 + 0x30 array (stride 0x10)
- For each object: calls FUN_004ba780 (begin object), FUN_004bafc0/FUN_004bb0c0 (get mesh data)
- Links objects into doubly-linked list at +0x6c0/0x6c4/0x6c8/0x6cc
- Reads second pass: local_113 objects → linked list at +0x6c0 (shadow/light objects)
- Reads +0xf24 objects → linked list at +0x714 (component list)
- Sets float range at +0xf30/+0xf34 (LOD or animation range)

**Calls:** FUN_004b8090, FUN_00566c00, FUN_00566650, FUN_004b5e50, FUN_004ba780, FUN_004ba830, FUN_004bafc0, FUN_004bb0c0, FUN_004b5040, FUN_004bb460, FUN_004b4250, FUN_004b5f60, FUN_004bb6b0, FUN_004bb200, FUN_004bacf0, FUN_004b44a0, FUN_004b43e0, FUN_00587bcf

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00550ad0 — Mesh Vertex/Index Buffer Loader

Source: likely meshloader.cpp or d3dmesh.cpp. Reads mesh vertex and index data from binary file, allocates buffer structures.

**Key logic:**
- Reads file via FUN_0058803f, uses DAT_008b8f30/8b8f34 as temp read buffers
- Two modes from param_1 flags: bit 0 = indexed (vertices + indices), bit 1 = non-indexed (vertex batches)
- Indexed: allocates stride 0x2c (44 bytes) per vertex, stores in param_1[4]; 0x20-byte sub-buffers per vertex at param_1[4]+0x28
- Non-indexed: allocates stride 0xc per batch, each batch has sub-arrays of 0x24-byte elements
- Computes vertex positions via stride * pfVar1 (scale = _DAT_0059e43c / param_1[1])

**Globals:**
- `DAT_008b8f30` — temp file read buffer
- `DAT_008b8f34` — temp file read buffer (secondary)

**Calls:** FUN_0058ace6 (file size), FUN_00587f64 (file seek), FUN_0058803f (file read), FUN_0059b260 (decompress?), FUN_0054a5c0 (stream read), FUN_00589901 (post-process), FUN_00587bcf, FUN_005507e0, FUN_005507a0, FUN_005593b0, FUN_00550800

**Moddability:** hardcoded

## FUN_00500bc8 — D3D Surface Copy/Blit

Source: likely d3dsurface.cpp or d3d9.cpp. COM surface copy/blit with format conversion across two resources.

**Key logic:**
- Validates surface type: 3 (texture), 4 (cube map), 5 (volume texture) via vtable+0x28
- Handles MSAA resolve: checks if samples are power-of-2, selects multisample format flags
- Blits surface data: vtable+0x38 (LockRect), +0x3c (source copy)
- Iterates sub-resources (array slices, mip levels, cube faces)
- Calls FUN_0050099c or FUN_00500b42 for actual pixel copy depending on surface type

**Calls:** FUN_0050099c, FUN_00500b42

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_005435d0 — Audio Mixer Channel Initializer

Source: likely audiomixer.cpp or soundmanager.cpp. Initializes a mixer channel/voice struct with default values.

**Key logic:**
- Calls FUN_0053c2a0 and FUN_0053c6a0 (mixer setup)
- Sets all fields to 0
- Sets volume: +0x17c/0x180/0x184 = 0x3f800000 (1.0 = full volume)
- Sets pan/balance: +0x1d4 = 0x3f800000 (1.0 = center)
- Sets pitch: +0x198 = 0x447a0000 (1000.0 Hz default)
- Sets spatial position: +0x188 = 0xb4 (180), +0x18a/0x18c = 0xa0 (160)
- Sets buffer size: +0xec = 0x2000 (8192 bytes)
- Calls FUN_0053cac0 to init substruct at +0x110

**Moddability:** configurable (defaults are compile-time)

<!-- target: docs/21-audio-network-internals.md -->

## FUN_005033a5 — DXT Compressed Texture Block Copy

Source: likely d3dtex.cpp. Copies aligned blocks between two DXT1-5 compressed texture surfaces.

**Key logic:**
- Validates both source/dest surface alignment: bits 0-1 of +0x1030-0x103c must be 0 (4-pixel alignment)
- Checks fourCC format: DXT1 (0x31545844) → 8-byte blocks, DXT2-5 → 16-byte blocks
- Computes source/dest pixel offsets from +0x1030/0x1034 (sub-offsets), +0x1040/0x1050/0x1054 (pitch)
- Nested loops: for each row (uVar5 = +0x105c), for each column (uVar3 >> 2 * block_size)
- Copies 4-byte chunks via pointer copy
- Returns HRESULT

**Calls:** none

**Moddability:** hardcoded

## FUN_0051d897 — Palette/Vector Quantization Nearest Neighbor

Source: likely texturecvt.cpp or palette.cpp. Weighted nearest-neighbor search for color quantization or palette lookup.

**Key logic:**
- Reads palette/table from in_EAX+0x70 (count) and +0x74 (data array of RGB triples)
- For each candidate: computes weighted squared distance from target (param_1, unaff_EDI, param_2)
- Weighting: red ×2, green ×3, blue ×1 (perceptual weighting?)
- Target range: param_1 ± 0x18, unaff_EDI ± 0x1c, param_2 ± 0x18 (tolerance window)
- Finds minimum distance across all candidates
- Writes all candidates within tolerance to param_3 output buffer

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004366e0 — Best-Fit Plane Fitting

Source: likely mathutils.cpp or collision.cpp. Fits a plane to a point cloud using PCA/covariance accumulation.

**Key logic:**
- Accumulates 6 sums from param_1 data (stride 0x1c): x², xy, xz, y², yz, z², plus sums of x, y, z, count
- Computes covariance-like matrix elements
- If FUN_005677b0() returns 0: computes plane normal from cross product of dominant axes
- Normalizes normal, stores in param_3, stores centroid*normal dot in param_4
- Falls back to identity quaternion + centroid if degenerate

**Calls:** FUN_005677b0 (synchronization/check)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0056a150 — Vehicle Physics State Copy + Transform

Source: likely vehiclephysics.cpp or stateupdate.cpp. Copies vehicle physics state between struct regions and applies matrix-vector multiply.

**Key logic:**
- Copies 6 dwords from +0x59 to +0x01, then 0x12 dwords from +0x5f to +0x07, 6 from +0x71 to +0x19, 6 from +0x77 to +0x25, 6 from +0x7d to +0x4d, 6 from +0x83 to +0x53
- Computes matrix-vector multiply: param_1[0x3b..0x4b] × [param_1[0x25], param_1[0x27], param_1[0x29]]
- Stores result at param_1[0x1f], param_1[0x21], param_1[0x23]

**Calls:** FUN_005692a0

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0044a170 — Visibility/Frustum Test

Source: likely culling.cpp or renderer.cpp. Computes visible element ratio from array of transformed coordinates.

**Key logic:**
- Initializes min/max/median to ±FLT_MAX
- First pass (param_3 elements): tracks element min/max, optionally stores prev pointer chain
- Second pass (param_4 elements): counts elements below threshold, tracks min/max
- Computes ratio: local_4/param_4 + bias from median spread
- Result in param_1[6]: visibility ratio (0-1+)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00443150 — Wheel Contact Force Solver

Source: likely tirecontact.cpp. Applies spring/damper contact force from wheel deflection to body.

**Key logic:**
- Body-local transform via FUN_00435e00(body at +0x15f0)
- Deflection check (local_10 < 0 = ground contact)
- Spring/damper: coeffs from param_2+0x34/0x3c/0x44
- Force distributed through body inertia matrix
- Applied via FUN_00569ad0

**Moddability:** hardcoded

## FUN_00401180 — Ray-Sphere/Quadratic Intersection Test

Source: likely collision.cpp or raycast.cpp. Solves ray intersection with a quadratic surface (sphere/ellipsoid).

**Key logic:**
- Takes 6 doubles: param_1-2 (ray origin), param_3-4 (ray direction), param_5-6 (sphere center offset)
- Computes quadratic coefficients: a = dx²+dy², b = ..., c = ...
- Handles degenerate cases (zero denominators)
- Solves via cross-multiplication, returns t where t = 1/distance
- Returns _DAT_0059e428 (≈0) if no intersection

**Moddability:** hardcoded

```


<!-- target: docs/01-engine-architecture.md -->

## FUN_00558cb0 — Array Element Flag Set with Bounds Check

Source: unknown | Confidence: high (Data/FlagSet pattern)
Sets bit 0x4000 on array element at computed index. Guarded by bounds check against capacity.

**Key logic:**
- If param_2 < *(param_1 + 0x2c) (element count vs capacity):
  - Calls FUN_0053b330(param_3, param_4, param_5) (setup/transform)
  - Sets flag |= 0x4000 at array offset: *(param_1 + 0x34) + param_2 * 0x80
- Array element stride = 0x80 bytes (128 bytes per element)
- Element capacity stored at param_1 + 0x2c

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x2c  | ElementCapacity | int | array length cap |
| +0x34  | ArrayBasePtr | int* | pointer to element array (stride 0x80) |

**Calls:** FUN_0053b330 (setup/transform helper, per docs/20)

**Used by system:** docs/01-engine-architecture.md — array-based flag tracking for entities/objects

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055ef24 — 3x3 Matrix × Float3 Vector Multiply

Source: unknown | Confidence: high (Math/3D pattern)
Multiplies a 3x3 matrix (row-major) by a 3-component float vector. Returns result in param_4.

**Key logic:**
- param_3 = input vector (3 floats: x, y, z at indices 0, 1, 2)
- param_5 = 3×3 matrix (9 floats stored row-major: m00..m02, m10..m12, m20..m22)
- Output per row:
  - result.x = m00*v.x + m10*v.y + m20*v.z
  - result.y = m01*v.x + m11*v.y + m21*v.z
  - result.z = m02*v.x + m12*v.y + m22*v.z
- This is standard 3×3 matrix × column-vector multiplication (M*v)

**Algorithm family:** 3D vector/matrix math — matrix-vector multiply

**Calls:** none (leaf function)

**Used by system:** docs/18-physics-dynamics.md — 3D transforms for physics

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00568be0 — QPC Timer Initialization

Source: unknown | Confidence: high (Sys/Timer pattern)
Initializes performance timer struct using QueryPerformanceCounter/Frequency.

**Key logic:**
- If param_2 == 1: calls QueryPerformanceFrequency + QueryPerformanceCounter
  - Stores counter low/high in param_1[6]/param_1[7]
  - Stores frequency low in *param_1
- Copies counter to param_1[8] (last sample copy)
- Stores param_2 in param_1[0x12] (timer mode)
- Zeroes param_1[10], param_1[0xb], param_1[4], param_1[5]
- Computes: *(double*)(param_1 + 2) = _DAT_005af448 / (double)*param_1
  - _DAT_005af448 = timer scaling constant (converts QPC ticks to game time units)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00  | FrequencyLowPart | uint | QPC frequency low DWORD |
| +0x08  | InvFrequencyScaled | double | _DAT_005af448 / freq |
| +0x10–+0x14 | AccLow/AccHigh | uint | Zeroed accumulators |
| +0x18–+0x1c | CounterLow/CounterHigh | uint | QPC init sample |
| +0x20–+0x24 | LastSampleLow/High | uint | Copy of init sample |
| +0x28–+0x2c | Acc/Overflow | uint | Zeroed |
| +0x48  | Mode | uint | Timer mode flags |

**Globals:**
- `_DAT_005af448` — timer frequency scaling constant

**Calls:** QueryPerformanceFrequency, QueryPerformanceCounter (Win32 API)

**Used by system:** docs/01-engine-architecture.md — performance timer init

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_005835f0 — Timer Init with SEH

Source: unknown | Confidence: high (Sys/TimerInit pattern)
Initializes a timer: calls FUN_00568ba0, FUN_00568be0(1), and FUN_00583660(0). Wrapped in MSVC SEH __try/__except.

**Key logic:**
- Sets up SEH handler (ExceptionList = &local_c, handler at 0x0059ce4b)
- Calls FUN_00568ba0 (timer struct zero-init, 17 fields)
- Sets local_4 = 0 (signals success)
- Calls FUN_00568be0(1) — QPC timer initialization with mode=1
- Calls FUN_00583660(0) — unknown init
- Restores ExceptionList
- Returns param_1

**Calls:** FUN_00568ba0 (frame/poll timer init — struct zero-init), FUN_00568be0(1) (QPC timer init), FUN_00583660(0) (unknown init)

**Used by system:** docs/01-engine-architecture.md — timer init with structured exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005870d0 — Set Vtable Pointer and Call Init

Source: unknown | Confidence: high (Data/Init pattern)
Sets vtable pointer to PTR_FUN_005b8c30 then calls FUN_00499ae0.

**Key logic:**
- *param_1 = &PTR_FUN_005b8c30 (vtable pointer assignment)
- Calls FUN_00499ae0 (init function)
- Standard C++ constructor prologue: set vtable, then call member init

**Calls:** FUN_00499ae0 (generic init/constructor helper)

**Used by system:** docs/01-engine-architecture.md — C++ object construction helper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00588864 — __global_unwind2 (MSVC CRT SEH Unwind)

Source: MSVC CRT | Confidence: high
MSVC CRT library function. Wraps RtlUnwind for structured exception handling global unwind.

**Key logic:**
- Calls RtlUnwind(param_1, (PVOID)0x58887c, NULL, NULL)
- Return address bookmark at 0x58887c
- Standard MSVC __global_unwind2 implementation

**Calls:** RtlUnwind (NTDLL API)

**Used by system:** docs/20-math-utilities.md — MSVC CRT SEH support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00592a62 — Array-of-Struct Stride Search

Source: unknown | Confidence: high (Algo/StrideSearch pattern)
Linear search for matching element in array-of-structs. Stride = 3 ints (12 bytes). Entry count from global DAT_005e7894.

**Key logic:**
- param_1 = search key, param_2 = array base pointer
- Each element = 3 ints (stride 12 bytes)
- Searches for element where *element_ptr == param_1
- Max entries from DAT_005e7894 (global constant)
- If found: returns pointer to matching element
- If not found or out of bounds: returns NULL

**Globals:**
- `DAT_005e7894` — array entry count

**Used by system:** docs/20-math-utilities.md — generic array search utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00595733 — __amsg_exit Runtime Error (CRT)

Source: MSVC CRT | Confidence: high
MSVC CRT runtime error handler. Calls __amsg_exit(2) — prints error message and exits.

**Key logic:**
- Calls __amsg_exit(2) — error code 2 = "runtime error" / abort
- No return (exit function)

**Calls:** __amsg_exit (MSVC CRT runtime error display + exit)

**Used by system:** docs/20-math-utilities.md — MSVC CRT error handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005986df — Locale Function Call Wrapper

Source: MSVC CRT | Confidence: high
Calls FUN_00598e2e(0) — locale/debug function call.

**Key logic:**
- Calls FUN_00598e2e(0) — MSVC locale/internal function
- No return value

**Calls:** FUN_00598e2e (locale/CRT function — unknown)

**Used by system:** docs/20-math-utilities.md — MSVC CRT locale support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598cdc — std::basic_streambuf::uflow (Stream Underflow)

Source: MSVC CRT (Visual Studio 2003 Release) | Confidence: high
std::basic_streambuf::uflow — reads one character from input buffer, advances position.

**Key logic:**
- Calls vtable[0x10/4] = virtual underflow() function (at vtable offset 0x10)
- If underflow returns -1 (EOF): returns -1
- Else: calls _Gninc(this) — advance get pointer and return previous byte
- Returns byte value (0-255) or -1 on EOF

**Calls:** vtable dispatch (underflow virtual), _Gninc (CRT internal — advance get pointer)

**Used by system:** docs/20-math-utilities.md — MSVC CRT stream I/O

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599bf0 — Locale Object Alloc and Vtable Setup

Source: MSVC CRT | Confidence: medium (decompiled with stack variable unaff_EBP)
Creates and initializes a locale/std::locale object with vtable pointers. Calls FUN_0059a3a9 for locale init.

**Key logic:**
- Calls FUN_0058a5d8 (stack probe/SEH init)
- If *(unaff_EBP + 0x10) != 0: sets vtable to DAT_005b9c5c, zeroes field[0xb], sets vtable2 to PTR_FUN_005b9c50
- Sets field[1] = 0
- Writes PTR_LAB_005b9c40 to vtable-determined offset
- Calls FUN_0059a3a9(uVar2, uVar1) — locale initialization
- Restores ExceptionList (SEH epilogue)
- Returns extraout_ECX (constructed object pointer)

**Globals:**
- `DAT_005b9c5c` — locale vtable pointer
- `PTR_FUN_005b9c50` — secondary vtable pointer
- `PTR_LAB_005b9c40` — locale facet pointer

**Calls:** FUN_0058a5d8 (stack probe/SEH init), FUN_0059a3a9 (locale init helper)

**Used by system:** docs/20-math-utilities.md — MSVC CRT locale initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00404030 — Zero-Vector Check (Both Inputs 3-Component)

Source: unknown | Confidence: high (math_util)
Returns 0 if both 3-component float vectors are all zeros (compared to DAT_0059e440 ≈ 0.0f threshold).

**Key logic:**
- Checks param_1[0], param_1[2] against zero threshold (DAT_0059e440 ~0.0f)
- Checks param_2[0], param_2[1], param_2[2] against zero threshold
- Returns 0 (true/null) if ALL 5 floats are near-zero
- Returns 1 (false/non-null) otherwise
- Used to test if two vectors are both effectively zero

**Globals:**
- `DAT_0059e440` (ZeroThreshold, ~0.0f physics clamp) — zero comparison constant

**Algorithm family:** float vector utility — zero check

**Used by system:** docs/20-math-utilities.md — vector math utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404f70 — Conditional Free with Bit 0 Flag

Source: unknown | Confidence: high (Data/FlagSet pattern)
Frees *param_1 if non-null, then optionally frees param_1 itself if bit 0 of param_2 is set.

**Key logic:**
- If *param_1 != 0: calls FUN_00587bcf(*param_1) — free inner pointer
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1) — free container
- Returns param_1 (this pointer, pass-through)
- Standard C++ "scalar deleting destructor" pattern

**Calls:** FUN_00587bcf (memory free/dealloc)

**Used by system:** docs/20-math-utilities.md — memory management / scalar deletion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406060 — Dot Product with Scale + Offset

Source: unknown | Confidence: high (math_util)
Computes weighted dot product of param_2 (3-float vector) with vector from indirection at param_1+0x54+0x70. Scales by globals and adds offset.

**Key logic:**
- Reads ptr from param_1 + 0x54
- Dot product: ptr[0x70..0x78] · param_2[0..2]
  = ptr[0x70]*param_2[0] + ptr[0x74]*param_2[1] + ptr[0x78]*param_2[2]
- Scales by _DAT_0059e4e8, adds _DAT_0059e43c, scales by _DAT_0059e450
- Returns float10 (x87 extended precision)

**Globals:**
- `_DAT_0059e4e8` — physics/math scaling constant
- `_DAT_0059e43c` — physics offset constant
- `_DAT_0059e440` — physics zero threshold (not used directly but nearby)

**Algorithm family:** float vector math — dot product + linear transform

**Used by system:** docs/20-math-utilities.md — physics/math computation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00407be0 — Linked List Node Removal by Key

Source: unknown | Confidence: high (unknown — linked list manipulation)
Removes a node from a singly-linked list by matching key value. Calls vtable destructor on removed node.

**Key logic:**
- param_1 = list struct (head at +8, tail at +0xc, current at +0x10, count at +0x14)
- Sets current position to head (+0x10 = +0x08)
- Traverses list comparing *node == param_2 (key match)
- When match found:
  - Updates current (+0x10) to next node
  - Updates predecessor's next pointer or head (+0x08)
  - Updates tail (+0x0c) if removing tail node
  - Decrements count (+0x14)
  - If node[2] flag set and *node non-null: calls vtable destructor at (**node)[0](1)
  - Frees node with FUN_00587bcf

**Calls:** FUN_00587bcf (memory free/dealloc)

**Used by system:** docs/20-math-utilities.md — generic linked list utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408420 — Reciprocal with Sign Check

Source: unknown | Confidence: high (math_util)
Computes reciprocal of param_2 with special handling. Sets fields at param_1+4 and param_1+8.

**Key logic:**
- Checks if param_2 ≈ 0.0f (against DAT_0059e440 threshold) and specifically if param_2 < 0 and param_2 == 0 (sign check)
- param_1[1] (+0x04) = 1.0f (always)
- If param_2 is negative-zero (param_2 < 0 and == 0): param_1[2] (+0x08) = 1.0f
- Else: param_1[2] = _DAT_0059e43c / param_2 (reciprocal scaled by physics constant)

**Globals:**
- `DAT_0059e440` (ZeroThreshold) — zero comparison
- `_DAT_0059e43c` — physics scaling constant

**Algorithm family:** float math — reciprocal with edge case handling

**Used by system:** docs/20-math-utilities.md — physics math utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040b560 — Struct Init with Vtable

Source: unknown | Confidence: high (math_util)
Initializes a 6-field struct: sets vtable to PTR_LAB_0059e6ac, zeroes 5 fields.

**Key logic:**
- *param_1 = &PTR_LAB_0059e6ac (vtable)
- param_1[1] = 0
- param_1[2] = 0
- param_1[3] = 0
- param_1[4] = 0
- param_1[5] = 0

**Globals:**
- `PTR_LAB_0059e6ac` — vtable pointer

**Used by system:** docs/20-math-utilities.md — object initialization

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0040e6a0 — Constants Struct Init (Float Array)

Source: unknown | Confidence: high (math_util)
Writes 7 precomputed float constants at param_1[0..6].

**Key logic:**
- param_1[0] = 0x41200000 = 10.0f
- param_1[1] = 0x3f800000 = 1.0f
- param_1[2] = 0x3f800000 = 1.0f
- param_1[3] = 0x3f800000 = 1.0f
- param_1[4] = 0x451c4000 = 2500.0f
- param_1[5] = 0x42700000 = 60.0f
- param_1[6] = 0x3f333333 = 0.7f
- Array of physics/game tuning constants

**Used by system:** docs/20-math-utilities.md — constant initialization

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00456150 — Struct Field Copy (3 Values)

Source: unknown | Confidence: high (math_util)
Copies 3 undefined4 values from param_2 to offsets +0x24, +0x28, +0x2c of param_1.

**Key logic:**
- If param_2 != NULL:
  - param_1[0x24] = param_2[0]
  - param_1[0x28] = param_2[1]
  - param_1[0x2c] = param_2[2]
- Simple field-by-field copy with null guard

**Used by system:** docs/20-math-utilities.md — struct copy utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b300 — Single Function Call Wrapper

Source: unknown | Confidence: high (math_util)
Calls FUN_0045bb90 with no arguments.

**Key logic:**
- Calls FUN_0045bb90()
- Simple delegation/dispatch

**Calls:** FUN_0045bb90 (unknown)

**Used by system:** docs/20-math-utilities.md — wrapper/dispatch

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0045cbf0 — Short Array Lookup and Zero Check

Source: unknown | Confidence: high (math_util)
Reads short from 2D array at param_1 + 0x12c4 + param_2*2, passes to FUN_0045c7c0, checks if result is zero.

**Key logic:**
- Reads short from array: *(short*)(param_1 + 0x12c4 + param_2 * 2)
- Calls FUN_0045c7c0(short_value, param_3)
- If result != DAT_0059e440 (zero threshold): returns 1
- Else: returns 0

**Globals:**
- `DAT_0059e440` (ZeroThreshold, ~0.0f)

**Calls:** FUN_0045c7c0 (unknown — converts short to float?)

**Used by system:** docs/20-math-utilities.md — array lookup utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00460c30 — Linear Search in 104-Element Array

Source: unknown | Confidence: high (math_util)
Linear search for param_2 in an array of 104 ints at param_1 + 0x3e18.

**Key logic:**
- Array at param_1 + 0x3e18, 0x68 = 104 elements
- Returns index (0-103) if found
- Returns 0x3f (63) if not found (default/fallback index)

**Used by system:** docs/20-math-utilities.md — array search

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004647d0 — Linked List Merge Sort (Recursive)

Source: unknown | Confidence: high (unidentified — merge sort algorithm)
Recursive merge sort on singly-linked list. Split at midpoint by counting and traversing. Compares element[2] as sort key.

**Key logic:**
- Returns NULL if param_1 is NULL
- Returns param_1 if list has < 2 elements
- Splits list at index (count/2 - 1): breaks link at midpoint
- Recursively sorts both halves
- Merges: compares ((*piVarx)[2]) as primary sort key
  - If key == -1: uses *piVarx[0] as secondary key
  - Merges nodes in ascending order
- Returns merged sorted list head

**Algorithm family:** linked list — merge sort

**Used by system:** docs/20-math-utilities.md — generic sorting utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00465150 — Single Call Wrapper

Small wrapper, calls FUN_00464d30(). No local logic.
**Calls:** FUN_00464d30 (unknown)

<!-- target: docs/20-math-utilities.md -->

## FUN_00466980 — Vtable Set with Init Call

Calls FUN_0048d3a0(param_2, param_3), sets vtable to PTR_FUN_0059f2c8. Returns param_1.
**Calls:** FUN_0048d3a0 (init — unknown)

<!-- target: docs/06-session-race-logic.md -->

## FUN_00479760 — Init with Float Constants

Calls FUN_00466980(0.5f, 1.0f). Sets vtable PTR_FUN_005a4e70. Returns param_1.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00494bf0 — Delegation Wrapper (5 args)

Passes param_2-6 to FUN_00543440. Simple passthrough.

<!-- target: docs/20-math-utilities.md -->

## FUN_00495810 — String Normalize + Lookup

Copies param_1 to local buffer, normalizes via FUN_00589901. Strips token at DAT_005cc79c (a delimiter). Appends DAT_005cc79c and DAT_005cc7a0 to end. Calls FUN_00494de0 for lookup/dispatch. Returns result or 0xFFFFFFFF on null input.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00499ee0 — Twin Field Getter

Reads param_1+0x60 into *param_2 and param_1+100 into *param_3. Simple getter.

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a5a0 — Dual Conditional Free

If param_1+0xc non-null: frees. If param_1+4 non-null: frees. Partial destructor.

<!-- target: docs/20-math-utilities.md -->

## FUN_0049b060 — Free Callback Registration (atexit-like)

Calls FUN_00587b3e(&DAT_0049b070). Registers cleanup handler at DATA address.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a0000 — Empty Stub

Immediate return. Placeholder/stripped virtual method.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9f70 — Object Init

Calls FUN_004b9780(). Zeroes param_1[0] and byte at param_1+4. Returns param_1.

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004c0370 — Struct Init with Defaults (-1)

Sets param_1[0]=0 and [1..8]=0xFFFFFFFF. Initializes to sentinel values.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c3890 — Composite String Compare

Calls FUN_00587ece on param_2+0x74 and param_1+0x74. Returns true if param_1 string < param_2 string.

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7c80 — Free Callback Registration

Calls FUN_00587b3e(&LAB_004c7c90). Atexit-style cleanup.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004dac30 — Size/Offset Table by Mode

Switch on param_1 (0-5). Returns 3 presets (x, y, width) in param_2/3/4. E.g. default: 0x32, 0x24e, 0x332. Screen region coordinates.

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc2d0 — Single Call Wrapper

Calls FUN_00567a00(). Delegation.

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcf30 — Twin Field Getter (param_1+0x14, +0x18)

If param_2 non-null: writes param_1+0x14 to *param_2. If param_3 non-null: writes param_1+0x18 to *param_3.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050c4bb — Bilinear Interpolation (3D)

Computes bilinear blend of two vectors param_3 and param_4 against param_2 base, using weights param_5 and param_6. Output at param_1. result = (v4-v2)*w2 + (v3-v2)*w1 + v2. Per-component for x,y,z.

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d748 — Axis-Angle to 4x4 Rotation Matrix

Computes 4x4 rotation matrix from axis (param_2) and angle (param_3). Uses cos/sin. Standard Rodrigues' rotation formula. Sets last row/col to [0,0,0,1]. param_1[16] output.

**Algorithm family:** 3D matrix — axis-angle rotation

<!-- target: docs/19-renderer.md -->

## FUN_00519346 — Malloc Wrapper

Calls _malloc(param_2). Simple CRT alloc wrapper. No null check.

<!-- target: docs/19-renderer.md -->

## FUN_0052a090 — Indirect Call Dispatch

Calls function pointer at param_2+0x24 with (*(param_2+0x28), param_1). Thin indirection wrapper.

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e530 — Object Init

Zeros param_1[0], [1], and byte at param_1+8. Calls FUN_0052e550(0, 1). Returns param_1.

<!-- target: docs/20-math-utilities.md -->

## FUN_00535560 — 4-Bit Field Pack

Calls FUN_00534e70 four times (each returns 0-255). Packs into single int: iVar1 + iVar2<<8 + iVar3<<16 + iVar4<<24. If iVar4==-1: writes 0xfffffffd to param_1+0x38. Color/RGBA packing.

<!-- target: docs/20-math-utilities.md -->

## FUN_00539830 — Object Alloc + Field Init

Calls vtable[0x20/4](0x1a) — alloc 0x1a-byte object. Sets fields: +4=(byte), [0]=0, +0x11=param_2, +0x12=return_addr, +0x16=param_3.

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b3b0 — Identity 4×4 Matrix Init

Zeroes 16 floats (param_1+10 to +0x19). Sets diagonal to 1.0 (0x3f800000) at +10, +0xf, +0x14, +0x19. Sets param_1[0]=1. Identity matrix.

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c680 — Three-Global Setter

Writes param_1 to _DAT_008b8f08, param_2 to DAT_008b8f0c, param_3 to _DAT_008b8f10.

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d400 — Single Global Setter

Writes param_1 to DAT_008b8e4c.

<!-- target: docs/20-math-utilities.md -->

## FUN_00540da0 — Conditional Bitmask Cleanup

If param_1 != 0: if param_2 & 4: calls FUN_00540f90(param_1+0x1c), zeros +0x20. If param_2 & 8: calls FUN_005410f0(param_1+0x24), zeros +0x28.

<!-- target: docs/20-math-utilities.md -->

## FUN_00542650 — Bit 5 Flag Set/Reset

If param_2 non-zero: sets bit 5 (0x20) at param_1+0x80. Else: clears bit 5.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054c1a0 — Bit 1+2 Flag Set

Sets bits 1 and 2 (0x6) at param_1+0x3c. OR operation.

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fca0 — Field Setter

Writes param_2 to param_1+100 (0x64). Simple setter.

<!-- target: docs/06-session-race-logic.md -->

## FUN_0055bb20 — 6-Field Struct Setter

Sets 6 consecutive fields at param_1+4 through +0x18 to param_2 through param_7. Returns 0.

<!-- target: docs/20-math-utilities.md -->

## FUN_00560fc0 — Bit 1 Flag Set

Sets bit 1 (0x2) at param_1+0x24. Simple OR.

<!-- target: docs/20-math-utilities.md -->

## FUN_00564b10 — Binary Search with Callback Comparator

Binary search on sorted array. param_2=base, param_4=element stride. Uses callback param_5 comparator. Sets *param_6=1 if exact match found. Returns insertion index (first >= key). Standard binary search.

<!-- target: docs/20-math-utilities.md -->

## FUN_00567f10 — 9-Pointer Array Cleanup

Iterates 9 pointers at param_1[0..8]. If non-null: calls FUN_00567cc0 to release. Zeroes each entry. Array cleanup.

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00587720 — Struct Field Getter (+0x410)

Returns *(param_1 + 0x410). Simple field accessor.

<!-- target: docs/08-file-formats.md -->

## FUN_0058bc56 — Two-Arg Call Wrapper

Calls FUN_0059508d(0x10000, 0x30000). Fixed-arg delegation.

<!-- target: docs/08-file-formats.md -->

## FUN_00596dfe — Three-Arg Call Wrapper

Calls FUN_00596e0f(param_1, 0, 4). Fixed-arg delegation.

<!-- target: docs/20-math-utilities.md -->

## FUN_005992d3 — Destructor Pattern (Scalar Deleting)

Calls FUN_00598e39(). If param_2 & 1: frees param_1 via FUN_00587bcf. Returns param_1.

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a535 — Delegation (atexit Register)

Calls FUN_00587b3e(FUN_0047aa60). Registers FUN_0047aa60 as cleanup callback.

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c552 — SEH Unwind (Free at EBP-0x10)

Frees *(unaff_EBP + -0x10) via FUN_00587bcf. SEH cleanup.

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cb68 — SEH Unwind (Call FUN_005833e0)

Calls FUN_005833e0(). MSVC unwind cleanup.

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d1c8 — SEH Unwind with Descriptor

Calls FUN_00599796(frame_local, &DAT_008d4330). Cleanup with type descriptor. Similar to Unwind_0059d1e8.

DONE — All 193 functions documented.

Source: unknown | Confidence: high (Engine/GlobalCall pattern)
Calls FUN_00555e50 with param_1 and global DAT_008b8f28. Simple dispatch wrapper.

**Key logic:**
- Calls FUN_00555e50(param_1, DAT_008b8f28)
- DAT_008b8f28: unknown global (likely subsystem state/context pointer)

**Globals:**
- `DAT_008b8f28` — unknown context/state pointer

**Calls:** FUN_00555e50 (unknown — not in decompiled_full_index)

**Used by system:** docs/01-engine-architecture.md — dispatch wrapper

**Moddability:** hardcoded

## FUN_004f7000 — Thunk to FUN_004f83b0

Source: unknown | Confidence: high
Trampoline — unconditional jmp to FUN_004f83b0. No local logic.

**Key logic:**
- Single call to FUN_004f83b0; address 0x004f7000 appears in a vtable or call stub
- Call target: FUN_004f83b0 (math_util — short computation, 2 lines)

**Calls:** FUN_004f83b0 (math_util — short computation, per triage index)

**Used by system:** docs/20-math-utilities.md — math utility trampoline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00534ae0 — AVIFileExit Stub

Source: AVIFileExit (MSVFW32.dll) | Confidence: high
Library stub — calls AVIFileExit from MS Video for Windows DLL. No local logic.

**Key logic:**
- Indirect jmp to AVIFileExit in MSVFW32.dll
- Standard import thunk for Video for Windows library

**Used by system:** docs/20-math-utilities.md — system library import

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055ef88 — 4x4 Matrix Multiply

Source: unknown | Confidence: high
Performs 4x4 float matrix multiplication: param_5 = param_3 × param_4 (row × column).

**Key logic:**
- Iterates 4 rows (i = 0..3), each computing 4 output elements
- Each output element = row of param_3 dot column of param_4
- Standard row-major 4x4 matrix multiply: out[i][j] = sum_k a[i][k] * b[k][j]
- Inputs param_3 (16 floats), param_4 (16 floats), output param_5 (16 floats)
- Uses x87 FPU for arithmetic

**Algorithm family:** 4x4 matrix multiplication

**Used by system:** docs/20-math-utilities.md — 3D math / transform pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00561a86 — Nested Loop Array Fill with Stride

Source: unknown | Confidence: high
Fills a buffer with a constant value using configurable stride pattern in a nested loop.

**Key logic:**
- Outer loop: runs param_2 times
- Inner body: writes param_7 to *puVar2, advances by param_8 elements
- If param_1 >= 0: also advances by param_5 after each write (skip pattern)
- param_1 controls which stride mode: negative = simple fill, non-negative = skip fill
- Base buffer at param_9 + param_6 * 4 (starts at offset within buffer)
- Used for 2D buffer operations (texture/rectangle fill with line stride)

**Algorithm family:** Array/strided buffer fill

**Used by system:** docs/20-math-utilities.md — data buffer manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00563df0 — Set Flag if Pointer Non-Null

Source: unknown | Confidence: high
Sets a flag at offset +0x74 (+0x1d * 4) if the first field of the struct is non-null.

**Key logic:**
- Checks *param_1 (first field, likely a pointer)
- If non-null: sets param_1[0x1d] = 1 (+0x74, flag)
- Returns 0 always

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | OwnerPtr | void* | Checked for null |
| +0x74 | ReadyFlag | int32 | Set to 1 if owner exists |

**Used by system:** docs/20-math-utilities.md — state/flag management

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00588a19 — Local Unwind Wrapper (SEH)

Source: unknown | Confidence: high
MSVC SEH local unwind wrapper — calls __local_unwind2 with exception registration data.

**Key logic:**
- Reads exception registration data from param_1 + 0x18 and param_1 + 0x1c
- Calls __local_unwind2(tryLevel, unwindHandler)
- Part of MSVC C++ exception handling implementation

**Calls:** __local_unwind2 (MSVC CRT SEH primitive)

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058d78e — Stream Byte Output with Buffer Management

Source: unknown | Confidence: high
Writes a byte to an output buffer, flushing and reloading when buffer runs out.

**Key logic:**
- Decrements buffer count at param_2[1]
- If count < 0: calls FUN_0058cf35 to flush/reload buffer
- Else: writes byte (param_1 & 0xff) to current buffer position *param_2, advances position
- If param_1 == -1 (0xffffffff after truncation): sets error flag *param_3 = -1
- Else: increments success counter *param_3

**Struct offsets (param_2, buffer descriptor):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | CurrentPtr | int32* | Current write position in buffer |
| +0x04 | RemainingCount | int32 | Bytes left before flush needed |

**Calls:** FUN_0058cf35 — Buffer flush/refill (72 lines, I/O stream management)

**Used by system:** docs/20-math-utilities.md — I/O stream utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005930e8 — PE Image Base Address Detection

Source: unknown | Confidence: high
Detects the PE image base address by reading DOS header and PE signature offset.

**Key logic:**
- Gets module handle for NULL (current process) via GetModuleHandleA
- Checks DOS signature at offset 0: must be 0x5A4D ("MZ")
- Reads PE signature offset from DOS header e_lfanew (at offset 0x3C)
- Extracts two bytes from PE header offset +2 and +3 (PE signature or subsystem data)
- Stores result in *param_1 as 2-byte value

**Calls:** GetModuleHandleA (Win32 API)

**Algorithm family:** PE image introspection

**Used by system:** docs/20-math-utilities.md — system/CRT utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cb93 — Unwind Handler (Free Field)

Source: unknown | Confidence: high
MSVC CRT unwind handler — frees a pointer from stack EBP-0x20.

**Key logic:**
- Reads pointer from stack EBP-0x20
- Calls FUN_00587bcf (free wrapper)

**Calls:** FUN_00587bcf — Free wrapper

**Used by system:** docs/20-math-utilities.md — MSVC CRT unwind/exception

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cd60 — Unwind Handler (Free Field)

Source: unknown | Confidence: high
MSVC CRT unwind handler — frees a pointer from stack EBP-0x14.

**Key logic:**
- Reads pointer from stack EBP-0x14
- Calls FUN_00587bcf (free wrapper)

**Calls:** FUN_00587bcf — Free wrapper

**Used by system:** docs/20-math-utilities.md — MSVC CRT unwind/exception

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00404460 — Multi-Phase Processing State Machine

Source: unknown | Confidence: medium
State machine with 3 phases (0, 1, 2) that processes iterations with different handlers per phase.

**Key logic:**
- Computes threshold: physicsConstant - (globalA + globalB) * globalC
- If above tolerance OR phase marker != -1:
  - Phase 0: if marker == -1, init float field, reset counter
  - Phase 0: calls FUN_004fb260(fVar2) in loop up to cap at +0x130
  - Phase 1: calls FUN_004faf60() in loop up to cap
  - Phase 2: calls FUN_004fb2e0() in loop up to cap
  - Transitions: 0→1→2→reset with marker = -1
- Uses iteration index at +0x174 and phase state at +0x16c

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x130 | Cap | int32 | Max iteration count per phase |
| +0x16c | Phase | int32 | 0, 1, 2 — state machine |
| +0x170 | FloatVal | float | Computed threshold value |
| +0x174 | IterIdx | int32 | Current iteration index |

**Globals:**
- `DAT_0059e43c` — physics constant
- `DAT_008afee8`, `DAT_008afeec` — additive globals
- `DAT_0059e450`, `DAT_0059e480` — multiplier/tolerance

**Calls:**
- FUN_004fb260 — Phase 0 handler
- FUN_004faf60 — Phase 1 handler
- FUN_004fb2e0 — Phase 2 handler

**Used by system:** docs/20-math-utilities.md — multi-phase processing / state machine

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404fe0 — One-Time Initialization with Atexit-Style Registration

Source: unknown | Confidence: high
One-time static initializer — checks a flag, calls sub-init, registers cleanup via FUN_00587b3e.

**Key logic:**
- If DAT_005ea4e0 bit 0 not set: sets it, calls FUN_00406ab0, registers &LAB_00405020 as cleanup
- Returns pointer to static buffer DAT_005ea440

**Globals:**
- `DAT_005ea4e0` — init flag (bit 0=initialized)
- `DAT_005ea440` — static buffer/handle

**Calls:**
- FUN_00406ab0 — sub-initialization
- FUN_00587b3e — ateexit/cleanup registration

**Used by system:** docs/20-math-utilities.md — static initialization

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00407c90 — Linked-List Node Removal with VTable Release

Source: unknown | Confidence: high
Searches a linked list for a node matching a key, removes it, calls vtable destructor on its data, and frees the node.

**Key logic:**
- Starts from list head at param_1+0x18
- Walks linked list (each node: [0]=key, [1]=next, [2]=flags)
- If key matches param_2: 
  - Removes node from linked list (updates prev/next pointers)
  - Updates tail pointer if needed (param_1+0x1c)
  - Decrements count at param_1+0x24
  - If data exists and destroy flag is set: calls vtable[0](1) destructor
  - Frees node via FUN_00587bcf
- If param_2 == 0: removes current node (the one at param_1+0x20)
- Advances current pointer (param_1+0x20) during search

**Struct offsets (param_1 — list controller):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18 | Head | int32* | Linked list head |
| +0x1c | Tail | int32* | Linked list tail |
| +0x20 | Current | int32* | Current iterator position |
| +0x24 | Count | int32 | Number of nodes |

**Node layout:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Key | int32 | Match key (compared against param_2) |
| +0x04 | Next | int32* | Next node pointer |
| +0x08 | Flags | byte[4] | Bit 0 = destroy data on removal |

**Calls:**
- Virtual method at vtable[0] — destructor with arg 1
- FUN_00587bcf — Free wrapper

**Used by system:** docs/20-math-utilities.md — linked list management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408450 — Safe Division with Zero Guard

Source: unknown | Confidence: high
Divides a physics constant by param_2, defaulting to 1.0 if denominator is near zero.

**Key logic:**
- Sets param_1+4 = 0 (clear flag)
- If param_2 ≈ 0 (compared against DAT_0059e440, zero threshold):
  - Sets param_1+8 = 1.0f (0x3f800000)
  - Calls FUN_004082b0 (zero-handler notification)
- Else: param_1+8 = DAT_0059e43c / param_2 (physics constant / param)

**Globals:**
- `DAT_0059e440` — Zero threshold constant (~0.0f)
- `DAT_0059e43c` — Physics constant (numerator)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | Flag | int32 | Set to 0 |
| +0x08 | Result | float | Division result or 1.0 fallback |

**Calls:** FUN_004082b0 — string/hash lookup (zero notification)

**Used by system:** docs/20-math-utilities.md — math utility with zero guard

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040b5a0 — VTable Switch with Virtual Call

Source: unknown | Confidence: high
Switches vtable, calls virtual method at index 3 on a child object, then switches vtable again.

**Key logic:**
- Sets *param_1 = PTR_LAB_0059e6ac (vtable A)
- If param_1[3] (child object) is non-null:
  - Calls child vtable[0](3) — virtual method with arg 3
- Sets *param_1 = PTR_LAB_0059e634 (vtable B)
- C++ object construction/destruction pattern — vtable switching for base/subobject

**Calls:** Virtual method on child object at param_1[3]

**Used by system:** docs/20-math-utilities.md — C++ object lifecycle

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040e6d0 — Struct Initializer with Sentinel Values

Source: unknown | Confidence: high
Initializes a 9-element (36 byte) struct with specific sentinel and default values.

**Key logic:**
- param_1[0] = -1 (0xffffffff) — sentinel
- param_1[1] = 0x7fffffff — INT_MAX
- param_1[2] as short = 0xffff — -1 short
- byte at byte offset +10 = 0
- param_1[3..6] = 0 — four zero fields
- param_1[7] = 9 — default count/size
- param_1[8] = 0 — last field zero

**Used by system:** docs/20-math-utilities.md — data structure initialization

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004145c0 — Struct Copy (32 bytes)

Source: unknown | Confidence: high
Copies 8 uint32 fields (32 bytes) from param_2 to param_1.

**Key logic:**
- Copies param_2[0..7] to param_1[0..7]
- Fields copied in order: 0, 2, 3, 4, 5, 6, 7, 1 (reordered access pattern)
- Simple struct assignment via 8 mov instructions

**Algorithm family:** Memory copy / struct assignment

**Used by system:** docs/20-math-utilities.md — data manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418ac0 — Array Slot Compaction with Gap Filling

Source: unknown | Confidence: medium
Iterates 20-element array (stride 0x20), finds gaps (slots with -1), and compacts by shifting data.

**Key logic:**
- Iterates 20 slots (i=0..0x13), each stride 0x20 = 8 int32
- Compares slot[3] against threshold DAT_008afea8, tracks min index
- Finds first gap (slot[0] == -1), stores as iVar5
- If gap found before last occupied slot: shifts data from later slots into the gap
- Calls FUN_004145c0 (struct copy) to move data, FUN_004144d0 for each shift

**Globals:**
- `DAT_008afea8` — threshold constant for slot comparison

**Calls:**
- FUN_004144d0 — (slot computation)
- FUN_004145c0 — struct copy (32 bytes)

**Used by system:** docs/20-math-utilities.md — array compaction / defragmentation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041f180 — Boolean Check Wrapper

Source: unknown | Confidence: high
Returns whether FUN_0041f040 returns exactly 1.

**Key logic:**
- Calls FUN_0041f040()
- Returns true if result == 1, else false

**Calls:** FUN_0041f040 — (lookup needed)

**Used by system:** docs/20-math-utilities.md — state query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421970 — Dual Function Call Chain

Source: unknown | Confidence: high
Calls two initialization/processing functions in sequence.

**Key logic:**
- Calls FUN_00421890(param_1)
- Calls FUN_00566650(param_1)

**Calls:**
- FUN_00421890 — math_util (short computation)
- FUN_00566650 — unknown (unidentified logic)

**Used by system:** docs/20-math-utilities.md — chained initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00423ad0 — 2D Vector Direction Projection (Dot/Length²)

Source: unknown | Confidence: high
Computes (param_1·param_2) / |param_1|² in 2D (XZ plane), with zero-length guard.

**Key logic:**
- Computes lenSq = param_1[0]² + param_1[2]² (XZ components, skipping Y)
- If lenSq > 0 (above DAT_0059e440 threshold):
  - Returns (param_1[0]*param_2[0] + param_1[2]*param_2[2]) / lenSq
- Else: returns 0.0 (DAT_0059e440)
- This is the scalar projection of param_2 onto the direction of param_1

**Globals:**
- `DAT_0059e440` — Zero threshold constant

**Algorithm family:** 2D vector math (XZ plane projection)

**Used by system:** docs/20-math-utilities.md — 2D vector math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004527e0 — Struct Init with Sub-Call

Source: unknown | Confidence: high
Initializes a struct, calls sub-function, zeros two fields.

**Key logic:**
- Sets *param_1 = 0
- Calls FUN_00452740(param_2, param_3)
- Sets param_1[7] = 0 and param_1[8] = 0

**Calls:** FUN_00452740 — (lookup needed)

**Used by system:** docs/20-math-utilities.md — initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00456280 — Triple Field Setter

Source: unknown | Confidence: high
Sets three consecutive fields in a struct.

**Key logic:**
- param_1[0] = param_2
- param_1[1] = param_3
- param_1[2] = param_4

**Used by system:** docs/20-math-utilities.md — property setter

**Moddability:** configurable — caller provides values

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b310 — Atexit-Style Cleanup Registration

Source: unknown | Confidence: high
Registers a cleanup function via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0045b320) — registers LAB_0045b320 as atexit/cleanup handler

**Calls:** FUN_00587b3e — atexit/cleanup registration

**Used by system:** docs/20-math-utilities.md — static initialization/cleanup

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0045cd50 — Struct Initializer (Flags + Fields)

Source: unknown | Confidence: high
Initializes a struct with flags and zero fields.

**Key logic:**
- param_1[0] = 0 (byte)
- param_1[1] = 1 (byte)
- *(uint32*)(param_1+4) = 0
- *(uint32*)(param_1+8) = 0
- *(uint32*)(param_1+0xc) = 0

**Used by system:** docs/20-math-utilities.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00460c60 — Array Init with Sentinel (-1) in Loop

Source: unknown | Confidence: high
Initializes 104 entries at param_1+0x3e18 to -1, calling sub-functions per iteration.

**Key logic:**
- Loops 104 times (0x68):
  - Sets current entry to -1 (0xffffffff)
  - Calls FUN_00461480 (sub-init)
  - Calls thunk_FUN_00500170 (init handler)
  - Advances to next entry

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3e18 | ArrayStart | Array of 104 int32 entries |

**Calls:**
- FUN_00461480 — per-entry initialization
- thunk_FUN_00500170 — per-entry init handler

**Used by system:** docs/20-math-utilities.md — array initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461fc0 — Vehicle State Query at Large Offset

Source: unknown | Confidence: medium
Reads a flag at a large vehicle struct offset and returns a state code.

**Key logic:**
- If *param_1 + 0x1b79c (large offset) is non-zero:
  - Calls FUN_00563e70()
  - Returns 1 if result == 1
  - Returns 2 if result == 2 or 3
- Returns 0 otherwise

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1b79c | LargeOffsetFlag | Large struct offset, possibly part of a big array/garage |

**Calls:** FUN_00563e70 — state query

**Used by system:** docs/20-math-utilities.md — vehicle state query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004630d0 — Unique ID / Config Validation

Source: unknown | Confidence: medium
Reads a session config and validates a magic/ID value (checks for 0x80).

**Key logic:**
- Opens session via FUN_0057a880()
- Calls FUN_0057a8e0() to check session readiness
- If ready (==0): calls FUN_0057a230(param_1, &local_4) to read config value
- If local_4 == 0x80 (magic byte read): returns 1 (valid)
- Otherwise returns 0
- Closes session via FUN_0057a8b0()

**Calls:**
- FUN_0057a880 — session open
- FUN_0057a8e0 — session check
- FUN_0057a230 — config/ID read
- FUN_0057a8b0 — session close

**Used by system:** docs/20-math-utilities.md — config/validation utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464930 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00464fd0.

**Key logic:**
- Calls FUN_00464fd0 with no arguments

**Calls:** FUN_00464fd0 — (lookup needed)

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00465160 — Wheel Speed Conversion with Zero Guard

Source: unknown | Confidence: high
Converts float wheel speeds to int32 stored values using fixed-point scaling.

**Key logic:**
- If param_2 > DAT_0059e440 (zero threshold):
  - *param_1 + 0x50 = (param_2 * 1000) >> 3 (with rounding adjustment)
- If param_3 > DAT_0059e440:
  - *param_1 + 0x54 = (param_3 * 1000) >> 3 (with rounding adjustment)
- Scaling: multiply by 1000 then divide by 8 (fixed-point representation)

**Struct offsets (param_1 indirect):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x50 | WheelSpeedFront | int32 — scaled front wheel speed |
| +0x54 | WheelSpeedRear | int32 — scaled rear wheel speed |

**Globals:** DAT_0059e440 — zero threshold

**Used by system:** docs/20-math-utilities.md — speed/velocity conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466a30 — Constructor with VTable and Float Init

Source: unknown | Confidence: high
C++ object constructor — sets vtable, initializes float fields.

**Key logic:**
- Calls FUN_004668e0(param_3, param_4) — parent/base init
- Sets vtable to PTR_FUN_0059f380
- Sets field at +0x104 (0x41*4) = 0.5f (0x3f000000)
- Sets byte at +0x100 = 0
- Sets field at +0x108 = param_2

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a4e0 — Constructor with VTable and Sub-Init

Source: unknown | Confidence: high
C++ object constructor — calls sub-init, zeros fields, sets vtable.

**Key logic:**
- Calls FUN_004893c0() — sub-init
- Sets field at +0x174 = 0
- Sets field at +0x178 = -1
- Sets vtable to PTR_FUN_0059f938
- Calls FUN_0048a3b0(0) — init with arg 0

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046d360 — Conditional Virtual Dispatch with State Check

Source: unknown | Confidence: high
Checks a state flag, conditionally calls virtual method with arg 1, then always calls with arg 0.

**Key logic:**
- Calls FUN_004d24a0() — state check
- If false (0): calls vtable+0x38(1) — enable/set
- Always calls vtable+0x38(0) — disable/clear
- Returns 0

**Calls:** FUN_004d24a0 — state query

**Used by system:** docs/20-math-utilities.md — state machine / UI dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046f610 — Constructor with VTable and Param Store

Source: unknown | Confidence: high
C++ object constructor — calls sub-init, stores param, sets vtable.

**Key logic:**
- Calls FUN_00487220(0, 0) — sub-init
- Sets field at +0xe4 (0x39*4) = param_2
- Sets vtable to PTR_FUN_0059ff80

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004713c0 — Destructor with Sub-Call and Conditional Free

Source: unknown | Confidence: high
C++ object destructor — calls sub-cleanup, optionally frees self.

**Key logic:**
- Calls FUN_0048c0d0() — sub-cleanup
- If param_2 bit 0 set: calls FUN_00587bcf(param_1) — free self
- Returns param_1

**Calls:** FUN_0048c0d0, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — C++ object destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00472d00 — Constructor with VTable and Field Init

Source: unknown | Confidence: high
C++ object constructor — calls sub-init, sets vtable, zeros field.

**Key logic:**
- Calls FUN_0048c070(2) — sub-init with arg
- Sets vtable to PTR_FUN_005a2400
- Zeros field at +0x31c (199*4)

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00474ba0 — Constructor with Multiple Field Inits and Global Ref

Source: unknown | Confidence: medium
C++ constructor — sets vtable, stores global reference, initializes multiple fields.

**Key logic:**
- Calls FUN_00466d60(1) — parent/base init
- Sets vtable to PTR_FUN_005a3fc0
- Stores DAT_007d0038 reference (game state global) at field +0x31c
- Sets fields around +0x328 to 0, 1, 1, 1
- Calls FUN_00486f30 twice with different constants
- Sets field at +0x334 = 0x1b6 (438)

**Globals:** DAT_007d0038 — game state reference

**Calls:** FUN_00466d60, FUN_00486f30(x2)

**Used by system:** docs/20-math-utilities.md — game system object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004761e0 — Multi-Phase Destructor with VTable Switching

Source: unknown | Confidence: high
C++ destructor with three-phase vtable switching, freeing pointers at each phase.

**Key logic:**
- Phase 1: vtable=PTR_FUN_005a4478, frees field at +0x40 if non-null
- Phase 2: vtable=PTR_FUN_005a4450, frees field at +0x30 if non-null
- Phase 3: vtable=PTR_FUN_005a443c, frees field at +4 if non-null
- If bit 0 of param_2: frees self

**Calls:** FUN_00587bcf (free) × 3-4

**Used by system:** docs/20-math-utilities.md — C++ object destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004781a0 — Virtual Dispatch with Conditional Arg Based on State

Source: unknown | Confidence: medium
Calls a virtual method on a global object with argument depending on state.

**Key logic:**
- Calls FUN_00461cd0() — state query
- If result == 3: calls vtable+0x1c(0x18) on DAT_007cd8c0 object
- Else: calls vtable+0x1c(0x11) on DAT_007cd8c0 object
- If result non-null: stores at param_1 + 0xe0

**Globals:** DAT_007cd8c0 — global manager/allocator object

**Calls:** FUN_00461cd0 — state query

**Used by system:** docs/20-math-utilities.md — resource/object allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479790 — Constructor with Range Init and VTable

Source: unknown | Confidence: high
C++ constructor — calls FUN_00466980(-1.0f, 1.0f), sets vtable.

**Key logic:**
- Calls FUN_00466980(0xbf800000=-1.0f, 0x3f800000=1.0f) — range init
- Sets vtable to PTR_FUN_005a4f28

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479cd0 — Constructor with Range Init (20, 100) and Flag

Source: unknown | Confidence: high
C++ constructor — calls FUN_0048d3a0(20.0f, 100.0f), sets vtable, sets flag.

**Key logic:**
- Calls FUN_0048d3a0(0x41a00000=20.0f, 0x42c80000=100.0f) — range init
- Sets vtable to PTR_FUN_005a5cd0
- Sets byte at +0xf0 = 1

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a800 — Constructor with Range Init (0.05, 1.0)

Source: unknown | Confidence: high
C++ constructor — calls FUN_004668e0(0.05f, 1.0f), sets vtable.

**Key logic:**
- Calls FUN_004668e0(0x3d4ccccd≈0.05f, 0x3f800000=1.0f) — range init
- Sets vtable to PTR_FUN_005a6570

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047c7f0 — Destructor with Sub-Call and Conditional Free

Source: unknown | Confidence: high
C++ destructor — calls FUN_0048d3e0(), optionally frees self.

**Key logic:**
- Calls FUN_0048d3e0() — sub-cleanup
- If param_2 bit 0 set: calls FUN_00587bcf(param_1) — free self
- Returns param_1

**Calls:** FUN_0048d3e0, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — C++ object destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485510 — Constructor with VTable and Sub-Init

Source: unknown | Confidence: high
C++ constructor — sets vtable, calls sub-init, optionally frees self.

**Key logic:**
- Sets vtable to PTR_FUN_005ab4a0
- Calls FUN_00487250() — sub-init
- If param_2 bit 0 set: calls FUN_00587bcf(param_1) — free self
- Returns param_1

**Calls:** FUN_00487250, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599689 — Catch Block with Buffer Allocation

Source: unknown | Confidence: high
MSVC exception catch block that allocates a buffer for exception data.

**Key logic:**
- Reads value from stack offset +8 (exception descriptor)
- Computes size = value + 2, clamps to 0 if negative
- Allocates buffer via operator_new
- Stores allocated pointer back to stack
- Returns cleanup handler address (DAT_005996a8)

**Calls:** operator_new (MSVC CRT global new)

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599cb7 — Locale Object Constructor with VTable Setup

Source: unknown | Confidence: high
MSVC CRT locale initialization — constructs a locale facet object with vtable switching.

**Key logic:**
- Calls FUN_0058a5d8 (SEH prolog)
- Sets vtable to PTR_FUN_005b9ca0 (phase 1)
- Calls FUN_0059a4c9 (sub-init)
- Sets vtable to PTR_FUN_005b9c68 (phase 2)
- Calls FUN_0059a473(uVar1, 0) with stack arg
- Sets ExceptionList (SEH epilog)
- Returns ECX (constructed object pointer)

**Calls:**
- FUN_0058a5d8 — SEH prolog
- FUN_00598c1c — (locale sub-init)
- FUN_0059a4c9 — (init method)
- FUN_0059a473 — (ctor with copy)

**Used by system:** docs/20-math-utilities.md — MSVC CRT locale support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059afc2 — Exception Object Destructor with SEH

Source: unknown | Confidence: high
MSVC exception destructor — calls exception::~exception() with SEH protection.

**Key logic:**
- Calls FUN_0058a5d8 (SEH prolog)
- Sets vtable to PTR_FUN_005b9d7c (destructor phase vtable)
- Calls FUN_005993af(1) — refcount decrement
- Calls exception::~exception(this) — chained destructor
- SEH epilog via FS[0]

**Calls:**
- FUN_0058a5d8 — SEH prolog
- FUN_005993af — refcount decrement
- exception::~exception — MSVC CRT exception destructor

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c428 — Unwind Handler (Free Buffer)

Source: unknown | Confidence: high
MSVC CRT unwind handler — calls free on a buffer from stack offset -0x10.

**Key logic:**
- Reads pointer from stack EBP-0x10
- Calls FUN_00587bcf (free wrapper)

**Calls:** FUN_00587bcf — Free wrapper (memory management)

**Used by system:** docs/20-math-utilities.md — MSVC CRT unwind/exception

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c596 — Unwind Handler (SEH)

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00506ccc.

**Key logic:**
- Calls FUN_00506ccc with no arguments

**Calls:** FUN_00506ccc — (lookup needed)

**Used by system:** docs/20-math-utilities.md — MSVC CRT unwind/exception

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00485df0 — Global Manager Shutdown Sequence

Source: unknown | Confidence: high
Shutdown/cleanup function for a global manager object.

**Key logic:**
- Calls FUN_004963d0() — sub-cleanup
- If DAT_007cd8c0 (global manager) is non-null: calls its destructor vtable[0](1)
- Nulls DAT_007cd8c0
- Calls FUN_004b0770(1)

**Globals:** DAT_007cd8c0 — global manager object pointer

**Calls:** FUN_004963d0, FUN_004b0770

**Used by system:** docs/20-math-utilities.md — manager lifecycle

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486710 — Byte Field Getter at +100

Source: unknown | Confidence: high
Returns a byte at offset +100.

**Key logic:**
- return *(byte*)(param_1 + 100)

**Used by system:** docs/20-math-utilities.md — field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487690 — Destructor with Sub-Call + Conditional Free

Source: unknown | Confidence: high
Calls sub-cleanup, optionally frees self.

**Key logic:**
- FUN_004876b0(); if param_2&1: free(self); return self

**Used by system:** docs/20-math-utilities.md — C++ destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00488900 — Delta-Based Update

Source: unknown | Confidence: medium
Computes time delta, triggers update if changed.

**Key logic:**
- FUN_00498880 get time; 3 virtual calls; if flag + delta changed: update stored, FUN_00488970, vtable+0x2c(1)

**Used by system:** docs/20-math-utilities.md — timed update logic

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489e90 — Float-to-Int Conversion

Source: unknown | Confidence: high
Gated float-to-int conversion.

**Key logic:**
- +0x150=0; if +0x160: +0x150 = __ftol()

**Used by system:** docs/20-math-utilities.md — type conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048c9a0 — Simple VTable + Null Init

Source: unknown | Confidence: high
2-field init with vtable.

**Key logic:**
- *p1 = PTR_FUN_005ac044; p1[1] = 0

**Used by system:** docs/20-math-utilities.md — C++ construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d660 — Constructor Dual Sub-Init

Source: unknown | Confidence: high
Two sub-init calls with vtable.

**Key logic:**
- FUN_00488b00(1,-1); vtable=PTR_FUN_005ac280; FUN_00488bc0(2)

**Used by system:** docs/20-math-utilities.md — C++ construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048eaa0 — Large Constructor (30+ Fields)

Source: unknown | Confidence: high
Zeros 30+ fields, vtable, config values.

**Key logic:**
- FUN_00485e30(); zero +0xf0..+0x16c; zero bytes +0x17d-f; vtable=PTR_LAB_005a4550; +0x100=1,+0x104=4,+0x108=0.5f,+0x170=-1,+0x178=10,byte+0x17c=1

**Used by system:** docs/20-math-utilities.md — C++ construction

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_0048feb0 — VTable + Sub-Init

Source: unknown | Confidence: high
Sets vtable, calls sub-init.

**Key logic:**
- *p1 = PTR_FUN_005ac6b0; FUN_00485eb0()

**Used by system:** docs/20-math-utilities.md — C++ construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004910d0 — List Iterator + Full Destruction

Source: unknown | Confidence: high
Iterates linked list, processes nodes, then destroys all.

**Key logic:**
- Walk via p1[2] iterator: FUN_00490aa0() per node; then free all nodes with data cleanup; zero controls; return 1

**Used by system:** docs/20-math-utilities.md — linked list

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491bd0 — Sub-List Walk + Destruction

Source: unknown | Confidence: high
Processes a sub-list then destroys all nodes.

**Key logic:**
- Walk *p1+0xc list; FUN_00490aa0(); free all data+node; zero parent fields

**Used by system:** docs/20-math-utilities.md — linked list

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00494c20 — Float Vector with Conditional Transform

Source: unknown | Confidence: medium
Int→float convert, conditional render call.

**Key logic:**
- (float)p1,p2,p3,p4; if FUN_00494c80(): FUN_00553a20(floats, p5)

**Used by system:** docs/20-math-utilities.md — transform

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495890 — Hash Table ID Resolution

Source: unknown | Confidence: medium
ID lookup via hash table.

**Key logic:**
- FUN_0058815f(table, key, id); FUN_00494fb0(&id, table, 1); return id or 0

**Used by system:** docs/20-math-utilities.md — ID resolution

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497240 — Byte Getter +0x25

Source: unknown | Confidence: high
Returns byte at +0x25.

**Key logic:**
- return *(byte*)(param_1 + 0x25)

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004980c0 — Conditional Setter +0x30

Source: unknown | Confidence: high
Sets field if non-null.

**Key logic:**
- if p2: p1+0x30 = p2

**Used by system:** docs/20-math-utilities.md — setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498f40 — Setter + Virtual Call

Source: unknown | Confidence: high
Sets field if non-null, then virtual call.

**Key logic:**
- if p2: p1[0x14]=p2; vtable+0x2c()

**Used by system:** docs/20-math-utilities.md — setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004995e0 — Destructor with Data Free

Source: unknown | Confidence: high
Frees data if flag set, optionally frees self.

**Key logic:**
- if [2] flag and *p1: FUN_00499ae0()+free(data); if p2&1: free(self)

**Used by system:** docs/20-math-utilities.md — C++ destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499bb0 — Struct Equality (7 Fields)

Source: unknown | Confidence: high
Compares 7 fields across two structs.

**Key logic:**
- Returns 1 if [0,1,2,3,7,8] all equal, else 0

**Used by system:** docs/20-math-utilities.md — comparison

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499f00 — Two-Channel 16-bit Reader

Source: unknown | Confidence: medium
Reads two pairs of int16 values from data source.

**Key logic:**
- If count>2: ch0→*p1,*p2; ch1→*p3,*p4

**Used by system:** docs/20-math-utilities.md — data parsing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a930 — Constructor with -1 Sentinels

Source: unknown | Confidence: high
Zeros fields, sets many to -1.

**Key logic:**
- FUN_004912f0(); zero [1..4],[0xd..0xe]; vtable=PTR_LAB_005acab0; +0x14/18/1c/20=-1

**Used by system:** docs/20-math-utilities.md — C++ construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049b1c0 — Static Array Cleanup

Source: unknown | Confidence: high
Frees entries in static pointer array.

**Key logic:**
- Iterate DAT_007ce23c..007ce24c; if non-null: FUN_004dcd10()×2 + free + null

**Used by system:** docs/20-math-utilities.md — cleanup

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004a0010 — Atexit Registration

Source: unknown | Confidence: high
Registers cleanup handler.

**Key logic:**
- FUN_00587b3e(&DAT_004a0020)

**Used by system:** docs/20-math-utilities.md — init/cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1ac0 — Aligned String Concat

Source: unknown | Confidence: high
Formats and appends string with 4-byte copy.

**Key logic:**
- FUN_0058815f format; measure lengths; 4-byte aligned copy

**Used by system:** docs/20-math-utilities.md — string

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a2a40 — Quote-Stripping Copy

Source: unknown | Confidence: high
Copies string stripping '"' chars, then trims.

**Key logic:**
- Skip quotes during copy; null-term; FUN_00589901() trim

**Used by system:** docs/20-math-utilities.md — string

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a55e0 — Conditional Dispatch

Source: unknown | Confidence: high
Calls function with one of two args based on flag.

**Key logic:**
- if +0x2c: FUN_004a5600(p1+0x10); else: FUN_004a5600(p1+0xc)

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b0720 — 5-Step Init

Source: unknown | Confidence: medium
Five-step initialization sequence.

**Key logic:**
- FUN_004b02b0(buf,256); FUN_004c2300(); FUN_004b0e30(); FUN_004c22a0(buf); FUN_004b0c00()

**Used by system:** docs/20-math-utilities.md — init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1f50 — Short Field Setter

Source: unknown | Confidence: high
Stores short values with conditional override.

**Key logic:**
- FUN_00566650(p2); set +0x16/18/1a; if p6: FUN_00566650(p6); if p7: +0x14=p3; FUN_004a1b70()

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b29b0 — Bitfield Insert (Bits 12-16)

Source: unknown | Confidence: medium
Inserts rounded scaled float into 5-bit field.

**Key logic:**
- ROUND(p2 * DAT_005accd0) & 0xff << 12 → XOR into +0x2c masked 0x1f000

**Used by system:** docs/20-math-utilities.md — bitfield

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004B32A0 � Packed ARGB Color Extraction and Conversion

Source: unknown | Confidence: high
Extracts R/G/B channels from packed 32-bit color format using shifts and masks, converts via scaling factor, transforms through coordinate/rotation functions.

**Key logic:**
- Zeroes 3 floats (local_18, local_14, local_10) = vector accumulator
- FUN_004b2480(&local_18) � angle validation (docs/20)
- FUN_004b25d0(&local_18) � float-to-fixed conversion (docs/20)
- FUN_004b2750(&local_18) � float-to-short clamped conversion (docs/20)
- R: local_18 = (float)(*param_1 << 8) * _DAT_0059e780 � red channel, shift left 8, scale
- G: local_14 = (float)(((*(ushort*)((int)param_1+2) & 0xff00) + param_1[1] * 0x10000)) * _DAT_0059e780 � green channel, complex mask+shift
- B: local_10 = (float)((param_1[1] >> 8 & 0xffff00) + *(byte*)(param_1+2) * 0x1000000) * _DAT_0059e780 � blue channel
- FUN_004b2310(&local_18, &local_c) � float-to-short normalized conversion (docs/20)
- FUN_004b2bf0() � ternary select by bitfield (docs/20)
- FUN_004b29b0(result) � bitfield insert bits 12-16 (docs/20)
- FUN_004b2c50() � bitfield extract and scale (docs/20)
- FUN_004b2930(result) � float-to-bitfield pack (docs/20)
- Sets *(undefined4*)(param_2 + 4) = param_3 � store user value

**Globals:**
- _DAT_0059e780 � color/channel scaling factor (docs/18)

**Calls:** FUN_004b2480 (angle validation, docs/20), FUN_004b25d0 (float-to-fixed, docs/20), FUN_004b2750 (float-to-short clamped, docs/20), FUN_004b2310 (float-to-short normalized, docs/20), FUN_004b2bf0 (ternary select, docs/20), FUN_004b29b0 (bitfield insert, docs/20), FUN_004b2c50 (bitfield extract+scale, docs/20), FUN_004b2930 (float-to-bitfield pack, docs/20)

**Moddability:** configurable (_DAT_0059e780 scaling factor)

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b46f0 — Quadruple List Cleanup

Source: unknown | Confidence: high
Frees 4 linked list slots.

**Key logic:**
- 4 slots at p1+0xb0 stride -16: walk each, free data+node, zero controls

**Used by system:** docs/20-math-utilities.md — list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b8bd0 — Key Priority Chain

Source: unknown | Confidence: high
Returns first pressed key mapped to 0,1,2,3.

**Key logic:**
- FUN_0044f4a0(0xcb=203)→0; (200)→1; (0xd0=208)→3; (0xcd=205)→2

**Used by system:** docs/20-math-utilities.md — input

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9fa0 — Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00566650().

**Key logic:**
- FUN_00566650()

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004baac0 — Conditional Array Alloc

Source: unknown | Confidence: high
Allocates 32 or 64 elements.

**Key logic:**
- alloc((p2?0x40:0x20)*0xc); init each via FUN_004b4450

**Used by system:** docs/20-math-utilities.md — allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb650 — List Full Destruction

Source: unknown | Confidence: high
Destroys list freeing data[0]+data+node.

**Key logic:**
- Walk: if flag+data: free(data[0])+free(data); free(node); zero controls

**Used by system:** docs/20-math-utilities.md — list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bd860 — Dynamic Array Push

Source: unknown | Confidence: high
Auto-growing int32 array push.

**Key logic:**
- If count==cap: grow+8, alloc new, copy, free old; append; count++

**Used by system:** docs/20-math-utilities.md — dynamic array

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c03a0 — Alternating Init (0/-1)

Source: unknown | Confidence: high
6-field init with 0, -1 pattern.

**Key logic:**
- [0]=0, [1]=-1, [2]=0, [3]=-1, [4]=0, [5]=0

**Used by system:** docs/20-math-utilities.md — init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2be0 — Accumulator

Source: unknown | Confidence: high
Adds to field +0x24.

**Key logic:**
- p1+0x24 += p2

**Used by system:** docs/20-math-utilities.md — accumulator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c40b0 — Conditional Dispatch

Source: unknown | Confidence: high
If non-null, chain two calls.

**Key logic:**
- if p1: FUN_004c3f80(p1); return FUN_004c4080(); else 0

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7dd0 — Field Zero +4

Source: unknown | Confidence: high
Sets +4 to 0.

**Key logic:**
- p1+4 = 0

**Used by system:** docs/20-math-utilities.md — reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8a10 — Global Virtual Dispatch Guarded

Source: unknown | Confidence: high
If global DAT_008ac4cc non-null, calls virtual method at vtable+0xc.

**Key logic:**
- If DAT_008ac4cc: vtable+0xc() on it

**Globals:** DAT_008ac4cc

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9820 — Virtual State Check via Index

Source: unknown | Confidence: high
Resolves pointer from param_1 indexed array, calls virtual method, returns status.

**Key logic:**
- Reads ptr from param_1+0x20 + param_1[0x1c]*4 (indexed slot)
- If non-null: calls vtable+0x1c() on it; returns 1 if result != 2; else 0

**Used by system:** docs/20-math-utilities.md — state query

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004d4a20 — Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004d4a50().

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7ad0 — Slot Array Init (3 slots)

Source: unknown | Confidence: high
Inits 3 slots with -1 sentinels and zeros.

**Key logic:**
- Loop 3×: sets +0x18[3]=0, [0]=0, [-6]=-1, [-3]=-1

**Used by system:** docs/20-math-utilities.md — array init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d82a0 — Array Iteration Conditional Call (25 slots)

Source: unknown | Confidence: high
Iterates 25 slots (0x19), calls FUN_004d7e30 if pointer non-null.

**Key logic:**
- Loop i=0..24: if param_1+0x10[i*4] != 0: FUN_004d7e30()

**Used by system:** docs/20-math-utilities.md — iteration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dad30 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004bc270(param_1+0x24).

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc2e0 — Atexit Registration

Source: unknown | Confidence: high
Registers cleanup via FUN_00587b3e.

**Key logic:**
- FUN_00587b3e(&LAB_004dc2f0)

**Used by system:** docs/20-math-utilities.md — init/cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcf50 — Triple Field Getter

Source: unknown | Confidence: high
Returns up to 3 fields from param_1+8,+0xc,+0x10.

**Key logic:**
- If param_2: *param_2 = param_1+8
- If param_3: *param_3 = param_1+0xc
- If param_4: *param_4 = param_1+0x10

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dedb0 — Sorted Array Insert with LRU Eviction

Source: unknown | Confidence: high
Inserts 9-float element into array sorted by priority, evicts lowest-priority when full (20 slots).

**Key logic:**
- Scans existing elements for match (all 9 floats); if found: calls FUN_004df110() and returns
- If full (20): finds lowest-priority element by scanning slot[1] priority, removes it by shift
- Shifts elements right to maintain sort order by slot[1]
- Inserts new element at correct position
- Calls FUN_004df110() per insert

**Globals:** DAT_005ad140, DAT_0059e670 — priority constants

**Struct:** param_1: +0x18=count, +0x1c..+0x24=per-slot (stride 0x24=36=9×4), 9 floats per slot

**Calls:** FUN_004df110

**Used by system:** docs/20-math-utilities.md — sorted array / LRU cache

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f1a60 — Loop with Conditional Sub-Call

Source: unknown | Confidence: high
Loops 4× calling FUN_004f18c0, then optionally calls FUN_004e8010.

**Key logic:**
- i=0..3: FUN_004f18c0(i, param_1, 0)
- If param_2: FUN_004e8010(0)

**Used by system:** docs/20-math-utilities.md — loop dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8280 — Color/Palette Lookup by Index

Source: unknown | Confidence: high
Returns RGB triple from palette based on case index.

**Key logic:**
- Default: DAT_005d67c8/cc/d0 (RGB)
- Cases 0-4, 0x2b: DAT_005d67b0/b4/b8 (palette A)
- Cases 0xc-0x14, 0x26-0x29, 0x2c: DAT_005d67bc/c0/c4 (palette B)

**Used by system:** docs/20-math-utilities.md — color lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9140 — Call Wrapper (Returns Input)

Source: unknown | Confidence: high
Calls FUN_00568ba0(); returns param_1 unchanged.

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->

## FUN_004ff0e0 — State Code by Float Comparison

Source: unknown | Confidence: medium
Returns state code 2, 3, 4, or 5 based on comparison of two floats against constants.

**Key logic:**
- If +0x20 == 0.0: return 2
- If +0x24 == 0.0: return 3
- If DAT_0059e4e8 <= +0x24: return 5 else 4

**Used by system:** docs/20-math-utilities.md — state classification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00500f3c — 7-Field Initializer

Source: unknown | Confidence: high
Zeros 7 selected fields of a struct.

**Key logic:**
- [0]=0, [1]=0, [2]=0, [0xe]=0, [0xf]=0, [0x13]=0, [0x14]=0

**Used by system:** docs/20-math-utilities.md — init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005038ef — Vehicle Data Forwarding Call

Source: unknown | Confidence: medium
Reads several fields from two vehicle structs and forwards to PTR_FUN_005d76c4.

**Key logic:**
- Reads from param_1[0]+0x18, +0x1050, +0x1058, +0x105c
- Reads from param_1[1]+0x18, +0x1050
- Calls PTR_FUN_005d76c4 with those values

**Used by system:** docs/20-math-utilities.md — data forwarding

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00506fd9 — Complex Destructor with Loop

Source: unknown | Confidence: medium
SEH-protected destructor that frees array data in a loop.

**Key logic:**
- SEH prolog; vtable=PTR_FUN_005adb90
- If [0x42f] and [0x430]: nested loop freeing each element (stride 8)
- Frees [0x42e] and [0x430] buffers
- SEH epilog via FUN_00506ccc

**Calls:** FUN_00587bcf × N

**Used by system:** docs/20-math-utilities.md — complex destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b20c — Constructor with Init

Source: unknown | Confidence: high
Calls FUN_00507496(p2,8,1); sets vtable.

**Used by system:** docs/20-math-utilities.md — C++ construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b7e3 — Constructor with Init

Source: unknown | Confidence: high
Calls FUN_0050afe2(p2); sets vtable.

**Used by system:** docs/20-math-utilities.md — C++ construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c5b0 — Dispatch Call Pair

Source: unknown | Confidence: low
Calls FUN_0050fea7(1); then indirect call via PTR_FUN_005d77f0.

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d84a — Dispatch Call Pair

Source: unknown | Confidence: low
Calls FUN_0050fea7(1); then indirect call via DAT_005d7860.

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e760 — 4-Component Vector × 4×3 Matrix Transform

Source: unknown | Confidence: high
Transforms a 4-component vector by a 4×3 matrix (affine transform).

**Key logic:**
- Computes out[0..3] = in.x * row[0] + in.y * row[4] + in.z * row[8] + row[12] (per component)
- Standard 4×3 matrix * 4-vector homogeneous transform

**Algorithm family:** 3D affine transform

**Used by system:** docs/20-math-utilities.md — 3D math

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00512114 — Masked Read at +8

Source: unknown | Confidence: high
Returns value at param_2+8 masked by param_3, if both ptrs non-null.

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513c38 — Bounded Memcmp Against Reference

Source: unknown | Confidence: medium
Compares memory against reference DAT_005af564, up to 8 bytes, with length and offset bounds.

**Used by system:** docs/20-math-utilities.md — comparison

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00515d26 — Object Buffer Copy with Validation

Source: unknown | Confidence: medium
Copies data from object slots to buffer with state validation.

**Key logic:**
- Iterates objects; checks state at +0x4c, type at +0x10
- If type 0-3 and flag enabled: alloc buffer via virtual, copies 0x20 dwords + 1 short
- Stores result at +0x4c

**Used by system:** docs/20-math-utilities.md — object data copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00516c0c — Buffer Init with Identity Pattern

Source: unknown | Confidence: medium
Allocates and fills a buffer with trivial font/character lookup patterns (0..255 and mask data).

**Key logic:**
- Allocates buffer; zeros first 0x40 dwords; fills next 0x100 bytes with 0,1,2,...,255
- Fills next 0x60 dwords with -1; next 0x60 dwords with 0
- Copies 0x20 dwords from [0x40] to [0x140]

**Used by system:** docs/20-math-utilities.md — buffer init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00519351 — Free Wrapper

Source: unknown | Confidence: high
Calls FUN_0058aa6f(param_2) to free memory.

**Used by system:** docs/20-math-utilities.md — memory

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051df18 — Symmetric Array Init (Mirror Pattern)

Source: unknown | Consensus: medium
Initializes array with mirror values: [0]=0,[-1]=0;[1]=1,[-2]=-1;[2]=2,[-3]=-2... up to 256 entries.

**Used by system:** docs/20-math-utilities.md — array init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052466c — MMX Packed Floating-Point SIMD Math

Source: unknown | Consensus: low
~870 lines of MMX/3DNow! packed floating-point operations. Complex SIMD computation using 64-bit MMX registers.

**Algorithm family:** SIMD packed floating-point

**Used by system:** docs/20-math-utilities.md — SIMD math library

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052a0a1 — Huffman Coding Frequency Table

Source: unknown | Consensus: medium
Builds Huffman frequency table (16 symbols) and validates code length constraints.

**Key logic:**
- Counts symbol frequencies in input buffer (16 possible symbols)
- Computes min/max used symbols
- Validates Huffman code length constraints (Kraft inequality)
- Returns 0 on success, -3 on overflow

**Algorithm family:** Huffman compression

**Used by system:** docs/20-math-utilities.md — compression

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e550 — Bounds-Checked Byte Setter

Source: unknown | Consensus: high
Sets byte at index if 0..8 (9-element array).

**Key logic:**
- If -1 < param_2 < 9: param_1[param_2] = param_3

**Used by system:** docs/20-math-utilities.md — array accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005355a0 — Stream/File Type Check with Dispatch

Source: unknown | Consensus: medium
Checks file type char at +0x5c; if 'w' (wave), checks sub-function result.

**Key logic:**
- If param_1==0: return -2
- If +0x5c=='w': FUN_005352d0() check; if non-zero: return FUN_00534ee0()
- Falls through to FUN_00534ee0()

**Used by system:** docs/20-math-utilities.md — file/stream dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00539f60 — Indirect Call via VTable+0x24

Source: unknown | Consensus: low
Calls virtual method at vtable+0x24 on param_2.

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b490 — Identity Function

Source: unknown | Consensus: high
Returns param_1 unchanged.

**Used by system:** docs/20-math-utilities.md — identity

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c6a0 — Two-Field Initializer

Source: unknown | Consensus: high
Sets *param_1=0 and byte at param_1+4=0.

**Used by system:** docs/20-math-utilities.md — init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d410 — Global Flag Setter

Source: unknown | Consensus: high
Sets DAT_008b8e2c = (param_1 != 0).

**Globals:** DAT_008b8e2c

**Used by system:** docs/20-math-utilities.md — global flag

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00540eb0 — Object Reset with Virtual Release

Source: unknown | Consensus: medium
Resets an object by draining its pending operations and releasing via virtual call.

**Key logic:**
- If param_2 and +0x20: loop while +0x14 > 0 calling FUN_00540f90(p2)
- Sets +0x14=0; calls vtable+8() on +0x20 to release
- Stores result in *param_1; nulls +0x20

**Used by system:** docs/20-math-utilities.md — object reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00542680 — Conditional Float Setter

Source: unknown | Consensus: high
Sets param_1+0x88 = param_2 if param_2 > DAT_0059e430.

**Globals:** DAT_0059e430 — threshold

**Used by system:** docs/20-math-utilities.md — setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005461b0 — Mutex/Semaphore Cleanup

Source: unknown | Consensus: medium
Cleans up a mutex/semaphore, frees memory, resets global.

**Key logic:**
- If FUN_00543bf0() ≠ 0: return -1
- FUN_0053c630(p1); if p1: FUN_005437e0() + free(p1)
- Sets DAT_008b8f28 = 0; return 0

**Used by system:** docs/20-math-utilities.md — cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005472d0 — Float-to-Int Switch (Cases 1-4)

Source: unknown | Consensus: medium
Converts float to int via __ftol in a switch with 4 identical cases (1-4).

**Key logic:**
- Switch param_1: cases 1,2,3,4: if param_2: *param_2 = __ftol()

**Used by system:** docs/20-math-utilities.md — type conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00548a30 — Random Password/Key Generator

Source: unknown | Consensus: high
Generates 4-char alphanumeric string from rand(), seeded with param_1 % 0xa55a.

**Key logic:**
- srand(param_1 % 0xa55a)
- Generates 4 chars: each = (rand() & 0xff) % 0x4e + 0x30, clamped to 0x30-0x7e

**Used by system:** docs/20-math-utilities.md — random generation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054a580 — Global State Variable Setter

Source: unknown | Consensus: high
Sets global DAT_008b8f3c to one of three sources based on mode.

**Key logic:**
- mode 0: DAT_008b8f3c = param_2
- mode 1: DAT_008b8f3c += param_2
- mode 2: DAT_008b8f3c = DAT_008b8f38 - param_2

**Globals:** DAT_008b8f3c, DAT_008b8f38

**Used by system:** docs/20-math-utilities.md — global state

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054c270 — Loop with Repeated Call (256×)

Source: unknown | Consensus: high
Calls FUN_0053b130() 256 times in a loop.

**Used by system:** docs/20-math-utilities.md — init/dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fcb0 — Field Setter at +0x80

Source: unknown | Consensus: high
Sets param_1+0x80 = param_2.

**Used by system:** docs/20-math-utilities.md — setter

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0055bdc0 — Field Getter at +0x118

Source: unknown | Consensus: high
Returns *(int*)(param_1 + 0x118).

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00561a15 — Short Array Fill with Stride

Source: unknown | Consensus: high
Fills array with short value using configurable stride.

**Key logic:**
- Base = param_5 + param_1 * 2
- Loop: writes param_3, advances by param_4 shorts, repeats param_2 times

**Used by system:** docs/20-math-utilities.md — array fill

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00565e20 — Linked-List Destructor with Child Cleanup

Source: unknown | Consensus: high
Destroys a linked list structure including its child objects and the root object.

**Key logic:**
- FUN_00565d50() pre-cleanup
- Frees child object at +0x210 (0x84*4) if non-null
- Walks linked list: frees each node's data via FUN_00414370 + free, frees node
- Zeros control fields; frees root param_1

**Calls:** FUN_00565d50, FUN_00414370, FUN_00587bcf ×N

**Used by system:** docs/20-math-utilities.md — linked list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005681f0 — Conditional Dispatch

Source: unknown | Consensus: high
If FUN_00568210(param_1) ≠ 0: returns FUN_00567970(); else returns 0.

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a760 — SEH-Protected Data Copy

Source: unknown | Consensus: high
SEH-protected operation that copies data between buffers.

**Key logic:**
- SEH prolog; calls FUN_00586700()
- Calls FUN_005853b0() — check
- If true: calls FUN_00586a10 to copy data from param_2 to local_64, stores to *param_3/*param_2
- Returns 0 on success, 0xb on failure
- SEH epilog

**Used by system:** docs/20-math-utilities.md — protected data copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005822b0 — Linked-List Free Standard

Source: unknown | Consensus: high
Standard linked-list destruction freeing data and nodes.

**Key logic:**
- Walk list: if destroy flag + data: free(data); free(node); zero controls

**Used by system:** docs/20-math-utilities.md — list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005862c0 — Mutex Creator with Error Handling

Source: unknown | Consensus: high
Creates Win32 mutex, handles existing handle.

**Key logic:**
- CloseHandle existing at +0x50 if active;
- CreateMutexA(inherit=TRUE); store at +0x50; set flag at +0x58

**Used by system:** docs/20-math-utilities.md — threading

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587880 — Field Getter at +0x400

Source: unknown | Consensus: high
Returns *(int*)(param_1 + 0x400).

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058969d — String/Format Processing with Null-Term

Source: unknown | Consensus: medium
Processes a string/format buffer with null-termination handling.

**Key logic:**
- Calls FUN_0058d04d to format/process
- Decrements length; if negative: calls FUN_0058cf35 to flush, else null-terminates

**Used by system:** docs/20-math-utilities.md — string processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058bdcd — Float-to-String with Sign/Width

Source: unknown | Consensus: high
Converts a double to string with sign, width, and precision handling.

**Key logic:**
- FUN_00595621 parse double → local buffer
- FUN_005955aa compute sign/width offset
- FUN_0058be2e render final string

**Used by system:** docs/20-math-utilities.md — string formatting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00591cf3 — __frnd — MSVC CRT Rounding

Source: unknown | Consensus: high
MSVC CRT __frnd: rounds double to extended precision (x87 ROUND).

**Key logic:**
- Returns ROUND(param_1) as float10

**Used by system:** docs/20-math-utilities.md — MSVC CRT math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00597037 — Constant Mapper (0x3a4→0x411 etc.)

Source: unknown | Consensus: high
Maps 4 input constants to output constants; returns 0 for unmapped.

**Key logic:**
- 0x3a4 → 0x411; 0x3a8 → 0x804; 0x3b5 → 0x412; 0x3b6 → 0x404; else 0

**Used by system:** docs/20-math-utilities.md — constant mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005993af — Reference Count Decrement with Conditional Free

Source: unknown | Consensus: high
Decrements a refcount and conditionally frees an object.

**Key logic:**
- If param_2: reads refcount at *(param_1+4)-1
- If 0 or -1: free; else decrement
- Zeros fields at +4, +8, +0xc

**Used by system:** docs/20-math-utilities.md — refcount management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a765 — Destructor Pattern with Conditional Free

Source: unknown | Consensus: high
Calls FUN_0059a728(); if bit 0 of param_2: free(self).

**Used by system:** docs/20-math-utilities.md — C++ destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c5bc — SEH Unwind Free Field

Source: unknown | Consensus: high
Frees a pointer from stack EBP+8 during unwind.

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cb9e — SEH Unwind Free Field

Source: unknown | Consensus: high
Frees a pointer from stack EBP-0x1c during unwind.

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d2bf — SEH Unwind Thunk

Source: unknown | Consensus: high
Unwind handler — thunk to FUN_00598cc1.

**Calls:** FUN_00598cc1

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

## FUN_004fffa0 — Thunk with Struct Init + Sub-Calls

Source: unknown | Confidence: high
Trampoline-style function that initializes a struct, then delegates to two subroutines. Not a pure thunk — contains local logic.

**Key logic:**
- Sets `*param_1 = DAT_005ad344` (global constant, unknown purpose)
- Sets `param_1[1] = 8` (likely enum/count/size field)
- Calls FUN_00500190 (vehicle struct access, per triage index)
- Calls FUN_005001b0 (arithmetic/comparison, per triage index)
- No return value

**Globals:**
- `DAT_005ad344` — referenced as initialization constant; not documented in docs/12

**Calls:**
- FUN_00500190 — vehicle struct access (triage index line 3412)
- FUN_005001b0 — arithmetic/comparison (triage index line 3413)

**Used by system:** docs/20-math-utilities.md — init wrapper, likely called during object construction in the 0x0050XXXX range

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005565b0 — High-Precision Timer Counter Arithmetic

Source: unknown | Confidence: high
Computes an elapsed time value using high-precision counter reads, handling 64-bit counter overflow/rollover.

**Key logic:**
- Reads multiple uint fields from param_1 array indices (offset in uint steps): [6], [7], [10], [0xb]
- Calls FUN_005564b0 (QueryPerformanceCounter wrapper) to get current counter values into local_18 (high) and local_1c (low)
- Computes elapsed counter ticks using 64-bit subtraction with borrow handling:
  - 64-bit diff = (local_18 - local_c) - borrow handling for low-part wraparound
  - Additional subtraction of local_14 (offset/bias)
- Combines with two additional terms:
  - `(local_1c - local_8) - local_10` divided by `*param_1` (frequency divisor)
  - Double value from `param_1[2]` (multiplier)
  - Double value from `param_1[4]` (additive bias)
- Returns float10 (x87 80-bit extended precision)

**Algorithm family:** High-resolution timer computation with 64-bit tick delta and frequency normalization

**Calls:**
- FUN_005564b0 — QueryPerformanceCounter wrapper (triage index lines 4553, 6328)

**Used by system:** docs/20-math-utilities.md — timing/performance measurement with QPC-based elapsed time calculation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00561acf — Array Fill with Value

Source: unknown | Confidence: high
Fills int array (4-byte stride) with specified value using counted loop.

**Key logic:**
- param_1 = start index
- param_2 = element count
- param_3 = fill value
- param_4 = array base address
- Writes param_3 to param_2 elements at param_4 + param_1*4

**Algorithm family:** Array/vector fill

**Used by system:** docs/20-math-utilities.md — generic array fill

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00566cf0 — Resource Lookup with Dual Path

Source: unknown | Confidence: medium
Two-strategy resource lookup: direct string search or system registration lookup.

**Key logic:**
- If `param_1[4] == 0`: calls FUN_0058babb(param_2, *param_1) — file write lookup
  - Returns true if result != -1
- If `param_1[4] != 0`: calls FUN_005352b0() — arithmetic/comparison
  - Returns true if result != -1

**Calls:**
- FUN_0058babb — write string to file via FUN_0058c1b1/FUN_0058e41b (triage index)
- FUN_005352b0 — arithmetic/comparison (triage index)

**Used by system:** docs/20-math-utilities.md — resource lookup with fallback

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b9f0 — Copy 4 Dwords Struct to Struct

Source: unknown | Confidence: high
Copies 16 bytes (4 dwords) from source struct to destination struct.

**Key logic:**
- Copies `param_1[0..3]` to `param_2[0..3]`
- 4 consecutive 4-byte (int/undefined4) assignments
- Equivalent to small struct copy or memcpy(dst, src, 16)

**Algorithm family:** Struct copy / bitblt

**Used by system:** docs/20-math-utilities.md — small struct copy utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00581a80 — Linked List Cleanup (Generic)

Source: unknown | Confidence: high
Destroys a singly-linked list of nodes, optionally freeing node data.

**Key logic:**
- Reads head pointer from `*param_1`
- Iterates via `next` pointer at `puVar2[1]` (offset +0x04)
- For each node: if `*(char *)(puVar2 + 2) != 0` (flag at offset +0x08): calls FUN_00587bcf(*puVar2) — free data at node start
- Then frees the node itself via FUN_00587bcf(puVar2)
- After loop: zeroes param_1[0..3] (4 fields, likely head/tail/count)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | head | int* | Linked list head pointer |
| +0x04 | tail/count | int* | Secondary list field |
| +0x08 | field2 | int | Additional list field |
| +0x0c | field3 | int | Additional list field |

**Calls:**
- FUN_00587bcf — free/operator delete (docs/09, 19, 21)

**Used by system:** docs/20-math-utilities.md — generic singly-linked list destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005871f0 — Read Field at Offset 0x14

Source: unknown | Confidence: high
Simple field getter — reads and returns value at param_1 + 0x14.

**Key logic:**
- Returns `*(undefined4 *)(param_1 + 0x14)` — 4-byte value at struct offset +0x14

**Algorithm family:** Field accessor

**Used by system:** docs/20-math-utilities.md — trivial struct field getter

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058a380 — Pass-Through Wrapper Function

Source: unknown | Confidence: high
Delegates all arguments directly to FUN_00593446 and returns its result. Pure pass-through.

**Key logic:**
- Calls `FUN_00593446(param_1, param_2, param_3, param_4)` — magic number check (0x19930520) with dispatch via vtable or fallback (triage index)
- Returns result unchanged

**Calls:**
- FUN_00593446 — magic number check with vtable dispatch (triage index line 7327)

**Used by system:** docs/20-math-utilities.md — pass-through wrapper, likely alias or interface adapter

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058d7c3 — Loop with Sentinel Termination

Source: unknown | Confidence: medium
Iterates up to param_2 times, calling a stream output function until sentinel value (-1) appears.

**Key logic:**
- Loop: decrements param_2, checks param_2 < 1 → return
- Calls `FUN_0058d78e(param_1, param_3, param_4)` — stream byte output with buffer management
- Continues while `*param_4 != -1` (sentinel check)
- Returns early if count exhausted

**Algorithm family:** Sentinel-terminated iteration

**Calls:**
- FUN_0058d78e — stream byte output with buffer management (triage index line 6838)

**Used by system:** docs/20-math-utilities.md — streaming output with sentinel termination

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058f6c7 — In-Place Digit Char Conversion, Strip Semicolons

Source: unknown | Confidence: high
In-place conversion of digit characters ('0'-'9') to their numeric values (0-9), stripping semicolons (';') from a string.

**Key logic:**
- Iterates through string in-place
- For each character:
  - If null terminator: return
  - If digit ('0'-'9'): converts to 0-9 via `cVar2 + -0x30` (subtract ASCII '0')
  - If semicolon (';'): shifts all subsequent chars left by 1 (strip it)
  - Otherwise: advance to next char unchanged
- Result: numeric values for digits, other non-digit non-semicolon chars preserved, semicolons removed

**Algorithm family:** String transform / in-place filter

**Used by system:** docs/20-math-utilities.md — string preprocessing, likely for parsing data files

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599d17 — VTable Pointer Init

Source: unknown | Confidence: high
Initializes object's vtable pointer and calls constructor init method.

**Key logic:**
- Sets `*param_1 = &PTR_FUN_005b9ca0` — assigns vtable pointer to function table at 0x005b9ca0
- Calls `FUN_00598c70()` — null check with virtual dispatch (triage index line 6953)

**Calls:**
- FUN_00598c70 — null check with virtual dispatch / error handling (triage index)

**Used by system:** docs/20-math-utilities.md — vtable/constructor initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c828 — Unwind Handler (SEH)

Source: unknown | Confidence: high
SEH unwind handler that delegates to linked list destroy with vtable destructor.

**Key logic:**
- Calls `FUN_005819c0()` — linked list destroy with vtable destructor (triage index line 6635)

**Calls:**
- FUN_005819c0 — linked list destroy with vtable destructor (triage index, docs/21)

**Used by system:** docs/20-math-utilities.md — SEH unwind cleanup for list-based object

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c972 — Unwind Handler (SEH)

Source: unknown | Confidence: high
SEH unwind handler delegating to pool destructor.

**Key logic:**
- Calls `FUN_00582190()` — pool destructor: closes mutex, frees busy/free linked lists (docs/21)

**Calls:**
- FUN_00582190 — pool destructor, closes mutex, frees linked lists (docs/21)

**Used by system:** docs/20-math-utilities.md — SEH unwind cleanup for pooled objects

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d208 — Unwind Handler (SEH)

Source: unknown | Confidence: low (register variable unaff_EBP)
SEH unwind handler freeing object at stack offset -0x10 with global data reference.

**Key logic:**
- Calls `FUN_00599796(*(undefined4 *)(unaff_EBP + -0x10), &DAT_008d4210)` — math_util / no-op stub

**Globals:**
- `DAT_008d4210` — passed as second argument; not in docs/12

**Calls:**
- FUN_00599796 — math_util / no-op stub (triage index lines 5796, 7603)

**Used by system:** docs/20-math-utilities.md — SEH unwind with global cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004045f0 — Short Computation (Struct Array Destructor)

Source: unknown | Confidence: medium
Frees three allocated buffers, clears flag fields, destroys an array of sub-objects with counted destructor loop.

**Key logic:**
- Frees buffers at +0x150, +0x154, +0x158 if non-null (via FUN_00587bcf)
- Zeroes those pointers
- Sets `*(float *)(param_1 + 0x148) = 0xbf800000` (-1.0f as float) — initial/default value
- If array at +0x134 non-null: reads element count from header at offset -4, iterates calling FUN_004b0170 (destructor) for each, then frees header
- Zeroes +0x134, +0x138, +0x130

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x130 | unknown | int | Zeroed |
| +0x134 | arrayPtr | int* | Pointer to array (with -4 header) |
| +0x138 | count | int | Array element count, zeroed |
| +0x148 | defaultVal | float | Set to -1.0f |
| +0x150 | buffer1 | int* | Freed if non-null |
| +0x154 | buffer2 | int* | Freed if non-null |
| +0x158 | buffer3 | int* | Freed if non-null |

**Calls:**
- FUN_00587bcf — free/operator delete
- FUN_004b0170 — destructor (triage index)

**Used by system:** docs/20-math-utilities.md — struct/array destructor helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00405050 — Short Computation (String-to-Resource-ID Lookup)

Source: unknown | Confidence: medium
Multi-strategy string-to-integer lookup: tries internal table, then file read, then format lookup.

**Key logic:**
- Calls FUN_00404fe0 (tokenize/preprocess param_1)
- Calls FUN_00407f10 (memory allocation) — tries internal ID lookup
  - If found (!= -1): stores result in *param_2, returns 1
- If not found: checks string length > 4
  - Calls FUN_00566810 (file read/filter check) 
  - If success: calls FUN_00587f59 (single function call wrapper) with param_1+4
  - Calls FUN_00404fe0(0) and FUN_00407e40 (memory allocation/short computation)
  - If found: reads ID from *(iVar2 + 0x10), stores in *param_2, returns 1
- Fallback: calls FUN_00595ae2(param_1, 0x8000, 0x100) — string format with 0x40 size
  - If found (!= -1): stores in *param_2, returns 1
- Returns 0 if all strategies fail

**Calls:**
- FUN_00404fe0 — tokenize/preprocess (triage index)
- FUN_00407f10 — memory allocation (triage index line 193)
- FUN_00566810 — file read/filter check (triage index)
- FUN_00587f59 — single function call wrapper (triage index)
- FUN_00407e40 — memory allocation (triage index)
- FUN_00595ae2 — string format (triage index)

**Used by system:** docs/20-math-utilities.md — resource ID lookup from string name

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406100 — Short Computation (Conditional Field Init)

Source: unknown | Confidence: medium
Conditionally initializes three local values and passes them to another function based on struct field availability.

**Key logic:**
- Checks `*(int *)(param_1 + 0x58) != 0` AND `*(int *)(*(int *)(param_1 + 0x58) + 0x10) != 0`
  — sub-struct and its field must exist
- If both non-null: sets up three local variables, calls FUN_00404fe0 (tokenize/preprocess) and FUN_00407e10 (short computation / memory allocation)

**Calls:**
- FUN_00404fe0 — tokenize/preprocess (triage index)
- FUN_00407e10 — short computation (triage index line 190)

**Used by system:** docs/20-math-utilities.md — conditional field initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00407d40 — Short Computation (Trigonometric/Angle Vector Math)

Source: unknown | Confidence: medium
Sets position and rotation fields on a struct, computing rotation matrix components using sin/cos.

**Key logic:**
- Copies 3 ints from param_2 (position: +0x58, +0x5c, +0x60)
- Copies 3 floats from param_3 (rotation angles: +0x64, +0x68, +0x6c)
- Computes rotation using fsin/fcos on the two rotation angles:
  - `sin_yaw = fsin(angle1)` at +0x68
  - `sin_pitch = fsin(angle0)` at +0x64
  - `cos_yaw = fcos(angle1)` at +0x68
- Uses DAT_0059e440 (ZeroThreshold, ~0.0f physics clamp constant)
- Writes 3 rotation values at +0x70, +0x74, +0x78 derived from sin/cos combinations

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x58 | posX | int | Position X |
| +0x5c | posY | int | Position Y |
| +0x60 | posZ | int | Position Z |
| +0x64 | anglePitch | float | Pitch rotation |
| +0x68 | angleYaw | float | Yaw rotation |
| +0x6c | angleRoll | float | Roll rotation |
| +0x70 | rotComponent0 | float | Rotation matrix value |
| +0x74 | rotComponent1 | float | Rotation matrix value |
| +0x78 | rotComponent2 | float | Rotation matrix value |

**Globals:**
- `DAT_0059e440` — ZeroThreshold (~0.0f, physics clamp constant, docs/12)

**Algorithm family:** 3D rotation/trigonometric computation

**Used by system:** docs/20-math-utilities.md — position + rotation setup with trigonometric matrix

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408490 — Short Computation (Float Multiply with Global Constant)

Source: unknown | Confidence: high
Multiplies input float by global constant _DAT_005be8f8.

**Key logic:**
- Returns `_DAT_005be8f8 * *param_1` — float multiplication by global constant

**Globals:**
- `_DAT_005be8f8` — global float constant (serialization constant area, docs/12)

**Algorithm family:** Scalar multiplication

**Used by system:** docs/20-math-utilities.md — float scaling with global multiplier

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040b630 — Short Computation (Nearest Neighbor Search with Float Distance)

Source: unknown | Confidence: medium
Searches array of structs (stride 0xd0) for element with closest float value to a reference.

**Key logic:**
- Reads count from `*(int *)(param_1 + 0x10)`
- Iterates array at `*(int *)(param_1 + 0xc)` with stride 0xd0 (208 bytes)
- For each element: reads float at offset +0x8c
- Calls FUN_004579c0(param_2) — returns float value
- Computes `|FUN_004579c0(param_2) - array[i].field_0x8c|` as absolute difference
- Tracks minimum distance (local_8, initialized to FLT_MAX 3.4028235e+38)
- Tracks best index (local_4, initialized to -1)
- Outputs best index via *param_3, best distance via *param_4

**Algorithm family:** Nearest-neighbor / minimum-distance search

**Calls:**
- FUN_004579c0 — math_util short computation (triage index)

**Used by system:** docs/20-math-utilities.md — minimum-distance element search in struct array

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d360 — Short Computation (Random Integer with Bounds)

Source: unknown | Confidence: medium
Generates a random float value within specified bounds using _rand().

**Key logic:**
- Sets `*(byte *)(param_1 + 0x2e) = 1` — active flag
- If param_2 < 1: sets min = 0, else min = param_2
- If param_3 < 1 OR param_3 <= param_2: sets max = min + 5
- Else: sets max = param_3
- Calls `_rand()`, computes: `rand() % (max - min) + min`
- Stores result as float at `*(float *)(param_1 + 0x3c)`
- Returns `rand() / (max - min)` — integer quotient

**Algorithm family:** Random number generation with bounds

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x2e | active | byte | Set to 1 |
| +0x30 | minVal | int | Minimum bound |
| +0x34 | maxVal | int | Maximum bound |
| +0x3c | randFloat | float | Random value as float |

**Used by system:** docs/20-math-utilities.md — bounded random value generation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e710 — Short Computation (Field Set via Switch Dispatch)

Source: unknown | Confidence: medium
Switch on mode field to determine where to write a value in sub-struct.

**Key logic:**
- Switches on `*(int *)(param_1 + 0x1c)` — mode/index field
- Cases 0,3: writes param_2 to `*(int *)(param_1 + 0x20) + 0xd0`
- Cases 1,4: same write (identical to cases 0,3)
- Cases 2,5: same write (identical to cases 0,3)
- All cases produce same effect — switch may be placeholder or decompilation artifact

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1c | mode | int | Switch selector (0-5) |
| +0x20 | subStruct | int* | Pointer to destination structure |

**Used by system:** docs/20-math-utilities.md — mode-dependent field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040fb00 — Short Computation (Struct Field Zero-Init)

Source: unknown | Confidence: high
Zero-initializes 10 fields spaced across a struct, then calls a sub-init routine.

**Key logic:**
- Sets 10 fields at offsets +0x08, +0x10, +0x18, +0x20, +0x28, +0x34, +0x40, +0x4c, +0x58, +0x64 to 0
- Offsets follow pattern: +0x08, then +0x08 gaps with some +0x0c gaps
- Calls FUN_0040fb30() — unknown sub-init
- Returns param_1

**Calls:**
- FUN_0040fb30 — unknown sub-init

**Used by system:** docs/20-math-utilities.md — struct field initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004119d0 — Short Computation (Range Check Classification)

Source: unknown | Confidence: high
Classifies an integer value into three bands with boundary checking.

**Key logic:**
- If 0 < param_1 < 0x123 (291): returns 0 (band 0)
- If 0x124 (292) < param_1 < 0x218 (536): returns 1 (band 1)
- Otherwise: returns 0xffffffff (-1, invalid/out of range)

**Used by system:** docs/20-math-utilities.md — integer range classifier, likely for enum/index validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_00418b70 — Short Computation (Table Lookup with Sentinel)

Source: unknown | Confidence: high
Looks up a value in a global table (stride 0x14) by index, with -1 sentinel check.

**Key logic:**
- If param_1 == -1: returns 0xffffffff (-1)
- Otherwise: returns `*(int *)(&DAT_005bf9a0 + param_1 * 0x14)` — table lookup with 20-byte stride

**Globals:**
- `DAT_005bf9a0` — global table with 0x14 (20) byte stride (near DriverDataTable at 0x005bf9b0)

**Used by system:** docs/20-math-utilities.md — indexed table lookup with sentinel guard

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041f190 — Short Computation (Multi-Condition State Check)

Source: unknown | Confidence: medium
Checks multiple conditions: a flag function, a state value, and a field comparison.

**Key logic:**
- Calls FUN_004c2850() — math_util short computation
- Calls FUN_004c11d0() — vehicle struct access (triage index)
- Calls FUN_0041f1e0() — returns boolean (math_util)
- Returns 1 if: FUN_0041f1e0() != 0 AND (iVar2 == 2 OR (iVar2 > 2 AND param_1[0x33 + iVar2] != 10))
- Otherwise returns 0

**Calls:**
- FUN_004c2850 — math_util short computation (triage index)
- FUN_004c11d0 — vehicle struct access (triage index)
- FUN_0041f1e0 — math_util short computation (triage index)

**Used by system:** docs/20-math-utilities.md — conditional state check with multiple criteria

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421990 — Short Computation (Delegation Wrapper)

Source: unknown | Confidence: high
Calls two functions with the same parameter.

**Key logic:**
- Calls FUN_00421890(param_1) — math_util short computation
- Calls FUN_00566650(param_1) — path registry / string set (docs/09)

**Calls:**
- FUN_00421890 — math_util short computation (triage index)
- FUN_00566650 — path registry / string set (docs/09)

**Used by system:** docs/20-math-utilities.md — delegation wrapper

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004530a0 — Short Computation (Mode-Dispatch with Conditional)

Source: unknown | Confidence: medium
Dispatches based on a mode flag: either direct call or conditional call with predicate.

**Key logic:**
- If `*param_1 == 0`: calls FUN_004527e0(param_1[1], param_2) — math_util
- If `*param_1 == 1`: calls FUN_00452b10(param_1[1], param_2 == 2)
  - If FUN_00452b10 returns non-zero: calls FUN_00452810(param_1[1]) — unknown
- Otherwise returns

**Calls:**
- FUN_004527e0 — math_util short computation (triage index)
- FUN_00452b10 — game object/slot lookup by address (triage index, docs/19)
- FUN_00452810 — unknown (triage index)

**Used by system:** docs/20-math-utilities.md — mode-based dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004562a0 — Short Computation (VTable Set + Conditional Free)

Source: unknown | Confidence: high
Sets vtable pointer and conditionally frees a sub-object.

**Key logic:**
- Sets `*param_1 = &PTR_FUN_0059efcc` — vtable assignment
- If `param_1[1] != 0`: calls FUN_00587bcf(param_1[1]) — free sub-object

**Calls:**
- FUN_00587bcf — free/operator delete

**Used by system:** docs/20-math-utilities.md — constructor with conditional cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b360 — Short Computation (Constructor/Initializer)

Source: unknown | Confidence: medium
Initializes a structured object with default values, loops to init 8 sub-elements.

**Key logic:**
- Calls FUN_004dcb70() — math_util short computation
- Sets param_1[0xb] = 0, param_1[0xc] = 0xffffffff
- Calls FUN_004dcf80() — references game state
- Loop 8 times: initializes sub-element at stride 0x17 (23 dwords = 92 bytes)
  - Sets byte to 0
  - Sets +0x14 to 0xffffffff
  - Sets +0x15 to 0xbf800000 (-1.0f)
  - Sets +0x16 to 3
- Sets vtable: `*param_1 = &PTR_FUN_0059f080`
- Sets param_1[199] = 0
- Loop: calls FUN_0045b430(i) for i = 0..7 — math_util
- Clears param_1[200] (byte), param_1[0xc9], param_1[0xca]

**Calls:**
- FUN_004dcb70 — math_util short computation (triage index)
- FUN_004dcf80 — references game state (triage index)
- FUN_0045b430 — math_util short computation (triage index)

**Used by system:** docs/20-math-utilities.md — structured object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bde0 — Short Computation (Delegation Wrapper)

Source: unknown | Confidence: high
Thin wrapper that delegates to FUN_0045ba60.

**Key logic:**
- Calls FUN_0045ba60() — unknown (64 lines, unidentified)

**Calls:**
- FUN_0045ba60 — unknown (triage index)

**Used by system:** docs/20-math-utilities.md — delegation wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045ce30 — Short Computation (String Concatenation with Backslash)

Source: unknown | Confidence: medium
Concatenates two strings into a third, inserting backslash separator, using optimized dword copy.

**Key logic:**
- Copies param_1 to local buffer (local_c0)
- Copies param_2 to local buffer (local_80)
- Calls FUN_0045cf30() twice — math_util short computation
- Finds end of param_3 (output buffer)
- Appends DAT_005c2aac (backslash) to param_3
- Copies local_c0 (first string) to param_3 after backslash, using dword (4-byte) copy for efficiency
- Appends second backslash
- Copies local_80 (second string) to param_3
- Returns resulting string length

**Globals:**
- `DAT_005c2aac` — backslash character (docs/08 path_util.cpp)

**Algorithm family:** String concatenation with optimized copy

**Calls:**
- FUN_0045cf30 — math_util short computation (triage index)

**Used by system:** docs/20-math-utilities.md — path string concatenation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004613e0 — Short Computation (Batch Dispatch with Predicate)

Source: unknown | Confidence: medium
Iterates an array of object pointers, conditionally calling a collision/callback function based on a predicate.

**Key logic:**
- Reads count from `*(int *)(param_1 + 0x3e14)` — number of entries
- Iterates array starting at `param_1 + 0x3c74` (stride 4 — pointer array)
- For each entry: calls FUN_00461530(2) — predicate check (math_util)
- If predicate returns 0: calls FUN_00462940(*current_ptr) — collision detection
- Continues until all entries processed

**Calls:**
- FUN_00461530 — math_util short computation (triage index)
- FUN_00462940 — collision detection (triage index)

**Used by system:** docs/20-math-utilities.md — batched conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461ff0 — Short Computation (Conditional Delegation)

Source: unknown | Confidence: high
Checks a condition, returns 0 if true, otherwise delegates to another function.

**Key logic:**
- Calls FUN_00461fc0() — math_util short computation
- If non-zero: returns 0 (skip)
- Otherwise: returns FUN_00563eb0() — single delegation call / passthrough (triage index)

**Calls:**
- FUN_00461fc0 — math_util short computation (triage index)
- FUN_00563eb0 — single delegation call (triage index)

**Used by system:** docs/20-math-utilities.md — conditional bridge

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463140 — Short Computation (Virtual Dispatch + Field Clear)

Source: unknown | Confidence: medium
Calls a dual virtual dispatch wrapper, then clears a struct field on the target object.

**Key logic:**
- Calls FUN_0057a660() — dual virtual dispatch wrapper (triage index)
- Sets `*(int *)(*param_1 + 0x3fc4) = 0` — clear field in target object

**Calls:**
- FUN_0057a660 — dual virtual dispatch wrapper (triage index)

**Used by system:** docs/20-math-utilities.md — dispatch and field reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464940 — Short Computation (SEH Handler Setup)

Source: unknown | Confidence: high
Sets up SEH handler via FUN_00587b3e.

**Key logic:**
- Calls `FUN_00587b3e(&LAB_00464950)` — boolean-to-int conversion with handler address

**Calls:**
- FUN_00587b3e — boolean-to-int conversion (triage index)

**Used by system:** docs/20-math-utilities.md — SEH handler registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004652d0 — Short Computation (Slot Activation Counter)

Source: unknown | Confidence: medium
Activates a slot (stride 0x230) in an array, increments global counter if slot was inactive.

**Key logic:**
- Computes slot address: `param_2 * 0x230 + 0xf8 + *param_1` — slot at stride 0x230, offset +0xf8
- If slot's active flag (`*pcVar1`) is 0: sets it to 1, increments counter at `*param_1 + 0xe40c`

**Struct offset (*param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xe40c | activeCount | int | Counter of active slots |

**Used by system:** docs/20-math-utilities.md — slot activation with usage tracking

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466c40 — Short Computation (Physics Computation + State Clear)

Source: unknown | Confidence: medium
Calls physics computation functions and clears a state flag.

**Key logic:**
- Calls FUN_00431390(field_0x108, field_0x104) — physics_math computation
- Calls FUN_00430f00() — unknown
- Clears `*(byte *)(param_1 + 0x100) = 0`

**Calls:**
- FUN_00431390 — physics_math computation (triage index)
- FUN_00430f00 — unknown

**Used by system:** docs/20-math-utilities.md — physics step with state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a510 — Short Computation (Destructor with Conditional Free)

Source: unknown | Confidence: high
Calls cleanup function, conditionally frees the object based on flag bit.

**Key logic:**
- Calls FUN_0046a530() — math_util short computation
- If `param_2 & 1 != 0`: calls FUN_00587bcf(param_1) — free object
- Returns param_1

**Calls:**
- FUN_0046a530 — math_util short computation (triage index)
- FUN_00587bcf — free/operator delete

**Used by system:** docs/20-math-utilities.md — destructor with ownership flag

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046d5f0 — Short Computation (Constructor - VTable Assignment)

Source: unknown | Confidence: high
Sets up object with field getter initialization and vtable assignment.

**Key logic:**
- Calls FUN_00487220(0, 0) — struct field getter at +0x10 (called with zeros)
- Sets `*param_1 = &PTR_FUN_0059fc08` — vtable assignment

**Calls:**
- FUN_00487220 — struct field getter at +0x10 (triage index)

**Used by system:** docs/20-math-utilities.md — constructor stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046f890 — Short Computation (Constructor - Field + VTable)

Source: unknown | Confidence: high
Constructor that stores a byte field and assigns vtable.

**Key logic:**
- Calls FUN_00487220(0, 0) — struct field getter at +0x10
- Stores param_2 at `param_1 + 0x39` — byte field
- Sets `*param_1 = &PTR_FUN_005a0040` — vtable assignment
- Returns param_1

**Used by system:** docs/20-math-utilities.md — constructor with field init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00471540 — Short Computation (Constructor with Default Values)

Source: unknown | Confidence: medium
Constructor initializing an object with default values, global references, and registration calls.

**Key logic:**
- Calls FUN_00466d60(1) — math_util short computation
- Sets vtable `*param_1 = &PTR_FUN_005a0e40`
- Sets param_1[0xcd] = 0xec (236) — size/count
- Calls FUN_00486f30 for three global addresses with -1 (unregister/reset)
  - &PTR_DAT_005be704, &PTR_DAT_005c32a4, &DAT_005c32a8
- Sets param_1[199] = &DAT_007ce73c — stores global reference
- Sets fields: [0xc9]=2, [0xca]=0, [0xcb]=1, [0xcc]=1 — configuration values
- Calls FUN_004670e0() — unknown (56 lines)

**Globals:**
- `DAT_007ce73c` — referenced but not in docs/12

**Calls:**
- FUN_00466d60 — math_util (triage index)
- FUN_00486f30 — unknown (triage index line 1742)
- FUN_004670e0 — unknown (triage index)

**Used by system:** docs/20-math-utilities.md — constructor with registration and config

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473330 — Short Computation (Constructor Config Init)

Source: unknown | Confidence: medium
Constructor setting vtable, global refs, and config values. Similar pattern to FUN_00471540.

**Key logic:**
- Calls FUN_00466d60(1) — math_util
- Sets vtable `*param_1 = &PTR_FUN_005a2700`
- Stores global ref: param_1[199] = &DAT_007cf788
- Config: [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0x10d (269)
- Registers two globals via FUN_00486f30 with -1

**Calls:**
- FUN_00466d60 — math_util (triage index)
- FUN_00486f30 — unknown (triage index)

**Used by system:** docs/20-math-utilities.md — constructor with config

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00474c50 — Short Computation (Destructor with Conditional Free)

Source: unknown | Confidence: high
Destructor calling cleanup and conditionally freeing object.

**Key logic:**
- Calls FUN_00474c70() — math_util
- If param_2 & 1: FUN_00587bcf(param_1)
- Returns param_1

**Calls:**
- FUN_00474c70 — math_util
- FUN_00587bcf — free/delete

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00476600 — Short Computation (Multi-Stage Destructor)

Source: unknown | Confidence: medium
Vtable-switching destructor that frees sub-objects at various indices.

**Key logic:**
- Three-stage vtable switch: sets vtable then frees field at that stage:
  1. vtable FUN_005a448c → free param_1[0xf]
  2. vtable FUN_005a4450 → free param_1[0xc]
  3. vtable FUN_005a443c → free param_1[1]
- If param_2 & 1: free param_1 itself
- Returns param_1

**Calls:**
- FUN_00587bcf — free/delete (multiple calls)

**Used by system:** docs/20-math-utilities.md — multi-stage destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004781e0 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor: calls function, sets vtable and default field.

**Key logic:**
- Calls FUN_0048fb70() — unknown
- Vtable: `&PTR_FUN_005a4810`
- Sets param_1[0x3a] = 0xffffffff

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004797c0 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor calling init with float params (0.5, 1.0), setting vtable.

**Key logic:**
- Calls FUN_00466980(0x3f000000=0.5f, 0x3f800000=1.0f) — math_util
- Vtable: `&PTR_FUN_005a4fe0`

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479d00 — Short Computation (Game Command Dispatch ×2)

Source: unknown | Confidence: medium
Dispatches two game commands (type 0xe, 0xf) via interface, conditionally calls handler.

**Key logic:**
- Queries `*DAT_007cd8c0 + 0x1c` (game command dispatch) with type 0xe
- If handler non-null: calls FUN_00477280(param_1)
- Same for type 0xf
- Returns 0

**Globals:**
- `DAT_007cd8c0` — game command dispatch interface (docs/06, 18, 22)

**Calls:**
- FUN_00477280 — unknown

**Used by system:** docs/20-math-utilities.md — game command dispatch

**Moddability:** hookable (via dispatch interface)

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a8f0 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor with float init (0.05f, 1.0f), vtable assignment.

**Key logic:**
- Calls FUN_004668e0(0x3d4ccccd=0.05f, 0x3f800000=1.0f)
- Vtable: `&PTR_FUN_005a6628`

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047c910 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor with init, field clear, vtable.

**Key logic:**
- Calls FUN_0048d3a0(0, 1.0f)
- Sets param_1[0x3f] = 0
- Vtable: `&PTR_FUN_005a6a68`

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485540 — Short Computation (Destructor)

Source: unknown | Confidence: high
Destructor: vtable set, function call, conditional free.

**Key logic:**
- Vtable: `&PTR_FUN_005ab3f0`
- Calls FUN_00487250() — key polling wrapper
- If param_2 & 1: free via FUN_00587bcf

**Calls:**
- FUN_00487250 — key polling (docs/19 renderer)
- FUN_00587bcf — free/delete

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485e30 — Short Computation (Constructor - Multi-Field Zero Init)

Source: unknown | Confidence: medium
Constructor zero-initializing many fields and setting sentinel values.

**Key logic:**
- Calls FUN_0049a930() — unknown
- Zeroes fields: [0x11] through [0x18], [0x1c] through [0x1f], [0x28], [0x2a], [0x2c], [0x2e], [0x30]
- Sets sentinel -1: [0x29], [0x2b], [0x2d], [0x2f], [0x31]
- Vtable: `&PTR_FUN_005ab8c0`
- Calls FUN_00486010() — unknown

**Used by system:** docs/20-math-utilities.md — constructor with extensive field init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486720 — Short Computation (Field Getter at +0x84)

Source: unknown | Confidence: high
Returns value at struct offset +0x84.

**Key logic:**
- Returns `*(undefined4 *)(param_1 + 0x84)` — 4-byte field getter

**Used by system:** docs/20-math-utilities.md — field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004876b0 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor: vtable assignment + function call.

**Key logic:**
- Vtable: `&PTR_FUN_005aba18`
- Calls FUN_00485eb0() — unknown

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00488970 — Short Computation (Clamp + Virtual Dispatch)

Source: unknown | Confidence: medium
Clamps a field to non-negative, adjusts based on two virtual method calls, then dispatches virtual at +0xa8.

**Key logic:**
- If param_1[0x38] < 0: sets to 0
- Else: gets values from virtual methods at +0x18 and +0x20
  - If +0x20 result < +0x18 result + param_1[0x38]: adjusts field = +0x20 - +0x18
- Calls virtual at +0xa8 (indirect jump table — could not recover)

**Used by system:** docs/20-math-utilities.md — UI/list scroll clamping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489ee0 — Short Computation (Conditional Float-to-Int Convert)

Source: unknown | Confidence: medium
Conditionally converts a float field to int using __ftol when above zero threshold.

**Key logic:**
- Clears field at +0x14c to 0
- If +0x160 != 0 AND *(float *)(+0x154) > DAT_0059e440 (ZeroThreshold):
  - Calls __ftol (float-to-long conversion)
  - Stores result at +0x14c

**Globals:**
- `DAT_0059e440` — ZeroThreshold (~0.0f, docs/12)

**Used by system:** docs/20-math-utilities.md — conditional float-to-int conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048c9b0 — Short Computation (Destructor Pattern)

Source: unknown | Confidence: high
Standard destructor: cleanup call + conditional free.

**Key logic:**
- Calls FUN_0048c9d0() — math_util
- If param_2 & 1: FUN_00587bcf(param_1)

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d680 — Short Computation (Destructor Pattern)

Source: unknown | Confidence: high
Standard destructor: cleanup + conditional free.

**Key logic:**
- Calls FUN_0048d6a0() — math_util
- If param_2 & 1: FUN_00587bcf(param_1)

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0048fec0 — Short Computation (Virtual Dispatch + Delegate)

Source: unknown | Confidence: medium
Calls virtual method at +0x40 with param_1[0x38], then delegates to another function.

**Key logic:**
- Calls virtual at (+0x40)(param_1[0x38]) — dispatch with field as argument
- Calls FUN_004901a0() — unknown
- Returns 0

**Used by system:** docs/20-math-utilities.md — virtual dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00494f00 — Short Computation (Delegation Wrapper)

Source: unknown | Confidence: high
Thin wrapper delegating to FUN_0053d310.

**Key logic:**
- Calls FUN_0053d310() — unknown

**Used by system:** docs/20-math-utilities.md — delegation wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004958d0 — Short Computation (Linked List Summation)

Source: unknown | Confidence: medium
Walks linked list summing values from each node, adds base value.

**Key logic:**
- If param_1 == 0: returns -1
- Gets list head via FUN_00498e30() — math_util
- Iterates via next pointer at +0x48
- For each node: calls FUN_00495920(iVar1) — math_util, accumulates sum
- Calls FUN_00498f60() (field at +0x4c), then FUN_00495930(result) — math_util
- Returns accumulated sum + final term

**Calls:**
- FUN_00498e30 — math_util (triage index)
- FUN_00495920 — math_util (triage index)
- FUN_00498f60 — field getter at +0x4c (triage index)
- FUN_00495930 — math_util (triage index)

**Used by system:** docs/20-math-utilities.md — list accumulator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497250 — Short Computation (Byte Field Setter)

Source: unknown | Confidence: high
Writes a byte value to struct at offset +0x25.

**Key logic:**
- Sets `*(byte *)(param_1 + 0x25) = param_2`

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498550 — Short Computation (Delegation with Offset)

Source: unknown | Confidence: medium
Calls FUN_00498560 with param_1 + 0x166c.

**Key logic:**
- Calls FUN_00498560(param_1 + 0x166c) — passes pointer to sub-struct

**Used by system:** docs/20-math-utilities.md — delegation to sub-struct method

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498f60 — Short Computation (Field Getter at +0x4c)

Source: unknown | Confidence: high
Returns value at param_1 + 0x4c.

**Key logic:**
- Returns `*(undefined4 *)(param_1 + 0x4c)`

**Used by system:** docs/20-math-utilities.md — field getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499620 — Short Computation (Destructor — Double Free Check)

Source: unknown | Confidence: high
Destructor freeing owned data if flag set, then optionally freeing self.

**Key logic:**
- If byte at param_1[3] (offset +0x0c) != 0: frees `*param_1` (owned pointer)
- If param_2 & 1: frees param_1 itself
- Returns param_1

**Calls:**
- FUN_00587bcf — free/delete

**Used by system:** docs/20-math-utilities.md — destructor with ownership flag

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499bf0 — Short Computation (Negated Predicate Wrapper)

Source: unknown | Confidence: high
Returns inverse of another function's result.

**Key logic:**
- Calls FUN_00499bb0(param_1) — math_util
- Returns true if result == 0

**Used by system:** docs/20-math-utilities.md — boolean inversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a110 — Short Computation (Linked List Node Count)

Source: unknown | Confidence: medium
Advances N steps through a linked list, then counts remaining nodes.

**Key logic:**
- Starts from list head at param_1 + 8
- Advances param_2 steps via next pointer at +0x24
- From resulting node, counts remaining nodes via next pointer at +0x28
- Returns count of remaining nodes

**Used by system:** docs/20-math-utilities.md — linked list remainder counting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a990 — Short Computation (Destructor)

Source: unknown | Confidence: high
Destructor: vtable reset, conditional free, base destructor call.

**Key logic:**
- Vtable: `&PTR_LAB_005acab0`
- If param_1[0xd] != 0: free via FUN_00587bcf
- Calls FUN_004b0170() — destructor (triage index)

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049bad0 — Short Computation (Vehicle Struct Access Check)

Source: unknown | Confidence: medium
Reads a float from vehicle struct, passes to two vehicle struct access functions, returns boolean.

**Key logic:**
- Calls FUN_004f0050() — returns float from vehicle struct access
- Calls FUN_004d1cf0(result) — vehicle struct access (returns 0/1/2)
- If != 2: calls FUN_004d1d40(result) — vehicle struct access
  - If != 2: returns 0
- Returns 1

**Globals:** None directly — uses vehicle struct through called functions

**Calls:**
- FUN_004f0050 — vehicle struct access (triage index)
- FUN_004d1cf0 — vehicle struct access (triage index)
- FUN_004d1d40 — vehicle struct access (triage index)

**Used by system:** docs/20-math-utilities.md — vehicle struct state check

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004a03f0 — System/OS API Call (Cursor Show)

Source: unknown | Confidence: high
Shows the Windows cursor and calls cleanup functions.

**Key logic:**
- Calls ShowCursor(1) in loop until count >= 1 (show cursor, ensure shown)
- Calls FUN_004a0d30(0) — unknown
- Calls FUN_004a0ad0() — unknown
- Calls FUN_004c85d0() — unknown
- Returns 0

**Calls:**
- ShowCursor — Win32 user32 API

**Used by system:** docs/20-math-utilities.md — UI cursor management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1b20 — Arithmetic/Comparison (String Prefix Copy)

Source: unknown | Confidence: medium
Copies a prefix string (from global DAT_005cd138 or DAT_005cd12c) to the end of destination, depending on whether source is empty.

**Key logic:**
- If `*param_2 == '\0'` (source empty): uses DAT_005cd12c prefix
- Else: uses DAT_005cd138 prefix
- Finds end of destination string
- Copies selected prefix to end using dword-optimized copy (same pattern as FUN_0045ce30)

**Globals:**
- `DAT_005cd138` — prefix string A
- `DAT_005cd12c` — prefix string B

**Algorithm family:** String concatenation

**Used by system:** docs/20-math-utilities.md — conditional string prefix append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a3320 — Unidentified Logic (Rotation/Euler Angle Setup)

Source: unknown | Confidence: low
Conditionally performs Euler angle rotation and stores result fields.

**Key logic:**
- If sub-struct at param_1+0x14 non-null:
  - Calls FUN_00566e40() — Euler angles to 3x3 rotation matrix (triage index)
  - Calls FUN_00567400(0x40490fdb=π, &local_30) — float rotation Y-axis
  - Calls FUN_0054b3b0(param_2[0], param_2[1], param_2[2]) — math_util
  - Calls FUN_0054b450(local_30, local_2c, local_28) — math_util
  - Sets param_1[2] = 2 — mode flag

**Calls:**
- FUN_00566e40 — Euler angles to 3x3 rotation (triage index line 6489, docs/18)
- FUN_00567400 — float rotation Y-axis (triage index line 6496)
- FUN_0054b3b0 — math_util
- FUN_0054b450 — math_util

**Used by system:** docs/20-math-utilities.md — rotation/Euler angle setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a5660 — Arithmetic/Comparison (Mode-Based Field Set)

Source: unknown | Confidence: medium
Sets fields based on a mode flag, with state-dependent branching.

**Key logic:**
- If param_2 == '\0': sets +0x28=1, +0x2c=0, +0x30=0 (default mode)
- Else if +0x28 != 2: sets +0x28=2, +0x2c=1, +0x30=1 (activated mode), calls FUN_004a55e0()
- Else: calls FUN_004a55e0() (already in mode 2)

**Calls:**
- FUN_004a55e0 — unknown

**Used by system:** docs/20-math-utilities.md — mode state machine

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b0b10 — Short Computation (Add 0x14)

Source: unknown | Confidence: high
Returns param_1 + 0x14 (20). Simple offset addition.

**Key logic:**
- Returns param_1 + 0x14

**Used by system:** docs/20-math-utilities.md — pointer offset arithmetic

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b20d0 — Arithmetic/Comparison (Clamp with Bounds)

Source: unknown | Confidence: high
Sets a field and clamps it between min (+0x1c) and max (+0x20) bounds.

**Key logic:**
- Sets `*(int *)(param_1 + 0x14) = param_2`
- If value < min (+0x1c): sets to min
- If value > max (+0x20): sets to max

**Used by system:** docs/20-math-utilities.md — clamped field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b29f0 — Short Computation (Bitfield Extract × Float)

Source: unknown | Confidence: medium
Extracts a 5-bit value from a bitfield and multiplies by a global constant.

**Key logic:**
- Extracts bits at position 12, mask 0x1f (5 bits): `(*(uint *)(param_1 + 0x2c) >> 12) & 0x1f`
- Multiplies by `_DAT_005accd4` (global float constant)
- Returns float10 (x87 extended precision)

**Globals:**
- `_DAT_005accd4` — global float constant (not in docs/12)

**Algorithm family:** Bitfield extraction + scalar multiply

**Used by system:** docs/20-math-utilities.md — bitfield to float conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b3a90 — Arithmetic/Comparison (Struct Copy with Header Size)

Source: unknown | Confidence: medium
Copies variable-length struct based on size field in source header. Uses dword-optimized copy.

**Key logic:**
- Reads size from `(*param_2 >> 8 & 0x3ff) + 8` — extracts 10-bit size field from header dword, adds 8
- Copies that many bytes from source to destination using dword-then-byte copy
- Copies field at index 0x6b (int) from source to destination (additional field beyond variable portion)

**Algorithm family:** Variable-size struct copy

**Used by system:** docs/20-math-utilities.md — struct copy with size header

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4760 — Arithmetic/Comparison (Bitmask Check + Dispatch)

Source: unknown | Confidence: medium
Checks bitmasks and conditions, then dispatches to another function.

**Key logic:**
- If param_1 == 0 AND `(*param_2 & 0xfc0000) == 0` AND `(*param_2 & 0xff) < 0x68`:
  - Calls FUN_004b4840(0, index, &param_1)
  - If non-zero: returns 1
- Returns 0

**Calls:**
- FUN_004b4840 — unknown

**Used by system:** docs/20-math-utilities.md — bitmask validation and dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b8c40 — Unidentified Logic (Float Switch with AI/Game Mode Dispatch)

Source: unknown | Confidence: low
Switch on denormalized float constants as enum keys, calls fuel/timing functions with different parameters per mode.

**Key logic:**
- Switch(param_1) with cases using denormalized float constants (1.4e-45, 2.8e-45, etc.) — likely enum aliases
- Each case: calls FUN_004b8790(), subtracts/adds global constants (_DAT_008afe90, _DAT_005acb58, _DAT_005acd64)
- Sets mode field at +0xf8c to 4-7
- Calls FUN_004b86e0 with computed fuel/timing value
- Followed by FUN_004c8d60/70/a0 calls with different parameters per case

**Globals:**
- `_DAT_008afe90`, `_DAT_005acb58`, `_DAT_005acd64` — global float constants
- `DAT_008ac4c4` — interface/manager pointer

**Calls:**
- FUN_004b8790 — unknown
- FUN_004b86e0 — unknown
- FUN_004c8d60/70/a0 — unknown

**Used by system:** docs/20-math-utilities.md — game mode / AI fuel strategy dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9fb0 — Arithmetic/Comparison (Mode Range Check)

Source: unknown | Confidence: high
Checks if mode == 2, then validates a value is in range 6-8.

**Key logic:**
- If *param_1 == 2: calls FUN_004b9e30()
  - If result < 6 OR result > 8: returns 0
- Returns 1

**Used by system:** docs/20-math-utilities.md — range validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bab20 — Unidentified Logic (Merge Sort — Linked List)

Source: unknown | Confidence: high
Recursive merge sort for singly-linked list, sorting by float value at (node[0]+4).

**Key logic:**
- Counts list length by following next pointer at index 1
- Splits list at midpoint
- Recursively sorts each half via FUN_004bab20
- Merges: compares `*(float *)(*node + 4)` values, merges in ascending order
- Returns sorted list head

**Algorithm family:** Merge sort (linked list)

**Used by system:** docs/20-math-utilities.md — generic linked list merge sort

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb6b0 — Unidentified Logic (Linked List Node Removal)

Source: unknown | Confidence: high
Removes a node from a doubly-linked list by value match, with conditional data free and sentinel handling.

**Key logic:**
- Walks list from *param_1, matching nodes by *node == param_2
- On match: updates head/tail/count pointers, unlinks node
- If param_3 == '\0': clears flag at node+2 (offset +0x08)
- If flag at node+2 non-zero: frees `*node` (data pointer)
- Frees node itself via FUN_00587bcf
- Returns 1 on success, 0 on failure

**Used by system:** docs/20-math-utilities.md — linked list node removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bd8c0 — Arithmetic/Comparison (Array Element Removal by Value)

Source: unknown | Confidence: high
Removes an element from an unsorted array by swapping with the last element.

**Key logic:**
- Searches array at param_1+8 for value == param_2
- Linear search through count at param_1+4
- On match: decrements count, overwrites matched slot with last element
- O(1) removal by swap-with-last

**Used by system:** docs/20-math-utilities.md — array element removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c03c0 — Arithmetic/Comparison (Struct Init with Alternating Defaults)

Source: unknown | Confidence: high
Initializes 6 fields with alternating 0/-1 pattern, calls sub-init.

**Key logic:**
- Sets fields [0]=0, [1]=-1, [2]=0, [3]=-1, [4]=0, [5]=-1
- Calls FUN_004c07f0() — unknown

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2bf0 — Short Computation (Increment Field at +0x28)

Source: unknown | Confidence: high
Increments integer field at offset +0x28 by 1.

**Key logic:**
- `*(int *)(param_1 + 0x28)++`

**Used by system:** docs/20-math-utilities.md — counter increment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c4900 — Arithmetic/Comparison (Struct Init)

Source: unknown | Confidence: high
Zero-initializes fields with one -1 sentinel.

**Key logic:**
- [0]=0, [1]=-1, [2]=0, [3]=0, [4]=0, [5]=0
- Calls FUN_004c4cf0() — unknown

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7de0 — Unidentified Logic (Timer/Countdown with Render Dispatch)

Source: unknown | Confidence: low
Decrements a timer float, conditional render dispatch when below threshold.

**Key logic:**
- If sub-struct at +0xc non-null:
  - Decrements float at +0x4 by global `_DAT_008afe98`
  - If result < DAT_0059e440 (ZeroThreshold): calls FUN_004c7f30(0.4f), adds `_DAT_0059e8c8`, clamps to 0
  - If global DAT_008ac4c4 != null: dispatches virtual at +0x28
  - Iterates linked list at (param_1+0xc)->indirection, calling FUN_004c8fc0 per node
  - Advances through list until empty

**Globals:**
- `DAT_0059e440` — ZeroThreshold (docs/12)
- `DAT_008ac4c4` — interface/manager pointer (unknown)
- `_DAT_008afe98`, `_DAT_0059e8c8` — float constants

**Used by system:** docs/20-math-utilities.md — timer/countdown with rendering dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8d60 — Arithmetic/Comparison (Virtual Dispatch via Global)

Source: unknown | Confidence: medium
Conditionally dispatches virtual method at +0x14 through global interface pointer.

**Key logic:**
- If DAT_008ac4c4 != null: calls virtual at (+0x14) via `*DAT_008ac4c4`

**Globals:**
- `DAT_008ac4c4` — interface/manager pointer

**Used by system:** docs/20-math-utilities.md — global interface dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9960 — Short Computation (Virtual Call + Pointer Clear)

Source: unknown | Confidence: high
Calls virtual destructor on a sub-object, then clears the pointer.

**Key logic:**
- If *(param_1 + 0x1c) != 0: calls first virtual method with arg 1, then sets pointer to 0

**Used by system:** docs/20-math-utilities.md — sub-object destruction

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004d0ec0 — Arithmetic/Comparison (Pointer Set + Conditional Re-init)

Source: unknown | Confidence: medium
Sets a pointer and conditionally re-initializes sub-objects.

**Key logic:**
- Sets `*param_1 = param_2`
- If param_1[1] != 0: calls FUN_005506a0(param_2, 0, 0) — re-init sub-object
- If param_1[2] != 0: calls FUN_005506a0(param_2, 0, 0) — re-init another

**Used by system:** docs/20-math-utilities.md — pointer update with re-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d4a30 — Short Computation (SEH Handler Setup)

Source: unknown | Confidence: high
Sets up SEH handler.

**Key logic:**
- Calls FUN_00587b3e(&LAB_004d4a40) — handler registration

**Used by system:** docs/20-math-utilities.md — SEH setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7b00 — Unidentified Logic (3-Way Range Check with Track Data)

Source: unknown | Confidence: low
Performs 3 iterations of range/interval matching against track data arrays to find min/max indices.

**Key logic:**
- Initializes 3 pairs of fields to -1
- For each of 3 iterations (iVar4=0,1,2):
  - Sets range bounds from globals DAT_005ea404, DAT_005ea3f8 array, DAT_005ea3fc array
  - Iterates count from DAT_008acfec over data at DAT_008acff0 (stride 8 per entry)
  - For each entry: checks if track float value falls within the range
  - Tracks min-index and max-index per iteration via -1 sentinel comparison

**Globals:**
- `DAT_005ea3f8`, `DAT_005ea3fc`, `DAT_005ea404` — track reference values
- `DAT_008acfec` — count (not in docs/12)
- `DAT_008acff0` — data array base (not in docs/12)

**Used by system:** docs/20-math-utilities.md — track data interval matching

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d8720 — Utility Function (Multi-Call Wrapper)

Source: unknown | Confidence: high
Calls a sequence of 6 other functions.

**Key logic:**
- Calls FUN_004d8fb0(), then FUN_004d9030(1..5), then FUN_004d8950()

**Used by system:** docs/20-math-utilities.md — batch initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dad50 — Arithmetic/Comparison (Scoring DB Query)

Source: unknown | Confidence: medium
Indexes into SeasonScoringDB using result from a query function.

**Key logic:**
- Calls FUN_004d1b50(0) — returns index
- Calls FUN_004dad30(&DAT_005ec6d8 + index * 0x48c0) — accesses SeasonScoringDB entry

**Globals:**
- `DAT_005ec6d8` — PlayerDataPath / SeasonScoringDB (docs/12)

**Calls:**
- FUN_004d1b50 — unknown
- FUN_004dad30 — unknown

**Used by system:** docs/20-math-utilities.md — season scoring data access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc310 — Short Computation (Delegation Wrapper)

Source: unknown | Confidence: high
Thin wrapper delegating to FUN_00565dc0 (file search init).

**Key logic:**
- Calls FUN_00565dc0() — file search init (docs/08)

**Used by system:** docs/20-math-utilities.md — file search init wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcfb0 — Utility Function (Path Set + Delegation)

Source: unknown | Confidence: medium
Registers a path and delegates to another function with all remaining args.

**Key logic:**
- Calls FUN_00566650(param_1) — path registry / string set
- Delegates to FUN_004dcc90(param_2..param_10)

**Used by system:** docs/20-math-utilities.md — path registration + forward

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004def70 — Unidentified Logic (3D Vector Math with Offset and SQRT)

Source: unknown | Confidence: low
Performs vector subtraction with conditional offset, then computes vector length via SQRT.

**Key logic:**
- Copies param_3 (3 floats) to local variables
- If flag at *(param_1+4)+0x42 set: subtracts offset values from sub-struct at (param_1+4)
- Copies param_4 (3 floats) to local variables (direction vector)
- Computes SQRT of squared length of direction vector
- If length < DAT_0059e440 (ZeroThreshold): calls FUN_004dedb0() — unknown

**Globals:**
- `DAT_0059e440` — ZeroThreshold (docs/12)

**Algorithm family:** 3D vector subtraction + normalization check

**Calls:**
- FUN_004dedb0 — unknown

**Used by system:** docs/20-math-utilities.md — 3D vector processing with offset correction

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f23a0 — Short Computation (Delegation)

Source: unknown | Confidence: high
Thin wrapper calling FUN_004f34e0 (tire init).

**Key logic:**
- Calls FUN_004f34e0() — tire/wheel related init (docs/04)

**Used by system:** docs/20-math-utilities.md — tire initialization wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8330 — Arithmetic/Comparison (Rate Computation with Clamp)

Source: unknown | Confidence: medium
Computes inverse rate from difference of two fields, clamped to zero threshold.

**Key logic:**
- Computes `fVar1 = *(param_1+0x80) - *(param_1+0x84)` — delta
- If delta > DAT_0059e440: stores `_DAT_0059e43c / delta` at +0x88 (1/delta scaling)
- Else: stores 0

**Globals:**
- `DAT_0059e440` — ZeroThreshold (docs/12)
- `_DAT_0059e43c` — physics constant (docs/12, line 49)

**Used by system:** docs/20-math-utilities.md — rate/inverse computation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9150 — Short Computation (Delegation)

Source: unknown | Confidence: high
Thin wrapper calling FUN_0055bfc0.

**Key logic:**
- Calls FUN_0055bfc0() — unknown

**Used by system:** docs/20-math-utilities.md — delegation wrapper

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004ff130 — Unidentified Logic (Two-Point Interpolation)

Source: unknown | Confidence: medium
Two-point linear interpolation between keyframes or control points.

**Key logic:**
- If pointer at +0x38 is null: calls FUN_004ff0e0(), returns
- Compares global _DAT_008afea0 against `*pfVar1` (key 1)
- If key 1 < threshold AND pfVar1[3] (key 2) non-null:
  - If `*pfVar2 > *pfVar1`: computes `fVar4 = (threshold - *pfVar1) / (*pfVar2 - *pfVar1)` — LERP factor
  - Interpolates: `fVar4 * pfVar2[2] + (1-fVar4) * pfVar1[2]`
  - Calls FUN_004feaa0(result)
- If only key 2 qualifies: uses pfVar2[2] directly
- Otherwise: uses pfVar1[2] directly

**Globals:**
- `_DAT_008afea0` — global threshold constant
- `DAT_0059e440`, `_DAT_0059e43c` — physics constants

**Algorithm family:** Two-point LERP with threshold dispatch

**Calls:**
- FUN_004feaa0 — unknown (receives interpolated value)

**Used by system:** docs/20-math-utilities.md — two-point interpolation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00500f55 — Arithmetic/Comparison (Recursive Free)

Source: unknown | Confidence: medium
Frees allocated buffers if corresponding flag pointers are non-null. Recursively frees sub-objects.

**Key logic:**
- If +4 != 0 AND +0x38 != 0: free +4
- If +8 != 0 AND +0x3c != 0: free +8
- If +0x4c != 0: recursively calls FUN_00500f55(), then frees
- If +0x50 != 0: recursively calls FUN_00500f55(), then frees
- Recursive pattern indicates tree/graph structure

**Calls:**
- FUN_00587bcf — free/delete
- Recursive call to self

**Used by system:** docs/20-math-utilities.md — recursive tree/graph deallocation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00507473 — Utility Function (Global Store)

Source: unknown | Confidence: low
Stores a combined value to global DAT_008b009c.

**Key logic:**
- Combines param_1 high 16 bits with FPU control word into local_8
- Stores to `DAT_008b009c`

**Used by system:** docs/20-math-utilities.md — global state write

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b228 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor: calls init function, sets vtable.

**Key logic:**
- Calls FUN_00507496(param_2, 0x10, 1) — unknown
- Vtable: `&PTR_FUN_005adcec`

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b7fb — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor: calls init, sets vtable.

**Key logic:**
- Calls FUN_0050afe2(param_2) — unknown
- Vtable: `&PTR_FUN_005addfc`

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c636 — Short Computation (Dispatch + Indirect Call)

Source: unknown | Confidence: low
Calls function with parameter 1, then jumps through global function pointer.

**Key logic:**
- Calls FUN_0050fea7(1) — unknown
- Jumps via `PTR_FUN_005d7800` — global function pointer

**Used by system:** docs/20-math-utilities.md — dispatch via global pointer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d857 — Thunk to Indirect Call via _DAT_005d7860

Source: unknown | Confidence: low
Thunk that calls through a global function pointer.

**Key logic:**
- Calls `(*_DAT_005d7860)()` — indirect call via global pointer

**Used by system:** docs/20-math-utilities.md — thunk to global function pointer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e7cb — Unidentified Logic (2D Transform with Division)

Source: unknown | Confidence: medium
Performs a 2D affine transform or projection with matrix multiplication and conditional inverse scaling.

**Key logic:**
- Reads multiple float fields from param_2 and param_3
- Computes `fVar6 = param_3[0xf] + param_2[1]*param_3[7] + param_2[0]*param_3[3]` — denominator
- Output[0] = param_3[0xc] + param_2[1]*param_3[4] + param_2[0]*param_3[0]
- Output[1] = param_3[0xd] + param_2[1]*param_3[5] + param_2[0]*param_3[1]
- Calls FUN_0050c042(denominator, 1.0f) — check
- If check passes: divides both outputs by denominator (perspective divide)

**Algorithm family:** 2D affine transform with perspective divide

**Calls:**
- FUN_0050c042 — unknown

**Used by system:** docs/20-math-utilities.md — 2D transform with division

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050ff84 — Unidentified Logic (State Init with Virtual Calls)

Source: unknown | Confidence: low
Initializes state fields, dispatches virtual methods, sets numerous flag/control fields.

**Key logic:**
- Uses register variable unaff_ESI (this pointer)
- Sets timer +0x14 = 0x65 (101) or 0x3c (60) based on flag
- Calls virtual methods at +0x04 and +0x00
- Loop: initializes byte fields around offset +0xda
- Sets various zero/one flags

**Used by system:** docs/20-math-utilities.md — game object state init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051212e — Short Computation (Conditional Field Read)

Source: unknown | Confidence: high
Returns field at offset +0xc if both params non-null.

**Key logic:**
- If param_1 && param_2: returns *(param_2 + 0xc), else 0

**Used by system:** docs/20-math-utilities.md — guarded accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513c80 — Unidentified Logic (Allocation + Zero-Init Optimized)

Source: unknown | Confidence: medium
Allocates memory, zeroes with dword-optimized clear.

**Key logic:**
- `size = param_2 * param_3`
- Calls FUN_00517e92(allocator, size)
- If > 0x8000: clears first 0x8000 bytes quickly, then remainder
- Uses dword-then-byte clear

**Calls:**
- FUN_00517e92 — memory allocator

**Used by system:** docs/20-math-utilities.md — optimized allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00515e85 — Arithmetic/Comparison (State Init + Virtual Dispatch)

Source: unknown | Confidence: low
Initializes sub-object, dispatches virtual methods.

**Key logic:**
- Gets sub-object from param_1[99]; clears bytes, sets code ptr + flag
- Calls virtual at (*param_1 + 0x10)(param_1) and param_1[100](param_1)
- Sets param_1[0x23] = 0

**Used by system:** docs/20-math-utilities.md — state init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00516fb0 — Unidentified Logic (Function Table / VTable Init)

Source: unknown | Confidence: medium
Populates 40+ fields with code addresses (function pointer table).

**Key logic:**
- Assigns param_1[0x00] through [0x36] with jump target addresses (LAB_0051xxxx)
- Pure table initialization

**Used by system:** docs/20-math-utilities.md — vtable/function table init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051935c — Short Computation (Pass-Through param_3)

Source: unknown | Confidence: high
Returns third parameter, ignores first two.

**Key logic:**
- Returns param_3

**Used by system:** docs/20-math-utilities.md — identity for third arg

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051dfcb — Unidentified Logic

Source: unknown | Confidence: low
Short unidentified logic. [8 lines — see raw decompilation]

**Used by system:** docs/20-math-utilities.md — unknown

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00525e9a — Unidentified Logic (124 lines)

Source: unknown | Confidence: low
Larger unidentified function with complex logic. [See raw decompilation]

**Used by system:** docs/20-math-utilities.md — unknown

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052a5a8 — Arithmetic/Comparison (Global Pointer Assign)

Source: unknown | Confidence: high
Assigns 4 global addresses to output parameters.

**Key logic:**
- `*param_1 = DAT_005d9418`
- `*param_2 = DAT_005d941c`
- `*param_3 = &DAT_005d9420`
- `*param_4 = &DAT_005da420`
- Returns 0

**Used by system:** docs/20-math-utilities.md — global pointer retrieval

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e5a0 — Short Computation (Delegation)

Source: unknown | Confidence: high
Thin wrapper to FUN_0052e5d0.

**Used by system:** docs/20-math-utilities.md — delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005355f0 — Arithmetic/Comparison (4-byte Write Loop)

Source: unknown | Confidence: medium
Writes 4 bytes from uint to output, shifting right 8 bits each iteration.

**Key logic:**
- Loop 4 times: calls FUN_00589898(param_2 & 0xff, param_1), shifts param_2 >>= 8

**Used by system:** docs/20-math-utilities.md — byte-by-byte uint output

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053a020 — Unidentified Logic (Compression/Huffman)

Source: unknown | Confidence: low
Large (1194 bytes) algorithm with frequency counting, bit-length arrays, Huffman-style tree construction, and bitstream encoding.

**Key logic:**
- Counts frequencies of symbols (0-15) from input array
- Builds Huffman-style code lengths using iterative bit allocation
- Generates codes and writes packed bitstream to output buffer
- Multiple return codes: 0=success, 0xfffffffb/0xfffffffc/0xfffffffd=errors

**Algorithm family:** Data compression / Huffman coding

**Used by system:** docs/20-math-utilities.md — compression algorithm

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b4a0 — Empty Stub

Source: unknown | Confidence: high
Empty function — body is bare return. 1 byte.

**Used by system:** docs/20-math-utilities.md — placeholder/stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c6b0 — Arithmetic/Comparison (String Copy with Prefix Value)

Source: unknown | Confidence: medium
Copies string from param_2+4 byte region into param_1, prepending first dword of param_2 as header.

**Key logic:**
- If param_2 non-null: copies string from (param_2+4) to param_1 using offset arithmetic, then copies *param_2 as header
- If null: zeroes both bytes of param_1

**Used by system:** docs/20-math-utilities.md — string copy with header

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d430 — Short Computation (Global Bool Set)

Source: unknown | Confidence: high
Sets global DAT_008b8e24 to 0 or 1 based on param_1.

**Key logic:**
- `DAT_008b8e24 = (param_1 != 0)`

**Used by system:** docs/20-math-utilities.md — global flag setter

**Moddability:** hookable

<!-- target: docs/19-renderer.md -->

## FUN_00546200 — Arithmetic/Comparison (Linked List Walk + Call)

Source: unknown | Confidence: medium
Walks a linked list starting from DAT_008b8f28, calling FUN_00557120 per node.

**Key logic:**
- Iterates via next pointer at +0x1e8
- Calls FUN_00557120() for each node
- Returns 0

**Globals:**
- `DAT_008b8f28` — linked list head

**Used by system:** docs/20-math-utilities.md — linked list iteration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547370 — Arithmetic/Comparison (String Copy with Offset)

Source: unknown | Confidence: high
Copies a string to a destination at a fixed offset from source.

**Key logic:**
- If param_2 != 0: copies param_1 to param_1 + (param_2 - param_1) — offset copy
- Copies chars including null terminator

**Used by system:** docs/20-math-utilities.md — string copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00548aa0 — Arithmetic/Comparison (Struct Init)

Source: unknown | Confidence: high
Zeroes 7 fields in a struct.

**Key logic:**
- Calls FUN_0053c2a0() — unknown
- Zeroes [0]-[6]

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054a5b0 — Short Computation (Global Read)

Source: unknown | Confidence: high
Returns global DAT_008b8f3c.

**Key logic:**
- Returns `DAT_008b8f3c`

**Used by system:** docs/20-math-utilities.md — global accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054c290 — Short Computation (SEH Handler)

Source: unknown | Confidence: high
SEH handler registration via FUN_00587b3e.

**Used by system:** docs/20-math-utilities.md — SEH setup

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00556220 � 17-Dword Struct Initializer (Skips Index 1)

Source: unknown | Confidence: high
Calls sub-init then zeroes 17 dwords, skipping index 1.

**Key logic:**
- FUN_0053c2a0() � sub-init
- Zeroes param_1[0] � first dword
- Zeroes param_1[2..0x11] � 15 dwords starting at index 2 (total 17 including index 0)
- Skips param_1[1] � NOT zeroed
- Returns param_1

**Calls:** FUN_0053c2a0 (sub-init)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055bdd0 — Short Computation (Field Getter at +0x11c)

Source: unknown | Confidence: high
Returns value at param_1 + 0x11c.

**Key logic:**
- Returns `*(undefined4 *)(param_1 + 0x11c)`

**Used by system:** docs/20-math-utilities.md — field getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00561e20 — Utility Function (Single Delegation Call)

Source: unknown | Confidence: high
Thin wrapper calling FUN_00561e30.

**Used by system:** docs/20-math-utilities.md — delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00565eb0 — Unidentified Logic (Calls FUN_00565d50, zeros field at *param_1+0x21c)

Source: unknown | Confidence: medium
Calls path set function, then zeros a field.

**Key logic:**
- Calls FUN_00565d50() — unknown
- Sets `*(int *)(*param_1 + 0x21c) = 0`

**Used by system:** docs/20-math-utilities.md — search path init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00568a60 — Utility Function (Weighted Running Checksum over File Stream)

Source: unknown | Confidence: medium
Computes weighted running checksum over a file stream using sequential byte reading.

**Key logic:**
- Opens file via FUN_00587db0(param_1, &DAT_005be828)
- Sets multiplier to 1 if param_2 == 0
- Reads bytes via FUN_00589fcc, accumulates weighted sum: `checksum += byte * multiplier`
- Updates multiplier: `multiplier = (multiplier + 1) % param_2`
- Returns 1 on success, 0 on failure

**Calls:**
- FUN_00587db0 — file open
- FUN_00589fcc — file read byte
- FUN_00587d02 — file close

**Algorithm family:** Checksum / hash computation

**Used by system:** docs/20-math-utilities.md — weighted file checksum

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a800 — Utility Function (Negated Predicate Wrapper)

Source: unknown | Confidence: high
Returns inverse of FUN_00585bf0 return value.

**Key logic:**
- Calls FUN_00585bf0() — trigger/event tick dispatch
- Returns true if result == 0

**Calls:**
- FUN_00585bf0 — trigger/event tick dispatch (docs/01)

**Used by system:** docs/20-math-utilities.md — boolean inversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00582fd0 — Unidentified Logic (MSVC Exception Handler Cleanup)

Source: unknown | Confidence: medium
Walks linked list freeing nodes with SEH protection.

**Key logic:**
- Sets up SEH handler with ExceptionList manipulation
- Walks linked list at *param_1
- For each node: if flag at byte+2 set and *node non-null: calls cleanup then frees
- Frees each node
- Zeroes param_1[0..3]
- Restores ExceptionList

**Calls:**
- FUN_005867b0 — unknown cleanup
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — SEH-protected list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00586a90 — Utility Function (Thunk to FUN_00563e70)

Source: unknown | Confidence: high
Thin wrapper delegating to FUN_00563e70.

**Used by system:** docs/20-math-utilities.md — delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587890 — Utility Function (Stub Returning 0x400)

Source: unknown | Confidence: high
Returns constant 0x400 (1024).

**Key logic:**
- Returns 0x400 — likely a buffer size constant

**Used by system:** docs/20-math-utilities.md — constant getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00589ca4 — Utility Function (Delegation with Fixed Args)

Source: unknown | Confidence: high
Calls FUN_00589cc6(param_1, 0, 0).

**Used by system:** docs/20-math-utilities.md — delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058bf45 — Utility Function (Number-to-String Formatting with Sign/Padding)

Source: unknown | Confidence: high
Formats a number as string with sign handling and zero-padding.

**Key logic:**
- If param_4 (pad flag) set and param_3 length-1 == param_2: appends '0' and null
- If sign bit in param_3: prepends '-'
- If length < 1: writes '0'
- If param_2 > 0: writes decimal separator (DAT_005e6bd8), pads with '0' via _memset

**Calls:**
- FUN_0058c0d0 — string write helper
- _memset — CRT

**Used by system:** docs/20-math-utilities.md — number-to-string formatting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00591d2e — Utility Function (Float Classification: NaN/Inf/Normal/Zero)

Source: unknown | Confidence: high
Classifies a double-precision float (split into high/low ints) into category.

**Key logic:**
- Checks for Inf (0x7ff00000 + 0), Inf negative (0xfff00000 + 0)
- Checks exponent bits for NaN (0x7ff8 pattern)
- Checks for normal/subnormal (0x7ff0 with non-zero mantissa)
- Returns: 1=+Inf, 2=-Inf, 3=NaN, 4=normal, 0=zero

**Algorithm family:** Float classification

**Used by system:** docs/20-math-utilities.md — float classification utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00597371 — Error Exit (Log + Terminate)

Source: unknown | Confidence: high
Logs error code and terminates process.

**Key logic:**
- Calls FUN_005932f3(10) — log code
- Calls FUN_00597388(0x16) — log subcode
- Calls __exit(3) — terminate

**Calls:**
- FUN_005932f3 — unknown
- FUN_00597388 — unknown
- __exit — MSVC CRT

**Used by system:** docs/20-math-utilities.md — fatal error handler

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599475 — MSVC streambuf::_Gninc (Get Pointer Increment)

Source: unknown | Confidence: high
MSVC standard library function: increments stream buffer's get pointer, returns previous position.

**Key logic:**
- Decrements count at this+0x2c
- Returns previous get pointer at this+0x1c, then increments

**Library:** Visual Studio 2003 Release — std::basic_streambuf::_Gninc

**Used by system:** docs/20-math-utilities.md — MSVC CRT streambuf

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059aaa2 — Empty Stub

Source: unknown | Confidence: high
Empty void function — bare return. No-op.

**Used by system:** docs/20-math-utilities.md — no-op placeholder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c5ee — Exception Unwind Handler (Free at +8)

Source: unknown | Confidence: low
SEH unwind handler freeing object at stack offset +8.

**Key logic:**
- Calls FUN_00587bcf(*(unaff_EBP + 8))

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cbe8 — C++ Unwind Helper (Thunk to FUN_005819c0)

Source: unknown | Confidence: high
Thunk to FUN_005819c0 (linked list destroy with vtable destructor).

**Key logic:**
- Calls FUN_005819c0()

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d308 — MSVC Exception Handler Unwind

Source: unknown | Confidence: low
SEH unwind handler calling FUN_00599796 with global DAT_008d4510.

**Key logic:**
- Calls FUN_00599796(*(unaff_EBP - 0x10), &DAT_008d4510)

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

## FUN_00550300 — Struct Field Setter at +0x4c

Source: unknown | Confidence: high
Single-field assign to struct at param_1 + 0x4c (int-sized). Sets field from param_2.

**Key logic:**
- Writes `*(param_1 + 0x4c) = param_2`
- No validation, no other operations

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x4c | unknown | int | Written directly from param_2 |

**Calls:** none

**Used by system:** docs/20-math-utilities.md — Simple setter, likely part of a larger struct init pattern.

**Algorithm family:** data accessor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00556650 — High-Resolution Timer Delta Calculation

Source: unknown | Confidence: high
Computes elapsed time since last sample using a high-resolution timer. Reads two previous samples, gets current time, returns scaled delta.

**Key logic:**
- Reads two previous timer values: `local_8 = param_1[6]` (low part), `local_c = param_1[7]` (high part)
- Calls FUN_005564b0(&local_10, &local_14) to get current QPC-like counter
- Computes elapsed ticks: `(local_10 - local_c) - (local_14 < local_8)` (handles 32-bit wraparound)
- Computes fractional part: `(local_14 - local_8)`
- Returns: `elapsed_seconds = elapsed_ticks * inv_freq + fractional / freq`
  - param_1[2] = inverse of frequency (double, multiplier)
  - param_1[0] = frequency (uint, divisor for fractional part)
- Return type is float10 (80-bit x87 extended precision)

**Struct offsets (param_1 — timer state struct):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Frequency | uint | QPF frequency |
| +0x08 | InvFrequency | double | 1.0 / Frequency (multiplier) |
| +0x18 | PrevLow | uint | Previous counter low part |
| +0x1c | PrevHigh | uint | Previous counter high part (wraparound tracking) |

**Calls:** FUN_005564b0 — reads current QPC counter values

**Used by system:** docs/20-math-utilities.md — Frame timing / game loop delta-T calculation. Same pattern as QueryPerformanceCounter-based timers.

**Algorithm family:** high-resolution timer math

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0055f080 — Struct Zero-Init Constructor (Large)

Source: unknown | Confidence: high
Initializes a struct by calling parent init then zeroing 19 fields. Larger variant of FUN_00553de0.

**Key logic:**
- Calls FUN_0053c2a0 (parent constructor)
- Zeros fields at indices: [0], [1] (byte), [9], [10], [0xb] (byte), [0x13], [0x14], [0x15] (byte), [0x1d], [0x1e], [0x1f], [0x20], [0x25], [0x26], [0x27]
- Byte offsets: 0, 4, 0x24, 0x28, 0x2c, 0x4c, 0x50, 0x54, 0x74, 0x78, 0x7c, 0x80, 0x94, 0x98, 0x9c

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00..+0x9c | various | int/byte | 19 fields zeroed |

**Calls:** FUN_0053c2a0 — parent constructor (math_util)

**Used by system:** docs/20-math-utilities.md — Large struct initialization, likely part of a complex game object.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00568cf0 — High-Resolution Timer Delta (with Update)

Source: unknown | Confidence: high
High-resolution timer delta calculation that also updates the stored timer state. Similar to FUN_00556650 but updates the previous sample after computing delta.

**Key logic:**
- Reads previous values: `local_8 = param_1[8]` (low), `local_c = param_1[9]` (high)
- Calls FUN_00568cb0(&local_10, &local_14) to get current QPC timestamp
- Updates stored state: param_1[8] = local_14, param_1[9] = local_10
- Returns elapsed time using same formula as FUN_00556650:
  `elapsed = elapsed_ticks * inv_freq + fractional_part / freq`

**Struct offsets (param_1 — timer state):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Frequency | uint | QPF frequency |
| +0x08 | InvFrequency | double | 1.0 / Frequency |
| +0x20 | PrevLow | uint | Previous counter low (updated) |
| +0x24 | PrevHigh | uint | Previous counter high (updated) |

**Calls:** FUN_00568cb0 — math_util, QPC timestamp read wrapper (18 lines)

**Used by system:** docs/20-math-utilities.md — Frame timing / delta-T with state update.

**Algorithm family:** high-resolution timer math

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00581ad0 — Close Handle + Destroy Linked List + Free Nodes

Source: resource manager | Confidence: high
Cleans up a resource manager: closes a Win32 handle if flagged, then destroys a singly-linked list freeing all nodes.

**Key logic:**
- If byte at param_1+6 (flag at offset 0x18) is non-zero: calls CloseHandle(param_1[4]), zeros param_1[4]
- Walks linked list starting from *param_1 (head pointer)
- For each node: saves next pointer (puVar2[1]), conditionally frees node data at *puVar2 (if byte at puVar2+2*4 = +8 is non-zero), frees node
- Zeros list head, tail, count, and size fields (param_1[0..3])

**Struct offsets (param_1 — resource list container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Head | int* | Linked list head (zeroed after) |
| +0x04 | Tail | int* | Linked list tail (zeroed) |
| +0x08 | Count | int | Element count (zeroed) |
| +0x0c | Size | int | Element size (zeroed) |
| +0x10 | Handle | HANDLE | Win32 handle (closed if byte+0x18 set) |
| +0x18 | CloseFlag | byte | If non-zero, close handle on cleanup |

**Per-node offsets:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Data | int* | Node payload |
| +0x04 | Next | int* | Next node pointer |
| +0x08 | FreeDataFlag | byte | If non-zero, free *Data before freeing node |

**Calls:** FUN_00587bcf — memory free/deallocation, CloseHandle (Win32)

**Used by system:** docs/20-math-utilities.md — Resource manager destructor pattern.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587b97 — Init CRT Float Conversion Function Pointers

Source: MSVC CRT | Confidence: high
Initializes 6 function pointer globals for MSVC CRT float conversion routines.

**Key logic:**
- Sets PTR_FUN_005e6734 = &LAB_0058bd29 (float-to-string converter)
- Sets PTR_FUN_005e6730 = __cfltcvt (CRT float convert)
- Sets PTR_FUN_005e6738 = __fassign (CRT float assign)
- Sets PTR_FUN_005e673c = FUN_0058bccf (custom float converter)
- Sets PTR_FUN_005e6740 = &LAB_0058bd77 (another float-to-string)
- Sets PTR_FUN_005e6744 = __cfltcvt (CRT float convert)

**Globals:**
- PTR_FUN_005e6730 through PTR_FUN_005e6744 — 6 function pointer globals for float conversion

**Calls:** none (just assigns function pointers)

**Used by system:** docs/20-math-utilities.md — MSVC CRT float conversion function pointer table initialization.

**Algorithm family:** CRT initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599707 — Char-by-Char Backward Scan with Validation

Source: unknown | Confidence: high
Scans a string backward from end, testing each character via a predicate. Returns success (1) if all chars pass before hitting -1, or failure (0) on first rejection.

**Key logic:**
- Initializes: `param_1 = param_1 + param_3` (start at end of buffer)
- If param_3 != 0: iterate backward
  - For each char: call FUN_0059685f(*char, param_2) — test char against character class
  - If result == -1: break (reject char)
  - Decrement param_3 until 0
- If all chars scanned (param_3 == 0): return 1 (success)
- If scan stopped early (param_3 > 0):
  - Loop FUN_00589fcc(param_2) for counter times (cleanup on failure)
  - Return 0 (failure)

**Calls:**
- FUN_0059685f — char classification/test against character class
- FUN_00589fcc — cleanup/reset on failure

**Used by system:** docs/20-math-utilities.md — Backward string validation/scan. Likely used for number parsing or string trimming.

**Algorithm family:** string scanning

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599d52 — Stream Char Reader with Buffer Fill + Getc Fallback

Source: I/O stream | Confidence: high
Reads characters from a buffered stream. Uses an internal buffer first (if available), then falls back to virtual method call (getc-style).

**Key logic:**
- Loop until param_3 chars read or EOF
- If buffer at param_1[7] is non-null and param_1[11] (buffer size >> 1) > 0:
  - Reads up to min(buffer_size, remaining) short values from buffer
  - Advances param_2 (output), accumulates count, decrements remaining
  - Calls FUN_0059a3f3(bytes_read) to update buffer position
- If buffer empty or exhausted: calls virtual method at vtable+0x14 (getc)
  - If returns -1: break (EOF)
  - Otherwise: stores char, increments count

**Struct offsets (param_1 — stream object):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1c | BufferPtr | short** | Internal read buffer (param_1[7]) |
| +0x2c | BufferSize | int | Buffer element count (param_1[0xb]) |

**Calls:**
- FUN_0059a3f3 — buffer position update (advance read pointer)
- Virtual method at vtable+0x14 — getc/read-char (returns -1 on EOF)

**Used by system:** docs/20-math-utilities.md — Buffered I/O stream reader (fread/getc abstraction). Same pattern as MSVC FILE stream.

**Algorithm family:** I/O buffered read

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00405160 — Memory Allocation / String Parsing Router

Source: unknown | Confidence: medium
Routes to three different parsing/handling modes based on param_3 value (0, 1, or 2). Involves multiple buffer/string operations and a sentinel comparison.

**Key logic:**
- Maps param_3 to sVar4: 0→0, 1→1, 2→2 (else →0)
- Calls FUN_00404fe0 (init/clear), FUN_00407e40 (lookup/try get)
- If lookup fails: calls FUN_00405fe0 again, FUN_00407fb0 (check valid), FUN_00408050 (parse fields), eventually FUN_0058c724 (string/format operation)
- If lookup succeeds: reads +0x28 and +0x24 as offsets/counts
- Mode 0: target = param_3 + param_2, sentinel 0
- Mode 1: sentinel 1
- Mode 2: if param_2!=0 returns 0; else calls FUN_0058c724 with sum
- Calls FUN_0058c724 (format/convert function) with computed target and sentinel

**Calls:** FUN_00404fe0, FUN_00407e40, FUN_00407fb0, FUN_00408050, FUN_0058c724

**Used by system:** docs/20-math-utilities.md — String/number parsing dispatcher with mode routing.

**Algorithm family:** string parsing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406230 — Short Computation / Conditional Free

Source: memory manager | Confidence: high
Calls a processing function then conditionally frees param_1 based on param_2 flag.

**Key logic:**
- Calls FUN_00406250() — processing/cleanup
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1) — free memory

**Calls:**
- FUN_00406250 — cleanup/processing function
- FUN_00587bcf — memory free (conditional)

**Used by system:** docs/20-math-utilities.md — Conditional memory cleanup after processing.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004084a0 — Short Computation / Float Global Reader

Source: unknown | Confidence: high
Simple getter that returns the float value at DAT_008afe90.

**Key logic:**
- Returns (float)DAT_008afe90 — frame delta time / global float value

**Globals:**
- `DAT_008afe90` — frame delta time / global collision decay float

**Used by system:** docs/20-math-utilities.md — Float global value accessor.

**Algorithm family:** data accessor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00411a00 — Short Computation / Two-Table Lookup by ID

Source: unknown | Confidence: high
Looks up a ushort value in one of two tables based on param_2 mode. Uses uVar1 as index from FUN_004144c0.

**Key logic:**
- Calls FUN_004144c0() — gets ID/index
- If uVar1 != 0x2693 or 0x2694 (special sentinel values):
  - If uVar1 >= 0 (signed):
    - If param_2 == 0: returns DAT_005bebb0[uVar1] (ushort table A)
    - If param_2 == 1: returns DAT_005bf2f8[uVar1] (ushort table B)
  - Returns 0xFFFFFFFF (-1) if invalid mode
- Returns uVar1 unchanged (for sentinel values)

**Calls:** FUN_004144c0 — ID/index getter

**Used by system:** docs/20-math-utilities.md — Table lookup by index/mode. Returns ushort from one of two lookup tables.

**Algorithm family:** table lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00415060 — Struct Zero-Init (12 Fields)

Source: unknown | Confidence: high
Zero-initializes 12 consecutive 4-byte fields of a struct.

**Key logic:**
- Zeros param_1[0] through param_1[0xb] (offsets 0 through 0x2c)

**Used by system:** docs/20-math-utilities.md — Simple struct initializer.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0041f1e0 — Short Computation / Season State Check

Source: game logic | Confidence: high
Checks season race count and two per-race flags at indexed offsets.

**Key logic:**
- Calls FUN_004c2850() — access season data section
- Calls FUN_004c11d0() — get race count
- If param_1 != 0 and race_count > 1 and both flags at param_1+0x14+index*4 and param_1+0x10+index*4 equal 1: return 1
- Otherwise: return 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10+index*4 | FlagA | int | Per-race flag 1 |
| +0x14+index*4 | FlagB | int | Per-race flag 2 |

**Calls:**
- FUN_004c2850 — season data section access
- FUN_004c11d0 — race count getter

**Used by system:** docs/20-math-utilities.md — Season state query; checks if specific race has both flags set.

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004531a0 — Memory Allocation / Large Struct Initializer

Source: unknown | Confidence: high
Massive struct initializer (~3768 bytes). Zeros multiple memory regions, sets sentinel values, initializes sub-structures.

**Key logic:**
- Sets param_1[2] = 0, param_1[0x9f] = 0x11 (sentinel)
- Zeros 0x32e dwords (0xCB8 bytes) from +3
- Zeros 0x30 dwords (0xC0 bytes) from +0x32f
- Sets param_1[0x382] = 0, param_1[0x41f] = 0x11
- Zeros 0xff dwords (0x3FC bytes) from +0x362
- Sets param_1[0x481] = 0, param_1[0x51e] = 0x11
- Zeros 0xff dwords from +0x461
- Zeros 0x164 dwords (0x590 bytes) from +0x560
- Calls FUN_00452780() 44 times — sub-object constructor
- Initializes 44 pairs of values at +0x8ac (stride 2): each pair = (0, -1)
- Sets final header fields at +0x360, +0x904..+0x908 = 0, +0x90a = 0
- Sets +0x35f = 1 (flag), +0x909 = -2
- Sets +0x560 = param_1 (self-pointer)

**Calls:** FUN_00452780 — sub-object constructor (44×)

**Used by system:** docs/20-math-utilities.md — Large initialization of a complex game object (AI/team/season data block).

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0045b3e0 — Short Computation / Destructor with Conditional Self-Delete

Source: unknown | Confidence: high
Destructor: calls base cleanup, conditionally frees self.

**Key logic:**
- Calls FUN_0045b400() — base cleanup/destructor
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1) — free self

**Calls:** FUN_0045b400, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — C++ destructor with conditional self-delete.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bdf0 — Short Computation / Single Function Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper around FUN_0045b9a0.

**Key logic:**
- Calls FUN_0045b9a0() — no local logic

**Calls:** FUN_0045b9a0 — target function

**Used by system:** docs/20-math-utilities.md — Call dispatch wrapper.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045cf30 — Short Computation / Backslash-to-Underscore Path Sanitizer

Source: file system | Confidence: high
Sanitizes a path string by replacing all backslashes with underscores.

**Key logic:**
- Iterates through param_1 string char by char until null terminator
- Each `\` (0x5C) replaced with `_` (0x5F)
- In-place modification

**Calls:** none

**Used by system:** docs/20-math-utilities.md — Path string sanitization for display/storage.

**Algorithm family:** string transform

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004636e0 — Short Computation / Byte + Int3 Composition

Source: unknown | Confidence: medium
Reads a byte from indirect pointer and combines with shifted value.

**Key logic:**
- Reads *param_1 as pointer, gets byte at +0x20
- Reads uint from *param_1, shifts right 8 bits
- Returns CONCAT31(shifted_value, byte) — combines into uint

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| *(param_1) + 0x20 | FieldByte | byte field read |

**Used by system:** docs/20-math-utilities.md — Struct field composition utility.

**Algorithm family:** bitwise composition

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464990 — Short Computation / Squared Distance Between 3D Points

Source: unknown | Confidence: high
Computes squared Euclidean distance between two 3D positions from different structs.

**Key logic:**
- Reads vehicle pointer from *param_1 (self)
- Reads three floats from self at offsets +0x75, +0x79, +0x7d (position XYZ)
- Reads three floats from param_2 at offsets +0x34e0, +0x34e4, +0x34e8 (target position XYZ)
- Computes squared distance: dx² + dy² + dz²
- Stores as int at param_1[1]

**Struct offsets:**
| Ptr | Offset | Field | Notes |
|-----|--------|-------|-------|
| *param_1 | +0x75/79/7d | SelfPos | 3 floats (XYZ) |
| param_2 | +0x34e0/4/8 | TargetPos | 3 floats (XYZ) |

**Used by system:** docs/20-math-utilities.md — Squared distance computation between two 3D objects.

**Algorithm family:** 3D vector math

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0046d610 — Short Computation / Destructor with Conditional Self-Delete

Source: unknown | Confidence: high
Destructor: calls cleanup, conditionally frees self.

**Key logic:**
- Calls FUN_0046d630() — cleanup
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1)

**Calls:** FUN_0046d630, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — C++ destructor pattern.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00474c70 — Short Computation / VTable Init + Function Call

Source: unknown | Confidence: high
Constructor: sets vtable and calls a setup function.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005a4080 (vtable)
- Calls FUN_0048c0d0() — setup

**Calls:** FUN_0048c0d0 — setup/init

**Used by system:** docs/20-math-utilities.md — C++ constructor.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004766f0 — Short Computation / Object Init with IDs

Source: unknown | Confidence: high
Constructor: calls setup, initializes fields with -1/0 sentinels, stores param.

**Key logic:**
- Calls FUN_0048eaa0() — init
- Sets param_1[99] = -1, [0x62]=0, [0x61]=-1, [0x60]=param_2
- Sets *param_1 = &PTR_LAB_005a44a0 (vtable)

**Calls:** FUN_0048eaa0

**Used by system:** docs/20-math-utilities.md — C++ constructor with ID/state fields.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004797f0 — Short Computation / Object Init with Float Param

Source: unknown | Confidence: high
Constructor: calls init with float parameter, sets vtable.

**Key logic:**
- Calls FUN_00466980(0, 0x3eb33333) — 0x3eb33333 = ~0.35f (float param)
- Sets *param_1 = &PTR_FUN_005a5098 (vtable)

**Calls:** FUN_00466980 — init with float parameter

**Used by system:** docs/20-math-utilities.md — C++ constructor with float configuration.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479db0 — Short Computation / Object Init with Float Param

Source: unknown | Confidence: high
Constructor: calls init with float parameter 1.0f, sets vtable, zeros byte.

**Key logic:**
- Calls FUN_004668e0(0, 0x3f800000) — 0x3f800000 = 1.0f
- Sets *param_1 = &PTR_FUN_005a5d88 (vtable)
- Sets byte at param_1 + 0x41 = 0

**Calls:** FUN_004668e0

**Used by system:** docs/20-math-utilities.md — C++ constructor with float config and flag.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0047c940 — Short Computation / Time Difference

Source: unknown | Confidence: high
Computes difference between two time values.

**Key logic:**
- Calls FUN_004b9ce0(param_1) — get time/score value A
- Calls FUN_004b9cb0() — get time/score value B
- Returns A - B

**Calls:**
- FUN_004b9ce0 — time/score getter with parameter
- FUN_004b9cb0 — time/score getter (global)

**Used by system:** docs/20-math-utilities.md — Time/score delta computation.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004889d0 — Short Computation / Frame Rate Ratio

Source: unknown | Confidence: high
Computes frame-time ratio: elapsed / threshold, capped at 0.

**Key logic:**
- Calls virtual method at +0x20 — get end time
- Calls virtual method at +0x18 — get start time
- If (end - start) > DAT_0059e440 (~0.0f): return param_1[0x38] / (end - start)
- Else: return 0.0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xe0 | param_1[0x38] | Numerator (scalar) |

**Globals:**
- `DAT_0059e440` — zero threshold (~0.0f)

**Used by system:** docs/20-math-utilities.md — Frame time ratio computation (e.g., FPS calculation).

**Algorithm family:** frame timing math

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00494fb0 — Short Computation / Surface/Font Push Wrapper

Source: UI/font | Confidence: high
Wrapper for MAS archive font/surface push with mode 0.

**Key logic:**
- Calls FUN_0053cb20(param_1, param_2, 0, param_3) — push font/surface with mode=0

**Calls:** FUN_0053cb20 — MAS/font surface push

**Used by system:** docs/20-math-utilities.md — Font/surface binding wrapper.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495920 — Short Computation / Single Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper around FUN_00495930.

**Key logic:**
- Calls FUN_00495930() — no local logic

**Calls:** FUN_00495930 — target function

**Used by system:** docs/20-math-utilities.md — Call wrapper.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00498f70 — Short Computation / Struct Field Getter at +0x44

Source: unknown | Confidence: high
Simple field getter returning *(param_1 + 0x44).

**Key logic:**
- Returns *(param_1 + 0x44) (4-byte value)

**Used by system:** docs/20-math-utilities.md — Data field accessor.

**Algorithm family:** data accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499660 — Short Computation / Single Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper around FUN_004b3db0.

**Key logic:**
- Calls FUN_004b3db0() — no local logic

**Calls:** FUN_004b3db0 — target function

**Used by system:** docs/20-math-utilities.md — Call wrapper.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499c10 — Short Computation / Struct Copy with Rotation

Source: unknown | Confidence: high
Copies selected fields from one struct to another, then rotates 13 dwords.

**Key logic:**
- Copies fields from param_3 to param_1: [0], [1], [2], [3], [7], [8]
- Rotates/copies 13 dwords (0xd) from param_1 (starting at [0]) to param_2

**Used by system:** docs/20-math-utilities.md — Struct field copy with rotation; likely a SIMD/vertex data operation.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0049a9c0 — Short Computation / Struct Field Multi-Setter

Source: unknown | Confidence: high
Sets 4 consecutive fields at offsets +4, +8, +0xc, +0x10.

**Key logic:**
- param_1+4 = param_2, param_1+8 = param_3, param_1+0xc = param_4, param_1+0x10 = param_5

**Used by system:** docs/20-math-utilities.md — Struct field bulk setter.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049c8a0 — Short Computation / Format String with Count

Source: game logic/scoring | Confidence: high
Formats a string with a count value from championship scoring.

**Key logic:**
- Calls FUN_004a5700() — championship score threshold search
- If result < 1: format with DAT_005c694c (no-score string)
- Else: format with DAT_005c3280 and the count value

**Calls:**
- FUN_004a5700 — championship score threshold search
- FUN_0058815f — string format (sprintf equivalent)

**Used by system:** docs/20-math-utilities.md — Score/threshold display string formatting.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ec40 — Short Computation / Sound Resource Release

Source: audio | Confidence: high
Releases a sound resource via FUN_005539f0 if non-null.

**Key logic:**
- If *param_1 != 0: calls FUN_005539f0(*param_1) (release sound), zeros *param_1

**Calls:** FUN_005539f0 — release sound resource

**Used by system:** docs/20-math-utilities.md — Sound handle cleanup.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004b2a10 — Short Computation / Bitfield Manipulation

Source: unknown | Confidence: high
Sets/clears bits in a bitfield at offset +0x2c using XOR-with-mask pattern.

**Key logic:**
- Computes mask: (param_2 + 1) << 8 masked with 0xf00
- XORs mask into existing value at param_1 + 0x2c
- Only touches bits 8-11 (0xf00)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2c | Flags | Bitfield (bits 8-11 modified) |

**Used by system:** docs/20-math-utilities.md — Bitwise flag manipulation.

**Algorithm family:** bitwise manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b3ad0 — Short Computation / Linked List Head Init

Source: unknown | Confidence: high
Initializes a doubly-linked list with a sentinel/dummy node pattern.

**Key logic:**
- Sets param_1+1 as both next and prev pointers for the sentinel (at very large offsets 0x1b001-0x1b003)
- Sets *param_1 = 0 (head)
- This looks like a corrupt/large struct initialization — offsets 0x1b001 are ~110KB into struct

**Used by system:** docs/20-math-utilities.md — Linked list or pool initializer with sentinel.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b47a0 — Arithmetic/Comparison / Bitmap Flag Set/Clear

Source: game logic | Confidence: high
Sets or clears a specific bit in a bitmap/flag array. Uses 7-bit alignment within byte array.

**Key logic:**
- If param_4 (bit index) != 0xFF:
  - Computes byte offset: param_3 * 0xd + 1 + param_1 (base + slot * 13 + 1)
  - Computes bit position: param_4 >> 3 (byte within group), and bit within byte
  - If param_2 != 0 (set): sets bit via OR
  - Else (clear): clears bit via AND with complement

**Used by system:** docs/20-math-utilities.md — Bitmap flag set/clear with stride 0xd per slot.

**Algorithm family:** bitwise manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9780 — Arithmetic/Comparison / Memory Allocation with Constructor

Source: game logic | Confidence: high
Allocates a large object (0xf9c bytes) and constructs it.

**Key logic:**
- Calls operator_new(0xf9c) — allocate 3996 bytes
- If successful: calls FUN_004b57f0() — construct/init, stores result in *param_1
- If failed: stores 0 in *param_1

**Calls:** operator_new, FUN_004b57f0

**Used by system:** docs/20-math-utilities.md — Large object allocation and construction.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004bd900 — Memory Allocation / Dynamic Array Push

Source: data structure | Confidence: high
Appends an element to a dynamic/growing array. Reallocates when capacity is exceeded.

**Key logic:**
- If stored count (param_1+0x10) == capacity (param_1+0xc):
  - Computes new_capacity = old_capacity + 8
  - Allocates new array via operator_new(new_capacity * 4)
  - Copies old elements to new array
  - Frees old array via FUN_00587bcf
  - Stores new array pointer
- Appends param_2 at position [count]
- Increments count

**Struct offsets (param_1 — dynamic array):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x0c | Capacity | Current capacity (in elements) |
| +0x10 | Count | Current element count |
| +0x14 | Data | Array data pointer |

**Calls:** operator_new, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — Dynamic array/growing buffer element push.

**Algorithm family:** dynamic array

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004c2c00 — Arithmetic/Comparison / Field Accumulator

Source: unknown | Confidence: high
Adds param_2 to a counter at param_1 + 0x30.

**Key logic:**
- *(param_1 + 0x30) += param_2

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x30 | Accumulator | Accumulator field |

**Used by system:** docs/20-math-utilities.md — Simple field accumulator.

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004d0f00 — Short Computation / Single Field Setter

Source: unknown | Confidence: high
Simple setter: *param_1 = param_2.

**Key logic:**
- Writes param_2 to *param_1

**Used by system:** docs/20-math-utilities.md — Field setter.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d4a50 — Short Computation / Struct Init (0, 4, 0)

Source: unknown | Confidence: high
Initializes 3 fields of a struct.

**Key logic:**
- Sets param_1[0] = 0, param_1[1] = 4, param_1[2] = 0

**Used by system:** docs/20-math-utilities.md — Small struct initializer.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7bf0 — Short Computation / Indexed Array Read

Source: unknown | Confidence: high
Returns element at param_1[param_2].

**Key logic:**
- Returns *(param_1 + param_2 * 4)

**Used by system:** docs/20-math-utilities.md — Array element accessor.

**Algorithm family:** data accessor

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004dae80 — Arithmetic/Comparison / Divisible-by-6 Check

Source: unknown | Confidence: medium
Checks if value is divisible by 6 and positive, returns formatted result.

**Key logic:**
- Reads uVar1 from param_1 + 0x20
- If uVar1 > 0 AND uVar1 % 6 == 0: returns (uVar1/6) with bit 8 set
- Else: returns uVar1 with low byte cleared (& 0xffffff00)

**Used by system:** docs/20-math-utilities.md — Divisible-by-6 check with status encoding.

**Algorithm family:** arithmetic check

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004ff2b0 — Unidentified Logic / Merge Sort on Linked List

Source: utility | Confidence: high
Recursive merge sort on a singly-linked list, sorting by float value at node[0]. Returns sorted list head.

**Key logic:**
- Base cases: empty list or single node returns unchanged
- Finds midpoint by walking half the list length
- Splits list at midpoint (null-terminate first half)
- Recursively sorts both halves
- Merges: compares *node (float value at node[0]), takes smaller, advances
- Tie-breaking: if left <= right, takes left; else takes right
- Returns merged head (always smaller element)

**Algorithm family:** sorting (merge sort)

**Used by system:** docs/20-math-utilities.md — Generic linked list merge sort by float key.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0050c78c — Unidentified Logic / Catmull-Rom Spline Interpolation

Source: math/geometry | Confidence: high
4-point Catmull-Rom spline interpolation for 4-component vectors. Computes weighted blend of 4 control points based on parameter t.

**Key logic:**
- fVar1 = t², fVar2 = t³
- Coefficients: A = 2t³ - 3t² + 1, B = t³ - 2t² + t, C = -2t³ + 3t², D = t³ - t²
- (Uses _DAT_0059e478 as 3.0 and _DAT_0059e43c as 1.0)
- For each of 4 components: result = A*P1 + B*P2 + C*P3 + D*P4

**Globals:**
- `DAT_0059e478` — 3.0f coefficient
- `DAT_0059e43c` — 1.0f coefficient

**Algorithm family:** spline interpolation

**Used by system:** docs/20-math-utilities.md — Spline interpolation for animation/camera paths.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0050e84b — Arithmetic/Comparison / 2x2 Matrix Multiply

Source: math | Confidence: high
Computes a partial 2x2 matrix multiplication: two components of output from 2D input vectors.

**Key logic:**
- result[0] = input[0]*mat[0] + input[1]*mat[4] (dot product row 0)
- result[1] = input[1]*mat[1] + input[0]*mat[5] (cross/dot row 1)
- Reads mat[0], mat[1], mat[4], mat[5] from param_3 (stride 1)
- Reads input[0], input[1] from param_2

**Algorithm family:** matrix math

**Used by system:** docs/20-math-utilities.md — 2D vector transform / matrix multiply.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00512144 — Short Computation / Conditional Field Reader

Source: unknown | Confidence: high
Reads a byte field from param_2+0x1d if both params are non-null.

**Key logic:**
- If param_1 != 0 AND param_2 != 0: returns *(param_2 + 0x1d)
- Else: returns 0

**Used by system:** docs/20-math-utilities.md — Conditional field accessor.

**Algorithm family:** data accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513d2f — Short Computation / Zero-Init 16 Dwords

Source: unknown | Confidence: high
Zero-initializes 16 consecutive dwords (64 bytes) at param_2.

**Key logic:**
- Loop: 16 iterations, zeros each dword, increments param_2

**Used by system:** docs/20-math-utilities.md — Small buffer zero-initializer.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_005262c2 — Unidentified Logic / SSE/3DNow! Vector Normalize

Source: math/3DNow | Confidence: high
3DNow!-accelerated 2-component vector normalization using packed SIMD instructions.

**Key logic:**
- Uses PackedFloatingMUL, PackedFloatingADD, PackedFloatingAccumulate
- Computes length²: x² + y²
- Approximates 1/sqrt via PackedFloatingReciprocalSQRAprox
- Two Newton-Raphson refinement iterations
- Compares against threshold _PTR_DAT_005af970
- Returns normalized components masked with comparison result

**Algorithm family:** SIMD vector math (3DNow!/SSE)

**Used by system:** docs/20-math-utilities.md — SIMD vector normalization.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052a5d7 — Unidentified Logic / Ring Buffer Read with Callback

Source: I/O/stream | Confidence: high
Ring/circular buffer read operation. Reads data from a buffer with wraparound handling and optional callback for each block.

**Key logic:**
- Reads buffer positions from param_1+0x30 (read), param_1+0x34 (end), param_1+0x2c (wrap limit)
- Computes available space: min(end - read, capacity in param_2+0x10)
- If param_3 == -5 (special mode): sets param_3 = 0
- Updates param_2+0x14 (total read) and param_2+0x10 (remaining)
- If callback at param_1+0x38 non-null: calls it with context and buffer, stores result
- Copies data to dest buffer at param_2+0xc (dword-aligned + byte remainder)
- If read pointer hits wrap limit: wraps to start at param_1+0x28
- Handles second segment after wraparound (same copy logic)
- Updates read pointer and param_2+0xc

**Struct offsets (param_1 — ring buffer):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x28 | BufferStart | Start of buffer (wrap target) |
| +0x2c | BufferEnd | End of buffer (wrap limit) |
| +0x30 | ReadPtr | Current read position |
| +0x34 | EndPtr | Buffer end pointer |
| +0x38 | Callback | Optional callback function |
| +0x3c | CallbackCtx | Callback context |

**Calls:** FUN_00587bcf, callback through param_1+0x38

**Used by system:** docs/20-math-utilities.md — Buffered/circular stream read with wraparound.

**Algorithm family:** ring buffer I/O

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00535620 — Arithmetic/Comparison / Struct Reset + Status Check

Source: unknown | Confidence: high
Resets struct fields and returns status code based on validity checks.

**Key logic:**
- If param_1 != 0 and inner pointer at param_1+0x1c non-null:
  - Zeros param_1+0x14, +8, +0x18
  - Sets *inner_ptr = -(inner_ptr[3] != 0) & 7 (status from flag)
  - Calls FUN_00537000(0) — reset
  - Returns 0
- Returns 0xfffffffe (-2) on invalid

**Calls:** FUN_00537000

**Used by system:** docs/20-math-utilities.md — Object reset/status check.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053a630 — Arithmetic/Comparison / Global Address Getter

Source: data | Confidence: high
Returns four global data addresses.

**Key logic:**
- *param_1 = DAT_005da998
- *param_2 = DAT_005da99c
- *param_3 = &DAT_005da9a0
- *param_4 = &DAT_005db9a0

**Used by system:** docs/20-math-utilities.md — Global data address query.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b4c0 — Unidentified Logic / 3x3 Rotation Matrix from Quaternion

Source: math | Confidence: high
Computes a 3x3 rotation matrix from a quaternion (w, x, y, z).

**Key logic:**
- Uses quaternion components: param_1[0..3] (w, x, y, z)
- Computes 9 elements of 3x3 rotation matrix (row-major) at param_2:
  - [0] = 1 - 2(y² + z²)
  - [1] = 2(xy - zw), [2] = 2(xz + yw)
  - [4] = 2(xy + zw), [5] = 1 - 2(x² + z²), [6] = 2(yz - xw)
  - [8] = 2(xz - yw), [9] = 2(yz + xw), [10] = 1 - 2(x² + y²)
- Uses _DAT_0059e43c (1.0f) for the diagonal

**Globals:**
- `DAT_0059e43c` — 1.0f

**Algorithm family:** quaternion → rotation matrix

**Used by system:** docs/20-math-utilities.md — 3x3 rotation matrix from quaternion.

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0053d450 — Short Computation / Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper around FUN_0055c9c0.

**Key logic:**
- Calls FUN_0055c9c0()

**Calls:** FUN_0055c9c0 — target function

**Used by system:** docs/20-math-utilities.md — Call wrapper.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00546230 — Short Computation / Global Setter Pair

Source: unknown | Confidence: high
Sets two global values from parameters.

**Key logic:**
- DAT_008b8f00 = param_1
- DAT_008b8efc = param_2

**Globals:**
- `DAT_008b8f00` — written from param_1
- `DAT_008b8efc` — written from param_2

**Used by system:** docs/20-math-utilities.md — Global variables setter.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00548e00 — Short Computation / Object Constructor

Source: unknown | Confidence: high
C++ constructor: calls parent init, zeros 3 fields.

**Key logic:**
- Calls FUN_0053c2a0() — parent constructor
- Zeros *param_1, param_1+0x10, param_1+0x14

**Calls:** FUN_0053c2a0 — parent constructor

**Used by system:** docs/20-math-utilities.md — C++ constructor.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054a5c0 — Arithmetic/Comparison / Global Buffer Copy with Advance

Source: data | Confidence: high
Copies data from a global buffer at DAT_008b8f3c to output, then advances the global pointer.

**Key logic:**
- Reads source from DAT_008b8f3c + param_2
- Copies param_3 bytes to param_1 (dword-aligned + byte remainder)
- Advances DAT_008b8f3c by param_3

**Globals:**
- `DAT_008b8f3c` — global data buffer pointer (advances on read)

**Used by system:** docs/20-math-utilities.md — Global buffer sequential read.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054c2d0 — Arithmetic/Comparison / Loop Call 256x

Source: unknown | Confidence: high
Calls FUN_0053b130 exactly 256 times.

**Key logic:**
- Loop: 0x100 (256) iterations, calls FUN_0053b130() each iteration

**Calls:** FUN_0053b130 (256×)

**Used by system:** docs/20-math-utilities.md — Bulk initialization loop.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00556260 — Unidentified Logic / High-Res Timer Setup

Source: timing | Confidence: high
Initializes a high-resolution timer using QueryPerformanceFrequency/Counter. Two modes: QPC init and alternate setup.

**Key logic:**
- If param_2 == 1 (QPC mode):
  - Gets QPF frequency, stores low part in *param_1
  - Gets QPC counter, stores in param_1[6..7]
- If param_2 == 2 (alternate mode):
  - Calls FUN_0055f080() — init struct
  - Calls FUN_0055fbc0() — get time
  - Calls FUN_0055687b() — compute
  - *param_1 = local_78 * 1000000
  - Calls FUN_00557470() — release
- Stores previous samples param_1[8]=[6], [9]=[7]
- Sets param_1[0x12] = param_2 (mode)
- Computes inv_freq: _DAT_005af448 / *param_1
- Zeros param_1[4], [5], [10], [0xb]

**Globals:**
- `DAT_005af448` — constant multiplier

**Calls:** QueryPerformanceFrequency, QueryPerformanceCounter, FUN_0055f080, FUN_0055fbc0, FUN_0055687b, FUN_00557470

**Used by system:** docs/20-math-utilities.md — High-resolution timer initialization (two modes).

**Algorithm family:** timer init

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00561ff0 — Short Computation / Wrapper: Call with 0

Source: unknown | Confidence: high
Wrapper: calls FUN_00562010(param_2, 0), returns 0.

**Key logic:**
- Calls FUN_00562010(param_2, 0) — target with second arg forced to 0
- Returns 0

**Calls:** FUN_00562010

**Used by system:** docs/20-math-utilities.md — Call wrapper with forced parameter.

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00568e30 — Short Computation / Struct Initializer

Source: unknown | Confidence: high
Zeros 4 fields of a struct then calls init function.

**Key logic:**
- Zeros *param_1, param_1[0x8c], [0x8e], [0x90]
- Calls FUN_00568f20() — init

**Calls:** FUN_00568f20 — struct initialization

**Used by system:** docs/20-math-utilities.md — Struct zero-init then setup.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586e50 — Short Computation / Struct Copy Assignment

Source: unknown | Confidence: high
Copy constructor/assignment: copies several fields from source to destination.

**Key logic:**
- *param_1 = *param_2 (first 2 fields)
- param_1[1] = param_2[1]
- FUN_00587620(param_2+2) — copy/deep-copy field block
- FUN_0059b3b0(param_2+5) — copy/deep-copy field block
- param_1[0x13] = param_2[0x13], param_1[0x14] = param_2[0x14]

**Calls:** FUN_00587620, FUN_0059b3b0

**Used by system:** docs/20-math-utilities.md — Struct copy assignment.

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00589d7d — Utility Function / Function Pointer Array Call-All

Source: utility | Confidence: high
Calls every non-null function pointer in a range [param_1, param_2).

**Key logic:**
- Iterates from param_1 to param_2 (exclusive)
- If *current != 0: calls (code*)*current()

**Used by system:** docs/20-math-utilities.md — Batch function pointer invocation.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058bfec — Utility Function / Number-to-String with Truncation

Source: CRT/util | Confidence: high
Converts a number to string with truncation and fallback formatting.

**Key logic:**
- Calls FUN_00595621 to parse number, check sign
- Prepares buffer with optional '-' prefix
- Calls FUN_005955aa to convert to string
- If result out of valid range: use FUN_0058be2e (fallback format)
- Else: if truncation needed, null-terminates; uses FUN_0058bf45

**Calls:** FUN_00595621, FUN_005955aa, FUN_0058be2e, FUN_0058bf45

**Used by system:** docs/20-math-utilities.md — Numeric string formatting with overflow handling.

**Algorithm family:** number formatting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00591e49 — Short Computation / FPU Status Word Read

Source: MSVC CRT | Confidence: high
Reads the x87 FPU status word.

**Key logic:**
- Returns (int)in_FPUStatusWord — FPU status register

**Used by system:** docs/20-math-utilities.md — FPU status query.

**Algorithm family:** FPU control

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00597547 — Overflow-Checked Unsigned Addition

Source: utility | Confidence: high
Performs unsigned addition with overflow detection.

**Key logic:**
- uVar1 = param_1 + param_2
- If overflow (sum < param_1 OR sum < param_2): set uVar2 = 1
- *param_3 = sum
- Returns uVar2 (0 = ok, 1 = overflow)

**Used by system:** docs/20-math-utilities.md — Safe unsigned addition with overflow detection.

**Algorithm family:** arithmetic overflow check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599485 — Unidentified Logic / Pointer Indirection Counter Toggle

Source: unknown | Confidence: medium
Decrements one double-indirect counter and increments another.

**Key logic:**
- **(param_1+0x30) = **(param_1+0x30) - 1
- **(param_1+0x20) = **(param_1+0x20) + 1

**Used by system:** docs/20-math-utilities.md — Double-indirect counter manipulation.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0050b425 — Thunk to FUN_00506ccc

Source: unknown | Confidence: high
Trampoline — unconditional jmp to FUN_00506ccc (duplicate body). Sets vtable pointer and frees sub-object.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005adb80 (vtable pointer assignment)
- Calls FUN_00587bcf(param_1[0x413]) — frees pointer at struct offset +0x104C (0x413 * 4)
- Body identical to FUN_00506ccc at 0x00506ccc

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|-----------|------|-------|
| +0x104C | HeapAllocationPtr | pointer | Freed via FUN_00587bcf (operator delete wrapper) |

**Calls:**
- FUN_00587bcf — operator delete / heap free wrapper

**Used by system:** docs/20-math-utilities.md — object destructor cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00551a30 — Struct Init with Default Scale

Source: unknown | Confidence: high
Initializes 5-field struct with default values, sets field 4 to 1.0f.

**Key logic:**
- Calls FUN_0053c2a0() — shared init
- Sets *param_1 = 0, param_1[1] = 0, param_1[4] = 0x3f800000 (1.0f)

**Calls:** FUN_0053c2a0 — shared init function

**Used by system:** docs/20-math-utilities.md — struct constructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055c3c0 — Get VTable Param Based on Flag Bits

Source: unknown | Confidence: medium
Flag-based vtable dispatch with fallback.

**Key logic:**
- param_2[6] bit 0 → use param_2[2] as vtable object
- param_2[6] bit 1 → use param_2[3]
- Calls vtable+0x20, returns 0xff on success or error from FUN_0055c450

**Calls:** FUN_0055c450 — error/result resolution

**Used by system:** docs/20-math-utilities.md — virtual dispatch with fallback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055fbc0 — Global Data Copy

Source: unknown | Confidence: high
Copies 40 dwords (160 bytes) from DAT_008b8f04 to output buffer.

**Key logic:**
- Loop: 0x28 iterations, copies *puVar2++ to *param_1++

**Globals:**
- DAT_008b8f04 — source data (undocumented)

**Used by system:** docs/20-math-utilities.md — constant data initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00564990 — Array Element Removal with Shift

Source: unknown | Confidence: medium
Removes element from array, shifts remaining elements via memmove.

**Key logic:**
- If param_2 < *param_1 - 1 (not last element):
  - Computes byte count = ((*param_1 - param_2) - 1) * param_1[2] (stride)
  - Calls FUN_005648b0 twice (address computation), then FUN_0058b130 (memmove)
- Decrements *param_1 (count)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| [0] | int | Element count |
| [2] | int | Element stride (bytes) |

**Calls:**
- FUN_005648b0 — address computation (network context)
- FUN_0058b130 — overlap-safe memmove (docs/06)

**Used by system:** docs/20-math-utilities.md — dynamic array management

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0057ab20 — Pointer Check with Fallback

Source: unknown | Confidence: medium
Validates pointer via FUN_0057acb0, returns status or masked value.

**Key logic:**
- uVar1 = FUN_0057acb0(*param_1)
- If 0: *param_1=0, return 1 (failure/success?)
- Else: return uVar1 & 0xffffff00

**Calls:** FUN_0057acb0 — pointer validation

**Used by system:** docs/20-math-utilities.md — pointer safety check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057bcc0 — Destructor with Flag Cleanup

Source: unknown | Confidence: high
Calls destructor logic, conditionally frees memory.

**Key logic:**
- FUN_0057bce0() — actual destructor
- If (param_2 & 1): FUN_00587bcf(param_1) — free memory

**Calls:**
- FUN_0057bce0 — object destructor logic
- FUN_00587bcf — operator delete wrapper

**Used by system:** docs/20-math-utilities.md — COM-like destructor pattern

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_005867b0 — SEH-Guarded Function with Exception Handling

Source: unknown | Confidence: medium
SEH wrapper preserving register state.

**Key logic:**
- SEH setup with exception handler at LAB_0059cbc8
- Calls FUN_0059b390() and FUN_00499ae0()
- SEH teardown

**Calls:**
- FUN_0059b390 — unknown
- FUN_00499ae0 — unknown

**Used by system:** docs/20-math-utilities.md — exception-safe call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587250 — Add Constant Wrapper

Source: unknown | Confidence: high
Returns FUN_0053d880() + 0xb.

**Key logic:**
- return FUN_0053d880() + 0xb

**Calls:** FUN_0053d880 — returns base value

**Algorithm family:** math_util — arithmetic wrapper

**Used by system:** docs/20-math-utilities.md — accessor with offset

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005894a0 — Float Function Pass-Through

Source: unknown | Confidence: medium
Chains two function calls and returns result.

**Key logic:**
- Calls FUN_0058dd28() then FUN_005894bd()

**Calls:**
- FUN_0058dd28 — unknown
- FUN_005894bd — unknown

**Used by system:** docs/20-math-utilities.md — delegation wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058ff0d — Binary Search in 8-Byte Record Array

Source: unknown | Confidence: high
Binary search over sorted array of 8-byte records, matching first 4 bytes.

**Key logic:**
- Standard binary search: lo=0, hi=count-1
- Midpoint computed, compares param_2 against *(int*)(array + mid*8)
- If match: sets *param_3 = *(int*)(array + mid*8 + 4), returns 1
- If no match: returns 0

**Algorithm family:** math_util — binary search

**Used by system:** docs/20-math-utilities.md — lookup in 8-byte key-value table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00595f82 — File Pointer Seek with Error Handling

Source: unknown | Confidence: high
Seeks file pointer, handles errors via callback.

**Key logic:**
- Calls FUN_00595d60 (seek operation)
- On failure (return != 0): calls FUN_00595d50 (error handler)
- Returns result

**Calls:**
- FUN_00595d60 — file seek operation
- FUN_00595d50 — error handling callback

**Used by system:** docs/20-math-utilities.md — safe file I/O wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598e39 — Destroy Locale Object, Free Resources, Call Dtor

Source: unknown | Confidence: medium
Conditional resource cleanup based on locale flags.

**Key logic:**
- Conditional branch: if flag bit 1 set → calls cleanup path
- Calls FUN_00598d31() for locale object cleanup
- Calls FUN_00587bcf to free locale object
- Calls FUN_00598c61() for finalization
- Clears struct fields

**Calls:**
- FUN_00598d31 — locale cleanup
- FUN_00587bcf — free
- FUN_00598c61 — finalization

**Used by system:** docs/20-math-utilities.md — locale/resource manager destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059A854 � Constructor with VTable Set

Source: unknown | Confidence: high
Calls parent init with param_2, sets vtable.

**Key logic:**
- FUN_0059a781(param_2) � parent initialization
- Sets vtable: *param_1 = &PTR_LAB_005b9ce4
- Returns param_1

**Note:** Vtable address is PTR_LAB_005b9ce4, not PTR_FUN_005b7e34 as previously documented.

**Calls:** FUN_0059a781 (parent init)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404790 — short computation

Source: unknown | Confidence: medium
Loop calling FUN_004fb5d0.

**Key logic:**
- Loop with count from param
- Each iteration calls FUN_004fb5d0

**Calls:** FUN_004fb5d0

**Used by system:** docs/20-math-utilities.md — batch computation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004053e0 — short computation

Source: unknown | Confidence: medium
Initializer: sets struct fields, makes 3 sub-calls.

**Key logic:**
- Sets multiple struct fields on param_1
- Calls 3 sub-functions sequentially

**Used by system:** docs/20-math-utilities.md — struct initializer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406250 — short computation

Source: unknown | Confidence: medium
Destructor: CloseHandle + cleanup loop.

**Key logic:**
- Calls CloseHandle() on handle at param_1+0x34
- Iterates and frees sub-resources in loop

**Calls:** CloseHandle (Win32 API)

**Used by system:** docs/20-math-utilities.md — resource destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00407e10 — short computation

Source: unknown | Confidence: medium
Reads 3 values from struct offsets +0x94, +0x98, +0x9c.

**Key logic:**
- Returns values from *(param_1+0x94), *(param_1+0x98), *(param_1+0x9c)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x94 | undefined4 | Value A |
| +0x98 | undefined4 | Value B |
| +0x9c | undefined4 | Value C |

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004084b0 — short computation

Source: unknown | Confidence: medium
Constructor: zero-init + vtable assignment.

**Key logic:**
- Zero-initializes struct
- *param_1 = &PTR_FUN_005b928c (vtable)

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040b6f0 — short computation

Source: unknown | Confidence: medium
Bounds-checked index setter with virtual call.

**Key logic:**
- Validates param_3 < *(param_1 + idx_offset)
- Sets value at computed offset
- Calls vtable method on completion

**Used by system:** docs/20-math-utilities.md — indexed setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d410 — short computation

Source: unknown | Confidence: medium
Conditional function call.

**Key logic:**
- Conditionally calls FUN_00408450() based on flag

**Calls:** FUN_00408450

**Used by system:** docs/20-math-utilities.md — conditional helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e860 — short computation

Source: unknown | Confidence: high
Sets 3 struct fields.

**Key logic:**
- Sets *(param_1+0x68) = param_2
- Sets *(param_1+0x6c) = param_3
- Sets *(param_1+0x70) = param_4

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040fda0 — short computation

Source: unknown | Confidence: medium
Conditional delete of sub-object.

**Key logic:**
- Checks if *(param_1+offset) non-null
- If non-null: calls vtable destructor + free

**Used by system:** docs/20-math-utilities.md — conditional destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00411a50 — short computation

Source: unknown | Confidence: medium
Multi-range switch/map.

**Key logic:**
- Switch/case tree covering multiple ranges
- Dispatches based on param_2 value ranges

**Used by system:** docs/20-math-utilities.md — range-to-value mapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00415090 — short computation

Source: unknown | Confidence: medium
Chain of 3 fallback checks.

**Key logic:**
- Tests 3 conditions sequentially
- Returns first true value found, or default

**Used by system:** docs/20-math-utilities.md — fallback chain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418cf0 — short computation

Source: unknown | Confidence: medium
Destructor: frees children then self.

**Key logic:**
- Iterates child list, calls destructor on each
- Frees self memory

**Calls:** FUN_00587bcf (operator delete)

**Used by system:** docs/20-math-utilities.md — tree node destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041fb10 — Memory Allocation (unidentified)

Source: unknown | Confidence: medium
Multiplayer session type detection.

**Key logic:**
- Checks globals for session type flags
- Branches based on multiplayer vs single-player
- Executes different allocation paths

**Globals:**
- DAT_007c56a4 (SessionType) — likely referenced

**Used by system:** docs/20-math-utilities.md — session setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004219d0 — short computation

Source: unknown | Confidence: medium
Calls FUN_00421890 + FUN_00566650.

**Key logic:**
- FUN_00421890() — unknown
- FUN_00566650() — string copy with realloc

**Calls:**
- FUN_00421890
- FUN_00566650 — string copy utility

**Used by system:** docs/20-math-utilities.md — string/path setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00423db0 — short computation

Source: unknown | Confidence: medium
Math: 2D coordinate frame calculation.

**Key logic:**
- Computes 2D transform coordinates
- Uses multiplication and addition for frame positioning

**Algorithm family:** math_util — 2D coordinate math

**Used by system:** docs/20-math-utilities.md — coordinate transform

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00453370 — Thunk to FUN_004530a0

Source: unknown | Confidence: high
Trampoline to FUN_004530a0.

**Calls:** FUN_004530a0

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00456fb0 — Clamped Float Setter

Source: unknown | Confidence: medium
Sets float field with clamping.

**Key logic:**
- Compares param_2 against min/max bounds
- Clamps value to range
- Stores result at struct offset

**Used by system:** docs/20-math-utilities.md — clamped accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b400 — Destructor with Resource Cleanup

Source: unknown | Confidence: medium
Destructor freeing sub-resources.

**Key logic:**
- Checks and frees multiple sub-objects
- Calls cleanup functions for each resource
- Zeroes freed pointers

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — multi-resource destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045be70 — Thunk

Source: unknown | Confidence: high
Thunk: FUN_00587b3e.

**Calls:** FUN_00587b3e — cleanup dispatcher

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045D240 — Boolean Flag Reset with Side Effects

Source: unknown | Confidence: high
If flag byte at param_1 is non-zero, calls two cleanup functions then clears it. Always returns 1.

**Key logic:**
- If `*param_1 != '\0'`:
  - `FUN_00561f60()` — single function call wrapper (docs/01)
  - `FUN_00561f80()` — socket close and cleanup (docs/21)
  - Sets `*param_1 = '\0'` — reset flag
- Returns 1 always

**Calls:** FUN_00561f60 (call wrapper, docs/01), FUN_00561f80 (socket close, docs/21)

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00461470 — Thunk to FUN_00461480

Source: unknown | Confidence: high
Trampoline to FUN_00461480.

**Calls:** FUN_00461480

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462250 — Texture Creation Wrapper

Source: unknown | Confidence: medium
Creates/manages texture object.

**Key logic:**
- Allocates texture structure
- Initializes texture properties (width, height, format)
- Returns texture handle

**Calls:** operator_new, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — texture resource management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004636f0 — Float Comparison Against Threshold

Source: unknown | Confidence: high
Compares float against DAT_0059e440 (ZeroThreshold).

**Key logic:**
- Compares param_1 against DAT_0059e440 (~0.0f)
- Returns comparison result

**Globals:**
- DAT_0059e440 — ZeroThreshold (~0.0f, physics clamp)

**Algorithm family:** math_util — float threshold check

**Used by system:** docs/20-math-utilities.md — physics zero-comparison utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004649f0 — Bit Flag Setter

Source: unknown | Confidence: high
Sets or clears flag bits on a value.

**Key logic:**
- Applies bitmask operation (AND/OR) to flag field
- Returns updated value

**Used by system:** docs/20-math-utilities.md — flag manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00465c30 — Linked List Pop-Front

Source: unknown | Confidence: medium
Removes and returns first element of linked list.

**Key logic:**
- Reads head pointer from list
- Unlinks head node, updates head to next
- Returns removed node

**Used by system:** docs/20-math-utilities.md — linked list operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004670e0 — Switch on Action ID → Virtual Call

Source: unknown | Confidence: medium
Dispatcher mapping action IDs to virtual method calls.

**Key logic:**
- Switch on action ID (multiple case labels)
- Each case calls specific vtable method
- Handles default case

**Used by system:** docs/20-math-utilities.md — action dispatcher

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a900 — Constructor: Fields + VTable

Source: unknown | Confidence: medium
Object constructor setting fields and vtable.

**Key logic:**
- Sets struct fields to initial values
- *param_1 = &PTR_vtable

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046d630 — VTable Setter + Sub-call

Source: unknown | Confidence: medium
Sets vtable, calls FUN_00487250.

**Key logic:**
- *param_1 = &PTR_vtable
- FUN_00487250() — init

**Calls:** FUN_00487250

**Used by system:** docs/20-math-utilities.md — construction helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046fd30 — Destructor + Conditional Delete

Source: unknown | Confidence: high
Destructor conditionally freeing sub-object.

**Key logic:**
- Checks if sub-object non-null
- If non-null: calls FUN_00587bcf (free)
- Clears pointer

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — simple destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00471650 — Constructor: LED/Indicator Setup

Source: unknown | Confidence: medium
Initializes LED/indicator UI element.

**Key logic:**
- Sets vtable pointer to control class
- Initializes position, size, color fields
- Sets default state

**Algorithm family:** math_util — UI element constructor

**Used by system:** docs/20-math-utilities.md — UI LED/indicator init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473430 — Constructor: Similar UI Element

Source: unknown | Confidence: medium
Initializes UI element (similar pattern to FUN_00471650).

**Key logic:**
- Sets vtable pointer
- Initializes UI fields (position, dimensions)

**Used by system:** docs/20-math-utilities.md — UI element constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00474c80 — Switch: Maps 0x1a2-0x1ac to Bitmask

Source: unknown | Confidence: medium
Maps action IDs to bitmask values.

**Key logic:**
- Switch on param_2 (cases 0x1a2 through 0x1ac)
- Each case returns specific bitmask constant

**Used by system:** docs/20-math-utilities.md — action-to-bitmask mapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00476d70 — UI Render Update Chain

Source: unknown | Confidence: medium
UI element render/update dispatch.

**Key logic:**
- Calls multiple render functions sequentially
- Updates UI state between renders
- Returns render result

**Used by system:** docs/20-math-utilities.md — UI update pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478220 — Monitors Changed Selection

Source: unknown | Confidence: medium
Detects selection changes in UI list.

**Key logic:**
- Compares current selection index against previous
- If changed: triggers update callback
- Returns change status

**Used by system:** docs/20-math-utilities.md — UI selection tracking

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479820 — Constructor: VTable + FUN_00466980

Source: unknown | Confidence: medium
Object constructor calling FUN_00466980.

**Key logic:**
- *param_1 = &PTR_vtable
- FUN_00466980() — sub-init

**Calls:** FUN_00466980

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479e30 — Constructor: VTable + FUN_004668e0

Source: unknown | Confidence: medium
Object constructor calling FUN_004668e0.

**Key logic:**
- *param_1 = &PTR_vtable
- FUN_004668e0() — sub-init

**Calls:** FUN_004668e0

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047aa60 — Empty Stub

Source: unknown | Confidence: high
No-op function. Empty body.

**Key logic:**
- No operations — bare return
- Used as callback placeholder

**Used by system:** docs/20-math-utilities.md — vtable placeholder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047c9d0 — Thunk to FUN_004b9c80

Source: unknown | Confidence: high
Trampoline to FUN_004b9c80.

**Calls:** FUN_004b9c80

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004855a0 — Destructor + Conditional Delete

Source: unknown | Confidence: high
Destructor conditionally freeing memory.

**Key logic:**
- Checks non-null pointer
- Calls FUN_00587bcf (free)
- Clears pointer field

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486010 � Field Initializer with Non-Zero Flag

Source: unknown | Confidence: high
Initializes multiple fields of a struct. Sets byte at +0x65 to 1 (active flag), zeroes all others.

**Key logic:**
- Sets byte at param_1 + 0x65 = 1 � enable/active flag (NOT zeroed � known error was claiming all fields zero)
- Sets byte at param_1 + 0x6c = 0
- Sets byte at param_1 + 100 (0x64) = 0
- Zeroes dwords at offsets: +0x80, +0x84, +0x88, +0x8c, +0x90, +0x94, +0x98, +0x9c, +0xc8, +0xcc, +0xd0, +0xd4, +0xd8, +0xdc

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004868c0 — Scrollbar/Area Rendering

Source: unknown | Confidence: medium
Renders scrollbar or scrollable area.

**Key logic:**
- Computes scrollbar dimensions from viewport
- Draws scrollbar track and thumb
- Handles button rendering at ends

**Algorithm family:** math_util — UI scrollbar render

**Used by system:** docs/20-math-utilities.md — UI scrollbar component

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487740 — Range Check

Source: unknown | Confidence: high
Checks value is in range (1, 4).

**Key logic:**
- Tests 1 < param_2 < 4
- Returns boolean result

**Used by system:** docs/20-math-utilities.md — bounds validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00488b00 — Constructor: Init + VTable

Source: unknown | Confidence: medium
Constructor with init + vtable assignment.

**Key logic:**
- Zero-initializes fields
- *param_1 = &PTR_vtable

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048a3b0 — Byte Setter at +0xe0

Source: unknown | Confidence: high
Sets byte value at struct offset +0xe0.

**Key logic:**
- *(byte*)(param_1 + 0xe0) = (byte)param_2

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048c9e0 — Int Setter at +4

Source: unknown | Confidence: high
Sets int value at struct field [1] (offset +4).

**Key logic:**
- *(int*)(param_1 + 4) = param_2

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d6f0 — Conditional Rendering Call

Source: unknown | Confidence: medium
Conditionally calls render function.

**Key logic:**
- Checks state flag on param_1
- If condition met: calls render function
- Returns status

**Used by system:** docs/20-math-utilities.md — conditional render dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048f300 — State Reset + Conditional Virtual Call

Source: unknown | Confidence: medium
Resets state, conditionally calls virtual method.

**Key logic:**
- Resets struct fields to default
- If condition met: calls vtable method

**Used by system:** docs/20-math-utilities.md — state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490160 — Boolean Flag Setter + Virtual Call

Source: unknown | Confidence: medium
Sets boolean flag, calls virtual method.

**Key logic:**
- Sets flag at *(param_1 + flag_offset) = param_2
- Calls vtable method at offset +0x14

**Used by system:** docs/20-math-utilities.md — state setter with notification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004912f0 — Thunk to FUN_00491330

Source: unknown | Confidence: high
Trampoline to FUN_00491330.

**Calls:** FUN_00491330

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491cf0 — LinkedList: Follow +0x1c Pointer

Source: unknown | Confidence: medium
Walks linked list via +0x1c next pointer.

**Key logic:**
- Iterates nodes following *(node + 0x1c)
- Applies callback to each node

**Used by system:** docs/20-math-utilities.md — linked list traversal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00494fd0 — Thunk to FUN_0053cb90

Source: unknown | Confidence: high
Trampoline to FUN_0053cb90.

**Calls:** FUN_0053cb90

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495930 — Tree Walker: Virtual Call + Recurse

Source: unknown | Confidence: medium
Recursive tree traversal with virtual dispatch.

**Key logic:**
- Calls vtable method on current node
- If method returns true: recurses into children

**Used by system:** docs/20-math-utilities.md — tree traversal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004972b0 — Rectangle Drawing with Pattern

Source: unknown | Confidence: medium
Draws rectangle with fill pattern.

**Key logic:**
- Computes rectangle dimensions from params
- Applies pattern/tiling to fill
- Renders using D3D/texture operations

**Algorithm family:** math_util — rectangle fill render

**Used by system:** docs/20-math-utilities.md — UI rectangle drawing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004985d0 — String Truncation Wrapper

Source: unknown | Confidence: medium
Truncates string to specified length.

**Key logic:**
- Checks string length against max
- If too long: truncates at max position
- Ensures null termination

**Used by system:** docs/20-math-utilities.md — string utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498f80 — Linked List Iteration + Virtual Call

Source: unknown | Confidence: medium
Iterates linked list, calling virtual method per node.

**Key logic:**
- Walks linked list from head
- For each node: calls vtable method

**Used by system:** docs/20-math-utilities.md — linked list processor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499670 — Thunk

Source: unknown | Confidence: high
Thunk: FUN_00587b3e.

**Calls:** FUN_00587b3e — cleanup dispatcher

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499c50 — Constructor: Init with -1 Sentinels

Source: unknown | Confidence: medium
Constructor initializing fields with -1 sentinel values.

**Key logic:**
- Sets multiple fields to -1 (invalid/empty state)
- Sets other fields to 0
- Assigns vtable pointer

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a180 — Zero-Init Int

Source: unknown | Confidence: high
Returns 0.

**Key logic:**
- return 0

**Used by system:** docs/20-math-utilities.md — constant accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a9e0 — Rectangle Edge Offset Calculator

Source: unknown | Confidence: medium
Computes offset from rectangle edge.

**Key logic:**
- Takes edge index and margin params
- Returns offset coordinate for alignment

**Algorithm family:** math_util — rectangle geometry

**Used by system:** docs/20-math-utilities.md — UI layout helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049CFC0 � 5-Slot Collider/Contact Geometry Processor

Source: unknown | Confidence: high
Processes 5 slots indexed 0-4. For each slot, checks if pointer field is non-null, then dereferences +0x54 for buffer size and calls ParamRangeClampedLerp.

**Key logic:**
- Five identical blocks with slot index 0-4:
  - Check *(int *)(param_1 + 0x4c + slot*4) != 0 (pointer per slot)
  - If valid: iVar1 = *(*(param_1 + 0x4c + slot*4) + 0x54) � get count/size from target
  - FUN_0049f530(slot, param_1 + buffer_base, iVar1) � lerp/fill buffer

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x4c | Slot0Ptr | int* | pointer to slot 0 data |
| +0x50 | Slot1Ptr | int* | pointer to slot 1 data |
| +0x54 | Slot2Ptr | int* | pointer to slot 2 data |
| +0x58 | Slot3Ptr | int* | pointer to slot 3 data |
| +0x5c | Slot4Ptr | int* | pointer to slot 4 data |
| +0x60 | Slot0Buffer | byte[] | buffer slot 0 (stride 0x4c) |
| +0xac | Slot1Buffer | byte[] | buffer slot 1 |
| +0xf8 | Slot2Buffer | byte[] | buffer slot 2 |
| +0x144 | Slot3Buffer | byte[] | buffer slot 3 |
| +0x190 (400) | Slot4Buffer | byte[] | buffer slot 4 |

**Calls:** FUN_0049f530 (ParamRangeClampedLerp, docs/17)

**Moddability:** hookable (slot pointers determine behavior)

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ec60 — Sound Resource Cleanup

Source: unknown | Confidence: medium
Cleans up sound resource.

**Key logic:**
- Checks if sound handle non-null
- Calls sound stop/release
- Frees memory

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — audio resource destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0cf0 — Conditional Init Guard

Source: unknown | Confidence: medium
Conditional initialization guard.

**Key logic:**
- Checks init flag
- If not initialized: calls init, sets flag

**Used by system:** docs/20-math-utilities.md — lazy init guard

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1d10 — Linked List Walker

Source: unknown | Confidence: medium
Walks linked list applying operation.

**Key logic:**
- Iterates linked list nodes
- Applies callback or accumulator to each

**Used by system:** docs/20-math-utilities.md — linked list utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a3440 — Flag-Based Loop + Conditional Call

Source: unknown | Confidence: medium
Loops based on flag bits, calls function conditionally.

**Key logic:**
- Tests flag bits in bitmask
- For each set bit: calls corresponding handler

**Used by system:** docs/20-math-utilities.md — flag-driven iterator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a57a0 — Index Decrement with Bounds Wrap

Source: unknown | Confidence: medium
Decrements index wrapping at 0.

**Key logic:**
- Decrements param_1
- If result < 0: wraps to count-1
- Returns wrapped index

**Algorithm family:** math_util — modular decrement

**Used by system:** docs/20-math-utilities.md — circular buffer index

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1375 — Clamped Float-to-Int Conversion

Source: unknown | Confidence: medium
Converts float to int with clamping.

**Key logic:**
- Converts float param to int
- Clamps result to valid range
- Returns clamped int

**Algorithm family:** math_util — type conversion with clamping

**Used by system:** docs/20-math-utilities.md — safe type conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2180 — Thunk to FUN_004b3ad0

Source: unknown | Confidence: high
Trampoline to FUN_004b3ad0.

**Calls:** FUN_004b3ad0

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2a30 — Bitfield Extract

Source: unknown | Confidence: high
Extracts bits from bitfield.

**Key logic:**
- Shifts and masks param_1
- Returns extracted bitfield value

**Algorithm family:** math_util — bitfield extraction

**Used by system:** docs/20-math-utilities.md — bitfield utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b3b40 — Buffer Reset (Linked List Init)

Source: unknown | Confidence: medium
Resets linked list/array buffer.

**Key logic:**
- Sets head/tail to NULL
- Zeroes count fields
- Reinitializes buffer state

**Used by system:** docs/20-math-utilities.md — buffer/container reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4800 — Bitfield Setter

Source: unknown | Confidence: high
Sets bits in bitfield.

**Key logic:**
- Applies mask to target field
- Sets specified bits to 1 or 0

**Algorithm family:** math_util — bitfield manipulation

**Used by system:** docs/20-math-utilities.md — bitfield utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b97d0 — Thunk to FUN_004b7300

Source: unknown | Confidence: high
Trampoline to FUN_004b7300.

**Calls:** FUN_004b7300

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba150 — Conditional State Update

Source: unknown | Confidence: medium
Conditionally updates state field.

**Key logic:**
- Tests condition
- If true: updates state at struct offset

**Used by system:** docs/20-math-utilities.md — state machine helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bac40 — Linked List Node Insertion

Source: unknown | Confidence: medium
Inserts node into sorted linked list.

**Key logic:**
- Allocates new node
- Finds insertion point in list
- Links node at correct position
- Updates count

**Calls:** operator_new — allocation

**Used by system:** docs/20-math-utilities.md — linked list insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb800 — Zero Two Fields

Source: unknown | Confidence: high
Zeroes two struct fields.

**Key logic:**
- Sets *(param_1+a) = 0
- Sets *(param_1+b) = 0

**Used by system:** docs/20-math-utilities.md — field reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bd970 — Array Remove-by-Value (Swap with Last)

Source: unknown | Confidence: medium
Removes element by value, swaps last element into gap.

**Key logic:**
- Searches array for matching value
- If found: swaps with last element
- Decrements count
- Returns found status

**Algorithm family:** math_util — array element removal

**Used by system:** docs/20-math-utilities.md — unordered array removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004C13C0 � Season Points Total Calculator

Source: unknown | Confidence: high
Accumulates total points/score across all races in a season using entity iteration.

**Key logic:**
- If param_1 != 0:
  - count = FUN_004c1370() � active entity counter (docs/06)
  - Loop  ..count (inclusive):
    - Index 0: entry = FUN_004c1390() � root entry (docs/06)
    - Others: entry = FUN_004c13a0(index-1) � entry by index (docs/06)
    - If entry valid:
      - FUN_004c0a20(buffer, 0x20) � scene/entity name lookup (docs/06, 09)
      - FUN_00566810() � validity/state check
      - If valid: accumulate entry + 0x198 (score/points field) into total
- Returns total (or 0 if invalid param)

**Calls:** FUN_004c1370 (active entity counter, docs/06), FUN_004c1390 (root entry getter, docs/06), FUN_004c13a0 (entry by index, docs/06), FUN_004c0a20 (scene name lookup, docs/06/09), FUN_00566810 (validity check, docs/06/09)

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2c10 — Increment Field at +0x34

Source: unknown | Confidence: high
Increments int field at offset +0x34.

**Key logic:**
- *(int*)(param_1 + 0x34)++

**Used by system:** docs/20-math-utilities.md — counter increment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c4bb0 — Linked List Search + Removal

Source: unknown | Confidence: medium
Searches linked list for matching key, removes node.

**Key logic:**
- Iterates list matching key
- Unlinks matching node
- Optionally frees node
- Returns found status

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — linked list search and remove

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8180 — Virtual Call on DAT_008ac4c4

Source: unknown | Confidence: medium
Calls virtual method on global DAT_008ac4c4.

**Key logic:**
- (**(code**)(*(int*)DAT_008ac4c4 + offset))() — vtable call

**Globals:**
- DAT_008ac4c4 — undocumented global object pointer

**Used by system:** docs/20-math-utilities.md — global object dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8d80 — Virtual Call on DAT_008ac4c4

Source: unknown | Confidence: medium
Calls virtual method on global DAT_008ac4c4.

**Key logic:**
- (**(code**)(*(int*)DAT_008ac4c4 + offset))()

**Globals:** DAT_008ac4c4

**Used by system:** docs/20-math-utilities.md — global object dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9b70 — Thunk to FUN_004ce820

Source: unknown | Confidence: high
Trampoline to FUN_004ce820.

**Calls:** FUN_004ce820

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004cdb90 — Constructor: Init Fields

Source: unknown | Confidence: medium
Constructor initializing multiple fields.

**Key logic:**
- Sets vtable pointer
- Initializes fields to defaults (0, -1, etc.)

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d1030 — Loop Over Two Parallel Arrays

Source: unknown | Confidence: medium
Iterates two parallel arrays, applies operation.

**Key logic:**
- Loops over count
- Reads from array A and array B
- Writes result based on both

**Algorithm family:** math_util — array processing

**Used by system:** docs/20-math-utilities.md — parallel array operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5840 — Resource Destroy

Source: unknown | Confidence: high
Destroys resource, frees memory.

**Key logic:**
- Calls resource destructor
- Frees via FUN_00587bcf

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — resource destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7c00 — Array Access at +0xc + index*4

Source: unknown | Confidence: high
Reads int from array at offset.

**Key logic:**
- Returns *(int*)(param_1 + 0xc + param_2 * 4)

**Algorithm family:** math_util — array indexing

**Used by system:** docs/20-math-utilities.md — array accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d8840 — Conditional Index Setter

Source: unknown | Confidence: medium
Conditionally sets indexed value.

**Key logic:**
- Checks bounds or flag
- If valid: sets array[index] = value

**Used by system:** docs/20-math-utilities.md — conditional array setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004db070 — Constructor: VTable + 3 Fields

Source: unknown | Confidence: medium
Constructor setting vtable and 3 fields.

**Key logic:**
- *param_1 = &PTR_vtable
- Sets 3 fields to initial values

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc340 — Alignment/Position Switch

Source: unknown | Confidence: medium
Computes position from alignment mode.

**Key logic:**
- Switch on alignment mode
- Each case computes x/y offset differently

**Algorithm family:** math_util — layout alignment

**Used by system:** docs/20-math-utilities.md — UI alignment utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd010 — Two Field Setters

Source: unknown | Confidence: high
Sets two struct fields.

**Key logic:**
- *(param_1 + offset_a) = param_2
- *(param_1 + offset_b) = param_3

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004df0a0 — Conditional Render Call

Source: unknown | Confidence: medium
Conditionally calls render function.

**Key logic:**
- Checks render flag
- If set: calls render function with params

**Used by system:** docs/20-math-utilities.md — conditional rendering

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e4590 — 4-Field Propagation

Source: unknown | Confidence: medium
Copies 4 fields from one struct to another.

**Key logic:**
- Copies 4 values from source to dest offsets

**Used by system:** docs/20-math-utilities.md — struct copy utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f2430 — Constructor: Zero-Init + Sub-Calls

Source: unknown | Confidence: medium
Constructor zero-initializing and calling sub-inits.

**Key logic:**
- Zeroes large struct region
- Sets vtable pointer
- Calls 2+ sub-init functions

**Used by system:** docs/20-math-utilities.md — complex constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f87c0 — HUD Element Config

Source: unknown | Confidence: medium
Configures HUD element properties.

**Key logic:**
- Reads HUD config values
- Sets position, size, visibility
- Returns config status

**Used by system:** docs/20-math-utilities.md — HUD setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9190 — Conditional Dispatch

Source: unknown | Confidence: medium
Conditionally dispatches to handler.

**Key logic:**
- Tests condition flag
- If true: calls handler function
- If false: calls alternate path

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004fb8e0 — Thunk to FUN_004fc9c0

Source: unknown | Confidence: high
Trampoline to FUN_004fc9c0.

**Calls:** FUN_004fc9c0

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ff3a0 — 3D Hermite/Spline Interpolation

Source: unknown | Confidence: high
Computes 3D Hermite spline interpolation.

**Key logic:**
- Takes 4 control points + parameter t
- Computes Hermite basis functions
- Interpolates position and tangent

**Algorithm family:** math_util — Hermite spline, 3D curve interpolation

**Used by system:** docs/20-math-utilities.md — 3D spline math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00500fca — DDS Texture Format Validation + Decoding

Source: unknown | Confidence: high
Validates and decodes DDS texture data. Large function (468 lines).

**Key logic:**
- Parses DDS header (magic, size, format, flags)
- Validates DX10/DXTn compressed formats
- Decodes pixel data into output buffer
- Handles multiple DXT formats (DXT1/3/5, BC1-7)

**Algorithm family:** math_util — DDS texture decoding

**Used by system:** docs/20-math-utilities.md — texture loading pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00503b94 — 16-bit Texture Blending

Source: unknown | Confidence: medium
Blends 16-bit (565/1555) texture pixels.

**Key logic:**
- Reads source and dest 16-bit pixels
- Blends based on alpha
- Writes result

**Algorithm family:** math_util — pixel blending

**Used by system:** docs/20-math-utilities.md — texture compositing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005076fe — Texture Copy/Realloc

Source: unknown | Confidence: medium
Copies or reallocates texture data.

**Key logic:**
- Allocates new texture buffer if needed
- Copies pixel data from source
- Frees old buffer

**Calls:** operator_new, FUN_00587bcf, FUN_0058b130 (memmove)

**Used by system:** docs/20-math-utilities.md — texture memory management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050B260 � Constructor with D3D Texture Init

Source: unknown | Confidence: high
Calls DirectX texture creation then sets vtable pointer.

**Key logic:**
- FUN_00507496(param_2, 8, 1) � DirectX texture creation with class size 8, count 1 (docs/19)
- Sets vtable: *param_1 = &PTR_FUN_005adcfc
- Returns param_1

**Calls:** FUN_00507496 (DirectX texture creation, docs/19)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b830 — Destructor with Resource Cleanup

Source: unknown | Confidence: medium
Texture destructor cleaning up resources.

**Key logic:**
- Releases texture handles
- Frees pixel data buffer
- Calls FUN_00587bcf to free object

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — texture destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c85d — Proxy Call to PTR_FUN_005d789c

Source: unknown | Confidence: medium
Proxy dispatch through function pointer.

**Key logic:**
- Calls (*PTR_FUN_005d789c)(param_1)

**Globals:**
- PTR_FUN_005d789c — function pointer (undocumented)

**Used by system:** docs/20-math-utilities.md — proxy/callback dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d96d — Proxy Call to PTR_FUN_005d7864

Source: unknown | Confidence: medium
Proxy dispatch through function pointer.

**Key logic:**
- Calls (*PTR_FUN_005d7864)(param_1)

**Globals:**
- PTR_FUN_005d7864 — function pointer (undocumented)

**Used by system:** docs/20-math-utilities.md — proxy/callback dispatch

**Moddability:** hookable

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00510f89 — Stream Read: 2-Byte Token Parser

Source: unknown | Confidence: medium
Parses 2-byte tokens from binary stream.

**Key logic:**
- Reads 2-byte tokens from data stream
- Matches against known token table
- Returns parsed value or error

**Algorithm family:** math_util — binary token parsing

**Used by system:** docs/20-math-utilities.md — binary format parser

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051215a — Guarded Float-to-Double Conversion

Source: unknown | Confidence: high
Converts float to double with guard check.

**Key logic:**
- Checks guard condition
- If valid: converts float param to double
- Returns result

**Algorithm family:** math_util — type conversion

**Used by system:** docs/20-math-utilities.md — safe float conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513d3d — Calloc-Like Allocator

Source: unknown | Confidence: medium
Allocates and zero-initializes memory.

**Key logic:**
- Calls HeapAlloc/operator_new
- Zeroes allocated memory
- Returns pointer

**Calls:** operator_new, memset

**Used by system:** docs/20-math-utilities.md — memory allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00515f23 — Memory Allocator (Buddy/Block Alloc)

Source: unknown | Confidence: medium
Block/buddy memory allocator.

**Key logic:**
- Manages free list of memory blocks
- Allocates block of requested size
- Splits larger blocks if needed
- Coalesces on free

**Algorithm family:** math_util — memory allocation

**Used by system:** docs/20-math-utilities.md — custom heap allocator

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0051e1ef — Combinatorial Permutation Generator

Source: unknown | Confidence: medium
Generates combinatorial permutations.

**Key logic:**
- Implements permutation generation algorithm
- Iterates through all permutations
- Applies callback per permutation

**Algorithm family:** math_util — combinatorial generation

**Used by system:** docs/20-math-utilities.md — combinatorics/optimization

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0052e5d0 — Ptr Setter

Source: unknown | Confidence: high
Sets pointer field.

**Key logic:**
- *(void**)(param_1 + offset) = param_2

**Used by system:** docs/20-math-utilities.md — pointer field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00535660 — Guarded Function Call + Cleanup

Source: unknown | Confidence: medium
Guarded call with cleanup on failure.

**Key logic:**
- Calls function
- If fails: performs cleanup
- Returns status

**Used by system:** docs/20-math-utilities.md — guarded operation

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0053c800 — String Registry (Dedup List)

Source: unknown | Confidence: medium
Registers/deduplicates strings in linked list.

**Key logic:**
- Searches linked list for matching string
- If found: returns existing entry
- If not: allocates new node, copies string, appends

**Calls:** operator_new, strcmp, strcpy

**Used by system:** docs/20-math-utilities.md — string interning/dedup

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00541040 — Draining Loop + Finalizer

Source: unknown | Confidence: medium
Drains a queue/buffer, then finalizes.

**Key logic:**
- Loops while queue not empty
- Processes each item
- Calls finalizer when done

**Used by system:** docs/20-math-utilities.md — queue drain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00543210 — Thunk with Arg Reorder

Source: unknown | Confidence: medium
Thunk reordering arguments.

**Key logic:**
- Calls target function with reordered parameters

**Used by system:** docs/20-math-utilities.md — call stub with arg reorder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00546250 — Constructor: Input/Control Init

Source: unknown | Confidence: medium
Initializes input/control device.

**Key logic:**
- Sets vtable pointer
- Initializes input state fields
- Registers with input manager

**Used by system:** docs/20-math-utilities.md — input device constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005473c0 — Two Counter Increments

Source: unknown | Confidence: high
Increments two int counters.

**Key logic:**
- *(int*)(param_1 + offset_a)++
- *(int*)(param_1 + offset_b)++

**Used by system:** docs/20-math-utilities.md — counter utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00548E20 � Struct Initializer (No VTable)

Source: unknown | Confidence: high
Calls sub-init, zero-initializes 24 dwords, clears additional fields. No vtable assignment.

**Key logic:**
- FUN_0053c2a0() � sub-init
- param_1[4] = 0 � field at +0x10
- *(byte*)(param_1 + 8) = 0 � byte flag
- Zeroes 0x18 dwords starting at param_1 + 0x1c (indices 7..0x1e)
- Individual zeroes at offsets: +0x7c, +0x80, +0x84, +0x18, +0xe8, +0xec, +0xf0, +0xf4, +0xf8, +0xfc
- Returns param_1

**Calls:** FUN_0053c2a0 (sub-init)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054a710 — Two Function Call Chain

Source: unknown | Confidence: medium
Calls FUN_0053b160 + FUN_004b0170.

**Key logic:**
- FUN_0053b160() — unknown
- FUN_004b0170() — unknown

**Calls:**
- FUN_0053b160
- FUN_004b0170

**Used by system:** docs/20-math-utilities.md — call chain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054c2f0 — Thunk

Source: unknown | Confidence: high
Thunk: FUN_00587b3e.

**Calls:** FUN_00587b3e — cleanup dispatcher

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00556700 — Bounds Check Against DAT_008b8e48

Source: unknown | Confidence: medium
Bounds check against audio channel count.

**Key logic:**
- Compares param against DAT_008b8e48 (channel count)
- If within bounds: calls FUN_00556440
- Returns result

**Globals:**
- DAT_008b8e48 — audio channel count

**Calls:** FUN_00556440 — channel operation

**Used by system:** docs/20-math-utilities.md — audio channel bounds check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055BE20 � String Copy + Field Reader (Void)

Source: unknown | Confidence: high
Copies null-terminated string from fixed offset to target buffer. Copies two int fields to output pointers. Void return.

**Key logic:**
- If param_2 != 0 (destination):
  - src = param_1 + 4
  - dest = param_2 - src + param_2 � self-relative copy (or memmove-like)
  - Copies byte-by-byte including null terminator
- If param_3 != NULL: *param_3 = *(param_1 + 0x110) � read field A
- If param_4 != NULL: *param_4 = *(param_1 + 0x114) � read field B
- No return value (void)

**Calls:** none

**Moddability:** hookable

<!-- target: docs/18-physics-dynamics.md -->

## FUN_005622b0 — Byte Swap

Source: unknown | Confidence: high
Swaps byte values at two byte pointers.

**Key logic:**
- temp = *byte_a
- *byte_a = *byte_b
- *byte_b = temp

**Algorithm family:** math_util — byte swap

**Used by system:** docs/20-math-utilities.md — utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00566650 — String Copy with Buffer Realloc

Source: unknown | Confidence: medium
String copy with reallocation if buffer too small.

**Key logic:**
- If dest buffer too small: reallocates
- Copies string via strcpy
- Returns dest

**Calls:** operator_new/realloc, strcpy

**Used by system:** docs/20-math-utilities.md — string management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005692a0 — Quadric/Tensor Math (Double)

Source: unknown | Confidence: medium
Quadric/tensor computation with double precision.

**Key logic:**
- Computes quadric error/tensor values
- Uses double precision arithmetic
- Matrix/vector operations

**Algorithm family:** math_util — quadric math, tensor computation

**Used by system:** docs/20-math-utilities.md — mesh simplification / error metric

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a8e0 — COM VTable Call via +0xc4

Source: unknown | Confidence: medium
COM vtable call returning inverted bool.

**Key logic:**
- Calls vtable method at offset +0xc4
- Returns !result (boolean inversion)

**Used by system:** docs/20-math-utilities.md — COM interface wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00583360 — Linked List Destructor Chain

Source: unknown | Confidence: medium
Destructor for linked list with specialized deallocation.

**Key logic:**
- Iterates linked list
- For each node: calls destructor, frees
- Uses FUN_00587860 for specialized dealloc

**Calls:** FUN_00587860 — specialized deallocation

**Used by system:** docs/20-math-utilities.md — linked list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00586ed0 — Thunk to FUN_00598815

Source: unknown | Confidence: high
Trampoline to FUN_00598815.

**Calls:** FUN_00598815

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587a50 — Thunk to FUN_00598815

Source: unknown | Confidence: high
Trampoline to FUN_00598815.

**Calls:** FUN_00598815

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00589ffd — Lock/Call/Unlock Wrapper

Source: unknown | Confidence: high
Lock, call FUN_0058a0bf, unlock wrapper.

**Key logic:**
- FUN_0058c1b1() — acquire lock
- FUN_0058a0bf() — guarded call
- FUN_0058c203() — release lock

**Calls:**
- FUN_0058c1b1 — lock acquire
- FUN_0058a0bf — guarded operation
- FUN_0058c203 — lock release

**Used by system:** docs/20-math-utilities.md — synchronized call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058c203 — Address-Range Critical Section Leave

Source: unknown | Confidence: high
LeaveCriticalSection or tracked unlock.

**Key logic:**
- Calls LeaveCriticalSection or releases tracked lock
- Returns lock state

**Calls:** LeaveCriticalSection (Win32 API)

**Used by system:** docs/20-math-utilities.md — synchronization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00591e57 — FPU Status Word Read

Source: unknown | Confidence: high
Reads FPU status word.

**Key logic:**
- fnstsw AX (store FPU status to AX)
- Returns status word

**Algorithm family:** math_util — FPU status

**Used by system:** docs/20-math-utilities.md — floating-point exception checking

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005975c6 — 96-Bit Left Shift by 1

Source: unknown | Confidence: high
Left-shifts a 96-bit number (3 x uint32) by 1 bit.

**Key logic:**
- Shifts param_1[2] << 1, carries bit 31 into param_1[1]
- Shifts param_1[1] << 1, carries bit 31 into param_1[0]
- Shifts param_1[0] << 1

**Algorithm family:** math_util — multi-word bit shift

**Used by system:** docs/20-math-utilities.md — 96-bit big integer arithmetic

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059978a — Thunk

Source: unknown | Confidence: high
Thunk: FUN_00587b3e(FUN_00599796).

**Calls:** FUN_00587b3e — cleanup dispatcher

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ad31 — Thunk

Source: unknown | Confidence: high
Thunk: FUN_00587b3e(FUN_0047aa60).

**Calls:** FUN_00587b3e — cleanup dispatcher

**Used by system:** docs/20-math-utilities.md — call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c652 — MSVC Exception Handler Unwind Trampoline

Source: unknown | Confidence: high
SEH unwind trampoline.

**Calls:** FUN_005861e0

**Used by system:** docs/20-math-utilities.md — exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cc93 — MSVC Exception Handler Unwind Trampoline

Source: unknown | Confidence: high
SEH unwind trampoline.

**Calls:** FUN_005861e0

**Used by system:** docs/20-math-utilities.md — exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d384 — MSVC Exception Handler: Conditional Cleanup

Source: unknown | Confidence: high
Conditional SEH cleanup on flag bit 0.

**Key logic:**
- Tests flag bit 0 on exception info
- If set: calls FUN_00598aea() — cleanup

**Calls:** FUN_00598aea — conditional cleanup

**Used by system:** docs/20-math-utilities.md — conditional exception cleanup

**Moddability:** hardcoded

## FUN_0050b82b — Thunk to FUN_00506fd9 (Destructor/Container Cleanup)

Source: unknown | Confidence: medium
Not a simple trampoline — contains SEH-wrapped container cleanup loop. Ghidra labels as thunk to FUN_00506fd9 but body performs object destruction.

**Key logic:**
- SEH handler init via FUN_0058a5d8
- Checks extraout_ECX[0x42f] and extraout_ECX[0x430] for non-null
- Inner loop: iterates elements at extraout_ECX[0x424] to extraout_ECX[0x426] (stride 4), calls FUN_00587bcf (free) on each
- Outer loop: repeats until uVar1 < extraout_ECX[0x428]
- Frees pointers at extraout_ECX[0x42e] and extraout_ECX[0x430]
- Calls FUN_00506ccc (destructor continuation)

**Calls:**
- FUN_0058a5d8 — SEH handler init
- FUN_00587bcf — Free/deallocate (multiple calls)
- FUN_00506ccc — Destructor continuation

**Used by system:** docs/20-math-utilities.md — container cleanup via SEH-guarded destructor pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00551f10 — Object Creation with Rollback on Failure

Source: unknown | Confidence: high
Attempts to create an object, allocates memory, initializes it, and rolls back on failure.

**Key logic:**
- Returns 0xFFFFFFFF on failure, 0 on success
- Allocates 0x14-byte block via operator_new
- If alloc fails, sets *param_1 = 0
- Calls FUN_00551a30 (struct init with default scale) on allocated block
- Calls FUN_00551a50(param_2, param_3, param_4) — if returns 0, cleanup and return 0
- On success: stores result in *param_1
- On failure: calls FUN_00557470 (cleanup), then FUN_00587bcf (free), sets *param_1 = 0

**Calls:**
- operator_new(0x14) — heap allocation
- FUN_00551a30 — Struct init with default scale
- FUN_00551a50 — Secondary initialization (returns 0=fail)
- FUN_00557470 — Cleanup/rollback
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — factory/object creation with transaction rollback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00554260 — Enum-to-Field-Offset Setter

Source: unknown | Confidence: high
Maps an enum value to a struct field offset and writes a value. Returns 1 on change, 0 if unchanged or invalid.

**Key logic:**
- Switch on param_2 (enum 1-6, 0xD, 0xE):
  - case 1: no offset (param_1 unchanged)
  - case 2: param_1 + 1 (int offset)
  - case 3: param_1 + 2
  - case 4: param_1 + 5
  - case 5: param_1 + 6
  - case 6: param_1 + 7
  - case 0xD: param_1 + 3
  - case 0xE: param_1 + 4
  - default: returns 0 (invalid enum)
- If pointer not null and *param_1 != param_3, writes param_3 and returns 1

**Calls:** None

**Used by system:** docs/20-math-utilities.md — generic enum-indexed field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005567a9 — Fixed-Point Division with Sign Handling

Source: unknown | Confidence: high
32-bit fixed-point division with sign management. Handles negative dividend by negation, division, then sign reapplication.

**Key logic:**
- Divides param_3 (32-bit) by param_4 via 64-bit intermediate
- If param_3 < 0: negates, divides, re-negates result
- Uses CONCAT44 shift (param_3 >> 16 | param_3 << 16) for 16:16 fixed-point alignment
- Returns CONCAT44(param_2, result) — high word preserved from param_2

**Calls:** None (pure math)

**Used by system:** docs/20-math-utilities.md — fixed-point math utility

**Algorithm family:** Fixed-point arithmetic

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598fd4 — Char Validation Against Encoding Table with Locale Fallback

Source: unknown | Confidence: medium
Character encoding validation: checks if a byte is valid in the current code page, with locale fallback.

**Key logic:**
- First checks if char is already validated in param_1's cached lookup (via *param_1[0x1c] → *param_1[0xc])
- If cache hit AND matches expected encoding: returns param_2
- Otherwise, tries locale-dependent validation:
  - If param_1+0x38 == 0: calls FUN_0059685f(param_2 & 0xff, param_1+0x50) — direct code page lookup, returns param_2 if found
  - Else: calls FUN_00599534(), FUN_00599707(), FUN_00599348() — locale-based multibyte validation with potential charset conversion
  - On locale match: stores param_1+0x3c into param_1+0x40 (updates cached field)
- If all fail: returns 0xFFFFFFFF (invalid)

**Calls:**
- FUN_0059685f — Code page character lookup
- FUN_00599534 — Locale context setup
- FUN_00599707 — Multibyte/wide char validation
- FUN_00599348 — Char conversion with fallback encoding
- DAT_005b9c38 — Fallback encoding constant

**Used by system:** docs/20-math-utilities.md — text encoding/validation

**Algorithm family:** Character encoding validation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a86c — Object Destructor with Ref Count Decrement

Source: unknown | Confidence: medium
Destructor that decrements a reference count and conditionally cleans up.

**Key logic:**
- SEH handler init via FUN_0058a5d8
- Gets ref count at extraout_ECX[9] (offset +0x24 in int array)
- If count == 0 OR (decrement and result < 1): calls FUN_0059a980() (full cleanup)
- Calls FUN_00598c70() (cleanup)

**Globals:**
- DAT_008d463c — Reference count array (indexed by extraout_ECX[9])

**Calls:**
- FUN_0058a5d8 — SEH handler init
- FUN_0059a980 — Full destructor cleanup
- FUN_00598c70 — Cleanup

**Used by system:** docs/20-math-utilities.md — reference-counted object destructor

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00465c70 — Merge Sort on Linked List (Float Key)

Source: unknown | Confidence: high
Recursive merge sort for a linked list, sorting by float value at (*node+4).

**Key logic:**
- Traverses list to find midpoint (list split)
- Recursively sorts left and right halves
- Merges two sorted lists by comparing *(float*)(*node + 4)
- Returns sorted list head
- Standard merge sort on singly-linked list (node[1] = next pointer)

**Calls:**
- FUN_00465c70 (self — recursive)

**Used by system:** docs/20-math-utilities.md — sorting utility

**Algorithm family:** Merge sort (linked list)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00467260 — Object Constructor with Parameter Setup

Source: unknown | Confidence: medium
Constructs an object with vtable, parameter pointer, and constant fields.

**Key logic:**
- Calls FUN_0048c070(0) — base init
- Sets param_1[0xc9] = param_2 (index)
- Sets vtable to PTR_FUN_0059f4f8
- Sets param_1[200] = &DAT_007c6270 + param_2*0x40 (data table entry at stride 0x40)
- Sets param_1[199] = param_3
- Sets param_1[0xca] = 0xB, [0xcb] = 4
- Sets byte at param_1+0x305 = 0

**Globals:**
- DAT_007c6270 — Data table base (stride 0x40 per entry)

**Calls:**
- FUN_0048c070(0) — Base init

**Used by system:** docs/20-math-utilities.md — object initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a950 — Destructor with Conditional Free

Source: unknown | Confidence: high
Destructor: calls cleanup, optionally frees.

**Key logic:**
- Calls FUN_0046a970() — destructor body
- If param_2 & 1: calls FUN_00587bcf(param_1) (free)
- Returns param_1

**Calls:**
- FUN_0046a970 — Destructor body
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — destructor wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046d680 — Object Constructor with VTable

Source: unknown | Confidence: medium
Constructs an object: calls init, sets vtable pointer.

**Key logic:**
- Calls FUN_00487220(0,0) — base init
- Sets vtable to PTR_FUN_0059fcb8

**Calls:**
- FUN_00487220 — Base init

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046fdc0 — VTable Dispatch with Conditional Creation

Source: unknown | Confidence: medium
Dispatches a creation via vtable, conditionally calls setup function.

**Key logic:**
- Calls FUN_0048fec0() — pre-setup
- Calls FUN_00490160(0) — setup
- Calls vtable at DAT_007cd8c0+0x1c with arg 0xC (12)
- If result non-null: calls FUN_00477280(param_1) — configure

**Globals:**
- DAT_007cd8c0 — Object with vtable at +0x1c

**Calls:**
- FUN_0048fec0 — Pre-setup
- FUN_00490160 — Setup
- (*DAT_007cd8c0+0x1c)(0xC) — VTable creation call
- FUN_00477280 — Post-creation config

**Used by system:** docs/20-math-utilities.md — factory/creation with vtable

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004716d0 — Graphics Constructor with Constants

Source: unknown | Confidence: medium
Constructs a graphics/UI object with vtable and constant field values.

**Key logic:**
- Calls FUN_00466d60(1) — base init
- Sets vtable to PTR_FUN_005a1080
- Sets param_1[199] = &DAT_007ce910 (data source)
- Sets [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0xEF
- Calls FUN_00486f30 twice with globals — register resources
- Calls FUN_004670e0() — finalize

**Globals:**
- DAT_007ce910 — Data source pointer
- PTR_DAT_005be704 — Resource 1
- DAT_005c32c8 — Resource 2

**Calls:**
- FUN_00466d60 — Base init
- FUN_00486f30 — Resource registration (x2)
- FUN_004670e0 — Finalization

**Used by system:** docs/20-math-utilities.md — graphics object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004734a0 — Graphics Constructor (Alternate Config)

Source: unknown | Confidence: medium
Similar to FUN_004716d0 with different vtable, data source, and constants.

**Key logic:**
- Calls FUN_00466d60(1) — base init
- Sets vtable to PTR_FUN_005a2940
- Sets param_1[199] = &DAT_007d00c8 (different data source)
- Sets [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0x110
- Calls FUN_00486f30 twice with same globals

**Globals:**
- DAT_007d00c8 — Data source pointer

**Calls:**
- FUN_00466d60 — Base init
- FUN_00486f30 — Resource registration (x2)

**Used by system:** docs/20-math-utilities.md — graphics object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00474f40 — Object Constructor with VTable and Resource Reg

Source: unknown | Confidence: medium
Constructs an object with vtable and resource registrations.

**Key logic:**
- Calls FUN_0048c070(1) — base init
- Sets vtable to PTR_FUN_005a4200
- Calls FUN_00486f30 twice to register resources

**Calls:**
- FUN_0048c070 — Base init
- FUN_00486f30 — Resource registration (x2)

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00476f90 — Single Function Dispatch

Source: unknown | Confidence: high
Calls FUN_00566650().

**Key logic:**
- Single call to FUN_00566650

**Calls:**
- FUN_00566650 — Target function

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478280 — Object Constructor with VTable

Source: unknown | Confidence: medium
Constructs an object with init, vtable, and initial field value.

**Key logic:**
- Calls FUN_0048fb70() — base init
- Sets vtable to PTR_FUN_005a48c0
- Sets param_1[0x3a] = 0xFFFFFFFF

**Calls:**
- FUN_0048fb70 — Base init

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479850 — Float Constructor with Range Setup

Source: unknown | Confidence: medium
Constructs object with float range parameters.

**Key logic:**
- Calls FUN_00466980(0xBF800000, 0x3F800000) — init with float range (-1.0, 1.0)
- Sets vtable to PTR_FUN_005a5208

**Calls:**
- FUN_00466980 — Float range init

**Used by system:** docs/20-math-utilities.md — float range object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479e50 — Destructor with VTable Reset

Source: unknown | Confidence: high
Destructor: resets vtable, calls cleanup, optionally frees.

**Key logic:**
- Sets vtable to PTR_FUN_005a5e40
- Calls FUN_0048d3e0() — cleanup
- If param_2 & 1: calls FUN_00587bcf(param_1)

**Calls:**
- FUN_0048d3e0 — Cleanup
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — destructor with vtable reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047aa80 — Destructor with VTable Reset

Source: unknown | Confidence: high
Destructor: resets vtable, calls cleanup, optionally frees.

**Key logic:**
- Sets vtable to PTR_FUN_005a66e0
- Calls FUN_00485eb0() — cleanup
- If param_2 & 1: calls FUN_00587bcf(param_1)

**Calls:**
- FUN_00485eb0 — Cleanup
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — destructor with vtable reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047ca30 — Timer-Based Float Dispatch

Source: unknown | Confidence: medium
Reads a value via FUN_004889d0(), passes it as float to FUN_0047c960().

**Key logic:**
- fVar1 = FUN_004889d0() (returns float80)
- FUN_0047c960((float)fVar1) — casts to float32 and dispatches

**Calls:**
- FUN_004889d0 — Value generator (timer/etc.)
- FUN_0047c960 — Float consumer

**Used by system:** docs/20-math-utilities.md — float pass-through dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004855d0 — Destructor with VTable Reset

Source: unknown | Confidence: high
Destructor: resets vtable, calls cleanup, optionally frees.

**Key logic:**
- Sets vtable to PTR_FUN_005ab1e0
- Calls FUN_00487250() — cleanup
- If param_2 & 1: calls FUN_00587bcf(param_1)

**Calls:**
- FUN_00487250 — Cleanup
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — destructor with vtable reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486080 — Multi-List Destructor with Cleanup

Source: unknown | Confidence: high
Destroys four linked lists and an object array with cleanup calls.

**Key logic:**
- Iterates 4 linked lists (param_1+0xCC, +0xD0, +0xD4, +0xD8): for each node, calls FUN_0049a5a0(), then frees node, follows +0x18 next pointer
- Iterates object list at param_1+0x90: calls FUN_00486320() for each, dispatches vtable destructor, frees
- Iterates resource list at param_1+0x54: frees inner/outer pointers, then frees node
- Zeroes param_1+0x54, +0x58, +0x5C, +0x60

**Calls:**
- FUN_0049a5a0 — Per-node cleanup (x4 per node)
- FUN_00587bcf — Free/deallocate (many calls)
- FUN_00486320 — Object list iteration helper

**Used by system:** docs/20-math-utilities.md — multi-list cleanup destructor

**Moddability:** hardcoded

Source: unknown | Confidence: medium
Iterates param_1+0x130 times calling FUN_004fb2e0().

**Key logic:**
- Count stored at param_1+0x130
- Loop: 0..count, calls FUN_004fb2e0() each iteration
- No per-element index passed — batch operation

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x130 | ElementCount | int | Number of iterations |

**Calls:**
- FUN_004fb2e0 — Element update function

**Used by system:** docs/20-math-utilities.md — element iteration loop

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00405410 — Multi-Stage Cleanup with Free

Source: unknown | Confidence: medium
Three-function cleanup sequence followed by conditional free.

**Key logic:**
- Calls FUN_004054a0() (first cleanup)
- Calls FUN_004d4860() (second cleanup)
- Calls thunk_FUN_0052d990() (third cleanup)
- If param_1+4 != 0: calls FUN_00587bcf (free)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x4 | FreePtr | int | Pointer freed if non-null |

**Calls:**
- FUN_004054a0 — Cleanup step 1
- FUN_004d4860 — Cleanup step 2
- thunk_FUN_0052d990 — Cleanup step 3
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — destructor/cleanup sequence

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406640 — Conditional Match Trigger

Source: unknown | Confidence: medium
Checks if a field matches a value, triggers action if so.

**Key logic:**
- If param_1+0xc == param_2: calls FUN_00406700()
- Simple compare-and-act pattern

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0C | MatchField | int | Compared against param_2 |

**Calls:**
- FUN_00406700 — Action on match

**Used by system:** docs/20-math-utilities.md — conditional trigger

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00407ef0 — Bitfield Extract from Struct

Source: unknown | Confidence: high
Extracts a 2-bit value from a byte field using bit shift and mask.

**Key logic:**
- Reads byte at param_1+0x1b
- Shifts right 4, AND with 2
- Returns (byte >> 4) & 2 — extracts bit 5 of the byte

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1B | FlagField | byte | Bit flags |

**Calls:** None

**Used by system:** docs/20-math-utilities.md — bitfield extraction utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408500 — Conditional Free by Flag

Source: unknown | Confidence: high
Calls cleanup, then conditionally frees based on param_2 bit 0.

**Key logic:**
- Calls FUN_00408520() (pre-cleanup)
- If param_2 & 1: calls FUN_00587bcf(param_1) (free)
- Returns param_1

**Calls:**
- FUN_00408520 — Pre-cleanup
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — conditional destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040bcd0 — Resource Lookup with Optional VTable Dispatch

Source: unknown | Confidence: medium
Looks up a resource index, validates, then optionally dispatches via vtable.

**Key logic:**
- If param_2 == 0: returns 0
- Calls FUN_0040b6c0(param_2) — lookup resource
- If index >= 0: calls FUN_0040b6f0(index) — validate
- If param_3 (flag) != 0: calls vtable function at *param_1+0x10
- Returns success status

**Calls:**
- FUN_0040b6c0 — Resource lookup by key
- FUN_0040b6f0 — Resource validation
- (*param_1+0x10)() — Vtable dispatch (optional)

**Used by system:** docs/20-math-utilities.md — resource lookup with optional callback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d450 — State Reset on Condition

Source: unknown | Confidence: medium
Resets a state field and triggers a function if value equals 3.

**Key logic:**
- If param_1+0x14 == 3: sets to 0xFFFFFFFF, calls FUN_0040cde0(3, 0)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x14 | StateField | int | Reset to -1 when == 3 |

**Globals:**
- FUN_0040cde0 — State change handler

**Calls:**
- FUN_0040cde0 — State handler

**Used by system:** docs/20-math-utilities.md — state machine transition

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e880 — Struct Field Initializer

Source: unknown | Confidence: high
Sets multiple fields in a struct then calls init function.

**Key logic:**
- param_1+8 = param_2 (short field)
- param_1+0x1c = 7 (constant)
- param_1+0x20 = param_3
- Calls FUN_0040e770() — continued init

**Calls:**
- FUN_0040e770 — Continuation init

**Used by system:** docs/20-math-utilities.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040fdd0 — Array-of-Objects Destructor

Source: unknown | Confidence: high
Destroys an array of objects with vtable reset and cleanup. Supports single or batch mode.

**Key logic:**
- If param_2 & 2 == 0 (single object mode):
  - Sets vtable to PTR_LAB_0059e720
  - Calls thunk_FUN_00568f20() (cleanup)
  - If param_2 & 1: frees param_1
  - Returns param_1
- If param_2 & 2 != 0 (array mode):
  - Reads element count from param_1[-1]
  - Iterates backward: for each element, resets vtable, calls cleanup
  - If param_2 & 1: frees param_1[-1]
  - Returns param_1[-1]
- Element stride: 0xc6 (198 bytes per element)

**Calls:**
- thunk_FUN_00568f20 — Per-element cleanup
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — array destructor with vtable reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00411ab0 — Random Range Table Initializer

Source: unknown | Confidence: medium
Initializes an array of (range, offset) pairs for randomization. Uses _rand() seeded per-index.

**Key logic:**
- First loop: initializes 0x219 (537) entries to (1, 0) — each entry is 2 shorts
- Second loop: for each index not in special excluded ranges (0, 0x218):
  - Calls FUN_004144c0() to get a base offset
  - Reads range from table (DAT_005bebb0 or DAT_005bf2f8 depending on index range)
  - If range > 0: sets entry = (range, rand() % range)
- Excluded indices: 0 and 0x218 are skipped

**Calls:**
- FUN_004144c0 — Random offset generator
- _rand — CRT random function

**Used by system:** docs/20-math-utilities.md — probability/randomization table init

**Algorithm family:** Random number generation table

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00415550 — Linked List Index Scanner with Validation

Source: unknown | Confidence: medium
Scans a linked list to find a valid index based on a test function.

**Key logic:**
- If param_2 == 0: returns -1
- Iterates through indices 0..param_1+0x1c-1
- For each index i: walks linked list at param_1+0x10 by i steps (following +4 pointers)
- Calls FUN_00566810() — test function
- If test returns non-zero: returns current index
- Returns -1 if no valid index found

**Calls:**
- FUN_00566810 — Validation/test function

**Used by system:** docs/20-math-utilities.md — linked list index search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418d60 — Destructor with Double Free Pattern

Source: unknown | Confidence: high
Destroys a struct: frees inner pointer then outer, with flag check.

**Key logic:**
- If param_1[2] (flag byte) non-zero AND *param_1 non-null:
  - If **param_1 != 0: frees *param_1
  - Frees piVar1 (the *param_1 pointer itself)
- If param_2 & 1: frees param_1 (the outer struct)

**Calls:**
- FUN_00587bcf — Free/deallocate (up to 3 calls)

**Used by system:** docs/20-math-utilities.md — multi-level destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041fdb0 — Timing Difference Checker

Source: unknown | Confidence: medium
Calls two functions, compares their returns, returns success if difference > 15.

**Key logic:**
- Calls FUN_0041f340() — init check, returns 0 on fail
- Calls FUN_0041f220() twice — gets two timestamps/counters
- If iVar2 - iVar1 > 15 (0xF): returns success flag
- Returns combined result

**Calls:**
- FUN_0041f340 — Initialization check
- FUN_0041f220 — Timer/counter read (called twice)

**Used by system:** docs/20-math-utilities.md — timing/threshold comparison

**Moddability:** hardcoded (threshold 15)

<!-- target: docs/20-math-utilities.md -->

## FUN_004219f0 — Dual Function Dispatch

Source: unknown | Confidence: high
Calls FUN_00421890(param_1) then FUN_00566650(param_1).

**Key logic:**
- Sequential call with same argument
- Two-step operation chain

**Calls:**
- FUN_00421890 — Step 1
- FUN_00566650 — Step 2

**Used by system:** docs/20-math-utilities.md — call chain wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00424040 — Large Struct Field Setter with Stored Reference

Source: unknown | Confidence: medium
Sets two fields in a struct (including one at very large offset 0x4034) and calls a function.

**Key logic:**
- *param_1 = param_2
- Calls FUN_004e4590(param_2)
- param_1[0x100d] = param_2 — offset +0x4034 (very large, likely array or buffer)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0 | PrimaryField | undefined4 | First copy |
| +0x4034 | SecondaryField | undefined4 | Second copy at array/buffer end |

**Calls:**
- FUN_004e4590 — Post-set operation

**Used by system:** docs/20-math-utilities.md — struct field initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004533a0 — Global State Initializer with Enum Values

Source: unknown | Confidence: medium
Initializes a table of (index, value) pairs using DAT_007d1370 as a conditional flag.

**Key logic:**
- Calls FUN_00453370(index, 2) for indices 0-6 (boot sequence)
- For indices 0x1a-0x21: if DAT_007d1370 == 1, value=2, else value=0
- Multiple hardcoded (index, value) pairs with values 0, 1, or 2
- Total of ~36 pairs initialized

**Globals:**
- DAT_007d1370 — Conditional flag (char, compared to 1)

**Calls:**
- FUN_00453370 — Table entry setter (index, value)

**Used by system:** docs/20-math-utilities.md — global state table initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004579c0 — Empty Stub

Source: unknown | Confidence: high
Empty function — bare return, no operations.

**Key logic:**
- No operations — bare return
- Referenced elsewhere (vtable slot, callback registration)

**Used by system:** docs/20-math-utilities.md — placeholder/stripped method

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b430 — Per-Index Struct Field Resetter

Source: unknown | Confidence: medium
Resets a per-index struct field to defaults with stride 0x5c.

**Key logic:**
- Computes element address: param_1 + param_2*0x5c + 0x3c
- Sets byte at element+0 to 0
- Sets element+0x50 = 0xFFFFFFFF
- Sets element+0x54 = 0xBF800000 (-1.0f as float)
- Sets element+0x58 = 3
- If param_2 == param_1+0x31c: increments param_1+0x31c with mod-8 wrap-around

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x31C | CurrentIndex | uint | Mod-8 counter incremented on match |
| +varies | per-element stride 0x5c | struct | Element at base + idx*0x5c + 0x3c |

**Calls:** None

**Used by system:** docs/20-math-utilities.md — per-element state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bea0 — AVI Stream Cleanup

Source: unknown | Confidence: high
Releases AVI streams and files, frees allocated memory.

**Key logic:**
- Releases two AVI streams (param_1+0x3c, +0x40) via AVIStreamRelease
- Releases AVI file (param_1+0x38) via AVIFileRelease
- Frees custom alloc (param_1+0x44) via FUN_0053cb90
- Frees buffer (param_1+0x50) via FUN_00587bcf
- Calls FUN_0045bf10() — additional cleanup
- Calls AVIFileExit() — VFW library shutdown

**Calls:**
- AVIStreamRelease — Win32 VFW API
- AVIFileRelease — Win32 VFW API
- AVIFileExit — Win32 VFW API
- FUN_0053cb90 — Custom deallocator
- FUN_00587bcf — Free/deallocate
- FUN_0045bf10 — Additional cleanup

**Used by system:** docs/20-math-utilities.md — AVI/replay file cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045d490 — Global Flag-Based State Setter

Source: unknown | Confidence: medium
Checks a global function result and flag, sets state byte accordingly.

**Key logic:**
- Calls FUN_00461dc0() — validation check
- If valid: calls FUN_0045cd70() — action
- If DAT_007d0f94 != 0: sets param_1+1 = 1
- Else: sets param_1+1 = 0

**Globals:**
- DAT_007d0f94 — Global boolean flag

**Calls:**
- FUN_00461dc0 — Validation check
- FUN_0045cd70 — Action function

**Used by system:** docs/20-math-utilities.md — conditional state set based on global flag

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461480 — Struct Field Zero-Init with Defaults

Source: unknown | Confidence: medium
Initializes a struct with specific default values, setting many fields to 0 or 0xFF.

**Key logic:**
- *param_1 = 0
- Various fields set to 0, 0xFF, or 0
- Fields at offsets: +4, +0x24, +0x3C, +0x5C, +0x7C, +0x7D, +0x7E, +0x80, +0x82, +0x84, +0x86, +0x88
- Pattern suggests a UI element or graphics surface struct

**Calls:** None

**Used by system:** docs/20-math-utilities.md — struct default initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462300 — Single Function Dispatch

Source: unknown | Confidence: high
Calls FUN_0057a810().

**Key logic:**
- Single call to FUN_0057a810

**Calls:**
- FUN_0057a810 — Target function

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463710 — String Copy to Struct Field

Source: unknown | Confidence: high
Copies a string into a struct field with length limit.

**Key logic:**
- If param_2 is NULL: sets *param_1+0x1b0 = 0 (clears field)
- Else: _strncpy(*param_1+0x1b0, param_2, 0x1f=31 chars), null-terminates at +0x1cf

**Struct offsets (*param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1B0 | NameBuffer | char[32] | 31 chars + null |
| +0x1CF | NullTerminator | char | Always set to 0 |

**Calls:**
- _strncpy — CRT string copy

**Used by system:** docs/20-math-utilities.md — string field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464a10 — Saturated Byte Add

Source: unknown | Confidence: high
Adds a value to a byte field with saturation at 0x7F (127).

**Key logic:**
- Reads current byte value from *param_1
- Adds param_2 to (bVar1 & 0x7F) — masks high bit
- Caps result at 0x7F (127)
- Writes back: preserves high bit of original, sets lower 7 bits to result
- Saturation arithmetic on 7-bit signed value

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0 | SaturatingField | byte | 7-bit value with sign bit preserved |

**Calls:** None

**Used by system:** docs/20-math-utilities.md — saturated arithmetic utility

**Algorithm family:** Saturated addition

**Moddability:** hardcoded

Source: unknown | Confidence: medium
Scales force/torque values per wheel element using a ratio-based calculation with clamping.

**Key logic:**
- Iterates over elements from unaff_EBX+0x39d4 (per-element force array)
- For each element i (0..iVar1 at unaff_EBX+0x39f8):
  - If i == 8: fVar2 = pfVar3[0x395] / pfVar3[-1] (special case at index 8 boundary)
  - Else: fVar2 = *pfVar3 / pfVar3[-1] (ratio of current/previous)
  - fVar2 = fVar2 * *(unaff_EBX+0x3a0c) * _DAT_005ad198 (global scaling factor)
  - Clamp: if fVar2 < param_3, fVar2 = param_3
  - Stores result: if i < 8, stores at pfVar3[0x11]; else at pfVar3[10]
- Calls FUN_004e6d93() after loop

**Globals:**
- _DAT_005ad198 — Global force scaling multiplier

**Calls:**
- FUN_004e6d93 — Post-loop processing

**Used by system:** docs/18-physics-dynamics.md — force/torque scaling per wheel

**Moddability:** configurable (_DAT_005ad198 global multiplier, param_3 clamp threshold)

Source: unknown | Confidence: high
Frees a pointer only if a flag byte is non-zero.

**Key logic:**
- Checks byte at param_1+2 (index 2 of int array → byte offset +8)
- If non-zero: calls FUN_00587bcf(*param_1) to free
- Conditional free pattern suggests reference counting or ownership flag

**Calls:**
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/01-engine-architecture.md — memory management helper

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00587bdc — CRT __ftol (Float-to-Long)

Source: unknown | Confidence: high
MSVC CRT intrinsic — converts float80 (x87 ST0) to signed 64-bit integer.

**Key logic:**
- Library function: __ftol from Visual Studio CRT
- (longlong)ROUND(in_ST0) — rounds float80 to 64-bit integer

**Calls:** None (CRT intrinsic)

**Used by system:** docs/20-math-utilities.md — MSVC CRT helper

**Algorithm family:** CRT intrinsic — float-to-long conversion

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00596840 — CRT __allshl (64-bit Left Shift)

Source: unknown | Confidence: high
MSVC CRT intrinsic — 64-bit left shift.

**Key logic:**
- Library function: __allshl from Visual Studio CRT
- If shift count > 63: returns 0
- If shift < 32: (hi << shift) | (lo >> (32-shift)), and lo << shift
- If shift >= 32: lo << (shift-32) placed in high 32 bits

**Calls:** None (CRT intrinsic)

**Used by system:** docs/20-math-utilities.md — MSVC CRT helper

**Algorithm family:** CRT intrinsic — 64-bit shift

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00568e60 — Multi-Field Cleanup Destructor

Source: unknown | Confidence: high
Thunk to FUN_00568f20 — cleans up multiple pointer fields in a struct, freeing non-null pointers and zeroing fields.

**Key logic:**
- Frees *param_1 if non-null, sets to 0
- Zeroes param_1[0x89], [0x8a], [0x8b]
- Frees param_1[0x8c] if non-null, sets to 0, sets [0x8d] = 0
- Frees param_1[0x8e] if non-null, sets to 0, sets [0x8f] = 0
- Frees param_1[0x90] if non-null, sets to 0
- Stride 4 (int array indexing) — real offsets: +0x224, +0x228, +0x22C, +0x230, +0x234, +0x238, +0x23C, +0x240

**Calls:**
- FUN_00587bcf — Free/deallocate (multiple calls)

**Used by system:** docs/20-math-utilities.md — struct cleanup destructor

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004869e0 — Multi-Region Offset Accumulation with VTable Dispatch

Source: unknown | Confidence: medium
Accumulates 4 region offset fields, dispatches rendering, recurses into child list, finalizes via vtable.

**Key logic:**
- Reads 4 region offset fields: param_1[1], [2], [3], [4]
- Calculates min/max clipping for each pair (with overflow-safe addition)
- Calls FUN_00499050 with clipped values — render/update call
- Accumulates param_3 to param_1[1] and [2], param_2 to param_1[3] and [4]
- VTable call at *param_1+0x2c(1) — update dispatch
- Recurses into child list at param_1[0x24] via next pointer at +0x8c
- Final vtable call at *param_1+0xa0

**Calls:**
- FUN_00499050 — Render/region update
- FUN_004869e0 (self) — recursion on children

**Used by system:** docs/20-math-utilities.md — UI/graphics region tree update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487760 — State-Dependent VTable Dispatch

Source: unknown | Confidence: low
Dispatches a vtable call based on a 5-state value and a boolean parameter.

**Key logic:**
- Reads state via FUN_00486720() (0-4)
- For states 0-3: dispatches vtable+0x40 based on param_1 being 0 or non-0
- For state 4: checks two conditions via FUN_00486710() and FUN_00487740() before dispatch
- Multiple indirect jump table calls (unrecovered by Ghidra)

**Calls:**
- FUN_00486720 — State query
- FUN_00486710 — Condition check 1
- FUN_00487740 — Condition check 2
- (*extraout_ECX+0x40)() — VTable dispatch

**Used by system:** docs/20-math-utilities.md — state-driven UI/graphics dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00488b30 — Constructor with VTable Set

Source: unknown | Confidence: medium
Constructs an object: sets vtable, calls cleanup.

**Key logic:**
- Sets vtable to PTR_LAB_005abc28
- Calls FUN_00485eb0() — init body

**Calls:**
- FUN_00485eb0 — Init body

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048aa00 — Passthrough Wrapper Returns 0

Source: unknown | Confidence: high
Calls FUN_0048a240 with all params forwarded, returns 0.

**Key logic:**
- FUN_0048a240(param_1, param_2, param_3, param_4)
- Returns 0 (constant success/void)

**Calls:**
- FUN_0048a240 — Target function

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048c9f0 — Object Constructor with Zeroed Fields

Source: unknown | Confidence: medium
Constructs an object with vtable, zeroed data references, and call to init function.

**Key logic:**
- Calls FUN_0048c070(0) — base init
- Sets [199]=0, [200]=0, [0xc9]=0, [0xca]=0 — zero data pointers
- Sets vtable to PTR_FUN_005ac048
- Calls FUN_0048d230() — final init

**Calls:**
- FUN_0048c070 — Base init
- FUN_0048d230 — Final init

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d740 — Large Zero-Init Constructor

Source: unknown | Confidence: medium
Constructs an object: zeroes 16 fields (offsets +0xE8 to +0x124), sets vtable.

**Key logic:**
- Calls FUN_00487220(0,0) — base init
- Zeroes param_1[0x3a] through [0x49] (16 ints, offsets 0xE8 to 0x124)
- Sets vtable to PTR_LAB_005ac328

**Calls:**
- FUN_00487220 — Base init

**Used by system:** docs/20-math-utilities.md — object constructor with field zeroing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048f330 — Field Setter with VTable Dispatch

Source: unknown | Confidence: medium
Sets a byte field, an int field to -1, dispatches via vtable.

**Key logic:**
- Sets byte at param_1+0x17f = 0
- Sets param_1[0x5c] = -1 (offset +0x170)
- VTable call at *param_1+0x2c(1)

**Calls:**
- (*param_1+0x2c)(1) — VTable dispatch

**Used by system:** docs/20-math-utilities.md — field setter with update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490190 — Zero-Check Getter

Source: unknown | Confidence: high
Returns field at param_1+0xe0 combined with zero-check flag.

**Key logic:**
- Reads int at param_1+0xe0
- Returns CONCAT31(result>>8, result==0) — packs comparison result with truncated value

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xE0 | StateField | int | Checked against 0 |

**Calls:** None

**Used by system:** docs/20-math-utilities.md — boolean/integer converter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491300 — Multi-Short Struct Writer

Source: unknown | Confidence: high
Writes 4 shorts and zeroes a dword into a struct.

**Key logic:**
- *param_1 = param_2, [1]=param_3, [2]=param_4, [3]=param_5
- Zeroes param_1[6] (dword at offset +0xC)

**Calls:** None

**Used by system:** docs/20-math-utilities.md — struct field writer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491d10 — Linked List Field Reader

Source: unknown | Confidence: medium
Reads a value from a linked list node via pointer chain.

**Key logic:**
- Reads **param_1 (base pointer)
- If base+0x24 != 0: follows base+0x24 to next+4
- If base+0x24 != 0: returns **(base+0x24)
- Returns 0 if null

**Calls:** None

**Used by system:** docs/20-math-utilities.md — linked list accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00494fe0 — Conditional Field Clear

Source: unknown | Confidence: high
Calls a test function, conditionally clears an output pointer.

**Key logic:**
- iVar1 = FUN_0053cbc0(param_2, param_1) — test/validate
- If result non-zero: *param_2 = 0 (clear output)

**Calls:**
- FUN_0053cbc0 — Validation/test function

**Used by system:** docs/20-math-utilities.md — conditional clearer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495970 — Simple Field Getter

Source: unknown | Confidence: high
Returns *(param_1 + 0x18).

**Calls:** None

**Used by system:** docs/20-math-utilities.md — field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004974a0 — Linked List Search with Action

Source: unknown | Confidence: medium
Walks linked list, triggers a sequence on matching value.

**Key logic:**
- Gets head from param_1+4, stores to param_1+0xc
- If non-null: walks list checking *node == param_2
- On match: calls FUN_0054fc40(1), FUN_00498e30(), FUN_00498f40()
- Walks list via next pointer at node+4
- Calls FUN_00497250(1) after traversal

**Calls:**
- FUN_0054fc40 — Action trigger
- FUN_00498e30 — Get data
- FUN_00498f40 — Process data
- FUN_00497250 — Post-traversal action

**Used by system:** docs/20-math-utilities.md — linked list search-and-act

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498650 — String-Length Guarded Field Setter

Source: unknown | Confidence: medium
Checks string length, dispatches function, sets 3 large-offset fields if string non-empty.

**Key logic:**
- If param_2 is NULL: skip
- Calculates strlen(param_2) via loop
- If non-empty: calls FUN_00566650(param_2), sets param_1+0x1560, +0x1564, +0x1568

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1560 | DataField1 | undefined4 | At large offset |
| +0x1564 | DataField2 | undefined4 | |
| +0x1568 | DataField3 | undefined4 | |

**Calls:**
- FUN_00566650 — String dispatch function

**Used by system:** docs/20-math-utilities.md — string-gated field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498fb0 — List Iteration with VTable Dispatch

Source: unknown | Confidence: medium
Iterates a linked list of objects, calling vtable+0x74 on each.

**Key logic:**
- Walks list at param_1+0x4c
- For each node: calls (*node+0x74)() via vtable
- Advances via FUN_00486320()
- Calls FUN_00499560() after traversal

**Calls:**
- FUN_00486320 — List iterator advance
- FUN_00499560 — Post-traversal cleanup

**Used by system:** docs/20-math-utilities.md — list iteration dispatcher

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499840 — Passthrough Wrapper

Source: unknown | Confidence: high
Calls FUN_00499850(), returns param_1 unchanged.

**Key logic:**
- FUN_00499850()
- Returns param_1

**Calls:**
- FUN_00499850 — Target function

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499cc0 — Destructor with Conditional Free

Source: unknown | Confidence: high
Calls cleanup, optionally frees param_1.

**Key logic:**
- Calls FUN_00499ce0() — cleanup
- If param_2 & 1: calls FUN_00587bcf(param_1)

**Calls:**
- FUN_00499ce0 — Cleanup
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — destructor wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a190 — List Cleanup with VTable Destructor

Source: unknown | Confidence: medium
Iterates linked list, deleting nodes via vtable destructor.

**Key logic:**
- While *param_1 != 0:
  - Calls FUN_00499e00() — get next / delete current
  - If extraout_ECX != 0: calls (*extraout_ECX)(1) — vtable destructor
  - Updates *param_1

**Calls:**
- FUN_00499e00 — List iteration/deletion
- (*extraout_ECX)(1) — VTable destructor

**Used by system:** docs/20-math-utilities.md — linked list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049aa10 — Multi-Field Struct Writer

Source: unknown | Confidence: high
Writes 4 values to consecutive struct offsets.

**Key logic:**
- param_1+0x14 = param_2
- param_1+0x18 = param_3
- param_1+0x1c = param_4
- param_1+0x20 = param_5

**Calls:** None

**Used by system:** docs/20-math-utilities.md — struct field writer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049d150 — Multi-Stage Cleanup with Repeated Call Cycle

Source: unknown | Confidence: medium
Frees 5 allocated pointers via two different deallocators, then runs a cleanup cycle 5 times.

**Key logic:**
- Frees param_1+0x18, +0x1c via FUN_0053cb90
- Frees param_1+4, +8, +0xc via FUN_0053d130
- Runs a 4-function cycle 5 times: FUN_0049ec40, 0049ec60, 0049eca0, 0049ecc0
- Calls FUN_0049e490() — finalize

**Calls:**
- FUN_0053cb90 — Deallocator (type A)
- FUN_0053d130 — Deallocator (type B)
- Multiple cleanup functions

**Used by system:** docs/20-math-utilities.md — multi-resource destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049eca0 — Single Field Free Wrapper

Source: unknown | Confidence: high
Frees a field at param_1+4 via FUN_005539f0, sets to 0.

**Key logic:**
- If param_1+4 != 0: FUN_005539f0(ptr), set to 0

**Calls:**
- FUN_005539f0 — Deallocator

**Used by system:** docs/20-math-utilities.md — field cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0d10 — Global State One-Time Initializer

Source: unknown | Confidence: high
One-time initialization of global flags and constants.

**Key logic:**
- If DAT_007ce269 == 0: sets to 1, sets _DAT_007ce26c = 0x40a00000 (5.0f as float)

**Globals:**
- DAT_007ce269 — Init flag (char)
- _DAT_007ce26c — Initialized to 5.0f

**Calls:** None

**Used by system:** docs/20-math-utilities.md — global one-time init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1d50 — Linked List Dispatch with VTable Calls

Source: unknown | Confidence: medium
Walks linked list, dispatches vtable call on each element.

**Key logic:**
- If param_3 != 0: calls FUN_00566cf0(param_3) — pre-dispatch
- Gets head from *param_1, stores to param_1[2]
- If non-null: walks list via next+4, calls (*node)(param_2) on each
- Stops when param_1[2] becomes 0 or null next

**Calls:**
- FUN_00566cf0 — Pre-dispatch setup
- (*node)(param_2) — VTable dispatch per node

**Used by system:** docs/20-math-utilities.md — linked list dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a34a0 — Per-Element Conditional Action Dispatcher

Source: unknown | Confidence: medium
Iterates elements with stride 0x78, applies different actions based on state flags.

**Key logic:**
- Two modes based on param_2:
  - param_2 == 0: iterates param_1+0xc elements at param_1+0x10 (stride 0x78)
    - Skips elements with -1 at +0x48 or zero at +100
    - If +0x70 < 1 OR **+0x74 != _DAT_0059e928: calls FUN_0054c1a0() if flag at +2 clear, else calls FUN_0054c190()
    - If +0x70 >= 1 and flag at +2 clear: calls FUN_0054c1a0()
    - Otherwise: calls FUN_0054c190()
  - param_2 != 0: for each valid element, calls FUN_0054c190()

**Globals:**
- _DAT_0059e928 — Float comparison constant

**Calls:**
- FUN_0054c1a0 — Action A
- FUN_0054c190 — Action B

**Used by system:** docs/20-math-utilities.md — per-element state machine

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a57f0 — Find Zero-Result Index

Source: unknown | Confidence: medium
Scans indices calling FUN_004a5820 until a non-zero result, writes last zero index to field.

**Key logic:**
- Loops iVar2=0,1,2,... calling FUN_004a5820(iVar2)
- Breaks when result == 0 AND iVar2 > 0
- Writes iVar2 to param_1+0xa8

**Calls:**
- FUN_004a5820 — Test function

**Used by system:** docs/20-math-utilities.md — scan for valid index

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1950 — Small Struct Constructor

Source: unknown | Confidence: high
Initializes a 5-field struct with vtable, zeros, and -1 defaults.

**Key logic:**
- [1]=0, [2]=-1, [3]=0, [4]=-1
- *param_1 = &PTR_LAB_005acbe4

**Calls:** None

**Used by system:** docs/20-math-utilities.md — struct constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2190 — Callback Registration

Source: unknown | Confidence: high
Registers a callback address.

**Key logic:**
- FUN_00587b3e(&LAB_004b21a0) — register callback

**Calls:**
- FUN_00587b3e — Callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2a40 — Float-to-Bitfield Encoder

Source: unknown | Confidence: medium
Converts a float to a 7-bit encoded value and stores in bitfield.

**Key logic:**
- Converts param_2 * _DAT_005accd8 to encoded byte (rounded)
- Subtracts 0x40, masks to 7 bits, ORs into existing field at param_1+0x2c (preserving high bit)

**Globals:**
- _DAT_005accd8 — Float multiplier for encoding

**Calls:** None

**Used by system:** docs/20-math-utilities.md — float-to-bitfield encoding

**Algorithm family:** Bitfield encoding

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b3c60 — Deterministic Hash/Pseudo-Random Generator

Source: unknown | Confidence: medium
Generates a deterministic pseudo-random number from state, tick count, and CRT rand().

**Key logic:**
- Calls FUN_0055687b() — get base state
- param_1[0x201] = (param_1[0x201] + 2) * 0x35abd — linear congruential
- Reads from hash table at param_1[(*param_1 & 0xff) + 1], increments counter
- Combines with GetTickCount() delta and _rand() result
- Returns total: base + (tick_delta) * (rand()*2 + 1)

**Calls:**
- FUN_0055687b — Base state retrieval
- GetTickCount — Win32 API
- __ftol — CRT helper
- _rand — CRT random

**Used by system:** docs/20-math-utilities.md — pseudo-random number generation

**Algorithm family:** LCG + hash-based PRNG

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4840 — Hash Table Lookup (Linked-List Buckets)

Source: unknown | Confidence: medium
Looks up a key in a hash table with linked-list collision resolution.

**Key logic:**
- Computes bucket index: (param_3 + (param_3>>31 & 7) >> 3) + param_1 + param_2*0xD
- Checks occupancy bit at iVar1+1 >> (param_3 & 7)
- If occupied: walks linked list at bucket (param_2+7)*0x10
- Compares each entry's low byte to param_3
- If match: reads flag byte, returns matching node
- List nodes followed via next+4 pointer

**Calls:** None

**Used by system:** docs/20-math-utilities.md — hash table lookup

**Algorithm family:** Hash table with chaining

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9800 — Single Function Dispatch

Source: unknown | Confidence: high
Calls FUN_004b71e0().

**Calls:**
- FUN_004b71e0 — Target function

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba180 — Conditional Multi-Path Dispatcher

Source: unknown | Confidence: medium
Dispatches one of two paths based on validation results.

**Key logic:**
- Guard: *param_1 must == 2
- Calls FUN_004b9a00() — validation
- If fail: calls FUN_004b8bd0()
  - If result != 2: FUN_004b8c40(result, 1), FUN_004b9d20()
  - Else: FUN_004c8dc0(1.0f), FUN_004b9e40()
- If success: FUN_004b9d20()

**Calls:**
- FUN_004b9a00 — Validation
- FUN_004b8bd0 — State query
- FUN_004b8c40 — State setter
- FUN_004b9d20 — Common path
- FUN_004c8dc0 — Set float constant
- FUN_004b9e40 — Alt path

**Used by system:** docs/20-math-utilities.md — conditional state dispatcher

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bacf0 — Linked List Node Removal

Source: unknown | Confidence: high
Removes a node from a singly-linked list by matching key value.

**Key logic:**
- Head at *param_1, stored to param_1[2]
- Clears flag at piVar1[2]
- Walks list matching *node to value from *head
- On match: removes node, adjusts head/prev/tail pointers
- If node flag set: frees *node and node itself
- Decrements count at param_1[3]
- Returns matched value, 0 if not found

**Calls:**
- FUN_00587bcf — Free (up to 2 calls)

**Used by system:** docs/20-math-utilities.md — linked list node removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb950 — Struct Reset/Reinitializer

Source: unknown | Confidence: medium
Resets a large struct to default values, freeing allocated buffers.

**Key logic:**
- Frees buffers at param_1+0x8c, +0x90 via FUN_00587bcf
- Frees count buffer at +0x94, counts 'active' entries before freeing
- Resets ~30 fields to default values (0, -1, 0xBF800000/-1.0f)
- Many float fields set to -1.0 (0xBF800000)
- Loop zeroes 10 dwords from +0xE0

**Calls:**
- FUN_00587bcf — Free (multiple calls)

**Used by system:** docs/20-math-utilities.md — struct reset/reinit

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bd9b0 — Dynamic Array Append with Realloc

Source: unknown | Confidence: high
Appends an element to a dynamic array, resizing when capacity reached.

**Key logic:**
- Capacity at param_1+0x18, count at param_1+0x1c, data at param_1+0x20
- If count == capacity: allocates (capacity+8)*4 bytes, copies existing data, frees old
- Appends param_2 at data[count], increments count

**Calls:**
- operator_new — heap allocation
- FUN_00587bcf — Free (old buffer)

**Used by system:** docs/20-math-utilities.md — dynamic array utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c1450 — Path/File Comparison Counter

Source: unknown | Confidence: low
Counts how many suffixes of a file path are deeper than the base path.

**Key logic:**
- Clears 26-int local array
- If param_1 != 0:
  - Gets base path count via FUN_004c13c0, FUN_004c1370
  - For each valid index i: builds path via FUN_004c13a0(i-1), calls FUN_00588410 to compare
  - For each match: increments suffix counter for subsequent indices
  - Returns count of matches where suffix path count > base path count
- Returns -1 if param_1 == 0, 1 if no iterations

**Calls:**
- FUN_004c13c0 — Path segment count
- FUN_004c1370 — Path info
- FUN_004c1390 — Root path getter
- FUN_004c13a0 — Path suffix getter
- FUN_004c0a20 — Buffer clear
- FUN_00588410 — String comparison

**Used by system:** docs/20-math-utilities.md — file path comparison utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2c20 — Simple Counter Increment

Source: unknown | Confidence: high
Increments a field by 1.

**Key logic:**
- param_1+0x38 = param_1+0x38 + 1

**Calls:** None

**Used by system:** docs/20-math-utilities.md — counter increment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c4cb0 — Linked List Key Search

Source: unknown | Confidence: high
Searches a singly-linked list for a matching key, returns found flag.

**Key logic:**
- Stores head at param_1+8 to param_1+0x10
- Walks list comparing *node to param_2
- Returns 1 if found, 0 if not
- Follows next+4 pointer

**Calls:** None

**Used by system:** docs/20-math-utilities.md — linked list search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c81a0 — List Search with Global Match

Source: unknown | Confidence: medium
Searches linked list for node matching global value DAT_008acfcc.

**Key logic:**
- Walks list at param_1+0xc
- Compares *(node+4) to DAT_008acfcc (global)
- On match: sets node+0x18 = 0 (clears field)
- Follows next pointers at +8

**Globals:**
- DAT_008acfcc — Global comparison value

**Calls:** None

**Used by system:** docs/20-math-utilities.md — list search against global

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8d90 — Global VTable Dispatch by Param

Source: unknown | Confidence: medium
Dispatches a vtable call on a global object based on param_1 value.

**Key logic:**
- Guard: DAT_008ac4c4 must be non-null
- If param_1 == 1: vtable at *DAT_008ac4c4+0x3c
- Else: same vtable call (different jump target - unrecovered)

**Globals:**
- DAT_008ac4c4 — Global object with vtable

**Calls:**
- (*DAT_008ac4c4+0x3c)() — VTable dispatch

**Used by system:** docs/20-math-utilities.md — global vtable dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9b80 — Callback Registration

Source: unknown | Confidence: high
Registers a callback address.

**Key logic:**
- FUN_00587b3e(&LAB_004c9b90)

**Calls:**
- FUN_00587b3e — Callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ce380 — Float Comparison with Constants Table

Source: unknown | Confidence: medium
Compares a float value against a zero threshold constant using indexed parameter selection.

**Key logic:**
- Iterates param_1+0x3c entries at param_1+0x40 (int array)
- For each entry i: reads *piVar3+4 (selector index)
  - If 0: compares param_2+0x2c
  - If 1: compares param_2+0x28
  - If 5: compares param_2+0x30
  - Else: skips
- Comparison: fVar1 against DAT_0059e440 (ZeroThreshold ~0.0f)
- Returns combined flag (NaN, <, == comparisons)

**Globals:**
- DAT_0059e440 — ZeroThreshold (~0.0f, physics clamp)

**Calls:** None

**Used by system:** docs/20-math-utilities.md — threshold comparison against physics zero

**Algorithm family:** Float threshold comparison

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d10e0 — Single Function Dispatch

Source: unknown | Confidence: high
Calls FUN_00403cd0().

**Calls:**
- FUN_00403cd0 — Target function

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5900 — Encoded Data Writer with XOR

Source: unknown | Confidence: medium
Writes encoded data: encodes a parameter value, then XORs with a key.

**Key logic:**
- Encodes param_2: 0→3, 1→1, 2→2, else→0xFF
- Calls FUN_004d5be0 with encoded param_2 (1 byte)
- XORs param_1+8 with param_3, writes 4 bytes

**Calls:**
- FUN_004d5be0 — Data writer

**Used by system:** docs/20-math-utilities.md — data encoding/writing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7c10 — Float Range Index Lookup

Source: unknown | Confidence: medium
Wraps a float into [0, size) range then looks up index in descending threshold table.

**Key logic:**
- If param_2 < ~0.0f: adds param_1+0x24 repeatedly until >= 0
- Subtracts param_1+0x24 repeatedly until within range
- If param_2 <= DAT_005ea404 (threshold): iterates through a 0x144-entry descending table starting at -1, returns index when param_2 < table[i]
- Returns 0 if above all thresholds

**Globals:**
- DAT_0059e440 — ZeroThreshold
- DAT_005ea404 — Threshold table base

**Calls:** None

**Used by system:** docs/20-math-utilities.md — range/table lookup

**Algorithm family:** Range normalization + table lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d8860 — Conditional Branch by Flag

Source: unknown | Confidence: high
Sets field or calls function based on boolean parameter.

**Key logic:**
- If param_2 == 0: sets param_1+8 = 0xFFFFFFFF
- Else: calls FUN_004d8880()

**Calls:**
- FUN_004d8880 — Action function

**Used by system:** docs/20-math-utilities.md — conditional dispatcher

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004db0e0 — Small Struct Constructor

Source: unknown | Confidence: high
Initializes 4-field struct with vtable and defaults.

**Key logic:**
- [1]=1, param_1+2_=1, [3]=0
- *param_1 = &PTR_LAB_005ad034

**Calls:** None

**Used by system:** docs/20-math-utilities.md — struct constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc430 — Conditional Dispatch with Global Check

Source: unknown | Confidence: medium
Returns 0 if param_1==0 AND DAT_008afe88==0, else dispatches to FUN_00545f40.

**Globals:**
- DAT_008afe88 — Global flag (int)

**Calls:**
- FUN_00545f40 — Target function

**Used by system:** docs/20-math-utilities.md — conditional dispatch with global gate

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd3a0 — Two-Output Passthrough

Source: unknown | Confidence: high
Calls FUN_004dc600 with reordered params, writes 2 outputs.

**Key logic:**
- FUN_004dc600(&param_6, &param_3, param_2, param_3)
- If param_4 != null: *param_4 = param_6
- If param_5 != null: *param_5 = param_3

**Calls:**
- FUN_004dc600 — Computation

**Used by system:** docs/20-math-utilities.md — dual-output wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dfa50 — 17-Element Zero-Init Loop

Source: unknown | Confidence: high
Zeroes 17 consecutive dwords starting at param_1.

**Key logic:**
- Loops 17 times: *param_1 = 0; param_1++

**Calls:** None

**Used by system:** docs/20-math-utilities.md — buffer zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e45b0 — Large Config Function with Physics Constants

Source: unknown | Confidence: low
Large configuration function with physics calculations, parameter clamping, and multi-free.

**Key logic:**
- Calls FUN_005881c0(), FUN_004e4790() — init sequence
- Checks extraout_ECX+0x32bc for valid range (0-3, skips if <1 or >3)
- Sets param_1+0x3498 clamped to [1, 64]
- Sets float params at +0x349c, +0x34a0, +0x34a4, +0x34a8, +0x34ac
  - +0x349c = param_squared
  - +0x34a0 = _DAT_0059e43c / (count * 0x28)
  - +0x34a4 = _DAT_0059e43c / ((count*5 + 5) * 8)
- Frees 7 pointers conditionally

**Globals:**
- _DAT_0059e43c — Physics constant (divisor)
- _DAT_008afea0 — Float constant

**Calls:**
- FUN_005881c0, FUN_004e4790, FUN_0043e050, FUN_0042e320, FUN_004f34e0, FUN_004f4270(x2)
- FUN_004e5f60, FUN_004e8010, FUN_0042ddd0
- FUN_00587bcf (up to 7 calls)

**Used by system:** docs/20-math-utilities.md — physics/config initialization

**Moddability:** configurable (count clamped [1,64], physics constants)

<!-- target: docs/20-math-utilities.md -->

## FUN_004f2b10 — Zero-Init 16-Element Array

Source: unknown | Confidence: high
Zeroes 16 dwords (0x10 ints) starting at param_1.

**Key logic:**
- Sets param_1[0..0xF] = 0

**Calls:** None

**Used by system:** docs/20-math-utilities.md — array zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8850 — Per-Index Struct Field Setter

Source: unknown | Confidence: medium
Calls setup then writes 4 fields at computed offset with stride 0x20.

**Key logic:**
- Calls FUN_004f87c0(param_2, param_3, param_4, param_5) — init
- Computes base: param_1 + param_2*0x20
- Sets +0xC4 = 1 (flag), param_6 values at offsets +200, +0xCC, +0xD0

**Calls:**
- FUN_004f87c0 — Pre-init

**Used by system:** docs/20-math-utilities.md — per-index struct field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f91b0 — Global-Guarded Field Reader

Source: unknown | Confidence: medium
Reads 4 fields from a struct if a global flag is set.

**Key logic:**
- Guard: DAT_008afe68 must be non-zero
- Calls FUN_0055bde0(param_1) — get struct
- If output ptrs non-null: copies fields at +8, +0xC, +0x14, +0x18

**Globals:**
- DAT_008afe68 — Global enable flag

**Calls:**
- FUN_0055bde0 — Struct retrieval

**Used by system:** docs/20-math-utilities.md — gated field reader

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004fb8f0 — Callback Registration

Source: unknown | Confidence: high
Registers a callback address.

**Key logic:**
- FUN_00587b3e(&LAB_004fb900)

**Calls:**
- FUN_00587b3e — Callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ff670 — Passthrough Wrapper

Source: unknown | Confidence: high
Calls FUN_00500170(), returns param_1 unchanged.

**Calls:**
- FUN_00500170 — Target function

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005016e0 — VTable Dispatch with Longjmp

Source: unknown | Confidence: high
Calls vtable+8 with param_1, then longjmps. Does not return.

**Key logic:**
- Calls (*param_1+8)(param_1) — vtable dispatch
- _longjmp(param_1+0x84, 1) — non-local jump, never returns

**Calls:**
- (*param_1+8)() — VTable function
- _longjmp — CRT non-local goto

**Used by system:** docs/20-math-utilities.md — vtable dispatch with error recovery

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00503ce3 — Bitplane Blending/Compositing

Source: unknown | Confidence: medium
Performs pixel blending between two image buffers with per-row stride. 16-bit color channel averaging.

**Key logic:**
- Reads both source buffers from param_1[1]+0x18 and *param_1+0x18
- Iterates rows with stride from *param_1+0x1050
- For each row: blends pixels using 16-bit color channel math
  - Splits into high/low nibbles per channel
  - Averages 3 sources with rounding

**Struct offsets (*param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18 | PixelBuffer | ushort* | Image data |
| +0x1050 | RowStrideBytes | int | Bytes per row |
| +0x1058 | RowWidth | int | Pixels per row |
| +0x105C | RowCount | int | Number of rows |

**Calls:** None (pure pixel math)

**Used by system:** docs/20-math-utilities.md — image compositing/blending

**Algorithm family:** 16-bit color channel averaging

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050a7c5 — Object Constructor with Size/Count Init

Source: unknown | Confidence: medium
Constructs an object with size parameter.

**Key logic:**
- Calls FUN_00507496(param_2, 0x18, 1) — init with size=24, count=1
- Sets vtable to PTR_FUN_005adba8

**Calls:**
- FUN_00507496 — Init with size/count

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b37d — Object Constructor (Alternate Size)

Source: unknown | Confidence: medium
Constructs an object with different size parameter.

**Key logic:**
- Calls FUN_00507496(param_2, 0x10, 2) — init with size=16, count=2
- Sets vtable to PTR_FUN_005add0c

**Calls:**
- FUN_00507496 — Init with size/count

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b879 — Object Constructor with Single Init

Source: unknown | Confidence: medium
Constructs an object with alternative init path.

**Key logic:**
- Calls FUN_0050a7e1(param_2)
- Sets vtable to PTR_FUN_005ade1c

**Calls:**
- FUN_0050a7e1 — Init

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c887 — Catmull-Rom Spline Interpolation (4-Point, 3D)

Source: unknown | Confidence: high
Performs Catmull-Rom spline interpolation across 4 control points with a global scale factor.

**Key logic:**
- 4 control points: param_2 (P0), param_3 (P1), param_4 (P2), param_5 (P3)
- Interpolation factor: param_6 (t)
- Computes Catmull-Rom basis functions
- Interpolates 4 float components (x, y, z, w) of each point
- Scales result by _DAT_0059e450 (global scale)

**Globals:**
- _DAT_0059e450 — Global output scale factor
- _DAT_0059e800, _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e46c — Basis coefficients

**Calls:** None (pure math)

**Used by system:** docs/20-math-utilities.md — spline interpolation

**Algorithm family:** Catmull-Rom spline (4-point, cubic, 3D vector)

**Moddability:** configurable (global scale factor)

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d97e — Indirect Call via Global Pointer

Source: unknown | Confidence: medium
Dispatches through a global function pointer.

**Key logic:**
- FUN_0050fea7(1) — pre-dispatch
- Calls PTR_FUN_005d786c(param_1, param_2, param_3, param_4, param_5)

**Globals:**
- PTR_FUN_005d786c — Function pointer

**Calls:**
- FUN_0050fea7 — Pre-dispatch
- PTR_FUN_005d786c — Indirect function call

**Used by system:** docs/20-math-utilities.md — indirect dispatch via global pointer

**Moddability:** hookable (global function pointer)

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e927 — 4×4 Matrix Transform (3D Vector, Projective)

Source: unknown | Confidence: high
Applies a 4×4 matrix transform to a 3D vector with perspective divide.

**Key logic:**
- Input: param_2 (3-vector), param_3 (4×4 matrix = 16 floats)
- Computes transform: result = M[12..14] + v[0..2]·M[0..2] + ...
- Handles perspective row
- Calls FUN_0050c042 to check if divide needed
- If non-zero: divides by perspective term

**Calls:**
- FUN_0050c042 — Zero/one comparison

**Used by system:** docs/20-math-utilities.md — 3D math / matrix transform

**Algorithm family:** 4×4 matrix × 3D vector (projective)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00511060 — Streaming Data Reader / Decoder

Source: unknown | Confidence: medium
Reads encoded data from a stream with buffer management and vtable dispatch.

**Key logic:**
- Reads from param_1[5] (stream state)
- If count == 0: calls vtable+0xC for refill
- Reads 2-byte length, sets struct fields
- Calls vtable+4 for data dispatch
- Calls vtable+0x10 with length-2

**Calls:**
- vtable+0xC — Stream refill
- vtable+4(param_1, 1) — Data dispatch
- vtable+0x10(param_1, length-2) — Post-read callback

**Used by system:** docs/20-math-utilities.md — streaming data decoder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00512183 — Flag-Guarded Byte Reader

Source: unknown | Confidence: high
Checks flag bit 0x800, reads byte at param_2+0x2c into output.

**Key logic:**
- Guards: param_1 && param_2 && param_3 all non-null
- Checks param_2+8 & 0x800 (flag bit)
- If set: *param_3 = param_2+0x2c (byte), returns 0x800

**Calls:** None

**Used by system:** docs/20-math-utilities.md — flag-gated field reader

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513d63 — 16-Bit Color to Float4 Decoder

Source: unknown | Confidence: high
Decodes a 16-bit color value (5-6-5 RGB) into float4 (RGBA) with global scale factors.

**Key logic:**
- R: (param_1 >> 11 & 0x1F) * _DAT_005accd4
- G: (param_1 >> 5 & 0x3F) * _DAT_005accdc
- B: (param_1 & 0x1F) * _DAT_005accd4
- A: 1.0

**Globals:**
- _DAT_005accd4 — Float scale for 5-bit channels
- _DAT_005accdc — Float scale for 6-bit channel

**Calls:** None

**Used by system:** docs/20-math-utilities.md — color format conversion

**Algorithm family:** 16-bit RGB (5-6-5) to float4 RGBA

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051601f — Memory Allocator with Alignment

Source: unknown | Confidence: medium
Allocates aligned memory and links into a per-index free list.

**Key logic:**
- Validates param_3 < 0x3B9AC9F0
- Aligns param_3 to next multiple of 8
- Validates param_2 in [0,1]
- Allocates param_3+0x10 bytes via FUN_00519346
- Links into per-index free list
- Returns pointer + 0x10

**Calls:**
- FUN_00519346 — Memory allocator
- FUN_00515f0e — Error/exception handler

**Used by system:** docs/20-math-utilities.md — memory allocation with alignment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005177b6 — 4×4 Matrix Multiply (Float32)

Source: unknown | Confidence: high
Multiplies two 4×4 matrices (16 floats each). Handles aliasing.

**Key logic:**
- If param_3 == param_1: copies param_3 to local temp if also aliased with param_2
- Standard row×column multiply
- Uses x87 float10 precision

**Calls:** None (pure math)

**Used by system:** docs/20-math-utilities.md — 3D math / matrix multiplication

**Algorithm family:** 4×4 matrix multiply (row×column)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051954e — Per-Index Buffer Copy with Interleaved Offset

Source: unknown | Confidence: low
Copies data between buffers with per-element offset calculation.

**Key logic:**
- Iterates param_1+0x20 elements
- For each element: reads from array at param_1+0xC4 (stride 0x15)
  - Computes local_10 = (piVar6[6] * *piVar6) / param_1+0x114
  - Does 3-way data rotation (shuffle left/center/right)

**Calls:** None

**Used by system:** docs/20-math-utilities.md — array processing / data shuffle

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051e512 — Per-Index Table Generation with Division

Source: unknown | Confidence: low
Generates lookup table per element using a global data table.

**Key logic:**
- Iterates param_1+100 elements
- For each unique iVar3: allocates buffer, fills it from DAT_005b05c8 table
- Each entry: (byte * -0x1FE + 0xFE01) / (iVar3 * 0x200 - 0x200)
- Caches result pointers

**Globals:**
- DAT_005b05c8 — Source data table

**Used by system:** docs/20-math-utilities.md — lookup table generation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005265db — 8×? SIMD Matrix/Packed Float Operation

Source: unknown | Confidence: low
Large SIMD-like matrix operation using PackedFloatingMUL/ADD on 8-element chunks. Uses 3DNow! or SSE packed float instructions.

**Key logic:**
- Processes 8-element chunks of param_2 with param_3 coefficients
- Uses PackedFloatingMUL (multiply) and PackedFloatingADD (add)
- Result stored in 8 × undefined8 chunks = 64 bytes
- Calls FastExitMediaState() to clear MMX/3DNow state after

**Calls:**
- PackedFloatingMUL — SIMD multiply
- PackedFloatingADD — SIMD add
- FastExitMediaState — SIMD state cleanup

**Used by system:** docs/20-math-utilities.md — SIMD matrix math

**Algorithm family:** SIMD packed float matrix operation (3DNow!)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052d8d0 — Threaded Object Creator with SEH

Source: unknown | Confidence: medium
Creates an object via SEH-wrapped allocation with rollback on failure.

**Key logic:**
- SEH handler setup
- If *param_1 == 0:
  - Allocates 0x2D40 bytes
  - Calls FUN_0052e170(param_2, param_3) — constructor
  - Calls vtable+4(0, param_4) — init
  - On failure: calls FUN_0052d990() — cleanup
  - Returns 1 on success, 0 on fail

**Calls:**
- operator_new(0x2D40)
- FUN_0052e170 — Object constructor
- (*piVar2+4)(0, param_4) — VTable init
- FUN_0052d990 — Cleanup/rollback

**Used by system:** docs/20-math-utilities.md — factory with lazy creation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005317c0 — Large Table Copy from ROM Data

Source: unknown | Confidence: medium
Copies two large tables from static data to destination with interleaved stride pattern.

**Key logic:**
- First copy: from DAT_005b6f0a to DAT_008b1924, 0x20 iterations, inner stride 0x40
- Second copy: from DAT_005b730a, same pattern
- Copies 8 dwords per step

**Calls:**
- FUN_004b0170 — Pre-init

**Used by system:** docs/20-math-utilities.md — table initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005357c0 — Argument Reorder Wrapper

Source: unknown | Confidence: high
Calls FUN_005356a0 with swapped arguments.

**Key logic:**
- FUN_005356a0(param_2, param_3)

**Calls:**
- FUN_005356a0 — Target

**Used by system:** docs/20-math-utilities.md — forwarding wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053ab70 — Single Field Free

Source: unknown | Confidence: high
Frees param_1+0xc via FUN_00587bcf.

**Calls:**
- FUN_00587bcf — Free/deallocate

**Used by system:** docs/20-math-utilities.md — field cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b6f0 — QR Decomposition / Givens Rotation (3×3 Double)

Source: unknown | Confidence: high
Performs QR decomposition of a 3×3 matrix using Givens rotations with iterative convergence (up to 50 iterations).

**Key logic:**
- Continuously applies Givens rotations to zero off-diagonal elements
- Up to 50 iterations
- Uses many physics constants for thresholds and stable sqrt computation

**Globals:**
- _DAT_0059e430 — Zero threshold
- _DAT_005b8970 — Early convergence threshold
- _DAT_0059ea20, _DAT_0059e880, _DAT_0059e420 — QR algorithm constants

**Calls:** None (pure math)

**Used by system:** docs/20-math-utilities.md — matrix decomposition (physics)

**Algorithm family:** QR decomposition via Givens rotations (iterative)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c900 — String Match with Flag Set

Source: unknown | Confidence: medium
Compares input string against a table of strings, sets a flag on match.

**Key logic:**
- Copies string to local buffer, normalizes via FUN_00589901
- Iterates DAT_008b8e30 entries (stride 0x84), comparing strings
- On match: sets flag bit 0x400 on matched entry
- Calls FUN_0053ca00() after

**Globals:**
- DAT_008b8e30 — Entry count
- DAT_008b5a3c — String table (stride 0x84)
- DAT_008b5a38 — Flag table

**Calls:**
- FUN_00589901 — String normalization
- FUN_0053ca00 — Post-match action

**Used by system:** docs/20-math-utilities.md — string lookup with flag update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d4c0 — Test-and-Free Wrapper

Source: unknown | Confidence: high
Tests a condition, frees pointer, returns status.

**Key logic:**
- Calls FUN_0053c4d0() — test
- If test != 0: returns -1
- If *param_1 != 0: FUN_00587bcf(*param_1)
- Returns 0

**Calls:**
- FUN_0053c4d0 — Test
- FUN_00587bcf — Free

**Used by system:** docs/20-math-utilities.md — conditional cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00541090 — Surface Blit/Lock with Flag Check

Source: unknown | Confidence: medium
Locks a video surface via vtable and returns a buffer pointer.

**Key logic:**
- If param_2 != null AND param_2+0x18 != null:
  - If *param_2 & 1: sets flag to 0x810
  - Calls vtable+0x2c on surface with dimensions param_4*2, param_5*2
  - Stores result, increments retry counter on failure

**Calls:**
- vtable+0x2c — Surface lock/blit

**Used by system:** docs/20-math-utilities.md — graphics surface operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00543230 — Argument Reorder Wrapper

Source: unknown | Confidence: high
Calls FUN_00540150 with reordered arguments.

**Key logic:**
- FUN_00540150(param_1, param_3, param_2)

**Calls:**
- FUN_00540150 — Target

**Used by system:** docs/20-math-utilities.md — forwarding wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00546330 — Self-Copy String to Buffer

Source: unknown | Confidence: high
Copies a string into an overlapping buffer, normalizes, sets field.

**Key logic:**
- Copies bytes from param_2 to param_2 + (param_1 - param_2)
- Calls FUN_00589901(param_1) — normalize
- Sets param_1+0xB8 = param_3

**Calls:**
- FUN_00589901 — String normalization

**Used by system:** docs/20-math-utilities.md — string buffer management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005473d0 — Multi-Field Zero-Init Constructor

Source: unknown | Confidence: high
Zeroes 10 fields (+8 to +0x2C), calls pre-init.

**Key logic:**
- Calls FUN_0053c2a0() — pre-init
- Zeroes 10 fields

**Calls:**
- FUN_0053c2a0 — Pre-init

**Used by system:** docs/20-math-utilities.md — struct field zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00548e80 — Self-Copy String with Offset

Source: unknown | Confidence: high
Copies string to buffer at param_1+8 via self-relocating copy, normalizes, sets field.

**Key logic:**
- Copies bytes from param_2 to param_2 + ((param_1+8) - param_2)
- Calls FUN_00589901(param_1+8)
- Sets param_1+4 = param_3

**Calls:**
- FUN_00589901 — String normalization

**Used by system:** docs/20-math-utilities.md — string buffer management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054a730 — Self-Copy String with Validation

Source: unknown | Confidence: high
Copies string via self-relocating copy, normalizes, validates.

**Key logic:**
- Copies and normalizes string
- Calls FUN_0054a870(param_3) — validate
- Returns -1 if valid, 0 if not

**Calls:**
- FUN_00589901 — String normalization
- FUN_0054a870 — Validation

**Used by system:** docs/20-math-utilities.md — string validation utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054d4e0 — Conditional Float Field Setter

Source: unknown | Confidence: high
Sets two float fields if new values differ from NaN constant.

**Key logic:**
- If param_2 != _DAT_0059e428 (NaN): set param_1+0xF4 = param_2
- If param_3 != _DAT_0059e428 (NaN): set param_1+0xF8 = param_3

**Globals:**
- _DAT_0059e428 — NaN sentinel constant

**Calls:** None

**Used by system:** docs/20-math-utilities.md — conditional float field update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fda0 — Array Copy with Realloc

Source: unknown | Confidence: high
Allocates a new buffer and copies an int array into it.

**Key logic:**
- Frees existing buffer if any
- Allocates param_3*4 bytes, copies param_3 ints
- Stores count at param_1+0x50

**Calls:**
- operator_new(param_3*4)
- FUN_00587bcf — Free

**Used by system:** docs/20-math-utilities.md — array copy utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00556790 — Fixed-Point Multiply with Rounding

Source: unknown | Confidence: high
32-bit fixed-point multiply with rounding (adds 0x8000 halfway).

**Key logic:**
- lVar1 = (longlong)param_3 * param_4 + 0x8000 (rounding)
- Packs high 16 bits of 32:32 fixed-point

**Calls:** None (pure math)

**Used by system:** docs/20-math-utilities.md — fixed-point arithmetic

**Algorithm family:** Fixed-point multiply with rounding

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055bfc0 — Simple Field Getter

Source: unknown | Confidence: high
Returns *(param_1 + 4).

**Calls:** None

**Used by system:** docs/20-math-utilities.md — field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00562830 — Stack Buffer Zero-Init with VTable Call

Source: unknown | Confidence: medium
Zeroes a large stack buffer, calls vtable function, then another setup function.

**Key logic:**
- Zeroes 0x15d (349) dwords on stack (1396 bytes)
- Calls vtable at param_1+0xCC
- Calls FUN_00562710 for final setup

**Calls:**
- vtable+0xCC — VTable dispatch
- FUN_00562710 — Stack setup

**Used by system:** docs/20-math-utilities.md — stack-based buffer setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005667b0 — In-Place String Shift (Subset Memmove)

Source: unknown | Confidence: high
Shifts characters within a string buffer via overlapping copy.

**Key logic:**
- If *param_1 is null: returns 0 if both params 0, else -1
- If valid range: shifts chars from param_3 to param_3 - param_2
- Returns 0 on success, -1 on invalid

**Calls:** None

**Used by system:** docs/20-math-utilities.md — string buffer manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0056c740 — 3×3 Matrix Multiply (Double Precision)

Source: unknown | Confidence: high
Multiplies two 3×3 matrices (9 doubles each).

**Key logic:**
- Standard row×column 3×3 multiply
- All 9 result elements computed explicitly

**Calls:** None (pure math)

**Used by system:** docs/20-math-utilities.md — 3D math / matrix multiplication

**Algorithm family:** 3×3 matrix multiply (double precision)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a900 — Single Delegation Call

Source: unknown | Confidence: high
Calls FUN_00585d20().

**Calls:**
- FUN_00585d20 — Target

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00583680 — Float Addition: Returns FUN_00568d90() + *param_1

Source: unknown | Confidence: high
Calls FUN_00568d90() and adds the float value at *param_1.

**Calls:**
- FUN_00568d90 — Float generator/state query

**Used by system:** docs/20-math-utilities.md — float addition utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00586ee0 — Callback Registration

Source: unknown | Confidence: high
Registers a callback address.

**Key logic:**
- FUN_00587b3e(&LAB_00586ef0)

**Calls:**
- FUN_00587b3e — Callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587aa0 — Callback Registration

Source: unknown | Confidence: high
Registers a callback address.

**Key logic:**
- FUN_00587b3e(&LAB_00587ab0)

**Calls:**
- FUN_00587b3e — Callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a32a — LOCK/UNLOCK Around Indirect Call via Jump Table

Source: unknown | Confidence: high
Acquires a lock, calls indirect function, releases lock.

**Key logic:**
- LOCK() — acquire
- UNLOCK() — release
- (*UNRECOVERED_JUMPTABLE)() — indirect call

**Calls:**
- LOCK/UNLOCK — Synchronization primitives

**Used by system:** docs/20-math-utilities.md — synchronized dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058c674 — Character Encoding Convert via Lookup Table + Fallback

Source: unknown | Confidence: medium
Converts a character code via lookup table with fallback to multibyte conversion.

**Key logic:**
- If param_2+1 < 0x101: direct table lookup in PTR_DAT_005e69c8
- Else: multibyte conversion via FUN_00595dc8
- Returns lookup result masked by param_3

**Calls:**
- FUN_00595dc8 — Multibyte character conversion

**Used by system:** docs/20-math-utilities.md — text encoding

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593446 � CRT Low-Level I/O Dispatcher

Source: MSVC CRT | Confidence: high
Dispatches file read/write operations based on stream flags and a magic signature check.

**Key logic:**
- If *param_5 != 0x19930520: call FUN_00593cfd (init stream)
- If stream flags *(param_1+4) & 0x66 == 0 (text mode):
  - If param_5[3] != 0 (buffer present):
    - If magic header matches -0x1f928c9d AND version > 0x19930520 AND function pointer at param_1[7]+8 valid:
      - Call virtual function (param_1, param_2...param_8)
    - Else: call FUN_005934e1 (default handler)
- Else (binary mode):
  - If param_5[1] != 0 AND param_6 == 0:
    - Call FUN_0059379b(param_2, param_4, param_5, -1) � flush/cleanup
- Returns 1

**Calls:** FUN_00593cfd (stream init), FUN_005934e1 (default handler), FUN_0059379b (flush handler)

**Moddability:** N/A (CRT function)

<!-- target: docs/08-file-formats.md -->

## FUN_005975f4 — 96-Bit Right Shift

Source: unknown | Confidence: high
Shifts a 96-bit value (3× uint32) right by 1 bit.

**Key logic:**
- Carries LSB of each element to MSB of next

**Calls:** None (pure math)

**Used by system:** docs/20-math-utilities.md — big integer shift

**Algorithm family:** 96-bit right shift

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599796 — Empty Stub

Source: unknown | Confidence: high
Empty function — bare return.

**Key logic:**
- No operations — bare return
- Referenced as callback target

**Used by system:** docs/20-math-utilities.md — placeholder/stripped callback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ae61 — Destructor with Conditional Free

Source: unknown | Confidence: high
Destructor: calls cleanup, optionally frees.

**Key logic:**
- Calls FUN_0059ae24() — cleanup
- If param_2 & 1: FUN_00587bcf(param_1)

**Calls:**
- FUN_0059ae24 — Cleanup
- FUN_00587bcf — Free

**Used by system:** docs/20-math-utilities.md — destructor wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c684 — MSVC Exception Handler Unwind Trampoline

Source: unknown | Confidence: high
Frees pointer at EBP+8.

**Key logic:**
- FUN_00587bcf(*(EBP+8))

**Calls:**
- FUN_00587bcf — Free

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cd1e — MSVC Exception Handler Unwind Trampoline

Source: unknown | Confidence: high
Frees pointer at EBP-0x10.

**Key logic:**
- FUN_00587bcf(*(EBP-0x10))

**Calls:**
- FUN_00587bcf — Free

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d41f — C++ Unwind Helper — Thunk to FUN_00599d17

Source: unknown | Confidence: high
Calls FUN_00599d17().

**Calls:**
- FUN_00599d17 — Cleanup target

**Used by system:** docs/20-math-utilities.md — SEH unwind

**Moddability:** hardcoded

## FUN_0050c021 — Render Object Destructor (thunk_FUN_0050b830)

Source: unknown | Confidence: medium
C++ object destructor with SEH frame. Sets vtable, frees sub-object at +0x10c4, calls sub-destructors.

**Key logic:**
- SEH prologue: saves exception list, registers handler frame
- Sets vtable pointer at `*this` to `PTR_LAB_005adbb8`
- Calls `FUN_0058a5d8` (SEH handler init)
- Calls `FUN_0050a92d` (VertexColorPackRGBto16 — renderer color pack)
- If field at `this + 0x10c4` (0x41b × 4) is non-null: frees via `FUN_00587bcf` (heap dealloc)
- Calls `FUN_00506ccc` (short computation)
- SEH epilogue: restores exception list, returns

**Struct offsets (param_1 / this):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10c4 | SubObject | pointer | Freed via FUN_00587bcf if non-null |

**Calls:**
- FUN_0058a5d8 — SEH handler init
- FUN_0050a92d — VertexColorPackRGBto16, renderer color pack (docs/06)
- FUN_00587bcf — heap memory deallocation
- FUN_00506ccc — short computation, return value discarded

**Used by system:** docs/19-renderer.md — renderer object cleanup; color conversion and vtable suggest renderer-owned object

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005567e1 — Float Scale and Round to Int

Source: unknown | Confidence: high
Multiplies float param_1 by global constant, rounds to nearest integer.

**Key logic:**
- `return (int)ROUND(param_1 * _DAT_005dc164)`
- Multiplies input float by global float constant at DAT_005dc164
- Rounds to nearest integer via ROUND() (banker's rounding / MSVC round-to-nearest)
- Returns int result

**Globals:**
- `_DAT_005dc164` — unknown scaling factor (float)

**Algorithm family:** scalar math — multiply + round conversion

**Used by system:** docs/20-math-utilities.md — general math utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00564ab0 — Callback-Based Array Stride Search

Source: unknown | Confidence: high
Generic array search with configurable stride and callback predicate. Returns pointer to first matching element.

**Key logic:**
- Iterates `param_3` elements starting at `param_2`
- Each element at byte offset `param_4` apart (stride)
- Calls callback `param_5(param_1, elementPtr)` on each element
- If callback returns 0: returns element pointer (`base + index * stride`)
- If no match after all elements: returns 0 (null)

**Parameters:**
| Param | Type | Purpose |
|-------|------|---------|
| param_1 | void* | Context data forwarded to callback |
| param_2 | byte* | Array base pointer |
| param_3 | int | Element count |
| param_4 | int | Element stride in bytes |
| param_5 | code* | Callback: (context, element) → int; 0 = match |

**Calls:** param_5 (callback, indirect)

**Algorithm family:** generic array search — callback predicate with stride

**Used by system:** docs/20-math-utilities.md — general purpose array search utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00567700 — Float-to-Int Truncate with Remainder

Source: unknown | Confidence: high
Splits float into integer and fractional parts. Stores integer via pointer, passes fractional remainder to sub-function.

**Key logic:**
- `iVar1 = __ftol()` — MSVC float-to-long truncation toward zero
- Stores integer part: `*param_1 = iVar1`
- Computes remainder: `param_2 - (float)iVar1 * DAT_0059e9b8` where DAT_0059e9b8 ≈ 1.0f
- Passes remainder to `FUN_005676c0` (float-to-int conversion with remainder calc)

**Globals:**
- `_DAT_0059e9b8` — float, ~1.0f (scale factor for remainder computation)

**Calls:**
- `__ftol` — MSVC CRT float-to-long truncation intrinsic
- FUN_005676c0 — float-to-int conversion with remainder

**Algorithm family:** float decomposition — integer + fractional split

**Used by system:** docs/20-math-utilities.md — float decomposition utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058a55a — Binary Interval Search for Matching Range

Source: unknown | Confidence: high
Searches backward through an interval array to find N intervals containing a target value. Returns pointer to first matching entry.

**Key logic:**
- Reads count from param_1+0xc, array base from param_1+0x10
- Array stride: 0x14 (20 bytes) per entry
  - Entry +4: interval low bound (int)
  - Entry +8: interval high bound (int)
- Walks array backward from last entry to first
- For each entry: checks if `low < param_3 <= high` (interval contains value)
- Each such match decrements param_2; continues until param_2 < 0
- Outputs:
  - *param_4 = index of first matching interval
  - *param_5 = index of last matching interval (uVar3)
- Returns pointer to first matching entry: `arrayBase + firstIndex * 0x14`
- Calls FUN_00593cfd (assert/error) if:
  - Count == 0xffffffff (corrupt/empty)
  - Output range invalid (last < first or last >= count)

**Parameters:**
| Param | Type | Purpose |
|-------|------|---------|
| param_1 | void* | Container: count at +0xc, array at +0x10 |
| param_2 | int | Number of intervals to find (decremented) |
| param_3 | int | Value to search for within intervals |
| param_4 | uint* | Output: first matching index |
| param_5 | uint* | Output: last matching index |

**Calls:**
- FUN_00593cfd — assert/error handler (called on invalid data)

**Algorithm family:** range-based interval search

**Used by system:** docs/20-math-utilities.md — find intervals containing a value

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0058d849 — Read 2-Byte Value from Stream Pointer

Source: unknown | Confidence: medium
Reads 16-bit value from a sequential stream pointer, advances pointer by 4 bytes (possibly alignment padding).

**Key logic:**
- Reads uint16 at current stream position `*(uint16*)(*param_1)`
- Advances stream pointer by 4: `*param_1 += 4`
- Returns the 16-bit value (zero-extended to 32 bits; high 16 bits of return value are unused)

**Parameters:**
| Param | Type | Purpose |
|-------|------|---------|
| param_1 | int* | Stream pointer, advanced by 4 after read |

**Algorithm family:** stream read utility

**Used by system:** docs/20-math-utilities.md — binary stream data reading

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c85c — SEH Unwind Handler

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — calls FUN_00581ad0.

**Key logic:**
- Calls FUN_00581ad0 (SEH cleanup helper)

**Calls:**
- FUN_00581ad0 — SEH cleanup helper

**Used by system:** docs/20-math-utilities.md — MSVC SEH unwind handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cc13 — SEH Unwind Free at EBP-0x20

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — frees pointer from caller stack frame.

**Key logic:**
- Reads pointer from `unaff_EBP - 0x20`
- Frees via FUN_00587bcf

**Calls:**
- FUN_00587bcf — heap free

**Used by system:** docs/20-math-utilities.md — MSVC SEH unwind utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cde0 — SEH Unwind Handler (crt_util)

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — calls FUN_005833e0.

**Key logic:**
- Calls FUN_005833e0

**Calls:**
- FUN_005833e0 — SEH cleanup helper

**Used by system:** docs/20-math-utilities.md — MSVC SEH unwind stub

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d290 — SEH Unwind with Flag Check

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — conditionally calls cleanup based on flag bit.

**Key logic:**
- Checks flag at `unaff_EBP - 0x10` bit 0
- If set: calls FUN_00598aea
- Otherwise: returns immediately

**Calls:**
- FUN_00598aea — conditional cleanup function

**Used by system:** docs/20-math-utilities.md — MSVC SEH unwind with conditional

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d498 — SEH Unwind (exception destructor)

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — calls C++ exception destructor.

**Key logic:**
- Reads exception pointer from `unaff_EBP - 0x10`
- Calls `exception::~exception()` on it

**Calls:**
- `exception::~exception` — MSVC C++ exception destructor

**Used by system:** docs/20-math-utilities.md — MSVC SEH/C++ exception cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00404820 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00404a50 unconditionally.

**Key logic:**
- Calls FUN_00404a50

**Calls:**
- FUN_00404a50 — target function

**Used by system:** docs/20-math-utilities.md — wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004054a0 — Conditional Cleanup with Dual Free

Source: unknown | Confidence: high
Frees sub-objects with different deallocation functions. Resets freed fields to 0.

**Key logic:**
- Calls FUN_00405630 (sub-operation)
- If field at +0x0c non-null: frees via FUN_00587d02 (alternate dealloc), zeros field
- If field at +0x18 non-null: frees via FUN_00587bcf (standard free)
- Calls FUN_00405440 (cleanup continuation)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | SubObjA | pointer | Freed via FUN_00587d02 |
| +0x18 | SubObjB | pointer | Freed via FUN_00587bcf |

**Calls:**
- FUN_00405630 — sub-operation
- FUN_00587d02 — alternate deallocator
- FUN_00587bcf — standard heap free
- FUN_00405440 — cleanup continuation

**Used by system:** docs/20-math-utilities.md — multi-object cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00407fb0 — Linked List Search by ID

Source: unknown | Confidence: high
Walks a linked list of nodes, searches for one matching a given ID (field at +0x5c).

**Key logic:**
- If param_2 == -1: returns 0
- Loads list head from param_1+0x18, stores as current node at param_1+0x20
- While current node non-null:
  - Gets entry pointer from `*current` (node's data reference)
  - If entry null: returns 0
  - Compares entry+0x5c with param_2
  - If match: returns 1
  - Advances: `current = *(current + 4)` (next node in list)
- Returns 0 if not found

**Struct offsets (param_1 — list container):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18 | ListHead | pointer* | First node in linked list |
| +0x20 | CurrentNode | pointer* | Iterator pointer |

**Struct offsets (node):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | EntryPtr | pointer | Data entry with ID field |
| +0x04 | Next | pointer | Next node link |

**Struct offsets (entry):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x5c | EntryID | int | ID to match against param_2 |

**Used by system:** docs/20-math-utilities.md — linked list search utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408520 — Vtable Entry Notify/Cleanup

Source: unknown | Confidence: high
Sets vtable pointer, then calls virtual methods on up to 9 sub-objects with argument 1 (or 3 for index 8). Final vtable update.

**Key logic:**
- Sets vtable to PTR_FUN_0059e60c
- For sub-objects at indices 4-12 (offsets +0x10 through +0x30):
  - If non-null: calls its first virtual method with argument 1 (or 3 for index 8)
- Sets vtable to PTR_LAB_0059e634 (final vtable)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | vtable | pointer | Initial→final vtable swap |
| +0x10–+0x30 | SubObj[4..12] | pointer[] | 9 sub-object slots |

**Calls:** (indirect virtual dispatch per sub-object)

**Used by system:** docs/20-math-utilities.md — object teardown/notification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040bde0 — Struct Field Initializer

Source: unknown | Confidence: high
Zeros multiple fields in a struct, sets defaults.

**Key logic:**
- Sets fields +0x00, +0x04, +0x08 to 0
- Sets +0x0c (index 3) to 2 (default count/capacity)
- Sets +0x14 (index 5) to 0xffffffff (-1, sentinel)
- Sets +0x18, +0x1c, +0x20 to 0
- Sets +0x2c (index 0xb), +0x24 (index 9), +0x28 (index 10) to 0
- Sets +0x25, +0x2d, +0x2e to 0 (byte fields)

**Algorithm family:** struct initialization

**Used by system:** docs/20-math-utilities.md — data structure zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d470 — Simple Setter with Sub-Call

Source: unknown | Confidence: high
Sets first field of struct, calls sub-function, returns self.

**Key logic:**
- `*param_1 = param_2` — store value
- Calls FUN_0040d490()
- Returns param_1

**Calls:**
- FUN_0040d490 — sub-function

**Used by system:** docs/20-math-utilities.md — value setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e8b0 — Struct Setup with Two Calls

Source: unknown | Confidence: high
Sets up a data structure with size and value fields, calls init functions.

**Key logic:**
- Sets +0x08 to param_2 (short ID/type)
- Sets +0x1c to 8 (size/count constant)
- Sets +0x20 to param_3 (data reference)
- Calls FUN_0040e480(param_1 + 0x18) — init on sub-struct
- Calls FUN_004be1d0(param_1) — object registration/link

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x08 | TypeID | short | Set from param_2 |
| +0x1c | SizeConst | int | Set to 8 |
| +0x20 | DataRef | int | Set from param_3 |
| +0x18 | SubStruct | bytes | Initialized via FUN_0040e480 |

**Calls:**
- FUN_0040e480 — sub-struct initialization
- FUN_004be1d0 — object registration/link

**Used by system:** docs/20-math-utilities.md — struct setup utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00410890 — Batch Process with Fixed Start Offsets

Source: unknown | Confidence: high
Iterates multiple arrays/segments of a structure, calling FUN_0040f130 on each element from varying start positions.

**Key logic:**
- For each of 6 segments (fields at +0x24, +0x30, +0x3c, +0x48, +0x54, +0x60):
  - Iterates from segment-specific start (0, 0, 0, 0x1a0, 0xd0, 0x340) up to count
  - Calls FUN_0040f130 per element
- Segment 3 starts at 0x1a0 if count > 0x1a0
- Segment 4 starts at 0xd0 if count > 0xd0
- Segment 5 starts at 0x340 if count > 0x340
- Zeros field at +0x6c before processing

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x24 | CountA | int | Element count, start 0 |
| +0x30 | CountB | int | Element count, start 0 |
| +0x3c | CountC | int | Element count, start 0 |
| +0x48 | CountD | int | Element count, start 0x1a0 |
| +0x54 | CountE | int | Element count, start 0xd0 |
| +0x60 | CountF | int | Element count, start 0x340 |
| +0x6c | Field_0x6c | int | Zeroed before processing |

**Calls:**
- FUN_0040f130 — per-element processing function

**Used by system:** docs/20-math-utilities.md — batch processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00414010 — Enum Value Translation (Resource IDs)

Source: unknown | Confidence: high
Maps an enum (1-22) to resource ID values (0x71-0x86), stores in struct, returns status.

**Key logic:**
- Switch on param_2 (expected 1-22):
  - case 1 → 0x71, 2 → 0x72, ..., 22 → 0x86
  - default: returns -1 (0xffffffff)
- Stores mapped value at param_1 + 0x08
- Calls FUN_00414180(0) and stores result at param_1 + 0x0c
- Returns 1 (success)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x08 | ResourceID | int | Mapped resource ID |
| +0x0c | ResourceHandle | int | Returned from FUN_00414180(0) |

**Calls:**
- FUN_00414180 — resource handle lookup

**Algorithm family:** enum-to-ID translation

**Used by system:** docs/20-math-utilities.md — resource ID mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00415650 — Linked List Indexed Accessor

Source: unknown | Confidence: high
Walks a singly-linked list and returns the data value at a given index.

**Key logic:**
- Checks param_2 in range [0, param_1[3]-1] — bounds check
- Walks list: starts at `*param_1` (head), follows `node[1]` (next pointer) for param_2 steps
- Returns null if walk hits null before reaching index
- Returns `*node` (first field) of target node

**Struct offsets (container at param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | HeadPtr | pointer | Head of linked list |
| +0x0c | Count | int | List size (index 3) |

**Struct offsets (node):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Data | uint | Value to return |
| +0x04 | Next | pointer | Next node link (index 1) |

**Algorithm family:** linked list indexed access

**Used by system:** docs/20-math-utilities.md — list element access by position

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418db0 — Global Variable Zero-Init

Source: unknown | Confidence: high
Zeros 4 sequential global variables.

**Key logic:**
- Sets `_DAT_005ebb18`, `_DAT_005ebb1c`, `_DAT_005ebb20`, `_DAT_005ebb24` to 0

**Globals:**
- `_DAT_005ebb18` — zeroed (unknown purpose)
- `_DAT_005ebb1c` — zeroed
- `_DAT_005ebb20` — zeroed
- `_DAT_005ebb24` — zeroed

**Used by system:** docs/20-math-utilities.md — global state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041fdf0 — Compare Result to 2

Source: unknown | Confidence: high
Calls FUN_0041fe00 and returns true if result equals 2.

**Key logic:**
- Returns `FUN_0041fe00() == 2`

**Calls:**
- FUN_0041fe00 — returns integer

**Algorithm family:** equality check wrapper

**Used by system:** docs/20-math-utilities.md — predicate wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421a10 — Dual Registration Call

Source: unknown | Confidence: high
Calls FUN_00421890 and FUN_00566650 with same argument.

**Key logic:**
- Calls FUN_00421890(param_1)
- Calls FUN_00566650(param_1) — path registry / string set

**Calls:**
- FUN_00421890 — registration function
- FUN_00566650 — path registry / string set

**Used by system:** docs/20-math-utilities.md — dual registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00424060 — Multi-Field Setter

Source: unknown | Confidence: high
Sets same value to 4 fields across a struct at varying offsets.

**Key logic:**
- Sets param_1+0x04 = param_2
- Sets param_1+0x10 = param_2
- Sets param_1+0x32d0 = param_2
- Sets param_1+0x4038 = param_2

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | FieldA | int | Set to param_2 |
| +0x10 | FieldB | int | Set to param_2 |
| +0x32d0 | FieldC | int | Set to param_2 |
| +0x4038 | FieldD | int | Set to param_2 (near SeasonPoints +0x403c) |

**Used by system:** docs/20-math-utilities.md — multi-field value propagation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00453560 — Camera/Viewport Config Batch

Source: unknown | Confidence: high
Batch configuration function. Sets 30+ parameters via FUN_0044f050 with IDs and mode values, then iterates a sub-process 44 times.

**Key logic:**
- Calls FUN_0044f050(id, mode) for 30+ parameter IDs:
  - Mode 2 parameters: IDs 0x1d, 0x9d, 0x38, 0x2a, 0x36, 0xb5, 0x37, 0x1a, 0x1b, 0x4f, 0x50, 0x51, 0x4b, 0x4c, 0x4d, 0x47, 0x48, 0x49, 0xe, 200, 0xd0, 0xcb, 0xcd
  - Mode 0 parameters: IDs 0xd2, 199, 0xc9, 0xd3, 0xcf, 0xd1, 0xc5, 0x39, 0x4a, 0x4e, 2-0xb, 0x3b-0x44, 0x57, 0x58
  - Mode 1 parameters: IDs 0xd, 0xc
- Calls FUN_004527c0() 44 times (0x2c iterations)

**Calls:**
- FUN_0044f050 — parameter setter (ID, mode)
- FUN_004527c0 — sub-process iteration

**Used by system:** docs/20-math-utilities.md — bulk configuration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00457b00 — State-Activated Position Save/Restore

Source: unknown | Confidence: high
Saves or restores 3 position fields (at +0x18, +0x1c, +0x20 → +0x90, +0x94, +0x98) based on state flag and param_2.

**Key logic:**
- If flag at +0x9c == 0 and param_2 == 1: copies +0x18, +0x1c, +0x20 to +0x90, +0x94, +0x98, sets flag to 1
- If flag at +0x9c == 1 and param_2 == 0: calls FUN_00456130 on backup area, resets flag to 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18–+0x20 | Position[3] | float[3] | Current position |
| +0x90–+0x98 | PositionBackup[3] | float[3] | Saved copy |
| +0x9c | SaveActive | byte | Flag: 0=inactive, 1=active |

**Calls:**
- FUN_00456130 — restore/process backup data

**Used by system:** docs/20-math-utilities.md — position save/restore mechanism

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b480 — String Array Comparison Search

Source: unknown | Confidence: high
Compares an input string against up to 8 stored strings (stride 0x5c). Returns index if match found.

**Key logic:**
- Iterates array starting at param_1+0x3c, stride 0x5c per entry, up to 8 entries
- Compares each stored string against param_2 (byte-by-byte comparison)
- On match: stores `DAT_0059f07c` at computed output offset, returns 1
- If no match: returns non-zero error code

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x3c | StringArray | byte[8][] | Array of 8 strings, stride 0x5c |
| +0x90 + i*0x5c | OutputSlot | uint | Per-entry output field |

**Globals:**
- `DAT_0059f07c` — stored on match (unknown purpose)

**Calls:** none (pure logic)

**Used by system:** docs/20-math-utilities.md — string enumeration lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bf10 — Wide Struct Zero-Init

Source: unknown | Confidence: high
Zeros 16 fields in a struct spanning +0x08 through +0x50.

**Key logic:**
- Sets +0x08, +0x0c to 0
- Loop: zeros +0x10 through +0x34 (10 dwords)
- Sets +0x38 through +0x50 to 0

**Used by system:** docs/20-math-utilities.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045d4c0 — Conditional Dispatch on Two Bytes

Source: unknown | Confidence: high
If first two bytes of param_1 are both non-null, calls FUN_00561f40.

**Key logic:**
- Checks param_1[0] != 0 and param_1[1] != 0
- If both non-null: calls FUN_00561f40 (call wrapper)
- Otherwise: no-op

**Calls:**
- FUN_00561f40 — call wrapper

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004614c0 — Two-Stage Check

Source: unknown | Confidence: high
Calls FUN_00461530 with args 2 and 4. Returns 1 if first succeeds and second fails.

**Key logic:**
- Calls FUN_00461530(2)
- If true: calls FUN_00461530(4)
  - If FUN_00461530(4) returns 0: returns 1
- Returns 0

**Calls:**
- FUN_00461530 — check function (returns char)

**Used by system:** docs/20-math-utilities.md — two-stage predicate

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462310 — Single Function Forward

Source: unknown | Confidence: high
Returns result of FUN_0057a820().

**Key logic:**
- Returns FUN_0057a820()

**Calls:**
- FUN_0057a820

**Used by system:** docs/20-math-utilities.md — function result forwarder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463750 — Constant Offset Accessor

Source: unknown | Confidence: high
Returns *param_1 + 0x1b0.

**Key logic:**
- `return *param_1 + 0x1b0;`

**Algorithm family:** simple accessor

**Used by system:** docs/20-math-utilities.md — field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464a60 — Float Store with Conversion

Source: unknown | Confidence: high
Stores a value at +0x220 and a float-to-int conversion at +0x22a.

**Key logic:**
- Stores param_2 at +0x220
- Calls __ftol() (MSVC float-to-long) — stores truncated result at +0x22a

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x220 | FloatValue | float | Stored from param_2 |
| +0x22a | IntVal | byte | Truncated float-to-int |

**Calls:**
- __ftol — MSVC CRT float-to-long intrinsic

**Used by system:** docs/20-math-utilities.md — dual-type store

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00465ff0 — Call with Code Pointer

Source: unknown | Confidence: high
Calls FUN_00587b3e with address of a code label.

**Key logic:**
- Calls FUN_00587b3e(&LAB_00466000)

**Calls:**
- FUN_00587b3e — function taking code pointer argument

**Used by system:** docs/20-math-utilities.md — wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004672c0 — Object Initializer with Vtable + Index

Source: unknown | Confidence: high
Initializes an object: sets vtable, computes indexed global pointer, stores parameters.

**Key logic:**
- Calls FUN_0048c070(0) — global init
- Computes: `param_1[200] = &DAT_007c5770 + (param_2 * 0xb + param_3) * 0x40` — indexed into global array
- Sets vtable to PTR_FUN_0059f4f8
- Stores param_2 at index 0xcb, param_3 at index 0xca
- Stores param_4 at index 199
- Sets index 0xc9 to 0x37 (55)
- Returns param_1

**Globals:**
- `DAT_007c5770` — base of global array, stride 0x40, accessed via (a*11 + b) pattern

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | vtable | pointer | Set to PTR_FUN_0059f4f8 |
| +0x320 | GlobalPtr | pointer | Index 200 (0xc8): pointer into DAT_007c5770 |
| +0x324 | Param4 | uint | Index 199 (0xc7): stored from param_4 |
| +0x328 | ConstVal | uint | Index 0xc9: set to 0x37 |
| +0x32c | Param3 | uint | Index 0xca: stored from param_3 |
| +0x330 | Param2 | uint | Index 0xcb: stored from param_2 |

**Calls:**
- FUN_0048c070 — global initialization

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a970 — Vtable Set + Sub-Call

Source: unknown | Confidence: high
Sets vtable pointer, calls FUN_00489440.

**Key logic:**
- Sets *param_1 to PTR_FUN_0059f9e8 (vtable)
- Calls FUN_00489440

**Calls:**
- FUN_00489440

**Used by system:** docs/20-math-utilities.md — object init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046d6a0 — Sub-Call + Conditional Free

Source: unknown | Confidence: high
Calls sub-function, conditionally frees param_1 based on flag bit.

**Key logic:**
- Calls FUN_0046d6c0
- If param_2 bit 0 set: calls FUN_00587bcf(param_1)
- Returns param_1

**Calls:**
- FUN_0046d6c0 — sub-function
- FUN_00587bcf — heap free (conditional)

**Used by system:** docs/20-math-utilities.md — conditional cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046fdf0 — Resource Check + Dispatch

Source: unknown | Confidence: medium
Checks resource via DAT_007cd8c0 virtual dispatch, calls FUN_00477280 if resource exists.

**Key logic:**
- Calls FUN_0048fec0() and FUN_00490160(1)
- Virtual call: `(*DAT_007cd8c0 + 0x1c)(0xc)` — checks resource type 0xc
- If non-null: calls FUN_00477280(param_1)
- Returns 0

**Globals:**
- DAT_007cd8c0 — global object with vtable (resource manager)

**Calls:**
- FUN_0048fec0
- FUN_00490160(1)
- (indirect) *DAT_007cd8c0 + 0x1c — resource query
- FUN_00477280

**Used by system:** docs/20-math-utilities.md — resource-dependent dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00471750 — Object Initializer with Globals

Source: unknown | Confidence: medium
Initializes object vtable, sets default fields, registers global handles.

**Key logic:**
- Calls FUN_00466d60(1)
- Sets vtable to PTR_FUN_005a1140
- Sets field 199 to &DAT_007ce718 (global reference)
- Sets constants: +0x324=2, +0x328=0, +0x32c=1, +0x330=1, +0x334=0xf0
- Registers 3 globals via FUN_00486f30(ptr, -1)
- Calls FUN_004670e0

**Globals:**
- DAT_007ce718 — referenced by field 199
- PTR_DAT_005be704 — registered
- PTR_DAT_005c32a4 — registered
- DAT_005c32a8 — registered

**Calls:**
- FUN_00466d60
- FUN_00486f30 — global handle register
- FUN_004670e0

**Used by system:** docs/20-math-utilities.md — object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473650 — Resource Check + Virtual Call

Source: unknown | Confidence: medium
Checks resource type 0x13, conditionally calls FUN_00477280, then calls virtual method.

**Key logic:**
- Virtual call: `(*DAT_007cd8c0 + 0x1c)(0x13)` — resource query
- If non-null: FUN_00477280(param_1)
- Virtual call: `(*param_1 + 0xac)()` — vtable slot 43
- Returns 0

**Globals:**
- DAT_007cd8c0 — resource manager

**Calls:**
- (indirect via DAT_007cd8c0) — resource query
- FUN_00477280
- (indirect via param_1 vtable) — vtable method

**Used by system:** docs/20-math-utilities.md — resource-dependent dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00474ff0 — Simple Object Constructor

Source: unknown | Confidence: high
Sets vtable, stores param_2 at index 0x39.

**Key logic:**
- Calls FUN_00487220(0, 0)
- Sets param_1[0x39] = param_2 (+0xe4)
- Sets *param_1 = PTR_FUN_005a42c0 (vtable)
- Returns param_1

**Calls:**
- FUN_00487220

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00477080 — Sub-Call + Field Zero

Source: unknown | Confidence: high
Calls FUN_0048ebd0, zeros byte at +0x17c.

**Key logic:**
- Calls FUN_0048ebd0
- Sets byte at param_1+0x17c = 0
- Returns 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x17c | FlagByte | byte | Zeroed |

**Calls:**
- FUN_0048ebd0

**Used by system:** docs/20-math-utilities.md — field reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004782a0 — Resource Alloc + Store

Source: unknown | Confidence: medium
Allocates resource type 0x10, stores returned pointer.

**Key logic:**
- Virtual call: `(*DAT_007cd8c0 + 0x1c)(0x10)` — resource allocate
- If non-null: stores at param_1+0xe0

**Globals:**
- DAT_007cd8c0 — resource manager

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xe0 | ResourcePtr | pointer | Stored resource handle |

**Used by system:** docs/20-math-utilities.md — resource allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479880 — Vtable Set with Range Call

Source: unknown | Confidence: high
Calls FUN_00466980 with -1.0f and 1.0f, sets vtable.

**Key logic:**
- Calls FUN_00466980(0xbf800000, 0x3f800000) — float values -1.0, 1.0 (range init)
- Sets *param_1 = PTR_FUN_005a52c0 (vtable)
- Returns param_1

**Calls:**
- FUN_00466980 — range initialization

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479e80 — Resource Check + Dispatch (dup)

Source: unknown | Confidence: medium
Checks resource type 0xc via DAT_007cd8c0, dispatches to FUN_00477280.

**Key logic:**
- Calls FUN_004883a0
- Virtual query: (*DAT_007cd8c0 + 0x1c)(0xc)
- If non-null: FUN_00477280(param_1)
- Returns 0

**Calls:**
- FUN_004883a0
- (indirect) resource query
- FUN_00477280

**Used by system:** docs/20-math-utilities.md — resource dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047abb0 — Return 0 Stub

Source: unknown | Confidence: high
Empty function — always returns 0.

**Key logic:**
- `return 0;`

**Used by system:** docs/20-math-utilities.md — stub/placeholder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047d060 — Sub-Call + Virtual Dispatch

Source: unknown | Confidence: medium
Calls FUN_00430f00, then virtual method at vtable+0xa4 (slot 41).

**Key logic:**
- Calls FUN_00430f00
- Virtual call: (*param_1 + 0xa4)() — vtable slot 41

**Calls:**
- FUN_00430f00
- (indirect virtual)

**Used by system:** docs/20-math-utilities.md — dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485600 — Destructor with Conditional Free

Source: unknown | Confidence: high
Sets vtable, calls FUN_00487250, conditionally frees self.

**Key logic:**
- Sets *param_1 = PTR_FUN_005ab130 (vtable)
- Calls FUN_00487250
- If param_2 bit 0 set: frees param_1 via FUN_00587bcf
- Returns param_1

**Calls:**
- FUN_00487250
- FUN_00587bcf (conditional)

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004861a0 — Conditional Multi-Param Dispatch

Source: unknown | Confidence: medium
Conditionally processes parameters through sub-functions based on their low-byte flags.

**Key logic:**
- If (char)param_1 != 0: extracts values via FUN_00499ee0, if both >0 calls FUN_0049aa70
- If (char)param_2 != 0: extracts values via FUN_00499f00, if any non-zero calls FUN_0049aa10

**Calls:**
- FUN_00499ee0 — value extraction
- FUN_0049aa70 — 2-param processing
- FUN_00499f00 — multi-value extraction
- FUN_0049aa10 — 4-param processing

**Used by system:** docs/20-math-utilities.md — conditional multi-dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486aa0 — Guarded Function Dispatch

Source: unknown | Confidence: high
Calls FUN_00497940 if field at +0x40 is non-null, otherwise returns -1.

**Key logic:**
- If param_1+0x40 != 0: returns FUN_00497940(param_2, -1)
- Otherwise: returns -1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x40 | GuardPtr | pointer | Non-null check |

**Calls:**
- FUN_00497940

**Used by system:** docs/20-math-utilities.md — guarded dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487830 — Conditional State Machine Dispatch

Source: unknown | Confidence: low
State-dependent dispatcher. Based on state from FUN_00486720(), conditionally calls vtable method +0x40.

**Key logic:**
- Gets state from FUN_00486720() (0-4)
- For states 0-1: if param_1 non-zero, calls virtual method
- For states 2-3: if param_1 zero, calls virtual method
- For state 4: double-check via FUN_00486710() and FUN_00487720(), then calls virtual method

**Calls:**
- FUN_00486720 — state query
- FUN_00486710 — sub-check
- FUN_00487720 — sub-check
- (indirect) virtual method +0x40

**Used by system:** docs/20-math-utilities.md — state machine dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00488bc0 — Simple Setter

Source: unknown | Confidence: high
Stores param_2 at param_1+0xe0.

**Key logic:**
- `*(param_1 + 0xe0) = param_2`

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048aa40 — Object Init with Field Zeroing

Source: unknown | Confidence: high
Zeros multiple fields, sets vtable, calls init function.

**Key logic:**
- Calls FUN_00488b00(1, -1)
- Zeros indices 0x3b through 0x42 (+0xec through +0x108) and bytes at +0x10c, +0x10d
- Sets *param_1 = PTR_LAB_005abe28 (vtable)
- Returns param_1

**Calls:**
- FUN_00488b00

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048ca30 — Destructor with Conditional Free

Source: unknown | Confidence: high
Calls FUN_0048ca50, conditionally frees self.

**Key logic:**
- Calls FUN_0048ca50
- If param_2 bit 0 set: FUN_00587bcf(param_1)
- Returns param_1

**Calls:**
- FUN_0048ca50
- FUN_00587bcf (conditional)

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048dff0 — State Machine with Virtual Dispatch

Source: unknown | Confidence: medium
State-based dispatch calling virtual methods +0x40 (notification) and +0x9c (commit).

**Key logic:**
- Gets state from FUN_00486720()
- Switch on state:
  - 1: virtual(6) + virtual+0x9c
  - 2: sets arg to 7, then virtual + virtual+0x9c
  - 4: virtual(8) + virtual+0x9c
  - 5: sets arg to 9, then virtual + virtual+0x9c
  - default: just virtual+0x9c
- Returns 0

**Calls:**
- FUN_00486720 — state query
- (indirect) vtable+0x40 (notification with arg)
- (indirect) vtable+0x9c (commit/finalize)

**Used by system:** docs/20-math-utilities.md — state machine

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048f590 — Linked List Indexed Accessor

Source: unknown | Confidence: high
Walks a linked list to index iVar2, returns data value. Bounds-checked.

**Key logic:**
- Reads index from param_1+0x174, validates 0 <= index < count at +0xfc
- Walks list from head at +0xf0, following node[1] links for index steps
- Returns 0 if walk hits null
- Returns *node (first field of target node)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xf0 | HeadPtr | pointer* | Linked list head |
| +0xfc | Count | int | Bounds limit |
| +0x174 | Index | int | Element index |

**Used by system:** docs/20-math-utilities.md — list accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490250 — Object Init with Field Zeroing

Source: unknown | Confidence: high
Zeros 5 fields, sets vtable.

**Key logic:**
- Calls FUN_00485e30
- Zeros indices 0x38-0x3c (+0xe0 through +0xf0)
- Sets *param_1 = PTR_FUN_005ac760 (vtable)
- Returns param_1

**Calls:**
- FUN_00485e30

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491330 — Short Array Zero-Init

Source: unknown | Confidence: high
Zeros 5 shorts and 1 int in a small struct.

**Key logic:**
- Sets param_1[0], [1], [2], [3] = 0 (shorts)
- Sets *(param_1+6) = 0 (int at offset +12)
- Sets param_1[4] = 0 (short)

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491d30 — Linked List Node Removal by Value

Source: unknown | Confidence: high
Removes a node from a singly-linked list by matching *node == param_2. Handles head/tail updates, conditional data free.

**Key logic:**
- Walks singly-linked list (head at *param_1, next at node[1])
- Finds node where *node == param_2
- Updates tail at param_1[2] if node is tail
- Updates head at *param_1 if node is head
- Unlinks: prev node's next = node's next
- Updates param_1[1] (previous pointer) if removing first node
- Decrements count at param_1[3]
- If param_3 == 0: clears flag at node[2]
- If flag at node[2] non-zero and *node non-null: frees *node via FUN_00587bcf
- Frees node via FUN_00587bcf
- Returns 1 on success, 0 on failure

**Struct offsets (container at param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Head | pointer* | List head |
| +0x04 | TailOrPrev | pointer* | Tail/previous tracker |
| +0x08 | Tail | pointer* | Tail node |
| +0x0c | Count | int | Element count |

**Struct offsets (node):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Value | int | Match key |
| +0x04 | Next | pointer | Next node |
| +0x08 | Flags/Data | int/ptr | Cleanup flag / data ptr |

**Calls:**
- FUN_00587bcf (conditional, up to 2 calls)

**Used by system:** docs/20-math-utilities.md — list node removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495010 — MAS Close Wrapper

Source: unknown | Confidence: high
Calls FUN_0053ce40 (MAS archive close).

**Key logic:**
- Calls FUN_0053ce40()

**Calls:**
- FUN_0053ce40 — MAS archive close

**Used by system:** docs/20-math-utilities.md — file archive wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495980 — Object Search with Double Iteration

Source: unknown | Confidence: low
Searches two lists/collections for an object matching a virtual method predicate (at vtable+0x30).

**Key logic:**
- Reads fields at +0x60 and +0x5c
- Calls FUN_00495970() — guard check
- First pass: iterates collection via FUN_00498f60(), checks vtable+0x30 predicate
  - Records last match in piVar5
- Second pass: if FUN_00498e40() non-zero and no match found: iterates linked list at +0x44 checking same predicate
- Returns matching node pointer (or 0)

**Calls:**
- FUN_00495970 — guard
- FUN_00498f60 — iterator get
- (indirect) vtable+0x30 — predicate
- FUN_00486320 — next iterator
- FUN_00498e40 — fallback list access
- FUN_00486320 — next iterator

**Used by system:** docs/20-math-utilities.md — multi-list search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497510 — Doubly-Linked List Node Insert

Source: unknown | Confidence: high
Allocates and inserts a node into a doubly-linked list. Increments counter.

**Key logic:**
- Increments counter at +0x2c
- Calls FUN_0054fdf0(param_1) and FUN_0054fc40(1)
- If param_2 != 0: allocates 0x10-byte node via operator_new
  - Node: [0]=param_2, [1]=0, [2]=0, [3]=1 (byte flag)
  - If list empty (+0x04 == 0): sets head(+0x04)=tail(+0x0c)=last(+0x08)=node, increments +0x10
  - Else: inserts at end (last->next = node, node->prev = last, updates last)
- Returns param_2

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | Head | pointer | List head |
| +0x08 | Last | pointer | Last node |
| +0x0c | Tail | pointer | Tail |
| +0x10 | Count | int | Element count |
| +0x2c | Counter | int | Incremented each call |

**Calls:**
- FUN_0054fdf0
- FUN_0054fc40
- operator_new — 0x10-byte alloc

**Used by system:** docs/20-math-utilities.md — list insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498730 — Float Field Accessor

Source: unknown | Confidence: high
Returns float at param_1+0xc0.

**Key logic:**
- `return *(float *)(param_1 + 0xc0)`

**Used by system:** docs/20-math-utilities.md — field getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498fe0 — Guarded Draw/Render Dispatch

Source: unknown | Confidence: low
Conditional render dispatch with bounds calculation, iterator loop, and virtual calls.

**Key logic:**
- If param_1[0x18] != 0 (flag):
  - Checks virtual predicate vtable+0x28
  - If true: computes rect from fields [1],[2],[3],[4], calls FUN_00490920 + FUN_004918d0
  - Calls FUN_004993d0
  - Iterates linked list at param_1[0x13], calling vtable+0x44 per node
  - Calls vtable+0x2c(0)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | X1 | int | Rect left |
| +0x08 | X2 | int | Rect right |
| +0x0c | Y1 | int | Rect top |
| +0x10 | Y2 | int | Rect bottom |
| +0x4c | SubList | pointer* | Index 0x13 |
| +0x60 | Flag | int | Enable/disable guard |

**Calls:**
- (indirect) vtable+0x28 — predicate
- FUN_00490920 — draw operation
- FUN_004918d0 — draw operation
- FUN_004993d0
- FUN_00486320 — iterator
- (indirect) vtable+0x44 — per-node call
- (indirect) vtable+0x2c

**Used by system:** docs/20-math-utilities.md — render dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499850 — Small Struct Init

Source: unknown | Confidence: high
Sets first element to 3, zeros 4 more.

**Key logic:**
- *param_1 = 3
- Zeros indices 1-5 (bytes: index 1 cleared, ints at 2-5)

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499ce0 — Destructor with Multiple Conditional Frees

Source: unknown | Confidence: high
Sets vtable, frees 10 sub-pointers at even indices (4 through 0x16).

**Key logic:**
- Sets *param_1 = PTR_FUN_005acaac (vtable)
- Calls FUN_00499da0(0) and FUN_0049af30
- Checks and frees pointers at indices 4,6,8,10,0xc,0xe,0x10,0x12,0x14,0x16 (offsets +0x10 through +0x58)
- Each freed via FUN_00587bcf if non-null

**Calls:**
- FUN_00499da0
- FUN_0049af30
- FUN_00587bcf (up to 10 calls)

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a1c0 — Conditional Single-Store with Iteration

Source: unknown | Confidence: low
If param_2 non-null and *param_1 already set: iterates via FUN_00499e00 until exhausted, then calls FUN_00499df0. If *param_1 empty: stores param_2.

**Key logic:**
- If param_2 == 0: return -1
- If *param_1 != 0 (already set): iterate FUN_00499e00() until null, then FUN_00499df0(), return 0
- If *param_1 == 0 (empty): *param_1 = param_2, return 0

**Calls:**
- FUN_00499e00 — iterator
- FUN_00499df0 — cleanup

**Used by system:** docs/20-math-utilities.md — conditional store

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049aa30 — Offset Accumulator

Source: unknown | Confidence: high
Accumulates deltas into position/size fields.

**Key logic:**
- Computes delta_x = param_3 - field at +4
- Computes delta_y = param_2 - field at +0xc
- Accumulates: +4 += delta_x, +8 += delta_x, +0xc += delta_y, +0x10 += delta_y

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | X | int | Reference X |
| +0x08 | Width | int | Accumulated delta_x |
| +0x0c | Y | int | Reference Y |
| +0x10 | Height | int | Accumulated delta_y |

**Used by system:** docs/20-math-utilities.md — offset accumulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049d3f0 — Global State Branch + Format

Source: unknown | Confidence: medium
Branches on DAT_007d0474 flag, formats string, calls render function.

**Key logic:**
- If DAT_007d0474 == 0: calls FUN_0049b950() → uVar1
- Else: calls FUN_0049b900() → uVar1
- Formats string: FUN_0058815f(local_10, formatString, uVar1)
- Calls FUN_00553070(local_10, 4, 0x2b, *(int*)(param_1+0x10)+0x54)

**Globals:**
- DAT_007d0474 — global flag
- DAT_005ccec8 — format string

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | Ptr | pointer | Dereferenced for arg |

**Calls:**
- FUN_0049b950 / FUN_0049b900 — value getters
- FUN_0058815f — string format
- FUN_00553070 — display/render

**Used by system:** docs/20-math-utilities.md — conditional UI render

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ecc0 — Conditional Free + Sub-Call

Source: unknown | Confidence: high
If field at +0xc non-null: calls sub-functions, frees, zeros field.

**Key logic:**
- If param_1+0xc != 0:
  - Calls FUN_005502c0
  - If field still non-null: FUN_00557470() + FUN_00587bcf() free
  - Zeros field at +0xc

**Calls:**
- FUN_005502c0
- FUN_00557470 — no-op stub
- FUN_00587bcf — heap free

**Used by system:** docs/20-math-utilities.md — conditional cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0d30 — Global State Setter

Source: unknown | Confidence: high
Sets global byte if changed, resets associated counter.

**Key logic:**
- If DAT_007ce254 != param_1:
  - DAT_007ce254 = param_1
  - DAT_007ce250 = 0

**Globals:**
- DAT_007ce254 — state byte
- DAT_007ce250 — counter/reset

**Used by system:** docs/20-math-utilities.md — global state management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1da0 — Flag Setter with Global Update

Source: unknown | Confidence: high
Sets struct byte, updates global reference.

**Key logic:**
- Sets param_1+0x10 = param_2
- DAT_007ce2e8 = (param_2 != 0) ? param_1 : 0

**Globals:**
- DAT_007ce2e8 — stores reference to param_1 when param_2 != 0

**Used by system:** docs/20-math-utilities.md — state flag setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a3560 — Flag Setter with OR

Source: unknown | Confidence: high
Sets field and updates flag bits.

**Key logic:**
- param_1[1] = param_2 (store value)
- *param_1 |= 2 (set bit 1 flag)

**Used by system:** docs/20-math-utilities.md — bitwise flag setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a5bd0 — Clamped Index Assignment

Source: unknown | Confidence: high
Float-to-int conversion with clamp to [0, max-1] range.

**Key logic:**
- Calls __ftol() → iVar1
- If iVar1 < 0: set +0x6c = 0
- Else if iVar1 >= field at +0x68: set +0x6c = field_at_0x68 - 1
- Else: set +0x6c = iVar1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x68 | MaxIndex | int | Upper bound |
| +0x6c | ClampedIndex | int | Output clamped value |

**Used by system:** docs/20-math-utilities.md — clamped index helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1970 — Small Struct Init with Vtable

Source: unknown | Confidence: high
Initializes 4 fields with defaults and vtable.

**Key logic:**
- [1] = 0, [2] = -1, [3] = 0, [4] = -1
- *param_1 = PTR_LAB_005acbd8 (vtable)

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b21c0 — Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004b3ad0.

**Key logic:**
- Calls FUN_004b3ad0

**Used by system:** docs/20-math-utilities.md — wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2a80 — Bitfield to Float Conversion

Source: unknown | Confidence: high
Extracts 7-bit signed value from bitfield, scales by global constant.

**Key logic:**
- Extract: `(param_1[0x2c] & 0x7f) - 0x40` — 7-bit signed value in [-64, 63]
- Multiply by _DAT_005accdc (float scale factor)
- Return as float10

**Globals:**
- `_DAT_005accdc` — float scale factor

**Used by system:** docs/20-math-utilities.md — bitfield decode

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b3ce0 — Random/Noise Value Generator

Source: unknown | Confidence: medium
Generates a noise/random value from bit counts and table lookup.

**Key logic:**
- Counts set bits in FUN_004b3c60() result (popcount over 32 bits)
- Uses param_1 as state: looks up table at param_1[(*param_1 & 0xff) + 0x101]
- Multiplies by _DAT_0059e450 (bias/offset constant)
- Adds (popcount - 0x10)
- Multiplies by _DAT_005accf8 (final scale)
- Increments *param_1 (advance state)

**Globals:**
- _DAT_0059e450 — scale/bias factor
- _DAT_005accf8 — final scale factor

**Algorithm family:** noise/RNG — bit count + table lookup

**Used by system:** docs/20-math-utilities.md — noise/random generation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b48e0 — Collision Object Insertion

Source: unknown | Confidence: medium
Processes a collision/object query, inserts into per-type linked lists.

**Key logic:**
- Checks *param_1 flag (active flag)
- Classifies *param_2 >> 0x1d (top 3 bits) into category: 0,1,2,3,-1
- Validates via FUN_004b4760(iVar5, param_2)
- If invalid: allocates via DAT_008ab708 or operator_new/FUN_004ba950/FUN_004bac40/FUN_004bacf0
- Calls FUN_004b3a90(param_2)
- Computes list head: param_1 + (iVar5 + 7) * 0x10
- Allocates 0xc-byte node, inserts into linked list
- Calls FUN_004b47a0(1, iVar5, *puVar7 & 0xff)
- Returns 1 on success, 0 on failure

**Globals:**
- DAT_008ab708 — global pool/pre-allocated node

**Calls:**
- FUN_004b4760 — category validation
- FUN_004ba780 — pre-insert callback
- FUN_004bb6b0 — alloc check
- operator_new/FUN_004ba950 — node alloc
- FUN_004bac40/FUN_004bacf0 — setup
- FUN_004b3a90 — param processing
- FUN_004b47a0 — post-insert callback

**Used by system:** docs/17-physics-collision.md — collision object management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9810 — Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004b70b0.

**Key logic:**
- Calls FUN_004b70b0

**Used by system:** docs/20-math-utilities.md — wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba1e0 — Simple Zero-Init

Source: unknown | Confidence: high
Sets *param_1 = 0.

**Key logic:**
- `*param_1 = 0`

**Used by system:** docs/20-math-utilities.md — zero/clear

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004bbed0 — Accumulator with Fixed Array

Source: unknown | Confidence: high
Stores or accumulates values in a fixed-size array of 4 entries.

**Key logic:**
- If count at +0x3c < 4: stores 3 at +0x40+index*8, stores byte from param_2+8 at +0x44+index*8, increments count
- If count >= 4: accumulates param_2+8 byte to existing entry at +0x3c+count*8
- Calls FUN_004a5660()

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x3c | Count | int | Array index (0-3) |
| +0x40 | ValueField[i] | int | First value slot, stride 8 |
| +0x44 | ByteField[i] | int | Second value slot, stride 8 |

**Calls:**
- FUN_004a5660

**Used by system:** docs/20-math-utilities.md — limited-size accumulator

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004c16b0 — Large Struct Zero-Init

Source: unknown | Confidence: high
Zeros 21 dwords (84 bytes) of a struct.

**Key logic:**
- Sets indices 0 through 0x14 (21 elements) to 0

**Used by system:** docs/20-math-utilities.md — zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2c30 — Increment Counter

Source: unknown | Confidence: high
Increments field at +0x3c by 1.

**Key logic:**
- `*(param_1 + 0x3c) += 1`

**Used by system:** docs/20-math-utilities.md — counter increment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c50e0 — Guarded List Accessor

Source: unknown | Confidence: low
Guarded list element access with index validation.

**Key logic:**
- If param_1 >= 0: calls FUN_005871f0()
- If lower < upper: calls FUN_004c6760, walks linked list at +0x08 to index, returns *node or 0

**Calls:**
- FUN_005871f0 — range query
- FUN_004c6760 — pre-access init

**Used by system:** docs/20-math-utilities.md — guarded list access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c81f0 — Struct Init with Default

Source: unknown | Confidence: high
Zeros 5 fields, sets 6th to 100.0f (0x42c80000).

**Key logic:**
- [0..4] = 0, byte at +4 cleared, [5] = 0
- [6] = 0x42c80000 (100.0f)

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8dc0 — Guarded Virtual Call

Source: unknown | Confidence: medium
If global DAT_008ac4c4 non-null, calls virtual method at +0x50.

**Key logic:**
- If DAT_008ac4c4 != null: calls (*DAT_008ac4c4 + 0x50)()

**Globals:**
- DAT_008ac4c4 — global object pointer

**Used by system:** docs/20-math-utilities.md — guarded virtual dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9d10 — Two-Field Setter

Source: unknown | Confidence: high
Sets +0x20 to -1.0f, +0x24 to 0.

**Key logic:**
- Sets +0x20 = 0xbf800000 (-1.0f)
- Sets +0x24 = 0

**Used by system:** docs/20-math-utilities.md — field init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ce820 — Struct Init with Float Defaults

Source: unknown | Confidence: high
Zeros 12 fields, sets 3 float defaults.

**Key logic:**
- [0..0xb] = 0 (12 dwords zeroed)
- [0xc] = 0x3f800000 (1.0f)
- [0xd] = 0x3f4ccccd (0.8f)
- [0xe] = 0xffffffff (-1)

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d1cd0 — Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004d0ec0.

**Used by system:** docs/20-math-utilities.md — wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5960 — Debug Log Init

Source: unknown | Confidence: medium
Initializes a local buffer, calls FUN_004d5be0 then FUN_0059dba9.

**Key logic:**
- Zeros first byte of local buffer
- Calls FUN_004d5be0(local_e5, 1)
- Calls FUN_0059dba9

**Calls:**
- FUN_004d5be0 — buffer init
- FUN_0059dba9 — cleanup/finalize

**Used by system:** docs/20-math-utilities.md — initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7cc0 — Three-Way Enum Converter

Source: unknown | Confidence: high
Maps input 0, 1, 2 to output 1, 2, 0. Default -1.

**Key logic:**
- 0 → 1, 1 → 2, 2 → 0
- Other → -1

**Algorithm family:** enum mapping

**Used by system:** docs/20-math-utilities.md — enum converter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d8880 — Index Validation Setter

Source: unknown | Confidence: medium
Validates index against array, sets field if valid and global flag set.

**Key logic:**
- If param_2 == -1: set +0x08 = -1
- Else if array at +0x0c has entry at index param_2 non-null AND DAT_007cf788 != 0: set +0x08 = param_2

**Globals:**
- DAT_007cf788 — enable flag

**Used by system:** docs/20-math-utilities.md — validated index setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004db4e0 — Dual-Vtable Destructor

Source: unknown | Confidence: high
Frees sub-object, transitions vtable, optionally frees self.

**Key logic:**
- Sets vtable to PTR_FUN_005ad0dc
- If [4] non-null: frees via FUN_00587bcf
- Sets vtable to PTR_LAB_005ad06c (second vtable)
- If param_2 bit 0 set: frees self via FUN_00587bcf
- Returns param_1

**Used by system:** docs/20-math-utilities.md — dual-phase destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc600 — Surface Size Query

Source: unknown | Confidence: medium
Gets surface dimensions via font/surface lookup and float-to-int conversion.

**Key logic:**
- Calls FUN_0053d1f0(param_1) — font/surface lookup
- If found: calls FUN_005531f0(param_2, param_3, param_4, 0) to get dimensions
- Converts results via __ftol() and stores in *param_3 and *param_4
- Zeros *param_3 and *param_4 if lookup fails

**Calls:**
- FUN_0053d1f0 — surface/font lookup
- FUN_005531f0 — dimension query
- __ftol — float-to-int (twice)

**Used by system:** docs/20-math-utilities.md — surface size query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd400 — Normalized Coordinate Calculator

Source: unknown | Confidence: high
Computes normalized coordinates by dividing by global constants.

**Key logic:**
- Calls FUN_004dd3a0 with param_1, param_2, param_3 and reference args
- If param_4 non-null: *param_4 = (float)param_6 / DAT_005d6d60
- If param_5 non-null: *param_5 = (float)param_3 / DAT_005d6d64

**Globals:**
- DAT_005d6d60 — divisor for X normalization
- DAT_005d6d64 — divisor for Y normalization

**Calls:**
- FUN_004dd3a0 — coordinate transform

**Used by system:** docs/20-math-utilities.md — coordinate normalization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dfa60 — Conditional Audio/Param Setup

Source: unknown | Confidence: medium
Initializes audio/parameter structure with conditional sub-calls.

**Key logic:**
- Stores param_2 as byte at +0x42
- If *param_1 != 0 (active):
  - If param_3 != 0: calls FUN_0040e2b0
  - Calls FUN_0054b530 with 6 pointer args (param_1+1 through +6)
  - Sets flag at +0x40 = 1
  - Calls FUN_0054c0b0 with param_3, param_2
  - Sets bool at +0x41 = (param_2 != 0)
- If inactive: zeros fields 1-6, flags at +0x40 and +0x41
- Calls FUN_00566e40 in both paths

**Calls:**
- FUN_0040e2b0
- FUN_0054b530
- FUN_0054c0b0
- FUN_00566e40

**Used by system:** docs/20-math-utilities.md — conditional parameter setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e4910 — Collision Wrapper with Lock

Source: unknown | Confidence: high
Wraps FUN_00401c90 with acquire/release lock calls.

**Key logic:**
- FUN_004e8010(1) — acquire lock
- FUN_00401c90(param_1) — collision detection
- FUN_004e8010(0) — release lock

**Calls:**
- FUN_004e8010 — lock acquire(1)/release(0)
- FUN_00401c90 — collision detection

**Used by system:** docs/17-physics-collision.md — collision detection wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f2b50 — Physics Defaults Initializer

Source: unknown | Confidence: medium
Initializes 20+ float/int fields to physics-related default constants.

**Key logic:**
- Calls FUN_004f2b10
- Sets 26 fields at offsets +0x48 through +0x104 to float/int constants including:
  - 0xbfb99999 (-1.45f), 0x3fc99999 (1.575f), 0x40882947 (4.255f), 0x40938800 (4.695f)
  - Various physics constants (masses, forces, thresholds)

**Used by system:** docs/18-physics-dynamics.md — physics parameter initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8a70 — Random Parameter Dispatch

Source: unknown | Confidence: medium
Uses rand() to select between two parameters, calls FUN_004f87c0.

**Key logic:**
- Calls rand()
- If result < 0x2aaa (10922, ~1/3 of RAND_MAX): cVar2 = 0x14 (20)
- Else: cVar2 = (result < 0x5554) ? 0x13 (19) : 0x12 (18)
- Calls FUN_004f87c0(cVar2, 2, 1.0f, 1.0f)

**Calls:**
- rand — CRT random
- FUN_004f87c0 — parameter setter

**Used by system:** docs/20-math-utilities.md — randomized selection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9200 — Guarded Field Accessor

Source: unknown | Confidence: high
Returns field from global-referenced struct or default value.

**Key logic:**
- If DAT_008afe68 != 0: looks up param_1 via FUN_0055bde0, returns *(result+0x10)
- Else: returns 0x10 (16, default)

**Globals:**
- DAT_008afe68 — enable flag

**Calls:**
- FUN_0055bde0 — lookup function

**Used by system:** docs/20-math-utilities.md — guarded accessor

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0050ed19 — Quaternion Normalize

Source: unknown | Confidence: high
Normalizes a quaternion (4-component). Handles zero case.

**Key logic:**
- Computes squared length: q0² + q1² + q2² + q3²
- Calls FUN_0050c042(fVar2, 1.0f) — comparison check
- If equal: handles near-zero case:
  - If length² <= *(PTR_DAT_005ade40) (small threshold): zeroes quaternion, returns
  - Else: computes `inv = DAT_0059e43c / sqrt(fVar2)`, scales all components
- If not equal: copies param_2 → param_1 directly

**Globals:**
- PTR_DAT_005ade40 — small threshold pointer (near-zero)
- DAT_0059e43c — physics constant (~1.0 or scale factor)

**Calls:**
- FUN_0050c042 — float comparison
- SQRT — square root

**Algorithm family:** quaternion normalization

**Used by system:** docs/20-math-utilities.md — quaternion math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005110fc — Bitstream/Token Reader

Source: unknown | Confidence: low
Reads tokenized data from a buffer with refill callback. Handles 0xFF escape sequences.

**Key logic:**
- Reads bytes from buffer at param_1[5], refills via callback when exhausted
- 0xFF byte: reads next bytes, accumulates until non-0xFF
  - If accumulated value != 0: dispatches to vtable handler, returns 1
  - If 0: increments counter at param_1[100]+0x58 by 2
- Non-0xFF byte: increments counter at param_1[100]+0x58 by 1
- Loops until data found or callback fails

**Calls:**
- (indirect via callback) — buffer refill
- (indirect via vtable+4) — data dispatch handler

**Used by system:** docs/20-math-utilities.md — bitstream/token parsing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051227f — Guarded Field Reader

Source: unknown | Confidence: high
If all guards pass, reads two fields from param_2 into output params.

**Key logic:**
- Guards: param_1 non-null, param_2 non-null, param_2[8] bit 3 set, param_3 non-null
- If all pass: *param_3 = *(param_2+0x10), *param_4 = *(uint16*)(param_2+0x14), return 8
- Else: return 0

**Used by system:** docs/20-math-utilities.md — guarded data read

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513daf — Batch Clamp to Max

Source: unknown | Confidence: high
Normalizes 16× 4-element vectors by clamping each component to a max value.

**Key logic:**
- Iterates 16 times (4 elements per group, stride 4 floats)
- For each 4-element group:
  - If [3] == 0: zeros all 4 elements
  - Else if [3] < 1: scales each of [0],[1],[2] by 1/[3] but clamps individual to max of 1.0
  - If [3] >= 1: leaves unchanged

**Algorithm family:** batch vector normalization with clamp

**Used by system:** docs/20-math-utilities.md — array normalization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005160ad — Memory Allocator with Chunking

Source: unknown | Confidence: low
Allocates memory with chunk size limits. Uses max chunks to avoid oversized allocations.

**Key logic:**
- Computes max chunk: uVar1 = 0x3b9ac9f0 / param_3 (1 billion / element size)
- If uVar1 == 0: calls error handler
- Uses min(uVar1, param_4) as chunk size
- Calls FUN_00515f23 for allocation
- Iterates to fill param_4 entries with sequentially allocated chunks

**Calls:**
- FUN_00515f23 — memory allocator
- FUN_0051601f — chunk allocator

**Used by system:** docs/20-math-utilities.md — chunked memory allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00517899 — 4×4 Matrix Multiply

Source: unknown | Confidence: high
Multiplies two 4×4 matrices. Handles aliased inputs via temporary buffer.

**Key logic:**
- If param_1 overlaps param_2 or param_3: uses local_48 as temp buffer
- Nested loop: computes each element of result as dot product of row (param_2) and column (param_3)
- Inner loop sums: `param_2_col * param_3_row` across 4 components (quaternion-style 4-component multiply)
- Copies temp buffer back to param_1 if aliased

**Algorithm family:** 4×4 matrix multiplication

**Used by system:** docs/20-math-utilities.md — matrix math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00519622 — Array Processing with Scaling

Source: unknown | Confidence: low
Processes array elements with modulo-based indexing and copy operations.

**Key logic:**
- Uses unaff_ESI as struct base
- Iterates (count at +0x20) times
- Reads stride*6 × first from piVar5 array (stride 0x15 ints = 84 bytes)
- Computes division and remainder
- If first iteration: stores computed value at +0x48
- Copies elements from memory (inner loop stride * 2)

**Used by system:** docs/20-math-utilities.md — array processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051ea5a — Virtual Array Fill

Source: unknown | Confidence: medium
Fills array by calling virtual method repeatedly.

**Key logic:**
- Iterates count at unaff_ESI+100 times
- Calls virtual method (+4 from vtable at unaff_ESI+4) each iteration
- Stores results sequentially in array at unaff_ESI+0x1a4 + 0x44 offset

**Calls:**
- (indirect virtual) — per-element value generator

**Used by system:** docs/20-math-utilities.md — array fill via virtual

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052692f — Matrix Interpolation/Blend

Source: unknown | Confidence: low
Complex 4×4 matrix interpolation with float packing/unpacking and platform-specific SIMD.

**Key logic:**
- Switch on (param_4, param_5, param_6) flags → selects between different transform paths
- Each path zeros local_44..local_18 and sets 4 diagonal elements to 1.0 (identity)
- Or calls FUN_00525e9a / FUN_005265db for specific transforms
- Applies interpolation: packed float multiply, subtract, reciprocal approximation
- Uses DAT_005af998, DAT_005af988, DAT_005af980 as constants
- Calls FUN_00526550 at end

**Calls:**
- FastExitMediaState — platform sync
- FUN_00525e9a — matrix init
- FUN_005265db — matrix composition
- FUN_00526550 — finalize
- PackedIntToFloatingDwordConv / PackedFloatingMUL/SUB/ReciprocalAprox — SIMD math ops

**Algorithm family:** 4×4 matrix blend/interpolation with SIMD

**Used by system:** docs/20-math-utilities.md — 3D transform math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052d970 — Guarded Function Call

Source: unknown | Confidence: high
Calls FUN_0052e350 only if *param_1 is non-null.

**Key logic:**
- If *param_1 != 0: returns FUN_0052e350(param_2, param_3)
- Else: returns 0

**Calls:**
- FUN_0052e350

**Used by system:** docs/20-math-utilities.md — guarded dispatch

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00535e10 — Conditional Multi-Field Reset

Source: unknown | Confidence: medium
If all guard fields non-null, resets multiple fields and calls two sub-functions.

**Key logic:**
- Guards: param_1 non-null, fields at +0x1c, +0x20, +0x24 all non-null
- Resets param_1+0x14, +0x08, +0x18 = 0; +0x2c = 2; +0x30 = 1
- Resets sub-struct (via param_1+0x1c): +0x14=0, +0x10=*(iVar1+8), clamps +0x18 to >=0
- Sets *(iVar1+4) based on +0x18 != 0 flag
- Zeros *(iVar1+0x1e)
- Calls FUN_00537e40() and FUN_00536260()
- Returns 0 on success, -2 on guard failure

**Calls:**
- FUN_00537e40
- FUN_00536260

**Used by system:** docs/20-math-utilities.md — conditional state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053ab80 — Curve/Spline Point Generator

Source: unknown | Confidence: medium
Fills an array with interpolated points computed from random values and accumulated differences.

**Key logic:**
- Stores param_2 at param_1[2]
- If param_1[3] (buffer) non-null: zeros first two fields
- Iterates count at *param_1: for each point, gets random float from FUN_005881f0(), stores in array (stride 8 bytes per float pair), computes difference from previous
- Appends final point, computes last difference, adds sentinel (copies last value, sets next to 0)

**Calls:**
- FUN_005881f0 — random float generator

**Algorithm family:** curve/spline point generation with random values

**Used by system:** docs/20-math-utilities.md — data point generation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053bce0 — Force/Scale Calculation

Source: unknown | Confidence: high
Computes scaled forces using multiple constants and struct fields.

**Key logic:**
- Computes 4 output values from param_1 and param_2 fields:
  - fVar1 = param_1+0x1c × +0x24 × param_2+0x48 × DAT_0059fec8
  - fVar2 = param_1+0x18 × +0x24 × param_2+0x44 × DAT_0059fec8
  - fVar3 = DAT_0059e440³ (zero-threshold cubed)
  - *param_3 = param_1+0x20 × +0x24 × param_2+0x4c × DAT_0059fec8
- Stores fVar1 at param_3[1], fVar2 at param_3[2], fVar3 at param_3[3]

**Globals:**
- DAT_0059fec8 — global scale factor
- DAT_0059e440 — zero-threshold (~0.0f physics clamp constant)

**Used by system:** docs/20-math-utilities.md — physics force scaling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c9c0 — Bit Flag Array Update

Source: unknown | Confidence: medium
Iterates an array of bit-field entries, modifies flags based on bit test.

**Key logic:**
- Iterates DAT_008b8e30 times over entries starting at DAT_008b5a38, stride 0x84 (33 ints)
- For each: if bit 0x4000 set: clears it and sets bit 0x400
- Calls FUN_0053ca00 at end

**Globals:**
- DAT_008b8e30 — array count
- DAT_008b5a38 — array base (stride 0x84 = 33×4)

**Calls:**
- FUN_0053ca00

**Used by system:** docs/20-math-utilities.md — flag array maintenance

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0054b3b0 — Three-Field Setter with Sub-Call

Source: unknown | Confidence: high
Sets 3 fields, calls FUN_0054b330.

**Key logic:**
- Sets +0x20, +0x24, +0x28 from params 2-4
- Calls FUN_0054b330

**Calls:**
- FUN_0054b330

**Used by system:** docs/20-math-utilities.md — setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054e0e0 — Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00540d40.

**Used by system:** docs/20-math-utilities.md — wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fdf0 — Simple Setter

Source: unknown | Confidence: high
Stores param_2 at param_1+0x54.

**Key logic:**
- `*(param_1 + 0x54) = param_2`

**Used by system:** docs/20-math-utilities.md — setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005567d3 — Float Round to Int

Source: unknown | Confidence: high
Rounds float to nearest int via ROUND().

**Key logic:**
- `return (int)ROUND(param_1)`

**Algorithm family:** float rounding

**Used by system:** docs/20-math-utilities.md — math utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055bfd0 — Bounded Array Accessor

Source: unknown | Confidence: high
Returns element at index if within bounds, else 0.

**Key logic:**
- If param_2 < *(param_1+4): returns *(param_1 + 8 + param_2*4)
- Else: returns 0

**Used by system:** docs/20-math-utilities.md — array accessor

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0057a940 — Thunk to FUN_00598815

Source: unknown | Confidence: high
Calls FUN_00598815.

**Used by system:** docs/20-math-utilities.md — thunk wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005836e0 — Counter/Assignment

Source: unknown | Confidence: high
Increments counter, stores two values, writes back.

**Key logic:**
- param_1[1] = param_3
- param_1[2] = param_4
- *param_1 += 1
- *param_2 = *param_1 (new count)

**Used by system:** docs/20-math-utilities.md — counter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00586fa0 — Bitfield Encoder

Source: unknown | Confidence: high
Encodes a bitmask into a byte array. Reads bit counts from a table and sets/clears bits based on mask.

**Key logic:**
- Reads source bit count from table at param_1[2] + 2 + param_2*4
- Builds mask: iterate count times, setting bits 0..count-1
- Reads destination bit count from table at param_1[2] + param_2*4
- For each bit position: computes byte offset and bit within byte
  - If param_3 & combined mask has bit set: sets bit
  - Else: clears bit

**Calls:** none (pure bit manipulation)

**Algorithm family:** bitfield encode/decode

**Used by system:** docs/20-math-utilities.md — bitfield operations

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587b3e — Boolean-to-Int Conversion

Source: unknown | Confidence: high
Calls FUN_00587ac0, returns -1 if true, 0 if false.

**Key logic:**
- `return (FUN_00587ac0(param_1) != 0) - 1`

**Calls:**
- FUN_00587ac0

**Used by system:** docs/20-math-utilities.md — boolean wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a3b6 — SEH Exception Frame Wrapper

Source: CRT / MSVC runtime | Confidence: high
Sets up an SEH exception frame with callback FUN_0058a40a.

**Key logic:**
- Sets up SEH frame with handler FUN_0058a40a
- Calls __CallSettingFrame_12 with params
- Restores exception list
- Returns result

**Calls:**
- __CallSettingFrame_12 — MSVC SEH frame call
- FUN_0058a40a — exception handler

**Used by system:** docs/20-math-utilities.md — SEH wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058cc00 — Memory Copy (Forward/Backward with Alignment)

Source: CRT / MSVC runtime | Confidence: high
Optimized memory copy with forward and backward paths, alignment handling, and 4-byte chunking.

**Key logic:**
- If dest < src and src < dest+size: backward copy (handle overlap)
  - Copies from end to start, maintaining alignment
- Else: forward copy
  - Copies from start to end, maintaining alignment
- Handles misaligned start: copies 1-3 bytes to reach alignment
- Copies main body in 4-byte chunks with optional 8+ chunk loop
- Copies trailing 1-3 bytes
- Returns dest pointer

**Used by system:** docs/20-math-utilities.md — memcpy-like utility (CRT)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593d53 — Empty Stub

Source: unknown | Confidence: high
No-op function — bare return with no logic.

**Key logic:**
- Returns immediately
- Likely placeholder or stripped virtual method

**Used by system:** docs/20-math-utilities.md — empty stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00597f6d — __mbsnbicoll CRT String Collation

Source: CRT (Visual Studio 2003 Release) | Confidence: high
MSVC __mbsnbicoll — bytewise string collation with locale.

**Key logic:**
- If _MaxCount == 0: return 0
- Calls FUN_0059807b with locale (DAT_008d48e4, DAT_008d46bc)
- Returns -1, 0, or +1 (collation result adjusted by -2 from CRT result)

**Globals:**
- DAT_008d48e4 — locale
- DAT_008d46bc — locale

**Calls:**
- FUN_0059807b — locale-aware string compare

**Used by system:** docs/20-math-utilities.md — CRT string function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005997cb — Thunk to FUN_00599958

Source: unknown | Confidence: high
Calls FUN_00599958.

**Key logic:**
- Calls FUN_00599958 (object constructor with SEH + vtable init)

**Calls:**
- FUN_00599958 — object constructor

**Used by system:** docs/20-math-utilities.md — thunk

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c6b6 — MSVC Exception Handler Unwind Trampoline

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — frees pointer at EBP+8.

**Key logic:**
- Frees *(unaff_EBP + 8) via FUN_00587bcf

**Calls:**
- FUN_00587bcf — heap free

**Used by system:** docs/20-math-utilities.md — MSVC SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cd40 — C++ Unwind Helper (thunk to FUN_00583360)

Source: CRT / MSVC runtime | Confidence: high
SEH unwind helper — calls FUN_00583360.

**Key logic:**
- Calls FUN_00583360

**Calls:**
- FUN_00583360 — SEH cleanup

**Used by system:** docs/20-math-utilities.md — MSVC C++ unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d4ac — MSVC Exception Handler (exception destructor)

Source: CRT / MSVC runtime | Confidence: high
SEH unwind handler — calls C++ exception destructor.

**Key logic:**
- Reads exception pointer from unaff_EBP - 0x10
- Calls `exception::~exception()`

**Calls:**
- `exception::~exception` — MSVC C++ exception destructor

**Used by system:** docs/20-math-utilities.md — MSVC SEH/C++ exception cleanup

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0050c2b3 — Thunk to (indirect via DAT_005d77e4)

Source: unknown | Confidence: high
Trampoline — indirect jump through function pointer at DAT_005d77e4. No local logic.

**Key logic:**
- Single indirect call through `*_DAT_005d77e4` — address 0x0050c2b3 is referenced as a call stub or vtable entry
- Ghidra warning: "Could not recover jumptable at 0x0050c2b3. Too many branches"
- The global DAT_005d77e4 holds a function pointer; this thunk dispatches to whatever function is currently stored there

**Globals:**
- `_DAT_005d77e4` — function pointer (indirect jump target)

**Calls:** (indirect via DAT_005d77e4)

**Used by system:** docs/20-math-utilities.md — utility trampoline for indirect dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00550760 — Struct Init with Scale Defaults

Source: unknown | Confidence: medium
Initializes a 17-element struct (0x44 bytes) with default scale values (1.0) and zeroes other fields. Calls parent init first.

**Key logic:**
- Calls FUN_0053c2a0 (parent constructor / subsystem init, docs/06)
- Sets byte at param_1+0x11 (offset +0x44) = 0
- Sets first dword = 0xFFFFFFFF (-1 sentinel)
- Loops 16 times: sets param_1[1..16] = 0x00000000 (zeroes 16 dwords)
- Sets param_1[6] = 0x3F800000 (1.0f) — scale value at offset +0x18
- Sets param_1[0xB] = 0x3F800000 (1.0f) — scale value at offset +0x2C
- Sets param_1[0x10] = 0x3F800000 (1.0f) — scale value at offset +0x40
- Sets param_1[1] = 0x3F800000 (1.0f) — scale value at offset +0x04
- Sets param_1[0x21] = 0 — at offset +0x84

**Struct offsets (param_1):**
| Offset | Field name (from docs/13 if known) | Type | Notes |
|--------|-------------------------------------|------|-------|
| +0x00 | unknown | int32 | Set to 0xFFFFFFFF (-1 sentinel) |
| +0x04 | unknown | float | 1.0f scale value |
| +0x18 | unknown | float | 1.0f scale value |
| +0x2C | unknown | float | 1.0f scale value |
| +0x40 | unknown | float | 1.0f scale value |
| +0x44 | unknown | byte | Cleared to 0 |
| +0x84 | unknown | int32 | Cleared to 0 |

**Calls:**
- FUN_0053c2a0 — parent constructor / subsystem init (docs/06)

**Used by system:** docs/20-math-utilities.md — data structure initialization

**Algorithm family:** Struct initialization

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0055685a — Return Constant 1

Source: unknown | Confidence: high
Returns the constant value 1 as a 16-bit integer. Leaf function, no dependencies.

**Key logic:**
- Returns 1 unconditionally
- No parameters, no globals, no side effects

**Used by system:** docs/20-math-utilities.md — constant accessor

**Algorithm family:** Constant return

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005642f0 — Struct Alloc/Init with Switch-Based Type

Source: unknown | Confidence: medium
Allocates a 5-field struct (20 bytes) on heap, initializes from parameters, and sets a type-dependent default value. Includes a switch on param_3 for flag initialization.

**Key logic:**
- Calls _malloc(0x14) to allocate 20-byte struct
- Sets *puVar1 = param_1 (first field)
- Sets len16 at puVar1+1 = param_2 (2-byte field)
- Sets len16 at puVar1+6 = 9999 (2-byte field, sentinel default)
- Sets puVar1[2] = param_3 (third field, used as switch key)
- Switch on param_3: cases 0, 1, 2, 3 → uVar2=2; default → uVar2=4
- Calls FUN_005646d0(uVar2, callback1=LAB_005645f0, callback2=LAB_00564620, 0)
- Stores result in puVar1[3]
- Sets puVar1[4] = param_4
- Returns pointer

**Calls:**
- _malloc — heap allocation (CRT)
- FUN_005646d0 — unknown (likely creates a sub-struct with callback registration)

**Used by system:** docs/20-math-utilities.md — data structure allocation and initialization

**Algorithm family:** Object construction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058a5d8 — SEH Handler Init

Source: unknown | Confidence: high
Initializes the Structured Exception Handler (SEH) registration by setting ExceptionList to a local stack variable.

**Key logic:**
- Sets `ExceptionList = auStack_c` (address of local stack array)
- Standard MSVC SEH registration prologue
- No other operations

**Used by system:** docs/20-math-utilities.md — SEH / exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058dc40 — CRT Float Passthrough Wrapper

Source: unknown | Confidence: high
Wraps a floating-point operation by passing through parameters and calling FUN_00596175. Returns the original float value unchanged.

**Key logic:**
- Takes 8 parameters with a float10 in ST0
- Sets up local stack frame with param_5/param_6 as uStack_1c/uStack_18
- Sets local_14 = param_7, local_10 = param_8
- Stores dStack_c = (double)in_ST0 (incoming float)
- Calls FUN_00596175(param_2, local_24, &param_3) — format/convert function
- Returns original float value from dStack_c

**Calls:**
- FUN_00596175 — format/convert operation (docs/20)

**Used by system:** docs/20-math-utilities.md — CRT math / float passthrough

**Algorithm family:** Float passthrough wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00590640 — __cintrindisp2 (MSVC CRT Internal)

Source: crt | Confidence: high
MSVC C Runtime internal function `__cintrindisp2` — calls `__trandisp2` and `FUN_0059070a`.

**Key logic:**
- Calls __trandisp2() — MSVC CRT float-to-int conversion dispatch
- Calls FUN_0059070a() — additional CRT init/cleanup
- Returns void

**Calls:**
- __trandisp2 — MSVC CRT float-to-int conversion dispatch
- FUN_0059070a — CRT internal helper

**Used by system:** docs/20-math-utilities.md — MSVC CRT runtime support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00596c20 — Uint-to-String Conversion (Arbitrary Base)

Source: unknown | Confidence: high
Converts unsigned integer to string in arbitrary base (2-36), with optional sign prefix. Reverses in-place.

**Key logic:**
- If param_4 (sign flag) != 0: writes '-', negates param_1
- Repeatedly divides by param_3 (base): digit < 10 → '0'+digit, else → 'W'+digit (lowercase 'a'-'z')
- Null-terminates, then reverses string in place

**Algorithm family:** Integer-to-string conversion

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005991c3 — Locale Encoding State Query

Source: unknown | Confidence: medium
Copies 6 dwords (24 bytes) of locale encoding state from format query or default descriptor.

**Calls:** FUN_00587f64, FUN_0058801d, FUN_0059942b

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c5e4 — SEH Unwind Handler

Source: unknown | Confidence: high
Frees pointer at EBP+8.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c6de — SEH Unwind Handler

Source: unknown | Confidence: high
Frees pointer at EBP+8.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c878 — SEH Unwind (Call FUN_00582650)

Source: unknown | Confidence: high
Calls FUN_00582650.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c9f0 — SEH Unwind (Call FUN_0057b7f0)

Source: unknown | Confidence: high
Calls FUN_0057b7f0.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cf86 — SEH Unwind (Call FUN_00585f30)

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d0c8 — SEH Unwind (Call FUN_0047aa60)

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d2b4 — SEH Unwind (Call FUN_00598c70)

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d4d8 — SEH Unwind (Call FUN_0059a5e9)

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00404830 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_00404840 via FUN_00587b3e.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004054e0 — Binary Data Deserialization

Source: unknown | Confidence: medium
Reads data record from memory buffer by index with type dispatch.

**Calls:** FUN_00587f64, FUN_0058803f, FUN_00404fe0, FUN_00407ef0, FUN_004056a0, FUN_0059b650, FUN_0052d8d0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406700 — Mutex Lock with Timeout

Source: unknown | Confidence: high
Waits on mutex with configurable timeout, writes state on success.

**Win32 API:** WaitForSingleObject, ReleaseMutex

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408000 — Linked List Traversal by ID

Source: unknown | Confidence: medium
Searches linked list for node with matching ID at +0x5C.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408740 — Float-Keyed Field Selector

Source: unknown | Confidence: medium
Selects field via float switch, applies scale transform.

**Globals:** _DAT_0059e65c

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00564b80 — Pad Output with Spaces Up to Length Limit

Source: unknown | Confidence: high
Copies characters from source to output in groups of 3, then appends 4 random characters per group using FUN_00564c40. Pads remaining space with nulls when source exhausted before param_2 limit.

**Key logic:**
- Returns with *param_3 = 0 if param_2 < 1
- Loop processes param_2 characters in groups of 3:
  - Copies up to 3 bytes from param_1 to param_3 (or zeros if past end)
  - Appends 4 random chars from FUN_00564c40()
- Null-terminates output
- Total output length: param_2 + ceil(param_2/3)*4 + 1 (null terminator)

**Calls:**
- FUN_00564c40 — random character generator

**Used by system:** docs/20-math-utilities.md — string padding / formatting

**Algorithm family:** String transformation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00567780 — Empty Stub

Source: unknown | Confidence: high
Returns immediately with no logic. Placeholder or stripped virtual method.

**Key logic:**
- No operations — bare return
- Address 0x00567780 is referenced somewhere (vtable slot, callback registration)
- Likely a virtual method that was never implemented or was stripped at link time

**Used by system:** docs/20-math-utilities.md — empty virtual stub

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0056f090 — Iterate and Find Minimum Value from Function

Source: unknown | Confidence: high
Iterates *param_1 times, calling FUN_00569de0 each iteration to get a value, and returns the minimum value found. Initializes minimum to DAT_0059e420 (1.0).

**Key logic:**
- Sets local_10 = _DAT_0059e420 (1.0) as initial minimum
- Loops iVar1 from 0 to *param_1 - 1:
  - Calls FUN_00569de0(param_2, param_3) — evaluation function
  - If result < current minimum: updates minimum
- Returns minimum as float10
- If *param_1 <= 0: returns 1.0 directly

**Globals:**
- `_DAT_0059e420` — constant 1.0 (initial min value)

**Calls:**
- FUN_00569de0 — evaluation/score function (docs/18 physics dynamics integration)

**Used by system:** docs/20-math-utilities.md — iterative minimum search

**Algorithm family:** Min-finding over function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040be20 — Conditional Virtual Call Triplet (Cleanup)

Source: unknown | Confidence: high
Checks three nullable object pointers at offsets +0x18, +0x1C, +0x20. For each non-null pointer, calls a virtual method (vtable+0) with argument 1, then nulls the pointer.

**Key logic:**
- For each of three offsets (+0x18, +0x1C, +0x20):
  - If pointer non-null:
    - Calls virtual method at vtable+0 on *ptr with arg 1
    - Sets pointer to 0

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x18 | obj1 | undefined4* | Released via virtual call if non-null |
| +0x1C | obj2 | undefined4* | Released via virtual call if non-null |
| +0x20 | obj3 | undefined4* | Released via virtual call if non-null |

**Used by system:** docs/20-math-utilities.md — destructor / cleanup helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d490 — Struct Field Init (Zero All + One Default)

Source: unknown | Confidence: high
Initializes 12 fields in a struct, setting most to 0 and one field (+0x28) to 1.

**Key logic:**
- Sets +0x04..+0x20: 7 ints to 0
- Sets +0x20: byte to 0
- Sets +0x24: int to 0
- Sets +0x28: int to 1 (default enable/flag)
- Sets +0x2C: int to 0

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x04 | unknown | int32 | 0 |
| +0x08 | unknown | int32 | 0 |
| +0x0C | unknown | int32 | 0 |
| +0x10 | unknown | int32 | 0 |
| +0x14 | unknown | int32 | 0 |
| +0x18 | unknown | int32 | 0 |
| +0x1C | unknown | int32 | 0 |
| +0x20 | unknown | byte | 0 |
| +0x24 | unknown | int32 | 0 |
| +0x28 | unknown | int32 | 1 (default) |
| +0x2C | unknown | int32 | 0 |

**Used by system:** docs/20-math-utilities.md — struct initialization

**Algorithm family:** Struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e8f0 — Struct Init with Float Constants and Sub-Calls

Source: unknown | Confidence: medium
Initializes a struct with a 16-bit field, sets pointers, calls helper functions with specific float constant arrays, and optionally calls an additional setup function.

**Key logic:**
- Sets param_1+8 = param_2 (16-bit field)
- Sets param_1+0x1C = 0
- Sets param_1+0x20 = param_3
- Builds local_20..local_c = float constants: {0.0, 0.25, 1.2, 1.575, 0.0, 0.25} (IEEE 754 hex values decoded)
  - 0x00000000 = 0.0, 0x3FD00000 = 0.25, 0x3FC99999 = 1.575, etc.
- Calls FUN_00459950(0, 2.00097656, &local_20) — scale/init with constant array
- Calls FUN_00459990(some_constants...) — another init with 6 float constants
- If param_4 != 0: calls FUN_0040e770(param_4, 0) — optional setup

**Calls:**
- FUN_00459950 — init with float array
- FUN_00459990 — init with float constants
- FUN_0040e770 — conditional sub-setup

**Used by system:** docs/20-math-utilities.md — struct initialization with float constants

**Algorithm family:** Struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00410980 — Loop with Conditional Skip Function

Source: unknown | Confidence: medium
Loops *param_1 times, calling FUN_0040f1c0(param_2) each iteration. If it returns 0, decrements counter and calls FUN_0040f100(). Calls FUN_004bdfe0 first.

**Key logic:**
- Calls FUN_004bdfe0() — pre-loop setup
- Loops iVar2 from 0 to *param_1 - 1:
  - Calls FUN_0040f1c0(param_2) — test function
  - If result == 0: decrements counter, calls FUN_0040f100() — rollback/undo

**Calls:**
- FUN_004bdfe0 — setup/allocation
- FUN_0040f1c0 — test/process function
- FUN_0040f100 — undo/rollback function

**Used by system:** docs/20-math-utilities.md — iterative processing with conditional rollback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00414140 — Decrement Counter with Floor at Zero

Source: unknown | Confidence: high
Decrements a counter at param_1+8 by 1, clamping to minimum 0.

**Key logic:**
- If *(param_1+8) > 0: decrements by 1
- Otherwise: no change

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x08 | counter | int | Decremented with floor 0 |

**Used by system:** docs/20-math-utilities.md — counter management

**Algorithm family:** Clamped decrement

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00415680 — Linked List Indexed Accessor

Source: unknown | Confidence: high
Traverses a singly-linked list by index and returns the data value at the found node. Returns 0 if index out of bounds or list ends early.

**Key logic:**
- Returns 0 if param_2 < 0 or param_2 >= *(param_1+0x1C) (bounds check)
- Traverses list starting at *(param_1+0x10), following `next` pointer at node[1]
- Advances param_2 steps through the list
- Returns *puVar1 (first dword of node data) if found, else 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | list_head | undefined4* | Linked list head pointer |
| +0x1C | list_count | int | Number of nodes |

**Node format:** node[0]=data, node[1]=next pointer

**Used by system:** docs/20-math-utilities.md — linked list accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418dd0 — Callback Registration (atexit-style)

Source: unknown | Confidence: high
Registers code at LAB_00418de0 for deferred execution via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_00418de0)
- Returns void

**Calls:**
- FUN_00587b3e — MSVC _atexit-like callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041ff10 — Scene Element Scan with Condition Check

Source: unknown | Confidence: medium
Scans scene elements (two tiers) looking for one with a specific condition at +0xD4 + index*4 == 10. Uses temporary buffers and filter/file checks.

**Key logic:**
- Gets index via FUN_004c2990()
- Initializes 0x50-byte buffer via FUN_004c2850
- Calls FUN_004c1390(), FUN_004c0a20(), checks FUN_00566810() (file filter)
- Tier 1: checks if any element at offset iVar2+0xD4 + iVar1*4 == 10 → returns 1
- Tier 2: iterates all entries via FUN_004c1370(), same condition check per entry
- Returns 0 if no match

**Calls:**
- FUN_004c2990 — get index
- FUN_004c2850 — buffer init
- FUN_004c1390/FUN_004c13a0 — element iteration
- FUN_004c0a20 — element operation
- FUN_00566810 — file/filter check (docs/08)

**Used by system:** docs/20-math-utilities.md — scene scanning

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421a30 — Dual Dispatch: Process + Path Register

Source: unknown | Confidence: medium
Calls FUN_00421890 (process/file op) then FUN_00566650 (path registry/set).

**Key logic:**
- Calls FUN_00421890(param_1) — process argument
- Calls FUN_00566650(param_1) — register string in path registry (docs/08)

**Calls:**
- FUN_00421890 — unknown process/format
- FUN_00566650 — path registry / string set (docs/08)

**Used by system:** docs/20-math-utilities.md — file/path processing

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00424e30 — Pair Array Linear Search

Source: unknown | Confidence: medium
Searches an array of int pairs at param_1+0x44A8 (stride 2) for a matching value. Returns 1 if found, 0 otherwise.

**Key logic:**
- If *(param_1+0x44B0) >= 0: iterates pair array
- Checks if pair[i*2] == param_2 → returns 1
- Continues up to index at +0x44B0
- Returns 0 if not found

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x44A8 | pair_array | int* | Array of int pairs (stride 2) |
| +0x44B0 | pair_count | int | Number of pairs to search |

**Used by system:** docs/20-math-utilities.md — array search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00454c20 — Enum-to-ID Mapping with Default Fallthrough

Source: unknown | Confidence: medium
Maps input enum to output ID. Returns 0x59 for input 1, 0xFFFFFFFF for many other values, otherwise passes through unchanged.

**Key logic:**
- Switch on param_1:
  - Case 1: return 0x59 (89 decimal)
  - Cases 2-0xD, 0x2A-0x53, 0x57, 0x58, 0x9C, 0xB7, 0xC5, 199, 0xC9, 0xCF, 0xD1-0xD3: param_1 = 0xFFFFFFFF
  - Default: pass through unchanged
- Returns param_1

**Used by system:** docs/20-math-utilities.md — enum mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00457cd0 — Struct Field Zero Init (7 dwords + 1 byte)

Source: unknown | Confidence: high
Zero-initializes 7 dwords and 1 byte (29 bytes total) of a struct.

**Key logic:**
- Sets param_1[0..6] = 0 (7 dwords = 28 bytes)
- Sets byte at param_1+7 = 0 (byte at offset +0x1C)

**Used by system:** docs/20-math-utilities.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b500 — Rotating Index Search with Threshold

Source: unknown | Confidence: medium
Searches through 8 slots (stride 0x5C) using a rotating counter at +0x31C. Finds first slot where float value at +0x90 passes a DAT_0059e440 threshold check. Falls back to finding minimum of int fields at +0xF0.

**Key logic:**
- Uses rotating counter from param_1+0x31C, incrementing modulo 8
- Computes slot index: (counter & 0x80000007) with sign correction
- Checks if float at slot*0x5C+0x90 < DAT_0059e440 (epsilon threshold)
- If no slot passes within 8 tries: scans int fields at +0xF0 (stride 0x5C), finds minimum
- If minimum's int at slot*0x5C+0x94 < param_2: returns -1
- Returns slot index

**Globals:**
- `DAT_0059e440` — zero/epsilon threshold (~0.0f, physics clamp)

**Used by system:** docs/20-math-utilities.md — rotating slot search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bf50 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper that delegates to FUN_00461c70.

**Key logic:**
- Calls FUN_00461c70()
- Returns void

**Calls:**
- FUN_00461c70 — unknown game function

**Used by system:** docs/20-math-utilities.md — dispatch wrapper

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0045d4e0 — String Length Check Dispatch

Source: unknown | Confidence: medium
Checks string length and dispatches to different functions based on whether string has 0, 1, or more characters.

**Key logic:**
- If *param_1 == '\0' (empty): return immediately
- If param_1[1] != '\0' (multi-char): calls FUN_00561e00()
- Else (single char): calls FUN_00561e20()

**Calls:**
- FUN_00561e00 — multi-char handler
- FUN_00561e20 — single-char handler

**Used by system:** docs/20-math-utilities.md — string dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004614f0 — Bitfield Set/Clear at +0x88

Source: unknown | Confidence: high
Sets or clears bits at param_1+0x88 depending on boolean param_3.

**Key logic:**
- If param_3 != 0: *(param_1+0x88) |= param_2 (set bits)
- If param_3 == 0: *(param_1+0x88) &= ~param_2 (clear bits)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x88 | flags | byte | Bitfield modified by this function |

**Used by system:** docs/20-math-utilities.md — bitfield manipulation

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00462330 — ID Lookup in Array

Source: unknown | Confidence: medium
Searches a 0x68-element int array at (*param_1 + 0x3E18) for a value matching FUN_0057a810(). Returns index or -1.

**Key logic:**
- Gets current value via FUN_0057a810()
- Iterates array at *param_1 + 0x3E18 (0x68 = 104 elements)
- If match: returns index
- Returns -1 if not found

**Calls:**
- FUN_0057a810 — get current comparison value

**Used by system:** docs/20-math-utilities.md — array search / ID lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463760 — Conditional State Dispatch

Source: unknown | Confidence: medium
Checks FUN_00461dc0() state, dispatches to one of three functions based on result and param_1.

**Key logic:**
- Calls FUN_00461dc0() for state check
- If state == 0: calls FUN_00461190(param_1)
- Else if param_1 != 0: calls FUN_00460e90()
- Else: calls FUN_00461020()

**Calls:**
- FUN_00461dc0 — state query
- FUN_00461190 — handler 1
- FUN_00460e90 — handler 2
- FUN_00461020 — handler 3

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00464ad0 — Dispatch Wrapper (Call with 1)

Source: unknown | Confidence: high
Calls FUN_004649f0 with argument 1.

**Key logic:**
- Calls FUN_004649f0(1)
- Returns void

**Calls:**
- FUN_004649f0(1) — target function

**Used by system:** docs/20-math-utilities.md — dispatch wrapper

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00466050 — Callback Registration (atexit-style)

Source: unknown | Confidence: high
Registers code at LAB_00466060 for deferred execution via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_00466060)
- Returns void

**Calls:**
- FUN_00587b3e — MSVC _atexit-like callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00467340 — Indexed Call with +/-1 Increment

Source: unknown | Confidence: medium
Reads a value from a struct within a linked node, increments or decrements it, then dispatches to different handlers based on a type field at +0x32C.

**Key logic:**
- If *(param_1+800) != 0 (node exists):
  - Reads iVar1 from *(node+0x14)
  - If param_2 == 1: iVar1 = iVar1 + 1
  - Else: iVar1 = iVar1 - 1
  - If *(param_1+0x32C) != 4:
    - Calls FUN_0042eaa0(type, subtype, iVar1)
  - Else:
    - Calls FUN_0042eb60(subtype, iVar1)
  - Calls FUN_004673b0()

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x320 | node_ptr | int | Pointer to linked list node |
| +0x324 | subtype | undefined4 | Passed to handlers |
| +0x328 | subtype2 | undefined4 | Passed to handlers |
| +0x32C | type | int | Type selector (4 = alternate handler) |

**Calls:**
- FUN_0042eaa0 — type-based handler
- FUN_0042eb60 — type-4 handler
- FUN_004673b0 — post-handler

**Used by system:** docs/20-math-utilities.md — indexed dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a980 — ID Pair Match and Clear

Source: unknown | Confidence: medium
Searches a global array at DAT_007d1b08 (stride 7 ints) for matching pair {*param_1, param_1[1]}, then resets match to {0, 0x59}.

**Key logic:**
- Iterates from &DAT_007d1b08 upward to 0x7d1fd8 in steps of 7 ints
- If (*piVar1 == *param_1) AND (piVar1[1] == param_1[1]):
  - Sets *piVar1 = 0
  - Sets piVar1[1] = 0x59

**Globals:**
- `DAT_007d1b08` — global array of pairs (stride 7, unknown module)

**Used by system:** docs/20-math-utilities.md — ID pair clear

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046d6c0 — VTable Set + Init Call

Source: unknown | Confidence: high
Sets vtable pointer and calls FUN_00487250.

**Key logic:**
- Sets *param_1 = &PTR_FUN_0059fcb8 (vtable)
- Calls FUN_00487250()
- Returns void

**Calls:**
- FUN_00487250 — initialization function

**Used by system:** docs/20-math-utilities.md — constructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046fe20 — State Check + Conditional Dispatch

Source: unknown | Confidence: medium
Checks a system state via virtual call on DAT_007cd8c0, conditionally calls FUN_00477280.

**Key logic:**
- Calls FUN_0048fec0() then FUN_00490160(0) — setup
- Calls virtual method at *DAT_007cd8c0 + 0x1C with arg 0xD (get state)
- If state != 0: calls FUN_00477280(param_1)
- Returns 0

**Globals:**
- `DAT_007cd8c0` — system state object (vtable dispatch)

**Calls:**
- FUN_0048fec0 — setup
- FUN_00490160 — init
- FUN_00477280 — conditional action

**Used by system:** docs/20-math-utilities.md — state-checked dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004717e0 — Complex Constructor (VTable + Fields + Ref Count)

Source: unknown | Confidence: medium
Initializes a large object with vtable, data pointers, default values, and reference count inc for two resources.

**Key logic:**
- Calls FUN_00466d60(1) — parent init
- Sets *param_1 = &PTR_FUN_005a1200 (vtable)
- Sets param_1[199] = &DAT_007ce784 (data reference)
- Sets fields: [0xC9]=1, [0xCA]=0, [0xCB]=1, [0xCC]=1, [0xCD]=0xF1
- Calls FUN_00486f30 twice to increment ref count on PTR_DAT_005be704 and DAT_005c32c8
- Calls FUN_004670e0() — post-init

**Globals:**
- `DAT_007ce784` — data reference stored in object

**Calls:**
- FUN_00466d60 — parent init
- FUN_00486f30 — ref count increment (x2)
- FUN_004670e0 — post-init

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473b00 — Constructor (VTable + Config Data)

Source: unknown | Confidence: medium
Initializes an object with vtable, config data pointer, and two ref-count increments.

**Key logic:**
- Calls FUN_0048c070(1) — parent init
- Sets *param_1 = &PTR_FUN_005a2dc0
- Sets param_1[200] = &DAT_007d0474 (config data)
- Sets param_1[199] = 0x116 (size/offset)
- Calls FUN_00486f30 twice for PTR_DAT_005c7084, PTR_DAT_005c7080

**Globals:**
- `DAT_007d0474` — config/state data pointer

**Calls:**
- FUN_0048c070 — parent init
- FUN_00486f30 — ref count increment (x2)

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00475020 — Conditional Free with Flag Check (Destructor)

Source: unknown | Confidence: high
Calls cleanup function, conditionally frees param_1 if bit 0 of param_2 is set.

**Key logic:**
- Calls FUN_00475040() — cleanup
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1)
- Returns param_1

**Calls:**
- FUN_00475040 — cleanup
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00477160 — Linked List Traversal + Virtual Call

Source: unknown | Confidence: medium
Traverses a linked list by index, validates node content via FUN_004773a0, then calls virtual method at vtable+0x90.

**Key logic:**
- Calls FUN_0048f300() — setup
- Reads iVar4 = *(param_1+0x170) (current index)
- Bounds check: -1 < iVar4 < *(param_1+0xFC)
- Traverses list at *(param_1+0xF0) by index
- Validates node content via FUN_004773a0(*piVar1)
- If valid: calls virtual method at vtable+0x90 on iVar4+0x30 object

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xF0 | list_head | int* | Linked list |
| +0xFC | list_count | int | Max index |
| +0x170 | current_index | int | Current position |

**Calls:**
- FUN_0048f300 — setup
- FUN_004773a0 — node validation

**Used by system:** docs/20-math-utilities.md — list traversal + dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004782c0 — State Sync with Dirty Flag

Source: unknown | Confidence: medium
Reads a state value from global system via DAT_007cd8c0, compares with local copy, updates if changed and triggers vtable notification.

**Key logic:**
- Calls virtual on *DAT_007cd8c0+0x1C(0x10) — get system state
- If state != 0 AND local copy at param_1[0x3A] != remote *(state+0x174):
  - Updates param_1[0x3A] = *(state+0x174)
  - Calls vtable+0x2C on *param_1 with arg 1 (dirty notification)
- Returns 0

**Globals:**
- `DAT_007cd8c0` — system state object

**Used by system:** docs/20-math-utilities.md — state sync

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004798b0 — Constructor with Range Init

Source: unknown | Confidence: high
Calls FUN_00466980 with -1.0 and 1.0 (float range), sets vtable.

**Key logic:**
- Calls FUN_00466980(0xBF800000, 0x3F800000) = FUN_00466980(-1.0f, 1.0f) — range init
- Sets *param_1 = &PTR_FUN_005a5378 (vtable)
- Returns param_1

**Calls:**
- FUN_00466980 — range initialization with float bounds

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479eb0 — Flag Set + Init

Source: unknown | Confidence: medium
Calls FUN_0047abb0 then sets byte at param_1+0x100 to 1. Returns 0.

**Key logic:**
- Calls FUN_0047abb0() — pre-init
- Sets *(param_1+0x100) = 1 (flag enable)
- Returns 0

**Calls:**
- FUN_0047abb0 — pre-init

**Used by system:** docs/20-math-utilities.md — flag set

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047b1b0 — Triple Virtual Call Dispatch

Source: unknown | Confidence: medium
Zeros a field then calls three virtual methods on an object.

**Key logic:**
- Sets param_1[0x41] = 0
- Calls vtable+0x40 with arg 0
- Calls vtable+0x2C with arg 1
- Calls vtable+0x9C (indirect, jumptable)

**Used by system:** docs/20-math-utilities.md — dispatch sequence

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0047e680 — Dual State-Checked Dispatch

Source: unknown | Confidence: medium
Checks two system states via DAT_007cd8c0 (IDs 0x19, 0x1A), calls FUN_00477280 for each non-null state.

**Key logic:**
- Calls virtual on *DAT_007cd8c0+0x1C(0x19) — state A
- If non-null: calls FUN_00477280(param_1)
- Calls virtual on *DAT_007cd8c0+0x1C(0x1A) — state B
- If non-null: calls FUN_00477280(param_1)
- Returns 0

**Globals:**
- `DAT_007cd8c0` — system state object

**Calls:**
- FUN_00477280 — conditional action

**Used by system:** docs/20-math-utilities.md — state-checked dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00485630 — Destructor with VTable

Source: unknown | Confidence: high
Sets vtable, calls FUN_00487250, conditionally frees param_1.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005ab080
- Calls FUN_00487250()
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1)
- Returns param_1

**Calls:**
- FUN_00487250 — destructor body
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486320 — Struct Field Accessor (+0x8C)

Source: unknown | Confidence: high
Returns value at param_1 + 0x8C.

**Key logic:**
- Returns *(param_1 + 0x8C)

**Used by system:** docs/20-math-utilities.md — field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486f00 — Guarded Conditional Render Call

Source: unknown | Confidence: medium
If param_2 (flag) and guard at +0x98 are both non-zero, calls FUN_00499050 with four field values.

**Key logic:**
- If param_2 != 0 AND *(param_1+0x98) != 0:
  - Calls FUN_00499050(*(param_1+4), *(param_1+8), *(param_1+0xC), *(param_1+0x10))

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | field_a | undefined4 | Passed to FUN_00499050 |
| +0x08 | field_b | undefined4 | Passed to FUN_00499050 |
| +0x0C | field_c | undefined4 | Passed to FUN_00499050 |
| +0x10 | field_d | undefined4 | Passed to FUN_00499050 |
| +0x98 | guard | int | Enables dispatch |

**Calls:**
- FUN_00499050 — render/graphics call (docs/20)

**Used by system:** docs/20-math-utilities.md — guarded render dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00487900 — State Change Handler with Subscriber Notification

Source: unknown | Confidence: medium
Handles state change, notifies subscribers via linked list, dispatches different actions for active vs inactive states.

**Key logic:**
- Calls FUN_00486710() for current state
- If param_2 != current: calls vtable+0x2C (changed signal)
- Calls FUN_00486660(param_2)
- If param_2 == 0 (inactive): calls FUN_00487740() + FUN_00487830()
- Else (active): calls vtable+0x40(4)
- Walks subscriber list at param_1[0x24], calls each subscriber's vtable+0x38(param_2)
- Uses FUN_00486320() as list iterator advance

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x24 | subscriber_list | int* | Linked list of subscriber objects |

**Calls:**
- FUN_00486710 — state query
- FUN_00486660 — state set
- FUN_00487740/FUN_00487830 — inactive handlers
- FUN_00486320 — list iterator

**Used by system:** docs/20-math-utilities.md — state change notification

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00488bd0 — Field Setter (+0xE4)

Source: unknown | Confidence: high
Sets value at param_1+0xE4 to param_2.

**Key logic:**
- Sets *(param_1 + 0xE4) = param_2

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b420 — Constructor with String Copy

Source: unknown | Confidence: medium
Complex constructor that sets vtable, allocates buffer, copies input string to both buffer and alternate location.

**Key logic:**
- Calls FUN_00485e30() — parent init
- Sets *param_1 = &PTR_FUN_005abed0
- If param_2 == 0: uses param_1+0xE6 as default buffer
- Stores buffer at param_1[0xBC]
- Calls FUN_0048b4f0() — post-init
- If param_4 > 0: calls FUN_0048b8f0(param_4) — size config
- Sets param_1[0xBF] = 0
- If param_3 (string) != NULL:
  - Computes string length
  - If length < param_4: copies string to buffer at param_1[0xBC]
  - Also copies string to alternate location at param_3 + (0x1E7 - param_3)
- Stores param_7 at param_1+0xE5
- Stores param_5 at param_1+0xE2
- Stores param_6 at param_1[0xBA]

**Calls:**
- FUN_00485e30 — parent init
- FUN_0048b4f0 — post-init
- FUN_0048b8f0 — size config

**Used by system:** docs/20-math-utilities.md — string constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048ca50 — Linked List Destructor (Cleanup + Free)

Source: unknown | Confidence: medium
Destructor that walks a linked list at param_1[199], freeing each node with optional virtual call cleanup.

**Key logic:**
- Sets *param_1 = &PTR_FUN_005ac048
- Walks list at param_1[199]: for each node with flag[3] and *node != NULL:
  - Calls (*(code*)**(node[0]))(1) — vtable cleanup
  - Frees node with FUN_00587bcf
- Zeros: param_1[199], param_1[200], param_1[0xC9], param_1[0xCA] (twice)
- Calls FUN_0048c0d0() — final cleanup

**Calls:**
- FUN_00587bcf — free
- FUN_0048c0d0 — final cleanup

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e070 — Constructor (Zero Init + Defaults)

Source: unknown | Confidence: high
Constructs an object with zero init, -1 sentinel, vtable set, and path registry reset.

**Key logic:**
- Calls FUN_00485e30() — parent init
- Sets param_1[0x3A] = 0
- Sets param_1[0x3B] = 0xFFFFFFFF (-1 sentinel)
- Sets *param_1 = &PTR_FUN_005ac3e0
- Sets param_1[0x38] = param_1[0x39] = 0
- Calls FUN_00566650(0) — reset path registry

**Calls:**
- FUN_00485e30 — parent init
- FUN_00566650 — path registry reset (docs/08)

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048f5d0 — Doubly-Linked List Append

Source: unknown | Confidence: medium
Allocates a 4-field node (16 bytes) and appends it to a doubly-linked list.

**Key logic:**
- If param_2 == 0: return (no-op)
- Allocates 16-byte node via operator_new
- Initializes node: [0]=param_2, [1]=0, [2]=0, [3]=param_3
- If list head at param_1+0xF0 is empty: sets head=tail=node
- Else: inserts after tail at param_1+0xF4, links prev/next
- Updates tail to node, increments count at param_1+0xFC

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xF0 | head | int* | List head |
| +0xF4 | tail | int* | List tail |
| +0xF8 | tail_prev | int* | Previous tail |
| +0xFC | count | int | Node count |

**Used by system:** docs/20-math-utilities.md — linked list append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004902a0 — Conditional Free (Destructor Pattern)

Source: unknown | Confidence: high
Calls cleanup function, conditionally frees param_1.

**Key logic:**
- Calls FUN_004902c0() — cleanup
- If (param_2 & 1) != 0: calls FUN_00587bcf(param_1)
- Returns param_1

**Calls:**
- FUN_004902c0 — cleanup
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004915a0 — AABB Overlap Test (Short-Coordinate)

Source: unknown | Confidence: high
Axis-aligned bounding box overlap test using short coordinates (4 shorts per box). Returns 1 if boxes overlap, else masked 0.

**Key logic:**
- Takes box with 4 shorts: [0]=x, [1]=y, [2]=width, [3]=height
- Checks: param_2 <= box.x < param_2+param_4 (x overlap)
- Checks: param_3 <= box.y < param_3+param_5 (y overlap)
- Checks: box.x + box.width <= param_2+param_4 (right edge)
- Checks: box.y + box.height <= param_3+param_5 (bottom edge)
- Returns CONCAT31(1, (char)(box.y >> 8)) on overlap, else masked 0

**Used by system:** docs/20-math-utilities.md — collision / AABB test

**Algorithm family:** AABB overlap

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491db0 — Linked List Destructor (Conditional Free)

Source: unknown | Confidence: high
Walks a singly-linked list, frees each node (and optionally its content), zeros list head/tail.

**Key logic:**
- Walks list from *param_1: for each node:
  - If node[2] (flag) != 0 AND *node (data) != 0: frees *node
  - Frees node
- Zeros param_1[0..3]

**Calls:**
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — linked list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495020 — Multi-Step Init Sequence

Source: unknown | Confidence: medium
Calls four initialization/setup functions in sequence.

**Key logic:**
- Calls FUN_004f9f00()
- Calls FUN_00553700(DAT_008b8dc8) — register global
- Calls FUN_004f9b30(0)
- Calls FUN_004f9f30()

**Globals:**
- `DAT_008b8dc8` — global resource/data pointer

**Calls:**
- FUN_004f9f00, FUN_00553700, FUN_004f9b30, FUN_004f9f30

**Used by system:** docs/20-math-utilities.md — init sequence

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00495a20 — Doubly-Linked List Node Unlink

Source: unknown | Confidence: high
Unlinks a specific node from a doubly-linked list with prev/next pointers at +0x68/+0x64.

**Key logic:**
- If param_2 != 0: searches list at param_1+0x14 for node matching param_2
- Traverses via next pointer at +0x64 (100 decimal)
- If found: unlinks by updating prev[+0x64] and next[+0x68] pointers
- Updates head at param_1+0x14 or tail at param_1+0x18 if needed

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x14 | head | int | List head |
| +0x18 | tail | int | List tail |

**Node offsets:** +0x64=next, +0x68=prev

**Used by system:** docs/20-math-utilities.md — linked list unlink

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497590 — Dual Field Setter + Process Call

Source: unknown | Confidence: medium
Sets two fields and calls a processing function.

**Key logic:**
- Sets *(param_2+0x40) = param_1
- Sets *(param_2+0x98) = param_3
- Calls FUN_00499360(param_2)

**Calls:**
- FUN_00499360 — process/update

**Used by system:** docs/20-math-utilities.md — field setter + process

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00498880 — Dual Field Read

Source: unknown | Confidence: high
Reads two fields and outputs through pointer parameters.

**Key logic:**
- *param_2 = *(param_1 + 0x5C)
- *param_3 = *(param_1 + 0x60)

**Used by system:** docs/20-math-utilities.md — field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499050 — Guarded Sub-Rectangle Render Dispatch

Source: unknown | Confidence: medium
Checks a type field, computes rectangle from params, dispatches to two render functions.

**Key logic:**
- If *(*(param_1+0x54)+0x28) == 2 (type check):
  - Computes width = param_3 - param_2, height = param_5 - param_4
  - Calls FUN_00490920(param_4, param_2, height, width)
  - Calls FUN_004918d0(param_4, param_2, height, width)

**Calls:**
- FUN_00490920 — render/submit function
- FUN_004918d0 — render/submit function

**Used by system:** docs/20-math-utilities.md — guarded render dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00499870 — Linked List Iterator Advance

Source: unknown | Confidence: medium
Advances to next element in a linked list, returns packed result (valid flag + data).

**Key logic:**
- If param_1+0x10 == 0 (no current element): returns 0
- Reads current from param_1+0x0C
- If current[0x0C] != 0: advances to next via current[0x0C][4] (linked list next)
- If no next: current = 0
- Else: reads data = *(*next_node), stores in param_1+0x10
- If data != 0: calls FUN_00498e30() to set param_1+0x14
- Returns CONCAT31(hi-byte-of-data, data != 0)

**Used by system:** docs/20-math-utilities.md — linked list iterator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499da0 — Tree/Node Recursive Destructor

Source: unknown | Confidence: high
Recursively frees a tree-like structure. If param_2 is null, uses param_1+8 as default. Frees node and recurses to children at +0x24 and +0x28.

**Key logic:**
- If param_2 is null: uses address param_1+8
- If *param_2 != 0:
  - Recurses to (*param_2) + 0x28 and (*param_2) + 0x24
  - Calls FUN_00499b50() — node cleanup
  - Frees *param_2 via FUN_00587bcf
- Zeros *param_2 and *(param_1+0xC)

**Calls:**
- FUN_00499b50 — node cleanup
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — tree destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a210 — String-Matched Linked List Search

Source: unknown | Confidence: medium
Searches a linked list for a node matching a string via FUN_00588410 (string compare).

**Key logic:**
- If param_2 != 0: iterates list from *param_1
  - For each node: calls FUN_00499e20() to get string, compares with param_2 via FUN_00588410
  - If match: returns node pointer
  - Advances via FUN_00499e00()
- Returns 0 if not found

**Calls:**
- FUN_00499e20 — get node string
- FUN_00588410 — string compare (docs/08)
- FUN_00499e00 — list advance

**Used by system:** docs/20-math-utilities.md — string-keyed list search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049aa70 — Position Update (Add Offsets)

Source: unknown | Confidence: high
Updates position by adding deltas to base values.

**Key logic:**
- Sets *(param_1+0x10) = *(param_1+0x0C) + param_2 (x)
- Sets *(param_1+8) = *(param_1+4) + param_3 (y)

**Used by system:** docs/20-math-utilities.md — position update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049d440 — Format + Register Dispatch

Source: unknown | Confidence: medium
Formats a buffer, dispatches to FUN_00553070 with a value from param_1+0x10 chain.

**Key logic:**
- Calls FUN_0049c6d0(local_10, 0xF) — format buffer with size 15
- Calls FUN_00553070(local_10, 4, 0, *(*(param_1+0x10)+0x54)) — register/dispatch

**Calls:**
- FUN_0049c6d0 — format
- FUN_00553070 — register/dispatch (docs/21? audio)

**Used by system:** docs/20-math-utilities.md — format + register

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ed00 — Field Setter + Trigger

Source: unknown | Confidence: high
Sets a field and triggers a function call.

**Key logic:**
- Sets *(param_1+0x1C) = param_2
- Calls FUN_0049ed30()

**Calls:**
- FUN_0049ed30 — trigger

**Used by system:** docs/20-math-utilities.md — setter + trigger

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0d90 — Set Global Flag

Source: unknown | Confidence: high
Sets global DAT_007ce25c to 1.

**Key logic:**
- DAT_007ce25c = 1

**Globals:**
- `DAT_007ce25c` — global flag (unknown module)

**Used by system:** docs/20-math-utilities.md — global flag setter

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1dc0 — Linked List Append (Guarded)

Source: unknown | Confidence: medium
Appends a node to a linked list if guard byte at param_1[4] is non-zero and param_2 is valid.

**Key logic:**
- If param_1[4] (guard) != 0 AND param_2 != 0:
  - Allocates 12-byte node via operator_new: [0]=param_2, [1]=0, [2]=0
  - If list at *param_1 is empty: sets head=tail=*param_1=node
  - Else: appends after tail at param_1[1]
  - Increments count at param_1[3]

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | head | int | List head |
| +0x04 | tail | int | List tail |
| +0x08 | tail2 | int | Secondary tail |
| +0x0C | count | int | Node count |
| +0x10 | guard | byte | Enable guard |

**Used by system:** docs/20-math-utilities.md — guarded list append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004A3570 � Bitmask-Controlled Element Reset with Interpolation

Source: unknown | Confidence: high
Resets elements based on bitmask flags. Bit 0 triggers counter decrement and element field reset to -1.0f. Bit 1 drives interpolation update on all elements.

**Key logic:**
- If (*param_1 & 1) AND param_1[8] > 0:
  - Decrements param_1[8] � element count
  - Loop  ..param_1[0xc] times (stride 0x78):
    - Sets *(param_1[0x10] + 0x44 + i*0x78) = 0xbf800000 = -1.0f
    - FUN_004a2840(0) � piecewise linear interpolation reset (docs/20)
- If (*param_1 & 2):
  - Loop  ..param_1[0xc] times:
    - FUN_004a2840(param_2 - param_1[4]) � interpolation with offset

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ControlFlags | byte | bit 0 = decrement+reset, bit 1 = interpolate |
| +0x04 | OffsetValue | float | used as base offset for interpolation |
| +0x08 | Counter | int | decremented when bit 0 set |
| +0x0c | ElementCount | int | number of elements to process |
| +0x10 | ElementArray | int* | pointer to element array (stride 0x78) |

**Calls:** FUN_004a2840 (piecewise linear interpolation, docs/20)

**Moddability:** configurable (bitmask flags, offsets)

<!-- target: docs/20-math-utilities.md -->

## FUN_004a5c10 — Guarded Call with Check

Source: unknown | Confidence: medium
Calls FUN_004a5820, then calls FUN_004a4830 only if the result is non-zero.

**Key logic:**
- iVar1 = FUN_004a5820(param_1)
- If iVar1 == 0: return
- Else: call FUN_004a4830()

**Calls:**
- FUN_004a5820 — check/query
- FUN_004a4830 — action

**Used by system:** docs/20-math-utilities.md — guarded call

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1990 — VTable + Fields Init

Source: unknown | Confidence: high
Initializes a 5-field struct with sentinel values (-1) and vtable.

**Key logic:**
- Sets param_1[1] = 0
- Sets param_1[2] = 0xFFFFFFFF (-1)
- Sets param_1[3] = 0
- Sets param_1[4] = 0xFFFFFFFF (-1)
- Sets *param_1 = &PTR_LAB_005acbcc (vtable)

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b21d0 — Callback Registration (atexit-style)

Source: unknown | Confidence: high
Registers code at LAB_004b21e0 via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_004b21e0)
- Returns void

**Calls:**
- FUN_00587b3e — callback registration

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2aa0 — Bitfield Set/Clear by Index

Source: unknown | Confidence: high
Sets or clears a single bit in a bitfield at param_1+0x30 by bit index.

**Key logic:**
- Computes mask = 1 << (param_2 & 0x1F)
- Sets bit to (param_3 & 1): result = (bitfield & ~mask) | ((param_3 & 1) << (param_2 & 0x1F))

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x30 | bitfield | uint | 32-bit bitfield |

**Used by system:** docs/20-math-utilities.md — bitfield manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b3d40 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004b3db0.

**Key logic:**
- Calls FUN_004b3db0()
- Returns void

**Calls:**
- FUN_004b3db0

**Used by system:** docs/20-math-utilities.md — dispatch wrapper

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4f50 — Dual Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004ff670 then FUN_004b4f70, returns param_1.

**Key logic:**
- Calls FUN_004ff670()
- Calls FUN_004b4f70()
- Returns param_1

**Calls:**
- FUN_004ff670
- FUN_004b4f70

**Used by system:** docs/20-math-utilities.md — dispatch wrapper

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9860 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004b5be0.

**Key logic:**
- Calls FUN_004b5be0()

**Calls:**
- FUN_004b5be0

**Used by system:** docs/20-math-utilities.md — dispatch wrapper

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba6c0 — Two-Path Dispatch (Mode 1/2)

Source: unknown | Confidence: medium
Dispatches based on *param_1 value (1 or 2) with state checks.

**Key logic:**
- If *param_1 == 1: checks DAT_007c56ac, FUN_00461db0, DAT_007cc4c8
- Else if *param_1 == 2: calls FUN_004b9a00() then possibly FUN_004cfcc0()

**Globals:** DAT_007c56ac, DAT_007cc4c8, DAT_007d0080

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004bae20 — Linked List Remove by Value

Source: unknown | Confidence: medium
Searches list for value, removes node, frees content and node.

**Calls:** FUN_004b0170, FUN_00587bcf

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bbf20 — Progress Bar Increment

Source: unknown | Confidence: medium
Increments global counter, calls progress bar.

**Globals:** DAT_0083ee60, DAT_008aae64, _DAT_008afea0

**Calls:** FUN_004b33b0 (docs/09)

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004bdb10 — Sphere Proximity Tag

Source: unknown | Confidence: medium
Sphere proximity test, tags matching objects.

**Algorithm family:** Sphere proximity

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004c1700 — Double List Cleanup

Source: unknown | Confidence: medium
Cleans two linked lists, frees nodes.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2c40 — Running Average Filter

Source: unknown | Confidence: high
Running avg with hard clamp limits.

**Algorithm family:** Running average

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c5130 — List Indexed Accessor

Source: unknown | Confidence: high
Indexed list access with head fallback.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8210 — List Destructor with Sub-Free

Source: unknown | Confidence: medium
Frees linked list with sub-pointer cleanup.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8ee0 — Singleton Init

Source: unknown | Confidence: high
First-call init with rand, counter on subsequent.

**Globals:** DAT_008ac4dc, DAT_008ac4d8

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9d30 — Recursive Tree Free

Source: unknown | Confidence: high
Recursive free of tree node at +0x24.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ce860 — String List Lookup

Source: unknown | Confidence: medium
Normalizes string, searches list.

**Calls:** FUN_00589901, FUN_004cdbf0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d2260 — Progress Bar + Data Store

Source: unknown | Confidence: medium
Progress increment, stores two values.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5984 — Field Setter

Source: unknown | Confidence: low
Sets field via unaff_ESI, calls sub-function.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7cf0 — Float Wrap + Table Interpolation

Source: unknown | Confidence: medium
Wraps float, interpolates in table.

**Algorithm family:** Table interpolation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d88b0 — Iterator Check

Source: unknown | Confidence: medium
Calls function, checks completion.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004db520 — Triple Virtual Call

Source: unknown | Confidence: medium
Three virtual calls in sequence.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc660 — Scaled Texture Render

Source: unknown | Confidence: medium
Renders texture with scale, restores original.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd450 — Float Vector Init

Source: unknown | Confidence: high
(1.0, 0, 0, 0, 0)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dfb00 — Large Zero Init

Source: unknown | Confidence: high
28 dwords, 0.25 default at [6].

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e4fb0 — Angular Velocity Integration

Source: unknown | Confidence: medium
Physics angular velocity with 3 paths.

**Used by system:** docs/18-physics-dynamics.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f3040 — Zero Init (20 dwords)

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8ab0 — Conditioned Float Read

Source: unknown | Confidence: medium
Returns float at slot or zero based on flag.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9230 — Path Dispatch

Source: unknown | Confidence: high
Calls FUN_004f9200(DAT_005ec48c).

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004fc280 — Multi-Field Reset

Source: unknown | Confidence: high
Resets many fields, frees two sub-pointers.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005000c0 — Passthrough Wrapper

Source: unknown | Confidence: high
Calls FUN_004ff680 with 4th arg 0.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00501992 — DDS Header Parsing

Source: unknown | Confidence: high
Parses DDS texture header, loads pixels.

**Used by system:** docs/19-renderer.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00503f75 — 2x Box Downscale

Source: unknown | Confidence: medium
2x2 pixel averaging filter.

**Algorithm family:** Box downscale

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050a8d9 — Render Format Constructor

Source: unknown | Confidence: high
Init with 32-bit depth, type 1.

**Used by system:** docs/19-renderer.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b3b5 — Render Format Constructor 2

Source: unknown | Confidence: high
Init with 32-bit depth, type 2.

**Used by system:** docs/19-renderer.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c026 — Destructor

Source: unknown | Confidence: high
Calls thunk, conditional free.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c9a9 — Bilinear Interp 4-Component

Source: unknown | Confidence: high
4-component bilinear interpolation.

**Algorithm family:** Bilinear interpolation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050dc90 — Indirect Call

Source: unknown | Confidence: high
Calls setup then function pointer.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0050edd2 — Two-Thunk Wrapper

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005111d3 — JPEG Marker Reader

Source: unknown | Confidence: high
Reads JPEG markers from byte stream.

**Used by system:** docs/19-renderer.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005122b2 — Media Format Query

Source: unknown | Confidence: medium
Queries format type, data, sample size.

**Used by system:** docs/21-audio-network-internals.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513e2d — Matrix Scale by W

Source: unknown | Confidence: high
16 float4 vectors scaled by W component.

**Algorithm family:** Matrix scaling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051613f — Chunked Buffer Alloc

Source: unknown | Confidence: medium
Allocates buffer with chunk limit.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00517927 — Function Table Init

Source: unknown | Confidence: high
Sets 8 function pointers.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005198b3 — Media Buffer Alloc

Source: unknown | Confidence: medium
Allocates media buffer per channel.

**Used by system:** docs/21-audio-network-internals.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051ea90 — Codec Mode Select

Source: unknown | Confidence: medium
Selects decode function by mode.

**Used by system:** docs/21-audio-network-internals.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00526b55 — 3DNow Vector Transform

Source: unknown | Confidence: medium
SIMD vector transform with 3DNow!

**Algorithm family:** SIMD

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052d990 — Virtual Cleanup

Source: unknown | Confidence: high
Calls vtable, nulls pointer.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00534ac0 — Callback Registration

Source: unknown | Confidence: high
atexit-style via FUN_00587b3e.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00536130 — Big-Endian Short Writer

Source: unknown | Confidence: high
Writes ushort as 2 bytes big-endian.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053ac40 — Table Lookup + Scale

Source: unknown | Confidence: medium
Indexed table lookup with multiplier.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053bde0 — 4-Element Dot Product

Source: unknown | Confidence: high
Weighted dot product (first term zero).

**Algorithm family:** Dot product

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053ca00 — Search Path Prune

Source: unknown | Confidence: medium
Removes flagged path entries.

**Used by system:** docs/08-file-formats.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d880 — Field Accessor (+0x8)

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00541500 — Scene State Setup

Source: unknown | Confidence: medium
Render state with float constants.

**Used by system:** docs/19-renderer.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005432f0 — Clipped Rect Render

Source: unknown | Confidence: medium
Computes clipped rect, dispatches.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00546430 — Conditional Zero

Source: unknown | Confidence: high
Zeros +0x94/+0x98 if bit 1 clear at +0x9C.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547420 — Two List Cleanup

Source: unknown | Confidence: medium
Frees two linked lists.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00549020 — String List Append

Source: unknown | Confidence: medium
Appends string to list, allocates nodes.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054b3f0 — Offset Dispatch

Source: unknown | Confidence: medium
Adds offset, dispatches.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0054e0f0 — Wrapper

Source: unknown | Confidence: high
Calls FUN_00540da0.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fe00 — Inverse Scale

Source: unknown | Confidence: high
Sets field = 1/param_2.

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_005568b0 — 512x Constructor Loop

Source: unknown | Confidence: high
Calls FUN_00548e00() 0x200 times.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c040 — Global Dispatch

Source: unknown | Confidence: high
Calls FUN_0053ead0(DAT_008b8f0c).

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_005631a0 — Two-Step Dispatch

Source: unknown | Confidence: high
Gets value, dispatches.

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00566bd0 — Conditional Dispatch

Source: unknown | Confidence: medium
Branches on flag at param_1[4].

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0056cf70 — 3x3 Matrix-Vector Multiply (Double)

Source: unknown | Confidence: high
Two double-precision 3x3 matrix-vector ops.

**Algorithm family:** 3x3 matrix-vector multiply

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a980 — Entity Constructor Wrapper

Source: unknown | Confidence: high
Calls FUN_00599958 (docs/08).

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00583a80 — Destructor

Source: unknown | Confidence: high
Cleanup + conditional free.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587100 — Negated Predicate

Source: unknown | Confidence: high
NOT of FUN_00587510.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587b96 — Empty Stub

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a65f — SEH Trampoline

Source: unknown | Confidence: low
Conditional SEH call.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058da70 — __trandisp1 (CRT)

Source: crt | Confidence: high
MSVC float classification.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00594bcd — Counter + Threshold

Source: unknown | Confidence: medium
Increments counter, triggers at threshold.

**Globals:** DAT_008d41b8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059801a — Bitfield Manager

Source: unknown | Confidence: medium
Get/set bit 7 in indexed array.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005997f5 — Fixed Delegation

Source: unknown | Confidence: high
Calls FUN_00599e66(0).

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0059af50 — VTable Constructor

Source: unknown | Confidence: high
Calls FUN_0059ae7d, sets vtable.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c6e8 — SEH Unwind

Source: unknown | Confidence: high
Frees at EBP+8.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cdc0 — Unwind Thunk to 0x00581880

Source: unknown | Confidence: high

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d4c0 — Unwind Thunk to 0x00598c70

Source: unknown | Confidence: high

**Moddability:** hardcoded

## FUN_0050c5bd — Thunk to thunk_FUN_0050c5b0 (Matrix Apply Indirect)

Source: unknown | Confidence: high
Trampoline — indirect jump through PTR_FUN_005d77f0. No local logic.

**Key logic:**
- Single indirect jmp through pointer stored at PTR_FUN_005d77f0
- Target is thunk_FUN_0050c5b0 — applies final transform / matrix operation in renderer pipeline
- Address 0x0050c5bd referenced via runtime dispatch table (vtable or function pointer)

**Calls:** thunk_FUN_0050c5b0 (matrix apply/final transform — docs/19-renderer.md)

**Used by system:** docs/19-renderer.md — renderer transform pipeline

<!-- target: docs/01-engine-architecture.md -->

## FUN_005523e0 — Hash Table / String Table Entry Default Init

Source: unknown | Confidence: medium
Initialize a 0x874-byte hash table node struct with default constants.

**Key logic:**
- Calls FUN_0053c2a0() (parent/sub-system init)
- Sets int/float fields to default values:
  - Fields [0], [1], [0x17], [0x18] = 1.0f (float, scale/weight defaults)
  - Fields [0xd..0x10] = 1
  - Fields [2..4], [0xb], [0xc], [0x11], [0x13], [0x19], [0x21a..0x21c] = 0
  - Field [5] byte = 0
  - Field [9] = 0x10000 (flag constant)
  - Field [0x12] = 0xc0ffffff (encoding/sentinel constant)
  - Field [0x14] = 0xc0 = 192 (max size or count)
  - Field [0x15] = 0x10002 (flag/type constant)
  - Field [0x16] = 0x7f = 127 (threshold/max length)

**Struct offsets (param_1):**
| Offset | Type | Default | Notes |
|--------|------|---------|-------|
| +0x00 | float | 1.0f | scale/weight |
| +0x04 | float | 1.0f | scale/weight |
| +0x24 | int | 0x10000 | flag constant |
| +0x48 | int | 0xc0ffffff | sentinel |
| +0x50 | int | 192 | max count |
| +0x54 | int | 0x10002 | flag constant |
| +0x58 | int | 127 | threshold |
| +0x5c | float | 1.0f | scale/weight |
| +0x868 | int | 0 | |
| +0x86c | int | 0 | |
| +0x870 | int | 0 | |

**Calls:** FUN_0053c2a0 (parent struct init)

**Used by system:** docs/06-session-race-logic.md — hash table node allocation

<!-- target: docs/01-engine-architecture.md -->

## FUN_00559390 — Struct Field Init (3 consecutive fields)

Source: unknown | Confidence: high
Initialize three consecutive struct fields at offsets +0x14, +0x18, +0x1c.

**Key logic:**
- Sets param_1+0x14 = param_2 (copy input)
- Sets param_1+0x18 = param_3 (copy input)
- Sets param_1+0x1c = 0 (zero-initialized)
- No return value

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x14 | undefined4 | from param_2 |
| +0x18 | undefined4 | from param_3 |
| +0x1c | undefined4 | zero fixed |

**Calls:** None

**Used by system:** docs/20-math-utilities.md — generic struct initialization helper

<!-- target: docs/01-engine-architecture.md -->

## FUN_00560b60 — Int Array Allocation

Source: unknown | Confidence: high
Allocate array of ints and store pointer in struct.

**Key logic:**
- Sets param_1[0] = 0 (count/flag = 0)
- Calls operator_new(param_2 * 4) — allocates param_2 × 4 bytes (param_2 int elements)
- Stores allocated pointer to param_1[1]
- Returns param_1

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int | count/flag, initialized 0 |
| +0x04 | int* | allocated array pointer |

**Calls:** operator_new (heap allocation)

**Used by system:** docs/20-math-utilities.md — array allocation utility

<!-- target: docs/08-file-formats.md -->

## FUN_00567900 — Struct Init with Conditional Default Read

Source: unknown | Confidence: medium
Initialize struct fields with defaults; conditionally read callback default from source object.

**Key logic:**
- Initializes fields 4–7, 9–10 to default values (0, -1, 0, -1, 0, 0)
- Sets *param_1 = param_2 (source reference)
- Sets fields 1–3 to 0
- If param_2 != 0: calls FUN_004979d0(param_2) which reads *(param_2 + 0x20)
- Stores result (or -1 if param_2 == 0) in field 8
- Returns param_1

**Struct offsets (param_1):**
| Offset | Type | Default | Notes |
|--------|------|---------|-------|
| +0x00 | int | param_2 | source reference |
| +0x04 | int | 0 | field |
| +0x08 | int | 0 | field |
| +0x0c | int | 0 | field |
| +0x10 | int | 0 | field |
| +0x14 | int | -1 | default sentinel |
| +0x18 | int | 0 | field |
| +0x1c | int | -1 | default sentinel |
| +0x20 | int | FUN_004979d0(param_2) or -1 | value read from source+0x20 |

**Calls:** FUN_004979d0 (read value at source+0x20)

**Used by system:** docs/20-math-utilities.md — struct initialization utility

<!-- target: docs/20-math-utilities.md -->

## FUN_00569280 — Copy 6 Dwords to Struct + Call

Source: unknown | Confidence: medium
Copy 6 int-sized values from source array to struct at offset +0x7c, then call update function.

**Key logic:**
- Copies 6 dwords (24 bytes) from param_2 to param_1+0x7c
- Calls FUN_00569410 after copy
- Simple memcpy-like loop with 6 iterations

**Struct offsets (param_1):**
| Offset | Size | Notes |
|--------|------|-------|
| +0x7c | 24 bytes (6 × int) | copied from param_2 array |

**Calls:** FUN_00569410 (post-copy update/notification)

**Used by system:** docs/20-math-utilities.md — data copy utility

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585e80 — Index-to-Bitmask Conversion

Source: unknown | Confidence: high
Convert a bit index (0–N) to byte offset and bitmask.

**Key logic:**
- *param_2 = param_1 >> 3 (byte offset = index / 8)
- *param_3 = 1 << (param_1 & 7) (bitmask with bit position within byte)
- Allows bit-level access in a byte array

**Algorithm family:** Bit manipulation — index to byte-offset + bitmask conversion

**Used by system:** docs/20-math-utilities.md — bitmap/flag array access utility

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058dca0 -- x87 FP Exponentiation (f2xm1/fscale)

Source: unknown | Confidence: high
Compute 2^x using x87 FPU instructions f2xm1 and fscale.

**Key logic:**
- Uses x87 FP exponentiation algorithm:
  - f2xm1(-(fractional_part)) -> compute 2^frac - 1
  - Adds 1 back -> 2^frac
  - fscale by integer part -> 2^int * 2^frac = 2^x
- ROUND(in_ST0) separates integer and fractional parts
- Result = 2^(in_ST0) computed entirely in x87 extended precision (float10)

**Algorithm family:** FP exponentiation -- x87 transcendental (2^x)

**Used by system:** docs/20-math-utilities.md -- FP math library

<!-- target: docs/20-math-utilities.md -->

## FUN_0059067e -- __cintrindisp1 (CRT Internal Dispatch)

Source: unknown | Confidence: high
MSVC CRT internal dispatch -- calls __trandisp1 then FUN_0059070a.

**Key logic:**
- Calls __trandisp1() (CRT transfer dispatch)
- Calls FUN_0059070a() (CRT locale/init continuation)

**Calls:** __trandisp1, FUN_0059070a (CRT internal init)

**Used by system:** docs/20-math-utilities.md -- MSVC CRT runtime support

<!-- target: docs/01-engine-architecture.md -->

## FUN_005989d7 -- Locale Object Constructor with Vtable Init

Source: unknown | Confidence: medium
MSVC CRT locale object constructor -- sets vtable pointers and calls initialization.

**Key logic:**
- Calls FUN_0058a5d8 (CRT sub-init)
- Sets vtable pointer to DAT_005b9bb8 on success
- Initializes fields at [10] = 0, [1] = PTR_FUN_005b9bb4
- Sets second vtable pointer to PTR_LAB_005b9bac
- Conditionally calls FUN_005993eb with saved parameters if flag set
- Restores ExceptionList from stack frame

**Calls:** FUN_0058a5d8, FUN_005993eb (locale initialization)

**Used by system:** docs/20-math-utilities.md -- MSVC CRT locale support

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a948 -- Struct Field Init with Conditional Call

Source: unknown | Confidence: medium
Initialize struct fields at offsets +0x08 to +0x1c, conditionally call FUN_00598c1c.

**Key logic:**
- If param_1 != -0x20 (0xffffffe0): calls FUN_00598c1c()
- Sets offset +0x08=0, +0x0c=0x201, +0x10=6, +0x14=0, +0x18=0, +0x1c=0
- Calls FUN_0059a5fe(0, 0)

**Struct offsets (param_1):**
| Offset | Type | Value | Notes |
|--------|------|-------|-------|
| +0x08 | int | 0 | |
| +0x0c | int | 0x201 | version/type constant |
| +0x10 | int | 6 | size/count |
| +0x14 | int | 0 | |
| +0x18 | int | 0 | |
| +0x1c | int | 0 | |

**Calls:** FUN_00598c1c, FUN_0059a5fe

**Used by system:** docs/20-math-utilities.md -- struct initialization

<!-- target: docs/20-math-utilities.md -->

## FUN_0059b5c0 -- Bitmap Allocation Tracker

Source: unknown | Confidence: high
Allocate and track a range of bits in a bitmap; clear bits and return index.

**Key logic:**
- Calls FUN_0059b490(param_2) and FUN_0059b530() (validation/prep)
- Writes two shorts into a tracking array at param_1[2] + param_1[5]*4: first short = param_1[4] (start index), second short = param_2 (count)
- Clears a range of bits (param_1[4] to param_1[4]+param_2) in bitmap at *param_1
- Returns index via *param_3 = param_1[5], then increments counters
- Returns success flag (1)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | bitmap pointer |
| +0x08 | int* | tracking array |
| +0x10 | int | current start position |
| +0x14 | int | current allocation index |

**Algorithm family:** Bitmap allocation tracker -- contiguous range allocator in a bit array

**Used by system:** docs/01-engine-architecture.md -- resource/slot allocation

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c4a0 -- SEH Unwind Cleanup (Free at EBP-0x14)

Source: unknown | Confidence: high
SEH unwind handler: frees object at stack offset EBP-0x14.

**Key logic:**
- Calls FUN_00587bcf on value at *(EBP-0x14)
- Standard C++ object destructor dispatch during stack unwinding

**Calls:** FUN_00587bcf (free/destructor)

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c5f8 -- SEH Unwind Cleanup (Free at EBP+8)

Source: unknown | Confidence: high
SEH unwind handler: frees object at stack offset EBP+8.

**Key logic:**
- Calls FUN_00587bcf on value at *(EBP+8)

**Calls:** FUN_00587bcf (free/destructor)

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c6f2 -- SEH Unwind Cleanup (Free at EBP+8)

Source: unknown | Confidence: high
SEH unwind handler: frees object at stack offset EBP+8. Identical to Unwind_0059c5f8.

**Key logic:**
- Calls FUN_00587bcf on value at *(EBP+8)

**Calls:** FUN_00587bcf (free/destructor)

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c880 -- SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00581b30.

**Key logic:**
- Calls FUN_00581b30() (cleanup callback dispatch)

**Calls:** FUN_00581b30

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059ca50 -- SEH Unwind Cleanup (Free at EBP-0x114)

Source: unknown | Confidence: high
SEH unwind handler: frees object at stack offset EBP-0x114.

**Key logic:**
- Calls FUN_00587bcf on value at *(EBP-0x114)

**Calls:** FUN_00587bcf (free/destructor)

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cc40 -- SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00583570.

**Key logic:**
- Calls FUN_00583570() (cleanup callback dispatch)

**Calls:** FUN_00583570

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059ce20 -- SEH Unwind Free Object at -0x10

Source: unknown | Confidence: high
SEH unwind handler: frees object at stack offset EBP-0x10.

**Key logic:**
- Calls FUN_00587bcf on value at *(EBP-0x10)

**Calls:** FUN_00587bcf (free/destructor)

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cfa2 -- SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_00586070 as unwind cleanup handler.

**Key logic:**
- Calls FUN_00586070()

**Calls:** FUN_00586070

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d0eb -- SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_00581880 as unwind cleanup handler.

**Key logic:**
- Calls FUN_00581880()

**Calls:** FUN_00581880

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d2c7 -- SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_00598c70 as unwind cleanup handler.

**Key logic:**
- Calls FUN_00598c70()

**Calls:** FUN_00598c70

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d4e0 -- SEH Unwind Cleanup (Free at EBP-0x14)

Source: unknown | Confidence: high
SEH unwind handler: frees object at stack offset EBP-0x14.

**Key logic:**
- Calls FUN_00587bcf on value at *(EBP-0x14)

**Calls:** FUN_00587bcf (free/destructor)

**Used by system:** docs/01-engine-architecture.md -- SEH unwind cleanup

<!-- target: docs/01-engine-architecture.md -->

## FUN_00404970 -- Conditional Sound/Render Dispatch on Param Check

Source: likely audio_video_init.cpp | Confidence: low
Check param_1+0x20 == 1, then dispatch sound/render init sequence.

**Key logic:**
- If *(param_1+0x20) == 1:
  - Calls FUN_0040d360(1, 0xf) (parameter set)
  - Calls FUN_004d8840(1) (audio/sound init)
  - Calls FUN_00408420(0x40400000 = 3.0f) (render setup)
  - If DAT_0059e440 (ZeroThreshold) < DAT_007cf380: calls FUN_004c85d0 and FUN_004c8830(3.0f)

**Globals:**
- `DAT_0059e440` (ZeroThreshold) -- physics threshold constant
- `DAT_007cf380` -- unknown float global

**Calls:** FUN_0040d360, FUN_004d8840, FUN_00408420, FUN_004c85d0, FUN_004c8830

**Used by system:** docs/01-engine-architecture.md -- conditional audio/render init

<!-- target: docs/01-engine-architecture.md -->

## FUN_00410ad0 -- Linked List Node Insert (Indexed Array)

Source: unknown | Confidence: high
Insert a node into an indexed array slot.

**Key logic:**
- param_1[2] is base array pointer, *param_1 is current count/index
- Stores param_2 at array[*param_1] (array of pointers)
- Sets *param_2 = *param_1 (node stores its own index)
- Increments *param_1 (count)

**Algorithm family:** Linked list / indexed array insertion

**Used by system:** docs/20-math-utilities.md -- array-of-pointers insertion utility

<!-- target: docs/20-math-utilities.md -->

## FUN_00414160 -- Global Field Selector by Index

Source: unknown | Confidence: medium
Return one of two globals based on param_1 (0 or 1).

**Key logic:**
- If param_1 == 0: returns DAT_005bf8c8
- If param_1 == 1: returns DAT_005bf8d0
- Default: returns DAT_005bf8c8

**Globals:**
- `DAT_005bf8c8` -- default field value
- `DAT_005bf8d0` -- alternate field value

**Used by system:** docs/20-math-utilities.md -- global value selector

<!-- target: docs/20-math-utilities.md -->

## FUN_004156c0 -- Linked List Indexed Accessor

Source: unknown | Confidence: high
Access Nth element in singly-linked list via next-pointer traversal.

**Key logic:**
- Bounds check: returns 0 if param_2 < 0 or param_2 >= *(param_1+0x2c) (count)
- Traverses linked list from head at param_1+0x20, following next pointers at [1]
- Returns value at *node for the param_2-th element
- Returns 0 if node is null during traversal

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x20 | int* | linked list head |
| +0x2c | int | count/length |

**Algorithm family:** Linked list traversal by index

**Used by system:** docs/20-math-utilities.md -- linked list indexed accessor

<!-- target: docs/01-engine-architecture.md -->

## FUN_00425660 -- Field Zero Setter

Source: unknown | Confidence: high
Set a single field at offset +0x4510 to 0.

**Key logic:**
- Sets *(param_1 + 0x4510) = 0

**Used by system:** docs/20-math-utilities.md -- field reset utility

<!-- target: docs/01-engine-architecture.md -->

## FUN_00461530 -- Flag Bit Test

Source: unknown | Confidence: high
Test if any bit from param_2 mask is set in byte at param_1+0x88.

**Key logic:**
- Returns (*(char*)(param_1+0x88) & param_2) != 0

**Used by system:** docs/20-math-utilities.md -- flag bit test

<!-- target: docs/20-math-utilities.md -->

## FUN_00462370 -- Struct Field Read at +0x3e14

Source: unknown | Confidence: high
Read int from *(param_1) + 0x3e14.

**Key logic:**
- Returns *(undefined4*)(*param_1 + 0x3e14)

**Used by system:** docs/20-math-utilities.md -- field accessor

<!-- target: docs/20-math-utilities.md -->

## FUN_00463c40 -- Null-Terminated String Length at +0x11c

Source: unknown | Confidence: high
Compute length of null-terminated string at *param_1 + 0x11c.

**Key logic:**
- Finds null terminator in string at *param_1+0x11c
- Returns pointer to string if non-empty (length > 0), else 0

**Used by system:** docs/08-file-formats.md -- string field length check

<!-- target: docs/20-math-utilities.md -->

## FUN_00464ae0 -- Character Range Check with Sign Flag

Source: unknown | Confidence: medium
Check byte at param_1+param_2 for sign bit and compare against param_3.

**Key logic:**
- If byte at (param_2+param_1) has high bit set (negative char): returns param_2 & 0xffffff00
- Otherwise: returns (value & 0x7f) <= param_3

**Used by system:** docs/20-math-utilities.md -- character/byte validation

<!-- target: docs/01-engine-architecture.md -->

## FUN_00486330 -- Field Setter at +0x8c

Source: unknown | Confidence: high
Set *(param_1+0x8c) = param_2.

**Used by system:** docs/20-math-utilities.md -- field setter

<!-- target: docs/01-engine-architecture.md -->

## FUN_00491600 -- Rectangle Clamp/Constraint

Source: unknown | Confidence: high
Clamp rectangle bounds given min/max constraints.

**Key logic:**
- param_1 is a short[4] rect: [x, y, w, h]
- Clamps y to param_3 (min y), adjusts height
- Clamps x to param_2 (min x), adjusts width
- Clamps width so x+w <= param_4+1+param_2
- Clamps height so y+h <= param_3+param_5

**Algorithm family:** Rectangle constraint math

**Used by system:** docs/19-renderer.md -- UI/2D rectangle clipping

<!-- target: docs/01-engine-architecture.md -->

## FUN_00495a80 -- Doubly-Linked List Append

Source: unknown | Confidence: high
Append node to doubly-linked list.

**Key logic:**
- If param_2 non-null: calls FUN_00495a20, zeros fields at +100, +0x68
- If list head (param_1+0x14) is null: sets head/tail = param_2
- Otherwise: walks to last node via next pointers at +100, appends
- Updates tail at param_1+0x18 and back-pointer at node+0x68

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x14 | int* | list head |
| +0x18 | int* | list tail |

**Calls:** FUN_00495a20

**Used by system:** docs/20-math-utilities.md -- doubly-linked list append

<!-- target: docs/01-engine-architecture.md -->

## FUN_004988a0 -- Field Setter + Call

Source: unknown | Confidence: high
Set param_1+0x58 = param_2, call FUN_0044f640.

**Calls:** FUN_0044f640

**Used by system:** docs/01-engine-architecture.md -- setter with notification

<!-- target: docs/01-engine-architecture.md -->

## FUN_004998c0 -- Linked List Node Traversal

Source: unknown | Confidence: high
Follow next pointer at +0x48 to advance through linked list.

**Key logic:**
- If *(param_1+0x14) non-null: replaces with *(data+0x48) (next pointer)
- Returns (new value != 0) as success flag

**Used by system:** docs/20-math-utilities.md -- linked list iterator

<!-- target: docs/20-math-utilities.md -->

## FUN_00499df0 -- Field Setter at +0x68

Source: unknown | Confidence: high
Set *(param_1+0x68) = param_2.

**Used by system:** docs/20-math-utilities.md -- field setter

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a250 -- Patterned Field Init (0, -1 alternating)

Source: unknown | Confidence: high
Initialize 7 fields with alternating 0, -1 pattern.

**Key logic:**
- Sets [0]=0, [1]=-1, [2]=0, [3]=-1, [4]=0, [5]=-1, [6]=0

**Used by system:** docs/20-math-utilities.md -- struct initialization pattern

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004a0da0 -- Global Flag Setter

Source: unknown | Confidence: high
Set DAT_007ce25d = 1.

**Globals:**
- `DAT_007ce25d` -- global flag

**Used by system:** docs/01-engine-architecture.md -- flag setter

<!-- target: docs/01-engine-architecture.md -->

## FUN_004b2ad0 -- Bit Test

Source: unknown | Confidence: high
Test bit at position param_2 in value at param_1+0x30.

**Key logic:**
- Returns (*(param_1+0x30) >> (param_2 & 0x1f)) & 1

**Used by system:** docs/20-math-utilities.md -- bit flag test

<!-- target: docs/01-engine-architecture.md -->

## FUN_004b4f70 -- Struct Init with Global Data

Source: unknown | Confidence: medium
Zero fields, set 3 fields to DAT_005acd10.

**Key logic:**
- Calls thunk_FUN_00500170
- Zeros [0], [1], [0x41], [0x61]
- Sets [0x84], [0x88], [0x8c] = DAT_005acd10

**Calls:** thunk_FUN_00500170

**Used by system:** docs/20-math-utilities.md -- struct init

<!-- target: docs/01-engine-architecture.md -->

## FUN_004bbf70 -- Array Shift + Conditional Dispatch

Source: unknown | Confidence: high
Decrement count, shift array elements, dispatch based on remaining count.

**Key logic:**
- Decrements count at param_1+0x3c
- Shifts remaining elements in paired array at param_1+0x40
- If count < 1: calls FUN_004a5660(0)
- Else: calls FUN_004a5660(1)

**Calls:** FUN_004a5660

**Used by system:** docs/01-engine-architecture.md -- array management with state dispatch

<!-- target: docs/20-math-utilities.md -->

## FUN_004bdde0 -- 65x Nested Call Loop

Source: unknown | Confidence: medium
Call FUN_004bd800() 65 times (8*8+1) via nested loops.

**Key logic:**
- Outer loop 8 iterations, inner loop 8 iterations: calls FUN_004bd800()
- One additional call after loops

**Calls:** FUN_004bd800

**Used by system:** docs/20-math-utilities.md -- batch initialization/iteration

<!-- target: docs/01-engine-architecture.md -->

## FUN_004c9d50 -- Sentinel Field Init

Source: unknown | Confidence: high
Set three fields to -1.

**Key logic:**
- [0]=-1, [1]=-1, [0x11]=-1

**Used by system:** docs/20-math-utilities.md -- sentinel init

<!-- target: docs/20-math-utilities.md -->

## FUN_004ce8d0 -- Indexed Array Access (stride 0x6c)

Source: unknown | Confidence: high
Return pointer to param_1 + 0xc + param_2 * 0x6c, bounds-checked.

**Key logic:**
- Returns param_1+0xc+param_2*0x6c if 0 <= param_2 < param_1+8
- Returns 0 if out of bounds

**Used by system:** docs/20-math-utilities.md -- indexed array accessor

<!-- target: docs/01-engine-architecture.md -->

## FUN_004dd470 -- Array Cleanup with Destructor Loop

Source: unknown | Confidence: high
Free resource at +0x8, iterate and destruct array elements, free allocation.

**Key logic:**
- Frees *(param_1+0x8) if non-null
- If *(param_1+0x10) non-null: iterates *(header-4) times calling FUN_004dd4d0 each iteration
- Frees the allocation header (ptr-4)

**Calls:** FUN_00587bcf, FUN_004dd4d0

**Used by system:** docs/01-engine-architecture.md -- array resource cleanup

<!-- target: docs/01-engine-architecture.md -->

## FUN_004f3190 -- Quadratic/Cubic Polynomial Evaluator

Source: unknown | Confidence: high
Evaluate 2nd- or 3rd-order polynomial at param_2, returning two outputs.

**Key logic:**
- If flag at *param_1 set: evaluates two polynomials:
  - y1 = a + b*x + c*x^2 (reading doubles at +4, +0xc, +0x14)
  - y2 = d + e*x + f*x^2 (reading doubles at +0x1c, +0x24, +0x2c)
- If flag not set: returns 0.0, 0.0

**Algorithm family:** Polynomial evaluation

**Used by system:** docs/18-physics-dynamics.md -- physics curve evaluation

<!-- target: docs/01-engine-architecture.md -->

## FUN_0050c042 -- Float Range Check
Source: unknown | Confidence: high
Check if difference of two floats is within range bounds.

**Key logic:**
- Computes param_1 - param_2
- Returns 1 if result is between _DAT_005ade3c (lower) and _DAT_005ac9c0 (upper), exclusive
- Returns 0 otherwise

**Used by system:** docs/20-math-utilities.md -- float range check

<!-- target: docs/20-math-utilities.md -->
## thunk_FUN_0050cba3 -- Thunk to Matrix Multiply
Source: unknown | Confidence: high
Call FUN_0050fea7(1), then indirect jump through PTR_FUN_005d77d4.

**Key logic:**
- Calls FUN_0050fea7(1)
- Indirect jmp through PTR_FUN_005d77d4

**Calls:** FUN_0050fea7, PTR_FUN_005d77d4 (matrix operation)

**Used by system:** docs/19-renderer.md -- matrix multiply pipeline

<!-- target: docs/19-renderer.md -->

## FUN_00512319 -- Bit Flag Setter
Source: unknown | Confidence: high
Set bit 0 at param_1+0x60.

**Key logic:**
- *(param_1+0x60) |= 1

**Used by system:** docs/20-math-utilities.md -- flag setter

<!-- target: docs/20-math-utilities.md -->

## FUN_00513e5d -- FPU Control Word Merger
Source: unknown | Confidence: medium
Merge FPU control word with param_1 into global DAT_008b00a0.

**Key logic:**
- Merges high 16 bits of param_1 with FPU control word
- Stores to DAT_008b00a0

**Globals:**
- `DAT_008b00a0`

**Used by system:** docs/20-math-utilities.md -- FPU control

<!-- target: docs/01-engine-architecture.md -->

## FUN_0053d890 -- Indexed Array Access (stride 0x43c)
Source: unknown | Confidence: high
Return pointer to param_1 + 0xc + param_2 * 0x43c, bounds-checked.

**Key logic:**
- Returns param_1+0xc+param_2*0x43c if param_2 < *(param_1+8)

**Used by system:** docs/20-math-utilities.md -- indexed array accessor

<!-- target: docs/01-engine-architecture.md -->

## FUN_005490b0 -- Doubly-Linked List Append
Source: unknown | Confidence: high
Append node to doubly-linked list using +0x4c (next) and +0x48 (prev) pointers.

**Key logic:**
- If list head at +0xec null: sets as head, zeros node's pointer fields
- Else walks to tail via +0x4c, appends and sets back-pointer at node+0x48

**Used by system:** docs/20-math-utilities.md -- linked list utility

<!-- target: docs/20-math-utilities.md -->

## FUN_0054b420 -- Triple Field Query
Source: unknown | Confidence: high
Copy three fields from param_1 to output pointers.

**Key logic:**
- Copies +0x20 to *param_2, +0x24 to *param_3, +0x28 to *param_4 (if output pointers non-null)

**Used by system:** docs/20-math-utilities.md -- multi-field getter

<!-- target: docs/20-math-utilities.md -->

## FUN_0054eaa0 -- 1024x Batch Call Loop
Source: unknown | Confidence: medium
Call FUN_00548e00() 1024 (0x400) times.

**Calls:** FUN_00548e00

**Used by system:** docs/20-math-utilities.md -- batch init

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fe10 -- Struct Init with Zero Fill
Source: unknown | Confidence: high
Call parent init, zero 16 fields, set defaults.

**Key logic:**
- Calls FUN_0053c2a0() (parent init)
- Zeros 16 dwords, sets [0]=0, [0x11..0x12]=0, [0x15..0x17]=0
- Sets [0x13]=1, [0x14]=1 (defaults)

**Calls:** FUN_0053c2a0

**Used by system:** docs/20-math-utilities.md -- struct init

<!-- target: docs/01-engine-architecture.md -->

## FUN_0056d3e0 -- Struct Init with Zero Fill + Sub-call
Source: unknown | Confidence: high
Call init, zero 7 specific fields, call FINALIZE.

**Key logic:**
- Calls FUN_004bf630()
- Zeros +4, +0xc, +0x14, +0x1c, +0x24, +0x28, +0x2c, +0x30
- Calls FUN_0056e970()

**Calls:** FUN_004bf630, FUN_0056e970

**Used by system:** docs/20-math-utilities.md -- struct init

<!-- target: docs/01-engine-architecture.md -->

## FUN_00595058 -- Bit Field Mask/Merge
Source: unknown | Confidence: medium
Read global bit field, merge with param_1 using param_2 as mask, write back.

**Key logic:**
- Reads current value from FUN_005950a3
- Merges: (current & ~param_2) | (param_1 & param_2)
- Writes via FUN_00595135

**Calls:** FUN_005950a3, FUN_00595135

**Used by system:** docs/01-engine-architecture.md -- bit field control

<!-- target: docs/08-file-formats.md -->

## FUN_005593b0 — Struct Zero-Init

Source: unknown | Confidence: high
Three-field struct zero-initializer. Calls base init then clears first three int fields.

**Key logic:**
- Calls FUN_0053c2a0() — generic base init
- Sets *param_1 = 0
- Sets param_1[1] = 0
- Sets param_1[2] = 0
- Returns param_1

**Calls:** FUN_0053c2a0 (base init/short computation, docs/20)

**Used by system:** docs/20-math-utilities.md — simple struct init pattern (3 ints)

**Moddability:** hardcoded
<!-- target: docs/20-math-utilities.md -->

## FUN_0050cbb0 — Thunk to FUN_0050cba3

Source: unknown | Confidence: high
Trampoline — indirect jump via PTR_FUN_005d77d4. Unconditional dispatch to FUN_0050cba3.

**Key logic:**
- Single indirect jmp/call via pointer at DAT_005d77d4
- Address likely appears in a vtable or function pointer table

**Calls:** FUN_0050cba3 (short computation, math_util per triage index)

**Used by system:** docs/20-math-utilities.md — thunk to simple math leaf function

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005626b0 — Stack Buffer Zero-Init with Callback

Source: unknown | Confidence: high
Zeroes 1396 bytes on stack, calls vtable method at param_1+200, then calls string utility.

**Key logic:**
- Loop: zeroes 0x15d*4 bytes from local_577 on stack
- Zeroes two trailing bytes
- Reads uVar1 = *(param_1+0x100)
- Calls (**(code **)(param_1+200))(uVar1)
- Calls FUN_00562710() with stack buffer

**Calls:**
- Function pointer at param_1+200
- FUN_00562710 — string duplication with char replacement (docs/06)

**Used by system:** docs/20-math-utilities.md — buffer init utility

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00565140 — XOR Encryption with Rolling Key Stream

Source: unknown | Confidence: high
XOR cipher: XORs each byte of param_2 with key bytes from rolling buffer at param_1+0x4d4. Refills via FUN_00564f10 when exhausted.

**Key logic:**
- Loop param_3 bytes
- If key ptr exhausted: reset to +0x4d4, call FUN_00564f10(0x10)
- XOR param_2[i] ^= **(param_1+0x514)
- Advance key ptr

**Calls:** FUN_00564f10 — PRNG key stream generator (docs/20)

**Used by system:** docs/20-math-utilities.md — XOR cipher for save/network data

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00567940 — Dual Pointer Cleanup

Source: unknown | Confidence: high
Frees two pointers at +0x18 and +0x10 if non-null.

**Key logic:**
- If *(param_1+0x18) != 0: FUN_00587bcf()
- If *(param_1+0x10) != 0: FUN_00587bcf()

**Calls:** FUN_00587bcf (memory free, docs/20)

**Used by system:** docs/20-math-utilities.md — cleanup helper

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0057aef0 � Linked List Destruction & Cleanup

Source: unknown | Confidence: high
Destroys two linked lists in container. Frees nodes + optional data, resets head/tail/count, swaps vtable.

**Key logic:**
- Sets *param_1 = vtable &PTR_LAB_005b8a1c (destructor begin)
- Walks list 1 at param_1[6]:
  - Save next from [1]; if flag at *(puVar2+8) != 0: free *puVar2 (data)
  - Free node puVar2 via FUN_00587bcf
- Zero param_1[6..9] (head, tail, count, capacity)
- Walks list 2 at param_1[2]: same pattern
- Zero param_1[2..5]
- Set *param_1 = vtable &PTR_LAB_005b8a40 (post-cleanup vtable)

**Calls:** FUN_00587bcf (memory free, docs/20)

**Used by system:** docs/20-math-utilities.md � generic linked list container destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586ca0 � Bit-Field Extraction with Status

Source: unknown | Confidence: high
Extracts status bitmask from bit array. Checks uVar3 bits, returns packed status with non-zero indicator.

**Key logic:**
- puVar1 = base at *(param_1+0x1c) + *(param_1+0x3c)*4
- uVar3 = puVar1[1] (bit count to check)
- Iterates uVar4 0..uVar3-1
- uVar2 = (puVar1[0]-1) + uVar3 - uVar4 (bit index)
- Checks bit in array at *(param_1+0x14)
- If set: sets bit uVar4 in result local_4
- Returns CONCAT31(local_4>>8, local_4!=0)

**Algorithm family:** bit-field extraction � status query from compressed bit array

**Calls:** none

**Used by system:** docs/20-math-utilities.md � bitfield status query

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587d7f � CRT Stream getc with Lock/Unlock

Source: unknown | Confidence: high
Thread-safe character read from file/stream with lock acquire/release wrapping.

**Key logic:**
- iVar1 = FUN_0058c5ac() � acquire lock (docs/06)
- If lock fails: return 0
- uVar2 = FUN_0058c43c(param_1, param_2, param_3, iVar1) � buffered file getc (docs/08)
- FUN_0058c203(iVar1) � release lock (docs/20)
- Returns uVar2

**Calls:**
- FUN_0058c5ac � lock/CS acquire (docs/06)
- FUN_0058c43c � buffered file/stream read (docs/08)
- FUN_0058c203 � lock/CS release (docs/20)

**Algorithm family:** CRT stream I/O � thread-safe getc

**Used by system:** docs/20-math-utilities.md � thread-safe character read from file

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00589cb5 � CRT __exit

Source: MSVC CRT | Confidence: high
MSVC C Runtime __exit function. Delegates to FUN_00589cc6 with code, exit flag=1, and 0.

**Key logic:**
- Calls FUN_00589cc6(_Code, 1, 0) � lower-level CRT exit handler (docs/06)

**Calls:** FUN_00589cc6 (CRT exit handler, docs/06)

**Algorithm family:** MSVC CRT � program termination

**Used by system:** docs/20-math-utilities.md � MSVC C Runtime library

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058bd8f � CRT __fassign

Source: MSVC CRT | Confidence: high
MSVC __fassign � flag-conditional float or pointer assignment. If flag non-zero: copies a float value. If flag zero: assigns pointer directly.

**Key logic:**
- If flag != 0: calls FUN_00595550(&local_c) � buffer format helper, copies 8 bytes (float/double) to argument
- If flag == 0: calls FUN_0059557d(&number, number) � string parse, assigns char pointer to argument

**Algorithm family:** MSVC CRT � type-variant assignment helper (float vs string)

**Calls:**
- FUN_00595550 � buffer format helper (docs/20)
- FUN_0059557d � string parse with format validation (docs/20)

**Used by system:** docs/20-math-utilities.md � MSVC C Runtime library

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058dccc � Float Rounding Mode Select from Status

Source: unknown | Confidence: high
Returns rounding mode constant based on x87 FPU status register bit 0x80000.

**Key logic:**
- Checks in_EAX & 0x80000 (x87 FPU status register bit � precision exception flag)
- If set: returns 7 (precision exception active)
- Otherwise: returns 1 (default rounding mode)

**Algorithm family:** x87 FPU control � rounding mode from status register

**Calls:** none

**Used by system:** docs/20-math-utilities.md � x87 FPU status decode

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005906bb � CRT __ctrandisp2

Source: MSVC CRT | Confidence: high
MSVC __ctrandisp2 � CRT transcendent dispatch helper. Loads two float arguments, dispatches to transcendent function, then calls cleanup.

**Key logic:**
- __fload(param_1, param_2) � load float value onto x87 FPU stack
- __fload(param_3, param_4) � load second float value
- __trandisp2() � transcendent math dispatch (tan, atan, etc.)
- FUN_00590703() � post-dispatch cleanup

**Algorithm family:** MSVC CRT � transcendent math dispatch

**Calls:** __fload, __trandisp2, FUN_00590703 (CRT internal helpers)

**Used by system:** docs/20-math-utilities.md � MSVC C Runtime library

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005972bd � Exception/Error Filter with Magic Comparison

Source: unknown | Confidence: high
Exception filter function. Checks exception record magic values, then dispatches to handler or calls registered global.

**Key logic:**
- piVar1 = (int *)*param_1 (dereference exception record)
- If piVar1[0] == 0xE06D7363 (C++ exception magic), piVar1[4] == 3, piVar1[5] == 0x19930520 (another C++ exception signature):
  - Return FUN_00593c9c() � SEH wrapper dispatch
- Else if DAT_008d41e4 (global function pointer) non-null AND FUN_00597359(DAT_008d41e4) validates it:
  - Call (*DAT_008d41e4)(param_1) � registered exception filter
- Return 0

**Globals:**
- DAT_008d41e4 � global exception handler function pointer

**Calls:**
- FUN_00593c9c � SEH wrapper dispatching to handler (docs/20)
- FUN_00597359 � code pointer validation / IsBadCodePtr (docs/20)

**Algorithm family:** MSVC SEH � C++ exception dispatch

**Used by system:** docs/20-math-utilities.md � exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059927c � Locale Destructor with Conditional Free

Source: unknown | Confidence: high
Locale/object destructor. Calls cleanup function, conditionally frees memory based on flag bit.

**Key logic:**
- FUN_00598aea() � vtable set + sub-call cleanup
- If (param_2 & 1) != 0: FUN_00587bcf(param_1) � free memory if flag set
- Returns param_1

**Calls:**
- FUN_00598aea � vtable set + sub-call cleanup (docs/20)
- FUN_00587bcf � memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities.md � locale/object destructor pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a38d � Locale Destructor with Conditional Free

Source: unknown | Confidence: high
Locale/object destructor. Calls vtable cleanup, conditionally frees memory based on flag.

**Key logic:**
- FUN_00599e71() � C++ destructor with vtable chain cleanup
- If (param_2 & 1) != 0: FUN_00587bcf(param_1) � free memory
- Returns param_1

**Calls:**
- FUN_00599e71 � C++ destructor with vtable chain (docs/20)
- FUN_00587bcf � memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities.md � locale destructor pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00401000 � Callback Loop N Times

Source: unknown | Confidence: high
Executes callback function pointer param_3 times.

**Key logic:**
- If param_3 - 1 >= 0:
  - Loop: call (*param_4)(), decrement param_3, repeat until param_3 == 0

**Algorithm family:** utility � N-time callback repeater

**Calls:** (*param_4)() � user callback

**Used by system:** docs/20-math-utilities.md � generic callback loop

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404a50 � Struct Allocation and Init

Source: unknown | Confidence: high
Allocates 0x58-byte struct via operator_new, initializes with defaults and constants.

**Key logic:**
- operator_new(0x58) � allocate 88-byte struct
- If allocation fails: *param_1 = 0, return param_1
- On success:
  - Zero fields [0]..[4], [10], [0xc], [0xe], [0x10]..[0x13], [0x14], [0x15]
  - Set [0xb] = [0xd] = [0xf] = 0xffffffff (-1 sentinel/default)
  - Set [6] = DAT_0059e48c (global/physics constant)
  - Set [8] = 0, byte at [9] = 0, byte at [5] = 0, byte at +0x15 = 0, [7] = 0
  - Store pointer in *param_1
  - Return param_1

**Globals:**
- DAT_0059e48c � physics/global constant

**Algorithm family:** initialization pattern � alloc + field init

**Calls:** operator_new (heap allocation)

**Used by system:** docs/20-math-utilities.md � struct allocation with default values

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00405670 � Memory Copy (Word-Aligned + Remainder)

Source: unknown | Confidence: high
Memory copy with 4-byte word loop followed by byte remainder. Returns end pointer (dest + size).

**Key logic:**
- Copies param_3 >> 2 dwords (word-aligned copy)
- Copies param_3 & 3 remaining bytes
- Returns (byte*)(param_3 + param_1) � end pointer

**Algorithm family:** memcpy � word-aligned with byte remainder

**Calls:** none

**Used by system:** docs/20-math-utilities.md � memory copy utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406a70 � Release ID Resource if Valid

Source: unknown | Confidence: high
If resource ID at +0x5c is not -1, releases via FUN_0058c331 and resets to -1.

**Key logic:**
- If *(param_1+0x5c) != -1: FUN_0058c331(id), set to 0xffffffff

**Calls:** FUN_0058c331 (resource/ID release, docs/20)

**Used by system:** docs/20-math-utilities.md � resource handle cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004080b0 � Linked List Search by Value

Source: unknown | Confidence: high
Walks linked list at param_1+0x38, searching for node whose first element matches param_2.

**Key logic:**
- Start: piVar1 = *(param_1+0x38) (head), set current = piVar1 at param_1+0x40
- If head == null: return null
- piVar1 = *head (first element of first node)
- If first element non-null: compare *piVar1 to param_2
- If match: return piVar1
- Else: advance current to current->next (offset +4), piVar1 = **current
- Repeat until match or end

**Algorithm family:** linked list � linear search by value

**Calls:** none

**Used by system:** docs/20-math-utilities.md � generic linked list lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00409770 � File Resource Processing with Callbacks

Source: unknown | Confidence: medium
Processes a file resource with optional mode selection. Calls file read, processes data through four optional vtable callbacks, then iterates a fixed-stride sub-array.

**Key logic:**
- If param_2 != 0:
  - FUN_0058ba36(param_2, 0x80) � toggle file read-only attribute off
  - FUN_005668b0() � zero-init small struct
  - If param_3 == 0: FUN_00566a70(param_2,0,1,1) � open for read
  - Else: FUN_00566940(param_2,0,1,1) � open for write
  - Four optional vtable callbacks at param_1+0x10, 0x14, 0x18, 0x1c: each calls vtable+8(local_1c, 0)
  - If any callback non-null: iterate array at param_1+0x20 (stride 200 bytes, count at param_1+0x38), call vtable+8 per element
  - FUN_00566b90() � conditional file handle close
  - If bVar5 (any callback ran): FUN_005668d0() � cleanup, return 0
  - FUN_005668d0() � cleanup
  - Return 1

**Calls:**
- FUN_0058ba36 � toggle file read-only attr (docs/20)
- FUN_005668b0 � zero-init struct (docs/20)
- FUN_00566a70 � open file for read (docs/06)
- FUN_00566940 � open file for write (docs/06)
- FUN_00566b90 � conditional file handle close (docs/20)
- FUN_005668d0 � cleanup/sub-call (docs/20)

**Used by system:** docs/20-math-utilities.md � file resource processing with data callbacks

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040c520 � Linked List Node Swap (Cross-Link)

Source: unknown | Confidence: high
Cross-links two nodes by swapping their +8 pointers.

**Key logic:**
- *(*(param_1+0x20)+8) = *(param_1+0x1c) � node A's next = node B
- *(*(param_1+0x1c)+8) = *(param_1+0x20) � node B's next = node A

**Algorithm family:** linked list � bidirectional cross-link

**Calls:** none

**Used by system:** docs/20-math-utilities.md � linked list node insertion/relinking

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040da00 � Conditional Free + Dual Cleanup

Source: unknown | Confidence: high
Conditionally frees pointer at +0x88, then calls two cleanup functions.

**Key logic:**
- If *(param_1+0x88) != 0: FUN_00587bcf()
- FUN_00567a30() � linked list destructor with memory free (docs/20)
- FUN_00434860() � physics math computation (docs/20)

**Calls:**
- FUN_00587bcf (memory free, docs/20)
- FUN_00567a30 (linked list destructor, docs/20)
- FUN_00434860 (physics math, docs/20)

**Used by system:** docs/20-math-utilities.md � structured cleanup sequence

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040ea30 � Physics Corner Distance Setup

Source: unknown | Confidence: medium
Sets up track corner geometry parameters. Computes squared distances between corner points, scales by constant, calls geometry functions.

**Key logic:**
- Sets param_1+0x20 = param_3 (corner data pointer)
- Sets param_1+8 = param_2 (corner ID/index)
- Sets param_1+0x1c = 2 (state/count)
- FUN_004dd550(&local_50) � compute corner data (fills floats local_50..local_3c)
- Computes squared distances:
  - local_28 = (local_48 - local_3c) (dy)
  - local_38 = (local_50 - local_44)^2 (dx^2)
  - dVar2 = (local_4c - local_40)^2 (dz^2)
  - local_20 = (local_28^2 + dVar2) * _DAT_0059e6f0
  - local_18 = (local_28^2 + local_38) * _DAT_0059e6f0
  - local_10 = (dVar2 + local_38) * _DAT_0059e6f0
- FUN_00459950(0, 0x40140000, &local_20) � collision detection (spatial setup)
- FUN_00459990(0, ...) � math computation
- Writes four constants to output struct at *(param_1+0x20)+0x40..0x4c
- If param_4 != 0: FUN_0040e770(param_4, 0)

**Globals:**
- _DAT_0059e6f0 � physics/scaling constant

**Calls:**
- FUN_004dd550 � geometry computation (docs/20)
- FUN_00459950 � collision/spatial setup (docs/20)
- FUN_00459990 � math utility (docs/20)
- FUN_0040e770 � short computation (docs/20)

**Algorithm family:** track geometry � corner parameter setup with distance/scale

**Used by system:** docs/20-math-utilities.md � track/physics corner initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00410af0 � Linked List Node Removal

Source: unknown | Confidence: high
Removes element from indexed list by index. Swaps last element into removed slot, updates back-pointer, marks removed index as -1.

**Key logic:**
- iVar1 = *param_1 (current count), decremented
- iVar2 = *param_2 (index to remove)
- param_1[2][iVar2] = param_1[2][iVar1-1] � copy last element to removed slot
- *(param_1[2][iVar2]) = iVar2 � update back-pointer at element
- *param_2 = -1 � mark removed

**Algorithm family:** array-backed pool � O(1) removal by swap-with-last

**Calls:** none

**Used by system:** docs/20-math-utilities.md � pool/array element removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00414180 � Global Data Selector by Index

Source: unknown | Confidence: high
Returns one of two global values based on param_1 index.

**Key logic:**
- Returns DAT_005bf8cc (global value 0)
- If param_1 == 1: returns DAT_005bf8d4 (global value 1) instead
- If param_1 != 0 and != 1: returns -1 (0xffffffff)

**Globals:**
- DAT_005bf8cc � data value for index 0
- DAT_005bf8d4 � data value for index 1

**Calls:** none

**Used by system:** docs/20-math-utilities.md � global data lookup by index

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00415700 � Linked List Reset: Clear Flag Field

Source: unknown | Confidence: high
Walks linked list, sets byte field at +0xc to 0 for each node.

**Key logic:**
- Start at *param_1 (head), store in param_1[2]
- If head non-null and *head non-zero:
  - Set *(iVar2+0xc) = 0 (clear flag)
  - Follow next at param_1[2] via +4 offset
  - Continue until list end or null node data

**Algorithm family:** linked list � flag reset traversal

**Calls:** none

**Used by system:** docs/20-math-utilities.md � linked list state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004190c0 � Linked List Free with Optional Data Cleanup

Source: unknown | Confidence: high
Frees linked list at param_1+0x1a0. Each node's data freed if flag set. Resets head/tail/count/capacity.

**Key logic:**
- Walk list at param_1+0x1a0: save next from [1], if flag at byte [2] and data [0] non-null: free data
- Free node itself via FUN_00587bcf
- Zero param_1[0x1a0], [0x1a4], [0x1a8], [0x1ac] (head, tail, count, capacity)

**Calls:** FUN_00587bcf (memory free, docs/20)

**Used by system:** docs/20-math-utilities.md � linked list destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004203f0 � Session Timing/Anomaly Detect

Source: unknown | Confidence: medium
Session/lap timing check. Compares two state instances using time diff thresholds (0,1,2,3,4,6 frames). If diff in range, calls resolution.

**Key logic:**
- iVar2 = FUN_0041e920() � get first game state instance (game_logic, docs/20)
- If non-null:
  - iVar3 = FUN_0041e920() � get second instance
  - iVar1 = *(iVar2+0x198) � field from instance A
  - iVar2 = *(iVar3+0x198) � field from instance B
  - FUN_004c2850() � short computation
  - iVar3 = FUN_004c11d0() � vehicle struct read
  - FUN_004c2850() � short computation
  - iVar4 = FUN_004c1190() � unknown/start time
  - iVar2 = iVar2 + (iVar4 - iVar3) * 10 � compute elapsed
  - If iVar1 <= iVar2 AND iVar2 < iVar1 + N (N = 1,2,3,4,6): call FUN_004144d0() � math/computation

**Calls:**
- FUN_0041e920 � get game state instance (game_logic, docs/20)
- FUN_004c2850 � short math (docs/20)
- FUN_004c11d0 � vehicle struct read (docs/20)
- FUN_004c1190 � unknown time/state read
- FUN_004144d0 � short computation (docs/20)

**Used by system:** docs/20-math-utilities.md � session/timing comparison with threshold detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421a70 � String/Path Processing Pair

Source: unknown | Confidence: high
Calls two functions with param_1: one for string op, one for path registry.

**Key logic:**
- FUN_00421890(param_1) � short computation / string op
- FUN_00566650(param_1) � path registry / string set (docs/20)

**Calls:**
- FUN_00421890 � short computation (docs/20)
- FUN_00566650 � path registry / string set (docs/20)

**Used by system:** docs/20-math-utilities.md � string/path processing utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004258c0 � AI Speed/Overtaking State Setter

Source: unknown | Confidence: high
Sets AI speed delta and overtaking zone flags based on speed and track position thresholds.

**Key logic:**
- Sets param_1+0x4438 = 1.0f (AISpeedDelta default)
- Sets param_1+0x4434 = 0 (AIGapToAhead)
- If *(param_1+0x4440) < _DAT_0059e46c (speed threshold) OR (both lateral distances > _DAT_0059e824):
  - Set param_1+0x4510 = 2 (overtaking zone flag)

**Globals:** _DAT_0059e46c, _DAT_0059e824 (physics/track thresholds)

**Calls:** none

**Used by system:** docs/20-math-utilities.md � AI state update for overtaking/speed delta (uses AI struct offsets +0x4438, +0x4440, +0x4510)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00455260 � Two-Way Dispatch by Index

Source: unknown | Confidence: high
Dispatches to two different functions based on *param_1 value (0 or 1).

**Key logic:**
- If *param_1 == 0: return FUN_00455200()
- If *param_1 == 1: return FUN_00455240()
- Otherwise: return 0

**Calls:** FUN_00455200, FUN_00455240

**Used by system:** docs/20-math-utilities.md � dispatch selector

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00457ee0 � Accumulated Distance Along Point Array

Source: unknown | Confidence: high
Computes cumulative Euclidean distance between consecutive 3D points (stride 0x1c). Stores running sum at each point's offset +6 (float). First point gets 0.

**Key logic:**
- For iVar2 from 0 to param_1[1]-1:
  - If iVar2 == 0: set *(param_1[0]+0x18) = 0
  - Else: compute SQRT((dx)^2 + (dy)^2 + (dz)^2) + previous accumulated distance, store at point+6
- param_1[2] = *(param_1[0] + last_offset) � store last point's accumulated value

**Algorithm family:** 3D geometry � cumulative chord length parameterization

**Calls:** SQRT (math library)

**Used by system:** docs/20-math-utilities.md � 3D point array distance accumulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b5c0 � Array Max Computation

Source: unknown | Confidence: medium
Iterates array, computes values via FUN_00456040 + FUN_004dd400, tracks maximum.

**Key logic:**
- local_4 = FUN_0045bb00() � get array count
- For each index iVar2:
  - iVar1 = FUN_0045b580(iVar2) � get indexed element
  - FUN_00456040(&local_8, &local_c) � get lookup vectors
  - FUN_004dd400(iVar1*0x5c + 0x3c + param_1, local_8, local_c, &local_10, 0, 0) � compute value
  - Track maximum in local_14
- Return maximum

**Algorithm family:** array math � maximum search with indexed lookup

**Calls:** FUN_0045bb00, FUN_0045b580, FUN_00456040, FUN_004dd400

**Used by system:** docs/20-math-utilities.md � array maximum search with indexed computation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bff0 � Short Computation Wrapper

Source: unknown | Confidence: high
Calls FUN_00587b3e with address LAB_0045c000.

**Key logic:**
- FUN_00587b3e(&LAB_0045c000) � register/callback with data address

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md � callback/registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045d510 � Conditional Resource Release

Source: unknown | Confidence: high
Calls init function, then conditionally releases resource at +0xc.

**Key logic:**
- FUN_0045d240() � init
- If *(param_1+0xc) != 0: FUN_00562c50(), set to 0

**Calls:** FUN_0045d240, FUN_00562c50

**Used by system:** docs/20-math-utilities.md � resource cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461550 � Pass-Through Wrapper

Source: unknown | Confidence: high
Calls FUN_00461560(), returns param_1 unchanged.

**Key logic:**
- FUN_00461560()
- Return param_1

**Calls:** FUN_00461560

**Used by system:** docs/20-math-utilities.md � wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462380 � Driver Count with Condition

Source: unknown | Confidence: high
Counts drivers matching condition FUN_00461530(2), bounded by vehicle count at *(param_1[0]+0x3e14).

**Key logic:**
- Counts how many times FUN_00461530(2) returns true, up to *(param_1[0]+0x3e14) (vehicle count)

**Calls:** FUN_00461530(2) � driver/state check

**Used by system:** docs/20-math-utilities.md � driver condition count

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463c60 � String Pointer Guard

Source: unknown | Confidence: high
Returns pointer to param_1[0]+0x16c if string at that address is non-empty, else 0.

**Key logic:**
- Scans string at (*param_1 + 0x16c) for null terminator
- If any char found before n=0 count runs out: returns &(*param_1+0x16c)
- Otherwise: returns 0

**Calls:** none

**Used by system:** docs/20-math-utilities.md � string existence check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464b10 � Repeated Call 104 Times

Source: unknown | Confidence: high
Calls FUN_00464a10(param_1) exactly 0x68 (104) times in a loop.

**Key logic:**
- Loop 0x68 times: call FUN_00464a10(param_1)

**Calls:** FUN_00464a10 (per-iteration handler)

**Algorithm family:** fixed-iteration loop � batch processing

**Used by system:** docs/20-math-utilities.md � repeated operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466090 � UI Visual Struct Init

Source: unknown | Confidence: high
Initializes UI visual struct with constants and vtable pointer.

**Key logic:**
- FUN_0048e600() � base init
- Sets float fields: [0x3e]=5.0f, [0x40]=5.0f, [0x3c]=0, [0x3f]=10.0f, [0x44]=1.0f, [0x46]=-1.0f, [0x49]=-1.0f
- Zeroes bytes and ints at multiple positions
- Sets vtable: *param_1 = &PTR_FUN_0059f140

**Calls:** FUN_0048e600

**Used by system:** docs/20-math-utilities.md � UI struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00467720 � UI Object Init with Linked List Cleanup

Source: unknown | Confidence: high
UI object constructor that cleans up a linked list at [0x3e] and sets up vtable and zero fields.

**Key logic:**
- FUN_00487ed0(0,0) � base init
- Zero [0x3e]..[0x41], [0x39]..[0x3c]
- Set vtable: *param_1 = &PTR_LAB_0059f5b8
- Walk linked list at [0x3e]: for each node with flag and data, free data and node
- Zero list head/tail/count/capacity and additional fields

**Calls:** FUN_00487ed0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � UI object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046b310 � Offset Accessor (+0x174)

Source: unknown | Confidence: high
Returns param_1 + 0x174 � pointer to field at fixed offset.

**Key logic:**
- return param_1 + 0x174

**Calls:** none

**Algorithm family:** accessor � fixed-offset field getter

**Used by system:** docs/20-math-utilities.md � struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046dd10 � UI Object Init

Source: unknown | Confidence: high
Initializes UI struct with vtable and zeroed field.

**Key logic:**
- FUN_00487220(0,0) � base init
- *param_1 = &PTR_FUN_0059fd68 (vtable)
- param_1[0x39] = 0

**Calls:** FUN_00487220

**Used by system:** docs/20-math-utilities.md � UI object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046ff40 � UI Object Destructor

Source: unknown | Confidence: high
UI destructor: sets vtable, frees optional buffer, calls cleanup, optionally frees self.

**Key logic:**
- *param_1 = &PTR_FUN_005a01a0 (vtable)
- If param_1[0x3b] != 0: FUN_00587bcf(param_1[0x3b])
- FUN_0048feb0() � cleanup
- If (param_2 & 1): FUN_00587bcf(param_1) � free self

**Calls:** FUN_00587bcf, FUN_0048feb0

**Used by system:** docs/20-math-utilities.md � UI destructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004718e0 � UI Object Init with State Values

Source: unknown | Confidence: medium
Initializes UI struct with vtable, state values, and handler registrations.

**Key logic:**
- FUN_00466d60(1) � base init
- *param_1 = &PTR_FUN_005a1380 (vtable)
- param_1[199] = &DAT_007ce760 (global display state)
- Sets [0xc9]=2, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0xf3
- FUN_00486f30(&PTR_DAT_005be704, -1) � 3 � register handlers
- FUN_004670e0() � finalize

**Globals:** DAT_007ce760 (display/UI state)

**Calls:** FUN_00466d60, FUN_00486f30 (�3), FUN_004670e0

**Used by system:** docs/20-math-utilities.md � UI object constructor with state config

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473bd0 � UI Object Init

Source: unknown | Confidence: high
Simple UI constructor: base init + vtable set.

**Key logic:**
- FUN_0048c070(0) � base init
- *param_1 = &PTR_FUN_005a2e80 (vtable)

**Calls:** FUN_0048c070

**Used by system:** docs/20-math-utilities.md � UI object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004750f0 � UI Object Init with Zero Fields

Source: unknown | Confidence: high
UI constructor: base init + zeroed fields + vtable.

**Key logic:**
- FUN_004893c0() � base init
- param_1[0x5d]=0, param_1[0x5e]=0, byte at param_1+0x5f=0
- *param_1 = &PTR_FUN_005a4370 (vtable)

**Calls:** FUN_004893c0

**Used by system:** docs/20-math-utilities.md � UI object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00477410 � UI Object Init with Parameter

Source: unknown | Confidence: high
UI constructor storing param_2 and default -1 sentinels.

**Key logic:**
- FUN_0048eaa0() � base init
- param_1[0x60] = param_2
- param_1[0x61] = -1
- param_1[0x62] = -1
- *param_1 = &PTR_LAB_005a4600 (vtable)

**Calls:** FUN_0048eaa0

**Used by system:** docs/20-math-utilities.md � UI object constructor with config

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478350 � State Change Detector with Callback

Source: unknown | Confidence: high
Compares cached state to current, triggers callback on mismatch.

**Key logic:**
- If param_1[0x38] != 0 (pointer valid):
  - iVar1 = *(param_1[0x38] + 0x174) � read current state
  - If param_1[0x39] != iVar1 (cache != current):
    - Update cache: param_1[0x39] = iVar1
    - FUN_00478390() � intermediate
    - Call vtable+0x2c(1) � notification

**Calls:** FUN_00478390, vtable+0x2c dispatch

**Used by system:** docs/20-math-utilities.md � state change detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479910 � UI Object Init

Source: unknown | Confidence: high
Simple UI constructor: base init with float param + vtable.

**Key logic:**
- FUN_00466980(0, 0.5f) � base init
- *param_1 = &PTR_FUN_005a54e8 (vtable)

**Calls:** FUN_00466980

**Used by system:** docs/20-math-utilities.md � UI object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a000 � UI Object Init with Byte Flag

Source: unknown | Confidence: high
UI constructor: base init + vtable + zero flag.

**Key logic:**
- FUN_004668e0(0, 1.0f) � base init
- *param_1 = &PTR_FUN_005a5ef8 (vtable)
- *(param_1+0x41) = 0

**Calls:** FUN_004668e0

**Used by system:** docs/20-math-utilities.md � UI object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047bb40 � UI Scroll/Position Controller

Source: unknown | Confidence: high
UI scroll/pan controller. Adjusts position offset param_1[0x44] based on target param_2, with step size param_1[0x3c] and constraints.

**Key logic:**
- iVar1 = vtable+0x1c() � get current position
- Half-width: param_1[0x46]/2
- If target < current - half: step left (-param_1[0x3c]), recheck
- If target > current + half: step right (+param_1[0x3c]), recheck
- If still out of range: compute delta, clamp to [0, param_1[0x45]]
- Call FUN_0047be00() � redraw/update

**Calls:** vtable+0x1c dispatch, FUN_0047be00

**Algorithm family:** UI � scroll/position snapping with step

**Used by system:** docs/20-math-utilities.md � UI scroll controller

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047eb30 � UI Object Destructor

Source: unknown | Confidence: high
UI destructor: cleanup with conditional free.

**Key logic:**
- If *(param_1+0xec) != 0: FUN_00587bcf()
- FUN_00488b30() � base cleanup
- If (param_2 & 1): FUN_00587bcf(param_1) � free self

**Calls:** FUN_00587bcf, FUN_00488b30

**Used by system:** docs/20-math-utilities.md � UI destructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485690 � UI Object Destructor

Source: unknown | Confidence: high
UI destructor: vtable swap + cleanup + conditional free.

**Key logic:**
- *param_1 = &PTR_FUN_005a9870 (vtable)
- FUN_00487250() � cleanup
- If (param_2 & 1): FUN_00587bcf(param_1) � free self

**Calls:** FUN_00487250, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � UI destructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486340 � Linked List Insert (Prepend/Append)

Source: unknown | Confidence: high
Inserts param_2 into linked list at param_1+0x90. Copies fields +0x40, +0x98, +0x9c. If param_3==0: appends to tail. If param_3!=0: prepends to head.

**Key logic:**
- Copy: *(param_2+0x40)=*(param_1+0x40), *(param_2+0x98)=*(param_1+0x98), *(param_2+0x9c)=*(param_1+0x9c)
- If param_3==0 (append):
  - If head at *(param_1+0x90)==0: new node becomes head
  - Else: walk to tail via +0x8c, call FUN_00486330 to link
- Else (prepend): new node->+0x8c = old head, new node becomes head
- Increment count at *(param_1+0x94)

**Algorithm family:** linked list � prepend/append with field copy

**Calls:** FUN_00486330

**Used by system:** docs/20-math-utilities.md � linked list node insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487060 � Indexed String/Name Lookup with Fallback

Source: unknown | Confidence: high
Looks up a string entry by index from two possible sources (primary array or fallback), returns ID + accumulator sum.

**Key logic:**
- iVar1 = *(param_1+0xc) (accumulator/base)
- iVar3 = FUN_0049adb0() � get primary array count
- If param_2 < count: FUN_0049aec0(param_2, &local_4, &local_4+2) � get entry
- If success: return (short)local_4 + iVar1
- Else if *(param_1+200) != 0 (fallback): same lookup from fallback
- Return -1 if not found

**Calls:** FUN_0049adb0, FUN_0049aec0

**Used by system:** docs/20-math-utilities.md � indexed string/name resolution

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487d50 � Vtable Method Dispatch

Source: unknown | Confidence: high
Calls base cleanup then dispatches vtable method at +0xa8.

**Key logic:**
- FUN_00487960()
- (*(param_1[0]+0xa8))() � vtable dispatch

**Calls:** FUN_00487960, vtable+0xa8 dispatch

**Used by system:** docs/20-math-utilities.md � vtable dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00488fb0 � UI Object Destructor

Source: unknown | Confidence: high
UI destructor: vtable swap + cleanup + conditional free.

**Key logic:**
- *param_1 = &PTR_FUN_005abcd0 (vtable)
- FUN_00485eb0() � cleanup
- If (param_2 & 1): FUN_00587bcf(param_1) � free self

**Calls:** FUN_00485eb0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � UI destructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b4f0 � UI State Flags Init

Source: unknown | Confidence: high
Sets multiple UI state flags and constants at various offsets.

**Key logic:**
- **(param_1+0x2f0) = 0 � clear indirect pointer
- *(param_1+0x2f4) = *(param_1+0x2f0) � copy pointer
- Sets byte flags: +0x1e7=0, +0xe0=0, +0xe2=0, +0xe3=1, +0xe4=1, +0xe5=0, +0x2ec=1, +0xe1=1
- Sets int: +0x2f8=0x100 (256), +0x300=0x10 (16), +0x2e8=0

**Calls:** none

**Used by system:** docs/20-math-utilities.md � UI state initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d0a0 � Float Random + Vtable Dispatch

Source: unknown | Confidence: high
Gets random float, passes through callback, dispatches vtable method.

**Key logic:**
- fVar1 = FUN_00498730() � get random value
- FUN_0048cb00((float)fVar1) � random callback/update
- (**(code **)(*param_1 + 0xac))() � vtable dispatch

**Calls:** FUN_00498730, FUN_0048cb00, vtable+0xac dispatch

**Used by system:** docs/20-math-utilities.md � randomized vtable dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e0d0 � UI Destructor with Conditional Release

Source: unknown | Confidence: high
UI destructor: releases two optional resources, calls base cleanup.

**Key logic:**
- *param_1 = &PTR_FUN_005ac3e0 (vtable)
- If param_1[0x38] != 0: FUN_00551f80() � release resource
- If param_1[0x3a] != 0: FUN_00587bcf() � free
- FUN_00485eb0() � base cleanup

**Calls:** FUN_00551f80, FUN_00587bcf, FUN_00485eb0

**Used by system:** docs/20-math-utilities.md � UI destructor with dual resource cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fb30 � Bounded Accumulator

Source: unknown | Confidence: high
Adds param_2 to accumulator at param_1+0x168, clamps to upper bound at param_1+0x16c.

**Key logic:**
- If param_2 < 0: param_2 = *(param_1+0x178) (fallback value)
- param_2 += *(param_1+0x168)
- Store param_2 at *(param_1+0x168)
- If > bound at *(param_1+0x16c): clamp to bound
- FUN_0048f870() � update

**Calls:** FUN_0048f870

**Used by system:** docs/20-math-utilities.md � bounded accumulator/position

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490330 � State-Dependent UI Dispatch

Source: unknown | Confidence: high
Dispatches UI command (2 or 5) based on state from FUN_00486720().

**Key logic:**
- uVar1 = FUN_00486720() � get state (0-5)
- If state 0/1/2: vtable+0x40(2)
- If state 3/4/5: vtable+0x40(5)
- vtable+0x98() � general update
- FUN_00490660() � cleanup

**Calls:** FUN_00486720, vtable+0x40, vtable+0x98, FUN_00490660

**Used by system:** docs/20-math-utilities.md � UI state machine dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491680 � Axis-Aligned Bounding Box (AABB) Overlap Test

Source: unknown | Confidence: high
2D AABB overlap/collision test. Compares two rectangles defined by min/max x,y with padding.

**Key logic:**
- iVar1 = *param_1 (rect A min x), iVar2 = max(x_min, param_2)
- iVar3 = param_1[2] + *param_1 (rect A max x), clamped to max(param_4+param_2)
- If overlap on X axis exists AND same for Y axis (param_1[1], param_3, param_1[3], param_5):
  - Return 1 (overlap)
- Return 0

**Algorithm family:** collision detection � AABB overlap (2D)

**Calls:** none

**Used by system:** docs/20-math-utilities.md � 2D AABB collision test

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491e40 � Conditional Data Free (Flag-Gated)

Source: unknown | Confidence: high
If flag byte at param_1[2] non-null and data pointer at *param_1 non-null: frees data.

**Key logic:**
- If param_1[2] (byte) != 0 AND *param_1 != 0: FUN_00587bcf(*param_1)

**Calls:** FUN_00587bcf (memory free, docs/20)

**Used by system:** docs/20-math-utilities.md � flag-gated list node data free

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495080 � Audio/System State Init Sequence

Source: unknown | Confidence: medium
Calls audio/system initialization sequence with global data reference.

**Key logic:**
- FUN_004f9f00() � base init
- FUN_00553700(DAT_008b8dc8) � audio/system call with global handle
- FUN_004f9b30(0) � config/state set
- FUN_004f9f30() � finalize

**Globals:** DAT_008b8dc8 (audio/system handle)

**Calls:** FUN_004f9f00, FUN_00553700, FUN_004f9b30, FUN_004f9f30

**Used by system:** docs/20-math-utilities.md � audio/system initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495ae0 � Resource Unlink with Callback

Source: unknown | Confidence: medium
Unlinks a linked list node, passes its data to callback, zeros pointers.

**Key logic:**
- If *(param_1+0x14) and *(*(param_1+0x14)+100) valid:
  - iVar1 = *(param_1+0x18), iVar2 = *(iVar1+0x68)
  - Update link: *(param_1+0x18) = iVar2, *(iVar2+100) = 0
  - FUN_00499050(iVar1[1..4]) � callback with node data
  - Zero iVar1[25] (+100) and iVar1[26] (+0x68)

**Calls:** FUN_00499050

**Used by system:** docs/20-math-utilities.md � linked list node unlink with data callback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004975d0 � Linked List Append with Field Init

Source: unknown | Confidence: high
Appends param_2 to linked list at param_1+0x1c. Initializes fields and optionally processes param_3.

**Key logic:**
- If param_2 == 0: return 0
- Set param_2+0x40 = param_1 (back-link), +0x98=0, +0x9c=0, +0x8c=0 (next)
- If param_3 != 0: FUN_0049ad50(param_3) � process extra data
- If list head at param_1+0x1c non-null: walk to tail via +0x8c, append
- Else: set as head

**Calls:** FUN_0049ad50

**Used by system:** docs/20-math-utilities.md � linked list append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004988c0 � Byte Setter at +0x18f5

Source: unknown | Confidence: high
Sets a single byte field at offset +0x18f5 in param_1.

**Key logic:**
- *(param_1 + 0x18f5) = param_2

**Calls:** none

**Used by system:** docs/20-math-utilities.md � field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499160 � UI Destructor with Conditional Free

Source: unknown | Confidence: high
UI destructor: cleanup + optional free.

**Key logic:**
- FUN_00499180() � cleanup
- If (param_2 & 1): FUN_00587bcf(param_1) � free self

**Calls:** FUN_00499180, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � UI destructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004998e0 � State/List Setup with Fallback

Source: unknown | Confidence: medium
Sets up state from param_1. If param_1 non-null, reads fields and checks for empty condition.

**Key logic:**
- FUN_00499850() � base init
- extraout_ECX[3] = param_1
- If param_1 != 0:
  - *extraout_ECX = 0
  - extraout_ECX[2] = *(param_1+0x1c) (linked list head)
  - extraout_ECX[4] = 0, extraout_ECX[5] = 0
  - If linked list empty: FUN_00499910()

**Calls:** FUN_00499850, FUN_00499910

**Used by system:** docs/20-math-utilities.md � state/iterator setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499e00 � Field Accessor at +0x68

Source: unknown | Confidence: high
Returns *(param_1 + 0x68).

**Key logic:**
- return *(param_1 + 0x68)

**Calls:** none

**Algorithm family:** accessor � field reader

**Used by system:** docs/20-math-utilities.md � field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a270 � Triple Pointer Cleanup

Source: unknown | Confidence: high
Frees three pointers at [4], [2], [0] if non-null.

**Key logic:**
- If param_1[4] != 0: FUN_00587bcf()
- If param_1[2] != 0: FUN_00587bcf()
- If *param_1 != 0: FUN_00587bcf()

**Calls:** FUN_00587bcf (�3 max)

**Used by system:** docs/20-math-utilities.md � cleanup helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ad50 � String/Path Processing

Source: unknown | Confidence: high
If param_1 non-null, normalizes string via FUN_00589901 then calls path registry.

**Key logic:**
- If param_1 != 0: FUN_00589901(param_1), FUN_00566650(param_1)

**Calls:** FUN_00589901 (string normalize), FUN_00566650 (path registry set)

**Used by system:** docs/20-math-utilities.md � string normalization + path registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049d4c0 � State-Batched UI Element Update

Source: unknown | Confidence: medium
Processes multiple UI element visibility/state flags using conditional dispatch (show vs hide per element).

**Key logic:**
- Checks 7+ UI conditions via FUN_0049b9a0, FUN_0049ba30, FUN_0049ba50, FUN_0049bab0, FUN_0049ba90, FUN_0049bad0, FUN_0049bb20
- Each condition determines whether to call FUN_0049e4e0 (show if true) or FUN_0049e520 (hide if false mode)
- Condition indexed against field at param_1+0x30..0x48

**Calls:** multiple FUN_0049b* (state checks), FUN_0049e4e0 (show), FUN_0049e520 (hide)

**Used by system:** docs/20-math-utilities.md � UI element visibility batch update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ed20 � Conditional Audio Call

Source: unknown | Confidence: high
If param_1+4 is non-null, calls audio function.

**Key logic:**
- If *(param_1+4) != 0: FUN_00553700()

**Calls:** FUN_00553700 (audio/system)

**Used by system:** docs/20-math-utilities.md � conditional audio trigger

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0db0 � Global Flag Setter

Source: unknown | Confidence: high
Sets global flag DAT_007ce25e to 1.

**Key logic:**
- DAT_007ce25e = 1

**Globals:** DAT_007ce25e

**Calls:** none

**Used by system:** docs/20-math-utilities.md � global flag toggle

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1f60 � Quad-Word Zero-Init

Source: unknown | Confidence: high
Zeros four consecutive 32-bit fields at param_1[0..3].

**Key logic:**
- param_1[0]=0, param_1[1]=0, param_1[2]=0, param_1[3]=0

**Calls:** none

**Used by system:** docs/20-math-utilities.md � struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a3b30 � Quad-Field Zero + Subcall

Source: unknown | Confidence: high
Zeros four fields (+0x78, +0x7c, +0x80, +0x84) and calls init.

**Key logic:**
- *(param_1+0x78..0x84) = 0 (4 ints)
- FUN_004a2220()

**Calls:** FUN_004a2220

**Used by system:** docs/20-math-utilities.md � struct field init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a6fe0 � Single Call Wrapper

Source: unknown | Confidence: high
Delegates to FUN_004a70e0().

**Key logic:**
- FUN_004a70e0()

**Calls:** FUN_004a70e0

**Used by system:** docs/20-math-utilities.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b19d0 � Field Init with Defaults

Source: unknown | Confidence: high
Initializes fields with defaults and vtable.

**Key logic:**
- param_1[1]=0, param_1[2]=-1, param_1[3]=0, param_1[4]=-1, *param_1=&PTR_LAB_005acc2c

**Calls:** none

**Used by system:** docs/20-math-utilities.md � struct init with sentinels

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2310 � Float-to-Short Normalized Conversion

Source: unknown | Confidence: high
Converts 3 float values to 16-bit signed shorts using scaling factor and clamp. Used for compressed vertex/geometry data.

**Key logic:**
- Copies 3 uint32 values from param_2 to param_1 (identity copy)
- For each float in param_3[0..2]:
  - Clamp to [_DAT_005acc90, _DAT_005acc94] range
  - Scale by _DAT_0059e714, round to int, store as short
  - If out of range: set to 0x8001 (min) or 0x7fff (max)
- Stores shorts at param_1+6, param_1+0xe, param_1+8

**Globals:** _DAT_005acc90, _DAT_005acc94 (clamp range), _DAT_0059e714 (scale factor)

**Algorithm family:** geometry compression � float[-1,1] to short

**Calls:** ROUND (math)

**Used by system:** docs/20-math-utilities.md � geometry data compression

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2ae0 � Bitfield Flag XOR Setter

Source: unknown | Confidence: high
Sets bits 28-30 in bitfield at +0x30 using XOR with shifted mask.

**Key logic:**
- *(param_1+0x30) ^= (param_2 << 0x1c) & 0x70000000 � XOR bits 28-30

**Calls:** none

**Algorithm family:** bit manipulation � flag field update

**Used by system:** docs/20-math-utilities.md � bitfield flag setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b3db0 � Identity/Pass-Through

Source: unknown | Confidence: high
Returns param_1 unchanged.

**Key logic:**
- return param_1

**Calls:** none

**Used by system:** docs/20-math-utilities.md � identity function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4fb0 � Struct Serialization/Write

Source: unknown | Confidence: medium
Serializes a struct to binary output via FUN_00566bd0. Writes header, string, and multiple fixed-size fields.

**Key logic:**
- FUN_00566bd0(param_1, 1) � write 1 byte marker
- Compute string length at param_1+1 via strlen
- Write length byte, then string data, then 0x20-byte block at +0x41, 0x20-byte at +0x61, 4-byte at +0x84, 4-byte at +0x88

**Calls:** FUN_00566bd0 (�6, binary write)

**Used by system:** docs/20-math-utilities.md � struct serialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9880 � Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004b7de0().

**Calls:** FUN_004b7de0

**Used by system:** docs/20-math-utilities.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba770 � Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004b8010().

**Calls:** FUN_004b8010

**Used by system:** docs/20-math-utilities.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004baf10 � Dual Linked List Insert with Tagged Nodes

Source: unknown | Confidence: high
Inserts nodes into two linked lists. First list: data pointer + flag=1. Second list: generated values with stride 0x3f8, flag=0.

**Key logic:**
- If param_2 non-null: alloc 12-byte node, set data=param_2, next=0, flag=1. Append to list head/tail at param_1[0..3], increment count.
- If param_3 flag set: alloc 12-byte nodes for each of 2 values (0, 0x3f8). Each node contains generated value (*param_2 + offset), flag=0. Insert at list head at param_1[4..7].

**Calls:** operator_new (multiple)

**Used by system:** docs/20-math-utilities.md � dual-list insertion with tagged nodes

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bc270 � Indexed Float Array Access with Default

Source: unknown | Confidence: high
Reads float from indexed array offset by param_2. Validates bounds, returns default _DAT_0059e670 on failure.

**Key logic:**
- param_2 = param_2 - 1
- If index valid (>=0, <=count, <array_size): return *(array_base + param_2*4)
- Else: return _DAT_0059e670 (default)

**Globals:** _DAT_0059e670 (default value)

**Calls:** none

**Used by system:** docs/20-math-utilities.md � bounded array lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bde20 � Clamped Nested Loop with Callback

Source: unknown | Confidence: medium
Clamps 4 values to [0,7], then runs nested loops calling FUN_004bd860.

**Key logic:**
- Clamps 4 float-to-int conversions to range [0,7]
- Nested loops: outer (iVar4-iVar3+1) � inner (param_1-iVar5+1)
- Inner loop: FUN_004bd860�N
- If any clamp occurred: one extra call to FUN_004bd860

**Calls:** __ftol (float-to-int), FUN_004bd860

**Used by system:** docs/20-math-utilities.md � clamped iteration with callback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c1e20 � Destructor with Conditional Free

Source: unknown | Confidence: high
Cleanup + conditional free.

**Key logic:**
- FUN_004c0b10() � cleanup
- If (param_2 & 1): FUN_00587bcf(param_1)

**Calls:** FUN_004c0b10, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � destructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2d30 � Running Average with Clamp

Source: unknown | Confidence: high
Computes running average of param_2, clamped to [5.0f, 100.0f]. Uses weighted blending based on count.

**Key logic:**
- param_2 *= _DAT_0059e6f8 (scale input)
- If count < 2: use param_2 or old value depending on count
- Else: fVar3 = (count-1) * old_value
- fVar3 = (fVar3 + param_2) / count (running average)
- If fVar3 >= _DAT_0059e7ec (threshold): clamp to min(100.0f)
- Else: set to 5.0f

**Globals:** _DAT_0059e6f8, _DAT_0059e7ec (physics thresholds)

**Algorithm family:** statistics � running average with clamp

**Calls:** none

**Used by system:** docs/20-math-utilities.md � smoothed value with clamp

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c5c80 � String/Path Registration

Source: unknown | Confidence: high
Initializes struct with vtable, registers string via path registry.

**Key logic:**
- param_1[1]=0, param_1[2]=-1, *param_1=param_2
- FUN_00566650(param_3) � register path/name
- FUN_004c5cb0() � finalize

**Calls:** FUN_00566650, FUN_004c5cb0

**Used by system:** docs/20-math-utilities.md � path/name registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c82f0 � Camera/View System Dispatch

Source: unknown | Confidence: medium
Dispatches camera/view system methods via global vtable pointer DAT_008ac4c4.

**Key logic:**
- If DAT_008ac4c4 non-null:
  - vtable+0x38(2) � dispatch command
  - iVar1 = vtable+4(DAT_007ce2dc) � query state
  - If returns 0: vtable+0x2c(1.0f), vtable+0x34(DAT_007cf230)
  - Else: reset DAT_008ac4c4 = 0

**Globals:** DAT_008ac4c4 (camera/view system ptr), DAT_007ce2dc, DAT_007cf230

**Calls:** vtable dispatch via DAT_008ac4c4

**Used by system:** docs/20-math-utilities.md � camera/view system update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8fc0 � Decrementing Counter with Reset and Callback

Source: unknown | Confidence: medium
Decrements param_1[6] by _DAT_008afe98, resets from param_1[5] when below zero threshold, calls callback.

**Key logic:**
- param_1[6] -= (int)_DAT_008afe98
- If result < epsilon (DAT_0059e440): reset from param_1[5], call FUN_004c9000(), if non-zero: vtable+0xc dispatch

**Globals:** DAT_0059e440 (zero threshold), _DAT_008afe98

**Calls:** FUN_004c9000, vtable+0xc dispatch

**Used by system:** docs/20-math-utilities.md � counter/timer with reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ca280 � 15-Field Struct Zero-Init with Free

Source: unknown | Confidence: high
Zeros 14 int fields, frees optional pointer at [0xe], zeros it.

**Key logic:**
- Zero param_1[0..0xd] (14 ints)
- If param_1[0xe] != 0: FUN_00587bcf()
- param_1[0xe] = 0

**Calls:** FUN_00587bcf (conditional)

**Used by system:** docs/20-math-utilities.md � struct cleanup/init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ce8f0 � Float Triple Zero Check

Source: unknown | Confidence: high
Returns 0 if three floats at [0], [5], [10] all equal DAT_0059e440 (zero threshold), else 1.

**Key logic:**
- If param_1[0]==DAT_0059e440 AND param_1[5]==DAT_0059e440 AND param_1[10]==DAT_0059e440: return 0
- Else: return 1

**Globals:** DAT_0059e440 (physics zero threshold)

**Calls:** none

**Used by system:** docs/20-math-utilities.md � zero-vector check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d2dd0 � Conditional Allocation with Callbacks

Source: unknown | Confidence: high
Allocates 8-byte struct if not already allocated. Calls init functions.

**Key logic:**
- If *(param_1+0xa4) != 0: return (already allocated)
- operator_new(8) � allocate
- If success: uVar2 = FUN_004d0060(), store at param_1+0xa4
- FUN_004d0110() � finalize (always called)

**Calls:** operator_new, FUN_004d0060, FUN_004d0110

**Used by system:** docs/20-math-utilities.md � one-time allocation with init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5be0 � FIR Filter / Convolution Accumulator

Source: unknown | Confidence: medium
FIR filter or checksum accumulator. Rotates coefficients through delay line, accumulates weighted input bytes.

**Key logic:**
- For each byte in input[0..param_3-1]:
  - Rotate delay line: param_1[3]?param_1[4], param_1[4]?param_1[5]
  - Accumulate: param_1[6] += byte * param_1[3] (delayed coefficient)
- FUN_00588678(param_2, param_3, 1, *param_1) � finalize

**Algorithm family:** signal processing � FIR/convolution accumulator

**Calls:** FUN_00588678

**Used by system:** docs/20-math-utilities.md � FIR filter or stream checksum

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7da0 � Callback Registration

Source: unknown | Confidence: high
Calls FUN_00587b3e with DAT_004d7db0.

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md � callback/event registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d89d0 � Struct Init with Defaults

Source: unknown | Confidence: high
Initializes struct fields with defaults: -1 sentinels, global constant, float defaults, zeroes 25 fields.

**Key logic:**
- param_1[0..2] = -1 (sentinels)
- param_1[0x37] = DAT_005acf34 (global)
- byte at param_1+0x38 = 1
- param_1[0x39] = 1.0f, param_1[0x3a] = 1.0f
- param_1[3] = 0, [0x1d..0x1f] = 0
- Loop: zero param_1[4..0x1c] (25 ints)
- param_1[0x36] = 0

**Globals:** DAT_005acf34

**Calls:** none

**Used by system:** docs/20-math-utilities.md � struct initialization with defaults

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004db7f0 � 8-Directional UI/Sprite Render

Source: unknown | Confidence: medium
Renders 8 directional indicators based on bitmask param_1. Each direction maps to a color and position offset.

**Key logic:**
- Maps bits 0-3 to 4 color constants computed from 0x444444 base + conditional adjustment
- FUN_0058815f() � format buffer
- Calls FUN_004d7e40 8 times (N, S, E, W, NE, NW, SE, SW) with offsets +/-0xa3, 0x88, 0x6d, 0x52 and direction indices

**Calls:** FUN_0058815f (format), FUN_004d7e40 (�8, draw sprite/direction)

**Used by system:** docs/20-math-utilities.md � 8-directional UI indicator render

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dca80 � Quad 3D Position Render

Source: unknown | Confidence: medium
Renders 4 corners of a 2D rectangle in 3D space using FUN_00553650.

**Key logic:**
- If *param_1 != 0:
  - Corner 0: (x, y, z)
  - Corner 1: (x, y+h, z)
  - Corner 2: (x+w, y+h, z)
  - Corner 3: (x+w, y, z)
- Each corner gets texture u,v parameters

**Calls:** FUN_00553650 (�4, 3D vertex/quad render)

**Used by system:** docs/20-math-utilities.md � 3D quad/rectangle render

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd4c0 � Conditional Pointer Free

Source: unknown | Confidence: high
Frees pointer at param_1+8 if non-null.

**Key logic:**
- If *(param_1+8) != 0: FUN_00587bcf()

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � cleanup helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dfb90 � 26-Byte Zero-Init

Source: unknown | Confidence: high
Zero-initializes 26 bytes starting at param_1.

**Key logic:**
- Zero 2 bytes + 6 ints (24 bytes) = 26 bytes total

**Calls:** none

**Used by system:** docs/20-math-utilities.md � struct zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e9537 � Tire Force/Load Computation

Source: unknown | Confidence: medium
Complex tire physics computation. Reads tire force parameters, computes interpolated friction/force using lookup table.

**Key logic:**
- fStack1c = input / (tire_load * speed_factor) � normalize
- fVar1 = SQRT(param)
- fStack20 = slip_angle * cornering_stiffness
- fVar2 = FUN_005895a2(fStack20) � lookup/interpolate
- Clamp index to [0, 13], bilinear interpolate from table at +0x3cc0
- fVar2 *= speed_factor * (load_scale / input)
- Min with fStack1c (friction limit)
- Subtract brake_force * speed_factor * input_percent and brake_bias

**Algorithm family:** tire physics � Pacejka/lookup-based friction computation

**Calls:** SQRT, FUN_005895a2 (math lookup)

**Used by system:** docs/20-math-utilities.md � tire force computation with interpolation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f31f0 � 6�6 Array Zero-Init

Source: unknown | Confidence: high
Zero-initializes a 6�6 matrix (stride 6) and 6 additional fields.

**Key logic:**
- Loop 6 times: zero 6 consecutive ints (6�6 = 36 ints)
- Zero additional fields at +0x90..+0xa4

**Calls:** none

**Used by system:** docs/20-math-utilities.md � matrix/array zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8b00 � Screen Coordinate Clamp

Source: unknown | Confidence: medium
Clamps screen coordinates to valid range. If FUN_004f8c00 returns 0, adjusts 3 coordinates by -0x8000.

**Key logic:**
- iVar2 = FUN_004f8c00(piVar1) � validate/range check
- *param_1 = iVar2
- If 0 (invalid): subtract 0x8000 from param_1[1], param_1[2], param_1[3]

**Calls:** FUN_004f8c00

**Used by system:** docs/20-math-utilities.md � screen coordinate validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9420 � 3D Projection Setup with Global Store

Source: unknown | Confidence: medium
3D projection/viewport function. Stores result globals on success.

**Key logic:**
- iVar1 = FUN_004f9240() � compute projection
- If result < 0: return 1 (error)
- Store globals: DAT_005d6d68=param_3, DAT_008afe78=param_4, DAT_005d6d60=param_1, DAT_008afe74=iVar1, DAT_005d6d64=param_2
- Return 0

**Globals:** DAT_005d6d68, DAT_008afe78, DAT_005d6d60, DAT_008afe74, DAT_005d6d64

**Calls:** FUN_004f9240 (projection compute)

**Used by system:** docs/20-math-utilities.md � projection/viewport setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004fc850 � Float Field Init with Defaults

Source: unknown | Confidence: high
Zeroes 4 int fields, sets 2 float fields to 20.0f.

**Key logic:**
- param_1[0..3] = 0
- param_1[4] = 20.0f, param_1[5] = 20.0f

**Calls:** none

**Used by system:** docs/20-math-utilities.md � struct init with defaults

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00500161 � Parameter Reorder Wrapper

Source: unknown | Confidence: high
Calls func_0x004ff717 with reordered parameters.

**Key logic:**
- func_0x004ff717(param_4, param_2)

**Calls:** func_0x004ff717

**Used by system:** docs/20-math-utilities.md � parameter forwarding wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050210e � Graphics Driver/Hardware Cap Detection

Source: unknown | Confidence: medium
Comprehensive graphics driver detection/initialization. Detects hardware capabilities, selects rendering path (software, hardware T&L, transform, lighting), sets up resources.

**Key logic:**
- Calls FUN_00513c38 � check if already initialized
- Version check "1.0.5"
- setjmp3 for exception handling
- Detects driver type (0,2,3,4,6) maps to capabilities (0x32,0x14,0x29,0x33,0x15)
- Handles texture format detection (0x10 ? specific FOURCC codes)
- Creates lookup tables (shuffle/permute) based on hardware capabilities
- Allocates buffers via operator_new

**Globals:** _DAT_005adb68, _DAT_005adb70, _DAT_0059e420

**Calls:** multiple FUN_0051* (driver detection), operator_new, setjmp3

**Used by system:** docs/20-math-utilities.md � graphics driver init / hardware caps detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050415c � Image/Texture Blend

Source: unknown | Confidence: high
Alpha-blends two images/textures using 16-bit color averaging with dither.

**Key logic:**
- Walks destination rows (param_1[1]+0x18) and source rows (*param_1+0x18)
- Inner loop: blends 16-bit pixels using (a+b+0x202)>>2 with per-channel masking
- Uses color channel separation: &0xf0f (low nibbles) and &0xffff00f0 (high bytes)

**Algorithm family:** graphics � 16-bit color blending/averaging

**Calls:** none

**Used by system:** docs/20-math-utilities.md � image compositing/blend

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050a911 � Object Init with Size/Type

Source: unknown | Confidence: high
Calls FUN_00507496 with size=0x10, type=1, sets vtable.

**Key logic:**
- FUN_00507496(param_2, 0x10, 1)
- *param_1 = &PTR_FUN_005adbe8

**Calls:** FUN_00507496

**Used by system:** docs/20-math-utilities.md � object constructor with size/type config

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b3ed � Object Init with Size/Type

Source: unknown | Confidence: high
Calls FUN_00507496 with size=0x20, type=2, sets vtable.

**Key logic:**
- FUN_00507496(param_2, 0x20, 2)
- *param_1 = &PTR_FUN_005add4c

**Calls:** FUN_00507496

**Used by system:** docs/20-math-utilities.md � object constructor with size/type config

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c07c � 6-Parameter Dispatch Wrapper

Source: unknown | Confidence: high
Calls FUN_0050fea7(1) then dispatches via PTR_FUN_005d780c with all 6 params.

**Key logic:**
- FUN_0050fea7(1) � acquire/init
- (PTR_FUN_005d780c)(param_1..param_6) � dispatch

**Calls:** FUN_0050fea7, PTR_FUN_005d780c (indirect)

**Used by system:** docs/20-math-utilities.md � parameterized dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050cdec � Init + Indirect Call

Source: unknown | Confidence: high
Calls FUN_0050fea7(1), then calls through _DAT_005d785c.

**Key logic:**
- FUN_0050fea7(1)
- (*_DAT_005d785c)() � indirect call

**Calls:** FUN_0050fea7, indirect via _DAT_005d785c

**Used by system:** docs/20-math-utilities.md � init + dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050dd0c � 4-Parameter Dispatch Wrapper

Source: unknown | Confidence: high
Calls FUN_0050fea7(1) then dispatches via PTR_FUN_005d782c with 4 params.

**Key logic:**
- FUN_0050fea7(1)
- (PTR_FUN_005d782c)(param_1..param_4)

**Calls:** FUN_0050fea7, PTR_FUN_005d782c (indirect)

**Used by system:** docs/20-math-utilities.md � parameterized dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050f199 � 4�4 Matrix Construction from Euler/Quat

Source: unknown | Confidence: high
Constructs a 4�4 transformation matrix from Euler angles/quaternion. Includes rotation, scaling, identity last row.

**Key logic:**
- thunk_FUN_0050e3cd(&local_14, param_2) � decompose euler/quaternion to sines/cosines
- fVar1..fVar3 = local_14 * _DAT_0059e7f0 (scaled rotation components)
- 4�4 matrix:
  - Row 0: [xx, xy, xz, 0]
  - Row 1: [yx, yy, yz, 0]
  - Row 2: [zx, zy, zz, 0]
  - Row 3: [tx, ty, tz, 1]
- Each element computed from rotation products + _DAT_0059e43c base offset

**Globals:** _DAT_0059e43c, _DAT_0059e7f0 (physics constants)

**Algorithm family:** 3D math � 4�4 matrix from Euler/quaternion

**Calls:** thunk_FUN_0050e3cd

**Used by system:** docs/20-math-utilities.md � 3D transformation matrix construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005115ee � Vtable Function Table Init

Source: unknown | Confidence: high
Allocates and populates a vtable function table with 0x5c bytes, sets default method pointers.

**Key logic:**
- Allocates 0x5c bytes via vtable dispatch
- Stores at param_1+400
- Sets method pointers: [0]=FUN_005115c4, [4]=&LAB_0051126a, [8]=FUN_00511457, [0xc]=FUN_00511060
- Loop 0x10..0x50: set all to FUN_00511060
- Override [0x10]=FUN_005105bf, [0x48]=FUN_005107fb
- FUN_005115c4(param_1) � finalize

**Calls:** vtable alloc dispatch, FUN_005115c4

**Used by system:** docs/20-math-utilities.md � virtual method table initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005123b3 � Byte Swap by Pairs

Source: unknown | Confidence: high
Swaps adjacent byte pairs in buffer if flag at param_1+9 equals 0x10.

**Key logic:**
- If *(param_1+9) == 0x10:
  - Loop: swap param_2[i] ? param_2[i+1], advance by 2
  - Iteration count: *(param_1+10) * *param_1

**Algorithm family:** data transformation � byte pair swap

**Calls:** none

**Used by system:** docs/20-math-utilities.md � byte-order transformation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513e80 � Float-to-24-bit Color Conversion

Source: unknown | Confidence: high
Converts 3 float values [0,1] to packed 24-bit RGB color with clamping and rounding.

**Key logic:**
- Clamp each float component to [0, 1] using DAT_0059e440 and _DAT_0059e43c thresholds
- FUN_00513e5d() � pre-conversion
- Pack: R<<6 | G<<5 | B, each rounded to int with offset _DAT_0059e450 and scaled by _DAT_005accd0/_DAT_005accd8

**Globals:** DAT_0059e440, _DAT_0059e43c, _DAT_005accd0, _DAT_005accd8, _DAT_0059e450

**Algorithm family:** color conversion � float[0,1] to 24-bit RGB

**Calls:** ROUND, FUN_00513e5d

**Used by system:** docs/20-math-utilities.md � color space conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051623e � Linked List Node Insert with Field Init

Source: unknown | Confidence: high
Inserts a 0x78-byte node into a linked list, initializes fields and flag.

**Key logic:**
- If param_2 != 1: set (*param_1)+0x14=0xc, +0x18=param_2, call *param_1()
- Alloc 0x78-byte node via FUN_00515f23
- Init: [0]=0, [1]=param_5, [2]=param_4, [3]=param_6, byte at +0x22=0, byte at [8]=param_3, [9]=*(iVar1+0x44)
- Prepend to list at iVar1+0x44

**Calls:** FUN_00515f23 (alloc)

**Used by system:** docs/20-math-utilities.md � linked list node creation and insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005179a2 � Resource/Process Release Guard

Source: unknown | Confidence: high
Validates pointers, calls cleanup callback, zeros resource pointer.

**Key logic:**
- If param_1 and *(param_1+0x1c) and *(param_1+0x24) valid:
  - iVar1 = *(*(param_1+0x1c)+0x14)
  - If non-null: FUN_00527eed(iVar1, param_1)
  - Call *(param_1+0x24)(*(param_1+0x28), *(param_1+0x1c)) � cleanup dispatch
  - Set *(param_1+0x1c)=0
  - Return 0
- Return -2 (0xfffffffe)

**Calls:** FUN_00527eed, function pointer at +0x24 dispatch

**Used by system:** docs/20-math-utilities.md � resource release with validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051a5ea � Huffman/Compression Tree Builder

Source: unknown | Confidence: medium
Builds Huffman coding tables from symbol frequency data. Computes code lengths, prefixes, and table entries.

**Key logic:**
- Allocates 0x5d4-byte struct at *param_3 if not already allocated
- Processes 17 symbols (indices 0x00-0x10) with frequency data from param_2
- Builds code length histogram (aiStack_520)
- Computes starting codes per length
- Fills encoding table at +0x48 (16 entries with code+length)
- Fills decode table at +0xd4 (0x100 entries with symbol values)
- Fills decode table at +0x4d4 (bit-length prefix data)

**Algorithm family:** data compression � Huffman code table generation

**Calls:** alloc via indirect (param_1+4)

**Used by system:** docs/20-math-utilities.md � Huffman coding table construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051ec00 � 4-Component Vector/Matrix Transform

Source: unknown | Confidence: high
Transforms 2D input vector through 4�4 matrix, producing 4-component output.

**Key logic:**
- Reads param_2 (2 components: x, y)
- Reads param_3 (4�4 matrix: 16 floats)
- Output: *param_1 = x*M[0] + M[0xc] + y*M[4]
- param_1[1] = x*M[1] + M[0xd] + y*M[5]
- param_1[2] = x*M[2] + M[0xe] + y*M[6]
- param_1[3] = x*M[3] + M[0xf] + y*M[7]

**Algorithm family:** 3D math � 2D-to-4D vector transform through 4�4 matrix

**Calls:** none

**Used by system:** docs/20-math-utilities.md � 3D coordinate transform

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052765a � Async I/O/State Reset Handler

Source: unknown | Confidence: medium
Handles async I/O completion or state reset. Dispatches based on state type, resets state machine.

**Key logic:**
- If param_3 non-null: *param_3 = param_1[0xf] (store result)
- If *param_1 == 4 or 5: dispatch callback at param_2+0x24(param_2+0x28, param_1[3])
- If *param_1 == 6: FUN_0052a090(param_1[1], param_2)
- Reset state: param_1[0xd]=param_1[10], param_1[0xc]=param_1[10], *param_1=0, [7]=0, [8]=0
- If param_1[0xe] non-null: call callback, store result at param_1[0xf] and param_2+0x30

**Calls:** FUN_0052a090, callback at param_1[0xe]

**Used by system:** docs/20-math-utilities.md � async I/O completion/state machine reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052da10 � Conditional-Sized Array Zero-Init

Source: unknown | Confidence: high
Zeroes an array of 0x240 or 0x480 elements based on global flag DAT_008b0108.

**Key logic:**
- If DAT_008b0108 == 0: iVar1 = 0x480 (1216 elements)
- Else: iVar1 = 0x240 (576 elements)
- Loop: zero 4-byte elements

**Globals:** DAT_008b0108

**Calls:** none

**Used by system:** docs/20-math-utilities.md � array initialization with configurable size

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00534b00 � Single Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00534b10(-1).

**Calls:** FUN_00534b10

**Used by system:** docs/20-math-utilities.md � call wrapper with fixed arg

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005361d0 � Multi-Condition Dispatch with Cleanup

Source: unknown | Confidence: medium
Checks type field for specific values (0x2a, 0x71, 0x29a), dispatches multiple callbacks, resets state.

**Key logic:**
- If param_1 and *(param_1+0x1c) and *(param_1+0x1c)+4 in {0x2a, 0x71, 0x29a}:
  - Dispatch *(param_1+0x24) for each of 4 non-null sub-conditions
  - Always dispatch once at end
  - Set *(param_1+0x1c)=0
  - Return 0xfffffffd or 0xfffffffe based on type
- Return 0xfffffffe

**Calls:** *(param_1+0x24) (�4 or more)

**Used by system:** docs/20-math-utilities.md � type-conditional multi-callback dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053ad50 � Multi-Field Free + Cleanup

Source: unknown | Confidence: high
Sets vtable, frees 3 pointers, calls base cleanup.

**Key logic:**
- *param_1 = &PTR_LAB_005b8910
- FUN_00587bcf(param_1[4])
- FUN_00587bcf(param_1[8])
- FUN_00587bcf(param_1[0xc])
- FUN_004b0170() � base cleanup (math_util)

**Calls:** FUN_00587bcf (�3), FUN_004b0170

**Used by system:** docs/20-math-utilities.md � destructor with triple free

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c150 � Callback Registration

Source: unknown | Confidence: high
Calls FUN_00587b3e with LAB_0053c160.

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md � callback/event registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053caf0 � Resource Cleanup with Conditional Free

Source: unknown | Confidence: high
Calls cleanup function, conditionally releases and frees param_1.

**Key logic:**
- FUN_00547420() � cleanup
- If param_1 != 0: FUN_00557470(), FUN_00587bcf(param_1)

**Calls:** FUN_00547420, FUN_00557470 (no-op release), FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � resource destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d8b0 � Struct Copy with Bounded Count

Source: unknown | Confidence: high
Copies 0x10f*4 bytes from param_2 into indexed slot of struct array. Bounded by count < 4.

**Key logic:**
- If *(param_1+8) < 4:
  - Copy 0x10f (271) dwords from param_2 to slot at index*(0x43c)+0xc
  - Increment count at *(param_1+8)

**Calls:** none

**Used by system:** docs/20-math-utilities.md � bounded array slot copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00541ca0 � Flag Bit Set/Clear

Source: unknown | Confidence: high
Sets or clears bit 3 in flag field at param_1+0x80.

**Key logic:**
- If param_2 != 0: *(param_1+0x80) |= 8
- Else: *(param_1+0x80) &= ~8

**Calls:** none

**Used by system:** docs/20-math-utilities.md � flag bit setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005434a0 � Float-to-Int Convert + Render Dispatch

Source: unknown | Confidence: medium
Converts float parameters to ints via __ftol, dispatches to render function, clears flag bit.

**Key logic:**
- Four __ftol() conversions from float params
- FUN_00543540(&dimensions) � setup dimensions
- If width>0 and height>0: FUN_005404d0(param_1, x, y, w, h, param_6) � render/bitblt
- Clear bit 10 (0x400) in flag at *(param_1+0x18)

**Calls:** __ftol (�4), FUN_00543540, FUN_005404d0

**Used by system:** docs/20-math-utilities.md � render dispatch with float-to-int conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00546f30 � Bounded Check + Trigger

Source: unknown | Confidence: high
If param_2 < *(param_1+0xa4) AND *(param_1+0xa4) < 8: call FUN_0054fc40(0x100000).

**Key logic:**
- If condition: FUN_0054fc40(0x100000) � trigger with mask

**Calls:** FUN_0054fc40

**Used by system:** docs/20-math-utilities.md � bounded condition trigger

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547670 � Linked List Append with Flag-Based Counter

Source: unknown | Confidence: high
Appends node to linked list, increments one of four counters based on flag bits at +0x9c.

**Key logic:**
- If list head at *(param_1+0x24) == 0: set head = param_2
- Else: walk to tail via +0xc0, append
- Set param_2+0xbc = prev, param_2+0xc0 = 0
- Check flags at *(param_2+0x9c):
  - If 0x20 & 0x100: increment param_1+0x1c
  - If 0x20 only: increment param_1+0x20
  - If 0x100 only: increment param_1+0x14
  - Else: increment param_1+0x18
- Increment total counter at *(param_1+0x10)

**Calls:** none

**Used by system:** docs/20-math-utilities.md � categorized linked list append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00549110 � Recursive Node Deletion with Shutdown Check

Source: unknown | Confidence: high
Recursive node deletion. Frees children first, checks shutdown condition, decrements refcount, frees self.

**Key logic:**
- If *(param_1+0x44) != 0: recursively call FUN_00549110()
- If *(param_1+0x40) and *(param_1+0x4c): recursively call
- FUN_0054a770() � shutdown check
- If shutdown: return -1
- FUN_0054a710() � decrement refcount
- FUN_00587bcf(param_1) � free self

**Calls:** FUN_00549110 (recursive), FUN_0054a770, FUN_0054a710, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � recursive tree/node destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054b450 � 3� Random Float Setter

Source: unknown | Confidence: high
Sets 3 float fields (+0x2c, +0x30, +0x34) to random values, then calls FUN_0054b330.

**Key logic:**
- *(param_1+0x2c) = FUN_0058957a() (random float)
- *(param_1+0x30) = FUN_0058957a() (random float)
- *(param_1+0x34) = FUN_0058957a() (random float)
- FUN_0054b330(0x40, 0, 0)

**Calls:** FUN_0058957a (�3, random), FUN_0054b330

**Used by system:** docs/20-math-utilities.md � random field initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054eac0 � Callback Registration

Source: unknown | Confidence: high
Calls FUN_00587b3e with LAB_0054ead0.

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md � callback/event registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fe50 � String Allocation + Path Extract

Source: unknown | Confidence: medium
Allocates 0x3c-byte struct, extracts filename from full path (finds last backslash), copies to struct buffer.

**Key logic:**
- operator_new(0x3c) � allocate struct
- FUN_005426a0() � init
- Store at *(param_1+0x54)
- Find last '\\' in param_2 (backslash search)
- Copy filename portion to param_1+4 via offset trick
- FUN_00589901(param_1+4) � normalize

**Calls:** operator_new, FUN_005426a0, FUN_00589901

**Used by system:** docs/20-math-utilities.md � filename extraction from path

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00557240 � Init Struct + Call Loop

Source: unknown | Confidence: high
Calls base init, runs a function 8 times, zeros 3 fields at +0x204/0x208/0x20c.

**Key logic:**
- FUN_0053c2a0() � base init
- Loop 8 times: FUN_00553db0()
- Zero fields: *(param_1+0x204)=0, *(param_1+0x208)=0, *(param_1+0x20c)=0

**Calls:** FUN_0053c2a0, FUN_00553db0 (�8)

**Used by system:** docs/20-math-utilities.md � struct init with repeated sub-call

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c2a0 � Linked List Tail Append

Source: unknown | Confidence: high
Appends param_2 to linked list at param_1+0x1518. Finds tail via +0x20 link chain.

**Key logic:**
- If list head *(param_1+0x1518) non-null: walk to tail via +0x20, set tail->+0x20=param_2, param_2->+0x1c=tail
- Else: set head = param_2

**Calls:** none

**Used by system:** docs/20-math-utilities.md � linked list append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00563e70 � Pointer Dereference Accessor

Source: unknown | Confidence: high
Returns *param_1 (dereference pointer).

**Key logic:**
- return *param_1

**Calls:** none

**Algorithm family:** accessor � pointer dereference

**Used by system:** docs/20-math-utilities.md � simple accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00566db0 � State Check + Lookup Wrapper

Source: unknown | Confidence: medium
Checks flag at param_1[4]; if set, calls FUN_00535390(0). Otherwise looks up key in hash/table.

**Key logic:**
- If param_1[4] != 0: return FUN_00535390(0) (bypass lookup)
- Else: iVar1 = FUN_00587f64(*param_1, param_2) � lookup
- If found: return param_2
- Else: return -1

**Calls:** FUN_00535390, FUN_00587f64

**Used by system:** docs/20-math-utilities.md � conditional lookup bypass

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0056eb90 � Array-of-Structs Zero-Init (stride 0x244)

Source: unknown | Confidence: high
Zeroes 12 int fields per element for *param_1 elements, stride 0x244.

**Key logic:**
- For iVar2 from 0 to *param_1-1:
  - Zero 12 ints at base + iVar3 + offsets 0x134..0x160
  - Advance iVar3 by 0x244 (stride)

**Calls:** none

**Used by system:** docs/20-math-utilities.md � array struct field zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057adb0 � Single Delegation Call

Source: unknown | Confidence: high
Calls FUN_00598815().

**Calls:** FUN_00598815

**Used by system:** docs/20-math-utilities.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00584110 � Float Accumulator at +0xe0

Source: unknown | Confidence: high
Adds param_2 to accumulated double at offset +0xe0.

**Key logic:**
- *(param_1+0xe0) += (double)param_2

**Calls:** none

**Used by system:** docs/20-math-utilities.md � accumulator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587200 � Byte Setter at +0x18

Source: unknown | Confidence: high
Sets single byte field at param_1+0x18.

**Key logic:**
- *(param_1+0x18) = param_2

**Calls:** none

**Used by system:** docs/20-math-utilities.md � field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587db0 � Delegation with Fixed Arg (0x40)

Source: unknown | Confidence: high
Calls FUN_00587d7f with third parameter fixed at 0x40.

**Key logic:**
- FUN_00587d7f(param_1, param_2, 0x40) � CRT stream read with 0x40 size

**Calls:** FUN_00587d7f (CRT stream getc with lock, docs/20)

**Used by system:** docs/20-math-utilities.md � fixed-size stream read wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a870 � MSVC 64-bit Unsigned Shift Right

Source: MSVC CRT | Confidence: high
MSVC __aullshr � 64-bit unsigned shift right. Handles shifts >63 (returns 0), 32-63, and 0-31.

**Key logic:**
- If shift > 63: return 0
- If shift >= 32: return param_2 >> (shift-32)
- Return CONCAT44(param_2>>shift, in_EAX>>shift | param_2<<(32-shift))

**Algorithm family:** MSVC CRT � 64-bit arithmetic

**Calls:** none

**Used by system:** docs/20-math-utilities.md � MSVC compiler runtime helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058dcb5 � Empty Stub

Source: unknown | Confidence: high
No-op � returns immediately with no operations.

**Key logic:**
- Bare return � no instructions

**Used by system:** docs/20-math-utilities.md � placeholder stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059508d � Masked Wrapper

Source: unknown | Confidence: high
Calls FUN_00595058 with param_2 & 0xfff7ffff (clears bit 19).

**Key logic:**
- FUN_00595058(param_1, param_2 & 0xfff7ffff)

**Calls:** FUN_00595058

**Used by system:** docs/20-math-utilities.md � masked argument wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005986b2 � Call Wrapper with Param

Source: unknown | Confidence: high
Calls FUN_00598e2e(0).

**Calls:** FUN_00598e2e

**Used by system:** docs/20-math-utilities.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059984f � Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00599e66(0).

**Calls:** FUN_00599e66 (vtable setter, docs/20)

**Used by system:** docs/20-math-utilities.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059b24a � RtlUnwind

Source: MSVC CRT | Confidence: high
MSVC RtlUnwind. Recursive call to RtlUnwind (thunk/trampoline via indirect jmp).

**Key logic:**
- RtlUnwind(TargetFrame, TargetIp, ExceptionRecord, ReturnValue) � pass-through

**Algorithm family:** MSVC CRT � exception unwinding

**Calls:** RtlUnwind (Win32 CRT)

**Used by system:** docs/20-math-utilities.md � MSVC exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c770 � C++ Unwind Helper (thunk)

Source: MSVC CRT | Confidence: high
Thunk to FUN_005867b0 (linked list cleanup).

**Key logic:**
- Calls FUN_005867b0 � linked list node cleanup with sub-object delete

**Calls:** FUN_005867b0 (list cleanup, docs/20)

**Algorithm family:** MSVC SEH � unwind cleanup

**Used by system:** docs/20-math-utilities.md � MSVC exception handling unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cebb � C++ Unwind Helper (thunk)

Source: MSVC CRT | Confidence: high
Thunk to FUN_00585fb0 (linked list cleanup).

**Key logic:**
- Calls FUN_00585fb0 � linked list cleanup with sub-object delete (docs/20)

**Calls:** FUN_00585fb0 (list cleanup, docs/20)

**Algorithm family:** MSVC SEH � unwind cleanup

**Used by system:** docs/20-math-utilities.md � MSVC exception handling unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d594 � MSVC Exception Handler

Source: MSVC CRT | Confidence: high
Calls exception::~exception(*(exception**)(EBP-0x10)) � C++ exception object destructor during unwind.

**Key logic:**
- exception::~exception(*(exception**)(unaff_EBP - 0x10)) � destroy exception object

**Algorithm family:** MSVC CRT � exception object destruction during unwind

**Calls:** exception::~exception (C++ runtime)

**Used by system:** docs/20-math-utilities.md � MSVC exception handling

**Moddability:** hardcoded

## FUN_0050cdf9 — Thunk via Global Function Pointer

Source: unknown | Confidence: high
Trampoline — indirect call through global function pointer at DAT_005d785c. No local logic.

**Key logic:**
- Single indirect call via `(*_DAT_005d785c)()` — reads function pointer from global and dispatches
- Used as an indirect call stub where the target function is selected at runtime
- Ghidra notes "Could not recover jumptable" — this is a function pointer dispatch, not a jump table

**Globals:**
- `DAT_005d785c` — function pointer (not in docs/12; likely renderer call table entry)

**Calls:** (*DAT_005d785c) (indirect target)

**Used by system:** docs/19-renderer.md — matrix stack push/pop operations
(referenced in FUN_00419a10's matrix stack identity set path)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00559630 — Linked List Node Search & Allocation

Source: unknown | Confidence: high
Searches a linked list for a node matching (param_2, param_3) key pair. If found, returns existing node. Otherwise allocates a new 0x20-byte node, initializes via FUN_00559330, and appends to list tail.

**Key logic:**
- Reads list head from `param_1 + 8`
- First pass: iterates via `+0x1c` (next), matches against `+0x14 == param_2` and `+0x18 == param_3`
- If match found: returns existing node
- Second pass (if head exists): walks to tail via `+0x1c` chain
- Allocates 0x20 bytes via operator_new
- If allocation fails: sets uVar4 = 0
- If succeeds: calls FUN_00559330 for initialization
- Appends new node to tail: `*(tail+0x1c) = uVar4`
- Calls FUN_00559390(key) to finalize
- If no head exists: allocates, inits, sets `param_1+8 = uVar4`, finalizes
- On alloc failure with no head: sets `param_1+8 = 0`, calls FUN_00559390 anyway

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | int* | linked list head pointer |

**Struct offsets (node):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x14 | int | first key (param_2) |
| +0x18 | int | second key (param_3) |
| +0x1c | int* | next node pointer |

**Calls:**
- operator_new (0x20 bytes) — heap allocation
- FUN_00559330 — node initializer (unknown)
- FUN_00559390 — node key setter (unknown)

**Used by system:** docs/20-math-utilities.md — data structure utility; generic key-value linked list container

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00582b10 — Linked List Element Removal with Cleanup

Source: unknown | Confidence: high
Searches a linked list for a node matching a value stored at head. Removes matching node(s), optionally frees sub-data via FUN_005867b0/FUN_00587bcf.

**Key logic:**
- Saves head value: `param_1[2] = *param_1` (iterator position)
- If head is non-null: reads key value `*head` as search target; sets `(char*)(head+2) = 0` (clears flag)
- Search: walks list via node[1] (next pointer), compares `*node == key`
- On match:
  - If node is current iterator (param_1[2]): advances iterator to node->next
  - If prev is null: updates head = node->next
  - Else: prev->next = node->next
  - If tail ptr (param_1[1]) == node: tail = prev
  - Decrements count (param_1[3])
  - If node[2] flag byte set AND `*node != 0`: calls FUN_005867b0 (SEH-guarded cleanup) then FUN_00587bcf (free sub-data)
  - Frees node itself via FUN_00587bcf
  - Returns the key value
- Returns 0 if not found

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | head pointer |
| +0x04 | int* | tail pointer |
| +0x08 | int* | current/iterator position |
| +0x0c | int | count |

**Struct offsets (node):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int | key value |
| +0x04 | int* | next pointer |
| +0x08 | char | flag byte |

**Calls:**
- FUN_005867b0 — SEH-guarded cleanup (docs/08, docs/20)
- FUN_00587bcf — free/delete operator

**Used by system:** docs/20-math-utilities.md — linked list container element removal with managed sub-object lifetime

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059987c — Locale Function Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper calling FUN_00599c58 with fixed arguments (0, 1).

**Key logic:**
- Calls `FUN_00599c58(0, 1)` — locale/CRT init call (unknown)
- No parameters, no return value manipulation

**Calls:**
- FUN_00599c58 — locale or CRT initialization function (unknown)

**Used by system:** docs/20-math-utilities.md — locale/CRT startup sequence

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00401030 — Array Destructor Iterator

Source: MSVC CRT | Confidence: high
MSVC++ array destructor helper. Calls a destructor callback N-1 times (iteration over array elements).

**Key logic:**
- Checks `param_3 - 1 >= 0` — at least one element
- Loop: calls `(*param_4)()` destructor callback, decrements count, repeats until zero
- param_1 = this pointer, param_2 = unknown, param_3 = count, param_4 = destructor function
- Standard MSVC `_destroy` / `_vector_destructor_iterator` pattern

**Calls:**
- (*param_4)() — destructor callback per element

**Used by system:** docs/20-math-utilities.md — MSVC CRT array destruction for C++ objects

**Algorithm family:** C++ array teardown

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005992b7 — Destructor with Flag Cleanup

Source: unknown | Confidence: high
Destructor stub that optionally frees memory based on a flag bit.

**Key logic:**
- Calls `FUN_00598cc1()` — pre-destructor cleanup (triage: C++ unwind helper)
- If `(param_2 & 1) != 0`: calls `FUN_00587bcf(param_1)` — free the object
- Returns param_1

**Calls:**
- FUN_00598cc1 — pre-destructor cleanup (triage: C++ unwind helper)
- FUN_00587bcf — free/delete operator

**Used by system:** docs/20-math-utilities.md — C++ object destructor with conditional delete

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058bef0 — Int-to-String with Sign + Position Draw

Source: unknown | Confidence: low
Converts a 64-bit integer to string representation and draws it at a screen position. Combines number formatting and text output.

**Key logic:**
- Calls `FUN_00595621(*param_1, &local_14, local_2c)` — int64-to-string conversion
- Calls `FUN_005955aa(sign_adj + param_2, local_10 + param_3, &local_14)` — decimal string formatting with rounding (docs/20)
- Calls `FUN_0058bf45(param_2, param_3, &local_14, 0)` — text draw at screen position
- Returns param_2 (original X position)

**Calls:**
- FUN_00595621 — int64 to string conversion
- FUN_005955aa — decimal string formatting with rounding (docs/20)
- FUN_0058bf45 — screen text draw at position

**Used by system:** docs/20-math-utilities.md — UI text rendering for numeric values

**Algorithm family:** numeric-to-string formatting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058dce5 — __fload_withFB — Float Load with NaN Check

Source: MSVCRT (Visual Studio) | Confidence: high
MSVC CRT library function. Loads a float/double value, checks for NaN by testing exponent bits.

**Key logic:**
- Reads upper 32 bits of double at `param_2 + 4`
- Masks with 0x7ff00000 (exponent bits for double)
- If exponent == 0x7ff (NaN/Inf): returns full high word (preserves NaN payload)
- Otherwise: returns masked exponent (non-NaN path)

**Calls:** none

**Used by system:** docs/20-math-utilities.md — MSVCRT math library; called by pow/log/transcendental functions

**Algorithm family:** IEEE 754 float classification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059083b — __ctrandisp1 — CRT Float Display/Format

Source: MSVCRT (Visual Studio) | Confidence: high
MSVC CRT library function for float-to-string conversion. Chains three internal calls.

**Key logic:**
- Calls `__fload(param_1, param_2)` — load float operand
- Calls `__trandisp1()` — float classification/dispersion (MSVCRT, triage index)
- Calls `FUN_00590703()` — stub/no-op (docs/06)

**Calls:**
- __fload — MSVC CRT float load
- __trandisp1 — MSVC CRT float classification
- FUN_00590703 — stub/no-op (docs/06)

**Used by system:** docs/20-math-utilities.md — MSVCRT printf/format float handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404b50 — Short Computation (Struct Field Zero)

Source: unknown | Confidence: high
Zeroes three fields of a struct pointed to by param_1's first field.

**Key logic:**
- Reads pointer from `*param_1` (indirect pointer)
- Zeroes bytes at `+0x14`, `+0x15` (2 bytes), and dword at `+0x1c`

**Struct offsets (indirect):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x14 | byte | zeroed |
| +0x15 | byte | zeroed |
| +0x1c | undefined4 | zeroed |

**Used by system:** docs/20-math-utilities.md — struct field initialization helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004056a0 — Memory Allocation / Serialization Struct Builder

Source: unknown | Confidence: medium
Builds a serialization packet by reading configuration fields from param_2 and writing them sequentially via FUN_00405670.

**Key logic:**
- Reads flag byte from `param_2 + 0x1b`
- Branch: if `(flag & 0x20) && (flag & 4)`: uses `param_2 + 0x20` as base; else uses `param_2 + 4`
- Computes:
  - `local_20[0] = base + 0x24`
  - `local_10 = *(param_2 + 0x18)` as ushort (element count)
  - `local_4 = (param_2 >> 16) | (param_2 + 0x1a byte)`
  - `local_20[1] = 0x10` (stride)
  - `local_20[2] = 1`
  - `local_20[3] = ((flag & 1) != 0) + 1`
  - `local_8 = (byte(param_2+0x1a) * local_20[3]) >> 3`
  - `local_c = local_8 * local_10`
- Writes 12 fields sequentially via FUN_00405670 using serialization constants (DAT_005be844, _83c, _834, _82c)

**Struct offsets (param_2):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | int | default base offset |
| +0x18 | ushort | element count |
| +0x1a | byte | field width |
| +0x1b | byte | flags (bits 0, 2, 5 used) |
| +0x20 | int | alt base offset |

**Globals:**
- DAT_005be844, DAT_005be83c, DAT_005be834, DAT_005be82c — serialization constants (docs/12)

**Calls:**
- FUN_00405670 — serialization field writer (unknown)

**Used by system:** docs/20-math-utilities.md — memory/resource serialization packet construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
