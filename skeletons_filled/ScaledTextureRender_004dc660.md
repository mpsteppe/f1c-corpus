## ScaledTextureRender_004dc660 — Render texture with scale adjustment and alignment

**Summary:** Renders a scaled texture by looking up the texture object via WideStringLinkedListSearch, temporarily multiplying its scale factors (offsets +92, +96) by the requested scales, computing aligned screen position, rendering via sub_553070, then restoring original scale and color values.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextRenderDispatcher (004dd030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dc340 | AlignmentPositionSwitch | Compute aligned position from dimensions and alignment flags |
| 0053d1f0 | WideStringLinkedListSearch | Find texture/string object by name in a linked list |
| 00552fc0 | FieldSetterAt0x48 | Set field at offset 0x48 on the texture object |
| 00553070 | sub_553070 | Render texture at given position using specified device |
| 005531f0 | sub_5531F0 | Retrieve base alignment dimensions from target object |
| 00587bdc | CRTFtol | Convert double to long (float-to-int helper) |

**Guard conditions:** Three-tier guard: (1) if `a9` (device ptr) is null, substitute with `dword_8B8DC8`; (2) if `a1` (texture name) or `a2` (target) is null, skip entirely; (3) if `WideStringLinkedListSearch(a1)` returns null (texture not found), skip rendering.
