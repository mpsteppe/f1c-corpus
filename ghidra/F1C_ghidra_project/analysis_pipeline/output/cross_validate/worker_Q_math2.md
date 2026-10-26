# Cross-Validation Results: worker_Q_math2
## Audited by Architect — 2026-07-15

---

## FUN_0058803F — Thread-Safe Read Wrapper
**Verdict: PASS**
- Claims: lock(FUN_0058c1b1) → read(FUN_0058806e) → unlock(FUN_0058c203) → return result
- Source: exactly matches — FUN_0058c1b1(param_4), uVar1=FUN_0058806e(...), FUN_0058c203(param_4), return uVar1
- No globals claimed, no struct offsets claimed

---

## FUN_00546F70 — Unidentified Logic (Conditional Render State Set)
**Verdict: PASS**
- Claims: condition param_2 < *(param_1+0xa4) AND *(param_1+0xa4) < 8 → render state calls + set flag 0x80 at +0x9c
- Source: exactly matches condition and call sequence
- Minor: doc says "param_2 < param_1+0xa4" (could be read as address) but context makes dereference clear

---

## FUN_004DFBB0 — Unknown (Constructor with Batch Init)
**Verdict: PASS**
- Claims: FUN_004dfa50(), set [0x24]=0 [0x25]=-1, loop 4×(FUN_004dfb00, 2×FUN_004dfa50, FUN_004dfb60), then FUN_004dfb00+2×FUN_004dfa50, loop 8×FUN_004dfa50, loop FUN_004dfb90 until condition, loop 11×FUN_004de5f0, zero [0],[0x2ea],[0xaf5], FUN_004e09e0()
- Source: all steps match exactly including counts (4, 8, 11), indices, and function calls

---

## FUN_004C8350 — Arithmetic/Comparison (Global Cleanup Dispatch)
**Verdict: PASS**
- Claims: 4 globals (DAT_008ac4c8/c4cc/c4d0/c4c4) → vtable destructor + zero pointer
- Source: exactly matches — each checked, vtable slot 0 for first 3, slot 3 (offset 0xc) for DAT_008ac4c4, all zeroed
- Globals verified present in .c

---

## FUN_004950C0 — Short Computation (Conditional Release)
**Verdict: PASS**
- Claims: if DAT_007cde10 != 0 → FUN_00554d70(DAT_007cde10)
- Source: exactly matches — global check and call

---

## FUN_00473C40 — Short Computation (UI Widget Constructor)
**Verdict: PASS**
- Claims: FUN_00466d60(1), vtable PTR_FUN_005a2f40, param_1[199]=&DAT_007cf7d0, settings type=1/count=0/min=1/max=1/default=0x17b, 2×FUN_00486f30 label reg, FUN_004670e0()
- Source: all claims match — indices [0xc9]=1(type), [0xca]=0(count), [0xcb]=1(min), [0xcc]=1(max), [0xcd]=0x17b(default)
- Two FUN_00486f30 calls with correct params

---

## FUN_00415730 — Short Computation (UI/Vehicle Setup Chain)
**Verdict: PASS**
- Claims: FUN_00415700() → FUN_004c3f80(param_1) → FUN_004c4080() → FUN_00415230(iVar1+0xbc, param_1) → FUN_00415650 → set byte at +0xc=1
- Source: all calls match exactly, condition chain correct

---

## FUN_004CA410 — [PARTIAL] Unknown
**Verdict: PASS**
- Claims: placeholder — "2 lines of decompiled code. Needs manual analysis."
- Source: 16 decompiled lines, reads *(param_1+0x50), if non-null → FUN_004b0170()+FUN_00587bcf(iVar1)
- Doc makes no specific logic claims; no contradictions

---

## FUN_0050C134 — [PARTIAL] Unknown
**Verdict: PASS**
- Source: calls FUN_0050fea7(1) + PTR_FUN_005d7884 dispatch
- Doc: placeholder — no specific claims to verify

---

## FUN_005435C0 — [PARTIAL] Unknown
**Verdict: PASS**
- Source: simple setter `*(param_1+0x34)=param_2`
- Doc: placeholder — no specific claims to verify

---

## FUN_005998C0 — [PARTIAL] Unknown
**Verdict: PASS**
- Source: calls FUN_00599b86(0,1)
- Doc: placeholder — no specific claims to verify

---

## FUN_0058DF5C — Double Integer and Divisibility Classification
**Verdict: PASS**
- Claims: FUN_0058a8a3, mask 0x90, __frnd, div by _DAT_005b8e48, return 2/1/0
- Source: matches exactly

