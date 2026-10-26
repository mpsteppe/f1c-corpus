## RenderResourceTeardown_005064cf — Release D3D surface/device resources and clear pointers

**Summary:** Tears down render resources by releasing COM interfaces stored in this[1]/this[2]/this[3] via vtable calls. Optionally performs a copy-before-release if this[1]/[2]/[3] are all valid and flag bit 0 not set. Sets released pointers to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DTextureSurfaceLockCopy (00506559)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x8 | R | — | vtable entry for Release method (offset 8: IUnknown::Release) on this[2] |
| *(this+0x8) | 0x28 | R | — | vtable entry at offset 40 (Unlock or copy-related method) on this[2] |
| *(this+0xC) | 0x8 | R | — | vtable entry for Release method (offset 8) on this[3] |
| *(this+0xC) | 0x70 | R | — | vtable entry at offset 112 (copy/surface transfer method) on this[3] |
| this | 0x0 | R | — | flag/control DWORD (bit 0 checked for conditional skip of copy operation) |
| this | 0x4 | RW | 0 | pointer to surface/device interface 1 (released indirectly or cleared) |
| this | 0x8 | RW | 0 | pointer to surface/device interface 2 (released via vtable+8, set to 0) |
| this | 0xC | RW | 0 | pointer to surface/device interface 3 (released via vtable+8, set to 0) |

**Written-by note (persistence):**
- this 0x4: conditional — set to 0 at end; if code reaches release path, external poke does NOT survive
- this 0x8: conditional — set to 0 after vtable+8 Release call; external poke does NOT survive
- this 0xC: conditional — set to 0 after vtable+8 Release call; external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[1] is non-null OR this[2] is non-null → calls vtable+40 on whichever is non-null. If all three (this[1], this[2], this[3]) are non-null AND flag bit 0 (this[0] & 1) is clear → calls vtable+112 on this[3] for copy-before-release. Then releases this[2] and this[3] unconditionally if non-null. Clears this[1] unconditionally.
