=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x0040b5a0 | callback | HIGH | C++ constructor with vtable switch pattern: sets vtable PTR_LAB_0059e6ac, calls virtual on sub-object at this+0xC, sets vtable PTR_LAB_0059e634. Called by operator new + placement new chain in user code | FUN_0040b5a0 is constructor body — called via new expression |
| 0x0044ca40 | callback | HIGH | Static collision data initializer for region block at 0x007cca7c. Sets type=12, Z, W=-1.0f. Data referenced by FUN_00452810 and FUN_0044ff50 collision search functions. Called via init function table during collision system startup | Unknown init dispatcher |
| 0x0044cfe0 | callback | HIGH | Static collision material init for block at 0x007cc9ec. Sets type=40, Z, W=0.0f, last=1.0f. Data referenced by FUN_00452810 and FUN_0044ff50. Called via init function table | Unknown init dispatcher |
| 0x0044d580 | callback | HIGH | Static collision region init for block at 0x007ccd08. Sets type=18, zeros. Data referenced by FUN_00452b10. Called via init function table | Unknown init dispatcher |
| 0x0044db20 | callback | HIGH | Static collision region init for block at 0x007ccf00. Sets type=46, zeros. Data referenced by FUN_00452b10. Called via init function table | Unknown init dispatcher |
| 0x0044e0c0 | callback | HIGH | Static collision region init for block at 0x007ccd98. Sets type=69, zeros. Data referenced by FUN_00452b10. Called via init function table | Unknown init dispatcher |
| 0x0044e660 | callback | HIGH | Static collision region init for block at 0x007cd04c. Sets type=84, zeros, and DAT_007cd060=18000. Data referenced by FUN_00452b10. Called via init function table | Unknown init dispatcher |
| 0x0044ec00 | callback | HIGH | Static collision region init for block at 0x007ca3f8. Sets type=99, zeros, and DAT_007ca40c=9000. Data referenced by FUN_00452b10. Called via init function table | Unknown init dispatcher |
| 0x0046c710 | game_logic_isolated | MEDIUM | Scans global arrays (DAT_007cd470 or DAT_007cd2b8) for negative values, returns count before first negative. Branches on param_1+0x174. Real game logic, references collision detection data arrays | — |
| 0x00486300 | game_logic_isolated | MEDIUM | UI string accessor. Returns string pointer from struct field at offset +0x50, or default path DAT_005ea438 if null. param_1+200 checked for null. Real game logic with UI context | — |
| 0x0049a110 | utility_isolated | HIGH | Linked list walker: skips param_2 nodes from list head at param_1+8, counts remaining nodes via +0x24/+0x28 offsets. Pure linked list utility, no game globals | — |
| 0x00500161 | utility_isolated | HIGH | Parameter reorder wrapper (4 bytes→2 params). Calls func_0x004ff717(param_4, param_2). Tiny shim likely for call convention adaptation | — |
| 0x0050d0bc | callback | HIGH | Thunk via global pointer _DAT_005d7810. Indirect jump through a function pointer stored in global. Called by code that writes to _DAT_005d7810 | Unknown dispatcher writing to DAT_005d7810 |
| 0x0050e84b | utility_isolated | HIGH | 2x2 matrix multiply with 6-element strided layout (accesses indices 0,1,4,5 in 6-element arrays). Pure math utility, no game globals | — |
| 0x0051bd61 | game_logic_isolated | MEDIUM | Audio ring buffer manager. Accesses param_1+0x188, virtual dispatch at +0x1c and +4 offsets. Handles buffer wrap-around (overflow to +0x14 counter). Real audio subsystem code | — |
| 0x0053aeb0 | utility_isolated | HIGH | Vertex batch transform with dual 4x4 matrix. Transforms vertices through two matrices (param_3, param_4), writes to param_1+0x30 and +0x10. Pure renderer transform math | — |
| 0x005604c0 | utility_isolated | HIGH | Pixel buffer blit with short-to-16bpp conversion. Uses LOCK/UNLOCK (multithreaded access). Row/column blit with stride. Pure renderer utility | — |
| 0x0057aa50 | utility_isolated | HIGH | Zeroes 4 consecutive globals at 0x008d3bfc-0x008d3c08. Simple init/reset function for unknown state variables | — |
| 0x0058a2a6 | entry_point | HIGH | MSVC CRT __amsg_exit. Runtime error exit with message display. Called by CRT abort/assert machinery. Library function | CRT abort handler |
| 0x0059086e | entry_point | HIGH | MSVC CRT __fload. 80-bit float load from memory. Called by CRT float operations. Library function | CRT floating point support |
| 0x00598660 | entry_point | HIGH | gethostbyname import thunk. Indirect jump to ws2_32.dll import. Called by networking code | Network subsystem caller |
| 0x00599689 | entry_point | HIGH | C++ exception catch block frame. Allocates buffer via operator_new with size from exception object+2. Standard MSVC SEH catch frame handler | MSVC exception dispatcher |
| 0x0059c86a | entry_point | HIGH | SEH unwind handler. Thunks to FUN_00581750 (common unwind helper). Standard MSVC exception handler frame | MSVC exception dispatcher |
| 0x0059cf94 | entry_point | HIGH | SEH unwind handler. Thunks to FUN_00581750 (common unwind helper). Standard MSVC exception handler frame | MSVC exception dispatcher |
| 0x0059d56c | entry_point | HIGH | SEH unwind: destroys exception object. Calls exception::~exception() on the caught exception object. Standard MSVC cleanup frame | MSVC exception dispatcher |

