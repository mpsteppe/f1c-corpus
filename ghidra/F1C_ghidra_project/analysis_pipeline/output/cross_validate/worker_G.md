# Cross-Validation Audit — Worker G

## FUN_004B4B50 — PASS

## FUN_004497E0 — PASS

## FUN_0044D850 — PASS

## FUN_00469DD0 — PASS

## FUN_0044C620 — PASS

## FUN_0044E150 — PASS

## FUN_0044EB40 — PASS

## FUN_0044CF20 — PASS

## FUN_0044E2D0 — PASS

## FUN_0044D640 — PASS

## FUN_0044D0A0 — PASS

## FUN_0044E450 — PASS

## FUN_0044D7C0 — PASS

## FUN_0044D220 — PASS

## FUN_0044E5D0 — PASS

## FUN_0044D790 — PASS

## FUN_0044DEB0 — PASS

## FUN_00491170 — PASS

## FUN_00438130 — PASS

## FUN_0052B561 — PASS

## FUN_0056BAF0 — PASS

## FUN_00430A50 — PASS

## FUN_004317F0 — PASS

## FUN_00431C60 — PASS

## FUN_00434450 — PASS

## FUN_00438CA0 — PASS

## FUN_00431A70 — PASS

## FUN_0043EA70 — PASS

## FUN_004380B0 — PASS

## FUN_004FB260 — PASS

## FUN_00426330 — PASS

## FUN_00548810 — PASS

## FUN_004EB430 — PASS

## FUN_004583B0 — PASS

## FUN_00489970 — PASS

## FUN_0048F9F0 — PASS

## FUN_004983B0 — PASS

## FUN_00462550 — PASS

## FUN_0050AFE2 — PASS

## FUN_0049ED30 — PASS

## FUN_0050EE0B — PASS

## FUN_0048CCB0 — PASS

## FUN_0051A9C6 — PASS

## FUN_0040FB30 — PASS

## FUN_0050B7CB — PASS

## FUN_0054FCC0 — PASS

## FUN_00519361 — FAIL
Source: docs/19-renderer.md

**Errors:**
- [WRONG_DEREF] Doc says "*(param_1 + 0x14)" but source shows `*(*param_1 + 0x14)` — missing one level of indirection. Sets param_1's POINTEE offset 0x14, not param_1's own offset 0x14.

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00519361 — Render State Set (0x30)

Source: renderer. Sets state code 0x30 on referenced object and dispatches via vtable.

**Key logic:**
- Sets `*(*param_1 + 0x14) = 0x30` (state code on dereferenced object)
- Calls virtual method through `*param_1`

**Calls:** Virtual dispatch through *param_1

**Moddability:** hardcoded

## FUN_0050C97A — PASS

## FUN_00554700 — PASS

## FUN_004967D0 — PASS

## FUN_00470AF0 — PASS

## FUN_004D7FA0 — PASS

## FUN_004144C0 — PASS

## FUN_0059B650 — PASS

## FUN_00593E1B — PASS

## FUN_0059491A — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_DESC] Description "CRT locale-dependent ctype table rebuild (isalpha, isdigit, etc.)" is wrong — function is a virtual memory page allocator using VirtualAlloc/HeapAlloc for 0x400000-byte regions with 0xf0-tagged page entries

**Corrected entry:**
<!-- target: docs/20-math-utilities.md -->
## FUN_0059491A — Virtual Memory Page Allocator

Source: memory subsystem. Allocates 4MB virtual memory region and initializes page tracking table.

**Key logic:**
- Allocates 0x2020-byte HeapAlloc tracking structure (or uses static PTR_LOOP_005e7968)
- Calls VirtualAlloc(NULL, 0x400000, 0x2000, 4) for 4MB region
- Calls VirtualAlloc(lpAddress, 0x10000, 0x1000, 4) for guard/commit page
- Initializes 0x400 tracking entries with 0xf1 tag
- Sets up page-free linked list within the 4MB region (0xf0 tag, 0x400-byte stride)
- Returns tracking structure pointer or 0 on failure

**Calls:** HeapAlloc, VirtualAlloc (×2), _memset, VirtualFree, HeapFree

**Moddability:** hardcoded

## FUN_00590246 — PASS

## FUN_0055C450 — PASS


Source: docs/19-renderer.md

**Errors:**
- [WRONG_DESC] Description "Direct3DCreate8 import wrapper" is inaccurate — function is a generic buffer/index pair allocator, no Direct3D calls

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0059B2F0 — Generic Buffer and Index Array Allocator

