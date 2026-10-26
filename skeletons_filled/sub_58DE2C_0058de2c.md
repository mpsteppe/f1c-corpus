## sub_58DE2C_0058de2c — Double special-case classifier for binary math operation

**Summary:** CRT math helper that classifies special IEEE 754 double values (infinity, NaN, zero, one, compared to 1.0) for a binary double operation. Computes one of several constant results based on the combination of input classifications and returns a flag indicating whether the result is a special case.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_588212 (00588212), FPUFSaveWrapper (0058da35)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8c80 | dbl_5B8C80 | R | CRT handle boundary constant |
| 005b8cc8 | dbl_5B8CC8 | R | Double zero constant |
| 005e7718 | dbl_5E7718 | R | Infinity-like result constant for |x|≠1 special cases |
| 005e7720 | dbl_5E7720 | R | 1.0 result constant for |x|==1 case |
| 005e7738 | dbl_5E7738 | R | Negative-result constant for -inf with negative integer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058df5c | DoubleIntegerAndDivisibilityClassification | Classify a2 as integer and test divisibility (for -inf base case) |

**Guard conditions:** Uses FPU condition-code flag (v6 from prior compare) to determine if a1 is negative and takes absolute value. Compares a2 exponent against 0x7FF (infinity/NaN pattern). When a2 is ±infinity: classifies |a1| relative to 1.0 (>1, ==1, <1). When a2 is finite but a1 is -infinity: classifies a2 sign and integer-ness via DoubleIntegerAndDivisibilityClassification to select result constant.
