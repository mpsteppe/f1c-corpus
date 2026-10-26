## ArrayOfStructLinearSearchByID_00410b80 — ArrayOfStructsLinearSearchByID

**Summary:** Linear search through array of structs comparing first DWORD (ID field) against `a2`. Returns pointer into parallel result array (36-byte stride per element) if found, 0 if not found. Used by collision detection system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionDetectionSystem (004ea970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | R | — | Element count of search array |
| this | 0x40 | R | — | Base address of result array (36-byte per element stride) |
| this | 0x44 | R | — | Base address of search array (0xC6-byte per element stride) |
| this | 0x114 | R | — | First DWORD of each search element — ID field being compared |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[0x3C] (count) <= 0 → block, return 0 (not found). Loop exits when index >= count → block, return 0 (not found). PASS: element ID matches `a2` → return result array pointer.
