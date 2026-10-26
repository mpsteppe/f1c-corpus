## LongjmpMSVCCRT_0058a770 — CRTLongjmp

**Summary:** MSVC CRT `longjmp` implementation. Unwinds stack frames (global + SEH local) to the saved jmp_buf state, calls cleanup handler if cookie validates, then jumps to saved return point.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VTableDispatchWithLongjmp (005016e0), AssertFailHandler (00502102), GuardedCallWithLongjmp (00511869)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Saved EIP/return address from setjmp |
| this | 0x14 (a1[5]) | R | — | Return address for final longjmp target (passed to sub_58893A) |
| this | 0x18 (a1[6]) | R | — | Saved ESP / exception registration frame pointer for unwind |
| this | 0x1C (a1[7]) | R | — | Saved trylevel for SEH frame unwind |
| this | 0x20 (a1[8]) | R | — | Longjmp cookie magic (0x564D5343 or 'CMSV') |
| this | 0x24 (a1[9]) | R | — | Optional cleanup function pointer called before jump |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588864 | GlobalUnwind2 | Unwind global stack frames (RtlUnwind) if saved frame != current FS:0 |
| 005888a6 | MSVCRTSEHFrameUnwinder | Unwind local SEH scope table to saved trylevel |
| 0058893a | sub_58893A | Callback with saved return address and target for final jump |
| 00593d53 | EmptyStub_3d53 | Validate jmp_buf integrity (cookie check wrapper) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | == | 1447244336 | Longjmp cookie (0x564D5343) validating jmp_buf integrity |

**Guard interpretation:** Checks if saved frame (a1[6]) != current FS:0 (TEB exception list). If different, performs global unwind. Checks if a1[6] (frame) is non-null: if EmptyStub_3d53 returns true AND cookie at a1[8] == 0x564D5343, calls cleanup handler at a1[9] (PASS — structured longjmp with cleanup). Otherwise performs SEH frame unwind to a1[7] (LEGACY — plain longjmp without cookie).
