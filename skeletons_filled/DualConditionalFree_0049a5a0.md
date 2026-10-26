## DualConditionalFree_0049a5a0 — DualConditionalFree

**Summary:** Conditionally frees two pointer fields at offsets 0x04 and 0x0C via FreeWrapper_7bcf if non-NULL. Returns the result of the last free call or 0 if none fired.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiListDestructorWithCleanup (00486080)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | first pointer field freed if non-NULL |
| this | 0xC | R | — | second pointer field freed if non-NULL |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free wrapper for each non-NULL pointer |

**Guard conditions:** this+12 (offset 0x0C) checked non-NULL — if non-NULL, free and capture result. this+4 (offset 0x04) checked non-NULL — if non-NULL, free and return result. Both independent.
