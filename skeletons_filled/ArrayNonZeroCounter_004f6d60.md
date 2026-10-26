## ArrayNonZeroCounter_004f6d60 — ArrayNonZeroCounter

**Summary:** Counts consecutive non-zero entries (max 5) from an array pointed to by `this[16]` (offset 0x40). Stores count in `*this` (offset 0x0). Returns when a zero entry is encountered or limit reached.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArithmeticComparison_8370 (004f8370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Counter of consecutive non-zero entries found |
| this | 0x40 | R | — | Pointer to array of entries to scan |

**Written-by note (persistence):**
- this 0x0: Overwritten each call with count; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop breaks early if `*v1 == 0` (zero entry found). Max 5 iterations.
