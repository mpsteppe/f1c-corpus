## BitfieldSetClearAt0x88_004614f0 — BitfieldSetOrClearAt0x88

**Summary:** Sets or clears specific bits in a byte field at this+0x88 based on a boolean control parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetComm_SetSelfAsReady (00460520), ConditionalRenderStateUpdate (00460710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x88 | RW | — | Bitfield byte storing flag bits |

**Written-by note (persistence):**
- this 0x88: modified each call; bits survive until explicitly cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no guard, always executes. When a3=1: ORs a2 bits into field. When a3=0: ANDs ~a2 bits (clears them).
