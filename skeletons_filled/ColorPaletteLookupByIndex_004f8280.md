## ColorPaletteLookupByIndex_004f8280 — ColorPaletteLookupByIndex

**Summary:** Returns RGB color triple from palette by index. Two color groups: bright/light (indices 0-4, 43) and dark/helm (indices 12-20, 38-41, 44). Defaults to MaterialColorR/TrackFrictionParam/ModuleInterfaceVal if index not in either group.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F70C0 (004f70c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004f82f4 | jpt_4F82B5 | R | Jump table for palette index switch |
| 004f8300 | byte_4F8300 | R | Unknown data near jump table |
| 005d67b0 | dword_5D67B0 | R | D3DCaps_BlendVal0 [DERIVED] — Bright palette red component |
| 005d67b4 | dword_5D67B4 | R | RGBColorLookup [DERIVED] — Bright palette green component |
| 005d67b8 | dword_5D67B8 | R | FOVParamHigh [DERIVED] — Bright palette blue component |
| 005d67bc | dword_5D67BC | R | HelmColor_Dark [DERIVED] — Dark palette red component |
| 005d67c0 | dword_5D67C0 | R | D3D_LightColorB [DERIVED] — Dark palette green component |
| 005d67c4 | dword_5D67C4 | R | FlavorColorBlue [DERIVED] — Dark palette blue component |
| 005d67c8 | flt_5D67C8 | R | MaterialColorR [DERIVED] — Default R value |
| 005d67cc | flt_5D67CC | R | TrackFrictionParam [DERIVED] — Default G value |
| 005d67d0 | flt_5D67D0 | R | ModuleInterfaceVal_5D67D0 [DERIVED] — Default B value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Switch on `a1` index. Cases 0-4,43 select bright palette; cases 12-20,38-41,44 select dark palette; default returns immediately with initial default values.
