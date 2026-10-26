## StateResetWithZero_004662e0 — StateFieldResetAndCleanup

**Summary:** Calls ResourceCleanup, then zeros field at this+0xF0 (index 60). Returns 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_6140 (00466140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF0 | RW | 0 | field index 60, zeroed as part of reset |

**Written-by note (persistence):**
- this 0xF0: conditional (called during destructor path). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048e890 | ResourceCleanup | release attached resources |

**Guard conditions:** None — unconditional.
