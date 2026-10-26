## SortDriversByDistance_004c9c00 — SortVehiclesBySpeedSum

**Summary:** Copies vehicle pointers from global array (with offset +0xC), sorts them by combined speed sum using SortComparatorSpeedSum, and writes the speed sums into a results buffer at this+103. Used by weather particle system to prioritize effects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WeatherParticleUpdate (004cfcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Start of output buffer; holds sorted vehicle pointers followed by speed sum results |

**Written-by note (persistence):**
- this 0x0: Filled every call with sorted list and speed sums. Not persistent (fresh output array each call).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004c9ba0 | SortComparatorSpeedSum | R | Comparator function passed to sort routine; compares (speed_0x738 + speed_0x740) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005890aa | sub_5890AA | Sort routine — performs qsort-style sort on the pointer array using the provided comparator |

**Guard conditions:** Checks `dword_5C329C` (VehicleCount) > 0. If zero or negative, skips all processing.
