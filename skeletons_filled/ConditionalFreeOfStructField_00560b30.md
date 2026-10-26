## ConditionalFreeOfStructField_00560b30 — ConditionalFreeField

**Summary:** Free memory pointer at this[107] (offset 0x1AC) if non-null, then zero the field. Returns the old pointer value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1AC | RW | 0 | Pointer to allocated resource to free |

**Written-by note (persistence):**
- this 0x1AC: set to 0 after freeing; persists until next assignment

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free allocated memory |

**Guard conditions:** this[107] (offset 0x1AC) — if null, skip free and return null.
