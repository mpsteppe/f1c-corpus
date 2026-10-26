## VirtualFunctionDispatchWithStackFrames_0057a4f0 — ContextDrivenVirtualDispatch

**Summary:** Dispatches multiple virtual calls using a context structure. Reads a byte flag at offset 0x2B (43), calls vtable init at +0x68 with context, forwards stack arguments to AllocationWrapper, calls vtable finalize at +0xC0, clears byte at offset 0x5D, and copies a string. Returns the context structure pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverEntrantSetupEntry (00462550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x68 | R | — | vtable entry at offset 0x68 (init call with context) |
| *(obj+0x0) | 0xC0 | R | — | vtable entry at offset 0xC0 (finalize call with context) |
| obj | 0x0 | R | — | vtable pointer of target object |
| obj | 0x5D | RW | 0 | byte flag at offset 0x5D (cleared to 0) |
| this | 0x0 | R | — | vtable pointer of context/owner (passed to virtual calls) |

**Written-by note (persistence):**
- obj 0x5D: unconditionally set to 0; survives as cleared flag

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00584ff0 | StringCopyToBufferWithLengthCap | copies string from stack parameter to buffer |
| 00585030 | AllocationWrapper | allocates memory using forwarded stack parameters |
| 00585860 | SingleFieldSetter | sets a field using value from context offset 0x2B (43) |

**Guard conditions:** none.
