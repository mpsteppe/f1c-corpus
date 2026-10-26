# Batch Math 2 — Cross-Validate Entries

## FUN_004861a0 — ConditionalArrayOps
Source: game_logic. Dispatches array init/copy ops based on two flag params.
- Checks `param_1` low byte for non-zero → calls FUN_00499ee0/FUN_0049aa70 (array size+write)
- Checks `param_2` low byte for non-zero → calls FUN_00499f00/FUN_0049aa10 (array fill with 4 args)
- Both branches independent, can execute both
Calls: FUN_00499ee0, FUN_0049aa70, FUN_00499f00, FUN_0049aa10

## FUN_0049d3f0 — ColorSelectRender
Source: renderer. Selects color palette based on global flag and renders with offset.
- Branches on `DAT_007d0474` — chooses FUN_0049b950 or FUN_0049b900 for base color
- Calls FUN_0058815f to build string buffer from global `DAT_005ccec8` + color
- Calls FUN_00553070 with position (4) and ID (0x2b) with param_1 offset 0x54
Calls: FUN_0049b950, FUN_0049b900, FUN_0058815f, FUN_00553070

## FUN_004ce820 — StructInit_15elems
Source: renderer. Initializes 15-element float/uint struct with defaults (identity transform).
- Zeroes indices [0..10] (11 ints)
- Sets [0xb]=0, [0xc]=0x3f800000 (1.0f), [0xd]=0x3f4ccccd (~0.8f), [0xe]=0xffffffff (-1)
Calls: none

## FUN_0051ea5a — FillFromVtable
Source: unknown. Iterates array calling vtable method per element.
- Loops from 0 to `*(unaff_ESI+100)` (count)
- Extracts ptr at `unaff_ESI+0x1a4`, offset 0x44 per element
- Calls vtable method (offset 4) from `*(unaff_ESI+4)` to produce each value
Calls: (code*)(vtable+4) (indirect)

## FUN_005997cb — Wrapper_00599958
Source: unknown. Thin wrapper.
- Calls FUN_00599958 then returns
Calls: FUN_00599958

## Unwind_0059d4d8 — UnwindHandler
Source: exception. MSVC unwind trampoline.
- Calls FUN_0059a5e9 then returns
Calls: FUN_0059a5e9

## FUN_00457cd0 — ZeroInit_7elems
Source: unknown. Zero-init 7-element struct (6 ints + 1 byte).
- Sets indices [0..6] to 0
- Indices [5] and [6] via pointer arithmetic on param_1+7 as byte
Calls: none

## FUN_0047b1b0 — ObjectResetAndCall
Source: game_logic. Resets state field then calls vtable methods.
- Sets `param_1[0x41] = 0` (state reset)
- Calls vtable[0x40](0), vtable[0x2c](1), vtable[0x9c]() sequentially (indirect jump treated as call)
Calls: (code**)vtable indirect (offsets 0x40, 0x2c, 0x9c)

## FUN_00499da0 — RecursiveTreeDelete
Source: game_logic. Recursively frees a binary tree node structure.
- If param_2 is null, defaults to `param_1+8` as list head
- Follows pointer chain: recursively frees left (offset 0x28) and right (offset 0x24) subtrees
- Calls FUN_00499b50 (tree op) and FUN_00587bcf (free) on current node
- Nulls out the head pointer and counter at param_1+0xc
Calls: FUN_00499da0 (recursive), FUN_00499b50, FUN_00587bcf

## FUN_004c2c40 — ExponentialMovingAverage
Source: physics_math. Exponentially weighted running average with clamp bounds.
- Reads `param_1[0x28]` as sample count N. If N==0: no-op. If N==1: stores raw value
- Running avg = `((N-1)*prev + newVal) / N`
- Clamps result: if <= `_DAT_0059e43c` → sets to 1.0f (0x3f800000); if >= `_DAT_0059e85c` → caps at 22.0f (0x41b00000)
Calls: none

## FUN_00501992 — DXTTextureDecompress
Source: renderer. Decompresses DXT1/3/5 compressed texture data into ARGB output buffer.
- Validates DDS header (param_2): checks fourCC, format byte at offset 7, bit depth at 0x10
- Determines pixel format: 16-bit (0x14), 32-bit (0x15), RGB565 (0x18), ARGB1555 (0x19), 8-bit (0x29), 32-bit A8R8G8B8 (0x32)
- Allocates 0x400-byte color table for DXT1 mode; handles alpha decompression (DXT3/DXT5)
- Supports vertical/horizontal flip flags (0x10/0x20) and alpha premultiplied flag (0x08)
- Returns 0 on success, HRESULT error codes on failure
Calls: operator_new, (no other direct calls — inline decompression math)

