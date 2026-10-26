# Cross-Validation Audit: Batch Math 1

Audit of 35 decompiled .c files. Each entry verified against source.

---

### FUN_00404460 — AudioPlaybackStateMachine

Source: audio/mixer.cpp. Three-phase audio playback state machine (init→play→stop). Computes mix position from globals, steps through buffer with phase-dependent callbacks.

**Key logic:**
- Computes `fVar2 = _DAT_0059e43c - (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450`
- State machine at param_1+0x16c: 0=init calls FUN_004fb260, 1=play calls FUN_004faf60, 2=stop calls FUN_004fb2e0
- Iterates param_1+0x174 from 0 to param_1+0x130 per phase

**Calls:** FUN_004fb260, FUN_004faf60, FUN_004fb2e0

---

### FUN_00466a30 — SomeObjectConstructor

Source: unknown.cpp. Constructor for object with vtable PTR_FUN_0059f380. Sets scale to 0.5 at offset 0x41*4 and stores param_2 at offset 0x42*4.

**Key logic:**
- Calls base constructor FUN_004668e0
- Initializes sub-object flag at offset 0x40 to 0
- Sets param_1[0x41] = 0x3f000000 (0.5f)

**Calls:** FUN_004668e0

---

### FUN_00486710 — GetFlagAtOffset100

Source: unknown.cpp. Getter returning byte at param_1 + 100 (0x64).

**Key logic:**
- Single read of byte field

**Calls:** none

---

### FUN_004a0010 — RegisterInitCallback

Source: init/shutdown.cpp. Registers callback DAT_004a0020 via FUN_00587b3e (atexit-like).

**Key logic:**
- Registers function pointer for cleanup

**Calls:** FUN_00587b3e

---

### FUN_004d4a20 — DelegateTo4D4A50

Source: unknown.cpp. Thin wrapper delegating to FUN_004d4a50.

**Key logic:**
- No additional logic

**Calls:** FUN_004d4a50

---

### FUN_00513c38 — MemoryCompare

Source: string/memory.cpp. Compares byte range against reference data at DAT_005af564. Returns -1/0/1 (memcmp semantics).

**Key logic:**
- Compares param_1 bytes starting at offset param_2 with reference at DAT_005af564
- Bound by param_3 (max 8) and offset param_2 (max 7)
- Standard three-way comparison result

**Calls:** none

---

### FUN_0054fcb0 — SetOffset80

Source: unknown.cpp. Setter writing param_2 to param_1 + 0x80.

**Key logic:**
- Single store at object offset 0x80

**Calls:** none

---

### FUN_00561acf — MemsetWords

Source: memory/utils.cpp. Fills array of int32 at `param_4 + param_1*4` with `param_3` for `param_2` iterations.

**Key logic:**
- Pointer arithmetic: base = param_4 + param_1 * 4
- Loop writes param_3 to consecutive 4-byte slots

**Calls:** none

---

### FUN_0040fb00 — ObjectInitZero

Source: unknown.cpp. Initializer for object — zeros 9 selected fields then calls FUN_0040fb30.

**Key logic:**
- Zeros at offsets: +8, +0x10, +0x18, +0x20, +0x28, +0x34, +0x40, +0x4c, +0x58, +0x64
- Offset pattern: staggered 8-byte spacing → array of structs or SIMD-aligned fields

**Calls:** FUN_0040fb30

---

### FUN_00471540 — SessionManagerConstructor

Source: session/manager.cpp. Constructor for session/game manager. Sets vtable PTR_FUN_005a0e40, configures replay and session parameters.

**Key logic:**
- Calls FUN_00466d60(1) (init with parameter)
- Sets param_1[0xcd] = 0xec (replay buffer size / config param)
- Registers two function pointers via FUN_00486f30 as -1 (unlimited/disabled)
- Sets param_1[199] = &DAT_007ce73c (global session pointer)
- Sets flags at 0xc9=2, 0xca=0, 0xcb=1, 0xcc=1