=== FULL ENTRIES ===
<!-- target: docs/20-math-utilities.md -->
### FUN_0040b5a0 — VTable Switch Constructor with Virtual Call

C++ constructor body for class with virtual base. Sets vtable pointer to PTR_LAB_0059e6ac, calls virtual function at vtable[0] on sub-object at this+0xC (offset 0x0C), then resets vtable to PTR_LAB_0059e634. Vtable switch pattern indicates virtual inheritance with adjusting vtable pointer during construction.

**Calls:** Virtual call via vtable[0] on sub-object at this+0x0C

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
### FUN_0044ca40 — Collision Region Init 12 (Block 0x007cca7c)

Static initializer for collision region descriptor at 0x007cca7c. Sets type=12 (0x0C), Z=0, W=-1.0 (0xbf800000). Called during collision system startup via init function table.

**Key logic:**
- Sets DAT_007cca7c = 12 (region type ID)
- Sets DAT_007cca80 = 0 (Z field)
- Sets DAT_007cca84 = 0xbf800000 (W = -1.0f)
- Sets DAT_007cca88 = 0

**Globals:**
- `DAT_007cca7c` — collision region type field (referenced by FUN_00452b10, FUN_00452810, FUN_0044ff50)

**Moddability:** `hardcoded`

### FUN_0044cfe0 — Collision Material Init 40 (Block 0x007cc9ec)

Static initializer for collision material descriptor at 0x007cc9ec. Sets type=40 (0x28), Z=0, W=0, last=1.0f. Called during collision system startup.

**Key logic:**
- Sets DAT_007cc9ec = 40 (material type ID)
- Sets DAT_007cc9f0 = 0
- Sets DAT_007cc9f4 = 0
- Sets DAT_007cc9f8 = 0x3f800000 (1.0f)

**Globals:**
- `DAT_007cc9ec` — collision material type (referenced by FUN_0044ff50, FUN_00452810)

**Moddability:** `hardcoded`

### FUN_0044d580 — Collision Region Init 18 (Block 0x007ccd08)

Static initializer for collision region descriptor at 0x007ccd08. Sets type=18 (0x12), all other fields zero. Called during collision system startup.

**Globals:**
- `DAT_007ccd08` — region type ID (referenced by FUN_00452b10)

**Moddability:** `hardcoded`

### FUN_0044db20 — Collision Broadphase Reset 46 (Block 0x007ccf00)

Static initializer for collision region descriptor at 0x007ccf00. Sets type=46 (0x2E), all other fields zero. Called during collision system startup.

**Globals:**
- `DAT_007ccf00` — region type ID (referenced by FUN_00452b10)

**Moddability:** `hardcoded`

### FUN_0044e0c0 — Collision Region Init 69 (Block 0x007ccd98)

Static initializer for collision region descriptor at 0x007ccd98. Sets type=69 (0x45), all other fields zero. Called during collision system startup.

**Globals:**
- `DAT_007ccd98` — region type ID (referenced by FUN_00452b10)

**Moddability:** `hardcoded`

### FUN_0044e660 — Collision Region Init 84 (Block 0x007cd04c)

Static initializer for collision region descriptor at 0x007cd04c. Sets type=84 (0x54), zeros, and sets DAT_007cd060=18000 (10-minute timer or distance threshold). Called during collision system startup.

**Globals:**
- `DAT_007cd04c` — region type ID (referenced by FUN_00452b10)
- `DAT_007cd060` — threshold value 18000

**Moddability:** `hardcoded`

### FUN_0044ec00 — Collision Region Init 99 (Block 0x007ca3f8)

Static initializer for collision region descriptor at 0x007ca3f8. Sets type=99, zeros, and sets DAT_007ca40c=9000. Called during collision system startup.

**Globals:**
- `DAT_007ca3f8` — region type ID (referenced by FUN_00452b10)
- `DAT_007ca40c` — threshold value 9000

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
### FUN_0046c710 — Global Array Scan for Negative

Scans collision-related global arrays (DAT_007cd470 or DAT_007cd2b8) looking for negative values. Branches on byte at param_1+0x174 to select which array to scan. Returns count of entries before first negative value found.

