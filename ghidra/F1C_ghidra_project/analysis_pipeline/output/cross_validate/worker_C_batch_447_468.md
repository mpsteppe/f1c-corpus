# Cross-Validation Results: Batch 447-468
# Target: docs/19-renderer.md
# Generated: 2026-07-15

---

## FUN_004CC970 — FAIL
Source: docs/19-renderer.md (line 263)
**Errors:**
- [INACCURATE_FORMULA] Doc claims count formula: `param_1[0x58] * spread * sqrt(param_3) >> param_1[2]`. Source formula: `param_1[0x58] * fVar10 * SQRT(param_3) * _DAT_005aceb4 >> (param_1[2] & 0x1f)`. Missing `_DAT_005aceb4` multiplier and `& 0x1f` mask. "spread" is inaccurate label for fVar10 (which comes from FUN_004b9ce0/DAT_008afe98 conditional chain).
- [MISSING_CALL] Missing `FUN_004b9cf0` from Calls list (called when DAT_008ab6e4==2 and FUN_004b9e30() result != 5).
- [MISSING_GLOBAL] Missing globals: `_DAT_0059e8cc`, `_DAT_005aceb4`, `DAT_008acaa0`, `DAT_008acaa4`, `DAT_008ac82c`, `DAT_008ac830`, `DAT_008ac83c`, `_DAT_0059e4dc`, `DAT_008afea0`, `DAT_008afe98`, `DAT_0059e440`, `DAT_0059e8cc`.
- [MISSING_CODE_PATH] Doc says "Branches on DAT_008ab6e4 (ScoringGate == 2): uses FUN_004b9ce0 for spread". Source branches twice: first for fVar9 (FUN_004b9ce0 vs DAT_008afea0), then for fVar10 (FUN_004b9e30 chain with FUN_004b9cf0 vs DAT_008afe98). The second branch is undocumented.
- [MISSING_CALL] Missing `FUN_004b9e30` path detail: when DAT_008ab6e4==2, calls FUN_004b9e30(); if result==5 uses DAT_0059e440, else FUN_004b9cf0().

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004cc970 — ParticleSpawnerBurst

Source: renderer/particle. Spawns burst of particles around a point.

**Key logic:**
- Returns if object count (param_1[0x58]) <= 0
- Draws 2 random values from ring buffer (DAT_008aae70/DAT_008ab274) for position jitter (x, z)
- First branch on DAT_008ab6e4 (ScoringGate):
  - == 2: fVar9 = FUN_004b9ce0() for spread, FUN_004b9e30() check:
    - If FUN_004b9e30() == 5: uses DAT_0059e440
    - Else: fVar10 = FUN_004b9cf0()
  - != 2: fVar9 = DAT_008afea0, fVar10 = DAT_008afe98
- Calls FUN_004cc840 for particle setup
- Computes count: ROUND(param_1[0x58] * fVar10 * SQRT(param_3) * _DAT_005aceb4) >> (param_1[2] & 0x1f)
- Loops for each particle:
  - Allocates via FUN_004cb540
  - Sets position from emitter center + circular offset via DAT_008acaa0/DAT_008acaa4 table (indexed by DAT_008acedc)
  - Sets color from texture array (DAT_008ac82c) by particle type index iVar3
  - Calls FUN_004cc700 for orientation with DAT_008ac830/DAT_008ac83c data
  - Computes size scaled by fVar4 (SQRT(param_3) * _DAT_0059e8cc)

**Globals:** DAT_008aae70, DAT_008ab274, DAT_008ab6e4 (ScoringGate), DAT_008acedc, DAT_008afea0, DAT_008afe98, DAT_0059e440, DAT_0059e8cc, DAT_005aceb4, DAT_008acaa0, DAT_008acaa4, DAT_008ac82c, DAT_008ac830, DAT_008ac83c, DAT_0059e4dc

**Calls:** FUN_004b9ce0, FUN_004b9e30, FUN_004b9cf0, FUN_004cc840, FUN_004cb540, FUN_004cc700

