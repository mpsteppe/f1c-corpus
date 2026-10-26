## CollisionContactStateDetection_0054d7a0 — Collision contact state detection

**Summary:** Determines collision contact state (contact, near-contact, or separated) between two collision objects by computing distance and testing against threshold radii. Evaluates collision plane equations for contact classification. Part of the physics/collision detection system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNodeStateUpdateWithTransform (005569f0), sub_556B10 (00556b10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Contact state word; low 3 bits encode state (1=potential, 2=separated, 4=contact), bit 4 selects contact mode path |
| this | 0x18 | R | — | Contact threshold margin (float); used for plane distance comparison |
| this | 0xF4 | R | — | Inner contact radius (float); minimum distance for contact detection |
| this | 0xF8 | R | — | Outer contact radius (float); maximum distance for contact detection |
| this | 0xFC | R | — | Contact plane count threshold; if > 4 triggers alternate separation logic |

**Written-by note (persistence):**
- this 0x14: state rewritten each call (bits 0-2 encode current contact state); survives between calls but updated each frame

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Entry: checks `this[20] & 0x10` (bit 4 of state word at +0x14) to select contact mode path. If NOT set, PASSES: uses simple radius check (this[0xF4] < v15 < this[0xF8] → contact state 4). If set, PASSES: uses plane-count-based logic with threshold this[0xFC] and optional flag a4; contact state 1 if near, 2 if penetrating or separated. If no condition matches, sets state 4 (contact).
