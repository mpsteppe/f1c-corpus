## TextureSurfaceAllocation_00541340 — Sub-allocated texture surface setup

**Summary:** Allocates a 76-byte structure with two 36-byte surface descriptor blocks via OperatorNewNhMallocWrapper, initializes each with format/width/height fields (322/24 and 34), then calls sub_540DF0 twice to create both surfaces.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_544740 (00544740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x114C) | 0x4 | RW | 322 | surface 1 format — set to 322 (D3DFMT?) |
| *(this+0x114C) | 0x8 | RW | 24 | surface 1 width/height — set to 24 |
| *(this+0x114C) | 0xC | RW | — | surface 1 size/depth — set from a2 parameter |
| *(this+0x114C) | 0x24 | RW | 34 | surface 2 format — set to 34 |
| *(this+0x114C) | 0x28 | RW | 322 | surface 2 format — set to 322 |
| *(this+0x114C) | 0x2C | RW | 24 | surface 2 width/height — set to 24 |
| *(this+0x114C) | 0x30 | RW | — | surface 2 size/depth — set from a2 parameter |
| this | 0x114C | RW | — | pointer to allocated descriptor structure |

**Written-by note (persistence):**
- *(this+0x114C) 0x4: set once after allocation — const 322
- *(this+0x114C) 0x8: set once after allocation — const 24
- *(this+0x114C) 0xC: set once after allocation — from a2
- *(this+0x114C) 0x24: set once after allocation — const 34
- *(this+0x114C) 0x28: set once after allocation — const 322
- *(this+0x114C) 0x2C: set once after allocation — const 24
- *(this+0x114C) 0x30: set once after allocation — from a2
- this 0x114C: allocated once — persists until freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540df0 | sub_540DF0 | creates vertex/index buffer from descriptor block |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 76 bytes for descriptor structure |

**Guard conditions:** If allocation fails → this+0x114C set to null, returns without buffer creation. Both sub_540DF0 calls must succeed; if either returns -1, function returns -1.