## FUN_0053bde0 — Dot4Scaled
Source: physics_math. 4-element dot product with global scale factor.
- Computes `DAT_0059e440 * param_2[0] + param_1[2]*param_2[1] + param_1[1]*param_2[2] + param_1[0]*param_2[3]`
Calls: none

## FUN_0058a65f — ConditionalDelegate
Source: unknown. Delegates to FUN_0058a677 if local flag is zero.
- Checks `*(unaff_EBP - 0x1c)` (local flag) — if zero, calls FUN_0058a677 with 4 args from stack
Calls: FUN_0058a677

## FUN_0059b5c0 — BitArrayAlloc
Source: renderer. Allocates run in a packed bit array; records offset and length.
- Calls FUN_0059b490 and FUN_0059b530 (setup/validation)
- Writes short pair at `param_1[2] + param_1[5]*4`: [start, length]
- Clears bits in raw bit array at `*param_1` for the allocated range
- Increments allocation counter at param_1[5]; returns 0x100-encoded result
Calls: FUN_0059b490, FUN_0059b530

## FUN_004bbf70 — RingBufferShift
Source: game_logic. Removes front element from ring buffer; checks if empty.
- Decrements count at `param_1+0x3c`; shifts remaining entries down by 2-index slots (offset 0x40+)
- If count drops below 1, calls FUN_004a5660(0) else calls FUN_004a5660(1)
Calls: FUN_004a5660

## FUN_00567940 — FreeTwoPtrs
Source: unknown. Frees two heap-allocated pointers if non-null.
- Checks `param_1+0x18` → FUN_00587bcf to free
- Checks `param_1+0x10` → FUN_00587bcf to free
Calls: FUN_00587bcf (×2)

## FUN_00410af0 — RemoveSwapArray
Source: math_util. Removes element from indexed array using swap-with-last pattern.
- Reads ref count at `*param_1`, decrements it
- Copies last element to removed slot: `param_1[2][iVar2*4] = param_1[2][(count-1)*4]`
- Updates back-reference: `**(param_1[2][iVar2*4]) = iVar2`
- Sets removed element index to -1
Calls: none

## FUN_0046ff40 — Destructor_VtableFree
Source: renderer. Object destructor: resets vtable, frees child pointer, optional self-free.
- Sets vtable pointer to `PTR_FUN_005a01a0`
- Frees `param_1[0x3b]` via FUN_00587bcf if non-null
- Calls FUN_0048feb0 (subsystem shutdown)
- If `(param_2 & 1)`: frees own allocation via FUN_00587bcf
Calls: FUN_00587bcf, FUN_0048feb0

## FUN_00491680 — RectIntersectClamp
Source: game_logic. Tests if a rectangle intersection region has positive area.
- Clamps X range: takes max of `*param_1` vs `param_2`; min of `param_1[2]+*param_1` vs `param_4+param_2`
- Clamps Y range: takes max of `param_1[1]` vs `param_3`; min of `param_1[3]+param_1[1]` vs `param_5+param_3`
- Returns 1 if both clamped ranges are non-empty, 0 otherwise
Calls: none

## FUN_004b3db0 — IdentityPassthrough
Source: unknown. Identity function — returns input unchanged.
- Returns `param_1` directly
Calls: none

## FUN_004dd4c0 — FreeSinglePtr
Source: unknown. Frees one heap pointer if non-null.
- Checks `param_1+8` → FUN_00587bcf to free
Calls: FUN_00587bcf

## FUN_005179a2 — CallbackInvoker
Source: game_logic. Invokes a completion callback then cleans up.
- Validates non-null chain: `param_1`, `param_1[0x1c]`, `param_1[0x24]`
- Calls FUN_00527eed on `param_1[0x1c]` offset 0x14 (notify)
- Calls function pointer at `param_1[0x24]` with args `param_1[0x28]` and `param_1[0x1c]`
- Nulls out `param_1[0x1c]`, returns 0 or -2 on failure
Calls: FUN_00527eed, (code*)(param_1+0x24) indirect

