## PitStopOrderRank_004d1bc0 — Compute driver race rank

**Summary:** Computes a driver's race position by counting how many other drivers rank ahead according to DriverStandingComparator. For session type 7, returns direct position value from VEH array instead.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount — number of vehicles to iterate for ranking |
| 005f0738 | dword_5F0738 | R | VEH[0].0x4060 = position array — direct position lookup |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — vehicle pointers for driver index extraction |
| 007c56a4 | dword_7C56A4 | R | SessionType — if 7, use direct position instead of comparator |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d0c20 | DriverStandingComparator | Compares two drivers' standing; returns <0 if first is behind second |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| dword_7C56A4 | — | == | 7 | Session type gate |
| dword_5C329C | — | > | 0 | Vehicle count > 0 |

**Guard interpretation:** If session type == 7, return direct position from VEH array (skip ranking). Else if vehicle count > 0, iterate and count ahead drivers; if count <= 0, return 1 (default rank).
