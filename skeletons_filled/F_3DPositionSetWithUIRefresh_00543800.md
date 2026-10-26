## F_3DPositionSetWithUIRefresh_00543800 — RGBColor3DSetWithUIRefresh

**Summary:** Converts three integer color components (0-255 range) to normalized floats (multiply by 1/255) and stores them as 3D color/position values at this[95..97] (offsets 0x17C, 0x180, 0x184). Dispatches a color update via VTableDispatchWithFieldCheck and sets the UI refresh flag (0x800) on the UI root context.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | RW | — | X/R color component (float, normalized from byte) |
| this | 0x180 | RW | — | Y/G color component (float, normalized from byte) |
| this | 0x184 | RW | — | Z/B color component (float, normalized from byte) |

**Written-by note (persistence):**
- this 0x17C: overwritten each call with a2 / 255.0
- this 0x180: overwritten each call with a3 / 255.0
- this 0x184: overwritten each call with a4 / 255.0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e460 | flt_59E460 | R | constant 0.0039215689 (1/255) used for byte-to-float normalization |
| 008b78a0 | dword_8B78A0 | R | SoundManager singleton pointer for dispatch |
| 008b8f28 | dword_8B8F28 | R | UI root context pointer; flag 0x800 set at +236 to request UI refresh |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541670 | VTableDispatchWithFieldCheck | dispatch method call via vtable with combined color value |

**Guard conditions:** No guard — always stores all three color components and triggers UI refresh.