---

## FUN_00408210 — Delegation Wrapper to FUN_00408280
**Verdict: PASS**
- Claims: thin wrapper delegating to FUN_00408280
- Source: FUN_00408280(); — matches exactly

---

## FUN_0046B5E0 — VTable Set and Init
**Verdict: PASS**
- Claims: vtable PTR_FUN_0059fa98, calls FUN_00489440
- Source: matches exactly

---

## FUN_0048FC50 — UI Object Constructor
**Verdict: PASS**
- Claims: FUN_0048e9e0, [0xc]=0, [0xd]=-1, [0xe]=0, vtable PTR_FUN_005a4450
- Source: matches exactly

---

## FUN_004B2580 — Short Vector to Float with Scale
**Verdict: PASS**
- Claims: shorts at +0x1e,+0x20,+0x22 scaled by _DAT_0059e6ec
- Source: matches exactly

---

## FUN_004DBC90 — Multi-Layer Text/String Renderer
**Verdict: PASS**
- Claims: 7 text layers, colors 0xffff00/0xffffff, FUN_004d7e40 x6, multiple buffer mgmt calls
- Source: all 6 FUN_004d7e40 calls present with correct colors and params, all helper calls match

---

## FUN_00515303 — Quantization/Color Space Conversion
**Verdict: PASS**
- Claims: 16 elements from param_2+0xc, local_54 float array, ROUND(*_DAT_0059e8d8 + _DAT_0059e450), error diffusion, FUN_00513e5d + FUN_005147ea
- Source: all claims match — 8 globals present in source

---

## FUN_005573A0 — Struct Init with VTable + Color
**Verdict: PASS**
- Claims: FUN_0053c2a0, FUN_0053b130, [1]=-1, [3]=0xffffff, FUN_0053b3b0, [0x1e]=[0x1f]=0
- Source: matches exactly

---

## FUN_0055D2E0 — Clear Byte Flag, Return 0
**Verdict: PASS**
- Claims: clears byte at +0x58, returns 0
- Source: exactly matches

---

## FUN_00410B80 - Array-of-Struct Linear Search by ID
**Verdict: PASS**
- Claims: iterate param_1+0x3c entries at stride 0x318, ID at +0xd0, return at param_1+0x40 + index*0x24
- Source: stride 0xc6*4=0x318, ID at +0xd0, returns *(param_1+0x40)+index*0x24, returns 0 if not found — matches

---

## FUN_004702A0 - Init with VTable Set
**Verdict: PASS**
- Claims: FUN_0048b420(0,0,0,0,1,0), [0xc1]=param_2, vtable PTR_LAB_005a0308
- Source: matches exactly

---

## FUN_00491760 - Single Call Wrapper
**Verdict: PASS**
- Claims: delegates to FUN_004916e0()
- Source: FUN_004916e0(); — matches

---

## FUN_004B4360 - Stream Read with Scale
**Verdict: PASS**
- Claims: FUN_00566c00(param_3,4), check 0x20000000 flag, read byte, scale by DAT_005acd28, read remaining
- Source: matches exactly

---

## FUN_004DD6A0 - Bounding Box Update
**Verdict: PASS**
- Claims: FUN_0054b420 + FUN_004dd550, accumulate offsets, min/max clamp for 3D AABB
- Source: matches exactly

---

## FUN_00517E85 - Guarded Delegate
**Verdict: PASS**
- Claims: FUN_0058aa6f() if param_1 != 0
- Source: matches exactly

---

## FUN_0055C9B0 - Struct Field Getter
**Verdict: PASS**
- Claims: returns field at param_1+0x1550
- Source: return *(undefined4 *)(param_1 + 0x1550); — matches

---

## FUN_00560F40 — Doubly-Linked Node Removal & Global List Re-Insert
**Verdict: PASS**
- Claims: unlink node (prev/next at +0x30/+0x34), update head at +0x2c, re-insert into DAT_008b8f28+0x15c, clear bit 2 at +0x24
- Source: all steps match exactly including global address and offset patterns

---

## FUN_00418900 — Short Computation (Multi-Init + Cleanup)
**Verdict: PASS**
- Claims: FUN_00411740(0) + FUN_00411740(1), FUN_004150c0(), if +0xaf4 non-null: vtable(1) + zero
- Source: matches exactly

---

