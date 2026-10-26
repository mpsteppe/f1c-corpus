## ByteFieldSetterAtOffset0x5d_0057a570 — FlagByteAtOffset0x5DSetter

**Summary:** Sets the byte at offset 0x5D of the object pointed to by *this to the value of a2. Returns the object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SynchronizeWithServer (00464290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x5D | RW | — | byte field at offset 0x5D (flag or state indicator) |
| this | 0x0 | R | — | pointer to the target object (dereferenced to access) |

**Written-by note (persistence):**
- obj 0x5D: written unconditionally with a2 value; survives as updated flag byte

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none.
