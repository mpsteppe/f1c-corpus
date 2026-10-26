## ArrayResourceCleanup_004a29a0 — ArrayResourceCleanup

**Summary:** Cleans up an array of 120-byte pit crew animation sub-structs and releases associated resources (3D sound source). Zeros 3 header DWORDs, iterates over elements calling sub_4A2220 destructor on each, frees the array block, then destroys the sound source.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StructInitCall (004a2980), PITANIMSMASAnimationFileLoader (004a3220), UIComponentCleanup (004a4db0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | DWORD header/state reset to 0 |
| this | 0x4 | RW | 0 | DWORD header/state reset to 0 |
| this | 0x8 | RW | 0 | DWORD header/state reset to 0 |
| this | 0xC | RW | 0 | count of 120-byte elements in array at 0x10 |
| this | 0x10 | RW | 0 | pointer to array of 120-byte pit crew animation sub-structs |
| this | 0x14 | RW | 0 | pointer to 3D sound source, freed via F_3DSoundSourceDestructor |

**Written-by note (persistence):**
- this 0x0: once unconditional (0)
- this 0x4: once unconditional (0)
- this 0x8: once unconditional (0)
- this 0xC: once unconditional (0), written after reading count for loop
- this 0x10: conditional — written to 0 only after checking and freeing the array; external poke would survive if written after
- this 0x14: conditional — written to 0 only after checking and freeing sound source; external poke would survive if written after

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a2220 | sub_4A2220 | destructor/init per 120-byte pit crew animation sub-struct element |
| 00545150 | F_3DSoundSourceDestructor | destroys the 3D sound source attached at offset 0x14 |
| 00587bcf | FreeWrapper_7bcf | frees the array block memory |

**Guard conditions:** Guard on this[0xC] (count): if > 0, loop zeroing a field at offset 100 within each 120-byte element. If 0, skip zeroing loop. Guard on this[0x10] (array pointer): if non-null, iterate backward over 120-byte elements calling sub_4A2220 on each, then free the whole block. If null, skip. Guard on global dword_8AFE88 AND this[0x14] (sound source): only call F_3DSoundSourceDestructor when both are non-zero. If either is zero, skip sound destruction.