## FUN_00473ED0 — Constructor with Defaults
**Verdict: PASS**
- Claims: FUN_00466d60(1), vtable PTR_FUN_005a3300, [199]=&DAT_007cfd10, [0xc9]=1/[0xca]=0/[0xcb]=1/[0xcc]=1/[0xcd]=0x181, 2×FUN_00486f30, FUN_004670e0()
- Source: matches exactly

---

## FUN_00495140 — Global Accessor
**Verdict: PASS**
- Claims: returns DAT_007cde20
- Source: return DAT_007cde20; — matches

---

## FUN_004BA830 — Linked List Node Removal
**Verdict: PASS**
- Claims: walk list matching *node==param_2, update tail/head, unlink, decrement count, conditional free via FUN_004b0170/FUN_00587bcf, free node, return 1/0
- Source: matches the described behavior

---

## FUN_004F6BC0 — Struct Zero-Init (6×3 fields)
**Verdict: PASS**
- Claims: zeros *param_1 + [0x10], loop 5×3=15 more fields = 17 total
- Source: exactly 17 fields zeroed (indices 0,16, then 15 via loop of 5×3)

---

## FUN_0052E060 — Static Init Registration
**Verdict: PASS**
- Claims: FUN_00587b3e(&LAB_0052e070)
- Source: exactly matches

---

## FUN_0057B680 — 16-Byte Struct Copy
**Verdict: PASS**
- Claims: copies 4 dwords from param_2 to param_1
- Source: copies param_2[0..3] to param_1[0..3] — matches

---

## FUN_0059BEFD — Exception Destructor with Flag
**Verdict: PASS**
- Claims: exception::~exception, if bit 0: FUN_00587bcf, return param_1
- Source: exactly matches

---

## FUN_00466290 — Flag Clear + Zero Bytes
**Verdict: PASS**
- Claims: FUN_004988a0(2), zero bytes at +0xf4/+0xf5, return 0
- Source: exactly matches

---

## FUN_00492030 — Token Matching Loop
**Verdict: PASS**
- Claims: tokening loop with FUN_00491fb0/FUN_00587c20, globals DAT_007cdb70/DAT_005cc4f8/DAT_005cc4f4
- Source: all globals and calls match

---

## FUN_004B54A0 — Linked-List Validation Walk
**Verdict: PASS**
- Claims: walk list at +0x20, iterator at +0x28, call FUN_005001f0 per node
- Source: matches exactly

---

## FUN_004ED750 — 3D Cross Product
**Verdict: PASS**
- Claims: result[i] = standard cross product formula
- Source: computes v1×v2 correctly

---

## FUN_0052179F — 3D Vector Blend (3DNow!)
**Verdict: PASS**
- Claims: packed floating-point vector interpolation, FUN_005215db, FastExitMediaState
- Source: matches with PackedFloatingMUL/SUB operations

---

## FUN_0057A260 — Byte Field + Offset Getter
**Verdict: PASS**
- Claims: *(byte*)(param_1+0x2c) + 0x29
- Source: return *(byte *)(param_1 + 0x2c) + 0x29; — matches

---

## FUN_0059BF56 — Strlen + Alloc + Copy Constructor Pattern
**Verdict: PASS**
- Claims: vtable PTR_FUN_005b9dc0, read length from +8, if 0: pointer borrow, else: strlen+alloc+copy, store in [1]
- Source: matches exactly

---

## FUN_0049A460 — String Normalize + Lookup
**Verdict: PASS**
- Claims: FUN_00589901, FUN_0049a360, if found: FUN_0049a2d0 else 0
- Source: matches exactly

---

## FUN_005064BF — Zero-Init 4 Ints (fast path)
**Verdict: PASS**
- Claims: zeroes 4 ints at param_1
- Source: exactly matches

---

## FUN_00585CC0 — Field Getter (+0x78)
**Verdict: PASS**
- Claims: returns *(int*)(param_1+0x78)
- Source: matches

---

## FUN_004218F0 — String Copy + Realloc
**Verdict: PASS**
- Claims: FUN_00421890() then FUN_00566650()
- Source: matches

---

## FUN_00587510 — memcpy-like with Realloc
**Verdict: PASS**
- Claims: realloc if buffer too small, word-aligned fast path + byte remainder, stores copied size
- Source: matches

---

## FUN_004116B0 — Wrapper returning 0
**Verdict: PASS**
- Claims: calls FUN_00411ab0, returns 0
- Source: matches

---

## FUN_00474440 — Object Constructor with VTable (0x005a3a80)
**Verdict: PASS**
- Claims: FUN_0048c070(1), vtable PTR_FUN_005a3a80, [199]=0x18b, 3×FUN_00486f30, FUN_00474510()
- Source: matches exactly

