## BufferInitWithIdentityPattern_00516c0c — InitIdentityLookupTables

**Summary:** Allocates a 1408-byte buffer via vtable allocator at *(this+4), stores pointer at this+0x11C. Fills first 256 bytes with identity pattern (each byte = its index), then populates three sequential tables: 0xFF fill, zero fill, and a copy of the identity table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | first vtable entry of allocator at this+0x4, allocates 1408-byte buffer |
| this | 0x4 | R | — | pointer to allocator object for buffer allocation |
| this | 0x11C | RW | — | stores allocated buffer pointer (base of identity table) |

**Written-by note (persistence):**
- this 0x11C: written once with allocated pointer, persists until freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — always allocates and fills all tables unconditionally.
