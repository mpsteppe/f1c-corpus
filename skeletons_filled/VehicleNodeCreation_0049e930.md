## VehicleNodeCreation_0049e930 — Vehicle node/D3D texture creation

**Summary:** Allocates and initializes a 96-byte vehicle node struct with D3D texture creation attempt. On successful texture creation, frees the struct and clears pointer; on failure, retains struct for retry state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49CD80 (0049cd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | allocated node pointer (set to new struct or 0) |

**Written-by note (persistence):**
- this 0x8: set to allocated struct or 0. Persists as long as object lives — external poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054fe10 | StructInitWithZeroFill | zero-initializes allocated struct |
| 00550080 | D3DTextureCreation | creates D3D texture with specified parameters |
| 00557470 | EmptyStub_7470 | cleanup/stub function called before free |
| 00587bcf | FreeWrapper_7bcf | frees allocated node struct |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 96 bytes for node struct |

**Guard conditions:** Allocates 96 bytes — if allocation fails, this[2] = 0 and returns 0. If allocation succeeds, stores pointer and sets flag bit 0 at offset 68. Then attempts D3DTextureCreation: if successful, frees struct and sets this[2]=0; if fails, keeps struct pointer in this[2].
