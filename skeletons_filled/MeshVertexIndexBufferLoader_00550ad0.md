## MeshVertexIndexBufferLoader_00550ad0 — MeshDataFileLoader

**Summary:** Loads mesh data from file handle or memory block, parsing header flags to determine format (material blocks vs texture/animation blocks), allocating sub-arrays, and inverting scale factor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5508A0 (005508a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Mesh header flags (bit 0 = material data present, bit 1 = texture/animation data present) |
| this | 0x4 | RW | — | Scale factor (read from file, then inverted to 1.0/value) |
| this | 0x8 | RW | — | Computed total dimension (count × scale) |
| this | 0xC | R | — | Count of top-level blocks (materials or textures) |
| this | 0x10 | RW | — | Pointer to allocated array of parsed block descriptors |
| this | 0x14 | RW | — | Sub-entry count (init from header, updated with max) |
| this | 0x18 | RW | — | Pointer to allocated sub-entry array (texture frames or sub-materials) |

**Written-by note (persistence):**
- this 0x4: Written unconditionally after header read; external poke overwritten
- this 0x8: Written conditionally (material path only); external poke overwritten on load
- this 0x10: Written with allocated pointer in material path; external poke overwritten on load
- this 0x14: Written initially from header, may be updated with max sub-count; external poke overwritten
- this 0x18: Written with allocated pointer; external poke overwritten on load

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 008b8f30 | dword_8B8F30 | RW | TempFileReadBuffer [DERIVED] |
| 008b8f34 | dword_8B8F34 | RW | FileReadBuffer2 [DERIVED] (also: ` — temp file read buffer (secondary) |
| 008b8f3c | dword_8B8F3C | W | GlobalDataBufferPtr [DERIVED] (also: ` — global data buffer pointer (advances on read) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054a5c0 | ArithmeticComparison_a5c0 | Read structured data from global buffer into target field |
| 005507a0 | sub_5507A0 | Initialize 8-dword sub-entry struct (texture frame) |
| 005507e0 | StructInitWithVtableZero | Initialize 11-dword struct with vtable zeroed (material block) |
| 00550800 | DualFieldZeroInit | Zero-initialize 2-dword sub-entry pair |
| 005593b0 | StructZeroInit_93b0 | Zero-initialize 3-dword struct |
| 00587bcf | FreeWrapper_7bcf | Free temporary read buffers on cleanup |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory (new/malloc wrapper) |
| 00587f64 | sub_587F64 | File seek operation |
| 0058803f | ThreadSafeReadWrapper_803f | Thread-safe file read |
| 00589901 | sub_589901 | Normalize/fix string (name field within loaded data) |
| 0058ace6 | FileSizeQueryWrapper | Query file size |
| 0059b260 | sub_59B260 | Post-process loaded data block (decompress/transform) |

**Guard conditions:** 
- a3 == 0 or flag (a3+296 + (a3+292)<<8) bit 0x10 clear: read entire file from a2 (standard path). PASS when a3 non-null and flag set (memory block path).
- ThreadSafeReadWrapper_803f returns != expected size: read failure → free buffers → return -1. PASS when sizes match.
- this+0x0 & 2 != 0: texture/animation data format → allocate frame arrays. PASS when bit 1 set.
- this+0x0 & 1 != 0 (and bit 1 not set): material data format → allocate material blocks. PASS when bit 0 set.
