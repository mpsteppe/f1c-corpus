## ShortArrayInit_00411680 — ShortPairArrayInitializer

**Summary:** Initializes an array of 537 word-pairs to (1, 0). Each iteration sets two consecutive words: first to 1 (enabled flag), second to 0 (counter/index). No guard conditions; always processes all 537 elements.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_84b0 (004184b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | first word of each pair: initialized to 1 (enabled/active flag) |
| this | 0x2 | RW | 0 | second word of each pair: initialized to 0 (counter/state) |

**Written-by note (persistence):**
- this 0x0: set to 1 for all 537 entries each call
- this 0x2: set to 0 for all 537 entries each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional loop of 537 iterations
