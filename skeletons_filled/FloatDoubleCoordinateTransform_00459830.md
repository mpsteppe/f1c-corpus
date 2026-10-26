## FloatDoubleCoordinateTransform_00459830 — FloatToDoubleCoordTransform

**Summary:** Converts float-precision position (offsets 4,8,12) and rotation (offsets 16,20,24) to double-precision. Stores position as 3 doubles at offset 0xD8, computes 3x3 rotation tensor matrix stored at offset 0x138, and saves position backup at offset 0xC0. If trigger flag at 0xD0 is set, calls external processing and clears buffer before conversion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateDependentUpdateDispatch (0040f130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | float position X |
| this | 0x8 | R | — | float position Y |
| this | 0xC | R | — | float position Z |
| this | 0x10 | R | — | float rotation X (Euler angle) |
| this | 0x14 | R | — | float rotation Y |
| this | 0x18 | R | — | float rotation Z |
| this | 0xC0 | RW | — | saved position X backup (copied from float position) |
| this | 0xC4 | RW | — | saved position Y backup |
| this | 0xC8 | RW | — | saved position Z backup |
| this | 0xD0 | R | — | trigger flag: if non-zero, call sub_54B4D0 and clear buffer before conversion |

**Written-by note (persistence):**
- this 0xC0: written every call. Overwritten each call, external poke does not survive.
- this 0xC4: written every call. Overwritten each call.
- this 0xC8: written every call. Overwritten each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b4d0 | sub_54B4D0 | external function called with position/rotation when trigger flag at 0xD0 is set |
| 0054fae0 | BufferEntryClear | clear buffer entry with identifier 0x8000000 |
| 005691d0 | F_3x3RotationTensorMatrixTransform | compute 3x3 rotation tensor matrix from Euler angles, output to v9 |
| 00569280 | Copy6DwordsToStructCall | copy 6-DWORD rotation matrix result from v9 to another struct location |

**Guard conditions:** If field at offset 0xD0 is non-zero → call sub_54B4D0 with float position/rotation data and clear buffer before conversion. Otherwise skip that step. Conversion always executes regardless.