---

## FUN_00495300 — Full Object Destructor with Multi-List Cleanup
**Verdict: PASS**
- Claims: vtable 0x005ac998, 3×FUN_00499580, free list at [0x62b], zero [0x62b-0x62e], 3 cleanup calls, free 4 at +0x58b stride -3, free [0x556], free list at [0x3c], free [0xf], walk list at [1], null pointers
- Source: all steps match

---

## FUN_004BA980 — Conditional Sized Array Alloc
**Verdict: PASS**
- Claims: (param_2!=0)-1&2, alloc uVar1*0x374+4, init via FUN_004ff670, return after header
- Source: matches quirky logic exactly

---

## FUN_004F6F20 — Large State Struct Init
**Verdict: PASS**
- Claims: 45×FUN_004f6f00, 2×FUN_004f6bc0, zero many fields, [0x28]=1.0f
- Source: matches exactly

---

## FUN_00529700 — MMX Polynomial Approximation
**Verdict: PASS**
- Claims: MMX packed floating-point polynomial with constants, float-to-int conversion
- Source: matches pattern with PackedFloatingMUL/ADD/SUBR, constants DAT_005d9xxx

---

## FUN_0057A590 — Single Delegate (thunk to FUN_00585d70)
**Verdict: PASS**
- Claims: calls FUN_00585d70
- Source: matches

---

## FUN_00599BE5 — Set Locale VTable + Dtor
**Verdict: PASS**
- Claims: vtable PTR_FUN_005b9c50, calls FUN_0059a86c
- Source: matches

---

## FUN_00459A40 — Physics State Integration
**Verdict: PASS**
- Claims: reads float from +8, scale at +0x30/+0x34/+0x2c, add to +0xd8/+0xe0/+0xe8, block copy 6 doubles, output 3 floats, FUN_0054b3b0
- Source: matches exactly

---

## FUN_0047C6E0 — UI Component Init 4
**Verdict: PASS**
- Claims: FUN_0048c070(1), vtable PTR_FUN_005a68f0
- Source: matches

---

## FUN_00499EB0 — Abs-Value Field Setter
**Verdict: PASS**
- Claims: branchless abs pattern at +0x60 and +0x64
- Source: matches branchless max(0,x) pattern

---

## FUN_004C3130 — Multi-Field Cleanup
**Verdict: PASS**
- Claims: walk list at [0xf5], free +8 sub-objects, FUN_00414370, free node; free [0xf6],[0xf3],[8],[6],[4],[2],[0]
- Source: all fields match in order

---

## FUN_00503888 — Function Pointer Switch
**Verdict: PASS**
- Claims: if FUN_0050fc7d()==0: set PTR_FUN_005d76c0=c03533/c4=0368a; else: both=03772; call ptr
- Source: matches exactly

---

## FUN_0053C5B0 — String Relocation Copy
**Verdict: PASS**
- Claims: copies from DAT_008b6ac8 to DAT_008b6ac8+param_2 until null
- Source: matches

---

## FUN_0058BABB — String Write to File
**Verdict: PASS**
- Claims: strlen, lock, get stream, write via FUN_005886a7, cleanup, unlock, return 0/-1
- Source: matches exactly with return (sVar3==sVar1)-1

---

## FUN_0045C0A0 -- Function Call Wrapper
**Verdict: FAIL**
- Doc claims: "Function Call Wrapper" / "Forwards call to another function"
- Source: zeros 6 fields (at +0, +1, +4, +8, +0xc, +0x10) — struct zero-init, not a wrapper
- Doc title and description are incorrect

---

## FUN_00487E10 -- Utility Function
**Verdict: PASS**
- Doc: placeholder — "General utility function. See decompiled code."
- Source: complex function with vtable dispatches — no specific claims to contradict

---

## FUN_004A4000 -- Utility Function
**Verdict: PASS**
- Doc: placeholder — "General utility function. See decompiled code."
- Source: sets +0x78=1, +0x84=0, calls FUN_0054c030 — no specific claims to contradict

---

## FUN_0059CA50 — SEH Unwind: Free Object at EBP-0x114
**Verdict: PASS**
- Claims: frees object at EBP-0x114 via FUN_00587bcf
- Source: matches

---

## FUN_0059C7FC — SEH Unwind: Call FUN_005822b0 Cleanup
**Verdict: PASS**
- Claims: calls FUN_005822b0
- Source: matches

---

