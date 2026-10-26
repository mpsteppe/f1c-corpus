## ArrayElementFlagSetWithBoundsCheck_00558cb0 — ArrayElementFlagSetter

**Summary:** Sets the 0x4000 flag on an array element at given index (bounds-checked), calling a multi-field update helper.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleCollisionSpark (004cb620), WheelRenderObjectPerFrameUpdate (004cb860), ParticleTrailEmitter (004cbc50), ParticleInstanceUpdate (004cc1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | array element count limit |
| this | 0x34 | R | — | texture/data array pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b330 | sub_53B330 | updates multiple fields on array element |

**Guard conditions:** If index a2 >= element count (this[11]) → skip and return null (BLOCKED: out of bounds). PASSES: index within bounds → set flag 0x4000 on entry and call sub_53B330.