**Calls:** FUN_00466d60, FUN_00486f30 (×3), FUN_004670e0

---

### FUN_00497250 — SetByteAtOffset25

Source: unknown.cpp. Setter writing a byte to param_1 + 0x25.

**Key logic:**
- Single write of byte field

**Calls:** none

---

### FUN_004bb6b0 — LinkedListRemoveNode

Source: data_structures/linkedlist.cpp. Removes a node identified by `param_2` integer value from doubly-linked list. Returns 1 on success, 0 on failure.

**Key logic:**
- Walks list from *param_1, matching node data against param_2
- Updates head (*param_1), tail (param_1[1]), current (param_1[2])
- Decrements count at param_1[3]
- Optionally frees node data via FUN_00587bcf if param_3 flag set

**Calls:** FUN_00587bcf (×2)

---

### FUN_00500f55 — RecursiveTreeDestructor

Source: data_structures/tree.cpp. Recursive destructor for tree/nested structure. Frees child and sibling pointers.

**Key logic:**
- Frees sibling (param_1+4) and child (param_1+8) if their control flags (param_1+0x38, +0x3c) are set
- Recursively calls itself on child at param_1+0x4c and param_1+0x50
- Uses FUN_00587bcf as deallocator

**Calls:** FUN_00587bcf, FUN_00500f55 (recursive, ×2)

---

### FUN_0053c6b0 — StringCopy

Source: string/utils.cpp. Copies null-terminated string from param_2 to param_1. Stores length/refcount at *param_1.

**Key logic:**
- Copies string bytes after the 4-byte header
- If param_2 is NULL: sets empty string (0 at *param_1, 0 at param_1[1])
- Otherwise copies header *param_1 = *param_2 and string body

**Calls:** none

---

### FUN_00599475 — Gninc (MSVC streambuf get pointer increment)

Source: MSVC CRT (std::basic_streambuf::_Gninc). Library function — skippable.

**Key logic:**
- Decrements the get area count at `this+0x2c` pointer target
- Increments get pointer at `this+0x1c` and returns old value

**Calls:** none

---

### FUN_0045b3e0 — DestructorWithDealloc

Source: unknown.cpp. Destructor pattern: calls cleanup method then optionally frees memory.

**Key logic:**
- Calls FUN_0045b400 (cleanup)
- If param_2 & 1: calls FUN_00587bcf(param_1) to deallocate

**Calls:** FUN_0045b400, FUN_00587bcf (conditional)

---

### FUN_004b2a10 — BitfieldSetNibble

Source: flags/bitfield.cpp. XOR-modifies bits at offset 0x2c, setting/clearing nibble in byte 1 based on param_2.

**Key logic:**
- `param_1[0x2c] ^= ((byte)(param_2+1) << 8 ^ param_1[0x2c]) & 0xf00`
- Masks bits 8-11 (0xf00) and sets them to (param_2+1)<<8

**Calls:** none

---

### FUN_0053d450 — DelegateTo55C9C0

Source: unknown.cpp. Thin wrapper delegating to FUN_0055c9c0.

**Key logic:**
- No additional logic

**Calls:** FUN_0055c9c0

---

### FUN_0057bcc0 — DestructorWithDealloc

Source: unknown.cpp. Destructor pattern (same as 0x0045b3e0): calls cleanup then optionally frees.

**Key logic:**
- Calls FUN_0057bce0 (cleanup)
- If param_2 & 1: calls FUN_00587bcf(param_1)

**Calls:** FUN_0057bce0, FUN_00587bcf (conditional)

---

### FUN_0041fb10 — SessionTypeDetector

Source: session/detector.cpp. Checks all controllers for presence of both race-type (10) and qualifying-type (6) sessions. Returns 1 if both exist, 0 otherwise.