**Moddability:** particle count, spread radius, color table

---

## FUN_0044F540 — FAIL
Source: docs/19-renderer.md (line 579)
**Errors:**
- [MISSING_DETAIL] Doc says "Returns success flag". Source returns `(uint)pvVar2 & 0xffffff00` — returns handle masked to non-zero on success, 0 on failure. Not a simple boolean success flag.
- [INACCURATE_MEMSET] Doc doesn't describe the 64-byte local buffer zero-fill before path construction (lines 16-22).
- [WRONG_TYPE] Doc says param_2 is "name". Source: param_2 is `undefined4` — it's a string pointer (passed to FUN_0058815f as format arg). OK, this is correct actually.
- [MISSING_GLOBAL] Missing `DAT_005ea438` from Globals (used as empty-string default for path prefix).
- [MISSING_CONSTANT] Missing `0x10` flag (LR_DEFAULTCOLOR | LR_DEFAULTSIZE) on LoadImageA call.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0044f540 — Bitmap/Load Image Loader

Source: render_image.cpp. Loads a bitmap image using Windows LoadImageA.

**Key logic:**
- Copies DAT_005ea438 (empty string) into local buffer
- Zero-fills 64 bytes of buffer (0x3f iterations)
- Selects path prefix: DAT_005ec408 if non-null, else &DAT_005ea438
- Formats full path: FUN_0058815f(buffer, DAT_005be860, prefix, param_2)
- Calls LoadImageA(0, buffer, type=2 (bitmap), 0, 0, flags=0x10)
- On success: stores handle at param_1+0x30 + index*0x14 (stride 0x14 slot array)
- Increments +0xa8 counter
- Returns handle & 0xffffff00 (non-zero = success)

**Globals:** DAT_005ec408, DAT_005be860, DAT_005ea438

**Calls:** FUN_0058815f, LoadImageA (Win32 API)

**Moddability:** hardcoded

---

## FUN_00489600 — PASS
Source: docs/19-renderer.md (line 721)

**Verification:**
- Size 0xe8 bytes: confirmed `operator_new(0xe8)` line 14
- Stores name from param_2: confirmed `FUN_00566650(param_2)` line 21 (string copy to internal struct)
- Strings from param_3/4/5: confirmed FUN_00566650 calls lines 26-31
- Calls FUN_00486340 and FUN_00489480: confirmed lines 33-34
- Vtable callbacks: confirmed `(**(code **)(*param_1 + 0x2c))(1)` and `(**(code **)(*param_1 + 0xac))(param_2)` lines 35-36
- Calls FUN_00488f90: confirmed line 19 (uVar2 = FUN_00488f90())
- Calls operator_new: confirmed line 14
- Calls FUN_00566650: confirmed lines 21, 26, 28, 30

All claims verified correct. No errors found.

---

## FUN_0048E4B0 — FAIL
Source: docs/19-renderer.md (line 863)
**Errors:**
- [WRONG_CALLING_CONVENTION] Doc uses `__thiscall` implicitly. Source signature is `__fastcall`.
- [MISSING_GLOBALS] Doc lists no globals. Source uses `DAT_005ea438` (empty string default twice, lines 19 and 23).
- [MISSING_CALLS] Doc calls list: FUN_00588410, FUN_00495150, FUN_00551cf0. Missing: FUN_00490920, FUN_004918d0, FUN_00566650 (indirect via vtable calls at +0x2c, +0x10, +0xa0).
- [INCOMPLETE_LOGIC] Doc says "Compares texts, dispatches to vtable+0xa0 or handles text field selection". Source shows:
  - First compares two strings at param_1[0x2c] and param_1[0x3f] via FUN_00588410
  - If match: dispatches to vtable+0xa0
  - If no match but param_1[0x39] non-zero and param_1[0x3e] non-zero: calls FUN_00495150/FUN_00551cf0 for text field selection, then clears +0x3e, calls FUN_00490920/FUN_004918d0, dispatches vtable+0x2c and vtable+0x10