Source: memory/utility. Allocates a main buffer and an index array, zeroes both, returns initialized struct.

**Key logic:**
- Allocates buffer of param_2 bytes, zeroes it (by dword then byte)
- Allocates index array of param_4 × 2 shorts, zeroes each pair
- Sets param_1[0]=buffer, [1]=size, [2]=indexptr, [3]=count, [6]=max(param_3,1), [7]=max(param_5,1)

**Calls:** operator_new (twice)

**Moddability:** hardcoded

## FUN_00595DC8 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [MISSING_ANALYSIS] Raw decompilation dump — no human-readable analysis
- [MISCATEGORIZATION] String encoding function, not math utility
- [NO_MODDABILITY] Missing
- [MISSING_CALLS] Calls GetStringTypeW, MultiByteToWideChar, GetStringTypeA, FUN_005881c0 not documented

**Corrected entry:** (see worker_G_math1.md for full)

## FUN_0058B92A — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [MISSING_ANALYSIS] Raw decompilation dump
- [MISCATEGORIZATION] Filesystem path resolver, not math utility
- [MISSING_CALLS] Calls GetCurrentDirectoryA, GetFullPathNameA, _malloc not documented

## FUN_0055D460 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [MISSING_ANALYSIS] Raw decompilation dump
- [MISSING_GLOBALS] Uses _DAT_0059e430, _DAT_0059e43c, DAT_008b8f28 not documented
- [MISSING_CALLS] Calls FUN_005416a0 not documented

## FUN_00534AAC — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [MISCATEGORIZATION] Miles Sound System audio thunk, not math utility

## FUN_0045B300 — PASS

## FUN_0050C4BB — PASS

## FUN_00596DFE — PASS

## FUN_00418AC0 — PASS

## FUN_004761E0 — PASS

## FUN_0048FEB0 — PASS

## FUN_004B32A0 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_DESC] G/B extraction oversimplified — involves masking/shifting packed format
- [MISSING_CALLS] 8 called sub-functions not listed

## FUN_004F1A60 — PASS

## FUN_0052E550 — PASS

## FUN_005862C0 — PASS

## FUN_0058F6C7 — PASS

## FUN_004562A0 — PASS

## FUN_0047A8F0 — PASS

## FUN_0049BAD0 — PASS

## FUN_004C9960 — PASS

## FUN_0050FF84 — PASS

## FUN_00556220 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_CONST] Doc claims "13 dwords" zeroed; source zeroes 17 dwords (skips index 1)

## FUN_0055F080 — PASS

## FUN_004766F0 — PASS

## FUN_004D4A50 — PASS

## FUN_00568E30 — PASS

## FUN_0059A854 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_CONST] Vtable address wrong: doc PTR_FUN_005b7e34, source PTR_LAB_005b9ce4
- [WRONG_CALL] param_2 omitted from sub-call

## FUN_0045D240 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [MISSING_CALLS] FUN_00561f60, FUN_00561f80 not documented
- [MISSING_RETURN] Always returns 1, not documented

## FUN_00486010 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_CONST] Doc claims all fields zeroed; byte at +0x65 set to 1

## FUN_0049CFC0 — FAIL
Source: docs/20-math-utilities.md

**Errors:**
- [WRONG_DESC] Fabricated "Sets size, format for each slot" — speculative render target claim unsupported by source

## FUN_004C8D80 — PASS

## FUN_0050B260 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [MISSING_ARGS] Doc omits args (8,1) from FUN_00507496 call

## FUN_0055BE20 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_RETURN] Claims returns copy status; function is void

## FUN_00465C70 — PASS

## FUN_0040BCD0 — PASS

## FUN_00596840 — PASS

## FUN_0049AA10 — PASS

## FUN_004C81A0 — PASS

## FUN_0050A7C5 — PASS

## FUN_0053D4C0 — PASS

## FUN_00593446 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [MISSING_CALLS] Missing preconditions on vtable dispatch, missing else-if branch with FUN_0059379b

## FUN_0040D470 — PASS

## FUN_0046A970 — PASS

## FUN_0048F590 — PASS

## FUN_004B21C0 — PASS

## FUN_004DD400 — PASS

## FUN_0054B3B0 — PASS

## FUN_005642F0 — PASS

## FUN_00567780 — PASS

## FUN_00464AD0 — PASS

## FUN_0048B420 — PASS

## FUN_004A3570 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [MISSING_CALLS] Missing FUN_004a2840(0) call in bit-0 reset loop

## FUN_004D5984 — PASS

## FUN_0050EDD2 — PASS

## FUN_00549020 — PASS

## FUN_0059CDC0 — PASS

