## ConditionalCleanupChain_0040f100 — ConditionalCleanupChain

**Summary:** Guarded cleanup chain: if ID field is not -1, runs helper subroutine, arithmetic comparison, and cleanup. Part of widget/scene object lifecycle system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LoopWithConditionalSkipFunction (00410980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | ID/identifier field; -1 (0xFFFFFFFF) = skip, anything else = proceed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410af0 | sub_410AF0 | Helper subroutine operating on this |
| 004bdf90 | ArithmeticComparison_df90 | Arithmetic comparison operation on this |
| 004be010 | sub_4BE010 | Cleanup subroutine after processing |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | != | 18446744073709551615 | ID field; -1 (0xFFFFFFFF) |

**Guard interpretation:** this[0] == -1 (0xFFFFFFFF) → skip (blocked). this[0] != -1 → helper + comparison + cleanup (passes through).
