## UIControlStateChangeHandler_00487960 — UIControl state change handler with string validation

**Summary:** UI control state change handler: if enabled flag at 0xE0 is set, normalizes string from this+0xA0 (with base from this+0x40), compares against string at this+0xA8, dispatches via StateDependentVTableDispatch_7760 based on comparison, and notifies on state change.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InitDispatchWithVTableCheck (004879e0), sub_487D50 (00487d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | validation state field updated by StateDependentVTableDispatch_7760 |
| this | 0x0 | R | — | vtable pointer for virtual notification call |
| this | 0x40 | R | — | base offset for string normalization lookup (added +5772 for lookup context) |
| this | 0xA0 | R | — | first string path/reference for normalization |
| this | 0xA8 | R | — | second string path/reference for comparison |
| this | 0xE0 | R | — | enable flag; if zero, entire handler body is skipped |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory string used as fallback when string fields are null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487720 | ShortComputation_7720 | computes current state value for change detection |
| 00487760 | StateDependentVTableDispatch_7760 | dispatches state machine logic based on string comparison result |
| 0049a460 | StringNormalizeLookup_a460 | normalizes/looks up string path to canonical form |
| 00588410 | sub_588410 | compares normalized string against target path (returns 0 if match) |

**Guard conditions:** this+0xE0 byte == 0 — BLOCKS entire handler body (feature disabled). If non-zero, proceeds with validation logic. StringNormalizeLookup_a460 returns 0 — BLOCKS comparison and StateDependentVTableDispatch_7760 call.
