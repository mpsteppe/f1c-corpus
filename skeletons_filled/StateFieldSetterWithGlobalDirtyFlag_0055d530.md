## StateFieldSetterWithGlobalDirtyFlag_0055d530 — Set single state field with DX update

**Summary:** Stores value a2 at offset 0x50, then calls DirectXVertexBufferTextureCoordinateSetup with mode 7 and sets dirty flag 0x800. Part of DirectX vertex buffer state update chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A500 (0055a500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Vertex buffer handle/identifier passed to DirectX call |
| this | 0x50 | RW | — | State field — written from a2 |

**Written-by note (persistence):**
- this 0x50: Overwritten each call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager — passed to DirectXVertexBufferTextureCoordinateSetup |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr — dirty flag 0x800 set at offset 236 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005416a0 | DirectXVertexBufferTextureCoordinateSetup | Update DirectX vertex buffer with state value (mode 7) |

**Guard conditions:** None — always executes unconditionally.