## FUN_0055c2a0 — ListAppend
Source: game_logic. Appends node to singly linked list stored at `param_1+0x1518`.
- Walks to tail by following `param_1[0x20]` chain from offset 0x1518
- Links new node: sets new node's prev at `param_2+0x1c` to tail, tail's next `iVar1+0x20` to new node
- If list empty (param_1+0x1518==0), sets head directly
Calls: none

## FUN_0058bef0 — CharPosRender
Source: renderer. Renders character at computed screen position.
- Calls FUN_00595621 to parse first param (double) into `local_14` (neg flag) and `local_2c` (char array)
- Calls FUN_005955aa with X-offset (adjusted for negative sign) and Y-offset
- Calls FUN_0058bf45 to render at position with local_14 as flag
Calls: FUN_00595621, FUN_005955aa, FUN_0058bf45

## FUN_0059525d — BitArrayClearAndQuery
Source: math_util. Clears a bit in a 3-element (96-bit) array; returns previous value if it was the last set.
- Computes word index (param_2/0x20) and bit position (0x1f - param_2%0x20)
- If bit was set AND FUN_005951be says no subsequent bits set → calls FUN_00595207 for prev-run query
- Clears the bit: `*puVar1 &= ~(1 << bVar3)`
- Zeroes remaining words after current index
Calls: FUN_005951be, FUN_00595207

## FUN_005179e0 — AllocatorSetup
Source: game_logic. Configures a memory allocator with chunk size and flags.
- Validates: param_3 must be "1" string, param_4 must be 0x38 (56 bytes)
- Sets default alloc/free callbacks if null: FUN_0052803a (alloc), FUN_00519351 (free)
- Calls allocator callback for 0x18 (24-byte) block
- Validates chunk size range: 8 < param_2 < 16 bits (256-32767)
- Sets up allocation with FUN_005276c5, returns error codes on failure
Calls: FUN_0052803a (via callback), FUN_005276c5, FUN_005179a2, FUN_00519351 (via callback)

## FUN_004f8c00 — AuthCheck
Source: network. Game copy-protection/DRM check via function pointer.
- If `DAT_008afc8c` is null → returns 4 (no check)
- Calls `DAT_008afc8c(param_1, param_2, param_3)`; returns 0 on 1 (pass), 7 on 2/3 (blocked), 6 otherwise
Calls: (code*)DAT_008afc8c indirect

## FUN_004b5040 — BufferInit
Source: renderer. Initializes a character/text buffer with size limits.
- Sets first byte to 1, copies 1 byte from param_2, null-terminates at param_2+1+param_1
- Sets memset-style: 0x20 (space) at offset 0x41, 0x20 at 0x61, 4 at 0x84, 4 at 0x88
- Returns 1
Calls: FUN_00566c00 (×5, memset-like)

## FUN_004988d0 — FindAndDelete
Source: game_logic. Looks up object by name from registry, calls lifecycle hooks, frees.
- Searches via FUN_00497750(param_2) — hash/name-based lookup
- If found: calls vtable[0x8c] (pre-delete), FUN_004979c0 (unlink), FUN_00553050 (free resources), vtable[0x90] (post-delete)
- Requires `*(param_1+0x18)`→offset 0x50 flag to be non-zero
Calls: FUN_00497750, FUN_004979c0, FUN_00553050, (code**)vtable indirect (offsets 0x8c, 0x90)

## FUN_00478690 — ConditionalVtableCall
Source: renderer. Returns pointer or null based on flag; calls vtable method with 1/0.
- If `param_1[0x4e]` non-zero: calls vtable[0x3c](1), returns `param_1+0x46`
- Else: calls vtable[0x3c](0), returns null
Calls: (code*)vtable[0x3c] indirect

## FUN_00421a90 — DoubleDelegate
Source: unknown. Calls two functions on same argument.
- Calls FUN_00421890(param_1)
- Calls FUN_00566650(param_1)
Calls: FUN_00421890, FUN_00566650

## FUN_004d5c50 — StaticInit_4d5c60
Source: unknown. Static initializer, registers LAB_004d5c60.
- Calls FUN_00587b3e with address of LAB_004d5c60
Calls: FUN_00587b3e

