# Engine Architecture - Session State Machine, Module Lifecycles
## FUN_00550800 — Dual Field Zero-Init

Source: unknown | Confidence: high
Zero-initializes two consecutive 4-byte fields of a struct.

**Key logic:**
- Sets `param_1[0] = 0` and `param_1[1] = 0`
- Two undefined4 fields at +0x00 and +0x04 cleared to 0
- Minimal init function — likely a struct constructor fragment or reset helper

**Used by system:** docs/01-engine-architecture.md — engine init/cleanup subsystem

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005528f0 — Conditional UI Cleanup Dispatch

Source: unknown | Confidence: high
Conditionally calls FUN_00554d70 if a flag bit is set and a pointer is non-null.

**Key logic:**
- Checks flag at `param_1 + 0x24` for bit 0x20000
- Checks pointer at `param_1 + 0x868` for non-null
- If both true: calls `FUN_00554d70(param_1->field_0x868)` to release/notify

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x24 | unknown | uint | flag field, bit 0x20000 tested |
| +0x868 | unknown | int* | pointer to sub-object |

**Calls:**
- FUN_00554d70 — notify device / release (renderer resource cleanup, docs/19)

**Used by system:** docs/01-engine-architecture.md — UI cleanup path; likely widget destructor or container cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005546a0 — Multi-Field Setter Dispatching to 7 Sub-Setters

Source: unknown | Confidence: medium
Reads 7 fields from param_2 at offsets +0x20 to +0x38 and dispatches each to a dedicated setter function.

**Key logic:**
- Stores param_3 into `*param_1` (first field set)
- Calls 7 setter functions sequentially, each fed a field from param_2:
  - FUN_00553fc0(param_2 + 0x20) — entity factory / creation (docs/20)
  - FUN_005542f0(param_2 + 0x24) — entity property set (docs/06)
  - FUN_005545e0(param_2 + 0x28) — unknown setter
  - FUN_00554560(param_2 + 0x30) — UI animation / interpolation (docs/20)
  - FUN_00554610(param_2 + 0x2c) — renderer element set (docs/19)
  - FUN_005544c0(param_2 + 0x34) — unknown setter
  - FUN_00554510(param_2 + 0x38) — unknown setter
- Each setter likely configures a specific aspect of an entity (position, size, behaviour flags, etc.)

**Calls:**
- FUN_00553fc0 — entity factory/creation (docs/20)
- FUN_005542f0 — entity property set (docs/06)
- FUN_005545e0 — unknown setter
- FUN_00554560 — UI animation interpolation (docs/20)
- FUN_00554610 — renderer element set (docs/19)
- FUN_005544c0 — unknown setter
- FUN_00554510 — unknown setter

**Used by system:** docs/01-engine-architecture.md — entity creation/initialization pipeline

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00556930 — Recursive State Traversal with Flag Check

Source: unknown | Confidence: medium
Recursively traverses a linked structure, executing FUN_00556980 on each node, gated by a flag comparison involving DAT_008b8e34.

**Key logic:**
- Reads node flag from `param_1 + 0x38`
- If flag non-zero AND `(param_2 + 0x84 & flag & DAT_008b8e34) != flag`: early return (state mismatch guard)
- Calls `FUN_00556980(param_2)` — process current node
- If `param_1 + 0x44 != 0`: recurses via `FUN_00556930(param_2)` — traverse child
- If `param_1 + 0x40 == 0`: returns (termination condition)
- Otherwise advances to next sibling via `param_1 + 0x4c` and continues loop
- Traversal pattern: process → recurse child → advance sibling → loop

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x38 | uint | node flag/state |
| +0x40 | int | termination flag |
| +0x44 | int | has-child flag |
| +0x4c | int | next sibling pointer |

**Struct offsets (param_2):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x84 | uint | context flag mask |

**Globals:**
- `DAT_008b8e34` — renderer state/flag mask (not in docs/12; likely renderer visibility or active-state mask)

**Calls:**
- FUN_00556980 — node processing callback (unknown, same module)
- FUN_00556930 (self) — recursive call on child

**Used by system:** docs/01-engine-architecture.md — game state traversal; likely UI widget tree or renderable scene graph traversal

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00560ba0 — Object Init with Parameter Linking

Source: unknown | Confidence: medium
Initializes an object structure with default values, links it to a parent object's slot at +0x230.

**Key logic:**
- Calls `FUN_0053c2a0()` — parent constructor / subsystem init (docs/06, docs/20)
- Sets default float at `param_1[0] = 0x3e4ccccd` (0.2f) — default scaling/ratio value
- Zeroes fields at param_1[1], param_1[2], param_1[7], param_1[8], param_1[3], param_1[4], param_1[5], param_1[0xb], param_1[0xc], param_1[0xd]
- Sets param_1[6] = param_2 (parent object reference)
- Links self into parent: `*(parent->field_0x138 + 0x230) = param_1`
- Sets param_1[0xa] = param_3 (user parameter)
- Sets param_1[9] = 2 (initial state/type = 2)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | float | initial value 0.2f |
| +0x04 | int | zero |
| +0x08 | int | zero |
| +0x0c | int | zero |
| +0x10 | int | zero |
| +0x14 | int | zero |
| +0x18 | int* | parent object ref (param_2) |
| +0x1c | int | zero |
| +0x20 | int | zero |
| +0x24 | int | zero |
| +0x28 | int | zero |
| +0x28 | int | param_3 (user arg) |
| +0x24 | int | initial type/state = 2 |

**Struct offsets (param_2 parent):**
| Offset | Notes |
|--------|-------|
| +0x138 | intermediate ptr |
| +0x230 | slot where self is stored |

**Calls:**
- FUN_0053c2a0 — parent constructor / subsystem init (docs/06, docs/20)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0057a020 — Struct Zero-Init (4 + 8 Words)

Source: unknown | Confidence: high
Zero-initializes a 12-dword (48 byte) struct. First 4 dwords set directly, next 8 via loop.

**Key logic:**
- Sets param_1[0..3] = 0 (first 16 bytes)
- Loop: sets param_1[4..11] = 0 (next 32 bytes)
- Returns param_1 pointer
- Total: 48 bytes zeroed

**Used by system:** docs/01-engine-architecture.md — engine struct/object constructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a750 — Single Function Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper: calls FUN_00585440 with no parameters, no local logic.

**Key logic:**
- Direct call to FUN_00585440 (unknown — no docs found)
- Used for callback registration or export stub

**Calls:**
- FUN_00585440 — target function (unknown, not documented)

**Used by system:** docs/01-engine-architecture.md — engine dispatch / callback table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b050 — Linked List Node Removal with Memory Free

Source: unknown | Confidence: high
Searches a doubly-linked list for a node matching a key (param_2), removes it, conditionally frees sub-data, and frees the node.

**Key logic:**
- Early return 0 if param_2 == 0
- Reads list head from `param_1 + 8`
- Walks list via next pointer at `node + 4`
- Compares `*node == param_2` (key match)
- If match found:
  - If node == tail (param_1+0x10): updates tail to node->next
  - If prev is null (node is head): updates head to node->next (param_1+8)
  - Else: updates prev->next = node->next
  - If tail ptr == node: updates tail to prev (param_1+0xc)
  - Decrements count at param_1+0x14
  - If `(char)node[2] != 0`: frees sub-object `*node` via FUN_00587bcf
  - Frees node itself via FUN_00587bcf
  - Returns 1 (success)
- Returns 0 (not found)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | int* | head pointer |
| +0x0c | int* | tail pointer (previous) |
| +0x10 | int* | tail end marker |
| +0x14 | int | count |

**Struct offsets (node):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int | key value (param_2 comparison) |
| +0x04 | int* | next pointer |
| +0x08 | char | flag byte (triggers sub-object free if non-zero) |

**Calls:**
- FUN_00587bcf — free/delete operator (docs throughout)

**Used by system:** docs/01-engine-architecture.md — linked list container node removal with managed lifetime

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057dbb0 — Vtable Call + Format Dispatch + Timer Dispatch Chain

Source: unknown | Confidence: medium
Calls a virtual method from param_1's vtable, then formats a timer/clock value via renderer message pipeline (FUN_00586800/FUN_00586a00), and dispatches the result through a chain (FUN_0057afa0 → FUN_00584c70).

**Key logic:**
- Calls virtual method at `(*param_1)(*param_1 + 0x58)` — likely vtable offset 0x58 / slot 22
- Calls `FUN_00586800(0, 0xb, 0, 2, 0xffffffff)` — renderer message begin, type 0xb (timer/clock update, docs/19, docs/21)
- Calls `FUN_00584f90()` — mutex-guarded timer read (triage index: Sync/MutexTimer)
- Casts result to int, stores on stack
- Calls `FUN_00586a00(&stack_val, 4)` — renderer message write 4 bytes (timer value) (docs/19, docs/21)
- Calls `FUN_0057afa0(&stack_val)` — network packet constructor (docs/21)
- Calls `FUN_00584c70(uVar1)` — unknown dispatch/notify

**Calls:**
- Virtual method (slot 0x58) — vtable dispatch
- FUN_00586800 — renderer message begin (docs/19)
- FUN_00584f90 — mutex-guarded timer read (triage: Sync/MutexTimer)
- FUN_00586a00 — renderer message data write (docs/19)
- FUN_0057afa0 — network packet constructor (docs/21)
- FUN_00584c70 — unknown dispatch/notify

**Used by system:** docs/01-engine-architecture.md — timer update flow bridging renderer, network, and UI

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00584f30 — Mutex-Protected Function Call with Wait

Source: unknown | Confidence: high
Acquires a mutex (WaitForSingleObject with timeout), calls FUN_00586000, releases mutex. Returns whether FUN_00586000 succeeded.

**Key logic:**
- Checks if handle at `param_1 + 0x5a8` is non-null (mutex handle)
- Calls WaitForSingleObject with timeout from `param_1 + 0x5ac`
- If wait succeeds (WAIT_OBJECT_0 or WAIT_ABANDONED): calls `FUN_00586000(param_2, 0)`
- If FUN_00586000 returns non-zero: result = true
- Releases mutex via ReleaseMutex
- Returns result

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x5a8 | HANDLE | mutex handle |
| +0x5ac | DWORD | timeout (ms) |

**Calls:**
- WaitForSingleObject — Win32 API
- FUN_00586000 — unknown callback (not documented)
- ReleaseMutex — Win32 API

**Used by system:** docs/01-engine-architecture.md — thread synchronization wrapper for resource access

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585f60 — Mutex Wait with Success Check

Source: unknown | Confidence: high
Waits on a mutex handle from param_1+0x50 with timeout from param_1+0x54. Returns param_1 on success, 0 on failure/null handle.

**Key logic:**
- If mutex handle at `param_1 + 0x50` is non-null:
  - Calls WaitForSingleObject with timeout at `param_1 + 0x54`
  - Returns param_1 (success) if WAIT_OBJECT_0 or WAIT_ABANDONED
- Returns 0 if handle is null or wait failed

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x50 | HANDLE | mutex handle |
| +0x54 | DWORD | timeout (ms) |

**Calls:**
- WaitForSingleObject — Win32 API

**Used by system:** docs/01-engine-architecture.md — thread synchronization primitive for mutex acquisition

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a9c2 — Single Function Call Wrapper

Source: unknown | Confidence: high
Trivial wrapper calling FUN_005993af with fixed argument (1).

**Key logic:**
- Calls `FUN_005993af(1)` — buffer flush/callback execution (triage index: referenced in buffer management and file format codec cleanup, docs/08)
- No parameters, no return

