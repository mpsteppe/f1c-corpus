## UIPropertyValueSetter_0055d410 — AlphaScaleFactorSetterWithDXUpdate

**Summary:** Stores integer value a3 into one of three alpha/scale factor fields (offset 0x14/0x24/0x34) selected by a2 (1/2/3), then calls DirectXVertexBufferTextureCoordinateSetup to update vertex buffer and sets dirty flag 0x800 on UI root context. Companion to sub_55D320 which uses these scale factors for byte-to-float color conversion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0), sub_55A500 (0055a500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Vertex buffer handle/identifier passed to DirectX call |
| this | 0x14 | RW | — | Alpha/scale factor for color group 1 — written from a3 when a2==1 |
| this | 0x24 | RW | — | Alpha/scale factor for color group 2 — written from a3 when a2==2 |
| this | 0x34 | RW | — | Alpha/scale factor for color group 3 — written from a3 when a2==3 |

**Written-by note (persistence):**
- this 0x14: Overwritten when a2==1. External poke does not survive group-1 writes.
- this 0x24: Overwritten when a2==2. External poke does not survive group-2 writes.
- this 0x34: Overwritten when a2==3. External poke does not survive group-3 writes.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager — passed to DirectXVertexBufferTextureCoordinateSetup |
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr — dirty flag 0x800 set at offset 236 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005416a0 | DirectXVertexBufferTextureCoordinateSetup | Update DirectX vertex buffer with new alpha value (mode 2, 3, or 4) |

**Guard conditions:** a2 (group selector): 1 → writes 0x14, DX mode 2. 2 → writes 0x24, DX mode 3. 3 → writes 0x34, DX mode 4. Any other value → no writes, no DX call (only dirty flag set).
