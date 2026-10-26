## LinearSearchWithLargeStructStride_0056ead0 — LinearSearchVehiclePhysicsBodyByString

**Summary:** Searches a linear array of 580-byte vehicle physics body structs for an element matching the given string, returning a pointer to the matching element or 0 if not found.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsBodyNameMapping (00438da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of elements in the vehicle physics body array |
| this | 0x4 | R | — | Pointer to base of vehicle physics body array (stride 580) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | Case-insensitive string comparison |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | <= | 0 | Array element count |

**Guard interpretation:** PASSES when *this > 0 — iterates array calling sub_588410 until match found, returns pointer to matching element. BLOCKED (returns 0 immediately) when *this <= 0 (empty array).
