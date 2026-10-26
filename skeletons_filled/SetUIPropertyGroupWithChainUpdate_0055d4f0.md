## SetUIPropertyGroupWithChainUpdate_0055d4f0 — StoreThreeValuesWithDXUpdate

**Summary:** Stores three integer parameters a2, a3, a4 at offsets 0x38/0x3C/0x40, then calls DirectXVertexBufferTextureCoordinateSetup with mode 6 and sets dirty flag 0x800. Part of DirectX vertex buffer property update chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55A500 (0055a500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Vertex buffer handle/identifier passed to DirectX call |
| this | 0x38 | RW | — | First property value (written from a2) |
| this | 0x3C | RW | — | Second property value (written from a3) |
| this | 0x40 | RW | — | Third property value (written from a4) |

**Written-by note (persistence):**
- this 0x38-0x40: Overwritten each call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager — passed to DirectXVertexBufferTextureCoordinateSetup |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr — dirty flag 0x800 set at offset 236 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005416a0 | DirectXVertexBufferTextureCoordinateSetup | Update DirectX vertex buffer with three values (mode 6) |

**Guard conditions:** None — always executes unconditionally.