- [MISSING_CALL] FUN_00566650 not called — retracted. Actually FUN_00566650 is NOT in source. But vtable dispatches at +0x2c, +0x10, +0xa0 are present.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0048e4b0 — UI Action/Event Handler

Source: ui_action.cpp. Handles UI action events with two dispatch paths.

**Key logic:**
- Reads two strings from param_1: +0x2c (default DAT_005ea438) and +0x3f (default DAT_005ea438)
- Compares via FUN_00588410
- If strings match: dispatches to vtable+0xa0, returns 0
- If no match and param_1[0x39] != 0 and param_1[0x3e] != 0:
  - Gets values at param_1[0x3a]..[0x3d]
  - Calls FUN_00495150(iVar6, iVar2, 0x20) for text field selection
  - Calls FUN_00551cf0() to process selection
  - If result == 1: clears param_1[0x3e], calls FUN_00490920 + FUN_004918d0
  - Dispatches vtable+0x2c(1) and vtable+0x10(param_1[0x3b], [0x3d], [0x3a], [0x3c])
- Returns 0

**Globals:** DAT_005ea438 (empty string default)

**Calls:** FUN_00588410, FUN_00495150, FUN_00551cf0, FUN_00490920, FUN_004918d0

**Moddability:** hardcoded

---

## FUN_004DCF80 — FAIL
Source: docs/19-renderer.md (line 1017)
**Errors:**
- [WRONG_NUM_PARAMS] Doc calls param_1 the this pointer. Source: `__fastcall` with int param_1. The signature is `__fastcall`, not `__thiscall`.
- [MISSING_CALL] Doc calls list: FUN_00566650, FUN_004dcb70. Source: `FUN_00566650(&DAT_005ea438)` is actually the FIRST call (line 8). It then sets +0x30 and +0x34 to 1.0f, then calls FUN_004dcb70. Doc description missing the FUN_00566650 call purpose (copies empty string to param_1).
- [MISSING_GLOBAL] Missing `DAT_005ea438` from globals.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004dcf80 — Render State Init

Source: render_state.cpp. Initializes render state with default values.

**Key logic:**
- Calls FUN_00566650(&DAT_005ea438) — copies empty string to param_1+0
- Sets +0x30 and +0x34 to 1.0f (0x3f800000)
- Calls FUN_004dcb70 for further initialization

**Globals:** DAT_005ea438

**Calls:** FUN_00566650, FUN_004dcb70

**Moddability:** hardcoded

---

## FUN_00560340 — FAIL
Source: docs/19-renderer.md (line 1827)
**Errors:**
- [STUB_ONLY] Entry is a stub with signature + one-line analysis. Does not meet full entry standard.
- [MISSING_LOGIC] Analysis says "allocates 3 vertex/index buffers". Source shows 3 virtual dispatch calls at vtable+300 with shader/data pairs at DAT_005dc7a4/DAT_005dc7b8, DAT_005dd1e0/DAT_005dd1f8, DAT_005dc628/DAT_005dc640. Plus one enable call at vtable+200(0x99, 1).
- [MISSING_RETURN_PATHS] Analysis doesn't describe error checking: each alloc returns error code, function returns 0xffffffff on failure.
- [MISSING_ELSE_BRANCH] Source: if param_1[0x4f5] == 0: sets DAT_008cef7c=0, DAT_008cef74=0, DAT_008cef78=0x144, returns 0. This branch is undocumented.
- [NO_STRUCT_OFFSETS] param_1[0x4f5] = 0x4f5*4 = 0x13d4 flag check. param_1[0x440] = 0x1100 pointer to render device. These offsets not documented.
- [MISSING_GLOBALS] Missing globals: DAT_008cef7c, DAT_008cef74, DAT_008cef78, DAT_005dc7a4, DAT_005dc7b8, DAT_005dd1e0, DAT_005dd1f8, DAT_005dc628, DAT_005dc640.
- [NO_MODDABILITY] Missing moddability classification.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00560340 — Render State Buffer Allocation

