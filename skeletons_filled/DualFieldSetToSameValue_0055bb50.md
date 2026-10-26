## DualFieldSetToSameValue_0055bb50 — ZeroInitAndSetDualField

**Summary:** Calls GlobalZeroInit_c2a0 to zero the struct, then sets fields at offsets 0x104 and 0x108 to the same value a2. Returns pointer to the struct. Part of display mode / sound manager node initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55BE80 (0055be80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x104 | RW | — | Field stored value (first copy of a2) |
| this | 0x108 | RW | — | Field stored value (second copy of a2) |

**Written-by note (persistence):**
- this 0x104: unconditional write. External poke survives.
- this 0x108: unconditional write. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c2a0 | GlobalZeroInit_c2a0 | Zero-initialize entire struct |

**Guard conditions:** None — always zeroes struct then writes both fields.
