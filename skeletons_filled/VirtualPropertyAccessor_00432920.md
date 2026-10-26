## VirtualPropertyAccessor_00432920 — VirtualPropertyAt3CAccessor

**Summary:** Reads a DWORD value at offset 0x3C from a dereferenced object pointer. Returns the virtual property or identifier field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExtensionStripperForAllListEntries (0046f170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3C | R | — | Virtual property/identifier field at offset 0x3C |
| this | 0x0 | R | — | Pointer to the target struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional dereference and field read. Assumes this->field0 is a valid pointer.