Source: render_state.cpp. Allocates 3 vertex/index buffers for render state, or resets state if disabled.

**Key logic:**
- If param_1[0x4f5] (flag at +0x13d4) == 0:
  - Sets DAT_008cef7c = 0, DAT_008cef74 = 0, DAT_008cef78 = 0x144 (324)
  - Returns 0
- Else: allocates 3 buffers via virtual dispatch at param_1[0x440]+300:
  - Buffer 1: DAT_005dc7a4/DAT_005dc7b8 → DAT_008cef7c, stride 0x10
  - Buffer 2: DAT_005dd1e0/DAT_005dd1f8 → DAT_008cef74, stride 0x10
  - Buffer 3: DAT_005dc628/DAT_005dc640 → DAT_008cef78, stride 0x10
- Each allocation: writes result to *param_1, returns 0xffffffff on error
- Enables via vtable+200(0x99, 1)
- Returns 0 on success

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x13d4 (0x4f5*4) | EnableFlag |
| +0x1100 (0x440*4) | RenderDevicePtr |

**Globals:** DAT_008cef7c, DAT_008cef74, DAT_008cef78, DAT_005dc7a4, DAT_005dc7b8, DAT_005dd1e0, DAT_005dd1f8, DAT_005dc628, DAT_005dc640

**Calls:** virtual dispatch at vtable+300, vtable+200

**Moddability:** hardcoded

---

