## F_6FieldBulkSetter_00459990 — SixFieldBulkSetter

**Summary:** Bulk-setter that writes six DWORD parameters (a2-a7) into six contiguous fields of a struct at offsets 0x28 through 0x3C (indices 10-15). Used for initializing grouped float/int configuration values.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StructInitWithFloatConstantsAndSubCalls (0040e8f0), StructInitWithFloatConstantsAndSubCalls_e990 (0040e990), sub_40EA30 (0040ea30), CameraProjectionMatrixInitWithFloatConstants (0040eb30), UtilityFunction_ebd0 (0040ebd0), StructInitializerWithFloatConstants (0040ec70), SwitchBasedFloatProcessing (0040eec0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | — | First bulk-set field (index 10, value from a2) |
| this | 0x2C | RW | — | Second bulk-set field (index 11, value from a3) |
| this | 0x30 | RW | — | Third bulk-set field (index 12, value from a4) |
| this | 0x34 | RW | — | Fourth bulk-set field (index 13, value from a5) |
| this | 0x38 | RW | — | Fifth bulk-set field (index 14, value from a6) |
| this | 0x3C | RW | — | Sixth bulk-set field (index 15, value from a7) |

**Written-by note (persistence):**
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — unconditionally writes all six parameters into struct fields.
