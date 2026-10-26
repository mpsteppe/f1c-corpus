## StateDependentUpdateDispatch_0040f130 — StateRangeCheckUpdateDispatch

**Summary:** Dispatches update processing on a UI/input object based on state range. Reads state field (offset 0x1C); only proceeds if state is 0-5. Inside, branches on sentinel check: if first DWORD is -1, calls NestedLoopCall; otherwise calls coordinate transform, sub_410AF0, and comparison. Always ends with sub_4BE010.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BatchProcessWithFixedStartOffsets (00410890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | sentinel/ID field; compared to -1 to select processing path |
| this | 0x1C | R | — | state field; values 0-5 pass the guard, any other value skips |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f19c | jpt_40F13B | R | jump table for switch on state field (all cases 0-5 collapse to same path) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] — unknown usage (passed to callees) |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] — unknown usage (passed to callees) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410af0 | sub_410AF0 | processing when object is NOT in sentinel state |
| 00459830 | FloatDoubleCoordinateTransform | transforms coordinate data at this+0xC (3rd field) |
| 004bdf90 | ArithmeticComparison_df90 | arithmetic/comparison on this object |
| 004be010 | sub_4BE010 | final processing step always executed after main branch |
| 004be180 | NestedLoopCall | processing when object IS in sentinel state (*this == -1) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 18446744073709551615 | sentinel/ID at this+0 compared to -1 (0xFFFFFFFF) |

**Guard interpretation:** if this[0] == -1 → sentinel path (NestedLoopCall). Else → normal path (sub_410AF0 + ArithmeticComparison_df90). Both branches converge on sub_4BE010.
