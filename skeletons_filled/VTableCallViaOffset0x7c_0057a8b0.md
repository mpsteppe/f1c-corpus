## VTableCallViaOffset0x7c_0057a8b0 — VTableCallMethodAtOffset0x7C

**Summary:** Calls virtual method at vtable offset 0x7C on a COM-like object. Passes `*this` as the `this` pointer to the callee.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverEntrantSetupEntry (00462550), BufferSendWithLocks (00462760), NetworkEntrantSetupWithIDCheck (004627c0), UniqueID (004630d0), ConditionalObjectCleanup (00464670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x7C | R | — | vtable function pointer at index 31 (0x7C/4) |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional call, no branch logic

