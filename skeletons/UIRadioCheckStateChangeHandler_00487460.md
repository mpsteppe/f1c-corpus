## UIRadioCheckStateChangeHandler_00487460 — Radio/check button state change handler with string validation

**Summary:** UI radio/check button state change handler: if enabled flag at 0xE0 is set, normalizes two string paths (from 0xA0 and 0xA8), compares them, updates validation state via sub_487260, and dispatches virtual notification if state changed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VirtualDispatchWithErrorHandling (00487530), VTableDispatch_7640 (00487640), UtilityFunction_7e10 (00487e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | validation state field updated by sub_487260 |
| this | 0x0 | R | — | vtable pointer for virtual notification call |
| this | 0xA0 | R | — | first string path/reference for normalization and comparison |
| this | 0xA8 | R | — | second string path/reference for comparison against normalized value |
| this | 0xE0 | R | — | enable flag; if zero, entire handler body is skipped |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory string used as fallback when string fields are null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487260 | sub_487260 | sets validation state on this object based on comparison result |
| 00487720 | ShortComputation_7720 | computes current state value for change detection |
| 0049a460 | StringNormalizeLookup_a460 | normalizes/looks up string path to canonical form |
| 00588410 | sub_588410 | compares normalized string against target path (returns 0 if match) |

**Guard conditions:** this+0xE0 byte == 0 — BLOCKS entire handler body (feature disabled). If non-zero, proceeds with validation logic. StringNormalizeLookup_a460 returns 0 — BLOCKS comparison + sub_487260 call.
