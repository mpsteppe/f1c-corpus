## FindNearestVehicle_004a4710 — NearestVehicleFinder

**Summary:** Iterates through the global vehicle pointer array (dword_7C54F0) to find the vehicle closest (by positive SpeedDeltaComputation) to a target vehicle identified by index a2. Uses two different distance-computation paths depending on whether the candidate pointer is null (fallback to base vehicle data). Returns the closest vehicle pointer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** OpponentProximityScanTeamRecognition (0042a7d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] — pointer to array of vehicle pointers |
| 007c5690 | byte_7C5690 | R | InitStateFlag [DERIVED] — end sentinel for vehicle array iteration |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00426cc0 | SpeedDeltaComputation | Computes a delta/distance metric between two vehicles (returns positive float) |
| 0042add0 | AIDelegateCall | Retrieves an AI-related value from the candidate vehicle for distance computation |

**Guard conditions:** Checks `*(_DWORD *)&this[4 * a2]` is non-null (target vehicle exists). PASSES when target pointer is valid. BLOCKED entirely (returns 0) when target pointer is null.