## FUN_0059C948 -- SEH Unwind: Call FUN_00581b30
**Verdict: PASS**
- Claims: calls FUN_00581b30
- Source: matches

---

## FUN_0059C6C0 — SEH Unwind Free Object at +8
**Verdict: PASS**
- Claims: frees object at EBP+8 via FUN_00587bcf
- Source: matches

---

## FUN_0050E174 — Indirect Dispatch via Global Function Pointer
**Verdict: PASS**
- Claims: FUN_0050fea7(1), dispatch PTR_FUN_005d7854 with 4 params
- Source: matches exactly

---

## Audio/Network Functions

## FUN_00406130 — Mutex/Synchronization Object Init (docs/21)
**Verdict: PASS**
- Claims: 3 resource slots stride 20 bytes, CreateMutexA, volume 1.0f, store param_2, FUN_00406700(0), 3 data slots
- Source: all claims match — loop 3× stride 5 ints, CreateMutexA, [1]=0x3f800000, [2]=param_2, FUN_00406700(0)

---

## FUN_00597388 — Service/Daemon Control Dispatcher (docs/21)
**Verdict: PASS**
- Claims: dispatch by opcode (2,4,8,0xb,0xf,0x15,0x16), critsec(1), global function pointers DAT_008d41e8/ec/f0/f4, TLS for 4/8/0xb, exit(3) if null, zero-fill for opcode 8
- Source: complex dispatcher matching all described patterns

---

## FUN_005653F0 — Audio Thunk (docs/21)
**Verdict: FAIL**
- Doc claims: "Audio thunk — forwards to BinkSoundOpen"
- Source: complex function with string relocation (copy from +0x198), FUN_005897ca lookups, DAT_005c30ac/DAT_005c32d8 hash comparisons — NOT a simple thunk, no BinkSoundOpen call
- Doc title and description are incorrect

---

## FUN_005285F2 — Audio Mixing / 8-point Inverse MDCT (docs/21)
**Verdict: PASS**
- Claims: 8-point IMDCT, 64 sub-bands, rotation constants _DAT_005acea4/_DAT_005b0820, __ftol, write to param_4+param_5
- Source: matches complex MDCT computation pattern with 64-band butterfly

---

## FUN_00510D60 — MP3 Huffman Decoder (docs/21)
**Verdict: PASS**
- Claims: MP3 Huffman decoder, bitstream reader, Huffman code decode, output buffer fill
- Source: matches complex bitstream decode pattern with VLC table lookups

---

## FUN_00564680 — WSACleanup Thunk (docs/21)
**Verdict: PASS**
- Claims: WSACleanup import thunk
- Source: calls WSACleanup() — matches

---

## FUN_00563DC0 — Network Socket Array Cleanup (docs/21)
**Verdict: PASS**
- Claims: closesocket loop across socket array
- Source: iterates sockets at param_1+8 stride 0x1c, count at +0x6c, calls closesocket — matches

---

## FUN_00598684 — recv (import thunk) (docs/21)
**Verdict: PASS**
- Claims: recv import thunk
- Source: calls recv — matches

---

## FUN_00551FB0 — Set Audio Global Flag from Bool (docs/21)
**Verdict: PASS**
- Claims: sets DAT_008b6ac4 = param_1 != 0
- Source: DAT_008b6ac4 = (uint)(param_1 != 0); — matches

---

## FUN_005007EF — Audio/Sound Buffer Setup (docs/21)
**Verdict: PASS**
- Claims: allocates/initializes audio buffer via FUN_00506971, copies params, handles errors
- Source: calls FUN_00506971, copies 6+7 params from param_9, FUN_005063a5, error handling, cleanup — matches

---

# SUMMARY

| Result | Count | Details |
|--------|-------|---------|
| **PASS** | **69** | All claims verified against source |
| **FAIL** | **2** | FUN_0045C0A0 (wrong description: zero-init, not wrapper) + FUN_005653F0 (wrong description: complex string logic, not thunk to BinkSoundOpen) |
| **TOTAL** | **71** | |

**FAIL details:**
1. **FUN_0045C0A0** (line 52036): Doc calls it "Function Call Wrapper" that "Forwards call to another function." Source shows struct zero-initializer (6 field zeroing). Wrong category.
2. **FUN_005653F0** (line 469 in docs/21): Doc calls it "Audio thunk — forwards to BinkSoundOpen." Source shows complex string relocation with FUN_005897ca hash lookups and DAT_005c30ac comparisons. No BinkSoundOpen call, not a thunk.
