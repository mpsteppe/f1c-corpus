## System Overview
## FUN_00406a90 — Short Computation (Dual Field Getter)

Source: unknown | Confidence: high
Returns two fields from param_1 to output pointers param_2 and param_3.

**Key logic:**
- If param_2 != null: `*param_2 = *(param_1 + 0x18)`
- If param_3 != null: `*param_3 = *(param_1 + 0x1c)`

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x18 | undefined4 | first value |
| +0x1c | undefined4 | second value |

**Used by system:** docs/20-math-utilities.md — struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004080f0 — Memory Allocation with Buffer Read

Source: unknown | Confidence: medium
Reads data count from a file/stream, allocates buffer, reads records into it.

**Key logic:**
- If `param_1+0xc != 0` AND `param_1+0x18 == 0` (valid handle, buffer not yet allocated):
  - Calls `FUN_00587f64(handle, 0, 0)` — file seek to position 0 (docs/20)
  - Calls `FUN_0058803f(&count, 4, 1, handle)` — read uint count (docs/09, 19)
  - Allocates `count * 4` bytes via operator_new to `param_1+0x18`
  - Zero-initializes buffer
  - Reads `count` dword values from file into buffer via FUN_0058803f
  - On read failure: calls FUN_0041a160(handle), frees buffer, sets buffer = 0
  - Returns 0 on success, 1 on error

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0c | int | file/stream handle |
| +0x14 | uint* | count field |
| +0x18 | int* | allocated buffer |

**Calls:**
- FUN_00587f64 — file seek (docs/20)
- FUN_0058803f — file read (docs/09, 19)
- operator_new — heap allocation
- FUN_0041a160 — file/stream close (unknown)
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — file-based array loading utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00409970 — Conditional Camera Pipeline Setup

Source: unknown | Confidence: high
Conditionally calls 5 renderer camera/viewport setup functions if a pointer field is non-null.

**Key logic:**
- If `*(int *)(param_1 + 8) != 0`:
  - `FUN_00542050(DAT_007cf6a4 * DAT_0059e65c, DAT_007cf6c8 * DAT_0059e65c, 1)` — camera projection scale
  - `FUN_00541ca0(DAT_007cf680)` — camera center/target set
  - `FUN_00542540(&LAB_004099e0, 0)` — pointer store pair
  - `FUN_00542680(0x3f000000)` = 0.5f — viewport scale set
  - `FUN_00542650(DAT_007cf6ec)` — camera zoom/distance set

**Globals:**
- `DAT_007cf6a4`, `DAT_007cf6c8` — renderer camera scale factors
- `DAT_0059e65c` — camera shake multiplier / conversion factor (docs/09, 19)
- `DAT_007cf680` — camera center/target position
- `DAT_007cf6ec` — camera zoom/distance
- `DAT_007cf6a4`, `DAT_007cf6c8` — renderer camera scale factors

**Calls:** FUN_00542050 (camera projection, docs/19), FUN_00541ca0 (camera target, docs/19), FUN_00542540 (pointer store, docs/06), FUN_00542680 (viewport scale, docs/09), FUN_00542650 (camera distance, docs/19)

**Moddability:** hookable (condition check at +0x8)

<!-- target: docs/19-renderer.md -->

## FUN_0040dbc0 — Mode Validation Check

Source: unknown | Confidence: high
Returns 1 if param_1's first value is 3 or 4, 0 otherwise.

**Key logic:**
- Reads `*param_1`
- Returns 1 if value is 3 or 4, else 0
- Used to validate a mode/state value

**Used by system:** docs/20-math-utilities.md — mode/state validation utility

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00587f59 — Single Function Call Wrapper (atoi)

Source: unknown | Confidence: high
Trivial wrapper that delegates to FUN_00587ece (atoi/string-to-int parser).

**Key logic:**
- Calls FUN_00587ece(param_1) — ASCII string to int conversion (docs/08)
- Forwards the return value

**Calls:**
- FUN_00587ece — atoi / string-to-int (docs/08)

**Used by system:** docs/08-file-formats.md — config file field parsing; docs/19-renderer.md; docs/21-audio-network-internals.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00589d62 — ExitProcess Stub

Source: unknown | Confidence: high
Win32 ExitProcess wrapper. Does not return.

**Key logic:**
- Calls `ExitProcess(uExitCode)` — terminates process with exit code
- Ghidra warning: "Subroutine does not return"
- Direct passthrough to kernel32!ExitProcess

**Calls:**
- ExitProcess — Win32 API (kernel32)

**Used by system:** docs/20-math-utilities.md — CRT runtime process termination

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00564530 — String Comparison with Constant, Dispatch

Source: unknown | Confidence: high
Compares param_2 against a 5-character constant string at DAT_005c61ec. On match, calls FUN_00564480. On mismatch, calls FUN_005644f0; if result is non-null, reads field at +4 and calls FUN_00587f59 on it.

**Key logic:**
- Compares param_2 against 5-char constant at DAT_005c61ec (exact string unknown — 5 bytes)
- If match: calls FUN_00564480() — host port read (docs/09); returns its result
- If no match: calls FUN_005644f0() (mode/state query, unknown)
  - If result is 0: returns param_3 (passthrough default)
  - If non-zero: reads int from (result + 4), calls FUN_00587f59 on it — atoi/parse int (docs/08, docs/21)

**Calls:**
- FUN_00564480 — host port read (docs/09)
- FUN_005644f0 — mode/state query (unknown)
- FUN_00587f59 — int parser / atoi (docs/08, docs/19, docs/21)

**Used by system:** docs/20-math-utilities.md — session/network configuration string parsing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00565d50 — Enhanced List Cleanup with Sub-Object Delete

Source: unknown | Confidence: high
Walks a linked list, conditionally frees sub-objects within each node, then frees the node itself. Resets list head and 3 counter fields.

**Key logic:**
- Reads list head from `*param_1`
- Iterates via node at `+0x04` (next pointer)
- For each node: checks `(char)node[2] != 0` (flag byte)
  - If set: reads `*node` (pointer to sub-object), checks if `subobj + 0x144 != 0`, if so frees it via FUN_00587bcf
  - Frees the sub-object itself via FUN_00587bcf
  - Then frees the node itself via FUN_00587bcf
- After loop: zeroes param_1[0], param_1[1], param_1[2], param_1[3] — head + 3 counters

**Struct offsets (node):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | pointer to sub-object |
| +0x04 | int* | next node pointer |
| +0x08 | char | flag byte (tested != 0) |

**Struct offsets (sub-object):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x144 | int* | sub-sub-object freed if non-null |

**Calls:**
- FUN_00587bcf — free/delete operator (docs/01, 17, 18, 19, 08, etc.)

**Used by system:** docs/20-math-utilities.md — generic list container cleanup with managed sub-object lifetime

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00567980 — Linked List Count

Source: unknown | Confidence: high
Iterates a singly-linked list and returns the count of nodes.

**Key logic:**
- Reads list head from `param_1 + 8`
- Traverses via next pointer at `+0x04` until null
- Counts nodes, returns total count
- List at param_1+8, stride to next at node+0x04

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | int* | linked list head |

**Struct offsets (node):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | int* | next node pointer |

**Used by system:** docs/20-math-utilities.md — generic linked list size/length utility

**Algorithm family:** linked list traversal, counting

**Moddability:** hardcoded

**Used by system:** docs/01-engine-architecture.md — engine object initialization; likely part of a widget/entity creation pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057ae00 — Callback Registration (Thunk)

Source: unknown | Confidence: high
Registers callback LAB_0057ae10 via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_0057ae10) — register static data (docs/17, 18, 06)

**Calls:**
- FUN_00587b3e — callback/atexit registration (docs/06, 17, 18)

**Used by system:** docs/20-math-utilities.md — static data registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585020 — Arithmetic/Comparison (returns param_1 + 100)

Source: unknown | Confidence: high
Returns param_1 + 100.

**Key logic:**
- Returns param_1 + 100 (offset/bias value)

**Used by system:** docs/20-math-utilities.md — simple arithmetic

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587210 — Short Computation (Struct Field Getter at +0x18)

Source: unknown | Confidence: high
Returns byte at param_1 + 0x18.

**Key logic:**
- Returns *(param_1 + 0x18)

**Used by system:** docs/20-math-utilities.md — struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058803f — Thread-Safe Read Wrapper

Source: unknown | Confidence: high
Thread-safe file/stream read with mutex lock.

**Key logic:**
- Calls FUN_0058c1b1(param_4) — lock mutex (docs/20)
- Calls FUN_0058806e(param_1, param_2, param_3, param_4) — actual read
- Calls FUN_0058c203(param_4) — unlock mutex
- Returns read result

**Calls:**
- FUN_0058c1b1 — mutex lock (docs/20)
- FUN_0058806e — raw read function
- FUN_0058c203 — mutex unlock (docs/20)

**Used by system:** docs/20-math-utilities.md — thread-safe I/O read (docs/09, 19)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a88f — Arithmetic/Comparison (NaN Check)

Source: unknown | Confidence: high
Checks if a float/double value is not NaN by testing exponent bits.

**Key logic:**
- Tests `(param_2 high word & 0x7ff0) != 0x7ff0`
- Returns true if NOT NaN/Inf (exponent != 0x7ff)
- False if NaN or Infinity

**Used by system:** docs/20-math-utilities.md — IEEE 754 float NaN validation

**Algorithm family:** float classification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058dd28 — Float Exponent Extract with NaN Guard

Source: unknown | Confidence: high
Extracts the exponent bits from a double, preserving NaN values.

**Key logic:**
- If exponent (bits 20-31) != 0x7ff: returns only exponent bits (masked)
- If NaN/Inf (exponent == 0x7ff): returns full value (preserves NaN payload)

**Algorithm family:** IEEE 754 float bitfield extraction

**Used by system:** docs/20-math-utilities.md — MSVCRT math helper for exponent classification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059525d — Bit Array — Clear Bit and Zero-Fill Subsequent Words

Source: unknown | Confidence: high
Clears a specific bit in a 3-word (96-bit) bit array and zeroes subsequent words.

**Key logic:**
- Computes word index from bit position: param_1 + (param_2/32) * 4
- Checks bit: if set AND FUN_005951be(bit+1) == 0: gets prior bit via FUN_00595207(bit-1)
- Clears bit: `*word &= ~(1 << (31 - (bit % 32)))`
- If word_index < 3: zeroes remaining (3 - word_index) words
- Returns previous bit value (0 or 1)

**Calls:**
- FUN_005951be — test next bit
- FUN_00595207 — get prior bit

**Used by system:** docs/20-math-utilities.md — fixed-size bitmap allocation/free

**Algorithm family:** bit array operations

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005986bf — Delegation with Static Arg

Source: unknown | Confidence: high
Registers callback LAB_005986cb via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_005986cb)

**Calls:**
- FUN_00587b3e — callback registration (docs/06, 17, 18)

**Used by system:** docs/20-math-utilities.md — static callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059985c — Delegation with Static Arg

Source: unknown | Confidence: high
Registers callback LAB_00599868 via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_00599868)

**Calls:**
- FUN_00587b3e — callback registration (docs/06, 17, 18)

**Used by system:** docs/20-math-utilities.md — static callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059b758 — Struct Field Getter at +0x10

Source: unknown | Confidence: high
Returns int at param_1 + 0x10.

**Key logic:**
- Returns *(param_1 + 0x10)

**Used by system:** docs/20-math-utilities.md — struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c7fc — C++ Unwind Helper (Thunk)

Source: unknown | Confidence: high
C++ SEH unwind helper — thunk to FUN_005822b0.

**Key logic:**
- Calls FUN_005822b0() — cleanup/destructor (unknown)

**Calls:**
- FUN_005822b0 — cleanup

**Used by system:** docs/20-math-utilities.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cef5 — C++ Unwind Helper (Thunk)

Source: unknown | Confidence: high
C++ SEH unwind helper — thunk to FUN_00586170.

**Key logic:**
- Calls FUN_00586170() — cleanup/destructor (unknown)

**Calls:**
- FUN_00586170 — cleanup

**Used by system:** docs/20-math-utilities.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d738 — Double Subtraction via unaff_ESI

Source: unknown | Confidence: low
Subtracts a double value at param_2+100 from ESI+0x28, then calls FUN_00449eb7.

**Key logic:**
- If param_2 != 0: `*(unaff_ESI + 0x28) -= *(param_2 + 100)` — double subtraction
- Calls FUN_00449eb7() — collision/geometry cleanup? (docs/17)

**Calls:**
- FUN_00449eb7 — cleanup/finalize (likely docs/17)

**Used by system:** docs/20-math-utilities.md — physics/energy subtraction with cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054b4a0 — Arithmetic/Comparison (Triple Field Getter)

Source: unknown | Confidence: high
Returns three fields from param_1 to output pointers.

**Key logic:**
- If param_2 != 0: *param_2 = param_1+0x2c
- If param_3 != 0: *param_3 = param_1+0x30
- If param_4 != 0: *param_4 = param_1+0x34

**Used by system:** docs/20-math-utilities.md — struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054eaf0 — Short Computation (Struct Zero-Init)

Source: unknown | Confidence: high
Zero-initializes a struct with 10+16 dwords.

**Key logic:**
- Zeroes param_1[0..3], param_1[7..9]
- Loop: zeroes param_1[0xd..0x1c] (16 dwords)

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005507A0 � 8-Dword Struct Initializer

Source: unknown | Confidence: high
Calls sub-init then zeroes 8 dwords (indices 0-7).

**Key logic:**
- FUN_0053b490() � sub-init
- Zeroes param_1[0..7] � 8 dwords (32 bytes total)
- Returns param_1

**Calls:** FUN_0053b490 (sub-init)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00557280 — Cleanup Function (Free + Destructor)

Source: unknown | Confidence: high
Frees sub-object at +0x20c, zeros pointer, calls destructor.

**Key logic:**
- If param_1+0x20c != 0: frees via FUN_00587bcf
- Zeros +0x20c
- Calls FUN_004b0170() — destructor (docs/19, 18)

**Calls:**
- FUN_00587bcf — free
- FUN_004b0170 — destructor (docs/19, 18)

**Used by system:** docs/20-math-utilities.md — sub-object cleanup with destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c440 — Empty Stub

Source: unknown | Confidence: high
Returns 0 immediately. Placeholder or stripped virtual method.

**Key logic:**
- Returns 0
- No operations

**Used by system:** docs/20-math-utilities.md — stub / placeholder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00563eb0 — Single Delegation Call

Source: unknown | Confidence: high
Wrapper calling FUN_00563e70.

**Key logic:**
- Calls FUN_00563e70() — unknown

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00566f40 — 3×3 Rotation Matrix from Quaternion

Source: unknown | Confidence: high
Converts a quaternion (4 floats) to a 3×3 rotation matrix (9 floats).

**Key logic:**
- Standard quaternion-to-matrix formula:
  - m[0][0] = 1 - 2*(y² + z²)
  - m[0][1] = 2*(x*y - z*w)
  - m[0][2] = 2*(x*z + y*w)
  - m[1][0] = 2*(x*y + z*w)
  - m[1][1] = 1 - 2*(x² + z²)
  - m[1][2] = 2*(y*z - x*w)
  - m[2][0] = 2*(x*z - y*w)
  - m[2][1] = 2*(y*z + x*w)
  - m[2][2] = 1 - 2*(x² + y²)
- Uses constant _DAT_0059e43c = 1.0 (unrolled 3.0 - 2.0 pattern)
- param_1 = quaternion (w, x, y, z), param_2 = output 3×3 matrix

**Globals:**
- DAT_0059e43c — constant 1.0f (docs/12)

**Used by system:** docs/20-math-utilities.md — rotation/orientation math for physics or rendering

**Algorithm family:** quaternion → rotation matrix, 3D math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0056ec70 — Matrix Identity Initialization (8-byte Doubles)

Source: unknown | Confidence: medium
Initializes a matrix/array of 8-byte doubles to identity or zero.

**Key logic:**
- If param_1+0x30 != 0: calls virtual method via param_1+0x30 (dynamic dispatch)
- Else:
  - First loop: zeroes all entries at column param_2 across rows
  - Second loop: zeroes all entries at row param_2 across columns
  - Sets diagonal element (param_2, param_2) = 1.0 (0x3ff00000 = 1.0 in double)
  - Zeroes one additional element at param_1+0x2c[param_2*2]

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x20 | int | row/column count |
| +0x28 | int* | matrix data pointer |
| +0x2c | int* | secondary array |
| +0x30 | int* | override vtable/pointer |

**Used by system:** docs/20-math-utilities.md — matrix identity initialization for physics dynamics

**Algorithm family:** matrix init, identity matrix

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c190 — Arithmetic/Comparison (Loop Call x42)

Source: unknown | Confidence: medium
Calls FUN_00556220 42 (0x2a) times.

**Key logic:**
- Loop 0x2a times: calls FUN_00556220()

**Calls:**
- FUN_00556220 — unknown

**Used by system:** docs/20-math-utilities.md — batch init loop

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053cb20 — Memory Allocation (Audio Emitter Create)

Source: unknown | Confidence: medium
Creates an audio emitter/stream object.

**Key logic:**
- Allocates 0x3c bytes via operator_new
- Calls FUN_005426a0() — audio emitter create (docs/19)
- Stores result in *param_1
- Calls FUN_005429b0(param_2,0,0,param_3,param_4) — output device/format setup (docs/19)
- On failure: calls FUN_00557470() and frees via FUN_00587bcf; returns -1
- Returns 0 on success

**Calls:**
- operator_new — heap alloc
- FUN_005426a0 — audio emitter create (docs/19)
- FUN_005429b0 — output device setup (docs/19)
- FUN_00557470 — audio emitter stop/release (docs/19)
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — audio emitter/stream initialization

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00541cd0 — Utility Function (Dual Dispatch)

Source: unknown | Confidence: medium
Dispatches 6 parameters to two chained functions.

**Key logic:**
- Calls FUN_00541db0(param_4, param_5, param_6)
- Calls FUN_00541d10(param_1, param_2, param_3)
- Splits 6 args into two groups of 3

**Calls:**
- FUN_00541db0 — handler (last 3 args)
- FUN_00541d10 — handler (first 3 args)

**Used by system:** docs/20-math-utilities.md — parameter routing/dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00543540 — Unidentified Logic (Rect/Viewport Clamp)

Source: unknown | Confidence: high
Clamps a rectangle within bounds using param_1+0x1c (width) and +0x20 (height) as limits.

**Key logic:**
- If *param_2 < 0: adjusts param_4, zeroes param_2 (negative x offset clamp)
- If width < param_4 + param_2: clamps param_4
- Clamps param_4 to [0, width]
- Same logic for y: param_3, param_5, height
- Classic viewport/rectangle clipping

**Used by system:** docs/20-math-utilities.md — viewport/rectangle boundary clamping

**Algorithm family:** rectangle clipping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00546f70 — Unidentified Logic (Conditional Render State Set)

Source: unknown | Confidence: low
Sets renderer state conditionally when an index is valid.

**Key logic:**
- If param_2 < param_1+0xa4 AND param_1+0xa4 < 8:
  - Calls FUN_0054fc40(0x800000) — render state write mask
  - FUN_0054fc80(0,0) — render state clear
  - FUN_0054fd30(1.0f, 1.0f) — scale set
  - FUN_0054fca0(2) — blend mode set
  - Sets flag bit 0x80 at param_1+0x9c

**Calls:**
- FUN_0054fc40 — render state mask (docs/19)
- FUN_0054fc80 — render state clear (docs/19)
- FUN_0054fd30 — scale set (docs/19)
- FUN_0054fca0 — blend mode set (docs/19)

**Used by system:** docs/19-renderer.md — conditional render state configuration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005477f0 — Arithmetic/Comparison (Binary Search / Trie Lookup)

Source: unknown | Confidence: high
Searches a binary tree/trie for a matching byte string using two-byte comparison.

**Key logic:**
- Walks a tree starting at param_1+0x24
- Compares byte pairs from param_2 against tree nodes
- Returns matching node or null
- On mismatch: branches via next at +0xc0
- Returns node pointer when match found

**Used by system:** docs/20-math-utilities.md — string/token lookup in binary search tree

**Algorithm family:** binary tree / trie search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00549170 — Arithmetic/Comparison (List Walk and Process)

Source: unknown | Confidence: low
Walks a linked list, calls processing on matching elements.

**Key logic:**
- Walks list from param_1+0xe8 via next at +0x14
- For each node: calls FUN_0054bc60(node, &id) — ID query
- If id != 0: calls FUN_005452b0(id) and FUN_005490b0(id) — process

**Calls:**
- FUN_0054bc60 — ID query
- FUN_005452b0 — process element
- FUN_005490b0 — process element

**Used by system:** docs/20-math-utilities.md — list iteration with conditional processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005179e0 — Unidentified Logic (Buffer Allocation with Validation)

Source: unknown | Confidence: low
Validates parameters then allocates and initializes a buffer via function pointers.

**Key logic:**
- If param_3 null or not '1' or size != 0x38: returns 0xfffffffa
- Calls alloc function at param_1+0x20(0x28, 1, 0x18) — allocates context buffer
- Sets fields at +0x1c, +0x14, +0xc
- If param_2 < 0: negates, sets sign flag
- Validates param_2 in [8, 15] range
- Calls FUN_005276c5 for sub-allocation
- Calls FUN_00517963() on success
- Returns various error codes on failure

**Calls:**
- Virtual methods (slots at +0x20, +0x24) — alloc/free
- FUN_005276c5 — sub-block allocator
- FUN_00517963 — success handler
- FUN_005179a2 — cleanup handler

**Used by system:** docs/20-math-utilities.md — custom heap/context allocator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051a794 — Unidentified Logic (Bit Stream Reader)

Source: unknown | Confidence: medium
Bit stream reader with run-length decode (0xFF escape). Reads bits from a buffer with refill callback.

**Key logic:**
- Reads bits from byte buffer at *param_1 with remaining count in param_1[1]
- 0xFF byte triggers run-length handling: consumes additional bytes until non-0xFF
- Result byte is 0xFF if more 0xFFs found, else reads count into param_1[2]
- If param_1[2] set: fills with 0 or reads more data
- Accumulates into param_2 via shift and OR (bitstream assembly)
- Returns 0 on buffer underflow, 1 on success

**Calls:**
- Virtual method (slot 0xc on param_1[7]+0x14) — buffer refill callback

**Used by system:** docs/20-math-utilities.md — compressed/deflate-style bit stream reader

**Algorithm family:** bit stream decompression

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051ec40 — Unidentified Logic (2D Transform with Perspective)

Source: unknown | Confidence: medium
Applies a 2D transformation with perspective divide using SSE rcpps.

**Key logic:**
- Transforms (x, y) through a 4×3 matrix:
  - x' = x*A + y*E + I
  - y' = x*B + y*F + J
  - w' = x*C + y*G + K
  - z' = x*D + y*H + L  (perspective depth)
- Computes reciprocal via rcpps (SSE approximate reciprocal)
- Applies perspective divide: result *= w'
- Returns transformed coordinates

**Algorithm family:** 2D transform, perspective projection, SSE

**Used by system:** docs/20-math-utilities.md — sprite/texture coordinate transformation with perspective

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005276C5 � Multi-Block Memory Allocator

Source: unknown | Confidence: high
Allocates three memory blocks via virtual allocator: header (0x40), data buffer (0x5a0), and variable-size work buffer. Returns pointer to allocation descriptor.

**Key logic:**
- Virtual alloc at param_1+0x20(size=0x40, type=1) ? header block
- If header valid:
  - Virtual alloc at param_1+0x20(size=0x5a0, type=8) ? data buffer
  - Store at header[9] = data buffer address
  - If data valid:
    - Virtual alloc at param_1+0x20(size=param_3, type=1) ? work buffer
    - Store at header[10] = work buffer address
    - If work buffer valid:
      - header[0] = 0 � clear flags
      - header[0xb] = dataBuffer + param_3 � end address
      - header[0xe] = param_2 � store user param
      - FUN_0052765a(header, param_1, 0) � async I/O/state reset handler (docs/01, 20)
      - Return header
    - If work buffer fails: free data and header, return NULL
  - If data fails: free header, return NULL
- Return NULL on any failure

**Struct offsets (returned descriptor):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Flags | int, cleared to 0 |
| +0x24 (idx 9) | DataBuffer | void*, 0x5a0 bytes |
| +0x28 (idx 10) | WorkBuffer | void*, param_3 bytes |
| +0x2c (idx 0xb) | EndAddress | void*, DataBuffer + param_3 |
| +0x38 (idx 0xe) | UserParam | undefined4, stored param_2 |

**Calls:** FUN_0052765a (async I/O/state reset, docs/01/20)

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0052de40 — Arithmetic/Comparison (Validation)

Source: unknown | Confidence: high
Returns true if FUN_0052da30 returns -1.

**Key logic:**
- Calls FUN_0052da30(param_1)
- Returns (result == -1)

**Calls:**
- FUN_0052da30 — lookup/check (unknown)

**Used by system:** docs/20-math-utilities.md — existence/availability check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00534d50 — Unidentified Logic (Stream/Format Parser)

Source: unknown | Confidence: low
Parses a data stream with magic number comparison and conditional block skipping.

**Key logic:**
- Compares values from FUN_00534e70() against DAT_005da780 array (2 entries)
- On mismatch: adjusts counters, returns
- On match: reads more data, checks bit flags (0xe0, 4, 8, 0x10, 2)
- Skips conditional blocks based on flags
- Uses DAT_005da780 as expected magic/header values

**Calls:**
- FUN_00534e70 — stream read byte/word

**Used by system:** docs/20-math-utilities.md — data stream format parser with header validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00536260 — Unidentified Logic (Table Lookup Init)

Source: unknown | Confidence: low
Initializes struct fields with values from a lookup table indexed by param_1+0x7a.

**Key logic:**
- Computes width = param_1+0x22 * 2
- Zero-terminates and zero-fills buffer at param_1+0x3a
- Looks up 3 ushort values from DAT_005b77e8/ea/ec arrays indexed by param_1+0x7a * 0xc
- Zeroes several fields
- Sets defaults: +0x72=lookup, +0x6e=2, +0x56=2

**Calls:** none

**Used by system:** docs/20-math-utilities.md — table-driven initialization; likely audio or input device config

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b0d0 — Arithmetic/Comparison (Singleton Alloc)

Source: unknown | Confidence: medium
Allocates a 4-byte singleton object and stores its pointer in globals.

**Key logic:**
- Allocates 4 bytes via operator_new
- If success: calls FUN_0053c2a0() — parent init (docs/06, 20), sets vtable = PTR_LAB_005b8938
- Stores in DAT_008b8f18 and DAT_008b8f24 (two refs)
- On failure: zeros both globals

**Globals:**
- DAT_008b8f18, DAT_008b8f24 — singleton pointer (dual reference)

**Calls:**
- operator_new — heap alloc
- FUN_0053c2a0 — parent constructor / init (docs/06, 20)

**Used by system:** docs/20-math-utilities.md — singleton/manager object lazy initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051166b — Arithmetic/Comparison (Virtual Dispatch Chain)

Source: unknown | Confidence: low
Calls virtual method, then two utility functions, then another virtual method.

**Key logic:**
- Calls virtual method (slot 8) on param_1
- Calls FUN_00516959() — unknown
- Calls FUN_00589ca4() — unknown
- Calls virtual method (slot 0xc) on unaff_retaddr with stack buffer

**Calls:**
- Virtual methods (slots 8, 0xc)
- FUN_00516959 — unknown
- FUN_00589ca4 — unknown

**Used by system:** docs/20-math-utilities.md — object method dispatch chain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005123e0 — Unidentified Logic (Pixel/Channel Swizzle)

Source: unknown | Confidence: low
Performs byte swapping/swizzling on image data based on format flags (bit 2 of header byte, stride indicator byte).

**Key logic:**
- Reads flags byte at param_1+2 (bit 2 tested)
- Reads stride specifier at param_1+9 (8 or 16)
- Uses format byte (2 or 6) to determine element stride (3 or 4)
- Swaps byte[0] with byte[2] for each element
- For stride 16: swaps 2 pairs per element (stride 6 or 8)
- Essentially a pixel format conversion (RGB ↔ BGR)

**Used by system:** docs/20-math-utilities.md — image/color format conversion

**Algorithm family:** pixel format swizzle, byte swap

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051512c — Unidentified Logic (Nibble-to-Float Decode)

Source: unknown | Confidence: medium
Decodes packed nibbles (4-bit values) from two 32-bit words into 16 floats with scaling.

**Key logic:**
- Calls FUN_00514fee() — key/format check
- If success:
  - Extracts 8 nibbles from param_2[0], each multiplied by DAT_005ac108 (scale)
  - Stores as floats at param_1+0xc (stride 16 bytes = 4 floats each)
  - Extracts 8 nibbles from param_2[1], same transform
  - Stores at param_1+0x8c
- Returns 0 on success

**Globals:**
- DAT_005ac108 — nibble-to-float scale factor

**Calls:**
- FUN_00514fee — key/format validation

**Used by system:** docs/20-math-utilities.md — audio/compressed data decompression; nibble-packed float reconstruction

**Algorithm family:** data decompression, nibble unpack

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051641e — Unidentified Logic (DMA/Copy with Clip)

Source: unknown | Confidence: low
Block copy operation with clipping logic — copies data with stride and height constraints.

**Key logic:**
- Uses register-based unaff_ESI struct (likely DMA context)
- Reads width/height/depth from ESI fields
- Clips copy size by available space
- If param_2 == 0: calls copy function (ESI[10])
- Else: calls fill/zero function (ESI[11])
- Iterates in chunks of ESI[5] (block size)
- Pointer arithmetic on source buffer at *ESI

**Used by system:** docs/20-math-utilities.md — video/texture DMA copy with clipping

**Algorithm family:** block memory copy with clipping

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0050ab19 — Short Computation (VTable Set + Init)

Source: unknown | Confidence: medium
Calls FUN_00507496(0x10, 1), sets vtable.

**Key logic:**
- Calls FUN_00507496(param_2, 0x10, 1) — buffer/surface init
- Sets *param_1 = PTR_FUN_005adc18

**Calls:**
- FUN_00507496 — buffer/surface init

**Used by system:** docs/20-math-utilities.md — widget/renderer constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b409 — Short Computation (VTable Set + Init)

Source: unknown | Confidence: medium
Similar to FUN_0050ab19 with different params.

**Key logic:**
- Calls FUN_00507496(param_2, 0x20, 2) — buffer/surface init
- Sets *param_1 = PTR_FUN_005add5c

**Calls:**
- FUN_00507496 — buffer/surface init

**Used by system:** docs/20-math-utilities.md — widget/renderer constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c0a6 — Unidentified Logic (Cubic Bezier Interpolation)

Source: unknown | Confidence: high
Computes a cubic Bezier curve point at parameter t (param_6). Using control points param_2-param_5.

**Key logic:**
- Computes t² and t³
- Bezier basis: B(t) = (1-t)³·P1 + 3(1-t)²t·P2 + 3(1-t)t²·P3 + t³·P4
- Constants: _DAT_0059e478, _DAT_0059e43c are 1.0f and 3.0f (Bezier coefficients)
- fVar4 = (t³·2) - t²·3 + 1 = (1-t)³ coefficient
- param_6 = t³ - 2t² + t = 3·(1-t)²t (some factor)
- fVar3 = t²·3 - 2t³ = 3·(1-t)t² coefficient
- (fVar2 - fVar1) = t³ - t² = t²(t-1) → t³ coefficient
- Computes 2D result: param_1[0] and param_1[1]

**Globals:**
- DAT_0059e478, DAT_0059e43c — Bezier spline coefficients (docs/12)

**Used by system:** docs/20-math-utilities.md — spline/curve interpolation for animation, camera path, or audio panning

**Algorithm family:** cubic Bezier interpolation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0050f632 — Unidentified Logic (Struct Init with Conditionals)

Source: unknown | Confidence: low
Complex init setting fields conditionally, zeroing memory, calling chain of inits.

**Key logic:**
- If param_2 != 0x3d: sets +0x14=10, +0x18=0x3d, +0x1c=param_2, calls vtable slot 0
- If param_3 != 0x1a8: sets +0x14=0x13, +0x18=0x1a8, +0x1c=param_3, calls vtable slot 0
- Zeroes 0x6a dwords (preserving original *param_1)
- Sets byte at param_1+3 = 1
- Calls FUN_00516883, zeroes fields at offsets
- Loop: zeroes 4 pairs of dwords
- Calls FUN_005115ee, FUN_00515ecd
- If DAT_005d79dc == 2: updates from FUN_005159c3()
- Sets param_1[4] = 200

**Calls:**
- Virtual method (slot 0) — process/dispatch
- FUN_00516883, FUN_005115ee, FUN_00515ecd, FUN_005159c3 — init chain

**Used by system:** docs/20-math-utilities.md — complex object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd4d0 — Short Computation (Conditional Free at +0x14)

Source: unknown | Confidence: high
Frees sub-object at param_1+0x14 if non-null.

**Key logic:**
- If param_1+0x14 != 0: frees via FUN_00587bcf

**Calls:**
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — sub-object cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dfbb0 — Unknown (Constructor with Batch Init)

Source: unknown | Confidence: low
Complex constructor calling many init functions in specific order/pattern.

**Key logic:**
- Calls FUN_004dfa50() — prep
- Sets param_1[0x24]=0, param_1[0x25]=-1
- Loop 4×: FUN_004dfb00, FUN_004dfa50×2, FUN_004dfb60
- Then FUN_004dfb00, FUN_004dfa50×2
- Loop 8×: FUN_004dfa50
- Loop: FUN_004dfb90 until condition
- Loop 11×: FUN_004de5f0
- Zeroes param_1[0], param_1[0x2ea], param_1[0xaf5]
- Calls FUN_004e09e0()

**Calls:**
- Many init functions

**Used by system:** docs/20-math-utilities.md — complex object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ea010 — Arithmetic/Comparison (Slot Allocator)

Source: unknown | Confidence: medium
Slot allocator — returns pointer to next slot in global table, max 32 slots.

**Key logic:**
- If DAT_008adaf8 < 32: returns &DAT_008ad3f8 + (index * 14), increments count
- If full: returns &DAT_008adac0 (overflow/default)

**Globals:**
- DAT_008adaf8 — slot counter
- DAT_008ad3f8 — slot table base (stride 14)
- DAT_008adac0 — overflow slot

**Used by system:** docs/20-math-utilities.md — slot/resource allocator

**Algorithm family:** fixed-size pool allocator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f3490 — Arithmetic/Comparison (ABS-Vector Load)

Source: unknown | Confidence: medium
Loads 3 double values via FUN_00565aa0, applies ABS to each.

**Key logic:**
- Reads 3 doubles from param_1+0x90, +0x98, +0xa0
- Calls FUN_00565aa0(param_3, &val1, &val2, &val3, 0)
- If non-zero: applies ABS to each
- Force-positive operation — ensures vector components are non-negative

**Calls:**
- FUN_00565aa0 — vector/stream load (unknown)
- ABS — absolute value

**Used by system:** docs/20-math-utilities.md — vector absolute value (magnitude guarantee)

**Algorithm family:** vector math, ABS

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8c00 — Arithmetic/Comparison (Callback Dispatch with Status)

Source: unknown | Confidence: medium
Dispatches via global function pointer DAT_008afc8c, returns status codes.

**Key logic:**
- If DAT_008afc8c == null: returns 4 (not initialized)
- Calls callback(param_1, param_2, param_3)
- Returns: 0 if result==1, 7 if result 2/3, 6 otherwise

**Globals:**
- DAT_008afc8c — function pointer

**Used by system:** docs/20-math-utilities.md — callback dispatch with status mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9ad0 — Arithmetic/Comparison (Time Accumulation)

Source: unknown | Confidence: medium
Computes a time delta from FUN_00556730, accumulates into global time variables.

**Key logic:**
- Calls FUN_00556730(0) — timer query
- Stores to _DAT_008afe90 (double), _DAT_008afe98
- _DAT_008afea0 += delta (current time accumulator)
- _DAT_008afea8 += delta (secondary time accumulator)

**Globals:**
- DAT_008afe90, DAT_008afe98, DAT_008afea0 (current session time), DAT_008afea8 — time accumulators

**Calls:**
- FUN_00556730 — timer query (0)

**Used by system:** docs/20-math-utilities.md — game timer update / time accumulation

**Algorithm family:** delta time accumulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004fc870 — Unidentified Logic (Float-to-UShort Conversion)

Source: unknown | Confidence: high
Converts float values to ushort via __ftol and ROUND with scaling.

**Key logic:**
- 4 × __ftol() → stores as ushort param_2[0..3]
- 2 × ROUND(float * DAT_0059e6fc) → stores as ushort param_2[4..5]
- Converts float coords to packed ushort representation

**Globals:**
- `DAT_0059e6fc` — float-to-ushort scaling factor

**Calls:**
- __ftol — MSVC CRT float-to-long
- ROUND — MSVC CRT rounding

**Used by system:** docs/20-math-utilities.md — coordinate/color data packing for rendering or network

**Algorithm family:** data conversion, float→ushort

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00500170 — Short Computation (Struct Init with Values)

Source: unknown | Confidence: medium
Sets vtable pointer, count field, calls two init functions.

**Key logic:**
- param_1[0] = DAT_005ad344 (vtable/data ptr)
- param_1[1] = 8 (count/size)
- Calls FUN_00500190() and FUN_005001b0()

**Calls:**
- FUN_00500190 — init
- FUN_005001b0 — init

**Used by system:** docs/20-math-utilities.md — struct/object init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ca3e0 — Arithmetic/Comparison (Struct Init -1/0)

Source: unknown | Confidence: high
Sets first 2 dwords to -1, zeroes 12 dword fields.

**Key logic:**
- param_1[0] = -1, param_1[1] = -1, param_1[2] = 0
- Zeroes param_1[0x14] through param_1[0x1a] (7 dwords)
- Sets param_1[0x10] = 0

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004d2e20 — Arithmetic/Comparison (Conditional Free)

Source: unknown | Confidence: high
Conditionally frees a sub-object at param_1+0xa4.

**Key logic:**
- If param_1+0xa4 != 0: calls FUN_004d0080(), frees via FUN_00587bcf, zeros pointer

**Calls:**
- FUN_004d0080 — pre-free cleanup
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — conditional sub-object cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5c40 — Short Computation (Global Zero Pair)

Source: unknown | Confidence: high
Zeroes two global variables.

**Key logic:**
- DAT_008ad254 = 0
- DAT_008ad258 = 0

**Globals:**
- DAT_008ad254, DAT_008ad258 — state/flag pair

**Used by system:** docs/20-math-utilities.md — global state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7dd0 — Short Computation (Call Wrapper)

Source: unknown | Confidence: high
Wrapper calling FUN_004d89d0.

**Key logic:**
- Calls FUN_004d89d0() — unknown

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d8a30 — Unidentified Logic (Audio/State Dispatch by Index)

Source: unknown | Confidence: low
Switch dispatch on param_1 (0-5) selecting global pointers, calls audio/notification function.

**Key logic:**
- Switch on param_1:
  - 0: jumps to case 0 (skip)
  - 1: iVar1 = DAT_008ad398
  - 2: iVar1 = DAT_008ad39c
  - 3: iVar1 = DAT_008ad3a0
  - 4: iVar1 = DAT_008ad3a4
  - 5: calls FUN_004d90d0(DAT_008ad3a8)
- Default: returns 1
- If iVar1 != 0 AND DAT_008b8dc8 != 0: calls FUN_00553700(DAT_008b8dc8) — audio stop/release (docs/19)

**Globals:**
- DAT_008ad398, _39c, _3a0, _3a4, _3a8 — state handles
- DAT_008b8dc8 — audio/event handle

**Calls:**
- FUN_004d90d0 — handler for case 5
- FUN_00553700 — audio stop/release (docs/19)

**Used by system:** docs/20-math-utilities.md — audio/event state dispatch by index

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004db9a0 — Utility Function (Number Format + UI Draw)

Source: unknown | Confidence: low
Converts a float to int via __ftol, formats string, draws on screen.

**Key logic:**
- Calls __ftol() — float-to-long conversion (MSVC CRT)
- Calls FUN_0058815f(buffer, format_string, value) — sprintf-style format (docs/06, 09)
- Calls FUN_004d7e40(buffer, param_2, param_3, 0xffff00, 2, 1, 1.0f, 1.0f) — UI text draw

**Calls:**
- __ftol — MSVC CRT
- FUN_0058815f — string format (docs/06)
- FUN_004d7e40 — UI text draw

**Used by system:** docs/20-math-utilities.md — UI numeric display rendering

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcb70 — Short Computation (Struct Init with Float Defaults)

Source: unknown | Confidence: high
Zeroes 8 dwords, sets two float defaults.

**Key logic:**
- Zeroes param_1[0..7]
- Sets param_1[9] = 1.0f (0x3f800000)
- Sets param_1[8] = 1.0f

**Used by system:** docs/20-math-utilities.md — struct init with default scale factors

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bafc0 — Memory Allocation (Linked List Builder)

Source: unknown | Confidence: medium
Allocates a linked list of 0x7f0-byte data blocks organized by size.

**Key logic:**
- Allocates 4-byte local container
- Allocates 0x7f4-byte block: sets first word = 2, calls FUN_004b4f50() twice
- Wraps in 0xc-byte linked list node
- Appends to param_1 list (head/tail at +0x00/+0x04/+0x08)
- Increments count at param_1[3]
- Allocates sub-nodes for sizes at strides 0x3f8 from 0 to 0x7f0
- Each wraps in 0xc-byte node with flag=0

**Calls:**
- operator_new — heap allocation × many
- FUN_004b4f50 — unknown init

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | head pointer |
| +0x04 | int* | tail pointer |
| +0x08 | int* | iterator |
| +0x0c | int | count |

**Used by system:** docs/20-math-utilities.md — memory pool / buffer list builder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bc2a0 — Arithmetic/Comparison (Bounded Array Lookup)

Source: unknown | Confidence: high
Looks up a float from an array with bounds checking, returns default on failure.

**Key logic:**
- Validates param_2 >= 0 AND < param_1+8 AND < param_1+0x88
- If valid: returns `*(param_1+0x90)[param_2]` as float
- Else: returns DAT_0059e670 (default threshold)

**Globals:**
- `DAT_0059e670` — default float value

**Used by system:** docs/20-math-utilities.md — safe array element access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bdf90 — Arithmetic/Comparison (Nested Loop Call x65)

Source: unknown | Confidence: low
Calls FUN_004bd8c0 65 times (8×8+1) in nested loops.

**Key logic:**
- Outer loop 8×, inner loop 8×: calls FUN_004bd8c0(param_1)
- Final call after loop
- Total: 65 calls

**Calls:**
- FUN_004bd8c0 — unknown handler

**Used by system:** docs/20-math-utilities.md — batch processing / init loop

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c1e40 — Utility Function (Destructor with Multi-Free)

Source: unknown | Confidence: high
Destructor that frees two sub-pointers then optionally self.

**Key logic:**
- If param_1[2] != 0: frees via FUN_00587bcf
- If *param_1 != 0: frees via FUN_00587bcf
- If (param_2 & 1): frees self via FUN_00587bcf

**Calls:**
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — multi-pointer object destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2dc0 — Arithmetic/Comparison (Running Average with Clamp)

Source: unknown | Confidence: medium
Computes running average with counter, clamps result to [0x428c0000, 0x42f00000] (70, 120).

**Key logic:**
- Increments counter at param_1+0x2c (wraps 0→1)
- Running average: `fVar3 = (counter_prev * avg + param_2) / counter_new`
- Stores to param_1+0x50
- If fVar3 < _DAT_005acb00 (threshold): sets = 70.0f (0x428c0000)
- If fVar3 > _DAT_0059e968 (max threshold): sets = 120.0f (0x42f00000)

**Calls:** none

**Used by system:** docs/20-math-utilities.md — running average calculator with clamp; possibly fuel consumption, speed, or lap time smoothing

**Algorithm family:** running average, clamp

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c5db0 — Short Computation (Struct Init with Defaults)

Source: unknown | Confidence: high
Zeroes 6 dwords, sets one to -1, calls FUN_004c62c0.

**Key logic:**
- Sets param_1[0]=0, param_1[1]=-1, param_1[2..5]=0
- Calls FUN_004c62c0() — unknown init

**Calls:**
- FUN_004c62c0 — unknown

**Used by system:** docs/20-math-utilities.md — struct/object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8350 — Arithmetic/Comparison (Global Cleanup Dispatch)

Source: unknown | Confidence: high
Calls destructor via vtable on 3 global objects, zeros pointers.

**Key logic:**
- If DAT_008ac4c8 != 0: calls vtable slot 0(1), zeros pointer
- If DAT_008ac4cc != 0: calls vtable slot 0(1), zeros pointer
- If DAT_008ac4d0 != 0: calls vtable slot 0(1), zeros pointer
- If DAT_008ac4c4 != 0: calls vtable slot 3(0xc), zeros pointer

**Globals:**
- DAT_008ac4c8, DAT_008ac4cc, DAT_008ac4d0, DAT_008ac4c4 — global singleton/manager pointers

**Calls:**
- Virtual dispatch (slot 0, slot 3) — destructors

**Used by system:** docs/20-math-utilities.md — global cleanup/shutdown

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9000 — Arithmetic/Comparison (Chained Validation)

Source: unknown | Confidence: low
Chained validation: checks field and calls FUN_0040c910 followed by FUN_0054c0e0.

**Key logic:**
- Calls FUN_0040c910() — game action query (docs/09, 19)
- If param_1+4 != 0 AND iVar1 != 0:
  - Calls FUN_0054c0e0(iVar1) — renderer resource check (docs/19)
  - If non-null: returns 1
- Returns 0

**Calls:**
- FUN_0040c910 — game action/state query
- FUN_0054c0e0 — renderer resource check (docs/19)

**Used by system:** docs/20-math-utilities.md — validation/availability check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b41b0 — Short Computation (Call Wrapper)

Source: unknown | Confidence: high
Calls FUN_004b9f70.

**Key logic:**
- Calls FUN_004b9f70() — unknown

**Used by system:** docs/20-math-utilities.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b5040 — Unknown (Buffer/Stream Init with Zero Fill)

Source: unknown | Confidence: medium
Initializes a buffer with data from a stream/param source, writes zeros to specific offsets.

**Key logic:**
- Calls FUN_00566c00(param_1, 1) — binary read 1 byte (docs/10, 06)
- Calls FUN_00566c00(&param_2, 1) — read 1 byte
- Calls FUN_00566c00(param_1+1, param_2) — read param_2 bytes
- Writes zero at `param_2 + 1 + param_1`
- Calls FUN_00566c00 for 4 more chunks at +0x41(0x20), +0x61(0x20), +0x84(4), +0x88(4)
- Returns 1

**Calls:**
- FUN_00566c00 — binary read from stream (docs/10, 06, 08)

**Used by system:** docs/20-math-utilities.md — replay/stream data deserialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9a10 — Unknown (Session Time Fraction Computation)

Source: unknown | Confidence: medium
Computes a fraction of session time relative to total session duration, used for progress/percentage calculations.

**Key logic:**
- Reads pointer from *param_1
- Calls FUN_004b87a0() — queue peek / time read (docs/06)
- If flag at +0xf81 == 0 (normal mode):
  - elapsed = end - start; total = start
- Else (alternate mode):
  - total = _DAT_008afea0 (current time) - param_1+0xf84
  - Clamps total >= start
  - elapsed = _DAT_008afea0 - total
- If elapsed > DAT_0059e440 (zero threshold): returns (value - total) / elapsed
- Returns 0

**Globals:**
- `DAT_008afea0` — current session time (docs/06, 09, 17, 18, 19, 21)
- `DAT_0059e440` — zero threshold (~0.0f, docs/12)

**Calls:**
- FUN_004b87a0 — queue peek / time read (docs/06)
- FUN_004b9ce0 — gate-specific value (docs/06, 19)

**Used by system:** docs/20-math-utilities.md — session progress/time fraction for scoring or UI

**Algorithm family:** normalized time computation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba780 — Short Computation (Linked List Peek)

Source: unknown | Confidence: high
Returns first element's value from a linked list. Updates iterator to head.

**Key logic:**
- *param_1 is head pointer
- Sets param_1[2] = head (iterator set to head)
- If non-null: returns *head (first element's key value)
- Returns 0 if empty

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | head pointer |
| +0x08 | int* | iterator position |

**Used by system:** docs/20-math-utilities.md — linked list peek/first-item accessor; used in replay stream (docs/20)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049f070 — Short Computation (Init Chain)

Source: unknown | Confidence: low
Calls a chain of initialization functions.

**Key logic:**
- Sequential calls to: FUN_0049f790, FUN_004082b0, FUN_00461d20, FUN_004d8450, FUN_0049d070
- If DAT_008ab6e4 (ScoringGate) != 2: calls FUN_0045bc00()
- Then FUN_0049f870, FUN_0049fdb0

**Globals:**
- `DAT_008ab6e4` (ScoringGate) — skip if 2 (docs/12)

**Calls:**
- Chain of init functions

**Used by system:** docs/20-math-utilities.md — system/championship init sequence

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0dc0 — System/OS API Call (Cursor Hide)

Source: unknown | Confidence: high
Hides the Windows cursor by calling ShowCursor(0) repeatedly until hidden.

**Key logic:**
- Sets DAT_007ce260 = 1 (cursor hidden flag)
- Loop: calls ShowCursor(0) until return value < 0 (cursor hidden)

**Globals:**
- DAT_007ce260 — cursor visibility flag

**Calls:**
- ShowCursor — Win32 API (user32)

**Used by system:** docs/20-math-utilities.md — application startup cursor management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1f80 — Arithmetic/Comparison (List Array Free)

Source: unknown | Confidence: high
Frees 4 linked lists (array of 4 heads). Each list iterates via +0x44 next pointer.

**Key logic:**
- Loop over 4 slots: reads head from param_1[i*4]
- For each slot: walks list via +0x44, frees each node via FUN_00587bcf

**Calls:**
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — multi-list array cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a3fe0 — Short Computation (Dual Zero + Conditional Call)

Source: unknown | Confidence: low
Zeroes two fields, conditionally calls FUN_0054c030.

**Key logic:**
- Sets +0x78 = 0, +0x84 = 0
- If param_1+0x64 != 0: calls FUN_0054c030(0,0,1,0) — notification/resource (docs/10, 06, 09)

**Calls:**
- FUN_0054c030 — notification/resource update (docs/10, 06, 09)

**Used by system:** docs/20-math-utilities.md — struct field reset with conditional notification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a6ff0 — Short Computation (Callback Registration)

Source: unknown | Confidence: high
Registers a callback via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&LAB_004a7000) — register callback/label (docs/17, 18, 06)

**Calls:**
- FUN_00587b3e — callback registration / _atexit (docs/06, 17, 18)

**Used by system:** docs/20-math-utilities.md — static init / callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b19f0 — Short Computation (Struct Init with Defaults)

Source: unknown | Confidence: high
Initializes a struct with vtable and default values.

**Key logic:**
- param_1[1] = 0
- param_1[2] = -1
- param_1[3] = 0
- param_1[4] = -1
- *param_1 = &PTR_LAB_005acc38 (vtable)

**Used by system:** docs/20-math-utilities.md — struct/object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2420 — Arithmetic/Comparison (Short-to-Float Conversion)

Source: unknown | Confidence: high
Converts packed short values to floats with a scaling factor.

**Key logic:**
- Copies 3 dwords from param_1 to param_2 (position data)
- Converts 3 short fields (at +6, +0xe, +8 relative to param_1) to float, multiplies by DAT_0059e77c
- Stores in param_3 (float array)

**Globals:**
- `DAT_0059e77c` — short-to-float scale/conversion factor

**Used by system:** docs/20-math-utilities.md — coordinate/position conversion (short to float)

**Algorithm family:** data conversion, short→float

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2b00 — Short Computation (Bitfield Extract)

Source: unknown | Confidence: high
Extracts a 3-bit field from bits 28-30 of a uint at param_1+0x30.

**Key logic:**
- Returns `(*(param_1+0x30) >> 0x1c) & 7` — value 0-7

**Used by system:** docs/20-math-utilities.md — bitfield/flag extraction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499e10 — Short Computation (Wrapper to FUN_00566650)

Source: unknown | Confidence: high
Trivial wrapper calling FUN_00566650 with no arguments.

**Key logic:**
- Calls FUN_00566650() — path registry/string set (docs/08, 09, 02)

**Calls:**
- FUN_00566650 — path registry / name set (docs/08)

**Used by system:** docs/20-math-utilities.md — path/name registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a2c0 — Thunk to FUN_00566650

Source: unknown | Confidence: high
Trampoline — unconditional jmp to FUN_00566650. No local logic.

**Key logic:**
- Single jmp instruction to FUN_00566650
- Address appears in vtable/IAT/call table

**Calls:** FUN_00566650 (target — path registry / name set, docs/08)

**Used by system:** docs/20-math-utilities.md — vtable dispatch for string set/registry

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049adb0 — Short Computation (Field Getter at +0xc)

Source: unknown | Confidence: high
Returns the int field at param_1+0xc.

**Key logic:**
- Direct field read: return *(param_1 + 0xc)

**Used by system:** docs/20-math-utilities.md — struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049d700 — Unknown (String Formatting Pipeline)

Source: unknown | Confidence: low
Builds formatted strings using multiple encoding/formatting steps with alternating key/value pairs.

**Key logic:**
- Reads DAT_005ccbc0 (input A), DAT_007ce238 (input B), DAT_005ccbb8 (base offset)
- Calls FUN_0049e410 to init
- Repeated pattern 4 times:
  - Clears 64-byte buffer
  - Calls FUN_0049f6a0(buffer, val, offset, param_1+8, data, flag) with alternating data/format
  - Advances offset by DAT_005ccbbc (stride)
- Final call with value 0xf0
- Uses string encode/decode functions (FUN_0049c310, _c370, _c490, _c4e0, _bcd0, _bd40, _c0b0)

**Globals:**
- DAT_005ccbc0, DAT_007ce238, DAT_005ccbb8, DAT_005ccbbc

**Calls:**
- Many string encode/decode functions
- FUN_0049f6a0 — string format builder

**Used by system:** docs/20-math-utilities.md — string formatting pipeline for UI/text output

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004916e0 — Short Computation (4 x ushort Setter)

Source: unknown | Confidence: high
Sets 4 consecutive ushort fields on a struct.

**Key logic:**
- *param_1 = param_2, param_1[1]=param_3, param_1[2]=param_4, param_1[3]=param_5

**Used by system:** docs/20-math-utilities.md — struct field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491e60 — Short Computation (Destructor with Conditional Free)

Source: unknown | Confidence: high
Trivial destructor — conditionally frees object.

**Key logic:**
- If (param_2 & 1): calls FUN_00587bcf(param_1)
- Returns param_1

**Calls:**
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — simple destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004950c0 — Short Computation (Conditional Release)

Source: unknown | Confidence: high
Conditionally calls FUN_00554d70 on a global handle.

**Key logic:**
- If DAT_007cde10 != 0: calls FUN_00554d70(DAT_007cde10) — notify device/release (docs/19)

**Globals:**
- DAT_007cde10 — renderer device/surface handle

**Calls:**
- FUN_00554d70 — notify device / release (docs/19)

**Used by system:** docs/20-math-utilities.md — renderer resource cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495b30 — Short Computation (Loop Until Condition)

Source: unknown | Confidence: low
Loops calling FUN_00498f70 and FUN_00495ae0 while a field is non-null.

**Key logic:**
- Reads field at param_1+0x18
- While non-null AND FUN_00498f70() returns 1: calls FUN_00495ae0(), re-reads field

**Calls:**
- FUN_00498f70 — condition check
- FUN_00495ae0 — loop body

**Used by system:** docs/20-math-utilities.md — polling/iteration loop

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004977e0 — Unknown (State Setter with Float Constant)

Source: unknown | Confidence: medium
Sets state field and a float value based on case (0-4).

**Key logic:**
- If param_3 != -1:
  - Stores param_2 at param_1+0x157c
  - Calls FUN_00496e90(1) twice
  - Switch on param_3 0-4: sets +0x1578 (state) to 0-3, always sets +0xdc = 0x3c23d70a (0.01f)

**Calls:**
- FUN_00496e90 — state notification

**Used by system:** docs/20-math-utilities.md — state configuration with default float constant

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004988d0 — Unknown (Widget/Entity Activation)

Source: unknown | Confidence: low
Looks up an object by name, calls virtual methods on it for activation/setup.

**Key logic:**
- If param_2 non-null:
  - Checks *(param_1+0x18)->field_0x50 != 0
  - Calls FUN_00497750(param_2) — name lookup
  - If found: calls virtual slot 0x8c(), FUN_004979c0() cleanup, FUN_00553050(data1, data2), virtual slot 0x90()

**Calls:**
- FUN_00497750 — name lookup
- Virtual methods (slots 0x8c, 0x90)
- FUN_004979c0 — cleanup
- FUN_00553050 — setup/init

**Used by system:** docs/20-math-utilities.md — entity/widget lookup and activation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499180 — Short Computation (VTable Set)

Source: unknown | Confidence: high
Sets vtable pointer and calls FUN_00498d90.

**Key logic:**
- Sets *param_1 = PTR_FUN_005aca30
- Calls FUN_00498d90()

**Calls:**
- FUN_00498d90 — unknown init

**Used by system:** docs/20-math-utilities.md — widget constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499910 — Unknown (State Machine Iterator)

Source: unknown | Confidence: low
Three-state machine iterating through a linked data structure with traversal logic.

**Key logic:**
- If param_1[1] flag set: returns (abort)
- State 0: on first call sets *param_1=1, reads from param_1[3]+4, walks chain
- State 1: reads +0x48 from current node
- State 2: calls FUN_004998c0()/FUN_00499870() for conditions; loops back to state 0 or advances via +0x44/+0x8c
- Otherwise advances via +0x8c

**Calls:**
- FUN_004998c0 — condition check
- FUN_00499870 — condition check

**Used by system:** docs/20-math-utilities.md — data structure state machine iterator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004870e0 — Unknown (UI List Position Lookup)

Source: unknown | Confidence: medium
Looks up a position in a UI list by index, with threshold check and alternative path.

**Key logic:**
- Reads offset from param_1+4 (base position)
- Gets count via FUN_0049adb0()
- If param_2 < count: calls FUN_0049aec0 to look up, returns (short)result + base
- Else if param_1+200 != 0: same lookup on alternative path
- Returns -1 on failure

**Calls:**
- FUN_0049adb0 — count getter
- FUN_0049aec0 — position lookup

**Used by system:** docs/20-math-utilities.md — UI list/widget position calculation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487d70 — Unknown (UI Checkbox/Toggle Logic)

Source: unknown | Confidence: low
UI checkbox/toggle handler — checks state via virtual dispatch toggles visual.

**Key logic:**
- Gets active element via virtual method slot 0xac
- If null: sets virtual slot 0x38(1) — enable
- Else: sets slot 0x38(0) — disable
- Checks param_1[0x39] flag byte to invert comparison
- Compares *element to 0 (checked state)
- Calls FUN_00487720() — state query
- If state changed: calls FUN_00487260(bVar3) and virtual slot 0x2c(1) — update

**Calls:**
- Virtual method (slots 0xac, 0x38, 0x2c) — UI element access
- FUN_00487720 — state query
- FUN_00487260 — visual update

**Used by system:** docs/20-math-utilities.md — UI checkbox/toggle control

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004893c0 — Unknown (Options Screen Init)

Source: unknown | Confidence: medium
Options/configuration screen constructor. Sets vtable, zeroes fields, sets defaults.

**Key logic:**
- Calls FUN_00485e30() — parent init
- Zeroes many fields (slots 0x51, 0x145, 0x146, 0x52, 0x4d-0x4f, 0x56, 0x58, 0x59, 0x5b)
- Vtable = PTR_FUN_005abd78
- Sets +0x131 = 1 (enabled), +0x50 = 5 (type/page), +0x5a = -1, +0x5c = -1, slot 0x38 = 1

**Calls:**
- FUN_00485e30 — parent init

**Used by system:** docs/20-math-utilities.md — UI options/configuration screen

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b560 — Unknown (Path/File Char Validator)

Source: unknown | Confidence: medium
Validates filename characters based on filesystem mode (param_1+0x2e8).

**Key logic:**
- Checks via FUN_00589c49 if char is valid ASCII/graphic
- Mode 1: rejects \, /, :, .; space handled specially via scanned string at +0x2f0
- Mode 2: rejects special chars (calls FUN_00589b9e, FUN_00589b70); allows . and :
- Returns 0 (reject) or 1 (accept)

**Calls:**
- FUN_00589c49 — valid char check
- FUN_00589b9e — special char check
- FUN_00589b70 — special char check

**Used by system:** docs/20-math-utilities.md — filesystem path/filename validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d0d0 — Unknown (UI Scroll/Page Navigation)

Source: unknown | Confidence: low
UI scrollbar/page navigation — computes new page index and scrolls until target reached.

**Key logic:**
- Gets page count via virtual slot 0x20, current page via slot 0x18
- If page_count > current_page:
  - Gets current page again, computes center offset via FUN_00498880
  - Computes new index = param_1[0xcd] + offset - (current + (page_count-current)/2)
  - Using param_1[0xca] and param_1[0xcb] as grid dimensions:
    - Normalizes index modulo (cols * rows), then divides by cols
    - Clamps to [0, cols-1]
  - Loops calling virtual slot 0xb8(bVar3) until index matches param_1[0xce]

**Calls:**
- Virtual methods (slots 0x20, 0x18, 0xb8)
- FUN_00498880 — center offset computation

**Used by system:** docs/20-math-utilities.md — UI grid/scroll navigation control

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e300 — Short Computation (UI Widget Constructor)

Source: unknown | Confidence: medium
UI widget constructor with FUN_00487220 init.

**Key logic:**
- Calls FUN_00487220(0, 0) — parent init
- Sets +0x3f=0, +0x40=-1, slot 0x39=0
- Vtable = PTR_LAB_005ac490
- Calls FUN_00566650(0) — path/name set (docs/08)

**Calls:**
- FUN_00487220 — parent init
- FUN_00566650 — path/name set

**Used by system:** docs/20-math-utilities.md — UI widget constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fb70 — Short Computation (UI Widget Constructor)

Source: unknown | Confidence: high
Widget constructor with FUN_00485e30 init.

**Key logic:**
- Calls FUN_00485e30() — parent init
- Vtable = PTR_FUN_005ac5f0
- Sets +0x38=0, +0x39=-1

**Calls:**
- FUN_00485e30 — parent init

**Used by system:** docs/20-math-utilities.md — UI widget constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490390 — Unknown (UI State Dispatch by Mode)

Source: unknown | Confidence: medium
Dispatches UI state based on FUN_00486720 result, calls virtual refresh.

**Key logic:**
- Calls FUN_00486720() — get current mode/state
- Switch on result 0-2: virtual slot 0x40(4) — large icon/page
- Switch on result 3-5: virtual slot 0x40(1) — compact icon/page
- Calls virtual slot 0x9c() — refresh/validate
- Calls FUN_00490660() — apply/finalize

**Calls:**
- FUN_00486720 — state/mode query
- Virtual methods (slots 0x40, 0x9c)
- FUN_00490660 — apply/finalize

**Used by system:** docs/20-math-utilities.md — UI mode-dependant icon/page render

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047bcf0 — Unknown (Menu Cursor Scroll Logic)

Source: unknown | Confidence: medium
UI menu scroll position management with boundary clamping and step logic.

**Key logic:**
- Gets cursor count from FUN_0047bc30() — menu cursor count forward (docs/19)
- Gets cursor count from end via FUN_0047bc90() — menu cursor count from end (docs/19)
- Reads current scroll pos from param_1+0xec
- If forward_count < scroll_pos:
  - Near boundary (scroll_pos-1 <= forward_count): decrements scroll by 1
  - Else: scroll -= max(step, scroll - forward_count)
- Else (forward >= scroll):
  - If forward < scroll + step: jumps to clamp
  - If forward >= scroll + step: scroll += max(step, forward - (scroll+step-1))
  - Else: scroll++
- Clamp: if scroll < 0: set to 0; if scroll >= end_count-1: set to end_count-2
- Calls FUN_0047bd90() — menu scroll apply/refresh

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xec | int | current scroll position |
| +0xf0 | int | scroll step size |

**Calls:**
- FUN_0047bc30 — menu cursor count forward (docs/19)
- FUN_0047bc90 — menu cursor count from end (docs/19)
- FUN_0047bd90 — menu scroll apply/refresh

**Used by system:** docs/20-math-utilities.md — UI menu scroll/position management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047eff0 — Short Computation (UI List Init)

Source: unknown | Confidence: high
UI list constructor — calls FUN_00488b00 with fixed params, sets vtable.

**Key logic:**
- Calls `FUN_00488b00(1, -1)` — UI list init (docs/01)
- Sets `*param_1 = &PTR_LAB_005a6d20` (vtable)

**Calls:**
- FUN_00488b00 — UI list init (docs/01)

**Used by system:** docs/20-math-utilities.md — UI list widget constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004856c0 — Short Computation (Widget Destructor)

Source: unknown | Confidence: high
Widget destructor — sets vtable, calls cleanup, optionally frees.

**Key logic:**
- Sets `*param_1 = &PTR_FUN_005a9710` (vtable reset)
- Calls FUN_00487250() — cleanup/destroy
- If (param_2 & 1): calls FUN_00587bcf(param_1) — free

**Calls:**
- FUN_00487250 — cleanup/destroy
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — UI widget destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004863c0 — Short Computation (Linked List Index Access)

Source: unknown | Confidence: high
Walks a singly-linked list to return the Nth node.

**Key logic:**
- Validates param_2 >= 0
- Reads head from param_1+0x90
- Iterates via next at +0x8c, decrementing param_2 each step
- When param_2 reaches 0 or list ends: returns current node or 0

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x90 | int* | list head |

**Struct offsets (node):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x8c | int* | next node pointer |

**Used by system:** docs/20-math-utilities.md — linked list index-based accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00470170 — Short Computation (Virtual Dispatch + Call)

Source: unknown | Confidence: high
Calls virtual method (slot 0xa0) then FUN_00470040.

**Key logic:**
- Virtual call: `(*param_1)->slot_0xa0()`
- Calls FUN_00470040()

**Calls:**
- Virtual method (slot 0xa0) — refresh/update
- FUN_00470040 — unknown

**Used by system:** docs/20-math-utilities.md — UI widget update/refresh

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00471970 — Short Computation (UI Widget Constructor)

Source: unknown | Confidence: medium
UI widget with vtable PTR_FUN_005a1440, sets defaults and registers labels.

**Key logic:**
- Calls FUN_00466d60(1) — parent constructor
- Vtable = PTR_FUN_005a1440
- param_1[199] = &DAT_007ce7f0 (data reference at +0x31c)
- Settings at +0x324..+0x334: type=2, count=0, min=1, max=1, default=0xf4 (244)
- Registers three label strings via FUN_00486f30 with -1 ID
- Calls FUN_004670e0() — finalize/init

**Calls:**
- FUN_00466d60 — parent constructor
- FUN_00486f30 — label/string registration (docs/06)
- FUN_004670e0 — finalize

**Used by system:** docs/20-math-utilities.md — UI slider/number selector widget

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473c40 — Short Computation (UI Widget Constructor)

Source: unknown | Confidence: medium
UI widget similar to FUN_00471970 with different vtable and defaults.

**Key logic:**
- Calls FUN_00466d60(1) — parent constructor
- Vtable = PTR_FUN_005a2f40
- param_1[199] = &DAT_007cf7d0 (data reference at +0x31c)
- Settings: type=1, count=0, min=1, max=1, default=0x17b (379)
- Registers two labels via FUN_00486f30
- Calls FUN_004670e0()

**Calls:**
- FUN_00466d60 — parent constructor
- FUN_00486f30 — label registration
- FUN_004670e0 — finalize

**Used by system:** docs/20-math-utilities.md — UI options screen widget

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00475120 — Short Computation (Destructor with Conditional Free)

Source: unknown | Confidence: high
Destructor — calls cleanup, optionally frees memory.

**Key logic:**
- Calls FUN_00475140() — cleanup
- If (param_2 & 1): calls FUN_00587bcf(param_1) — free
- Returns param_1

**Calls:**
- FUN_00475140 — cleanup
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — widget destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004775f0 — Short Computation (Scene Sync via Virtual)

Source: unknown | Confidence: low
Checks scene data (+0x174) against stored value, updates if different via virtual refresh.

**Key logic:**
- Calls FUN_00477810() — scene accessor
- If result != 0 AND `result+0x174 != param_1[0x61]`:
  - Updates `param_1[0x61] = result+0x174`
  - Calls virtual method at slot 0xa0 — refresh

**Calls:**
- FUN_00477810 — scene data accessor
- Virtual method (slot 0xa0) — UI refresh

**Used by system:** docs/20-math-utilities.md — UI scene/session sync

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478690 — Short Computation (Conditional Virtual Dispatch)

Source: unknown | Confidence: medium
Checks flag field, dispatches virtual method with 1 or 0.

**Key logic:**
- If param_1[0x4e] (+0x138) != 0: virtual call slot 0x3c(1), returns param_1+0x46
- Else: virtual call slot 0x3c(0), returns null

**Calls:**
- Virtual method (slot 0x3c) — selection callback

**Used by system:** docs/20-math-utilities.md — UI list/selector selection handler

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479940 — Short Computation (UI Widget Constructor)

Source: unknown | Confidence: medium
Widget constructor with FUN_00466980 init, sets enable flag.

**Key logic:**
- Calls FUN_00466980(0, 1.0f) — parent init
- Vtable = PTR_FUN_005a55a0
- Sets byte at param_1+0x3c = 1 (enabled)

**Calls:**
- FUN_00466980 — parent init (0, 1.0f)

**Used by system:** docs/20-math-utilities.md — UI toggle/enable control constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a190 — Short Computation (UI Widget Constructor)

Source: unknown | Confidence: medium
Widget constructor with FUN_004668e0 init, clears enable flag.

**Key logic:**
- Calls FUN_004668e0(0, 1.0f) — parent init
- Vtable = PTR_FUN_005a5fb0
- Sets byte at param_1+0x41 = 0 (disabled)

**Calls:**
- FUN_004668e0 — parent init

**Used by system:** docs/20-math-utilities.md — UI button/control constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466140 — Short Computation (VTable Set + Init Calls)

Source: unknown | Confidence: medium
Sets vtable pointer then calls two init functions.

**Key logic:**
- Sets `*param_1 = &PTR_FUN_0059f140` (vtable)
- Calls FUN_004662e0() — unknown init
- Calls FUN_0048e670() — unknown init

**Used by system:** docs/20-math-utilities.md — UI/widget constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00468090 — Short Computation (VTable Set + Field Init)

Source: unknown | Confidence: medium
Sets vtable, calls init function, sets a field to -1.

**Key logic:**
- Calls FUN_00466090() — unknown init
- Sets `*param_1 = &PTR_FUN_0059f668` (vtable)
- Sets `param_1[0x4a] = -1` (field at +0x128, byte offset = 0x4a * 4 = 0x128)

**Used by system:** docs/20-math-utilities.md — UI/widget constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046b580 — Short Computation (UI Options Constructor)

Source: unknown | Confidence: medium
Constructor for UI options/configuration widget. Sets vtable, calls init, stores params.

**Key logic:**
- Calls `FUN_004893c0()` — options init (docs/06, 08)
- Sets `*param_1 = &PTR_FUN_0059fa98` (vtable)
- Calls `FUN_0048a3b0(param_3)` — unknown init with parameter
- Sets `param_1[0x5d] = 0` (+0x174), `param_1[0x5e] = -1` (+0x178), `param_1[0x5f] = param_2` (+0x17c)

**Calls:**
- FUN_004893c0 — options init (docs/06, 08)
- FUN_0048a3b0 — unknown init

**Used by system:** docs/20-math-utilities.md — UI options/configuration screen constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046e170 — Short Computation (Game Command Dispatch)

Source: unknown | Confidence: high
Dispatches game commands (0x24, 0x23) via DAT_007cd8c0 interface +0x1c, calls FUN_00489cb0 (HTML init) on success.

**Key logic:**
- Calls: `(*DAT_007cd8c0)->vtable_slot_0x1c(0x24)` — game command dispatch (docs/09, 22)
- If non-null: calls FUN_00489cb0() — HTML/state init (docs/06)
- Calls: `(*DAT_007cd8c0)->vtable_slot_0x1c(0x23)` — game command dispatch
- If non-null: calls FUN_00489cb0()

**Globals:**
- `DAT_007cd8c0` — game command dispatch interface (docs/09, 22)

**Calls:**
- Virtual method (slot 0x1c) on DAT_007cd8c0 — game command dispatch
- FUN_00489cb0 — HTML/state init (docs/06)

**Used by system:** docs/20-math-utilities.md — game UI command dispatch for screens 0x23/0x24

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461560 — Unknown (Struct Init with Default Values)

Source: unknown | Confidence: medium
Initializes a byte-based struct with zeros and specific default values.

**Key logic:**
- Zeroes bytes at offsets +0x00, +0x20, +0x40, +0x64, +0x65, +0x6e
- Sets default values: +0x66=0x10, +0x67=1, +0x68=1, +0x69=100, +0x6a=1, +0x6b=0, +0x6c=0, +0x6d=0
- As 4-byte: zeros +0x60
- As 2-byte: zeros +0x70, +0x72, +0x74, +0x76, +0x78, +0x7a; sets +0x7c=200

**Used by system:** docs/20-math-utilities.md — struct init with config defaults

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004623b0 — Short Computation (Validation Check)

Source: unknown | Confidence: high
Wraps FUN_0057a830 with fixed param_2=0x8c, returns true if result is 0.

**Key logic:**
- Calls `FUN_0057a830(param_1, 0x8c)` — validates/checks resource (0x8c = 140 bytes)
- Returns true if valid (result == 0), false otherwise

**Calls:**
- FUN_0057a830 — validation/check function (unknown)

**Used by system:** docs/20-math-utilities.md — resource/struct size validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463ca0 — Short Computation (Conditional Dispatch)

Source: unknown | Confidence: low
Conditionally calls two functions based on a field value from param_1's dereference.

**Key logic:**
- Reads `param_1[0] + 0x3fc4`
- If non-null: calls FUN_0057a730(0x100) and FUN_0045f710()

**Calls:**
- FUN_0057a730 — function with param 0x100 (unknown)
- FUN_0045f710 — unknown

**Used by system:** docs/20-math-utilities.md — conditional dispatch based on state field

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464b40 — Float Computation (Audio/Event Categorization)

Source: unknown | Confidence: low
Processes an event packet by comparing float threshold and checking flag bits, then dispatches based on encoded type.

**Key logic:**
- If `param_1+0x71 < param_2[1]` OR `(byte flags XOR at bit 7) & 0x7 != 0`:
  - Extracts type from `*param_2 >> 0x12 & 0x3f` (6-bit type field, bits 18-23)
  - If type == 0: calls FUN_004b3a90(param_2) — sound/AI audio event (docs/18?)
  - If type == 7: calls FUN_004b2dd0(param_1+0x6d, param_2[1]) — unknown handler
  - Loop: calls FUN_004649f0(0) up to 0x68 times

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x6d | byte | target for type 7 handler |
| +0x70 | byte | flags (XOR comparison) |
| +0x71 | float | threshold |

**Calls:**
- FUN_004b3a90 — sound/AI event handler (unknown)
- FUN_004b2dd0 — unknown handler
- FUN_004649f0 — loop callback (unknown)

**Used by system:** docs/20-math-utilities.md — event/audio packet processing and dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00457f90 — Unknown (Buffer Alloc + Copy)

Source: unknown | Confidence: medium
Allocates and initializes a buffer of 3-element (triplet) structs, copies data from param_2.

**Key logic:**
- If param_2 != null and param_3 > 3:
  - Calls FUN_00458020() — unknown prep
  - Stores param_3 count in param_1[1]
  - Allocates `param_3 * 0x1c + 4` bytes via operator_new
  - Stores count at beginning, advances pointer
  - Loop: copies param_2 triplets (3 dwords = 12 bytes) into buffer at stride 0x1c (28 bytes per element)
  - Calls FUN_00457ee0() — unknown post-process
  - Returns 0 (success)
- Returns 1 (error)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | allocated buffer pointer |
| +0x04 | int | count of elements |

**Calls:**
- FUN_00458020 — unknown prep
- operator_new — heap allocation
- FUN_00457ee0 — unknown post-process

**Used by system:** docs/20-math-utilities.md — buffer management / array duplication

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045b9a0 — Short Computation (Loop Init x8)

Source: unknown | Confidence: high
Zeroes a field and calls FUN_0045b430 eight times.

**Key logic:**
- Sets `param_1 + 0x31c = 0`
- Calls `FUN_0045b430(i)` for i = 0..7 — contact processing init (docs/17)

**Calls:**
- FUN_0045b430 — contact processing (docs/17)

**Used by system:** docs/20-math-utilities.md — collision contact initialization loop

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045c030 — Unknown (Struct Init with Float Defaults)

Source: unknown | Confidence: medium
Initializes a struct with zeros and two float defaults.

**Key logic:**
- Zeroes param_1[2] through param_1[0xd] (12 dwords = 48 bytes zeroed)
- Sets `param_1[0] = 0x41200000` = 10.0f
- Sets `param_1[1] = 0x40ca6666` = 6.325f

**Used by system:** docs/20-math-utilities.md — struct initialization with default physics/collision values

**Algorithm family:** struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045d730 — Unknown (Multi-List Cleanup + Destructor)

Source: unknown | Confidence: medium
Performs major cleanup of multiple linked lists, calls batch destructors, and frees sub-objects.

**Key logic:**
- Four linked list walks at offsets +0x1b780, +0x1b770, +0x1b758: each iterates via +4 next pointer, calls FUN_00418d60(1), zeroes head/tail/count
- Two batch destructor loops (0x68 = 104 iterations each): calls FUN_004b0170()
- Linked list walk at +0x3fc8: calls FUN_004646f0(1) per node, zeroes head/tail/count
- Resets vtable pointer at param_1+0x3fbc to PTR_FUN_0059f0cc
- Frees sub-objects at +0xbc and +0xb4 via FUN_00587bcf if non-null
- Final call to FUN_004b0170()

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x3fbc | void** | vtable pointer (reset to PTR_FUN_0059f0cc) |
| +0x3fc8 | int* | linked list head 4 |
| +0x1b758 | int* | linked list head 1 |
| +0x1b770 | int* | linked list head 2 |
| +0x1b780 | int* | linked list head 3 |
| +0xb4 | int* | sub-object freed if non-null |
| +0xbc | int* | sub-object freed if non-null |

**Calls:**
- FUN_00418d60 — unknown callback
- FUN_004b0170 — destructor (docs/19, docs/18)
- FUN_004646f0 — collision/contact cleanup (docs/17)
- FUN_00587bcf — free

**Used by system:** docs/20-math-utilities.md — complex object destructor / teardown for physics/collision system

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00410b20 — Short Computation (Call Wrapper)

Source: unknown | Confidence: high
Trivial wrapper calling FUN_00410ad0.

**Key logic:**
- Calls `FUN_00410ad0()` — unknown initialization/reset
- No parameters, no return

**Calls:**
- FUN_00410ad0 — unknown (not documented)

**Used by system:** docs/20-math-utilities.md — utility call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004141a0 — Short Computation (Array Lookup)

Source: unknown | Confidence: high
Returns a value from an array indexed by param_1 (0 or 1), with special cases.

**Key logic:**
- Validates param_1 in range [0, 1]
- If param_1 == 0: returns 1
- If param_1 == 1: returns DAT_005bf8d4
- Otherwise returns value from DAT_005bf8c8 array at the computed index

**Globals:**
- DAT_005bf8c8 — int array (at least 2 entries)
- DAT_005bf8d4 — int value

**Used by system:** docs/20-math-utilities.md — lookup table access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00415730 — Short Computation (UI/Vehicle Setup Chain)

Source: unknown | Confidence: low
Calls a chain of vehicle/scene lookup functions and sets a flag byte.

**Key logic:**
- Calls FUN_00415700() — unknown prep
- Calls `FUN_004c3f80(param_1)` — vehicle lookup by name (docs/08)
- Calls `FUN_004c4080()` — current vehicle accessor (docs/08, 09)
- If non-null: calls `FUN_00415230(result + 0xbc, param_1)` — named entry lookup (docs/19)
- Calls `FUN_00415650(uVar2)` — resolve target struct (docs/02)
- If non-null: sets byte at `+0xc = 1`

**Calls:**
- FUN_00415700 — unknown prep
- FUN_004c3f80 — vehicle lookup by name (docs/08)
- FUN_004c4080 — current vehicle accessor (docs/08, 09)
- FUN_00415230 — named entry lookup (docs/19)
- FUN_00415650 — resolve target struct (docs/02)

**Used by system:** docs/20-math-utilities.md — vehicle setup / scene lookup chain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041a160 — Short Computation (Empty Stub)

Source: unknown | Confidence: high
Empty function — returns immediately with no logic.

**Key logic:**
- Bare return
- No operations, no parameters modified
- Referenced as cleanup callback in FUN_004080f0

**Used by system:** docs/20-math-utilities.md — placeholder / call stub for file cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004212e0 — Short Computation (Session Score Aggregation)

Source: unknown | Confidence: medium
Iterates session entries and sums a score field at +0x1a0 across all valid entries.

**Key logic:**
- If param_1 == 0: returns 0
- Calls FUN_004c2850() — season/data buffer init (docs/06)
- Gets entity count via FUN_004c1370() — active entity counter (docs/06)
- Loop per entity:
  - Calls `FUN_004c2850(i, buffer, 0x50)` — load entity into buffer (docs/06)
  - Calls FUN_004c13a0(entity) — container get-by-index (docs/06)
  - Calls `FUN_004c0a20(buffer, 0x50)` — scene/entity name lookup (docs/06, 09)
  - Checks FUN_00566810() — file/stream validity
  - If valid: adds `*(entity + 0x1a0)` (score field) to running total
- Returns accumulated sum

**Struct offsets (entity):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1a0 | int | score/points field |

**Calls:**
- FUN_004c2850 — season/data buffer operations (docs/06, 08)
- FUN_004c1370 — active entity counter (docs/06)
- FUN_004c13a0 — container get-by-index (docs/06)
- FUN_004c0a20 — scene/entity name lookup (docs/06, 09)
- FUN_00566810 — file/stream validity check (docs/06)

**Used by system:** docs/20-math-utilities.md — season championship scoring aggregation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421a90 — Short Computation (Dual Call)

Source: unknown | Confidence: high
Calls two functions in sequence: FUN_00421890 and FUN_00566650 with same parameter.

**Key logic:**
- Calls FUN_00421890(param_1) — unknown handler
- Calls FUN_00566650(param_1) — path registry / name set (docs/08, 09, 02, etc.)

**Calls:**
- FUN_00421890 — unknown handler
- FUN_00566650 — path registry / string set (docs/08, 09, 02)

**Used by system:** docs/20-math-utilities.md — path/name registration

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00455bd0 — Short Computation (Loop Call x44)

Source: unknown | Confidence: medium
Calls FUN_00453100 44 (0x2c) times in a loop.

**Key logic:**
- Loop counter = 0x2c (44 iterations)
- Calls FUN_00453100 each iteration — collision result processing (docs/17)

**Calls:**
- FUN_00453100 — collision result processing (docs/17)

**Used by system:** docs/20-math-utilities.md — collision batch processing loop

**Moddability:** hardcoded

## FUN_0050d0bc — Thunk to FUN_0050d0af via Global Pointer

Source: unknown | Confidence: high
Trampoline — indirect jump via global pointer DAT_005d7810. No local logic.

**Key logic:**
- Reads function pointer from DAT_005d7810 and calls it
- Indirect jump (vtable-like dispatch or dynamic binding stub)
- Address 0x0050d0bc appears as thunk target for FUN_0050d0af

**Calls:**
- (*DAT_005d7810) — indirect call via global pointer

**Used by system:** docs/20-math-utilities.md — thunk trampoline, likely in vtable or callback table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055d200 — Struct Zero-Init with Base Call

Source: unknown | Confidence: high
Zero-initializes key struct fields after calling base initializer.

**Key logic:**
- Calls FUN_0053c2a0 (base struct initializer)
- Sets param_1[0] = 0, param_1[5..0xc] = 0 (multi-field zero)
- Returns param_1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | param_1[0] | int | First field |
| +0x14 | param_1[5] | int | Field 5 |
| +0x18 | param_1[6] | int | Field 6 |
| +0x1c | param_1[7] | int | Field 7 |
| +0x20 | param_1[8] | int | Field 8 |
| +0x24 | param_1[9] | int | Field 9 |
| +0x28 | param_1[10] | int | Field 10 |
| +0x2c | param_1[11] | int | Field 11 |
| +0x30 | param_1[0xc] | int | Field 12 |

**Calls:**
- FUN_0053c2a0 — base struct initializer

**Used by system:** docs/20-math-utilities.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005697a0 — Struct Copy with Reciprocal Division

Source: unknown | Confidence: medium
Copies 6 ints from param_2 to param_1+0xbc, then computes reciprocals of first 3 elements using global constant DAT_0059e420.

**Key logic:**
- Loads global constant DAT_0059e420
- Copies 6 ints (24 bytes) from param_2 to param_1+0xbc (likely 3D vector + 3 extras)
- Computes param_1+0xd4 = DAT_0059e420 / param_2[0]
- Computes param_1+0xdc = DAT_0059e420 / param_2[1]
- Computes param_1+0xe4 = DAT_0059e420 / param_2[2]
- Calls FUN_00569410 (post-processing)

**Globals:**
- DAT_0059e420 — physics/rendering constant

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xbc | CopiedData[6] | int[6] | Copy destination |
| +0xd4 | InvScale0 | double | DAT_0059e420 / param_2[0] |
| +0xdc | InvScale1 | double | DAT_0059e420 / param_2[1] |
| +0xe4 | InvScale2 | double | DAT_0059e420 / param_2[2] |

**Calls:**
- FUN_00569410 — post-processing after scale copy

**Used by system:** docs/20-math-utilities.md — physics math, reciprocal division

**Algorithm family:** vector math with reciprocal scaling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b0d0 — Indexed Linked-List Node Getter

Source: unknown | Confidence: high
Gets node at given index from a linked list structure.

**Key logic:**
- Validates index: -1 < param_2 < *(param_1+0x14) (bounds check)
- Starts from list head at param_1+0x8
- Walks linked list by following next pointer at [n+1] for param_2 iterations
- If node found: returns *node (node value)
- If null encountered mid-traversal: returns 0
- Out of bounds: returns 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x08 | ListHead | ptr | First node pointer |
| +0x14 | NodeCount | int | Total nodes in list |

**Used by system:** docs/20-math-utilities.md — linked list accessor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005679a5 — List Traversal with Early Exit

Source: unknown | Confidence: medium
Traverses a linked list with counter, returning when counter reaches 0 or pointer is null.

**Key logic:**
- Requires ZF flag from caller (enters with flags from previous instruction)
- If ZF not set: iterates decrementing param_1 until it reaches 0 or in_EAX pointer becomes 0
- On each iteration: reads in_EAX = *(in_EAX+4) (linked list next pointer)
- Pure linked list traversal with max depth counter

**Used by system:** docs/20-math-utilities.md — list traversal utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9ac0 � Audio Sample Dispatch by State

Source: unknown | Confidence: medium
Dispatches audio sample playback through one of three paths based on occlusion/field flags.

**Key logic:**
- If param_3 equals sentinel DAT_005acd04, replaces with value from FUN_004b8790
- Calls FUN_004b72a0(param_1, param_3) � visibility/lookup test
- Three paths based on occlusion state flags
- Each calls FUN_005000c0 or FUN_00500210 for audio playback

**Calls:**
- FUN_004b72a0 � visibility lookup
- FUN_005001d0, FUN_005001f0 � flag checks
- FUN_005000c0 � audio playback with buffer offset
- FUN_00500210 � audio sample playback

**Used by system:** docs/20-math-utilities.md
**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba790 � Double Pointer Accessor

Source: unknown | Confidence: high
Returns value at **(param_1+8) if valid.

**Used by system:** docs/20-math-utilities.md
**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb0c0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
10 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004bb0c0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004bc2d0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004bc2d0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004be010 — [PARTIAL] Unknown

Source: unknown | Confidence: low
14 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004be010
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004c22a0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
3 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004c22a0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_004c5de0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
5 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004c5de0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004c84a0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
6 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004c84a0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9060 — [PARTIAL] Unknown

Source: unknown | Confidence: low
2 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004c9060
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004ca410 — [PARTIAL] Unknown

Source: unknown | Confidence: low
2 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004ca410
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004cefa0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
5 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004cefa0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004d4780 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004d4780
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5c50 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004d5c50
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7de0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004d7de0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004d8fb0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
5 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004d8fb0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004dbab0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004dbab0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcba0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
9 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004dcba0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd4e0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
6 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004dd4e0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

```
<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_004EA930 � 3D Vector Subtraction

Source: unknown | Confidence: high
Computes param_3 = param_1 - param_2 (component-wise 3D vector subtraction).

**Key logic:**
- param_3[0] = param_1[0] - param_2[0] � x component
- param_3[1] = param_1[1] - param_2[1] � y component
- param_3[2] = param_1[2] - param_2[2] � z component

**Algorithm family:** 3D vector math

**Moddability:** pure utility

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f62e6 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004f62e6
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8c50 — [PARTIAL] Unknown

Source: unknown | Confidence: low
3 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004f8c50
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9b20 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004f9b20
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_004fc910 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x004fc910
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005001b0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
2 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005001b0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_005043c9 — [PARTIAL] Unknown

Source: unknown | Confidence: low
3 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005043c9
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0050ab35 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0050ab35
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b42a — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0050b42a
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c134 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0050c134
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d44f — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0050d44f
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0050df88 — Thunk

Source: unknown | Confidence: high
Indirect jump or trampoline. No local logic — delegates to another function.

**Key logic:**
- Single jmp/call instruction; appears in vtable or call table

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050f6f7 — [PARTIAL] Unknown

Source: unknown | Confidence: low
19 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0050f6f7
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0051177c — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0051177c
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005124d5 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005124d5
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005151af — [PARTIAL] Unknown

Source: unknown | Confidence: low
11 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005151af
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005164a6 — [PARTIAL] Unknown

Source: unknown | Confidence: low
9 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005164a6
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00517ac5 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00517ac5
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

```
<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_00520FC6 � SSE 3D Vector Normalization with Length

Source: unknown | Confidence: high
SSE-accelerated 3D vector normalization. Computes length squared, determines if vector is zero, normalizes output vector and optional length.

**Key logic:**
- Loads source vector from param_1 (2 x 64-bit = 2 x float pair)
- Computes lenSq = x� + y� + z� via PackedFloatingMUL + ADD + Accumulate
- Compares against threshold at _PTR_DAT_005af970
- If lenSq > threshold:
  - invLen = RSQRT(lenSq) � reciprocal square root approximation
  - If param_2 (output vector) non-null:
    - Newton-Raphson refinement: invLen = RSQRT_iter1(invLen�, lenSq) * invLen
    - Normalize: out.x = src.x * invLen, out.y = src.y * invLen
  - If param_3 (output length) non-null:
    - len = FUN_00529000() � square root approximation (docs/21, 20)
    - len *= _DAT_005af908 � scale factor
    - *param_3 = len
- Else (zero vector):
  - Zero output vector at param_2
  - Zero param_3
- FastExitMediaState() � SIMD/media state cleanup

**Globals:**
- _DAT_005af8f0 � SSE constant / zero threshold
- _DAT_005af970 � length squared threshold pointer
- _DAT_005af908 � output length scale factor

**Algorithm family:** 3D vector math, SSE/SIMD

**Calls:** FUN_00529000 (square root approximation, docs/20/21)

**Moddability:** pure utility

<!-- target: docs/20-math-utilities.md -->

## FUN_00527eed — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00527eed
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0052df10 — [PARTIAL] Unknown

Source: unknown | Confidence: low
5 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0052df10
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00534e70 — [PARTIAL] Unknown

Source: unknown | Confidence: low
8 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00534e70
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00536e90 — [PARTIAL] Unknown

Source: unknown | Confidence: low
6 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00536e90
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b110 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0053b110
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_0053cb90 — [PARTIAL] Unknown

Source: unknown | Confidence: low
2 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0053cb90
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0053fc30 — [PARTIAL] Unknown

Source: unknown | Confidence: low
21 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0053fc30
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00541f60 — [PARTIAL] Unknown

Source: unknown | Confidence: low
3 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00541f60
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005435c0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005435c0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00546fe0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
2 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00546fe0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00547860 — [PARTIAL] Unknown

Source: unknown | Confidence: low
4 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00547860
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005491d0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
8 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005491d0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0054b4d0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0054b4d0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0054eb20 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0054eb20
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00550810 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00550810
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00557350 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00557350
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c7b0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0055c7b0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

```
<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_00567010 � File/Stream Cleanup Wrapper

Source: unknown | Confidence: high
Sequential call wrapper for two file/stream cleanup operations.

**Key logic:**
- FUN_00566f40() � stream/file cleanup
- FUN_00566ee0() � stream/file cleanup

**Calls:** FUN_00566f40, FUN_00566ee0

**Moddability:** hookable

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00579fb0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00579fb0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0057ae30 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0057ae30
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005853b0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
3 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005853b0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00587220 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00587220
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005881f0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005881f0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_0058dd3e — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0058dd3e
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_00595304 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x00595304
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0059870c — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0059870c
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_005998c0 — [PARTIAL] Unknown

Source: unknown | Confidence: low
1 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x005998c0
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ba1d — [PARTIAL] Unknown

Source: unknown | Confidence: low
6 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0059ba1d
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c830 — SEH Unwind Handler

Source: unknown | Confidence: high
Structured Exception Handling unwind cleanup handler.

**Key logic:**
- Performs cleanup during C++ exception stack unwinding
- Calls a cleanup/destructor function

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cf2f — SEH Unwind Handler

Source: unknown | Confidence: high
Structured Exception Handling unwind cleanup handler.

**Key logic:**
- Performs cleanup during C++ exception stack unwinding
- Calls a cleanup/destructor function

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d7d1 — [PARTIAL] Unknown

Source: unknown | Confidence: low
16 lines of decompiled code. Needs manual analysis.

**Key logic:**
- Function at 0x0059d7d1
- See decompiled .c file for details

**Used by system:** docs/20-math-utilities.md

**Moddability:** unknown

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059163b -- Math Dispatch with Error Fallback

Source: unknown | Confidence: medium
If DAT_005e9ad0==0: calls FUN_00591bf1; else errno 0x21

**Key logic:**
- If DAT_005e9ad0==0: calls FUN_00591bf1; else errno 0x21

**Calls:**
- FUN_00591bf1, FUN_0058afcf, FUN_00591e66

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593cfd -- SEH-Guarded Function Pointer Call

Source: unknown | Confidence: high
SEH frame; calls PTR_FUN_005e7960 if non-null; finally cleanup

**Key logic:**
- SEH frame; calls PTR_FUN_005e7960 if non-null; finally cleanup

**Calls:**
- PTR_FUN_005e7960, FUN_00593c9c

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00401080 -- Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004010b0()

**Key logic:**
- Calls FUN_004010b0()

**Calls:**
- FUN_004010b0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404d00 -- Array Indexed Pointer Getter

Source: unknown | Confidence: high
Returns (&PTR_PTR_005be6c4)[param_1]

**Key logic:**
- Returns (&PTR_PTR_005be6c4)[param_1]

**Calls:**
- none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00405880 -- Destructor with Conditional Free

Source: unknown | Confidence: high
Calls FUN_004058a0(); if param_2&1: FUN_00587bcf(param_1)

**Key logic:**
- Calls FUN_004058a0(); if param_2&1: FUN_00587bcf(param_1)

**Calls:**
- FUN_004058a0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md.md -->

## FUN_0050dd3a — Thunk via Function Pointer

Source: unknown | Confidence: high
Trampoline — indirect jump through function pointer stored at PTR_FUN_005d782c. No local logic.

**Key logic:**
- Single indirect jump via `(*(code *)PTR_FUN_005d782c)()`
- Address 0x0050dd3a appears as a call target or vtable entry point
- Target function pointer stored at 0x005d782c

**Used by system:** Unknown — indirect call via runtime-resolved function pointer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00552fc0 — Field Setter at +0x48

Source: unknown | Confidence: high
Simple field setter — assigns `param_2` to struct field at offset +0x48. Used by renderer and UI subsystems to configure object properties.

**Key logic:**
- Single operation: `*(undefined4 *)(param_1 + 0x48) = param_2`
- Writes a 4-byte value (int/float/pointer) to field at +0x48

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x48 | unknown | int/float/ptr | Written directly with param_2 |

**Calls:** none (leaf function)

**Used by system:** docs/19-renderer.md — called during texture/font/resource setup; generic setter pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00559760 — UTF-16 String Search in Linked List

Source: unknown | Confidence: high
Searches a linked list for a node whose stored UTF-16 string matches the search key. Returns matching node pointer or null.

**Key logic:**
- Reads first node from `*param_1` (head pointer)
- For each node: compares stored string against `param_2` byte-by-byte in 2-byte (UTF-16) strides
- Comparison returns -1/0/+1 (standard string comparison result)
- If match found (`iVar4 == 0`): returns node pointer (`pbVar2`)
- If no match: follows `next` pointer at node+0x1c
- Returns null if list exhausted

**Struct offsets (linked list node):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | StringData | byte[] | UTF-16 string (2-byte characters, null-terminated) |
| +0x1c | NextPtr | byte* | Next node in linked list |

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — generic UTF-16 string-keyed linked list search

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00564640 — GetTickCount Win32 Stub

Source: kernel32.dll | Confidence: high
Direct import stub wrapping Win32 `GetTickCount()` from kernel32. No local logic.

**Key logic:**
- Single call: `GetTickCount()` (kernel32)
- Returns DWORD millisecond count since system start

**Calls:**
- GetTickCount — Win32 API (kernel32)

**Used by system:** docs/20-math-utilities.md — timing/performance measurement

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00565ed0 — Linked List Node Data Peek

Source: unknown | Confidence: high
Peeks at data from a linked list node. Reads the `next` pointer at inner_struct+8, dereferences it, and returns data+4.

**Key logic:**
- Reads pointer from `**param_1` (indirection: param_1 → struct → first field)
- Checks if struct has a valid next pointer at `*(*param_1 + 8) != NULL`
- Checks if `**(int**)(*param_1 + 8) != 0` (dereferenced next pointer is valid)
- Returns `data + 4` (pointer to payload, skipping header)
- Returns 0 if either check fails

**Struct offsets (list head):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | ListStruct | int* | Inner structure containing list state |
| +0x08 | CurrentOrNext | int** | Pointer to current/first node |

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — generic linked list traversal utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005679c0 — String-Keyed Linked List Search

Source: unknown | Confidence: high
Searches a singly-linked list for a node whose name matches `param_2`. Uses FUN_00499e20 (section entry reader) and FUN_00588410 (string compare).

**Key logic:**
- Reads head node from `*(param_1 + 8)`
- Returns 0 immediately if `param_2 == 0`
- Iterates list: for each node calls FUN_00499e20 (get entry name), then FUN_00588410 to compare against param_2
- Returns matching node pointer on match
- Follows `next` pointer at node+4 if no match
- Returns 0 if list exhausted

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x08 | ListHead | int* | First node in linked list |

**Struct offsets (node):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x04 | NextPtr | int | Next node pointer |

**Calls:**
- FUN_00499e20 — section entry reader / string accessor (docs/19, docs/08)
- FUN_00588410 — string compare (docs/22)

**Used by system:** docs/08-file-formats.md — configuration file section lookup by name

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a070 — String Copy with Bytewise OR Transform

Source: unknown | Confidence: medium
Copies a 9-byte string into buffer, applies bytewise OR transform using second string, then appends second string at offset +0x10.

**Key logic:**
- Copies 9 bytes from `param_2` to `param_1` via `_strncpy` (null-terminated)
- Loops 4 times: ORs each byte of `param_1[0..3]` with corresponding byte of `param_3`
- Copies 4 bytes from `param_3` to `param_1 + 0x10` via `_strncpy`
- Result: `param_1` = `{param_2[0..8] OR-ed with param_3[0..3] (first 4 bytes), param_3[0..3] at +0x10}`

**Calls:**
- _strncpy — CRT string copy with length limit

**Used by system:** docs/20-math-utilities.md — utility for building composite name strings with transformed prefix

**Algorithm family:** string transform / masking

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b530 — Ring Buffer Head/Tail Reset

Source: unknown | Confidence: high
Resets ring buffer head and tail pointers to zero. No other logic.

**Key logic:**
- Sets `*(short*)(param_1 + 0x1000) = 0` (head index)
- Sets `*(short*)(param_1 + 0x1002) = 0` (tail index)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x1000 | RingHead | short | Head index in ring buffer |
| +0x1002 | RingTail | short | Tail index in ring buffer |

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — ring buffer management utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585fb0 — Linked List Cleanup with Sub-Object Delete

Source: unknown | Confidence: high
Walks a linked list, calling release + free on each node's object, then frees each node. Zeros list state after.

**Key logic:**
- Reads list head from `*param_1`
- Walks list via `next` pointer at node[1]:
  - If node[2] flag != 0 AND `*node` (object ptr) != 0:
    - Calls FUN_004b0170 (release/cleanup)
    - Calls FUN_00587bcf (free object memory)
  - Frees node itself via FUN_00587bcf
- Zeros all 4 state fields at param_1[0..3]

**Struct offsets (node):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | ObjectPtr | int* | Sub-object to release and free |
| +0x04 | NextPtr | int* | Next node in list |
| +0x08 | CleanupFlag | byte | Non-zero if cleanup needed |

**Calls:**
- FUN_004b0170 — release/cleanup signal (docs/01)
- FUN_00587bcf — memory free/deallocation

**Used by system:** docs/20-math-utilities.md — generic linked list cleanup utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00586de0 — Bitmask Generation from Bit Array

Source: unknown | Confidence: medium
Generates a compact uint bitmask from a range of bits in a bit array. Reads a range length, iterates bits, and packs non-zero bits into a return mask.

**Key logic:**
- Reads range length from `*(ushort*)(*(param_1+0x1c) + *(param_1+0x44)*4 + 2)` (bit count)
- Base value: `*(ushort*)(*(param_1+0x1c) + *(param_1+0x44)*4)` (starting index)
- Loops `uVar2` times, computing bit index: `((base - 1) + range) - loop_index`
- Checks if bit is set in bit array at `param_1 + 0x14` using `>> 3` (byte index) and `& 1 << (bit & 7)`
- If set: ORs a 1 << (loop_index & 0x1f) into result mask
- Returns final bitmask (up to 32 bits)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x14 | BitArray | byte* | Pointer to bit array data |
| +0x1c | RangeTable | int* | Table of range definitions |
| +0x44 | RangeIndex | int | Index into range table |

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — bit array to mask conversion for state/flag extraction

**Algorithm family:** bit manipulation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058a770 — _longjmp MSVC CRT

Source: MSVC CRT | Confidence: high
MSVC C Runtime `_longjmp` implementation. Restores stack frame and unwinds SEH records.

**Key logic:**
- Reads saved ExceptionList from `_Buf[6]`
- If saved ExceptionList != current: calls `__global_unwind2` (SEH global unwind)
- If saved ExceptionList != null:
  - Checks if C++ exception type 'VC20' at `_Buf[8]` via FUN_00593d53
  - If not C++ exception: calls `__local_unwind2` with saved exception handler
  - If C++ exception: calls destructor callback at `_Buf[9]` if non-null
- Calls FUN_0058893a(0) — finalization
- Indirect jump to saved PC at `_Buf[5]`

**Calls:**
- __global_unwind2 — SEH global unwind
- __local_unwind2 — SEH local unwind
- FUN_00593d53 — C++ exception type check
- FUN_0058893a — CRT finalization

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058c0d0 — String Shift by Offset

Source: unknown | Confidence: high
Shifts a string's content right by `param_2` bytes. Copies the entire string (including null terminator) from its start to `start + param_2`.

**Key logic:**
- If `param_2 != 0`:
  - Gets string length via `_strlen`
  - Calls `FUN_0058b130(dest=param_1+param_2, src=param_1, len=strlen+1)` — memcpy-like shift
- Result: string content moved `param_2` bytes forward, creating space at beginning

**Calls:**
- _strlen — CRT string length
- FUN_0058b130 — memcpy/memmove (docs/06, docs/20)

**Used by system:** docs/20-math-utilities.md — string buffer manipulation utility

**Algorithm family:** string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058df5c — Double Integer and Divisibility Classification

Source: unknown | Confidence: medium
Classifies a double value: checks if it's an integer, and if so, whether it's evenly divisible by a constant.

**Key logic:**
- Calls FUN_0058a8a3 (double classification: NaN/Inf check via mask 0x90)
- If NOT NaN/Inf (mask 0x90 bits not set):
  - Rounds via `__frnd(param_2)` (intrinsic round to nearest integer)
  - If `rounded == param_2` (is integer):
    - Divides by `_DAT_005b8e48` (constant divisor)
    - Rounds result: if `rounded_div == div_result` → returns 2 (evenly divisible)
    - Else returns 1 (integer, but not evenly divisible)
- Returns 0 (not integer, NaN, or Inf)

**Globals:**
- `_DAT_005b8e48` — divisor constant (likely 10 for decimal divisibility test)

**Calls:**
- FUN_0058a8a3 — double NaN/Inf/integer classification
- __frnd — MSVC intrinsic: round to integer

**Used by system:** docs/20-math-utilities.md — numeric classification for formatting/conversion

**Algorithm family:** float classification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00591c79 — Set Error Code Based on Input Range

Source: unknown | Confidence: high
Sets errno to EDOM (33) or ERANGE (34) depending on input value range. CRT domain/range error dispatcher.

**Key logic:**
- If `param_1 == 1`: sets errno = 0x21 (33 = EDOM, domain error)
- If `1 < param_1 < 4`: sets errno = 0x22 (34 = ERANGE, range error)
- Otherwise: no action

**Calls:**
- FUN_0058afcf — errno/error state accessor

**Used by system:** docs/20-math-utilities.md — MSVC CRT math error handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00597359 — Code Pointer Validation (IsBadCodePtr Wrapper)

Source: unknown | Confidence: high
Wraps Win32 `IsBadCodePtr` to validate that a function pointer points to executable code.

**Key logic:**
- Calls `IsBadCodePtr(param_1)` (Win32 API)
- Returns `true` if pointer is valid (IsBadCodePtr returned 0)
- Returns `false` if pointer is invalid

**Calls:**
- IsBadCodePtr — Win32 API (kernel32)

**Used by system:** docs/20-math-utilities.md — code pointer safety check

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a418 — std::_Gninc (Stream Buffer Get Pointer Increment)

Source: MSVC CRT | Confidence: high
MSVC `std::basic_streambuf::_Gninc` implementation. Increments the read/get pointer by 2 (wchar_t) and decrements available count.

**Key logic:**
- Decrements `*(int**)(param_1 + 0x2c)[0]` (get area available count)
- Increments `*(int**)(param_1 + 0x1c)[0]` by 2 (wchar_t get pointer advance)

**Used by system:** docs/20-math-utilities.md — MSVC CRT stream buffer internals

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059abcd — Object Constructor with VTable and String Init

Source: unknown | Confidence: medium
C++ object constructor that sets vtable, copies initialization bytes from stack, zeroes fields, and initializes from a global string constant.

**Key logic:**
- Calls FUN_0058a5d8 (CRT pre-init)
- Sets this[1] = 1
- Sets `*this = &PTR_LAB_005b9d54` (initial vtable)
- Copies bytes from EBP+0x08 (constructor args) to this+5 and this+6
- Zeroes this[2], this[3], this[4]
- Sets SEH handler flag
- Calls FUN_005993af(0) — sub-init
- Gets length of global string DAT_005c406c via _strlen
- Calls FUN_00599615 to init buffer with that string
- Restores ExceptionList
- Sets `*this = &PTR_FUN_005b9d4c` (final vtable)
- Returns constructed object

**Globals:**
- DAT_005c406c — global string constant used for initialization

**Calls:**
- FUN_0058a5d8 — CRT/object pre-initialization
- FUN_005993af — sub-initializer
- FUN_00599615 — buffer init from string

**Used by system:** docs/20-math-utilities.md — C++ object construction pattern

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059c4e6 — SEH Unwind Handler (Free Stack Var at -0x44)

Source: unknown | Confidence: high
SEH unwind handler that frees a stack-allocated object during exception propagation.

**Key logic:**
- Frees `*(void**)(EBP - 0x44)` via FUN_00587bcf
- Called only during stack unwinding after an exception

**Calls:**
- FUN_00587bcf — memory free

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c62a — SEH Unwind Handler (Free Stack Var at +8)

Source: unknown | Confidence: high
SEH unwind handler that frees a stack-allocated object during exception propagation.

**Key logic:**
- Frees `*(void**)(EBP + 8)` via FUN_00587bcf
- Called only during stack unwinding after an exception

**Calls:**
- FUN_00587bcf — memory free

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c750 — SEH Unwind Handler (Free Stack Var at +8)

Source: unknown | Confidence: high
SEH unwind handler that frees a stack-allocated object during exception propagation. Identical to FUN_0059c62a.

**Key logic:**
- Frees `*(void**)(EBP + 8)` via FUN_00587bcf
- Called only during stack unwinding after an exception

**Calls:**
- FUN_00587bcf — memory free

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c8d0 — SEH Unwind Handler (Calls FUN_00583ae0)

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00583ae0 (cleanup/finalize) during exception propagation.

**Key logic:**
- Calls `FUN_00583ae0()` — cleanup/finalization
- No parameters — uses captured stack frame

**Calls:**
- FUN_00583ae0 — cleanup/finalization

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cac0 — SEH Unwind Handler (Free Stack Var at -0x20)

Source: unknown | Confidence: high
SEH unwind handler that frees a stack-allocated object during exception propagation.

**Key logic:**
- Frees `*(void**)(EBP - 0x20)` via FUN_00587bcf

**Calls:** FUN_00587bcf (memory free)

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cc9e — SEH Unwind Handler (Free Stack Var at -0x10)

Source: unknown | Confidence: high
SEH unwind handler that frees a stack-allocated object during exception propagation.

**Key logic:**
- Frees `*(void**)(EBP - 0x10)` via FUN_00587bcf

**Calls:** FUN_00587bcf (memory free)

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ce8c — SEH Unwind Handler (Calls FUN_00581750)

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00581750 (cleanup/rollback) during exception propagation.

**Key logic:**
- Calls `FUN_00581750()` — cleanup/rollback

**Calls:**
- FUN_00581750 — cleanup/rollback function

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cfe8 — SEH Unwind Handler (Calls FUN_00586170)

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00586170 (cleanup/finalize) during exception propagation.

**Key logic:**
- Calls `FUN_00586170()` — cleanup/finalization

**Calls:**
- FUN_00586170 — cleanup/finalization

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d150 — SEH Unwind Handler (Free Stack Var at -0x14)

Source: unknown | Confidence: high
SEH unwind handler that frees a stack-allocated object during exception propagation.

**Key logic:**
- Frees `*(void**)(EBP - 0x14)` via FUN_00587bcf

**Calls:** FUN_00587bcf (memory free)

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d328 — SEH Unwind Handler (Calls FUN_00599796)

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00599796 with a stack variable and a global during exception propagation.

**Key logic:**
- Calls `FUN_00599796(*(void**)(EBP - 0x10), &DAT_008d45a0)` — cleanup with global context

**Globals:**
- DAT_008d45a0 — cleanup context data

**Calls:**
- FUN_00599796 — cleanup/destructor with context

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d52f — SEH Unwind Handler (Calls FUN_0059a5e9)

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_0059a5e9 (cleanup/finalize) during exception propagation.

**Key logic:**
- Calls `FUN_0059a5e9()` — cleanup/finalization

**Calls:**
- FUN_0059a5e9 — cleanup/finalization

**Used by system:** docs/20-math-utilities.md — SEH exception handling infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00401090 — Callback Registration Stub

Source: unknown | Confidence: high
Registers LAB_004010a0 as a callback via FUN_00587b3e.

**Key logic:** Calls `FUN_00587b3e(&LAB_004010a0)`

**Calls:** FUN_00587b3e — callback registration

**Used by system:** docs/20-math-utilities.md — initialization callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404d10 — Field Accessor at +0x20

Source: unknown | Confidence: high
Returns a 4-byte value from indirect struct access: `*(*param_1 + 0x20)`.

**Key logic:** `return *(undefined4*)(*param_1 + 0x20);`

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — generic field getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004058a0 — Object Constructor with VTable and Sub-Free

Source: unknown | Confidence: high
Constructs an object by setting vtable pointers, calling sub-initializers, and freeing a held resource.

**Key logic:**
- Sets `*param_1 = &PTR_FUN_0059e490` (initial vtable)
- Calls FUN_00405b00 (sub-init)
- Calls FUN_00407be0(param_1) (sub-init with context)
- Sets `*param_1 = &PTR_FUN_0059e4b4` (final vtable)
- If param_1[1] != 0: frees via FUN_00587bcf

**Calls:** FUN_00405b00, FUN_00407be0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — two-phase construction pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406b80 — Conditional Destructor

Source: unknown | Confidence: high
Calls cleanup then conditionally frees the object based on a flag bit.

**Key logic:**
- Calls FUN_00406ba0 (cleanup)
- If `param_2 & 1`: calls FUN_00587bcf(param_1) (free object)
- Returns param_1

**Calls:** FUN_00406ba0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — conditional self-destruct pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408210 — Delegation Wrapper to FUN_00408280

Source: unknown | Confidence: high
Thin wrapper delegating to FUN_00408280.

**Key logic:** `FUN_00408280();`

**Calls:** FUN_00408280

**Used by system:** docs/20-math-utilities.md — stub/delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040a890 — Multi-Field Membership Check

Source: unknown | Confidence: medium
Checks if a value matches any of 8 stored fields or appears in a secondary array with stride 200. Returns boolean.

**Key logic:**
- If param_2 == 0: returns 1
- Checks param_2 against fields at +0x10, +0x14, +0x18, +0x1c, +0x24, +0x28, +0x2c, +0x30
- If no match: iterates array starting at +0x20 with stride 200 (0xc8), count from +0x38
- Returns 1 if match found, 0 otherwise

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x10 | Field0 | int | Direct compare target |
| +0x14 | Field1 | int | Direct compare target |
| +0x18 | Field2 | int | Direct compare target |
| +0x1c | Field3 | int | Direct compare target |
| +0x20 | ArrayStart | int | First element of strided array |
| +0x24 | Field4 | int | Direct compare target |
| +0x28 | Field5 | int | Direct compare target |
| +0x2c | Field6 | int | Direct compare target |
| +0x30 | Field7 | int | Direct compare target |
| +0x38 | ArrayCount | int | Element count in strided array |

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — membership/lookup utility

**Moddability:** hardcoded

<!-- target: docs/09-track-system.md -->

## FUN_0040ec70 — Struct Initializer with Float Constants

Source: unknown | Confidence: medium
Initializes a struct with hex-encoded float constants and calls two sub-initializers.

**Key logic:**
- Sets param_1+0x08 = param_2 (short value)
- Sets param_1+0x1c = 5, param_1+0x20 = param_3
- Initializes local float array: {0.0, 1.0, 0.0, 0.5, 0.0, 1.5} (IEEE754 hex)
- Calls FUN_00459950(0, 2.5f, &locals) — init with threshold
- Calls FUN_00459990(0, 5.375f, 0, 3.21875f, 2.0f, 1.775f) — multi-param init
- If param_4 != 0: calls FUN_0040e770(param_4, 0)

**Calls:**
- FUN_00459950 — float parameter init
- FUN_00459990 — multi-parameter init
- FUN_0040e770 — conditional init

**Used by system:** docs/20-math-utilities.md — object initialization with preset floats

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00410b60 — Delegation Wrapper to FUN_0040ed10

Source: unknown | Confidence: high
Thin wrapper delegating to FUN_0040ed10.

**Key logic:** `FUN_0040ed10();`

**Calls:** FUN_0040ed10

**Used by system:** docs/20-math-utilities.md — stub/delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00414200 — Callback Registration (FUN_00414210)

Source: unknown | Confidence: high
Registers FUN_00414210 as a callback via FUN_00587b3e.

**Key logic:** `FUN_00587b3e(FUN_00414210);`

**Calls:** FUN_00587b3e — callback registration

**Used by system:** docs/20-math-utilities.md — initialization callback registration

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0041e840 — Nested Data Section Field Accessor

Source: unknown | Confidence: medium
Navigates 3-level data hierarchy (section → entry → sub-entry) using FUN_004c2850 and FUN_004c1390. Returns field at +0x198 from final entry.

**Key logic:**
- Calls FUN_004c2850 (set current section)
- If success: calls FUN_004c1390 (get entry count/access)
- If success: calls FUN_004c2850 again (sub-section)
- If success: calls FUN_004c1390 again
- Returns `*(undefined4*)(entry + 0x198)` or 0 on failure

**Calls:**
- FUN_004c2850 — section setter (data file section access)
- FUN_004c1390 — entry getter

**Used by system:** docs/20-math-utilities.md — structured data file field access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421480 — Callback Registration (LAB_00421490)

Source: unknown | Confidence: high
Registers LAB_00421490 as a callback via FUN_00587b3e.

**Key logic:** `FUN_00587b3e(&LAB_00421490);`

**Calls:** FUN_00587b3e — callback registration

**Used by system:** docs/20-math-utilities.md — initialization callback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421ad0 — Path Registration Wrapper

Source: unknown | Confidence: high
Calls sub-init then registers a path in the global path registry.

**Key logic:**
- Calls FUN_00421890(param_1) — sub-init
- Calls FUN_00566650(param_1) — path registry registration

**Calls:**
- FUN_00421890 — sub-initialization
- FUN_00566650 — path registry (docs/08, docs/19)

**Used by system:** docs/20-math-utilities.md — path registration utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00426cc0 — Speed Delta Computation

Source: unknown | Confidence: medium
Computes relative speed between two vehicles/objects. Uses AI overtaking flag to select comparison target.

**Key logic:**
- Loads default value from _DAT_0059e670
- If `param_2 == 0`: returns DAT_0059e440 (ZeroThreshold, ~0.0f)
- If AIStateFlags at param_1+0x4354 non-zero (AI overtaking zone active):
  - Computes `speed(param_2+0x4c) - speed(following_vehicle+0x4c)`
  - Following vehicle pointer stored at param_1+0x4354
- Returns delta (positive = param_2 faster)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x4354 | AIStateFlags | int | Non-zero when AI in overtaking zone (docs/13) |
| +0x4354 | AIFollowTarget | int* | Pointer to followed vehicle when AIStateFlags set (docs/15) |

**Struct offsets (vehicle speed field):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x4c | Speed | float | Vehicle speed magnitude |

**Globals:**
- _DAT_0059e670 — default speed delta constant
- DAT_0059e440 — ZeroThreshold (~0.0f, physics clamp)

**Calls:** none (leaf function)

**Used by system:** docs/02-ai-system.md — AI relative speed calculation for overtaking logic

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00456040 — Double Field Getter at +0x30/+0x34

Source: unknown | Confidence: high
Returns two 4-byte values from struct fields at +0x30 and +0x34 via output params.

**Key logic:** If param_2 non-null: `*param_2 = *(param_1+0x30)`. If param_3 non-null: `*param_3 = *(param_1+0x34)`.

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004582a0 — Strided Array Element Pointer

Source: unknown | Confidence: high
Returns pointer to element at index `param_2` in array with stride 0x1c (28 bytes). Bounds-checked.

**Key logic:** If 0 <= param_2 < param_1[1]: returns param_1[0] + param_2 * 0x1c. Else returns 0.

**Calls:** none

**Used by system:** docs/20-math-utilities.md — array index getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045ba60 — String Matching with Case-Sensitive/Case-Insensitive Modes

Source: unknown | Confidence: medium
Iterates 8 entries (stride 0x5c) at param_1+0x3c. For each, compares against param_2 string either via bytewise compare (param_3==0, UTF-16) or FUN_00566810 (param_3!=0, case-insensitive). Calls FUN_0045b430(index) on match.

**Key logic:**
- If param_2 non-null: 8 iterations checking entries at param_1+0x3c with stride 0x5c
- param_3==0: UTF-16 bytewise string compare
- param_3!=0: case-insensitive compare via FUN_00566810
- On match: calls FUN_0045b430(entry_index)

**Calls:** FUN_00566810, FUN_0045b430

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045c3c0 — Two-Byte Field Setter

Source: unknown | Confidence: high
Sets two consecutive byte fields.

**Key logic:** `*param_1 = param_2; param_1[1] = param_3;`

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045e590 — Buffer Fill with 0xFFFFFFFF

Source: unknown | Confidence: high
Fills 0x68 (104) dwords at param_1+0x1d4 with 0xFFFFFFFF (-1). Array/state reset.

**Key logic:** Loop 0x68 times writing 0xFFFFFFFF to consecutive dwords starting at param_1+0x1d4.

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004615f0 — Bit Flag Test at +0x6E

Source: unknown | Confidence: high
Tests if a specific bit is set in byte at param_1+0x6e. Bit index from param_2.

**Key logic:** Returns `(*(byte*)(param_1+0x6e) & (1 << (param_2 & 0x1f))) != 0`

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462410 — Struct Array Copy at Stride 0x8C

Source: unknown | Confidence: medium
Copies 0x23 (35) dwords from array at base+0x394 indexed by param_2 (stride 0x8C). Also reads a dword from base+0x3C74 at same index.

**Key logic:** If valid index: copies 35 dwords (stride 0x8C) starting at *(param_1)+0x394+param_2*0x8C to param_3. Sets *param_4 from *(param_1)+0x3C74+param_2*4. Returns 1. Else returns 0.

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463dc0 — Conditional Stride Pointer Computation

Source: unknown | Confidence: medium
If FUN_005001f0 returns true: returns `*param_1 + 0x4188 + param_2 * 0x368`. Else returns 0.

**Calls:** FUN_005001f0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464bd0 — Float Field Decrement with Clamp

Source: unknown | Confidence: high
Subtracts param_2 from float at param_1+0x68. Clamps to >=0. If result < param_2, sets to param_2 instead.

**Key logic:** var = *(param_1+0x68); var -= param_2; if var < 0: var=0; else if param_2 < var: var=param_2.

**Globals:** DAT_0059e440 (ZeroThreshold)

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004661b0 — Game Object Update Frame

Source: unknown | Confidence: medium
Multi-step update function: resets timer if param_1[0x3a] set, decrements counter by delta from FUN_00498730, triggers vtable callbacks, checks state flags, calls FUN_00466350 and FUN_00466650.

**Key logic:**
- If param_1[0x3a] != 0: FUN_00496750(param_1, 0)
- If DAT_0059e440 <= param_1[0x49]: decrements by delta, triggers FUN_004988a0(1) + vtable+0xac if below zero
- If flags at param_1[0x3d] or param_1+0xf5 set: FUN_00466350()
- Calls FUN_00466650()
- Calls vtable+0x2c(1) and vtable+0xa8()

**Calls:** FUN_00496750, FUN_00498730, FUN_004988a0, FUN_00466350, FUN_00466650

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004685f0 — Conditional Destructor with Cleanup

Source: unknown | Confidence: high
Calls FUN_00468610 cleanup. If param_2 & 1: frees param_1 via FUN_00587bcf. Returns param_1.

**Calls:** FUN_00468610, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046b5e0 — VTable Set and Init

Source: unknown | Confidence: high
Sets vtable to PTR_FUN_0059fa98 and calls FUN_00489440.

**Calls:** FUN_00489440

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046e5c0 — Init with Stack Buffer

Source: unknown | Confidence: medium
Calls FUN_0046e600(0x100) then FUN_00433ed0 with a 256-byte stack buffer and param 1.

**Calls:** FUN_0046e600, FUN_00433ed0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00470250 — Conditional Destructor

Source: unknown | Confidence: high
Calls FUN_0048b4e0. If param_2 & 1: frees param_1 via FUN_00587bcf. Returns param_1.

**Calls:** FUN_0048b4e0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00471b20 — UI Object Constructor with Defaults

Source: unknown | Confidence: medium
Constructor for UI object. Sets vtable PTR_FUN_005a1680, configures scrolling/selection params (values 2, 0, 1, 1, 0xf7). Registers 3 global callbacks with -1.

**Key logic:**
- FUN_00466d60(1)
- Sets vtable, param_1[199]=DAT_007ce6f4, param_1[0xc9..0xcd]={2,0,1,1,0xf7}
- FUN_00486f30 on PTR_DAT_005be704, PTR_DAT_005c32a4, DAT_005c32a8 with -1
- FUN_004670e0()

**Calls:** FUN_00466d60, FUN_00486f30 (×3), FUN_004670e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473dd0 — UI Object Constructor (Variant)

Source: unknown | Confidence: medium
Similar to FUN_00471b20 but different vtable (PTR_FUN_005a3180), DAT_007cfbd8 reference, and values {1, 0, 1, 1, 0x17f}.

**Calls:** FUN_00466d60, FUN_00486f30 (×3), FUN_004670e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00475530 — State Reset and Conditional Init

Source: unknown | Confidence: medium
Resets DAT_007cd850=0. Calls FUN_00475150. If global conditions met (DAT_007d0e74==0, DAT_007d0fac!=0, param_1+0x17c==0): calls FUN_00461de0, sets flag at +0x17c=1.

**Globals:** DAT_007cd850, DAT_007d0e74, DAT_007d0fac

**Calls:** FUN_00475150, FUN_00461de0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00477ea0 — UI Object Constructor

Source: unknown | Confidence: medium
Constructor: calls FUN_00488180, FUN_00499b10. Sets defaults: param_1[0x57]=-1, [0x56]=0, [0x47]=-1, [0x48]=-1. Sets vtable PTR_FUN_005a46b0.

**Calls:** FUN_00488180, FUN_00499b10

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478e10 — UI Object Constructor (Extended)

Source: unknown | Confidence: medium
Constructor: calls FUN_00488180, FUN_00499b10. Sets vtable PTR_LAB_005a4a20. Configures fields at [0x57..0x5c, 0x54], sets [0x46]=0x94.

**Calls:** FUN_00488180, FUN_00499b10

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004799a0 — Object Constructor with Float Params

Source: unknown | Confidence: medium
Calls FUN_00466980 with hex floats 0x455ac000 (5592.0) and 0x4633b000 (11544.0). Sets vtable PTR_FUN_005a5710. Sets byte at param_1+0x3c=1.

**Calls:** FUN_00466980

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a230 — Conditional Destructor with VTable

Source: unknown | Confidence: high
Sets vtable PTR_FUN_005a6068. Calls FUN_0048d3e0. If param_2 & 1: frees param_1. Returns param_1.

**Calls:** FUN_0048d3e0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047BE00 � Menu Scroll Position Calculator with Clamp

Source: unknown | Confidence: high
Computes weighted average scroll position from menu cursor count and two state fields. Clamps result to valid range.

**Key logic:**
- iVar2 = FUN_0047bc90() - 1 � cursor count from end minus 1 (docs/19)
- al = *(param_1 + 0x114) � divisor/capacity
- weight = *(param_1 + 0x110) � weight factor
- If al == 0: sets position at +0xec = 0
- Else: pos = (val/2 + weight * iVar2) / val � weighted average centered on val/2
- Clamps pos to [0, iVar2] (0 to count-2)
- If iVar2 < val (i.e. count - 1 < val, meaning count <= val): calls FUN_0047bd90() � menu scroll apply/refresh (docs/20)

**Struct offsets (param_1):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xec | int | ScrollPosition | computed result, clamped to [0, count-2] |
| +0x110 | int | ScrollWeight | weighting factor |
| +0x114 | int | ScrollCapacity | divisor, max items threshold |

**Calls:** FUN_0047bc90 (menu cursor count from end, docs/19), FUN_0047bd90 (menu scroll apply, docs/20)

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0047f180 — Doubly-Linked List Append

Source: unknown | Confidence: high
Allocates 16-byte node, stores param_2 pointer and param_3 flag. Appends to doubly-linked list. Returns 1 on success, 0 on failure.

**Key logic:**
- Allocates node via operator_new(0x10): fields = {param_2, next=0, prev=0, flag=param_3}
- If list empty (*param_1==0): sets head=tail=node, increments count
- Else: appends after tail (param_1[1]), updates tail, increments count

**Calls:** operator_new

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485720 — Conditional Constructor/Destructor

Source: unknown | Confidence: high
Sets vtable PTR_FUN_005a9448. Calls FUN_00499b50, FUN_00485eb0. If param_2 & 1: frees param_1. Returns param_1.

**Calls:** FUN_00499b50, FUN_00485eb0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486460 — Conditional Delegation

Source: unknown | Confidence: medium
If *(param_1+200) != 0: returns FUN_0049a150(). Else returns 0.

**Calls:** FUN_0049a150

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487220 — Constructor with Byte Params

Source: unknown | Confidence: medium
Calls FUN_00485e30. Sets *(param_1+0x38)=param_2, vtable=PTR_FUN_005ab968, *(param_1+0xe1)=param_3.

**Calls:** FUN_00485e30

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487e70 — Multi-Stage VTable Dispatch

Source: unknown | Confidence: medium
Calls FUN_00498880 for locals. Calls FUN_004874e0. If OK: dispatches vtable+0x30, then vtable+0x9c. If vtable+0x9c returns 0: calls FUN_00486630, returns 0. Else returns -1.

**Calls:** FUN_00498880, FUN_004874e0, FUN_00486630

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489450 — Linked List Traversal by Index

Source: unknown | Confidence: high
Walks a singly-linked list from param_1+0x90. Traverses `next` at +0x8C. Returns pointer at index stored in param_1+0x168.

**Key logic:** Start at *(param_1+0x90). Walk `next` (+0x8C) for `*(param_1+0x168)` steps (if >=0). Return node or 0.

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b810 — Edit Buffer String Update

Source: unknown | Confidence: medium
Checks if new string matches current via UTF-16 compare. If match: returns -1. Else copies new string into buffer at param_1[0xbc] (length from param_1[0xbe]), strips non-display chars via FUN_0048b560, updates cursor at param_1[0xbd], dispatches vtable+0x2c(1).

**Calls:** FUN_0048b560, _strncpy

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d230 — Linked List Destruction with VTable Call

Source: unknown | Confidence: high
Walks linked list at param_1+0x31c. For each node: checks flag at node[3], if set calls vtable[0](1) destructor. Frees nodes via FUN_00587bcf. Zeros 10 fields, sets +0x33c=1.

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e5c0 — Conditional Geometry/Display Update

Source: unknown | Confidence: medium
If vtable+0xa0 returns 0: reads param_1[0x3a..0x3d] and dispatches to FUN_00490920 and FUN_004918d0.

**Calls:** FUN_00490920, FUN_004918d0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fc50 — UI Object Constructor

Source: unknown | Confidence: medium
Calls FUN_0048e9e0. Sets param_1[0xc]=0, [0xd]=-1, [0xe]=0. Vtable=PTR_FUN_005a4450.

**Calls:** FUN_0048e9e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490640 — VTable Dispatch + Init

Source: unknown | Confidence: medium
Dispatches vtable+0x40 with arg 0. Calls FUN_00490660.

**Calls:** FUN_00490660

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491740 — Conditional Destructor

Source: unknown | Confidence: high
If *param_1 != 0: calls FUN_00490b90, then FUN_00587bcf(*param_1).

**Calls:** FUN_00490b90, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491ee0 — File Open Wrapper with Mode Check

Source: unknown | Confidence: medium
Opens file via FUN_00534b00. If mode flag at param_1+0x19a set: calls FUN_00587db0 with second file. If both fail: clears flag. If first file opened: calls FUN_00535390(0). If mode flag set: calls FUN_00587f64(seek).

**Calls:** FUN_00534b00, FUN_00587db0, FUN_00535390, FUN_00587f64

**Used by system:** docs/08-file-formats.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495110 — Global Getter

Source: unknown | Confidence: high
Returns global value DAT_008b8dc8.

**Key logic:** `return DAT_008b8dc8;`

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00496280 — Float Array Init with Random

Source: unknown | Confidence: medium
Fills 16 floats at param_1+0x162c with values from FUN_005881f0 (random/noise).

**Key logic:** Loop 0x10 times: pfVar2[i] = (float)FUN_005881f0()

**Calls:** FUN_005881f0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497940 — Lookup Dispatch

Source: unknown | Confidence: medium
If param_1!=0: calls FUN_004976c0(param_1). If result non-null: calls FUN_00497890(result, param_2). Returns result or 0.

**Calls:** FUN_004976c0, FUN_00497890

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498d00 — Path Register + Field Set

Source: unknown | Confidence: high
Registers param_2 via FUN_00566650 (path registry). Sets param_1+0x44 = param_3.

**Calls:** FUN_00566650

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499260 — Conditional Destructor

Source: unknown | Confidence: high
Calls FUN_00499280. If param_2 & 1: frees param_1 via FUN_00587bcf. Returns param_1.

**Calls:** FUN_00499280, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499a20 — Float Field Decrement

Source: unknown | Confidence: high
Subtracts param_2 from float at param_1+0x08.

**Key logic:** `*(float*)(param_1 + 8) -= param_2;`

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499e40 — Path Registry Wrapper

Source: unknown | Confidence: high
Calls FUN_00566650 with no args (or uses implicit arg from calling convention).

**Calls:** FUN_00566650

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a2f0 — Multi-List Destruction (26 Lists)

Source: unknown | Confidence: high
Destroys 26 linked lists (0x1a iterations). Each list walks nodes via next at +0x18. Calls FUN_0049a270 then FUN_00587bcf per node. Zeros each list head.

**Calls:** FUN_0049a270, FUN_00587bcf (×N)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ae40 — Indexed List Entry Write

Source: unknown | Confidence: medium
If param_1 matches FUN_0049adb0 result: redirects through FUN_0049adc0. Else walks linked list to index param_1, writes param_2 and param_3 as short at entry address. Returns entry address with bit 0 set.

**Calls:** FUN_0049adb0, FUN_0049adc0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049da60 — Timestamped Render/String Update

Source: unknown | Confidence: medium
Reads globals DAT_005ccbc0, DAT_007ce238, DAT_005ccbb8, DAT_005ccbbc. Calls FUN_0049e410. If param_1+8 non-null: formats and renders string via FUN_0049c8f0/FUN_0049c960 and FUN_0049f6a0 (once for primary, once for secondary).

**Globals:** DAT_005ccbc0, DAT_007ce238, DAT_005ccbb8, DAT_005ccbbc

**Calls:** FUN_0049e410, FUN_0049c8f0, FUN_0049f6a0 (×2), FUN_0049c960

**Used by system:** docs/20-math-utilities.md — HUD/timestamp overlay

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049f6a0 — String Format and Render

Source: unknown | Confidence: medium
If all params non-null: handles mode dispatch (1=special format via FUN_0049f710, 2=alt via FUN_0049f750). Calls FUN_00553070 to render.

**Calls:** FUN_0049f710, FUN_0049f750, FUN_00553070

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0df0 — Session State Dispatch

Source: unknown | Confidence: medium
Dispatches based on FUN_00461cd0 result (session state). State 3: calls DAT_007cd8c0+0x1c(0x24). State 2: calls +0x1c(0x23). On success: calls FUN_004896c0, FUN_00489ab0, FUN_004c8de0.

**Globals:** DAT_007cd8c0

**Calls:** FUN_00461cd0, FUN_004896c0, FUN_00489ab0, FUN_004c8de0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1fd0 — Range Proportion Initializer

Source: unknown | Confidence: high
Sets two floats (min/max) and computes inverse range. If range > 0: stores 1/range. Else stores 0.

**Key logic:** `*param_1=min; param_1[1]=max;` if `max-min > 0`: `param_1[2] = _DAT_0059e43c / (max-min)` else 0.

**Globals:** DAT_0059e440, _DAT_0059e43c

**Calls:** none

**Used by system:** docs/20-math-utilities.md — range mapping/normalization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a4030 — State Setter with Conditional Call

Source: unknown | Confidence: medium
Sets *(param_1+0x78)=2. If *(param_1+100)!=0: calls FUN_0054c030(1,1,1,0).

**Calls:** FUN_0054c030

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a8af0 — VTable Init with Defaults

Source: unknown | Confidence: high
Sets 6 fields to alternating 0/-1 pattern and vtable PTR_LAB_005acbf0.

**Key logic:** param_1[1..6] = {0,-1,0,-1,0,-1}, *param_1 = &PTR_LAB_005acbf0

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1a30 — VTable Init with Defaults (Shorter)

Source: unknown | Confidence: high
Sets 4 fields to alternating 0/-1 pattern and vtable PTR_LAB_005acc50.

**Key logic:** param_1[1..4] = {0,-1,0,-1}, *param_1 = &PTR_LAB_005acc50

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2580 — Short Vector to Float with Scale

Source: unknown | Confidence: high
Converts 3 shorts at param_1+0x1e, +0x20, +0x22 to floats scaled by _DAT_0059e6ec.

**Key logic:** param_2[i] = (float)(short)(param_1+0x1e+i*2) * _DAT_0059e6ec for i=0..2

**Globals:** _DAT_0059e6ec — scale factor

**Calls:** none

**Used by system:** docs/20-math-utilities.md — short-to-float vector conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2b40 — Bitfield Extraction with Scale

Source: unknown | Confidence: medium
Extracts 2 bits from uint at param_1+0x30 at position 22-23 (bits 22-23), scales by _DAT_0059e98c.

**Key logic:** `return (float10)((*(uint*)(param_1+0x30) >> 0x16) & 3) * _DAT_0059e98c;`

**Globals:** _DAT_0059e98c — scale factor

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b42e0 — Binary Data Reader

Source: unknown | Confidence: medium
Reads 4 bytes via FUN_00566bd0. Parses header: checks magic (0x20000000 mask) and flags. If matches: reads 1 byte via __ftol conversion. Then reads data chunk of size from header.

**Calls:** FUN_00566bd0 (×3), __ftol

**Used by system:** docs/20-math-utilities.md — binary format reader

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b52a0 — List Rebuild with Node Transfer

Source: unknown | Confidence: medium
Complex list management: removes nodes matching a value from one list, transfers them to another. Frees removed sub-objects via FUN_004b0170+FUN_00587bcf. Allocates new 12-byte nodes.

**Calls:** FUN_004b0170, FUN_00587bcf, operator_new

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9c80 — Range Width Getter

Source: unknown | Confidence: medium
Gets two float bounds via FUN_004b87a0, returns difference (max-min).

**Calls:** FUN_004b87a0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba7a0 — Doubly-Linked List Node Removal

Source: unknown | Confidence: high
Searches doubly-linked list for node matching param_2. Removes it, updates head/tail/count. Optionally clears flag. Frees sub-object if flag set. Frees node.

**Calls:** FUN_004b0170, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb150 — List Append with Sub-List Generation

Source: unknown | Confidence: medium
Appends a node to primary list. Then generates sub-list of 32 (or 0x20+flag*0x20) entries from param_2 value with stride 0xc.

**Calls:** operator_new (×N)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bc2f0 — Conditional Field Setter

Source: unknown | Confidence: high
If param_1[0xb] != param_2: calls FUN_00419120 with old/new values, updates field.

**Calls:** FUN_00419120

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004be180 — Nested Loop Call (8×8+1)

Source: unknown | Confidence: medium
Calls FUN_004bd970(param_1) 65 times: nested loop 8×8 plus one extra.

**Calls:** FUN_004bd970

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2300 — Dual-List Destruction with Deep Cleanup

Source: unknown | Confidence: high
Destroys two linked lists (primary at param_1[0], secondary at param_1[4]). For secondary: frees 3-level deep objects. Zeros 36 fields. Sets flag at +0x1b=1. Restores from DAT_007d0a24.

**Globals:** DAT_007d0a24

**Calls:** FUN_004c0b10, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2fa0 — Delegation Wrapper

Source: unknown | Confidence: high
Thin wrapper delegating to FUN_004b3db0.

**Calls:** FUN_004b3db0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c6760 — Bounds-Checked Index Setter

Source: unknown | Confidence: high
If 0 <= param_2 < *(param_1+0x14): sets *(param_1+0x18)=param_2.

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8560 — Lazy Audio/Resource Init

Source: unknown | Confidence: medium
If DAT_008ac4c4 non-null and DAT_008ac4cc==0: calls vtable+0x60 to initialize, stores in DAT_008ac4cc.

**Globals:** DAT_008ac4c4, DAT_008ac4cc

**Calls:** (vtable+0x60)

**Used by system:** docs/19-renderer.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c91d0 — Triple VTable Destructor Release

Source: unknown | Confidence: high
Releases 3 interface pointers at param_1+0x20, +0x24, +0x28 via vtable[0](1), zeros each.

**Calls:** (vtable[0]) on 3 interfaces

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ca430 — Float Struct Initializer

Source: unknown | Confidence: medium
Sets 14 float fields with hex constants (1.0, 1.0, 1.0, 0, 0, 0, 0, 0, 0, 10.0, 3.0, 3.0, 3.0, 0.25, 16.0, 0).

**Hex values:** +0x0c=0x3f800000(1.0), +0x10=1.0, +0x14=1.0, +0x18..+0x30=0, +0x30=0x41200000(10.0), +0x34=0x40400000(3.0), +0x38=3.0, +0x3c=3.0, +0x44=0x3e800000(0.25), +0x48=0x41800000(16.0), +0x4c=0

**Calls:** none

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004cefe0 — Strided Array Search and Call

Source: unknown | Confidence: medium
Searches array at param_1+0x14 (stride 0x6c) for entry matching param_2 at +4. If found: calls FUN_004cd8d0(param_3).

**Calls:** FUN_004cd8d0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d4790 — Delegation Wrapper

Source: unknown | Confidence: high
Calls FUN_00587d02(param_1).

**Calls:** FUN_00587d02

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5c70 — Quaternion/Transform Computation

Source: unknown | Confidence: medium
Complex math function computing quaternion or transform from 3 double params. Clamps param_2 to _DAT_0059e430 range. Builds local matrices with IEEE754 constants (1.0, etc.), computes square and cube terms. Falls back to identity if FUN_005677b0 returns non-zero.

**Globals:** _DAT_0059e430, _DAT_0059e420, _DAT_0059e7e0

**Calls:** FUN_005677b0

**Used by system:** docs/20-math-utilities.md — physics math / quaternion

**Algorithm family:** quaternion / rotation math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7e00 — VTable Dispatch Chain

Source: unknown | Confidence: medium
Calls vtable+0x18. If non-zero: calls FUN_004d7fe0. If param_1[2] flag set: calls FUN_004d7ff0. Then calls vtable+0x04 (indirect jump).

**Calls:** FUN_004d7fe0, FUN_004d7ff0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004d9030 — Audio Resource Release by Type

Source: unknown | Medium. Releases audio resources indexed by param_1 (1-5). Selects from DAT_008ad398..008ad3a8. Frees via FUN_005539f0. Special case param_1==3: extra cleanup via FUN_005502c0 + FUN_00557470 + FUN_00587bcf. **Calls:** FUN_005539f0, FUN_005502c0, FUN_00557470, FUN_00587bcf. **Used by system:** docs/21-audio-network-internals.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004dbc90 — Multi-Layer Text/String Renderer

Source: unknown | Medium. Renders 7 text layers with different colors and display modes using FUN_004d7e40. Colors: 0xffff00 (yellow), 0xffffff (white). Modes: 0/1/2. Renders string at param_1+0x32 (length 0x2e) then param_1+0xf5 (length 10 then 0x32 then 0x5a). Uses FUN_0049c6d0/bb40/bbb0/bcd0/bd40/c0b0 for buffer management. **Calls:** FUN_0049c6d0, FUN_004d7e40 (x6), FUN_0049bb40, FUN_0049bbb0, FUN_0049bcd0, FUN_0049bd40, FUN_0049c0b0. **Used by system:** docs/19-renderer.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcc90 — Float-to-Int Conversion Delegation

Source: unknown | Medium. Calls __ftol 5 times to convert float args to ints, then delegates to FUN_004dcba0. **Calls:** __ftol (x5), FUN_004dcba0. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd550 — Bounding Box Computation (Min/Max)

Source: unknown | Medium. Computes min/max bounding box across scene objects. Initializes min=FLT_MAX, max=-FLT_MAX. Iterates render entries via FUN_0054c210/FUN_0054c230, checks flags for visibility category, then iterates sub-elements via FUN_0054e100/FUN_0054e120, updating min/max per component (x,y,z). **Globals:** DAT_0059e440. **Calls:** FUN_004dd4e0, FUN_0054c210, FUN_0054c230, FUN_0054e100, FUN_0054e120. **Used by system:** docs/19-renderer.md. **Algorithm family:** bounding volume computation. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004e0d70 — Conditional Resource Release

Source: unknown | Medium. If *param_1 != 0 and flag at param_1[0x10] set: calls FUN_0054baa0, clears flag, calls FUN_0054c030(1,1,1,0). **Calls:** FUN_0054baa0, FUN_0054c030. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004ec020 — 3D Vector Addition

Source: unknown | High. Adds two 3D vectors component-wise. dst[i] = src[i] + dst[i] for i=0..2. **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Algorithm family:** 3D vector math. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004f6af0 — Callback Registration Stub

Source: unknown | High. Registers LAB_004f6b00 via FUN_00587b3e. **Calls:** FUN_00587b3e. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8c70 — Global Callback Dispatcher

Source: unknown | High. If DAT_008afc88 non-null: calls it with param_1, returns 0. Else returns 4. **Globals:** DAT_008afc88. **Calls:** (indirect via DAT_008afc88). **Used by system:** docs/20-math-utilities.md. **Moddability:** hookable.

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9b30 — State Flag Computation

Source: unknown | Medium. Computes flags: base=2-(FUN_004f9b20()!=0). If param_1!=0 or DAT_007ce254!=0: ORs with 4. Calls FUN_0055c060(flags). If result==-2: sets DAT_008afe72=1. **Globals:** DAT_007ce254, DAT_008afe72. **Calls:** FUN_004f9b20, FUN_0055c060. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004fc9a0 — Float Array Initializer (20/0.3 pattern)

Source: unknown | High. Sets 4 floats: {0, 20.0f (0x41a00000), 0.3f (0x3e99999a), 0}. **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005001f0 — Float Comparison Check

Source: unknown | High. Returns 1 if float at param_1+0xc != _DAT_005ad34c, else 0. **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00502bf4 — Dual VTable Destructor

Source: unknown | High. Releases two interface pointers: if param_1[1]!=0: vtable[0](1). If *param_1!=0: vtable[0](1). **Calls:** (vtable[0]) on two interfaces. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00504640 — Memory Allocation with Vector Constructor

Source: unknown | Medium. Allocates memory block (size from struct fields), constructs objects via _vector_constructor_iterator_ with LAB_005007ec callback, then iterates 2D array calling vtable+4 and vtable+8 per element. Frees via FUN_00587bcf. Returns HRESULT (0 or 0x80004005). Uses SEH. **Calls:** FUN_0058a5d8, operator_new, _vector_constructor_iterator_, FUN_00587bcf. **Used by system:** docs/19-renderer.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0050ae22 — Constructor with VTable + Sub-Init

Source: unknown | High. Calls FUN_00507496(param_2, 0x10, 1). Sets vtable = PTR_FUN_005adc4c. **Calls:** FUN_00507496. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b446 — Constructor with VTable + Sub-Init (Variant)

Source: unknown | High. Calls FUN_00507496(param_2, 0x10, 1). Sets vtable = PTR_FUN_005add7c. **Calls:** FUN_00507496. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c15e — Hermite/Cubic Spline Interpolation

Source: unknown | Medium. Computes cubic Hermite spline interpolation at parameter param_6. Uses precomputed basis functions with constants _DAT_0059e800, _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e46c. Evaluates position from 4 control points (param_2..param_5) at parameter t, scales by _DAT_0059e450. Outputs 2D result (x,y). **Globals:** _DAT_0059e450, _DAT_0059e800, _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e46c. **Calls:** none (leaf function). **Used by system:** docs/20-math-utilities.md. **Algorithm family:** spline/bezier interpolation. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d4d9 — Delegation Wrapper with Pre-Call

Source: unknown | Medium. Calls FUN_0050fea7(1). Then calls through PTR_FUN_005d7830 with 4 params. **Calls:** FUN_0050fea7, (indirect via PTR_FUN_005d7830). **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e04f — Indirect Jump Thunk

Source: unknown | High. Indirect jump through _DAT_005d78a4. No local logic. **Calls:** (indirect via _DAT_005d78a4). **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0050f86a — State Machine Dispatch

Source: unknown | Medium. State machine with states: 200, 0xc9, 0xca, 0xd0-0xd1, 0xd2. State transitions via vtable dispatches. State 200 -> sets to 0xc9. State 0xc9 -> calls vtable[99], transitions to 0xca on success. State 0xca -> returns 1. State 0xd0-0xd1 or 0xd2 -> calls vtable[99]. Default: sets error code, calls vtable[0]. **Calls:** (vtable dispatches), FUN_0050f6f7. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0051184f — Triple Field Setter

Source: unknown | High. Sets *(param_1+0x40)=param_3, *(param_1+0x44)=param_4, *(param_1+0x48)=param_2. **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005125c9 — Bit Packing/Unpacking (1/2/4-bit)

Source: unknown | Medium. Unpacks bits from a byte buffer into individual values. Supports 1-bit, 2-bit, and 4-bit fields. Reads byte at param_1+9 for bit width (1/2/4). Processes `*param_1` elements from param_2 buffer. Sets byte at param_1+9 to 8, computes buffer size. **Calls:** none (leaf function). **Used by system:** docs/20-math-utilities.md. **Algorithm family:** bit manipulation/packing. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00515303 — Quantization/Color Space Conversion

Source: unknown | Medium. Processes 16 elements (0x10) from param_2+0xc. Accumulates in local_54 float array. Applies quantization: ROUND(value * _DAT_0059e8d8 + 0.5f). Packs result bits into param_1 uint array. Applies error diffusion (neighbors at +1, +3, +4, +5). Calls FUN_005147ea for finalization. **Globals:** _DAT_0059e8d8, _DAT_0059e450, _DAT_005adb14, _DAT_005ac108, _DAT_005af63c, _DAT_005af638, _DAT_005af634, _DAT_0059e9e0. **Calls:** FUN_00513e5d, FUN_005147ea. **Used by system:** docs/20-math-utilities.md. **Algorithm family:** image/color quantization with error diffusion. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00516531 — Ring Buffer Write with Bounds Check

Source: unknown | Medium. Writes to ring/circular buffer. Validates bounds against buffer[6] (start offset) and buffer[4] (capacity). Calls error handler via vtable if invalid. Updates write cursor at buffer[7]. Optionally copies data via FUN_005159a8 if flag buffer[8] set. Returns pointer to write destination. **Calls:** FUN_0051641e, FUN_005159a8. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00517e43 — Alloc and Zero Init (Size by Type)

Source: unknown | High. Allocates memory of size 0x40 (64) for type 2, or 0x19c (412) for type 1. Zeroes via loop. Returns pointer or null. **Calls:** _malloc. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0051ad93 — Array Processing with Validation

Source: unknown | Medium. Validates conditions at param_1[0x5a..0x5d]. Iterates param_1[0x48] elements. For each: validates fields at +0x14 (range 0-3) and +0x18, checks corresponding flags at param_1[0x28/0x2c+index]. Calls FUN_0051a5ea for transforms. Zeros final state fields. Stores param_1[0x3f] to iVar1+0x30. **Calls:** FUN_0051a5ea. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0052156f — Media/3DNow Math Operation

Source: unknown | Low. Calls FastExitMediaState. Calls FUN_005262c2, PackedFloatingMUL, FUN_005295e0. Performs packed floating-point multiplication operations. Likely 3DNow! or SSE SIMD math. **Calls:** FastExitMediaState, FUN_005262c2, PackedFloatingMUL, FUN_005295e0. **Used by system:** docs/20-math-utilities.md. **Algorithm family:** SIMD/multimedia math. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00527f21 — Checksum/CRC Computation

Source: unknown | Medium. Computes checksum using Adler-32-like algorithm. Processes input buffer in 0x15b0-byte blocks. For each block: processes 16-byte chunks summing bytes, performs modulus 0xfff1. Accumulates two values (low: uVar3, high: param_1). Returns combined result. **Calls:** none (leaf function). **Used by system:** docs/20-math-utilities.md. **Algorithm family:** checksum/hash. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0052df70 — State Check and Conditional Init

Source: unknown | Medium. Calls FUN_0052df90. Stores masked result (0xff) in DAT_008b0108. If non-zero: calls FUN_005317c0. **Globals:** DAT_008b0108. **Calls:** FUN_0052df90, FUN_005317c0. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00534ee0 — File Handle Destructor with Mode Check

Source: unknown | Medium. File/stream destructor. Frees resources at +0x50, +0x1c (mode 'w'->FUN_005361d0, 'r'->FUN_00535660), checks +0x40 error state, checks +0x38 return code, frees +0x44, +0x48, +0x54. Frees self via FUN_0058aa6f. Returns error code or -2 for null input. **Calls:** FUN_0058aa6f (x5), FUN_005361d0/FUN_00535660, FUN_00587d02, FUN_0058afcf. **Used by system:** docs/08-file-formats.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00536fd0 — Delegation Wrapper

Source: unknown | High. Calls FUN_0058ab58(param_2, param_3). **Calls:** FUN_0058ab58. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b130 — 10-Float Struct Initializer

Source: unknown | High. Zeroes 7 dwords, sets 3 to 1.0f (0x3f800000). Calls FUN_0053b3b0. **Calls:** FUN_0053b3b0. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c200 — Delegation Wrapper

Source: unknown | High. Calls FUN_0053d4f0(). **Calls:** FUN_0053d4f0. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0053ced0 — Doubly-Linked List Node Removal by Flag

Source: unknown | Medium. Walks linked list at DAT_008b8f14. Checks flag at node+0x114 bit 3 (0x8). If set: unlinks node from doubly-linked list (prev->next = node->next), releases via FUN_0055fe30 + FUN_00557470, frees via FUN_00587bcf. Decrements DAT_008b6ac0 count. Processes tail node similarly. **Globals:** DAT_008b8f14, DAT_008b6ac0. **Calls:** FUN_0055fe30, FUN_00557470, FUN_00587bcf. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0053fed0 — Rendering/Composition Setup

Source: unknown | Medium. Configures render target or compositing surface. Checks flags at param_4[6] for 0x800/0x800000. Sets color key (0xff000000|param_4[0xd] or 0xffff00ff). Calls FUN_005006d5 for surface creation. Handles modes: 0 (init), 4/8 (texture creation via vtable+0x3c on param_4[4]/[5]), 1 or 2 (select param_4[2]/[3] as surface). Calls FUN_005008e4. Releases temp surface for modes 4/8. **Calls:** FUN_005006d5, FUN_0055c450, FUN_0053f720, FUN_005008e4. **Used by system:** docs/19-renderer.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005423c0 — Two-Field Setter + Call

Source: unknown | Medium. Sets param_1+4=param_2, param_1+8=param_3. Calls FUN_00542050 with fields at +0x6c and +0x70. **Calls:** FUN_00542050. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00543920 — Bounded Float Setter with Flag

Source: unknown | Medium. If _DAT_0059e430 <= param_2 < _DAT_0059e420: sets *(param_1+400)=param_2, ORs 0x10000 into *(param_1+0xec). **Globals:** _DAT_0059e430, _DAT_0059e420. **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00547040 — Conditional Render State Setup

Source: unknown | Medium. If param_2 < *(param_1+0xa4) < 8: sets render states via FUN_0054fc40(0x1000000), FUN_0054fc80(0,0), FUN_0054fd30(1.0f,1.0f), FUN_0054fca0(5). **Calls:** FUN_0054fc40, FUN_0054fc80, FUN_0054fd30, FUN_0054fca0. **Used by system:** docs/19-renderer.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005478b0 — Doubly-Linked List Node Removal with Array Cleanup

Source: unknown | Medium. Removes node from doubly-linked list (prev/next at +0x58/+0x5c). Updates head at param_1+0x28 if needed. Decrements allocation counter at node-4, releases via FUN_00557470 per count. Frees via FUN_00587bcf. Decrements list count at param_1+0xc. **Calls:** FUN_00557470 (xN), FUN_00587bcf. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005492b0 — Linked List Walk with Dispatch

Source: unknown | Medium. Walks linked list at param_1+0xf0 (next at +0xd). For each node: calls FUN_005456b0(*node+0x58), if result non-zero: calls FUN_005455f0+FUN_00549250. **Calls:** FUN_005456b0, FUN_005455f0, FUN_00549250. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0054b530 — Dual Matrix/Transform Multiply

Source: unknown | Medium. Calls FUN_0054b4a0(param_4,param_5,param_6) then FUN_0054b420(param_1,param_2,param_3). Likely transform composition. **Calls:** FUN_0054b4a0, FUN_0054b420. **Used by system:** docs/18-physics-dynamics.md. **Algorithm family:** matrix/transform math. **Moddability:** hardcoded.

<!-- target: docs/17-physics-collision.md -->

## FUN_00550870 — Struct Zero Init with Unit Vector

Source: unknown | High. Calls FUN_0053c2a0. Zeroes 6 dwords and a byte. Sets param_1[1] = 1.0f (0x3f800000). **Calls:** FUN_0053c2a0. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005573a0 — Struct Init with VTable + Color

Source: unknown | Medium. Calls FUN_0053c2a0, FUN_0053b130. Zeroes fields, sets param_1[1]=-1, param_1[3]=0xffffff (white). Calls FUN_0053b3b0. Sets param_1[0x1e]=param_1[0x1f]=0. **Calls:** FUN_0053c2a0, FUN_0053b130, FUN_0053b3b0. **Used by system:** docs/19-renderer.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c9a0 — Masked Field Getter

Source: unknown | High. Returns *(param_1+0x13a8) & 0xf1000. **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00564480 — Short-to-Int Field Getter

Source: unknown | High. Returns (int)*(short*)(param_1+6). **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005676c0 — Float-to-Int Conversion with Remainder

Source: unknown | High. Converts float to int via __ftol. Stores int part in *param_1. Stores remainder (float - int * _DAT_0059f118) in *param_2. **Globals:** _DAT_0059f118. **Calls:** __ftol. **Used by system:** docs/20-math-utilities.md. **Algorithm family:** float conversion. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a000 — Callback Registration Stub

Source: unknown | High. Registers LAB_0057a010 via FUN_00587b3e. **Calls:** FUN_00587b3e. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0057ae40 — Callback Registration Stub

Source: unknown | High. Registers DAT_0057ae50 via FUN_00587b3e. **Calls:** FUN_00587b3e. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00585400 — VTable Dispatch with Conditional Branch

Source: unknown | Medium. If FUN_00586d00() returns 0: dispatches vtable+0x2c, calls FUN_00584230, dispatches vtable+0x5c. Else: calls FUN_00584dd0. Returns 1. **Calls:** FUN_00586d00, FUN_00584230, FUN_00584dd0. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00587260 — Decompression Decode (Encoded to UShort Buffer)

Source: unknown | Medium. Decodes compressed data into ushort buffer. Reads header via FUN_00587250. Checks output capacity. Decompresses via FUN_00587580 into temp buffer. Copies decoded data to output (dword-by-dword then byte remainder). Appends 3 header fields from param_1+0x10/+0x14/+0x18. Updates *param_3 with final size. Returns 1 on success, 0 on overflow. **Calls:** FUN_00587250, FUN_00587580. **Used by system:** docs/08-file-formats.md. **Algorithm family:** decompression. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_005883e5 — Float Roundedness Check

Source: unknown | Medium. Checks if float in ST0 equals its rounded value. No action taken (void return). Likely a debug/assert helper. **Calls:** none (uses x87 FPU). **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a947 — __nh_malloc (MSVC CRT)

Source: MSVC CRT | High. MSVC __nh_malloc implementation. Tries allocation via FUN_0058a973. If fails and _NhFlag != 0: calls FUN_00593db8 (new handler) in retry loop. Returns null on failure or size >= 0xffffffe1. **Calls:** FUN_0058a973, FUN_00593db8. **Used by system:** docs/20-math-utilities.md — MSVC CRT memory allocation. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0058e0b4 — Two-Field Initializer

Source: unknown | High. Sets *(param_1+0x50)=&DAT_005e7810, *(param_1+0x14)=1. **Calls:** none. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0059532b — Big-Integer Right Shift (3-Word)

Source: unknown | Medium. Performs right bit-shift on a 3-word (96-bit) big integer. Shifts by param_2 bits. Handles cross-word carry. Zeros words that shift out of range. **Calls:** none (leaf function). **Used by system:** docs/20-math-utilities.md. **Algorithm family:** big-integer math. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00598731 — Constructor with VTable Fixup

Source: unknown | High. Sets vtable pointer via *(*(*param_1+4)+(int)param_1) = &PTR_LAB_005b9ba4. Calls FUN_00598aea. **Calls:** FUN_00598aea. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_00599904 — Delegation with Fixed Args

Source: unknown | High. Calls FUN_00599b86(0,1). **Calls:** FUN_00599b86. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0059baa3 — Type-Info Destructor

Source: unknown | Medium. Sets vtable to type_info::vftable. Acquires critsec slot 0x1b via FUN_0058dfea. Frees param_1[1] via FUN_0058aa6f. Releases critsec via FUN_0058e04b(0x1b). **Calls:** FUN_0058dfea, FUN_0058aa6f, FUN_0058e04b. **Used by system:** docs/20-math-utilities.md — MSVC RTTI type_info destructor. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c86a — SEH Unwind Handler (Calls FUN_00581750)

Source: unknown | High. SEH unwind handler calling FUN_00581750. **Calls:** FUN_00581750. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cf70 — SEH Unwind Handler (Array Dtor)

Source: unknown | Medium. SEH unwind handler calls FUN_0058a5f7 to destroy an array of 0x28-sized objects (count from stack, destructor FUN_00583aa0). **Calls:** FUN_0058a5f7. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d7ea — Thunk to FUN_00443c07

Source: unknown | High. Thunk/delegation to FUN_00443c07. **Calls:** FUN_00443c07. **Used by system:** docs/20-math-utilities.md. **Moddability:** hardcoded.

=== END OF DOCUMENTED FUNCTIONS ===

## FUN_0050df95 — Thunk via Indirect Jump (DAT_005d7878)

Source: unknown | Confidence: high
Trampoline — indirect jump through global function pointer DAT_005d7878.

**Key logic:**
- Calls `(*_DAT_005d7878)()` — indirect call through a function pointer stored in DAT_005d7878
- No local logic; acts as a dispatch stub
- Address appears in a vtable or jump table context

**Globals:**
- `DAT_005d7878` — function pointer (unknown module)

**Called by:** address 0x0050df95 referenced in vtable/jump table context

**Used by system:** docs/20-math-utilities.md — generic thunk mechanism

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00552ff0 — Switch-Based Parameter Field Set with Flags

Source: unknown | Confidence: high
Sets two struct fields at +0x54 and +0x58 based on a switch parameter.

**Key logic:**
- Writes `param_2` to `param_1+0x54` (generic value passthrough)
- Switch on `param_3` (0–4) selects value written to `param_1+0x58`:
  - case 0: 0xbf
  - case 1: 0x7f
  - case 2: 0x3f
  - case 3: 0x00
  - case 4: 0xff

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x54 | int | Value passthrough from param_2 |
| +0x58 | int | Flag/mask selected by switch (0xbf/0x7f/0x3f/0x00/0xff) |

**Used by system:** docs/20-math-utilities.md — parameter set utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055d2e0 — Clear Byte Flag, Return 0

Source: unknown | Confidence: high
Clears a single byte field at +0x58 and returns 0.

**Key logic:**
- `*(byte*)(param_1+0x58) = 0`
- Returns 0

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x58 | byte | Flag byte cleared to 0 |

**Used by system:** docs/20-math-utilities.md — cleanup/reset utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00560eb0 — Append Node to Doubly-Linked List Tail

Source: unknown | Confidence: high
Appends a node to the tail of a doubly-linked list with ownership flag.

**Key logic:**
- If `param_2+0x30` (prev pointer) is non-null: update its `+0x34` (next pointer) to `param_2+0x34`
- If `param_2+0x34` (next pointer) is non-null: update its `+0x30` (prev pointer) to `param_2+0x30`
- Detaches param_2 from its current list (if any)
- Walks list from `param_1+0x2c` to find tail (following `+0x34` next pointers)
- If list head is null: sets `param_1+0x2c = param_2` (new head)
- Else: appends `param_2` to tail of list
- Sets `param_2+0x30 = iVar2` (prev = old tail), `param_2+0x34 = 0` (next = null)
- Sets `param_2+0x24 |= 4` (ownership/dirty flag)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x2c | int* | List head pointer |

**Struct offsets (param_2 - node):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x24 | uint | Flags (bit 2 = ownership flag) |
| +0x30 | int* | Prev pointer |
| +0x34 | int* | Next pointer |

**Used by system:** docs/20-math-utilities.md — generic doubly-linked list append

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00589fcc — Stream getc with Underflow Handler

Source: unknown (CRT stream I/O) | Confidence: high
Reads a single byte from a stream buffer, handling underflow via refill callback.

**Key logic:**
- Calls `FUN_0058c1b1(param_1)` — lock stream (critical section)
- Decrements byte count at `param_1[1]`
- If count < 0: calls `FUN_0058c255(param_1)` — underflow handler, refills buffer
- Else: reads byte from `*param_1` buffer, advances pointer
- Calls `FUN_0058c203(param_1)` — unlock stream
- Returns the byte read

**Calls:**
- FUN_0058c1b1 — stream buffer lock via critical section
- FUN_0058c255 — underflow handler / buffer refill
- FUN_0058c203 — stream buffer unlock

**Used by system:** docs/20-math-utilities.md — CRT stream getc implementation

**Algorithm family:** stream I/O

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a935 — _malloc — Wrapper for __nh_malloc

Source: crt/malloc.c (Visual Studio 2003 Release) | Confidence: high
Standard CRT malloc wrapper — calls __nh_malloc with debug heap flag.

**Key logic:**
- Calls `__nh_malloc(_Size, DAT_008d41b0)` — MSVC debug heap allocator
- DAT_008d41b0 is likely the debug heap flag (non-zero = debug heap tracking)
- Returns allocated pointer

**Globals:**
- `DAT_008d41b0` — CRT debug heap flag

**Calls:**
- __nh_malloc — MSVC internal heap allocation

**Used by system:** docs/20-math-utilities.md — CRT memory allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058c1b1 — Stream Buffer Lock via Critical Section

Source: CRT stream I/O | Confidence: high
Locks a stream buffer's critical section for thread-safe access. Handles both per-stream and shared critical section arrays.

**Key logic:**
- If `param_1` address falls in range (0x5e6747, 0x5e69a9):
  - Computes index: `(param_1 - 0x5e6748) >> 5`
  - Calls `FUN_0058dfea(index + 0x1c)` — critical section lazy init + enter at array index
- Otherwise:
  - Calls `EnterCriticalSection(param_1 + 0x20)` — uses embedded critical section in stream struct

**Calls:**
- FUN_0058dfea — critical section lazy init + enter (indexed)
- EnterCriticalSection (Win32 API)

**Used by system:** docs/20-math-utilities.md — CRT stream locking infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00591ca1 — ID-to-Value Table Lookup in Constant Table

Source: unknown | Confidence: high
Linear search through a constant table for a matching integer ID, returning associated value.

**Key logic:**
- Table at `DAT_005e7640`, entries stride 8 bytes (4 bytes ID + 4 bytes value)
- Range: from 0x5e7640 to 0x5e7718 (0xd8 bytes = 27 entries)
- Compares `*piVar1 == param_1` — match on ID
- Returns value at `iVar2 * 8 + 0x5e7644` (second dword of matching entry)
- Returns 0 if not found

**Used by system:** docs/20-math-utilities.md — constant lookup table utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059750a — Array-of-Struct Linear Search by ID

Source: unknown | Confidence: high
Linear searches an array of 12-byte structures for a matching ID field at offset +4.

**Key logic:**
- Step 0xc through array starting at `param_2`, for `DAT_005e7894` entries
- At each entry: compare `*(entry + 4) == param_1` (ID match)
- Returns matching entry pointer, or 0 if not found
- Short-circuit: checks first entry before entering loop

**Globals:**
- `DAT_005e7894` — array element count

**Used by system:** docs/20-math-utilities.md — array-of-struct linear search

**Algorithm family:** linear search

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059bcd2 — Stream Read Wrapper with Lock/Unlock

Source: CRT stream I/O | Confidence: high
Thread-safe stream read wrapper — locks, reads, unlocks.

**Key logic:**
- Calls `FUN_0058c1b1(param_2)` — lock stream
- Calls `FUN_0059bcfc(param_1, param_2)` — actual read (returns short)
- Calls `FUN_0058c203(param_2)` — unlock stream
- Returns the read value

**Calls:**
- FUN_0058c1b1 — stream lock
- FUN_0059bcfc — stream read (returns short)
- FUN_0058c203 — stream unlock

**Used by system:** docs/20-math-utilities.md — thread-safe stream I/O utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c504 — SEH Unwind Helper (Free Local)

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that frees a local variable on the stack during stack unwinding.

**Key logic:**
- Reads local at `unaff_EBP - 0x40`
- Calls `FUN_00587bcf()` — memory free
- Part of MSVC C++ exception handling cleanup for stack-allocated objects

**Calls:**
- FUN_00587bcf — memory free/dealloc

**Used by system:** docs/20-math-utilities.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cae0 — SEH Unwind Handler

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that delegates to FUN_0057b7f0 (VTable pointer initialization).

**Key logic:**
- Calls `FUN_0057b7f0()` — vtable pointer init

**Calls:**
- FUN_0057b7f0 — VTable pointer init (triage: Data/VTableInit)

**Used by system:** docs/20-math-utilities.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ccc0 — SEH Unwind Helper

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that delegates to FUN_00583270 (linked list destructor with vtable cleanup).

**Key logic:**
- Calls `FUN_00583270()` — linked list destructor with vtable cleanup call

**Calls:**
- FUN_00583270 — linked list destructor with vtable cleanup

**Used by system:** docs/20-math-utilities.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004010b0 � Struct Init with Float Constants

Source: unknown | Confidence: medium
Initializes a data structure with predefined float and integer constants.

**Key logic:**
- Loop: sets param_1[2] through param_1[5] to 1, 2, 3, 4
- Zeroes 6 fields at offsets +0x4b, 0x4c, 0x4d, 0x4e, 0x52, 0x53 (byte + dwords)
- Sets float constants: param_1[0] = 4.75f (0x40980000), param_1[1] = 4.3125f (0x408a0000)
- Sets param_1[0x4a] = 0.995f (0x3f7eb852)
- Sets integer constants: +0x58=0x68(104), +0x59=0x34(52), +0x5a=3, +0x57=1

**Used by system:** docs/20-math-utilities.md � configuration/state initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404d20 � Float Getter via Double Indirection

Source: unknown | Confidence: high
Reads a float from a struct field at offset +0x18 through a pointer-to-pointer.

**Key logic:**
- return (float)*(float *)(*param_1 + 0x18) � reads field at +0x18 via double indirection

**Used by system:** docs/20-math-utilities.md � simple data accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004058d0 - Destructor with VTable and Free

Source: unknown | Confidence: high
Destructor that sets vtable, frees a child pointer, and optionally frees self.

**Key logic:**
- Sets vtable: *param_1 = &PTR_FUN_0059e4b4
- If param_1[1] (child ptr at +0x4) non-null: frees via FUN_00587bcf
- If (param_2 & 1) != 0: frees self via FUN_00587bcf
- Returns param_1

**Calls:**
- FUN_00587bcf - memory free/dealloc

**Used by system:** docs/20-math-utilities.md - object destructor with conditional self-free

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406ba0 - Complex Destructor with 4 Linked Lists

Source: unknown | Confidence: medium
Destructor that destroys 4 linked lists with different cleanup strategies and vtable switching.

**Key logic:**
- Sets vtable: *param_1 = &PTR_FUN_0059e530
- Calls FUN_00406e50() - pre-cleanup
- Destroy list at param_1[0xe]: free nodes, no data destructor
- Destroy list at param_1[10]: free nodes, call FUN_00404f70(1) on data
- Destroy list at param_1[6]: free nodes, call virtual destructor on data (vtable+0 with arg 1)
- Destroy list at param_1[2]: free nodes, call virtual destructor on data (vtable+0 with arg 1)
- Sets final vtable: *param_1 = &PTR_LAB_0059e598

**Calls:**
- FUN_00406e50, FUN_00404f70, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md - multi-list object destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00408220 - Registration Wrapper

Source: unknown | Confidence: high
Thin wrapper that registers a static data block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&DAT_00408230) - registers address for deferred execution

**Calls:**
- FUN_00587b3e - deferred function registration (MSVC _atexit-like)

**Used by system:** docs/20-math-utilities.md - static data registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040ac00 - Struct Init with VTable

Source: unknown | Confidence: high
Initializes a 6-dword struct with vtable, zeroing all fields.

**Key logic:**
- Sets param_1[1..5] = 0 (offsets +0x4 through +0x14)
- Sets vtable: *param_1 = &PTR_LAB_0059e678

**Used by system:** docs/20-math-utilities.md - object initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040c8d0 - State Check with Ternary Logic

Source: unknown | Confidence: medium
Checks state fields and returns boolean based on comparison with DAT_007cfcc8.

**Key logic:**
- If param_1+0xc == 0 AND *(param_1+0x18+0x34) == 0: returns 3
- If field == 1: returns true
- If field == 2: returns DAT_007cfcc8 == 0
- Otherwise: returns false

**Globals:**
- DAT_007cfcc8 - unknown state flag

**Used by system:** docs/20-math-utilities.md - state evaluation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040dd30 - Conditional Delegation

Source: unknown | Confidence: medium
Checks nested pointers and conditionally delegates for result.

**Key logic:**
- If param_1+0x88 non-null AND *(param_1+0x88+4) non-null:
  - Calls FUN_0049adb0() and FUN_0040d4c0(result) - process
  - Returns result
- Otherwise: returns 0

**Calls:**
- FUN_0049adb0 - value getter
- FUN_0040d4c0 - processor

**Used by system:** docs/20-math-utilities.md - guarded delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040eec0 - Switch-Based Float Processing

Source: unknown | Confidence: medium
Processes float parameters through math functions based on a mode switch.

**Key logic:**
- Converts 6 float params to doubles
- Switch on param_1+0x1c (mode 0-5): calls FUN_00459950 and FUN_00459990

**Calls:**
- FUN_00459950, FUN_00459990

**Used by system:** docs/20-math-utilities.md - float processing with dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00410b80 - Array-of-Struct Linear Search by ID

Source: unknown | Confidence: medium
Linear search through an array of structures for a matching ID.

**Key logic:**
- Iterates param_1+0x3c entries at stride 0x318, ID at +0xd0
- On match: returns pointer at param_1+0x40 + index * 0x24
- Returns 0 if not found

**Used by system:** docs/20-math-utilities.md - ID-to-data lookup

**Algorithm family:** linear search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00414210 - Global List Triple Cleanup with Timer Removal

Source: unknown | Confidence: medium
Cleans up three global linked lists with different destructor strategies.

**Key logic:**
- Calls FUN_004150c0() - pre-cleanup
- Destroys DAT_005ea608 list with FUN_00414420 on data
- Destroys DAT_005ea5f8 list with FUN_00414380 on data
- Destroys DAT_005ea5e8 list: removes 4 timers per node, frees data
- Zeros all list heads

**Globals:**
- DAT_005ea608, DAT_005ea5f8, DAT_005ea5e8

**Calls:**
- FUN_004150c0, FUN_00414420, FUN_00414380, FUN_004149a0, FUN_00401030, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md - global resource cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004186a0 - Buffer Init with -1.0f Defaults

Source: unknown | Confidence: medium
Initializes a large buffer of floats to -1.0f.

**Key logic:**
- Loop 0x14 (20) times: calls FUN_004144d0()
- Loop 0x219 (537) times: sets each dword to 0xbf800000 (-1.0f)
- Sets fields at +0xae8=0, +0xae4=0, +0xaec=0xffffffff, +0x135c=0

**Calls:**
- FUN_004144d0

**Used by system:** docs/20-math-utilities.md - buffer init with sentinels

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041ed20 - Indexed Field Getter

Source: unknown | Confidence: high
Returns a dword from a struct's indexed field array.

**Key logic:**
- If param_1 != 0: returns *(param_1 + 0xd8 + param_2 * 4)
- Returns 0 if null

**Used by system:** docs/20-math-utilities.md - indexed field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004214a0 - Struct Init with 0/0xffffffff Pattern

Source: unknown | Confidence: high
Initializes 46 dwords with alternating 0/0xffffffff pattern.

**Key logic:**
- Sets param_1[0]=0, param_1[1]=0xffffffff
- Continues pattern: even=0, odd=0xffffffff through index 0x2d
- Calls FUN_004216f0() - post-init

**Calls:**
- FUN_004216f0

**Used by system:** docs/20-math-utilities.md - struct init with sentinel pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421af0 - Dual Delegation Wrapper

Source: unknown | Confidence: high
Calls two functions with the same parameter.

**Key logic:**
- Calls FUN_00421890(param_1) and FUN_00566650(param_1)

**Calls:**
- FUN_00421890, FUN_00566650 (path registry/string set, docs/08)

**Used by system:** docs/20-math-utilities.md - dual delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00429fd0 - Random-Weighted Tier Selection

Source: unknown | Confidence: medium
Selects a tier based on chained comparisons against DAT_008afee8 with randomization at boundaries.

**Key logic:**
- Compares DAT_008afee8 against threshold chain with rand() at boundaries
- Returns 4-6 depending on threshold crossing, with 50/50 randomization at some boundaries
- Searches vehicle array for matching tier, returns index

**Globals:**
- DAT_008afee8, DAT_0059e868, DAT_0059e7e8, DAT_0059e450, DAT_0059e970, DAT_0059e8cc, DAT_0059e908

**Calls:**
- _rand, FUN_004d7570, FUN_004a4830

**Used by system:** docs/20-math-utilities.md - weighted tier selection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00456060 - Dual Field Getter

Source: unknown | Confidence: high
Reads two struct fields at +0x38 and +0x3c, optionally outputs to pointers.

**Key logic:**
- If param_2 non-null: *param_2 = *(param_1 + 0x38)
- If param_3 non-null: *param_3 = *(param_1 + 0x3c)

**Used by system:** docs/20-math-utilities.md - field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004582c0 - Guarded Function with Flag Set

Source: unknown | Confidence: medium
Checks a pointer, sets flag, and calls function if non-null.

**Key logic:**
- If *param_1 != 0: sets byte at param_1+7 to 1, calls FUN_00457d00()
- If null: returns 0

**Calls:**
- FUN_00457d00

**Used by system:** docs/20-math-utilities.md - guarded execution

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bb00 - Float Array Threshold Search

Source: unknown | Confidence: medium
Searches array of floats for first value exceeding threshold, returns index.

**Key logic:**
- Iterates up to 8 entries stride 0x5c starting at param_1+0x90
- Checks if float > DAT_0059e440 (ZeroThreshold, ~0.0f)
- Returns index of first above-threshold value, or 0

**Globals:**
- DAT_0059e440 (ZeroThreshold, docs/12)

**Algorithm family:** threshold search

**Moddability:** hardcoded
<!-- target: docs/20-math-utilities.md -->

## FUN_0045c3d0 - Parser Dispatch Wrapper

Source: unknown | Confidence: medium
Calls FUN_00568a60 (generic parser) with byte flag from param_1+1, returns 1 on success.

**Key logic:**
- Calls FUN_00568a60(*(param_1+1), param_3)
- If non-zero: returns 1
- Else: sets *param_3=0, returns 0

**Calls:**
- FUN_00568a60 - generic parser (docs/08 file formats)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045e5b0 - Array Search for -1 Sentinel

Source: unknown | Confidence: high
Searches int array at param_1+0x1d4 for first -1 entry, returns index.

**Key logic:**
- Iterates 0x68 (104) entries from base +0x1d4
- Returns index of first entry == -1
- Returns -1 if not found

**Algorithm family:** linear search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004618d0 - Reverse Path Search for Backslash

Source: unknown (path utils) | Confidence: high
Extracts filename from a path by scanning backwards for last backslash separator.

**Key logic:**
- Computes string length via manual strlen loop
- Scans backwards for '\' backslash
- Returns pointer after last backslash (filename)
- If no backslash: returns pointer to start

**Used by system:** docs/20-math-utilities.md - path parsing (basename)

**Algorithm family:** string parsing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462460 - Driver Data Copy by ID

Source: unknown | Confidence: medium
Copies driver data block from array when matching ID found.

**Key logic:**
- Iterates *(param_1+0x3e14) entries at stride 0x8c
- For each entry: compares byte at +0x410 with param_2 (ID)
- On match: copies 0x23 dwords from +0x394 to param_3
- Copies value at +0x3c74 (indexed) to *param_4
- Returns 1 on match, 0 if not found

**Struct offsets:**
| Offset | Field |
|--------|-------|
| +0x3e14 | Entry count |
| +0x410 | ID byte per entry |
| +0x394 | Data block per entry (0x23 dwords) |
| +0x3c74 | Aux data per index (stride 4) |

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463e00 - Guarded Function Call by State

Source: unknown | Confidence: medium
Calls FUN_004607a0 if global state field equals 3.

**Key logic:**
- If *(param_1+0x3fc4) == 3: calls FUN_004607a0()

**Calls:**
- FUN_004607a0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464c10 - Large Struct Initialization (0x230-stride blocks)

Source: unknown | Confidence: medium
Initializes a large struct with 0x68 sub-blocks each 0x230 bytes, plus allocation.

**Key logic:**
- Calls FUN_00568ba0() - session init
- Zeroes 8 dwords at +0x6c through +0x88
- Loop 0x68 times: per block at stride 0x230:
  - Initializes via FUN_00401000 (timer/callback)
  - Zeroes +0x220, +0x224, +0x228
  - Allocates 8-byte node (pointer + float), stores at +0x22c
  - Calls FUN_00464a40()
- Zeroes 8 dwords at +0xe5b0 through +0xe5cc
- Calls FUN_00568be0(1) - session finalize
- Sets floats: +100=1.0, +0x60=1.0, +0x50=0xffffffff, +0x54=0xffffffff, +0xe40c=0
- Fills 0x68 dwords at +0xe410 with 0xffffffff

**Calls:**
- FUN_00568ba0, FUN_00401000, operator_new, FUN_00464a40, FUN_00568be0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466250 - Flag Setter

Source: unknown | Confidence: medium
Calls FUN_004988a0(3) and sets byte flag at +0xf4 to 1, returns 0.

**Key logic:**
- FUN_004988a0(3) - some init
- *(param_1+0xf4) = 1
- Returns 0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00468610 - Destructor with Free

Source: unknown | Confidence: high
Destructor sets vtable, frees child pointer at +0x174, calls cleanup.

**Key logic:**
- *param_1 = &PTR_FUN_0059f718
- If param_1[0x5d] non-null: FUN_00587bcf free
- FUN_00489440() - cleanup

**Calls:**
- FUN_00587bcf, FUN_00489440

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046c030 - Field Setter

Source: unknown | Confidence: high
Sets integer field at +0x174 to 2.

**Key logic:**
- *(param_1+0x174) = 2

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046e6f0 - Conditional Delegation via VTable

Source: unknown | Confidence: medium
Calls vtable method to allocate, then processes via FUN_0046e5c0.

**Key logic:**
- Calls virtual method at vtable+0x1c with arg 0x2c (alloc)
- If successful: calls FUN_00489920() and FUN_0046e5c0()
- Returns 0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004702a0 - Init with VTable Set

Source: unknown | Confidence: medium
Calls FUN_0048b420, sets field at [0xc1], sets vtable.

**Key logic:**
- FUN_0048b420(0,0,0,0,1,0) - bulk initialization
- param_1[0xc1] = param_2
- *param_1 = &PTR_LAB_005a0308

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00472040 - Object Init with Defaults

Source: unknown | Confidence: medium
Initializes struct with vtable, sizes, and flags.

**Key logic:**
- FUN_00466d60(1) - pre-init
- param_1[199]=0, param_1[0xca]=0
- *param_1 = &PTR_FUN_005a1a40
- param_1[0xc9]=0x20, param_1[0xcb]=1, param_1[0xcc]=1, param_1[0xcd]=0xfc

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473e50 - Object Init with Global Ref

Source: unknown | Confidence: medium
Initializes struct referencing DAT_007cfbb4 global.

**Key logic:**
- FUN_00466d60(1)
- *param_1 = &PTR_FUN_005a3240
- param_1[199] = &DAT_007cfbb4
- Sets multiple size/flag fields
- Calls FUN_00486f30 twice with globals, then FUN_004670e0()

**Globals:**
- DAT_007cfbb4, PTR_DAT_005be704, DAT_005c32c8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00475570 - Conditional Chain

Source: unknown | Confidence: medium
Calls FUN_00461f70, then conditionally calls FUN_00475150.

**Key logic:**
- FUN_00461f70()
- If FUN_00462140() non-zero: FUN_00475150()
- Returns 0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00477ee0 - Destructor with Free + Condition

Source: unknown | Confidence: high
Destructor frees field, calls cleanups, optionally frees self.

**Key logic:**
- If param_1+0x158 non-null: FUN_00587bcf free
- FUN_00499b50() x2, FUN_00485eb0()
- If (param_2 & 1): FUN_00587bcf(param_1)

**Calls:**
- FUN_00587bcf, FUN_00499b50, FUN_00485eb0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478e80 - Single Call Wrapper

Source: unknown | Confidence: high
Delegates to FUN_00499b80().

**Key logic:**
- FUN_00499b80()

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004799e0 - Init with VTable

Source: unknown | Confidence: medium
Calls FUN_00466980 with float 0.3f, sets vtable.

**Key logic:**
- FUN_00466980(0, 0x3e99999a) = (0, 0.3f)
- *param_1 = &PTR_FUN_005a57c8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a260 - VTable Dispatch

Source: unknown | Confidence: medium
Calls vtable method via DAT_007cd8c0 to allocate, then dispatches.

**Key logic:**
- FUN_004883a0()
- Calls virtual at (*DAT_007cd8c0)+0x1c with arg 0xd
- If non-null: FUN_00477280(param_1)

**Globals:**
- DAT_007cd8c0 - vtable/object pointer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047be70 - Init with VTable

Source: unknown | Confidence: high
Calls FUN_004893c0, sets vtable, zeroes field.

**Key logic:**
- FUN_004893c0()
- *param_1 = &PTR_FUN_005a6788
- param_1[0x5d] = 0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047f1f0 - Clamp by Range

Source: unknown | Confidence: high
Clamps *param_1 to [param_2, param_3] range.

**Key logic:**
- If *param_1 < param_2 OR param_3 < *param_1: set to nearer bound
- Equivalent: clamp(*param_1, param_2, param_3)

**Algorithm family:** clamp

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485870 - Destructor with Triple Free

Source: unknown | Confidence: high
Destructor frees three child pointers, calls cleanups, optionally frees self.

**Key logic:**
- FUN_00499b50()
- Frees +0x128, +0x120, +0x118 via FUN_00587bcf if non-null
- FUN_00499b50(), FUN_00485eb0()
- If (param_2 & 1): FUN_00587bcf(param_1)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486480 - Append to Linked List Tail

Source: unknown | Confidence: high
Appends param_2 to linked list starting at param_1+0xcc (next at +0x18).

**Key logic:**
- If head (+0xcc) is null: set head = param_2, return
- Else: walk to tail via +0x18 pointers, append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487250 - Init with VTable + Cleanup

Source: unknown | Confidence: high
Sets vtable and calls cleanup.

**Key logic:**
- *param_1 = &PTR_FUN_005ab968
- FUN_00485eb0()

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487ed0 - Init with VTable + Flags

Source: unknown | Confidence: medium
Initializes struct with vtable and two byte params.

**Key logic:**
- FUN_00485e30()
- *(param_1+0x38)=param_2, *param_1=&PTR_FUN_005abac8, *(param_1+0xe1)=param_3
- param_1[0x21]=0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489480 - Pop List with Destructor

Source: unknown | Confidence: medium
Pops entries from a linked list, calling their virtual destructors.

**Key logic:**
- Count = *(param_1+0x94) - param_1+0x170 (bounded by 0)
- For each entry: pop head, call virtual destructor at *puVar1 on arg 1
- Decrements count

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b8f0 - Bounded Field Setter

Source: unknown | Confidence: high
Sets field at +0x2f8 to param_2 if in range [0, 0x100).

**Key logic:**
- If -1 < param_2 < 0x100: *(param_1+0x2f8) = param_2
- Returns 0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d2b0 - Linked List Node Append

Source: unknown | Confidence: medium
Allocates and appends a node to a doubly-linked list with allocation and init.

**Key logic:**
- Allocates 8-byte temp via operator_new
- Calls FUN_0048c9a0() and FUN_0048c9e0() for allocation/init
- Allocates 0x10-byte node (data pointer, next, prev, flag byte=1)
- If list head (param_1[199]) is null: set head = tail
- Else: append to tail, set prev link
- Increments count at param_1[0xca]
- Calls FUN_0048cc20() and vtable method at +0x2c
- Returns 1 on success, 0 on failure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e650 - Destructor with Conditional Self-Free

Source: unknown | Confidence: high
Calls cleanup and optionally frees self.

**Key logic:**
- FUN_0048e670() - cleanup
- If (param_2 & 1): FUN_00587bcf(param_1)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fc80 - Struct Field Copy

Source: unknown | Confidence: high
Copies fields from param_2's nested struct into param_1.

**Key logic:**
- param_1+0x38 = param_2
- param_1+0xc = *(param_2+0xc)+0x1c
- param_1+0x10 = *(param_2+0xc)+0x20

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490660 - VTable Dispatch List Iteration

Source: unknown | Confidence: medium
Iterates linked list, calling vtable method on each node based on range check.

**Key logic:**
- Cals FUN_00486720() - get state/phase
- If 2 < state < 6: sets flag = 1
- Iterates param_1+0xec entries via linked list at param_1+0xe0
- Calls virtual method at vtable+0x10 on each valid node with flag

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491760 - Single Call Wrapper

Source: unknown | Confidence: high
Delegates to FUN_004916e0().

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491f60 - Triple Field Cleanup

Source: unknown | Confidence: high
Checks and frees three fields, then zeroes them.

**Key logic:**
- If *param_1: FUN_005355a0()
- If param_1[1]: FUN_00587d02()
- If param_1[2]: FUN_00587d02()
- Sets all three to 0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495120 - Global Field Reader

Source: unknown | Confidence: high
Reads two fields from DAT_008b8dc8 global.

**Key logic:**
- *param_1 = *(DAT_008b8dc8 + 0x1c)
- *param_2 = *(DAT_008b8dc8 + 0x20)

**Globals:**
- DAT_008b8dc8 - unknown global struct

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004963c0 - Field Setter

Source: unknown | Confidence: high
Sets field at +0x28 to 1, returns 0.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004979b0 - Thunk: Polling Loop via FUN_00498f70

Source: unknown | Confidence: medium
Thunk/delegation with polling loop - calls FUN_00498f70 until it returns != 1.

**Key logic:**
- While param_1+0x18 non-null AND FUN_00498f70() == 1: call FUN_00495ae0()

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498d20 - Init with VTable + Param

Source: unknown | Confidence: medium
Calls init, sets vtable, calls post-init, stores param.

**Key logic:**
- FUN_0049a930() - alloc
- *param_1 = &PTR_FUN_005ac9e8
- FUN_00498df0() - post-init
- param_1[0x11] = param_2

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499280 - Destructor with List Walk

Source: unknown | Confidence: medium
Destructor walks linked list calling destructors, frees fields, calls cleanup.

**Key logic:**
- *param_1 = &PTR_FUN_005aca74
- Walks list at param_1[0x11], calls virtual destructor on each node
- Frees param_1[0x18] and param_1[0x16] via FUN_00587bcf
- FUN_0049a990()

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499a30 - String + Field Setter

Source: unknown | Confidence: high
Calls FUN_00566650 (path/string set) with param_2, stores param_3.

**Key logic:**
- FUN_00566650(param_2) - string registry set
- *(param_1+8) = param_3

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499e50 - Single Call Wrapper

Source: unknown | Confidence: high
Delegates to FUN_00566650() with no args.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a330 - Char-to-Index Conversion

Source: unknown | Confidence: high
Converts first char of string to index (0-25 for A-Z), else -1.

**Key logic:**
- FUN_00589901(param_1) - string normalize
- iVar1 = param_1[0] - 0x41 ('A')
- Returns iVar1 if 0-25, else -1

**Algorithm family:** character mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049aec0 - Linked List Indexed Field Reader

Source: unknown | Confidence: medium
Gets data at Nth position in linked list, reads two short values.

**Key logic:**
- If param_2 out of [0, param_1[3]) range: param_1[2]=0
- Else walks linked list to find Nth node
- If valid: reads two shorts from node data to *param_3, *param_4
- Returns 1 on success, 0 on failure

**Algorithm family:** linked list indexed access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049e170 - Format String Batch Display

Source: unknown | Confidence: medium
Formats multiple strings with DAT_005ccef0 format and calls display function.

**Key logic:**
- Checks pointers non-null chain (param_1+0xc, +0x14, +0x14+0x54)
- Repeated pattern: FUN_0058815f (format) + FUN_00553070 (display)
- Uses many DAT_007ceXXX globals as offsets/values
- 14 format+display pairs with varying x-positions and widths
- Uses DAT_007ce6ac, DAT_007ce7cc, DAT_007ce718, etc.

**Calls:**
- FUN_0058815f - format string
- FUN_00553070 - display/print

**Globals:**
- DAT_005ccef0 - format string
- Multiple DAT_007ceXXX - position/offset constants

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049f710 - Subtraction with Guard

Source: unknown | Confidence: medium
Conditionally computes difference with safety check.

**Key logic:**
- If param_4 != 0: calls FUN_005531f0 then stores param_2 - param_4 to *param_3

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0fb0 - Global Zero-Init

Source: unknown | Confidence: high
Zeros multiple DAT_ globals.

**Key logic:**
- DAT_007ce250 = 0, DAT_007ce258 = 0, DAT_007ce260 = 0
- DAT_007ce269 = 0, DAT_007ce26c = 0

**Globals:**
- DAT_007ce250, DAT_007ce258, DAT_007ce260, DAT_007ce269, DAT_007ce26c

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a21d0 - String Copy with Reverse

Source: unknown | Confidence: medium
Copies string to local buffer with reversal (actually strcpy with pointer arithmetic).

**Key logic:**
- Copies param_2 string byte-by-byte to local_48 buffer using pointer subtraction trick
- Sets local_8=1, local_4=0
- Calls FUN_004a2010(param_1, local_48, param_3, param_4)

**Algorithm family:** string copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a4050 - Accumulator with State Switch

Source: unknown | Confidence: medium
Updates accumulator based on state at +0x78.

**Key logic:**
- If +0x78 == 0: return no-op
- If +0x78 == 1: set +0x84=0, call FUN_004a2840()
- Else: +0x84 += param_2, call FUN_004a2840()

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a8b10 - Init with Sentinel Values

Source: unknown | Confidence: high
Initializes 3-dword struct with 0, -1, vtable.

**Key logic:**
- param_1[1]=0, param_1[2]=0xffffffff, *param_1=&PTR_LAB_005acc08

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1a50 - Init with Sentinel Pattern

Source: unknown | Confidence: high
Initializes 5-dword struct with 0/-1 pattern + vtable.

**Key logic:**
- param_1[1]=0, param_1[2]=0xffffffff, param_1[3]=0, param_1[4]=0xffffffff
- *param_1 = &PTR_LAB_005acc5c

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b25d0 - Float-to-Fixed Conversion with Clamp

Source: unknown | Confidence: high
Converts float values to fixed-point with clamping to min/max bounds.

**Key logic:**
- First channel: clamp *param_2 to [DAT_005acca8, DAT_005accac], multiply by DAT_0059e8ec, round to byte
- Second channel: clamp param_2[1] to [DAT_005acca0, DAT_005acca4], multiply by DAT_0059e91c, round to short
- Third channel: clamp param_2[2] same as first, store at +0x25
- Returns byte/short/byte packed

**Globals:**
- DAT_005accac, DAT_005acca8, DAT_005acca4, DAT_005acca0 - clamp bounds
- DAT_0059e8ec, DAT_0059e91c - conversion multipliers

**Algorithm family:** float-to-fixed conversion with saturation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2b60 - Bitfield Setter

Source: unknown | Confidence: high
Sets a 15-bit field within a 32-bit bitfield at +0x30.

**Key logic:**
- *(param_1+0x30) = (*(param_1+0x30) & 0xffc07fff) | (param_2 << 0xf)
- Replaces bits 15-29 with param_2

**Algorithm family:** bitfield manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4360 - Stream Read with Scale

Source: unknown | Confidence: medium
Reads from stream, conditionally scales value by constant.

**Key logic:**
- FUN_00566c00(param_3,4) - read 4 bytes
- If header flags match (0x20000000) and sub-flags zero:
  - Reads one more byte, scales: byte_val * DAT_005acd28 + param_2
- Else: stores raw param_2
- Reads remaining data based on size field

**Calls:**
- FUN_00566c00 - binary read (docs/08)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b5380 - Float Comparison List Iteration

Source: unknown | Confidence: medium
Iterates linked list comparing floats and calling per-entry handlers.

**Key logic:**
- Sets param_1+0x30 = param_2
- Iterates list at param_1+0x20
- For each node: compares float at +0x1bc and +0xc against param_2
- Calls FUN_004b3a90 with offset +0x1b8 or +8 depending on result
- Calls FUN_005001d0, FUN_005001f0, FUN_00500170, FUN_00500190, FUN_005001b0 for dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9cd0 - Single Call Wrapper

Source: unknown | Confidence: high
Delegates to FUN_004b86e0().

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba820 - Quad Zero-Init

Source: unknown | Confidence: high
Zeroes 4 dwords at param_1.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb200 - Multi-Level Allocation

Source: unknown | Confidence: medium
Complex multi-level allocation with node creation and linked list insertion.

**Key logic:**
- Allocates 4-byte root, then 0x180-byte block initialized via FUN_004b4450 x32
- Creates 0xc-byte node within linked list at param_1
- Creates sub-nodes for each 0xc-aligned offset in 0x180 range
- Uses dual linked lists at param_1[0..3] and param_1[4..7]

**Calls:**
- operator_new, FUN_004b4450

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bc320 - Field Copy

Source: unknown | Confidence: high
Copies +0x68 to +0x28, +0x2c to +0x24.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004be1d0 - Nested Loop Range Traversal

Source: unknown | Confidence: medium
Clamps 4 float-to-int conversions to [0,7], then iterates nested loop calling FUN_004bd9b0.

**Key logic:**
- Converts 4 floats to ints via __ftol, each clamped 0-7
- Double loop: outer = iVar4-iVar3+1, inner = param_1-iVar5+1
- Calls FUN_004bd9b0 in inner loop
- If any value was clamped: calls FUN_004bd9b0 one extra time

**Algorithm family:** bounded iteration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2760 - Delegated Field Getter

Source: unknown | Confidence: medium
Calls FUN_004c2850() and returns field at +0xb144 if non-null.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2fb0 - Registration Wrapper

Source: unknown | Confidence: high
Registers address via FUN_00587b3e.

**Calls:**
- FUN_00587b3e - atexit-like registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7774 - Bit Extraction + Global Field Copy

Source: unknown | Confidence: medium
Extracts bits from fields and copies to global struct.

**Key logic:**
- Extracts bit 25 of *(EDI+0x38), stores byte at EBX+0x1067
- Calls FUN_004b2b00, FUN_004c7bf0, FUN_004b2b80
- Copies bit 0 of *(EDI+0x3b) to EBX+0x4024
- Converts float from FUN_004b2b40(), stores at EBX+0x4028

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8580 - VTable Method Guard

Source: unknown | Confidence: medium
Calls vtable method at +8 on global DAT_008ac4c8.

**Key logic:**
- If DAT_008ac4c8 non-null: call virtual at +8, return 1 if non-zero
- Else: return 0

**Globals:**
- DAT_008ac4c8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9260 - State-Indexed Field Getter

Source: unknown | Confidence: high
Returns field at +0x20/+0x24/+0x28 based on state at +0x1c.

**Key logic:**
- If +0x1c==0: return +0x20; if 1: +0x24; if 2: +0x28; else 0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004cad30 - Hex String Parser

Source: unknown | Confidence: high
Parses a hex string (big-endian, reverse scan) to integer.

**Key logic:**
- Computes string length
- Scans backwards, converting hex chars (0-9, A-F, a-f) to nibbles
- Accumulates: iVar8 += nibble << (bit_offset); bit_offset += 4
- Returns parsed value

**Algorithm family:** string-to-integer conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004cf010 - Array Search by ID with Cleanup

Source: unknown | Confidence: medium
Searches array at stride 0x6c for matching ID, calls cleanup on match.

**Key logic:**
- Iterates *(param_1+0x10) entries at stride 0x6c starting at *(param_1+0x14)
- Compares entry+4 with param_2
- On match: calls FUN_004cb5e0()

**Algorithm family:** linear search with callback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d47a0 - Thread-Safe Read Wrapper

Source: unknown | Confidence: high
Delegates to FUN_0058803f with params reordered.

**Key logic:**
- FUN_0058803f(param_2, 1, param_3, param_1) - lock+read+unlock

**Calls:**
- FUN_0058803f - thread-safe read (wraps FUN_0058806e with lock)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d5ea0 - Division with Threshold

Source: unknown | Confidence: medium
Computes ratio with divisor clamped to minimum threshold.

**Key logic:**
- If param_3 > DAT_0059e440: fVar1 = param_3 (use param_3)
- Else: fVar1 = DAT_0059eae0 (use fallback)
- param_1[0] = (param_2 - DAT_0059e43c) / fVar1
- param_1[1] = fVar1

**Globals:**
- DAT_0059e440 (ZeroThreshold), DAT_0059eae0, DAT_0059e43c

**Algorithm family:** guarded division

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7e30 - VTable Dispatch with Field Clear

Source: unknown | Confidence: medium
Zeroes field +12, then calls virtual method at vtable+0x10.

**Key logic:**
- param_1[3] = 0
- (**(param_1)+0x10)() - virtual call

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d90d0 - Quad Render with Color

Source: unknown | Confidence: medium
Renders a quad/triangle strip with colors using FUN_00553650.

**Key logic:**
- If param_2 != 0:
  - Computes 4 corner positions from +0xe4, +0xe8 with scaling by globals
  - Calls FUN_00553650 4 times for each vertex with position + color (0x3f800000=white)
  - Vertex 0: (+0xe4*A, +0xe8*B) color white
  - Vertex 1: (+0xe4*A, +0xe8*A+B) color white
  - Vertex 2: combined position, color white
  - Vertex 3: combined position, color white

**Calls:**
- FUN_00553650 - vertex/primitive add

**Algorithm family:** quad rendering

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dbde0 - Text Render with Shadow

Source: unknown | Confidence: medium
Renders text twice (shadow then foreground) using FUN_004d7e40.

**Key logic:**
- Initializes buffer via FUN_0049c8f0
- Render shadow: FUN_004d7e40 with color 0xffffff at slightly offset position
- Calls FUN_0049c960 (blit)
- Render foreground: FUN_004d7e40 with color 0xffffff at normal position
- Uses param_1+0xf5 as text source, length 10

**Calls:**
- FUN_0049c8f0, FUN_004d7e40, FUN_0049c960

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcd10 - Resource Cleanup

Source: unknown | Confidence: medium
Releases sound resources and frees memory.

**Key logic:**
- If param_1[1] non-null: stop (FUN_005502c0), release (FUN_00557470), free (FUN_00587bcf)
- If *param_1 non-null: FUN_005539f0 (release sound)
- FUN_004dcb70() - final cleanup

**Calls:**
- FUN_005502c0, FUN_00557470, FUN_00587bcf, FUN_005539f0, FUN_004dcb70

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd6a0 - Bounding Box Update

Source: unknown | Confidence: medium
Updates AABB min/max from computed offsets.

**Key logic:**
- Calls FUN_0054b420 (get 3D offset) and FUN_004dd550 (get position)
- Accumulates offsets into min/max bounds
- Clamps param_2 (min) to computed values and param_3 (max) from computed values
- Element-wise min/max update for 3D AABB

**Algorithm family:** 3D AABB update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e16c0 - Field Read + Delegate

Source: unknown | Confidence: high
Reads 6 fields from param_1 and passes to FUN_0054b4d0.

**Key logic:**
- FUN_0054b4d0(param_1+8, +0xc, +0x10, +0x14, +0x18, +0x1c)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ec050 - 6-Field Struct Init

Source: unknown | Confidence: high
Stores 6 params into consecutive dword array.

**Key logic:**
- param_1[0..5] = param_2..param_7

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f6b80 - Registration Wrapper

Source: unknown | Confidence: high
Registers address via FUN_00587b3e.

**Calls:**
- FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8c90 - Module Unload

Source: unknown | Confidence: high
Calls function pointer from loaded module then frees library.

**Key logic:**
- If DAT_008afc78 (HMODULE) non-null:
  - Call function at DAT_008afc80
  - FreeLibrary(DAT_008afc78)
  - Zero the handle
  - Return 0
- Else: return 3 (not loaded)

**Globals:**
- DAT_008afc78 - loaded module handle
- DAT_008afc80 - function pointer from module

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9b70 - File Load with Retry Loop

Source: unknown | Confidence: medium
Loads a file with retry loop, displays progress UI.

**Key logic:**
- Calls FUN_00404fe0() for config, FUN_00551f10() for file load
- If load fails: copies param_1 to local buffer, retries with modified path
- Displays loading screen via FUN_00495140, FUN_005434a0 (progress)
- Loop: calls FUN_00551cf0() checking load status
- If param_2 flag set and DAT_007cb218 > 0: aborts
- On completion/error: calls cleanup functions

**Calls:**
- FUN_00551f10, FUN_00495140, FUN_005434a0, FUN_00551cf0, FUN_004c8580, etc.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004fc9c0 - Struct Init with Float Defaults

Source: unknown | Confidence: medium
Initializes a struct with float values and sentinel defaults.

**Key logic:**
- FUN_004fc850() and FUN_004fc280() - pre-init
- Sets *param_1 = 1.0f (0x3f800000)
- Zeroes many fields
- Sets sentinel values: +0x4a=0xffff, +0x13=0xffff, +0x4e=0, +0x14=0x7fff, +0x52=0x8000
- FUN_004fd6f0() - post-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00500680 - ID-to-Struct Table Lookup

Source: unknown | Confidence: high
Searches stride-9 array for matching ID, returns default if not found.

**Key logic:**
- Table at DAT_005ad508, upper bound at PTR_DAT_005d7150
- Step 9 ints per entry
- Returns matching entry ptr or &DAT_005ad4e0 (default)

**Algorithm family:** table lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00502c28 - Complex Memory Allocation with Float Computation

Source: unknown | Confidence: low
Complex allocation function with float-to-int conversions and nested loops. Possibly a DSP/buffer allocation function.

**Key logic:**
- Computes ratios from param_1/param_2
- Allocates memory via operator_new
- Nested loops with float computations, conversion to int via __ftol
- Uses DAT_0059e440 (ZeroThreshold), DAT_0059e450, DAT_005adb14, DAT_005ad260 globals
- Builds output structure with counts and offsets

**Algorithm family:** complex memory allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00504f5a - Multi-Level Buffer Allocation with Vector Ops

Source: unknown | Confidence: low
Complex buffer allocation with vector construction and float processing. Possibly texture/D3D buffer allocation.

**Key logic:**
- Checks state flags at extraout_ECX[2]
- Multi-level allocation based on size params at +0x1058, +0x105c, +0x1060
- Uses _vector_constructor_iterator_ for array construction
- Nested loops processing float vectors with multiplication and addition
- Multiple buffer levels with complex index arithmetic
- Calls vtable methods for data processing

**Calls:**
- FUN_0058a5d8, operator_new, _vector_constructor_iterator_, FUN_00587bcf

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050ae3e - Init with Class 8

Source: unknown | Confidence: high
Calls FUN_00507496(param_2, 8, 1) and sets vtable.

**Key logic:**
- FUN_00507496(param_2, 8, 1) - init with class size 8
- *param_1 = &PTR_FUN_005adc5c

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b462 - Init with Class 0x10

Source: unknown | Confidence: high
Calls FUN_00507496(param_2, 0x10, 1) and sets vtable.

**Key logic:**
- FUN_00507496(param_2, 0x10, 1) - init with class size 16
- *param_1 = &PTR_FUN_005add8c

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c20d - Dispatch with VTable Call

Source: unknown | Confidence: high
Calls FUN_0050fea7(1) then dispatches through PTR_FUN_005d7888.

**Key logic:**
- FUN_0050fea7(1) - sync/barrier
- (*(code *)PTR_FUN_005d7888)(params) - indirect call with 6 params

**Globals:**
- PTR_FUN_005d7888 - function pointer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d563 - Dispatch with VTable Call (4 param)

Source: unknown | Confidence: high
Calls FUN_0050fea7(1) then dispatches through PTR_FUN_005d7840.

**Key logic:**
- FUN_0050fea7(1) - sync/barrier
- (*(code *)PTR_FUN_005d7840)(param_1, param_2) - indirect call

**Globals:**
- PTR_FUN_005d7840 - function pointer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e0d3 - Indirect Jump Thunk

Source: unknown | Confidence: high
Indirect jump through DAT_005d78a8.

**Key logic:**
- (*_DAT_005d78a8)() - indirect function call

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050f904 - State Machine Dispatcher

Source: unknown | Confidence: low
State machine with states 0xcd, 0xce, 0xcf, 0xd2. Processes param_1 and delegates to vtable methods.

**Key logic:**
- Switch on param_1[4] (state)
- State 0xcd/0xce: sets error code, calls vtable, transitions to 0xd2
- State 0xcf: transitions to 0xd2
- State 0xd2: default handler
- Loop: checks param_1[99] flag, calls vtable methods

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00511869 - Guarded Call with longjmp

Source: unknown | Confidence: medium
Optionally calls callback, then longjmps.

**Key logic:**
- If param_1[0x10] non-null: call it with (param_1, param_2)
- _longjmp(param_1, 1) - never returns

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00512850 - Bit Expand/Decompress

Source: unknown | Confidence: medium
Decompresses/expands packed bits to bytes.

**Key logic:**
- If byte at param_1+9 == 0x10:
  - Iterates (param_1[0] * param_1+10) times
  - Copies every other byte from param_2 source
  - Sets mode to 8, adjusts bit counts

**Algorithm family:** bit unpacking/decompression

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005158af - Delegation with Error Check

Source: unknown | Confidence: medium
Calls FUN_00513e2d() and FUN_00515303() with error propagation.

**Key logic:**
- If FUN_00513e2d() >= 0: call FUN_00515303(param_1, local_104)
  - If >= 0: return 0
  - Else: propagate error
- Returns error code

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051664f - Offset Validation with Buffer Update

Source: unknown | Confidence: low
Validates buffer offsets and expands buffer if needed.

**Key logic:**
- Checks param_2 buffer bounds against param_3/param_4
- On overflow: sets error code at *param_1+0x14, calls vtable handler
- Adjusts buffer size at param_2[6] and param_2[7]
- Optionally processes entries via FUN_005159a8
- Returns pointer to element at computed offset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00517e85 - Guarded Delegate

Source: unknown | Confidence: high
Calls FUN_0058aa6f() if param_1 != 0.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051aefc - Counter Update with Zero

Source: unknown | Confidence: low
Updates counter at +0x58 by value from +0x194�8, zeroes source.

**Key logic:**
- *(*(EDI+400)+0x58) += *(EDI+0x194)+0x14 / 8
- *(EDI+0x194+0x14) = 0
- Calls vtable method at (EDI+400)+8
- If returns non-zero: zeroes range at iVar2+0x24 for iVar2+0x120 entries
- Sets fields and returns 1

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005215db - Packed Floating-Point Math (SIMD)

Source: unknown | Confidence: low
Complex packed floating-point multiplication, addition, reciprocal, and compare operations. Likely 3D math / SIMD.

**Key logic:**
- Uses PackedFloatingMUL, ADD, SUB, Accumulate, CompareGE
- Computes packed floating reciprocal via PackedFloatingReciprocalSQRAprox
- Iterative refinement: RecipSQRIter1, RecipIter2, FloatingReciprocalAprox
- PackedFloatingMUL with input vectors param_2, param_3
- Stores result in *param_1 and param_1[1]

**Algorithm family:** packed/SIMD floating-point math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052803a - Delegation Wrapper

Source: unknown | Confidence: high
Calls FUN_0058ab58(param_2, param_3).

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052df90 - CPUID Feature Check (MMX/SSE)

Source: unknown | Confidence: high
Checks CPU feature flags via cpuid instruction.

**Key logic:**
- Calls cpuid_Version_info(1)
- Checks bit 23 of result+8 (SSE/MMX flag: 0x800000)
- If clear: returns 0xffffff00
- If set: returns 0xffffff01

**Algorithm family:** CPU feature detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005351d0 - Line Input Reader

Source: unknown | Confidence: medium
Reads a line of input with character-by-character check.

**Key logic:**
- Iterates up to param_3 characters
- Calls FUN_00534f90(1) each iteration
- Breaks on newline or if function returns != 1
- Null-terminates the string
- Returns string pointer or null if empty

**Algorithm family:** line input

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00537000 - State Reset with Callback

Source: unknown | Confidence: medium
Resets state variables and calls optional callback.

**Key logic:**
- If param_3 non-null: *param_3 = param_1[0xf]
- If *param_1 in {4,5}: calls vtable+0x24 method
- If *param_1 == 6: calls FUN_00539f60()
- Resets *param_1=0, copies param_1[10] to +0xd and +0xc, sets +0x7=+0x8=0
- If param_1[0xe] non-null: calls it(0), stores result

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b160 - Empty Stub

Source: unknown | Confidence: high
Empty function - bare return. Placeholder or stripped virtual method.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c210 - Registration Wrapper

Source: unknown | Confidence: high
Registers address via FUN_00587b3e.

**Calls:**
- FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d130 - String Compare Linked List Search

Source: unknown | Confidence: medium
Searches linked list for matching wide string, frees param_1 on match.

**Key logic:**
- Iterates linked list at DAT_008b8e20 (stride 0x870)
- Compares wide strings (2-byte chars) at +0x14
- On match: calls FUN_0053d3a0(), FUN_00552760(), FUN_00557470(), FUN_00587bcf(param_1)
- Uses string comparison with carryless comparison logic

**Globals:**
- DAT_008b8e20 - linked list head

**Algorithm family:** string matching with linked list walk

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00540050 - Resource Load with Output

Source: unknown | Confidence: medium
Loads a resource with output fields for result data.

**Key logic:**
- FUN_005006d5(param_2, param_3, &local_1c)
- If error: sets *param_1, returns 0xffffffff
- Optionally writes local_1c and local_18 to param_4/param_5
- If param_6 != 0: calls FUN_0055c450(local_c, 0, param_6)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005423e0 - Color Pack (RGB)

Source: unknown | Confidence: high
Packs three byte values into a single dword at param_1+0x7c.

**Key logic:**
- param_1+0x7c = (param_2 * 0x100 + param_3) * 0x100 + param_4
- Packs as 24-bit RGB: param_2<<16 | param_3<<8 | param_4

**Algorithm family:** color packing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00543a60 - Field Getter

Source: unknown | Confidence: high
Reads field at +400 (0x190) and optionally writes to output.

**Key logic:**
- If param_2 non-null: *param_2 = *(param_1 + 400)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005470a0 - Guarded Render State Set

Source: unknown | Confidence: medium
Checks bounds then sets render states.

**Key logic:**
- If param_2 < param_1+0xa4 < 8: calls FUN_0054fc40, 0054fc80, 0054fd30, 0054fca0

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547920 - String Search in Linked List

Source: unknown | Confidence: medium
Searches linked list of strings for case-insensitive match.

**Key logic:**
- Copies param_2 to local buffer, normalizes case via FUN_00589901
- Walks linked list starting at param_1+0x28 (+0x5c next)
- Compares wide strings (2-byte) using carryless comparison
- If node+0x4c == 1: single match per node
- Else: scans stride-0x60 array within node
- Returns matching node pointer or 0

**Algorithm family:** string search in linked list

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005492f0 - Linked List String Insert

Source: unknown | Confidence: medium
Allocates and inserts a string node into linked list.

**Key logic:**
- If param_1+0xf8 empty: allocates 0x18-byte node, stores at +0xf8
- Else: walks to tail (+0x14 chain), allocates and appends
- Copies param_2 string to node via pointer subtraction trick
- Normalizes string via FUN_00589901

**Calls:**
- operator_new, FUN_00548e00, FUN_00589901

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054bc60 - Recursive Tree String Search

Source: unknown | Confidence: medium
Recursively searches a tree structure for matching wide string.

**Key logic:**
- Recursive calls to children at +0x44 and +0x4c
- At leaf: performs wide string comparison
- Sets *param_3 = param_1 on match
- Uses carryless comparison for wide chars

**Algorithm family:** tree search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054ee90 - 2D Cross Product (Perp Dot)

Source: unknown | Confidence: high
Computes 2D cross product (perp dot product) of two vectors.

**Key logic:**
- Returns (a[p4] - b[p4]) * (c[p5] - b[p5]) - (c[p4] - b[p4]) * (a[p5] - b[p5])
- Where a=param_1, b=param_2, c=param_3 as float arrays indexed by p4/p5

**Algorithm family:** 2D cross product / perp dot

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00550ac0 - Call Wrapper Returning 0

Source: unknown | Confidence: high
Calls FUN_00550f70() and returns 0.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005573f0 - Dual Delegate

Source: unknown | Confidence: high
Calls FUN_0053b160() (empty stub) and FUN_004b0170().

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c9b0 - Struct Field Getter

Source: unknown | Confidence: high
Returns field at param_1+0x1550.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005644a0 - Short Field Getter

Source: unknown | Confidence: high
Returns short at param_1+4.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00567740 - FPU Control Word Mask Extract

Source: unknown | Confidence: high
Extracts bits 8-9 (0x300 mask) from FPU control word.

**Key logic:**
- Returns in_FPUControlWord & 0x300

**Algorithm family:** FPU status query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a160 - Constructor: VTable Set + Init

Source: unknown | Confidence: high
Constructor with vtable assignment and init call.

**Key logic:**
- *param_1 = &PTR_LAB_005b8a00
- FUN_0057a1e0() - init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057b2e0 - Struct Field Getter

Source: unknown | Confidence: high
Returns field at param_1+0x24.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585440 - Clamp/Min - Store Min Value

Source: unknown | Confidence: high
Stores min(FUN_00587890(), param_2) to param_1+0x80.

**Key logic:**
- iVar1 = FUN_00587890()
- If iVar1 < param_2: *(param_1+0x80) = iVar1
- Else: *(param_1+0x80) = param_2

**Algorithm family:** min/clamp

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005873f0 - Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00598815().

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00588570 - Float-Convert Wrapper

Source: unknown | Confidence: high
Converts float80 to double and calls two functions.

**Key logic:**
- FUN_0058dd28((double)in_ST0) - convert and process
- FUN_0058858d() - post-call

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a9da - Thunk to FUN_0058e04b(9)

Source: unknown | Confidence: high
Calls FUN_0058e04b with argument 9.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058e4a8 - Clear Struct Fields if Flag Set

Source: unknown | Confidence: high
Clears struct fields if byte flag at param_2+0xd has bit 0x10 set.

**Key logic:**
- If param_1 != 0 AND (param_2+0xd & 0x10): 
  - FUN_0058a05a(param_2) - cleanup
  - Clears bits 0x10 and 0x11 from flag
  - Zeroes param_2[6], *param_2, param_2[2]

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059553a - Delegation with Static Data

Source: unknown | Confidence: high
Calls FUN_005953b8(param_1, param_2, &DAT_005e99b8).

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598750 - Delegation with Fixed Args

Source: unknown | Confidence: high
Calls FUN_00598a41(0, 1).

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599942 - Callback Registration

Source: unknown | Confidence: high
Registers callback at LAB_0059994e via FUN_00587b3e.

**Calls:**
- FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059bf19 - String Copy Constructor

Source: unknown | Confidence: high
String copy constructor: allocates, copies string, sets refcount.

**Key logic:**
- *param_1 = &PTR_FUN_005b9dc0 (vtable)
- _strlen(*param_2) + 1 bytes allocated via operator_new
- Copies string via FUN_0058fca0
- Sets refcount at param_1[2] = 1

**Algorithm family:** string construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c8a4 - SEH Unwind Helper

Source: unknown | Confidence: high
C++ unwind helper - thunk to FUN_00581ee0.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cf94 - SEH Unwind Helper

Source: unknown | Confidence: high
C++ unwind helper - thunk to FUN_00581750.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d806 - Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00443f71().

**Moddability:** hardcoded

## FUN_0050e198 — Thunk to FUN_0050e174

Source: unknown | Confidence: high
Trampoline — indirect jump via PTR_FUN_005d7854. No local logic.

**Key logic:**
- Single indirect call via function pointer at PTR_FUN_005d7854
- The sibling function FUN_0050e174 calls FUN_0050fea7(1) first (PSGP init) then calls the same pointer
- This thunk skips the PSGP init call — used as a direct pipeline entry without shader setup

**Calls:** (indirect) via PTR_FUN_005d7854 (renderer function pointer)

**Used by system:** docs/19-renderer.md — DirectX renderer pipeline dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00557410 — Struct Zero-Init with Defaults

Source: unknown | Confidence: high
Initializes a struct with zeroed fields and float default constants.

**Key logic:**
- Calls FUN_0053c2a0() — parent constructor / mixer init
- Zeros fields at offsets: +0x00 (byte), +0x20 through +0x38 (7 ints), +0x40, +0x3c, +0x4c, +0x50, +0x44, +0x48, +0x64, +0x68
- Sets float defaults at:
  - +0x54 = 1.0f (0x3f800000)
  - +0x58 = 1.0f (0x3f800000)
  - +0x5c = 1.0f (0x3f800000)
  - +0x60 = 100.0f (0x42c80000)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | type/tag | byte | Zeroed |
| +0x20–+0x38 | data0–data6 | int[7] | Zeroed (contiguous) |
| +0x3c–+0x50 | data7–data11 | int[5] | Zeroed |
| +0x54 | scaleX | float | Default 1.0 |
| +0x58 | scaleY | float | Default 1.0 |
| +0x5c | scaleZ | float | Default 1.0 |
| +0x60 | speed/param | float | Default 100.0 |
| +0x64 | field_64 | int | Zeroed |
| +0x68 | field_68 | int | Zeroed |

**Calls:** FUN_0053c2a0 — parent struct init / mixer setup

**Used by system:** docs/20-math-utilities.md — struct/data object constructor

**Algorithm family:** data structure initialization

**Moddability:** hookable — values are compile-time hardcoded defaults

<!-- target: docs/08-file-formats.md -->

## FUN_0055d3f0 — Byte Extraction from uint

Source: unknown | Confidence: high
Extracts three bytes from a uint32 and forwards to text layout function.

**Key logic:**
- param_1 = target, param_2 = source uint
- Extracts bytes: (param_2 >> 16) & 0xff, (param_2 >> 8) & 0xff, param_2 & 0xff
- Calls FUN_0055d320(param_1, b2, b1, b0)

**Calls:** FUN_0055d320 — UI text bounding box layout (docs/20-math-utilities)

**Used by system:** docs/20-math-utilities.md — UI text layout helper

**Algorithm family:** bit extraction / UI layout

**Moddability:** hookable — pure parameter transformation

<!-- target: docs/20-math-utilities.md -->

## FUN_00560f40 — Doubly-Linked Node Removal & Global List Re-Insert

Source: unknown | Confidence: medium
Removes a node from current doubly-linked list, re-inserts at tail of global list (DAT_008b8f28).

**Key logic:**
- Unlinks param_2 from local list (prev/next at +0x30/+0x34)
- If param_2 is head of local list (param_1+0x2c): updates head to node->next
- Appends param_2 to global list at DAT_008b8f28+0x15c (tail pointer)
  - If tail null: sets global root to param_2
  - Else walks to tail via +0x34, appends, sets prev/next
- Clears bit 0x2 at node+0x24 (in-list flag)

**Struct offsets (param_2):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x24 | Flags | uint | Bit 0x2 cleared |
| +0x30 | prev | int* | Previous node |
| +0x34 | next | int* | Next node |

**Globals:**
- `DAT_008b8f28` — global scene/renderer list root (+0x15c = tail)

**Used by system:** docs/01-engine-architecture.md — scene graph / render list management

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00565f20 — Linked List Node Peek

Source: unknown | Confidence: medium
Peeks at next entry in a linked list, advancing head pointer.

**Key logic:**
- Reads *param_1 as list head pointer iVar1
- If *(iVar1+8) (next pointer) is non-null: updates it to *(*(iVar1+8)+4) (advances one step)
- piVar2 = *(iVar1+8) (current list entry)
- If piVar2 is non-null and *piVar2 ≠ 0: returns 0x100 | 0x01 (0x101)
- Else: returns lower byte shifted to high byte (essentially 0 or status)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | headPtr | int* | Current list head |
| *(headPtr)+0x08 | nextPtr | int* | Next entry in list |

**Used by system:** docs/20-math-utilities.md — linked list traversal utility

**Algorithm family:** linked list operations

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005698e0 — Buffer Entry Append with Matrix Init

Source: unknown | Confidence: medium
Allocates a new entry in a buffer, sets metadata, inits transform matrix.

**Key logic:**
- Computes entry offset: `param_1[0x234] * 0x84 + param_1[0x238]` — stride 0x84 (132) per entry
- Increments entry count at param_1+0x234
- Stores param_5 at +0x78 (user data), param_3 at +0x7c, param_4 at +0x80
- Calls FUN_0056c3a0(iVar1+0x18, iVar1+0x30) — 3x4 matrix init (transform)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x234 | entryCount | int | Incremented each call |
| +0x238 | baseOffset | int | Base offset for stride calc |

**Struct offsets (entry buffer):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x18 | transform1 | float[12] | 3x4 matrix (via FUN_0056c3a0) |
| +0x30 | transform2 | float[12] | Second 3x4 matrix |
| +0x78 | userData | int | Written from param_5 |
| +0x7c | param3 | int | Written from param_3 |
| +0x80 | flag | byte | Written from param_4 |

**Calls:** FUN_0056c3a0 — 3x4 matrix copy/init (docs/20-math-utilities)

**Used by system:** docs/20-math-utilities.md — transform buffer / render entry allocation

**Algorithm family:** buffer management / matrix operations

**Moddability:** hookable — param values passed as arguments

<!-- target: docs/01-engine-architecture.md -->

## FUN_005830c0 — Object Allocation with SEH

Source: unknown | Confidence: high
Allocates pool control block with SEH protection, initializes 2 slots.

**Key logic:**
- SEH setup (puStack_8 = &LAB_0059ce2b)
- operator_new(0x207c) — allocates 0x207c-byte block
- On success: *puVar1 = 2, calls FUN_0058a6eb(puVar1+1, 0x103c, 2, FUN_00582110, FUN_0047aa60)
  - 2 slots of 0x103c bytes each, construct FUN_00582110, destruct FUN_0047aa60
  - *param_1 = puVar1+1 (output handle)
- On failure: *param_1 = 0
- SEH teardown

**Calls:**
- operator_new — heap alloc
- FUN_0058a6eb — array init (memset + constructors)
- FUN_00582110 — SocketAddressInit constructor (docs/21)
- FUN_0047aa60 — small destructor (docs/19)

**Used by system:** docs/20-math-utilities.md — pool allocator for network/audio objects

**Algorithm family:** SEH-protected pool allocation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058aa39 — Mutex Unlock Wrapper

Source: unknown | Confidence: high
Thin wrapper calling FUN_0058e04b(9) to release critical section index 9.

**Key logic:**
- Calls FUN_0058e04b(9) — leaves critical section at DAT_005e6c80 + 9*4

**Calls:** FUN_0058e04b — LeaveCriticalSection by index (docs/20-math-utilities)

**Used by system:** docs/20-math-utilities.md — threading synchronization wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058e04b — CritSect Leave (generic)

Source: unknown | Confidence: high
Leaves a critical section selected by index from a global table.

**Key logic:**
- Calls LeaveCriticalSection on DAT_005e6c80[param_1] — indexed critical section table
- DAT_005e6c80 is an array of LPCRITICAL_SECTION pointers (stride 4)

**Globals:**
- `DAT_005e6c80` — global critical section pointer table

**Calls:** LeaveCriticalSection — Win32 API

**Used by system:** docs/20-math-utilities.md — threading synchronization leave

**Algorithm family:** synchronization wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00591cc6 — Bit Flag Decoder via Bit Tests

Source: unknown | Confidence: high
Decodes a byte parameter into a 5-value enum using bit tests.

**Key logic:**
- Tests bits of param_1 in order:
  - bit 0x20 (5): returns 5
  - bit 0x08 (3): returns 1
  - bit 0x04 (2): returns 2
  - bit 0x01 (0): returns 3
  - bit 0x02 (1): returns 2 << 1 = 4
- Returns decoded value 1–5 based on which bit is set
- Only one bit expected to be set at a time

**Used by system:** docs/20-math-utilities.md — bitfield/flag decoding

**Algorithm family:** bit decoding

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005951be — Check if Bit Range is Clear Across Dwords

Source: unknown | Confidence: high
Tests whether a range of bits across up to 3 dwords is entirely clear.

**Key logic:**
- param_1 = bitfield base pointer, param_2 = bit index
- Computes dword index: param_2 / 0x20, bit position: param_2 % 0x20
- Tests bit at computed position; if set, returns 0
- Tests remaining dwords from index+1 to 2 (up to 3 dwords):
  - If any dword non-zero, returns 0
- Returns 1 (all clear)

**Used by system:** docs/20-math-utilities.md — bitfield range test

**Algorithm family:** bitfield operations

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00597568 — CRT ___add_12 (128-bit Addition)

Source: MSVC CRT | Confidence: high
Visual Studio 2003 Release CRT — 128-bit integer addition with carry propagation.

**Key logic:**
- Library ___add_12: adds two 128-bit values (3 dwords each)
- param_1[0] += param_2[0]; if overflow: param_1[1] += 1
- param_1[1] += param_2[1]; if overflow: param_1[2] += 1
- param_1[2] += param_2[2]
- Uses FUN_00597547 as add-with-carry primitive

**Calls:** FUN_00597547 — add-with-carry (CRT intrinsic)

**Used by system:** docs/20-math-utilities.md — MSVC CRT big integer

**Algorithm family:** big integer addition

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599465 — Ref Count Inc/Dec

Source: unknown | Confidence: high
Increments one counter, decrements another via double indirection.

**Key logic:**
- Reads counter ptr at param_1+0x2c, derefs, increments
- Reads counter ptr at param_1+0x1c, derefs, decrements
- Returns decremented value (ref count at +0x1c)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1c | int* | Pointer to ref counter (decremented) |
| +0x2c | int* | Pointer to ref counter (incremented) |

**Used by system:** docs/20-math-utilities.md — reference counting

**Algorithm family:** reference counting

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a43c — Stream Buffer Pointer Adjust

Source: unknown | Confidence: medium
Adjusts stream buffer pointers — decrements by 1, increments by 2.

**Key logic:**
- Reads counter ptr at param_1+0x30, derefs, decrements by 1
- Reads counter ptr at param_1+0x20, derefs, increments by 2
- Likely read position (-1) and skip distance (+2)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x20 | int* | Pointer to position counter (+=2) |
| +0x30 | int* | Pointer to position counter (-=1) |

**Used by system:** docs/20-math-utilities.md — stream/CRT internal tracking

**Algorithm family:** stream I/O internals

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00401130 — Short Computation (Triple Free + Cleanup)

Source: unknown | Confidence: high
Frees up to 3 allocated pointers, calls cleanup.

**Key logic:**
- If param_1+0x150 non-null: frees via FUN_00587bcf
- If param_1+0x154 non-null: frees via FUN_00587bcf
- If param_1+0x158 non-null: frees via FUN_00587bcf
- Calls FUN_004034d0() — cleanup

**Calls:**
- FUN_00587bcf — memory deallocation (×3)
- FUN_004034d0 — cleanup

**Used by system:** docs/20-math-utilities.md — data structure destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404d30 — Short Computation (Indirect Field Setter)

Source: unknown | Confidence: high
Writes param_2 to *(param_1)+0x18 through double indirection.

**Key logic:**
- Reads *param_1 as pointer to object, writes param_2 to +0x18

**Used by system:** docs/20-math-utilities.md — indirect field setter

**Moddability:** hookable

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00408250 — Short Computation

Source: unknown | Confidence: high
Delegates to FUN_0040bde0.

**Key logic:**
- Calls FUN_0040bde0() — cleanup or continue

**Calls:** FUN_0040bde0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040ac40 — VTable Switch

Source: unknown | Confidence: medium
Switches vtable pointer with conditional destructor call.

**Key logic:**
- Sets *param_1 = &PTR_LAB_0059e678 (first vtable)
- If param_1[3] non-null: calls vtable dispatch on it (*(**(code**)**param_1[3])(3))
- Sets *param_1 = &PTR_LAB_0059e634 (second vtable)

**Used by system:** docs/20-math-utilities.md — object vtable management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040c910 — Short Computation (Indirect Read)

Source: unknown | Confidence: high
Returns *(*(param_1+8)+4) — double-indirect read.

**Key logic:**
- Returns *(int*)(*(int*)(param_1+8) + 4)

**Used by system:** docs/20-math-utilities.md — linked list / struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040dd80 — Short Computation (State Machine)

Source: unknown | Confidence: medium
State machine with switch on *param_1+1, reads global.

**Key logic:**
- uVar1 = *param_1 + 1
- Switch: cases 3/4 → calls FUN_0040c870, sets param_1[0x23..0x25], reads DAT_007c54dc, sets state to 4
- Case 5 → returns success (0x101)
- Default → sets *param_1 = -1
- Cases 0/1/2/6 → fallthrough

**Globals:**
- `DAT_007c54dc` — unknown (near PlayerVehiclePtr)

**Calls:** FUN_0040c870

**Used by system:** docs/20-math-utilities.md — state/progress machine

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040f0d0 — Short Computation (Conditional Multi-Init)

Source: unknown | Confidence: medium
If *param_1 == -1, calls three init functions.

**Key logic:**
- If *param_1 == -1 (uninitialized):
  - Calls FUN_00410ad0(param_1)
  - Calls FUN_004be180(param_1)
  - Calls FUN_004bde20(param_1)

**Calls:**
- FUN_00410ad0
- FUN_004be180
- FUN_004bde20

**Used by system:** docs/20-math-utilities.md — lazy initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00411330 — Short Computation (Vehicle Parameter Setter)

Source: unknown | Confidence: medium
Sets vehicle parameter value by type (3/4/5) with lookup tables.

**Key logic:**
- param_2 selects parameter type (3, 4, or 5)
- For type 3: accesses via param_1+0x4c, stride 0x24, indexed by param_4×4 + param_5
- For type 4: accesses via param_1+0x58, stride 0x24, with sub-index on param_5==0
- For type 5: accesses via param_1+0x64, stride 0x24, indexed by param_4×8 + param_5
- All paths add _DAT_007d0ad4 + *param_6 to field at +0x1c
- Calls FUN_0040e770, FUN_0040eec0, FUN_0040ef70
- Sets byte at iVar2+0xa = 1 (dirty/updated flag)

**Globals:**
- `DAT_007d0ad4` — global float offset

**Calls:**
- FUN_0040e770, FUN_0040eec0, FUN_0040ef70

**Used by system:** docs/20-math-utilities.md — vehicle parameter assignment

**Moddability:** configurable — values read from tables DAT_005ecf0c, DAT_005ed3ac, DAT_005ed434

<!-- target: docs/20-math-utilities.md -->

## FUN_00414370 — Short Computation (Conditional Free)

Source: unknown | Confidence: high
If *param_1 non-null, frees it.

**Key logic:**
- If *param_1 != 0: FUN_00587bcf(*param_1)

**Calls:** FUN_00587bcf — memory deallocation

**Used by system:** docs/20-math-utilities.md — pointer cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418900 — Short Computation (Multi-Init + Cleanup)

Source: unknown | Confidence: medium
Calls two init functions, then conditionally calls destructor.

**Key logic:**
- Calls FUN_00411740(0) and FUN_00411740(1) — init
- Calls FUN_004150c0() — init
- If param_1+0xaf4 (object ptr) non-null: calls vtable dispatch(1) then zeros pointer

**Calls:**
- FUN_00411740 — init function (×2)
- FUN_004150c0 — init function

**Used by system:** docs/20-math-utilities.md — resource init/deinit

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041ed30 — CRT Math Helper

Source: unknown | Confidence: medium
Accumulates values from repeated calls, returning count-sum.

**Key logic:**
- Calls FUN_004c2850() — get count/state
- If non-zero: calls FUN_004c11d0() — get limit
- If limit >= 2: calls FUN_0041eb30() — init
- Loop: calls FUN_0041ed20() accumulating into iVar3
- Returns iVar3 (accumulated sum - 1)

**Calls:**
- FUN_004c2850 — count/state query
- FUN_004c11d0 — limit query
- FUN_0041eb30 — init
- FUN_0041ed20 — value accumulator

**Used by system:** docs/20-math-utilities.md — CRT math/computation helper

**Algorithm family:** summation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_00423060 — Short Computation (Accessor)

Source: unknown | Confidence: high
Returns *(param_1 + 0xc4) — field accessor.

**Key logic:**
- Returns int at param_1+0xc4

**Used by system:** docs/20-math-utilities.md — struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0042e1f0 — CRT Math Helper (Bounded Scale)

Source: unknown | Confidence: medium
Scales two double values by param_5, clamps result within bounds.

**Key logic:**
- If param_3 non-zero:
  - Calls FUN_00565aa0(param_3, param_1, param_1+1, ...) — string/number parse
  - On success: truncates result via __ftol, stores at param_1+2
  - param_1[0] *= param_5, param_1[1] *= param_5 (scale doubles)
- Calls FUN_00565760(param_4, piVar2, ...) — clamp/convert
  - If param_1[2] > 0: clamps *piVar2 to [0, param_1[2]-1]
  - Else: sets *piVar2 = 0

**Calls:**
- FUN_00565aa0 — string/number parse
- FUN_00565760 — clamp function
- __ftol — MSVC float-to-long conversion

**Used by system:** docs/20-math-utilities.md — CRT math helper, bounded value scaling

**Algorithm family:** value scaling with bounds

**Moddability:** hookable — scale factor passed as param_5

<!-- target: docs/20-math-utilities.md -->

## FUN_00456080 — Short Computation (Two-Field Accessor)

Source: unknown | Confidence: high
Returns values at +0x40 and +0x44 through output pointers.

**Key logic:**
- If param_2 non-null: writes param_1+0x40 to *param_2
- If param_3 non-null: writes param_1+0x44 to *param_3

**Used by system:** docs/20-math-utilities.md — field pair accessor

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004582e0 — Buffer Alloc + Copy (0x1c stride)

Source: unknown | Confidence: medium
Allocates buffer array with 0x1c-byte stride entries, copies from indexed source.

**Key logic:**
- Validates *param_2 != 0 and param_2[1] > 3
- Calls FUN_00458020() — pre-init
- operator_new(iVar1 * 0x1c + 4) — allocates array
- Stores count at base, returns ptr+1 as working pointer
- Copies iVar1 entries: each entry = 7 dwords (0x1c bytes) from FUN_004582a0(i)
- Calls FUN_00457ee0() — post-cleanup

**Calls:**
- FUN_00458020, FUN_004582a0, FUN_00457ee0, operator_new

**Used by system:** docs/20-math-utilities.md — array allocation/copy

**Algorithm family:** array allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bb40 — Short Computation

Source: unknown | Confidence: high
Calls FUN_0045b360, returns param_1.

**Key logic:**
- Calls FUN_0045b360()

**Calls:** FUN_0045b360

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045c400 — Unidentified (Validation Pipeline)

Source: unknown | Confidence: low
Large function with 7 validation checks and up to 7 conditional frees.

**Key logic:**
- Calls init/check functions (FUN_005881c0, FUN_0042e320, FUN_004f34e0, FUN_004f4270)
- 7x FUN_00568a60() check → accumulates into accumulator
- Frees 7 conditional pointers via FUN_00587bcf
- Calls FUN_0042ddd0() — cleanup
- Returns AND of all 7 validation flags

**Calls:**
- FUN_005881c0, FUN_0042e320, FUN_004f34e0, FUN_004f4270
- FUN_00568a60 (×7), FUN_00587bcf (×up to 7), FUN_0042ddd0

**Used by system:** docs/20-math-utilities.md — validation pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045e5d0 — Short Computation (Array Setter)

Source: unknown | Confidence: high
Writes param_3 to indexed array at param_1+0x1d4[param_2].

**Key logic:**
- *(param_1 + 0x1d4 + param_2*4) = param_3

**Used by system:** docs/20-math-utilities.md — indexed array setter

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00461c70 — Short Computation (Large Alloc + Init)

Source: unknown | Confidence: high
Allocates 0x1ce60-byte buffer, calls init function.

**Key logic:**
- operator_new(0x1ce60) — ~118KB alloc
- Calls FUN_0045d530(param_1), stores result
- On failure: stores 0

**Calls:** operator_new, FUN_0045d530

**Used by system:** docs/20-math-utilities.md — large buffer allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462530 — Short Computation (Float Process)

Source: unknown | Confidence: high
Processes float through FUN_0045ca20.

**Key logic:**
- Calls FUN_0045ca20(param_1, &param_1, 0)
- Returns processed value

**Calls:** FUN_0045ca20

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** float processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464600 — Unidentified (Scene/Camera Check)

Source: unknown | Confidence: low
Conditional scene/camera/vehicle checks before processing.

**Key logic:**
- If DAT_007ce260 == 0 (scene active):
  - Calls FUN_004b16b0() — pre-check
  - If *(param_1[0] + 0x3fc4) non-null (vehicle): calls FUN_00463140, FUN_0045d500
  - Calls FUN_0057a910() — audio/ambient update
  - If flags at param_1[0]+0xc5 or +0xc6 non-zero: calls FUN_004a0de0(), returns

**Globals:**
- `DAT_007ce260` — scene active flag

**Calls:**
- FUN_004b16b0, FUN_00463140, FUN_0045d500, FUN_0057a910, FUN_004a0de0

**Used by system:** docs/20-math-utilities.md — conditional scene processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464d30 — Unidentified (Struct Reinit with List Cleanup)

Source: unknown | Confidence: low
Resets a large struct, frees 4 linked lists, zeroes counters.

**Key logic:**
- Stores param_2 to *param_1
- Calls FUN_00568c60() — time/random init
- Sets param_1[0x18..0x1a] = 0, 0x3f800000 (1.0f), 0
- Frees linked list at param_1[0x1b] (4-field list, free nodes via FUN_00587bcf)
- Frees linked list at param_1[0x1f] (same pattern)
- Loops calling FUN_00464a40() until flag set
- Zeros param_1[0x3903]
- Frees linked list at param_1[0x396c] and [0x3970] (same pattern)

**Calls:** FUN_00568c60, FUN_00587bcf, FUN_00464a40

**Used by system:** docs/20-math-utilities.md — struct reinit with list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466270 — Short Computation (Flag Set)

Source: unknown | Confidence: high
Sets flag at param_1+0xf5 = 1, calls FUN_004988a0(3).

**Key logic:**
- Calls FUN_004988a0(3)
- Sets param_1+0xf5 = 1
- Returns 0

**Calls:** FUN_004988a0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004692a0 — Short Computation

Source: unknown | Confidence: high
Calls FUN_00468ee0(0), returns 0.

**Key logic:**
- Calls FUN_00468ee0(0)

**Calls:** FUN_00468ee0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046c6f0 — Short Computation (Constructor-like)

Source: unknown | Confidence: medium
Calls init, sets flag from param_2, sets vtable.

**Key logic:**
- FUN_004893c0() — base init
- param_1[0x5d] = param_2 (flag)
- *param_1 = &PTR_FUN_0059fb58 (vtable)

**Calls:** FUN_004893c0

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046e7d0 — Short Computation (Constructor-like)

Source: unknown | Confidence: medium
Calls init, sets vtable, zeros flag.

**Key logic:**
- FUN_004893c0() — base init
- *param_1 = &PTR_FUN_0059fe18 (vtable)
- param_1[0x5d] = 0

**Calls:** FUN_004893c0

**Used by system:** docs/20-math-utilities.md — object constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004702f0 — Short Computation (VTable Set)

Source: unknown | Confidence: high
Sets vtable, calls FUN_0048b4e0.

**Key logic:**
- *param_1 = &PTR_LAB_005a0308
- FUN_0048b4e0()

**Calls:** FUN_0048b4e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00472340 — Short Computation (VTable Set + Init)

Source: unknown | Confidence: high
Constructor-like: init, set vtable, sub-init.

**Key logic:**
- FUN_0048c070(1)
- *param_1 = &PTR_FUN_005a1e00
- FUN_00472400()

**Calls:** FUN_0048c070, FUN_00472400

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00473ed0 — Constructor with Defaults

Source: unknown | Confidence: medium
Constructor setting vtable and multiple default fields.

**Key logic:**
- FUN_00466d60(1)
- *param_1 = &PTR_FUN_005a3300
- param_1[199] = &DAT_007cfd10
- [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0x181
- FUN_00486f30 for DAT_005c32a4/005c32a8
- FUN_004670e0()

**Calls:** FUN_00466d60, FUN_00486f30 (×2), FUN_004670e0

**Used by system:** docs/20-math-utilities.md — constructor with defaults

**Moddability:** moddable

<!-- target: docs/20-math-utilities.md -->

## FUN_00475c80 — Conditional Draw

Source: unknown | Confidence: medium
Draws if visibility check passes.

**Key logic:**
- FUN_00495150() check
- If passes: FUN_00494c20(coords..., 0xff0000)

**Calls:** FUN_00495150, FUN_00494c20

**Used by system:** docs/20-math-utilities.md — conditional draw

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00477fa0 — Polling + State Change Detection

Source: unknown | Confidence: low
Polls two sources, triggers update callback on change.

**Key logic:**
- vtable[0x1c](3) on param_1[0x10]: if changed → vtable[0xa0]()
- vtable[0x1c](0x12) on *DAT_007cd8c0: if +0x174 changed → vtable[0xa0]()

**Globals:** DAT_007cd8c0

**Used by system:** docs/20-math-utilities.md — change detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479320 — Hit Test / Bounds Check

Source: unknown | Confidence: low
Scans linked list for intersection with bounding region (±0x14).

**Key logic:**
- FUN_00498880() — get cursor pos
- Walks list at param_1+0x164
- Tests x ∈ (node.x + originX) ± 0x14, y ∈ (node.y + originY) ± 0x14
- On match: stores index to param_1+0x158

**Calls:** FUN_00498880

**Used by system:** docs/20-math-utilities.md — hit testing

**Algorithm family:** hit testing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479a10 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor: init with float values, set vtable.

**Key logic:**
- FUN_00466980(0x3f000000=0.5f, 0x3f800000=1.0f)
- *param_1 = &PTR_FUN_005a5880

**Calls:** FUN_00466980

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a3a0 — Short Computation (Constructor)

Source: unknown | Confidence: high
Constructor: init, set vtable, zero flag.

**Key logic:**
- FUN_004668e0(0, 1.0f)
- *param_1 = &PTR_FUN_005a6120
- param_1[0x41] = 0

**Calls:** FUN_004668e0

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047be90 — Short Computation (Destructor)

Source: unknown | Confidence: high
Destructor with conditional free.

**Key logic:**
- FUN_00489440() — base destructor
- If param_2 & 1: FUN_00587bcf(param_1) — free

**Calls:** FUN_00489440, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047f210 — Short Computation (Conditional VTable Call)

Source: unknown | Confidence: high
If flag set and pointer non-null, calls vtable dispatch(1).

**Key logic:**
- If param_1[3] byte non-zero and *param_1 non-null:
  - (**(code**)**(*(undefined4**)*param_1))(1)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004858e0 — Short Computation (Destructor)

Source: unknown | Confidence: high
Destructor with conditional free.

**Key logic:**
- FUN_00485eb0() — base destructor
- If param_2 & 1: FUN_00587bcf(param_1)

**Calls:** FUN_00485eb0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004864c0 — Linked List Append

Source: unknown | Confidence: high
Appends node to singly-linked list at +0x18 pointer chain.

**Key logic:**
- If param_1+0xd0 (head) is null: sets head = param_2
- Else: walks chain via +0x18 to tail, appends param_2 at tail

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0xd0 | listHead | int* | Linked list head |
| Each node+0x18 | next | int* | Next node pointer |

**Used by system:** docs/20-math-utilities.md — linked list append

**Algorithm family:** linked list operations

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00487260 � State-Dependent vTable Dispatcher with bool Param

Source: unknown | Confidence: high
Dispatches vtable method at offset +0x40 based on state (0-4) from FUN_00486720() and boolean parameter.

**Key logic:**
- state = FUN_00486720() � returns 0-4 (docs/20)
- Cases 0, 2: if param_1 != 0 ? call vtable+0x40
- Cases 1, 3: if param_1 == 0 ? call vtable+0x40
- Case 4:
  - Calls FUN_00486710() � byte field getter (docs/20)
  - If returns 0: calls FUN_00487740() (docs/20), then calls vtable+0x40 on BOTH sub-branches (regardless of FUN_00487740 result)
  - If returns non-zero: returns without dispatch

**Calls:** FUN_00486720 (state query, docs/20), FUN_00486710 (condition check, docs/20), FUN_00487740 (range check, docs/20)

**Moddability:** hookable

<!-- target: docs/19-renderer.md -->

## FUN_00487f10 — Destructor

Source: unknown | Confidence: high
Destructor with conditional free.

**Key logic:**
- FUN_00487f30() — base destructor
- If param_2 & 1: FUN_00587bcf(param_1)

**Calls:** FUN_00487f30, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004894d0 — Strlen + Overwrite

Source: unknown | Confidence: high
Finds end of string, overwrites last char with global terminator.

**Key logic:**
- If null: return -1
- Walk to null terminator
- Write DAT_005c692c (ushort) at end-1

**Globals:** DAT_005c692c

**Used by system:** docs/20-math-utilities.md — string utility

**Algorithm family:** string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b910 — Setter + VTable + ID Check

Source: unknown | Confidence: medium
Sets flag, dispatches vtable, conditionally unregisters ID.

**Key logic:**
- param_1[0x38] = param_2
- vtable[+0x2c](1)
- If param_2 == 0:
  - FUN_004979d0() — get current ID
  - If matches: FUN_004979e0() — unregister
  - vtable[+0xb0]() — cleanup

**Calls:** FUN_004979d0, FUN_004979e0, vtable[+0x2c], vtable[+0xb0]

**Used by system:** docs/20-math-utilities.md — property setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d360 — Guarded Accessor

Source: unknown | Confidence: high
Returns field at +0x338 if count at +0x328 >= 1.

**Key logic:**
- If +0x328 < 1: return -1
- Return +0x338

**Used by system:** docs/20-math-utilities.md — guarded accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e670 — Destructor

Source: unknown | Confidence: high
Destructor: switch vtable, cleanup, free, base destructor.

**Key logic:**
- *param_1 = &PTR_FUN_005ac540
- FUN_0048e890()
- If param_1[0x38] non-null: free
- FUN_00485eb0()

**Calls:** FUN_0048e890, FUN_00587bcf, FUN_00485eb0

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fd60 — Constructor

Source: unknown | Confidence: high
Constructor: init, set vtable, zero field.

**Key logic:**
- FUN_0048e9e0()
- *param_1 = &PTR_FUN_005ac69c
- param_1[0xc] = 0

**Calls:** FUN_0048e9e0

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490920 — Accessor

Source: unknown | Confidence: high
Calls FUN_004906e0(), returns field at +4.

**Key logic:**
- iVar1 = FUN_004906e0()
- return *(iVar1+4)

**Calls:** FUN_004906e0

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491770 — Unidentified (Array Iteration + Cleanup)

Source: unknown | Confidence: low
Iterates array of 0x10-byte stride, calls cleanup on each + init offsets.

**Key logic:**
- piVar1 = *param_1 (array base)
- For each of *piVar1 entries (count at start): calls FUN_004910d0(entry + iVar2) with stride 0x10
- Then calls FUN_004910d0 on +0xc and +0x1c offsets

**Calls:** FUN_004910d0 (×N+2)

**Used by system:** docs/20-math-utilities.md — array cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491fb0 — Unidentified (Loop with Random Wait)

Source: unknown | Confidence: low
Loops with random backoff (0x100=256 range), increments counters.

**Key logic:**
- iVar1 = FUN_005351d0(0x100) — random in [0,256)
- Loop: while iVar1 != 0:
  - Increments param_1+0x18c (counter)
  - iVar1 = FUN_005651b0() — status check
  - If iVar1 != 1 and not in [3,4]: break (exit)
  - Increments param_1+400 (counter2)
  - iVar1 = FUN_005351d0(0x100) — re-roll random
- Returns 1

**Calls:** FUN_005351d0 (×2), FUN_005651b0

**Used by system:** docs/20-math-utilities.md — polling loop with randomization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495140 — Global Accessor

Source: unknown | Confidence: high
Returns DAT_007cde20.

**Key logic:**
- return DAT_007cde20

**Globals:** DAT_007cde20

**Used by system:** docs/20-math-utilities.md — global accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004966e0 — Linked List Node Insert

Source: unknown | Confidence: high
Allocates and inserts node into doubly-linked list at param_1+0x18dc.

**Key logic:**
- If param_2 != 0: allocates 0x10-byte node via operator_new
  - node[0] = param_2, node[1]=node[2]=0, node[3]=0
- If list head (+0x18dc) null: sets head=tail=node
- Else: inserts at front (updates current head's prev, sets node->prev=old)
- Updates current pointer (+0x18e0) to node
- Increments count (+0x18e8)

**Calls:** operator_new

**Used by system:** docs/20-math-utilities.md — doubly-linked list insert

**Algorithm family:** linked list operations

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004979c0 — Setter

Source: unknown | Confidence: high
Writes param_2 to param_1+0x20.

**Key logic:**
- param_1+0x20 = param_2

**Used by system:** docs/20-math-utilities.md — setter

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00498d70 — Destructor

Source: unknown | Confidence: high
Destructor with conditional free.

**Key logic:**
- FUN_00498d90() — base destructor
- If param_2 & 1: FUN_00587bcf(param_1)

**Calls:** FUN_00498d90, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004992e0 — Unidentified (Layout/Position Calc)

Source: unknown | Confidence: low
Sets param, computes centered position offset.

**Key logic:**
- If param_2 non-null: param_1+0x4c = param_2
- If param_3 non-zero:
  - Gets container size from *(param_1+0x50)
  - Computes width = [0x10]-[0xc], height = [8]-[4] (clamped to 0 or +1)
  - Centers: (width/2 - offsetX) - target_width/2, (height/2 - offsetY) - target_height/2
  - Calls FUN_0049acc0 with result

**Calls:** FUN_0049acc0

**Used by system:** docs/20-math-utilities.md — UI layout

**Algorithm family:** UI layout

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499a50 — Float Threshold Check

Source: unknown | Confidence: high
Returns 1 if float > ZeroThreshold.

**Key logic:**
- If *(param_1+8) > DAT_0059e440: return 1
- Else: return 0

**Globals:** DAT_0059e440 (ZeroThreshold, docs/12)

**Used by system:** docs/20-math-utilities.md — threshold check

**Algorithm family:** float comparison

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499e60 — Delegation Wrapper

Source: unknown | Confidence: high
Delegates to FUN_00566650.

**Key logic:**
- Calls FUN_00566650() — path registry

**Calls:** FUN_00566650 (path registry, docs/08)

**Used by system:** docs/20-math-utilities.md — delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a360 — Hash Table Search

Source: unknown | Confidence: medium
Searches hash table bucket chain for string key match.

**Key logic:**
- FUN_00589901(param_2) — hash prep
- iVar1 = FUN_0049a330(param_2) — bucket index
- If != -1: walks chain at param_1[iVar1*4] via +0x18 next
  - FUN_0049a2b0 get key, FUN_00588410 compare
  - Match: return node
- Return 0 (not found)

**Calls:** FUN_00589901, FUN_0049a330, FUN_0049a2b0, FUN_00588410

**Used by system:** docs/20-math-utilities.md — hash table lookup

**Algorithm family:** hash table search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049af30 — Linked List Free

Source: unknown | Confidence: high
Frees linked list nodes, zeroes struct fields.

**Key logic:**
- Walks list from *param_1 (head), frees each node
  - If node[2] byte non-zero: frees node[0] first
  - Frees node itself
- Zeros 4 struct fields (head, tail, count, flags)

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049e3e0 — Conditional Dispatch

Source: unknown | Confidence: low
If three conditions met, calls FUN_0049f1c0 with data.

**Key logic:**
- If param_1+8 non-null AND param_1+0x14 non-null:
  - Reads *(*(param_1+0x14)+0x54) as iVar1
  - If iVar1 non-null: FUN_0049f1c0(1,1,0, param_1+8, iVar1)

**Calls:** FUN_0049f1c0

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049f750 — Center Calc

Source: unknown | Confidence: medium
Computes centered offset using FUN_005531f0.

**Key logic:**
- If param_4 non-zero:
  - FUN_005531f0(param_1, &param_4, &param_1, 0) — compute half-width
  - *param_3 = param_2 - param_4/2 — center position

**Calls:** FUN_005531f0

**Used by system:** docs/20-math-utilities.md — center calculation

**Algorithm family:** centering

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004a2220 — Unidentified (Struct Init + Cleanup)

Source: unknown | Confidence: low
Large struct initializer with cleanup of previous state.

**Key logic:**
- Zeros first 4 bytes, sets flags
- Sets sentinel values: +0x22 = 0xbf800000 (-1.0f), +0x24 = -1
- Zeros +0x26 through +0x30
- If DAT_008afe88 != 0 and +0x32 non-null: calls FUN_00545150 — cleanup
- Frees +0x32, +0x34, +0x36, +0x38, +0x3a + -4 (allocated block with header)
- Destructor loop for +0x3a block via FUN_004dd4d0

**Calls:** FUN_00545150, FUN_00587bcf, FUN_004dd4d0

**Used by system:** docs/20-math-utilities.md — struct reinit/destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a40b0 — Empty Stub

Source: unknown | Confidence: high
Empty function — returns immediately. No logic.

**Key logic:**
- Bare return
- Placeholder or stripped method

**Used by system:** docs/20-math-utilities.md — empty stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a8b30 — Short Constructor

Source: unknown | Confidence: high
Sets vtable, zero, and -1 sentinel.

**Key logic:**
- param_1[1] = 0
- param_1[2] = -1
- *param_1 = &PTR_FUN_005acbfc

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1a70 — Short Constructor

Source: unknown | Confidence: high
Sets vtable, zeros, sentinel values.

**Key logic:**
- param_1[1]=0, param_1[2]=-1, param_1[3]=0, param_1[4]=-1
- *param_1 = &PTR_LAB_005acc68

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b26d0 — Float Truncation (x3)

Source: unknown | Confidence: high
Converts 3 floats to int via __ftol, back to float (truncation).

**Key logic:**
- __ftol → truncate, assign back to float (cast float→int→float)
- Repeats 3 times for param_1[0], [1], [2]

**Calls:** __ftol (MSVC float-to-long) ×3

**Used by system:** docs/20-math-utilities.md — float truncation

**Algorithm family:** float conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2b80 — Bitfield Extract

Source: unknown | Confidence: high
Extracts 7 bits (0x7f) from param_1+0x30 at offset 15.

**Key logic:**
- return (*(param_1+0x30) >> 15) & 0x7f

**Used by system:** docs/20-math-utilities.md — bitfield extract

**Algorithm family:** bitfield operations

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b43e0 — File Format Header Reader

Source: unknown | Confidence: medium
Reads 4-byte header, decodes magic+size, dispatches.

**Key logic:**
- FUN_00566c00(local_1b0, 4) — read 4 bytes from file
- Check magic: (header & 0xe0000000) == 0x20000000 AND (header & 0xfc0000) == 0
  - If match: size = ((header >> 8) & 0x3ff) + 1
  - Else: size = (header >> 8) & 0x3ff
- FUN_00566df0(size) — process/allocate with computed size

**Calls:** FUN_00566c00, FUN_00566df0

**Used by system:** docs/20-math-utilities.md — file header decoder

**Algorithm family:** binary format parsing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b5460 — List Walk with User Cancel Check

Source: unknown | Confidence: low
Walks list, calling FUN_005001d0 each iteration; stops if cancelled.

**Key logic:**
- Sets walker at param_1+0x28 = *(param_1+0x20) (list)
- For each node: calls FUN_005001d0() — user cancel check
- If cancelled: returns 0
- Advances via +4 (next pointer)
- Returns success (0x101)

**Calls:** FUN_005001d0 — user cancel/input check

**Used by system:** docs/20-math-utilities.md — cancellable list iteration

**Algorithm family:** list iteration with cancel

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9ce0 — Delegation

Source: unknown | Confidence: high
Calls FUN_004b8790().

**Key logic:**
- Calls FUN_004b8790()

**Calls:** FUN_004b8790

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba830 — Linked List Node Removal

Source: unknown | Confidence: high
Removes node from singly-linked list by key match.

**Key logic:**
- Walks list from *param_1 matching *piVar5 == param_2
- On match:
  - Updates tail (param_1[2]) if needed
  - Unlinks: prev->next = node->next
  - If head (*param_1): updates head = node->next
  - Updates back pointer (param_1[1])
  - Decrements count param_1[3]
  - If param_3 != 0 and node[2] flag set: frees node[0] via FUN_004b0170/FUN_00587bcf
  - Frees node via FUN_00587bcf
- Returns 1 on success, 0 on failure

**Calls:** FUN_004b0170, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — linked list delete

**Algorithm family:** linked list operations

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb2e0 — Merge Sort (Linked List, Float Key)

Source: unknown | Confidence: high
Recursive merge sort for singly-linked list, sorting by float value at *node.

**Key logic:**
- Count nodes via +1 next traversal
- If count <= 1: return (base case)
- Find midpoint, split list (set mid->next = 0)
- Recursively sort left and right halves
- Merge: compare *left_float vs *right_float
  - Smaller float first in output chain
  - Use +1 as next pointer
- Returns sorted list head

**Calls:** self (recursive)

**Used by system:** docs/20-math-utilities.md — linked list sort

**Algorithm family:** merge sort

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bc330 — Field Copy

Source: unknown | Confidence: high
Copies +0x24 to +0x2c.

**Key logic:**
- param_1+0x2c = param_1+0x24

**Used by system:** docs/20-math-utilities.md — field copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004be6f0 — Delegation

Source: unknown | Confidence: high
Calls FUN_004be700, returns param_1.

**Key logic:**
- FUN_004be700()
- return param_1

**Calls:** FUN_004be700

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2780 — Node Alloc + List Insert

Source: unknown | Confidence: high
Allocates large buffer, inserts node into list.

**Key logic:**
- FUN_004c2760() check; if == 2: FUN_004c1820()
- operator_new(0xb154) — 45KB alloc
- On success: FUN_004c0ab0() → iVar1
- FUN_004c0db0() — get/create
- If iVar1 != 0: allocates 0xc-byte node, *node = iVar1, node[1]=0, node[2]=1
- If list empty (*param_1==0): sets head=tail=current=node, count++
- Else: appends via current tail, count++

**Calls:** FUN_004c2760, FUN_004c1820, operator_new, FUN_004c0ab0, FUN_004c0db0

**Used by system:** docs/20-math-utilities.md — pool/node alloc

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2fe0 — Delegation

Source: unknown | Confidence: high
Calls FUN_004c4900().

**Key logic:**
- FUN_004c4900()

**Calls:** FUN_004c4900

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7b20 — Two-Call Delegation

Source: unknown | Confidence: high
Calls FUN_004c3fe0(param_1) and FUN_004c78f0(global).

**Key logic:**
- FUN_004c3fe0(param_1)
- FUN_004c78f0(DAT_008ac38c)

**Globals:** DAT_008ac38c

**Calls:** FUN_004c3fe0, FUN_004c78f0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c85a0 — VTable Dispatch via Global

Source: unknown | Confidence: low
Calls vtable methods on global if non-null and valid.

**Key logic:**
- If DAT_008ac4c8 non-null:
  - vtable[+8]() — check
  - If returns non-zero: vtable[+0x10]() — dispatch

**Globals:** DAT_008ac4c8

**Used by system:** docs/20-math-utilities.md — vtable dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9280 — Equality + State Check

Source: unknown | Confidence: low
Checks if param_2 matches internal state, queries global singleton.

**Key logic:**
- If param_2 == param_1+0x1c (matches expected):
  - FUN_004c9260() — get singleton
  - If non-null: vtable[+0x1c]() checks state
  - If state != 2: return 1
- Return 0

**Calls:** FUN_004c9260, vtable[+0x1c]

**Used by system:** docs/20-math-utilities.md — state validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004CAED0 � 16-Float Lexicographic Comparison with String Fallback

Source: unknown | Confidence: high
Lexicographic comparison of two structs containing 16 float fields followed by sub-struct with string + int fields. Returns comparison result as bitmask.

**Key logic:**
- Compare int at param_1+4 vs param_2+4 � early mismatch exit
- Sequentially compare 16 float fields at offsets: +0x0c, +0x10, +0x14, +0x18, +0x1c, +0x20, +0x24, +0x28, +0x2c, +0x44, +0x48, +0x4c, +0x30, +0x34, +0x38, +0x3c
  - For each: encodes result bits: bit 8 (less), bit 10 (NaN), bit 14 (equal)
  - If floats equal: continue to next float
  - If not equal: return result bitmask
- After all 16 floats equal: compare sub-structs at +0x50:
  - Compare int at +0x20 within each sub-struct
  - Compare string at +0x38 within each sub-struct (byte-by-byte)
  - Compare ints at +0x58, +0x5c, +0x60, +0x64, +0x68, +0x6c
  - Compare string at +0x70
  - Compare string at +0x90
- If all equal and param_1+0x58 < param_2+0x58: update param_1+0x58 = param_2+0x58, return 1
- Returns comparison bitmask with upper byte masked

**Struct offsets (param_1/param_2):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | SortKey | int | primary sort key |
| +0x0c�+0x3c | FloatFields[16] | float | 16 floats for comparison (gaps at 0x40) |
| +0x44�+0x4c | FloatFields[3] | float | continuation after gap |
| +0x50 | SubStructPtr | int* | pointer to sub-struct with string/int fields |
| +0x58 | UpdateCounter | int | incremented if this wins comparison |

**Moddability:** hookable

<!-- target: docs/19-renderer.md -->

## FUN_004cf040 — Repeated Call Loop

Source: unknown | Confidence: high
Loops FUN_004cb5e0() for count at param_1+0x10.

**Key logic:**
- For i=0 to param_1+0x10: calls FUN_004cb5e0()

**Calls:** FUN_004cb5e0 (×N)

**Used by system:** docs/20-math-utilities.md — batch call

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d47c0 — Delegation

Source: unknown | Confidence: high
Delegates to FUN_00587f64.

**Key logic:**
- FUN_00587f64(param_1, param_2, param_3)

**Calls:** FUN_00587f64

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d6830 — Cubic Hermite Interpolation

Source: unknown | Confidence: high
Performs a cubic Hermite spline evaluation using a lookup table.

**Key logic:**
- Computes ratio = param_4/param_2 as double, scales by param_1+8
- Calls FUN_005895a2(dVar1) — clamp
- Index = (uint)ROUND(fVar4), clamped to [0, param_1[0x10]-1]
- Reads 4 coefficients from table at param_1+0x14[index*0x20]
- Evaluates cubic: ((coeff[0]*t + coeff[1])*t + coeff[2])*t + coeff[3]
  - Where t = dVar1 (the scaled ratio)

**Calls:** FUN_005895a2 — float clamp

**Used by system:** docs/20-math-utilities.md — spline interpolation

**Algorithm family:** cubic Hermite spline / lookup table interpolation

**Moddability:** configurable — table at param_1+0x14 is data-driven

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7e40 — UI Text Render with Scale

Source: unknown | Confidence: low
Renders UI text with temporary scale modification and position calculation.

**Key logic:**
- FUN_004d7fa0(param_6) — get object
- Saves original scale at +0x5c/+0x60
- Applies param_7/param_8 scale multipliers
- FUN_00552fc0(param_4) — set color
- __ftol converts position params
- If param_5 == 1: FUN_004d7f60 (method A)
- If param_5 == 2: FUN_004d7f20 (method B)
- FUN_00553070(param_1, x, y, DAT_008b8dc8) — render text
- Restores original scale

**Globals:** DAT_008b8dc8 — render context

**Calls:** FUN_004d7fa0, FUN_00552fc0, __ftol (×2), FUN_004d7f60/FUN_004d7f20, FUN_00553070

**Used by system:** docs/20-math-utilities.md — UI text rendering

**Algorithm family:** UI rendering

**Moddability:** hookable — scale factors passed as params

<!-- target: docs/20-math-utilities.md -->

## FUN_004d91e0 — ID-to-Value Mapper

Source: unknown | Confidence: high
Maps input parameter ID to output value via switch table.

**Key logic:**
- Switch on param_1 (0-0x18):
  - 0 → 100
  - 1,3-6,9-0x18 (many) → 0x32 (50)
  - 2, 0xd → 0x31 (49)
  - 7,8,0x13 → 0x33 (51)
  - 0x11 → 0x34 (52)

**Used by system:** docs/20-math-utilities.md — ID/value mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dbe60 — Multi-Layer Text Rendering

Source: unknown | Confidence: low
Renders 4 layers of text with different formatting, conditional on global flag.

**Key logic:**
- If DAT_008acf8c != 0x7fffffff (flag set):
  - FUN_0049c670 (init text A), set params: 0.75f, 2, yellow(0xffff00), 0x2e
- Else:
  - FUN_0049c8f0 (init text B), FUN_004d7e40 (render text), FUN_0049c960
  - Params: 1.0f, 0, white(0xffffff), 10
- Additional 3 rendering passes with varying formatting
- All use FUN_004d7e40 for text rendering

**Globals:** DAT_008acf8c

**Calls:** FUN_0049c670, FUN_0049c8f0, FUN_0049c960, FUN_0049c700, FUN_0049c770, FUN_004d7e40 (×4)

**Used by system:** docs/20-math-utilities.md — HUD/text overlay rendering

**Algorithm family:** UI rendering

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcd60 — Conditional Call

Source: unknown | Confidence: high
If *param_1 non-null, calls FUN_00553700.

**Key logic:**
- If *param_1 != 0: FUN_00553700()

**Calls:** FUN_00553700

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dd7c0 — Unidentified (Best-Fit Selection)

Source: unknown | Confidence: low
Iterates entries, selects best match using dot product-like scoring.

**Key logic:**
- FUN_004dd4e0() — get threshold
- Zeros param_3[0..2] (output)
- Iterates outer count (FUN_0054c210):
  - For each: checks type/state via flags
  - Calculates priority: 4 - (flag&0x40), or 2 - (flag&0x40) for 0x2000000 flag
  - If priority <= threshold: iterates inner list (FUN_0054e100):
    - Computes dot product: pfVar11[0]*fVar1 + pfVar11[1]*fVar2 + pfVar11[2]*fVar3
    - Keeps max-scoring entry, writes to param_3 output

**Calls:** FUN_004dd4e0, FUN_0054c210, FUN_0054c230, FUN_0054e100, FUN_0054e120

**Used by system:** docs/20-math-utilities.md — best-fit / spatial selection

**Algorithm family:** scoring / selection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e21d0 — Color/Alpha Update + Flag Set

Source: unknown | Confidence: low
Sets alpha-based color on all entries, sets dirty flag.

**Key logic:**
- __ftol() converts to int → base alpha
- Iterates all entries (FUN_0054e100/FUN_0054e120 count):
  - Sets +0x18 color = alpha * 0x1000000 + 0xffffff
- Sets bit 0x10000000 at param_1+0x14 (dirty/updated flag)

**Calls:** __ftol, FUN_0054e100, FUN_0054e120

**Used by system:** docs/20-math-utilities.md — color/alpha mass update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ed710 — Vec3 Add

Source: unknown | Confidence: high
3-component vector addition.

**Key logic:**
- param_3[0] = param_1[0] + param_2[0]
- param_3[1] = param_1[1] + param_2[1]
- param_3[2] = param_1[2] + param_2[2]

**Used by system:** docs/20-math-utilities.md — 3D vector math

**Algorithm family:** 3D vector addition

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f6bc0 — Struct Zero-Init (6×3 fields)

Source: unknown | Confidence: high
Zeros struct with 6 blocks of 3 ints each (18 fields total).

**Key logic:**
- Zeros *param_1 and param_1[0x10]
- Loop 5 times: zeros 3 consecutive fields each iteration (stride 3)
- Total: 2 + 5*3 = 17 fields zeroed

**Used by system:** docs/20-math-utilities.md — struct initializer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8cd0 — Delegation

Source: unknown | Confidence: high
Calls FUN_004f9140.

**Key logic:**
- FUN_004f9140()

**Calls:** FUN_004f9140

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9f00 — Conditional Init

Source: unknown | Confidence: medium
Conditionally sets global flag and calls init.

**Key logic:**
- FUN_0055c9b0() — check ready
- If ready AND DAT_008afe71 == 0:
  - Sets DAT_008afe71 = 1
  - FUN_005550a0() — init

**Globals:** DAT_008afe71

**Calls:** FUN_0055c9b0, FUN_005550a0

**Used by system:** docs/20-math-utilities.md — one-time init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004fd6d0 — Two-Call Delegation

Source: unknown | Confidence: high
Calls FUN_004fc280 then FUN_004fd840.

**Key logic:**
- FUN_004fc280()
- FUN_004fd840()

**Calls:** FUN_004fc280, FUN_004fd840

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005006a4 — FourCC Decoder

Source: unknown | Confidence: high
Decodes FourCC codes (0x36314c20, 0x36314c41, etc.) to numeric IDs.

**Key logic:**
- param_1 == 0x36314c20 (" L16") → 0x32 (50)
- param_1 == 0x36314c41 ("AL16") → 0x33 (51)
- param_1 == 0x36315220 (" R16") → 0x14 (20)
- param_1 == 0x36315241 ("AR16") → 0x15 (21)
- else → return param_1 unchanged

**Used by system:** docs/20-math-utilities.md — FourCC/sound format decoder

**Algorithm family:** audio format ID mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00502ee5 — Conditional Free (Allocation Header)

Source: unknown | Confidence: medium
Frees memory with awareness of allocation header (-4 offset).

**Key logic:**
- If param_2 & 2 == 0: frees *param_1, optionally frees param_1
- If param_2 & 2 != 0: adjusts to header (param_1-1), calls FUN_0058a5f7, optionally frees header
- Returns adjusted pointer or param_1

**Calls:** FUN_00587bcf (×2), FUN_0058a5f7

**Used by system:** docs/20-math-utilities.md — custom deallocator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005053ec — Memory Allocation (Index Remap Table)

Source: unknown | Confidence: medium
Allocates and fills an indexed remap table with float-to-int interpolation.

**Key logic:**
- operator_new(unaff_EBX << 4) — allocates EBX entries of 16 bytes each
- For each i in [0, EBX):
  - Computes fVar3 = (float)i * (fVar1/fVar2) - 0x5adb14 offset
  - FUN_005895a2 clamp → ROUND
  - uVar5 = index, uVar6 = uVar5+1 (clamped to [0, EDI-1])
  - Stores: [0]=uVar5, [2]=uVar6, [1]=fraction, [3]=1-fraction
- Returns allocated array

**Globals:** _DAT_005adb14, DAT_008b0098, _DAT_0059e450, _DAT_0059e43c

**Calls:** operator_new, FUN_005895a2

**Used by system:** docs/20-math-utilities.md — lookup table construction

**Algorithm family:** lookup table generation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050ae5a — Constructor

Source: unknown | Confidence: high
Calls FUN_00507496, sets vtable.

**Key logic:**
- FUN_00507496(param_2, 8, 1) — init with size 8
- *param_1 = &PTR_FUN_005adc6c

**Calls:** FUN_00507496

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b727 — Constructor

Source: unknown | Confidence: high
Calls FUN_00507496, sets vtable.

**Key logic:**
- FUN_00507496(param_2, 0x20, 1) — init with size 32
- *param_1 = &PTR_FUN_005add9c

**Calls:** FUN_00507496

**Used by system:** docs/20-math-utilities.md — constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c23c — Bilinear Interpolation (2D)

Source: unknown | Confidence: high
2D bilinear interpolation.

**Key logic:**
- out = b + (c-b)*w1 + (d-b)*w2
- For both x and y components

**Used by system:** docs/20-math-utilities.md — 2D interpolation

**Algorithm family:** bilinear interpolation

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d57f — Y-Axis Rotation Matrix

Source: unknown | Confidence: high
Builds 4x4 rotation matrix about Y axis.

**Key logic:**
- cosθ, sinθ via fcos/fsin
- Row-major matrix with cosθ/sinθ at elements [1,1],[1,2],[2,1],[2,2]

**Calls:** fcos, fsin

**Used by system:** docs/20-math-utilities.md — 3D transform

**Algorithm family:** rotation matrix

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0050f9ab — State Machine Dispatch

Source: unknown | Confidence: low
State machine with conditional vtable calls.

**Key logic:**
- If param_1[4] ∉ {200, 0xc9}: set state to 0x12, param to param_1[4], call vtable
- FUN_0050f86a() returns state 1 or 2
- State 2 + param_2 non-zero: set state 0x32, call vtable, call FUN_00516937

**Calls:** FUN_0050f86a, FUN_00516937, vtable

**Used by system:** docs/20-math-utilities.md — state dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00511887 — Callback Dispatch

Source: unknown | Confidence: high
Calls function pointer at +0x44 if non-null.

**Key logic:**
- If *(param_1+0x44): call(param_1, param_2)

**Used by system:** docs/20-math-utilities.md — callback pattern

**Moddability:** hookable — callback pluggable

<!-- target: docs/20-math-utilities.md -->

## FUN_00513374 — Pixel Format Converter

Source: unknown | Confidence: low
Converts buffer pixels between formats (3-byte→1-byte, 4-byte→1-byte, direct offset).

**Key logic:**
- Format code at param_1[2]:
  - 0x02 (RGB 24→8): bit pack with lookup
  - 0x06 (RGBA 32→8): bit pack with lookup (stride 4)
  - 0x03: direct byte offset translation
- Updates format state after conversion

**Calls:** none (pure computation)

**Used by system:** docs/20-math-utilities.md — pixel format conversion

**Algorithm family:** pixel conversion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005158e3 — Init+Process Wrapper

Source: unknown | Confidence: medium
Calls init then process with error propagation.

**Key logic:**
- FUN_00513e2d() init
- If ok: FUN_00515417(param_1, buf)
- Return 0 on success, -1 on error

**Calls:** FUN_00513e2d, FUN_00515417

**Used by system:** docs/20-math-utilities.md — init+process

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00516772 — Unidentified (List Cleanup by Index)

Source: unknown | Confidence: low
Cleans up two linked lists indexed by param_2, with per-node processing.

**Key logic:**
- If param_2 ∉ [0,1]: error (set state 0xc)
- If param_2 == 1: walks two lists (+0x40, +0x44), clears flags, calls callbacks
- Processes queue at iVar1+0x38[param_2]: walks list, calls FUN_00519351 for each, decrements counter
- Processes queue at iVar1+0x30[param_2]: same pattern

**Calls:** FUN_00519351, vtable dispatch

**Used by system:** docs/20-math-utilities.md — queue/list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00517ec8 — Conditional Call

Source: unknown | Confidence: high
If both params non-zero, calls FUN_0058aa6f(param_2).

**Key logic:**
- If param_1 && param_2: FUN_0058aa6f(param_2)

**Calls:** FUN_0058aa6f

**Used by system:** docs/20-math-utilities.md — conditional delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051c3e2 — Media/Audio Decode Dispatch

Source: unknown | Confidence: low
Constructs decode command table with format-specific handlers.

**Key logic:**
- Allocates command table via vtable[1](param_1, 1, 0xa0)
- Sets up command table entries per input channel (param_1[8] count)
- For each: computes scaled dimensions (width*scale, height*scale)
- Selects decode function based on dimension ratios and flags:
  - Identity, half, quarter scalers
  - Handles upscale/downscale decisions
- Calls FUN_00515927 for resource allocation

**Calls:** vtable dispatch, FUN_00515927, FUN_0051bfc0

**Used by system:** docs/20-math-utilities.md — media/audio decode setup

**Algorithm family:** decode pipeline setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00521712 — MMX/3DNow Vector Transform

Source: unknown | Confidence: medium
Uses 3DNow! SIMD instructions for packed floating-point operations.

**Key logic:**
- FastExitMediaState() — enter/exit MMX state
- PackedFloatingADD — packed add
- FUN_005215db — buffer transform (×2)
- FloatingReciprocalAprox, PackedFloatingReciprocalIter1/Iter2 — 3DNow! reciprocal
- PackedFloatingMUL — packed multiply

**Calls:** FastExitMediaState, PackedFloatingADD, FUN_005215db (×3), FloatingReciprocalAprox, PackedFloatingReciprocalIter1/Iter2, PackedFloatingMUL

**Used by system:** docs/20-math-utilities.md — SIMD vector math

**Algorithm family:** 3DNow! SIMD operations

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00528bd0 — Empty Stub

Source: unknown | Confidence: high
Empty function — only returns. No logic.

**Key logic:**
- Bare return
- 232 byte function body all zeroed — stripped/virtual placeholder

**Used by system:** docs/20-math-utilities.md — empty stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e060 — Static Init Registration

Source: unknown | Confidence: high
Registers LAB_0052e070 for deferred execution.

**Key logic:**
- FUN_00587b3e(&LAB_0052e070) — atexit/deferred registration

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md — static init registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00535220 — Buffer Fill with Timeout

Source: unknown | Confidence: low
Fills buffer from source, reading in 0x4000-byte chunks with decompression.

**Key logic:**
- Validates param_1 non-null and flag byte == 'w'
- Sets *param_1=param_2, param_1[1]=param_3 (buffer position/target)
- Loop: reads 0x4000 bytes via FUN_00588678, processes via FUN_00535e80
- On error/FUN_00588678 returns != 0x4000: fall through to finalize
- Calls FUN_00536e90 to finalize

**Calls:** FUN_00588678, FUN_00535e80, FUN_00536e90

**Used by system:** docs/20-math-utilities.md — buffered I/O with decompression

**Algorithm family:** buffered I/O

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00537070 — Multi-Block Allocator

Source: unknown | Confidence: medium
Allocates multiple memory blocks via callback function.

**Key logic:**
- Calls alloc callback (param_1+0x20) for 0x40-byte control block
- Calls alloc for 0x5a0-byte block → puVar1[9]
- Calls alloc for unaff_EBX bytes → puVar1[10]
- Sets puVar1[0xb] = end of second block
- Sets puVar1[0xe] = param_2
- *puVar1 = 0
- Calls FUN_00537000(0)
- On any failure: frees via callback at param_1+0x24

**Calls:** vtable allocate(×3), vtable free, FUN_00537000

**Used by system:** docs/20-math-utilities.md — custom allocator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b170 — Three-Field Accessor

Source: unknown | Confidence: high
Returns values at param_1+4, +8, +0xc via output pointers.

**Key logic:**
- If param_2: *param_2 = *(param_1+4)
- If param_3: *param_3 = *(param_1+8)
- If param_4: *param_4 = *(param_1+0xc)

**Used by system:** docs/20-math-utilities.md — multi-accessor

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c2a0 — Global Zero Init

Source: unknown | Confidence: high
Zeros two globals and returns param_1.

**Key logic:**
- DAT_008b6ac8 = 0
- DAT_008b6ab8 = 0

**Globals:** DAT_008b6ac8, DAT_008b6ab8

**Used by system:** docs/20-math-utilities.md — global state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d1d0 — Conditional Call

Source: unknown | Confidence: high
Calls FUN_0053d1f0; if non-zero, calls FUN_005528f0.

**Key logic:**
- FUN_0053d1f0(param_1) check
- If non-zero: FUN_005528f0()

**Calls:** FUN_0053d1f0, FUN_005528f0

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005400c0 — VTable Dispatch by Flags

Source: unknown | Confidence: low
Dispatches to different vtable methods based on flag bits.

**Key logic:**
- If param_4 == 0: reads default flags from param_2+0x18
- Bit 0x100 → sets flag 0x10
- Bit 0 → uses vtable[+0x24] on param_2+8
- Bit 1 → uses vtable[+0x24] on param_2+0xc
- Bit 2 → uses vtable[+0x40] on param_2+0x10
- Returns 0 on success, flag value (0/0x10) on failure

**Calls:** vtable[+0x24], vtable[+0x40]

**Used by system:** docs/20-math-utilities.md — polymorphic dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00542420 — Two-Call Delegation

Source: unknown | Confidence: high
Calls two sub-functions with different parameter sets.

**Key logic:**
- FUN_00542490(param_4, param_5, param_6)
- FUN_00542460(param_1, param_2, param_3)

**Calls:** FUN_00542490, FUN_00542460

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00543a80 — Memory Allocation with Fallback

Source: unknown | Confidence: low
Conditionally allocates two objects, with fallback/cleanup on error.

**Key logic:**
- If param_1+0xec bit 2 clear:
  - operator_new(0x3c) → FUN_005426a0 → DAT_008b8dbc
  - FUN_00542950 check → on failure: cleanup via FUN_00557470/FUN_00587bcf
  - Same for DAT_008b8dc0
- FUN_0055b6b0(param_2) file check → on failure: cleanup both
- Sets flag bits at param_1+0xec (0x10800)

**Globals:** DAT_008b8dbc, DAT_008b8dc0, DAT_008b8df4, DAT_008b8df8

**Calls:** operator_new, FUN_005426a0, FUN_00542950, FUN_00557470, FUN_00587bcf, FUN_0055b6b0, FUN_00542e50

**Used by system:** docs/20-math-utilities.md — resource allocation with fallback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547100 — Conditional Check + Call

Source: unknown | Confidence: medium
If condition met, calls two sub-functions.

**Key logic:**
- If param_2 < *(param_1+0xa4) AND *(param_1+0xa4) < 8:
  - FUN_0054fc40(0x80000000)
  - FUN_0054fca0(4)

**Calls:** FUN_0054fc40, FUN_0054fca0

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547af0 — String Dot Finder

Source: unknown | Confidence: high
Finds first '.' in string, replaces with null terminator.

**Key logic:**
- strlen check (loop counting to null)
- Iterates characters: if '.' found, sets to '\0', returns 1
- Returns 0 if no '.' found

**Used by system:** docs/20-math-utilities.md — string manipulation

**Algorithm family:** string split

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00549380 — Linked List Update

Source: unknown | Confidence: medium
Walks linked list, updates field via FUN_0054a2d0 per node.

**Key logic:**
- Walks list at param_1+0xf8 via +0x14 next
- For each: calls FUN_0054a2d0(iVar1), stores at +0x10

**Calls:** FUN_0054a2d0

**Used by system:** docs/20-math-utilities.md — list property update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054bcd0 — Recursive Traversal

Source: unknown | Confidence: low
Recursive traversal with conditional dispatch.

**Key logic:**
- If param_1+0x44 non-null: recurse(param_2, param_3, param_4)
- If param_1+0x4c non-null: recurse(param_2, param_3, param_4)
- If param_4: calls FUN_0054bf10
- Else: calls FUN_0054bdc0

**Calls:** self (recursive), FUN_0054bf10, FUN_0054bdc0

**Used by system:** docs/20-math-utilities.md — recursive tree traversal

**Algorithm family:** recursive traversal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fb90 — Struct Init with Defaults

Source: unknown | Confidence: high
Initializes struct with zero fields and float/int defaults.

**Key logic:**
- FUN_0053c2a0() — base init
- Zeros 16 ints (loop), then sets:
  - [0x11]=1, [0x12]=1, [0x10]=0, [0x13..0x17]=0
  - [0x1c]=0, [0x1d]=0, [0x1b]=0, [0x20..0x24]=0
  - [0x1e]=1.0f, [0x1f]=1.0f (scales)
  - [0x18]=0x100000 (1048576), [0x19]=4, [0x1a]=-1

**Calls:** FUN_0053c2a0

**Used by system:** docs/20-math-utilities.md — struct constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005528b0 — Conditional Free by Flag

Source: unknown | Confidence: high
If flag at +0x24 bit 0x20000 set, releases resource at +0xc.

**Key logic:**
- If +0x24 & 0x20000:
  - FUN_00540eb0(+0xc) — pre-release
  - Free +0xc via FUN_00587bcf
  - Zero +0xc

**Calls:** FUN_00540eb0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — conditional resource release

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00557470 — Empty Stub

Source: unknown | Confidence: high
Empty function — returns immediately. No logic.

**Key logic:**
- Bare return
- Placeholder for vtable slot or stripped method

**Used by system:** docs/20-math-utilities.md — empty stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055c9c0 — Float Array Value Setter (Stride 0x44)

Source: unknown | Confidence: medium
Sets float value in array entries with stride 0x44, calling vtable on change.

**Key logic:**
- If param_1[0x440] non-null:
  - Stores param_2 to param_1[0x4f9]
  - Iterates i=0 to param_1[0x4ec]:
    - If float at param_1+0x46e[i*0x11] != param_1[0x4f9]:
      - Sets it to param_1[0x4f9]
      - Calls vtable dispatch at +0xfc with (param_1[0x440], i, 0x13, param_1[0x4f9])

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x440 | vtableBase | int* | Vtable for dispatch |
| +0x46e | values | float[] | Stride 0x44 (17 floats apart) |
| +0x4ec | count | int | Array length |
| +0x4f9 | newValue | int | Value to set |

**Calls:** vtable[+0xfc]

**Used by system:** docs/20-math-utilities.md — array value update

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_005645b0 — String Hash with Weighted Accumulation

Source: unknown | Confidence: high
Computes hash of string modulo param_2 using weighted accumulation.

**Key logic:**
- For each char: iVar2 = FUN_0058b465(char) → weighted value
- uVar3 = iVar2 + uVar3 * 0x99ccf919 (-0x63306ce7 signed)
- Returns uVar3 % param_2

**Calls:** FUN_0058b465 — character weight function

**Used by system:** docs/20-math-utilities.md — string hashing

**Algorithm family:** hash function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005678f0 — Character Class Check

Source: unknown | Confidence: high
Returns true if byte < 0x21 (33 = first printable ASCII).

**Key logic:**
- return param_1 < 0x21

**Used by system:** docs/20-math-utilities.md — character classification

**Algorithm family:** character class check (whitespace/control)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a180 — Dword-Aligned Memory Copy

Source: unknown | Confidence: high
Copies memory in dword chunks + byte remainder, advances dest pointer.

**Key logic:**
- Copies param_3>>2 dwords from param_2 to *param_1
- Copies param_3 & 3 remaining bytes
- Advances *param_1 by param_3

**Used by system:** docs/20-math-utilities.md — memory copy utility

**Algorithm family:** aligned memory copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057b680 — 16-Byte Struct Copy

Source: unknown | Confidence: high
Copies 4 dwords (16 bytes) from param_2 to param_1.

**Key logic:**
- Copies param_2[0..3] to param_1[0..3]

**Used by system:** docs/20-math-utilities.md — struct copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005857c0 — Mutex-Protected Field Write

Source: unknown | Confidence: high
Writes value to field with mutex protection.

**Key logic:**
- If mutex at param_1+0xf0 valid:
  - WaitForSingleObject(param_1+0xf0, param_1+0xf4) with timeout
  - On success or WAIT_TIMEOUT: proceed
- Writes param_2 to param_1+0xec
- Releases mutex via ReleaseMutex

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xec | value | int | Target field |
| +0xf0 | mutex | HANDLE | Win32 mutex |
| +0xf4 | timeout | DWORD | Wait timeout |

**Calls:** WaitForSingleObject, ReleaseMutex

**Used by system:** docs/20-math-utilities.md — thread-safe field write

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587400 — Static Init Registration

Source: unknown | Confidence: high
Registers LAB_00587410 via FUN_00587b3e.

**Key logic:**
- FUN_00587b3e(&LAB_00587410)

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md — static init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005887ed — strlen + Format Call Wrapper

Source: unknown | Confidence: high
Computes string length, then calls format function.

**Key logic:**
- local_18 = 0x49 (format code)
- local_20 = _strlen(param_1)
- FUN_0058e4d2(&local_24, param_2, &stack)

**Calls:** _strlen (CRT), FUN_0058e4d2 (format)

**Used by system:** docs/20-math-utilities.md — string format helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058ac7a — Mutex Unlock Thunk

Source: unknown | Confidence: high
Thunk to FUN_0058e04b(9) — leave critical section 9.

**Key logic:**
- FUN_0058e04b(9)

**Calls:** FUN_0058e04b (critsect leave)

**Used by system:** docs/20-math-utilities.md — sync wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058fb7e — Stub Returning 0

Source: unknown | Confidence: high
Returns 0. Placeholder.

**Key logic:**
- return 0

**Used by system:** docs/20-math-utilities.md — stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00595550 — Buffer Format Helper

Source: unknown | Confidence: medium
Formats buffer via FUN_00596245, dispatches to FUN_00595524.

**Key logic:**
- FUN_00596245(local_10, &param_2, param_2, 0,0,0,0) — format
- FUN_00595524(local_10, param_1) — output

**Calls:** FUN_00596245, FUN_00595524

**Used by system:** docs/20-math-utilities.md — format helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005987a1 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_005987ad via FUN_00587b3e.

**Key logic:**
- FUN_00587b3e(&LAB_005987ad)

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md — callback registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599b1c — C++ EH Frame Setup

Source: unknown | Confidence: medium
C++ exception handler frame setup with vtable assignment.

**Key logic:**
- FUN_0058a5d8() — SEH prologue
- ExceptionList setup
- If param (EBP+0x14) non-zero:
  - Vtable = DAT_005b9c54, sets [10]=0, [1]=PTR_FUN_005b9c50
  - State tracking (unaff_EBP + -0x10)
- Sets vtable at computed address via *(*ECX+4)+ECX to PTR_LAB_005b9c48
- If byte at EBP+0x10 non-zero: calls FUN_0059a3a9
- ExceptionList restore

**Calls:** FUN_0058a5d8, FUN_0059a3a9

**Used by system:** docs/20-math-utilities.md — C++ EH constructor frame

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059bfa0 — MSVC ~exception Destructor

Source: unknown | Confidence: high
MSVC CRT `exception::~exception()` destructor.

**Key logic:**
- Sets vtable to PTR_FUN_005b9dc0
- If *(this+8) non-null: frees *(this+4)
- This is the standard MSVC exception class destructor

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c8f4 — C++ Unwind Helper

Source: unknown | Confidence: high
SEH unwind helper — thunk to FUN_00581820.

**Key logic:**
- Calls FUN_00581820()

**Calls:** FUN_00581820

**Used by system:** docs/20-math-utilities.md — unwind helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cfda — C++ Unwind Helper

Source: unknown | Confidence: high
SEH unwind helper — thunk to FUN_00586170.

**Key logic:**
- Calls FUN_00586170()

**Calls:** FUN_00586170

**Used by system:** docs/20-math-utilities.md — unwind helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d928 — Single Delegation Call

Source: unknown | Confidence: high
Delegates to FUN_0043ff3d.

**Key logic:**
- FUN_0043ff3d()

**Calls:** FUN_0043ff3d

**Used by system:** docs/20-math-utilities.md — delegation

**Moddability:** hardcoded

## FUN_0050e3da — Thunk to FUN_0050e3cd

Source: unknown | Confidence: high
Trampoline — indirect jmp via PTR_FUN_005d781c to FUN_0050e3cd.

**Key logic:** Single indirect call via pointer at PTR_FUN_005d781c. Address appears as call stub or vtable slot. No local logic.

**Calls:** FUN_0050e3cd (short computation, math_util)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00569990 — 3D Vector Transform with Buffer Write

Source: unknown | Confidence: high
Transform 3D vector through matrix, write to circular buffer with metadata.

**Key logic:** Reads buffer position at param_1+0x23c (+0x240 base). Computes delta vector from reference at param_1+0x04/0x0c/0x14. Applies 3x3 matrix multiply (offsets 0x1c-0x5c). Writes result + 4 metadata fields to buffer (stride 0x58).

**Struct offsets (param_1):** +0x04 OriginX/Y/Z double[3], +0x1c Matrix[3][3] double[9], +0x23c BufferCount int, +0x240 BufferBase int

**Used by system:** docs/20-math-utilities.md — called from body solver (docs/10)

**Algorithm family:** 3D vector transform, matrix multiply

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b630 — Read Bytes from Circular Buffer with Wrap-Around

Source: unknown | Confidence: high
Read bytes from ring buffer into destination with wrap-around.

**Key logic:** Checks avail at param_1+0x1002 >= param_3. Reads from cursor at param_1+0x1000. Wraps via 0x80000fff mask.

**Struct offsets:** +0x1000 ReadCursor short, +0x1002 AvailableData ushort

**Calls:** None — inline ring buffer read

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** ring buffer

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583210 — Linked List Node Alloc & Prepend

Source: unknown | Confidence: high
Allocate 12-byte node, prepend to singly-linked list.

**Key logic:** Allocates 3-field (12-byte) node: [0]=data, [1]=next, [2]=flag. If head empty: set head=tail=cursor=new. Else: prepend.

**Struct offsets:** +0x00 Head, +0x04 Tail, +0x08 Cursor, +0x0c Count

**Calls:** operator_new

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** linked list

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00591d05 — Float Bit Manipulation (Exponent Adjust)

Source: unknown | Confidence: high
Adjust floating-point exponent via bit manipulation.

**Key logic:** Extracts lower 6 bytes, computes exponent = (param_2+0x3FE)*0x10, preserves sign bit. Returns 80-bit extended precision float.

**Calls:** None — inline float bit op

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** float bit manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00595207 — Bitset Clear from Bit Position

Source: unknown | Confidence: high
Clear bit in bitset array, propagate borrow to higher words.

**Key logic:** Target word = param_1 + (param_2/32)*4. Calls FUN_00597547 (overflow-checked subtraction) with mask. Walks backward borrowing through preceding words.

**Calls:** FUN_00597547 (safe math, triage)

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** bitset operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00597cc0 — Bit-Packed Data Decode via Lookup Table

Source: unknown | Confidence: high
Decode bit-packed integer using lookup tables at 0x5e9bd8/0x5e9d38.

**Key logic:** 3-bit chunks from param_2. Positive/negative table select. 0x54 stride per bit. 12-byte entries. Calls FUN_00597aa0 (render/string format, docs/06).

**Calls:** FUN_00597aa0 (render/string format, docs/06)

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** bit-packed decode

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598c1c — Locale Refcount Acquire Under Lock

Source: unknown | Confidence: high
Acquire locale object with thread-safe refcount increment.

**Key logic:** FUN_0059aab9 (singleton init). Store to *param_1. Lock via FUN_0059a54d. FUN_00598c4a (counter increment). Unlock via FUN_0059a5e9.

**Calls:** FUN_0059aab9 (singleton, docs/08), FUN_0059a54d (crient enter), FUN_00598c4a (counter inc), FUN_0059a5e9 (critsect leave)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/08-file-formats.md -->

## FUN_0059a44c — Conditional Callback with Null Check

Source: unknown | Confidence: high
Check handle, close if valid, call init callback. Same pattern as FUN_00599495.

**Key logic:** If param_1+0x50 non-null: FUN_00587d02 (file close). If success: FUN_0059a473(0,2) (init), return param_1. If fail: return 0.

**Struct offsets:** +0x50 FileHandle int

**Calls:** FUN_00587d02 (file close), FUN_0059a473 (entity init, triage)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059befd — Exception Destructor with Flag

Source: unknown | Confidence: high
C++ exception destructor with conditional free.

**Key logic:** exception::~exception(param_1). If param_2 bit 0: FUN_00587bcf(param_1). Return param_1.

**Calls:** exception::~exception, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c518 — SEH Unwind Free at -0x40

Source: unknown | Confidence: high
SEH unwind handler freeing object at EBP-0x40.

**Key logic:** FUN_00587bcf(*(unaff_EBP-0x40))

**Calls:** FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c648 — SEH Unwind Free at +8

Source: unknown | Confidence: high
SEH unwind handler freeing object at EBP+8.

**Key logic:** FUN_00587bcf(*(unaff_EBP+8))

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c7d0 — CRT Unwind Helper

Source: unknown | Confidence: high
CRT unwind: delegates to FUN_00583ae0.

**Key logic:** FUN_00583ae0() (list destruction)

**Calls:** FUN_00583ae0 (list destruction, triage)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c902 — CRT Unwind Helper

Source: unknown | Confidence: high
CRT unwind: delegates to FUN_005818e0.

**Key logic:** FUN_005818e0() (list destruction)

**Calls:** FUN_005818e0 (data structure cleanup, triage)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cb28 — SEH Unwind Free at +4

Source: unknown | Confidence: high
SEH unwind freeing object at EBP+4.

**Key logic:** FUN_00587bcf(*(unaff_EBP+4))

**Calls:** FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cce0 — SEH Unwind Free at -0x14

Source: unknown | Confidence: high
SEH unwind freeing object at EBP-0x14.

**Key logic:** FUN_00587bcf(*(unaff_EBP-0x14))

**Calls:** FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cead — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind: delegates to FUN_00586070 (CloseHandle wrapper).

**Key logic:** FUN_00586070()

**Calls:** FUN_00586070 (CloseHandle wrapper, docs/21)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d012 — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind: delegates to FUN_005861e0 (CloseHandle wrapper).

**Key logic:** FUN_005861e0()

**Calls:** FUN_005861e0 (CloseHandle wrapper, triage)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d17b — SEH Unwind Handler

Source: unknown | Confidence: high
SEH unwind: delegates to FUN_0059b390 (dual-pointer free).

**Key logic:** FUN_0059b390()

**Calls:** FUN_0059b390 (dual free, triage)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d368 — CRT Unwind Helper

Source: unknown | Confidence: high
CRT unwind: FUN_00599796 with stack + global.

**Key logic:** FUN_00599796(*(unaff_EBP-0x10), &DAT_008d4440)

**Globals:** DAT_008d4440

**Calls:** FUN_00599796 (no-op stub, triage)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d56c — SEH Unwind Destroy Exception Object

Source: unknown | Confidence: high
SEH unwind destroying exception at EBP-0x10.

**Key logic:** exception::~exception(*(unaff_EBP-0x10))

**Calls:** exception::~exception

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004034d0 — Object Release Array Iterator

Source: unknown | Confidence: medium
Release elements in array, free array, reset pointers.

**Key logic:** If param_1+0x134 null: zero +0x134/+0x130, return. Read count from ptr[-1]. Iterate count times calling FUN_004b0170 (release). Free via FUN_00587bcf(ptr-4). Zero pointers.

**Struct offsets:** +0x130 Ptr1 int*, +0x134 ArrayPtr int*

**Calls:** FUN_004b0170 (object release, triage), FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00404d40 — Struct Field Setter

Source: unknown | Confidence: high
Write param_2 to offset +0x20 in struct pointed by *param_1.

**Key logic:** target = *param_1; target+0x20 = param_2

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00405b00 — Audio Resource Release

Source: unknown | Confidence: medium
Release Miles Sound System audio resource with refcount.

**Key logic:** vtable+8 call. If param_1[0x17] non-null: decrement refcount at ptr+4. If <1: _AIL_mem_free_lock_4 + FUN_00587bcf.

**Struct offsets:** +0x5c SoundData int*, +0x60 Refcount int

**Calls:** _AIL_mem_free_lock_4 (MSS), FUN_00587bcf, FUN_00407be0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406f90 — Object Array + Linked-List Walk

Source: unknown | Confidence: medium
Process array of objects and walk linked list, calling virtual methods.

**Key logic:** If array at +0x48 non-null: iterate count at +0x4c, vtable+8 per element. Walk list at +0x18: vtable+0xc per node.

**Struct offsets:** +0x18 ListHead, +0x20 ListIter, +0x48 ArrayPtr, +0x4c ArrayCount

**Calls:** Virtual calls via vtable+8, vtable+0xc

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040acd0 — Minimum Distance Search

Source: unknown | Confidence: high
Find element with minimum float distance to reference.

**Key logic:** Iterates array (stride 0xa0). Reads float at +0x8c. Computes |ref-value|. Tracks min. Returns index+dist.

**Struct offsets:** +0x0c ArrayBase, +0x10 Count; Element+0x8c CompareValue

**Calls:** FUN_004579c0 (math transform)

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** nearest-neighbor search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040cd60 — Session Phase Decode

Source: unknown | Confidence: high
Return state code 0-5 based on event type field.

**Key logic:** If Ptr2==Ptr1: switch event (+0x34): 0→0,1→1,2→2,3→3,4→4. Else/default: 5.

**Struct offsets:** +0x08 Ptr1, +0x0c Result, +0x18 Ptr2; *(Ptr2)+0x34 EventType

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040f100 — Conditional Cleanup Chain

Source: unknown | Confidence: high
If *param_1 != -1: call 3 cleanup functions.

**Key logic:** If sentinel check passes: FUN_00410af0, FUN_004bdf90, FUN_004be010.

**Calls:** 3 cleanup functions

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00411570 — Status Field Copy

Source: unknown | Confidence: medium
Copy session/player status fields from global array.

**Key logic:** Base DAT_005ecf0c, stride 0x1230. If param_2==0: clear mode (0). Else: copy 4+2+8 field groups via FUN_0040e710.

**Globals:** DAT_005ecf0c, DAT_005ed3ac, DAT_005ed3f0

**Calls:** FUN_0040e710 (field output)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00414380 — Multi-Field Pointer Free

Source: unknown | Confidence: high
Free 8 pointers + head, organized in stride-5 groups.

**Key logic:** FUN_00414d70. 4 groups of 2 ptrs at registers +0x2b..+0x08. Free each non-null via FUN_00587bcf. Free *param_1 if non-null.

**Calls:** FUN_00414d70, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00418940 — State Flag Check

Source: unknown | Confidence: high
Check subsystem availability and state flag.

**Key logic:** If +0xaf4 valid AND vtable+8 returns non-zero: return 1. If +0x864 != -1: return 1. Else: 0.

**Struct offsets:** +0x864 StateFlag, +0xaf4 SubsystemPtr

**Calls:** Virtual call via vtable+8

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041ef00 — Array Scan for Value 10

Source: unknown | Confidence: high
Scan array backward looking for value 10.

**Key logic:** FUN_004c2850 + FUN_004c11d0 get index. Backward scan from param_1+0xd8 + index*4 for value 10.

**Struct offsets:** +0xd8 ValueArray int[]

**Calls:** FUN_004c2850, FUN_004c11d0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00421890 — Path Trailing Backslash Normalizer

Source: unknown | Confidence: high
Ensure path ends with backslash.

**Key logic:** Computes string length. If no trailing '\\': appends backslash from DAT_005c2aac.

**Globals:** DAT_005c2aac (backslash)

**Calls:** None — inline

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00423250 — Windows Admin Check

Source: unknown | Confidence: high
Check if process has admin privileges via Windows security API.

**Key logic:** SEH frame. ImpersonateSelf. OpenThreadToken/OpenProcessToken. Create admin SID. Build security descriptor. AccessCheck. RevertToSelf on success.

**Calls:** Win32 security API (ImpersonateSelf, OpenThreadToken, AccessCheck, etc.) + FUN_00588821

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004560a0 — Dual Field Getter

Source: unknown | Confidence: high
Read two fields at +0x4c/+0x50 to output pointers.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004584a0 — VTable Init + Call Chain

Source: unknown | Confidence: high
Set vtable PTR_LAB_0059f00c, call thunk_FUN_00458020 + FUN_004562a0.

**Calls:** thunk_FUN_00458020, FUN_004562a0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## thunk_FUN_0045b400 — Thunk with Free

Source: unknown | Confidence: high
Set vtable PTR_FUN_0059f080, call FUN_004dd000, optionally free param_1[0xb], call FUN_004dcd10.

**Calls:** FUN_004dd000, FUN_00587bcf, FUN_004dcd10

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0045c750 — Wrapper with Constant

Source: unknown | Confidence: high
Calls FUN_0045c8b0(1), returns param_1.

**Calls:** FUN_0045c8b0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045e5f0 — Array Scan for Match

Source: unknown | Confidence: high
Scan 104-element array at param_1+0x3e18 for value matching param_2.

**Calls:** None — inline

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** linear search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461cd0 — Session State Check

Source: unknown | Confidence: high
Check session state field against 4, with override.

**Key logic:** If *param_1+0x3fc4 != 4: return value. If 4: call FUN_0057a900. If result==3: set to 3. Else: keep 4.

**Struct offsets:** +0x3fc4 SessionState int

**Calls:** FUN_0057a900 (state query)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00464e90 — Buffer Size Lookup

Source: unknown | Confidence: high
Return buffer size by selector. 1→0xB9F, 2→0x1C20, 3→0x7080, 4→0x98968, default→0x5CF

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_00466290 — Flag Clear + Zero Bytes

Source: unknown | Confidence: high
FUN_004988a0(2). Zero bytes at +0xf4/+0xf5. Return 0.

**Calls:** FUN_004988a0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00469857 — Three-Call Chain

Source: unknown | Confidence: high
func_0x5746985d, FUN_0048d360, FUN_004693e0.

**Calls:** FUN_0048d360, FUN_004693e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046c710 — Global Array Scan for Negative

Source: unknown | Confidence: medium
Scan global array for first negative value, branch on +0x174 flag.

**Globals:** DAT_007cd470/DAT_007cd610, DAT_007cd2b8/DAT_007cd457

**Struct offsets:** +0x174 Flag byte

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** linear search

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00475cc0 — Offset/Position Computation

Source: unknown | Confidence: medium
Compute display position offset. If ptrs equal: default (10,10). Else: compute from ftol.

**Calls:** __ftol

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_004795e0 — VTable Set + Init

Source: unknown | Confidence: high
FUN_0048d3a0(param_2,param_3). *param_1 = PTR_FUN_005a4ad8.

**Calls:** FUN_0048d3a0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479a40 — Float Range Constructor

Source: unknown | Confidence: medium
FUN_00466980(-1.0f, 1.0f). Vtable PTR_FUN_005a5938. param_1[0x40]=0.

**Calls:** FUN_00466980

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a550 — Float Value Constructor

Source: unknown | Confidence: medium
FUN_004668e0(0.1f, 1.0f). Vtable PTR_FUN_005a61d8.

**Calls:** FUN_004668e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047beb0 — File Extension Stripper

Source: unknown | Confidence: high
Strip file extension from path (remove after last '.').

**Key logic:** Format path. Walk backward from end. Find '.', truncate to '\0'.

**Calls:** FUN_00568910, FUN_0058815f

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047f370 — Screen Data Struct Init

Source: unknown | Confidence: medium
Init large screen data structure with sentinel pairs + zero region.

**Key logic:** FUN_00495190. Set vtable PTR_FUN_005a6e70. Set sentinel pairs at [0x863..0x868]. Zero-fill 0x1FC dwords from +0x647.

**Calls:** FUN_00495190

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00485900 — Destructor with Conditional Free

Source: unknown | Confidence: high
Free two buffers, call cleanup, optionally free self.

**Struct offsets:** +0x118 BufferA, +0x154 BufferB

**Calls:** FUN_00587bcf, FUN_00499b50, FUN_00485eb0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00486500 — Linked List Tail Append

Source: unknown | Confidence: high
Append node to end of singly-linked list (+0x18 next ptr).

**Struct offsets:** +0xd4 ListHead int*

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** linked list

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487330 — State-Dependent VTable Dispatch

Source: unknown | Confidence: medium
Dispatch to vtable+0x40 based on mode (0-3) and param_1 flag.

**Calls:** FUN_00486720, FUN_00486710, FUN_00487720, vtable+0x40

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00487f30 — VTable Set + Cleanup

Source: unknown | Confidence: high
*param_1 = PTR_FUN_005abac8. FUN_00485eb0.

**Calls:** FUN_00485eb0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489500 — Decrement Counter + Virtual Call

Source: unknown | Confidence: medium
vtable+0x2c(1). Decrement param_1[0x53]. FUN_00489d00 + FUN_00489e90.

**Struct offsets:** +0x14c Counter (param_1[0x53])

**Calls:** vtable+0x2c, FUN_00489d00, FUN_00489e90

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b950 — String Cursor Reset

Source: unknown | Confidence: medium
Reset string cursor, optionally zero-terminate and dispatch.

**Struct offsets:** +0x2f0 StringBase, +0x2f4 Cursor, +0x1e7 FormatBuf

**Calls:** vtable+0x2c, FUN_0048b810

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d380 — Bounds-Checked Index Setter

Source: unknown | Confidence: high
Set +0x338 if param_2 in [0, +0x328).

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e6a0 — Wrapper + Return 0

Source: unknown | Confidence: high
FUN_004966e0(param_1). Return 0.

**Calls:** FUN_004966e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fd80 — Destructor with Conditional Free

Source: unknown | Confidence: high
Vtable PTR_FUN_005a443c. Free param_1[1] if non-null. Optionally free self.

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00490930 — Global Data Read

Source: unknown | Confidence: high
FUN_004906e0() → return *pointer (first dword).

**Calls:** FUN_004906e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004917c0 — Circular Buffer Ring Advance

Source: unknown | Confidence: medium
Advance ring index, remove expired entries (age≥3 triggers free).

**Calls:** FUN_004f9b20, FUN_004910d0 (x2), FUN_00490aa0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** ring buffer maintenance

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00492030 — Token Matching Loop

Source: unknown | Confidence: medium
Parse tokens, match strings, balance nesting counter.

**Globals:** DAT_007cdb70, DAT_005cc4f8, DAT_005cc4f4

**Calls:** FUN_00491fb0, FUN_00587c20

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** tokenizer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495150 — Global Accessor

Source: unknown | Confidence: high
Returns DAT_007cde14.

**Globals:** DAT_007cde14

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00496750 — Doubly-Linked List Append

Source: unknown | Confidence: high
Alloc 16-byte node. Append to list. Dirty flag if param_3 set.

**Struct offsets:** +0x24 DirtyFlag, +0x18bc Head, +0x18c0 Cursor, +0x18c4 Tail, +0x18c8 Count

**Calls:** operator_new

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** linked list

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004979d0 — Field Getter

Source: unknown | Confidence: high
Returns *(param_1+0x20).

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498d90 — Dual-List Destruction

Source: unknown | Confidence: medium
Walk two linked lists calling virtual destructors.

**Calls:** FUN_00498f60, FUN_00486320, FUN_0049a990

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00499360 — Object Registration

Source: unknown | Confidence: medium
Register param_2 into param_1's list with overflow handling.

**Calls:** FUN_004869e0, FUN_00486320, FUN_00486330

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00499ab0 — Struct Init + Path Registry

Source: unknown | Confidence: high
param_1[0]=0, [1]=0xFFFFFFFF. FUN_00566650(param_2). [2]=param_3.

**Calls:** FUN_00566650 (path registry, docs/08)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00499e70 — Path Registry Wrapper

Source: unknown | Confidence: high
FUN_00566650().

**Calls:** FUN_00566650

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a3b0 — Resource Lookup or Create

Source: unknown | Confidence: medium
Lookup name, create node if not found. Follows chain at param_1[slotIndex].

**Calls:** FUN_00589901, FUN_0049a520, FUN_0049a330, thunk_FUN_00566650, FUN_0049a250, FUN_0049a2e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0049afa0 — Wrapper

Source: unknown | Confidence: high
FUN_004b3db0().

**Calls:** FUN_004b3db0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049e410 — Dual Text Display

Source: unknown | Confidence: medium
Format and display two text strings.

**Calls:** FUN_0049bb40, FUN_0049f6a0, FUN_0049bbb0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0049f790 — Mode-Based Dispatch

Source: unknown | Confidence: medium
Dispatch based on global mode/flags. Multiple DAT_007ccXXX checks.

**Globals:** DAT_007cc234, DAT_005ea518, DAT_005ea528, DAT_007cf7ac, DAT_007cc28c/2b8/2e4/310

**Calls:** FUN_0049f150, FUN_0049f170, FUN_004a5750, FUN_004a57a0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004a11d0 — Wrapper (same as 0049afa0)

Source: unknown | Confidence: high
FUN_004b3db0().

**Calls:** FUN_004b3db0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a2770 — Mode-Dependent Subsystem Call

Source: unknown | Confidence: medium
Set fields, call init, conditional subsystem call.

**Struct offsets:** +0x02 ModeFlag, +0x48 Value, +0x64 ActiveFlag

**Calls:** FUN_004a2010, FUN_0054c030

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004a40c0 — Callback Registration

Source: unknown | Confidence: high
FUN_00587b3e(&DAT_004a40d0).

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004aa170 — Multi-Pointer Free

Source: unknown | Confidence: high
Free 3 pointers at +0x04, +0x0c, +0x14 if non-null.

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1a90 — Struct Init with VTable + Sentinels

Source: unknown | Confidence: high
[1]=0, [2]=0xFFFFFFFF, [3]=0, [4]=0xFFFFFFFF. Vtable PTR_LAB_005acc74.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2750 — Float-to-Short Clamped Conversion

Source: unknown | Confidence: high
Convert float to short with clamping. Scale via DAT_005accb4, range DAT_005accb8/bc.

**Struct offsets:** +0x28 MappedValue1 short, +0x2a MappedValue2 short

**Globals:** DAT_005accb4, DAT_005accb8, DAT_005accbc

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** value quantization

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2b90 — Float Threshold Classification

Source: unknown | Confidence: high
Classify float into 2-bit code based on 3 thresholds.

**Struct offsets:** +0x0f ClassificationBits byte

**Globals:** DAT_0059e7fc, DAT_0059e908, DAT_0059ee8c

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** threshold classification

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4450 — Wrapper + Pass-Through

Source: unknown | Confidence: high
FUN_004b4460(). Return param_1.

**Calls:** FUN_004b4460

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b54a0 — Linked-List Validation Walk

Source: unknown | Confidence: medium
Walk list calling FUN_005001f0 (validation) on each node.

**Struct offsets:** +0x20 ListHead, +0x28 ListIter

**Calls:** FUN_005001f0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9cf0 — Float Difference

Source: unknown | Confidence: medium
FUN_004b8790() - *(extraout_ECX+0xf3c)

**Calls:** FUN_004b8790

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba8c0 — Node Destructor

Source: unknown | Confidence: high
If flag byte set: FUN_004b0170 + free *param_1. Optionally free self.

**Calls:** FUN_004b0170, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb3d0 — Node Data Free

Source: unknown | Confidence: high
If flag set: free inner data, free node.

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004bc390 — Lap/Split Time Event

Source: unknown | Confidence: medium
Trigger time/split event with display update.

**Globals:** DAT_008ad238, DAT_008aae64, DAT_0083ee60

**Calls:** FUN_0054c150, FUN_004bc340, FUN_004efbd0, FUN_004d5900, FUN_004b33b0, FUN_004bc4e0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_004c2810 — Array Check + Init

Source: unknown | Confidence: medium
Check array state via FUN_004c2850. If non-zero: FUN_004c1050, return 1.

**Calls:** FUN_004c2850, FUN_004c1050

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2ff0 — Callback Registration

Source: unknown | Confidence: high
FUN_00587b3e(&LAB_004c3000).

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7c00 — Constant 5

Source: unknown | Confidence: high
Returns 5.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c85c0 — Null-Checked VTable Call

Source: unknown | Confidence: high
If DAT_008ac4c8 non-null: vtable+0x14 call on *DAT_008ac4c8.

**Globals:** DAT_008ac4c8

**Calls:** Virtual vtable+0x14

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c92b0 — Object Property Setter

Source: unknown | Confidence: medium
Set param_1+0x1c = param_2. Get object via FUN_004c9260. Call vtable+4.

**Calls:** FUN_004c9260, vtable+4

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004cb4f0 — Multi-Field Free

Source: unknown | Confidence: high
Zero +0x58. Free +0x5c (ptr-4). Zero +100. Free +0x68. Free +0x54 via FUN_005592b0.

**Calls:** FUN_00587bcf, FUN_005592b0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004d0030 — Wrapper

Source: unknown | Confidence: high
FUN_004d0f10().

**Calls:** FUN_004d0f10

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d47e0 — Array State Read

Source: unknown | Confidence: high
FUN_0058801d(param_1, &local_8). Return local_8[0].

**Calls:** FUN_0058801d

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7020 — Struct Init with Sentinels

Source: unknown | Confidence: high
Set fields + sentinels. FUN_004d7050().

**Calls:** FUN_004d7050

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7f20 — Centered Position

Source: unknown | Confidence: medium
Compute centered = param_2 - width/2.

**Calls:** FUN_004d7fa0, FUN_005531f0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004d9280 — Return 0 Stub

Source: unknown | Confidence: high
Returns 0.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dbf90 — Multi-Color Text Render

Source: unknown | Confidence: medium
Render text with multiple color/style passes (yellow/white, style 0/1/2).

**Calls:** FUN_0049c670, FUN_004d7e40 (x5), FUN_0049bde0, FUN_0049be50, FUN_0049c700, FUN_0049c770

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcd80 — Two-Field Setter + Update

Source: unknown | Confidence: high
Set +0x14=param_2, +0x18=param_3. FUN_004dca80().

**Calls:** FUN_004dca80

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004e23d0 — 3x3 Matrix Transform

Source: unknown | Confidence: high
Set position, copy 3x3 matrix, compute transformed output.

**Key logic:** out[x] = M[0][x]*p[0] + M[1][x]*p[1] + M[2][x]*p[2] + pos[x]

**Calls:** None — inline matrix multiply

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** 3D math, matrix transform

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ed750 — 3D Cross Product

Source: unknown | Confidence: high
Compute result = v1 x v2.

**Key logic:** result[0]=v1[1]*v2[2]-v1[2]*v2[1], [1]=v1[2]*v2[0]-v1[0]*v2[2], [2]=v1[0]*v2[1]-v1[1]*v2[0]

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** 3D vector math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f6d60 — Array Non-Zero Counter

Source: unknown | Confidence: high
Count non-zero elements in 5-element array.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8ce0 — Callback Registration

Source: unknown | Confidence: high
FUN_00587b3e(&LAB_004f8cf0).

**Calls:** FUN_00587b3e

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9f30 — Conditional State Reset

Source: unknown | Confidence: medium
If FUN_0055c9b0 && DAT_008afe71: reset DAT_008afe71=0, FUN_005550c0.

**Globals:** DAT_008afe71

**Calls:** FUN_0055c9b0, FUN_005550c0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_004fd6f0 — Range Interpolation Table

Source: unknown | Confidence: high
Fill 14-value table by lerping between range with different coefficients.

**Globals:** Multiple DAT_0059eXXX, DAT_005acXXX, DAT_005adXXX constants

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** lerp/interpolation

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_005006d5 — Lock/Unlock Wrapper

Source: unknown | Confidence: medium
Lock, call FUN_00502a15, unlock. Return error code.

**Calls:** FUN_00500f3c, FUN_00502a15, FUN_00500f55

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00503533 — Image Blending/Compositing

Source: unknown | Confidence: medium
Pixel blending with chroma-key bit arithmetic. SIMD-style ops with 0xffc03fc0/0xff00ff masks.

**Calls:** None — inline pixel processing

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** image processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005063a5 — D3D Context Init

Source: unknown | Confidence: medium
Graphics context init with validation and error cleanup chain.

**Key logic:** Validates format parameter. Creates sub-objects. Runs 11+ init functions. Cleans up on failure with virtual destructors.

**Calls:** FUN_0050b8a9 (x2), FUN_005076fe, FUN_00504508..FUN_00506003 (init chain)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0050ae76 — Constructor Size 0x10

Source: unknown | Confidence: high
FUN_00507496(param_2,0x10,1). Vtable PTR_FUN_005adc7c.

**Calls:** FUN_00507496

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b743 — Constructor Size 0x30

Source: unknown | Confidence: high
FUN_00507496(param_2,0x30,1). Vtable PTR_FUN_005addac.

**Calls:** FUN_00507496

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c2a6 — DirectX Call Wrapper

Source: unknown | Confidence: high
FUN_0050fea7(1). (*DAT_005d77e4)().

**Globals:** DAT_005d77e4 (DX func ptr)

**Calls:** FUN_0050fea7, indirect call

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d5f9 — DX Wrapper (2-param)

Source: unknown | Confidence: high
FUN_0050fea7(1). PTR_FUN_005d7844(param_1, param_2).

**Calls:** FUN_0050fea7, indirect call

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e281 — DX Wrapper (6-param)

Source: unknown | Confidence: high
FUN_0050fea7(1). PTR_FUN_005d7874(param_1..param_6).

**Calls:** FUN_0050fea7, indirect call

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050fa0e — Buffer Processing State Machine

Source: unknown | Confidence: medium
Buffer processing with state transitions, vtable callbacks.

**Calls:** Multiple virtual calls via vtable dispatch

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0051189c — Double-Buffer Init

Source: unknown | Confidence: high
FUN_005117c8(param_1, param_2). FUN_00511869(param_1, local_54).

**Calls:** FUN_005117c8, FUN_00511869

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00513a56 — Flag Setter + Float Store

Source: unknown | Confidence: high
If params non-null: set bit 0 at param_2+8, store (float)param_3 at param_2+0x28.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00515917 — Ceiling Division

Source: unknown | Confidence: high
(int)((param_1 - 1 + param_2) / param_2) — ceiling division.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** integer math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00516853 — Two-Iteration Cleanup

Source: unknown | Confidence: medium
Loop 2x: FUN_00516772. Final: FUN_00519351. Zero +4. FUN_00587b96.

**Calls:** FUN_00516772, FUN_00519351, FUN_00587b96

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00517ee1 — Memory Copy

Source: unknown | Confidence: high
Copy dword-aligned then remainder bytes. Returns dest.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** memory operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051c5a3 — Table Init with Arithmetic Progression

Source: unknown | Confidence: low
Initialize 4 parallel arrays with arithmetic progression values.

**Calls:** Virtual calls via *(in_EAX+4) vtable

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** table generation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052179f — 3D Vector Blend (3DNow!)

Source: unknown | Confidence: medium
Packed floating-point vector interpolation using 3DNow! instructions.

**Calls:** FUN_005215db, FastExitMediaState

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** SIMD (3DNow!)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00528f00 — 3D Vector Normalize (3DNow!)

Source: unknown | Confidence: medium
Packed 3DNow! vector normalization with Newton-Raphson refinement.

**Calls:** PackedFloatingMAX/MIN/MUL/ADD/SUB, FloatingReciprocalAprox, Iter1/Iter2

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** SIMD (3DNow!)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e080 — 64-bit Integer Division

Source: unknown | Confidence: high
(param_1 * param_2) / param_3 using 64-bit arithmetic.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** integer math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005352b0 — String Length Dispatch

Source: unknown | Confidence: high
Compute string length, call FUN_00535220 with length.

**Calls:** FUN_00535220

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00537ce0 — Triple VTable Call

Source: unknown | Confidence: high
FUN_00537000(0). Call (param_2+0x24) three times. Return 0.

**Calls:** FUN_00537000, vtable+0x24 (x3)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b1d0 — Triple Field Getter

Source: unknown | Confidence: high
Read +0x1c/+0x20/+0x24 to output pointers.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c2c0 — Engine Init Block

Source: unknown | Confidence: medium
FUN_0053c2a0. Zero fields. FUN_00556260(1). Set globals.

**Globals:** DAT_008b6c20, DAT_008b8e40, DAT_008b8ed8

**Calls:** FUN_0053c2a0, FUN_00556260

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d1f0 — Wide-String Linked List Search

Source: unknown | Confidence: high
Search linked list (global DAT_008b8e20) for wide-char string match.

**Globals:** DAT_008b8e20

**Calls:** None — inline string comparison

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** linked list search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00540150 — Bitmask Virtual Dispatch

Source: unknown | Confidence: medium
Dispatch to vtable+0x28 or vtable+0x44 based on bitmask.

**Calls:** Virtual calls via vtable+0x28, vtable+0x44

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00542460 — Triple Field Getter (Variant)

Source: unknown | Confidence: high
Read +0x24/+0x28/+0x2c to output pointers.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00544f50 — Two-Level Wide-String Search

Source: unknown | Confidence: high
Search hierarchical linked list (primary + secondary via +0x1b0) for wide-string.

**Calls:** None — inline string comparison

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** linked list search

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547140 — Indexed Field Copy

Source: unknown | Confidence: medium
Switch param_2 (1-4): copy indexed field via DAT_008b8f24 vtable+0x10.

**Globals:** DAT_008b8f24 (UI context)

**Calls:** Virtual call via vtable+0x10

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_005487a0 — Linked-List Walk + Interlocked Dec

Source: unknown | Confidence: medium
Walk list, call FUN_00546450, InterlockedDecrement DAT_008b8eec, FUN_00545f50.

**Globals:** DAT_008b8eec

**Calls:** FUN_00546450, FUN_00545f50

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_005493b0 — String Copy + Node Alloc

Source: unknown | Confidence: medium
Alloc/find node, copy string, normalize.

**Calls:** operator_new, FUN_00548e00, FUN_00589901

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0054bda0 — Self-Relative String Copy

Source: unknown | Confidence: high
Copy string to self-relative offset.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fc10 — Self-Relative Copy + Normalize

Source: unknown | Confidence: high
Copy string to self-relative offset. FUN_00589901.

**Calls:** FUN_00589901

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00552fd0 — Masked Field Setter

Source: unknown | Confidence: high
+0x4c = param_2 & 0x20. +0x50 = param_3 & 0xC0.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00559350 — String Copy + Field Init

Source: unknown | Confidence: high
Self-relative copy. Set +0x14=param_3, +0x18=param_4, +0x1c=0.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** string manipulation

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0055ceb0 — RGBA Byte Extraction

Source: unknown | Confidence: high
Extract R/G/B from packed uint, call FUN_0055cee0.

**Calls:** FUN_0055cee0

**Used by system:** docs/20-math-utilities.md

**Algorithm family:** color/bit manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005647d0 — Callback + Check

Source: unknown | Confidence: medium
Call function ptr at +0xc. Check via FUN_00564a20. Process via FUN_005648b0.

**Calls:** FUN_00564a20, FUN_005648b0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->
## thunk_FUN_0059d6a9 — Null-Check Wrapper

Source: unknown | Confidence: high
If param_1==0: return 0. Else: FUN_005679a5().

**Calls:** FUN_005679a5

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a260 — Byte Field + Offset Getter

Source: unknown | Confidence: high
*(byte*)(param_1+0x2c) + 0x29.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057b6a0 — Pointer Advance

Source: unknown | Confidence: high
param_1 + 0x10.

**Calls:** None

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587490 — Struct Init + Parse

Source: unknown | Confidence: high
Zero init. FUN_00587580 parse. If success: FUN_00587510.

**Calls:** FUN_00587580, FUN_00587510

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/08-file-formats.md -->

## FUN_0058ac95 — Safe String Format

Source: unknown | Confidence: high
Format with overflow guard (0x7FFFFFFF limit).

**Calls:** FUN_0058d04d, FUN_0058cf35

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_005904c1 — Windows NT Check

Source: unknown | Confidence: high
GetVersionExA: return 1 if dwPlatformId==2 (NT).

**Calls:** GetVersionExA

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00595621 — Locale-Aware String Format

Source: unknown | Confidence: medium
Locale formatting with char/wide-char conversion.

**Calls:** FUN_0059567d, FUN_005976e8, FUN_0058fca0

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_005987c1 — Factory Wrapper

Source: unknown | Confidence: high
FUN_00598a41(0, 1).

**Calls:** FUN_00598a41

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c127 — Thread-Safe Wrapper

Source: unknown | Confidence: high
Lock(FUN_0058c1b1). Call FUN_0059c156. Unlock(FUN_0058c203). Return result.

**Calls:** FUN_0058c1b1, FUN_0059c156, FUN_0058c203

**Used by system:** docs/20-math-utilities.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c93a — C++ Unwind Helper

Source: unknown | Confidence: high
Thunk to FUN_00581750.

**Calls:** FUN_00581750 (data structure cleanup)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d020 — C++ Unwind Helper

Source: unknown | Confidence: high
Thunk to FUN_00586210.

**Calls:** FUN_00586210 (CloseHandle cleanup, docs/01)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d99e — Thunk to FUN_004e94a3

Source: unknown | Confidence: high
Calls FUN_004e94a3().

**Calls:** FUN_004e94a3

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

## FUN_005514a0 — Flag Update with Cascade

Source: unknown | Confidence: high
Clears and sets bits in a flag field at param_1+4, then triggers a cascade update.

**Key logic:**
- Clears param_1+4 bitmask: `& 0xfffe2fff` (clears bits 0x1D000 = bits 13, 14, 17)
- Sets bit 0x2000 (bit 13): `| 0x2000`
- Calls FUN_005563e0 (property/flag propagation cascade)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x4 | uint | Bitfield — flags modified then propagated |

**Calls:** FUN_005563e0 (cascade/update notification)

**Used by system:** docs/20-math-utilities.md — flag modification utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055bb50 — Dual Field Set to Same Value

Source: unknown | Confidence: high
Sets two adjacent fields at +0x104 and +0x108 to the same value after calling parent init.

**Key logic:**
- Calls FUN_0053c2a0 (parent constructor / subsystem init)
- Sets `param_1 + 0x104` = param_2
- Sets `param_1 + 0x108` = param_2
- Returns param_1

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x104 | undefined4 | Field set to param_2 |
| +0x108 | undefined4 | Field set to param_2 |

**Calls:** FUN_0053c2a0 (parent constructor / subsystem init, docs/06)

**Used by system:** docs/20-math-utilities.md — object initialization/setter

**Moddability:** configurable — param_2 is caller-supplied value

<!-- target: docs/01-engine-architecture.md -->

## FUN_005668b0 — Zero-Init Small Struct

Source: unknown | Confidence: high
Zero-initializes 6 int fields and a byte field in a small struct.

**Key logic:**
- Sets param_1[1] = 0, param_1[2] = 0xFFFFFFFF, *param_1 = 0
- Sets param_1[3] = 0, param_1[4] = 0, param_1[5] = 0
- Sets `*(byte*)(param_1 + 6)` = 0 (byte field at +0x18)
- Note: param_1[2] = -1 (0xFFFFFFFF) is an intentional sentinel value, not a zero

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | undefined4 | Field 0 — zeroed |
| +0x04 | undefined4 | Field 1 — zeroed |
| +0x08 | undefined4 | Field 2 — set to 0xFFFFFFFF (sentinel/INVALID) |
| +0x0c | undefined4 | Field 3 — zeroed |
| +0x10 | undefined4 | Field 4 — zeroed |
| +0x14 | undefined4 | Field 5 — zeroed |
| +0x18 | byte | Field 6 — zeroed |

**Used by system:** docs/20-math-utilities.md — struct initialization utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00568560 — Replace Special Chars with Underscore/Hyphen

Source: unknown | Confidence: high
String sanitizer: replaces special characters with underscores and hyphens in-place.

**Key logic:**
- Two-pass string sanitization on param_1 (char*)
- Pass 1: Iterates chars > 0x2D ('-') that are not '0'-'9' or '\\' → replaces with '_'
  - Matches: chars in range '.' to '/' and ':' to '[' etc.
- Pass 2: Iterates chars, calls FUN_005685b0 (char classification), if true → replaces with '-'
- Null-safe: checks param_1 != NULL before processing

**Algorithm family:** string sanitization

**Calls:** FUN_005685b0 (character classification — not yet documented)

**Used by system:** docs/20-math-utilities.md — string processing utility for filename/path sanitization

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00586f70 — Bit Set/Clear Operation

Source: unknown | Confidence: high
Sets or clears a single bit in a bitmap/bitfield based on a boolean parameter.

**Key logic:**
- Computes bit mask: `1 << (param_2 & 7)` (bit position within byte)
- Computes byte index: `param_2 >> 3` (bit index / 8)
- If param_3 (char) != 0: ORs mask into byte at `*param_1 + byte_index` (set bit)
- Else: ANDs complement of mask (clear bit)
- Classic bitmap bit manipulation pattern

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | Base pointer to bitmap buffer |

**Algorithm family:** bitwise bitmap manipulation

**Used by system:** docs/20-math-utilities.md — bitmap/flag array utility

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_005884e0 — TLS Field Setter

Source: unknown | Confidence: high
Retrieves the thread-local storage (TLS) buffer and writes param_1 at offset +0x14.

**Key logic:**
- Calls FUN_0058e0c7() — retrieves/initializes TLS buffer for current thread
- Writes param_1 to `TLS_buffer + 0x14`
- Used to store a per-thread value in the TLS slot

**Globals:**
- `DAT_005e6d40` — TLS index (used by FUN_0058e0c7)

**Calls:** FUN_0058e0c7 (TLS value retrieval with init)

**Used by system:** docs/20-math-utilities.md — per-thread storage setter

**Moddability:** configurable — param_1 is caller-supplied

<!-- target: docs/08-file-formats.md -->

## FUN_0058c38e — Handle Close with Error Reporting

Source: unknown | Confidence: high
Closes a Win32 handle by index from a handle table, with error checking.

**Key logic:**
- Calls FUN_00595a1f(param_1) — indexed bitmap lookup (docs/06)
- If lookup returns -1: handle not found, skip
- If param_1 == 1 or 2 (std handles): checks both share same handle to avoid double-close
- Calls CloseHandle() on handle value
- On CloseHandle failure: gets GetLastError()
- Calls FUN_005959a0(param_1) — release handle table slot
- Sets `DAT_008d4920[(param_1>>5)] + 4 + (param_1 & 0x1f) * 0x24` = 0 (mark slot free)
- On error: calls FUN_0058af5c(DVar4) (error logging), returns -1
- On success: returns 0

**Globals:**
- `DAT_008d4920` — Handle table base

**Calls:** FUN_00595a1f (indexed bitmap lookup, docs/06), CloseHandle (Win32), GetLastError (Win32), FUN_005959a0 (release handle slot), FUN_0058af5c (error logging)

**Used by system:** docs/20-math-utilities.md — Win32 handle management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058e0c7 — TLS Value Retrieval with Init

Source: unknown | Confidence: high
Retrieves the thread-local storage buffer for the current thread, allocating and initializing it on first access.

**Key logic:**
- Saves GetLastError() state
- Calls TlsGetValue(DAT_005e6d40) — retrieve TLS buffer for this thread
- If TLS value is NULL (first call for this thread):
  - Allocates 0x74-byte buffer via FUN_0058ab58(1, 0x74)
  - Calls TlsSetValue(DAT_005e6d40, buffer)
  - Calls FUN_0058e0b4(buffer) — zero-init TLS buffer
  - Stores GetCurrentThreadId() in buffer[0]
  - Sets buffer[1] = 0xFFFFFFFF
  - On failure: calls __amsg_exit(0x10) — fatal error
- Restores original GetLastError()
- Returns TLS buffer pointer

**Globals:**
- `DAT_005e6d40` — TLS index

**Calls:** TlsGetValue, TlsSetValue, GetCurrentThreadId, GetLastError, SetLastError (Win32), FUN_0058ab58 (heap alloc), FUN_0058e0b4 (buffer init), __amsg_exit (fatal error)

**Used by system:** docs/20-math-utilities.md — MSVC CRT per-thread data management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00591e66 — Return FPU Control Word

Source: unknown | Confidence: high
Returns the current FPU (x87) control word as an integer.

**Key logic:**
- Reads the FPU control word from the `in_FPUControlWord` register
- Returns as int (cast from short)
- Used to save/query FPU precision mode (single/double/extended), rounding control, and exception masks

**Algorithm family:** FPU control register read

**Used by system:** docs/20-math-utilities.md — FPU state management utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005952e9 — 4-Int Copy (Align/Memcpy Helper)

Source: unknown | Confidence: high
Copies 4 consecutive int values (16 bytes) from source to destination using pointer arithmetic.

**Key logic:**
- Computes dest = source_ptr - (param_1 - param_2) using subtraction-based offset
- Loop: copies 4 ints from param_2[] to dest[] (stride 1, 4 iterations)
- Unrolled or counted loop (iVar1 = 3 down to 0)
- Essentially: memcpy(param_1, param_2, 16) via the param_1 instead of param_2 as dest

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — small block memory copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00597fac — WideChar→MultiByte String Conversion with Alloc Loop

Source: unknown | Confidence: high
Iterates a linked list of wide strings, converts each to UTF-8/MultiByte, and registers via callback.

**Key logic:**
- Reads linked list from global `DAT_008d3e98`
- For each node containing a wide string (LPWSTR):
  - Calls WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL) to get required buffer size
  - Allocates buffer with _malloc()
  - Calls WideCharToMultiByte to perform conversion into buffer
  - Calls FUN_00598323(buffer, 0) — register/converted string storage
  - Advances to next node
- On failure (allocation error or conversion error): returns -1
- Returns 0 on success (or if list empty)

**Globals:**
- `DAT_008d3e98` — linked list of wide strings (command-line args / locale strings)

**Calls:** WideCharToMultiByte (Win32), _malloc, FUN_00598323 (string registration)

**Used by system:** docs/20-math-utilities.md — MSVC CRT locale/string initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059bf56 — Strlen + Alloc + Copy Constructor Pattern

Source: unknown | Confidence: high
String copy constructor: allocates memory and copies string, or directly assigns pointer for empty strings.

**Key logic:**
- Sets `*param_1 = &PTR_FUN_005b9dc0` (vtable)
- Reads `param_2 + 8` (string length/sentinel)
- Stores length in `param_1[2]`
- If length == 0: directly copies pointer from `param_2 + 4` (borrowed reference, no copy)
- Else: calls _strlen() on string at `param_2 + 4`, allocates via operator_new(len+1), copies via FUN_0058fca0 (memcpy/strcpy)
- Stores allocated copy in `param_1[1]`
- Returns param_1

**Struct offsets (param_1 — string object):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | void* | vtable pointer (PTR_FUN_005b9dc0) |
| +0x04 | char* | String buffer (pointer to data) |
| +0x08 | int | Length/flag |

**Param_2 (source string object):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | char* | String data |
| +0x08 | int | String length (0 = empty/bare pointer) |

**Calls:** _strlen, operator_new, FUN_0058fca0 (string/memory copy)

**Used by system:** docs/20-math-utilities.md — C++ string copy constructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c52c — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_00506ccc.

**Key logic:**
- Calls FUN_00506ccc() — cleanup function (trampoline target)
- No local variables — pure delegation

**Calls:** FUN_00506ccc (cleanup trampoline)

**Used by system:** docs/01-engine-architecture.md — MSVC SEH exception unwind handler

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c65c — CRT Unwind: Free Stack Object

Source: unknown | Confidence: high
SEH unwind handler: frees an object at EBP+8 (stack-allocated during SEH).

**Key logic:**
- Reads pointer from `EBP + 8` (stack frame local)
- Calls FUN_00587bcf() to free/deallocate it
- MSVC __except_handler3 cleanup pattern for stack-allocated objects

**Calls:** FUN_00587bcf (free/delete)

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c7d8 — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_0057bc70.

**Key logic:**
- Calls FUN_0057bc70() — cleanup/destructor call
- No local variables — pure delegation

**Calls:** FUN_0057bc70 (cleanup call)

**Used by system:** docs/01-engine-architecture.md — MSVC SEH exception unwind handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c910 — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_00581a20.

**Key logic:**
- Calls FUN_00581a20() — cleanup/destructor call
- No local variables — pure delegation

**Calls:** FUN_00581a20 (cleanup call)

**Used by system:** docs/01-engine-architecture.md — MSVC SEH exception unwind handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cb40 — SEH Unwind with Single Call

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_00583270.

**Key logic:**
- Calls FUN_00583270() — cleanup/destructor call
- No local variables — pure delegation

**Calls:** FUN_00583270 (cleanup call)

**Used by system:** docs/01-engine-architecture.md — MSVC SEH exception unwind handler

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cceb — SEH Unwind Free Object at -0x10

Source: unknown | Confidence: high
SEH unwind handler: frees a stack-allocated object at EBP-0x10.

**Key logic:**
- Reads pointer from `EBP - 0x10` (stack local variable)
- Calls FUN_00587bcf() to free/deallocate it
- MSVC __except_handler3 pattern — cleanup local object on exception

**Calls:** FUN_00587bcf (free/delete)

**Used by system:** docs/01-engine-architecture.md — MSVC SEH exception unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cec9 — CRT Unwind: General Cleanup

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_004b0170 for general cleanup.

**Key logic:**
- Calls FUN_004b0170() — general object cleanup/release
- No local variable access — pure delegation

**Calls:** FUN_004b0170 (general cleanup/release)

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d02e — CRT Unwind: Call Linked-List Destructor

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_005833e0 (linked-list destructor).

**Key logic:**
- Calls FUN_005833e0() — walk linked list, call destructor, free nodes
- No local variables — pure delegation

**Calls:** FUN_005833e0 (linked list destructor, docs/01)

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception unwind cleanup for list containers

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d190 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_00499ae0.

**Key logic:**
- Calls FUN_00499ae0() — object cleanup/teardown (docs/21 — network subsystem cleanup)
- No local variables — pure delegation

**Calls:** FUN_00499ae0 (network/subsystem cleanup, docs/21)

**Used by system:** docs/01-engine-architecture.md — MSVC SEH exception unwind handler for network objects

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d3a8 — CRT Unwind: Conditional Object Destruction

Source: unknown | Confidence: high
SEH unwind handler: conditionally calls destructor on local object based on flag at EBP-0x10.

**Key logic:**
- Checks `*(uint*)(EBP - 0x10) & 1` (flag on local object)
- If bit 0 set: calls FUN_00599be5() — destructor/cleanup
- Conditional destruction pattern for MSVC SEH unwinding

**Calls:** FUN_00599be5 (conditional destructor)

**Used by system:** docs/20-math-utilities.md — MSVC CRT exception unwind with conditional destructor call

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d580 — SEH Unwind: exception::~exception

Source: unknown | Confidence: high
SEH unwind handler: calls the MSVC exception destructor on a local exception object.

**Key logic:**
- Reads exception pointer from `EBP - 0x10` (stack-local exception object)
- Calls `exception::~exception()` — MSVC standard exception destructor
- Standard MSVC CRT pattern for exception handling cleanup

**Calls:** exception::~exception (MSVC CRT)

**Used by system:** docs/20-math-utilities.md — MSVC exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00403540 — Index Remapping with Stride (Collision/Physics Array)

Source: unknown | Confidence: medium
Iterates array with stride 0x13c, remapping index fields to pointer offsets or resetting to sentinel.

**Key logic:**
- Count at `param_1 + 0x130` (element count)
- Base index at `param_1 + 0x134` (offset base)
- For each element (stride 0x13c):
  - Reads index at +0x124, +0x120, +0x128 relative to base
  - If index == -1 or index >= count: zeroes corresponding offset field (+0x110, +0x10c, +0x114) and sets index to -1
  - Else: computes offset = index * 0x13c + base_offset and stores it
- Essentially remapping 3 relative indices to absolute offsets

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x130 | int | Element count |
| +0x134 | int | Base offset/index |
| +0x10c | int | First remapped offset (per-element, stride 0x13c) |
| +0x110 | int | Second remapped offset (per-element) |
| +0x114 | int | Third remapped offset (per-element) |
| +0x120 | int | First source index (per-element) |
| +0x124 | int | Second source index (per-element) |
| +0x128 | int | Third source index (per-element) |

**Algorithm family:** array index remapping

**Used by system:** docs/20-math-utilities.md — collision/physics index resolution

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00408280 — Field Clear + Chain Call

Source: unknown | Confidence: high
Clears a byte flag at +0x15, then calls FUN_004083e0.

**Key logic:**
- Sets `param_1 + 0x15` = 0 (clears byte flag)
- Calls FUN_004083e0() — camera manager update (docs/01)
- Returns param_1

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x15 | byte | Flag — zeroed |

**Calls:** FUN_004083e0 (camera manager update, docs/01)

**Used by system:** docs/20-math-utilities.md — camera/state flag cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040ad60 — Linear Search with Stride 0xA0

Source: unknown | Confidence: high
Finds index of a matching value in an array with stride 0xA0 (160 bytes per element).

**Key logic:**
- Reads count at `param_1 + 0x10`
- If count > 0: starts from `param_1 + 0xc` (first element key)
- Compares each element's first field against param_2
- Advances by stride 0xA0 per element
- Returns index (0-based) on match, -1 on not found
- Linear search, breaks on first match

**Struct offsets (param_1 — array container):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0c | int | First element's key field (array base) |
| +0x10 | int | Element count |

**Algorithm family:** linear search with fixed stride

**Used by system:** docs/20-math-utilities.md — linear search in structured array

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040cdd0 — Simple Setter (Struct + 8 = param_2)

Source: unknown | Confidence: high
Sets +0x8 field on a struct to param_2. One-line setter.

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | undefined4 | Set to param_2 |

**Used by system:** docs/20-math-utilities.md — leaf setter

**Moddability:** configurable — param_2 is caller-supplied

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e1c0 — Delegation Thunk

Source: unknown | Confidence: high
Thin wrapper: calls FUN_0040fb00().

**Key logic:**
- Calls FUN_0040fb00 — no args, no return value

**Calls:** FUN_0040fb00 (unknown)

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00411650 — Circular Buffer Index Increment

Source: unknown | Confidence: high
Circular buffer counter: increments index with wraparound.

**Key logic:**
- Reads `param_1[0]` (max count/buffer size)
- If max > 1:
  - Returns current `param_1[1]` (index position)
  - Increments `param_1[1]`
  - If index >= max: wraps to 0
- Returns 0 if max <= 1

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | ushort | Buffer max size |
| +0x02 | ushort | Current index (post-increment) |

**Algorithm family:** circular buffer index stepping

**Used by system:** docs/20-math-utilities.md — circular buffer/ring counter utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00418970 — Threshold-Gated Virtual Dispatch

Source: unknown | Confidence: medium
Checks a value against thresholds (DAT_0059e440, DAT_0059e43c), then calls virtual method at vtable+0x1c.

**Key logic:**
- Checks: pointer at `param_1 + 0xaf4` != null
- Checks: `DAT_0059e440` (zero threshold ~0.0f) <= param_2
- Checks: param_2 < DAT_0059e43c (physics constant)
- If all true: calls virtual method at vtable+0x1c on the object at param_1+0xaf4

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xaf4 | void* | Object with vtable at +0x1c |

**Globals:**
- `DAT_0059e440` (ZeroThreshold ~0.0f, physics clamp)
- `DAT_0059e43c` (physics constant — upper bound)

**Used by system:** docs/20-math-utilities.md — threshold-gated physics callback dispatch

**Moddability:** configurable — DAT_0059e440 and DAT_0059e43c are physics constants

<!-- target: docs/06-session-race-logic.md -->

## FUN_00423459 — Handle/Resource Cleanup (LocalFree + FreeSid)

Source: unknown | Confidence: high
Windows cleanup function: frees two LocalAlloc handles and a security ID.

**Key logic:**
- If `unaff_EBX` != 0: calls LocalFree (Win32)
- If `unaff_EDI` != 0: calls LocalFree (Win32)
- If `*(PSID*)(EBP - 0x24)` != 0: calls FreeSid (Win32 security)
- Register-based parameters indicate inline cleanup in a larger function

**Calls:** LocalFree (Win32), FreeSid (Win32)

**Used by system:** docs/20-math-utilities.md — Win32 resource cleanup (security descriptor cleanup)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0045bb60 — ID to Color Mask Mapper

Source: unknown | Confidence: high
Maps ID (1 or 2) to specific color mask values.

**Key logic:**
- If param_1 == 1: return 0xFFFF0000 (red channel mask)
- If param_1 == 2: return 0xFFFFFF00 (luma/alpha mask)
- Else: return 0xFFFFFFFF (default/white)

**Used by system:** docs/20-math-utilities.md — color format conversion utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045c780 — Bounded Byte Array Accessor

Source: unknown | Confidence: high
Safe array access into byte array at param_1+0x354 with bounds check.

**Key logic:**
- If 0 <= param_2 < 0x68 (104): returns byte at `param_1 + 0x354 + param_2`
- Else: returns 0

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x354 | byte[104] | Bounded byte array |

**Used by system:** docs/20-math-utilities.md — bounds-checked byte array accessor

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004646c0 — Float Clamp

Source: unknown | Confidence: high
Clamps a float value between min and max bounds, in-place.

**Key logic:**
- If `*param_1 < param_2`: set `*param_1 = param_2` (lower bound)
- Else if `param_3 < *param_1`: set `*param_1 = param_3` (upper bound)
- Classic clamp: `param_2 <= result <= param_3`

**Algorithm family:** math utility — float clamping

**Used by system:** docs/20-math-utilities.md — value clamping utility

**Moddability:** configurable — bounds are caller-supplied

<!-- target: docs/20-math-utilities.md -->

## FUN_00464ee0 — Conditional Delegate Based on Counter

Source: unknown | Confidence: high
If counter field < 1, calls delegate function with first field.

**Key logic:**
- Checks `param_1[0x14]` (counter at +0x50)
- If counter < 1: calls FUN_00464e90(*param_1) with first field

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | undefined4 | First field — passed to delegate |
| +0x50 | int | Counter — gate condition |

**Calls:** FUN_00464e90 (delegate — unknown)

**Used by system:** docs/20-math-utilities.md — threshold-gated delegation

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0047a580 — Float Return Stub

Source: unknown | Confidence: high
Returns a float literal constant.

**Key logic:**
- Returns 0.0f (returns float 0)

**Used by system:** docs/20-math-utilities.md — constant getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047C0A0 � String Copy from UI Screen to Global Buffer

Source: unknown | Confidence: high
Copies null-terminated string from UI screen text accessor to global buffer.

**Key logic:**
- Calls FUN_00489920() � UI screen text accessor (docs/19)
- If result non-null: copies string byte-by-byte from source to DAT_007cd880 including null terminator

**Globals:**
- DAT_007cd880 � global string buffer (32 chars, used in track init docs/09)

**Calls:** FUN_00489920 (UI screen text accessor, docs/19)

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0047f3d0 — Simple Getter

Source: unknown | Confidence: high
Returns a value from struct at offset +0x10.

**Key logic:**
- Returns `*(int*)(param_1 + 0x10)`

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x10 | int | Returned value |

**Used by system:** docs/20-math-utilities.md — leaf getter

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004979e0 — Simple Setter (Zero at +0x20)

Source: unknown | Confidence: high
One-line setter: zeros field at param_1+0x20.

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x20 | int | Zeroed |

**Used by system:** docs/20-math-utilities.md — field zero utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498df0 — Multi-Field Struct Init

Source: unknown | Confidence: high
Zero-initializes many fields in a struct with one field set to 1.

**Key logic:**
- Zeroes +0x48, +0x4c, +0x50, +0x64, +0x68, +0x58
- Sets +0x60 = 1 (active/default flag)
- Zeroes +0x5c
- Zeroes 10 ints starting at +0x6c
- Zeroes 10 ints starting at +0x94

**Used by system:** docs/20-math-utilities.md — struct init utility

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00499ae0 — Free If Non-Null

Source: unknown | Confidence: high
Conditionally frees pointer at `*param_1` if non-null.

**Key logic:**
- If `*param_1 != 0`: calls FUN_00587bcf(*param_1) — free

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — safe free utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499e80 — Delegation to Path Registry

Source: unknown | Confidence: high
Calls FUN_00566650() with no args.

**Calls:** FUN_00566650 (path registry)

**Used by system:** docs/20-math-utilities.md — path registry delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a460 — String Normalize + Lookup

Source: unknown | Confidence: medium
Normalizes a string, looks it up, returns result.

**Key logic:**
- Calls FUN_00589901(param_1) — string normalize
- Calls FUN_0049a360(param_1) — lookup
- If found (non-zero): returns FUN_0049a2d0()
- Else: returns 0

**Calls:** FUN_00589901 (string normalize), FUN_0049a360 (lookup), FUN_0049a2d0 (get result)

**Used by system:** docs/20-math-utilities.md — string lookup/normalize

**Moddability:** configurable — param_1 is input string

<!-- target: docs/01-engine-architecture.md -->

## FUN_0049e490 — Zero-Init Large Buffer (0x60 bytes)

Source: unknown | Confidence: high
Zeroes 0x60 bytes starting at param_1 (24 ints).

**Key logic:**
- Zeros 24 consecutive 4-byte fields (param_1[0] through param_1[0x17])

**Used by system:** docs/20-math-utilities.md — large buffer zero-init

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a27d0 — Conditional Dispatch

Source: unknown | Confidence: medium
If field at +0x64 is non-zero, dispatches six fields to FUN_0054b4d0.

**Calls:** FUN_0054b4d0

**Used by system:** docs/20-math-utilities.md — conditional dispatch helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a40e0 — Large Buffer Zero-Init (0x68 ints)

Source: unknown | Confidence: high
Zeroes 0x68 consecutive ints starting at param_1 (0x1A0 bytes total).

**Used by system:** docs/20-math-utilities.md — large buffer zero-init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004aa1b0 — Free Two Pointers

Source: unknown | Confidence: high
Frees two pointers at +0x0c and +0x04 if non-null.

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — safe multi-free

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1ab0 — Identity Function

Source: unknown | Confidence: high
Returns param_1 unchanged.

**Used by system:** docs/20-math-utilities.md — identity/no-op function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2800 — Short-to-Float Vector Unpack

Source: unknown | Confidence: high
Converts 2 short values to floats with a global scale factor.

**Key logic:**
- `param_2[0]` = `*(short*)(param_1+0x28) * DAT_0059e4d8`
- `param_2[1]` = 0.0f
- `param_2[2]` = `*(short*)(param_1+0x2a) * DAT_0059e4d8`

**Globals:** `DAT_0059e4d8` (physics scale factor)

**Algorithm family:** vector unpack — short-to-float with scale

**Used by system:** docs/20-math-utilities.md — physics vector unpack

**Moddability:** configurable — DAT_0059e4d8 is a physics constant

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2bf0 — Ternary Select by Bitfield

Source: unknown | Confidence: medium
Selects one of 4 physics constants based on 2-bit field.

**Key logic:**
- Reads `param_1+0xf` & 3 (2-bit selector)
- Returns one of four DAT_ floats: 0→DAT_0059e6e8, 1→DAT_0059e8cc, 2→DAT_0059e824, 3→DAT_0059e43c

**Algorithm family:** physics constant lookup by index

**Used by system:** docs/20-math-utilities.md — indexed physics constant selector

**Moddability:** configurable — DAT_ globals are physics constants

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4460 — Small Struct Zero-Init

Source: unknown | Confidence: high
Zeroes 10 bytes: 2 ints + 1 short.

**Key logic:**
- Sets `*param_1 = 0`, `param_1[1] = 0`, `*(short*)(param_1+2) = 0`

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004bb400 — Linked-List Destructor

Source: unknown | Confidence: high
Frees all nodes in a singly-linked list and zeros container fields.

**Key logic:**
- Walks list: for each node, if flag byte at node+3 non-zero, frees `*node`; then frees node
- Zeros all 4 container fields

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — linked list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bd760 — Sentinel Slot Fill

Source: unknown | Confidence: high
Finds first -1 slot in a 10-element array, writes value at param_1+8 there.

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | int | Value to store |
| +0xe0 | int[10] | Array of 10 slots |

**Used by system:** docs/20-math-utilities.md — sentinel-array insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bf630 — Zero-Init 4 Ints

Source: unknown | Confidence: high
Zeroes 4 ints (16 bytes).

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004c3020 — Delegation Thunk

Source: unknown | Confidence: high
Calls FUN_004b3db0().

**Calls:** FUN_004b3db0

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7c10 — Conditional Delegation (if param_1 == 1)

Source: unknown | Confidence: high
If param_1 == 1: returns FUN_00404fe0(). Else returns 0.

**Calls:** FUN_00404fe0

**Used by system:** docs/20-math-utilities.md — conditional leaf dispatch

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_004d4800 — State Get/Set Wrapper

Source: unknown | Confidence: medium
Sets state to 2, reads it, restores to 0, returns saved value.

**Calls:** FUN_004d47e0, FUN_004d47c0

**Used by system:** docs/20-math-utilities.md — temporary state swap

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004d7f60 — Size Computation with Subtraction

Source: unknown | Confidence: medium
Calls FUN_004d7fa0, computes delta.

**Key logic:**
- Calls FUN_004d7fa0(param_4) — get base value
- If non-zero: calls FUN_005531f0, sets `*param_3 = param_2 - param_4`

**Calls:** FUN_004d7fa0, FUN_005531f0

**Used by system:** docs/20-math-utilities.md — size/delta computation

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004dcda0 — Float-to-Int Conversion + Dispatch

Source: unknown | Confidence: medium
Converts float to int with __ftol, passes result to FUN_004dcd80.

**Calls:** __ftol, FUN_004dcd80

**Used by system:** docs/20-math-utilities.md — float-int conversion chain

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f8d10 — Delegation Thunk

Source: unknown | Confidence: high
Calls FUN_004f8d40().

**Calls:** FUN_004f8d40

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9f60 — Time + Offset Getter

Source: unknown | Confidence: medium
Returns FUN_00568d90() + DAT_008afea0.

**Globals:** DAT_008afea0

**Calls:** FUN_00568d90

**Used by system:** docs/20-math-utilities.md — time computation

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00503659 — Physics State Dispatch

Source: unknown | Confidence: low
Dispatches physics state arrays to a function pointer (PTR_FUN_005d76c0).

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int | Source struct |
| +0x04 | int | Target struct with +0x18, +0x1050-0x105c fields |

**Used by system:** docs/20-math-utilities.md — physics state copy/dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005064bf — Zero-Init 4 Ints (fast path)

Source: unknown | Confidence: high
Zeroes 4 ints (16 bytes) at param_1.

**Used by system:** docs/20-math-utilities.md — buffer zero-init

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_005118c1 — Two-Step Delegation

Source: unknown | Confidence: medium
Calls FUN_005117c8 then FUN_00511887.

**Calls:** FUN_005117c8, FUN_00511887

**Used by system:** docs/20-math-utilities.md — two-step call delegation

**Moddability:** configurable — params are caller-supplied

<!-- target: docs/20-math-utilities.md -->

## FUN_00513b12 — Flag Setter with Guard

Source: unknown | Confidence: high
If both param_1 and param_2 non-null: sets flag at param_2+8 bit 3, stores param_3/param_4.

**Struct offsets (param_2):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | uint | Flag field — ORed with 8 |
| +0x10 | undefined4 | Set to param_3 |
| +0x14 | undefined2 | Set to param_4 |

**Used by system:** docs/20-math-utilities.md — conditional flag/field setter

**Moddability:** configurable — params are caller-supplied

<!-- target: docs/20-math-utilities.md -->

## FUN_00515927 — Align Up (Round to Multiple)

Source: unknown | Confidence: high
Rounds param_1 up to the next multiple of param_2.

**Key logic:**
- `result = (param_1 - 1 + param_2) - ((param_1 - 1 + param_2) % param_2)`
- Equivalent to: `((param_1 + param_2 - 1) / param_2) * param_2`

**Algorithm family:** integer math — round up to multiple

**Used by system:** docs/20-math-utilities.md — alignment/memory utility

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00517f04 — Memset with Byte Fill

Source: unknown | Confidence: high
Fills memory with a byte value (optimized memset).

**Key logic:**
- Fills `param_4 / 4` ints with byte repeated 4 times (via CONCAT22/CONCAT11)
- Fills remaining `param_4 & 3` bytes
- Returns param_2 (destination)

**Algorithm family:** memory utility — optimized memset

**Used by system:** docs/20-math-utilities.md — memory fill utility

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00529000 — Square Root Approximation (SIMD/3DNow!)

Source: unknown | Confidence: medium
SQRT approximation using 3DNow!/SIMD reciprocal instructions.

**Algorithm family:** math utility — SIMD square root approximation

**Used by system:** docs/20-math-utilities.md — SIMD math utility

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00537eb0 — Empty Stub

Source: unknown | Confidence: high
Empty function — returns immediately. Placeholder or stripped virtual.

**Used by system:** docs/20-math-utilities.md — empty placeholder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b200 — Multi-Field Setter (5 fields)

Source: unknown | Confidence: high
Sets 5 fields from params, one to 1.0f.

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | int | param_2 |
| +0x08 | int | param_3 |
| +0x0c | int | param_4 |
| +0x58 | int | copy of param_2 |
| +0x5c | int | copy of param_3 |
| +0x60 | int | copy of param_4 |
| +0x64 | float | 1.0f (0x3f800000) |

**Used by system:** docs/20-math-utilities.md — multi-field assignment

**Moddability:** configurable

<!-- target: docs/19-renderer.md -->

## FUN_00542490 — 3-Field Getter

Source: unknown | Confidence: high
Returns 3 fields from param_1 if output pointers are non-null.

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x30 | int | Field A |
| +0x34 | int | Field B |
| +0x38 | int | Field C |

**Used by system:** docs/20-math-utilities.md — multi-field getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00545020 — Simple Getter (+0xf8)

Source: unknown | Confidence: high
Returns `*(int*)(param_1 + 0xf8)`.

**Used by system:** docs/20-math-utilities.md — leaf getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005471c0 — Simple Setter (+0xb0)

Source: unknown | Confidence: high
Sets `param_1 + 0xb0 = param_2`.

**Used by system:** docs/20-math-utilities.md — leaf setter

**Moddability:** configurable — param_2 is caller-supplied

<!-- target: docs/20-math-utilities.md -->

## FUN_005487e0 — Linked-List Walk with Exit Check

Source: unknown | Confidence: medium
Walks linked list at +0x24 via +0xc0 next pointer, checking FUN_005469c0.

**Calls:** FUN_005469c0

**Used by system:** docs/20-math-utilities.md — linked list traversal

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0054c030 — Flag Field Bit Manipulation

Source: unknown | Confidence: high
Sets/clears bits in a flag field at +0x3c based on 3 boolean params.

**Key logic:**
- param_4 == 1 → recursive call
- param_2: 1 = clear bit 1, 0 = set bits 1 and 2
- param_3: 1 = clear bit 2, 0 = set bit 2

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x3c | uint | Bitfield modified |

**Used by system:** docs/20-math-utilities.md — flag bit manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fc40 — Simple Setter (+0x60)

Source: unknown | Confidence: high
Sets `param_1 + 0x60 = param_2`.

**Used by system:** docs/20-math-utilities.md — leaf setter

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_00553620 — Setter Writes +0x10, Returns 0

Source: unknown | Confidence: high
Sets `param_1 + 0x10 = param_2`, returns 0.

**Used by system:** docs/20-math-utilities.md — setter with fixed return

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_005597c0 — Binary Tree Search (2-byte key)

Source: unknown | Confidence: high
Binary tree search using 2-byte key comparison, walking +0x1c link.

**Key logic:**
- Starts at root (`param_1 + 4`)
- Compares 2-byte keys sequentially
- Returns matching node or null on miss
- Walks via +0x1c (right child pointer)

**Algorithm family:** data structure — binary tree search

**Used by system:** docs/20-math-utilities.md — binary tree lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055d230 — Struct Init with Float Defaults (1.0, -1.0)

Source: unknown | Confidence: high
Initializes a struct with 9 fields set to 1.0f and 1 set to -1.0f.

**Key logic:**
- Calls FUN_0053c2a0 (parent constructor)
- Zeroes many fields
- Sets `*param_1 = 0x180` (flag/value)
- Sets param_1[5..0xd] = 0x3f800000 (9 fields = 1.0f)
- Sets param_1[0x12] = 0xbf800000 (-1.0f)

**Used by system:** docs/20-math-utilities.md — struct initializer with float defaults

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00567a30 — Linked-List Destructor with Inner Free

Source: unknown | Confidence: high
Destroys linked list at +0x24: frees inner data pointer if flag set and inner pointer has data.

**Key logic:**
- Calls FUN_00567f10
- Walks linked list: for each node, if flag byte at node[2] set and `*node` non-null → frees `**node` then `*node`
- Frees each node
- Zeros 4 container fields at +0x24..+0x30

**Calls:** FUN_00567f10, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — linked list destruction with nested free

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a330 — Struct Field Serializer/Packer

Source: unknown | Confidence: high
Serializes 7 fields from a struct into a byte buffer.

**Key logic:**
- Calls FUN_0057a1b0 for each field: +0x04 (int, 4 bytes), +0x08 (char[32], 32 bytes), +0x28..+0x2d (6 bytes)
- Final field at +0x2d has variable length from +0x2c
- Returns total bytes written in `*param_3`

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | int | Field 1 — 4 bytes |
| +0x08 | char[32] | Field 2 — 32 bytes |
| +0x28 | byte | Field 3 |
| +0x29 | byte | Field 4 |
| +0x2a | byte | Field 5 |
| +0x2b | byte | Field 6 |
| +0x2c | byte | Length for field 7 |
| +0x2d | byte[] | Field 7 — variable length |

**Calls:** FUN_0057a1b0 (serialize helper)

**Used by system:** docs/20-math-utilities.md — struct serialization utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057b6b0 — Offset Getter (param_1 + 0x20)

Source: unknown | Confidence: high
Returns `param_1 + 0x20`.

**Used by system:** docs/20-math-utilities.md — leaf offset getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585cc0 — Field Getter (+0x78)

Source: unknown | Confidence: high
Returns `*(int*)(param_1 + 0x78)`.

**Used by system:** docs/20-math-utilities.md — leaf getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587500 — Simple Setter (Zero at +0x8)

Source: unknown | Confidence: high
Sets `param_1 + 8 = 0`.

**Used by system:** docs/20-math-utilities.md — leaf zero-setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## __local_unwind2 — MSVCRT SEH Frame Unwinder

Source: unknown | Confidence: high
MSVC CRT library function: unwinds SEH exception handling frames.

**Key logic:**
- Walks the SEH unwind table for the current function
- For each entry between current and target try level: calls the unwind handler if present
- Part of MSVC C++ exception handling runtime

**Used by system:** docs/20-math-utilities.md — MSVC CRT SEH support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058afcf — TLS Offset Getter (+8)

Source: unknown | Confidence: high
Calls FUN_0058e0c7() (TLS buffer), returns pointer + 8.

**Calls:** FUN_0058e0c7 (TLS value retrieval with init)

**Used by system:** docs/20-math-utilities.md — TLS field access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00590616 — Count Alphabetical Chars

Source: unknown | Confidence: high
Counts consecutive alphabetical characters at start of string.

**Key logic:**
- Iterates string while char is 'A'-'Z' or 'a'-'z'
- Returns count

**Algorithm family:** string utility — alphabetical prefix count

**Used by system:** docs/20-math-utilities.md — string processing utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059567d — Float80-to-Float64 Unpack

Source: unknown | Confidence: high
Converts x87 extended precision (80-bit) float to IEEE 754 double (64-bit).

**Key logic:**
- Extracts sign, exponent (11 bits), mantissa (64 bits) from 80-bit source
- Handles denormals, normals, zero, NaN/Inf cases
- Normalizes mantissa with while loop
- Packs into 64-bit IEEE format with 11-bit exponent and 52-bit mantissa

**Algorithm family:** math utility — FPU format conversion

**Used by system:** docs/20-math-utilities.md — float format conversion

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059da3a — Call Wrapper

Source: unknown | Confidence: high
Delegates to FUN_004e7f39().

**Calls:** FUN_004e7f39

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

## FUN_00513cd3 — Safe Delete Guard for thunk_FUN_00517ec8

Source: unknown | Confidence: high
Safe-delete wrapper — checks both pointers non-null before calling free wrapper.

**Key logic:**
- Guards against double-free by verifying param_1 (object) and param_2 (child pointer) are both non-null
- Calls FUN_0058aa6f(param_2) — memory free wrapper
- If either pointer is null, returns without action

**Calls:**
- FUN_0058aa6f — free wrapper (memory management, per triage index)

**Used by system:** docs/20-math-utilities.md — memory management utility pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005685b0 — String Prefix Pattern Check (+~XX)

Source: unknown | Confidence: high
Checks if a string starts with "+~" followed by two alphanumeric characters.

**Key logic:**
- Computes string length via manual loop (strlen equivalent)
- Guard: if length <= 3, return 0 (too short for pattern)
- Checks first two chars are '+' and '~' (prefix)
- Validates chars at index 2 and 3 with `FUN_00589bc6()` (alphanumeric/isX digit check)
- Both must pass: return 1
- Any failure: return 0

**Algorithm family:** string pattern matching

**Calls:**
- FUN_00589bc6 — character classification (likely isdigit/isalpha), math_util

**Used by system:** docs/20-math-utilities.md — string parsing utility

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_005884ed — _rand() LCG Random Number Generator

Source: MSVC CRT | Confidence: high
CRT _rand(). LCG with multiplier 0x343FD, increment 0x269EC3.

**Key logic:**
- TLS seed via FUN_0058e0c7()
- `seed = seed * 0x343FD + 0x269EC3`
- Returns `(seed >> 16) & 0x7FFF`

**Algorithm family:** LCG PRNG

**Used by system:** docs/20-math-utilities.md — MSVC CRT

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a2a6 — CRT __amsg_exit (Error Exit)

Source: MSVC CRT | Confidence: high
Runtime error exit. Displays message, terminates with code 255.

**Key logic:**
- If `DAT_008d3ebc == 1`: FUN_005932ba() (error display)
- FUN_005932f3(param_1) — message handler
- `_exit(0xFF)`

**Globals:**
- `DAT_008d3ebc` — error display flag

**Used by system:** docs/20-math-utilities.md — CRT runtime error

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058C411 � MSVC CRT __freebuf

Source: MSVC CRT library | Confidence: high
Frees a file stream's internal buffer if the stream owns it and has allocated one.

**Key logic:**
- If _File->_flag & 0x83 (owned buffer) AND _File->_flag & 8 (has buffer):
  - FUN_0058aa6f(_File->_base) � free the buffer
  - Clear buffer flags: _flag &= ~0x0408
  - Reset _ptr, _base, _cnt

**Calls:** FUN_0058aa6f (buffer free)

**Moddability:** N/A (CRT function)

<!-- target: docs/08-file-formats.md -->

## FUN_00591e89 — Empty Stub (No-Op)

Source: unknown | Confidence: high
Bare return. Size 86 bytes (padding/alignment).

**Used by system:** docs/20-math-utilities.md — unused/padding

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00595310 — Array-of-3 Zero Check

Source: unknown | Confidence: high
Checks 3 consecutive ints for all-zero.

**Key logic:**
- Returns 1 if all zero, 0 otherwise

**Used by system:** docs/20-math-utilities.md — state check

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a4c9 — Self-Referential Pointer Ring Init

Source: unknown | Confidence: high
Creates ring of self-pointers for pool/queue structure.

**Key logic:**
- Forward pointers from nodes to sibling offsets, forming a ring

**Used by system:** docs/20-math-utilities.md — data structure init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ae07 — C++ Throw with Exception

Source: unknown | Confidence: high
Calls constructor then raises C++ exception via SEH.

**Key logic:**
- FUN_0059ae7d() (constructor), then __CxxThrowException_8
- Does not return

**Used by system:** docs/20-math-utilities.md — exception infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059bfc3 — __CxxThrowException_8

Source: MSVC CRT | Confidence: high
Raises C++ exception via SEH.

**Key logic:**
- Copies SEH params from DAT_005b9de0, calls RaiseException

**Used by system:** docs/20-math-utilities.md — CRT exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00404ef0 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00566650() (string copy with buffer realloc).

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00411680 — Short Array Init (537× {1,0})

Source: unknown | Confidence: high
Initializes 537 pairs of shorts to {1, 0}.

**Used by system:** docs/20-math-utilities.md — array init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00414490 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004184b0().

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0041f040 — Array Index Lookup

Source: unknown | Confidence: medium
Returns `*(param_1 + 0x14 + index*4)` where index from FUN_004c11d0().

**Used by system:** docs/20-math-utilities.md — array lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004218f0 — String Copy + Realloc

Source: unknown | Confidence: high
Calls FUN_00421890() then FUN_00566650().

**Used by system:** docs/20-math-utilities.md — string utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00423490 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004234c0().

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0045c7a0 — Float-to-Short via __ftol

Source: unknown | Confidence: high
Converts float result to short via __ftol().

**Used by system:** docs/20-math-utilities.md — type conversion

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00462a00 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_0057a560().

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00499e90 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00566650() (string copy with realloc).

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a490 — String Reverse Copy + Lookup

Source: unknown | Confidence: medium
Reverses string param_1 into local buffer, calls FUN_00589901(), then checks with FUN_0049a360(). On match: FUN_0049a2e0() — on miss: FUN_0049a3b0().

**Used by system:** docs/20-math-utilities.md — string processing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0049feb0 — Merge Sort (Linked List)

Source: unknown | Confidence: high
Recursive merge sort on singly-linked list. Divides by finding midpoint, sorts sub-lists, merges by float key at value+4.

**Algorithm family:** merge sort

**Used by system:** docs/20-math-utilities.md — sorting

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004a40f0 — Array Zero-Init (0x68 ints + 1)

Source: unknown | Confidence: high
Zeros param_1[0x68] first, then 0x68 more ints from start.

**Used by system:** docs/20-math-utilities.md — array init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b0170 — Empty Stub (vtable slot)

Source: unknown | Confidence: high
Empty function — body is bare return. Used as vtable placeholder or callback.

**Used by system:** docs/20-math-utilities.md — stub/callback

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004bd7a0 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004bdb90().

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004c7c30 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004bf630().

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004d7920 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00550800().

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004f6f00 — Struct Zero-Init (32 bytes)

Source: unknown | Confidence: high
Zeros 32 bytes starting at param_1.

**Used by system:** docs/20-math-utilities.md — init

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0051593f — 2D Array Block Copy (Word-Aligned)

Source: unknown | Confidence: high
Copies param_5 rows of param_6-byte data from (param_1+param_2*4) to (param_3+param_4*4). Word-aligned fast path + byte remainder.

**Used by system:** docs/20-math-utilities.md — data copy

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00517f35 — Byte Array to Int (endian-agnostic)

Source: unknown | Confidence: high
Packs 4 bytes to uint32 in memory order.

**Used by system:** docs/20-math-utilities.md — type punning

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051c6be — 2D Copy Delegation

Source: unknown | Confidence: high
Calls FUN_0051593f() with parameters from param_1+0x5c.

**Used by system:** docs/20-math-utilities.md — copy delegation

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_005295e0 — Packed Floating-Point Math (3DNow!)

Source: unknown | Confidence: medium
Packed floating-point operations: compare, MUL, ADD, reciprocal. Uses table-driven polynomial approximation. 3DNow! SIMD.

**Algorithm family:** SIMD math — 3DNow! floating-point

**Used by system:** docs/20-math-utilities.md — SIMD math

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00540240 — Return Zero

Source: unknown | Confidence: high
Returns 0. Single instruction.

**Used by system:** docs/20-math-utilities.md — stub

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_005648b0 — Linear Interpolation

Source: unknown | Confidence: high
Returns `*(param_1+8) * param_2 + *(param_1+0x14)`.

**Algorithm family:** linear interpolation

**Used by system:** docs/20-math-utilities.md — math utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a560 — Byte Extraction from Pointer

Source: unknown | Confidence: high
Returns byte at *param_1 + 0x5d combined with shifted high byte of *param_1.

**Used by system:** docs/20-math-utilities.md — field extraction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587510 — memcpy-like with Realloc

Source: unknown | Confidence: high
Copies data with realloc if buffer too small. Word-aligned fast path + byte remainder. Stores copied size.

**Used by system:** docs/20-math-utilities.md — data copy with realloc

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058890e — CRT __abnormal_termination

Source: MSVC CRT | Confidence: high
Checks if current exception handler is the C++ abnormal termination handler.

**Used by system:** docs/20-math-utilities.md — CRT exception support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058b050 — CRT _strrchr

Source: MSVC CRT | Confidence: high
CRT strrchr() — finds last occurrence of char in string.

**Used by system:** docs/20-math-utilities.md — CRT string function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059086e — CRT __fload (float load)

Source: MSVC CRT | Confidence: high
Loads float from 80-bit extended precision format. Checks for NaN/inf.

**Used by system:** docs/20-math-utilities.md — CRT float support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005957bd — Memory Allocator Init (0x1000)

Source: unknown | Confidence: high
Allocates 0x1000 bytes via _malloc(). Stores to param_1[2]. Sets up buffer pointers. On failure: uses internal buffer.

**Used by system:** docs/20-math-utilities.md — buffer allocation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059dab7 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_0044657d().

**Used by system:** docs/20-math-utilities.md — call delegation

**Moddability:** hardcoded

## FUN_0052d8b0 — DirectInput8Create Import Stub

Source: unknown | Confidence: high
DirectInput8Create import stub — transfers to the actual implementation in DINPUT8.DLL.

**Key logic:**
- Indirect jump via jumptable to DirectInput8Create exported from DINPUT8.DLL
- 6 bytes total: minimal trampoline
- Import address table (IAT) entry for the DirectInput8 COM API entry point

**Used by system:** Input system initialization (DInput)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00551760 — Linked List Traversal with Conditional Timer Update

Source: unknown | Confidence: medium
Traverses a linked list from param_1+0x13c, calling FUN_005514c0 (timer-based state update) on each node that has a non-zero value at +0x1c.

**Key logic:**
- Start: iVar1 = *(param_1 + 0x13c) — linked list head
- Loop: while iVar1 != 0, advance via *(iVar1 + 0x24) — next pointer
- Conditional call: if *(iVar1 + 0x1c) != 0, call FUN_005514c0(param_1)
- FUN_005514c0 is documented as "Timer-based state update with cap" (triage, GameLogic/Timer)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x13c | NextOrHead | int* | Pointer to linked list head |
| +0x24 | NextPtr | int* | Node-level next pointer |
| +0x1c | ActiveFlag | int | Non-zero → call timer update |

**Calls:**
- FUN_005514c0 — Timer-based state update with cap

**Used by system:** docs/01-engine-architecture.md — event/animation update tick

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00563230 — Array-of-Struct Stride Search by ID

Source: unknown | Confidence: high
Linear search through an array of 7-int (0x1c byte) stride structures for a matching ID. Returns index or -1.

**Key logic:**
- Get array count from param_1+0x6c
- Array base: *(param_1 + 8) + 4 — start at second int of each element
- Stride: 7 ints (28 bytes) per element
- Compare each element's ID field (second int, offset +4 within element) against param_2
- If match: return index
- If not found: return -1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x6c | ElementCount | int | Number of array elements |
| +0x08 | ArrayBase | int* | Pointer to array-of-struct |

**Calls:** none

**Used by system:** docs/01-engine-architecture.md — resource or configuration lookup by ID

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00569b70 — 3D Vector Subtract with Cross Product (Rigid Body)

Source: unknown | Confidence: medium
Subtracts a 3D vector from a target, then subtracts a cross product result from three consecutive vectors. Likely a rigid body angular velocity update.

**Key logic:**
- param_1 + 0x134 -= param_3[0] (X translation)
- param_1 + 0x13c -= param_3[1] (Y translation)
- param_1 + 0x144 -= param_3[2] (Z translation)
- param_1 + 0x14c -= (param_3[2]*param_2[1] - param_3[1]*param_2[2]) — cross product Z
- param_1 + 0x154 -= (param_2[2]*param_3[0] - param_3[2]*param_2[0]) — cross product Y
- param_1 + 0x15c -= (param_3[1]*param_2[0] - param_3[0]*param_2[1]) — cross product X
- This is: velocity -= cross(omega, something) — angular correction term

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x134 | VelocityX | double | Linear velocity / position X |
| +0x13c | VelocityY | double | Linear velocity / position Y |
| +0x144 | VelocityZ | double | Linear velocity / position Z |
| +0x14c | AngularCorrZ | double | Cross product correction Z |
| +0x154 | AngularCorrY | double | Cross product correction Y |
| +0x15c | AngularCorrX | double | Cross product correction X |

**Algorithm family:** 3D vector math / rigid body dynamics

**Used by system:** docs/18-physics-dynamics.md — rigid body angular velocity correction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005864e0 — Conditional List Node Cleanup

Source: unknown | Confidence: high
Conditionally cleans up a list node: if flag is set and object pointer is non-null, calls cleanup then frees the node.

**Key logic:**
- If param_1[2] (byte flag at +0x08) != 0 AND *param_1 (object ptr) != 0:
  - FUN_005867b0() — cleanup call
  - FUN_00587bcf(*param_1) — free the object

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ObjectPtr | int | Object to free |
| +0x08 | HasObject | byte | Non-zero → cleanup needed |

**Calls:**
- FUN_005867b0 — Node cleanup
- FUN_00587bcf — Free wrapper

**Used by system:** docs/01-engine-architecture.md — linked list node cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058a2cb — Error Handler with Optional Cleanup Then Exit

Source: unknown | Confidence: high
Error handler that optionally runs cleanup logic based on a global flag, then exits the process with code 0xFF.

**Key logic:**
- If DAT_008d3ebc == 1: call FUN_005932ba() — cleanup
- Call FUN_005932f3(param_1) — final error handler
- ExitProcess(0xFF) — terminate with error code 255

**Globals:**
- DAT_008d3ebc — Cleanup enable flag (if 1, run cleanup)

**Calls:**
- FUN_005932ba — Optional cleanup
- FUN_005932f3 — Error handling
- ExitProcess — Win32 process termination

**Used by system:** docs/01-engine-architecture.md — fatal error handling

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0058c6f0 — __allmul (64-bit Integer Multiply)

Source: crt/src/allmul.asm | Confidence: high
MSVC CRT intrinsic for signed/unsigned 64-bit multiplication on 32-bit x86. Multiplies two 64-bit values split into high/low 32-bit halves.

**Key logic:**
- Input: param_1 (low), param_2 (high), param_3 (low), param_4 (high)
- If param_4 == 0 && param_2 == 0: return (uint64)param_1 * (uint64)param_3 (simple case)
- Otherwise: compute cross terms:
  - result.low = param_1 * param_3
  - result.high = (param_1*param_3 >> 32) + param_2*param_3 + param_1*param_4
- Result as 64-bit CONCAT44(high, low)

**Calls:** none (leaf function)

**Used by system:** docs/20-math-utilities.md — MSVC CRT runtime helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058e1b0 — _strlen (Aligned Word-Scan Implementation)

Source: MSVC CRT (strlen.asm) | Confidence: high
Optimized strlen implementation using aligned 4-byte reads with magic number detection (0x7efefeff) for null-byte scanning.

**Key logic:**
- Align: byte-scan until pointer is 4-byte aligned, checking for null
- Aligned loop: read 4 bytes at a time
  - Magic check: ((word ^ 0xffffffff ^ (word + 0x7efefeff)) & 0x81010100) == 0 → no null byte
  - If null detected: check each byte position (0, 1, 2, 3) for zero
- Return (end_ptr - start_ptr)

**Calls:** none (leaf CRT function)

**Used by system:** docs/20-math-utilities.md — MSVC CRT string utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00403f70 — Array-of-Struct Indexed Field Copy

Source: unknown | Confidence: high
Reads two 3-float vectors from an array of 0x1c-byte stride structures at index param_2. Used for structured data lookup.

**Key logic:**
- Base: array at *(param_1 + 0x154), stride 0x1c per element
- At index param_2: copy fields [0..2] (12 bytes, 3 floats) to *param_3
- At index param_2 + offset 0xc: copy fields [0..2] (12 bytes, 3 floats) to *param_4
- Essentially reads two 3-component vectors from a packed struct array

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x154 | ArrayBase | int* | Array of 0x1c-byte strided elements |

**Calls:** none

**Algorithm family:** Array element accessor

**Used by system:** docs/20-math-utilities.md — structured data array lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404f00 — Byte Field Extractor with Shift

Source: unknown | Confidence: medium
Extracts a byte from a pointer-based struct at a computed offset. Tiny leaf accessor.

**Key logic:**
- Reads *param_1 as a base pointer
- Extracts byte at offset +0x14 from that pointer
- Returns it merged with bits from the original value via CONCAT31
- Purpose: read a specific byte from a dereferenced pointer chain

**Calls:** none

**Algorithm family:** Leaf accessor / field getter

**Used by system:** docs/20-math-utilities.md — pointer-chase field access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00405f80 — Scaled Dot Product with Clamp

Source: unknown | Confidence: medium
Computes a ratio of two 3-vector dot products, multiplies by a scaling factor, then clamps the result between two thresholds.

**Key logic:**
- Fetch pointer iVar1 = *(param_1 + 0x54)
- Compute numerator: (iVar1+0x80)*param_2[1] + (iVar1+0x7c)*param_2[0] + (iVar1+0x84)*param_2[2] + _DAT_0059e4e4
- Compute denominator: (param_1+0x34)*param_2[0] + (param_1+0x38)*param_2[1] + (param_1+0x3c)*param_2[2] + _DAT_0059e4e4
- fVar2 = (numerator / denominator) * *(param_1 + 0x48)
- Clamp: if fVar2 < _DAT_0059e4e0 (~0.125f) → set to 0.125f
- If fVar2 > _DAT_0059e4dc (~8.0f) → set to 8.0f
- Else store computed value

**Globals:**
- _DAT_0059e4e4 — Small epsilon/prevent-division-by-zero (~0.0f)
- _DAT_0059e4e0 — Lower clamp threshold (~0.125f, stored as 0x3e000000)
- _DAT_0059e4dc — Upper clamp threshold (~8.0f, stored as 0x41000000)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x34 | DotWeight1 | float | Weight for X |
| +0x38 | DotWeight2 | float | Weight for Y |
| +0x3c | DotWeight3 | float | Weight for Z |
| +0x48 | ScaleFactor | float | Scaled by result |
| +0x54 | DataPtr | int* | Pointer to data with vector at +0x7c/+0x80/+0x84 |

**Calls:** none

**Algorithm family:** Dot product ratio with clamp

**Used by system:** docs/18-physics-dynamics.md — physics simulation weighting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00407810 — Linked List Node Insert with Allocation

Source: unknown | Confidence: high
Allocates and inserts a node into a linked list after processing data through a sub-function. Returns object ID or 0.

**Key logic:**
- Guard: if *(param_1 + 0x88) == 0 or param_2 == 0 → return 0
- Allocate 0x6c bytes via operator_new
- If alloc succeeds: call FUN_004057f0(param_2, param_3, param_4, param_1) → get node data
- If data != 0:
  - Allocate 0xc byte node struct
  - Store data ptr at piVar3[0], set next=0, flags=0
  - If list empty (param_1[2] == 0): head=node, tail=node, current=node, count++
  - Else: insert after current, update current, count++
  - Return data pointer
- Return 0 on failure

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x88 | ListActive | int | Non-zero → list is operational |
| +0x08 | ListHead | int* | First node |
| +0x0c | ListCurrent | int* | Current node (insert position) |
| +0x10 | ListTail | int* | Last node |
| +0x14 | ListCount | int | Node count |

**Calls:**
- operator_new — Heap alloc
- FUN_004057f0 — Data processing for node

**Used by system:** docs/01-engine-architecture.md — linked list manager insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004082b0 — Float Clamp with Event Dispatch

Source: unknown | Confidence: medium
Applies clamped delta movement to a float value, dispatching events when crossing zero threshold. Includes global threshold reference.

**Key logic:**
- If *param_1 == DAT_0059e440 (zero threshold):
  - If byte at param_1+0x15 (event flag) non-zero: call FUN_004d8860(1), clear flag
- Else:
  - If DAT_008ad2a0 != -1: call FUN_004d8860(0), set event flag
  - Calls FUN_005404d0 twice with computed values — likely audio/event dispatch
- Movement: if param_1[1] (min) <= *param_1 (current) → lower clamp
  - If *param_1 < param_1[1]: apply delta *param_1 -= _DAT_008afe90 * param_1[2], clamp at min
- Else: apply delta *param_1 += _DAT_008afe90 * param_1[2], clamp at max

**Globals:**
- DAT_0059e440 — Zero threshold (~0.0f, physics clamp)
- DAT_008ad2a0 — Event dispatch enable flag
- _DAT_008afe90 — Delta multiplier (decay/approach rate)
- DAT_008b8dc8 — Audio/event context

**Calls:**
- FUN_004d8860 — Event dispatch (0=enter, 1=exit)
- FUN_005404d0 — Audio/event notification
- __ftol — CRT float-to-long conversion

**Algorithm family:** Clamped float interpolation with event dispatch

**Used by system:** docs/01-engine-architecture.md — parameter smoothing with event triggers

**Moddability:** hookable — threshold and rate controlled by global floats

<!-- target: docs/20-math-utilities.md -->

## FUN_0040b360 — Virtual Dispatch Chain

Source: unknown | Confidence: medium
Double virtual dispatch: calls a method on an object, then calls another method on the returned object.

**Key logic:**
- Call virtual method via (*param_1 + 0x18) — first vtable dispatch
- If result non-zero: call virtual method via (*param_1 + 0x18) again → get second object
- On second object: call virtual method via (*second + 0x1c) — third dispatch
- Chain: object → get_something() → get_child() → do_action()

**Calls:** none (all virtual dispatch)

**Algorithm family:** Virtual dispatch chain

**Used by system:** docs/01-engine-architecture.md — C++ vtable-based object traversal

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004116b0 — Wrapper returning 0

Source: unknown | Confidence: high
Thin wrapper that calls FUN_00411ab0 and returns 0.

**Key logic:**
- Calls FUN_00411ab0()
- Returns 0

**Calls:**
- FUN_00411ab0 — Implementation call

**Used by system:** docs/01-engine-architecture.md — call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004144a0 — Callback Unregistration

Source: unknown | Confidence: high
Unregisters a callback at address LAB_004144b0 from the cleanup handler list.

**Key logic:**
- FUN_00587b3e(&LAB_004144b0) — remove callback from cleanup list

**Calls:**
- FUN_00587b3e — Callback unregistration

**Used by system:** docs/01-engine-architecture.md — shutdown/cleanup registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004189f0 — Array Search Returning Index

Source: unknown | Confidence: medium
Linear search through an array of 8-int (0x20 byte) stride structures at param_1+0x864. Returns 1 if found, 0 if not.

**Key logic:**
- Array base: param_1 + 0x864, stride 8 ints
- 0x14 (20) iterations
- Compare each element's first int against param_2
- If match: call FUN_004144d0(), return 1
- Return 0 if not found

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x864 | ArrayBase | int[] | 20 elements, 0x20 byte stride |

**Calls:**
- FUN_004144d0 — Match handler

**Algorithm family:** Linear search

**Used by system:** docs/01-engine-architecture.md — resource/tag lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041f070 — Relative Performance Comparator

Source: unknown | Confidence: medium
Iterates all vehicles/objects, finds maximum of a specific field across others (excluding self), computes difference from own value, returns flagged result.

**Key logic:**
- If param_1 == 0: return modified EAX (edge case)
- Iterate all objects via FUN_004c2850/FUN_004c1370 iterator pattern
- For each object at index iVar2:
  - If not the same as param_1:
    - Track maximum of *(object + 0x198) in iVar3
- Compute: iVar3 = *(param_1 + 0x198) - iVar3 (own value - max of others)
- Return (iVar3 > 9) as byte, shifted into result

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x198 | PerformanceValue | int | Comparison metric |

**Calls:**
- FUN_004c2850 — Iterator enum start/advance
- FUN_004c1370 — Iterator count
- FUN_004c13a0 — Get object by index

**Used by system:** docs/01-engine-architecture.md — relative ranking/comparison

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421910 — Double Delegate Call

Source: unknown | Confidence: high
Calls two functions in sequence with a single parameter.

**Key logic:**
- FUN_00421890(param_1)
- FUN_00566650(param_1)

**Calls:**
- FUN_00421890 — First handler
- FUN_00566650 — Second handler

**Used by system:** docs/01-engine-architecture.md — event chain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004234a0 — Callback Unregistration

Source: unknown | Confidence: high
Unregisters a callback at address LAB_004234b0 from the cleanup handler list.

**Key logic:**
- FUN_00587b3e(&LAB_004234b0) — remove callback

**Calls:**
- FUN_00587b3e — Callback unregistration

**Used by system:** docs/01-engine-architecture.md — shutdown/cleanup registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00452740 — Swap and Reinit

Source: unknown | Confidence: medium
Swaps two values through an object, then triggers reinitialization.

**Key logic:**
- FUN_0044f050(*param_1, 0) — release current value
- param_1[1] = param_3 — store new secondary
- *param_1 = param_2 — store new primary
- FUN_0044f050() — reinitialize

**Calls:**
- FUN_0044f050 — Object data release/reinit

**Used by system:** docs/01-engine-architecture.md — resource swap

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00456110 — 3-Vector Copy to Struct

Source: unknown | Confidence: high
Copies three consecutive float/uint values from an array into struct fields at +0x0c, +0x10, +0x14.

**Key logic:**
- If param_2 != null:
  - *(param_1+0x0c) = param_2[0]
  - *(param_1+0x10) = param_2[1]
  - *(param_1+0x14) = param_2[2]

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | VectorX | float/int | Component 0 |
| +0x10 | VectorY | float/int | Component 1 |
| +0x14 | VectorZ | float/int | Component 2 |

**Calls:** none

**Algorithm family:** 3-component vector copy

**Used by system:** docs/01-engine-architecture.md — vector/position assignment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00459990 — 6-Field Bulk Setter

Source: unknown | Confidence: high
Bulk assign 6 values to consecutive fields starting at offset +0x28.

**Key logic:**
- param_1[0x28] = param_2 through param_1[0x3c] = param_7
- Sequential field assignment, 6 values

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x28 | Field1 | int | Assigned param_2 |
| +0x2c | Field2 | int | Assigned param_3 |
| +0x30 | Field3 | int | Assigned param_4 |
| +0x34 | Field4 | int | Assigned param_5 |
| +0x38 | Field5 | int | Assigned param_6 |
| +0x3c | Field6 | int | Assigned param_7 |

**Calls:** none

**Used by system:** docs/01-engine-architecture.md — struct configuration/setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bbe0 — Double Delegate Call

Source: unknown | Confidence: high
Calls two init functions in sequence.

**Key logic:**
- FUN_0045b950()
- FUN_0045b9a0()

**Calls:**
- FUN_0045b950 — First init
- FUN_0045b9a0 — Second init

**Used by system:** docs/01-engine-architecture.md — two-phase init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045c850 — Per-Element Array Reset

Source: unknown | Confidence: medium
Resets multiple fields of an indexed element in several parallel arrays. Clears int/byte fields and writes a sentinel value.

**Key logic:**
- Clear *(param_1 + 0x14 + param_2*4) = 0
- Clear *(param_1 + 0x1b4 + param_2*4) = 0
- Clear byte at param_1 + 0x354 + param_2 = 0
- Clear byte at param_1 + 0x3bc + param_2 = 0
- Zero 8 dwords at param_1 + 0x424 + param_2*0x20 (8 * 4 = 32 bytes)
- Clear short at param_1 + 0x12c4 + param_2*2 = 0
- Set float at param_1 + 0x1124 + param_2*4 = 0xbf800000 (-1.0f)
- Total struct per element: ~0x10e4 bytes stride

**Struct offsets (param_1 — per element):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x14 + i*4 | Field1 | int | Cleared |
| +0x1b4 + i*4 | Field2 | int | Cleared |
| +0x354 + i | FlagByte1 | byte | Cleared |
| +0x3bc + i | FlagByte2 | byte | Cleared |
| +0x424 + i*0x20 | DataBlock | byte[32] | Zeroed (8 dwords) |
| +0x12c4 + i*2 | ShortField | short | Cleared |
| +0x1124 + i*4 | InitFloat | float | Set to -1.0f |

**Calls:** none

**Used by system:** docs/01-engine-architecture.md — per-element state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00460710 — Conditional Render State Update

Source: unknown | Confidence: medium
Updates render state if a specific flag is not set to 1.

**Key logic:**
- If *(param_1 + 0x3fc4) != 1:
  - FUN_00461470() — begin state capture
  - FUN_004623e0() — write state to buffer
  - FUN_004614f0(4, 1) — set render state
  - FUN_004623b0() — restore from buffer
  - FUN_004b0170() — finalize/apply

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x3fc4 | StateFlag | int | 1 = skip update, other = run |

**Calls:**
- FUN_00461470 — Begin state capture
- FUN_004623e0 — Write state
- FUN_004614f0 — Set render state
- FUN_004623b0 — Restore state
- FUN_004b0170 — Apply

**Used by system:** docs/19-renderer.md — render state management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00464720 — Byte Clamp

Source: unknown | Confidence: high
Clamps a byte value between min and max bounds. In-place modification.

**Key logic:**
- If *param_1 < param_2 (min): *param_1 = param_2
- Else if param_3 (max) < *param_1: *param_1 = param_3
- Otherwise unchanged

**Calls:** none

**Algorithm family:** Clamp

**Used by system:** docs/20-math-utilities.md — byte range clamping utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464f90 — Threshold-to-Rank Classifier

Source: unknown | Confidence: high
Maps an integer to a ranked category (0-4) based on threshold comparisons.

**Key logic:**
- param_1 < 0x5d0 (1488): return 0
- param_1 < 0xba0 (2976): return 1
- param_1 < 0x1c21 (7201): return 2
- param_1 <= 0x7080 (28800): return 3
- param_1 > 0x7080: return 4

**Calls:** none

**Algorithm family:** Threshold-based classification

**Used by system:** docs/20-math-utilities.md — integer range classifier

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466300 — State Initializer with Flag Check

Source: unknown | Confidence: medium
Initializes multiple subsystems and conditionally calls a function based on a flag.

**Key logic:**
- Set *(param_1 + 0x124) = 0xbf800000 (-1.0f) — sentinel
- Call FUN_0048e8d0() — sub-init A
- Call FUN_004988a0(2) — sub-init B with mode 2
- Call FUN_00466350() — sub-init C
- Call FUN_00466650() — sub-init D
- If *(param_1 + 0xec) != 0: call FUN_00541ca0(1) — conditional call

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x124 | InitSentinel | float | Set to -1.0f |
| +0xec | FlagCondition | int | Non-zero triggers extra call |

**Calls:**
- FUN_0048e8d0 — Sub-init
- FUN_004988a0 — Sub-init with mode
- FUN_00466350 — Sub-init
- FUN_00466650 — Sub-init
- FUN_00541ca0 — Conditional init

**Used by system:** docs/01-engine-architecture.md — multi-phase initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a220 — Object Constructor with VTable

Source: unknown | Confidence: medium
Object constructor that initializes fields and sets vtable.

**Key logic:**
- FUN_0048c9f0() — base constructor
- param_1[0xd2] (offset +0x348) = 0
- param_1[0xd3] (offset +0x34c) = -1
- param_1[0xd1] (offset +0x344) = 0
- *param_1 = &PTR_LAB_0059f878 — set vtable

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | VTablePtr | int* | Virtual method table |
| +0x344 | Field_d1 | int | Cleared |
| +0x348 | Field_d2 | int | Cleared |
| +0x34c | Field_d3 | int | Set to -1 |

**Calls:**
- FUN_0048c9f0 — Base constructor

**Used by system:** docs/01-engine-architecture.md — C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046cb00 — Global Sign Check

Source: unknown | Confidence: high
Returns a byte indicating if a global is negative, merged with upper bits.

**Key logic:**
- Returns CONCAT31((DAT_007cd2b8 >> 8), DAT_007cd2b8 < 0)
- Extracts sign bit (bit 31) from DAT_007cd2b8 and upper byte

**Globals:**
- DAT_007cd2b8 — Signed value for sign check

**Calls:** none

**Algorithm family:** Sign extraction

**Used by system:** docs/20-math-utilities.md — global sign query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046efe0 — Conditional Update on Changed State

Source: unknown | Confidence: medium
Compares a stored value against a current value, updates if different.

**Key logic:**
- iVar1 = FUN_00432a60() — get current value
- If *(param_1 + 0x174) != iVar1 (stored differs from current):
  - FUN_0046f170() — update action
  - *(param_1 + 0x174) = iVar1 — store new value
- Return 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x174 | CachedValue | int | Previously stored value |

**Calls:**
- FUN_00432a60 — Current state query
- FUN_0046f170 — Update handler

**Used by system:** docs/01-engine-architecture.md — state change watcher

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00470cc0 — Object Constructor with Global References

Source: unknown | Confidence: medium
Constructs an object with vtable, global references, and initializes many fields to default values.

**Key logic:**
- FUN_00466d60(1) — base init with mode
- *param_1 = &PTR_FUN_005a0840 — vtable
- param_1[199] (offset +0x31c) = &DAT_007cf014 — global ref
- param_1[0xc9] (offset +0x324) = 1
- param_1[0xca] (offset +0x328) = 0
- param_1[0xcb] (offset +0x32c) = 1
- param_1[0xcc] (offset +0x330) = 1
- param_1[0xcd] (offset +0x334) = 0x198 (408)
- FUN_00486f30(&PTR_DAT_005be704, -1) — register resource
- FUN_00486f30(&DAT_005c32c8, -1) — register resource

**Globals:**
- DAT_007cf014 — External reference stored
- PTR_DAT_005be704 — Registered resource
- DAT_005c32c8 — Registered resource

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | VTablePtr | int* | Virtual method table |
| +0x31c | GlobalRef | int* | Reference to DAT_007cf014 |
| +0x324 | Field_c9 | int | Set to 1 |
| +0x328 | Field_ca | int | Set to 0 |
| +0x32c | Field_cb | int | Set to 1 |
| +0x330 | Field_cc | int | Set to 1 |
| +0x334 | Field_cd | int | Set to 0x198 |

**Calls:**
- FUN_00466d60 — Base init
- FUN_00486f30 — Resource registration

**Used by system:** docs/01-engine-architecture.md — C++ object construction with resource registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00472a80 � Object Constructor with Global Ref (VTable at 0x005a2280)

Source: unknown | Confidence: medium
Constructor setting vtable, global reference, and registering resources. Similar pattern to FUN_00470cc0.

**Key logic:**
- FUN_00466d60(1) � base init
- *param_1 = &PTR_FUN_005a2280 � vtable
- param_1[199] = &DAT_007d1334 � global ref
- param_1[0xc9] = 1, [0xca]=0, [0xcb]=1, [0xcc]=1
- param_1[0xce] = 0x107 (263)
- FUN_00486f30(&PTR_DAT_005be704, -1) � register
- FUN_00486f30(&DAT_005c32c8, -1) � register
- FUN_004670e0() � final init

**Calls:** FUN_00466d60, FUN_00486f30 (x2), FUN_004670e0

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00474440 � Object Constructor with VTable (0x005a3a80)

Source: unknown | Confidence: medium
Constructor with field initialization and resource registration.

**Key logic:**
- FUN_0048c070(1) � base init
- *param_1 = &PTR_FUN_005a3a80 � vtable
- param_1[199] = 0x18b (395)
- FUN_00486f30(&PTR_DAT_005be704, -1) � register
- FUN_00486f30(&PTR_DAT_005c32a4, -1) � register
- FUN_00486f30(&DAT_005c32a8, -1) � register
- FUN_00474510() � final init

**Calls:** FUN_0048c070, FUN_00486f30 (x3), FUN_00474510

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004760d0 � Object Constructor with VTable (0x005a4464)

Source: unknown | Confidence: medium
Constructor clearing fields and setting a sentinel value.

**Key logic:**
- FUN_0048fc50() � base init
- Clear fields: param_1[0xf] through [0x15] = 0 or -1
- param_1[0x15] = -1
- param_1[0x13] = 0
- *param_1 = &PTR_LAB_005a4464 � vtable

**Calls:** FUN_0048fc50

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478110 � Object Constructor with VTable (0x005a4760)

Source: unknown | Confidence: medium
Constructor setting two fields and vtable.

**Key logic:**
- FUN_0048fb70() � base init
- param_1[0x3a] = 0
- param_1[0x3b] = -1
- *param_1 = &PTR_FUN_005a4760 � vtable

**Calls:** FUN_0048fb70

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479700 � Object Constructor with VTable (0x005a4d00)

Source: unknown | Confidence: medium
Constructor with init params 0 and 1.0f.

**Key logic:**
- FUN_004795e0(0, 0x3f800000) � init with (0, 1.0f)
- *param_1 = &PTR_FUN_005a4d00 � vtable

**Calls:** FUN_004795e0

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479c30 � Object Constructor with VTable (0x005a5b60)

Source: unknown | Confidence: medium
Constructor with float parameters and flag set.

**Key logic:**
- FUN_0048d3a0(0x428c0000, 0x42f00000) � init with (70.0f, 120.0f)
- *param_1 = &PTR_FUN_005a5b60 � vtable
- Byte at param_1+0x3c (index 0xf) = 1

**Calls:** FUN_0048d3a0

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a5e0 � Object Constructor with VTable (0x005a6400)

Source: unknown | Confidence: medium
Constructor with float params (0.1f, 1.0f).

**Key logic:**
- FUN_004668e0(0x3dcccccd, 0x3f800000) � init with (0.1f, 1.0f)
- *param_1 = &PTR_FUN_005a6400 � vtable

**Calls:** FUN_004668e0

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047c6c0 � Double Delegate Call

Source: unknown | Confidence: medium
Calls two functions in sequence, returns 0.

**Key logic:**
- FUN_00489cb0()
- FUN_0048a3b0(0)
- Return 0

**Calls:** FUN_00489cb0, FUN_0048a3b0

**Used by system:** docs/01-engine-architecture.md � initialization sequence

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047fb10 � Destructor with List Cleanup and Conditional Free

Source: unknown | Confidence: medium
Destructor that tears down a linked list, calls cleanup functions, and optionally frees the object.

**Key logic:**
- *param_1 = &PTR_FUN_005a7168 � set vtable
- FUN_004c5de0() � cleanup
- *param_1 = &PTR_LAB_005a4550 � alternative vtable
- Traverse linked list at param_1[0x3c] (offset +0xf0):
  - For each node: call virtual release if flag set, then free node
- Null list pointers (param_1[0x3c..0x3f])
- FUN_00485eb0() � final cleanup
- If param_2 & 1: free param_1

**Calls:** FUN_004c5de0, FUN_00587bcf (per node), FUN_00485eb0

**Used by system:** docs/01-engine-architecture.md � C++ destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485a90 � Destructor with Two-Pointer Free

Source: unknown | Confidence: high
Frees two pointers if non-null, calls base cleanup, then optionally frees self.

**Key logic:**
- If *(param_1 + 0x184) non-null: free it
- If *(param_1 + 0x17c) non-null: free it
- FUN_00468610() � base cleanup
- If param_2 & 1: free param_1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x17c | AllocA | int | First allocation to free |
| +0x184 | AllocB | int | Second allocation to free |

**Calls:** FUN_00587bcf (x2-3), FUN_00468610

**Used by system:** docs/01-engine-architecture.md � C++ destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486600 � Linked List Traversal with Call

Source: unknown | Confidence: medium
Traverses a linked list at param_1+0xcc, calling a function on each node.

**Key logic:**
- iVar1 = *(param_1 + 0xcc) � list head
- While iVar1 != 0:
  - FUN_0049a5d0(param_1)
  - iVar1 = *(iVar1 + 0x18) � next pointer

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xcc | ListHead | int* | Linked list head |
| +0x18 (node) | NextPtr | int* | Node-level next |

**Calls:** FUN_0049a5d0

**Used by system:** docs/01-engine-architecture.md � list traversal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004875f0 � Mode-Dispatched Virtual Call

Source: unknown | Confidence: medium
Calls a virtual method with parameter based on a mode value (2 or 3).

**Key logic:**
- iVar1 = FUN_00486720() � get mode
- If mode == 2: virtual call (*param_1 + 0x40)(0)
- If mode == 3: virtual call (*param_1 + 0x40)(1), clear param_1[0x37]
- Else: clear param_1[0x37]

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xdc | ModeResult | int | Cleared after action |

**Calls:** FUN_00486720, virtual at (*+0x40)

**Used by system:** docs/01-engine-architecture.md � mode-dispatched behavior

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004881f0 � Surface Render Region Setup

Source: unknown | Confidence: medium
Computes render region coordinates from a source surface or param_1 fields. Handles both allocated and inline source.

**Key logic:**
- Virtual call at (*param_1 + 0xa8) � get render source
- If source is null: use param_1[1..4] fields as rect
  - Compute width = param_1[4] - param_1[3], height = param_1[2] - param_1[1]
  - If both > 0: call FUN_00495150 (alloc surface), FUN_00494bf0 (fill)
  - Output rect via param_2..param_5
- If source exists: compute from source dims
  - Width = source[1] - source[0], height = source[3] - source[2]
  - If valid and source[8]+0xc non-null: call FUN_00495150, FUN_00494a30 (blit), FUN_0049aa70
  - Output rect via param_2..param_5
- Virtual call at (*param_1 + 0x2c)(0) � post-render

**Calls:** multiple virtual, FUN_00495150, FUN_00494bf0, FUN_00494a30, FUN_0049aa70

**Used by system:** docs/19-renderer.md � render surface region setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004895b0 � Accumulator with Cap

Source: unknown | Confidence: medium
Accumulates two values with an upper cap, then calls update functions.

**Key logic:**
- Virtual call (*param_1 + 0x2c)(1) � pre-update
- iVar1 = param_1[0x53] + param_1[0x59] � accumulate
- param_1[0x53] = iVar1
- If param_1[0x58] < iVar1: param_1[0x53] = param_1[0x58] � cap
- FUN_00489d00() � update
- FUN_00489e90() � update

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x14c | Accumulator | int | Running total |
| +0x160 | CapValue | int | Upper limit |
| +0x164 | Addend | int | Value added each frame |

**Calls:** virtual at (*+0x2c), FUN_00489d00, FUN_00489e90

**Used by system:** docs/01-engine-architecture.md � accumulator with cap

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048c070 � Constructor with Parameter Storage

Source: unknown | Confidence: medium
Constructor that stores a parameter and initializes multiple fields.

**Key logic:**
- FUN_0048b420(0,0,0,0,0,0) � base init
- param_1[0xc2] = param_2 � store parameter
- Byte at param_1+0xc1 = 1
- Byte at param_1+0x305 = 1
- param_1[0xc5] = 1
- *param_1 = &PTR_FUN_005abf88 � vtable
- param_1[0xc6] = 0
- param_1[0xc3] = 0
- param_1[0xc4] = 0

**Calls:** FUN_0048b420

**Used by system:** docs/01-engine-architecture.md � C++ object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d3f0 � Destructor with VTable and Conditional Free

Source: unknown | Confidence: high
Set vtable, call cleanup, and optionally free object.

**Key logic:**
- *param_1 = &PTR_FUN_005ac1d0 � set vtable
- FUN_00485eb0() � base cleanup
- If param_2 & 1: FUN_00587bcf(param_1) � free

**Calls:** FUN_00485eb0, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md � C++ destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048ea20 � Two-Field Setter

Source: unknown | Confidence: high
Sets two consecutive fields at +0x14 and +0x18.

**Key logic:**
- *(param_1 + 0x14) = param_2
- *(param_1 + 0x18) = param_3

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x14 | Field14 | int | param_2 |
| +0x18 | Field18 | int | param_3 |

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � field assignment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fe30 � Virtual Dispatch on Sub-Object

Source: unknown | Confidence: medium
Calls two virtual methods on a sub-object (at param_1+0x30) if it exists.

**Key logic:**
- Get sub-object: *(param_1 + 0x30)
- If non-null: call virtual at (*sub + 0x3c)(param_2), then (*sub + 0x38)()
- Two virtual calls: first with param, second without

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x30 | SubObject | int* | Target object for virtual dispatch |

**Calls:** none (virtual dispatch)

**Used by system:** docs/01-engine-architecture.md � delegated processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490b00 � Array-of-Struct Allocator with Zero-Init

Source: unknown | Confidence: high
Allocates an array of 4-int (0x10 byte) stride structures, zero-initialized.

**Key logic:**
- Clear param_1[3..0xe] (12 ints from +0xc to +0x38)
- FUN_004912f0() � pre-init
- *param_1 = param_2 � store element size/element count
- param_1[1] = 0
- Allocate: operator_new(param_2 * 0x10 + 4) � 4-int stride + header
- If alloc fails: param_1[2] = 0; return
- Store element count in header array[0] = param_2
- Zero-fill each element (4 ints per element)
- param_1[2] = pointer to first element (array + 1)

**Calls:** operator_new, FUN_004912f0

**Used by system:** docs/01-engine-architecture.md � array allocator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004919c0 � Linked List Node Insert with Data Processing

Source: unknown | Confidence: high
Processes data into a node, allocates a 3-int node struct, inserts into linked list.

**Key logic:**
- iVar2 = FUN_00490940(param_4, param_5) � process data
- If iVar2 != 0:
  - Allocate 3-int node (12 bytes)
  - Store data: piVar4[0]=iVar2, piVar4[1]=0, piVar4[2]=0
  - If list empty (param_1[0xc]==0): head=node, tail=node, current=node, count++
  - Else: insert after current, update current, count++
  - Return 1
- Return 0

**Calls:** FUN_00490940, operator_new

**Used by system:** docs/01-engine-architecture.md � linked list insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00494690 � Render Surface Allocation and Text Initialization

Source: unknown | Confidence: medium
Allocates multiple render surfaces and initializes text color objects with RGB values.

**Key logic:**
- Allocate 3 surfaces via operator_new + FUN_0054fe10 (allocator)
- For each: call FUN_0054fec0 for surface config (w/h = 0x100/0x400/0x200)
- Store width from allocated +0x54 to globals
- Create text objects via FUN_00553980 with mode 2
- For first two surfaces: if creation ok (returns 0):
  - Read floats from DAT_005d6d60/0x64 (color components)
  - Create 4 text color entries via FUN_00553650 with RGBA values (0,255,0x3f160000,0x3f480000)

**Globals:**
- DAT_007cde04, DAT_007cde08, DAT_007cde0c � surface 1 refs
- DAT_007cde10, DAT_007cde14, DAT_007cde18 � surface 2 refs
- DAT_007cde1c, DAT_007cde20, DAT_007cde24 � surface 3 refs
- DAT_005cc9d8, DAT_005cc9d0, DAT_005cc9c8 � surface config data
- DAT_005d6d60, DAT_005d6d64 � color component floats

**Calls:** operator_new, FUN_0054fe10, FUN_0054fec0, FUN_00553980, FUN_00553650

**Used by system:** docs/19-renderer.md � text rendering initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495300 � Full Object Destructor with Multi-List Cleanup

Source: unknown | Confidence: medium
Complex destructor that tears down multiple linked lists and frees allocations.

**Key logic:**
- *param_1 = &PTR_FUN_005ac998 � set vtable for destructor
- FUN_00499580() x3 � cleanup calls
- Traverse and free linked list at param_1[0x62b]
- Null list pointers at param_1[0x62b..0x62e]
- FUN_0049a190(), FUN_004b0170(), FUN_0049a2f0() � cleanup
- Free 4 allocations at param_1+0x58b (stride -3)
- Free param_1[0x556] if non-null
- Traverse and free list at param_1[0x3c]
- Free param_1[0xf] if non-null
- Traverse and free list at param_1[1] with virtual release calls
- Null all list pointers

**Calls:** FUN_00499580, FUN_0049a190, FUN_004b0170, FUN_0049a2f0, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md � complex object destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00496e20 � Float Threshold Comparison

Source: unknown | Confidence: high
Returns 1 if float at param_1+0xdc exceeds global zero threshold, else 0.

**Key logic:**
- If *(param_1 + 0xdc) > DAT_0059e440 (zero threshold): return 1
- Return 0

**Globals:**
- DAT_0059e440 � Zero threshold (~0.0f)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xdc | Value | float | Compared to threshold |

**Calls:** none

**Used by system:** docs/20-math-utilities.md � threshold check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497e80 � ID-Based Linked List Search

Source: unknown | Confidence: high
Searches a linked list for a matching ID, returns associated value at +0x50 on match.

**Key logic:**
- If param_2 != 0:
  - Traverse list at param_1 + 0x10c (next pointer at +0x54)
  - Call FUN_00588410(node, param_2) � ID comparison
  - If match (returns 0): return *(node + 0x50)
- Return 0 (not found)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10c | ListHead | int* | Start of linked list |

**Node offsets:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x50 | ReturnValue | int | Value returned on match |
| +0x54 | NextPtr | int* | Next node |

**Calls:** FUN_00588410 � ID comparison

**Used by system:** docs/01-engine-architecture.md � ID-based list lookup

**Moddability:** hardcoded
<!-- target: docs/20-math-utilities.md -->

## FUN_00498e40 � Leaf Field Accessor at +0x50

Source: unknown | Confidence: high
Reads and returns the value at param_1 + 0x50.

**Key logic:**
- Returns *(param_1 + 0x50)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x50 | Field | int/uint | Accessed value |

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � struct field accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499540 � Linked List Virtual Call Traversal

Source: unknown | Confidence: medium
Traverses a linked list calling a virtual method on each node.

**Key logic:**
- piVar1 = *(param_1 + 0x44) � list head
- While piVar1 != null:
  - Call virtual at (*piVar1 + 0x70)()
  - piVar1 = FUN_00486320() � advance

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x44 | ListHead | int* | Linked list head |

**Calls:** virtual at (*+0x70), FUN_00486320

**Used by system:** docs/01-engine-architecture.md � list virtual dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499b10 � State Struct Zero-Init with Global Assign

Source: unknown | Confidence: high
Zero-initializes 13 int fields and assigns a global constant.

**Key logic:**
- Zero: param_1[0..3], param_1[4..12] (13 fields)
- param_1[6] = DAT_005acaa8

**Globals:**
- DAT_005acaa8 � Constant

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � state init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499ea0 � Single Delegate (thunk to FUN_00566650)

Source: unknown | Confidence: high
Thin wrapper.

**Key logic:**
- FUN_00566650()

**Calls:** FUN_00566650

**Used by system:** docs/01-engine-architecture.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a520 � ID-Based List Traversal with Comparison

Source: unknown | Confidence: medium
Looks up item by ID using key function, traverses list, returns 1 on match.

**Key logic:**
- FUN_00589901(param_2) � prepare lookup
- iVar1 = FUN_0049a330(param_2) � find bucket
- If index == -1: return -1
- Traverse list:
  - FUN_0049a2b0() � get comparand
  - FUN_00588410(param_2, comparand) � compare
  - If match (returns 0): return 1
  - Advance via +0x18 next
- Return 0

**Calls:** FUN_00589901, FUN_0049a330, FUN_0049a2b0, FUN_00588410

**Used by system:** docs/01-engine-architecture.md � hash bucket lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049b020 � Callback Unregistration

Source: unknown | Confidence: high
Unregisters callback at LAB_0049b030.

**Key logic:**
- FUN_00587b3e(&LAB_0049b030)

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md � cleanup callback

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049e8f0 � State Struct Zero-Init (17 ints)

Source: unknown | Confidence: high
Zeroes 17 consecutive int fields.

**Key logic:**
- param_1[0] through [0x12] = 0

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � state init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ffc0 � Single Delegate (thunk to FUN_004b3db0)

Source: unknown | Confidence: high
Thin wrapper.

**Key logic:**
- FUN_004b3db0()

**Calls:** FUN_004b3db0

**Used by system:** docs/01-engine-architecture.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004a2840 � Piecewise Linear Interpolation with Threshold

Source: unknown | Confidence: medium
Looks up value in sorted array, interpolates between entries, dispatches to listeners.

**Key logic:**
- Guard: param_1+0x6c == 0 ? return
- Iterate 7-float stride array
- If param_2 <= entry[0]: set current = entry[0], call listeners with entry[3]
- If param_2 >= entry[1]: set current = entry[1], call listeners with entry[4]
- If in between: linear interpolation with formula
- Dispatch to registered listeners via FUN_00551210

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x44 | CurrentValue | float | Stored value |
| +0x6c | ArrayPtr | int* | Lookup array |
| +0x70 | ArrayCount | int | Entries |
| +0x68 | ListenerCount | int | Count |
| +0x6c | ListenerArray | int* | Callbacks |

**Calls:** FUN_00551210

**Algorithm family:** Piecewise linear interpolation

**Used by system:** docs/01-engine-architecture.md � configurable interpolation

**Moddability:** configurable � lookup table driven

<!-- target: docs/20-math-utilities.md -->

## FUN_004a46f0 � Indexed Field Setter with Flag

Source: unknown | Confidence: medium
Sets or clears field indexed by value at param_2+4.

**Key logic:**
- If param_3 != 0: param_1[*(param_2+4)] = param_2
- Else: param_1[*(param_2+4)] = 0

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � indexed management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b01b0 � String Copy with Suffix Append

Source: unknown | Confidence: high
Concatenates two strings, copies with dword alignment, appends global suffix.

**Key logic:**
- Guard: null check
- FUN_004b0180(param_1, param_2) � pre-process
- Compute string lengths
- Dword-aligned copy of param_1 to param_2 end
- Append DAT_005cc1f4 and DAT_005cc1f8 as suffix

**Globals:**
- DAT_005cc1f4 � Suffix dword
- DAT_005cc1f8 � Suffix byte

**Calls:** FUN_004b0180

**Used by system:** docs/08-file-formats.md � path concatenation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1c20 � Field Initialize and Propagate

Source: unknown | Confidence: medium
Sets four byte fields, optionally propagates first value.

**Key logic:**
- FUN_00566650(param_2) � base init
- Set param_1+0x15 = param_3, +0x16 = param_4, +0x17 = param_5
- If param_7 != 0: param_1+0x14 = param_3

**Calls:** FUN_00566650 (x2)

**Used by system:** docs/01-engine-architecture.md � state init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b28f0 � Scaled Byte/Short Read

Source: unknown | Confidence: high
Reads indexed byte and short, returns as scaled floats.

**Key logic:**
- *p3 = (float)*(char)(p2 + 0x12 + p1) * _DAT_005ac988
- *p4 = (float)*(short)(p1 + 0x16 + p2*2) * _DAT_0059e444

**Globals:** _DAT_005ac988, _DAT_0059e444

**Calls:** none

**Used by system:** docs/20-math-utilities.md � scaled access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2c50 � Bitfield Extract and Scale

Source: unknown | Confidence: high
Extracts 6-bit field from packed uint, scales to float.

**Key logic:**
- Read uint at p1+0xf, >>2 & 0x3f, * _DAT_005acce4

**Calls:** none

**Algorithm family:** Bitfield extraction

**Used by system:** docs/20-math-utilities.md � packed data

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b44a0 � File Operation Open + Write

Source: unknown | Confidence: high
Opens file handle, writes 4+2 bytes.

**Key logic:**
- FUN_00566e20() � open handle
- Store handle at param_1+4
- FUN_00566c00(param_1, 4) � write
- FUN_00566c00(param_1+8, 2) � write

**Calls:** FUN_00566e20, FUN_00566c00 (x2)

**Used by system:** docs/08-file-formats.md � file write

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b5e30 � Sum Array (104 ints)

Source: unknown | Confidence: high
Sums 0x68 (104) ints starting at param_1+0x4c.

**Key logic:**
- Loop 0x68 times: accumulate
- Return sum

**Calls:** none

**Algorithm family:** Summation

**Used by system:** docs/20-math-utilities.md � accumulator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9d80 � Single Delegate (thunk to FUN_004b8140)

Source: unknown | Confidence: high
Thin wrapper.

**Key logic:**
- FUN_004b8140()

**Calls:** FUN_004b8140

**Used by system:** docs/01-engine-architecture.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba980 � Conditional Sized Array Alloc

Source: unknown | Confidence: medium
Allocates array of 0x374-byte stride elements based on flag.

**Key logic:**
- Compute size: (param_2 != 0) - 1 & 2 ? 0 or 2
- Alloc: uVar1 * 0x374 + 4
- Init each element via FUN_004ff670
- Return pointer after header

**Calls:** operator_new, FUN_004ff670

**Used by system:** docs/01-engine-architecture.md � dynamic array

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb490 � Linked List Insert (Head)

Source: unknown | Confidence: high
Inserts node at head of linked list.

**Key logic:**
- Alloc 3-int node
- If list empty: head=tail=current=node
- Else: node->next = old head, head = node
- Increment count

**Calls:** operator_new

**Used by system:** docs/01-engine-architecture.md � list head-insert

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bd7b0 � Callback Unregistration

Source: unknown | Confidence: high
Unregisters callback at LAB_004bd7c0.

**Key logic:**
- FUN_00587b3e(&LAB_004bd7c0)

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md � cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bf730 � Linked List Destructor with Conditional Release

Source: unknown | Confidence: high
Frees linked list nodes with optional release.

**Key logic:**
- Traverse list: if flag at node+2 set, free node[0]
- Free node itself
- Null all list pointers

**Calls:** FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md � list destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c2990 � Conditional Result Selector

Source: unknown | Confidence: medium
Calls FUN_004c2850(), conditionally returns result.

**Key logic:**
- If int part != 0: return FUN_004c11d0()

**Calls:** FUN_004c2850, FUN_004c11d0

**Used by system:** docs/01-engine-architecture.md � selector

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c3050 � State Struct Multi-Field Init

Source: unknown | Confidence: high
Initializes large struct with alternating 0/-1 patterns, zeros, 1.0 sentinel.

**Key logic:**
- Pattern: 0, -1, 0, -1 repeated 10x
- Scattered zeros at many offsets
- Field 0x1c = 1.0f

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � state init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7c40 � Callback Unregistration

Source: unknown | Confidence: high
Unregisters callback at LAB_004c7c50.

**Key logic:**
- FUN_00587b3e(&LAB_004c7c50)

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md � cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c8830 � Conditional Ratio Compute

Source: unknown | Confidence: medium
Computes ratio between two values if conditions met.

**Key logic:**
- Multiple guard checks (flags, globals)
- If active: set flag=1, compute ratio DAT_007cf380 / param_2

**Globals:** DAT_008ac4c8, DAT_007cf380, DAT_0059e440

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � ratio computation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c94d0 � Virtual Release Array (3 elements)

Source: unknown | Confidence: high
Releases 3 objects via virtual method + null.

**Key logic:**
- Loop 3: call virtual at (*obj)(1), set to null

**Calls:** virtual dispatch

**Used by system:** docs/01-engine-architecture.md � batch release

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004cb5e0 � Backward Array Iterator Release

Source: unknown | Confidence: medium
Iterates backward, releases each element.

**Key logic:**
- Count down from param_1+100
- For each: set element[1]=-1, FUN_00558b30(element[0])

**Calls:** FUN_00558b30

**Used by system:** docs/01-engine-architecture.md � array release

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d0080 � Array-of-Struct Deallocator

Source: unknown | Confidence: high
Frees all elements in array-of-struct, then frees buffer.

**Key logic:**
- If DAT_008afe88: iterate elements at stride 0x84, call FUN_00545150
- Deallocate: iterate header elements, FUN_004a2220 each, free buffer
- Null pointers

**Calls:** FUN_00545150, FUN_004a2220, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md � array cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d4860 � VTable Setter with Init

Source: unknown | Confidence: medium
Sets vtable and calls init.

**Key logic:**
- *param_1 = &PTR_FUN_005acf08
- FUN_004d48b0()

**Calls:** FUN_004d48b0

**Used by system:** docs/01-engine-architecture.md � construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7930 � Callback Unregistration

Source: unknown | Confidence: high
Unregisters callback at LAB_004d7940.

**Key logic:**
- FUN_00587b3e(&LAB_004d7940)

**Calls:** FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md � cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7fe0 � Delegate with Dereference

Source: unknown | Confidence: high
Calls FUN_004d8a30 with *(param_1+4).

**Key logic:**
- FUN_004d8a30(*(param_1 + 4))

**Calls:** FUN_004d8a30

**Used by system:** docs/01-engine-architecture.md � delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d9f80 � Countdown with Threshold Check

Source: unknown | Confidence: medium
Decrements float until hitting threshold, triggers callbacks.

**Key logic:**
- If value > DAT_0059e440: decrement by _DAT_008afe98
- If sub-value < threshold: call FUN_004d9fe0()
- If FUN_004da080(): call FUN_004da0d0(), return 0
- Return 1

**Calls:** FUN_004d9fe0, FUN_004da080, FUN_004da0d0

**Used by system:** docs/01-engine-architecture.md � countdown

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc220 � Conditional Object Constructor

Source: unknown | Confidence: medium
Allocates 4-dword object if param_1==0.

**Key logic:**
- Alloc 0x10 bytes, set vtable, [1]=3, byte+2=0, [3]=0

**Calls:** operator_new

**Used by system:** docs/01-engine-architecture.md � conditional singleton

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcee0 � Float-to-Int Chain Delegate

Source: unknown | Confidence: medium
__ftol chain then delegate.

**Key logic:**
- uVar1 = __ftol(x), uVar2 = __ftol(uVar1), uVar3 = __ftol(uVar2)
- FUN_004dcdd0(uVar3, uVar2, uVar1, x)

**Calls:** __ftol (x3), FUN_004dcdd0

**Used by system:** docs/01-engine-architecture.md � float-int delegate

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004de5d0 � Indexed Struct Field Compute

Source: unknown | Confidence: high
Returns computed pointer: ushort*0x30 + base.

**Key logic:**
- Read ushort at p1+p2*2, * 0x30, + *(*(p1+8)+0xc)

**Calls:** none

**Algorithm family:** Indexed struct access

**Used by system:** docs/01-engine-architecture.md � element lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e2a60 � Object Init Delegate

Source: unknown | Confidence: high
Calls init on sub-object at +0x90.

**Key logic:**
- FUN_004ddad0(param_1 + 0x90, 0)

**Calls:** FUN_004ddad0

**Used by system:** docs/01-engine-architecture.md � sub-object init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004efee0 � 3D Dot Product

Source: unknown | Confidence: high
Dot product of 3-float vectors.

**Key logic:**
- Return p1[0]*p2[0] + p1[1]*p2[1] + p1[2]*p2[2]

**Calls:** none

**Algorithm family:** 3D vector math � dot product

**Used by system:** docs/18-physics-dynamics.md � vector math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f6f20 � Large State Struct Init

Source: unknown | Confidence: high
Multi-field zero/sentinel init for large struct.

**Key logic:**
- 45x FUN_004f6f00(), FUN_004f6bc0() x2
- Zero many fields, set [0x28]=1.0f

**Calls:** FUN_004f6f00 (x45), FUN_004f6bc0 (x2)

**Used by system:** docs/01-engine-architecture.md � struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8d40 � State Struct Zero-Init

Source: unknown | Confidence: high
Zeroes 12 ints + 2 bytes.

**Key logic:**
- 11 ints zeroed, + scattered bytes at +0xb, +0x1b

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � state init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f9fc0 � Audio Timer Config Set

Source: unknown | Confidence: medium
Sets audio timing global, resets channels, reads back.

**Key logic:**
- _DAT_008afea0 = (double)param_1
- Reset channels 0/1, read back channel 0

**Globals:** _DAT_008afea0, _DAT_008afea8

**Calls:** FUN_00568c60, FUN_00556700 (x2), FUN_00556760

**Used by system:** docs/21-audio-network-internals.md � audio timing

**Moddability:** configurable � sets global timing

<!-- target: docs/20-math-utilities.md -->

## FUN_004fde00 � Piecewise Response Curve

Source: unknown | Confidence: medium
3-region piecewise function mapping to 2D output.

**Key logic:**
- 5 thresholds mapping to (0,0), linear ramp, hold, second ramp, (1,1)

**Globals:** _DAT_0059e4e8, _DAT_0059e8f8, _DAT_0059e6e8, _DAT_0059e43c

**Calls:** none

**Algorithm family:** Piecewise response curve

**Used by system:** docs/01-engine-architecture.md � curve mapping

**Moddability:** configurable � globals control thresholds

<!-- target: docs/20-math-utilities.md -->

## FUN_005008e4 � Render Region Copy with Validation

Source: unknown | Confidence: medium
Copies rect between surfaces with bounds validation.

**Key logic:**
- Validate params non-null
- Validate dimensions via FUN_00502a15
- Validate clip rect bounds
- Perform copy via FUN_0050070d

**Calls:** FUN_00500f3c, FUN_00502a15, FUN_0050070d, FUN_00500f55

**Used by system:** docs/19-renderer.md � surface copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00503772 � MMX Image Blend (2x2 Pixel Averaging)

Source: unknown | Confidence: medium
MMX-optimized bilinear image blending.

**Key logic:**
- 2x2 pixel averaging: (a + b + 2) >> 2
- Channel clamp to [0, 255]
- Fallback to scalar if unaligned

**Algorithm family:** MMX image blend

**Used by system:** docs/19-renderer.md � image processing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00506538 � Single Field Zero-Init

Source: unknown | Confidence: high
Sets *param_1 = 0.

**Key logic:**
- *param_1 = 0

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � leaf reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050afc6 � Constructor with VTable (0x005adcac)

Source: unknown | Confidence: medium
Constructor.

**Key logic:**
- FUN_00507496(param_2, 0x20, 1) � base
- *param_1 = &PTR_FUN_005adcac

**Calls:** FUN_00507496

**Used by system:** docs/01-engine-architecture.md � construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b797 � Constructor with VTable (0x005addcc)

Source: unknown | Confidence: medium
Constructor.

**Key logic:**
- FUN_0050afe2(param_2) � base
- *param_1 = &PTR_FUN_005addcc

**Calls:** FUN_0050afe2

**Used by system:** docs/01-engine-architecture.md � construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c3bb � Cubic Bezier Interpolation (3D)

Source: unknown | Confidence: medium
Evaluates point on cubic Bezier curve from 4 control points.

**Key logic:**
- t, t�, t� basis functions with global constants
- 4 coefficients computed, applied to each XYZ dimension
- Global scale factor applied

**Globals:** _DAT_0059e450, _DAT_0059e800, _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e46c

**Algorithm family:** Cubic Bezier curve

**Used by system:** docs/20-math-utilities.md � spline interpolation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d6ac � 2D Rotation Matrix (Z-axis, 4x4)

Source: unknown | Confidence: high
Builds 4x4 Z-axis rotation matrix from angle.

**Key logic:**
- cos/sin, 4x4 matrix with standard Z-rotation layout

**Calls:** fcos, fsin

**Algorithm family:** 3D math � rotation matrix

**Used by system:** docs/18-physics-dynamics.md � transforms

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e342 � Quaternion SLERP

Source: unknown | Confidence: medium
Spherical linear interpolation between two quaternions.

**Key logic:**
- Sum angles, check threshold
- Two-stage slerp via FUN_0050e174
- Near-identity fallback: copy source

**Calls:** FUN_0050c042, thunk_FUN_0050e174 (x3)

**Algorithm family:** Quaternion SLERP

**Used by system:** docs/18-physics-dynamics.md � quaternion ops

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050fc58 � CPU Feature Check (MMX/SSE)

Source: unknown | Confidence: high
Checks CPUID for feature flags.

**Key logic:**
- CPUID leaf 1, check ECX bit 23

**Calls:** cpuid_Version_info

**Used by system:** docs/01-engine-architecture.md � CPU detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00511f23 � Repeated Element Dispatch

Source: unknown | Confidence: medium
Repeatedly dispatches elements to function.

**Key logic:**
- Get inner/outer counts
- Loop: for each outer, for each inner: FUN_00511b7c

**Calls:** FUN_0051234d, FUN_00511b7c

**Used by system:** docs/01-engine-architecture.md � batched dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513b51 � Dual Operation with Guard

Source: unknown | Confidence: medium
Two operations if both params non-null.

**Key logic:**
- FUN_00513b36 + FUN_00513a56 with global

**Calls:** FUN_00513b36, FUN_00513a56

**Used by system:** docs/01-engine-architecture.md � dual dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00515986 � Bitfield-Controlled Memory Copy

Source: unknown | Confidence: high
Copies dwords controlled by bitfield.

**Key logic:**
- (param_3 & 0x1ffffff) << 5 dwords copied

**Calls:** none

**Algorithm family:** Masked copy

**Used by system:** docs/20-math-utilities.md � copy utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00516959 � Virtual Release + Null

Source: unknown | Confidence: high
Calls virtual release, nulls pointers.

**Key logic:**
- If *(p1+4): call virtual at (*(p1+4)+0x28)(p1)
- Null p1+4 and p1+0x10

**Calls:** virtual dispatch

**Used by system:** docs/01-engine-architecture.md � sub-object release

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00517f58 � Dual Call Delegate

Source: unknown | Confidence: high
Two calls in sequence.

**Key logic:**
- FUN_00513bd1 + FUN_00513cf0

**Calls:** FUN_00513bd1, FUN_00513cf0

**Used by system:** docs/01-engine-architecture.md � dual operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051c813 � MMX Pixel Blender (8-bit channels)

Source: unknown | Confidence: low
Complex MMX pixel blending with per-channel weighted average.

**Key logic:**
- Uses psubsw, pmaddwd, packssdw, psraw
- Per-channel blend with saturation clamp to [0..255]
- 3 output values per pixel

**Algorithm family:** MMX SIMD pixel blend

**Used by system:** docs/19-renderer.md � software pixel pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00522b22 � Media State Init with 64-bit Values

Source: unknown | Confidence: medium
Initializes media playback state.

**Key logic:**
- Set 8 fields with 64-bit constants
- FastExitMediaState()

**Calls:** FastExitMediaState

**Used by system:** docs/21-audio-network-internals.md � media state

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00529700 � MMX Polynomial Approximation

Source: unknown | Confidence: low
MMX packed floating-point polynomial.

**Key logic:**
- Packed float-to-int, polynomial via constants
- Result in MMX register

**Algorithm family:** MMX polynomial

**Used by system:** docs/20-math-utilities.md � MMX math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e4e0 � Debug Output String

Source: unknown | Confidence: high
Formats and outputs debug string.

**Key logic:**
- Format via FUN_0058ac95, OutputDebugStringA

**Calls:** FUN_0058ac95, OutputDebugStringA

**Used by system:** docs/01-engine-architecture.md � debug

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005354e0 � File Open by Type

Source: unknown | Confidence: medium
Opens file based on type tag 'r'.

**Key logic:**
- Check byte at +0x17 == 'r'
- Copy source, get handle
- Read via FUN_0058afe1 or FUN_00587f64

**Calls:** FUN_00536e90, FUN_0058afe1, FUN_00587f64

**Used by system:** docs/08-file-formats.md � file open

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00539670 � Bit Reversal

Source: unknown | Confidence: high
Reverses bits of uint over given width.

**Key logic:**
- For param_2 bits: LSB?result, shift
- Return (result & 0x7fffffff) | LSB

**Calls:** none

**Algorithm family:** Bit reversal

**Used by system:** docs/20-math-utilities.md � bit manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b330 � Flag Setter + Three-Field Assign

Source: unknown | Confidence: high
Sets bit 1, stores 3 values.

**Key logic:**
- *p1 |= 2, p1[7]=p2, p1[8]=p3, p1[9]=p4

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � field assign

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c590 � String Copy to Global Buffer

Source: unknown | Confidence: high
Copies string to DAT_008b6ac8.

**Key logic:**
- Copy param_2 to DAT_008b6ac8 via offset trick

**Globals:** DAT_008b6ac8

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � string copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d2e0 � Conditional Delegate

Source: unknown | Confidence: high
Calls FUN_00553070 if FUN_0053d1f0 succeeds.

**Key logic:**
- Conditional guard

**Calls:** FUN_0053d1f0, FUN_00553070

**Used by system:** docs/01-engine-architecture.md � conditional

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00540760 � Multi-List Destructor with Virtual Release

Source: unknown | Confidence: medium
Complex destructor traversing 4 linked lists.

**Key logic:**
- For each list: traverse, call virtual (*+8)(), free nodes
- Null head after each

**Calls:** virtual dispatch, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md � complex destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005424e0 � 4-Field Bulk Getter

Source: unknown | Confidence: high
Reads 4 fields from struct to output ptrs.

**Key logic:**
- If ptr non-null: assign from param_1+0x54, +0x58, +100, +0x68

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � bulk getter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005454a0 � Destructor with Conditional Free

Source: unknown | Confidence: high
Cleanup + conditional free.

**Key logic:**
- FUN_005455f0, FUN_0055d2e0
- If p1 != 0: FUN_00557470, free

**Calls:** FUN_005455f0, FUN_0055d2e0, FUN_00557470, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md � destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547240 � Gear Ratio Setter with Flag Condition

Source: unknown | Confidence: medium
Sets two short fields (gear ratios), conditionally sets flag bit.

**Key logic:**
- Set (param_1+0xac) and (param_1+0xae) if in [1, 8]
- Unless (2,1): set bit 5 at +0x9c

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x9c | Flags | uint | Bit 5 |
| +0xac | GearA | short | Ratio A |
| +0xae | GearB | short | Ratio B |

**Calls:** none

**Used by system:** docs/10-vehicle-physics.md � gear config

**Moddability:** configurable � direct gear ratio write

<!-- target: docs/20-math-utilities.md -->

## FUN_00548850 � Indexed Linked List Search

Source: unknown | Confidence: high
Searches list by 16-bit index.

**Key logic:**
- Guard: idx >= count ? 0
- Traverse at p1+0x24, next at +0xc0
- Return matching node

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � list lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054a1c0 � Bitmask Global Set/Clear

Source: unknown | Confidence: high
Sets/clears bits in DAT_008b8ee0.

**Key logic:**
- If param_2 == 0: clear bits
- Else: set bits

**Globals:** DAT_008b8ee0

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � global mask

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0054c0e0 � Bitmask Permission Check

Source: unknown | Confidence: high
Checks permission flags.

**Key logic:**
- If (p2+0x84) & mask & DAT_008b8e34 != mask: return 0

**Globals:** DAT_008b8e34

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � permission check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fc70 � Single Field Setter

Source: unknown | Confidence: high
Sets *(p1 + 0x6c) = p2.

**Key logic:**
- Single field assign

**Calls:** none

**Used by system:** docs/01-engine-architecture.md � field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00553d00 � 2D Range Swap + Grid Fill Call

Source: unknown | Confidence: medium
Swaps min/max, calls grid fill.

**Key logic:**
- If param_3 < param_2: swap
- FUN_00561a15()

**Calls:** FUN_00561a15

**Used by system:** docs/01-engine-architecture.md � 2D fill

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00559f00 � PRNG � 4 Uniform Ints from Seed (base 10)

Source: unknown | Confidence: medium
Generates 4 uniform random integers in [0, 10).

**Key logic:**
- Uses FUN_00589278 for each output

**Calls:** FUN_00559d80, FUN_00589278

**Algorithm family:** PRNG

**Used by system:** docs/01-engine-architecture.md � RNG

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055eeaf � 4x3 Matrix 3D Vector Transform

Source: unknown | Confidence: high
Affine transform: 4x3 matrix � 3D vector.

**Key logic:**
- Standard matrix-vector multiply with 4x3 layout

**Calls:** none

**Algorithm family:** 4x3 matrix transform

**Used by system:** docs/18-physics-dynamics.md � coordinate transform

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00564a00 � Delegated Call with Struct Fields

Source: unknown | Confidence: medium
Calls FUN_005890aa with struct fields.

**Key logic:**
- FUN_005890aa(p1[5], *p1, p1[2], p2)

**Calls:** FUN_005890aa

**Used by system:** docs/01-engine-architecture.md � delegation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00567cc0 � Recursive Tree Destructor

Source: unknown | Confidence: high
Recursively destroys 3-child tree.

**Key logic:**
- Recurse on children at +4, +8, +0xc
- Node cleanup + free

**Calls:** recursive, FUN_00567940, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md � tree destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a590 � Single Delegate (thunk to FUN_00585d70)

Source: unknown | Confidence: high
Thin wrapper.

**Key logic:**
- FUN_00585d70()

**Calls:** FUN_00585d70

**Used by system:** docs/01-engine-architecture.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057b800 � Object Init with Field Copy

Source: unknown | Confidence: high
Init + copy field at +0x1c.

**Key logic:**
- FUN_00587370(p2)
- *(p1 + 0x1c) = *(p2 + 0x1c)

**Calls:** FUN_00587370

**Used by system:** docs/01-engine-architecture.md � init + copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585e50 � Single Delegate (thunk to FUN_00599958)

Source: unknown | Confidence: high
Thin wrapper.

**Key logic:**
- FUN_00599958()

**Calls:** FUN_00599958

**Used by system:** docs/01-engine-architecture.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587680 � Single Delegate (thunk to FUN_00598815)

Source: unknown | Confidence: high
Thin wrapper.

**Key logic:**
- FUN_00598815()

**Calls:** FUN_00598815

**Used by system:** docs/01-engine-architecture.md � call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005891fe � Range Partitioning with Callback Comparator

Source: unknown | Confidence: medium
Partitions range, finds optimal element via callback.

**Key logic:**
- Step through range
- Callback comparator selects best
- FUN_0058924c acts on best

**Calls:** callback, FUN_0058924c

**Used by system:** docs/01-engine-architecture.md � optimal partition

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058b9ff � Drive Type Validation

Source: unknown | Confidence: high
Checks drive is valid/fixed via GetDriveTypeA.

**Key logic:**
- Build "X:\" path
- Return 0 for invalid/removable

**Calls:** GetDriveTypeA

**Used by system:** docs/08-file-formats.md � FS validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005912bc � Float Modulus with Denormal Handling

Source: unknown | Confidence: medium
fmod with subnormal/edge-case handling.

**Key logic:**
- Normal exponent ? helper
- Denormal ? scale + helper
- Zero ? in_ST0 - trunc(in_ST0/in_ST1)*in_ST1

**Algorithm family:** Float modulus

**Used by system:** docs/20-math-utilities.md � float math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00596888 � Decompression Push � Buffer Decrement-Write

Source: unknown | Confidence: medium
Pushes byte into decompression ring buffer.

**Key logic:**
- Decrement write ptr
- Write or compare (dedup)
- Update count and flags

**Algorithm family:** Decompression buffer

**Used by system:** docs/08-file-formats.md � decompression

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598e07 � Copy 6 Dwords from Global Source

Source: unknown | Confidence: high
Copies 6 dwords from FUN_0059942b source.

**Key logic:**
- Get global data ptr, copy 6 dwords

**Calls:** FUN_0059942b

**Used by system:** docs/01-engine-architecture.md � state copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a0d5 � Buffer Read Through VTable with Bounds Check

Source: unknown | Confidence: medium
Buffered read with inline optimization.

**Key logic:**
- Try inline buffer first with bounds check
- Fallback: virtual dispatch

**Calls:** virtual dispatch

**Used by system:** docs/01-engine-architecture.md � buffered read

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c4aa � SEH Unwind Handler (free object)

Source: unknown | Confidence: high
Frees object at EBP-0x14.

**Calls:** FUN_00587bcf

**Used by system:** docs/20-math-utilities.md � SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ca30 � SEH Unwind Handler (thunk to FUN_0047aa60)

Source: unknown | Confidence: high
SEH unwind trampoline.

**Calls:** FUN_0047aa60

**Used by system:** docs/20-math-utilities.md � SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d0e0 � SEH Unwind Handler (thunk to FUN_005870d0)

Source: unknown | Confidence: high
SEH unwind trampoline.

**Calls:** FUN_005870d0

**Used by system:** docs/20-math-utilities.md � SEH unwind

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059db5b � Thunk to FUN_004a13d9

Source: unknown | Confidence: high
Trampoline.

**Key logic:**
- FUN_004a13d9()

**Calls:** FUN_004a13d9

**Used by system:** docs/20-math-utilities.md � thunk

**Moddability:** hardcoded

## FUN_0052d8c0 — VTable Destructor Wrapper with Null Check

Source: unknown | Confidence: high
Destructor wrapper — calls vtable method at slot 0 on object pointer if non-null, then clears the pointer.

**Key logic:**
- Checks if `*param_1` (object pointer) is non-null
- If non-null: calls vtable[0] with argument 1 (destructor pattern), then sets `*param_1 = 0`
- Returns 1 if object was destroyed, 0 if null
- Common C++ idiom: null-safe destructor wrapper for COM-like or reference-counted objects

**Calls:** vtable[0] (destructor — address 0x0052d990 based on function naming)

**Used by system:** docs/20-math-utilities.md — likely called as a cleanup helper from various engine subsystems

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00551790 — Linked List String Key Removal

Source: unknown | Confidence: medium
Walks a linked list, compares each node's string key against a target, removes matching nodes by clearing a flag bit and calling a notification function.

**Key logic:**
- Reads linked list head from `param_1 + 0x13c`, walks via `+0x24`
- At each node: compares wide string at `+0x1c` from content pointer against `param_2`
- If match: clears bit `0x00020000` at `node+0x04`, calls FUN_00551480

**Calls:** FUN_00551480 — animation start / audio flag set (per docs/09)

**Used by system:** docs/20-math-utilities.md — animation key removal or audio event unlinking

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b7f0 — VTable Pointer Init

Source: unknown | Confidence: high
Sets vtable pointer to PTR_FUN_005b8a64, calls FUN_005870d0 (init).

**Key logic:**
- `*param_1 = &PTR_FUN_005b8a64`
- Calls FUN_005870d0 — vtable init function

**Calls:** FUN_005870d0 (vtable init)

**Used by system:** docs/20-math-utilities.md — object construction with vtable assignment

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005879f0 — Field Constants Initialization

Source: unknown | Confidence: high
Sets fields: `*(param_1+0x400)=0, *(param_1+0x404)=0, *(param_1+0x408)=0, *(param_1+0x40c)=500`.

**Key logic:**
- Value 500 at +0x40c — likely a timeout or max count

**Used by system:** docs/20-math-utilities.md — struct constructor initialization

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0058a2ef — SEH Unwind with Indirect Jump

Source: unknown | Confidence: medium
MSVC exception unwind: manipulates ExceptionList, indirect jump via unrecovered jumptable.

**Key logic:**
- Sets `ExceptionList = *(void**)ExceptionList` — unwinds SEH chain
- Indirect jump (jumptable unrecoverable by Ghidra)

**Used by system:** docs/20-math-utilities.md — MSVC C++ exception internals

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598cc1 — Set Locale VTable + Call

Source: unknown | Confidence: medium
Sets vtable to PTR_FUN_005b9c04, calls FUN_00598c70.

**Key logic:**
- MSVC locale/iostream init pattern

**Calls:** FUN_00598c70 (null check with virtual dispatch)

**Used by system:** docs/20-math-utilities.md — MSVC runtime locale init

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599be5 — Set Locale VTable + Dtor

Source: unknown | Confidence: medium
Sets vtable to PTR_FUN_005b9c50, calls FUN_0059a86c (object destructor with ref count decrement).

**Calls:** FUN_0059a86c (object destructor)

**Used by system:** docs/20-math-utilities.md — MSVC runtime locale teardown

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a70b — C++ Throw with Exception

Source: unknown | Confidence: high
Constructs exception object, throws via MSVC runtime.

**Key logic:**
- Calls FUN_0059a781 (exception ctor with string copy)
- Calls `__CxxThrowException_8` (noreturn)

**Calls:** FUN_0059a781 (exception ctor), __CxxThrowException_8

**Used by system:** docs/20-math-utilities.md — C++ exception throwing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059aeda — Exception Destructor

Source: unknown | Confidence: high
C++ exception destructor — SEH init, vtable set, ref count decrement, base dtor call.

**Key logic:**
- Calls FUN_0058a5d8 (SEH init), sets vtable to PTR_FUN_005b9d7c
- Calls FUN_005993af(1) (ref count decrement), exception::~exception(), restores ExceptionList

**Calls:** FUN_0058a5d8 (SEH init), FUN_005993af (ref count), exception::~exception

**Used by system:** docs/20-math-utilities.md — C++ exception internals

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c400 — SEH Unwind Free at -0x54

Source: unknown | Confidence: high
SEH unwind handler: frees object at EBP-0x54.

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/01-engine-architecture.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c56e — SEH Unwind Free at -0x10

Source: unknown | Confidence: high
SEH unwind handler: frees object at EBP-0x10.

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c67a — SEH Unwind Free at +8

Source: unknown | Confidence: high
SEH unwind handler: frees object at EBP+8.

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c804 — SEH Unwind → FUN_00581820

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00581820 (list destructor with CloseHandle).

**Calls:** FUN_00581820

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c948 — SEH Unwind → FUN_00581b30

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00581b30 (cleanup).

**Calls:** FUN_00581b30

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cb80 — SEH Unwind → FUN_005834c0

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_005834c0 (list destruction with virtual release).

**Calls:** FUN_005834c0

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cd13 — SEH Unwind Free at -0x18

Source: unknown | Confidence: high
SEH unwind handler: frees object at EBP-0x18.

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059ceed — SEH Unwind → FUN_005833e0

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_005833e0 (list walk + destructor + free).

**Calls:** FUN_005833e0

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d050 — SEH Unwind → FUN_00583650

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00583650 (single function call wrapper).

**Calls:** FUN_00583650

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d1d8 — SEH Unwind with Object Dtor

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00599796 (no-op stub) with DAT_008d42a0 param.

**Globals:** DAT_008d42a0 — data object

**Calls:** FUN_00599796 (no-op stub)

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d414 — SEH Unwind → FUN_00598c70

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00598c70 (null check with virtual dispatch).

**Calls:** FUN_00598c70

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00403fc0 — Indexed Struct Data Read

Source: unknown | Confidence: medium
Reads two 3-value sets from a 2D array indexed by (param_2, param_3).

**Key logic:**
- Array stride: 0x1c bytes per element
- Base at `*(param_1+0x158)`, columns at `*(param_1+0x164)`
- Index: `(cols * param_3 + param_2) * 0x1c`
- Copies two 12-byte triplets to *param_4 and *param_5 (offset +0xc between them)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x158 | int* | Array base pointer |
| +0x164 | int | Array columns count |

**Used by system:** docs/20-math-utilities.md — lookup table / data access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404f10 — Conditional Flag Return

Source: unknown | Confidence: low
Returns 0x100 (bit 8 set) if FUN_00404f00 returns true and value at *ECX+0x20 is 1 or 2.

**Key logic:**
- Calls FUN_00404f00(); if true and `*(*ECX+0x20)` is 0 < value < 3: returns 0x100
- Otherwise returns original value with low byte cleared

**Calls:** FUN_00404f00

**Used by system:** docs/20-math-utilities.md — state flag check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00406020 — Smoothstep Interpolation

Source: unknown | Confidence: medium
Smoothstep-like interpolation with cubic Hermite curve.

**Key logic:**
- Computes `fVar1 = *(param_1+0x1c) * param_2 + *(param_1+0x20)`
- If fVar1 < DAT_0059e43c (≈0.0f): returns *(param_1+0x40)
- Else: `t = DAT_0059e43c / fVar1; result = ((t³ - t) * *(param_1+0x24) + t) * *(param_1+0x40)`
- Smoothstep: `t * t * (3 - 2t)` variant with gain at +0x24

**Globals:** DAT_0059e43c — physics constant (~0.0f)

**Used by system:** docs/20-math-utilities.md — audio envelope or animation curve

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004078a0 — Linked List Node Insert

Source: unknown | Confidence: medium
Allocates and inserts a node into a linked list (queue).

**Key logic:**
- If `*(param_1+0x88) != 0`: allocates 0x60 bytes, calls FUN_00406130
- Allocates 0xc byte node: `*node = FUN_00406130_result, node[1]=0, node[2]=0`
- If list head (+0x18) null: head=tail=node; else appends at tail(+0x1c)
- Increments count at +0x24

**Calls:** operator_new, FUN_00406130

**Used by system:** docs/20-math-utilities.md — linked list node insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004083e0 — Struct Init with Conditional Notify

Source: unknown | Confidence: medium
Zero-initializes struct fields, conditionally calls notification.

**Key logic:**
- Sets [0]=0, [1]=0, [2]=0x3f800000 (1.0f), [3]=0, [4]=0, [5]=0 (byte)
- If byte at +0x15 is non-zero: calls FUN_004d8860(1), clears +0x15

**Calls:** FUN_004d8860 (short computation)

**Used by system:** docs/20-math-utilities.md — struct initialization with deferred notification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040b450 — Lookup with Optional Callback

Source: unknown | Confidence: low
Looks up a value by key, optionally fires a vtable callback.

**Key logic:**
- If param_2 != 0: calls FUN_0040ad60(param_2) for lookup
- If positive: calls FUN_0040ad90 on result
- If param_3 != 0: calls vtable[0x10]()
- Returns result with bit 8 set on success

**Calls:** FUN_0040ad60, FUN_0040ad90, vtable[0x10]

**Used by system:** docs/20-math-utilities.md — key lookup with optional notification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d100 — Game State Branch Dispatch

Source: unknown | Confidence: medium
Switches on DAT_007cfdc4 to dispatch game state update calls.

**Key logic:**
- If `*(param_1+0x18) != 0`: switch on DAT_007cfdc4
  - default: FUN_00409440(2,0,1) + FUN_0040cde0(2,0)
  - case 1: FUN_00409440(1,0,1) + FUN_0040cde0(1,0)
  - case 2: FUN_00409440(0,0,1) + FUN_0040cde0(0,0)
  - case 3: FUN_00409440(3,0,1) + FUN_0040cde0(3,0)
  - case 4: FUN_00409440(3,0,1) + FUN_0040cde0(5,0)

**Globals:** DAT_007cfdc4 — game state phase/selector

**Calls:** FUN_00409440 (game_logic), FUN_0040cde0 (game_logic)

**Used by system:** docs/20-math-utilities.md — game state machine dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e2b0 — Audio/Physics Mix with Lerp

Source: unknown | Confidence: low
Computes blended audio/physics values with interpolation factor based on mode.

**Key logic:**
- Calls FUN_004dd550 (vector setup)
- Computes weighted sums: fVar1/fVar2/fVar3 = (vector components) × DAT_0059e450
- Iterates iVar7 times (FUN_0054e100/120 — vehicle struct access), accumulates values
- Averages by dividing by iVar7
- Blends with factor from DAT_0059e6e8 or DAT_0059e458 depending on param_2==2
- Smooth blend: `result = computed × factor + accumulated × (1 - factor)`
- Calls FUN_0054b420/FUN_0054b3b0 (vector ops) and FUN_0054c230 (vehicle access)

**Globals:** DAT_0059e450, DAT_0059e43c, DAT_0059e6e8, DAT_0059e458 — physics constants

**Calls:** FUN_004dd550, FUN_0054c230, FUN_0054e100, FUN_0054e120, FUN_0054b420, FUN_0054b3b0, FUN_0040e1f0

**Used by system:** docs/20-math-utilities.md — audio parameter blending or physics interpolation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040f380 — Switch-Based State Handler

Source: unknown | Confidence: medium
Dispatches between 8 cases based on `*(param_1+0x1c)`, calls vehicle physics functions.

**Key logic:**
- Cases 0/1/3/4/5: calls FUN_004ea040 (vehicle struct access)
- Case 2: reads 3 doubles from +0x138/+0x140/+0x148, casts to float, calls FUN_0054fb40(1) + FUN_004e9a40
- Case 6: checks bit 0 at **(param_1+0x20)+0x48bc, reads int at [0x1ba], float at +0x34ec
- Case 7: calls FUN_004e9a40(0), FUN_0054f7a0(uVar2,1), FUN_0054fb40(0)

**Calls:** FUN_004ea040, FUN_0054fb40, FUN_004e9a40, FUN_0054f7a0

**Used by system:** docs/20-math-utilities.md — vehicle physics state dispatcher

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004116c0 — Scene Graph Query

Source: unknown | Confidence: medium
Queries scene graph via DAT_008ac4c4 pointer, calls vtable method twice.

**Key logic:**
- If DAT_008ac4c4 non-null: calls FUN_004117b0 (lookup)
- On success: calls vtable[0x48] twice with (local_c, local_10)

**Globals:** DAT_008ac4c4 — scene graph root pointer

**Calls:** FUN_004117b0, vtable[0x48]

**Used by system:** docs/20-math-utilities.md — scene graph query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004144d0 — Struct Init with Sentinel Values

Source: unknown | Confidence: high
Initializes struct with 0xffffffff and 0xbf800000 (-1.0f) sentinel values.

**Key logic:**
- [0]=0xffffffff, [2]=0xbf800000 (-1.0f), [3]=0, [4..7]=0xffffffff

**Used by system:** docs/20-math-utilities.md — struct sentinel initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00418a20 — Boolean OR of Two Checks

Source: unknown | Confidence: medium
Returns 1 if either FUN_004189f0 or FUN_004189b0 returns true.

**Calls:** FUN_004189f0, FUN_004189b0

**Used by system:** docs/20-math-utilities.md — composite condition check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041f100 — Triple-Value Equality Check

Source: unknown | Confidence: medium
Checks if three consecutive values at indexed positions all equal 10.

**Key logic:**
- Calls FUN_004c2850, FUN_004c11d0 to get index iVar1
- If param_1 != 0 and iVar1 > 2: checks `*(param_1+0xd0+iVar1*4)==10`, `+0xd4...==10`, `+0xd8...==10`

**Calls:** FUN_004c2850, FUN_004c11d0 (vehicle struct access)

**Used by system:** docs/20-math-utilities.md — game state triple-value check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421930 — Chained Call

Source: unknown | Confidence: medium
Calls FUN_00421890(param_1) then FUN_00566650(param_1) — string copy with buffer realloc.

**Calls:** FUN_00421890, FUN_00566650 (string copy with realloc)

**Used by system:** docs/20-math-utilities.md — chained utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004234c0 — 3-Field Zero Init

Source: unknown | Confidence: high
Zeroes 3 int fields and 1 byte field.

**Key logic:**
- param_1[0]=0, [1]=0, [2]=0, byte at param_1+3 = 0

**Used by system:** docs/20-math-utilities.md — mini struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00452780 — Struct Init with Fixed Values

Source: unknown | Confidence: high
Initializes 11-field struct with fixed values and calls sub-init.

**Key logic:**
- param_1[1]=0x59 (89), [2..6]=0, [0]=0
- Calls FUN_00452740(0x59, 0)
- param_1[7..10]=0

**Calls:** FUN_00452740

**Used by system:** docs/20-math-utilities.md — struct construction with default values

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00456130 — Vector Copy (3 floats)

Source: unknown | Confidence: high
Copies 3 floats from param_2 to param_1+0x18, +0x1c, +0x20.

**Key logic:**
- Null-safe: checks param_2 != 0 before copying

**Used by system:** docs/20-math-utilities.md — 3D vector copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00459a40 — Physics State Integration

Source: unknown | Confidence: medium
Integrates velocity/acceleration values into physics state with 6-double block copy.

**Key logic:**
- Reads float from param_2+8, scales values at +0x30, +0x34, +0x2c
- Adds to state at param_1+0xd8, +0xe0, +0xe8
- Block copy: copies 6 doubles (48 bytes) from local to state
- Outputs 3 floats to param_3
- Calls FUN_0054b3b0 (vector op)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xd8 | double[6] | Physics velocity/acceleration state |

**Calls:** FUN_0054b3b0

**Used by system:** docs/20-math-utilities.md — physics integration step

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045bc00 — Thunk to FUN_0045b840

Source: unknown | Confidence: high
Trampoline — unconditional jmp to FUN_0045b840 (collision detection per triage).

**Calls:** FUN_0045b840 (collision detection)

**Used by system:** docs/20-math-utilities.md — collision call stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045c8b0 — Array Initialization Loop

Source: unknown | Confidence: medium
Resets struct fields and calls init function in 0x68-iteration loop.

**Key logic:**
- Sets *param_1 = 0
- If param_2 != 0: zeroes param_1[1..4]
- Loops 0x68 (104) times calling FUN_0045c850(i)

**Calls:** FUN_0045c850

**Used by system:** docs/20-math-utilities.md — array/table initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00460770 — Hash/Checksum Computation

Source: unknown | Confidence: medium
Computes weighted sum with constants: `param_1 * 0x122572e8 + param_2 * (-0x13797) + 0x1bf00fb1 + DAT_007c56b8`.

**Globals:** DAT_007c56b8 — hash seed or accumulator

**Used by system:** docs/20-math-utilities.md — hash or checksum function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461f70 — Conditional Function Call

Source: unknown | Confidence: medium
If `*(*param_1 + 0x1b79c) != 0`: calls FUN_00563410.

**Key logic:**
- Checks a large struct offset (0x1b79c from object at *param_1)

**Calls:** FUN_00563410

**Used by system:** docs/20-math-utilities.md — conditional dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00462ff0 — Clamped Physics Scale with Threshold

Source: unknown | Confidence: medium
Computes scaled physics value with magnitude-based clamping and condition checks.

**Key logic:**
- Uses param_2 * 0x48c0 to index into DAT_005efbd0/fbd4/fbd8 (physics data tables)
- Computes: `magnitude = sqrt(x² + y² + z²) * DAT_0059f128`
- If magnitude < DAT_0059e8a0: applies quadratic scale `(1 - mag * k) * param_3`
- If bit 1 at DAT_005f0f94[param_2 * 0x1230] clear: scales by DAT_0059e46c
- Clamps result to [DAT_0059e440, DAT_0059e450]

**Globals:** DAT_0059e440 (zero threshold), DAT_0059e450, DAT_0059e8a0, DAT_0059f124, DAT_0059f128, DAT_0059e46c, DAT_005efbd0/fbd4/fbd8, DAT_005f0f94

**Used by system:** docs/20-math-utilities.md — physics scaling with lookup tables

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464740 — Linked List Node Removal

Source: unknown | Confidence: medium
Removes node from singly-linked list by key match, frees content.

**Key logic:**
- Walks list at *param_1, compares *node == param_2
- Unlinks node, decrements count at param_1[3]
- Handles head/tail updates
- If content flag set: frees *node via FUN_00587bcf, then frees node

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — linked list node deletion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464fd0 — 0xE5D0-Byte Alloc and Init

Source: unknown | Confidence: medium
Allocates 0xe5d0 (58,320) bytes, calls init function, stores result.

**Key logic:**
- operator_new(0xe5d0), FUN_00464c10() init, *param_1 = result
- Returns null on allocation failure

**Calls:** operator_new, FUN_00464c10

**Used by system:** docs/20-math-utilities.md — large struct allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004668e0 — Init + VTable Set

Source: unknown | Confidence: high
Calls FUN_0048d3a0(param_2, param_3), sets `*param_1 = &PTR_FUN_0059f210`.

**Calls:** FUN_0048d3a0

**Used by system:** docs/20-math-utilities.md — object init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046a270 — VTable Set + Free + Call

Source: unknown | Confidence: medium
Sets vtable; if param_1[0xd2] non-null, frees it; calls FUN_0048ca50.

**Calls:** FUN_00587bcf (free), FUN_0048ca50

**Used by system:** docs/20-math-utilities.md — destructor pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046cb10 — Driver/Table Index Initialization

Source: unknown | Confidence: medium
Initializes driver mapping table from DAT_007cd470.

**Key logic:**
- Calls FUN_0046cb00(); if false, returns
- Loops through DAT_007cd470[] (up to 0x68 entries), writes to DAT_005f0730[entry * 0x1230] = iteration
- Stops on negative entry

**Globals:** DAT_007cd470 — driver index array; DAT_005f0730 — mapping table

**Calls:** FUN_0046cb00

**Used by system:** docs/20-math-utilities.md — driver/team mapping table init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046f490 — Clear Buffer and Init

Source: unknown | Confidence: medium
Calls FUN_0046e600(0x100) (256), then FUN_00433b60(buffer, 0, 1).

**Calls:** FUN_0046e600, FUN_00433b60

**Used by system:** docs/20-math-utilities.md — buffer clear utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00470d30 — UI Camera Constructor

Source: unknown | Confidence: medium
Initializes UI camera/view struct with default values.

**Key logic:**
- Calls FUN_00466d60(1)
- Sets vtable to PTR_FUN_005a0900
- Sets defaults: param_1[199]=&DAT_007cf038, [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0x199 (409)
- Registers with FUN_00486f30 twice

**Globals:** DAT_007cf038 — UI camera data; DAT_005be704, DAT_005c32c8 — registration targets

**Calls:** FUN_00466d60, FUN_00486f30

**Used by system:** docs/20-math-utilities.md — UI camera/view setup

**Moddability:** configurable — values at [0xc9-0xcd] may map to .svm fields

<!-- target: docs/20-math-utilities.md -->

## FUN_00472bc0 — Scene Graph Query + Conditional Call

Source: unknown | Confidence: medium
Calls FUN_0048c0e0, queries scene via DAT_007cd8c0 vtable[0x1c](0x13), conditionally calls FUN_00477280.

**Globals:** DAT_007cd8c0 — scene graph root

**Calls:** FUN_0048c0e0, vtable[0x1c], FUN_00477280

**Used by system:** docs/20-math-utilities.md — scene graph interaction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00474900 — UI Camera Constructor 2

Source: unknown | Confidence: medium
Similar to FUN_00470d30 but with different vtable and defaults.

**Key logic:**
- Calls FUN_00466d60(1), sets vtable to PTR_FUN_005a3cc0
- Defaults: param_1[199]=&DAT_007cfc44, [0xc9]=1, [0xca]=0, [0xcb]=1, [0xcc]=1, [0xcd]=0x18e (398)
- Registers + calls FUN_004670e0

**Calls:** FUN_00466d60, FUN_00486f30, FUN_004670e0

**Used by system:** docs/20-math-utilities.md — UI camera/view setup variant

**Moddability:** configurable

<!-- target: docs/20-math-utilities.md -->

## FUN_004761a0 — String Copy with Guard

Source: unknown | Confidence: medium
If param_1 != 0: calls FUN_00566650() — string copy with buffer realloc.

**Calls:** FUN_00566650 (string copy with realloc)

**Used by system:** docs/20-math-utilities.md — guarded string copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00478140 — Field Free + Cleanup

Source: unknown | Confidence: high
Frees field at +0xe8 if non-null, calls FUN_00485eb0, conditionally frees self.

**Calls:** FUN_00587bcf, FUN_00485eb0

**Used by system:** docs/20-math-utilities.md — destructor/cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479730 — UI Component Init

Source: unknown | Confidence: medium
Calls FUN_00466980(0, 0x3e4ccccd = 0.2f), sets vtable to PTR_FUN_005a4db8.

**Calls:** FUN_00466980

**Used by system:** docs/20-math-utilities.md — UI component constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479c80 — UI Component Init 2

Source: unknown | Confidence: medium
Calls FUN_004668e0(0, 0x3f800000 = 1.0f), sets vtable to PTR_FUN_005a5c18.

**Calls:** FUN_004668e0

**Used by system:** docs/20-math-utilities.md — UI component constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047a620 — UI Component Init 3

Source: unknown | Confidence: medium
Calls FUN_004668e0(0x3d4ccccd=0.05f, 0x3f800000=1.0f), sets vtable to PTR_FUN_005a64b8.

**Calls:** FUN_004668e0

**Used by system:** docs/20-math-utilities.md — UI component constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047c6e0 — UI Component Init 4

Source: unknown | Confidence: medium
Calls FUN_0048c070(1), sets vtable to PTR_FUN_005a68f0.

**Calls:** FUN_0048c070

**Used by system:** docs/20-math-utilities.md — UI component constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047fba0 — UI Component Dtor

Source: unknown | Confidence: high
Sets vtable, calls FUN_00489440, conditionally frees self.

**Calls:** FUN_00489440, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — UI component destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00485ae0 — Field Free + UI Dtor

Source: unknown | Confidence: high
Frees field at +0x174, calls FUN_00489440, conditionally frees self.

**Calls:** FUN_00587bcf (free), FUN_00489440

**Used by system:** docs/20-math-utilities.md — UI component destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486630 — Linked List Traversal with Callback

Source: unknown | Confidence: medium
Walks linked list starting at +0xd0 (next at +0x18), calls FUN_0049a5d0 on each iteration.

**Calls:** FUN_0049a5d0

**Used by system:** docs/20-math-utilities.md — list iteration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487640 — VTable Dispatch

Source: unknown | Confidence: medium
Calls FUN_00487460, then dispatches via vtable[0xa8].

**Calls:** FUN_00487460, vtable[0xa8]

**Used by system:** docs/20-math-utilities.md — vtable dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004883a0 — 5-Field Init

Source: unknown | Confidence: high
Sets fields +0xe0, +0xe4, +0xe8 = 0; +0xec = 1; +0xed = 0.

**Used by system:** docs/20-math-utilities.md — struct field init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489940 — Field Getter

Source: unknown | Confidence: high
Returns `*(param_1 + 0x168)`.

**Used by system:** docs/20-math-utilities.md — simple accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048c0d0 — VTable + Init

Source: unknown | Confidence: medium
Sets vtable to PTR_FUN_005abf88, calls FUN_0048b4e0.

**Calls:** FUN_0048b4e0

**Used by system:** docs/20-math-utilities.md — object vtable init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d4b0 — Scroll/Progress Handler

Source: unknown | Confidence: medium
UI scroll/progress handler — checks value delta thresholds, dispatches callbacks.

**Key logic:**
- Calls vtable[0xb4] to get current position
- If position == 0 or `(float)[0x3e] - (float)[0x3d] <= 0`: resets position, calls vtable[0x38](1)
- Else: calls vtable[0x20] then [0x18], converts to int
- If int != [0x38]: calls vtable[0x2c](1), updates [0x38], calls FUN_00488970 and vtable[0xb0]

**Calls:** vtable[0xb4/0x38/0x20/0x18/0x2c/0xb0], FUN_00488970

**Used by system:** docs/20-math-utilities.md — UI scrollbar or progress bar logic

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048ea40 — 4-Field Setter

Source: unknown | Confidence: high
Sets param_1+0x1c, +0x20, +0x24, +0x28 from params 4,5,2,3.

**Used by system:** docs/20-math-utilities.md — struct field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fe60 — UI Component Init 5

Source: unknown | Confidence: medium
Calls FUN_00485e30, sets vtable to PTR_FUN_005ac6b0, [0x38]=1, [0x39]=0.

**Calls:** FUN_00485e30

**Used by system:** docs/20-math-utilities.md — UI component constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490b90 — Multi-List Destruction

Source: unknown | Confidence: high
Destroys three linked lists with sub-object cleanup.

**Key logic:**
- Processes array of `*param_1` elements at param_1[2] (stride 0x10), calls FUN_004910d0 each
- Calls FUN_004910d0 on param_1+3, +7, +0xb
- Frees array allocation (with -4 header offset) via FUN_00587bcf
- Calls FUN_004b0170
- Destroys 3 linked lists: walks nodes, calls FUN_00491e60(1) if flagged, frees node

**Calls:** FUN_004910d0, FUN_00587bcf, FUN_004b0170, FUN_00491db0, FUN_00491e60

**Used by system:** docs/20-math-utilities.md — multi-list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491a40 — Linked List Node Unlink by Content

Source: unknown | Confidence: medium
Unlinks a node from list by matching content pointer, frees it.

**Key logic:**
- Uses `*(*param_1 + 0x10)` as content target, sets `*(*param_1 + 0x14) = target`
- Walks list at `*(*param_1 + 0xc)`, matches `*node == target`
- Unlinks node, decrements count at +0x18
- Frees content and node via FUN_00587bcf

**Calls:** FUN_00490aa0, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — list node removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00494a30 — 10-Param Forwarder

Source: unknown | Confidence: high
Forwards 10 params to FUN_00543250.

**Calls:** FUN_00543250

**Used by system:** docs/20-math-utilities.md — call forwarder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00495790 — Field Getter at +0x1570

Source: unknown | Confidence: high
Returns `*(param_1 + 0x1570)`.

**Used by system:** docs/20-math-utilities.md — simple accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00496e40 — Linked List Traversal with Virtual Call

Source: unknown | Confidence: medium
Walks linked list calling vtable[0x6c] on each node's content.

**Key logic:**
- Reads list from param_1 + 0x18dc, iterator at +0x18e4
- While iterator non-null and *iterator non-null:
  - Calls vtable[0x6c]() on content
  - Advances to next node via +0x04

**Used by system:** docs/20-math-utilities.md — list iteration with polymorphic dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497ec0 — Driver Name String Handler

Source: unknown | Confidence: medium
Copies driver name string into struct array, max 0x50 bytes each.

**Key logic:**
- Null-guard on param_2, returns -1 if null
- Copies string to local_50 buffer, calls FUN_00589901 to process
- Calls FUN_00497f90 (check), returns -1 on failure
- Calls FUN_00495810 (validation)
- Truncates at '&' separator (DAT_005beb48)
- Copies to struct at offset: base + count * 0x50
- Increments count at param_1 + 0x1514

**Globals:** DAT_005beb48 — separator character '&'

**Calls:** FUN_00589901, FUN_00497f90, FUN_00495810, FUN_00587c20

**Used by system:** docs/20-math-utilities.md — driver name registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498e50 — Node Insertion into Tree

Source: unknown | Confidence: medium
Inserts a node into a tree/hierarchy structure.

**Key logic:**
- Increments counter at param_1+0x58
- Sets param_2+0x50 = param_1 (parent link)
- Calls FUN_0049a9c0 with field values from param_1
- Walks children via +0x48 links, appends param_2 at end
- If no children: sets both head and tail

**Calls:** FUN_0049a9c0

**Used by system:** docs/20-math-utilities.md — tree node insertion

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499560 — Linked List Walk with Virtual Call

Source: unknown | Confidence: medium
Walks linked list at +0x44, calls vtable[0x74] on each node.

**Calls:** vtable[0x74], FUN_00486320 (iterator advance)

**Used by system:** docs/20-math-utilities.md — list iteration with vtable dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499b50 — Conditional Dual Cleanup

Source: unknown | Confidence: medium
Frees field at +0x30 via FUN_005539f0; if +0x2c set, calls FUN_005502c0.

**Calls:** FUN_005539f0 (resource cascade cleanup), FUN_005502c0

**Used by system:** docs/20-math-utilities.md — conditional resource cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00499eb0 — Abs-Value Field Setter

Source: unknown | Confidence: high
Sets fields to absolute values using branchless abs pattern.

**Key logic:**
- `param_1+0x60 = (param_2 < 0 ? -1 : 0) & param_2` — abs mask
- `param_1+100 = (param_3 < 0 ? -1 : 0) & param_3`

**Used by system:** docs/20-math-utilities.md — absolute value assignment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a580 — 7-Field Sentine Init

Source: unknown | Confidence: high
Initializes 7 fields with 0/0xffffffff sentinels.

**Key logic:**
- [1]=0, [2]=0xffffffff, [3]=0, [4]=0xffffffff, [0]=0, [6]=0, [5]=0

**Used by system:** docs/20-math-utilities.md — struct sentinel init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049b050 — Empty Stub

Source: unknown | Confidence: high
Returns immediately with no logic. Placeholder or stripped method.

**Used by system:** docs/20-math-utilities.md — empty placeholder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049e930 — Vehicle Node Creation

Source: unknown | Confidence: medium
Allocates and initializes a vehicle/entity node.

**Key logic:**
- Allocates 0x60 bytes, calls FUN_0054fe10 for init
- Sets bit 0 at +0x44 (active flag)
- Calls FUN_00550080(param_2, 0, 0x804) — resource binding
- On failure: calls FUN_00557470 + FUN_00587bcf, clears pointer

**Calls:** operator_new, FUN_0054fe10, FUN_00550080, FUN_00557470, FUN_00587bcf

**Used by system:** docs/20-math-utilities.md — vehicle/entity node allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049ffd0 — Cleanup Registration

Source: unknown | Confidence: high
Registers LAB_0049ffe0 as cleanup callback via FUN_00587b3e.

**Calls:** FUN_00587b3e (callback registration)

**Used by system:** docs/20-math-utilities.md — cleanup handler registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1a00 — String Format + Copy with Float

Source: unknown | Confidence: medium
Formats a float into string, computes string length, copies to destination with dword-aligned copy.

**Key logic:**
- Formats `*param_2` via FUN_0058815f using format DAT_005cd130
- Computes source string length (null termination scan)
- Computes dest string length
- Dword-aligned memory copy from end of source to end of dest (overlapping safe?)
- 4-byte stride then remaining bytes

**Calls:** FUN_0058815f (format)

**Used by system:** docs/20-math-utilities.md — string formatting utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a2980 — Struct Init + Call

Source: unknown | Confidence: high
Zeroes 3 fields, calls FUN_004a29a0, returns param_1.

**Calls:** FUN_004a29a0

**Used by system:** docs/20-math-utilities.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a48c0 — 5-Loop Init + Call

Source: unknown | Confidence: medium
Loops 5× calling FUN_0042e1c0, zeroes 3 fields, calls FUN_004a4db0.

**Calls:** FUN_0042e1c0, FUN_004a4db0

**Used by system:** docs/20-math-utilities.md — state initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b0220 — Path Truncation Utility

Source: unknown | Confidence: medium
Copies and truncates a path string at the last backslash.

**Key logic:**
- Null-guard on both params, returns -1 if either null
- Calls FUN_00568620(0x200) — buffer clear
- Uses _strncpy to copy param_1 into local_200 buffer with max length
- Null-terminates
- Walks backward from end, truncates at last '\\' character
- Returns 0 on success

**Calls:** FUN_00568620, _strncpy

**Used by system:** docs/20-math-utilities.md — path string manipulation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1d90 — Multi-Field Setter with String Copy

Source: unknown | Confidence: medium
Copies strings, sets 3 fields, conditionally copies extra field.

**Key logic:**
- Calls FUN_00566650(param_2) — string copy
- Sets +0x20=param_5, +0x18=param_3, +0x1c=param_4
- If param_6 != 0: copies string
- If param_7 != 0: sets +0x14=param_3 (alias)
- Calls FUN_004a1b70

**Calls:** FUN_00566650 (string copy), FUN_004a1b70

**Used by system:** docs/20-math-utilities.md — struct field setup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2930 — Float-to-Bitfield Pack

Source: unknown | Confidence: medium
Packs a scaled float into a 15-bit integer bitfield at [17:31].

**Key logic:**
- `iVar1 = ROUND(param_2 * DAT_0059e5fc)`, clamped to [0, 0x7fff]
- Sets bits [17:31] of `param_1+0x2c` to iVar1, preserving low 17 bits

**Globals:** DAT_0059e5fc — scale factor

**Used by system:** docs/20-math-utilities.md — bitfield packing utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2c80 — Vector-to-Short3 Conversion

Source: unknown | Confidence: medium
Converts 3-float vector to signed 16-bit integers with clamping.

**Key logic:**
- Copies 3 floats from param_2, calls FUN_004b21f0 and FUN_004b2580 (vector transforms)
- Each component clamped to [DAT_0059e70c, DAT_0059e710] (min/max thresholds)
- If in range: `round(component * DAT_0059e708)`, else 0x8001 (below) or 0x7fff (above)
- Stores as 3 consecutive int16 at param_1+9, +0xb, +0xd
- Calls FUN_004b29f0 and FUN_004b2b90 (timing/update)

**Globals:** DAT_0059e708, DAT_0059e70c, DAT_0059e710 — conversion constants

**Calls:** FUN_004b21f0, FUN_004b2580, FUN_004b29f0, FUN_004b2b90

**Used by system:** docs/20-math-utilities.md — 3D vector quantization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b45e0 — Cleanup Registration

Source: unknown | Confidence: high
Registers LAB_004b45f0 as cleanup callback via FUN_00587b3e.

**Calls:** FUN_00587b3e (callback registration)

**Used by system:** docs/20-math-utilities.md — cleanup handler registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b72a0 — Linked List Traversal with Filter

Source: unknown | Confidence: low
Walks linked list with stride-0x10 nodes, filtering via FUN_004b50c0.

**Key logic:**
- Computes node base: `param_1 + (param_2 + 4) * 0x10`
- Walks nodes via +0x04 links
- At each node: checks `*node == 0` or calls FUN_004b50c0(param_3)
- Advances via +0x08 content pointer update
- Returns content value or 0

**Calls:** FUN_004b50c0

**Used by system:** docs/20-math-utilities.md — filtered list traversal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b9d90 — Passthrough

Source: unknown | Confidence: high
Calls FUN_004b8150(param_1).

**Calls:** FUN_004b8150

**Used by system:** docs/20-math-utilities.md — call forwarder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004ba9f0 — Linked List Destruction

Source: unknown | Confidence: high
Destroys linked list: frees content and nodes.

**Key logic:**
- Walks list at *param_1: for each node, if flagged, calls FUN_004b0170 + frees content
- Frees each node, clears list metadata (param_1[0..3]=0)

**Calls:** FUN_004b0170, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bb4f0 — Linked List Destruction with Ref-Count Loop

Source: unknown | Confidence: high
Destroys linked list with ref-count decrement loop and header-allocated objects.

**Key logic:**
- Walks list, for each node: if flagged, decrements ref count (loop), frees `*node` at -4 header offset
- Frees node and sub-object via FUN_00587bcf
- Clears list metadata

**Calls:** FUN_00587bcf (free), FUN_004b0170

**Used by system:** docs/20-math-utilities.md — ref-counted list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bd7d0 — 3-Field Init + Call

Source: unknown | Confidence: high
Zeroes 3 fields at +0x08, +0x14, +0x20, calls FUN_004bd800, returns param_1.

**Calls:** FUN_004bd800

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bfd40 — Indexed List Lookup

Source: unknown | Confidence: medium
Returns content at list index by walking linked list.

**Key logic:**
- If param_2 < param_1[3] (count): walks `param_1[2]` (iterator) by `param_2` steps via `+0x04` links
- Returns `**(int**)param_1[2]` (content pointer) or 0

**Used by system:** docs/20-math-utilities.md — indexed list access

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c29b0 — Conditional Call Wrapper

Source: unknown | Confidence: medium
If FUN_004c2850() succeeds (non-zero), calls FUN_004c11e0().

**Calls:** FUN_004c2850, FUN_004c11e0 (vehicle struct access)

**Used by system:** docs/20-math-utilities.md — conditional accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c3130 — Multi-Field Cleanup

Source: unknown | Confidence: high
Frees 7+ fields stored in param_1 array offsets via FUN_00587bcf.

**Key logic:**
- Walks linked list at param_1[0xf5] (via +0x10 links), frees sub-objects at +0x08, calls FUN_00414370, frees each node
- Frees fields at [0xf6], [0xf3], [8], [6], [4], [2], [0] in order

**Calls:** FUN_00587bcf (free), FUN_00414370

**Used by system:** docs/20-math-utilities.md — multi-field resource cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c7c70 — Passthrough

Source: unknown | Confidence: high
Calls FUN_004c81f0().

**Calls:** FUN_004c81f0

**Used by system:** docs/20-math-utilities.md — call forwarder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c88a0 — Conditional Ratio Compute

Source: unknown | Confidence: medium
If flag set and global conditions met: computes ratio of global value to param_2.

**Key logic:**
- If `*(param_1+0x10) != 0`, DAT_008ac4c8 != 0, and `*(DAT_008ac4c8+4) > 0`:
  - Sets +0x14 = 2
  - If param_2 > 0: `*(param_1+0x18) = *(DAT_008ac4c8+4) / param_2`
  - Else: `*(param_1+0x18) = DAT_007cf380`

**Globals:** DAT_008ac4c8, DAT_007cf380

**Used by system:** docs/20-math-utilities.md — conditional ratio computation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004c9600 — VTable Switch + Dtor

Source: unknown | Confidence: medium
Sets vtable, calls FUN_004c9790, switches vtable, conditionally frees self.

**Calls:** FUN_004c9790, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — destructor with vtable reassignment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004cbdd0 — Ray-Sphere Intersection

Source: unknown | Confidence: medium
Ray-sphere intersection test with position correction.

**Key logic:**
- Computes: `fVar2 = (ray_origin - param_3 * ray_dir) - (sphere_center - DAT_005d3488 * ray_dir)`
- Same for Y/Z components
- If squared distance < DAT_005d348c (radius²):
  - `fVar4 = dot(fVar2, ray_dir)`
  - `fVar2 = fVar2 - fVar4 * ray_dir` (perpendicular component)
  - If `radius² - |fVar2|² > 0`: `sqrt_val = sqrt(radius² - |fVar2|²)`
  - If sqrt_val - fVar4 > 0: moves ray origin along ray_dir by (sqrt_val - fVar4)
- Classic ray-sphere intersection: adjusts ray origin to hit point

**Globals:** DAT_005d3488, DAT_005d348c — sphere parameters

**Used by system:** docs/20-math-utilities.md — collision geometry: ray-sphere intersection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d0b00 — 3-Field Init + Call

Source: unknown | Confidence: high
Zeroes 3 fields at +0x64, +0x6c, +0x74, calls FUN_004a2220.

**Calls:** FUN_004a2220

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d4870 — Lazy Init with Callback

Source: unknown | Confidence: medium
If field at +0x04 is 0: calls PTR_FUN_005d43c4, caches result, increments ref count.

**Calls:** PTR_FUN_005d43c4 (function pointer)

**Used by system:** docs/20-math-utilities.md — lazy initialization with caching

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7a50 — String Split Loop

Source: unknown | Confidence: medium
Advances param_3 past all '&' characters (DAT_005c2aac), then formats output.

**Key logic:**
- Returns 0 if *param_1 < param_2
- Loops: `param_3 = FUN_00587c20(param_3+1, &DAT_005c2aac)` — skips separator
- Calls FUN_004d7aa0 with format string "s___12_12s_5d__005d4a38"

**Calls:** FUN_00587c20, FUN_004d7aa0

**Used by system:** docs/20-math-utilities.md — string parsing/splitting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d7ff0 — Phase-Based Audio/Particle Envelope

Source: unknown | Confidence: low
Computes envelope value based on phase with multiple threshold regions.

**Key logic:**
- Accumulates `param_1+0xc += DAT_008afe98` (phase accumulator)
- Computes wrapped phase: `fVar4 = phase - floor(phase / DAT_0059f118) * DAT_0059f118`
- If phase < DAT_0059e7e8: return (silent zone)
- Phase -= DAT_0059e7e8
- Threshold regions:
  - < DAT_0059e450: linear attack (ramp up)
  - < DAT_0059e8a4: sustain (1.0)
  - < DAT_0059e800: decay (ramp down)
  - < DAT_0059e8e4: release (ramp down)
  - < DAT_005acce8: sustain (1.0)
  - >= DAT_0059e46c: return (silent)

**Globals:** DAT_008afe98, DAT_0059f118, DAT_0059e7e8, DAT_0059e450, DAT_0059e8a4, DAT_0059e800, DAT_0059e8e4, DAT_005acce8, DAT_0059e46c

**Calls:** FUN_004d8130

**Used by system:** docs/20-math-utilities.md — audio/PWM or particle envelope generator

**Moddability:** configurable — threshold constants likely from .svm

<!-- target: docs/20-math-utilities.md -->

## FUN_004da9c0 — Division-Based Alignment

Source: unknown | Confidence: medium
Returns `((FUN_004da990() - 1) / 6) * 6`.

**Calls:** FUN_004da990

**Used by system:** docs/20-math-utilities.md — alignment/index rounding

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc290 — Fixed Node Allocator

Source: unknown | Confidence: medium
Allocates 0x10-byte node with fixed field values.

**Key logic:**
- operator_new(0x10); if failed returns null
- [1]=4, byte[2]=0, [3]=0, vtable = PTR_LAB_005ad11c

**Calls:** operator_new

**Used by system:** docs/20-math-utilities.md — fixed-struct node allocator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dcf20 — Field Setter + Call

Source: unknown | Confidence: high
Sets field at +0x1c, calls FUN_004dca80.

**Calls:** FUN_004dca80

**Used by system:** docs/20-math-utilities.md — field set + update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004de5f0 — 2-Field Init + Call

Source: unknown | Confidence: high
Zeroes +0x0c, +0x14, calls FUN_004ded20.

**Calls:** FUN_004ded20

**Used by system:** docs/20-math-utilities.md — struct init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004e2ad0 — Physics/Audio Vector Update

Source: unknown | Confidence: low
Two-pass vector update loop modifying vehicle physics arrays.

**Key logic:**
- Calls FUN_004dd550 (vector setup)
- Computes 3 weighted values from 3-component vectors
- Loop twice:
  - For each component: accumulates, applies via FUN_0054b420/FUN_0054b3b0 (vector ops)
  - Iterates iVar1 vehicles: for each, subtracts local vectors from per-vehicle float arrays (FUN_0054e120)
  - Clears bitmask at vehicle+0x14
  - Calls renderer chain: FUN_0054d520/FUN_0054e270/FUN_0054d080

**Calls:** FUN_004dd550, FUN_0054b420, FUN_0054b3b0, FUN_0054c210, FUN_0054c230, FUN_0054e100, FUN_0054e120, FUN_0054d520, FUN_0054e270, FUN_0054d080

**Used by system:** docs/20-math-utilities.md — physics vector update affecting rendered vehicles

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004effd0 — Distance Comparison

Source: unknown | Confidence: medium
Compares squared distance between two 3D positions against threshold.

**Key logic:**
- Calls FUN_004efb20 and FUN_004d1140 to get two positions
- Computes squared distance between them
- Returns 1 if < DAT_0059e46c, else 0

**Globals:** DAT_0059e46c — distance threshold

**Calls:** FUN_004efb20, FUN_004d1140

**Used by system:** docs/20-math-utilities.md — proximity check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8030 — Switch-Based Param Setting

Source: unknown | Confidence: medium
Maps input parameter to two output values via large switch table.

**Key logic:**
- Maps param_1 (0..0x2b) to *param_2/*param_3 values:
  - Most cases: *param_2=0/1, *param_3=0
  - Switch has ~40 cases grouped by behavior
- All outputs are either (1,0) or (0,0)

**Used by system:** docs/20-math-utilities.md — parameter mapping

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004f8ea0 — Frame Rate Counter Init/Reset

Source: unknown | Confidence: medium
Resets FPS counter struct: frees previous font surface, finds new "FTFRAMERATE" font.

**Key logic:**
- If param_1[6] != 0: calls FUN_00557470 + frees
- Looks up font "FTFRAMERATE" via FUN_0053d1f0 (font/surface lookup, per docs/06)
- If found: calls FUN_0053d130
- Zero-initializes 13 int fields + 2 byte fields

**Calls:** FUN_00557470, FUN_00587bcf (free), FUN_0053d1f0 (font lookup), FUN_0053d130

**Used by system:** docs/20-math-utilities.md — FPS display counter initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004fad80 — Large Struct Zero-Init with Defaults

Source: unknown | Confidence: high
Zero-initializes ~50 struct fields and sets 5 non-zero defaults.

**Key logic:**
- Zeroes fields at indices: 0x12, 0x13, 0x4c, 0,1,2,3,4,5,6,8,9,10,7,0x14,0x15,0xb,0xc,0x16,0x17,0xd,0xe,0x18,0x19,0x1c,0x1d,0x1e,0x20,0x22,0x23,0x47,0x25,0x26,0x27,0x29,0x2a,0x2b,0x43,0x44,0x45,0x2f,0x30,0x31
- Non-zero defaults:
  - [0x1f] = 0xc11cf5c3 (-9.85f)
  - [0x21] = 0x3f800000 (1.0f)
  - [0x48..0x4b] = 0xffffffff

**Used by system:** docs/20-math-utilities.md — large struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004feaa0 — Threshold-Based Return

Source: unknown | Confidence: medium
Maps float input to integer category based on thresholds.

**Key logic:**
- param_1 < DAT_005ad334 → 2
- param_1 < DAT_0059e6e8 → 3
- param_1 < DAT_005a0038 → 4
- else → 5

**Globals:** DAT_005ad334, DAT_0059e6e8, DAT_005a0038

**Used by system:** docs/20-math-utilities.md — value classification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050099c — Surface/Blit Operation

Source: unknown | Confidence: low
Complex surface blit/compositing operation with size and position validation.

**Key logic:**
- Validates input pointers (param_1, param_4 non-null required)
- If param_7&0xffff==5 or param_8!=0: direct path via FUN_00506559 + FUN_0050070d
- Else: compares param_2 vs param_5 (data comparison), param_3 vs param_6
- Uses vtable[0x20] to get dimensions
- Compares delta sizes: if mismatched → direct path
- If matched: calls vtable[0xc], FUN_00500eac(1), vtable[0x70] (blit), FUN_00500eac(0), vtable[8]

**Globals:** None directly; uses vtable dispatch

**Calls:** FUN_005064bf, FUN_00506559, FUN_0050070d, FUN_00500eac, vtable[0xc/0x20/0x70/8], thunk_FUN_005064cf

**Used by system:** docs/20-math-utilities.md — graphics surface compositing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00503888 — Function Pointer Switch

Source: unknown | Confidence: medium
Selects and calls one of two function pairs based on FUN_0050fc7d result.

**Key logic:**
- If FUN_0050fc7d() == 0: PTR_FUN_005d76c0 = FUN_00503533, PTR_FUN_005d76c4 = FUN_0050368a
- Else: PTR_FUN_005d76c0 = FUN_00503772, PTR_FUN_005d76c4 = FUN_00503772 (same function)
- Calls PTR_FUN_005d76c0()

**Calls:** FUN_0050fc7d, FUN_00503533, FUN_0050368a, FUN_00503772 (via pointer)

**Used by system:** docs/20-math-utilities.md — runtime CPU/capability dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050653e — VTable Release + Clear

Source: unknown | Confidence: high
Calls vtable[0x28] on object, then clears pointer.

**Key logic:**
- If `*param_1` non-null: calls `(*(*param_1)->vtable[0x28])(*param_1)`
- Sets `*param_1 = 0`

**Used by system:** docs/20-math-utilities.md — COM-style release wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b1d4 — Init + VTable Set

Source: unknown | Confidence: medium
Calls FUN_00507496(param_2, 0x10, 1), sets vtable to PTR_FUN_005adcbc.

**Calls:** FUN_00507496

**Used by system:** docs/20-math-utilities.md — object init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b7af — Dtor with Cleanup

Source: unknown | Confidence: high
Calls thunk_FUN_00506fd9, conditionally frees self.

**Calls:** thunk_FUN_00506fd9, FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050c48c — Lock + Function Pointer Call (6-param)

Source: unknown | Confidence: medium
Calls FUN_0050fea7(1) (lock), then dispatches through PTR_FUN_005d7894.

**Calls:** FUN_0050fea7, PTR_FUN_005d7894

**Used by system:** docs/20-math-utilities.md — thread-safe dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050d728 — Lock + Function Pointer Call (3-param)

Source: unknown | Confidence: medium
Calls FUN_0050fea7(1) (lock), then dispatches through PTR_FUN_005d7870.

**Calls:** FUN_0050fea7, PTR_FUN_005d7870

**Used by system:** docs/20-math-utilities.md — thread-safe dispatch wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050e3cd — Lock + Indirect Call

Source: unknown | Confidence: medium
Calls FUN_0050fea7(1) (lock), then indirect jmp through PTR_FUN_005d781c.

**Calls:** FUN_0050fea7, PTR_FUN_005d781c (indirect)

**Used by system:** docs/20-math-utilities.md — thread-safe dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050fd16 — CPUID 3DNow! Detection

Source: unknown | Confidence: medium
Detects 3DNow! CPU feature via CPUID extended function 0x80000001.

**Key logic:**
- Calls cpuid(0x80000000) to check if extended functions available
- If yes: calls cpuid(0x80000001), checks bit 31 of EDX (3DNow! flag)
- Returns result in param_2:local_8 pair

**Used by system:** docs/20-math-utilities.md — CPU feature detection (3DNow!)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00511f70 — Large Struct Partial Reset

Source: unknown | Confidence: medium
Resets portions of a large struct while preserving certain fields.

**Key logic:**
- Calls FUN_00513d2f for params 2 and 3 (content removal)
- Calls FUN_00517ec8 (release) for multiple field indices: 0x27, 0x37, 0x36, 0x5d, 0x5e, 0x4e
- Conditionally releases: [0x41] if bit 0x10 at +0x5d, [0x57] if bit 0x20
- If [0x51] non-null: loops 1<<(8-[0x4b]) times releasing entries
- Saves 16 dwords, zeroes 0x67 dwords, restores 16 dwords, preserves [0x10], [0x11], [0x12]

**Calls:** FUN_00513d2f, FUN_00517ec8, FUN_005179a2

**Used by system:** docs/20-math-utilities.md — large struct partial teardown

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00513b8a — Multi-Field Setter with Flag

Source: unknown | Confidence: medium
Sets multiple fields based on conditional parameters.

**Key logic:**
- If param_1 and param_2 both non-null:
  - If param_3 != 0: `*(param_2+0x30)=param_3`
  - If param_5 != 0: copies 3 values from param_5 to [0x34],[0x38],[0x3c]
  - If param_4 == 0: param_4 = 1
  - Sets bit 0x10 at param_2+8
  - Sets int16 at +0x16 = param_4

**Used by system:** docs/20-math-utilities.md — struct configuration setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005159a8 — Memory Zero-Fill

Source: unknown | Confidence: high
Zero-fills memory with dword-aligned then byte-aligned loops.

**Key logic:**
- Dword loop: writes 0 for `param_2>>2` iterations
- Byte loop: writes 0 for `param_2 & 3` remaining bytes

**Used by system:** docs/20-math-utilities.md — memory zero-fill utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00516974 — VTable Alloc + Null-Terminate

Source: unknown | Confidence: medium
Calls vtable[0] on object at param_1+4, null-terminates at +0x80.

**Used by system:** docs/20-math-utilities.md — buffer allocation + sentinel

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051923d — CRC32 Computation

Source: unknown | Confidence: high
Computes CRC32 hash using 256-entry lookup table at DAT_005affa0.

**Key logic:**
- Standard CRC32 with table-driven approach
- Unrolled 8-byte inner loop for >7 byte inputs
- Processes remaining bytes in single-byte loop
- Table at DAT_005affa0 (256 × 4 bytes = 1024 bytes)

**Globals:** DAT_005affa0 — CRC32 lookup table (1024 bytes)

**Used by system:** docs/20-math-utilities.md — CRC32 checksum

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0051cb6d — Input Binding/Config Setup

Source: unknown | Confidence: low
Sets up input device configuration with callback function pointers.

**Key logic:**
- Allocates 0x1c bytes via vtable[1], stores at param_1[0x68]
- Sets callback function based on param_1[9] and param_1[10] (input type/device)
- Supports mappings: single, dual, quad (values 1,2,4)
- Sets param_1[0x19] and param_1[0x1a] as mode/config indices
- Configures 0x54-byte stride per channel

**Calls:** vtable[1/0], FUN_0051c6be, FUN_0051c94f, FUN_0051c6e1, FUN_0051c653, FUN_0051c5a3

**Used by system:** docs/20-math-utilities.md — input device configuration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00522ce2 — 3DNow! Matrix/Vector Math

Source: unknown | Confidence: low
Large 3DNow!-accelerated matrix/vector math function (4504 bytes).

**Key logic:**
- Uses packed floating-point SIMD instructions (PackedFloatingADD, PackedFloatingMUL, etc.)
- 3DNow! technology instructions for 64-bit MMX registers
- Operates on 8-element arrays (param_1[0..7])
- Multiple computation paths based on null-ness of param_2, param_3, param_4
- Final accumulation with param_6 and/or param_7
- Calls FastExitMediaState() to exit MMX state

**Globals:** DAT_005af8e0, DAT_005af8f0, DAT_005af900, DAT_005af904 — constant tables

**Calls:** FastExitMediaState (EMMS)

**Used by system:** docs/20-math-utilities.md — 3DNow!-accelerated matrix transform

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00529af8 — Field Setter with VTable Alloc

Source: unknown | Confidence: medium
Allocates 0x1c-byte block, stores 4 field values.

**Key logic:**
- Allocates via vtable at param_5+0x20, size 0x1c
- Sets: [0]=0, byte[4]=param_1, byte[0x11]=param_2, [5]=param_3, [6]=param_4

**Used by system:** docs/20-math-utilities.md — struct field initializer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e520 — Halt/Assert Handler

Source: unknown | Confidence: high
Prints "Halting program" message and triggers debug breakpoint.

**Key logic:**
- Calls `PTR_FUN_005da714("---Halting program...")` — print/output function
- Executes `swi(3)` — software interrupt / debug breakpoint (int 3)

**Used by system:** docs/20-math-utilities.md — debug assertion failure handler

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00535550 — Passthrough

Source: unknown | Confidence: high
Calls FUN_00535390(1).

**Calls:** FUN_00535390

**Used by system:** docs/20-math-utilities.md — call forwarder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005397a0 — Checksummed Buffer Writer

Source: unknown | Confidence: medium
Writes data to buffer with 4-byte checksum per word.

**Key logic:**
- Calls FUN_00539720()
- Sets field at +0x16a7 = 8
- If param_4 != 0: writes param_3 as 4 bytes: byte0, byte1, ~byte0, ~byte1 (checksum pattern)
- Then writes param_3 bytes from param_2 sequentially
- Implements a simple checksum/validation scheme

**Used by system:** docs/20-math-utilities.md — serialization with checksum

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053b350 — Conditional Scale Apply

Source: unknown | Confidence: medium
If bit 1 of *param_1 set: clears it, applies 3 scaling factors to 9 fields.

**Key logic:**
- If `(*param_1 & 2) != 0`:
  - `*param_1 &= ~2` (clear bit)
  - Scales [10],[0xb],[0xc] by (float)[7]
  - Scales [0xe],[0xf],[0x10] by (float)[8]
  - Scales [0x12],[0x13],[0x14] by (float)[9]

**Used by system:** docs/20-math-utilities.md — conditional scaling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053c5b0 — String Relocation Copy

Source: unknown | Confidence: medium
Copies string from DAT_008b6ac8 to DAT_008b6ac8+param_2 (relocation).

**Key logic:**
- If param_2 != 0: copies bytes from source to source+param_2 until null terminator

**Used by system:** docs/20-math-utilities.md — string relocation copy

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0053d310 — Conditional Font/Surface Call

Source: unknown | Confidence: medium
Looks up font/surface, conditionally calls FUN_005531f0.

**Calls:** FUN_0053d1f0 (font/surface lookup), FUN_005531f0

**Used by system:** docs/20-math-utilities.md — conditional UI/surface operation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00540d40 — Conditional Field Setter

Source: unknown | Confidence: medium
Sets fields based on bit flags in param_2.

**Key logic:**
- If param_1 != 0:
  - If param_2 & 4: calls FUN_00540f00, stores at +0x20
  - If param_2 & 8: calls FUN_00541090, stores at +0x28

**Calls:** FUN_00540f00, FUN_00541090

**Used by system:** docs/20-math-utilities.md — conditional update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00542520 — Double-Field Getter

Source: unknown | Confidence: high
Returns fields at +0x04 and +0x08 via output pointers.

**Used by system:** docs/20-math-utilities.md — accessor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005458d0 — Flag Bit Setter (3-state)

Source: unknown | Confidence: medium
Sets bits at param_1+0xec based on 3-state input (0/1/2).

**Key logic:**
- param_2==0: clears bits 21-22
- param_2==1: sets bit 21 (0x200000)
- param_2==2: sets bit 22 (0x400000)

**Used by system:** docs/20-math-utilities.md — 3-state flag control

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00547280 — Dual Field Setter by Key

Source: unknown | Confidence: medium
Sets field at +0x8c (if param_3==0x1000) or +0x90 (if param_3==0x2000).

**Used by system:** docs/20-math-utilities.md — keyed field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005489a0 — Linked List Node Append

Source: unknown | Confidence: medium
Allocates and appends node to linked list.

**Key logic:**
- Allocates 0x18 bytes, calls FUN_0053ab20(0x400, param_2)
- If list head at +0x2c non-null: walks to tail via +0x14, appends
- Else: sets head to new node

**Calls:** operator_new, FUN_0053ab20

**Used by system:** docs/20-math-utilities.md — list append

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054a200 — Global Flag Set/Clear

Source: unknown | Confidence: medium
Sets or clears bits in DAT_008b8e34.

**Globals:** DAT_008b8e34 — global flag bitfield

**Used by system:** docs/20-math-utilities.md — global flag management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054c190 — Bit Clear

Source: unknown | Confidence: high
Clears bits 0-2 at param_1+0x3c (`&= 0xfffffff9`).

**Used by system:** docs/20-math-utilities.md — flag clear

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054fc80 — Dual Field Setter

Source: unknown | Confidence: high
Sets +0x70=param_2, +0x74=param_3.

**Used by system:** docs/20-math-utilities.md — field setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005545e0 — Setter with Notification

Source: unknown | Confidence: medium
Sets field [0xb] if param_2 differs, notifies via global callback.

**Key logic:**
- If param_2 != -1 and param_2 != param_1[0xb]:
  - Calls `(*DAT_008b89a0)->vtable[0xfc](DAT_008b89a0, *param_1, 0xb, param_2)`
  - Updates param_1[0xb] = param_2

**Globals:** DAT_008b89a0 — notification/observer object

**Used by system:** docs/20-math-utilities.md — property setter with change notification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00559fb0 — PRNG — 4 Uniform Floats from Seed

Source: unknown | Confidence: medium
Generates up to 4 uniform random floats in [0,1) using FUN_0058b077.

**Key logic:**
- Calls FUN_00559d80(param_2) for validation
- Uses `param_1[0x30c] + 1` as seed
- For each non-null output pointer: calls FUN_0058b077 (PRNG step) to generate float

**Calls:** FUN_00559d80, FUN_0058b077 (PRNG)

**Used by system:** docs/20-math-utilities.md — uniform random float generator

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00560f10 — Doubly-Linked List Node Unlink

Source: unknown | Confidence: high
Unlinks a node from a doubly-linked list.

**Key logic:**
- If node+0x30 (prev) non-null: sets prev->+0x34 = node->+0x34 (next)
- If node+0x34 (next) non-null: sets next->+0x30 = node->+0x30 (prev)
- If list head at param_1+0x2c == node: updates head to node->+0x34

**Used by system:** docs/20-math-utilities.md — doubly-linked list removal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00564a20 — Buffer Index Computation

Source: unknown | Confidence: medium
Computes index into a buffer based on position, size, and stride.

**Key logic:**
- If param_1 non-null: computes index as `(remaining - param_1[5]) / param_1[2]`
- Calls FUN_005648b0 and FUN_00564ab0 (or FUN_00564b10 if param_4 != 0)
- Returns index or -1

**Calls:** FUN_005648b0, FUN_00564ab0/FUN_00564b10

**Used by system:** docs/20-math-utilities.md — buffer position calculation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00567d00 — String Hash

Source: unknown | Confidence: medium
Computes string hash via weighted character sum modulo 9.

**Key logic:**
- Returns -1 if param_1 null
- Computes string length
- If length > 0: extracts characters at positions 0, length/6, length/2, length-2
- Computes weighted sum with constants (0x2771, 0x3b1, 10, etc.) modulo 9
- Returns hash value 0-8

**Used by system:** docs/20-math-utilities.md — simple string hash for bucketing

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a680 — COM VTable Call via +0x60

Source: unknown | Confidence: medium
Indirect jump through vtable slot 0x60.

**Key logic:**
- Calls `(**(**(param_1)->vtable + 0x60))()`
- Ghidra cannot recover jumptable

**Used by system:** docs/20-math-utilities.md — COM interface dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057ef20 — SEH-Wrapped Constructor

Source: unknown | Confidence: medium
Allocates 0x20 bytes under SEH protection, calls constructor.

**Key logic:**
- Installs SEH handler (LAB_0059ca1b)
- operator_new(0x20)
- If success: calls FUN_0057b780(0,0,0)
- Restores SEH chain before return

**Calls:** operator_new, FUN_0057b780

**Used by system:** docs/20-math-utilities.md — SEH-safe object construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585e60 — Cleanup Registration

Source: unknown | Confidence: high
Registers LAB_00585e70 via FUN_00587b3e.

**Calls:** FUN_00587b3e (callback registration)

**Used by system:** docs/20-math-utilities.md — cleanup handler registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005876d0 — Cleanup Registration

Source: unknown | Confidence: high
Registers LAB_005876e0 via FUN_00587b3e.

**Calls:** FUN_00587b3e (callback registration)

**Used by system:** docs/20-math-utilities.md — cleanup handler registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00589278 — Call Wrapper with 0

Source: unknown | Confidence: high
Calls FUN_0058928f(param_1, param_2, param_3, 0).

**Calls:** FUN_0058928f

**Used by system:** docs/20-math-utilities.md — call forwarder

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058babb — String Write to File

Source: unknown | Confidence: medium
Writes string to file via stream lock/write/unlock wrappers.

**Key logic:**
- strlen(param_1)
- Locks stream (FUN_0058c1b1), gets stream (FUN_0058e41b)
- Writes via FUN_005886a7
- Cleans up (FUN_0058e4a8), unlocks (FUN_0058c203)
- Returns 0 on success, -1 on failure (length mismatch)

**Calls:** _strlen, FUN_0058c1b1 (lock), FUN_0058e41b (stream), FUN_005886a7 (write), FUN_0058e4a8 (cleanup), FUN_0058c203 (unlock)

**Used by system:** docs/20-math-utilities.md — file string write

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059168f — Conditional Math with DAT_005e9ad0 Flag

Source: unknown | Confidence: low
Mathematical function with conditional branch on global flag.

**Key logic:**
- Calls FUN_005919da, which if fails calls FUN_00591727
- Calls FUN_00591cc6 for index/result
- If DAT_005e9ad0 == 0 and result != 0: calls FUN_00591bf1 (computation path)
- Else: calls FUN_00591c79 + FUN_00591e66 (fallback path)

**Globals:** DAT_005e9ad0 — flag controlling algorithm path

**Calls:** FUN_005919da, FUN_00591727, FUN_00591cc6, FUN_00591bf1, FUN_00591c79, FUN_00591e66

**Used by system:** docs/20-math-utilities.md — conditional math algorithm

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00596bf3 — Base-10 Negative Special Case

Source: unknown | Confidence: medium
Conversion helper — special-cases param_3==10 and param_1<0.

**Key logic:**
- If param_3 == 10 and param_1 < 0: sets flag = 1
- Calls FUN_00596c20(param_1, param_2, param_3, flag)
- Returns param_2

**Calls:** FUN_00596c20

**Used by system:** docs/20-math-utilities.md — number conversion utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598e2e — VTable Init Only

Source: unknown | Confidence: high
Sets `*param_1 = &PTR_FUN_005b9bcc`.

**Used by system:** docs/20-math-utilities.md — vtable assignment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a3f3 — Pointer Adjustment

Source: unknown | Confidence: medium
Adjusts values through two levels of indirection.

**Key logic:**
- `**(param_1+0x2c) -= param_2`
- `**(param_1+0x1c) += param_2 * 2`

**Used by system:** docs/20-math-utilities.md — pointer-based counter adjustment

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c4f0 — SEH Unwind Free at -0x30

Source: unknown | Confidence: high
SEH unwind handler: frees object at EBP-0x30.

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cb00 — SEH Unwind → FUN_005870d0

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_005870d0 (vtable init function).

**Calls:** FUN_005870d0

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d130 — SEH Unwind → FUN_00585fb0

Source: unknown | Confidence: high
SEH unwind handler: calls FUN_00585fb0 (unknown cleanup).

**Calls:** FUN_00585fb0

**Used by system:** docs/20-math-utilities.md — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059db88 — Call Wrapper

Source: unknown | Confidence: high
Calls FUN_004a1367().

**Calls:** FUN_004a1367

**Used by system:** docs/20-math-utilities.md — call forwarder

**Moddability:** hardcoded

## FUN_00406AB0 — Generic Object Constructor with VTable

Source: unknown | Confidence: high
Zero-initializes 18 dword fields, sets vtable pointer, stores default constants.

**Key logic:**
- Zeroes fields at indices [2]–[0x11] (dwords) = 16 fields
- Sets vtable: `*param_1 = &PTR_FUN_0059e530`
- Sets `param_1[1] = 1` (counter or ID, default to 1)
- Sets `param_1[0x15] = 2` (mode or type selector)
- Sets `param_1[0x23] = 0x3f800000` = 1.0f (float default)
- Calls `FUN_004072e0(0)` — Miles Sound System sample allocator init (docs/21)
- Returns `param_1`

**Calls:** FUN_004072e0 (MSS sample allocator init, docs/21)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004081e0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040a610 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

```


<!-- target: docs/20-math-utilities.md -->

## FUN_0040dbe0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040ebd0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00410b40 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004141f0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004184b0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0041b970 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421470 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00421ab0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004263eb -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00458020 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_0045e570 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004615c0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004623e0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00463d50 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00464bb0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00466160 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004685b0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0046b5c0 -- Destructor with Conditional Free

Source: unknown | Confidence: medium
Calls cleanup; frees memory if flag set.

**Key logic:**
- Calls cleanup; frees memory if flag set.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

```


<!-- target: docs/20-math-utilities.md -->

## FUN_00470230 — Constructor with Bulk Init and VTable

Source: unknown | Confidence: high
Calls bulk initialization then sets vtable pointer.

**Key logic:**
- `FUN_0048b420(0, 0, 0, 0, 1, 0)` — bulk zero-init with flag=1 (docs/20)
- Sets vtable: `*param_1 = &PTR_FUN_005a0250`
- Returns `param_1`

**Calls:** FUN_0048b420 (bulk init with string copy, docs/20)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00475140 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00478bc0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00479970 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047A210 � Constructor with Parent Init and VTable

Source: unknown | Confidence: high
Calls parent initializer, sets vtable, clears enable flag.

**Key logic:**
- Calls FUN_004668e0(0, 0x3f800000) � parent init with (0, 1.0f) (docs/20)
- Sets vtable: *param_1 = &PTR_FUN_005a6068
- Clears byte at param_1 + 0x40 (offset +0x100 byte) � disable flag
- Returns param_1

**Calls:** FUN_004668e0 (Init + VTable Set, docs/20)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0047bd90 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

<!-- target: docs/20-math-utilities.md -->


<!-- target: docs/20-math-utilities.md -->

## FUN_004856f0 -- Object Constructor

Source: unknown | Confidence: medium
Allocates or initializes object with vtable and defaults.

**Key logic:**
- Allocates or initializes object with vtable and defaults.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486400 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487160 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00487e10 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00489440 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048b7e0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048d1a0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048e360 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0048fc10 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004903f0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491710 -- Object Constructor

Source: unknown | Confidence: medium
Allocates or initializes object with vtable and defaults.

**Key logic:**
- Allocates or initializes object with vtable and defaults.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491e80 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

```


<!-- target: docs/20-math-utilities.md -->

## FUN_00495B60 � 4-Iteration Data Processing with Conditional Copy

Source: unknown | Confidence: high
Iterates 4 entries (stride 0xc), conditionally processes each, packs valid entries via copy when iteration count lags behind valid count.

**Key logic:**
- Base pointer at param_1 + 0x15fc
- Loop 4 times (iVar4 = 0..3):
  - FUN_00499a20(param_1[0xc0]) � float field decrement using context (docs/20)
  - FUN_00499a50() � float threshold check (docs/20)
  - If threshold check returns non-zero (valid entry):
    - If iVar2 != iVar4 (gap in valid entries detected):
      - FUN_00499a70(iVar3) � copy data entry (docs/19)
      - FUN_00499a00() � init source struct (docs/19)
    - iVar2++ � increment valid count
  - iVar3 += 0xc � advance to next entry (stride 12 bytes)
- After loop: valid entries are packed sequentially at the front

**Calls:** FUN_00499a20 (float field decrement, docs/20), FUN_00499a50 (float threshold check, docs/20), FUN_00499a70 (data entry copy, docs/19), FUN_00499a00 (small struct init, docs/19)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497890 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00498940 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004991e0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004999E0 � Iterator/Index Initializer

Source: unknown | Confidence: high
Initializes a small object: zeroes first field, sets second to -1, calls struct init.

**Key logic:**
- *param_1 = 0 � first field zeroed
- param_1[1] = 0xffffffff � second field set to -1 (end/invalid marker)
- FUN_00499a00() � small struct init (docs/19)
- Returns param_1

**Calls:** FUN_00499a00 (small struct init, docs/19)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00499e30 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049a2e0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049adc0 -- Object Constructor

Source: unknown | Confidence: medium
Allocates or initializes object with vtable and defaults.

**Key logic:**
- Allocates or initializes object with vtable and defaults.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0049f150 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004a1fb0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a4000 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a7010 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b1a10 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2480 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b2b10 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b41c0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004b50c0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

## FUN_00598c88 — Refcount Decrement with Lock

Source: unknown | Confidence: high
Thread-safe refcount decrement. Locks, decrements refcount at param_1+4 if non-zero/non-negative, unlocks, returns param_1 if still alive or 0 if dead.

**Key logic:**
- Calls FUN_0059a54d() — enter critical section (lock)
- Reads refcount at `*(int*)(param_1 + 4)`
- If refcount != 0 and != -1: decrements by 1
- Reads refcount again (post-decrement)
- Calls FUN_0059a5e9() — leave critical section (unlock)
- Returns param_1 if refcount is now 0 (object alive), else returns 0 (object dead)
- Uses `~-(uint)(iVar1 != 0) & param_1` — returns param_1 if iVar1==0, else 0

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | unknown | pointer | Object pointer being refcounted |
| +0x04 | RefCount | int | Reference count; decremented if >0; -1 = special "never release" sentinel |

**Globals:** none

**Calls:**
- FUN_0059a54d — critical section enter/lock (docs/20)
- FUN_0059a5e9 — critical section leave/unlock (docs/20)

**Used by system:** docs/20-math-utilities — thread-safe refcounting utility

**Algorithm family:** refcount / critical section

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c45a — SEH Unwind: Free Object at EBP-0x30

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored on the stack frame during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x30)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper
- Standard MSVC SEH unwind pattern

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c4b4 — SEH Unwind: Free Object at EBP-0x14

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored on the stack frame during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x14)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper
- Standard MSVC SEH unwind pattern

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c5b2 — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored at EBP+8 during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer from caller's stack frame
- Calls FUN_00587bcf() — heap memory free wrapper
- Standard MSVC SEH unwind pattern using positive EBP offset (parameter slot)

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c5f8 — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored at EBP+8 during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer from caller's stack frame
- Calls FUN_00587bcf() — heap memory free wrapper
- Identical pattern to Unwind_0059c5b2 — different source location in binary, same logic

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c616 — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored at EBP+8 during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer from caller's stack frame
- Calls FUN_00587bcf() — heap memory free wrapper
- Identical pattern to adjacent unwind handlers

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c65c — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored at EBP+8 during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer from caller's stack frame
- Calls FUN_00587bcf() — heap memory free wrapper
- Identical pattern to adjacent unwind handlers

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c68e — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored at EBP+8 during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer from caller's stack frame
- Calls FUN_00587bcf() — heap memory free wrapper
- Identical pattern to other EBP+8 unwind handlers in this address range

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c7d0 — SEH Unwind: Call FUN_00583ae0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling list destruction function during exception propagation.

**Key logic:**
- Calls FUN_00583ae0() — linked list destruction with CloseHandle and memory free
- Standard MSVC SEH cleanup pattern for objects containing linked lists

**Globals:** none

**Calls:**
- FUN_00583ae0 — linked list destroy with CloseHandle (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c804 — SEH Unwind: Call FUN_00581820 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked list destroy during exception propagation.

**Key logic:**
- Calls FUN_00581820() — linked list destruction with CloseHandle (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00581820 — linked list destroy + CloseHandle (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c8e6 — SEH Unwind: Call FUN_00499ae0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling global cleanup function during exception propagation.

**Key logic:**
- Calls FUN_00499ae0() — free if non-null / global cleanup utility (docs/20)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00499ae0 — free if non-null / global cleanup (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c92c — SEH Unwind: Call FUN_00581ad0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling close handle + list destroy during exception propagation.

**Key logic:**
- Calls FUN_00581ad0() — close handle, destroy linked list, free nodes
- Same pattern as Unwind_0059c846

**Globals:** none

**Calls:**
- FUN_00581ad0 — close handle + destroy linked list + free nodes (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c988 — SEH Unwind: Call FUN_005822b0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked-list free during exception propagation.

**Key logic:**
- Calls FUN_005822b0() — standard linked-list free (docs/20)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_005822b0 — linked-list free standard (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ca50 — SEH Unwind: Free Object at EBP-0x114

Source: unknown | Confidence: high
SEH unwind handler freeing a large stack-local allocation during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x114)` — stack-local object pointer (276 bytes below EBP)
- Calls FUN_00587bcf() — heap memory free wrapper
- Larger negative EBP offset suggests a bigger local object or buffer on the stack

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cc6b — SEH Unwind: Free Object at EBP-0x10

Source: unknown | Confidence: high
SEH unwind handler freeing a stack-local object during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x10)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cd13 — SEH Unwind: Free Object at EBP-0x18

Source: unknown | Confidence: high
SEH unwind handler freeing a stack-local object during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x18)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cf21 — SEH Unwind: Call FUN_00586170 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling handle close + linked list cleanup during exception propagation.

**Key logic:**
- Calls FUN_00586170() — handle close & linked list cleanup (docs/01)
- Same target as Unwind_0059cedf

**Globals:** none

**Calls:**
- FUN_00586170 — handle close & linked list cleanup (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cfa2 — SEH Unwind: Call FUN_00586070 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling CloseHandle wrapper during exception propagation.

**Key logic:**
- Calls FUN_00586070() — CloseHandle wrapper (docs/21)
- Standard MSVC SEH cleanup for objects with handle resources

**Globals:** none

**Calls:**
- FUN_00586070 — CloseHandle wrapper (docs/21)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cfcc — SEH Unwind: Call FUN_00586170 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling handle close + linked list cleanup during exception propagation.

**Key logic:**
- Calls FUN_00586170() — handle close & linked list cleanup (docs/01)
- Same target as Unwind_0059cedf and Unwind_0059cf21

**Globals:** none

**Calls:**
- FUN_00586170 — handle close & linked list cleanup (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d02e — SEH Unwind: Call FUN_005833e0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked list walk + destructor + free during exception propagation.

**Key logic:**
- Calls FUN_005833e0() — walk linked list, call destructor, free nodes (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_005833e0 — walk linked list, call destructor, free nodes (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d070 — SEH Unwind: Call FUN_0047aa60 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling empty stub / small destructor during exception propagation.

**Key logic:**
- Calls FUN_0047aa60() — empty stub / no-op / small array destructor
- Same pattern as Unwind_0059caa0

**Globals:** none

**Calls:**
- FUN_0047aa60 — empty stub / small destructor / no-op (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d1d8 — SEH Unwind: Call FUN_00599796 with DAT_008d42a0

Source: unknown | Confidence: high
SEH unwind handler calling locale refcount release / no-op stub with a global context descriptor during exception propagation.

**Key logic:**
- Calls FUN_00599796(*(stack-0x10), &DAT_008d42a0) — cleanup with global context descriptor
- FUN_00599796 is an empty stub / no-op (likely stripped locale refcount release)
- DAT_008d42a0 is a static type descriptor used in MSVC EH tables

**Globals:**
- `DAT_008d42a0` — static type descriptor used in MSVC exception handling data

**Calls:**
- FUN_00599796 — empty stub / locale refcount release (no-op, docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d348 — SEH Unwind: Call FUN_00599796 with DAT_008d4568

Source: unknown | Confidence: high
SEH unwind handler calling locale refcount release / no-op stub with a global context descriptor during exception propagation.

**Key logic:**
- Calls FUN_00599796(*(stack-0x10), &DAT_008d4568) — cleanup with global context descriptor
- Same pattern as Unwind_0059d1d8 but different DAT_ descriptor

**Globals:**
- `DAT_008d4568` — static type descriptor used in MSVC exception handling data

**Calls:**
- FUN_00599796 — empty stub / locale refcount release (no-op, docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d45c — SEH Unwind: Call FUN_0059a9c2 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling single function call wrapper during exception propagation.

**Key logic:**
- Calls FUN_0059a9c2() — single function call wrapper (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_0059a9c2 — single function call wrapper (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d4e0 — SEH Unwind: Free Object at EBP-0x14

Source: unknown | Confidence: high
SEH unwind handler freeing a stack-local object during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x14)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d51c — SEH Unwind: Call FUN_0059ac3f Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling vtable pointer setter / constructor helper during exception propagation.

**Key logic:**
- Calls FUN_0059ac3f() — vtable pointer setter / constructor helper (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_0059ac3f — vtable pointer setter / constructor helper (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d580 — SEH Unwind: Destroy exception Object

Source: unknown | Confidence: high
SEH unwind handler that explicitly calls the C++ exception destructor during stack unwinding.

**Key logic:**
- Reads `exception**` from `(unaff_EBP + -0x10)` — pointer to exception object on stack
- Calls `exception::~exception()` — explicit MSVC exception object destructor
- Standard MSVC EH pattern for destroying exception objects during stack unwinding when an exception propagates past a catch point

**Globals:** none

**Calls:**
- `exception::~exception` — MSVC C++ exception destructor

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004047d0 — Counted Loop Call to Element Update

Source: unknown | Confidence: high
Iterates a counter at param_1+0x130 times, calling FUN_004fb2e0 (vehicle closest-approach distance) each iteration.

**Key logic:**
- Reads count from `*(int*)(param_1 + 0x130)`
- If count > 0: loops 0..count-1, calling FUN_004fb2e0() each iteration
- Each call likely updates a proximity/contact element for collision detection

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x130 | ElementCount | int | Number of elements to process |

**Globals:** none

**Calls:**
- FUN_004fb2e0 — vehicle closest-approach distance (docs/17)

**Used by system:** docs/20-math-utilities — physics collision proximity update loop

**Algorithm family:** counted iteration / batch update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00534ae6 — Import Trampoline

Source: AVIFile (Windows API) | Confidence: high
Import trampoline for the Windows AVIFileRelease function from avifil32.dll.

**Key logic:**
- Indirect jump via IAT to AVIFileRelease from avifil32.dll
- No local logic — pure import trampoline generated by the linker for delay-load or bound import
- Ghidra could not recover the jump table; function is a single indirect jump instruction

**Globals:** none

**Calls:** none (indirect jump to system DLL)

**Used by system:** docs/20-math-utilities — Windows API import trampoline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005888a6 — MSVCRT SEH Frame Unwinder

Source: MSVCRT library function | Confidence: high
Standard MSVC C Runtime library function that unwinds exception handler frames during SEH propagation.

**Key logic:**
- Library function: `__local_unwind2` from Visual Studio C Runtime (matches 1998–2003 versions)
- Iterates through SEH handler registration table at param_1+8
- For each handler: checks if its index (param_2) matches the unwind target
- If match found (or sentinel -1 reached): stops
- Otherwise: reads handler address from table (iVar1 + iVar2 * 0xc + 8), calls it if flag byte (iVar1 + 4 + iVar2 * 0xc) is zero
- Calls FUN_0058893a(0x101) before invoking non-null handlers (likely debug/trace breakpoint)
- Updates current handler index at param_1+0xc to track position

**Globals:** none

**Calls:**
- FUN_0058893a — debug breakpoint / trace utility (called with constant 0x101)

**Used by system:** docs/20-math-utilities — MSVC CRT SEH infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599d31 — MSVC streambuf uflow

Source: MSVC standard library | Confidence: high
MSVC `std::basic_streambuf<unsigned short>::uflow()` implementation — reads next character from input buffer.

**Key logic:**
- Library function from Visual Studio 2003 Release
- Calls virtual function at vtable offset +0x10 via `(**(code**)(*param_1 + 0x10))()` — typically `underflow`
- If result == -1 (EOF): returns 0xffff
- Otherwise: returns character from `Gninc()` pointer (increment get pointer)

**Globals:** none

**Calls:**
- Virtual function at vtable+0x10 — `underflow()` (streambuf virtual method)
- Gninc — streambuf get pointer increment utility

**Used by system:** docs/20-math-utilities — MSVC C++ standard library

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c552 — SEH Unwind: Free Object at EBP-0x10

Source: unknown | Confidence: high
SEH unwind handler freeing a stack-local object during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x10)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c684 — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler freeing object at EBP+8 during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer from caller's stack frame
- Calls FUN_00587bcf() — heap memory free wrapper

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c7fc — SEH Unwind: Call FUN_005822b0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked-list free during exception propagation.

**Key logic:**
- Calls FUN_005822b0() — standard linked-list free (docs/20)

**Globals:** none

**Calls:**
- FUN_005822b0 — linked-list free standard (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c93a — SEH Unwind: Call FUN_00581750 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling handle close with cleanup during exception propagation.

**Key logic:**
- Calls FUN_00581750() — handle close with cleanup (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00581750 — handle close with cleanup (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cb68 — SEH Unwind: Call FUN_005833e0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked list walk + destructor + free during exception propagation.

**Key logic:**
- Calls FUN_005833e0() — walk linked list, call destructor, free nodes (docs/01)

**Globals:** none

**Calls:**
- FUN_005833e0 — walk linked list, call destructor, free nodes (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cd1e — SEH Unwind: Free Object at EBP-0x10

Source: unknown | Confidence: high
SEH unwind handler freeing a stack-local object during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x10)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cef5 — SEH Unwind: Call FUN_00586170 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling handle close + linked list cleanup during exception propagation.

**Key logic:**
- Calls FUN_00586170() — handle close & linked list cleanup (docs/01)

**Globals:** none

**Calls:**
- FUN_00586170 — handle close & linked list cleanup (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d020 — SEH Unwind: Call FUN_00586210 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling CloseHandle + cleanup during exception propagation.

**Key logic:**
- Calls FUN_00586210() — CloseHandle + cleanup (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00586210 — CloseHandle + cleanup (docs/01)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d1c8 — SEH Unwind: Call FUN_00599796 with DAT_008d4330

Source: unknown | Confidence: high
SEH unwind handler calling locale refcount release / no-op stub with a global context descriptor during exception propagation.

**Key logic:**
- Calls FUN_00599796(*(stack-0x10), &DAT_008d4330) — cleanup with global context descriptor
- Same pattern as Unwind_0059d1d8 and Unwind_0059d348 but different DAT_ descriptor

**Globals:**
- `DAT_008d4330` — static type descriptor used in MSVC exception handling data

**Calls:**
- FUN_00599796 — empty stub / locale refcount release (no-op, docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d41f — SEH Unwind: Call FUN_00599d17 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling vtable pointer init during exception propagation.

**Key logic:**
- Calls FUN_00599d17() — vtable pointer init (docs/20)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00599d17 — vtable pointer init (docs/20)

**Used by system:** docs/20-math-utilities — MSVC SEH exception handling

**Moddability:** hardcoded

## FUN_0058c07f -- __cfltcvt: CRT Float Conversion Dispatch

Source: MSVCRT (Visual Studio 2003 Release) | Confidence: high
MSVC CRT float-to-string conversion dispatcher. Entry point for `__cfltcvt`. Selects format-specific conversion routine based on `sizeInBytes` format code.

**Key logic:**
- If `sizeInBytes == 0x65` ('e') or `0x45` ('E'): calls FUN_0058bdcd(arg, buffer, format, precision) -- scientific notation
- If `sizeInBytes == 0x66` ('f'): calls FUN_0058bef0(arg, buffer, format) -- fixed-point
- Otherwise (default): calls FUN_0058bfec(arg, buffer, format, precision) -- general/number
- Returns errno_t result from dispatched function

**Calls:**
- FUN_0058bdcd -- Float-to-string with sign/width (docs/20-math-utilities.md)
- FUN_0058bef0 -- Int-to-string with sign + position draw (docs/20-math-utilities.md)
- FUN_0058bfec -- Number-to-string with truncation (docs/20-math-utilities.md)

**Used by system:** docs/20-math-utilities.md -- MSVC CRT float formatting

**Algorithm family:** CRT string conversion dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005995e5 -- Conditional String Free with Length Check

Source: unknown | Confidence: high
Pre-modify buffer check -- conditionally frees a string buffer based on length prefix validity before writing new data.

**Key logic:**
- Reads string pointer from `*(char **)(param_1 + 4)`
- Checks pointer is non-null
- Checks `Str[-1]` (length prefix byte) is non-null and not -1 (valid length)
- If all checks pass: calls FUN_005993af(1) (refcount decrement), computes `_strlen(_Str)`, then calls FUN_00599615(_Str, length) (buffer write with null-terminate)
- Otherwise: skips free -- no-op

**Calls:**
- FUN_005993af(1) -- Reference count decrement with conditional free (docs/20-math-utilities.md)
- `_strlen` -- MSVC CRT string length
- FUN_00599615 -- Buffer write with null-terminate (docs/01-engine-architecture.md)

**Used by system:** docs/01-engine-architecture.md -- pre-modify buffer check referenced at line 10475

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cb60 -- SEH Unwind: Call FUN_00583360

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00583360 for linked list cleanup during exception unwinding.

**Key logic:**
- Calls FUN_00583360() -- linked list destructor chain
- No parameters, no return value
- SEH unwind cleanup action: releases linked list resources when exception propagates

**Calls:**
- FUN_00583360 -- Linked list destructor chain (docs/20-math-utilities.md)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind / data structure cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d5bc -- SEH Unwind: Exception Destructor

Source: unknown | Confidence: high
SEH unwind handler -- destructs an exception object during stack unwinding.

**Key logic:**
- Reads exception pointer from `*(exception **)(unaff_EBP + -0x10)` (stack frame local)
- Calls `exception::~exception()` on the object
- SEH unwind cleanup action: ensures exception object is properly destroyed when exception propagates through this frame

**Calls:**
- exception::~exception -- MSVC exception destructor

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind / exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005679a0 -- Null-Check Wrapper

Source: unknown | Confidence: high
Null-check wrapper: returns 0 if param_1 is null, otherwise delegates to FUN_005679a5.

**Key logic:**
- If `param_1 == 0`: return 0 immediately
- Else: calls FUN_005679a5() and returns its result
- __fastcall convention (param_1 in ECX)

**Calls:**
- FUN_005679a5 -- List traversal with early exit (docs/20-math-utilities.md)

**Used by system:** docs/20-math-utilities.md -- null-safe list traversal wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c40a -- SEH Unwind: Free Field at -0x5C

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x5C during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x5C)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded


<!-- target: docs/20-math-utilities.md -->

## FUN_0059c478 -- SEH Unwind: Free Field at -0x2C

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x2C during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x2C)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c518 -- SEH Unwind: Free Field at -0x40

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x40 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x40)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c56e -- SEH Unwind: Free Field at -0x10

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x10 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x10)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c6f2 -- SEH Unwind: Free Object at +8

Source: unknown | Confidence: high
SEH unwind handler -- frees an object at stack offset EBP+8 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + 8)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059c7d8 -- SEH Unwind: Call FUN_0057bc70

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_0057bc70 (single vtable pointer set) during exception unwinding.

**Key logic:**
- Calls FUN_0057bc70() -- single vtable pointer set / node destructor (docs/01-engine-architecture.md)

**Calls:** FUN_0057bc70 -- Single vtable pointer set (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c902 -- SEH Unwind: Call FUN_005818e0

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_005818e0 (list destruction with handle close) during exception unwinding.

**Key logic:**
- Calls FUN_005818e0() -- list destruction with handle close (docs/01-engine-architecture.md)

**Calls:** FUN_005818e0 -- List destruction with handle close (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded


<!-- target: docs/20-math-utilities.md -->

## FUN_0059c948 -- SEH Unwind: Call FUN_00581b30

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00581b30 (cleanup callback dispatch) during exception unwinding.

**Key logic:**
- Calls FUN_00581b30() -- cleanup callback dispatch (docs/20-math-utilities.md)

**Calls:** FUN_00581b30 -- Cleanup callback dispatch (docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cc40 -- SEH Unwind: Call FUN_00583570

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00583570 (list destruction with COM release) during exception unwinding.

**Key logic:**
- Calls FUN_00583570() -- list destruction with COM release (docs/01-engine-architecture.md)

**Calls:** FUN_00583570 -- List destruction with COM release (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059cceb -- SEH Unwind: Free Field at -0x10

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x10 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x10)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cead -- SEH Unwind: Call FUN_00586070

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00586070 (CloseHandle wrapper) during exception unwinding.

**Key logic:**
- Calls FUN_00586070() -- CloseHandle wrapper (docs/21-audio-network-internals.md)

**Calls:** FUN_00586070 -- CloseHandle wrapper (docs/21)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind / handle cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ceed -- SEH Unwind: Call FUN_005833e0

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_005833e0 (walk linked list, call destructor, free nodes) during exception unwinding.

**Key logic:**
- Calls FUN_005833e0() -- walk linked list, call destructor, free nodes (docs/01-engine-architecture.md)

**Calls:** FUN_005833e0 -- Walk list, call destructor, free nodes (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d0eb -- SEH Unwind: Call FUN_00581880

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00581880 (linked list destruction with vtable release) during exception unwinding.

**Key logic:**
- Calls FUN_00581880() -- linked list destruction with vtable release (docs/01-engine-architecture.md)

**Calls:** FUN_00581880 -- Linked list destruction with vtable release (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059d190 -- SEH Unwind: Call FUN_00499ae0

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00499ae0 (free if non-null / object teardown) during exception unwinding.

**Key logic:**
- Calls FUN_00499ae0() -- free if non-null / object teardown (docs/20-math-utilities.md)

**Calls:** FUN_00499ae0 -- Free if non-null / object teardown (docs/20)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind / object cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d368 -- SEH Unwind: Call FUN_00599796 (Cleanup with Descriptor)

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00599796 with a stack-local pointer and global type descriptor DAT_008d4440 during exception unwinding.

**Key logic:**
- Reads object pointer from *(unaff_EBP + -0x10)
- Calls FUN_00599796(object_ptr, &DAT_008d4440) -- cleanup with type descriptor pair

**Calls:**
- FUN_00599796 -- Cleanup with type descriptor / empty stub (docs/20-math-utilities.md)
- DAT_008d4440 -- Global type descriptor

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind / locale cleanup

**Moddability:** hardcoded


<!-- target: docs/20-math-utilities.md -->

## FUN_0059d414 -- SEH Unwind: Call FUN_00598c70

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00598c70 (null check with virtual dispatch) during exception unwinding.

**Key logic:**
- Calls FUN_00598c70() -- null check with virtual dispatch / init helper (docs/01-engine-architecture.md)

**Calls:** FUN_00598c70 -- Null check with virtual dispatch (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004203d0 -- Thunk to FUN_004201e0

Source: unknown | Confidence: high
Trampoline -- unconditional jmp to FUN_004201e0. No local logic.

**Key logic:**
- Single jmp instruction; address appears in a vtable, IAT, or call stub
- Call target: FUN_004201e0 (track format ID lookup, docs/08-file-formats.md)

**Calls:** FUN_004201e0 -- Track format ID lookup (docs/08)

**Used by system:** docs/08-file-formats.md -- track file format identification

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050cba3 -- Pre-Dispatch Wrapper (Matrix Operation)

Source: unknown | Confidence: high
Short wrapper -- calls FUN_0050fea7(1) then dispatches through a global function pointer (PTR_FUN_005d77d4).

**Key logic:**
- Calls FUN_0050fea7(1) -- pre-dispatch / sync (docs/19-renderer.md)
- Indirect jump via (*(code *)PTR_FUN_005d77d4)() -- matrix operation dispatch

**Calls:**
- FUN_0050fea7(1) -- Pre-dispatch / sync (docs/19)
- PTR_FUN_005d77d4 -- Indirect function pointer (matrix math)

**Used by system:** docs/19-renderer.md -- matrix transform / render dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a7ec -- __setjmp3: MSVC JmpBuf Save

Source: MSVCRT (Visual Studio) | Confidence: high
MSVC CRT __setjmp3 implementation -- saves register state and exception handler chain into a jmp_buf for longjmp.

**Key logic:**
- Saves EBP, EBX, EDI, ESI, stack pointer, and return address into param_1[0..5]
- Writes magic value 0x56433230 ("VC20") at param_1[8] for version identification
- Saves ExceptionList at param_1[6]
- If ExceptionList == 0xFFFFFFFF (no handler): writes 0xFFFFFFFF at param_1[7]
- Else if param_2 == 0 or 1: writes handler data at param_1[7] from *(ExceptionList + 0xC); param_1[9] optionally set to param_3
- Else (param_2 >= 2): saves param_4 at param_1[7], then copies up to 6 additional stack values to param_1[10..15]
- Returns 0 (first return); longjmp returns non-zero

**Calls:** None (pure CRT routine)

**Used by system:** docs/20-math-utilities.md -- MSVC CRT setjmp/longjmp support

**Algorithm family:** CRT jmp_buf save

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c830 -- SEH Unwind: Call FUN_00581a20

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00581a20 (handle close + linked list destruction with vtable release) during exception unwinding.

**Key logic:**
- Calls FUN_00581a20() -- handle close + linked list destruction with vtable release (docs/01-engine-architecture.md)

**Calls:** FUN_00581a20 -- Handle close + linked list destruction with vtable release (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind / handle + list cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cf2f -- SEH Unwind: Call FUN_00581750

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00581750 (handle close with cleanup) during exception unwinding.

**Key logic:**
- Calls FUN_00581750() -- handle close with cleanup (docs/01-engine-architecture.md)

**Calls:** FUN_00581750 -- Handle close with cleanup (docs/01)

**Used by system:** docs/20-math-utilities.md -- MSVC SEH unwind / handle cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00566e20 — Resource Lookup Dispatcher

Source: unknown | Confidence: medium
Routes resource lookup to one of two target functions based on a mode flag.

**Key logic:**
- Checks param_1[4] (uint at offset +0x10) as mode selector
- If flag == 0: calls FUN_0058ace6(*param_1) — primary string-based resource lookup
- Else: calls FUN_00535550() — secondary/fallback resource lookup path

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0 | ResourceKey | undefined4 | Key/identifier forwarded to primary lookup |
| +0x10 | LookupModeFlag | uint | 0 = primary path, non-zero = secondary |

**Calls:**
- FUN_0058ace6 — File Size Query Wrapper / Resource lookup (primary)
- FUN_00535550 — Passthrough / Resource lookup (secondary/fallback)

**Used by system:** docs/20-math-utilities.md — resource lookup dispatcher used by file handle mgmt (docs/01-engine-architecture.md line 14001) and stream reading (docs/06-session-race-logic.md)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058dd4b — __math_exit (MSVC CRT Math Error Handler)

Source: MSVC CRT (__math_exit) | Confidence: high
MSVC CRT function that checks FPU status word and conditionally dispatches to math error handling.

**Key logic:**
- Reads return address (unaff_retaddr) and FPU status word (in_FPUStatusWord)
- If return address != 0x27f AND (return address & 0x20) != 0 AND (FPU status word & 0x20) != 0:
  Calls __startOneArgErrorHandling()
- Otherwise returns immediately — no error path triggered
- Condition checks for floating-point exception flags in both context

**Calls:**
- __startOneArgErrorHandling (MSVC CRT) — one-argument math domain error handler

**Used by system:** docs/20-math-utilities.md — MSVC math library error infrastructure

**Algorithm family:** MSVC CRT math error handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599b86 — Object Constructor with Vtable Setup

Source: unknown | Confidence: low
Object constructor with SEH prologue, vtable registration, and conditional field initialization.

**Key logic:**
- Calls FUN_0058a5d8 (SEH handler init) as function prologue
- Stores output of extraout_ECX (allocated this pointer) to local stack
- Sets local init flag to 0
- If param at EBP+0xc (constructor argument) is non-zero:
  - Sets vtable pointer to DAT_005b9c54
  - Sets field at +0x28 (extraout_ECX[10]) to 0
  - Sets vtable entry +4 to PTR_FUN_005b9c50
  - Sets init flag to 1
- Sets secondary vtable pointer at computed offset to PTR_LAB_005b9c48
- Calls FUN_0059a8fa (vtable/constructor finalize)
- Restores exception handler list
- Returns this pointer (extraout_ECX)

**Struct offsets (this):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0 | VTablePtr | int* | Main vtable pointer set to DAT_005b9c54 |
| +0x4 | VTable2Ptr | int* | Secondary vtable entry PTR_FUN_005b9c50 |
| +0x28 | Field_0x28 | int | Zeroed during conditional init |

**Calls:**
- FUN_0058a5d8 — SEH Handler Init / stack probe
- FUN_0059a8fa — vtable/constructor finalize / post-init

**Used by system:** docs/20-math-utilities.md — generic object constructor with dual vtable

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059c4a0 — SEH Unwind Free Object at -0x14

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x14. Identical body to Unwind_0059c446 at a different address (duplicate unwind landing pad).

**Key logic:**
- Loads pointer from stack at EBP-0x14
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for object at stack offset -0x14

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c648 — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +8. Identical body to Unwind_0059c60c but at different address (duplicate unwind landing pad).

**Key logic:**
- Loads pointer from stack at EBP+8
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for parameter at stack offset +8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c67a — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +8. Identical body to Unwind_0059c60c but at different address.

**Key logic:**
- Loads pointer from stack at EBP+8
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for parameter at stack offset +8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c6c0 — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +8. Identical body to Unwind_0059c60c but at different address.

**Key logic:**
- Loads pointer from stack at EBP+8
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for parameter at stack offset +8

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c7ee — SEH Unwind: Call FUN_00499ae0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00499ae0 (Free If Non-Null / global cleanup) during stack unwinding.

**Key logic:**
- Calls FUN_00499ae0() with no arguments

**Calls:**
- FUN_00499ae0 — Free If Non-Null / global cleanup function (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling global cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c83e — SEH Unwind: Call FUN_00581a80

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00581a80 (Linked List Cleanup Generic) during stack unwinding.

**Key logic:**
- Calls FUN_00581a80() with no arguments

**Calls:**
- FUN_00581a80 — Linked List Cleanup (Generic) (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling linked list destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c8b2 — SEH Unwind: Call FUN_00582190

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00582190 (pool destructor: closes mutex, frees linked lists).

**Key logic:**
- Calls FUN_00582190() with no arguments

**Calls:**
- FUN_00582190 — Pool destructor, closes mutex, frees linked lists (docs/21)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling pool destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c9ab — SEH Unwind Free Object at -0x130

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x130 (large stack frame).

**Key logic:**
- Loads pointer from stack at EBP-0x130
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for large stack frame object

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cb80 — SEH Unwind: Call FUN_005834c0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_005834c0 (List Destruction with Virtual Release).

**Key logic:**
- Calls FUN_005834c0() with no arguments

**Calls:**
- FUN_005834c0 — List Destruction with Virtual Release (docs/01)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling list destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cc00 — SEH Unwind: Call FUN_00583570

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00583570 (List Destruction with COM Release) during stack unwinding.

**Key logic:**
- Calls FUN_00583570() with no arguments

**Calls:**
- FUN_00583570 — List Destruction with COM Release (docs/01)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling list destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cd08 — SEH Unwind: Call FUN_00582fd0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00582fd0 (ExceptionList walk and object cleanup).

**Key logic:**
- Calls FUN_00582fd0() with no arguments

**Calls:**
- FUN_00582fd0 — MSVC exception handler ExceptionList walk and object cleanup (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling exception handler cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ce76 — SEH Unwind: Call FUN_00583650

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00583650 (Single Function Call Wrapper).

**Key logic:**
- Calls FUN_00583650() with no arguments

**Calls:**
- FUN_00583650 — Single Function Call Wrapper (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling function wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cec9 — SEH Unwind: Call FUN_004b0170

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_004b0170 (game state update/release/cleanup function).

**Key logic:**
- Calls FUN_004b0170() with no arguments

**Calls:**
- FUN_004b0170 — Game state update / object release / destructor (docs/01, docs/06, docs/17)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling release/cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cf03 — SEH Unwind: Call FUN_005833e0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_005833e0 (Walk Linked List, Call Destructor, Free Nodes).

**Key logic:**
- Calls FUN_005833e0() with no arguments

**Calls:**
- FUN_005833e0 — Walk Linked List, Call Destructor, Free Nodes (docs/01)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling list destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cf4b — SEH Unwind: Call FUN_005870d0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_005870d0 (Set VTable Pointer and Call Init).

**Key logic:**
- Calls FUN_005870d0() with no arguments

**Calls:**
- FUN_005870d0 — Set VTable Pointer and Call Init (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling vtable init

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d012 — SEH Unwind: Call FUN_005861e0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_005861e0 (CloseHandle Wrapper) during stack unwinding.

**Key logic:**
- Calls FUN_005861e0() with no arguments

**Calls:**
- FUN_005861e0 — CloseHandle Wrapper (docs/01)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling handle close wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d050 — SEH Unwind: Call FUN_00583650

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00583650 (Single Function Call Wrapper). Same target as Unwind_0059ce76.

**Key logic:**
- Calls FUN_00583650() with no arguments

**Calls:**
- FUN_00583650 — Single Function Call Wrapper (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling function wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d0a7 — SEH Unwind: Call FUN_0047aa60

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_0047aa60 (empty stub / no-op) during stack unwinding.

**Key logic:**
- Calls FUN_0047aa60() with no arguments

**Calls:**
- FUN_0047aa60 — Empty stub / no-op cleanup function (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling no-op stub

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d170 — SEH Unwind: Call FUN_00499ae0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00499ae0 (Free If Non-Null / global cleanup).

**Key logic:**
- Calls FUN_00499ae0() with no arguments

**Calls:**
- FUN_00499ae0 — Free If Non-Null / global cleanup function (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling global cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d1b8 — SEH Unwind: Call FUN_00599796 with Data

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00599796 (empty stub / locale refcount release) with a stack-local pointer and a global static descriptor.

**Key logic:**
- Loads pointer from stack at EBP-0x10
- Calls FUN_00599796(local_ptr, &DAT_008d4248) — paired cleanup with static type descriptor

**Calls:**
- FUN_00599796 — Empty stub / locale refcount release (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup with type descriptor context

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d2c7 — SEH Unwind: Call FUN_00598c70

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00598c70 (Null Check with Virtual Dispatch).

**Key logic:**
- Calls FUN_00598c70() with no arguments

**Calls:**
- FUN_00598c70 — Null Check with Virtual Dispatch (docs/01)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling null-check dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d318 — SEH Unwind: Call FUN_00599796 with Data

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00599796 (empty stub / locale refcount release) with a stack-local pointer and a global static descriptor.

**Key logic:**
- Loads pointer from stack at EBP-0x10
- Calls FUN_00599796(local_ptr, &DAT_008d44b8) — paired cleanup with static type descriptor

**Calls:**
- FUN_00599796 — Empty stub / locale refcount release (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup with type descriptor context

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d3a8 — SEH Unwind: Conditional Call FUN_00599be5

Source: unknown | Confidence: high
MSVC SEH unwind handler — conditionally calls FUN_00599be5 (Set Locale VTable + Dtor) based on a flag bit at EBP-0x10.

**Key logic:**
- Checks bit 0 of uint at stack offset EBP-0x10
- If set: calls FUN_00599be5() — locale vtable destructor
- Else: returns immediately — no cleanup

**Calls:**
- FUN_00599be5 — Set Locale VTable + Dtor (docs/20)

**Used by system:** docs/20-math-utilities.md — conditional SEH cleanup for locale object

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0050e174 — Indirect Dispatch via Global Function Pointer

Source: unknown | Confidence: high
Wrapper that calls FUN_0050fea7(1) for lock acquisition, then dispatches through a global function pointer.

**Key logic:**
- Calls FUN_0050fea7(1) — acquire/lock/sync (render context PSGP-related)
- Calls through global PTR_FUN_005d7854 with all 4 parameters forwarded
- Passthrough wrapper — no logic beyond dispatch

**Calls:**
- FUN_0050fea7 — Sync/lock/acquire (render context, docs/19)
- PTR_FUN_005d7854 (indirect via global) — target operation

**Used by system:** docs/20-math-utilities.md — dispatch wrapper in render/PSGP subsystem

**Algorithm family:** Indirect function dispatch via global pointer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587d33 — MSVC CRT File Close (Locked)

Source: MSVC CRT (__fclose_lk) | Confidence: high
MSVC CRT locked file close — flushes buffers, frees temp filename, marks file as closed.

**Key logic:**
- Returns -1 if param_1->_flag & 0x83 == 0 (not open)
- Calls FUN_0058a05a(param_1) — flush/write buffers
- Calls __freebuf(param_1) — free internal buffer
- Calls FUN_0058c331(param_1->_file) — close OS file handle
- If close fails: returns -1
- If _tmpfname non-null: frees via FUN_0058aa6f, sets to NULL
- Sets _flag = 0 (closed)

**Struct offsets (param_1 — FILE*):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | _flag | int | Mode flags |
| +0x10 | _file | int | OS file handle |
| +0x1c | _tmpfname | char* | Temp filename (freed if non-null) |

**Calls:**
- FUN_0058a05a — Buffer Flush/Write
- __freebuf — MSVC CRT free buffer
- FUN_0058c331 — MSVC CRT close file handle
- FUN_0058aa6f — Heap free for temp filename

**Used by system:** docs/20-math-utilities.md — MSVC CRT file I/O locked close

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058dc57 — MSVC CRT Math Error Handler

Source: MSVC CRT (__startOneArgErrorHandling) | Confidence: high
MSVC CRT function for handling single-argument math domain errors (sqrt of negative, log of zero, etc.).

**Key logic:**
- Saves FPU top-of-stack (ST0) to local variable
- Stores param_5 and param_6 as error context
- Calls FUN_00596175(param_2, error_buffer, &param_3) — CRT error dispatch
- Returns original ST0 value

**Calls:**
- FUN_00596175 — CRT error handling dispatch

**Used by system:** docs/20-math-utilities.md — MSVC math library error infrastructure

**Algorithm family:** MSVC CRT math error handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c4f0 — SEH Unwind Free Object at -0x30

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x30 (large local allocation).

**Key logic:**
- Loads pointer from stack at EBP-0x30
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for large local object

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c652 — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +8 (parameter slot). Identical to Unwind_0059c60c.

**Key logic:**
- Loads pointer from stack at EBP+8
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for parameter at +8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c770 — C++ Unwind Helper (thunk to FUN_005867b0)

Source: unknown | Confidence: high
MSVC SEH unwind handler — thunk to FUN_005867b0 (SEH-Guarded Function with Exception Handling).

**Key logic:**
- Calls FUN_005867b0() — SEH-guarded cleanup for linked list nodes

**Calls:**
- FUN_005867b0 — SEH-Guarded Function / linked list node cleanup (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling SEH-guarded node cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c8f4 — C++ Unwind Helper (thunk to FUN_00581820)

Source: unknown | Confidence: high
MSVC SEH unwind handler — thunk to FUN_00581820 (Linked List Destroy + CloseHandle).

**Key logic:**
- Calls FUN_00581820() — linked list destruction with handle close

**Calls:**
- FUN_00581820 — Linked List Destroy + CloseHandle (docs/01)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling list destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cb00 — C++ Unwind Helper (thunk to FUN_005870d0)

Source: unknown | Confidence: high
MSVC SEH unwind handler — thunk to FUN_005870d0 (Set VTable Pointer and Call Init).

**Key logic:**
- Calls FUN_005870d0() — vtable init function

**Calls:**
- FUN_005870d0 — Set VTable Pointer and Call Init (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling vtable init

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cc93 — SEH Unwind Free Object at -0x18

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x18.

**Key logic:**
- Loads pointer from stack at EBP-0x18
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/20-math-utilities.md — SEH cleanup for object at stack offset -0x18

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cebb — C++ Unwind Helper (thunk to FUN_00585fb0)

Source: unknown | Confidence: high
MSVC SEH unwind handler — thunk to FUN_00585fb0 (Linked List Cleanup with Sub-Object Delete).

**Key logic:**
- Calls FUN_00585fb0() — linked list cleanup with sub-object deletion

**Calls:**
- FUN_00585fb0 — Linked List Cleanup with Sub-Object Delete (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cfda — C++ Unwind Helper (thunk to FUN_00586170)

Source: unknown | Confidence: high
MSVC SEH unwind handler — thunk to FUN_00586170 (Handle Close & Linked List Cleanup).

**Key logic:**
- Calls FUN_00586170() — handle close + linked list cleanup

**Calls:**
- FUN_00586170 — Handle Close & Linked List Cleanup (docs/01)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling handle/list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d130 — C++ Unwind Helper (thunk to FUN_00585fb0)

Source: unknown | Confidence: high
MSVC SEH unwind handler — thunk to FUN_00585fb0 (Linked List Cleanup with Sub-Object Delete). Same target as Unwind_0059cebb.

**Key logic:**
- Calls FUN_00585fb0() — linked list cleanup with sub-object deletion

**Calls:**
- FUN_00585fb0 — Linked List Cleanup with Sub-Object Delete (docs/20)

**Used by system:** docs/20-math-utilities.md — SEH cleanup calling list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d384 — SEH Unwind: Conditional Call FUN_00599be5

Source: unknown | Confidence: high
MSVC SEH unwind handler — conditionally calls FUN_00599be5 (Set Locale VTable + Dtor) based on a flag bit. Identical to Unwind_0059d3a8.

**Key logic:**
- Checks bit 0 of uint at stack offset EBP-0x10
- If set: calls FUN_00599be5() — locale vtable destructor
- Else: returns immediately

**Calls:**
- FUN_00599be5 — Set Locale VTable + Dtor (docs/20)

**Used by system:** docs/20-math-utilities.md — conditional SEH cleanup for locale object

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d594 — SEH Unwind: Destroy Exception Object

Source: unknown | Confidence: high
MSVC SEH unwind handler — destroys a C++ exception object at stack offset -0x10. Identical to Unwind_0059d484.

**Key logic:**
- Loads exception pointer from stack at EBP-0x10
- Calls exception::~exception()

**Calls:**
- exception::~exception (MSVC C++ exception destructor)

**Used by system:** docs/20-math-utilities.md — SEH cleanup destroying exception object

**Moddability:** hardcoded


<!-- target: docs/20-math-utilities.md -->
## FUN_00457cf0 — Conditional Free and Struct Zero-Init

Source: unknown | Confidence: high
Null-checks a pointer field, frees the heap object if set, then zeroes six consecutive fields.

**Key logic:**
- If `*param_1 != 0`: calls FUN_00587bcf(*param_1 - 4) — free wrapper; sets `*param_1 = 0`
- Unconditionally zeroes param_1[1] through param_1[6]
- Pattern: safe release + reset of a struct managing one heap pointer and 6 data fields

**Struct offsets (param_1 — int array):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| [0] (+0x00) | HeapPtr | int* | freed via FUN_00587bcf if non-null, then nulled |
| [1]–[6] (+0x04–+0x18) | DataFields | int | zeroed unconditionally |

**Calls:**
- FUN_00587bcf — Free Wrapper (thunk to heap free)

**Used by system:** docs/20-math-utilities.md — resource cleanup utility, called during object teardown

**Algorithm family:** memory management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## FUN_0045bb50 — VTable Init + Conditional Resource Free

Source: unknown | Confidence: high
Sets vtable pointer on param_1, performs two-call sequence, then conditionally frees a secondary resource at param_1[0xb].

**Key logic:**
- Sets `*param_1 = &PTR_FUN_0059f080` — vtable assignment (C++ constructor pattern)
- Calls FUN_004dd000() — short two-call sequence (engine init step)
- If `param_1[0xb] != 0`: calls FUN_00587bcf(param_1[0xb]) — frees heap resource at slot 0xb
- Calls FUN_004dcd10() — resource cleanup

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| [0] (+0x00) | VTablePtr | ptr | set to PTR_FUN_0059f080 |
| [0xb] (+0x2c) | ResourcePtr | int | freed if non-null |

**Calls:**
- FUN_004dd000 — Short Computation / Two-Call Sequence (docs/01)
- FUN_00587bcf — Free Wrapper
- FUN_004dcd10 — Resource Cleanup (docs/20)

**Used by system:** docs/20-math-utilities.md — constructor/init pattern shared with FUN_0045b400 (Destructor with Resource Cleanup)

**Algorithm family:** memory management

**Moddability:** hardcoded
