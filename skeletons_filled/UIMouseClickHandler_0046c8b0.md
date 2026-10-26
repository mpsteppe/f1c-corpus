## UIMouseClickHandler_0046c8b0 — UIMouseClickHandler_0046c8b0

**Summary:** Mouse click handler for key binding UI. Reads dual-field values from this+64, looks up binding index via sub_489F40, removes existing binding and inserts new binding into array based on byte flag at 0x174.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | structure pointer passed to DualFieldRead |
| this | 0x174 | R | — | selector byte: controls which binding array to modify |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0046c7b0 | IndexedArrayInsertWithShift | inserts new key binding into array with shift |
| 00489f40 | sub_489F40 | looks up binding index from DualFieldRead values |
| 00498880 | DualFieldRead | reads two field values from structure at this+64 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x174 | == | 0 | selector byte for binding array selection |

**Guard interpretation:** v4 (index from sub_489F40) >= 0 → enters binding remove/insert path. BLOCKED if v4 < 0 → returns early. The byte at 0x174 is passed to IndexedArrayInsertWithShift to select array: == 0 means primary, != 0 means secondary.
