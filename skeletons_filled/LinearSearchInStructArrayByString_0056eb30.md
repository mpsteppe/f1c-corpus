## LinearSearchInStructArrayByString_0056eb30 — LinearSearchSuspensionBarByString

**Summary:** Searches a linear array of 72-byte suspension bar structs for an element matching the given string, skipping null entries, returning pointer to matching element or 0.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsBodyNameMapping (00438da0), SuspensionBarLookup (0043af50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Count of elements in the suspension bar array |
| this | 0x1C | R | — | Pointer to base of suspension bar array (stride 72) |

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
| this | 0x18 | <= | 0 | Array element count (this[6]) |

**Guard interpretation:** PASSES when this[6] > 0 — iterates array, skips null string entries (where this[7]+i is 0), calls sub_588410 to match, returns pointer to matching element. BLOCKED (returns 0 immediately) when this[6] <= 0 (empty array).
