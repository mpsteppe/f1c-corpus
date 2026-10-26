## LinkedNodeDestruction_0054fa50 — LinkedBufferNodeDestructor

**Summary:** Frees a linked buffer node's data array and descriptor struct, then clears the reference pointer. Used for particle/scene buffer cleanup.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneGraph (0054a770), VertexParticleBufferAllocator (0054f830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E0 | RW | 0 | pointer to buffer descriptor (freed then set to 0) |
| this | 0x1E8 | R | — | pointer to data array (freed via descriptor+8) |

**Written-by note (persistence):**
- this 0x1E0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory |

**Guard conditions:** If this[120] (this+0x1E0) is null → skip and return null (BLOCKED). PASSES: descriptor pointer non-null → free data array, free descriptor, clear pointer.
