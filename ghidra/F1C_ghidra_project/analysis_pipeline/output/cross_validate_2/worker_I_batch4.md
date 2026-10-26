# Cross-Validation Results — BATCH 4 (worker_I_batch4)

## FUN_004f6b40 — FAIL
Source: docs/18-physics-dynamics.md
**Errors:** [WRONG_NAME] / [MISSING_CALL]
**Details:**
- Name "Tire/Grip Data Array Init (Rear)" conflicts with global reference entry (DAT_008af570 = InputMappingTable, not tire data). Function initializes 45 entries of input mapping table, not tire grip data.
- Missing call: FUN_00566650 called in each iteration (lock/push context)
**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004f6b40 — Input Mapping Table Init (Rear)

Source: input_mapping.cpp. Initializes 45 entries of input mapping/control binding table at DAT_008af570.

**Key logic:**
- Walks DAT_008af570 array (45 entries, stride 5 ints = 20 bytes)
- Each entry: field[-2]=0, field[-1]=-1, field[0]=-1, field[1]=-1, field[2]=0
- Calls FUN_00566650 per iteration (push context / lock)

**Globals:** DAT_008af570

**Calls:** FUN_00566650

**Moddability:** hardcoded

---

## FUN_0052b561 — PASS
Source: docs/18-physics-dynamics.md
- Verified: MMX pmaddwd/packssdw SIMD quaternion multiply with 5 constant vectors (DAT_005b0c70/78/80/88/90)
- Verified: shift-right-5, mask-0x3ff lookup into param_6 (1024-byte LUT)
- Verified: 32 bytes written to param_4[]+param_5 (8 slots × 4 bytes)
- Verified: no function calls (pure inline SIMD)

---

## FUN_004e4f40 — PASS
Source: docs/18-physics-dynamics.md
- Verified: zeroes +0x354c–+0x3560 (6 floats)
- Verified: DAT_0059e440 < +0x3a04 → FUN_004e5080
- Verified: mode check at +0x39f0 vs +0x39f4
- Verified: mode 0/1/2 spring/damper computation with _DAT_0059e450/_DAT_0059e7f8
- Verified: calls FUN_004e5080, FUN_0059daef
- Note: doc does not list globals _DAT_0059e440, _DAT_0059e43c, _DAT_0059e450, _DAT_0059e7f8 (minor omission)

---

## FUN_004f01b0 — PASS
Source: docs/18-physics-dynamics.md
- Verified: calls FUN_004e9630, reads ptr+0x24, ptr[0x43]+0x24, ptr[0x44]+0x24
- Verified: mode (*param_1+0x4040): 0=subtract, 2=add
- Verified: 2.8026e-45 denorm check for uninitialized floats
- Verified: projection of param_1[0xd35]–[0xd37] (offset 0x34d4) onto direction vector
- Verified: linear interpolation between segments, returns interpolated value

---

## FUN_004e2760 — PASS
Source: docs/18-physics-dynamics.md
- Verified: 4 wheel indices at param_1+0x108, stride 0x4a
- Verified: pack to +0x938, +0x93c, +0x93e
- Verified: flag at +0x98c controls clear vs. process path
- Verified: 17 analog channels at +0x9a8, stride 7 floats
- Verified: enable flag at pfVar9[-6], bitmask at +0x940
- Verified: 3 floats per channel (pfVar9[-2], [-1], [0]) scaled by _DAT_0059e708, clamped via _DAT_0059e70c/_DAT_0059e710
- Verified: stores at +0x944, +0x946, +0x948

---

## FUN_004485d0 — PASS
Source: docs/18-physics-dynamics.md
- Verified: 2D quadrant comparison (*param_2 vs *pfVar4, param_2[3] vs pfVar4[3])
- Verified: 4 child pointers at indices 0x13–0x16 (offsets 0x4c–0x58)
- Verified: operator_new(0x60) + FUN_00448510 for new node init
- Verified: double key match at *(param_2+1) == *(pfVar4+1)
- Verified: overflow chain at pfVar4[0x17] (offset 0x5c)
- Verified: struct offsets table is accurate

---

## FUN_00431390 — PASS
Source: docs/18-physics-dynamics.md
- Verified: param_1+0x19a4 = 0, *param_1 = 1
- Verified: *(param_1 + param_2*4 + 0x1ca8) = param_3
- Verified: calls FUN_004313c0