## FUN_004DAEA0 — FAIL
Source: docs/19-renderer.md (line 1017 — NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_004DAEA0` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004daea0 — Render/Graph Object Factory (Switch on Type)

Source: renderer/object_factory. Creates rendering graph objects by type ID (switch dispatch).

**Key logic:**
- Switch on param_1 (type ID):
  - case 0: alloc 0x18 bytes, vtable PTR_LAB_005ad050, fields[1]=2, [+2]=1, [+3]=0
  - case 1: alloc 0x14 bytes, vtable PTR_LAB_005ad034, fields[1]=1, [+2]=1, [+3]=0
  - case 2: alloc 0x14 bytes, vtable PTR_LAB_005ad018, fields[1]=1, [+2]=1, [+3]=0
  - case 6: alloc 0x14 bytes, vtable PTR_LAB_005acffc, fields[1]=1, [+2]=1, [+3]=0
  - case 7: alloc 0x14 bytes, calls FUN_004db070(1,1), vtable PTR_LAB_005acfe0
  - case 8: alloc 0x14 bytes, calls FUN_004db0e0(), vtable PTR_LAB_005acfc4
  - case 0xd: alloc 0x20 bytes, vtable PTR_LAB_005acfa8, fields[1]=1, [+2]=1, [+3]=0
  - case 0x11: alloc 0x18 bytes, calls FUN_004db070(1,1), vtable PTR_LAB_005acf8c
  - case 0x13: alloc 0x2c bytes, vtable PTR_LAB_005acf70, fields[1]=1, [+2]=1, [+3]=0
  - default: returns NULL
- Returns pointer to new object or NULL on allocation failure

**Calls:** operator_new, FUN_004db070, FUN_004db0e0

**Moddability:** hardcoded

---

## FUN_005107FB — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_005107FB` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_005107fb — JPEG/Image Data Stream Reader (Adobe marker detection)

Source: renderer/texture decompression. Reads byte stream from buffer, detects Adobe-style marker (0x41646f62 = "Adobe"), dispatches to read callback.

**Key logic:**
- Reads 2-byte big-endian length from stream buffer
- If buffer exhausted: calls read callback (param_1[5]+3 function table) to refill
- Reads first 2 bytes as length, subtracts 2
- If remaining < 0xc: sets param_1[*param_1+0x14]=0x4d, [*param_1+0x18]=remaining
- Else: reads 12 bytes into local buffer
- Checks for "Adobe" signature (0x41='A', 0x64='d', 0x6f='o', 0x62='b', 0x65='e')
  - If Adobe: writes 5 bytes to *piVar5+0x18..0x24, sets param_1[*param_1+0x14]=0x4b, sets +0x106=1, +0x107=local_d
  - If not Adobe: sets param_1[*param_1+0x14]=0x4d, [*param_1+0x18]=remaining
- Calls param_1[*param_1+4](param_1, 1) to advance position
- If remaining > 0: calls param_1[5]+0x10(param_1, remaining) to read more

**Calls:** read callback (param_1[5]+3), advance callback (param_1[*param_1+4]), fill callback (param_1[5]+0x10)

**Moddability:** hardcoded

---

## FUN_00506971 — FAIL
Source: docs/19-renderer.md (line 2826)
**Errors:**
- [MISSING_CALL] Doc calls list: FUN_0050653e, FUN_00500eac, FUN_00587bcf. Missing: thunk at param_3+0x20 (surface query), param_3+0x24 (actual blit), param_3+0x1c (surface lock), *local_8+0x34 (capability check).
- [MISSING_LOGICAL_PATH] Doc doesn't describe the fast-path (no-clip full surface copy) vs clipped path in sufficient detail.
- [INACCURATE_CALL] Doc says "thunk at param_3+0x24 to perform the actual blit". Source shows this is at vtable+0x24 (0x24 = 36, 9th vtable entry), dispatched as `(**(code **)(*param_3 + 0x24))(param_3, &local_1c, local_4c, uVar6)` — it locks/gets a destination surface. The actual copy happens via this call; it's not a simple "perform blit" but a LockRect equivalent.
- [MISSING_FLAGS] Doc doesn't describe param_7 flags: bit 0 (passthrough), bit 0x20000 (no format probe).
- [MISSING_GLOBAL] `DAT_005ad4b0` used but undocumented.
- [MISSING_RETURN] Return value -0x7789f794 (error code) on invalid rect not documented.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00506971 — Direct3D Texture Blitter (StretchRect with Clipping)

Source: renderer (Direct3D 8). Copies a sub-rectangle from source surface to destination surface, handling format conversion (DXT1/2/3/4/5, YUY2, UYVY), clipping, and pitch alignment.

**Key logic:**
- Calls FUN_0050653e if *param_1 already active
- Queries surface caps via thunk at param_3+0x20
- If param_5 (source rect) is null: uses full surface dimensions, sets passthrough flag
- If param_5 non-null: copies rect bounds, validates against surface; returns -0x7789f794 on bounds error
- Checks surface format local_6c (FourCC):
  - DXT1/2/3/4/5 (0x31545844, 0x32545844, 0x33545844, 0x34545844, 0x35545844): 4-aligned rect
  - UYVY (0x32595559), YUY2 (0x59565955): 2-aligned rect
  - Other formats: unaligned copy
- If full-surface no-clip copy and format allows: fast-path with aligned LockRect via param_3+0x24
- If clip needed: computes aligned sub-rect, calls param_3+0x24 to lock destination
- If format conversion needed (param_7 & 0x20000 == 0): probes surface format via param_3+0x1c + *local_8+0x34
- Stores output surface info in param_2 buffer (offset, format, size, pitch)
- Returns 0 on success, negative on error

**Calls:** FUN_0050653e, FUN_00500eac, virtual dispatch at param_3+0x20, +0x24, +0x1c, *local_8+0x34

**Moddability:** hardcoded

---

## FUN_0047B910 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_0047B910` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0047b910 — Text/String Position Search (Binary-like)

Source: ui/text_render. Searches for correct text rendering position with character visibility check.

**Key logic:**
- Reads vtable pointer from param_1[0xe0] for string buffer; defaults to DAT_005ea438 if null
- Iterates from param_3+1 to param_4-1:
  - Saves current char, replaces with null terminator
  - Calls FUN_004983b0(string+param_3, &param_2, local_4, 1) to measure rendered width
  - Restores character
  - If measured width exceeds target param_2: adjusts position (bisection-like), breaks
  - Otherwise advances and tracks cumulative width
- If at end (param_4) and last char non-null: decrements position
- Returns final position index

**Globals:** DAT_005ea438 (empty string default)

**Calls:** FUN_004983b0

**Moddability:** hardcoded

---

## FUN_004FB5D0 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_004FB5D0` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004fb5d0 — Animation/Float Array Fill (Hierarchical)

Source: renderer/animation. Walks a linked hierarchy filling float arrays with current value, resetting to default (500.0) when below threshold.

**Key logic:**
- Reads child ptr from param_1 + 0x110
- If child exists: starts with fVar1 = param_1 + 0x3c (current value)
- For each node in hierarchy:
  - Fills two 8-entry float arrays at param_1+0xcc (indices 0-7) and param_1+0xec (indices 0-7)
  - Each entry set to fVar1 if (index+1) < child->+0x50 or child->+0x54 (threshold)
  - Advances: fVar1 += child->+0x3c (increment), child = child->+0x110 (next)
  - Terminates if next is null or self-referential
  - Breaks if fVar1 >= _DAT_0059e91c (max threshold ~12500.0)
- Any unfilled array entries set to 0x43fa0000 (500.0f, default)

**Globals:** DAT_0059e91c

**Moddability:** hardcoded

---

## FUN_00490940 — PASS
Source: docs/19-renderer.md (line 6780)

**Verification:**
- Pool from FUN_00490930(): confirmed line 18
- Free node check at head +0x10: confirmed line 19 (piVar6 = *(int**)(iVar5+0x10))
- Marks busy, validates via FUN_00491d30: confirmed lines 24-26
- Allocates new (4-byte header + 0x44-byte data): confirmed lines 32-49: operator_new(4) for header, operator_new(0x44) for data
- Sub-struct init calls FUN_004912f0: confirmed line 45
- Registers via FUN_00434030: confirmed line 51
- Zeroes 0x40 bytes at 0x10 stride via FUN_004bb490: confirmed lines 53-56
- Unlinks from free list, updates head/tail: confirmed lines 64-87
- Decrements pool count, calls FUN_00491e40 + free: confirmed lines 80-82
- Calls FUN_004916e0 for final dispatch: confirmed line 93

Calls list verification:
- FUN_00490930: confirmed line 18
- FUN_00491d30: confirmed line 26
- operator_new: confirmed lines 32, 37
- FUN_004912f0: confirmed line 45
- FUN_00434030: confirmed line 51
- FUN_004bb490: confirmed line 54
- FUN_00491e40: confirmed line 81
- FUN_00587bcf: confirmed line 82
- FUN_004916e0: confirmed line 93

All claims verified correct. No errors found.

---

## FUN_005418E0 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_005418E0` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_005418e0 — Render Object Initializer (Large Struct)

Source: renderer/object_init. Initializes a large render object struct with default constants and string copy.

**Key logic:**
- Sets field +4 = 1.0f
- Sets field +8 = 1000.0f (0x447a0000)
- Zeroes fields +0xc through +0x20 (5 dwords)
- Calls FUN_00541cd0(0,0,0,0,0,0)
- Zeroes fields +0x3c through +0x68 (12 dwords):
  - +0x3c..0x5c: zero
  - +0x60: zero, +0x64: zero (actually offset 100 = 0x64)
  - +0x68: zero, +0x6c: 90.0f (0x42b40000), +0x70: 75.0f (0x42960000)
  - +0x74: 1.0f, +0x78: 0
  - +0x7c: address of LAB_00484848 (function pointer?)
  - +0x80: 0x22 (34), +0x84: -1, +0x88: 1.0f
- Zeroes fields +0x19c..+0x1b8 (8 dwords)
- Copies param_2 string to field +0x8c (string copy loop until null)
- Zeroes 0x18 dwords at +0x9c (96 bytes)

**Calls:** FUN_00541cd0

**Moddability:** hardcoded

---

## FUN_005289E0 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_005289E0` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_005289e0 — Vector Quaternion/SIMD Complex Transform (DSP-like)

Source: renderer/vector_math. Applies complex linear transform to 4-component uint vectors with bitwise blend/mask operations. Heavy use of global constants for polynomial approximation.

**Key logic:**
- Extracts 4 components from param_1 via AND masks (DAT_005d9060..006c)
- Computes linear transform: fVar = (component * DAT_005d9040..004c) + DAT_005d8ff0..0ffc
- Applies inverse: fVar = fVar - DAT_005d8ff0..0ffc
- Decomposition: fVar_orig - (DAT_005d9030..003c * delta_0..3) weighted chain
- Computes squared components (fVar * fVar)
- Bitwise operations: AND masks (PTR_DAT_005d8fc0..08fc) for carry extraction, blend masks via DAT_005d8fb0..08fbc
- Polynomial approximation via Horner evaluation:
  - Sine path: (c3*x^2 + c2)*x^2 + c1)*x^2 + c0) * x
  - Cosine path: same + final offset
