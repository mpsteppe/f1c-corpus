# Cross-Validation Report — worker_F_A

**Generated:** 2026-07-15
**Functions processed:** 46 (1756-1801)
**Doc target:** docs/01-engine-architecture.md (except 1756-1757 → docs/00-source-tree.md)

---

## 1756. FUN_0042C130 — DynMan::Enter

**PASS**

Doc: docs/00-source-tree.md (line 17204 as ### entry)
Source: decompiled_all\0x0042c130__FUN_0042c130.c

Verification:
- ✅ "DynMan module entry point" — source path dynman.cpp
- ✅ Calls FUN_004d7a50(2, ...) — level 2 trace guard
- ✅ If enabled: logs to DAT_008ad25c with "Entered DynMan::Enter()"
- ✅ Delegates to FUN_0042bd60
- ✅ Calls: FUN_004d7a50, FUN_004d7aa0, FUN_0042bd60 — all present

---

## 1757. FUN_004D7150 — Tire brand file parser (*.tbc)

**PASS**

Doc: docs/00-source-tree.md (line 1131 as #### entry)
Source: decompiled_all\0x004d7150__FUN_004d7150.c

Verification:
- ✅ Opens and parses .tbc tire brand files — source path tire_manager.cpp
- ✅ First pass: counts SLIPCURVE and COMPOUND sections
- ✅ Allocates slip curves (0x18 bytes) and compounds (0x2A8 bytes)
- ✅ Second pass via FUN_004d5f70 (slip curves) and FUN_004d6b00 (compounds)
- ✅ "Bad syntax in file %s caused miscount" error string present
- ✅ Extracts filename without extension
- ✅ Calls list comprehensive and matching

---

## 1758. FUN_0049F000 — OnScreen::Restart()

**PASS**

Doc: docs/01-engine-architecture.md (line 181, ### entry)
Source: decompiled_all\0x0049f000__FUN_0049f000.c

Verification:
- ✅ Source path: onscreen.cpp
- ✅ Calls FUN_0045bdf0 twice (lines 14, 18)
- ✅ Calls FUN_0049f150(0)
- ✅ Sets param_1+4 = 1 (active flag), param_1+8 = 0 (sub-state)
- ✅ Calls FUN_004d82a0 (buffer flush)
- ✅ Calls: FUN_0045bdf0, FUN_0049f150, FUN_004d82a0

---

## 1759. FUN_00455240 — EMPTY String Pointer Getter

**PASS**

Doc: docs/01-engine-architecture.md (line 673, ### entry)
Source: decompiled_all\0x00455240__FUN_00455240.c

Verification:
- ✅ Returns from s__EMPTY__005c44b0 table, stride 9 — source confirms `param_1 * 9`
- ✅ Range 0–0x6D — source `param_1 < 0x6e`
- ✅ Default: returns DAT_005ea438 (empty string)
- ✅ No game logic — pure string table lookup

---

## 1760. FUN_00413820 — Cascading Threshold Level Mapper

**FAIL** — Minor inaccuracy in level range

Doc: docs/01-engine-architecture.md (line 1009, ## entry)
Source: analyzed\0x00413820__FUN_00413820.c

Verification:
- ✅ Requires param_2==0 and param_4==0
- ✅ Compares param_3 against threshold globals DAT_0059e420 through DAT_0059e788
- ✅ Stores result in param_1+8
- ✅ Calls FUN_00414180 for secondary value at param_1+0xc
- ✅ Thresholds cascade from DAT_0059e420 (highest) downward
- ❌ Doc says range "0-17" but actual range is 1-17 (minimum is 1 when param_3 < first threshold; return 0xffffffff on error)
- ❌ Missing documentation of final raw param_3 comparisons against constants 0x4b, 0x6e, 0x3e6

Corrected entry:
```
## FUN_00413820 — Cascading Threshold Level Mapper

Source: Unknown. Maps an integer value to a discrete level (1-17) through cascading threshold comparisons.

**Key logic:**
- Requires param_2==0 and param_4==0
- Compares param_3 against threshold globals (DAT_0059e420 through DAT_0059e788) in cascade
- Returns level: 1-17 based on which threshold range param_3 falls in
- After all thresholds passed: additional raw comparisons against 0x4b (→14), 0x6e (→15), 0x3e6 (→16 or 17)
- Stores result in param_1+8, calls FUN_00414180 for secondary value at +0xc

**Calls:** FUN_00414180

**Moddability:** hardcoded
```

---

## 1761. FUN_0058AFD8 — TLS Offset Getter (+12)

**PASS**

Doc: docs/01-engine-architecture.md (line 1410, ## entry)
Source: analyzed\0x0058afd8__FUN_0058afd8.c (9 bytes)

Verification:
- ✅ Calls FUN_0058e0c7() — TLS value retrieval
- ✅ Returns result + 0xc (+12 bytes)

---

## 1762. FUN_00583650 — Single Function Call Wrapper

**PASS**

Doc: docs/01-engine-architecture.md (line 2006, ## entry)
Source: analyzed\0x00583650__FUN_00583650.c (8 bytes)

Verification:
- ✅ Calls FUN_004b0170 with no arguments

---

## 1763. FUN_0050FDF3 — OS Version Detection (GetVersionEx)

**PASS**

Doc: docs/01-engine-architecture.md (line 2410, ## entry)
Source: analyzed\0x0050fdf3__FUN_0050fdf3.c

Verification:
- ✅ Calls GetVersionExA (OSVERSIONINFOA)
- ✅ Checks dwPlatformId: 1=Win9x, 2=NT
- ✅ Win9x: IE4+ check (build >= 0x55d)
- ✅ WinNT: calls IsProcessorFeaturePresent for features 6, 7, 10
- ✅ Feature 10 (SSE): checks via FUN_0050fd4e bit 3
- ✅ Returns feature flag or 0
- ✅ Calls: GetVersionExA, IsProcessorFeaturePresent, FUN_0050fd4e, FUN_0050fd16

---

## 1764. FUN_005996AE — Buffer Size Management with Copy

**PASS**

Doc: docs/01-engine-architecture.md (line 2882, ## entry)
Source: analyzed\0x005996ae__FUN_005996ae.c

Verification:
- ✅ Partial decompilation (register variables) correctly handled
- ✅ Reads buffer size from *(uint*)(unaff_ESI + 8)
- ✅ Calls FUN_0058cc00(dest+1, src, uVar2) — memmove-style copy
- ✅ Calls FUN_005993af(1) — reference count decrement
- ✅ Writes null terminator at buffer start
- ✅ Sets +0xc = total size, +0x08 = new capacity
- ✅ Writes null at position src_ptr + new_capacity

---

## 1765. FUN_0057BC70 — Single VTable Pointer Set

**PASS**

Doc: docs/01-engine-architecture.md (line 3330, ## entry)
Source: analyzed\0x0057bc70__FUN_0057bc70.c (7 bytes)

Verification:
- ✅ Sets *param_1 = &PTR_LAB_005b8a00 — vtable pointer
- ✅ No other calls

---

## 1766. FUN_00462140 — Short Computation / Refresh Flag Clear

**PASS**

Doc: docs/01-engine-architecture.md (line 3910, ## entry)
Source: analyzed\0x00462140__FUN_00462140.c (22 bytes)

Verification:
- ✅ Checks DAT_007cd2a0 != 0
- ✅ If set: clears to 0, returns 1
- ✅ Otherwise: returns 0

---

## 1767. FUN_004C7E80 — Double-Linked List Destroy with Virtual Call

**PASS**

Doc: docs/01-engine-architecture.md (line 4346, ## entry)
Source: analyzed\0x004c7e80__FUN_004c7e80.c

Verification:
- ✅ Gets list container at param_1 + 0xc
- ✅ Two passes over linked list at *container
- ✅ Each node: if flag set and data non-null: calls virtual destructor (*(*data))(1)
- ✅ Frees node via FUN_00587bcf
- ✅ Zeros container head/tail/count/size
- ✅ Second pass identical to first
- ✅ Frees container pointer itself
- ✅ Zeros param_1+0xc

---

## 1768. FUN_00587BCF — Free Wrapper (Thunk to FUN_0058aa6f)

**PASS**

Doc: docs/01-engine-architecture.md (line 4804, ## entry)
Source: analyzed\0x00587bcf__FUN_00587bcf.c (11 bytes)

Verification:
- ✅ Single jmp to FUN_0058aa6f (heap deallocation)

---

## 1769. FUN_0057ADC0 — Free Callback Registration

**PASS**

Doc: docs/01-engine-architecture.md (line 5379, ## entry)
Source: analyzed\0x0057adc0__FUN_0057adc0.c (12 bytes)

Verification:
- ✅ Calls FUN_00587b3e(&LAB_0057add0) — callback registration

---

## 1770. FUN_00586A10 — Bounded Memory Copy with Size Validation

**PASS**

Doc: docs/01-engine-architecture.md (line 5921, ## entry)
Source: analyzed\0x00586a10__FUN_00586a10.c

Verification:
- ✅ Gets min size from FUN_0053d880()
- ✅ If param_2 < min size: returns 4
- ✅ Calls FUN_00587580 for buffer validation
- ✅ Copies data in dword chunks + trailing bytes
- ✅ If param_3 non-null: stores actual size
- ✅ Returns 0 (success), 1 (invalid buffer)

---

## 1771. FUN_00546370 — Array Cleanup with Dual Free

**PASS**

Doc: docs/01-engine-architecture.md (line 6350, ## entry)
Source: analyzed\0x00546370__FUN_00546370.c

Verification:
- ✅ If param_1+0xa8 non-null
- ✅ Iterates count at +0xa4, stride 0x94
- ✅ Frees pointer at +0x4c from base
- ✅ Frees pointer at +0x90 from base (with FUN_00557470 first)
- ✅ Frees allocation block with refcount decrement
- ✅ Zeros param_1+0xa8
- ✅ Calls: FUN_00587bcf, FUN_00557470

---

## 1772. FUN_005987FF — Callback Registration (atexit-style)

**PASS**

Doc: docs/01-engine-architecture.md (line 6805, ## entry)
Source: analyzed\0x005987ff__FUN_005987ff.c (12 bytes)

Verification:
- ✅ Calls FUN_00587b3e(&LAB_0059880b)

---

## 1773. FUN_0058A5F7 — N-Time Callback Loop with SEH

**PASS**

Doc: docs/01-engine-architecture.md (line 7108, ## entry)
Source: analyzed\0x0058a5f7__FUN_0058a5f7.c

Verification:
- ✅ SEH setup (ExceptionList manipulation)
- ✅ Loops param_3 times, calling (*param_4)()
- ✅ Decrements param_3, exits when < 0
- ✅ Sets SEH cookie 0xffffffff, calls FUN_0058a65f (SEH epilogue)
- ✅ Restores ExceptionList

---

## 1774. FUN_0046AF00 — Dual Call Wrapper

**PASS**

Doc: docs/01-engine-architecture.md (line 7510, ## entry)
Source: analyzed\0x0046af00__FUN_0046af00.c (23 bytes)

Verification:
- ✅ Calls FUN_0046ae60()
- ✅ Calls FUN_00489ab0(0, 1)
- ✅ Returns 0

---

## 1775. FUN_004902C0 — Linked List Destructor with VTable Notification

**PASS**

Doc: docs/01-engine-architecture.md (line 7884, ## entry)
Source: analyzed\0x004902c0__FUN_004902c0.c

Verification:
- ✅ Sets vtable to PTR_FUN_005ac760
- ✅ Walks linked list at param_1[0x38]
- ✅ Each node: if flag[3] set and data: calls vtable+0 on *data(1)
- ✅ Frees each node via FUN_00587bcf
- ✅ Zeros list head fields (4 slots)
- ✅ Calls FUN_00485eb0()

---

## 1776. FUN_004DFB60 — Init with Dual Call

**PASS**

Doc: docs/01-engine-architecture.md (line 8197, ## entry)
Source: analyzed\0x004dfb60__FUN_004dfb60.c

Verification:
- ✅ Calls FUN_004dfb00()
- ✅ Zeros fields at +0x120, +0x10c, +0x110
- ✅ Calls FUN_004dfa50() twice

---

## 1777. FUN_0055C060 — Call Wrapper

**PASS**

Doc: docs/01-engine-architecture.md (line 8504, ## entry)
Source: analyzed\0x0055c060__FUN_0055c060.c (11 bytes)

Verification:
- ✅ Calls FUN_0055be60()

---

## 1778. FUN_00593C50 — CRT __CallSettingFrame@12

**PASS**

Doc: docs/01-engine-architecture.md (line 8954, ## entry)
Source: analyzed\0x00593c50____CallSettingFrame_12.c

Verification:
- ✅ MSVC __CallSettingFrame — SEH notification helper
- ✅ __NLG_Notify1 call + function pointer dispatch
- ✅ If param_3 == 0x100: converts to 2
- ✅ Second __NLG_Notify1 call

---

## 1779. FUN_0058A6EB — N-Time Callback Loop with SEH

**PASS**

Doc: docs/01-engine-architecture.md (line 9659, ## entry)
Source: analyzed\0x0058a6eb__FUN_0058a6eb.c

Verification:
- ✅ SEH handler frame setup (DAT_005b8cb8, LAB_0058895c)
- ✅ ExceptionList registration
- ✅ Loop: calls (*param_4)() for param_3 iterations
- ✅ Sets local_8 = 0xffffffff (SEH termination)
- ✅ Calls FUN_0058a755 — SEH epilogue
- ✅ Restores ExceptionList

---

## 1780. FUN_00598AEA — Vtable Set + Sub-Call

**PASS**

Doc: docs/01-engine-architecture.md (line 10196, ## entry)
Source: analyzed\0x00598aea__FUN_00598aea.c (11 bytes)

Verification:
- ✅ Sets *param_1 = &PTR_FUN_005b9bb4
- ✅ Calls FUN_0059a86c

---

## 1781. FUN_0040DCD0 — State Machine Initializer

**PASS**

Doc: docs/01-engine-architecture.md (line 10744, ## entry)
Source: analyzed\0x0040dcd0__FUN_0040dcd0.c

Verification:
- ✅ Sets param_1[0x21] = 0 (state detail)
- ✅ Sets *param_1 = 1 (state = starting)
- ✅ Calls FUN_0040d490 (prep)
- ✅ Calls FUN_00568210(param_2) → stores at param_1[0x21]
- ✅ If lookup returns 0: returns 0
- ✅ Sets *param_1 = 2 (state = processing)
- ✅ Calls FUN_0040ddf0 (process step)
- ✅ If succeeds: returns 1
- ✅ Sets *param_1 = -1 (state = error), returns 0
- ✅ Offset table correct: +0x00 (State), +0x84 (ResultID = 0x21*4)

---

## 1782. FUN_00598B5D — Object Constructor with SEH + Vtable Init

**PASS**

Doc: docs/01-engine-architecture.md (line 11256, ## entry)
Source: analyzed\0x00598b5d__FUN_00598b5d.c

Verification:
- ✅ Calls FUN_0058a5d8() — allocation/pre-init
- ✅ Sets vtable at *extraout_ECX = &DAT_005b9bc0
- ✅ Sets extraout_ECX[0xb] = 0
- ✅ Sets extraout_ECX[2] = &PTR_FUN_005b9bb4
- ✅ Sets vtable at *(extraout_ECX+4)+extraout_ECX = &PTR_LAB_005b9ba4
- ✅ Calls FUN_0059a8fa() — post-init
- ✅ Restores ExceptionList

---

## 1783. FUN_0057B5C0 — Ring Buffer Pop with Wrap Check

**PASS**

Doc: docs/01-engine-architecture.md (line 11694, ## entry)
Source: analyzed\0x0057b5c0__FUN_0057b5c0.c

Verification:
- ✅ Checks param_3 <= count at param_1+0x1002 (ushort)
- ✅ Loops param_3 times: reads byte from ring buffer at (param_1 + *(short*)(param_1+0x1000))
- ✅ Writes to output at param_2
- ✅ Increments read position with modulo 0x1000 wrap: (pos+1) & 0x80000fff with sign adjustment
- ✅ Decrements count at +0x1002 by param_3
- ✅ Returns 0x101 on success (CONCAT31)
- ✅ Struct offsets: +0x1000 (readPos), +0x1002 (count) — correct

---

## 1784. FUN_00565F50 — Linked List Pop Front

**PASS**

Doc: docs/01-engine-architecture.md (line 12097, ## entry)
Source: analyzed\0x00565f50__FUN_00565f50.c

Verification:
- ✅ Reads next ptr from *param_1
- ✅ Sets param_1[2] = piVar1 (popped node)
- ✅ Checks for null/empty
- ✅ Returns success/fail bit flag
- ✅ No sub-calls

---

## 1785. FUN_00473F50 — UI Screen Constructor (Type 2)

**PASS**

Doc: docs/01-engine-architecture.md (line 12403, ## entry)
Source: analyzed\0x00473f50__FUN_00473f50.c

Verification:
- ✅ Calls FUN_00466d60(1)
- ✅ Sets *param_1 = &PTR_FUN_005a33c0
- ✅ Sets param_1[199] = &DAT_007cfc68
- ✅ Sets param_1[0xc9] = 2, [0xca] = 0, [0xcb] = 1, [0xcc] = 1, [0xcd] = 0x182
- ✅ Calls FUN_00486f30 three times
- ✅ Moddability: hookable — correct

---

## 1786. FUN_005994BC — Object Initialization with Buffer/Bounds Setup

**PASS**

Doc: docs/01-engine-architecture.md (line 12874, ## entry)
Source: analyzed\0x005994bc__FUN_005994bc.c

Verification:
- ✅ Sets param_1+0x48 = (param_3 == 1) — bool flag
- ✅ If param_3 == 0: calls FUN_00598c70, potentially FUN_00598c1c, sets +0x44 = 0
- ✅ Calls FUN_0059a4c9()
- ✅ If param_2 != 0 AND flag == 0: sets +0x1c, +0x0c, +0x10, +0x20, +0x2c, +0x30
- ✅ Sets +0x50 = param_2, +0x40 = DAT_008d5a68, +0x38 = 0, +0x3c = DAT_008d5a68

---

## 1787. FUN_00564780 — Function Pointer Call with Error Handling

**PASS**

Doc: docs/01-engine-architecture.md (line 13439, ## entry)
Source: analyzed\0x00564780__FUN_00564780.c

Verification:
- ✅ Calls function pointer at param_1+0xc
- ✅ Calls FUN_00564a20(param_1+0x10, 0, 0) — buffer index computation
- ✅ If result == -1: calls FUN_005648c0 (error path)
- ✅ Else: calls FUN_005649d0(iVar1) (success path)
- ✅ Struct offsets: +0x0c (code*), +0x10 (undefined4) — correct

---

## 1788. FUN_0059CA10 — SEH Unwind (Free EBP-0x10)

**PASS** (SEH unwind handler — trivial verification)

Doc: docs/01-engine-architecture.md (line 13791, ## entry)
Source: analyzed\0x0059ca10__Unwind_0059ca10.c

Verification:
- ✅ Frees *(unaff_EBP + -0x10) via FUN_00587bcf
- ✅ Standard MSVC SEH unwind pattern

---

## 1789. FUN_004698C0 — Destructor with Sub-Object Free

**PASS**

Doc: docs/01-engine-architecture.md (line 14013, ## entry)
Source: analyzed\0x004698c0__FUN_004698c0.c

Verification:
- ✅ If *(param_1+0x180) != 0: frees via FUN_00587bcf
- ✅ Calls FUN_00489440()
- ✅ If (param_2 & 1) != 0: frees param_1 via FUN_00587bcf

---

## 1790. FUN_004B5760 — Linked List Iterator with State Update

**PASS**

Doc: docs/01-engine-architecture.md (line 14236, ## entry)
Source: analyzed\0x004b5760__FUN_004b5760.c

Verification:
- ✅ Walks linked list from param_1+0x20
- ✅ For each node: checks state via FUN_005001d0/FUN_005001f0/FUN_00500210
- ✅ Writes to value+0x370
- ✅ Calls FUN_00410f60()

---

## 1791. FUN_005388D0 — Frequency Table Construction

**PASS**

Doc: docs/01-engine-architecture.md (line 14456, ## entry)
Source: analyzed\0x005388d0__FUN_005388d0.c

Verification:
- ✅ Builds frequency table from 16-entry short array (asStack_20, loop to 0x10)
- ✅ Iterates up to param_2
- ✅ Updates frequencies in table
- ✅ Algorithm family: frequency table / Huffman coding — plausible

---

## 1792. FUN_00583530 — Zero-Fill Memory Region with Step

**PASS**

Doc: docs/01-engine-architecture.md (line 14867, ## entry)
Source: analyzed\0x00583530__FUN_00583530.c

Verification:
- ✅ Calls FUN_00586000(param_1, 1) — pre-init
- ✅ Loop: iVar1 from 0 to < 0x2078, step 0x103c
- ✅ Calls FUN_00583210(*param_1 + iVar1, 0) — zero-fill each block
- ✅ Total: 2 blocks of 0x103c = 0x2078 bytes

---

## 1793. FUN_00583570 — List Destruction with COM Release

**PASS**

Doc: docs/01-engine-architecture.md (line 15346, ## entry)
Source: analyzed\0x00583570__FUN_00583570.c

Verification:
- ✅ Walks list from *param_1
- ✅ For each node: calls FUN_0058a5f7 with params (iVar3, 0x103c, *(iVar3-4), FUN_0047aa60)
- ✅ Frees sub-object and node via FUN_00587bcf
- ✅ Zeros list head (4 DWORDs)
- ✅ Allocation header at -4 offset

---

## 1794. FUN_0059C50E — SEH Unwind: Free Object at EBP-0x3C

**PASS** (SEH unwind handler — trivial verification)

Doc: docs/01-engine-architecture.md (line 15706, ## entry)
Source: analyzed\0x0059c50e__Unwind_0059c50e.c

Verification:
- ✅ Frees *(unaff_EBP + -0x3c) via FUN_00587bcf
- ✅ Standard MSVC SEH unwind pattern

---

## 1795. FUN_0059D3F0 — SEH Unwind: Conditional Call FUN_00599be5

**PASS** (SEH unwind handler — trivial verification)

Doc: docs/01-engine-architecture.md (line 16109, ## entry)
Source: analyzed\0x0059d3f0__Unwind_0059d3f0.c

Verification:
- ✅ Checks bit 0 of *(unaff_EBP + -0x10)
- ✅ If set: calls FUN_00599be5

---

## 1796. FUN_0059C620 — SEH Unwind: Free Object at +8

**PASS** (SEH unwind handler — trivial verification)

Doc: docs/01-engine-architecture.md (line 16468, ## entry)
Source: analyzed\0x0059c620__Unwind_0059c620.c

Verification:
- ✅ Frees *(unaff_EBP + 8) via FUN_00587bcf

---

## 1797. FUN_0059CB28 — SEH Unwind Free Object at +4

**PASS** (SEH unwind handler — trivial verification)

Doc: docs/01-engine-architecture.md (line 16813, ## entry)
Source: analyzed\0x0059cb28__Unwind_0059cb28.c

Verification:
- ✅ Frees *(unaff_EBP + 4) via FUN_00587bcf

---

## 1798. FUN_004FAD00 — VidMan::Exit()

**PASS**

Doc: docs/01-engine-architecture.md (line 17165, ### entry)
Source: decompiled_all\0x004fad00__FUN_004fad00.c

Verification:
- ✅ Logs "Entered VidMan::Exit()" from vidman.cpp line 0x5b1
- ✅ Calls FUN_00494900 (texture manager cleanup)
- ✅ Calls FUN_0055c040 (specialized renderer shutdown)
- ✅ Calls FUN_004a1830 twice (memory cleanup) with FUN_004a14e0 in between (scene object release)
- ✅ If DAT_008afe64 != 0: calls FUN_0053d4c0 and sets to 0
- ✅ Globals: DAT_008afe64 — display device handle

---

## 1799. FUN_0046D6D0 — Game Mode / Menu State Router

**PASS**

Doc: docs/01-engine-architecture.md (line 17474, ## entry)
Source: analyzed\0x0046d6d0__FUN_0046d6d0.c

Verification:
- ✅ Calls FUN_004186a0 (frame start/pre-update)
- ✅ Switch on DAT_007d0410 (RaceMode)
- ✅ Cases 1-3: "SELECTCIRCUITPAGE" via FUN_00486aa0
- ✅ Case 4: calls FUN_004a0630, "CH_RESUME" page
- ✅ Case 5: multiplayer path — calls FUN_00461cd0, if == 3 shows "MPCLIENTGRID" via FUN_00497940
- ✅ Calls FUN_00461550, FUN_004627c0, FUN_00461900
- ✅ Allocates via vtable+0x1c(0x18), calls FUN_00477640/FUN_00477680
- ✅ Sets DAT_005cc9e8 = 1
- ✅ Default: returns 0
- ✅ All globals listed correctly

---

## 1800. FUN_004883D0 — UI TextBox Renderer with Scrollbar

**PASS**

Doc: docs/01-engine-architecture.md (line 17900, ## entry)
Source: analyzed\0x004883d0__sub_4883D0.c (IDA Hex-Rays, 299 lines)

Verification:
- ✅ Allocates scrollbar control via sub_486460(1)
- ✅ Measures text content height vs visible area
- ✅ If text taller than box: enables scrollbar, computes scroll offset
- ✅ Renders text block with sub_494A30 using scroll offset + visible rect
- ✅ Second pass: allocates scrollbar thumb via sub_486460(2), computes position/size
- ✅ Clips output rects to scrollbar dimensions (a2-a5 clip bounds)
- ✅ Renders text label (this[44] string) using sub_4983B0 measure, sub_4981F0 background
- ✅ Renders optional secondary element (this[46] string)
- ✅ Calls virtual cleanup at vtable+172
- ✅ Globals: byte_5EA438 — correct
- ✅ Calls list comprehensive and matching IDA source

---

## 1801. FUN_0042B8C0 — Stub to Nullsub

**PASS**

Doc: docs/01-engine-architecture.md (line 18275, ## entry)
Source: analyzed\0x0042b8c0__sub_42B8C0.c (IDA Hex-Rays, 10 bytes)

Verification:
- ✅ Calls nullsub_3(&unk_5EC6D0) — no-op stub
- ✅ Returns result (always 0 from nullsub)
- ✅ Globals: unk_5EC6D0
- ✅ Moddability: hookable — correct (stub can be replaced)

---

## Summary

| Result | Count | Details |
|--------|-------|---------|
| **PASS** | 45 | All claims verified against source |
| **FAIL** | 1 | FUN_00413820 — level range claimed 0-17 but actual is 1-17; missing raw constant thresholds |
| **Total** | 46 | |

**Accuracy rate:** 45/46 = 97.8%
