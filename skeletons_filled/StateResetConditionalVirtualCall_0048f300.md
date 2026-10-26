## StateResetConditionalVirtualCall_0048f300 — StateFlagResetWithVirtualDispatch

**Summary:** Resets byte flags at offsets 0x17D and 0x17E to zero. If state field at offset 0x104 is NOT equal to 4, resets it to 0 and invokes virtual method at vtable+64 with argument 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListTraversalVirtualCall (00477160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | virtual dispatch offset |
| this | 0x0 | R | — | vtable pointer |
| this | 0x104 | RW | 0 | state flag compared against value 4 |
| this | 0x17D | RW | 0 | byte flag reset to 0 |
| this | 0x17E | RW | 0 | byte flag reset to 0 |

**Written-by note (persistence):**
- this 0x104: reset to 0 if not equal to 4; preserved if equal to 4
- this 0x17D: unconditionally set to 0
- this 0x17E: unconditionally set to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- Byte flags at 0x17D and 0x17E: unconditionally zeroed (always PASS)
- if (this[65] != 4) → PASS (reset state to 0 and call virtual at vtable+64)
- if (this[65] == 4) → BLOCKED (skip reset and virtual call)