- Blends sin/cos results with bit masks based on quadrant
- XOR combines with carry/shift bits and masked inputs
- Stores 2 x 4-component results in param_2 and param_3

**Globals:** ~60 global constants at DAT_005d8f30..005d906c range (polynomial coefficients, mask values)

**Calls:** none (pure computation)

**Moddability:** hardcoded (math constants)

---

## FUN_00500B42 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_00500B42` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00500b42 — Surface Blit Wrapper (With Lock/Unlock)

Source: renderer/blit. Wrapper around FUN_00506971 (texture blitter) and FUN_005007ef (surface copy) with lock/unlock.

**Key logic:**
- Calls FUN_00506538() to lock/prepare
- Validates param_1 and param_4 non-null; returns -0x7789f794 on null
- If param_1 == param_4: uses flags 0x10001 (self-copy)
- Else: uses flags 0x1
- Calls FUN_00506971(&local_54, param_4, param_5, param_6, 0, uVar1) to get surface info
- Calls FUN_005007ef(param_1, param_2, param_3, local_54..48, param_5, local_2c, param_7, param_8) for actual copy
- Calls thunk_FUN_0050653e() to unlock/cleanup
- Returns 0 on success

**Calls:** FUN_00506538, FUN_00506971, FUN_005007ef, thunk_FUN_0050653e

