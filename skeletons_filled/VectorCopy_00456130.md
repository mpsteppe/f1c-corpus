## VectorCopy_00456130 — Vector3Copy_0x18

**Summary:** Copies three consecutive DWORDs from source to struct fields at offsets 0x18, 0x1C, 0x20 (elements [6], [7], [8]).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_457000 (00457000), sub_4572B0 (004572b0), CollisionResponseWithRandomPerturbation (00457a00), StateActivatedPositionSaveRestore (00457b00), F_2DTransformStructCopy (00457b60), sub_4585E0 (004585e0), sub_458DF0 (00458df0), ComponentTransformInitializer (00459010), sub_459330 (00459330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | RW | — | X component (element [6]) |
| this | 0x1C | RW | — | Y component (element [7]) |
| this | 0x20 | RW | — | Z component (element [8]) |

**Written-by note (persistence):**
- this 0x18: always written when a2 non-null. Overwritten each call; external poke survives.
- this 0x1C: same as 0x18.
- this 0x20: same as 0x18.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 nullable; copy occurs only when a2 is non-null.