---

## FUN_00432920 — PASS
Source: docs/18-physics-dynamics.md
- Verified: returns *(undefined4*)(*param_1 + 0x3c)
- 6-byte function, vtable/vtable-referenced property accessor

---

## FUN_00433e60 — PASS
Source: docs/18-physics-dynamics.md
- Verified: calls FUN_00432cc0 (base destructor)
- Verified: frees param_1[5], [2], [0] via FUN_00587bcf
- Verified: if (param_2 & 1): frees param_1 (self)

---

## FUN_00441600 — PASS
Source: docs/18-physics-dynamics.md
- Verified: call sequence: FUN_004412f0, FUN_0043f7f0(param_1,param_2), FUN_0056ecf0, FUN_0056ee40, FUN_0056f090(param_1,param_2), FUN_00441450
- Verified: returns result from FUN_0056f090 (cast to double)

---

## FUN_00438100 — PASS
Source: docs/18-physics-dynamics.md
- Verified: dVar1 = *(double*)(+0x36c) × *(double*)(+0x364), stored at +0x374
- Verified: +0x22c = dVar1 × *(double*)(+0x38c) + *(double*)(+900)
- Verified: all 5 struct offsets correct (FactorA, FactorB, Product, Multiplier, BiasTerm)

---

## FUN_004e3050 — PASS
Source: docs/18-physics-dynamics.md
- Verified: 4 iterations, starting at param_1+500 (0x1f4), stride 0x4a ints (0x128 bytes)
- Verified: clears piVar1[-1]=0, frees *piVar1 via FUN_00587bcf, zeroes *piVar1
- Note: doc is a lightweight triage entry, matches source

---

## FUN_004c2cb0 — PASS
Source: docs/18-physics-dynamics.md
- Verified: count at param_1+0x28, stored value at +0x48
- Verified: running average formula (int(param_2) + prev) / count
- Verified: clamp logic — below _DAT_0059e43c → 1.0f (0x3f800000), above _DAT_0059e85c → 22.0f (0x41b00000)
- Verified: globals _DAT_0059e43c, _DAT_0059e85c

---

## FUN_004efb20 — PASS
Source: docs/18-physics-dynamics.md
- Verified: 3×3 rotation matrix at offsets +0x34b0–+0x34d0 (row0: b0/b4/b8, row1: bc/c0/c4, row2: c8/cc/d0)
- Verified: translation at +0x34d4/d8/dc
- Verified: extra vec3 at +0x34e0/e4/e8
- Verified: calls FUN_004ef680
- Algorithm: 3D affine transform — matches doc

---

## FUN_0058f6fe — PASS
Source: docs/18-physics-dynamics.md
- Verified: branch on dword_8D3F3C (pool active flag)
- Verified: active path: sub_58AB58(1,48) → sub_58F7C9 → link node → sub_58F8EB + sub_58AA6F (old head) → dword_8D3F68 = new node
- Verified: inactive path: static fallback via off_5E9A90/94/98, off_5E9AC0 → static storage
- Verified: returns 0 on success, 1 on failure
- Verified: all globals (dword_8D3F3C, dword_8D3F68, off_5E9AC0, off_5E9A90/94/98)

---

## FUN_0051f98e — PASS
Source: docs/18-physics-dynamics.md
- Verified: SSE dot product via _mm_and_ps with xmmword_5D8B40 (abs mask 0x7FFFFFFF)
- Verified: Newton-Raphson 1/sqrt with lazy init (dword_8D60C0, dword_8D60C4, xmmword_8D4690, xmmword_8D46A0, byte_8D46B0)
- Verified: normalization of a3, reflection matrix build, multiply by a2
- Verified: alignment-checked store (8 __m128 halves vs 4 aligned stores)
- Verified: no function calls (pure SSE intrinsics)
- Verified: all 8 globals listed

---

