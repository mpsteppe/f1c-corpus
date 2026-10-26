## SpeedValueSetterWithGlobalMirror_004f1890 — SpeedValueSetterWithGlobalMirror

**Summary:** Sets per-instance speed value and conditionally mirrors to global when rigid body constraint is absent. Part of speed/value management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), sub_429960 (00429960), PitStopDecisionTireCompound (0042a3d0), AISteeringRacingLineCorrection (0042b0e0), PitStopOperationTimer (004a6340), PitStopProgress (004a68b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | Rigid body constraint pointer (mirror gate) |
| this | 0x3978 | RW | — | Speed/throttle value set from a2 |

**Written-by note (persistence):**
- this 0x3978: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c75c4 | dbl_7C75C4 | W | GlobalSpeedTime (double) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Sets local speed value unconditionally. Then checks rigid body ptr (this+0x32BC). PASSES (mirrors value to global dbl_7C75C4) when ptr is zero. BLOCKED (no global write) when ptr is nonzero.