**Key logic:**
- Iterates controllers via FUN_004c2990, FUN_004c2850, FUN_004c1390, FUN_004c13a0
- Checks session type at offset +0xd4 + sessionIdx*4
- Flags: bVar1=true if type==10 (race), bVar2=true if type==6 (qualifying)
- Returns 1 only when both race and qual sessions exist (e.g., race weekend loaded)

**Calls:** FUN_004c2990, FUN_004c2850 (×5), FUN_004c1390 (×2), FUN_004c0a20 (×2), FUN_00566810 (×2), FUN_004c1370 (×2), FUN_004c13a0 (×3)

---

### FUN_00476d70 — VtableDispatchProcessor

Source: unknown.cpp. Generic processor with vtable dispatch. Checks global DAT_005eb10c for vtable call, processes object via FUN_0048f590/FUN_0041b980.

**Key logic:**
- If DAT_005eb10c non-null: calls via vtable offset 0xc (*DAT_005eb10c)
- Calls FUN_004186a0 after each dispatch
- Checks FUN_0048f590 return for valid object chain (offset 0x48 count, +0x3c pointer chain)
- Calls FUN_0041b980 on final target

**Calls:** FUN_004186a0 (×2), FUN_0048f590, FUN_0041b980

---

### FUN_004972b0 — RectangleBorderDraw

Source: renderer/2d_draw.cpp. Draws a rectangle border with two-color pattern (solid vs dithered) using random offset generation.

**Key logic:**
- Computes width = param_5-param_4, height = param_7-param_6
- Calls FUN_00495150 to randomize starting offset, FUN_00494bf0 to seed
- Draws 4 borders: top, right, bottom, left using FUN_00494c20
- Alternates color `uVar3` (param_2 masked) and `uVar2` (~param_2 masked) depending on edge
- Loop param_3 times for border thickness

**Calls:** FUN_00495150 (×5), FUN_00494bf0, FUN_00494c20 (×4)

---

### FUN_004bac40 — LinkedListSortedInsert

Source: data_structures/linkedlist.cpp. Inserts integer value into a sorted linked list. Creates primary nodes and parallel index nodes stepped by 0x1b0.

**Key logic:**
- Creates new list node via operator_new(0xc), stores param_2 value
- Appends to tail of primary list (param_1[0..3] = head/tail/current/count)
- Based on param_3 flag: creates secondary index nodes with values offset by 0x1b0
- Secondary list stored at param_1[4..7]

**Calls:** operator_new (×N)

---

### FUN_004f87c0 — EffectParameterSetter

Source: vehicle/effects.cpp. Sets effect/parameter for vehicle subsystem. Indexed by param_2, uses global multipliers `_DAT_007cf35c`/`_DAT_007cf338`.

**Key logic:**
- If `*(*param_1 + 13000) == 0`: uses `_DAT_007cf338`, increments param_3
- Otherwise uses `_DAT_007cf35c`
- Computes intensity = global * param_4, stored at param_1[param_2*8 + 0x2f]
- Sets param_5 at param_1[(param_2+6)*8]
- Clamps param_3 to [0,3] range for effect type at offset +0x2e
- Sets active flag at offset +0x2d

**Calls:** none (reads globals only)

---

### FUN_00543210 — ReorderedParamDelegate

Source: unknown.cpp. Delegates call with reordered parameters to FUN_005400c0.

**Key logic:**
- Calls FUN_005400c0(param_1, param_3, param_2) — swaps param_2 and param_3

**Calls:** FUN_005400c0

---

### FUN_0059ad31 — RegisterTeardownCallback

Source: init/shutdown.cpp. Registers FUN_0047aa60 as a teardown/cleanup callback.

**Key logic:**
- Calls FUN_00587b3e with function pointer (atexit pattern)

**Calls:** FUN_00587b3e

---

### FUN_0047ca30 — RandomDrivenProcess

Source: random/utils.cpp. Gets random float from FUN_004889d0 and passes to FUN_0047c960.