## FUN_004f8440 — PASS
Source: docs/18-physics-dynamics.md
- Verified: 3-component coordinate transform via dot products of orientation axes (param_1[5]–[10]) with velocity/position
- Verified: FUN_004f8850 param lookup
- Verified: gate at (*param_1+0x48bc)>>1 & 1
- Verified: wheel pair selection (+0x1a6 or +0x195 based on param_1[0x2c])
- Verified: local_20 = (param_1[0x23] - param_1[0x21]) * param_1[0x22], clamped [0,1]
- Verified: FUN_004c7bd0 (IsDriverPlayer) branch for player/AI force calc
- Verified: player path uses _DAT_005d67a0/9c/98, _DAT_007cf35c/f0
- Verified: AI path uses _DAT_005d67ac/a8/a4, _DAT_007cf2f0/38
- Verified: loop 5 to 0x2c (40 iterations), virtual dispatch at (*piVar1+8) and (*piVar1+4)
- Verified: special case iVar4=0x2c: param_1[399] *= _DAT_007cf314 * local_24
- Verified: parameter table at end is comprehensive

---

## FUN_00411b50 — PASS
Source: docs/19-renderer.md
- Verified: 0x2693→0x18d→0x2d, 0x2693→0x1aa→0x2e
- Verified: 0x2694→1→0x2a, 0x2694→2→0x2b
- Verified: lookup tables DAT_005bee08 (param_2=0) and DAT_005bf4c0 (param_2=1)
- Verified: validation (param_1<0 or iVar2<0 → return 1)
- Verified: stores mapping in param_3+8 and param_3+0xc
- Verified: calls FUN_00566650

---

## FUN_004862a0 — PASS
Source: docs/19-renderer.md
- Verified: if *(param_1+200) non-null → returns **(param_1+200)+0x38
- Verified: returns &DAT_005ea438 if null pointer chain
- Lightweight triage entry, accurate

---

## FUN_00489ba0 — PASS
Source: docs/19-renderer.md
- Verified: linked list at param_1+0x90, next via +0x8c
- Verified: name at +0xb0 (or DAT_005ea438 sentinel)
- Verified: FUN_00588410 for string comparison, FUN_00489ab0 on match
- Verified: returns 0 on match, 0xffffffff on no match

---

## FUN_004957a0 — PASS
Source: docs/19-renderer.md
- Verified: short array at param_3, count=param_2
- Verified: shortcut 1 → +0x50→+0x60; shortcut 0x1c → +0x50→+0x58
- Verified: calls FUN_004988d0 with text pointer
- Verified: delegates to vtable+0x20

---

## FUN_0045bc10 — PASS
Source: docs/19-renderer.md
- Verified: null check param_1 → DAT_005ea438 sentinel
- Verified: calls FUN_0058969d(param_2, param_3, &DAT_005c5b60, param_1)
- Verified: null-terminates at param_2+param_3-1
- Verified: returns bool (-1 < iVar1)

---

## FUN_00560410 — PASS
Source: docs/19-renderer.md (triage entry)
- Verified: DAT_005dd804 = transparent color key (param_9 & 0xffff)
- Verified: two paths — fast 32-bit aligned copy when key=0xffff and alignment OK; per-pixel 16-bit comparison with color key skip otherwise
- Verified: stride support (param_4 src row stride, param_6 dst row stride)
- Triage entry description matches source behavior

---

## FUN_0053d4f0 — PASS
Source: docs/19-renderer.md
- Verified: calls FUN_00553de0 (8 times in loop)
- Verified: sets DAT_008b6ac8=0, _DAT_008b6ab8=0
- Verified: initializes many struct offsets at param_1 (0x4, 0x8, 0x10fc–0x1174, 0x1398–0x1558, etc.)
- Verified: sets dimension values (0x280=640, 0x1e0=480, 0x1e00=7680, 0x4b0=1200)
- Doc is minimal but accurate

---

## FUN_00540250 — PASS
Source: docs/19-renderer.md
- Verified: acquires surfaces via vtable 0x3c dispatch
- Verified: checks +0x30 bit depth (>8 → interlacing mode)
- Verified: two paths — param_10==-2 (direct, vtable 0x70) vs indirect (vtable 0x24/0x28)
- Verified: indirect path calls FUN_005401a0
- Verified: releases surfaces via vtable+8
- Verified: clears dirty flag at +0x18 (0xfffffbff mask)

---

## FUN_00459330 — PASS
Source: docs/19-renderer.md
- Verified: calls FUN_00415c30 + FUN_00566650
- Verified: copies projection quaternion (+0x90–+0x98)
- Verified: 6 rect copy functions (FUN_00456040/60/80/a0/c0/e0) = 3 sub-rectangles × 2
- Verified: squares FOV at +0x8c (fVar1 × fVar1)
- Verified: calls FUN_004582e0(iVar2+0xb0)
- Calls list matches source

