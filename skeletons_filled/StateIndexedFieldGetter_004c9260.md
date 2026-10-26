## StateIndexedFieldGetter_004c9260 — StateIndexedFieldGetter

**Summary:** Indexed field selector: reads selector at this+0x1C (0/1/2) and returns the corresponding value at this+0x20/0x24/0x28. Returns 0 for out-of-range index.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EqualityStateCheck (004c9280), ObjectPropertySetter (004c92b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | Index selector (0, 1, or 2) |
| this | 0x20 | R | — | Return value when index == 0 |
| this | 0x24 | R | — | Return value when index == 1 |
| this | 0x28 | R | — | Return value when index == 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this+0x1C selects the field: 0 → this+0x20, 1 → this+0x24, 2 → this+0x28. Any other value returns 0.
