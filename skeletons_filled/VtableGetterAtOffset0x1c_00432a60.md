## VtableGetterAtOffset0x1c_00432a60 — VtableFieldAt1cGetter

**Summary:** Reads a DWORD at offset 0x1C from a dereferenced object pointer. Likely retrieves a vtable-based method pointer or interface identifier.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalUpdateOnChangedState (0046efe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | Field at offset 0x1C in target struct (vtable entry or property) |
| this | 0x0 | R | — | Pointer to the target struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional dereference and field read. Assumes this->field0 is a valid pointer.
