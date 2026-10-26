## CopyBufferHeaderFieldsCallInit_00587370 — Copy buffer header fields with sub-init

**Summary:** Calls BufferWriteWithParams on source field at offset 0x4, then copies four header fields (DWORD 0x10, DWORD 0x14, BYTE 0x18, BYTE 0x19) from source `a2` to `this`. Acts as a buffer/header copy initializer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57B800 (0057b800), ObjectInitWithCopy (0057b820), NetworkPacketSend_0c10 (00580c10), sub_581070 (00581070), sub_585870 (00585870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | Copied from a2+0x10; first DWORD field |
| this | 0x14 | RW | — | Copied from a2+0x14; second DWORD field |
| this | 0x18 | RW | — | Copied from a2+0x18; first BYTE field |
| this | 0x19 | RW | — | Copied from a2+0x19; second BYTE field |

**Written-by note (persistence):**
- this 0x10: copied from a2 each call; external poke overwrites it
- this 0x14: copied from a2 each call; external poke overwrites it
- this 0x18: copied from a2 each call; external poke overwrites it
- this 0x19: copied from a2 each call; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587620 | BufferWriteWithParams | Writes buffer data from source at a2+4 before field copy |

**Guard conditions:** None — all operations execute unconditionally.
