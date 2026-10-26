## SurfaceMemoryAllocate_00519361 — SurfaceMemoryAllocate

**Summary:** Sets surface memory stride/pitch to 48 bytes then delegates allocation to the object's vtable function. Part of surface/texture memory management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceAllocation (0051629f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | vtable pointer (used to call allocation function) |
| obj | 0x14 | RW | 48 | surface stride/pitch in bytes (set to 48) |
| this | 0x0 | R | — | first dword of obj (vtable) |

**Written-by note (persistence):**
- obj 0x14: set unconditionally to 48; external poke overwrites stride

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always writes 48 to stride and calls vtable dispatch.
