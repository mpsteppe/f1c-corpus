## ShortComputation_e710_0040e710 — ShortComputation_e710

**Summary:** Switch on value at this+0x1C (modes 0-5): writes parameter a2 to a destination field. Cases 0/3/1/4/2/5 all write a2 to offset 0xD0 within a sub-struct pointed by this+0x20; default returns immediately without writing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StatusFieldCopy (00411570)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | mode selector, switch dispatch value (this[7]) |
| this | 0x20 | R | — | pointer to destination sub-struct (this[8]), offset 0xD0 within it written |
| this | 0xF0 | RW | — | destination field written with a2 (accessed as *(this[8] + 0xD0)) |

**Written-by note (persistence):**
- this 0xF0: written unconditionally when this[7] is 0-5, value = a2 (parameter) — persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040e750 | jpt_40E718 | R | jump table for switch statement |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- this+0x1C == 0, 1, 2, 3, 4, or 5 → PASSES: writes a2 to this+0xF0 (via this[8]+0xD0), returns original this[7] value.
- this+0x1C == any other value → BLOCKED: returns this[7] immediately, no write.
