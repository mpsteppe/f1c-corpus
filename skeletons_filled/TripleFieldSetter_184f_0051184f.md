## TripleFieldSetter_184f_0051184f — Set three object fields from parameters

**Summary:** Writes three consecutive DWORD fields at offsets 0x40, 0x44, 0x48 from three parameters, with parameter-to-offset remapping (a2→0x48, a3→0x40, a4→0x44).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5118E6 (005118e6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | RW | — | stores parameter a3 |
| this | 0x44 | RW | — | stores parameter a4 |
| this | 0x48 | RW | — | stores parameter a2 |

**Written-by note (persistence):**
- this 0x40: written unconditionally each call; external poke overwrites until next set
- this 0x44: written unconditionally each call; external poke overwrites until next set
- this 0x48: written unconditionally each call; external poke overwrites until next set

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all three fields.
