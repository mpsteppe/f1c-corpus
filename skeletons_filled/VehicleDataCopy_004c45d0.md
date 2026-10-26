## VehicleDataCopy_004c45d0 -- Vehicle Template Data Deep Copy

**Summary:** Performs a deep copy of vehicle configuration data from a source template struct (a2) into the destination vehicle instance (this). Copies 7 string fields (with null-fallback to default directory path), multiple byte-range blocks of varying sizes (8 to 256 bytes), a 15-DWORD contiguous block, and a final trailing DWORD. Called once during vehicle loading to instantiate a vehicle from its template.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleDataLoader (004c4240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal -> value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | -- | Vehicle ID bytes, 16-byte identifier block from source+40 |
| this | 0x38 | RW | -- | Vehicle param DWORD[0] from source+56 |
| this | 0x3C | RW | -- | Vehicle param DWORD[1] from source+60 |
| this | 0x40 | RW | -- | Vehicle param DWORD[2] from source+64 |
| this | 0x44 | RW | -- | Vehicle param DWORD[3] from source+68 |
| this | 0x48 | RW | -- | Vehicle param DWORD[4] from source+72 |
| this | 0x4C | RW | -- | Vehicle param DWORD[5] from source+76 |
| this | 0x50 | RW | -- | Vehicle param DWORD[6] from source+80 |
| this | 0x54 | RW | -- | Vehicle param DWORD[7] from source+84 |
| this | 0x58 | RW | -- | Vehicle param DWORD[8] from source+88 |
| this | 0x5C | RW | -- | Vehicle param DWORD[9] from source+92 |
| this | 0x60 | RW | -- | Vehicle param DWORD[10] from source+96 |
| this | 0x64 | RW | -- | Vehicle param DWORD[11] from source+100 |
| this | 0x68 | RW | -- | Vehicle param DWORD[12] from source+104 |
| this | 0x6C | RW | -- | Vehicle param DWORD[13] from source+108 |
| this | 0x70 | RW | -- | Vehicle param DWORD[14] from source+112 |
| this | 0x74 | RW | -- | 8-byte block from source+116 |
| this | 0x7C | RW | -- | 64-byte block from source+124 |
| this | 0xBC | RW | -- | 64-byte block from source+188 |
| this | 0xFC | RW | -- | 64-byte block from source+252 |
| this | 0x13C | RW | -- | 64-byte block from source+316 |
| this | 0x17C | RW | -- | 64-byte block from source+380 |
| this | 0x1BC | RW | -- | 64-byte block from source+444 |
| this | 0x2BC | RW | -- | 256-byte block from source+444 extended |
| this | 0x33C | RW | -- | 128-byte block from source+700 |
| this | 0x34C | RW | -- | 16-byte block from source+828 |
| this | 0x38C | RW | -- | 64-byte block from source+844 |
| this | 0x39C | RW | -- | 16-byte block from source+908 |
| this | 0x3AC | RW | -- | 16-byte block from source+924 |
| this | 0x3BC | RW | -- | 16-byte block from source+940 |
| this | 0x3D4 | RW | -- | 16-byte block from source+956 |
| this | 0x3E0 | RW | -- | 64-byte block from source+992 |
| this | 0x420 | RW | -- | Final DWORD from source+1056 |

**Written-by note (persistence):**
- this 0x28: one-time copy during vehicle load; external poke does NOT persist
- this 0x38: one-time copy during vehicle load; external poke does NOT persist
- this 0x3C: one-time copy during vehicle load; external poke does NOT persist
- this 0x40: one-time copy during vehicle load; external poke does NOT persist
- this 0x44: one-time copy during vehicle load; external poke does NOT persist
- this 0x48: one-time copy during vehicle load; external poke does NOT persist
- this 0x4C: one-time copy during vehicle load; external poke does NOT persist
- this 0x50: one-time copy during vehicle load; external poke does NOT persist
- this 0x54: one-time copy during vehicle load; external poke does NOT persist
- this 0x58: one-time copy during vehicle load; external poke does NOT persist
- this 0x5C: one-time copy during vehicle load; external poke does NOT persist
- this 0x60: one-time copy during vehicle load; external poke does NOT persist
- this 0x64: one-time copy during vehicle load; external poke does NOT persist
- this 0x68: one-time copy during vehicle load; external poke does NOT persist
- this 0x6C: one-time copy during vehicle load; external poke does NOT persist
- this 0x70: one-time copy during vehicle load; external poke does NOT persist
- this 0x74: one-time copy during vehicle load; external poke does NOT persist
- this 0x7C: one-time copy during vehicle load; external poke does NOT persist
- this 0xBC: one-time copy during vehicle load; external poke does NOT persist
- this 0xFC: one-time copy during vehicle load; external poke does NOT persist
- this 0x13C: one-time copy during vehicle load; external poke does NOT persist
- this 0x17C: one-time copy during vehicle load; external poke does NOT persist
- this 0x1BC: one-time copy during vehicle load; external poke does NOT persist
- this 0x2BC: one-time copy during vehicle load; external poke does NOT persist
- this 0x33C: one-time copy during vehicle load; external poke does NOT persist
- this 0x34C: one-time copy during vehicle load; external poke does NOT persist
- this 0x38C: one-time copy during vehicle load; external poke does NOT persist
- this 0x39C: one-time copy during vehicle load; external poke does NOT persist
- this 0x3AC: one-time copy during vehicle load; external poke does NOT persist
- this 0x3BC: one-time copy during vehicle load; external poke does NOT persist
- this 0x3D4: one-time copy during vehicle load; external poke does NOT persist
- this 0x3E0: one-time copy during vehicle load; external poke does NOT persist
- this 0x420: one-time copy during vehicle load; external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default directory path string; fallback when source string pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies a string with buffer reallocation; used for all 7 string fields |

**Guard conditions:** No guard conditions; function is unconditional. Each string field uses a null check: if source pointer is null, falls back to byte_5EA438 (default directory path). Function always returns this pointer.
