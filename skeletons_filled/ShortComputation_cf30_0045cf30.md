## ShortComputation_cf30_0045cf30 — Replace backslash with underscore in string

**Summary:** Iterates through a null-terminated string, replacing every backslash character (0x5C = 92) with underscore (0x5F = 95) in-place. Returns the last character processed (or 0 for empty string).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_ce30 (0045ce30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 95 | Current character in string — replaced if it equals 92 (backslash) |
| this | 0x1 | R | — | Next character in string (lookahead for loop termination) |

**Written-by note (persistence):**
- this 0x0: each character overwritten in-place if it matches backslash; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always processes entire null-terminated string
