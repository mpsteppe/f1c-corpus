## ConditionalDispatch_27d0_004a27d0 — ConditionalTransformUpdate

**Summary:** Conditionally dispatches 6 transform/position parameters (3 DWORDS + 3 floats at offsets 0x4C-0x60) to sub_54B4D0 when the sound source handle at offset 0x64 is non-null. Otherwise returns the struct pointer unchanged.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Vec3CopyToStruct (004a2800), PitCrewAnimationLoader (004a2a90), sub_4D0110 (004d0110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | first DWORD parameter for position/transform dispatch |
| this | 0x50 | R | — | second DWORD parameter |
| this | 0x54 | R | — | third DWORD parameter |
| this | 0x58 | R | — | first float parameter (X coordinate?) for 3D position |
| this | 0x5C | R | — | second float parameter (Y coordinate?) |
| this | 0x60 | R | — | third float parameter (Z coordinate?) |
| this | 0x64 | R | — | guard: sound source handle, must be non-null to dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b4d0 | sub_54B4D0 | sets 3D position/transform from 6 parameters (3 DWORDs + 3 floats) |

**Guard conditions:** Guard at this[0x64] (sound source handle): if non-null, call sub_54B4D0 with fields 0x4C-0x60. If null, skip — return `this` unmodified.
