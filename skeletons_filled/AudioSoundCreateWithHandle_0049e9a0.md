## AudioSoundCreateWithHandle_0049e9a0 — Audio node/D3D texture creation

**Summary:** Allocates and initializes a 96-byte audio node struct with D3D texture creation attempt (same pattern as VehicleNodeCreation but stores at this[3] instead of this[2]). On success frees struct, on failure retains for retry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49CD80 (0049cd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | allocated audio node pointer (set to new struct or 0) |

**Written-by note (persistence):**
- this 0xC: set to allocated struct or 0. Persists as long as object lives — external poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054fe10 | StructInitWithZeroFill | zero-initializes allocated struct |
| 00550080 | D3DTextureCreation | creates D3D texture with specified parameters |
| 00557470 | EmptyStub_7470 | cleanup/stub function called before free |
| 00587bcf | FreeWrapper_7bcf | frees allocated audio node struct |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 96 bytes for audio node struct |

**Guard conditions:** Allocates 96 bytes — if allocation fails, this[3] = 0 and returns 0. If allocation succeeds, stores pointer and sets flag bit 0 at offset 68. Then attempts D3DTextureCreation: if successful, frees struct and sets this[3]=0; if fails, keeps struct pointer in this[3].
