## DotProductWithScaleOffset_00406060 — DotProductScaledPanBias

**Summary:** Computes [0.2-0.8] range pan/balance factor from 3D orientation dot product with fixed scale (0.6) and offset (+1.0, *0.5). Maps dot product to stereo position range. Part of 3D sound positioning system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundPositioningUpdate (00405b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | R | — | pointer to sub-struct containing orientation direction data |
| this | 0xC4 | R | — | unknown (not directly referenced in decompiled code) |
| this | 0xC8 | R | — | unknown (not directly referenced in decompiled code) |
| this | 0xCC | R | — | unknown (not directly referenced in decompiled code) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always computes the dot product and returns scaled result