**Key logic:**
- If param_1+0x174 == 0: scan DAT_007cd470 (0x007cd470 to 0x007cd610, 0xA0/4=40 entries)
- If param_1+0x174 != 0: scan DAT_007cd2b8 (0x007cd2b8 to 0x007cd458, ~0x1A0/4=104 entries)
- Returns index of first negative entry, or total count if none found

**Globals:**
- `DAT_007cd470` — first collision data array (40 entries)
- `DAT_007cd2b8` — second collision data array (104 entries)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x174 | ArraySelector | byte, 0=first array, non-zero=second array |

**Moddability:** `hardcoded`

### FUN_00486300 — UI String Accessor

Returns a string pointer from a UI struct. Takes `this` pointer (param_1, __fastcall), checks field at offset +200 (0xC8). If null, returns null. Otherwise dereferences +200 as pointer and returns string at +0x50 within that sub-struct. Falls back to DAT_005ea438 (directory path) if sub-string is null.

**Key logic:**
- if *(param_1+200) == 0: return null
- else: return *(*(param_1+200)+0x50) or DAT_005ea438 as fallback

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xC8 | SubObjectPtr | pointer to sub-object containing string |
| +0x50 (sub) | DisplayString | string pointer |

**Globals:**
- `DAT_005ea438` — directory path default fallback string

**Moddability:** `hardcoded`

<!-- target: docs/20-math-utilities.md -->
### FUN_0049a110 — Linked List Node Counter

Walks a linked list starting from list head at param_1+8. Skips `param_2` nodes using +0x24 as `next` pointer, then counts remaining nodes using +0x28 as `next` pointer. Two different `next` offsets suggest intrusive list with multiple linkage options.

**Key logic:**
- Head pointer at param_1+8
- Skip `param_2` nodes via +0x24 link
- Count remaining nodes via +0x28 link
- Returns count

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | ListHead | pointer to first node |
| +0x24 (node) | SkipLink | next pointer for skipping |
| +0x28 (node) | CountLink | next pointer for counting |

**Moddability:** `hardcoded`

### FUN_00500161 — Parameter Reorder Wrapper

Tiny function that reorders parameters from (a,b,c,d) to (d,b) and calls func_0x004ff717. Likely a thunk for convention adaptation or partial application.

**Calls:** func_0x004ff717 (at address 0x004ff717)

**Moddability:** `hardcoded`

### thunk_FUN_0050d0af (0x0050d0bc) — Global Function Pointer Thunk

Indirect call through global pointer _DAT_005d7810. Loads function address from global and jumps to it. Used for dynamic dispatch where the target is stored in a global variable at runtime.

**Key logic:**
- Calls (*_DAT_005d7810)()

**Globals:**
- `DAT_005d7810` — function pointer (callable target)

**Moddability:** `hookable` — replace DAT_005d7810 to intercept

### FUN_0050e84b — 2x2 Matrix Multiply (Strided 6-Element Layout)

Performs 2x2 matrix multiply with 6-element strided row layout (3 elements per row). Computes:
- param_1[0] = param_2[0]*param_3[0] + param_2[1]*param_3[4]
- param_1[1] = param_2[0]*param_3[1] + param_2[1]*param_3[5]

Accesses indices 0,1,4,5 out of 6-element arrays — likely 2x3 or 3x2 matrices stored in row-major order.

**Moddability:** `hardcoded`

<!-- target: docs/21-audio-network-internals.md -->
### FUN_0051bd61 — Audio Ring Buffer Manager

Manages a ring buffer for audio data streaming. When buffer is empty, allocates new buffer via virtual function call. Copies audio data through virtual dispatch, handles buffer overflow by incrementing a counter and resetting the write position.

**Key logic:**
- Checks ring buffer at param_1+0x188 for empty state (puVar1 = iVar2+0x18)
- If empty: allocates via virtual call (vtable[0x1c/4] = vtable[7])
- Writes data via virtual call (vtable[4] on object at param_1+0x19c)
- On overflow: copies overflow data via virtual call (vtable[4] on object at param_1+0x1a4)
- Increments counter at iVar2+0x14, resets buffer position

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x188 | AudioBufferObj | audio buffer state object |
| +0x19c | WriteInterface | audio data writer vtable |
| +0x1a4 | OverflowInterface | overflow handler vtable |

**Buffer state (at param_1+0x188):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | BufferSize | total buffer capacity |
| +0x0c | WritePointer | current write position |
| +0x10 | Threshold | overflow threshold |
| +0x14 | OverflowCount | accumulated overflow count |
| +0x18 | Position | current fill level |

**Moddability:** `hardcoded`

<!-- target: docs/19-renderer.md -->
### FUN_0053aeb0 — Vertex Batch Transform (Dual Matrix)