**Calls:**
- FUN_005993af — buffer flush / callback chain execution (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md — resource/stream flush on shutdown

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059bacc — Exception Destructor with Conditional Free

Source: unknown | Confidence: high
Exception/destructor handler that calls cleanup then conditionally frees the object.

**Key logic:**
- Calls `FUN_0059baa3()` — pre-destructor cleanup (unknown)
- If `(param_2 & 1) != 0`: calls `FUN_00587bcf(param_1)` — free the object
- Returns param_1
- Pattern matches MSVC++ exception handling destructor thunk

**Calls:**
- FUN_0059baa3 — pre-destructor cleanup (unknown)
- FUN_00587bcf — free/delete operator

**Used by system:** docs/01-engine-architecture.md — C++ exception handling object cleanup; similar to FUN_005992b7 pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c4c8 — SEH Unwind with Field Free

Source: unknown | Confidence: high
C++ SEH unwind handler — frees an object stored at EBP-0x14 (local variable cleanup).

**Key logic:**
- Reads pointer from `*(unaff_EBP - 0x14)` — local variable slot
- Calls `FUN_00587bcf(ptr)` — free/deallocate
- Standard C++ exception unwind cleanup for stack-allocated object

**Calls:**
- FUN_00587bcf — free/delete operator

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table for local object cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c60c — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
C++ SEH unwind handler — frees an object stored at EBP+8 (callee parameter cleanup).

**Key logic:**
- Reads pointer from `*(unaff_EBP + 8)` — parameter slot
- Calls `FUN_00587bcf(ptr)` — free/deallocate

**Calls:**
- FUN_00587bcf — free/delete operator

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table for parameter object cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059c706 — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
C++ SEH unwind handler — identical to Unwind_0059c60c: frees object at EBP+8.

**Key logic:**
- Reads pointer from `*(unaff_EBP + 8)` — parameter slot
- Calls `FUN_00587bcf(ptr)` — free/deallocate

**Calls:**
- FUN_00587bcf — free/delete operator

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table for parameter object cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c896 — Unwind Handler (SEH)

Source: unknown | Confidence: high
C++ SEH unwind handler — calls a single cleanup function.

**Key logic:**
- Calls `FUN_00581c20()` — unknown cleanup function
- No parameters, no conditional logic

**Calls:**
- FUN_00581c20 — cleanup/destructor (unknown)

**Used by system:** docs/20-math-utilities.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059ca80 — SEH Unwind with Single Call

Source: unknown | Confidence: high
C++ SEH unwind handler — calls FUN_0047aa60 (array destructor / small destructor, referenced in docs/19 renderer cleanup).

**Key logic:**
- Calls `FUN_0047aa60()` — array/small object destructor (docs/19)

**Calls:**
- FUN_0047aa60 — array destructor / small destructor (docs/19)

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table for array cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059cc6b — Unwind Handler (SEH)

Source: unknown | Confidence: high
C++ SEH unwind handler — frees an object at EBP-0x10.

**Key logic:**
- Reads pointer from `*(unaff_EBP - 0x10)` — local variable slot
- Calls `FUN_00587bcf(ptr)` — free/deallocate

**Calls:**
- FUN_00587bcf — free/delete operator

**Used by system:** docs/20-math-utilities.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059ce60 — Unwind Handler (SEH) — Array Destructor

Source: unknown | Confidence: high
C++ SEH unwind handler — calls array destructor on an object at EBP-0x14.

**Key logic:**
- Computes address: `*(unaff_EBP - 0x14) + 4`
- Calls `FUN_0058a5f7(addr, 0x28, 1, FUN_00583aa0)` — destructor iterator over array of stride 0x28
  - 0x28 = element size (40 bytes)
  - 1 = one element
  - FUN_00583aa0 = element destructor callback

**Calls:**
- FUN_0058a5f7 — destructor iterator / array cleanup

**Used by system:** docs/20-math-utilities.md — C++ SEH unwind table for array-type members

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059cfbe — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
C++ SEH unwind handler — calls FUN_004b0170 (destructor, referenced in docs/19 renderer, docs/18 physics).

**Key logic:**
- Calls `FUN_004b0170()` — destructor / cleanup (docs/19, docs/18)

**Calls:**
- FUN_004b0170 — destructor (docs/19, docs/18)

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d110 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
C++ SEH unwind handler — calls FUN_00586460 (unknown cleanup).

**Key logic:**
- Calls `FUN_00586460()` — cleanup/destructor (unknown)

**Calls:**
- FUN_00586460 — cleanup function (unknown)

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d2e4 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
C++ SEH unwind handler — calls FUN_00598c70 (unknown cleanup).

**Key logic:**
- Calls `FUN_00598c70()` — cleanup/destructor (unknown)

**Calls:**
- FUN_00598c70 — cleanup function (unknown)

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## Unwind_0059d508 — SEH Unwind Cleanup Call

Source: unknown | Confidence: high
C++ SEH unwind handler — calls FUN_0059ac3f (vtable pointer setter / constructor helper, triage index: Memory/VTable).

**Key logic:**
- Calls `FUN_0059ac3f()` — vtable pointer setter (triage: Memory/Constructor)

**Calls:**
- FUN_0059ac3f — vtable pointer setter / constructor

**Used by system:** docs/01-engine-architecture.md — C++ SEH unwind table

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593c9c — SEH Wrapper Dispatching to Handler Function

Source: unknown | Confidence: high
Sets up SEH frame, retrieves TLS data, checks a function pointer at +0x60, and calls it if non-null.

**Key logic:**
- Installs SEH frame (puStack_c = DAT_005b9988, handler = LAB_0058895c)
- Calls `FUN_0058e0c7()` — TLS value retrieval with init (docs/20, triage: TLS access)
- Checks `*(result + 0x60) != 0` — function pointer present
- If non-null: sets local_8 = 1 (SEH try), retrieves TLS again, calls the function pointer
- local_8 = 0xffffffff (SEH termination)
- Calls `FUN_00597371()` — SEH epilogue/unwind (unknown)

**Calls:**
- FUN_0058e0c7 — TLS value retrieval (docs/20)
- (*fnptr)() — callback from TLS context
- FUN_00597371 — SEH epilogue/unwind (unknown)

**Used by system:** docs/01-engine-architecture.md — TLS-based callback dispatch with exception protection

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00597321 — IsBadReadPtr Wrapper

Source: Win32 API wrapper | Confidence: high
Wraps Win32 IsBadReadPtr, returns true if memory is readable.

**Key logic:**
- Calls `IsBadReadPtr(param_1, param_2)` — validates memory range readability
- Returns `true` if IsBadReadPtr returns 0 (memory is readable), `false` otherwise
- Inverted logic: Win32 returns 0 for success, this wrapper normalizes to boolean

**Calls:**
- IsBadReadPtr — Win32 API (kernel32)

**Used by system:** docs/01-engine-architecture.md — memory safety validation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598aa0 — Status Check with Error Dispatch

Source: unknown | Confidence: low
Performs status validation on a polymorphic object (uses virtual dispatch via relative offsets). On error, calls FUN_0059a5fe with status flag.

**Key logic:**
- Reads vtable from `*param_1`
- Dereferences `*(vtable + 4)` to get field offset
- Reads status byte at `param_1 + field_offset + 4`
- Checks bit 1 & bit 2 of status: if both clear (mask 0x6 == 0):
  - Gets pointer from `param_1 + field_offset + 0x28`
  - Calls virtual method at slot 0x2c on that pointer
  - If result == -1: sets error flag (uVar2 = 4)
- If error flag set (uVar2 != 0):
  - Sets status |= error flag at `param_1 + field_offset + 4`
  - If inner pointer is null: sets additional flag | 4
  - Calls `FUN_0059a5fe(uVar2, 0)` — error dispatch

**Calls:**
- Virtual method (slot 0x2c) — status check
- FUN_0059a5fe — error dispatch (unknown)

**Used by system:** docs/01-engine-architecture.md — engine object health/status validation pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058a6eb — N-Time Callback Loop with SEH

Source: unknown | Confidence: high
Calls a callback function N times, wrapped in SEH (structured exception handling).

**Key logic:**
- Sets up SEH handler frame (puStack_c = DAT_005b8cb8, puStack_10 = LAB_0058895c)
- Installs handler via `ExceptionList = &local_14` (thread-local SEH registration)
- Loop: calls `(*param_4)()` for `param_3` iterations
- Sets `local_8 = 0xffffffff` (SEH termination)
- Calls FUN_0058a755() — SEH epilogue/unwind
- Restores ExceptionList

**Calls:**
- (*param_4)() — callback function pointer
- FUN_0058a755 — SEH unwind/epilogue handler

**Used by system:** docs/01-engine-architecture.md — SEH-protected batch callback execution; renderer batch processing (docs/19)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040c610 — Conditional Mode Dispatch with Global Gate

Source: unknown | Confidence: medium
Dispatches a mode change based on param_1 state and the global DAT_007cfcc8.

**Key logic:**
- If `DAT_007cfcc8 == 0` (no queued mode):
  - If param_1+0xc == 1 or 2: stores mode to param_1+0x14, calls FUN_0040cde0(0,0)
- Else (queued mode exists):
  - If param_1+0xc == 1: stores 1 to param_1+0x14, calls FUN_0040cde0(2,0)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0c | int | requested mode |
| +0x14 | int | stored mode |

**Globals:**
- `DAT_007cfcc8` — queued mode flag (docs/09)

**Calls:**
- FUN_0040cde0 — game action state machine (docs/01, 06, 07, 09, 18)

**Used by system:** docs/01-engine-architecture.md — mode/state transition gating

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00586d00 — Bitmap Range Occupancy Test via Bit Ops

Source: unknown | Confidence: medium
Tests a range of bits in a bitmap for occupancy. Given a start bit and count, returns a bitmask indicating which slots in the range are occupied.

**Key logic:**
- Reads base size from `*(param_1+0x1c) + *(param_1+0x34)*4 + 2` as ushort (range start bit index)
- Reads range length from `*(param_1+0x1c) + *(param_1+0x34)*4` as ushort (number of slots to test)
- Calculates uVar2 = length - 1 + start — effectively the end bit
- Loop iterates from uVar3 = 0 to uVar2 - 1:
  - Computes bit position: `(start - 1 + length) - uVar3`
  - Tests bitmap at `param_1+0x14` with: `bitmap[(pos >> 3)] & (1 << (pos & 7))` — standard bit test
  - If occupied: sets corresponding bit in result via `result |= 1 << (uVar3 & 0x1f)`
- Returns result bitmask (up to 32 bits)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x14 | byte* | bitmap data pointer |
| +0x1c | int* | segment data pointer |
| +0x34 | int | array index into segment data |

**Used by system:** docs/01-engine-architecture.md — resource/thread slot bitmap allocation test

**Algorithm family:** bitmap / bit array operations

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005874d0 — operator new with Result Check

Source: unknown | Confidence: high
Allocates memory via operator_new, stores in output parameter, returns success boolean.

**Key logic:**
- Calls `operator_new(param_1)` — heap allocation of param_1 bytes
- Stores pointer in `*param_2`
- Returns `true` if allocation succeeded, `false` otherwise

**Calls:**
- operator_new — heap allocation (C++ operator new)

**Used by system:** docs/01-engine-architecture.md — safe allocation wrapper with boolean result

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00562890 — Buffer Zero-Init with Virtual Method Call

Source: unknown | Confidence: medium
Zeroes a local buffer (0x15d dwords = 892 bytes), then calls a virtual method from param_1 and a string duplication utility.

**Key logic:**
- Zero-initializes 0x15d (349) dwords = 1396 bytes of stack buffer via loop
- Writes final 4 zero bytes: *(undefined2*)puVar3 = 0, *(undefined1*)(puVar3+2) = 0
- Reads function pointer from `param_1 + 0xd0` and calls it with parameter from `param_1 + 0x100`
- Calls `FUN_00562710(string_dup, &stack_buffer)` — string duplication with char replacement (docs/06)
- Large stack buffer suggests string formatting or path construction

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xd0 | code* | virtual method pointer |
| +0x100 | undefined4 | parameter for virtual call |

**Calls:**
- (*(param_1+0xd0))(*(param_1+0x100)) — virtual method dispatch
- FUN_00562710 — string duplication with character replacement (docs/06)

**Used by system:** docs/01-engine-architecture.md — engine initialization or UI rendering pipeline

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00550820 — Array-of-Struct Destructor with Countdown

Source: unknown | Confidence: medium
Iterates array of structs backward, destructs each element, frees memory.

**Key logic:**
- Reads count from param_1+0x8 (array element count)
- If count > 0, iterates count-1 times calling FUN_00550810 (destructor per element)
- After destructor loop, frees the array block via FUN_00587bcf(param_1 + (-4))
- Calls FUN_004b0170 (cleanup/free wrapper)

**Calls:**
- FUN_00550810 — element destructor/free wrapper (per-element)
- FUN_00587bcf — memory deallocation (frees block)
- FUN_004b0170 — cleanup/free wrapper

**Used by system:** docs/01-engine-architecture.md — memory management, cleanup on shutdown or array resizing

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00556980 — Animation Dispatch with Skip Flag

Source: unknown | Confidence: medium
Iterates animation/object list, dispatches animation handler per item if skip flag not set.

**Key logic:**
- Resolves param_2 via FUN_0054b570(param_2, 0) to get object set
- Checks flag at param_1+0x3c bit 2 — if set, skips entire dispatch (early out)
- Iterates linked list starting at param_1+0x204, each node at +0x10 offset
- If iVar3 (resolved object) != 0: clears bits 0xdfffffd7 from flags at node+0x14
- If node flags bit 0x200000 is clear: dispatches either FUN_00556b10 (if node+0x13c==0) or FUN_005569f0 (if node+0x13c != 0)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x3c | SkipFlags | byte | Bit 2 = skip dispatch |
| +0x204 | ListHead | ptr | Linked list of animation objects (next at +0x10) |

**Calls:**
- FUN_0054b570 — object set resolver
- FUN_00556b10 — animation handler (new/empty slot)
- FUN_005569f0 — animation handler (existing slot)

**Used by system:** docs/01-engine-architecture.md — animation dispatch loop

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_005596e0 — Function Pointer Dispatch via Linked Traversal

Source: unknown | Confidence: medium
Traverses two linked node chains, dispatches function pointer call when matching ID found.

**Key logic:**
- Reads root ID from *param_1 at param_1[2]+0x224 (list head)
- Traverses first linked list: for each node, checks if *node (ID) matches root+0x220
- If match AND *(node+0x18)+0x14 (function pointer) is non-null: sets param_1[8] to *(node+0x18)+0x18, calls via (node+0x18)+0x14
- If no match in list AND root is non-null: checks root+0x220 directly for function pointer at *(root+0x220)+0x14, calls it if non-null

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | *param_1 | ptr | Root node |
| +0x08 | param_1[2] | ptr | List head with vtable/dispatch table |
| +0x20 | param_1[8] | int | Result field (set before dispatch) |

**Used by system:** docs/01-engine-architecture.md — function pointer dispatch mechanism

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a040 — Pass-Through Wrapper

Source: unknown | Confidence: high
Forwarding wrapper — calls FUN_0057a070 with fixed 4th parameter 0, returns param_1 unchanged.

**Key logic:**
- Calls FUN_0057a070(param_2, param_3, param_4, 0)
- Returns param_1 unchanged

**Calls:**
- FUN_0057a070 — target function

**Used by system:** docs/01-engine-architecture.md — wrapper/adapter pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00584f90 — Mutex-Guarded Timer Read

Source: unknown | Confidence: high
Reads a timer/counter under mutex protection, returns float result.

**Key logic:**
- If mutex handle at param_1+0xd4 is non-null: acquires via WaitForSingleObject with timeout at param_1+0xd8
- Calls FUN_00583680() to get timer value
- If mutex was acquired: releases via ReleaseMutex
- Returns float10 timer value

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xd4 | MutexHandle | HANDLE | Mutex for synchronization |
| +0xd8 | MutexTimeout | DWORD | Wait timeout |

**Calls:**
- WaitForSingleObject — Win32 mutex acquisition
- ReleaseMutex — Win32 mutex release
- FUN_00583680 — timer/clock read

**Used by system:** docs/01-engine-architecture.md — thread-safe timer query

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585f90 — ReleaseMutex Wrapper Returning Success

Source: unknown | Confidence: high
Wrapper around Win32 ReleaseMutex, returns true if release succeeded.

**Key logic:**
- If mutex handle at param_1+0x50 is non-null: calls ReleaseMutex
- Returns true if ReleaseMutex returned 1 (success), false otherwise

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x50 | MutexHandle | HANDLE | Mutex to release |

**Calls:**
- ReleaseMutex — Win32 API

**Used by system:** docs/01-engine-architecture.md — mutex synchronization utility

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00587580 — Buffer Query: Return Ptr+Size If Valid

Source: unknown | Confidence: high
Returns buffer pointer and size if buffer has capacity, otherwise zero-output.

**Key logic:**
- If param_1[1] (capacity) < 1: sets *param_2=0, *param_3=0, returns 0
- Else: sets *param_2 = param_1[0] (data ptr), *param_3 = param_1[2] (size), returns 1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | DataPtr | ptr | Buffer start |
| +0x04 | Capacity | int | Max elements |
| +0x08 | Size | int | Current size |

**Used by system:** docs/01-engine-architecture.md — buffer access validation

**Moddability:** hardcoded

Source: unknown | Confidence: high
Thin wrapper — calls FUN_00585770 with no arguments, no return value processing.

**Key logic:**
- Calls FUN_00585770() directly

**Calls:**
- FUN_00585770 — target function

**Used by system:** docs/01-engine-architecture.md — function call stub in call chain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057dff0 — Mutex-Protected Linked-List Lookup by ID

Source: unknown | Confidence: high
Thread-safe linked-list lookup with mutex synchronization. Looks up node matching param_3 and param_2 short ID.

**Key logic:**
- Acquires mutex (WaitForSingleObject) at param_1+0xabc with timeout at param_1+0xac0
- On timeout/error: skips list traversal (piVar5 = null)
- Traverses linked list starting at *piVar5, stores current pointer in piVar5[2]
- Matches on *(node+4)==param_3 AND *(node+2) short == param_2 (primary match)
- Also tries *(node+0x14)==param_3 AND *(node+0x12) short == param_2 (secondary match)
- Releases mutex via ReleaseMutex
- If match found: calls FUN_0057de30(iVar7, param_6) with the matched node
- Returns combined status (mutex release success + lookup result)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xaac | ListHead | ptr* | Double pointer to list head |
| +0xabc | MutexHandle | HANDLE | Synchronization mutex |
| +0xac0 | MutexTimeout | DWORD | Wait timeout in ms |

**Calls:**
- WaitForSingleObject — Win32 mutex wait
- ReleaseMutex — Win32 mutex release
- FUN_0057de30 — process matched node

**Used by system:** docs/01-engine-architecture.md — thread-safe resource lookup

**Moddability:** hookable (mutex timeout)

<!-- target: docs/01-engine-architecture.md -->

## FUN_00582eb0 — Linked-List Node Removal with Cleanup Callback

Source: unknown | Confidence: high
Removes node from linked list by value, calls destructor on data and frees node.

**Key logic:**
- Reads *param_1 as list head, stores in param_1[2]
- Marks node+2 as 0 (byte at offset +8)
- Traverses list to find node where *node == iVar2 (matching ID)
- When found: unlinks node, updates list head if needed
- Decrements param_1[3] (count)
- If node+2 byte (cleanup flag) is non-zero AND *node != 0: calls FUN_00587bcf(*node) to free data
- Calls FUN_00587bcf(node) to free node itself
- Returns matched ID, or 0 if not found

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ListHead | ptr | First node |
| +0x04 | TailPtr | ptr | Last node |
| +0x08 | Current | ptr | Current iteration ptr |
| +0x0c | Count | int | Node count |

**Calls:**
- FUN_00587bcf — memory deallocation

**Used by system:** docs/01-engine-architecture.md — linked list management

**Moddability:** hardcoded

Source: unknown | Confidence: high
Sets state field at param_1+0x24 to value 2, calls cleanup wrapper.

**Key logic:**
- Sets *(param_1+0x24) = 2 (state flag, possibly "ready" or "active" state)
- Calls FUN_004b0170 (cleanup/free wrapper)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x24 | StateFlag | int | Set to 2 |

**Calls:**
- FUN_004b0170 — cleanup/free wrapper

**Used by system:** docs/01-engine-architecture.md — state machine transition

**Moddability:** hardcoded (constant 2)

<!-- target: docs/01-engine-architecture.md -->

## FUN_005628f0 — Large Stack Struct Zero-Init with Vtable Call

Source: unknown | Confidence: medium
Zeroes a large stack buffer (0x15d * 4 = 892 bytes), then calls a vtable method.

**Key logic:**
- Zero-fills stack buffer of 0x15d * 4 = 892 bytes (557 int32 entries)
- Sets trailing 3 bytes to zero
- Reads value from param_1+0x100 (data pointer)
- Calls vtable method at param_1+0xd4 with that value
- Calls FUN_00562710 with stack buffer and retaddr

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0xd4 | vtable_method | code* | Method pointer called with data |
| +0x100 | DataPtr | ptr | Data passed to vtable method |

**Calls:**
- FUN_00562710 — stack-based operation with the zeroed buffer

**Used by system:** docs/01-engine-architecture.md — initialization with large temporary struct

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00565dc0 — Allocate Struct with Default Values

Source: unknown | Confidence: high
Allocates 0x224-byte struct via operator_new, initializes with default values.

**Key logic:**
- Allocates 0x224 (548) bytes via operator_new
- If allocation succeeds: zeroes fields 0-3, sets field +0x84=0, field +0x85=0xffffffff, zeroes flags
- Stores pointer in *param_1, returns param_1
- On allocation failure: sets *param_1=0, returns param_1

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | *param_1 | ptr | Allocated struct pointer |
| +0x210 | puVar1[0x84] | int | Field at offset 0x210, initialized to 0 |
| +0x214 | puVar1[0x85] | int | Field at offset 0x214, initialized to -1 |

**Used by system:** docs/01-engine-architecture.md — memory allocation with default init

**Moddability:** hookable (default values)

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a810 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper — calls FUN_00585770 with no arguments, no return value processing.

**Key logic:**
- Calls FUN_00585770() directly

**Calls:**
- FUN_00585770 — target function

**Used by system:** docs/01-engine-architecture.md — function call stub in call chain

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00589d6b � Lock Acquire by Index

Source: unknown | Confidence: high
Calls FUN_0058dfea(0xd) to acquire lock/index 13.

**Calls:** FUN_0058dfea � lock acquisition
**Used by system:** docs/01-engine-architecture.md
**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058a755 -- Conditional Callback with SEH

Source: unknown | Confidence: medium
If SEH flag==0: dispatches FUN_0058a677

**Key logic:**
- If SEH flag==0: dispatches FUN_0058a677

**Calls:**
- FUN_0058a677 -- conditional dispatch

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## __cf -- CRT Float Conversion (_cfltcvt)

Source: unknown | Confidence: high
Dispatches float-to-string: 0x65/0x45=exponential, 0x66=fixed, else generic

**Key logic:**
- Dispatches float-to-string: 0x65/0x45=exponential, 0x66=fixed, else generic

**Calls:**
- FUN_0058bdcd, FUN_0058bef0, FUN_0058bfec

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## __math_e -- CRT Math Exit Handler

Source: unknown | Confidence: high
Checks FPU status; dispatches __startOneArgErrorHandling if error

**Key logic:**
- Checks FPU status; dispatches __startOneArgErrorHandling if error

**Calls:**
- __startOneArgErrorHandling -- CRT error handler

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059733d -- IsBadWritePtr Wrapper

Source: unknown | Confidence: high
Returns true if IsBadWritePtr(param_1, param_2)==0

**Key logic:**
- Returns true if IsBadWritePtr(param_1, param_2)==0

**Calls:**
- IsBadWritePtr -- Win32 API

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598aea -- Vtable Set + Sub-Call

Source: unknown | Confidence: high
Sets vtable to PTR_FUN_005b9bb4; calls FUN_0059a86c

**Key logic:**
- Sets vtable to PTR_FUN_005b9bb4; calls FUN_0059a86c

**Calls:**
- FUN_0059a86c

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005992ef -- Buffer Append with Memset

Source: unknown | Confidence: high
Realloc if needed; validate; _memset fill; null-terminate

**Key logic:**
- Realloc if needed; validate; _memset fill; null-terminate

**Calls:**
- FUN_0059ad49, FUN_00599560, _memset

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059988b -- Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00587b3e(&LAB_00599897)

**Key logic:**
- Calls FUN_00587b3e(&LAB_00599897)

**Calls:**
- FUN_00587b3e

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a407 -- Pointer Offset Adjuster

Source: unknown | Confidence: medium
Increments **(param_1+0x2c) by 1; decrements **(param_1+0x1c) by 2

**Key logic:**
- Increments **(param_1+0x2c) by 1; decrements **(param_1+0x1c) by 2

**Calls:**
- none

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ab83 -- Object Destructor with SEH

Source: unknown | Confidence: medium
SEH frame; base destructor; checks DAT_008d4650; vtable release

**Key logic:**
- SEH frame; base destructor; checks DAT_008d4650; vtable release

**Calls:**
- FUN_0058a5d8, FUN_0059a54d, FUN_00598c88, FUN_0059a5e9

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00554b20 — Resource Factory via VTable Dispatch

Source: unknown | Confidence: medium
Creates a resource object through vtable dispatch. Chooses between two creation paths based on `param_3` flag and checks a sub-object's field at +0x1a0.

**Key logic:**
- Calls `FUN_005424e0` (arithmetic helper) to initialize 4 local variables
- If `param_3 == 0` AND `*(int*)(param_2 + 0x1a0) == 0` (no existing resource at param_2):
  - Tests flag at `*(byte*)(param_2 + 0x80) & 2`
  - If flag NOT set: uVar1=0, uVar2=2 (default format)
  - If flag IS set: uVar1=*(param_2+0x7c), uVar2=3 (custom format)
  - Dispatches vtable slot +0x90 (slot 36) with params: `(param_1[0x440], 0, 0, uVar2, uVar1, 1.0f, 0)`
  - Stores result in `*param_1`
- If `param_3 == 0` AND resource exists: calls `FUN_00543250` (clear/blit) with mixed params
- If `param_3 != 0`: dispatches vtable slot +0x90 with (param_1[0x440], 0, 0, 2, 0, 1.0f, 0), stores to `*param_1`

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | ResourceResult | int | Output: created resource handle |
| +0x440 | VTableBasePtr | int* | Pointer to object with vtable at index 0x90 |

**Struct offsets (param_2):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x1a0 | ExistingResource | int | Non-null if resource already allocated |
| +0x80 | Flags | byte | Bit 1 (0x02) selects format mode |
| +0x7c | FormatParam | int | Custom format value when bit 1 set |

**Calls:**
- FUN_005424e0 — arithmetic helper (4 locals initialized)
- FUN_00543250 — clear/blit destination (used in renderer, per docs/17)

**Used by system:** docs/01-engine-architecture.md — resource manager factory pattern for creating graphics/compute resources

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005569f0 — Scene Node State Update with Transform

Source: unknown | Confidence: medium
Updates scene node state flags, bounding box, and transformation data. Integrates D3D device transforms with collision contact state.

**Key logic:**
- Calls FUN_00551760 (scene begin update) and FUN_0054b570 (Euler-angle to 4x4 transform matrix, docs/19)
- If `*(param_2 + 0x1ac) == 0` (no bounding data): calls FUN_0054d9f0 (bounding box computation, docs/19)
- If flag `*(param_3+0x14)` bit 29 (0x20000000) NOT set:
  - Calls D3D device (DAT_008b8f24) vtable+4 to transform data from `param_1+0x204` to `param_3+0xe8` area
  - Sets bit 29 in flags
- Calls FUN_0054d7a0 (collision contact state detection, docs/06)
- If bit 2 (0x4) set AND bit 3 (0x8) NOT set in flags:
  - Sets bit 3 (0x8)
  - Loops 8 times (stride 0xc): transforms 8 sub-elements via D3D device (DAT_008b8f24 vtable+4)
- If flags & 0x5 != 0 (bits 0 or 2 set):
  - If bit 5 (0x20) NOT set: checks `**(param_3+0x11c) & 0x100` → calls FUN_0055ed10 (math transform, docs/20); checks bit 20 (0x100000) → calls FUN_0055d5c0 (audio/network, docs/21)
  - Calls FUN_00556d60 (state finalizer, docs/20)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x114 | OutputTransform | int | Transform output buffer |
| +0x1a0 | TransformSrc | int | Source data for D3D transform |
| +0x204 | TransformOffset | int | Offset/base for transform computation |

**Struct offsets (param_2):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x1ac | BoundingData | int | Non-null if bounding volume exists |

**Struct offsets (param_3):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x14 | StateFlags | uint | Bitfield: bit2=0x4, bit3=0x8, bit5=0x20, bit20=0x100000, bit29=0x20000000 |
| +0xe8 | ContactState | int | Collision contact state buffer |
| +0x11c | CollisionData | int* | Pointer to collision data flags |

**Globals:**
- `DAT_008b8f24` — D3D device wrapper / scene manager singleton vtable (docs/22)

**Calls:**
- FUN_00551760 — scene begin update
- FUN_0054b570 — Euler-angle to 4x4 transform matrix (docs/19)
- FUN_0054d9f0 — bounding box computation (docs/19)
- FUN_0054d7a0 — collision contact state detection (docs/06)
- FUN_0055ed10 — math transform (docs/20)
- FUN_0055d5c0 — audio/network action (docs/21)
- FUN_00556d60 — state finalizer (docs/20)

**Used by system:** docs/06-session-race-logic.md — scene graph node update with transform propagation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055d2a0 — String Copy with Flag Union

Source: unknown | Confidence: medium
Sets flag bits on an object, copies a null-terminated string into internal buffer at +0x58, and computes a hash/ID from the flag value stored at +0x04.

**Key logic:**
- Sets `*param_1 |= param_3` (union of flag bits into first field)
- Copies string `param_2` byte-by-byte into buffer at `*(char*)(param_1 + 0x58)` until null terminator
- Calls `FUN_00541500(param_3)` (hash/checksum of flag value)
- Stores result in `param_1[1]` (field at +0x4)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | Flags | uint | Bitfield, OR-ed with param_3 |
| +0x04 | ComputedID | uint | Output from FUN_00541500(param_3) |
| +0x58 | NameBuffer | char[] | Null-terminated string copy of param_2 |

**Calls:**
- FUN_00541500 — hash/checksum computation from flag value

**Used by system:** docs/01-engine-architecture.md — object initialization with name assignment and ID computation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00560e50 — Multi-Field Object Destructor with Cleanup Calls

Source: unknown | Confidence: high
Destructor that releases and frees three resource pointers at offsets +0x0c, +0x1c, and +0x20.

**Key logic:**
- If `*(param_1 + 0x0c) != 0`: calls FUN_004b0170 (release), then FUN_00557470 (unload), then FUN_00587bcf (free), zeros pointer
- If `*(param_1 + 0x1c) != 0`: calls FUN_00557470 (unload), then FUN_00587bcf (free)
- If `*(param_1 + 0x20) != 0`: calls FUN_00560b90 (sub-cleanup), then FUN_00587bcf (free)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x0c | ResourceA | int* | Freed with release+unload+free sequence |
| +0x1c | ResourceB | int* | Freed with unload+free |
| +0x20 | ResourceC | int* | Freed with sub-cleanup+free |

**Calls:**
- FUN_004b0170 — game state update/release signal (docs/01, docs/09)
- FUN_00557470 — resource unload/release (docs/06, docs/17, docs/19)
- FUN_00587bcf — memory free/deallocation (docs/01, docs/06)
- FUN_00560b90 — sub-object cleanup helper

**Used by system:** docs/01-engine-architecture.md — generic C++ object destructor pattern

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_005697f0 — Triple Buffer Allocation

Source: unknown | Confidence: high
Allocates three buffers of varying stride via operator_new. Used to prepare storage for three different data types in a renderer or physics batch.

**Key logic:**
- Buffer 1: `operator_new(count_at_0x22c * 0x38)` → stored at +0x230, zero count
- Buffer 2: `operator_new(count_at_0x234 * 0x84)` → stored at +0x238, zero count
- Buffer 3: `operator_new(count_at_0x23c * 0x58)` → stored at +0x240, zero count

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x22c | CountA | int | Element count for buffer A (stride 0x38 = 56 bytes) |
| +0x230 | BufferA | void* | Allocated buffer A |
| +0x234 | CountB | int | Element count for buffer B (stride 0x84 = 132 bytes) |
| +0x238 | BufferB | void* | Allocated buffer B |
| +0x23c | CountC | int | Element count for buffer C (stride 0x58 = 88 bytes) |
| +0x240 | BufferC | void* | Allocated buffer C |

**Calls:**
- operator_new — C++ allocation operator (malloc wrapper)

**Used by system:** docs/10-vehicle-physics.md — called during body initialization (FUN_005697f0 called from body init chain, per docs/10)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a830 — VTable Boolean Test Wrapper

Source: unknown | Confidence: high
Calls a vtable method at slot +0x9c (slot 39) and returns true if the result is zero (null/empty).

**Key logic:**
- Calls `(**(code**)(*(int*)*param_1 + 0x9c))(param_2, param_3)` — vtable method at offset 0x9c
- Returns `true` if the return value is `'\0'` (zero byte), else `false`
- Used as an existence/truth check against a virtual method result

**Calls:**
- (vtable+0x9c) — virtual method returning char/byte

**Used by system:** docs/01-engine-architecture.md — generic vtable boolean predicate wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057e6e0 — Thread-Safe Linked List Destruction with Mutex

Source: unknown | Confidence: high
Destroys a linked list under mutex protection. Waits on a mutex, walks the list calling virtual destructors on each node, frees memory, and releases the mutex.

**Key logic:**
- Reads list head from `*(param_1 + 0xac8)` (pointer to first node)
- If mutex handle at `param_1 + 0xad8` is valid: calls `WaitForSingleObject(handle, timeout_at_param_1+0xadc)`
- If wait fails (non-zero and not WAIT_TIMEOUT=0x80): skips processing (sets list pointer to null)
- Walks list: for each node (`next` at node[1]):
  - If node[2] (flag byte) != 0 and *node (object ptr) non-null: calls `(*(vtable**)*node)[0](1)` — virtual destructor with arg 1
  - Frees node via FUN_00587bcf
- Zeros list head, tail, count, and other state fields
- If mutex was valid: calls `ReleaseMutex`

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0xac8 | ListHead | int* | First node pointer |
| +0xacc | ListState | int | Tail/count state fields |
| +0xad8 | MutexHandle | HANDLE | Win32 mutex for thread safety |
| +0xadc | MutexTimeout | DWORD | Wait timeout in ms |

**Struct offsets (node):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | ObjectPtr | int* | Object with vtable at [0] |
| +0x04 | NextPtr | int* | Next node in list |
| +0x08 | DestructFlag | byte | Non-zero if destructor should be called |

**Globals:**
- WaitForSingleObject — Win32 API (kernel32)
- ReleaseMutex — Win32 API (kernel32)

**Calls:**
- FUN_00587bcf — memory free/deallocation
- (vtable[0]) — virtual destructor call on object

**Used by system:** docs/01-engine-architecture.md — thread-safe resource cleanup with mutex synchronization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00582f60 — SEH-Protected Linked List Destruction

Source: unknown | Confidence: high
Destroys a linked list with SEH (Structured Exception Handling) protection. Walks list calling virtual destructors, frees nodes, and zeros state. Similar to FUN_0057e6e0 but uses SEH instead of mutex.

**Key logic:**
- Sets up SEH handler (LAB_0059cdc8) via FS:[0] registration
- Reads list head from `*param_1`
- Walks linked list: for each node (`next` at node[1]):
  - If node[2] (flag byte) != 0 and *node (object ptr) non-null: calls `(*(vtable**)*node)[0](1)` — virtual destructor
  - Frees node via FUN_00587bcf
- After walk (or exception): zeros head/tail/count fields (param_1[0..3])
- Restores original ExceptionList

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | ListHead | int* | First node pointer |
| +0x04 | ListTailOrState | int | List state |
| +0x08 | ListCount | int | Element count |

**Struct offsets (node):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | ObjectPtr | int* | Object with vtable at [0] |
| +0x04 | NextPtr | int* | Next node in list |
| +0x08 | DestructFlag | byte | Non-zero if destructor should be called |

**Calls:**
- FUN_00587bcf — memory free/deallocation
- (vtable[0]) — virtual destructor call on object

**Used by system:** docs/01-engine-architecture.md — robust resource cleanup with exception safety

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00584ff0 — String Copy to Buffer with Length Cap

Source: unknown | Confidence: high
Copies a string into a fixed-size buffer (16 chars max) at offset +0x64 and zeros a flag byte at +0x74.

**Key logic:**
- Null-terminates buffer at `param_1 + 0x64`
- If `param_2 != NULL`: copies `param_2` into buffer via `_strncpy` with max length 0x10 (16)
- Zeros byte at `param_1 + 0x74` (clears associated flag/state)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x64 | NameBuffer | char[16] | Fixed-size name/string buffer |
| +0x74 | AssociatedFlag | byte | Flag cleared after string copy |

**Calls:**
- _strncpy — CRT string copy with length limit

**Used by system:** docs/01-engine-architecture.md — object name assignment utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005875c0 — Buffer Reallocation and Data Copy

Source: unknown | Confidence: high
Reallocates a buffer: allocates new memory via FUN_005874d0, copies content from old buffer, frees old buffer, and returns success/error code.

**Key logic:**
- Calls `FUN_005874d0(param_1[1] + param_2, &new_ptr)` — allocates new buffer with size = current_capacity + additional
- If allocation succeeds:
  - Copies `param_1[2]` bytes from old buffer (`*param_1`) to new buffer
  - Bulk copy: `size >> 2` words (4-byte chunks)
  - Remainder: `size & 3` bytes individually
  - Frees old buffer via FUN_00587bcf
  - Sets `*param_1 = new_ptr`
- Returns `uVar2 & 0xffffff00` (success/error from allocation)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | BufferPtr | void* | Current data buffer |
| +0x04 | BufferCapacity | int | Current allocated capacity |
| +0x08 | BufferSize | int | Current used size in bytes |

**Calls:**
- FUN_005874d0 — buffer allocation (new with size)
- FUN_00587bcf — memory free/deallocation

**Used by system:** docs/01-engine-architecture.md — dynamic buffer growth utility

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00589d74 — Critical Section Leave (Slot 0xd)

Source: unknown | Confidence: high
Delegates to critical section leave function with fixed slot index 0xd (13). Wrapper for indexed CRITICAL_SECTION release.

**Key logic:**
- Single call: `FUN_0058e04b(0xd)` — leave critsec for slot 13

**Calls:**
- FUN_0058e04b — CritSect leave by slot index (docs/20, docs/21)

**Used by system:** docs/01-engine-architecture.md — thread synchronization leave wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00593db8 — Global Callback Dispatcher with Null Check

Source: unknown | Confidence: medium
Calls a global function pointer if it is registered. Returns success/failure.

**Key logic:**
- Checks `DAT_008d41b4` (global callback pointer)
- If non-null: calls `(*DAT_008d41b4)(param_1)`, returns 1 if result non-zero
- Returns 0 if callback null or returns 0

**Globals:**
- `DAT_008d41b4` — global callback function pointer

**Calls:**
- (indirect) callback via DAT_008d41b4

**Used by system:** docs/01-engine-architecture.md — optional global hook/callback mechanism

**Moddability:** hookable — replaceable via global function pointer

<!-- target: docs/20-math-utilities.md -->

## FUN_00598af5 — Object Constructor with VTable Setup and SEH

Source: unknown | Confidence: medium
C++ object constructor. Sets up vtable pointers, initializes fields, registers SEH handler, and calls sub-constructor.

**Key logic:**
- Calls FUN_0058a5d8 (CRT pre-init)
- If stack param at EBP+0x10 (arg3) non-zero:
  - Sets `*this = DAT_005b9bc0` (vtable pointer)
  - Sets `this[0xb] = 0` (field at +0x2c)
  - Sets `this[2] = &PTR_FUN_005b9bb4` (secondary vtable/interface)
  - Sets SEH handler flag
- Sets `this[1] = 0` (field at +0x04)
- Sets up `this->vtable = &PTR_LAB_005b9ba4` (final vtable assignment)
- Calls FUN_005993eb with params from EBP+0x08 and EBP+0x0c
- Restores ExceptionList from SEH chain
- Returns constructed object pointer

**Globals:**
- DAT_005b9bc0 — primary vtable pointer
- PTR_FUN_005b9bb4 — secondary interface/vtable
- PTR_LAB_005b9ba4 — final vtable pointer

**Calls:**
- FUN_0058a5d8 — CRT/object pre-initialization
- FUN_005993eb — sub-constructor/initializer

**Used by system:** docs/01-engine-architecture.md — C++ object construction with exception safety

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599348 — Buffer Truncation/Shrink

Source: unknown | Confidence: high
Removes a range of bytes from a buffer, shifting remaining content left and updating size.

**Key logic:**
- If buffer size (`*(param_1+8)`) < `param_2`: calls FUN_0059af68 (error/assert)
- Calls FUN_005995e5 (pre-modify check)
- Clamps `param_3` (bytes to remove) to `(size - param_2)` if needed
- If param_3 != 0:
  - Shifts data: copies from `(buffer+param_2+param_3)` to `(buffer+param_2)` for `(remaining - param_3)` bytes via FUN_0058b130 (memmove)
  - Computes `new_size = size - param_3`
  - Calls FUN_00599560(new_size, 0) to validate/set capacity
  - If valid: updates size, null-terminates at `buffer[new_size]`
- Returns param_1

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | BufferPtr | int | Data buffer |
| +0x04 | DataStart | int | Offset to data start |
| +0x08 | BufferSize | int | Current used size |

**Calls:**
- FUN_0059af68 — error handler / assertion
- FUN_005995e5 — pre-modify buffer check
- FUN_0058b130 — memcpy/memmove (docs/06)
- FUN_00599560 — capacity validation

**Used by system:** docs/01-engine-architecture.md — dynamic buffer management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005998a1 — VTable Fixup During Construction

Source: unknown | Confidence: high
Adjusts vtable pointer of an object during construction and calls initialization helper.

**Key logic:**
- Sets vtable: `*(void***)(*(*param_1 + 4) + (int)param_1) = &PTR_LAB_005b9c40`
- Calls FUN_00599be5 (sub-initializer)

**Calls:**
- FUN_00599be5 — sub-object initializer

**Used by system:** docs/01-engine-architecture.md — C++ object construction vtable fixup pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040dcd0 — State Machine Initializer

Source: unknown | Confidence: high
Initializes a state machine/progress tracker. Sets state fields, calls lookup, validates result.

**Key logic:**
- Sets param_1[0x21] = 0 (state detail)
- Sets `*param_1 = 1` (state = starting)
- Calls FUN_0040d490 (prep)
- Calls FUN_00568210(param_2) to look up entry → stores at param_1[0x21]
- If lookup returns 0: returns 0 (not found)
- Sets `*param_1 = 2` (state = processing)
- Calls FUN_0040ddf0 (process step)
- If succeeds: returns 1
- Sets `*param_1 = -1` (state = error), returns 0

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | State | int | 1=starting, 2=processing, -1=error |
| +0x84 | ResultID | int | Result from FUN_00568210 lookup |

**Calls:**
- FUN_0040d490 — preparation step
- FUN_00568210 — section/entry lookup
- FUN_0040ddf0 — processing step

**Used by system:** docs/01-engine-architecture.md — state-driven initialization sequence

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005511a0 — Object Destructor with Array Cleanup

Source: unknown | Confidence: medium
Destructor for a C++ object containing a direct pointer resource and a counted array of resources. Releases each via FUN_00557470 (unload/release) then frees memory via FUN_00587bcf.

**Key logic:**
- Reads `*param_1` (first field, direct pointer): if non-null, calls FUN_00557470 (release) then FUN_00587bcf (free), zeros field
- Reads `param_1[6]` (7th field, array pointer at +0x18): if non-null, reads allocation size prefix at `*(param_1[6] - 4)`, loops that many times calling FUN_00557470 (release per element), then frees allocation base via FUN_00587bcf
- Zeros array pointer field
- Calls FUN_004b0170 (game state/release signal)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | DirectResourcePtr | int* | Single resource pointer, freed directly |
| +0x18 | ArrayResourcePtr | int* | Pointer to counted array, allocation header at -4 |

**Calls:**
- FUN_00557470 — resource release/unload (per element, per docs/06, docs/17, docs/19)
- FUN_00587bcf — memory free/deallocation (per docs/01, docs/06)
- FUN_004b0170 — game state update/release notification (per docs/01, docs/09)

**Used by system:** docs/01-engine-architecture.md — generic C++ object destructor pattern used by resource management subsystem

**Moddability:** hardcoded


<!-- target: docs/20-math-utilities.md -->

## FUN_00551390 — Per-Entity Data Block Copy from Parameter Table

Source: unknown | Confidence: medium
Copies per-entity data from a parameter table into entity slots, indexed by entity type byte.

**Key logic:**
- Reads max index from `param_1+0x1c → +0x14` (table header)
- If `param_3 < max_index`: sets `param_1+8 = param_3` (use provided index)
- Else: sets `param_1+8 = max_index - 1` (clamp)
- Iterates over `param_1+0x14` entity entries (each stride 0x22 dwords = 0x88 bytes)
- For each entry whose type byte (low byte of flags) < 0xff:
  - Computes source table offset: `(param_1+8) * 0x20 + (type_byte * 0x2c + 0x28)` from table at `param_1+0x1c → +0x10`
  - Calls FUN_0053b4c0(puVar3 + 1) — copy-initializes entity slot
  - Copies 3 dwords from source at offsets +4, +8, +0xc to entity at offsets 0xd, 0xe, 0xf (within 0x88-byte slot)
- Sets flag `param_1+4 |= 0x10000`
- If param_2 != 0: calls FUN_0054b330(0x40, 0x20, 0) — bitmask clear on scene graph

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x4 | uint | Flags (dirty bitmask) |
| +0x8 | int | Current/selected entity index |
| +0x14 | int | Entity count |
| +0x18 | uint** | Entity array pointer |
| +0x1c | int* | Table header pointer → +0x10 = source data table, +0x14 = max index |

**Calls:**
- FUN_0053b4c0 — copy/init call (unknown, triage: unidentified logic)
- FUN_0054b330 — BitmaskClear on scene graph node (docs/06)

**Used by system:** docs/01-engine-architecture.md — entity/param system initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00554c30 — State Flag Iteration Across Entries

Source: unknown | Confidence: medium
Walks a linked list of nodes and clears/resets state flags on child entries matching a criterion.

**Key logic:**
- Outer loop: traverse linked list starting at `param_1+0x24`, following `+0xc0` next pointers
- For each node: iterate over `+0xa4` entries (count) at stride 0x25 dwords (= 0x94 bytes), starting at `+0xa8+0x8c`
- For each entry: check if byte at offset `-0x13` from current entry has bit 2 set
- If bit 2 set AND `entry->+0x54->+0x14 == 0` (nested null check):
  - Clear bit 0 at `entry->+0x54->+0x18` (disable flag)
  - Set bit 3 at same location (enable flag)
  - Call `FUN_0053f720(entry->+0x54, 0)` — format validation or device call (docs/19 renderer)
  - Set bit 1 at same location (enable flag)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x24 | int* | Linked list head (next at +0xc0) |
| +0xa4 | int | Entry count per node |
| +0xa8 | int | Entry array base |

**Calls:**
- FUN_0053f720 — format/device validation call (docs/19 renderer)

**Used by system:** docs/01-engine-architecture.md — state flag management across hierarchical entries

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005570c0 — Nested Linked List Traversal with Dirty Mark

Source: unknown | Confidence: medium
Traverses nested linked lists and marks all downstream nodes dirty via FUN_00556cd0.

**Key logic:**
- First traversal: iterate nodes starting at `param_1+0x100`, each with `+0x104` next pointer
  - For each node: traverse sub-list starting at `+0xec`, each with `+0x4c` next pointer
  - Call `FUN_00556cd0(param_2, 0)` on each sub-node — D3D dirty mark
- Second traversal: iterate nodes starting at `param_1+0x108`, each with `+0x4c` next pointer
  - Call `FUN_00556cd0(param_2, 0)` on each node — D3D dirty mark

**Calls:**
- FUN_00556cd0 — D3DMarkDirty: sets dirty flags on scene graph resource descriptors (docs/19)

**Used by system:** docs/01-engine-architecture.md — scene graph dirty propagation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00559a40 — Large Buffer Zero-Init (0x60 Dwords)

Source: unknown | Confidence: high
Zero-initializes a struct buffer of 0x60 dwords plus specific header fields.

**Key logic:**
- Zeroes 0x60 dwords starting at `param_1+3` (= offset +0xc)
- Sets `param_1[0]`, `param_1[1]`, `param_1[2]` to 0 (offsets 0x0, 0x4, 0x8)
- Sets `param_1[0xc3]` and `param_1[0xc4]` to 0 (offsets 0x30c, 0x310)
- Total zeroed: 0x68 dwords + 2 extra at end = ~0x318 bytes of struct

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0–0x8 | int×3 | Header fields |
| +0xc–0x18c | int×0x60 | Buffer body |
| +0x30c–0x310 | int×2 | Tail fields |

**Used by system:** docs/01-engine-architecture.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00564650 — Sleep Wrapper

Source: unknown | Confidence: high
Wrapper around Win32 Sleep() with parameter passthrough.

**Key logic:**
- `Sleep(param_1)` — calls Win32 Sleep API directly
- No return value

**Calls:** Sleep (Win32 API)

**Used by system:** docs/01-engine-architecture.md — threading/timing wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00565ef0 — Reverse Path Search for Backslash Separator

Source: unknown (filesystem/path utils) | Confidence: high
Extracts filename portion from a full path by scanning backwards for the last backslash separator.

**Key logic:**
- Calls `FUN_005662d0()` — Directory Entry Iterator (docs/08) to get current entry path
- If path is non-null:
  - Computes string length via manual strlen loop
  - Positions pointer at end of string
  - Scans backwards for last `\` backslash character
  - Returns pointer to character after last backslash (filename portion)
- If no backslash found: returns pointer to start of string
- If path is null: returns null

**Calls:**
- FUN_005662d0 — Directory Entry Iterator (docs/08)

**Used by system:** docs/01-engine-architecture.md — file path parsing utility (similar to basename)

**Algorithm family:** string parsing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00567a00 — Struct Zero-Init (9 Words + Loop)

Source: unknown | Confidence: high
Zero-initializes a 14-dword struct.

**Key logic:**
- Sets `param_1[9]` through `param_1[0xd]` (= offsets +0x24 through +0x34) to 0 explicitly
- Loop: zeroes `param_1[0]` through `param_1[8]` (= offsets 0x0 through +0x20) — 9 dwords
- Returns param_1

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0–+0x20 | int×9 | First block (loop-zeroed) |
| +0x24–+0x34 | int×5 | Second block (explicitly zeroed) |

**Used by system:** docs/01-engine-architecture.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0057a0c0 — 16-Byte Memory Comparison for Equality

Source: unknown | Confidence: high
Compares two 16-byte memory blocks for byte-exact equality.

**Key logic:**
- Uses pointer subtraction trick: `param_2 = param_2 - param_1` (distance between blocks)
- Compares 16 bytes by indexing `param_1[i]` vs `param_1[param_2 + i]`
- Returns 1 if all 16 bytes match, 0 if any differ
- Stops early on first mismatch

**Calls:** None (inline comparison)

**Used by system:** docs/01-engine-architecture.md — 16-byte comparison utility (possibly UUID/GUID or 128-bit key comparison)

**Algorithm family:** memory comparison

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a850 — VTable Bool Check (Inverted)

Source: unknown | Confidence: medium
Calls a virtual method at vtable offset 0xa0 and returns the inverse boolean result.

**Key logic:**
- `param_1` is a pointer-to-pointer (vtable)
- Calls `(**(code **)(*(int *)*param_1 + 0xa0))(param_2, param_3, param_4)`
- Returns true if the virtual method returned 0 (inverted check)
- Acts as a guard/test: method returns non-zero on failure/success and this inverts it

**Used by system:** docs/01-engine-architecture.md — virtual method call wrapper for boolean testing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b550 — Ring Buffer Push with Wrap Check

Source: unknown | Confidence: high
Pushes data to a ring buffer with capacity bound and modulo wrap-around.

**Key logic:**
- Reads short at `+0x1002` (current count/tail position) and `+0x1000` (base/head offset)
- Buffer capacity: 0x1000 bytes (4096)
- Checks: `current_count + param_3 < 0x1001` — prevents overflow
- If overflow: returns error without writing
- If valid:
  - Computes write position with modulo: `(base + count) & 0x80000fff` with sign-adjust for negative
  - Copies `param_3` bytes from `param_2` to ring buffer
  - Updates count at `+0x1002 += param_3`
  - Returns success
- Modulo arithmetic: `(index & 0x80000fff)` with sign-correcting branch for negative values

**Struct offsets (param_1 — ring buffer):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1000 | short | Base/head offset |
| +0x1002 | short | Current count/tail position |
| +0x1004+ | byte[] | Ring buffer data (0x1000 bytes capacity) |

**Used by system:** docs/01-engine-architecture.md — ring buffer data structure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057e760 — Mutex-Protected Linked List Flush/Destroy

Source: unknown | Confidence: high
Flushes and destroys a linked list under mutex protection, freeing all nodes and optionally their data.

**Key logic:**
- Acquires mutex at `param_1+0xb10` via WaitForSingleObject with timeout from `param_1+0xb14`
- If mutex unavailable: returns null for output
- Reads linked list head from `param_1+0xb00`
  - Node layout: [0]=data_ptr, [1]=next_ptr, byte[2]=free_data_flag
- Iterates list: for each node:
  - If `node[2]` (byte) is non-zero: calls `FUN_00587bcf(node[0])` — frees node's data
  - Calls `FUN_00587bcf(node)` — frees node itself
- Zeros all 4 list head fields at `param_1+0xb00` through `param_1+0xb0c`
- Releases mutex via ReleaseMutex

**Struct offsets (param_1 — synchronized list):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xb00 | int* | Linked list head (node.next at +0x4) |
| +0xb04 | int* | List tail/aux |
| +0xb08 | int* | List count/aux |
| +0xb0c | int* | List aux |
| +0xb10 | HANDLE | Mutex handle |
| +0xb14 | DWORD | WaitForSingleObject timeout |

**Calls:**
- WaitForSingleObject (Win32 API)
- FUN_00587bcf — memory free/dealloc (used throughout engine)
- ReleaseMutex (Win32 API)

**Used by system:** docs/01-engine-architecture.md — thread-safe list cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583050 — Destroy Linked List with SEH, Call Destructors

Source: unknown | Confidence: high
Destroys a linked list under SEH protection, calling virtual destructors before freeing nodes.

**Key logic:**
- Sets up SEH handler frame (exception registration)
- Iterates linked list from `*param_1`
- For each node (layout: [0]=data_ptr, [1]=next_ptr, [2]=destructor_flag):
  - If node[2] (byte flag) is non-zero AND node[0] (data_ptr) non-null:
    - Calls `(**(code **)(*(int *)*piVar2 + 4))(1)` — virtual destructor at vtable+4, arg 1
  - Frees node with `FUN_00587bcf`
- Zeroes all 4 list head fields at `param_1[0..3]`
- Restores previous exception handler

**Calls:**
- FUN_00587bcf — memory free/dealloc
- ExceptionList manipulation (SEH frame)

**Used by system:** docs/01-engine-architecture.md — SEH-safe list destruction with virtual destructor calls

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585030 — Allocation Wrapper

Source: unknown | Confidence: high
Thin wrapper around FUN_0057a0f0 (byte-aligned memory copy with offset), passing stack address as parameter.

**Key logic:**
- Calls `FUN_0057a0f0(&stack0x00000004)` — memcpy/allocation with a stack-relative source address
- No return value

**Calls:**
- FUN_0057a0f0 — byte-aligned memory copy with offset (triage: Mem/Copy)

**Used by system:** docs/01-engine-architecture.md — memory allocation utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586170 — Handle Close & Linked List Cleanup

Source: unknown | Confidence: high
Closes a handle and then destroys a linked list, freeing nodes and their data.

**Key logic:**
- If byte at `param_1[6]` (flag at offset +0x18) is non-zero:
  - Calls `CloseHandle((HANDLE)param_1[4])` — closes handle at +0x10
  - Zeros handle slot
- Walks linked list from `*param_1`
- For each node (layout: [0]=data_ptr, [1]=next_ptr, [2]=free_data_flag):
  - If flag byte at node[2] non-zero AND node[0] non-null:
    - Calls `FUN_005867b0()` — SEH-guarded pool/free helper
    - Frees node data with `FUN_00587bcf(node[0])`
  - Frees node itself with `FUN_00587bcf`
- Zeros all 4 list head fields

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0 | int* | Linked list head |
| +0x10 | HANDLE | Handle to close |
| +0x18 | byte | Flag: non-zero = close handle |

**Calls:**
- CloseHandle (Win32 API)
- FUN_005867b0 — SEH-guarded pool/free helper
- FUN_00587bcf — memory free/dealloc

**Used by system:** docs/01-engine-architecture.md — handle + linked list cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586f10 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper that calls FUN_00599958 (object constructor with SEH + vtable init).

**Key logic:**
- Calls `FUN_00599958()` unconditionally
- No parameters, no return

**Calls:**
- FUN_00599958 — object constructor with SEH + vtable init (docs/08)

**Used by system:** docs/01-engine-architecture.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587620 — Buffer Write with Params

Source: unknown | Confidence: medium
Delegating wrapper that reads parameters from a struct and calls FUN_00587510 (memcpy-like copy).

**Key logic:**
- Extracts `param_2[0]` (data ptr) and `param_2[2]` (size/count) from parameter struct
- Calls `FUN_00587510(param_2[0], param_2[2])` — memory copy operation
- Returns param_1 (this pointer passthrough)

**Calls:**
- FUN_00587510 — Memory copy, memcpy-like with word-aligned fast path

**Used by system:** docs/01-engine-architecture.md — data buffer write utility

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0058dfea — Critical Section Lazy Init + Enter

Source: CRT/threading support | Confidence: high
Lazy-initializes and enters a critical section from a global array of tracked critical sections.

**Key logic:**
- Indexes into global array at `DAT_005e6c80` (array of pointers to CRITICAL_SECTION)
- If slot is null:
  - Allocates `_malloc(0x18)` — sizeof(CRITICAL_SECTION)
  - Calls `InitializeCriticalSection` on allocated memory
  - Stores pointer in array slot
- Double-checked locking pattern (check, allocate+init, re-check to avoid race)
- Enters the critical section via `EnterCriticalSection`

**Globals:**
- `DAT_005e6c80` — global array of CRITICAL_SECTION pointers

**Calls:**
- _malloc — CRT allocator
- InitializeCriticalSection (Win32 API)
- EnterCriticalSection (Win32 API)
- __amsg_exit — CRT error on allocation failure
- FUN_0058e04b — callback registration context push/pop

**Used by system:** docs/01-engine-architecture.md — thread synchronization infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00594b76 — Memory Region Validation & Heap Lookup

Source: CRT heap internals | Confidence: medium
Validates a memory pointer against registered heap regions, returning region metadata and an adjusted value.

**Key logic:**
- Iterates a linked list of region descriptors (starting at `PTR_LOOP_005e7968`)
- Each descriptor has bounds: `ppuVar1[4]` (low bound) and `ppuVar1[5]` (high bound)
- Finds first region where `low_bound < param_1 < high_bound`
- If not found: returns 0
- Validates alignment: `param_1 & 0xf` must be 0 (16-byte aligned)
- Validates page offset: `param_1 & 0xfff >= 0x100` (not in first 256 bytes of page)
- If validation passes:
  - Stores region descriptor in `*param_2`
  - Stores page-aligned address (`param_1 & 0xfffff000`) in `*param_3`
  - Returns computed value: `(param_1 - 0x100 - page_base) >> 4 + 8 + page_base`

**Used by system:** docs/01-engine-architecture.md — CRT heap validation utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598b5d — Object Constructor with SEH + Vtable Init

Source: unknown | Confidence: medium
Constructs an object with SEH protection, initializing vtable pointers and fields.

**Key logic:**
- Calls `FUN_0058a5d8()` — likely allocation or pre-init
- Sets up vtable at `*extraout_ECX = &DAT_005b9bc0`
- Sets `extraout_ECX[0xb] = 0` field
- Sets `extraout_ECX[2] = &PTR_FUN_005b9bb4` — another vtable/function pointer
- Sets vtable at `*(extraout_ECX + 4) + extraout_ECX = &PTR_LAB_005b9ba4` — offset-based vtable
- Calls `FUN_0059a8fa()` — post-init
- Restores SEH exception handler

**Calls:**
- FUN_0058a5d8 — allocation/pre-init
- FUN_0059a8fa — post-init

**Used by system:** docs/01-engine-architecture.md — object construction with MSVC SEH

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005993eb — Object Init with VTable + Flag Set

Source: unknown | Confidence: medium
Initializes an object's vtable, sets a capacity field, and conditionally activates a flag.

**Key logic:**
- Sets `param_1+0x2c = 0` (null pointer)
- Sets `param_1+0x28 = param_2` (storage parameter)
- Sets `param_1+0x30 = 0x20` (capacity/size = 32)
- Calls `FUN_0059a948()` — post-init
- If `param_1+0x28 == 0`: calls `FUN_0059a5fe(param_1+4 | 4, 0)` — set flag bit 2
- If `param_3 != 0`: calls `FUN_0059a8fa()` — secondary init

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x28 | int | Storage parameter |
| +0x2c | int* | Pointer field (nulled) |
| +0x30 | byte | Capacity/size field (0x20 = 32) |

**Calls:**
- FUN_0059a948 — post-init
- FUN_0059a5fe — flag set operation
- FUN_0059a8fa — secondary init

**Used by system:** docs/01-engine-architecture.md — object initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005998cf — Cleanup Wrapper

Source: unknown | Confidence: high
Registers a cleanup callback via FUN_00587b3e (MSVC _atexit-like registration).

**Key logic:**
- Calls `FUN_00587b3e(&LAB_005998db)` — registers address 0x005998db for deferred cleanup
- The registered address likely contains destructor/cleanup code

**Calls:**
- FUN_00587b3e — deferred function registration (MSVC _atexit-like)

**Used by system:** docs/01-engine-architecture.md — cleanup/atexit registration

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a428 — Double Indirect Counter Update

Source: unknown | Confidence: medium
Updates two counters through double-indirection (pointers-to-pointers).

**Key logic:**
- `**(param_1 + 0x30) -= param_2` — decrements target at double-pointer +0x30 by param_2
- `**(param_1 + 0x20) += param_2 * 2` — increments target at double-pointer +0x20 by 2× param_2

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x20 | int** | Double indirect counter (incremented by 2×param_2) |
| +0x30 | int** | Double indirect counter (decremented by param_2) |

**Used by system:** docs/01-engine-architecture.md — counter/refcount balanced update utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ac3f — VTable Pointer Setter

Source: unknown | Confidence: high
Sets the first dword of a struct to a vtable pointer constant.

**Key logic:**
- `*param_1 = &PTR_LAB_005b9d54` — sets vtable pointer

**Used by system:** docs/01-engine-architecture.md — vtable/object type initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c634 — SEH Unwind with Field Free

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that frees a local variable at EBP+8 during stack unwinding.

**Key logic:**
- Reads local at `unaff_EBP + 8`
- Calls `FUN_00587bcf()` — memory free
- Part of MSVC C++ exception handling cleanup

**Calls:**
- FUN_00587bcf — memory free/dealloc

**Used by system:** docs/01-engine-architecture.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c790 — SEH Unwind with Field Free (EBP-0x10)

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that frees a local variable at EBP-0x10 during stack unwinding.

**Key logic:**
- Reads local at `unaff_EBP - 0x10`
- Calls `FUN_00587bcf()` — memory free

**Calls:**
- FUN_00587bcf — memory free/dealloc

**Used by system:** docs/01-engine-architecture.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c8d8 — SEH Unwind Cleanup Call

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that delegates to FUN_0057bc70 (linked list destructor with vtable cleanup).

**Key logic:**
- Calls `FUN_0057bc70()` — single vtable pointer set / node destructor

**Calls:**
- FUN_0057bc70 — single vtable pointer set (triage: Entity/Vtable set)

**Used by system:** docs/01-engine-architecture.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ce9a — SEH Unwind with Single Call

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that delegates cleanup to FUN_00586460.

**Key logic:**
- Calls `FUN_00586460()` — cleanup/dealloc function

**Calls:**
- FUN_00586460 — cleanup/dealloc (unknown)

**Used by system:** docs/01-engine-architecture.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cff6 — SEH Unwind with Single Call

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that delegates to FUN_00586170 (Handle Close & Linked List Cleanup, already documented).

**Key logic:**
- Calls `FUN_00586170()` — handle close + linked list cleanup

**Calls:**
- FUN_00586170 — Handle Close & Linked List Cleanup (docs/01)

**Used by system:** docs/01-engine-architecture.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d15b — SEH Unwind with Field Free (EBP-0x10)

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that frees a local variable at EBP-0x10 during stack unwinding.

**Key logic:**
- Reads local at `unaff_EBP - 0x10`
- Calls `FUN_00587bcf()` — memory free

**Calls:**
- FUN_00587bcf — memory free/dealloc

**Used by system:** docs/01-engine-architecture.md — SEH unwind infrastructure

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d338 — SEH Unwind Release Locale Refcount

Source: CRT/exception handling | Confidence: medium
C++ SEH unwind handler that releases a locale reference count during stack unwinding.

**Key logic:**
- Reads local at `unaff_EBP - 0x10`
- Calls `FUN_00599796(local, &DAT_008d4478)` — locale refcount release
- FUN_00599796 is an empty stub (likely stripped at link time)

**Globals:**
- `DAT_008d4478` — locale data reference

**Calls:**
- FUN_00599796 — locale refcount release (empty stub)

**Used by system:** docs/01-engine-architecture.md — CRT locale cleanup in SEH unwind

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d544 — SEH Unwind with Single Call

Source: CRT/exception handling | Confidence: high
C++ SEH unwind handler that delegates to FUN_0059a9c2 (single function call wrapper).

**Key logic:**
- Calls `FUN_0059a9c2()` — single function call wrapper

**Calls:**
- FUN_0059a9c2 — single function call wrapper (triage: Engine/Call)

**Used by system:** docs/01-engine-architecture.md — SEH unwind infrastructure

**Moddability:** hardcoded
<!-- target: docs/20-math-utilities.md -->

## FUN_00551440 — Entity Flag Set + Sub-Init Chain

Source: unknown | Confidence: medium
Sets entity flags and calls three initialization sub-functions.

**Key logic:**
- Sets bits at param_1+0x4: clears 0xfffe2fff, sets 0x2000 (entity active flag)
- Calls FUN_00551390(0,0) — likely renderable/scene object attach (renderer)
- Calls FUN_005563e0 — unknown init step
- Calls FUN_00556440 — unknown init step
- Zeros param_1+0x10 (a counter or state field)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x04 | Flags | uint | Bit 0x2000 set after clearing 0xfffe2fff |
| +0x10 | Counter/State | int | Zeroed |

**Calls:**
- FUN_00551390(0,0) — renderable/scene attach
- FUN_005563e0 — unknown init
- FUN_00556440 — unknown init (called by bounds check function at 0x00556700)

**Used by system:** docs/01-engine-architecture.md — entity/object initialization sequence

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00553050 — Two-Field Setter

Source: unknown | Confidence: medium
Simple setter storing two parameters into object fields at +0x5c and +0x60.

**Key logic:**
- Writes param_2 to param_1+0x5c
- Writes param_3 to param_1+0x60

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x5c | value1 | int | Written from param_2 |
| +0x60 | value2 | int | Written from param_3 |

**Used by system:** docs/01-engine-architecture.md — object property setter

**Moddability:** hookable — values passed as parameters

<!-- target: docs/01-engine-architecture.md -->

## FUN_00554d70 — UI Cleanup Iterator

Source: unknown | Confidence: low
Iterates UI item collection, disposes each item matching a target pointer, clears state flags.

**Key logic:**
- Reads param_2[0x15] (offset +0x54) as a control block pointer iVar1
- If *(iVar1+0x14) is non-null (active UI list):
  - Loops iVar3 from 0 to param_1[0x4ec] (item count, stride 4)
  - Calls vtable dispatch at param_1[0x440]+0xf0 to get item at index iVar3
  - If result matches param_2: calls FUN_00554610(0) (dispose helper)
  - Calls vtable destructor on the item (vtable+8)
- After loop: destroys the active list item itself via vtable
- Zeros iVar1+0x14 (active list pointer)
- Clears flags at iVar1+0x18: masks 0xfffffbf7
- Sets iVar1+0x38 to 0xbf800000 (-1.0f as float — sentinel/invalid value)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x440 | vtable/itemArray | int* | Array with vtable at offset +0xf0 for getter |
| +0x4ec | count | int | Item count (stride 4) |

**Struct offsets (param_2):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x54 | controlBlock | int* | Points to control structure |
| controlBlock+0x14 | activeList | int* | Active UI component list |
| controlBlock+0x18 | Flags | uint | Cleared bits 0x0808 (0xfffffbf7 mask) |
| controlBlock+0x38 | sentinel | float | Set to -1.0f |

**Calls:**
- FUN_00554610(0) — dispose/cleanup helper (renderer, docs/19)
- Vtable dispatch at +0xf0 — get item by index
- Vtable destructor at +8 — dispose item

**Used by system:** docs/01-engine-architecture.md — UI cleanup / object destruction pass

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00564690 — String Malloc + Copy (strdup)

Source: unknown | Confidence: high
Allocates memory and copies a null-terminated string (strdup equivalent).

**Key logic:**
- If param_1 is null: returns
- Calculates strlen via while loop
- Calls `_malloc(~uVar3)` — allocates strlen+1 bytes
- If allocation succeeds: copies string byte-by-byte
- Uses CRT `_malloc`, not operator_new

**Calls:** `_malloc` — CRT heap allocation

**Used by system:** docs/01-engine-architecture.md — string duplication utility

**Algorithm family:** string utility (strdup wrapper)

**Moddability:** hookable — source string passed as parameter

<!-- target: docs/20-math-utilities.md -->

## FUN_005684a0 — Object ID Lookup Across 9 Arrays

Source: unknown | Confidence: medium
Searches across 9 indexed arrays for an object matching a computed hash ID.

**Key logic:**
- Early exit: if param_2 is null or FUN_00568220(param_2) < 0 (invalid hash), returns 0
- Iterates local_4 from 0 to 8 (9 arrays):
  - For each array: reads array base from param_1[local_4]
  - Walks linked list: calls FUN_0049adb0 (next node) in nested loops
  - For each node: calls FUN_004979d0 (get ID/hash)
  - If ID matches param_2's hash: calls FUN_00568320 (linked list insert) and returns 1
  - Also walks a secondary chain via FUN_0055bfc0 with same ID comparison

**Calls:**
- FUN_00568220 — hash table entry search (docs/08-file-formats)
- FUN_0049adb0 — linked list node traversal helper
- FUN_004979d0 — get object ID/hash
- FUN_00568320 — doubly-linked list insertion (docs/21-audio-network-internals)
- FUN_0055bfc0 — secondary list walk function (renderer, docs/19)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00–+0x20 | arrays[9] | int*[9] | Array of 9 linked list heads (4 bytes each) |

**Used by system:** docs/01-engine-architecture.md — object registry / hash table lookup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a0f0 — Byte-Aligned Memory Copy with Offset

Source: unknown | Confidence: high
Copies 32 bytes (0x20) from source to destination with a byte-level offset.

**Key logic:**
- Copies 16 bytes in first loop: `param_1[i] = param_1[param_2 - param_1 + i]` for i=0..15
  - This computes dest[i] = src[i] where src = dest + (param_2 - dest) 
  - Effectively: src = param_2, dest = param_1, copy parameter is the byte offset between them
- Copies 16 more bytes in second loop: param_1+0x10[i] = (param_1+0x10)[param_2 - param_1 + i] for i=0..31
  - Continues copy for second half

**Used by system:** docs/01-engine-architecture.md — low-level byte-aligned memory copy utility

**Algorithm family:** memory copy (memcpy variant)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a880 — VTable Query with Stack Buffer Result

Source: unknown | Confidence: medium
Calls a vtable method to query object info, returns pointer to stack buffer.

**Key logic:**
- Reads *param_1 as object pointer
- Calls vtable dispatch at offset +0x78: `(**(code**)(*(int*)*param_1 + 0x78))(local_8, local_4)`
  - local_8 and local_4 are stack buffers (4 bytes each)
- If result is 0: returns null
- Returns pointer to local_8 (stack buffer — unsafe if used after return)

**Calls:** vtable[0x1e] (offset +0x78) — query method returning success/fail

**Used by system:** docs/01-engine-architecture.md — object property/status query via interface

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b5c0 — Ring Buffer Pop with Wrap Check

Source: unknown | Confidence: high
Pops bytes from a ring buffer, handling wraparound at 0x1000 boundary.

**Key logic:**
- Checks if param_3 (requested bytes) <= current count at param_1+0x1002 (ushort)
- If yes: loops param_3 times
  - Reads byte from ring buffer at position (param_1 + *(short*)(param_1+0x1000))
  - Writes to output buffer at param_2
  - Increments read position with modulo 0x1000 wrap: `(pos + 1) & 0x80000fff` with sign adjustment for negative
- Decrements count at param_1+0x1002 by param_3
- Returns 0x100 | 0x01 (0x101) on success

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x1000 | readPos | short | Current read position (mod 0x1000) |
| +0x1002 | count | short | Bytes available in buffer |

**Used by system:** docs/01-engine-architecture.md — ring buffer / FIFO byte stream reader

**Algorithm family:** ring buffer operations

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057e7e0 — Mutex-Protected Linked List Destruction

Source: unknown | Confidence: high
Destroys a mutex-protected linked list, freeing all nodes.

**Key logic:**
- Accesses list head at param_1+0xb1c
- Acquires mutex at param_1+0xb2c via WaitForSingleObject with timeout from param_1+0xb30
  - If mutex handle is null or wait fails: skips
- Walks linked list from *puVar4 (head):
  - For each node: saves next pointer (puVar2[1])
  - If flag byte at puVar2+2 (offset +8) non-zero: frees *puVar2 via FUN_00587bcf
  - Frees node itself via FUN_00587bcf
- Zeros list fields (head, tail, count at +0xb1c through +0xb28)
- Releases mutex via ReleaseMutex

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0xb1c | listHead | int* | List start (4 int fields) |
| +0xb2c | mutexHandle | HANDLE | Win32 mutex |
| +0xb30 | mutexTimeout | DWORD | WaitForSingleObject timeout |

**Calls:**
- WaitForSingleObject — Win32 API
- ReleaseMutex — Win32 API
- FUN_00587bcf — memory deallocation (operator delete)

**Used by system:** docs/01-engine-architecture.md — thread-safe list cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585220 — Status Check via VTable Dispatch

Source: unknown | Confidence: medium
Checks object status via vtable method against threshold.

**Key logic:**
- If param_2 (output byte) non-null: writes param_1+0x5d to *param_2
- Calls vtable[+0xa4]() — status query
- Reads threshold param_1[0x18] (+0x60)
- If param_3 non-null: writes (status < threshold) to *param_3
- If param_1+0x5d non-zero AND status < threshold: returns 1 (busy)
- Else: returns 0 (idle)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x5d | busyFlag | byte | Non-zero when processing |
| +0x60 | threshold | int | Comparison threshold |

**Calls:** vtable[+0xa4] — status query method

**Used by system:** docs/01-engine-architecture.md — object status polling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005861e0 — CloseHandle Wrapper

Source: unknown | Confidence: high
Conditionally closes Win32 handle at +0x54, guarded by flag at +0x5c.

**Key logic:**
- If byte at param_1+0x5c non-zero:
  - CloseHandle(*(HANDLE*)(param_1+0x54))
  - On success: zeros param_1+0x54

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x54 | handle | HANDLE | Win32 handle |
| +0x5c | validFlag | byte | Guard flag |

**Calls:** CloseHandle — Win32 API

**Used by system:** docs/01-engine-architecture.md — handle cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586f20 — Single Function Call Wrapper

Source: unknown | Confidence: high
Static init registration — calls FUN_00587b3e with LAB_00586f30.

**Key logic:**
- Calls FUN_00587b3e(&LAB_00586f30) — MSVC _atexit-style deferred registration

**Calls:** FUN_00587b3e — atexit/callback registration

**Used by system:** docs/01-engine-architecture.md — module static init

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587690 — Free Callback Registered Cleanup

Source: unknown | Confidence: high
Static cleanup registration — calls FUN_00587b3e with LAB_005876a0.

**Key logic:**
- Calls FUN_00587b3e(&LAB_005876a0) — registers cleanup callback

**Calls:** FUN_00587b3e — atexit/callback registration

**Used by system:** docs/01-engine-architecture.md — module cleanup registration

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0058a02c — Memory Block Validation Check

Source: unknown | Confidence: medium
Validates a memory block, checking for corruption flags.

**Key logic:**
- Calls FUN_0058a05a(param_1) — basic memory validation
- If validation fails: returns -1
- If byte at param_1+0xd has bit 0x40 set:
  - Calls FUN_00592891(param_1+0x10) — error/overflow flag check
  - If non-zero: returns -1 (error)
- Returns 0 (valid)

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x0d | flags | byte | Bit 0x40 = corruption/overflow flag |
| +0x10 | dataPtr | int | Pointer checked by FUN_00592891 |

**Calls:**
- FUN_0058a05a — memory block base validation
- FUN_00592891 — error/overflow flag check (docs/06)

**Used by system:** docs/01-engine-architecture.md — heap/memory integrity validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058c1e0 — Critical Section Enter

Source: unknown | Confidence: high
Enters a critical section, with fast-path for small index values.

**Key logic:**
- If param_1 < 0x14 (20): calls FUN_0058dfea(param_1 + 0x1c) — enter critsec by adjusted index
- Else: calls EnterCriticalSection(param_2 + 0x20) — enter by explicit LPCRITICAL_SECTION

**Calls:**
- FUN_0058dfea — enter critical section by index
- EnterCriticalSection — Win32 API

**Used by system:** docs/01-engine-architecture.md — threading synchronization entry

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598bbc — Object Constructor with SEH + VTable Init Chain

Source: unknown | Confidence: medium
C++ object constructor with SEH frame, vtable setup, sub-init chain.

**Key logic:**
- FUN_0058a5d8() — SEH prologue / stack probe
- SEH setup with ExceptionList
- Sets vtable to PTR_FUN_005b9c04
- Calls FUN_0059a4c9 and FUN_00598c1c — init sub-functions
- Switches vtable to PTR_FUN_005b9bcc (base class vtable)
- Calls FUN_005994bc(uVar1, 0) — destructor registration
- SEH teardown — restore ExceptionList

**Calls:**
- FUN_0058a5d8 — SEH handler init / stack probe
- FUN_00598c1c — sub-init (constructor chain)
- FUN_0059a4c9 — sub-init (constructor chain)
- FUN_005994bc — destructor registration

**Used by system:** docs/01-engine-architecture.md — C++ SEH-protected constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005998e5 — VTable Set + Sub-Call

Source: unknown | Confidence: medium
Sets vtable pointer at computed address, calls init method.

**Key logic:**
- Computes: *(int*)(*param_1 + 4) + (int)param_1 — base + vtable-derived offset
- Writes PTR_LAB_005b9c48 (vtable) to computed address
- Calls FUN_00599be5

**Calls:** FUN_00599be5 — init continuation

**Used by system:** docs/01-engine-architecture.md — C++ vtable patch in constructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ac63 — Exception Destructor with Conditional Free

Source: unknown | Confidence: high
Destructor that optionally frees the object based on a flag.

**Key logic:**
- Calls FUN_0059ac7f() — base destructor / cleanup
- If bit 0 of param_2 is set: calls FUN_00587bcf(param_1) — free the object
- Returns param_1

**Calls:**
- FUN_0059ac7f — base destructor
- FUN_00587bcf — memory deallocation

**Used by system:** docs/01-engine-architecture.md — C++ exception-aware destructor

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004a11b0 — Global Flag Clear

Source: unknown | Confidence: high
Clears DAT_007ce250 to 0.

**Key logic:**
- DAT_007ce250 = 0

**Globals:** DAT_007ce250

**Used by system:** docs/01-engine-architecture.md — state reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005532a0 — Object Allocation with Zero-Init

Source: unknown | Confidence: high
Allocate and initialize engine object struct with zero-initialized members and sub-allocated 0x24-byte inner buffer.

**Key logic:** Calls FUN_0053c2a0 (parent constructor). Sets param_1[0]=2. Zeroes param_1[1..4]. Allocates 0x24-byte block, zeroes 9 fields. Sets inner ptr at param_1[5].

**Struct offsets:** +0x00 TypeOrID uint=2, +0x14 InnerBufferPtr uint*, +0x04-+0x20 Reserved

**Calls:** FUN_0053c2a0 — Parent constructor (engine subsystem, docs/06)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005550a0 — VTable Getter Wrapper

Source: unknown | Confidence: high
Call vtable method at offset 0x88 on embedded object, store result.

**Key logic:** Reads param_1[0x440] (+0x1100) as object pointer, calls vtable+0x88 method, stores result to *param_1.

**Calls:** Virtual call via vtable+0x88 on embedded object

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00557480 — Flag-Conditional Branch Dispatch

Source: unknown | Confidence: high
Branch dispatch based on flag bit at param_1+0x20.

**Key logic:** Checks bit 3 of byte at param_1+0x20. If CLEAR: calls FUN_00557ce0 (CRT string/init). If SET: calls FUN_00557670 (MTS init/PTEMP mesh). Returns 0xFFFFFFFF on error, 0 on success.

**Struct offsets:** +0x20 StateFlags byte — bit 3 selects path

**Calls:** FUN_00557ce0 (CRT utility, docs/20), FUN_00557670 (MTS init/mesh, docs/00)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055baf0 — Small Struct Init (9 uint32 fields)

Source: unknown | Confidence: high
Init 9-field struct: first=0, second=0xFFFFFFFF, rest=0.

**Key logic:** param_1[0]=0, param_1[1]=0xFFFFFFFF, param_1[2..8]=0

**Calls:** None

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055d410 — UI Property Value Setter

Source: unknown | Confidence: high
Set UI property at indexed offset, trigger UI update via dirty flag.

**Key logic:** param_2 (1,2,3) selects offset (+0x14/+0x24/+0x34). Calls FUN_005416a0 (DirectX vertex buffer setup). Sets DAT_008b8f28+0xec bit 0x800 (dirty flag).

**Struct offsets:** +0x04 Unknown1, +0x14 PropertyValue1, +0x24 PropertyValue2, +0x34 PropertyValue3

**Globals:** DAT_008b8f28 (UI context base) — dirty flag at +0xec

**Calls:** FUN_005416a0 — DirectX vertex buffer texture coord setup (docs/19)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00560fd0 — State Flag Bit Clear

Source: unknown | Confidence: high
Clear bit 1 (0x02) of state flag uint32 at param_1+0x24.

**Key logic:** *(uint*)(param_1+0x24) &= 0xFFFFFFFD

**Calls:** None

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00563000 — Polling Loop with Process Calls

Source: unknown | Confidence: high
Poll flag until zero, call two processing functions per iteration.

**Key logic:** Reads *param_1. While non-zero: calls FUN_00563410 (engine process), FUN_00564650 (Sleep wrapper), re-reads flag.

**Calls:** FUN_00563410 (engine processing, docs/00), FUN_00564650 (Sleep wrapper)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_005646d0 — Allocate Int Array via Factory

Source: unknown | Confidence: high
Allocates control struct + int array, fills via factory function.

**Key logic:** Allocates 0x14-byte control struct + (param_2*4)-byte int array. Fills array via FUN_00564810 loop.

**Struct offsets (return):** +0x00 DataPtr, +0x04 Count, +0x08 FactoryParam

**Calls:** _malloc, FUN_00564810 (alloc 0x18 struct + inner buffer, docs/08)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00565f50 — Linked List Pop Front

Source: unknown | Confidence: high
Pop front node from singly-linked list.

**Key logic:** Reads next ptr from *param_1 into piVar1. Sets param_1[2]=piVar1. Checks for null/empty. Returns success/fail bit flag.

**Struct offsets:** +0x00 HeadPtr, +0x08 PoppedNode

**Calls:** None

**Used by system:** docs/01-engine-architecture.md

**Algorithm family:** linked list operation

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0057a1b0 — Memcpy with Advance Pointer

Source: unknown | Confidence: high
Copy bytes in dword chunks then byte remainder, advance source pointer.

**Key logic:** Reads src from *param_1. Copies param_3 bytes: dword phase (>>2 iterations), then byte phase (&3 iterations). Advances *param_1 += param_3.

**Calls:** None

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a8b0 — VTable Call via Offset 0x7c

Source: unknown | Confidence: high
Indirect vtable call through object at *param_1, calling method at vtable+0x7c.

**Key logic:** Reads *param_1, dereferences vtable, calls method at vtable+0x7c.

**Calls:** Virtual call via vtable+0x7c

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057ee80 — Thread-Safe Mutex Queue with Timed Wait

Source: unknown | Confidence: high
Thread-safe linked-list queue read with mutex protection.

**Key logic:** WaitForSingleObject on mutex at +0xad8. Walk list at +0xac8. Call FUN_0057b840 (msg compare). If match: FUN_005871f0, store to *param_3. ReleaseMutex.

**Struct offsets:** +0xac8 ListHead, +0xad0 ListIter, +0xad8 MutexHandle

**Calls:** WaitForSingleObject, ReleaseMutex, FUN_0057b840 (msg compare), FUN_005871f0 (field read)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00585320 — Linked-List Walk with Input Dispatch

Source: unknown | Confidence: high
Walk linked list, dispatch each node through input processing.

**Key logic:** Reads list at param_1+0x11c. For each node: FUN_00587720 (field getter). If != -1: FUN_005878a0(param_2) + FUN_00587710(0xFFFFFFFF).

**Calls:** FUN_00587720 (field getter +0x410), FUN_005878a0 (vtable-mediated), FUN_00587710 (state setter)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586210 — CloseHandle + Cleanup

Source: unknown | Confidence: high
Conditionally close handle, call cleanup.

**Key logic:** If byte at param_1+0x24 != 0: CloseHandle(*(param_1+0x1c)). On success: zero handle. Call FUN_005870d0 (vtable init).

**Struct offsets:** +0x1c Handle, +0x24 HandleValidFlag byte

**Calls:** CloseHandle, FUN_005870d0 (vtable init)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/19-renderer.md -->

## FUN_005876c0 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_00599958.

**Key logic:** Single call to FUN_00599958 (object constructor with SEH + vtable init, docs/08).

**Calls:** FUN_00599958 (constructor, docs/08)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005881c0 — Stack Probe / alloca

Source: unknown | Confidence: high
MSVC _chkstk pattern for large stack frames.

**Key logic:** Iterates backward in 0x1000 (4KB) page steps, touching each page. Stores return addr at final position.

**Calls:** None — asm pattern

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0058aad9 — Semaphore Release (Slot 9)

Source: unknown | Confidence: high
Release critical section slot 9.

**Key logic:** Calls FUN_0058e04b(9)

**Calls:** FUN_0058e04b (CritSect leave)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058c232 — Critical Section Leave

Source: unknown | Confidence: high
Leave critSect via slot or direct API.

**Key logic:** If param_1 < 0x14: FUN_0058e04b(param_1+0x1c). Else: LeaveCriticalSection(param_2+0x20).

**Calls:** FUN_0058e04b, LeaveCriticalSection

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_0058e060 — TLS Allocation + Thread ID Init

Source: unknown | Confidence: high
Allocate TLS slot, per-thread data block, init with thread ID.

**Key logic:** Calls FUN_0058dfc1. TlsAlloc() to DAT_005e6d40. FUN_0058ab58(1, 0x74) alloc 0x74-byte block. TlsSetValue. FUN_0058e0b4 init. GetCurrentThreadId(). Stores thread ID at [0], -1 at [1]. Returns 1 success, 0 fail.

**Globals:** DAT_005e6d40 (TLS index)

**Calls:** FUN_0058dfc1, TlsAlloc, TlsSetValue, GetCurrentThreadId, FUN_0058ab58 (CRT alloc), FUN_0058e0b4 (init)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599913 — Free Callback Registration

Source: unknown | Confidence: high
Register cleanup callback.

**Key logic:** FUN_00587b3e(&LAB_0059991f) — register atexit handler

**Calls:** FUN_00587b3e (atexit-like registration, docs/06/17/18)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ac7f — Object Teardown with Iterator Cleanup

Source: unknown | Confidence: medium
SEH-protected array teardown with lock, per-element destroy, free.

**Key logic:** SEH init via FUN_0058a5d8. Lock. Iterate array at ECX[2] (count ECX[3]). Per-element: FUN_00598c88 (refcount dec), virtual destructor call. Free array via FUN_0058aa6f. Unlock via FUN_0059a5e9. FUN_005993af (refcount dec).

**Calls:** FUN_0058a5d8, FUN_0059a54d, FUN_00598c88, FUN_0058aa6f, FUN_0059a5e9, FUN_005993af

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00408260 — Callback Registration

Source: unknown | Confidence: high
Register atexit handler at 0x00408270.

**Key logic:** FUN_00587b3e(&LAB_00408270)

**Calls:** FUN_00587b3e (atexit-like)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040e170 — Tick/Update Dispatch

Source: unknown | Confidence: medium
Conditional dispatch with state check, vtable call, chain updates.

**Key logic:** If +0x88 non-null and *(obj)+0x24==10: FUN_004347c0. If *(subsys+0xaf4): vtable+0xc. FUN_004186a0 + FUN_0040da30.

**Calls:** FUN_004347c0, FUN_004186a0 (session update), FUN_0040da30

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00462760 — Buffer Send with Locks

Source: unknown | Confidence: high
Send buffer: acquire, write 0x80, release.

**Key logic:** FUN_0057a880 (acquire). FUN_0057a8e0 (prep). FUN_0057a200(param_1,0x80). FUN_0057a8c0 (finalize). FUN_0057a8b0 (vtable+0x7c). Return 1.

**Calls:** FUN_0057a880, FUN_0057a8e0, FUN_0057a200, FUN_0057a8c0, FUN_0057a8b0

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00464670 — Conditional Object Cleanup

Source: unknown | Confidence: high
Check flag, vtable call + cleanup, chain.

**Key logic:** If *param_1+0x3fb8 non-zero: FUN_0057a8b0(vtable+0x7c) on +0x417c, FUN_0057ab20, zero +0x3fb8. FUN_0045d510.

**Calls:** FUN_0057a8b0, FUN_0057ab20, FUN_0045d510

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0046e7f0 — Polling Loop with Branch

Source: unknown | Confidence: medium
Poll FUN_004328f0 until done. Branch on +0x168 flag.

**Calls:** FUN_004328f0, FUN_00432a10, FUN_00489920, FUN_00432980, FUN_00432180

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00470670 — UI Screen Constructor (Type 1)

Source: unknown | Confidence: medium
Construct UI screen type 1 with data pointer DAT_007d1250.

**Calls:** FUN_00466d60, FUN_00486f30, FUN_004670e0

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00472400 — Virtual Factory + Path Format

Source: unknown | Confidence: medium
Call DAT_007cd8c0 vtable+0x1c(0x13). If non-null: FUN_00477280. Format + register path.

**Globals:** DAT_007cd8c0, DAT_005c3280, DAT_007d09d8

**Calls:** Virtual factory, FUN_00477280, FUN_0058815f, FUN_0048b810

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00473f50 — UI Screen Constructor (Type 2)

Source: unknown | Confidence: medium
Construct UI screen type 2 with data pointer DAT_007cfc68.

**Calls:** FUN_00466d60, FUN_00486f30 (x3)

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00478090 — Virtual Factory + Store

Source: unknown | Confidence: high
Call DAT_007cd8c0 vtable+0x1c(0x14). If non-null: store at param_1+0xe0.

**Calls:** Virtual factory via DAT_007cd8c0+0x1c

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00585810 — Mutex-Protected Worker Call

Source: unknown | Confidence: high
WaitForSingleObject on +0x640. FUN_00587210. ReleaseMutex.

**Calls:** WaitForSingleObject, FUN_00587210, ReleaseMutex

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00599c58 — C++ Constructor with SEH

Source: unknown | Confidence: medium
SEH frame. Vtable set. Field init. FUN_0059a8fa finalize.

**Calls:** FUN_0058a5d8, FUN_0059a8fa

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050f6f2 — VTable Dtor + Null Fields

Source: unknown | Confidence: high
Partial destructor: calls vtable destructor on subobject, then zeros two fields.

**Key logic:**
- If `param_1 + 0x4` (subobject pointer) is non-null: calls virtual method at vtable offset +0x28 on it (likely destructor or cleanup)
- Sets `param_1 + 0x4` = 0
- Sets `param_1 + 0x10` = 0
- C++ object teardown pattern: conditional virtual dtor call followed by field nulling

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x4 | unknown | void* | Subobject pointer, dtor called if non-null |
| +0x10 | unknown | undefined4 | Zeroed after cleanup |

**Calls:** Virtual method at vtable+0x28 on subobject (destructor/cleanup)

**Used by system:** docs/01-engine-architecture.md — generic object lifecycle/cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00553310 — Conditional Resource Cleanup

Source: unknown | Confidence: medium
Conditional cleanup of two resource slots controlled by flags at param_1[0].

**Key logic:**
- Checks `param_1[0] & 1` or `param_1[0] & 2` (flags at offset 0)
- If either flag set AND `param_1[6]` non-null: calls FUN_00587bcf(free) on param_1[6], zeros it
- If `param_1[5]` non-null: calls FUN_00540eb0 (destructor) then FUN_00587bcf(free), zeros param_1[5]
- Calls FUN_004b0170 (general cleanup/release)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | uint | Flags: bit0 and bit1 control resource slot cleanup |
| +0x14 | void* | param_1[5] — resource pointer, freed with dtor+free |
| +0x18 | void* | param_1[6] — resource pointer, freed with free only |

**Calls:** FUN_00587bcf (free/delete), FUN_00540eb0 (object destructor), FUN_004b0170 (general cleanup)

**Used by system:** docs/01-engine-architecture.md — resource lifecycle management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005550c0 — VTable Dispatch Getter

Source: unknown | Confidence: high
Calls virtual method at vtable offset +0x8c on a subobject, stores result in param_1[0].

**Key logic:**
- Reads `param_1[0x440]` (field at +0x1100 if int-indexed: 0x440 × 4 = 0x1100)
- Dereferences as a vtable pointer, calls method at vtable+0x8c on that object
- Stores return value in `param_1[0]`

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x000 | undefined4 | Output — result of virtual call stored here |
| +0x1100 | void* | Object with vtable — queried via virtual method |

**Used by system:** docs/01-engine-architecture.md — virtual dispatch pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005575f0 — Flag Check with Conditional Path Dispatch

Source: unknown | Confidence: high
Checks flags at +0x20, dispatches to different code paths based on bitmask, returns success/failure.

**Key logic:**
- Reads `param_1 + 0x20` flag field
- If bit 3 (0x8) is clear: branch A — if bit 10 (0x400) set returns 0, else calls FUN_00558310
- If bit 3 (0x8) is set: branch B — if bit 10 (0x400) set returns 0, else calls FUN_0047abb0
- If called function returns 0: sets bit 10 (0x400) in flags, returns 0
- If called function returns non-zero: returns 0xFFFFFFFF

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x20 | uint | Flag field: bit3 selects code path, bit10 is "busy/error" state |

**Calls:** FUN_00558310 (handler A — unknown), FUN_0047abb0 (deactivation handler, docs/06)

**Used by system:** docs/01-engine-architecture.md — flag-controlled dispatch with state management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0055d4f0 — Set UI Property Group with Chain Update

Source: unknown | Confidence: high
Sets three property fields on a UI struct, triggers a chain update, then sets dirty flag on global UI context.

**Key logic:**
- Sets `param_1 + 0x38` = param_2 (prop A)
- Sets `param_1 + 0x3c` = param_3 (prop B)
- Sets `param_1 + 0x40` = param_4 (prop C)
- Calls `FUN_005416a0(param_1, *(param_1 + 4), 6)` — DirectX vertex buffer / texture coordinate update with type 6 (docs/19)
- Sets `DAT_008b8f28 + 0xec` bit 0x800 (UI context dirty flag)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x38 | undefined4 | Property field A |
| +0x3c | undefined4 | Property field B |
| +0x40 | undefined4 | Property field C |

**Globals:**
- `DAT_008b8f28` (UI context / scene global) — dirty flag at +0xec set bit 0x800

**Calls:** FUN_005416a0 (DirectX VB texture coord setup, docs/19)

**Used by system:** docs/01-engine-architecture.md — UI property management with renderer integration

**Moddability:** configurable — params 2-4 are caller-supplied values

<!-- target: docs/01-engine-architecture.md -->

## FUN_00561620 — Recursive Tree Node Traversal

Source: unknown | Confidence: high
Recursively traverses a tree structure processing nodes unless a flag at +0x3c blocks it.

**Key logic:**
- Checks `param_1 + 0x3c` bit 1: if set, skip (blocked state)
- If not blocked:
  - If `param_1 + 0x44` (next sibling?) non-null: recursively traverse
  - If `param_1 + 0x40` AND `param_1 + 0x4c` (child?) both non-null: recursively traverse child
  - Calls `FUN_00561660(param_1)` — process/visit current node (physics document tree, docs/18)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x3c | byte | Blocking flag: bit 1 prevents traversal |
| +0x40 | int | Unknown pointer (sibling/child condition) |
| +0x44 | int | Next pointer (sibling branch) |
| +0x4c | int | Child/sibling pointer |

**Calls:** FUN_00561660 (tree node processor, docs/18-physics-dynamics.md)

**Used by system:** docs/01-engine-architecture.md — tree-based document/scene graph traversal

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00563020 — Multi-Stage Initialization Chain with Error Checking

Source: unknown | Confidence: medium
Multi-stage initialization guard: checks if already initialized, runs a 3-step init chain, zeros counters.

**Key logic:**
- If `*param_1 != 0`: returns 4 (already initialized)
- Calls `FUN_00562d20()` (socket array create, docs/21) — if fails, returns error
- Calls `FUN_00563080()` (create UDP broadcast socket, docs/21) — if fails, returns error
- Calls `FUN_005630d0(param_4, param_5)` — if fails, returns error
- Sets `param_1[0x1c] = 0` and `param_1[0x1d] = 0` (zero counters at +0x70, +0x74)
- If `param_2 == 0`: calls `FUN_00563000()` (enter listen mode, docs/21)
- Returns 0 on success

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int | Guard flag: 0 = uninitialized, non-zero = already initialized |
| +0x70 | int | Counter field — zeroed on init |
| +0x74 | int | Counter field — zeroed on init |

**Calls:** FUN_00562d20 (SocketArrayCreate, docs/21), FUN_00563080 (CreateUdpBroadcastSocket, docs/21), FUN_005630d0 (session init, unknown), FUN_00563000 (listen mode, docs/21)

**Used by system:** docs/01-engine-architecture.md — network subsystem initialization

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0057a1e0 — Small Struct Field Init (6 Fields)

Source: unknown | Confidence: high
Initializes 6 fields of a struct with default values.

**Key logic:**
- Sets `param_1 + 0x28` = 1 (byte — enabled/active flag)
- Sets `param_1 + 4` = 0 (int)
- Sets `param_1 + 8` = 0 (byte)
- Sets `param_1 + 0x29` = 0 (byte)
- Sets `param_1 + 0x2a` = 0 (byte)
- Sets `param_1 + 0x2b` = 0 (byte)
- Sets `param_1 + 0x2c` = 0 (byte)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | int | Zeroed |
| +0x08 | byte | Zeroed |
| +0x28 | byte | Set to 1 (active/default true) |
| +0x29 | byte | Zeroed |
| +0x2a | byte | Zeroed |
| +0x2b | byte | Zeroed |
| +0x2c | byte | Zeroed |

**Used by system:** docs/01-engine-architecture.md — object initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a8c0 — Virtual Dispatch Wrapper

Source: unknown | Confidence: high
Thin wrapper: calls a virtual method at vtable offset +0xc0, always returns 0.

**Key logic:**
- Reads `*param_1` as vtable pointer
- Calls vtable method at offset +0xc0 with `param_2` as argument
- Returns 0

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | void* | vtable pointer |

**Used by system:** docs/01-engine-architecture.md — virtual method dispatch pattern (callback/completion)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b780 — Object Init with VTable + Field Set

Source: unknown | Confidence: medium
Initializes an object: calls FUN_00587030 for setup, sets vtable pointer, zeros a field.

**Key logic:**
- Calls `FUN_00587030(param_2, param_3, param_4)` — stack/param setup (docs/21)
- Sets `*param_1 = &PTR_FUN_005b8a64` — assigns vtable
- Sets `param_1[7] = 0` — zeros field at +0x1c
- Returns param_1

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | void* | vtable pointer — set to PTR_FUN_005b8a64 |
| +0x1c | undefined4 | Zeroed field |

**Calls:** FUN_00587030 (stack/param setup, docs/21)

**Used by system:** docs/01-engine-architecture.md — object constructor/initialization (likely network/async object)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00581750 — Handle Close with Cleanup

Source: unknown | Confidence: high
Closes a Win32 handle if an active flag is set, then nulls the handle field.

**Key logic:**
- Checks `param_1 + 0xc` (byte): if non-zero (handle active)
  - Calls `CloseHandle(*(param_1 + 4))` — Win32 API
  - On success: zeros `param_1 + 4` (handle field)
- Thread/event handle cleanup pattern

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | HANDLE | Win32 handle (thread/event/mutex) |
| +0x0c | byte | Active flag — non-zero means handle is open |

**Calls:** CloseHandle (Win32 API)

**Used by system:** docs/01-engine-architecture.md — thread/event handle cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005833e0 — Walk Linked List, Call Destructor, Free Nodes

Source: unknown | Confidence: high
Destructor for a linked list: traverses nodes, conditionally calls destructor + free on each, zeros list head.

**Key logic:**
- Walks linked list from `*param_1` (head)
- For each node: if node[2] byte flag != 0 AND node[0] (data) != 0:
  - Calls FUN_005867b0 (SEH-guarded cleanup) on node data
  - Calls FUN_00587bcf (free) on data pointer
- Frees each node with FUN_00587bcf
- Zeros list head (`*param_1`), count (param_1[1]), and two more fields (param_1[2], param_1[3])

**Struct offsets (param_1 — list container):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | void* | Linked list head pointer |
| +0x04 | int | Count/tail pointer — zeroed |
| +0x08 | int | Field — zeroed |
| +0x0c | int | Field — zeroed |

**Per-node offsets:**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | void* | Data pointer — freed if flag set |
| +0x04 | void* | Next node pointer |
| +0x08 | byte | Flag — non-zero means data needs cleanup |

**Calls:** FUN_005867b0 (SEH-guarded cleanup), FUN_00587bcf (free/delete)

**Used by system:** docs/01-engine-architecture.md — linked list container destruction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585380 — VTable Dispatch with Conditional Call

Source: unknown | Confidence: high
Conditionally processes param_2, then calls a virtual method at vtable offset +0x38.

**Key logic:**
- Default return = 2
- If param_2 != 0: calls FUN_00584c70(param_2), sets return = 0
- Calls virtual method at vtable+0x38 on `*param_1`
- Returns the value (0 or 2)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | int* | vtable pointer |

**Calls:** FUN_00584c70 (callback/resource processor — undocumented), virtual method at vtable+0x38

**Used by system:** docs/01-engine-architecture.md — object lifecycle callback dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586240 — Linked-List Destruction with SEH + Alloc Cleanup

Source: unknown | Confidence: high
Linked-list destructor with SEH protection. Nearly identical to FUN_005833e0 but wrapped in SEH try/except.

**Key logic:**
- Sets up SEH frame (exception handler at LAB_0059d138)
- Walks linked list from `*param_1`
- For each node: if node[2] byte flag != 0 AND node[0] (data) != 0:
  - Calls FUN_004b0170 (general cleanup/release) on data
  - Calls FUN_00587bcf (free) on data pointer
- Frees each node with FUN_00587bcf
- Zeros all 4 list container fields
- Restores SEH handler

**Struct offsets (param_1 — list container):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | void* | Linked list head pointer |
| +0x04 | int | Count/tail — zeroed |
| +0x08 | int | — zeroed |
| +0x0c | int | — zeroed |

**Calls:** FUN_004b0170 (general object cleanup/release), FUN_00587bcf (free/delete)

**Used by system:** docs/01-engine-architecture.md — SEH-protected linked list destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058ab31 — Lock Release by Index (CritSect 9)

Source: unknown | Confidence: high
Thin wrapper: releases critical section index 9.

**Key logic:**
- Calls FUN_0058e04b(9) — leave critical section (docs/20-math-utilities.md)
- Lock index 9 is a specific global critical section used for file/console I/O

**Calls:** FUN_0058e04b (CritSect leave, index 9)

**Used by system:** docs/01-engine-architecture.md — synchronization primitive release

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598c4a — Counter Increment Thread-Safe

Source: unknown | Confidence: high
Increment a counter field under critical section protection, with sentinel guard.

**Key logic:**
- Calls FUN_0059a54d() — enter critical section (lock)
- If `param_1 + 4` != -1 (sentinel): increments the counter at param_1 + 4
- Calls FUN_0059a5e9() — leave critical section (unlock)
- Thread-safe counter increment pattern

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | int | Counter — incremented if not -1 (-1 = disabled/invalid sentinel) |

**Calls:** FUN_0059a54d (critical section enter/lock), FUN_0059a5e9 (critical section leave/unlock)

**Used by system:** docs/01-engine-architecture.md — thread-safe counter increment (logging/event counting)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005994bc — Object Initialization with Buffer/Bounds Setup

Source: unknown | Confidence: medium
Initializes an object with buffer pointer assignment, bounds setup, and mode-dependent path.

**Key logic:**
- Sets `param_1 + 0x48` = (param_3 == 1) — bool: is extended/alt mode
- If param_3 == 0 (standard mode):
  - Calls FUN_00598c70 (init helper A)
  - If param_1 != -0x4c: calls FUN_00598c1c (init helper B)
  - Sets param_1 + 0x44 = 0
- Calls FUN_0059a4c9() (common init step)
- If param_2 != 0 AND `param_1 + 0x48` == 0 (standard mode with buffer):
  - Sets +0x1c = param_2 (base)
  - Sets +0x0c = param_2 + 8 (read cursor / end of header)
  - Sets +0x10 = param_2 + 8 (write cursor / end of header)
  - Sets +0x20 = param_2 (base)
  - Sets +0x2c = param_2 + 4 (mid-pointer)
  - Sets +0x30 = param_2 + 4 (mid-pointer)
- Sets +0x50 = param_2 (buffer pointer)
- Sets +0x40 = DAT_008d5a68 (cap limit high)
- Sets +0x38 = 0 (low bound)
- Sets +0x3c = DAT_008d5a68 (cap limit high)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0c | int | Buffer read cursor |
| +0x10 | int | Buffer write cursor |
| +0x1c | int | Buffer base pointer |
| +0x20 | int | Buffer base (copy) |
| +0x2c | int | Mid pointer |
| +0x30 | int | Mid pointer (copy) |
| +0x38 | int | Lower bound / min |
| +0x3c | int | Upper bound / max (from DAT_008d5a68) |
| +0x40 | int | Upper bound (copy from DAT_008d5a68) |
| +0x44 | int | Flags/counters — zeroed in standard mode |
| +0x48 | bool | Extension mode flag (param_3 == 1) |
| +0x50 | int | Buffer pointer |

**Globals:**
- `DAT_008d5a68` — global capacity/limit constant

**Calls:** FUN_00598c70 (init helper A), FUN_00598c1c (init helper B), FUN_0059a4c9 (common init)

**Used by system:** docs/01-engine-architecture.md — buffer/stream object initialization

**Moddability:** configurable — param_2 is caller-supplied buffer pointer

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599933 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper: calls FUN_00599b86 with fixed arguments (0, 1).

**Key logic:**
- Calls FUN_00599b86(0, 1) — object constructor with vtable setup (index 0, flag 1)
- No other logic — pure delegation

**Calls:** FUN_00599b86 (object constructor with vtable setup)

**Used by system:** docs/01-engine-architecture.md — static singleton/global initialization stub

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059a473 — Object Init with Buffer/Data Pointer Assignment

Source: unknown | Confidence: medium
Initializes an object with buffer pointer and bounds setup. Similar to FUN_005994bc but simpler.

**Key logic:**
- Sets `param_1 + 0x48` = (param_3 == 1) — bool: extended/alt mode
- If param_3 == 0 (standard mode):
  - Calls FUN_00598c70 (init helper A)
  - If param_1 != -0x4c: calls FUN_00598c1c (init helper B)
  - Sets param_1 + 0x44 = 0
- Calls FUN_0059a4c9() (common init step)
- Sets +0x50 = param_2 (data/buffer pointer)
- Sets +0x40 = DAT_008d5a60 (capacity limit)
- Sets +0x38 = 0 (lower bound)
- Sets +0x3c = DAT_008d5a60 (upper bound)

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x38 | int | Lower bound |
| +0x3c | int | Upper bound (from DAT_008d5a60) |
| +0x40 | int | Capacity limit (from DAT_008d5a60) |
| +0x44 | int | Flags — zeroed in standard mode |
| +0x48 | bool | Extension mode flag |
| +0x50 | int | Data/buffer pointer |

**Globals:**
- `DAT_008d5a60` — capacity/limit global constant

**Calls:** FUN_00598c70, FUN_00598c1c, FUN_0059a4c9

**Used by system:** docs/01-engine-architecture.md — buffer/stream object initialization variant

**Moddability:** configurable — param_2 is caller-supplied buffer pointer

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ad3d — Free Callback Registered Cleanup

Source: unknown | Confidence: high
Registers a cleanup callback (FUN_00599796) for at-exit execution via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(FUN_00599796) — registers FUN_00599796 as an atexit/deferred cleanup handler
- Typical MSVC static initialization pattern: register destructor/cleanup in global init list

**Calls:** FUN_00587b3e (callback/deferred function registration), FUN_00599796 (target cleanup function)

**Used by system:** docs/01-engine-architecture.md — static resource registration for cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00404e60 — Linked-List Node Insertion

Source: unknown | Confidence: high
Allocates a 2-element data node and a 3-element list node, appends to list tail.

**Key logic:**
- Allocates 8-byte data node: [0]=0, [1]=0xFFFFFFFF (sentinel)
- Calls FUN_00566650(param_2) — name/path registration
- Allocates 12-byte list node: [0]=data_ptr, [1]=0, [2]=1 (active flag)
- If list head (+0x40) == 0: sets head = tail = cursor = new node
- Else: appends to tail via +0x44 (tail pointer)
- Increments count at +0x4c

**Struct offsets (param_1 — list container):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x40 | void* | List head pointer |
| +0x44 | void* | List tail write pointer |
| +0x48 | void* | Cursor/read pointer |
| +0x4c | int | Element count |

**Calls:** operator_new (2 allocs), FUN_00566650 (path/name registry)

**Used by system:** docs/01-engine-architecture.md — linked list node insertion (named list elements)

**Moddability:** configurable — param_2 is user-supplied name/identifier

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00407070 — Array + Linked-List Virtual Dispatch Iterator

Source: unknown | Confidence: medium
Iterates an array of objects calling vtable+0x10, then walks a linked list calling vtable+0x14.

**Key logic:**
- Phase 1: if array at +0x48 non-null AND count at +0x4c > 0:
  - Iterates array (stride 0x14) calling vtable+0x10 on each element
- Phase 2: walks linked list starting at +0x18 (head), cursor at +0x20:
  - Calls vtable+0x14 on each node's data
  - Advances via next pointer (offset +4 from node header)
  - Guard: stops if head+0x20 becomes null or next's data is null

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x18 | void* | Linked list head pointer |
| +0x20 | void* | Linked list cursor/iterator |
| +0x48 | void* | Array base pointer |
| +0x4c | int | Array element count |

**Used by system:** docs/01-engine-architecture.md — dual-phase dispatch (array batch + linked list walk)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00414420 — Multi-Pointer Free (5 pointers)

Source: unknown | Confidence: high
Frees 5 pointers from two groups plus one more, using FUN_00414fe0 for pre-cleanup.

**Key logic:**
- Calls FUN_00414fe0() — text format struct cleanup/release
- First group: frees 2 pointers at param_1[0x12] and param_1[0xd] (stride -5, 2 iterations)
- Second group: frees 2 pointers at param_1[0x8] and param_1[3] (stride -5, 2 iterations)
- Frees `*param_1` (pointer at +0x0)
- Each pointer freed via FUN_00587bcf if non-null

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x00 | void* | Freed |
| +0x0c | void* | param_1[3] — freed |
| +0x20 | void* | param_1[8] — freed |
| +0x34 | void* | param_1[0xd] — freed |
| +0x48 | void* | param_1[0x12] — freed |

**Calls:** FUN_00414fe0 (text format struct cleanup), FUN_00587bcf (free)

**Used by system:** docs/01-engine-architecture.md — multi-pointer cleanup/destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004526c0 — Array Destructor via Virtual Dispatch

Source: unknown | Confidence: high
Destroys 10 array elements by calling vtable+0x2c (destructor) then vtable+0x8 (release), then nulling pointer.

**Key logic:**
- Zeros `param_1 + 0x414` (array count)
- Iterates 10 elements starting at `param_1 + 100` (0x64), stride 0x1a (26 ints = 0x68 bytes)
- For each element:
  - If non-null: calls vtable+0x2c (destructor) then vtable+0x8 (release/free)
  - Nulls the pointer

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x64 | void* | Element array (10 entries, stride 0x68) |
| +0x414 | int | Count/flag — zeroed |

**Used by system:** docs/01-engine-architecture.md — array of polymorphic objects cleanup

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004627c0 — Network/Entrant Setup with ID Check

Source: unknown | Confidence: medium
Network/entrant setup: creates entrant entry, checks session state, sets flags.

**Key logic:**
- Calls FUN_0057a880() — create entrant entry
- Calls FUN_0057a8e0(entry) — setup entrant
- Calls FUN_0057a230(param_1, &local_4) — check session with 0x80 flag
- bVar4 = (local_4 == 0x80) — flag unchanged = session active
- Calls FUN_00462370() — get player slot ID
- Sets `param_1 + 0x65` = slot_id - 1
- Sets `param_1 + 0x66` = entrant_entry + 0x2b (entrant flag)
- If param_2 != null: calls vtable+0x18 on entrant, stores result
- Calls FUN_0057a8b0(entry) — cleanup entrant entry
- Returns bVar4

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x65 | char | Player slot (adjusted -1) |
| +0x66 | byte | Entrant flag copied from entry |

**Calls:** FUN_0057a880 (entrant create, docs/19), FUN_0057a8e0 (entrant setup), FUN_0057a230 (session check), FUN_00462370 (get slot ID), FUN_0057a8b0 (entrant cleanup)

**Used by system:** docs/01-engine-architecture.md — network/entrant setup and session query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049afb0 — Callback Registration (atexit)

Source: unknown | Confidence: high
Registers LAB_0049afc0 as cleanup callback via FUN_00587b3e.

**Calls:** FUN_00587b3e (atexit/deferred function registration)

**Used by system:** docs/01-engine-architecture.md — static cleanup registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a11e0 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_004a11f0 as cleanup callback via FUN_00587b3e.

**Calls:** FUN_00587b3e (atexit/deferred function registration)

**Used by system:** docs/01-engine-architecture.md — static cleanup registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004d0040 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_004d0050 via FUN_00587b3e.

**Calls:** FUN_00587b3e (atexit registration)

**Used by system:** docs/01-engine-architecture.md — static init registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0050b75f — Destructor with Self-Free

Source: unknown | Confidence: high
Calls thunk_FUN_00506ccc for cleanup, optionally frees self.

**Calls:** thunk_FUN_00506ccc, FUN_00587bcf

**Used by system:** docs/01-engine-architecture.md — object destructor pattern

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_005987d0 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_005987dc via FUN_00587b3e.

**Calls:** FUN_00587b3e (atexit registration)

**Used by system:** docs/01-engine-architecture.md — static init registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## uflow — MSVC wchar_t stream underflow

Source: unknown | Confidence: high
MSVC std::basic_streambuf<wchar_t>::uflow() — reads next wide char from stream.

**Key logic:**
- Calls virtual method at vtable+0x10 on stream buffer
- If -1: returns 0xFFFF (EOF)
- Else: returns current char via Gninc() and increments pointer

**Calls:** vtable+0x10, Gninc

**Used by system:** docs/20-math-utilities.md — MSVC CRT wchar_t stream support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c414 — MSVC Exception Handler Unwind Trampoline

Source: unknown | Confidence: high
SEH unwind handler: frees stack object at EBP-0x48 via FUN_00587bcf.

**Calls:** FUN_00587bcf (free)

**Used by system:** docs/20-math-utilities.md — MSVC SEH unwind cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059c980 — C++ Unwind Helper (thunk to FUN_00581880)

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_00581880.

**Calls:** FUN_00581880

**Used by system:** docs/20-math-utilities.md — MSVC C++ unwind helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## Unwind_0059d058 — C++ Unwind Helper (thunk to FUN_00583650)

Source: unknown | Confidence: high
SEH unwind handler: thunk to FUN_00583650.

**Calls:** FUN_00583650

**Used by system:** docs/20-math-utilities.md — MSVC C++ unwind helper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005514c0 — Timer-Based State Update with Cap

Source: unknown | Confidence: medium
Timer-driven update routine. Accumulates elapsed time with upper cap, dispatches to callbacks based on flag state.

**Key logic:**
- Guard: returns immediately if `param_1+0x1c` (timer config) is null
- If flag `0x1000` set at `param_1+4`: clears `0x1000`, sets flag `0x8000`, zeros `param_1+8`, calls `FUN_00556440()`
- If byte-shifted sign bit of `param_1+4` is set (bit 15):
  - Gets current time from `FUN_005565b0()` (high-precision timer)
  - Stores at `param_1+0x10`
  - If accumulated time >= max time at `*(param_1+0x1c)+8`: caps to max, checks flag `0x20000`
    - Flag `0x20000` set → calls `FUN_005514a0()` then `FUN_00551210(param_2, capped_time)`
    - Else → calls `FUN_00551440()`, `FUN_00551480()` then `FUN_00551210()`
  - Otherwise calls `FUN_00551210(param_2, accumulator)`
- Common animation/timer update pattern: accumulate delta, clamp at max, dispatch update

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | uint | Flags bitfield (0x1000=reset, 0x8000=post-reset, 0x20000=alt path) |
| +0x08 | uint | Zeroed on reset flag |
| +0x10 | float | Accumulated time (capped at max) |
| +0x1c | int* | Pointer to timer config struct (+0x08=max time) |

**Calls:**
- FUN_00556440 — bounds check / timer reset callback
- FUN_005565b0 — high-precision timer counter arithmetic (docs/20)
- FUN_005514a0 — flag update with cascade
- FUN_00551210 — animation/timer dispatch (370 bytes, docs/20)
- FUN_00551440 — list init/timer init
- FUN_00551480 — animation start (docs/09)

**Used by system:** docs/01-engine-architecture.md — timer-driven update loop for animation or event scheduling

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00553630 — Two-Field Setter

Source: unknown | Confidence: high
Simple setter — writes two 4-byte values to struct offsets +0x08 and +0x0c.

**Key logic:**
- `param_1+0x08 = param_2`
- `param_1+0x0c = param_3`
- No validation, no side effects

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | undefined4 | First field written |
| +0x0c | undefined4 | Second field written |

**Used by system:** docs/01-engine-architecture.md — generic property setter, likely part of an entity/component pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00556330 — Timer Accumulate via QueryPerformanceCounter

Source: unknown | Confidence: high
Accumulates elapsed time using QueryPerformanceCounter or alternate timer source. 64-bit delta accumulation with carry.

**Key logic:**
- Guard: returns if `*param_1==0` OR `param_1[0xd]==0` OR `param_1[0xc]==0` (timer uninitialized)
- If byte flag at `param_1+0x48` bit 0 is 0: calls `FUN_0055687b()` for timestamp
- Else: calls `QueryPerformanceCounter()` directly (Win32 high-precision timer)
- Accumulates delta as 64-bit value:
  - Low part: `param_1[0xa] += (new_low - old_low)`
  - High part: `param_1[0xb] += (new_high - old_high) - carry_borrow`
- Zeroes out stored timestamps at `param_1[0xc]` and `param_1[0xd]`

**Struct offsets (param_1, int-indexed):**
| Index | Offset | Type | Notes |
|-------|--------|------|-------|
| [0x00] | +0x00 | int | Non-null guard (object self-check) |
| [0x0a] | +0x28 | int | Accumulator low part |
| [0x0b] | +0x2c | int | Accumulator high part |
| [0x0c] | +0x30 | int | Last timestamp low part |
| [0x0d] | +0x34 | int | Last timestamp high part |
| [0x12]byte | +0x48 | byte | Flag bit 0: QPC vs alternate timer |

**Calls:**
- FUN_0055687b — alternate timer source (when QPC flag not set)
- QueryPerformanceCounter — Win32 high-precision timer API

**Used by system:** docs/01-engine-architecture.md — engine timing infrastructure

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0055bb70 — Partial Struct Zero-Init

Source: unknown | Confidence: high
Zeros specific fields of a struct — not a full initialization, only targeted fields at indices 0, 0x43–0x48.

**Key logic:**
- `*param_1 = 0` (first int field)
- `*(byte*)(param_1 + 1) = 0` (byte at offset 4)
- `param_1[0x43] = 0` (offset +0x10c)
- `param_1[0x44] = 0` (offset +0x110)
- `param_1[0x45] = 0` (offset +0x114)
- `param_1[0x46] = 0` (offset +0x118)
- `param_1[0x47] = 0` (offset +0x11c)
- `param_1[0x48] = 0` (offset +0x120)
- Selective field reset, not a full memset

**Struct offsets (param_1, int-indexed):**
| Index | Offset | Type | Notes |
|-------|--------|------|-------|
| [0x00] | +0x00 | int | First field zeroed |
| +1 byte | +0x04 | byte | Byte field zeroed |
| [0x43] | +0x10c | int | Array/struct field |
| [0x44] | +0x110 | int | Array/struct field |
| [0x45] | +0x114 | int | Array/struct field |
| [0x46] | +0x118 | int | Array/struct field |
| [0x47] | +0x11c | int | Array/struct field |
| [0x48] | +0x120 | int | Array/struct field |

**Used by system:** docs/01-engine-architecture.md — object state partial reset

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055d530 — State Field Setter with Global Dirty Flag

Source: unknown | Confidence: high
Writes a state field, dispatches a DirectX texture coordinate update, then sets a global dirty flag bit.

**Key logic:**
- Writes `param_2` to `param_1+0x50`
- Calls `FUN_005416a0(param_1, *(param_1+4), 7)` — DirectX vertex buffer texture coord setup with mode 7
- Sets bit 0x800 at `DAT_008b8f28 + 0xEC` — global dirty/update flag

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | undefined4 | Passed to FUN_005416a0 as second arg |
| +0x50 | undefined4 | State field written |

**Globals:**
- `DAT_008b8f28` — global struct; `+0xEC` has bit 0x800 set as dirty flag

**Calls:**
- FUN_005416a0 — DirectX Vertex Buffer Texture Coordinate Setup (docs/19), mode 7

**Used by system:** docs/01-engine-architecture.md — state management with render sync

**Moddability:** configurable — param_2 sets the field at +0x50

<!-- target: docs/01-engine-architecture.md -->

## FUN_00561940 — Field Cleanup with Null Check

Source: unknown | Confidence: high
Null-checks a pointer field at +0x1ec, frees it if non-null, then zeros the field.

**Key logic:**
- If `param_1+0x1ec` is non-null:
  - Calls `FUN_00587bcf()` on the pointer (free wrapper)
  - Sets `param_1+0x1ec = 0` (null out after free)
- Standard safe-cleanup pattern

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1ec | int* | Pointer field; freed and zeroed if non-null |

**Calls:**
- FUN_00587bcf — free wrapper (memory management, per triage index)

**Used by system:** docs/01-engine-architecture.md — resource cleanup/teardown

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00564780 — Function Pointer Call with Error Handling

Source: unknown | Confidence: medium
Calls a function pointer from vtable/struct, then performs error-checked resource lookup.

**Key logic:**
- Calls function pointer at `param_1+0xc` (virtual method or callback)
- Calls `FUN_00564a20(param_1+0x10, 0, 0)` — buffer index computation with stride-based division
- If result == -1: calls `FUN_005648c0()` (single function call wrapper, error path)
- Else: calls `FUN_005649d0(iVar1)` (call chain wrapper, success path)
- Dispatches to success or error handler based on lookup result

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x0c | code* | Function pointer (vtable slot or callback) |
| +0x10 | undefined4 | Passed to buffer index computation |

**Calls:**
- FUN_00564a20 — buffer index computation with stride-based division
- FUN_005648c0 — single function call wrapper (error path)
- FUN_005649d0 — call chain wrapper (success path)

**Used by system:** docs/01-engine-architecture.md — call-with-retry or dispatch pattern

**Moddability:** hookable — function pointer at +0xc is pluggable

<!-- target: docs/01-engine-architecture.md -->

## FUN_005668d0 — Sub-Call with Conditional Field Free

Source: unknown | Confidence: high
Calls a sub-routine then conditionally frees a pointer field.

**Key logic:**
- Calls `FUN_00566b90()` — conditional file handle close with flag-based dispatch
- If `param_1+4` is non-null: calls `FUN_00587bcf()` to free it
- Cleanup/teardown helper

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | int* | Pointer field; freed if non-null |

**Calls:**
- FUN_00566b90 — conditional file handle close with flag-based dispatch
- FUN_00587bcf — free wrapper (memory management)

**Used by system:** docs/01-engine-architecture.md — cleanup/teardown sequence

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a200 — memcpy-like Copy with Word/Byte Split + Size Store

Source: unknown | Confidence: high
Copies data from param_2 to param_1+0x2d with size param_3. Uses word-aligned fast path for bulk, byte loop for remainder. Stores size at +0x2c.

**Key logic:**
- Target buffer: `param_1 + 0x2d`
- First loop: copies `param_3 >> 2` 4-byte words
- Second loop: copies `param_3 & 3` remaining bytes
- Stores total size as char at `param_1 + 0x2c`

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x2c | char | Size of copied data |
| +0x2d | byte[] | Copied data buffer |

**Used by system:** docs/01-engine-architecture.md — generic data copy utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a910 — Single Function Call Wrapper

Source: unknown | Confidence: high
Thin wrapper — delegates directly to FUN_005855e0.

**Key logic:**
- Calls FUN_005855e0() — thread suspend with mutex wait/lock
- No parameters, no return value processing

**Calls:**
- FUN_005855e0 — thread suspend with mutex wait/lock (thread management)

**Used by system:** docs/01-engine-architecture.md — dispatch/threading utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b7b0 — Conditional Free Based on Flag Bit

Source: unknown | Confidence: high
Initializes vtable then conditionally frees param_1 based on param_2 bit 0.

**Key logic:**
- Calls FUN_0057b7f0() — VTable pointer init
- If `param_2 & 1`: calls FUN_00587bcf(param_1) to free
- Returns param_1

**Calls:**
- FUN_0057b7f0 — VTable pointer init
- FUN_00587bcf — free wrapper

**Used by system:** docs/01-engine-architecture.md — object init with conditional ownership

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00581780 — Linked List Node Advance

Source: unknown | Confidence: high
Advances linked list iterator. Returns value pointer or 0.

**Key logic:**
- If `param_1+8` (current) non-null: advance to `*(param_1+8)->next` (+4)
- If new node non-null: return `**new_node` (value at +0)
- Otherwise return 0

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x08 | int* | Current node pointer |

**Used by system:** docs/01-engine-architecture.md — linked list traversal

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005834c0 — List Destruction with Virtual Release

Source: unknown | Confidence: high
Walks linked list, releases via vtable, frees nodes, zeros header.

**Key logic:**
- Walks list from `*param_1` (head)
- If node active AND value ptr non-null: calls vtable[1] with arg 3, frees value
- Frees each node
- Zeros header[0..3] (head, tail, count, capacity)

**Used by system:** docs/01-engine-architecture.md — list teardown

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585550 — Thread Termination with Wait Cleanup

Source: unknown | Confidence: high
Terminates thread with retry, signals completion, releases mutex, waits for exit.

**Key logic:**
- Up to 10 retries with 250ms sleep calling FUN_00585680() (thread resume)
- Sets completion byte, waits on mutex with timeout, releases
- WaitForSingleObject INFINITE on thread handle, CloseHandle
- Zeros handle fields

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | HANDLE | Thread handle |
| +0x0c | byte | Completion flag |
| +0x10 | HANDLE | Mutex handle |

**Used by system:** docs/01-engine-architecture.md — thread lifecycle

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586460 — Destroy Linked List with VTable Destructor Dispatch

Source: unknown | Confidence: high
Destroys list with SEH-wrapped vtable callback, frees nodes, zeros header.

**Key logic:**
- Walks linked list
- For active nodes: calls FUN_0058a5f7(vtable, 0x418, vtable[-4], FUN_004b0170) then frees
- Frees each node, zeros header

**Calls:**
- FUN_0058a5f7 — N-time callback loop with SEH
- FUN_004b0170 — empty stub (render register / callback)
- FUN_00587bcf — free wrapper

**Used by system:** docs/01-engine-architecture.md — list teardown with virtual destruction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587030 — Object Init with VTable Setup

Source: unknown | Confidence: high
Allocates array, sets vtable, stores four fields.

**Key logic:**
- Calls FUN_00587460(0) — array alloc
- `param_1[4] = param_4`, `param_1[5] = param_2`, byte at +0x18 = param_3, byte at +0x19 = 0
- `*param_1 = &PTR_FUN_005b8c30`

**Used by system:** docs/01-engine-architecture.md — object construction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587710 — Field Setter at +0x410

Source: unknown | Confidence: high
Writes param_2 to param_1+0x410.

**Key logic:**
- `param_1 + 0x410 = param_2`

**Used by system:** docs/01-engine-architecture.md — property setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058abf1 — Critical Section Leave (Slot 9)

Source: unknown | Confidence: high
Wrapper for FUN_0058e04b with slot 9.

**Key logic:**
- Calls `FUN_0058e04b(9)` — CritSect leave

**Used by system:** docs/01-engine-architecture.md — sync utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058e12e — Encoding/Locale Detection from Parse Result

Source: unknown | Confidence: medium
Detects string encoding from parse result. Returns flags (ANSI/UTF-16/UTF-32).

**Key logic:**
- Calls FUN_00596245() for parse
- If bit 4 clear (success): interprets result as ANSI (0x80) or UTF-16 (0x100)
- If bit 4 set (failure): flag 0x200 (unknown)
- Returns flags + codepage delta

**Used by system:** docs/01-engine-architecture.md — text encoding detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005982f8 — Bounded String Length with Cap

Source: unknown | Confidence: high
Returns strlen bounded by param_2.

**Key logic:**
- Walks up to param_2 chars, returns actual len or cap

**Used by system:** docs/01-engine-architecture.md — string utility

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598c70 — Null Check with Virtual Dispatch

Source: unknown | Confidence: high
Checks *param_1, gets locale object, dispatches vtable.

**Key logic:**
- If `*param_1 != 0`: FUN_00598c88() (locale refcount), then vtable[0](1)

**Used by system:** docs/01-engine-architecture.md — locale management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599534 — Buffer Boundary Marker Check + Set

Source: unknown | Confidence: high
Checks sentinel byte before buffer, calls cleanup if corrupted, sets to 0xFF.

**Key logic:**
- Sentinel at `*(param_1+4) - 1`: if != 0 and != -1, call FUN_00599560(param_1+8, 0)
- Always sets sentinel to -1

**Used by system:** docs/01-engine-architecture.md — memory buffer boundary tracking

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599ad9 — Ref Count Decrement with Check

Source: unknown | Confidence: high
Decrements DAT_005ea04c counter, calls cleanup at zero.

**Key logic:**
- FUN_0059a54d(), decrement, if zero: FUN_00598aa0() x3, FUN_0059a5e9()

**Globals:**
- `DAT_005ea04c` — reference counter

**Used by system:** docs/01-engine-architecture.md — ref counting

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c53e — SEH Unwind (Free EBP-0x14)

Source: unknown | Confidence: high
SEH unwind: frees pointer at EBP-0x14.

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c666 — SEH Unwind (Free EBP+8)

Source: unknown | Confidence: high
SEH unwind: frees pointer at EBP+8.

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c464 — SEH Unwind (Free EBP-0x30)

Source: unknown | Confidence: high
SEH unwind: frees pointer at EBP-0x30.

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ca10 — SEH Unwind (Free EBP-0x10)

Source: unknown | Confidence: high
SEH unwind: frees pointer at EBP-0x10.

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c7e0 — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_0057bc70() (vtable pointer set).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c91e — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_00581ad0() (close handle, destroy list, free nodes).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cb48 — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_00581880() (linked-list destruction with vtable release).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cd00 — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_00583360() (list destructor with special deallocation).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ced7 — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_005833e0() (walk list, call destructor, free nodes).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d036 — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_00586460() (destroy list with vtable destructor dispatch).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d09c — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_0047aa60() — thunk/deactivation handler.

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d1a8 — SEH Unwind Release Locale Refcount

Source: unknown | Confidence: high
Calls FUN_00599796() to release locale refcount.

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d3cc — SEH Unwind Conditional Cleanup

Source: unknown | Confidence: high
If flag bit 0 set, calls FUN_00599be5() (locale vtable dtor).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d5a8 — SEH Unwind Cleanup

Source: unknown | Confidence: high
Calls FUN_0059a9c2() (single function call wrapper).

**Used by system:** docs/01-engine-architecture.md — SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0040ad90 — Bounded Index Setter

Source: unknown | Confidence: high
Sets param_1+0x14 = param_2 if in [-1, param_1+0x10).

**Used by system:** docs/01-engine-architecture.md — guarded property setter

**Moddability:** configurable

<!-- target: docs/19-renderer.md -->

## FUN_0040e1d0 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_0040e1e0 via FUN_00587b3e().

**Used by system:** docs/01-engine-architecture.md — event registration

**Moddability:** hardcoded

<!-- target: docs/09-track-system.md -->

## FUN_004189b0 — State-Checked Virtual Dispatch

Source: unknown | Confidence: high
If param_1+0xaec == param_2 AND inner obj valid: vtable+8 check, vtable+0xc execute.

**Used by system:** docs/01-engine-architecture.md — guarded action dispatch

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_00452700 — Conditional Field Setter with State

Source: unknown | Confidence: high
Three-path setter based on guard flags at +0x08 and +0x0c.

**Used by system:** docs/01-engine-architecture.md — assignment tracking

**Moddability:** configurable

<!-- target: docs/19-renderer.md -->

## FUN_0045bb90 — Object Allocator (0x32c bytes)

Source: unknown | Confidence: high
Allocates 0x32c bytes, calls constructor FUN_0045bb40().

**Used by system:** docs/01-engine-architecture.md — construction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0045ebd0 — Linked List Purge by Threshold (0x40)

Source: unknown | Confidence: medium
Removes excess elements when count > 0x40, frees values and nodes.

**Used by system:** docs/01-engine-architecture.md — container management

**Moddability:** hardcoded (threshold 0x40)

<!-- target: docs/01-engine-architecture.md -->

## FUN_00461dc0 — State Check Wrapper

Source: unknown | Confidence: high
Returns 1 if FUN_00461cd0() returns 1 or 2.

**Used by system:** docs/01-engine-architecture.md — state check

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004646f0 — Conditional Destructor

Source: unknown | Confidence: high
Frees value if active flag set, optionally frees self.

**Used by system:** docs/01-engine-architecture.md — destruction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00464f50 — Division with Cap Computation

Source: unknown | Confidence: medium
Looks up table value, divides baseline by count-1, caps at table value.

**Used by system:** docs/01-engine-architecture.md — scaled computation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004698c0 — Destructor with Sub-Object Free

Source: unknown | Confidence: high
Frees param_1+0x180, calls FUN_00489440(), optionally frees self.

**Used by system:** docs/01-engine-architecture.md — destruction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0046c7b0 — Indexed Array Insert with Shift

Source: unknown | Confidence: high
Inserts value into fixed-size array (0x68 ints). Sentinel -1 marks end. Shifts right on insert.

**Globals:**
- `DAT_007cd2b8` / `DAT_007cd470` — array bases

**Used by system:** docs/01-engine-architecture.md — ordered array

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00472720 — String Path Resolution with Fallback

Source: unknown | Confidence: high
Trims trailing space, registers path via FUN_00486f30(). Falls back to param_2 if empty.

**Used by system:** docs/01-engine-architecture.md — asset path resolution

**Moddability:** configurable

<!-- target: docs/19-renderer.md -->

## FUN_004780d0 — State-Dependent Virtual Dispatch

Source: unknown | Confidence: medium
Calls vtable+0x1c with arg 0x17 or 0x15 based on state.

**Used by system:** docs/01-engine-architecture.md — resource allocation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00486580 — Linked List Node Insert

Source: unknown | Confidence: high
Allocates key-value pair + wrapper node, inserts into doubly-linked list.

**Used by system:** docs/01-engine-architecture.md — list insertion

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004881b0 — Dual Cleanup with Conditional Free

Source: unknown | Confidence: high
Calls FUN_00499b50() + FUN_00485eb0(), optionally frees self.

**Used by system:** docs/01-engine-architecture.md — destruction

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0048e890 — Resource Cleanup (Free + Zero)

Source: unknown | Confidence: high
Frees +0xe8 if non-null, zeroes +0xe8 and +0xec.

**Used by system:** docs/01-engine-architecture.md — resource cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0048fdf0 — Conditional Dispatch with Cleanup

Source: unknown | Confidence: medium
If guard non-null: cleans sub-object, dispatches FUN_0049aa30(), calls vtable+0x2c.

**Used by system:** docs/01-engine-architecture.md — event dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00490aa0 — Linked List Node Prepend

Source: unknown | Confidence: high
Allocates node, prepends to list head.

**Used by system:** docs/01-engine-architecture.md — list insert

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00491960 — Dual Dispatch with Guard

Source: unknown | Confidence: high
Dispatches same call to two sub-objects if both dimensions > 0.

**Used by system:** docs/01-engine-architecture.md — 2D operation dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00494620 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_00494630 via FUN_00587b3e().

**Used by system:** docs/01-engine-architecture.md — event registration

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004952e0 — Destructor with Conditional Free

Source: unknown | Confidence: high
Calls FUN_00495300(), optionally frees self.

**Used by system:** docs/01-engine-architecture.md — destruction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00496840 — Linked List Summation with Iterator

Source: unknown | Confidence: high
Walks linked list starting from param_1+4, sums results of FUN_004958d0() on each node's value.

**Used by system:** docs/01-engine-architecture.md — list aggregation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00497d00 — Two-Field Setter

Source: unknown | Confidence: high
Writes param_2 to +0x18a8, sets byte at +0x18ec = 1.

**Used by system:** docs/01-engine-architecture.md — property setter

**Moddability:** configurable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00498e30 — Field Getter (+0x48)

Source: unknown | Confidence: high
Returns `*(param_1 + 0x48)`.

**Used by system:** docs/01-engine-architecture.md — accessor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00499520 — Linked List Virtual Dispatch

Source: unknown | Confidence: high
Walks linked list from param_1+0x44, calls vtable+0xa4 on each node.

**Used by system:** docs/01-engine-architecture.md — list iteration

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00499af0 — Object Reset with VTable Dispatch

Source: unknown | Confidence: high
If param_1[0x14] non-null: call vtable on it. Then zero 20 ints starting at param_1.

**Used by system:** docs/01-engine-architecture.md — object reset

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049afe0 — Multi-Call Sequence

Source: unknown | Confidence: high
Calls FUN_0049e8f0() ×5 then FUN_0049e490().

**Used by system:** docs/01-engine-architecture.md — batch operation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004b1ac0 — Multi-Field Setter with Strings

Source: unknown | Confidence: high
Copies strings via FUN_00566650(), sets multiple fields, conditionally sets +0x14.

**Used by system:** docs/01-engine-architecture.md — property setter

**Moddability:** configurable

<!-- target: docs/19-renderer.md -->

## FUN_004b4470 — File Handle + Close Registration

Source: unknown | Confidence: high
Gets handle via FUN_00566e20(), stores at param_1+4. Registers close callbacks: with flag 4 at param_1, flag 2 at param_1+8.

**Used by system:** docs/01-engine-architecture.md — IO handle management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004b5760 — Linked List Iterator with State Update

Source: unknown | Confidence: medium
Walks linked list from param_1+0x20. For each node: checks state, writes to value+0x370, calls FUN_00410f60().

**Used by system:** docs/01-engine-architecture.md — list iteration with state update

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004b9d20 — Float Comparison with Fallback

Source: unknown | Confidence: medium
Compares two floats from FUN_004b8790() and global +0xf3c. If equal and flag clear, returns. Else updates state.

**Used by system:** docs/01-engine-architecture.md — state comparison

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004ba950 — Conditional Allocation

Source: unknown | Confidence: high
Allocates `((param_2 != 0 ? 0x18 : 0) + 8) * 0x1b0` bytes. Stores result to *param_1.

**Used by system:** docs/01-engine-architecture.md — conditional alloc

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004bb460 — Destructor with Conditional Free

Source: unknown | Confidence: high
Frees param_1+4 if non-null, optionally frees self.

**Used by system:** docs/01-engine-architecture.md — destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bf640 — Linked List Destruction

Source: unknown | Confidence: high
Frees all nodes and their values (if active flag set). Zeros header.

**Used by system:** docs/01-engine-architecture.md — list teardown

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004c2850 — Linked List Dereference

Source: unknown | Confidence: high
Gets `*(param_1+4)`, stores to param_1+8, returns *value or 0.

**Used by system:** docs/01-engine-architecture.md — list node access

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004c3030 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_004c3040 via FUN_00587b3e().

**Used by system:** docs/01-engine-architecture.md — event registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004cb5a0 — Array Element Removal (Swap-Out)

Source: unknown | Confidence: high
Removes element from array by swapping with last element, decrements count.

**Used by system:** docs/01-engine-architecture.md — array management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004d0060 — Zero-Init + Sub-Call

Source: unknown | Confidence: high
Sets param_1+4 = 0, calls FUN_004d0080(), returns param_1.

**Used by system:** docs/01-engine-architecture.md — init

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004d93e0 — Range Check (1-5)

Source: unknown | Confidence: high
Returns 1 if param_2 in [1..5] AND param_1 == 0.

**Used by system:** docs/01-engine-architecture.md — validation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004ddf70 — Zero-Init Wrapper

Source: unknown | Confidence: high
Calls FUN_004ddad0(0, param_1).

**Used by system:** docs/01-engine-architecture.md — init utility

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004f8d20 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_004f8d30 via FUN_00587b3e().

**Used by system:** docs/01-engine-architecture.md — event registration

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_004fd840 — Dual Linked List Destruction

Source: unknown | Confidence: high
Frees two linked lists: one singly-linked (+0x3c), one doubly (+0x54). Frees values if active. Zeros header.

**Used by system:** docs/01-engine-architecture.md — container cleanup

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0050af3b — Object Init with VTable (alloc 0x20)

Source: unknown | Confidence: high
Calls FUN_00507496(param_2, 0x20, 1), sets vtable PTR_FUN_005adc9c.

**Used by system:** docs/01-engine-architecture.md — construction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0050b77b — Object Init with VTable (alloc 0x40)

Source: unknown | Confidence: high
Calls FUN_00507496(param_2, 0x40, 1), sets vtable PTR_FUN_005addbc.

**Used by system:** docs/01-engine-architecture.md — construction

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0050fb3b — State Machine with Dispatch

Source: unknown | Confidence: medium
Multi-state function. States 0xCA→0xCB→0xCF plus default. Dispatches callbacks, updates counters.

**Used by system:** docs/01-engine-architecture.md — state machine

**Moddability:** hookable

<!-- target: docs/01-engine-architecture.md -->

## FUN_00511b5c — Conditional Dispatch with Guard

Source: unknown | Confidence: high
If byte at +0x5c bit 6 not set: calls FUN_0051868c(). Then calls FUN_005124de().

**Used by system:** docs/01-engine-architecture.md — guarded dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00513b36 — Flag Setter with Guard

Source: unknown | Confidence: high
If both params non-null: sets bit 3 at param_2+9, writes param_3 to param_2+0x2c.

**Used by system:** docs/01-engine-architecture.md — property setter

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00516937 — Virtual Dispatch + Conditional Value

Source: unknown | Confidence: high
Calls vtable+0x24 on param_1+4. Sets param_1+0x10 = 200 or 100 based on byte at +0xc.

**Used by system:** docs/01-engine-architecture.md — state update

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0052e1c0 — Thunk with VTable + Flag Check

Source: unknown | Confidence: high
Sets vtable to PTR_FUN_005b47e8. If byte at param_1+0x93b non-zero: calls FUN_0052e320().

**Used by system:** docs/01-engine-architecture.md — thunk/init

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_005388d0 — Frequency Table Construction

Source: unknown | Confidence: medium
Builds Huffman-like frequency table from 16-entry short array. Iterates up to param_2, updates frequencies.

**Algorithm family:** frequency table / Huffman coding

**Used by system:** docs/01-engine-architecture.md — data compression/encoding

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0053d2b0 — Guarded Delegation

Source: unknown | Confidence: high
If FUN_0053d1f0(param_1) non-zero: calls FUN_00553050(param_2, param_3).

**Used by system:** docs/01-engine-architecture.md — guarded dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0054c0b0 — Bit Flag Reader

Source: unknown | Confidence: high
Reads bits 1 and 2 from `~*(param_1+0x3c)` into output pointers.

**Used by system:** docs/01-engine-architecture.md — flag accessor

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00559a30 — Single Function Call Wrapper

Source: unknown | Confidence: high
Calls FUN_005596e0().

**Used by system:** docs/01-engine-architecture.md — call delegation

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00567a90 — Recursive Tree Traversal + Free

Source: unknown | Confidence: high
Recursively frees a tree structure: children (via linked list at +4), then sub-tree via FUN_0049adb0(), then calls FUN_00567940() + free self.

**Used by system:** docs/01-engine-architecture.md — tree destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057b6c0 — Setter at +0x24

Source: unknown | Confidence: high
Writes param_2 to param_1+0x24.

**Used by system:** docs/01-engine-architecture.md — property setter

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585e20 — Callback Registration

Source: unknown | Confidence: high
Registers LAB_00585e30 via FUN_00587b3e().

**Used by system:** docs/01-engine-architecture.md — event registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00598994 — Ref Count Decrement with Cleanup

Source: unknown | Confidence: high
Decrements DAT_005e9ef4 counter. If zero: cleanup sequence (FUN_00598aa0() ×3).

**Globals:**
- `DAT_005e9ef4` — reference counter

**Used by system:** docs/01-engine-architecture.md — reference counting

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00599e71 — C++ Destructor with VTable Chain

Source: unknown | Confidence: high
C++ destructor with vtable chain (PTR_FUN_005b9c68 → PTR_FUN_005b9ca0). Releases locale refcounts, frees sub-object.

**Used by system:** docs/01-engine-architecture.md — C++ object destruction

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00553980 — Object Constructor with Allocation and Sub-Init

Source: unknown | Confidence: medium
Constructs an object with heap allocation, two sub-init calls, and a final setup call. Returns 0 on failure or success.

**Key logic:**
- Allocates 0x24 (36) bytes via operator_new
- If alloc fails: return 0
- If alloc succeeds: calls FUN_005532a0 (object allocation with zero-init) for construction
- If param_2 != 0: calls FUN_00553370(param_2) — sub-object init
- If param_3 != 0: calls FUN_00553620(param_3) — sub-object init
- Calls FUN_00553630(param_4, param_5) — final setup
- Calls FUN_0055c2a0(uVar2) — post-construction registration
- If param_1 != null: stores result via *param_1 = uVar2
- Returns 0 always (success)

**Calls:**
- operator_new(0x24) — heap alloc, 36 bytes
- FUN_005532a0 — Object allocation with zero-init (constructor)
- FUN_00553370 — Sub-object init
- FUN_00553620 — Sub-object init
- FUN_00553630 — Final setup (param_4, param_5)
- FUN_0055c2a0 — Post-construction registration

**Used by system:** docs/01-engine-architecture.md — entity object construction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005563e0 — Timer Start via QueryPerformanceCounter

Source: unknown | Confidence: high
Starts a high-resolution timer using QueryPerformanceCounter. Only starts if the timer is initialized (param_1 != 0) and not already running (flags at +0x30 and +0x48 are zero).

**Key logic:**
- Guard: if *param_1 == 0 OR param_1[0xc] (flag at +0x30) != 0 OR param_1[0xd] (flag at +0x34) != 0 → skip
- If flag at (param_1 + 0x48) bit 0 set: use QueryPerformanceCounter directly
- Else: call FUN_0055687b to set time
- Stores result in param_1[0xd] (HighPart) and param_1[0xc] (LowPart)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Initialized | int | Zero check — timer struct valid |
| +0x30 | TimerRunning | int | Flag — timer already active |
| +0x34 | TimerRunning2 | int | Flag — timer already active |
| +0x48 | TimerFlags | byte | Bit 0: use QPC vs wrapper |

**Calls:**
- QueryPerformanceCounter — Win32 high-res timer
- FUN_0055687b — Alternative timer start wrapper

**Used by system:** docs/01-engine-architecture.md — timing subsystem

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00558990 — Resource Teardown with State Array Reset

Source: unknown | Confidence: medium
Frees sub-resources linked from a parent structure, clears an array of state entries, and resets counters. Returns 0.

**Key logic:**
- Dereferences param_1+0x50 → +0x1c to get a sub-resource pointer
- If non-null: calls FUN_00540eb0 (release), then FUN_00587bcf (free wrapper), sets to null
- Gets another pointer at +0x24, calls FUN_00541040 (release), then FUN_00587bcf, sets to null
- Clears bit 8 of flag at param_1+0x20
- Iterates over array at param_1+0x34 with count at param_1+0x2c, clearing 3 fields per entry (offset 0x78, 0x7c, and bit 6 of first dword) — stride 0x80 (32 dwords)
- Resets counters at param_1+0x30 and param_1+0x38 to 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x50 | ResourceBlk | int* | Pointer to resource block |
| +0x1c (sub) | SubResource1 | int | Resource pointer 1 |
| +0x24 (sub) | SubResource2 | int | Resource pointer 2 |
| +0x20 | Flags | uint | Bit 8 cleared during teardown |
| +0x2c | StateCount | int | Number of state array entries |
| +0x34 | StateArray | uint* | Pointer to state entry array |
| +0x30 | Counter1 | int | Reset to 0 |
| +0x38 | Counter2 | int | Reset to 0 |

**Calls:**
- FUN_00540eb0 — Resource release
- FUN_00587bcf — Free wrapper (FUN_0058aa6f)
- FUN_00541040 — Resource release
- FUN_00587bcf — Free wrapper

**Used by system:** docs/01-engine-architecture.md — resource cleanup / state reset

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055bba0 — Linked List Free with Traversal and Nulling

Source: unknown | Confidence: high
Frees all nodes in a linked list starting at param_1+0x120, then sets the head pointer to null. Returns 0.

**Key logic:**
- Get head: iVar1 = *(param_1 + 0x120)
- If head != null: traverse via +0x20 next pointer
- For each node: free current (FUN_00587bcf), advance to next
- After loop: free the final node, set head to null

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x120 | ListHead | int* | Linked list head pointer |
| +0x20 (node)| NextPtr | int* | Node-level next pointer |

**Calls:**
- FUN_00587bcf — Free wrapper (FUN_0058aa6f)

**Used by system:** docs/01-engine-architecture.md — list-based data structure cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0055d560 — Field Getter by Index (1/2/3)

Source: unknown | Confidence: high
Gets a field from an object by index. Supports indices 1, 2, and 3 reading from offsets +0x14, +0x24, +0x34 respectively.

**Key logic:**
- Guard: if param_3 (output pointer) is null → return
- If param_2 == 1: *param_3 = *(param_1 + 0x14)
- If param_2 == 2: *param_3 = *(param_1 + 0x24)
- If param_2 == 3: *param_3 = *(param_1 + 0x34)
- Other indices: no write

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x14 | Field1 | int | Index 1 |
| +0x24 | Field2 | int | Index 2 |
| +0x34 | Field3 | int | Index 3 |

**Used by system:** docs/01-engine-architecture.md — state query interface

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00564860 — Batch Loop with Memory Cleanup

Source: unknown | Confidence: high
Iterates a counter, calling a per-element cleanup function for each, then frees two allocated buffers. No return value.

**Key logic:**
- Loop: for iVar1 = 0 to *param_1 - 1 → call FUN_00564890() each iteration
- Free param_1[5] — secondary allocation via FUN_0058aa6f
- Free param_1 — primary allocation via FUN_0058aa6f

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Count | int | Number of iterations |
| +0x14 | SecondaryBuf | int | Buffer pointer to free |

**Calls:**
- FUN_00564890 — Per-element cleanup
- FUN_0058aa6f — Memory free

**Used by system:** docs/01-engine-architecture.md — batch cleanup/destructor

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00568750 — ASCII Char Code Validation (Printable vs Special)

Source: unknown | Confidence: high
Validates whether a character is a printable or special (punctuation/symbol) ASCII character.

**Key logic:**
- First: call FUN_00589c1b(char) — alphanumeric check (docs/06, character classification)
- If alphanumeric: return 1
- Then: switch on character code for punctuation/symbol ranges:
  - Space (0x20), ! (0x21), # (0x23) through ')', comma, hyphen, period, slash
  - Colon, semicolon, equals, @
  - Brackets [ \ ] ^ _ `
  - Braces { | } ~
- All these cases: return 1
- Default: return 0 (control character or invalid)

**Calls:**
- FUN_00589c1b — Character classification (alphanumeric check)

**Used by system:** docs/01-engine-architecture.md — input text field validation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0057a230 — Byte-Aligned Memory Copy from Struct

Source: unknown | Confidence: high
Copies a byte buffer from a struct field (offset +0x2c) to a destination buffer, with length stored in the size byte. Includes optimized dword-aligned copy with final byte remainder.

**Key logic:**
- Read count: bVar1 = *(param_1 + 0x2c) — byte count
- *param_3 = (uint)bVar1 — return count
- If count > 0:
  - Source starts at param_1 + 0x2d
  - Copy full dwords: count >> 2 iterations, 4 bytes at a time
  - Copy remaining bytes: count & 3 iterations, 1 byte at a time

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x2c | DataLength | byte | Number of bytes to copy |
| +0x2d | DataBuffer | byte[] | Variable-length data |

**Calls:** none

**Used by system:** docs/01-engine-architecture.md — serialization / struct-to-buffer copy

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057a920 — Single Function Call Wrapper

Source: unknown | Confidence: high
Trampoline wrapper that delegates to FUN_00585680.

**Key logic:**
- Single call to FUN_00585680
- No additional logic, no return manipulation

**Calls:**
- FUN_00585680 — target function

**Used by system:** docs/01-engine-architecture.md — call wrapper / vtable thunk

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0057b7d0 — Object Copy-Init with VTable Setup

Source: unknown | Confidence: high
Initializes an object by calling a sub-routine, setting the vtable pointer, and zeroing a field.

**Key logic:**
- Calls FUN_00587090(param_2) — base initialization
- Sets *param_1 = &PTR_FUN_005b8a64 — vtable pointer
- Sets param_1[7] = 0 — field at +0x1c

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | VTablePtr | int* | Virtual method table |
| +0x1c | Field7 | int | Zeroed on init |

**Calls:**
- FUN_00587090 — Base initialization

**Used by system:** docs/01-engine-architecture.md — object construction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00581880 — Linked List Destruction with VTable Release Call

Source: unknown | Confidence: high
Destroys a linked list by calling a virtual release method on each node, then freeing the node and resetting the list pointers.

**Key logic:**
- Start: piVar2 = *param_1 — head of list
- Loop: while piVar2 != null:
  - Save next: piVar1 = piVar2[1] — node's next pointer
  - If node[2] (flag) != 0 AND *piVar2 (object ptr) != null:
    - Call virtual method: (**(code**)**piVar2)(1) — release with arg 1
  - Free node: FUN_00587bcf(piVar2)
  - Advance to next
- Null out all list pointers: param_1[0..3] = 0

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ListHead | int* | First node pointer |
| +0x04 | ListTail | int* | Zeroed on destroy |
| +0x08 | ListCount | int* | Zeroed on destroy |
| +0x0c | ListFlags | int* | Zeroed on destroy |

**Node offsets:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ObjectPtr | int* | Object with vtable at *ObjectPtr |
| +0x04 | NextPtr | int* | Next node in list |
| +0x08 | HasObject | byte | Flag: non-zero → release object |

**Calls:**
- FUN_00587bcf — Free wrapper (FUN_0058aa6f)

**Used by system:** docs/01-engine-architecture.md — linked list manager destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583530 — Zero-Fill Memory Region with Step

Source: unknown | Confidence: high
Zero-fills a memory region of size 0x2078 bytes in steps of 0x103c, with a prior initialization call.

**Key logic:**
- Call FUN_00586000(param_1, 1) — init with some parameter
- Loop: for iVar1 = 0; iVar1 < 0x2078; iVar1 += 0x103c:
  - Call FUN_00583210(*param_1 + iVar1, 0) — zero-fill 0x103c-byte block
- Total fill: 2 blocks of 0x103c = 0x2078 bytes

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | BasePtr | int | Base memory address to fill |

**Calls:**
- FUN_00586000 — Pre-init call
- FUN_00583210 — Per-block zero-fill

**Used by system:** docs/01-engine-architecture.md — memory region initialization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_005855e0 — Thread Suspend with Mutex Wait/Lock

Source: unknown | Confidence: high
Suspends a thread with retry logic and mutex synchronization. Returns 1 on success, 0 on failure.

**Key logic:**
- Guard: if param_1+4 (thread handle) == 0 → return 1
- local_4 = param_1 + 0x1c (status flag ptr)
- If mutex at param_1+0x20 exists: WaitForSingleObject with timeout from param_1+0x24
  - If wait fails (timeout or error): set local_4 to null
- If *local_4 == 0 (not yet suspended):
  - Retry loop up to 50 iterations:
    - Sleep with increasing delay (1ms, 2ms, 3ms...)
    - Call SuspendThread
    - If success (DVar2 != -1 and DVar2 != 0): set *local_4 = 1, goto done
  - If 50 retries exhausted: local_5 = 0 (failure)
- ReleaseMutex if mutex held
- Return local_5 (1 = success, 0 = failure)

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | ThreadHandle | HANDLE | Thread to suspend |
| +0x1c | SuspendFlag | byte | 0 = not suspended, 1 = suspended |
| +0x20 | MutexHandle | HANDLE | Synchronization mutex |
| +0x24 | MutexTimeout | DWORD | Wait timeout in ms |

**Calls:**
- WaitForSingleObject — Win32 mutex wait
- SuspendThread — Win32 thread suspend
- Sleep — Win32 sleep
- ReleaseMutex — Win32 mutex release

**Used by system:** docs/01-engine-architecture.md — thread synchronization / worker thread management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00587070 — Destructor with Conditional Free

Source: unknown | Confidence: high
Destructor that calls cleanup then optionally frees the object based on a flag parameter.

**Key logic:**
- Calls FUN_005870d0() — base destructor/cleanup
- If param_2 & 1: FUN_00587bcf(param_1) — free the object

**Calls:**
- FUN_005870d0 — Base cleanup
- FUN_00587bcf — Free wrapper

**Used by system:** docs/01-engine-architecture.md — object destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587930 — Buffer Copy via Virtual Type Dispatch

Source: unknown | Confidence: medium
Parses a serialized buffer using type-length-value encoding, dispatching to virtual methods for type resolution. Copies data into typed structures.

**Key logic:**
- Iterate over param_3 bytes of data at param_2
- For each entry:
  - Get type resolver via virtual call: (**(code**)(**(int**)(param_1+0x414)+0x58))()
  - Read byte bVar1 = *(param_2 + iVar5) — type byte
  - Compute expected size: uVar3 = ((*(iVar2+0x24) & 7) != 0) + (*(iVar2+0x24) >> 3)
  - If bVar1 matches uVar3 (type match):
    - Copy bVar1 bytes from source to *(iVar2 + 0x14) (storage ptr)
    - Dword-aligned copy for speed, then remaining bytes
  - Read next byte from source as child count
  - Call FUN_00587510 — process children
  - Set iVar2+4 = param_4 — assign user data
  - Call FUN_00585400(iVar2) — finalize entry

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x414 | TypeResolver | int* | Vtable-based type dispatch |

**Calls:**
- Virtual call at ( +0x58 ) — Type size query
- FUN_00587510 — Child processing
- FUN_00585400 — Entry finalization

**Used by system:** docs/01-engine-architecture.md — serialization/deserialization system

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_005921c5 — Lazy-Init Singleton with Flag Guard

Source: unknown | Confidence: high
One-time lazy initialization of a singleton resource with lock/unlock guards.

**Key logic:**
- Check DAT_008d4078 (init flag): if non-zero → skip (already initialized)
- FUN_0058dfea(0xb) — acquire resource lock (type 0xb)
- If DAT_008d4078 still 0 (double-check):
  - FUN_005921f3() — perform initialization
  - DAT_008d4078++ — mark initialized
- FUN_0058e04b(0xb) — release resource lock

**Globals:**
- DAT_008d4078 — Initialization flag (0 = uninitialized, >0 = initialized)

**Calls:**
- FUN_0058dfea — Acquire lock (type 0xb)
- FUN_005921f3 — Actual initialization routine
- FUN_0058e04b — Release lock

**Used by system:** docs/01-engine-architecture.md — singleton / one-time init pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00595524 — String Parse via Delegate

Source: unknown | Confidence: high
String parsing wrapper that delegates to FUN_005953b8 with a shared data table reference.

**Key logic:**
- FUN_005953b8(param_1, param_2, &DAT_005e99a0) — parse using lookup table DAT_005e99a0

**Globals:**
- DAT_005e99a0 — Shared parse/lookup table

**Calls:**
- FUN_005953b8 — String parse implementation

**Used by system:** docs/01-engine-architecture.md — configuration/command string parsing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598502 — Null-Terminated Int Array Copy with Alloc

Source: unknown | Confidence: high
Deep-copies a null-terminated integer array, allocating a new buffer and copying each element via FUN_00598600.

**Key logic:**
- If param_1 is null: return null
- Count elements: traverse until 0 sentinel, count = iVar5
- Allocate: _malloc(iVar5 * 4 + 4) — enough for elements + null terminator
- If alloc fails: __amsg_exit(9) — fatal error
- Copy loop: for each non-zero element:
  - Call FUN_00598600(element) — deep copy/transform element
  - Store result in output
- Write null terminator at end
- Return new array

**Calls:**
- _malloc — CRT heap alloc
- __amsg_exit — Fatal error (out of memory)
- FUN_00598600 — Element copy/transform

**Used by system:** docs/01-engine-architecture.md — array duplication utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0040d0b0 — Mode-Dispatched Subsystem Call

Source: unknown | Confidence: medium
Dispatches to one of four subsystem calls based on a global mode variable (DAT_007cfdc4).

**Key logic:**
- Guard: if *(param_1 + 0x18) == 0 → return 0 (no operation)
- Switch on DAT_007cfdc4 (global mode):
  - default: call FUN_0040a610(2)
  - case 1: call FUN_0040a610(1)
  - case 2: call FUN_0040a610(0)
  - case 3: call FUN_0040a610(3)

**Globals:**
- DAT_007cfdc4 — Dispatch mode selector (0-3)

**Calls:**
- FUN_0040a610 — Subsystem call with mode parameter

**Used by system:** docs/01-engine-architecture.md — mode-routed engine call

**Moddability:** configurable — DAT_007cfdc4 controls routing

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040e1f0 — Global Vector Offset Update

Source: unknown | Confidence: medium
Iterates all vehicles/objects and subtracts a 3D offset vector from each sub-object's position, then updates flags.

**Key logic:**
- Get vehicle count via FUN_0054c210()
- For each vehicle:
  - Get vehicle via FUN_0054c230(index)
  - Get part count via FUN_0054e100()
  - For each part:
    - Get part position ptr via FUN_0054e120(partIdx)
    - Subtract param_2 (offset) from all 3 components: x -= offset[0], y -= offset[1], z -= offset[2]
  - Clear bits in flag at iVar2+0x14 (0xfeffffdf mask — clears bits 0,5,23)
  - Call FUN_0054d520(1) — update transform
  - Call FUN_0054e270() — update bounds
  - Call FUN_0054d080(0) — update physics

**Calls:**
- FUN_0054c210 — Get vehicle/object count
- FUN_0054c230 — Get vehicle by index
- FUN_0054e100 — Get part count for vehicle
- FUN_0054e120 — Get part position pointer
- FUN_0054d520 — Mark transform dirty
- FUN_0054e270 — Update bounds
- FUN_0054d080 — Update physics

**Used by system:** docs/01-engine-architecture.md — world-space position adjustment

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0040f300 — Mode-Dispatched Render/Physics Call

Source: unknown | Confidence: medium
Dispatches to different subsystem calls based on a mode flag at param_1+0x1c. Routes to render or physics init functions.

**Key logic:**
- Switch on *(param_1 + 0x1c):
  - case 0, 3: FUN_0045ae00(param_2) — render path A
  - case 1, 4: FUN_0045ae00(param_2) — render path B (same function, different state)
  - case 2, 5: FUN_0045ae00(param_2) — render path C
  - case 6: FUN_004f0430(param_2) + FUN_004ef180() — physics/init path

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x1c | DispatchMode | int | Mode 0-6, determines behavior |

**Calls:**
- FUN_0045ae00 — Render setup
- FUN_004f0430 — Physics setup
- FUN_004ef180 — Physics finalize

**Used by system:** docs/01-engine-architecture.md — mode-routed initialization

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00461ed0 — Directory String Processing with Decode

Source: unknown | Confidence: medium
Processes a string path through a directory decoder, then passes the result to a configuration function.

**Key logic:**
- Guard: if *(param_1[0] + 0x1b79c) == 0 → skip everything
- Copy param_2 (string) into local buffer via _strncpy, max 0x3f chars
- Call FUN_00587c20(buffer, &DAT_005c3f6c) — decode/process
- If decode success:
  - FUN_005897ca(buffer, &DAT_005c3f6c) — further processing
  - FUN_005897ca(0, &DAT_005c3f6c) — get result
  - If result != 0: FUN_00587ece(result) — convert
- FUN_00563260(uVar2, 1, 5) — set configuration

**Globals:**
- DAT_007d0fe8 — Global state (used via uint cast)
- DAT_005c3f6c — Lookup/config data

**Calls:**
- _strncpy — CRT string copy
- FUN_00587c20 — String decode/parse
- FUN_005897ca — String processing
- FUN_00587ece — String/ID conversion
- FUN_00563260 — Configuration set

**Used by system:** docs/01-engine-architecture.md — string config processing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00462d30 — Enum-to-Enum Translator

Source: unknown | Confidence: medium
Translates an enum value from one system's representation to another. Maps values {2 → 1, 3 → 2, 5 → 4, else → 0 or 3}.

**Key logic:**
- Call FUN_0057a900() — preliminary check
- If result == 0: return 0
- Call FUN_0057a590(param_1) — get source enum
- Switch on result:
  - 0: return 0
  - 2: return 1
  - 3: return 2
  - 5: return 4
  - default: return 3

**Calls:**
- FUN_0057a900 — Pre-check
- FUN_0057a590 — Enum source

**Used by system:** docs/01-engine-architecture.md — enum translation layer

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a1830 � Windows Message Pump with Sleep

Source: unknown | Confidence: high
Pumps Windows messages with sleep between frames.

**Key logic:**
- Initial PeekMessage
- Loop while messages exist:
  - GetMessageA, TranslateMessage, DispatchMessageA
  - If WM_QUIT: return -1
- If no messages and sleep flag not set: Sleep(dwMilliseconds)
- Return 0

**Globals:**
- DAT_007ce2e4 � Sleep suppress flag

**Calls:** PeekMessageA, GetMessageA, TranslateMessage, DispatchMessageA, Sleep

**Used by system:** docs/01-engine-architecture.md � main loop

**Moddability:** hookable � sleep via DAT_007ce2e4

<!-- target: docs/20-math-utilities.md -->

## FUN_005539f0 — Resource Cascade Cleanup

Source: unknown | Confidence: high
Three-step resource cleanup: unlink from list → conditional cleanup → free memory.

**Key logic:**
- Calls FUN_0055c2e0(param_1) — doubly-linked list node unlink
- If param_1 non-null: calls FUN_00553310 (conditional cleanup), then FUN_00587bcf (free wrapper)
- Returns 0

**Calls:** FUN_0055c2e0 (list unlink), FUN_00553310 (resource cleanup), FUN_00587bcf (free)

**Used by system:** docs/01-engine-architecture.md — generic engine resource manager cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00556440 — High-Resolution Timer Reset

Source: unknown | Confidence: high
Resets a high-precision timer using QueryPerformanceCounter or RDTSC.

**Key logic:**
- Guards on `*param_1 != 0`
- If `param_1+0x12` bit 0 clear: uses FUN_0055687b (RDTSC); else QueryPerformanceCounter
- Stores time at param_1[6]/[7] (+0x18/+0x1c)
- Clears elapsed (+0x30/+0x34), pause (+0x28/+0x2c), total (+0x04/+0x08)
- Copies base time: param_1[8]/[9] = param_1[6]/[7]

**Calls:** QueryPerformanceCounter, FUN_0055687b (RDTSC)

**Used by system:** docs/01-engine-architecture.md — engine frame/lap timing

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0055d590 — Triple-Field Getter

Source: unknown | Confidence: high
Null-safe getter for 3 consecutive int32 fields at +0x44, +0x48, +0x4c.

**Key logic:**
- Each output pointer checked independently; may be null
- Field values read from param_1+0x44, +0x48, +0x4c

**Used by system:** docs/01-engine-architecture.md — generic property accessor

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00564890 — Indirect Call via Function Pointer

Source: unknown | Confidence: medium
Calls helper then invokes function pointer at param_1+0x10.

**Key logic:**
- If `*(param_1+0x10)` non-null: calls FUN_005648b0, then calls `*(param_1+0x10)()`

**Calls:** FUN_005648b0 — linear interpolation utility

**Used by system:** docs/01-engine-architecture.md — callback invocation

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_00568ba0 — Struct Zero-Init (17 Fields)

Source: unknown | Confidence: high
Zeroes 17 consecutive int32 fields of a struct (param_1[0x04] through [0x11]).

**Key logic:**
- Sets 17 fields to 0; field at index 0x01 intentionally preserved
- Struct size 0x48 bytes, 68 bytes zeroed

**Used by system:** docs/01-engine-architecture.md — struct initialization

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0057a950 — Cleanup Wrapper with SEH

Source: unknown | Confidence: medium
Registers cleanup routine via FUN_00587b3e(&LAB_0057a960).

**Key logic:**
- Calls FUN_00587b3e — callback registration for cleanup/exception handling

**Calls:** FUN_00587b3e — callback registration

**Used by system:** docs/01-engine-architecture.md — SEH-safe cleanup registration

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_005818e0 — List Destruction with Handle Close

Source: unknown | Confidence: high
Destroys linked list, closes Win32 handle, frees each node.

**Key logic:**
- If flag at +0x18 set: closes handle at param_1[4] via CloseHandle
- Walks list: for each node, calls vtable[0] destructor if flag set, frees node
- Clears list metadata (param_1[0..3] = 0)

**Calls:** CloseHandle, vtable[0] (destructor), FUN_00587bcf (free)

**Used by system:** docs/01-engine-architecture.md — engine resource list destruction

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00583570 — List Destruction with COM Release

Source: unknown | Confidence: high
Destroys linked list with SEH-wrapped cleanup.

**Key logic:**
- Walks list, for each node: calls FUN_0058a5f7 (SEH callback loop) then frees sub-object and node
- FUN_0058a5f7 params: (iVar3, 0x103c, *(iVar3-4), FUN_0047aa60)
- Allocation header at -4 offset

**Calls:** FUN_0058a5f7 (SEH callback), FUN_0047aa60 (math), FUN_00587bcf (free)

**Used by system:** docs/01-engine-architecture.md — COM-style object cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00585680 — Thread Resume with Mutex Wait

Source: unknown | Confidence: high
Resumes suspended thread under dual mutex protection with retry loop.

**Key logic:**
- Waits on timing mutex (+0xd4), calls timing functions, releases
- If thread handle (+0x04) non-null: loops up to 50× calling ResumeThread with Sleep backoff
- If ResumeThread returns 0 or 1: clears flag, breaks
- Waits on sync mutex (+0x20) before resume attempt

**Calls:** WaitForSingleObject, ReleaseMutex, ResumeThread, Sleep, FUN_00583680 (timing), FUN_00583660 (timing)

**Used by system:** docs/01-engine-architecture.md — worker thread synchronization

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00586500 — Mutex Create/Recreate

Source: unknown | Confidence: high
Creates unnamed Win32 mutex with inheritance.

**Key logic:**
- If flag +0x0c set: closes existing handle at +0x04
- Creates new mutex via CreateMutexA (inherit=true, name=null)
- Stores handle at +0x04, sets flag at +0x0c

**Calls:** CloseHandle, CreateMutexA

**Used by system:** docs/01-engine-architecture.md — threading sync primitive management

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00587090 — Object Copy-Construct from Source

Source: unknown | Confidence: medium
Copy-constructs object, initializing vtable and copying fields.

**Key logic:**
- Calls FUN_00587490(param_2+4) — struct zero-init
- Copies fields +0x10→param_1[4], +0x14→param_1[5], +0x18→param_1[6] byte
- Sets vtable: `*param_1 = &PTR_FUN_005b8c30`

**Calls:** FUN_00587490 (struct init)

**Used by system:** docs/01-engine-architecture.md — object copying in container

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0058af5c — Error ID Lookup Table

Source: unknown | Confidence: high
Maps error IDs to error codes via lookup table with range-based fallback.

**Key logic:**
- Calls FUN_0058afd8 (TLS getter), stores param_1
- Walks table at 0x005e65c0 (stride 8 bytes, ~90 entries)
- Matched: FUN_0058afcf (TLS access), stores mapped code
- Range 0x12-0x24 → code 0xd; 0xbb-0xca → code 8; default → code 0x16

**Globals:** DAT_005e65c0 — error lookup table base

**Calls:** FUN_0058afd8 (TLS getter), FUN_0058afcf (TLS access)

**Used by system:** docs/01-engine-architecture.md — centralized error mapping

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059247a — Critical Section Guarded Call

Source: unknown | Confidence: high
Calls function under critsect 0xb.

**Key logic:**
- Enter critsect 0xb (FUN_0058dfea), call FUN_0059249b, leave critsect (FUN_0058e04b)

**Calls:** FUN_0058dfea (critsect enter), FUN_0059249b (operation), FUN_0058e04b (critsect leave)

**Used by system:** docs/01-engine-architecture.md — thread-safe call wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059557d — String Parse with Format

Source: unknown | Confidence: medium
Parses string via format function, passes to handler.

**Key logic:**
- Calls FUN_00596245 (parse/format, 393 lines) then FUN_0059553a (delegation)

**Calls:** FUN_00596245 (format/parse), FUN_0059553a (delegation)

**Used by system:** docs/01-engine-architecture.md — config or command parsing

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00598600 — String Alloc+Copy

Source: unknown | Confidence: high
strlen + malloc + strcpy string duplication.

**Key logic:**
- Null-guard; calls _strlen, _malloc(len+1), FUN_0058fca0 (copy)
- Returns 0 on failure

**Calls:** _strlen, _malloc, FUN_0058fca0 (string copy)

**Used by system:** docs/01-engine-architecture.md — string duplication utility

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00599615 — Buffer Write with Null-Terminate

Source: unknown | Confidence: high
Writes data to buffer with capacity check, null-terminates.

**Key logic:**
- Validates via FUN_00599560(param_3, 1)
- Calls FUN_0058cc00 (memory write), updates written size at +0x08
- Null-terminates at buffer[param_3] = 0

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x04 | byte* | Buffer pointer |
| +0x08 | int | Written size tracker |

**Calls:** FUN_00599560 (validation), FUN_0058cc00 (memory write)

**Used by system:** docs/01-engine-architecture.md — string/buffer management

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d6a9 — Null-Checked Call Wrapper

Source: unknown | Confidence: high
Returns 0 if param_1 null, else calls FUN_005679a5 (list traversal).

**Calls:** FUN_005679a5 (list traversal with early exit)

**Used by system:** docs/01-engine-architecture.md — null-safe call wrapper

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00456010 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00471a00 -- Object Constructor

Source: unknown | Confidence: medium
Allocates or initializes object with vtable and defaults.

**Key logic:**
- Allocates or initializes object with vtable and defaults.

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00473cc0 -- Object Constructor

Source: unknown | Confidence: medium
Allocates or initializes object with vtable and defaults.

**Key logic:**
- Allocates or initializes object with vtable and defaults.

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00477810 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0049d8b0 -- Utility Function

Source: unknown | Confidence: medium
General utility function. See decompiled code for exact behavior.

**Key logic:**
- General utility function. See decompiled code for exact behavior.

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004a0de0 -- Function Call Wrapper

Source: unknown | Confidence: medium
Forwards call to another function. No additional logic.

**Key logic:**
- Forwards call to another function. No additional logic.

**Used by system:** docs/01-engine-architecture.md

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00560c00 — State Flag Setter + Cleanup

Source: unknown | Confidence: medium
Sets a state flag at param_1+0x24 to 2, then triggers general cleanup.

**Key logic:**
- Writes immediate value 2 to `*(param_1 + 0x24)` — state/status transition
- Calls FUN_004b0170() — general cleanup/release/destructor (docs/01, docs/20)
- Function is minimal: flag write followed by cleanup, suggesting object teardown or reset

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x24 | unknown | int | Set to 2 — state flag indicating a specific phase |

**Globals:** none

**Calls:**
- FUN_004b0170 — general cleanup/release signal (docs/01, docs/20)

**Used by system:** docs/01-engine-architecture — likely object destructor or state machine transition during engine lifecycle

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00582290 — Conditional Free by Flag Check

Source: unknown | Confidence: high
Conditionally frees a heap allocation if a flag byte at param_1+8 is non-zero.

**Key logic:**
- Reads flag byte at `param_1[2]` (byte offset +8: param_1 is int*, so param_1[2] = param_1 + 0x8)
- If flag byte != '\0': calls FUN_00587bcf(*param_1) to free the pointer stored at param_1[0]
- Otherwise: returns immediately with no action
- Typical pattern: object has a flag indicating whether its primary allocation needs freeing

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x00 | Ptr | pointer | Heap allocation to conditionally free |
| +0x08 | FreeFlag | byte | Non-zero indicates allocation should be freed |

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/01-engine-architecture — generic memory/object cleanup pattern

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059a541 — Cleanup Callback Registration

Source: unknown | Confidence: high
Registers FUN_00599796 as a deferred cleanup callback via MSVC _atexit-like mechanism.

**Key logic:**
- Calls FUN_00587b3e(FUN_00599796) — registers address of FUN_00599796 as an atexit/deferred cleanup handler
- FUN_00599796 is an empty stub (no-op) — likely a stripped locale refcount release

**Globals:** none

**Calls:**
- FUN_00587b3e — MSVC _atexit-like deferred callback registration (docs/01)
- FUN_00599796 — empty stub / locale refcount release (no-op, docs/20)

**Used by system:** docs/01-engine-architecture — static init/cleanup registration pattern

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c400 — SEH Unwind: Free Object at EBP-0x54

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored on the stack frame during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x54)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper
- Standard MSVC SEH unwind pattern: cleans up partially-constructed objects when an exception unwinds past their construction point

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c50e — SEH Unwind: Free Object at EBP-0x3C

