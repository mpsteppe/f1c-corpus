## Destructor_0047f3f0 — ScreenDataTextureManagerDtor

**Summary:** Destructor for ScreenData texture manager: resets vtable, frees three allocated buffer pointers at offsets 0x218C, 0x2194, 0x219C if non-null, then chains to base destructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SimpleGetter (0047f3d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer reset to TextureManagerVTable |
| this | 0x218C | R | — | first allocated buffer pointer, freed if non-null |
| this | 0x2194 | R | — | second allocated buffer pointer, freed if non-null |
| this | 0x219C | R | — | third allocated buffer pointer, freed if non-null |

**Written-by note (persistence):**
- this 0x0: set at entry to off_5A6E70; overwritten by sub_495300 base destructor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6e70 | off_5A6E70 | R | TextureManagerVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions:** Each of the three buffer pointers at offsets 0x218C, 0x2194, 0x219C is only freed if non-null.