## FUN_0050f6f7 — StateMachineRender
Source: renderer. State machine dispatching render setup with validation.
- `unaff_ESI[8]` is state selector (1, 3, 4 default)
- State 1: sets flags [9]=[10]=1, jumps to cleanup
- State 3: checks `[0x40]` and `[0x106]` flags; validates RGB values ([0x31]→[0],[0x15],[0x2a]); dispatches error codes 0x6b/0x6e on mismatch
- State 4: checks `[0x106]` flag, error code 0x6e for invalid [0x107], states 4/5
- Cleanup block sets 14 fields: flags [9]..[0x15] including scale 0x3ff00000 (~1.0) and max 0x100
Calls: (code*)vtable[4] indirect

## FUN_005491d0 — LinkedAllocNode
Source: unknown. Allocates new node in linked list; appends to tail.
- If `param_1+0xf0` is null: allocates 0x38-byte block, calls FUN_0055d200 to init, stores at [0xf0]
- Else walks to tail via `[0x34]` chain; allocates 0x38-byte block at tail's `[0x34]`
- Zero-checks allocation, stores null on failure
Calls: operator_new, FUN_0055d200

## FUN_0059163b — ConditionalMathDispatch
Source: math_util. Dispatches to float math function or error handler based on global flag.
- If `DAT_005e9ad0 == 0`: calls FUN_00591bf1(1, param_1, param_2, 0, param_2, param_3) — normal math path
- Else: calls FUN_0058afcf for error context, sets `*puVar1 = 0x21` (error code), calls FUN_00591e66 (error handler), returns param_2 unchanged
Calls: FUN_00591bf1, FUN_0058afcf, FUN_00591e66

## Gninc @ 0059a418 — Streambuf_Gninc
Source: MSVC CRT. `std::basic_streambuf::_Gninc()` — advances get pointer in wchar_t stream buffer.
- Decrements `**(param_1+0x2c)` (eback ptr)
- Increments `**(param_1+0x1c)` (gptr) by 2 (wchar_t advance)
Calls: none

## FUN_00410b60 — Wrapper_0040ed10
Source: unknown. Thin wrapper.
- Calls FUN_0040ed10
Calls: FUN_0040ed10

## FUN_00471b20 — Constructor_InitDefaults
Source: renderer. Constructor: sets vtable, inits render state defaults.
- Calls FUN_00466d60(1) (global state setup)
- Sets vtable to `PTR_FUN_005a1680`
- Sets 6 config fields: `[199]`=DAT_007ce6f4, `[0xc9]`=2, `[0xca]`=0, `[0xcb]`=1, `[0xcc]`=1, `[0xcd]`=0xf7
- Calls FUN_00486f30 to init 3 globals with -1 (PTR_DAT_005be704, PTR_DAT_005c32a4, DAT_005c32a8)
- Calls FUN_004670e0 (post-init)
Calls: FUN_00466d60, FUN_00486f30 (×3), FUN_004670e0

## FUN_00491ee0 — AudioDeviceInit
Source: audio. Initializes audio device/playback handle.
- Calls FUN_00534b00() (device query), stores at `*param_1`
- If flag at `param_1+0x19a` set: calls FUN_00587db0 (create handle from DAT_005c302c), stores at `param_1[1]`
- If handle null: clears flag at 0x19a
- If `*param_1` non-null: calls FUN_00535390(0) (start playback)
- If flag set: calls FUN_00587f64(param_1[1], 0, 0) (buffer setup)
Calls: FUN_00534b00, FUN_00587db0, FUN_00535390, FUN_00587f64

## FUN_004b52a0 — BucketListRehash
Source: game_logic. Rehashes linked bucket list; removes dup entries and re-inserts.
- Stores `DAT_005acd24` to `param_1+0x30` (hash multiplier)
- Walks list at `param_1+0x20`: removes nodes matching current key (`iVar1`) by unlinking from chain
- If node's `[2]` flag set: calls FUN_004b0170 (hash op) and FUN_00587bcf (free key)
- Allocates new 0xc-byte node, inserts at head of list at `param_1+0x10`
- Loops indefinitely until list empty
Calls: operator_new, FUN_004b0170, FUN_00587bcf

## FUN_004e0d70 — ConditionalRelease
Source: unknown. Releases resource if active flag is set.
- Checks `*param_1` non-null AND `param_1[0x10]` flag set
- Calls FUN_0054baa0(*param_1) (release), clears flag at [0x10], calls FUN_0054c030(1,1,1,0) (notify)
Calls: FUN_0054baa0, FUN_0054c030

