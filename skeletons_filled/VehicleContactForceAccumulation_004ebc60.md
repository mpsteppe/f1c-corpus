## VehicleContactForceAccumulation_004ebc60 — Vehicle Collision Response Accumulator

**Summary:** Per-frame accumulation of contact forces from vehicle collisions: transforms local contact impulses through a rotation matrix into world-space linear and angular impulse accumulators, then dispatches to physics, particle effects, or pointer-computation subsystems based on a mode selector.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ModeDispatchWithSwitch (0040f4b0), ParticleEffectUpdateDispatch (004eb430), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | base-object field read for ConditionalStridePointerComputation in mode 2 |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | R | — | contact-processing mode selector (0=physics impulse, ≤1=spark effects, 2=pointer chain) |
| this | 0x34B0 | R | — | rotation matrix element (col 1, row 1) for contact-force world-transform |
| this | 0x34B4 | R | — | rotation matrix element (col 1, row 2) for contact-force world-transform |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | rotation matrix element (col 2, row 1) for contact-force world-transform |
| this | 0x34C0 | R | — | rotation matrix element (col 3, row 1) for contact-force world-transform |
| this | 0x34C4 | R | — | rotation matrix element (col 2, row 2) for contact-force world-transform |
| this | 0x34C8 | R | — | rotation matrix element (col 3, row 2) for contact-force world-transform |
| this | 0x34CC | R | — | rotation matrix element (col 2, row 3) for contact-force world-transform |
| this | 0x34D0 | R | — | rotation matrix element (col 3, row 3) for contact-force world-transform |
| this | 0x34EC | RW | — | accumulated local-space linear impulse X (frame sum) |
| this | 0x34F0 | RW | — | RenderX [FACT] |
| this | 0x34F4 | RW | — | RenderY [FACT] |
| this | 0x34F8 | RW | — | RenderZ [FACT] |
| this | 0x34FC | RW | — | accumulated local-space linear impulse X (reading+writing frame accumulator) |
| this | 0x3500 | RW | — | accumulated local-space linear impulse Y (reading+writing frame accumulator) |
| this | 0x3504 | RW | — | accumulated local-space linear impulse Z (reading+writing frame accumulator) |
| this | 0x3508 | RW | — | accumulated angular impulse component (torque axis 1) |
| this | 0x350C | RW | — | accumulated angular impulse component (torque axis 2) |
| this | 0x3518 | R | — | contact-force scalar multiplier (applied to linear impulses before accumulation) |
| this | 0x3528 | R | — | angular-impulse scale factor for cross-product component 1 |
| this | 0x352C | R | — | angular-impulse scale factor for cross-product component 2 |
| this | 0x3530 | R | — | angular-impulse scale factor for cross-product component 3 |

**Written-by note (persistence):**
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e5d0 | AccumulateAngularImpulse | feed angular-impulse data into the race physics system using race time |
| 0045eb00 | Vector3ScalarMultiply | multiply a 3D direction vector by a scalar |
| 00463dc0 | ConditionalStridePointerComputation | resolve a pointer from the game-module manager + base-object field (mode 2 path) |
| 004b2480 | UtilityFunction_2480 | post-process computed vector data after pointer resolution (mode 2 path) |
| 004b2580 | ShortVectorToFloatWithScale | convert packed short-int vector from resolved pointer to unscaled float vector |
| 004ea930 | sub_4EA930 | transform contact-point vector through inverse object rotation (local-to-world) |
| 004ec020 | F_3DVectorAddition | add two 3D float vectors in-place |
| 004ec050 | F_6FieldStructInit | initialise a 6-field struct from 6 double-precision scalar values |
| 004ec1a0 | CollisionSparkParticleEffects | spawn collision spark / debris particle effects at contact point |

**Guard conditions:** Field `this+0x32BC` (DWORD mode selector) controls all dispatch:
- `mode == 0`: PASSES — angular impulse accumulated via `AccumulateAngularImpulse` + 6-field struct init using contact data scaled by `a2[1] * 40.0`.
- `mode >= 0 && mode <= 1`: PASSES — if `a3` (char flag) is non-zero, calls `CollisionSparkParticleEffects`; otherwise no side effects.
- `mode == 2`: PASSES — resolves a pointer via `ConditionalStridePointerComputation`, converts short-vector to float, scales direction by contact multiplier, adds vectors, and calls `UtilityFunction_2480`.
- `mode < 0`: BLOCKED — all branches skipped, returns immediately.
- The linear/angular impulse accumulation (lines 60-81) runs unconditionally before the mode dispatch.

(End of file - total 73 lines)
