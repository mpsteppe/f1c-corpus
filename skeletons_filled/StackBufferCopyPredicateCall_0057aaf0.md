## StackBufferCopyPredicateCall_0057aaf0 — StackBufferCopyAndPredicateCheck

**Summary:** Copies 48-byte buffer from a1 to stack, zeroes *a2, then calls sub_57ABB0 with all 12 DWORDs as individual args plus a2 pointer. Returns true if sub_57ABB0 returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_463E20 (00463e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | output parameter a2, zeroed before sub_57ABB0 call |

**Written-by note (persistence):**
- this 0x0: written once per call (set to 0); written value may be overwritten by sub_57ABB0 via pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d3bfa | unk_8D3BFA | R | unknown — not directly referenced in this function's C code |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057abb0 | sub_57ABB0 | predicate function called with stack buffer contents and a2 pointer |

**Guard conditions:** none — unconditional copy and call

