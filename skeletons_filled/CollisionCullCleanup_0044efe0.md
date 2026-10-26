## CollisionCullCleanup_0044efe0 — D3DSurfaceCleanup

**Summary:** Cleans up D3D surface: zeros surface type field at this[158] (0x278), releases the DirectDrawSurface at this[1] (0x4) via vtable[32] (Release) and vtable[8] (ReleaseDC if applicable), then zeros the pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Post (00455e70), HWInput_Exit (00455f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x8 | R | — | vtable entry 8 (ReleaseDC if applicable) |
| *(this+0x4) | 0x20 | R | — | vtable entry 32 (Release method) |
| this | 0x4 | RW | 0 | DirectDrawSurface pointer (released then zeroed) |
| this | 0x278 | RW | 0 | Surface type ID field (zeroed to mark invalid) |

**Written-by note (persistence):**
- this 0x4: Set to 0 on cleanup. Pointer is invalid after release.
- this 0x278: Set to 0 on cleanup. Resets type ID.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[1] (surface pointer at offset 0x4) is NULL, skip release path. Otherwise release and zero.
