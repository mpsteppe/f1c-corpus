## TextureSurfaceLoader_00497d20 — LoadTextureSurfaceAndRegister

**Summary:** Loads a texture/surface by name `a2`. Validates init status via dword_8AC4C4, calls surface creation method (vtable+0x5C). On success: allocates 88-byte node (name via strcpy at +0, surface handle at +0x50, next at +0x54), appends to linked list (head at this+0x10C), increments counter at this+0x110.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492460 (00492460), sub_493060 (00493060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x160)+0x54) | 0x54 | RW | — | Next pointer at node offset 0x54 (linked list link) |
| this | 0x10C | RW | — | Head pointer of loaded-surface linked list |
| this | 0x110 | R | — | Counter of registered surfaces (incremented each load) |
| this | 0x160 | R | — | Pointer to a list node for next-pointer access |

**Written-by note (persistence):**
- *(*(this+0x160)+0x54) 0x54: Written on append. External poke does not survive for appended node.
- this 0x10C: Written on first insert. External poke survives if list non-empty.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default base directory path |
| 005ec400 | dword_5EC400 | R | Base directory pointer for surface loading |
| 008ac4c4 | dword_8AC4C4 | R | Global init status object pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00497e80 | sub_497E80 | Checks if surface name is already loaded |
| 00566650 | StringCopyWithBufferRealloc | Copies string with buffer reallocation |
| 00587bcf | FreeWrapper_7bcf | Frees temporary buffer |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates 88-byte node memory |

**Guard conditions:** Parameter a2 must be non-null — returns 0. If sub_497E80 returns non-null (already loaded), skips load (returns 1). dword_8AC4C4 must be non-null — null returns 0 (system not initialized). Surface creation virtual call must return non-null — null jumps to cleanup and returns 0. Surface must not already be initialized (virtual method at vtable+0x14 check) — if initialized, releases surface and returns 0.
