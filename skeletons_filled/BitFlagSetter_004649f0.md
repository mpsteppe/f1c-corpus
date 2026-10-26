## BitFlagSetter_004649f0 — Bit 7 flag setter/clearer

**Summary:** Sets or clears bit 7 (0x80) of byte at this, based on a2. If a2 nonzero, sets bit 7; if zero, clears bit 7. Returns a2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DispatchWrapper (00464ad0), FloatComputation (00464b40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709551488 | Byte whose bit 7 is set or cleared |

**Written-by note (persistence):**
- this 0x0: unconditionally modified each call; bit 7 set or cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always sets bit 7 if a2 nonzero, clears it if zero.