**Moddability:** hardcoded

---

## FUN_0049EB40 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_0049EB40` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0049eb40 — UI/Render Quad Setup (4-corner fill)

Source: renderer/quad. Sets up 4 corners of a filled quad/rectangle for rendering.

**Key logic:**
- Checks param_1+0xc non-zero; returns if zero
- Calls FUN_0049eca0() to reset/prepare
- Calls FUN_00553980(param_1+4, param_6, param_1[0xc], 0x20, 0xc0) to init render state with width=0x20, height=0xc0
- On success (returns 0):
  - Stores param_2..param_5 in param_1+0x3c..0x48 (x1, y1, x2, y2)
  - Calls FUN_00553650 for each of 4 vertices:
    - Vertex 0: (x1, y1) white (0x3f800000,0,0) alpha=0xffffffff
    - Vertex 1: (x1, y1+height) white (0,0x3f800000) alpha=0xffffffff
    - Vertex 2: (x1+width, y1+height) white (0x3f800000,0x3f800000,0x3f800000) alpha=0xffffffff
    - Vertex 3: (x1+width, y1) white (0x3f800000,0,0) alpha=0xffffffff

**Calls:** FUN_0049eca0, FUN_00553980, FUN_00553650 (4 times)

**Moddability:** hardcoded

---

## FUN_0050D93F — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_0050D93F` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0050d93f — Render Dispatch Thunk (Table-driven)

Source: renderer/dispatch. Thin wrapper that calls FUN_0050fea7(1) then dispatches through global function pointer.