---

## FUN_00504731 — PASS
Source: docs/19-renderer.md
- Verified: checks extraout_ECX[2] flag == 1
- Verified: takes min of 3 dimensions (0x1058, 0x105c, 0x1060)
- Verified: allocates two vertex buffers with stride 0x10
- Verified: vtable dispatch at +4 and +8 for copy
- Verified: calls FUN_0058a5d8, _vector_constructor_iterator_, FUN_00587bcf
- Verified: returns HRESULT (0 = success)

---

## FUN_00530840 — PASS
Source: docs/19-renderer.md
- Verified: reads bitstream state at +0x24a8 (bit pos) / +0x24a4 (buffer ptr)
- Verified: decodes variable-length codes via param_6 codebook
- Verified: two modes based on +0x24cc (1=single, 2=dual channel)
- Verified: produces 3 output shorts at offsets -0x40, 0, +0x40
- Verified: color lookup via param_2 palette (64-entry/row, 4 bytes each)
- Verified: byte-reverse and rotate operations
- Verified: jump-table dispatch at end

---

## FUN_0054b570 — PASS
Source: docs/19-renderer.md
- Verified: checks dirty flags at +0x3c
- Verified: sin/cos of yaw(+0x2c), pitch(+0x30), roll(+0x34)
- Verified: writes rotation to primary slot (+0x114/124/134), position to +0x144, W=1
- Verified: copies backup to +0x154, sets computed flag 0x40
- Verified: calls FUN_0054b330, FUN_0053b240/200, FUN_0054b770
- Struct offset table verified

---

## FUN_00554cc0 — PASS
Source: docs/19-renderer.md
- Verified: linked list at param_1+0x24, next via +0xc0
- Verified: stride 0x25 (37 dwords) elements per node
- Verified: flag check at (piVar4[-0x13]) & 2
- Verified: release chain: FUN_0053f6e0 → FUN_00557470 → FUN_00587bcf
- Verified: calls FUN_00554d70 per element

---

## FUN_0045bd10 — PASS
Source: docs/19-renderer.md
- Verified: checks DAT_007d02e4 (line cap)
- Verified: 0x1020304 → FUN_0045bb60 conversion
- Verified: measures string length, copies up to 79 chars (0x4f) via _strncpy
- Verified: trims trailing spaces by scanning backwards from position 0x4e
- Verified: calls FUN_0045b9c0(line, mode, DAT_0059f07c, param_2)
- Verified: globals DAT_007d02e4, DAT_0059f07c

---

## FUN_004cd8d0 — PASS
Source: docs/19-renderer.md
- Verified: param_2 *= _DAT_005acec4
- Verified: ROUND==0 path → FUN_004cb5e0
- Verified: count at +0x58>0 and +100==0 → FUN_004024f0
- Verified: iVar2 = ROUND(param_2) * 0x1000000 + 0xffffff
- Verified: element array at +0x68, calls FUN_00558dc0(elem, 0-3, iVar2) (4 channels)
- Verified: calls FUN_004cb5e0, FUN_004024f0, FUN_00558dc0

---

## FUN_005604c0 — PASS
Source: docs/19-renderer.md
- Verified: src = base + Y*srcRowStride + X*2
- Verified: dst = base + Y*dstRowStride + X*2
- Verified: LOCK/UNLOCK pair
- Verified: 16-bit pixel != param_13 → CONCAT22 expansion to 32-bit
- Verified: writes to both dest and dest+param_10
- Verified: stride advance logic

---

## FUN_00409970 — PASS
Source: docs/19-renderer.md
- Verified: if *(param_1+8) != 0 → calls 5 functions:
  - FUN_00542050(_DAT_007cf6a4*_DAT_0059e65c, _DAT_007cf6c8*_DAT_0059e65c, 1)
  - FUN_00541ca0(DAT_007cf680)
  - FUN_00542540(&LAB_004099e0, 0)
  - FUN_00542680(0x3f000000 = 0.5f)
  - FUN_00542650(DAT_007cf6ec)
- Verified: all 5 globals listed

---

## FUN_00489530 — PASS
Source: docs/19-renderer.md
- Verified: vtable+0x2c(1)
- Verified: param_1[0x53]++ (counter at +0x14c)
- Verified: calls FUN_00489d00(), FUN_00489e90()
- Verified: returns 0

