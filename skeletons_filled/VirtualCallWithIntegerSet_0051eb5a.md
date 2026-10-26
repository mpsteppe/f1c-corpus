## VirtualCallWithIntegerSet_0051eb5a — WriteFieldAndCallVirtual

**Summary:** Writes integer constant 45 to field at offset 0x14 of the sub-object pointed to by `this->field_0`, then calls the first virtual function on `this`. Belongs to object initialization/callback dispatch system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | First virtual function pointer read for dispatch |
| obj | 0x14 | RW | 45 | Integer field written before virtual call; used as parameter/flag for the callee |
| this | 0x0 | R | — | Pointer to sub-object (obj) containing function table and writable data |

**Written-by note (persistence):**
- obj 0x14: unconditional write of 45 before each call; persists in obj field until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always writes 45 and dispatches virtual call.