**Key logic:**
- FUN_004889d0 returns random float (0.0–1.0)
- Casts to float, passes to FUN_0047c960

**Calls:** FUN_004889d0, FUN_0047c960

---

### FUN_0045bea0 — AVICleanupDestructor

Source: video/avi.cpp. Destructor/cleanup for AVI playback object. Releases AVI stream, file, and buffer resources.

**Key logic:**
- Releases AVIStream at offsets +0x3c and +0x40
- Releases AVIFile at offset +0x38
- Frees buffer at +0x44 via FUN_0053cb90
- Frees buffer at +0x50 via FUN_00587bcf
- Calls FUN_0045bf10 and AVIFileExit

**Calls:** AVIStreamRelease (×2), AVIFileRelease, FUN_0053cb90, FUN_00587bcf, FUN_0045bf10, AVIFileExit

---

### FUN_00495970 — GetIntAtOffset24

Source: unknown.cpp. Getter returning int at param_1 + 0x18 (offset 24).

**Key logic:**
- Single read of int32 field

**Calls:** none

---

### FUN_004ba180 — MenuStateDispatch

Source: menu/state.cpp. State machine dispatcher for menu/UI flow. Checks primary state flag and delegates.

**Key logic:**
- Returns immediately if *param_1 != 2
- Calls FUN_004b9a00 to check sub-state
- If sub-state false: calls FUN_004b8bd0, branch on value 2 → FUN_004c8dc0(1.0f) + FUN_004b9e40, else → FUN_004b8c40 + FUN_004b9d20
- Always calls FUN_004b9d20 at end

**Calls:** FUN_004b9a00, FUN_004b8bd0, FUN_004b8c40, FUN_004b9d20 (×2), FUN_004c8dc0, FUN_004b9e40

---

### FUN_004f2b10 — ZeroInit16Words

Source: memory/utils.cpp. Zero-initializes 16 consecutive int32/float fields (64 bytes total).

**Key logic:**
- Stores 0 at param_1[0] through param_1[0xf]

**Calls:** none

---

### FUN_005265db — Matrix4x4MultiplySSE

Source: math/matrix4x4.cpp. Multiplies two 4x4 matrices using SSE packed floating-point operations. Uses PackedFloatingMUL/ADD for SIMD-style computation across all 4 columns.

**Key logic:**
- Processes 4 rows (param_2[0..3], [2..5], [4..7], [6..7]) each with 4 columns
- Each row: 4 FMAs: `col*row + col*row + col*row + col*row`
- Stores result as 8 packed doubles at param_1[0..7]

**Calls:** PackedFloatingMUL (×32), PackedFloatingADD (×16), FastExitMediaState

---

### FUN_0056c740 — Matrix3x3MultiplyDouble

Source: math/matrix3x3.cpp. Multiplies two 3x3 matrices of doubles. `param_3 = param_1 × param_2`.

**Key logic:**
- Computes 9 entries: each is sum of 3 products (row × column)
- param_3[0] = param_2[0]*param_1[0] + param_2[3]*param_1[1] + param_2[6]*param_1[2]
- Same pattern for all 9 elements

**Calls:** none

---

### FUN_0059d290 — UnwindHandler

Source: MSVC CRT exception handling. C++ unwind handler. Checks flag at EBP-0x10 and optionally calls FUN_00598aea.

**Key logic:**
- If `*(unaff_EBP - 0x10) & 1` is set: calls exception cleanup FUN_00598aea

**Calls:** FUN_00598aea (conditional)

---

### FUN_0045d4c0 — TwoCharStringCheck

Source: string/utils.cpp. Checks if first two characters of string are non-null; if so, delegates to FUN_00561f40.

**Key logic:**
- Guards: `*param_1 != '\0' && param_1[1] != '\0'`
- On success: calls FUN_00561f40

**Calls:** FUN_00561f40 (conditional)
