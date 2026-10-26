## TwoFieldSetter_9d10_004c9d10 — SpecialFxFieldInit

**Summary:** Initializes two fields of a special FX object: offset 0x20 set to -1.0f (sentinel/inactive) and offset 0x24 set to 0. Called during SpecialFX_Init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | 18446744072627421184 → -1.0f | Field initialized to -1.0f sentinel value (inactive/idle state) |
| this | 0x24 | RW | 0 | Field initialized to 0 (state/counter cleared) |

**Written-by note (persistence):**
- this 0x20: Written once with -1.0f. Survives unless another function modifies it.
- this 0x24: Written once with 0. Survives unless another function modifies it.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always writes both fields unconditionally.
