## VirtualDispatchWrapper_a8c0_0057a8c0 — VTableCallMethodAtOffset0xC0

**Summary:** Calls virtual method at vtable offset 0xC0 with one argument (a2). Always returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BufferSendWithLocks (00462760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0xC0 | R | — | vtable function pointer at index 48 (0xC0/4) |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional call, always returns 0

