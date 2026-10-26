## SpeedDeltaComputation_00426cc0 — SpeedDeltaComputation

**Summary:** Computes speed difference between AI's target vehicle (stored at this[0x4354]) and another vehicle (a2). Returns: 0.0 if a2 is null, speed difference if both exist, or -1.0 if AI has no target. Used by AI overtaking and nearest-vehicle logic.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A4110 (004a4110), FindNearestVehicle (004a4710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4354 | R | — | pointer to target/lead vehicle object (used to compute relative speed) |
| this | 0x43A0 | R | — | (referenced in IDB, not in decompiled body) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 == 0 (null target), returns 0.0 directly. If this[0x4354] (AI's target vehicle) is null, returns -1.0 (unknown/unset). Otherwise computes and returns speed delta.
