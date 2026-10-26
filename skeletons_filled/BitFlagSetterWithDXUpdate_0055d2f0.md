## BitFlagSetterWithDXUpdate_0055d2f0 — Bit-7 flag set/clear with DirectX texture update

**Summary:** Sets or clears bit 7 (0x80) of this+0x0 based on boolean parameter a2, then calls DirectXVertexBufferTextureCoordinateSetup with SoundManager, this pointer, field at +0x4, and constant 1. Part of DirectX vertex/texture management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0), sub_55A500 (0055a500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Bitfield flags — bit 7 (0x80) set or cleared based on a2 |
| this | 0x4 | R | — | Value passed as parameter to DirectX texture coordinate setup |

**Written-by note (persistence):**
- this 0x0: Bit 7 modified each call. Other bits from external poke survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager — passed to DirectXVertexBufferTextureCoordinateSetup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005416a0 | DirectXVertexBufferTextureCoordinateSetup | Configure DirectX vertex buffer texture coordinates with flag state |

**Guard conditions:** a2 == 0: BLOCKED from setting bit 7 (clears it instead). a2 != 0: PASSES to bit-7 set path.
