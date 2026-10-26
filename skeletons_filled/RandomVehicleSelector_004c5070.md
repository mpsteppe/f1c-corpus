## RandomVehicleSelector_004c5070 — Get random vehicle entry from filtered list

**Summary:** Generates a random index from an internal 64-bit state, bounds-checks it against the linked list count, walks the list to the indexed node, and returns the corresponding vehicle entry pointer from the global vehicle array. Used for AI opponent vehicle selection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIOpponentSelection (004bf790), AIPathPerformanceFunction (004bfa00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c6760 | BoundsCheckedIndexSetter_6760 | Set and validate random index against list count; returns clamped index via v3/v4 |
| 005871f0 | ReadFieldAtOffset0x14 | Read 64-bit random state/seed from offset 0x14 of `this` |

**Guard conditions:** Returns 0 if `a2` < 0. Returns 0 if high part of `ReadFieldAtOffset0x14` result >= low part (invalid range from RNG). After `BoundsCheckedIndexSetter_6760`, returns 0 if resulting index `v3` >= list count `*(v4+20)` or list head `*(v4+8)` is null. Returns 0 if vehicle index from selected node is out of valid range [0, dword_8AC390).
