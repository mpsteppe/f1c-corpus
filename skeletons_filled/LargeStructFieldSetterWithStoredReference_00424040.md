## LargeStructFieldSetterWithStoredReference_00424040 — StoreReferenceAtTwoOffsets

**Summary:** Stores input value a2 at this[0] and this[4109] (offset 0x4034), calls propagation function, returns result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleObjectConstructor (004c6920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | postProcessInput [CONFIRMED] |
| this | 0x4034 | RW | — | Duplicate storage of same input value at distant offset |

**Written-by note (persistence):**
- this 0x0: written every call with input a2; external poke overwritten on next call
- this 0x4034: written every call with same input a2; external poke overwritten on next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e4590 | F_4FieldPropagation | Propagate the stored input value to related fields/subsystems |

**Guard conditions:** No guard conditions — unconditional stores and return.
