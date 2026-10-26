## AIVehiclePathPositionTracking_004ef7c0 — AIVehiclePathPositionTracking

**Summary:** Tracks AI vehicle position error against target path position, accumulates correction offsets, and ensures rigid body constraint is solved. Part of AI vehicle path following system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringRacingLineCorrection (0042b0e0), sub_4C6B60 (004c6b60), SceneRenderUpdate (004c6d90), LoopOverTwoParallelArrays (004d1030), SessionStateTransition (004ef5a0), VehicleYawRotationRecoveryController (004f1c40), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | Rigid body constraint pointer (null triggers re-solve) |
| this | 0x34B0 | R | — | Rotation matrix [0][0] |
| this | 0x34B4 | R | — | Rotation matrix [0][1] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | Rotation matrix [0][2] |
| this | 0x34C0 | R | — | Rotation matrix [1][0] |
| this | 0x34C4 | R | — | Rotation matrix [1][1] |
| this | 0x34C8 | R | — | Rotation matrix [1][2] |
| this | 0x34CC | R | — | Rotation matrix [2][0] |
| this | 0x34D0 | R | — | Rotation matrix [2][1] |
| this | 0x34D4 | RW | — | Position offset error X (accumulated) |
| this | 0x34D8 | RW | — | Position offset error Y (accumulated) |
| this | 0x34DC | RW | — | Position offset error Z (accumulated) |
| this | 0x34E0 | RW | — | Input orientation X (copied from a3) |
| this | 0x34E4 | RW | — | Input orientation Y (copied from a3) |
| this | 0x34E8 | RW | — | Input orientation Z (copied from a3) |
| this | 0x3A9C | RW | 0 | Constraint solve counter (reset to 0 each frame) |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34E0: recalc every frame — external poke does NOT persist
- this 0x34E4: recalc every frame — external poke does NOT persist
- this 0x34E8: recalc every frame — external poke does NOT persist
- this 0x3A9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e4b0 | RigidBodyConstraintSolve | Solves rigid body constraint for AI path position tracking |
| 004e9bd0 | F_3x3MatrixTransformWithTranslation | Transforms vector by 3x3 matrix with translation |
| 004ef680 | RideHeightDelta | Computes ride height delta 3-vector |
| 00566e40 | EulerToRotationMatrix | Converts Euler angles to 3x3 rotation matrix |

**Guard conditions:** Checks if rigid body constraint pointer (this+0x32BC) is null. PASSES (calls RigidBodyConstraintSolve) when null — re-solves constraint. BLOCKED (returns early with existing result) when pointer is non-null.
