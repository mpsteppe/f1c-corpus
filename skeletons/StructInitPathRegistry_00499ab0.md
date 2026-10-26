## StructInitPathRegistry_00499ab0 — Three-field init with string copy

**Summary:** Constructor/init: zeroes field at this+0x0, sets sentinel at this+0x4 to -1, copies string from a2, sets this+0x8 to a3. Part of path/texture registry initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BitmapLoader (004979f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | first field — pointer/index zeroed |
| this | 0x4 | RW | -1 (0xFFFFFFFF) | sentinel — set to -1 |
| this | 0x8 | RW | — | field set to parameter a3 (path/identifier) |

**Written-by note (persistence):**
- this 0x0: written once unconditionally in init; persists for object lifetime
- this 0x4: written once unconditionally in init; persists for object lifetime
- this 0x8: written once with a3 parameter; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies string from a2 with buffer reallocation |

**Guard conditions:** none — unconditional init sequence
