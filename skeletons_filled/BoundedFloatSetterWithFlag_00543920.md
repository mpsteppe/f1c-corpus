## BoundedFloatSetterWithFlag_00543920 — BoundedFloatSetterWithFlag

**Summary:** Stores a float value (offset 0x190) clamped to range [0.0, 1.0] and sets the 0x10000 UI update flag. Values outside the valid range are silently rejected.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | flags/state field; bit 0x10000 set when value is valid |
| this | 0x190 | RW | — | bounded float value (clamped [0.0, 1.0]) |

**Written-by note (persistence):**
- this 0xEC: bit 0x10000 OR'd in when value is valid; other bits survive
- this 0x190: overwritten only when a2 is in [0.0, 1.0]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | constant 1.0 (upper bound) |
| 0059e430 | dbl_59E430 | R | constant ~0.0 (lower bound) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** BLOCKED when a2 < 0.0 or a2 > 1.0 → no write, no flag set.
