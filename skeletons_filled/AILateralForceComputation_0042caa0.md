## AILateralForceComputation_0042caa0 — VehicleLateralInteractionForce

**Summary:** Computes lateral interaction forces between all vehicle pairs. Phase 1 calculates per-vehicle direction vectors and curvature radius from velocity. Phase 2 accumulates pairwise proximity-weighted forces and writes resultant vector (x,z components) to each vehicle struct at offset 14948.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e888 | flt_59E888 | R | TwoPi [DERIVED] (also: ` â€” 2Ï€ (360Â° in radians) |
| 0059e8a8 | flt_59E8A8 | R | AIOvertakeThreshold [DERIVED] |
| 0059e9e0 | flt_59E9E0 | R | ColorChannelScaleFactor [DERIVED] |
| 0059e9e4 | flt_59E9E4 | R | ForceBiasTerm [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Outer loop gated by VehicleCount > 0. Inner pairwise loop skips same-vehicle pairs (i != v17). Direction comparison uses floating-point angle tolerance tests.
