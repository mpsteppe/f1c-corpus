## UtilityFunction_15c0_004615c0 — BitFlagSetOrClearAt0x6E

**Summary:** Sets or clears a bit at a bit-indexed position within byte field this+0x6E based on boolean control.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionConfigBuilder (00461610)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6E | RW | — | Bitfield byte at offset 0x6E |

**Written-by note (persistence):**
- this 0x6E: modified each call; bits survive until explicitly cleared

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no guard, always executes. When a3=1: sets bit at index a2. When a3=0: clears bit at index a2.
