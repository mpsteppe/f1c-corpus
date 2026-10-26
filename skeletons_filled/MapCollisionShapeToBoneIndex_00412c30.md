## MapCollisionShapeToBoneIndex_00412c30 — CollisionShapeToBoneIndexMapper

**Summary:** Maps collision shape IDs (1-12, 15, 20, 25, 30, 35, 40, 50) to bone indices (153-189). Each shape maps to a base value minus boolean flag (a4 != 0). Writes mapped bone index to output a1+8 and secondary value from sub_414180(0) to a1+12. Returns 1 on success, -1 if a2 != 0 or shape ID unrecognized.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceEventMessageDispatcher (00411bf0), SoundEventDispatcher (00411e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | mapped bone index (153-189), written on success |
| this | 0xC | RW | — | secondary value from sub_414180(0), written on success |

**Written-by note (persistence):**
- this 0x8: written on successful mapping; persists until overwritten
- this 0xC: written on success via sub_414180; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00412dc8 | jpt_412C54 | R | jump table for switch on shape ID (cases 1-12, 15, 20, 25, 30, 35, 40, 50) |
| 00412e18 | byte_412E18 | R | case value table for shape ID dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414180 | sub_414180 | computes secondary value (called with 0) written to a1+12 |

**Guard conditions:** a2 must be 0; a3 must be one of {1-12, 15, 20, 25, 30, 35, 40, 50}. If computed bone index v5 < 0 → skip write and return -1.
