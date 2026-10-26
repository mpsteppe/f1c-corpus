## TransformationMatrixUpdate_0054b770 — Scene node transform matrix update with hierarchy and scaling

**Summary:** Updates the world transformation matrix for a scene node. Concatenates with parent's world matrix if parent exists, applies XYZ scale factors when scaling flag is set, and stores final combined matrix at `this+0x1A0`.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_54B570 (0054b570)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | R | — | Flags: bit 0 = local transform present, bit 14 (0x4000) = enable scaling |
| this | 0x40 | R | — | Parent node pointer (null if root) |
| this | 0x194 | R | — | X-axis scale factor |
| this | 0x198 | R | — | Y-axis scale factor |
| this | 0x19C | R | — | Z-axis scale factor |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x40]` (parent ptr) is null AND flag bit 0 not set → skip parent/world matrix composition. If flag bit 14 (0x4000, scale) not set → skip scale factor application, copy existing world matrix to output directly.
