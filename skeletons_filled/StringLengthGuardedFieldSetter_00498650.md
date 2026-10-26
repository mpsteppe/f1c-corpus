## StringLengthGuardedFieldSetter_00498650 — Guarded String Copy With Field Set

**Summary:** Copies a non-empty string to an internal buffer and stores three associated integer values in adjacent fields. If the input is NULL or empty, returns 0 without modification.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1560 | RW | — | First associated integer (from parameter a3); written when string is valid |
| this | 0x1564 | RW | — | Second associated integer (from parameter a4) |
| this | 0x1568 | RW | — | Third associated integer (from parameter a5) |

**Written-by note (persistence):**
- this 0x1560: Written together with 0x1564/0x1568 when a2 is non-NULL and non-empty; persists until next successful call
- this 0x1564: Same as 0x1560
- this 0x1568: Same as 0x1560

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies string a2 into the buffer at this+0x1558 (via pointer), reallocating if necessary |

**Guard conditions:**
- `a2 == NULL` → return 0 (BLOCKED: no input string)
- `strlen(a2) == 0` → return 0 (BLOCKED: empty string)
- `a2 != NULL && strlen(a2) > 0` → copy string, store three integers, return a3 (PASSES)