Source: unknown | Confidence: high
SEH unwind handler that frees an object pointer stored on the stack frame during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x3c)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper
- Standard MSVC SEH unwind pattern

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c566 — SEH Unwind: Call FUN_00506ccc Cleanup

Source: unknown | Confidence: high
SEH unwind handler that calls FUN_00506ccc (vtable set + free child) during exception propagation.

**Key logic:**
- Calls FUN_00506ccc() — cleanup function that sets vtable to PTR_FUN_005adb80 and frees sub-object at param_1[0x413]
- No arguments needed (uses static EBP-relative context from caller's frame)
- Standard MSVC SEH unwind pattern for objects with renderer sub-resources

**Globals:** none

**Calls:**
- FUN_00506ccc — vtable set + free child (docs/19)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling (likely renderer object cleanup)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c6ca — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler freeing object at EBP+8 via FUN_00587bcf.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer at EBP+8
- Calls FUN_00587bcf() — heap free

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c706 — SEH Unwind: Free Object at EBP+8

Source: unknown | Confidence: high
SEH unwind handler freeing object at EBP+8 via FUN_00587bcf.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + 8)` — object pointer at EBP+8
- Calls FUN_00587bcf() — heap free

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c846 — SEH Unwind: Call FUN_00581ad0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling close handle + list destroy during exception propagation.

**Key logic:**
- Calls FUN_00581ad0() — close handle, destroy linked list, free nodes
- Standard MSVC SEH cleanup for objects with handle + linked list resources

**Globals:** none

**Calls:**
- FUN_00581ad0 — close handle + destroy linked list + free nodes (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c88e — SEH Unwind: Call FUN_00582a10 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling list/system cleanup during exception propagation.

**Key logic:**
- Calls FUN_00582a10() — linked list/system cleanup (docs/20)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00582a10 — system/list cleanup (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059caa0 — SEH Unwind: Call FUN_0047aa60 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling empty stub / small destructor during exception propagation.

**Key logic:**
- Calls FUN_0047aa60() — empty stub / no-op / small array destructor
- Functions in 0x0047XXXX range are game-logic/UI adjacent

**Globals:** none

**Calls:**
- FUN_0047aa60 — empty stub / small destructor / no-op (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cb40 — SEH Unwind: Call FUN_00583270 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked list destructor with vtable cleanup during exception propagation.

**Key logic:**
- Calls FUN_00583270() — linked list destructor with vtable cleanup call
- Standard MSVC SEH cleanup for objects with linked lists and virtual methods

**Globals:** none

**Calls:**
- FUN_00583270 — linked list destructor with vtable cleanup (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cb88 — SEH Unwind: Call FUN_00583050 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling destroy linked list with SEH during exception propagation.

**Key logic:**
- Calls FUN_00583050() — destroy linked list with SEH, call destructors (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00583050 — destroy linked list with SEH, call destructors (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cc08 — SEH Unwind: Call FUN_005822b0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked-list free during exception propagation.

**Key logic:**
- Calls FUN_005822b0() — standard linked-list free (docs/20)
- Same target as Unwind_0059c988

**Globals:** none

**Calls:**
- FUN_005822b0 — linked-list free standard (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cce0 — SEH Unwind: Free Object at EBP-0x14

Source: unknown | Confidence: high
SEH unwind handler freeing a stack-local object during exception propagation.

**Key logic:**
- Reads `*(undefined4*)(unaff_EBP + -0x14)` — stack-local object pointer
- Calls FUN_00587bcf() — heap memory free wrapper

**Globals:** none

**Calls:**
- FUN_00587bcf — heap memory free wrapper (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cd88 — SEH Unwind: Call FUN_005819c0 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked list destroy with vtable destructor during exception propagation.

**Key logic:**
- Calls FUN_005819c0() — linked list destroy with vtable destructor call (docs/01)
- Standard MSVC SEH cleanup for objects with linked lists containing virtual-method objects

**Globals:** none

**Calls:**
- FUN_005819c0 — linked list destroy with vtable destructor (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ce40 — SEH Unwind: Call FUN_004b0170 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling general cleanup/destructor during exception propagation.

**Key logic:**
- Calls FUN_004b0170() — general cleanup/release/destructor (docs/01, docs/20)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_004b0170 — general cleanup/release signal (docs/01, docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cea2 — SEH Unwind: Call FUN_00586240 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked-list destruction with SEH + alloc cleanup during exception propagation.

**Key logic:**
- Calls FUN_00586240() — linked-list destruction with SEH + alloc cleanup (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00586240 — linked-list destruction with SEH + alloc cleanup (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cedf — SEH Unwind: Call FUN_00586170 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling handle close + linked list cleanup during exception propagation.

**Key logic:**
- Calls FUN_00586170() — handle close & linked list cleanup (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00586170 — handle close & linked list cleanup (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d0b2 — SEH Unwind: Call FUN_0047aa60 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling empty stub / small destructor during exception propagation.

**Key logic:**
- Calls FUN_0047aa60() — empty stub / no-op / small array destructor
- Same pattern as Unwind_0059caa0, Unwind_0059d070

**Globals:** none

**Calls:**
- FUN_0047aa60 — empty stub / small destructor / no-op (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d110 — SEH Unwind: Call FUN_00586460 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling linked list destroy with vtable destructor dispatch during exception propagation.

**Key logic:**
- Calls FUN_00586460() — destroy linked list with vtable destructor dispatch (docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00586460 — destroy linked list with vtable destructor dispatch (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d17b — SEH Unwind: Call FUN_0059b390 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling dual-pointer free during exception propagation.

**Key logic:**
- Calls FUN_0059b390() — dual-pointer free (frees two heap allocations, docs/01)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_0059b390 — dual-pointer free (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d248 — SEH Unwind: Conditional Call FUN_00598aea

Source: unknown | Confidence: high
SEH unwind handler that conditionally calls vtable set + sub-call cleanup based on a flag bit.

**Key logic:**
- Checks bit 0 of `*(uint*)(unaff_EBP + -0x10)` — construction-complete flag
- If bit 0 set: calls FUN_00598aea() — vtable set + sub-call cleanup
- Standard MSVC EH pattern: flag tracks whether construction completed; only call destructor if object was fully constructed

**Globals:** none

**Calls:**
- FUN_00598aea — vtable set + sub-call cleanup (docs/01)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d2dc — SEH Unwind: Call FUN_00598cc1 Cleanup

Source: unknown | Confidence: high
SEH unwind handler calling locale vtable set + cleanup during exception propagation.

**Key logic:**
- Calls FUN_00598cc1() — set locale vtable and call cleanup (docs/20)
- Standard MSVC SEH cleanup pattern

**Globals:** none

**Calls:**
- FUN_00598cc1 — set locale vtable and call cleanup (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d3f0 — SEH Unwind: Conditional Call FUN_00599be5

Source: unknown | Confidence: high
SEH unwind handler that conditionally calls locale vtable destructor based on a flag bit.

**Key logic:**
- Checks bit 0 of `*(uint*)(unaff_EBP + -0x10)` — construction-complete flag
- If bit 0 set: calls FUN_00599be5() — set locale vtable and call destructor
- Standard MSVC EH pattern: only call destructor if object was fully constructed

**Globals:** none

**Calls:**
- FUN_00599be5 — set locale vtable and call destructor (docs/20)

**Used by system:** docs/01-engine-architecture — MSVC SEH exception handling

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00561f40 -- Dispatch Wrapper to Timeout Handler

Source: unknown | Confidence: high
Thin wrapper -- calls FUN_00562ac0 with no additional logic. No parameters, no return value.

**Key logic:**
- Single call to FUN_00562ac0()
- Returns void

**Calls:**
- FUN_00562ac0 -- Timeout/activity handler (docs/01-engine-architecture.md line 5287-5300)

**Used by system:** docs/01-engine-architecture.md -- timeout/dispatch wrapper

**Moddability:** hookable

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ae24 -- Exception Destructor SEH Wrapper

Source: unknown | Confidence: high
SEH-guarded exception destructor. Sets up exception handling frame, destructs an exception object, and restores the exception chain.

**Key logic:**
- Calls FUN_0058a5d8() -- SEH handler init / stack probe
- Writes exception pointer to stack frame at EBP-0x10
- Sets vtable of exception object `this` to `PTR_FUN_005b9d7c`
- Sets stack frame guard to 0 (try block marker)
- Calls FUN_005993af(1) -- reference count decrement with conditional free
- Sets stack guard to 0xFFFFFFFF (end of try block)
- Calls `exception::~exception(this)` -- MSVC exception destructor
- Restores ExceptionList from saved chain pointer at EBP-0x0C

**Calls:**
- FUN_0058a5d8 -- SEH handler init / stack probe (docs/20-math-utilities.md)
- FUN_005993af(1) -- Reference count decrement with conditional free (docs/20-math-utilities.md)
- exception::~exception -- MSVC exception destructor

**Used by system:** docs/01-engine-architecture.md -- C++ exception handling / cleanup wrapper

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c670 -- SEH Unwind: Free Object at +8

Source: unknown | Confidence: high
SEH unwind handler -- frees an object at stack offset EBP+8 during exception unwinding.

**Key logic:**
- Reads pointer from `*(undefined4 *)(unaff_EBP + 8)` (stack frame parameter/local)
- Calls FUN_00587bcf() to free the memory
- SEH unwind cleanup action: releases allocated memory when exception propagates through this frame

**Calls:**
- FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d03e -- SEH Unwind: Call FUN_00585fb0

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00585fb0 for linked list cleanup with sub-object deletion during exception unwinding.

**Key logic:**
- Calls FUN_00585fb0() -- linked list cleanup with sub-object delete (docs/20-math-utilities.md)
- No parameters, no return value
- SEH unwind cleanup action: releases linked list resources when exception propagates

**Calls:**
- FUN_00585fb0 -- Linked list cleanup with sub-object delete (docs/20-math-utilities.md)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / data structure cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c4c8 -- SEH Unwind: Free Field at -0x14

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x14 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x14)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c5c6 -- SEH Unwind: Free Object at +8

Source: unknown | Confidence: high
SEH unwind handler -- frees an object at stack offset EBP+8 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + 8)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded


<!-- target: docs/08-file-formats.md -->

## FUN_0059c6ac -- SEH Unwind: Free Object at +8

Source: unknown | Confidence: high
SEH unwind handler -- frees an object at stack offset EBP+8 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + 8)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c812 -- SEH Unwind: Call FUN_00581880

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00581880 (linked list destruction with vtable release) during exception unwinding.

**Key logic:**
- Calls FUN_00581880() -- linked list destruction with vtable release (docs/01-engine-architecture.md)

**Calls:** FUN_00581880 -- Linked list destruction with vtable release (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059c896 -- SEH Unwind: Call FUN_00581c20

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00581c20 (unknown cleanup) during exception unwinding.

**Key logic:**
- Calls FUN_00581c20() -- cleanup function (docs/06-session-race-logic.md)

**Calls:** FUN_00581c20 -- Cleanup function (docs/06)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c9a0 -- SEH Unwind: Call FUN_0047aa60

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_0047aa60 (small destructor / empty stub) during exception unwinding.

**Key logic:**
- Calls FUN_0047aa60() -- small destructor / math_util (docs/01-engine-architecture.md)

**Calls:** FUN_0047aa60 -- Small destructor / empty stub (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059cbe0 -- SEH Unwind: Call FUN_005834c0

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_005834c0 (list destruction with virtual release) during exception unwinding.

**Key logic:**
- Calls FUN_005834c0() -- list destruction with virtual release (docs/01-engine-architecture.md)

**Calls:** FUN_005834c0 -- List destruction with virtual release (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded


<!-- target: docs/20-math-utilities.md -->

## FUN_0059cd48 -- SEH Unwind: Call FUN_005833e0

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_005833e0 (walk linked list, call destructor, free nodes) during exception unwinding.

**Key logic:**
- Calls FUN_005833e0() -- walk linked list, call destructor, free nodes (docs/01-engine-architecture.md)

**Calls:** FUN_005833e0 -- Walk list, call destructor, free nodes (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059ce60 -- SEH Unwind: Call FUN_0058a5f7 (Array Destructor)

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_0058a5f7 to destroy an array of 0x28-sized objects during exception unwinding.

**Key logic:**
- Computes array address from *(unaff_EBP + -0x14) + 4
- Calls FUN_0058a5f7(array, 0x28, 1, FUN_00583aa0) -- N-time callback loop with SEH
- Stride 0x28 (40 bytes), count 1, destructor callback FUN_00583aa0 (CloseHandle pair wrapper)

**Calls:**
- FUN_0058a5f7 -- N-time callback loop with SEH (docs/01-engine-architecture.md)
- FUN_00583aa0 -- Close handle pair wrapper (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / array cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cf3d -- SEH Unwind: Call FUN_005861e0

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_005861e0 (CloseHandle wrapper) during exception unwinding.

**Key logic:**
- Calls FUN_005861e0() -- CloseHandle wrapper (docs/01-engine-architecture.md)

**Calls:** FUN_005861e0 -- CloseHandle wrapper (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / handle cleanup

**Moddability:** hardcoded


<!-- target: docs/08-file-formats.md -->

## FUN_0059d091 -- SEH Unwind: Call FUN_0047aa60

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_0047aa60 (small destructor / empty stub) during exception unwinding.

**Key logic:**
- Calls FUN_0047aa60() -- small destructor / empty stub (docs/01-engine-architecture.md)

**Calls:** FUN_0047aa60 -- Small destructor / empty stub (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d1e8 -- SEH Unwind: Call FUN_00599796 (Cleanup with Descriptor)

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00599796 with a stack-local pointer and global type descriptor DAT_008d42d8 during exception unwinding.

**Key logic:**
- Reads object pointer from *(unaff_EBP + -0x10)
- Calls FUN_00599796(object_ptr, &DAT_008d42d8) -- cleanup with type descriptor pair

**Calls:**
- FUN_00599796 -- Cleanup with type descriptor / empty stub (docs/20-math-utilities.md)
- DAT_008d42d8 -- Global type descriptor

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / locale cleanup

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059d2e4 -- SEH Unwind: Call FUN_00598c70

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00598c70 (null check with virtual dispatch) during exception unwinding.

**Key logic:**
- Calls FUN_00598c70() -- null check with virtual dispatch / init helper (docs/01-engine-architecture.md)

**Calls:** FUN_00598c70 -- Null check with virtual dispatch (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d470 -- SEH Unwind: Exception Destructor at -0x14

Source: unknown | Confidence: high
SEH unwind handler -- destructs an exception object at stack offset EBP-0x14 during exception unwinding.

**Key logic:**
- Reads exception pointer from *(exception **)(unaff_EBP + -0x14)
- Calls exception::~exception() on the object
- SEH unwind cleanup action: ensures exception object is properly destroyed

**Calls:** exception::~exception -- MSVC exception destructor

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / exception handling

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0059c414 -- SEH Unwind: Free Field at -0x48

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x48 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x48)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c620 -- SEH Unwind: Free Object at +8

Source: unknown | Confidence: high
SEH unwind handler -- frees an object at stack offset EBP+8 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + 8)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded


<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c730 -- SEH Unwind: Free Field at -0x10

Source: unknown | Confidence: high
SEH unwind handler -- frees a field from stack frame at EBP-0x10 during exception unwinding.

**Key logic:**
- Reads pointer from *(unaff_EBP + -0x10)
- Calls FUN_00587bcf() to free the memory

**Calls:** FUN_00587bcf -- Memory free/deallocation (docs/08, docs/20)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c980 -- SEH Unwind: Call FUN_00581880

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00581880 (linked list destruction with vtable release) during exception unwinding.

**Key logic:**
- Calls FUN_00581880() -- linked list destruction with vtable release (docs/01-engine-architecture.md)

**Calls:** FUN_00581880 -- Linked list destruction with vtable release (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cc88 -- SEH Unwind: Call FUN_00582f60

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00582f60 (SEH-protected linked list destruction) during exception unwinding.

**Key logic:**
- Calls FUN_00582f60() -- SEH-protected linked list destruction (docs/01-engine-architecture.md)

**Calls:** FUN_00582f60 -- SEH-protected linked list destruction (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / list cleanup

**Moddability:** hardcoded


<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ce7e -- SEH Unwind: Call FUN_00585f30

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00585f30 (handle close with flag check) during exception unwinding.

**Key logic:**
- Calls FUN_00585f30() -- handle close with flag check (docs/01-engine-architecture.md)

**Calls:** FUN_00585f30 -- Handle close with flag check (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / handle cleanup

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d058 -- SEH Unwind: Call FUN_00583650

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00583650 (single function call wrapper) during exception unwinding.

**Key logic:**
- Calls FUN_00583650() -- single function call wrapper (docs/01-engine-architecture.md)

**Calls:** FUN_00583650 -- Single function call wrapper (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d358 -- SEH Unwind: Call FUN_00599796 (Cleanup with Descriptor)

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_00599796 with a stack-local pointer and global type descriptor DAT_008d4400 during exception unwinding.

**Key logic:**
- Reads object pointer from *(unaff_EBP + -0x10)
- Calls FUN_00599796(object_ptr, &DAT_008d4400) -- cleanup with type descriptor pair

**Calls:**
- FUN_00599796 -- Cleanup with type descriptor / empty stub (docs/20-math-utilities.md)
- DAT_008d4400 -- Global type descriptor

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind / locale cleanup

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d524 -- SEH Unwind: Call FUN_0059a9c2

Source: unknown | Confidence: high
SEH unwind handler -- calls FUN_0059a9c2 (single function call wrapper) during exception unwinding.

**Key logic:**
- Calls FUN_0059a9c2() -- single function call wrapper (docs/01-engine-architecture.md)

**Calls:** FUN_0059a9c2 -- Single function call wrapper (docs/01)

**Used by system:** docs/01-engine-architecture.md -- MSVC SEH unwind support

**Moddability:** hardcoded

## FUN_0059c446 — SEH Unwind Free Object at -0x14

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x14.

**Key logic:**
- Loads pointer from stack at EBP-0x14
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for object at stack offset -0x14

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c4d2 — SEH Unwind Free Object at -0x1c

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x1c.

**Key logic:**
- Loads pointer from stack at EBP-0x1c
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for object at stack offset -0x1c

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c52c — SEH Unwind with Single Call

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls a cleanup function with no local argument.

**Key logic:**
- Calls FUN_00506ccc() (Vtable Set + Free Child / destructor continuation)
- No parameters, no stack locals read

**Calls:**
- FUN_00506ccc — Vtable Set + Free Child / destructor continuation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling destructor continuation

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c582 — SEH Unwind Free Object at -0x24

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x24.

**Key logic:**
- Loads pointer from stack at EBP-0x24
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for object at stack offset -0x24

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c5d0 — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +8 (parameter slot).

**Key logic:**
- Loads pointer from stack at EBP+8
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for parameter at stack offset +8

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c60c — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +8 (parameter slot).

**Key logic:**
- Loads pointer from stack at EBP+8
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for parameter at stack offset +8

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c6fc — SEH Unwind Free Object at +8

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +8 (parameter slot).

**Key logic:**
- Loads pointer from stack at EBP+8
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for parameter at stack offset +8

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c7b0 — SEH Unwind Free Object at -0x10

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x10.

**Key logic:**
- Loads pointer from stack at EBP-0x10
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for object at stack offset -0x10

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c880 — SEH Unwind: Call FUN_00581b30

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00581b30 (cleanup callback dispatch).

**Key logic:**
- Calls FUN_00581b30() with no arguments

**Calls:**
- FUN_00581b30 — Cleanup callback dispatch (docs/20)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling cleanup callback dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059c910 — SEH Unwind: Call FUN_00581a20

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00581a20 (Handle Close + Linked-List Destruction with VTable Release).

**Key logic:**
- Calls FUN_00581a20() with no arguments

**Calls:**
- FUN_00581a20 — Handle Close + Linked-List Destruction with VTable Release (docs/01)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling handle/list destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059c956 — SEH Unwind: Call FUN_00581c20

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00581c20 (cleanup/destructor function).

**Key logic:**
- Calls FUN_00581c20() with no arguments

**Calls:**
- FUN_00581c20 — Cleanup/destructor function (docs/06)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling cleanup function

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059ca80 — SEH Unwind: Call FUN_0047aa60

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_0047aa60 (empty stub / no-op) during stack unwinding.

**Key logic:**
- Calls FUN_0047aa60() with no arguments

**Calls:**
- FUN_0047aa60 — Empty stub / no-op cleanup function (docs/20)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling no-op stub

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059cb28 — SEH Unwind Free Object at +4

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object at stack offset +4.

**Key logic:**
- Loads pointer from stack at EBP+4
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for object at stack offset +4

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cc60 — SEH Unwind Free Object at -0x14

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x14.

**Key logic:**
- Loads pointer from stack at EBP-0x14
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for object at stack offset -0x14

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ccc8 — SEH Unwind: Call FUN_00581880

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00581880 (Linked List Destruction with VTable Release Call).

**Key logic:**
- Calls FUN_00581880() with no arguments

**Calls:**
- FUN_00581880 — Linked List Destruction with VTable Release Call (docs/01)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling linked list destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cd80 — SEH Unwind: Call FUN_005834c0

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_005834c0 (List Destruction with Virtual Release). Same target as Unwind_0059cb80.

**Key logic:**
- Calls FUN_005834c0() with no arguments

**Calls:**
- FUN_005834c0 — List Destruction with Virtual Release (docs/01)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling list destructor

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059ce20 — SEH Unwind Free Object at -0x10

Source: unknown | Confidence: high
MSVC SEH unwind handler — frees an object allocated at stack offset -0x10.

**Key logic:**
- Loads pointer from stack at EBP-0x10
- Calls FUN_00587bcf (heap memory free)

**Calls:**
- FUN_00587bcf — heap free / memory deallocation

**Used by system:** docs/01-engine-architecture.md — SEH cleanup for object at stack offset -0x10

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059cfbe — SEH Unwind: Call FUN_004b0170

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_004b0170 (destructor/release/cleanup) during stack unwinding.

**Key logic:**
- Calls FUN_004b0170() — cleanup/release

**Calls:**
- FUN_004b0170 — Game state update / object release / destructor (docs/01, docs/06, docs/17)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling release/destructor

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d0f6 — SEH Unwind: Call FUN_0047aa60

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_0047aa60 (empty stub / no-op) during stack unwinding.

**Key logic:**
- Calls FUN_0047aa60() with no arguments

**Calls:**
- FUN_0047aa60 — Empty stub / no-op cleanup function (docs/20)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling no-op stub

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d224 — SEH Unwind: Conditional Call FUN_00598aea

Source: unknown | Confidence: high
MSVC SEH unwind handler — conditionally calls FUN_00598aea (Vtable Set + Sub-Call) based on a flag bit at EBP-0x10.

**Key logic:**
- Checks bit 0 of uint at stack offset EBP-0x10
- If set: calls FUN_00598aea() — Vtable set + sub-call cleanup
- Else: returns immediately — no cleanup performed

**Calls:**
- FUN_00598aea — Vtable Set + Sub-Call / conditional cleanup (docs/01)

**Used by system:** docs/01-engine-architecture.md — conditional SEH cleanup based on initialization flag

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0059d427 — SEH Unwind: Call FUN_00598c70

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_00598c70 (Null Check with Virtual Dispatch) during stack unwinding.

**Key logic:**
- Calls FUN_00598c70() with no arguments

**Calls:**
- FUN_00598c70 — Null Check with Virtual Dispatch (docs/01)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling null-check dispatch

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d484 — SEH Unwind: Destroy Exception Object

Source: unknown | Confidence: high
MSVC SEH unwind handler — destroys a C++ exception object at stack offset -0x10 by calling its destructor.

**Key logic:**
- Loads exception pointer from stack at EBP-0x10
- Calls exception::~exception() on the exception object

**Calls:**
- exception::~exception (MSVC C++ exception destructor)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup destroying exception object

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d508 — SEH Unwind: Call FUN_0059ac3f

Source: unknown | Confidence: high
MSVC SEH unwind handler — calls FUN_0059ac3f (VTable Pointer Setter) during stack unwinding.

**Key logic:**
- Calls FUN_0059ac3f() with no arguments

**Calls:**
- FUN_0059ac3f — VTable Pointer Setter / constructor helper (docs/01)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup calling vtable setter

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0059d56c — SEH Unwind: Destroy Exception Object

Source: unknown | Confidence: high
MSVC SEH unwind handler — destroys a C++ exception object at stack offset -0x10 by calling its destructor. Identical to Unwind_0059d484.

**Key logic:**
- Loads exception pointer from stack at EBP-0x10
- Calls exception::~exception() on the exception object

**Calls:**
- exception::~exception (MSVC C++ exception destructor)

**Used by system:** docs/01-engine-architecture.md — SEH cleanup destroying exception object

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

### FUN_0042d6b0 — Game::Init

Source: game.cpp. Sets game state machine to state 3, then calls all major subsystem initialization functions. Returns 0 on success, 1 if VidMan::Init fails.

**Key logic:**
- Sets `*param_1 = 3` (Game state 3 = Init)
- Calls FUN_004d7a50/7aa0 for scoped logging
- Calls FUN_004ba1f0 (replay/load state init)
- Calls FUN_004fa320 (VidMan::Init) — if non-zero return, abort with error code 1
- Calls subsystem inits in sequence: sound init (FUN_004c8ae0), physics (FUN_004040a0), file paths (FUN_004b0170), timers (FUN_004d38f0), hardware input (FUN_00455d50), special effects (FUN_004cf070), game state (FUN_0042c1a0), replay (FUN_0040c920), on-screen display (FUN_0049efa0), HUD (FUN_004b4030), pit UI (FUN_004a40e0), menu (FUN_00463f70)
- Returns 0

**Calls:** FUN_004ba1f0 (replay init), FUN_004fa320 (VidMan::Init, docs/01), FUN_004bdc10, FUN_004fcaa0, FUN_004040a0, FUN_004b0170, FUN_004d38f0, FUN_00455d50 (HWInput::Init, docs/01), FUN_004cf070 (SpecialFX::Init, docs/09), FUN_0042c1a0, FUN_0040c920, FUN_004c8ae0 (Sound::Init, docs/01), FUN_004b4030, FUN_004a40e0, FUN_0049efa0 (OnScreen::Init, docs/01), FUN_004a1830, FUN_00463f70

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

### FUN_004c8ab0 — Sound::Setup

Source: sound.cpp. Log-only entry function. Part of the Sound Manager module lifecycle (state 2/Setup phase).

**Key logic:**
- Calls FUN_004d7a50 for assertion/scope entry
- Calls FUN_004d7aa0 for log message if assertions enabled
- No other operations

**Calls:** FUN_004d7a50 (assert/scope), FUN_004d7aa0 (log)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

### FUN_0049f120 — OnScreen::Exit

Source: onscreen.cpp. Log-only cleanup function. Part of the OnScreen Manager module lifecycle (state 7/Exit phase).

**Key logic:**
- Calls FUN_004d7a50 for assertion/scope entry
- Calls FUN_004d7aa0 for log message if assertions enabled
- No other cleanup operations

**Calls:** FUN_004d7a50 (assert/scope), FUN_004d7aa0 (log)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

### FUN_004fa640 — VidMan::Restart

Source: vidman.cpp. Pauses game and reconfigures render state based on current session type. Handles formation lap gate for race sessions.

**Key logic:**
- Calls FUN_0042d210(0) to pause game execution
- Switches on `DAT_007c56a4` (SessionType):
  - Cases 0-4 (practice): enables render state 0x40, disables 0x80
  - Case 5 (server): enables render state 0x40, enables 0x80
  - Cases 6-7 (quali/race): enables 0x40 and 0x80, conditionally 0x100
  - Race (7) specific: if ScoringGate != 2 AND HUD enabled AND network session OK, calls FUN_0042d210(1) to resume (formation lap gate)
  - Default: disables 0x40, 0x80, 0x100
- Calls FUN_004f9fc0(0), resets globals `DAT_008afea8`, `DAT_008afeac`, `DAT_008afe84`
- Calls FUN_004f8f10 (renderer callback) and FUN_004f9f70(0)

**Globals:**
- `DAT_007c56a4` — SessionType (7=race, 6=quali, 0-5=practice)
- `DAT_008ab6e4` — ScoringGate (skip if 2)
- `DAT_007ce254` — DisableHUDFlag

**Calls:** FUN_0042d210 (game pause/resume), FUN_0054a200 (render state set), FUN_00404f10, FUN_00461db0, FUN_004f9fc0, FUN_004f8f10, FUN_004f9f70

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

### FUN_004a18d0 — OSMan::Enter

Source: osman.cpp. Creates named mutex to enforce single application instance (prevents multiple F1 Challenge 99-02 processes).

**Key logic:**
- Calls FUN_004d7a50/7aa0 for scoped logging
- Creates mutex with name "F1 Challenge 99-02_APP_MUTEX" via CreateMutexA
- If mutex handle is valid, checks GetLastError():
  - If ERROR_ALREADY_EXISTS (0xB7): mutex already held by another instance → return 1 (failure)
  - Otherwise: first instance → return 0 (success)
- Stores mutex handle in `DAT_007ce2d8`

**Globals:**
- `DAT_007ce2d8` — mutex handle (new)

**Calls:** CreateMutexA (Win32 API), GetLastError (Win32 API), FUN_004d7a50 (assert/scope), FUN_004d7aa0 (log)

**Moddability:** hardcoded

<!-- target: docs/09-track-system.md -->

### FUN_0042db20 — Game::Exit()

Full game teardown. Sets state to 7 (exit), logs entry, calls shutdown sequence for all subsystems.

**Key logic:**
- Writes `*param_1 = 7` — transitions game state to Exit
- Logs "Entered Game::Exit()" via debug channel
- Calls exit/cleanup: Sound::Exit, render shutdown, string cleanup (×2), HWInput::Exit, game vars cleanup, OnScreen::Exit, VidMan::Exit, UI manager, game state machine, session cleanup

**Calls:** FUN_004c8d00 (Sound::Exit, docs/01), FUN_004cfff0, FUN_004b0170 (string buffer), FUN_00455f00 (HWInput::Exit, docs/01), FUN_0042ca70, FUN_004ba770, FUN_0049f120 (OnScreen::Exit), FUN_004fad00 (VidMan::Exit, docs/01), FUN_00464670, FUN_0042d350, FUN_004a1930

<!-- target: docs/01-engine-architecture.md -->

### FUN_004c8b20 — Sound::Restart()

Restarts the sound system. Logs entry, calls sound subsystem restart and audio manager re-init.

**Key logic:**
- Logs "Entered Sound::Restart()" from sound.cpp line 0x2b6
- Calls sound buffer restart (FUN_004c8630), sound channel reset (FUN_004c7dd0), audio manager init (FUN_004186a0)

**Calls:** FUN_004c8630 (sound buffer restart), FUN_004c7dd0 (sound channel reset), FUN_004186a0 (audio manager init)

<!-- target: docs/01-engine-architecture.md -->

### FUN_00455c60 — HWInput::Setup()

Initializes DirectInput for the hardware input subsystem.

**Key logic:**
- Skips debug log if `DAT_007c569c == 5` (server mode — no local input)
- Calls `DirectInput8Create(DAT_007ce2a0, 0x800, &DAT_005ad4a0, param_1, 0)` to create DirectInput device
- On failure (return != 0): calls DirectInput cleanup functions (FUN_0044ee10, FUN_0044fa60×3, FUN_0044fbe0×2, FUN_004533a0)

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server)
- `DAT_007ce2a0` — DirectInput instance handle
- `DAT_005ec4a4` — input config path
- `DAT_007ce2dc` — DirectInput device pointer

**Calls:** DirectInput8Create, FUN_0044ee10, FUN_0044fa60, FUN_0044fbe0, FUN_004533a0

<!-- target: docs/01-engine-architecture.md -->

### FUN_004fad00 — VidMan::Exit()

Shuts down the video manager. Logs entry, tears down renderer resources, releases device handle.

**Key logic:**
- Logs "Entered VidMan::Exit()" from vidman.cpp line 0x5b1
- Calls: texture manager cleanup, specialized renderer shutdown, memory cleanup (×2), scene object release
- If `DAT_008afe64` (display device handle) non-zero: calls FUN_0053d4c0 (device release) and sets to 0

**Globals:**
- `DAT_008afe64` — display device handle (cleared on exit)

**Calls:** FUN_00494900 (texture manager), FUN_0055c040, FUN_004a1830×2 (memory cleanup), FUN_004a14e0 (scene object release), FUN_0053d4c0

<!-- target: docs/01-engine-architecture.md -->

### FUN_004a0eb0 — Options::Setup()

Options menu main loop. Displays options screen, processes keyboard input, handles mode switching.

**Key logic:**
- Logs "Entered Options::Setup()" from options.cpp
- If `DAT_007ce260` == 0 (not in special init mode):
  - Sub-mode 0: enters menu loop — processes frame timing (FUN_004f9f00), renders UI (FUN_004537b0), increments frame counter (DAT_007ce250), checks keyboard (FUN_00485b90), dispatches frame (FUN_004186f0), calls UI/input handlers (FUN_004f9ad0, FUN_00404b60). Exits on DAT_007ce25c flag or ESC (key -1) or Enter (key 1).
  - Sub-mode non-0: checks DAT_005ccfe4 flag, clears and exits if set. Returns 1 otherwise.
- If DAT_007ce260 != 0: sets DAT_007c5690 = 1 (init state), returns 0.

**Globals:**
- `DAT_007ce260` — options init guard
- `DAT_007ce264` — sub-mode selector
- `DAT_007ce250` — frame counter
- `DAT_007ce25c` — exit flag
- `DAT_005ccfe4` — sub-mode exit flag
- `DAT_007c5690` — init state flag

**Calls:** FUN_004f9f00 (frame timing), FUN_004537b0, FUN_00485b90 (keyboard input), FUN_004186f0, FUN_004f9ad0, FUN_00404b60, FUN_004a1830

<!-- target: docs/09-track-system.md -->

### FUN_0042C130 — DynMan::Enter

DynMan module entry point. Called during engine module lifecycle to enter DynMan (Dynamic Manager) subsystem.

**Key logic:**
- Calls debug trace guard (FUN_004d7a50, level 2) to check if tracing enabled
- If enabled, logs "Entered DynMan::Enter()" to global trace buffer (DAT_008ad25c)
- Delegates to FUN_0042bd60 (Game::Post or engine tick) — drives engine state machine

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf), FUN_0042bd60 (game state tick, docs/01)

<!-- target: docs/01-engine-architecture.md -->

### FUN_004C8CA0 — Sound::Post

Sound module post-frame update. Called during engine Post phase for audio subsystem.

**Key logic:**
- Calls debug trace guard (FUN_004d7a50, level 2) — logs "Entered Sound::Post()" if enabled
- Calls four sub-functions in sequence for sound processing pipeline
- No return value — void dispatch

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf), FUN_004c8180 (sound update), FUN_004c7e80 (sound update), FUN_004c8a10 (sound update), FUN_00418a60 (unknown utility)

<!-- target: docs/01-engine-architecture.md -->

### FUN_00455D50 — HWInput::Init

Hardware input module initialization. Called during engine Init phase for input subsystem.

**Key logic:**
- Guards on DAT_007c569c (SessionType5, docs/12) — skips debug trace if SessionType5 == 5 (server mode)
- Calls debug trace guard (FUN_004d7a50, level 2) — logs "Entered HWInput::Init()" if not server
- Calls three initialization sub-functions in sequence

**Globals:**
- `DAT_007c569c` — SessionType5 (5=server, docs/12)

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf), FUN_004532d0 (input init), FUN_004533a0 (input init), FUN_00453560 (input init)

<!-- target: docs/01-engine-architecture.md -->

### FUN_004B4030 — Render::Init

Render module initialization entry point. Called during engine Init phase for rendering subsystem.

**Key logic:**
- Calls debug trace guard (FUN_004d7a50, level 2) — logs "Entered Render::Init()" if enabled
- Pure tracing function — no additional initialization calls
- Returns immediately after trace

**Calls:** FUN_004d7a50 (trace guard), FUN_004d7aa0 (trace printf)

<!-- target: docs/08-file-formats.md -->

### FUN_0042C170 — DynMan::Setup

Trace entry stub for dynamic manager setup. Logs "Entered DynMan::Setup()".

**Key logic:**
- Calls FUN_004d7a50 (assert/trace gate) with source path and line number
- If gate passes, calls FUN_004d7aa0 to log entry trace string

**Calls:** FUN_004d7a50 (trace gate, docs/21), FUN_004d7aa0 (trace log, docs/21)

<!-- target: docs/01-engine-architecture.md -->

### FUN_0042C1A0 — DynMan::Init

Initializes dynamic management system. Handles vehicle grid setup, session-dependent init paths, and per-vehicle UI setup.

**Key logic:**
- Iterates vehicle grid array DAT_005ef9a0 (stride 0x1230) up to 104 entries
- If RaceMode != 4 (championship), sets grid entry at +0x364 to slot index+1
- On empty slot or end, calls error handlers FUN_0042bbd0/FUN_0042bc40 if no vehicles found
- Branches on DAT_007c5690 (InitStateFlag): if 0, loads config via FUN_004b1520 then either race init (FUN_004bfd90, FUN_004bff70) or practice path
- If InitStateFlag != 0 and RaceMode == 4 (championship) and SessionType 1-4 (practice), calls FUN_004c01a0
- After init, iterates VehicleCount (DAT_005c329c) calling FUN_004c6c40 per vehicle
- If CurrentVehicleIndex (DAT_007c54e4) valid (0-0x67) and field +13000 == 0, calls FUN_004336f0

**Globals:** DAT_007d0410 (RaceMode), DAT_007c56a4 (SessionType), DAT_007c5690 (InitStateFlag), DAT_007cebc4 (FormationLap), DAT_005c329c (VehicleCount), DAT_007c54e4 (CurrentVehicleIndex), DAT_007c54f0 (VehiclePtrArray), DAT_005ef9a0 (VehicleGridArray)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_0040fe50, FUN_0042bbd0, FUN_0042bc40, FUN_004b1520, FUN_004bfd90, FUN_004bff70, FUN_004c01a0, FUN_0042bc80, FUN_005895a2, FUN_004f9480, FUN_004c6c40, FUN_004326e0, FUN_004336f0

**Moddability:** `hardcoded`

<!-- target: docs/01-engine-architecture.md -->

### FUN_0042C9F0 — DynMan::Post

Post-update processing for dynamic manager. Called after main update loop.

**Key logic:**
- Iterates all vehicles (VehicleCount DAT_005c329c) calling FUN_004c6e80 per vehicle
- Calls FUN_0043e230 (generic post-update)
- Calls FUN_0042bd60 (game state machine)
- Calls FUN_0040fb30 (memory/allocator cleanup)

**Globals:** DAT_005c329c (VehicleCount)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_004c6e80, FUN_0043e230, FUN_0042bd60 (Game::Post, docs/01), FUN_0040fb30

<!-- target: docs/01-engine-architecture.md -->

### FUN_004C8D00 — Sound::Exit

Sound module exit/cleanup. Shuts down sound subsystem.

**Key logic:**
- Calls FUN_00411740(1) and FUN_00411740(0) with channel IDs
- Calls FUN_00418900 (general cleanup)
- Calls FUN_004c8630 and FUN_004c8350 (sound tear-down)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_00411740, FUN_00418900, FUN_004c8630, FUN_004c8350

<!-- target: docs/01-engine-architecture.md -->

### FUN_0049EF40 — OnScreen::Enter

Empty trace-entry stub for OnScreen module. Logs "Entered OnScreen::Enter()".

**Key logic:**
- Calls FUN_004d7a50 (assert/trace gate), logs entry trace if gate passes
- No other logic — pure debug trace function

**Calls:** FUN_004d7a50 (trace gate, docs/21), FUN_004d7aa0 (trace log, docs/21)

<!-- target: docs/01-engine-architecture.md -->

### FUN_0049EFA0 — OnScreen::Init

Initializes on-screen display system (HUD, text overlays).

**Key logic:**
- Calls FUN_004d8220 (UI/widget pool init)
- If VehicleCount > 0, calls FUN_0049ca00 (vehicle HUD setup)
- Calls FUN_0045bbe0 (bitmap/texture load for UI)
- Calls FUN_0049b0a0 (HUD render state init)

**Globals:** DAT_005c329c (VehicleCount)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_004d8220, FUN_0049ca00, FUN_0045bbe0, FUN_0049b0a0

<!-- target: docs/01-engine-architecture.md -->

### FUN_00455DA0 — HWInput::Restart

Restarts hardware input system (keyboard/joystick/wheel). Resets input device state.

**Key logic:**
- Skips trace log if SessionType5 (DAT_007c569c) == 5 (server mode)
- Calls FUN_0044f680 with device parameter buffers (DAT_005d6d60, DAT_005d6d64)
- Calls FUN_0044f0a0 (input device reset)
- If DAT_007d1ffc (AudioQualityLevel) != 0, calls FUN_0044ff50 (audio mixer)
- Sets byte at param_1+0x2428 to 0 or 1 based on scan of input device struct at +0x1f98 checking for non-zero entries paired with 0x59

**Globals:** DAT_007c569c (SessionType5), DAT_007d1ffc (AudioQualityLevel), DAT_005d6d60, DAT_005d6d64

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_0044f680, FUN_0044f0a0, FUN_0044ff50 (audio mixer)

<!-- target: docs/01-engine-architecture.md -->

### FUN_00455E70 — HWInput::Post

Post-update processing for hardware input. Releases input devices and cleans up.

**Key logic:**
- Skips trace log if SessionType5 == 5 (server mode)
- Calls FUN_0044f070(1) (device close)
- If param_1[0x665] != 0, calls FUN_004526c0 (force feedback / haptic cleanup)
- Calls FUN_0044fbe0 (input buffer flush) twice
- Calls FUN_0044efe0 (keyboard state cleanup)
- Checks if param_1[0] (vtable/device ptr) is non-null, calls virtual method at vtable+8 (release), then zeros the pointer

**Globals:** DAT_007c569c (SessionType5)

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_0044f070, FUN_004526c0, FUN_0044fbe0, FUN_0044efe0

<!-- target: docs/01-engine-architecture.md -->

### FUN_004FA000 — VidMan::Enter

Video manager initialization. Detects display device, may launch 3DCONFIG.EXE for configuration, then initializes rendering.

**Key logic:**
- Starts timer via FUN_00568be0(1)
- Calls FUN_0053d470 to test Direct3D device; if fails, returns 1
- Reads device name from player file (DAT_005ec488) via FUN_0053d890
- If no device configured, copies "No Device" string
- Compares device name from file with current device handle (DAT_005ec480)
- On match: calls render init chain (FUN_004f9160, FUN_004f91b0, FUN_004a1200, FUN_0053c680, FUN_005408f0, FUN_004f9420, FUN_004f9310)
- On mismatch: launches 3DCONFIG.EXE via CreateProcessA and returns 1

**Globals:** DAT_005ec488 (PlayerFile), DAT_005ec480, DAT_005ec48c, DAT_005ec4a4, DAT_005ec4b4, DAT_005ea438, DAT_007ce2dc, DAT_007ce2a0, DAT_008afe74

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_00568be0 (timer init), FUN_0053d470, FUN_0053d890, FUN_0053d8e0, FUN_004f9160, FUN_004f91b0, FUN_004a1200, FUN_0053c680, FUN_005408f0, FUN_004f9420, FUN_004f9310, FUN_004f9f00, FUN_005434a0, FUN_0055c060, FUN_004f9f30, FUN_00494690, FUN_00422be0, CreateProcessA (Win32)

**Moddability:** `hardcoded` — reads device config from player file

<!-- target: docs/01-engine-architecture.md -->

### FUN_004B4060 — Render::Restart

Render module restart. Fills render context structure with default values.

**Key logic:**
- Fills 0x68 bytes (26 ints) of param_1 with 0x01010101 (default initializer)
- No other operations — pure state reset

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log)

<!-- target: docs/01-engine-architecture.md -->

### FUN_004B40A0 — Render::ScreenSave

Saves screenshot to file. Checks input device state for screenshot key ('X' marker) and writes screen capture.

**Key logic:**
- Iterates DAT_007cb21c array (count in DAT_007cb218) looking for entries == 0x58 ('X')
- When found, saves screenshot via FUN_00551fd0 to path from DAT_005ec478 (or DAT_005ea438 fallback)
- Writes "Screen Saved" message to message buffer (DAT_005ec4cc) and displays via FUN_0045bd10
- Posts screen save via FUN_004fbd70 (buffer swap), FUN_004b3dc0 (render flush), FUN_00557120

**Globals:** DAT_007cb218, DAT_007cb21c, DAT_005ec478, DAT_005ea438, DAT_008b8dd4, DAT_008b8dd8, DAT_005ec4cc (MessageBuffer)

**Calls:** FUN_00551fd0, FUN_00423a00, FUN_0045bd10, FUN_004fbd70, FUN_004b3dc0, FUN_00557120

<!-- target: docs/01-engine-architecture.md -->

### FUN_0040C920 — CamMan::Init

Camera manager initialization. Sets up camera system with MAINVIEW camera handle.

**Key logic:**
- Gets "MAINVIEW" camera object via FUN_00544f50, stores in param_1
- Zeros camera globals DAT_005ea550/554/558/500/504/508
- Calls camera subsystem inits: FUN_0040c240, FUN_0040c3b0, FUN_0040c520
- Sets byte at param_1+0x2d to 0
- Calls FUN_0040c140; if returns 0, copies param_1[6] into param_1[2]
- Enables render culling via FUN_0054a200(0x20, 1)

**Globals:** DAT_005ea550, DAT_005ea554, DAT_005ea558, DAT_005ea500, DAT_005ea504, DAT_005ea508

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_00544f50, FUN_0040c240, FUN_0040c3b0, FUN_0040c520, FUN_0040c140, FUN_0054a200

<!-- target: docs/01-engine-architecture.md -->

### FUN_004B1870 — PlayerFile::Setup

Sets up player file subsystem. Initializes configuration file I/O.

**Key logic:**
- Calls FUN_004b0770(1) — if returns non-zero, returns true
- Otherwise calls FUN_004b0540(1) and returns its result

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log), FUN_004b0770, FUN_004b0540

<!-- target: docs/01-engine-architecture.md -->

### FUN_004B18D0 — PlayerFile::Restart

Empty stub for PlayerFile restart. Just logs "Entered PlayerFile::Restart()".

**Key logic:**
- Pure trace entry, no functional logic

**Calls:** FUN_004d7a50 (trace gate), FUN_004d7aa0 (trace log)

<!-- target: docs/08-file-formats.md -->

