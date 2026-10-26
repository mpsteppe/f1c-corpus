## FAILCallChainSaysAccumulatesButFunctionZEROS0x94_00546430 — Conditional zero fields at 0x94 and 0x98

**Summary:** If flag bit 2 at this+0x9C is clear, zeros two fields at offsets 0x94 and 0x98. Despite call-chain name suggesting accumulation, this function only ever clears those fields. Resource manager state reset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListAccumulation (00548810)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x94 | RW | 0 | first zeroed field (accumulation counter, cleared here) |
| this | 0x98 | RW | 0 | second zeroed field (accumulation counter, cleared here) |
| this | 0x9C | R | — | flag byte: bit 2 guards zeroing (if clear, zero; if set, skip) |

**Written-by note (persistence):**
- this 0x94: zeroed conditionally when bit 2 at 0x9C is clear
- this 0x98: zeroed conditionally when bit 2 at 0x9C is clear

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If bit 2 at this+0x9C is CLEAR, PASSES: both 0x94 and 0x98 are zeroed. If bit 2 is SET, BLOCKED: early return, fields unchanged.