**Key logic:**
- Calls FUN_0050fea7(1) — pre-dispatch setup
- Calls through PTR_FUN_005d7868(param_1, param_2, param_3, param_4) — indirect dispatch

**Calls:** FUN_0050fea7, indirect via PTR_FUN_005d7868

**Moddability:** hookable (via PTR_FUN_005d7868)

---

## FUN_00503E36 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_00503E36` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00503e36 — Pixel Format Downscale/Blend (2:1 reduction with edge blend)

Source: renderer/texture. Reduces a 16-bit texture row by averaging adjacent pixel pairs with edge-preserving blend.

**Key logic:**
- Reads source buffer from *param_1 + 0x1050 pitch, +0x105c height offset
- Reads destination buffer from param_1[1] + 0x18
- For each row: iterates through pixel pairs (2-byte stride)
  - Blends 4 adjacent pixels (topleft, topright, botleft, botright) using weighted average:
    - Extracts lower 3 bits each channel (mask 0x1c)
    - Averages with bias (+8, >>2)
    - For upper bits (mask 0xe3): averages with bias (+0x42, >>2)
    - XOR blends lower and upper results preserving 0x1c bit pattern
  - Writes 1 byte per pair (2:1 reduction)
- Writes to destination with matching pitch/stride

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x18 | SourceSurfacePtr |
| +0x1050 | RowPitch (bytes) |
| +0x1058 | VisibleWidth |
| +0x105c | SourceHeightOffset |

**Moddability:** hardcoded

---

## FUN_0050D0AF — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_0050D0AF` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0050d0af — Render Dispatch Thunk (via DAT_005d7810)

Source: renderer/dispatch. Thin wrapper: calls FUN_0050fea7(1), then dispatches via global function pointer DAT_005d7810.

**Key logic:**
- Calls FUN_0050fea7(1)
- Indirect jump/call via *_DAT_005d7810()
- All 4 params passed through

**Calls:** FUN_0050fea7, indirect via DAT_005d7810

**Moddability:** hookable (via DAT_005d7810 function pointer)

---

## FUN_004560E0 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_004560E0` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004560e0 — 3D Object Property Accessor (Position/Size Getter)

Source: renderer/object_props. Gets 3 fields from param_1 and writes to output pointers.

**Key logic:**
- If param_2 non-null: *param_2 = *(param_1 + 0x64) — field at +100 (+0x64)
- If param_3 non-null: *param_3 = *(param_1 + 0x68) — field at +0x68
- If param_4 non-null: *param_4 = *(param_1 + 0x6c) — field at +0x6c

**Moddability:** hardcoded

---

## FUN_004B2C20 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_004B2C20` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004b2c20 — Packed Field Bit Update (Float-to-Int Bit Insert)

Source: renderer/bitfield. Converts float to int via __ftol, then inserts 6-bit value (bits 0-5) at position 2 in a packed byte field.

**Key logic:**
- Reads current value from param_1+0xf (packed byte)
- Calls __ftol() to convert float ST(0) to int
- Masks converted value: (uVar2 & 0x3f) << 2
- Masks existing field: uVar1 & 0xffffff03
- XORs together and writes back to param_1+0xf

**Moddability:** hardcoded

---

## FUN_005619F1 — FAIL
Source: docs/19-renderer.md (NOT FOUND, no doc entry exists)
**Errors:**
- [NO_DOC_ENTRY] Function has no `## FUN_005619F1` entry in any doc file.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_005619f1 — Buffer Fill (16-bit value, counted)

Source: renderer/buffer. Fills a buffer with a 16-bit value for a given count.

**Key logic:**
- Computes base address: param_4 + param_1 * 2 (param_1 is offset in 16-bit units)
- Loops param_2 times: writes param_3 (16-bit) to each successive element
- No return value

**Moddability:** hardcoded

---

# Summary
- PASS: 2 (FUN_00489600, FUN_00490940)
- FAIL: 20
- PASS rate: 9%
