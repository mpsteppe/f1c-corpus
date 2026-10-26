## BufferSendWithLocks_00462760 — VTableBufferSend

**Summary:** Queries COM temporary object, calls lock via vtable offset 0xc4, copies buffer data, unlocks, and releases the temporary object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WeatherSurfaceUpdate (004628a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | COM interface pointer for vtable query |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a200 | MemcpyLikeCopyWithWordByteSplitSizeStore | Copy data buffer with size tracking |
| 0057a880 | VTableQueryWithStackBufferResult | Query COM vtable to get temporary object |
| 0057a8b0 | VTableCallViaOffset0x7c | Release COM temporary object via vtable |
| 0057a8c0 | VirtualDispatchWrapper_a8c0 | Unlock/sync after buffer copy |
| 0057a8e0 | COMVTableCallVia0xc4 | Lock/acquire for buffer write via vtable offset 0xc4 |

**Guard conditions:** None — always executes the full sequence.