## FUN_0051ad93 — AudioChannelValidate
Source: audio. Validates audio channel state; dispatches errors on out-of-range indices.
- Checks `param_1[0x5a..0x5d]` 4 flags — if any non-default, dispatches error 0x76 via vtable[4]
- Iterates `param_1[0x48]` channels: validates `[offset+0x14]` (channel idx, must be 0-3) and `[offset+0x18]` (subchannel idx, also 0-3)
- On invalid idx: dispatches error 0x31 via vtable with the bad value at [0x18]
- Calls FUN_0051a5ea to process each channel pair; stores results; zeroes accumulated state
Calls: (code**)vtable indirect (offsets 4, 0), FUN_0051a5ea

## FUN_005676c0 — FloatFloorSplit
Source: math_util. Splits float into integer floor part and fractional remainder.
- Calls `__ftol()` (float-to-long truncation)
- Stores integer part to `*param_1`
- Computes remainder: `param_3 - (float)intPart * _DAT_0059f118`
Calls: __ftol (intrinsic)

## _malloc @ 0058a935 — MSVC_malloc
Source: MSVC CRT. Standard malloc implementation.
- Calls `__nh_malloc(_Size, DAT_008d41b0)` (heap handle)
Calls: __nh_malloc

## FUN_0041ed20 — FieldGetter_Indexed
Source: unknown. Returns indexed value from struct field array.
- Returns `*(param_1 + 0xd8 + param_2 * 4)` if param_1 non-null, else 0
Calls: none

## FUN_00475570 — ConditionalSystemUpdate
Source: game_logic. Runs system update; conditionally calls secondary init.
- Calls FUN_00461f70 (main update)
- Checks return of FUN_00462140 (condition query) — if true, calls FUN_00475150 (secondary init)
- Returns 0
Calls: FUN_00461f70, FUN_00462140, FUN_00475150

## FUN_004963c0 — FlagSetter_28
Source: unknown. Sets a single flag to 1.
- Sets `*(param_1 + 0x28) = 1`
- Returns 0
Calls: none

## FUN_004ba820 — ZeroInit_4elems
Source: unknown. Zero-initializes 4-element struct.
- Sets param_1[0..3] = 0
Calls: none

## FUN_004f6b80 — StaticInit_4f6b90
Source: unknown. Static initializer, registers LAB_004f6b90.
- Calls FUN_00587b3e with address of LAB_004f6b90
Calls: FUN_00587b3e

## FUN_0052803a — AllocDelegate
Source: unknown. Allocator delegate calling through to memory function.
- Calls FUN_0058ab58(param_2, param_3) — actual allocation
Calls: FUN_0058ab58

## FUN_0057a160 — Constructor_VtableSet
Source: unknown. Constructor: sets vtable pointer and calls init.
- Sets `*param_1 = &PTR_LAB_005b8a00`
- Calls FUN_0057a1e0 (initialization)
Calls: FUN_0057a1e0

## FUN_005830c0 — AllocWithException
Source: renderer. Allocates 0x207c-byte block with SEH exception handling.
- Sets up SEH frame (ExceptionList)
- Calls `operator_new(0x207c)` — if succeeds: sets `*puVar1 = 2`, calls FUN_0058a6eb(..., FUN_00582110, FUN_0047aa60)
- Stores result pointer at `*param_1` (+1 offset), returns param_1
- On null: stores 0 at `*param_1`
Calls: operator_new, FUN_0058a6eb

## FUN_00423060 — FieldGetter_c4
Source: unknown. Simple field accessor.
- Returns `*(param_1 + 0xc4)`
Calls: none

## FUN_00479320 — OverlapDetect
Source: game_logic. Spatial overlap detection — tests cursor against object rectangles.
- Gets cursor position via FUN_00498880(local_4, local_8)
- Walks linked list at `param_1+0x164` checking each node's XY + offset[0xc] and offset[4]
- Tests if cursor within rectangle: `local_4` in [x-0x14, x+0x14] and `local_8` in [y-0x14, y+0x14]
- On match: walks back to find node index, stores at `param_1+0x158`, returns
Calls: FUN_00498880

## FUN_00498d70 — Destructor_CondFree
Source: unknown. Destructor: calls cleanup; optionally frees self.
- Calls FUN_00498d90 (subsystem cleanup)
- If `(param_2 & 1)` non-zero: calls FUN_00587bcf(param_1) to free
- Returns param_1
Calls: FUN_00498d90, FUN_00587bcf

