## EulerToRotationMatrix_00566e40 — EulerAnglesToRotationMatrix

**Summary:** Converts 3 Euler angles (a1[0..2] = pitch, yaw, roll) into a 3x3 rotation matrix (a2[0..8], row-major). Pure trigonometric computation, no side effects.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraModeViewportUpdate (00409a00), AISteeringRacingLineCorrection (0042b0e0), VehicleMainPhysicsUpdate (004441f0), sub_4A3320 (004a3320), Camera (004a3b50), VehicleProximityCollisionDetection (004a5fa0), VehicleVisibilityCulling (004b3dc0), sub_4BC9B0 (004bc9b0), VehiclePhysicsTimeStep (004c73f0), sub_4D0110 (004d0110), ConditionalAudioParamSetup (004dfa60), AIRacingLinePathFollowing (004e9ca0), CoordinateTransformWithOffset (004ef6c0), AIVehiclePathPositionTracking (004ef7c0), VehicleYawRotationRecoveryController (004f1c40), AudioParameterInterpolation (004ff680)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output matrix row 0 column 0 |
| this | 0x4 | RW | — | output matrix row 0 column 1 |
| this | 0x8 | RW | — | output matrix row 0 column 2 |
| this | 0xC | RW | — | output matrix row 1 column 0 |
| this | 0x10 | RW | — | output matrix row 1 column 1 |
| this | 0x14 | RW | — | output matrix row 1 column 2 |
| this | 0x18 | RW | — | output matrix row 2 column 0 |
| this | 0x1C | RW | — | output matrix row 2 column 1 |
| this | 0x20 | RW | — | output matrix row 2 column 2 |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — pure computation function with no branches or early returns.