## FUN_00462370 — PASS

## FUN_00512319 — PASS

## FUN_005906BB — PASS

## FUN_00455260 — PASS

## FUN_0047A000 — PASS

## FUN_004998E0 — PASS

## FUN_004C1E20 — PASS

## FUN_00500161 — PASS

## FUN_0053AD50 — PASS

## FUN_00587DB0 — PASS

## FUN_00409970 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_DESC] Claims float self-copy at +0x18; source shows conditional multi-function call with 5 sub-calls

## FUN_005507A0 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_CONST] Title says "7 Fields" but source zeroes 8 dwords (indices 0-7)

## FUN_0053B0D0 — PASS

## FUN_004D7DD0 — PASS

## FUN_004A6FF0 — PASS

## FUN_0048D0D0 — PASS

## FUN_00461560 — PASS

## FUN_004B9AC0 — PASS

## FUN_004EA930 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [PARTIAL] Placeholder entry; source has 21 lines of clear 3D vector subtraction

## FUN_00520FC6 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [PARTIAL] Placeholder entry; source has 55 lines packed SSE vector normalization

## FUN_00567010 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [PARTIAL] Placeholder "1 line" — source has 13 lines with 2 sub-calls

## FUN_00559760 — PASS

## FUN_0059CC9E — PASS

## FUN_004582A0 — PASS

## FUN_0047BE00 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_DIRECTION] Condition inverted: doc says "if count exceeds val" but source calls when count <= val

## FUN_00499E40 — PASS

## FUN_004C2FA0 — PASS

## FUN_00502BF4 — PASS

## FUN_0053C200 — PASS

## FUN_0058E0B4 — PASS

## FUN_0059CCC0 — PASS

## FUN_0045C3D0 — PASS

## FUN_00485870 — PASS

## FUN_0049AEC0 — PASS

## FUN_004C8580 — PASS

## FUN_0050AE3E — PASS

## FUN_00540050 — PASS

## FUN_0059553A — PASS

## FUN_0059A43C — PASS

## FUN_00461C70 — PASS

## FUN_00487260 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [WRONG_LOGIC] Case 4 logic wrong — vtable call happens on both branches after FUN_00487740, not only "if both false"

## FUN_0049F750 — PASS

## FUN_004CF040 — PASS

## FUN_0050D57F — PASS

## FUN_00547AF0 — PASS

## FUN_0059D928 — PASS

## FUN_00418940 — PASS

## FUN_00486500 — PASS

## FUN_0049E410 — PASS

## FUN_004C92B0 — PASS

## FUN_0050C2A6 — PASS

## FUN_00544F50 — PASS

## FUN_0055BB50 — PASS

## FUN_0045C780 — PASS

## FUN_004BD760 — PASS

## FUN_005471C0 — PASS

## FUN_0058C411 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [MISSING_CALLS] Missing FUN_0058aa6f (buffer free) from Calls section

## FUN_004C7C30 — PASS

## FUN_005864E0 — PASS

## FUN_0045C850 — PASS

## FUN_004875F0 — PASS

## FUN_0049FFC0 — PASS

## FUN_004D0080 — PASS

## FUN_0050D6AC — PASS

## FUN_00547240 — PASS

## FUN_0059C4AA — PASS

## FUN_0040E2B0 — PASS

## FUN_0046CB10 — PASS

## FUN_0048FE60 — PASS

## FUN_004B2930 — PASS

## FUN_004DC290 — PASS

## FUN_005159A8 — PASS

## FUN_005545E0 — PASS

## FUN_0040DBE0 — PASS

## FUN_00470230 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [MISSING_CALLS] Doc says "forwards call, no additional logic" but source sets vtable AND calls FUN_0048b420(0,0,0,0,1,0)

## FUN_00495B60 — FAIL
Source: docs/20-math-utilities.md
**Errors:** [PARTIAL] Stub "General utility function"; source has specific 4-iteration loop with conditional copy using FUN_00499a70/FUN_00499a00

## FUN_0059C5B2 — PASS

## FUN_0059D45C — PASS

## FUN_0059CB60 — PASS

## FUN_0050CBA3 — PASS

## FUN_0059CF03 — PASS

## FUN_0059CFDA — PASS

## FUN_00584CD0 — PASS

## FUN_0059A54D — PASS

## FUN_004FDEB0 — PASS

## FUN_00516A1D — PASS

## FUN_005642B0 — PASS

## FUN_0057C860 — PASS

## FUN_0057FBE0 — PASS

## FUN_004117B0 — PASS

## FUN_00564740 — PASS

