## SimpleSetter_0040cdd0 — SimpleFieldSetter

**Summary:** Writes argument a2 into this+0x8 and returns it. Trivial setter/assignment helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionPhaseDispatchWithCascadeChecks (0040d1b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | field written with a2 and returned |

**Written-by note (persistence):**
- this 0x8: set to argument a2 on each call; overwritten on each invocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional write