Transforms a batch of vertices through two 4x4 matrices. Reads vertex positions from param_2+0x0C, transforms through matrix param_3, stores result at param_1+0x10 (first pass) and writes to param_2+0x20 (output). Then transforms through matrix param_4 using data at param_2+0x0C+12 (offset by 12 bytes per vertex), stores at param_1+0x30.

**Key logic:**
- Reads vertex count from param_2+8
- Row-major 4x3 matrix multiplication (4 rows, 3 columns output)
- First transform: source at param_2+0x0C, matrix param_3, output to param_2+0x20
- Second transform: source at param_2+0x0C+12, matrix param_4, output to param_1+0x30
- Interleaved vertex format (12 bytes per vertex = 3 floats)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x10 | TransformOutput1 | first transform output buffer |
| +0x30 | TransformOutput2 | second transform output buffer (matrix cache) |

**Moddability:** `hardcoded`

### FUN_005604c0 — Pixel Buffer Blit with Short-to-16bpp Conversion

Blits pixel data between two buffers with format conversion. Reads 16-bit values (short) from source buffer, converts to 16bpp (two short values packed per 32-bit write). Uses LOCK/UNLOCK for thread safety. Row-major blit with configurable strides.

**Key logic:**
- Source: short* at (param_3 + param_6*param_5 + param_4*2)
- Dest: undefined4* at (param_7 + param_10*param_9 + param_8*2)
- Inner loop: param_11 iterations, converts short→short pairs
- Outer loop: param_12 rows, strides of param_6 (source) and param_10*2 (dest)
- Conditional: skips pixel if value == param_13 (transparent color key)

**Moddability:** `hardcoded`

<!-- target: docs/06-session-race-logic.md -->
### FUN_0057aa50 — State Reset Function

Zeroes 4 consecutive 32-bit globals at 0x008d3bfc–0x008d3c08. Simple state init/reset function.

**Globals:**
- `DAT_008d3bfc` through `DAT_008d3c08` — 4 state variables

**Moddability:** `hardcoded`

<!-- target: docs/20-math-utilities.md -->
### __amsg_exit (0x0058a2a6) — CRT Error Exit

MSVC runtime library function. Displays runtime error message and exits process. Calls FUN_005932ba (if DAT_008d3ebc == 1, likely CRT debug flag), then FUN_005932f3(param_1), then _exit(0xFF).

**Globals:**
- `DAT_008d3ebc` — CRT debug flag (1 = debug mode active)

**Calls:** FUN_005932ba, FUN_005932f3, _exit

**Moddability:** `hardcoded`

### __fload (0x0059086e) — CRT Float Load

MSVC runtime library function. Loads an 80-bit extended precision float from memory. Handles NaN/infinity special cases (0x7FF0 exponent check).

**Key logic:**
- If exponent == 0x7FF0: return NaN/infinity with full mantissa
- Else: convert 64-bit double to 80-bit extended precision

**Moddability:** `hardcoded`

<!-- target: docs/21-audio-network-internals.md -->
### gethostbyname (0x00598660) — Import Thunk

Import thunk to ws2_32.dll gethostbyname function. Jumps through the IAT entry to the Windows Sockets 2 library for DNS hostname resolution.

**Calls:** gethostbyname (ws2_32.dll import)

**Moddability:** `hardcoded`

### Catch_00599689 — Catch Block Buffer Allocator

MSVC C++ exception handling catch frame. Allocates buffer for caught exception object. Reads exception object size from unaff_EBP+8, adds 2 bytes of overhead, and calls operator_new.

**Key logic:**
- Reads exception object pointer from saved EBP+8
- Adds 2 bytes to size (for internal bookkeeping)
- Caps at 0 if overflow
- Calls operator_new(size)
- Stores new buffer pointer back at EBP+8
- Returns exception handler continuation address (DAT_005996a8)

**Calls:** operator_new

**Moddability:** `hardcoded`

### Unwind_0059c86a — SEH Unwind Handler

MSVC C++ exception handling unwind frame. Thunks to common unwind helper FUN_00581750. Called by exception dispatcher during stack unwinding.

**Calls:** FUN_00581750 (common SEH unwind helper)

### Unwind_0059cf94 — SEH Unwind Handler

MSVC C++ exception handling unwind frame. Thunks to common unwind helper FUN_00581750. Called by exception dispatcher during stack unwinding.

**Calls:** FUN_00581750 (common SEH unwind helper)

<!-- target: docs/01-engine-architecture.md -->
### Unwind_0059d56c — SEH Unwind: Destroy Exception Object

MSVC C++ exception handling cleanup frame. Destroys the caught exception object by calling exception::~exception() on the exception pointer at saved EBP-0x10.

**Key logic:**
- Calls exception::~exception(*(exception**)(unaff_EBP - 0x10))

**Calls:** exception::~exception (MSVC exception class destructor)
