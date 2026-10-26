## sub_55EBA0_0055eba0 — BillboardDirectionCompute

**Summary:** For each vertex, computes a reflected direction vector using D3D device transforms: transforms source position, adds offset from a2[9-11], normalizes, computes reflection via half-vector formula, maps to [0,1] range, stores at vertex buffer offsets +40 and +44. Checks MMX flag at this[6]+20 to select stride (16 vs 12). Part of billboard/reflection shader setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55D720 (0055d720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Vertex count (this[2]) — loop bound |
| this | 0xC | R | — | Source vertex data pointer (this[3]) — base for transform |
| this | 0x18 | R | — | Render state struct (this[6]) — MMX flag at +20, scene node at +312 |
| this | 0x20 | R | — | Dest vertex buffer pointer (this[8]) — output at +40, +44 per vertex |
| this | 0x2C | R | — | Unknown field (this[11]) |
| this | 0x150 | R | — | Unknown field (this[84]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | Float threshold for zero-length normalization check |
| 0059e450 | flt_59E450 | R | DegreesToRadians — angle conversion constant |
| 00800000 | unk_800000 | R | MMXFlag — bitmask checked against this[6]+20 for stride select |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr — vtable calls for coordinate transform (entries 0 and 1) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | > | 0 | Vertex count (this[2]) — if > 0, loop executes |

**Guard interpretation:** a2 (input array) == NULL: BLOCKED — entire function skipped. this[2] > 0: PASSES to per-vertex loop. <= 0: BLOCKED.
