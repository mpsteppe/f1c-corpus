## sub_58DE2C_0058de2c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_588212 (00588212), FPUFSaveWrapper (0058da35)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8c80 | dbl_5B8C80 | R | CRTHandleBoundary [DERIVED] |
| 005b8cc8 | dbl_5B8CC8 | R | DoubleZero [DERIVED] |
| 005e7718 | dbl_5E7718 | R | MathTableBoundary_5E7640 [DERIVED] |
| 005e7720 | dbl_5E7720 | R | CRP_MathConst [DERIVED] |
| 005e7738 | dbl_5E7738 | R | MathConstDouble [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058df5c | DoubleIntegerAndDivisibilityClassification | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
