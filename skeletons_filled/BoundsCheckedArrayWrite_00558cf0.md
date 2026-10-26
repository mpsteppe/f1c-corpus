## BoundsCheckedArrayWrite_00558cf0 — BoundsCheckedElementFieldWrite

**Summary:** Writes a value to offset 0xC of an array element at given index with bounds checking against the array element count.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleCollisionSpark (004cb620), WheelRenderObjectPerFrameUpdate (004cb860), ParticleTrailEmitter (004cbc50), ParticleInstanceUpdate (004cc1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | array element count limit |
| this | 0x34 | R | — | element data array pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If index a2 >= element count (this[11]) → skip and return (BLOCKED: out of bounds). PASSES: index within bounds → write a3 to element's offset 0xC.
