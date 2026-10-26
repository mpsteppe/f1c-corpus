## CoordinateBoundCheck_004b69f0 — Buffer Index Validity Check

**Summary:** Returns TRUE if either circular buffer index (write or read) is negative, indicating the buffer is in an uninitialized or invalid state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CircularBufferCheck (004b68c0), PitstopActionSet (004b6940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B8 | R | — | Current write index (checked for < 0) |
| this | 0x9BC | R | — | Read index (checked for < 0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x9B8 | < | 0 | Write index negative = invalid/uninitialized |
| this | 0x9BC | < | 0 | Read index negative = invalid/uninitialized |

**Guard interpretation:** Returns TRUE (buffer invalid) if write index < 0 OR read index < 0. Returns FALSE (buffer valid) only when both indices are >= 0.
