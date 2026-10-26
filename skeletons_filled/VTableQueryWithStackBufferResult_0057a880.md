## VTableQueryWithStackBufferResult_0057a880 — VTableQueryWithIntResult

**Summary:** Calls virtual method at vtable offset 0x78. Method fills an int and a 4-byte buffer on stack. If method returns non-zero, returns the int value; otherwise returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverEntrantSetupEntry (00462550), BufferSendWithLocks (00462760), NetworkEntrantSetupWithIDCheck (004627c0), UniqueID (004630d0), sub_463E20 (00463e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x78 | R | — | vtable function pointer at index 30 (0x78/4) — query method |
| obj | 0x0 | R | — | object/interface pointer from *this; vtable base |
| this | 0x0 | R | — | COM-style pointer-to-pointer handle |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** vtable method at offset 0x78 returns non-zero → PASSES (return int result from v2). Returns zero → return 0.