---

## FUN_0053c360 — PASS
Source: docs/19-renderer.md
- Verified: zeroes DAT_008b5a3c..0x8b6abc, stride 0x84
- Verified: sets DAT_008b8e30 = 0
- Verified: calls FUN_0053d930, FUN_0053d750, FUN_0055be80, FUN_0053b0d0, FUN_005566d0
- Verified: allocates via FUN_0055f080 (0xa0 bytes) + FUN_005593b0 (0xc bytes)
- Verified: stores in DAT_008b8f04, DAT_008b8f2c

---

## FUN_0048bc70 — PASS
Source: docs/19-renderer.md
- Verified: calls FUN_0048bbe0()
- Verified: vtable+0xac()
- Verified: returns 0

---

## FUN_00553a20 — PASS
Source: docs/19-renderer.md
- Verified: checks flag 0x40000 at +0x18
- Verified: if set: calls FUN_0055c860(param_1, param_2, param_2+0xc, param_3)
- Verified: if not set: chain of __ftol() calls + FUN_00553aa0
- Verified: clears bit 10 (0x400) via &0xfffffbff in both branches
- Minor note: doc says "clears 0x400" only in if-branch but clearing happens in both

---

## FUN_0048e3a0 — PASS
Source: docs/19-renderer.md
- Verified: existing font at +0xe4 → FUN_00551f80
- Verified: path at +0xb0 (or DAT_005ea438 sentinel)
- Verified: allocates 0x80-byte buffer
- Verified: uses DAT_005ec3f0 (font dir) and +0xb8 (fallback path)
- Verified: calls FUN_00551f10 (load font)
- Verified: calls FUN_00551eb0(DAT_007cf2cc) to register
- Verified: stores font width/height

---

## FUN_004cb860 — FAIL
Source: (none)
**Errors:** [NO_DOC_ENTRY]
**Details:**
- Function exists as IDA Hex-Rays decompilation (1008 bytes) in analyzed/
- No ## FUN_004cb860 entry found in any docs/ file
- Globals ref mentions it uses DAT_008AC4E0 (SceneObjectPool) and DAT_005D3494 (PhysicsStepAccumulator)
- Source shows it iterates scene objects with LOD culling, time-based interpolation, and color/intensity computation
- Needs a full doc entry
**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004cb860 — Scene Object LOD Processing with Time Interpolation

Source: scene_render.cpp. Processes scene objects with level-of-detail selection, time-based interpolation, and color/intensity update.

**Key logic:**
- Reads dword_8AB6E4 (render mode flag): if 2, gets time from sub_4B9CE0; else uses dbl_8AFEA0 (global time)
- Iterates objects from array at this+104 (count at this+100)
- For each object: checks time against v5[2] (start) and v5[3] (end) — culls if out of range
- Computes interpolation factor v26 = time - v5[2]
- Computes 3D position: v5[11] + v26*v5[14], etc.
- Computes orientation/scale using object v5[26] × (this+36/40/44) + (this+24/28/32)
- Applies camera view transform (this+12/16/20) multiplied by interpolation factor
- Half-scale adjustment on Y-component
- Calls sub_558C60 and sub_558CB0 to set position and transform data
- Computes color/intensity: two branches based on v21 <= v5[5] (with v22|v3 condition) for intensity = v26 * v5[8] * v5[10] or (1-(v21-v5[6])*v5[9])*v5[10]
- Calls sub_558CF0 to set final color: (intensity << 24) + 0xFFFFFF

**Globals:** dword_8AB6E4, dbl_8AFEA0, DAT_008AC4E0 (SceneObjectPool), DAT_005D3494, dword_7CFA28, dword_7C54F0, dword_7C54DC, dword_7C54E0, flt_5D3490, flt_5D3494

**Calls:** sub_4B9CE0, sub_5881F0, sub_4C9C70, sub_4CBDD0, sub_558C60, sub_558CB0, sub_558CF0, sub_4CB5A0

**Moddability:** hardcoded

---

## FUN_00519361 — PASS
Source: docs/19-renderer.md
- Verified: *(undefined4*)(*param_1 + 0x14) = 0x30
- Verified: vtable dispatch via **param_1
- Verified: struct offset +0x14 = AllocationTag (written with 0x30)
