## AIRacingLine_00425920 — AI Racing Line Update

**Summary:** Per-frame AI racing line and speed-profile update — traverses waypoint chain, computes aerodynamic drag from lead car, builds speed profile with tire-force energy model, and determines throttle/brake targets based on overtaking feasibility and track position.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4400)+0x114) | 0xC | R | — | lead vehicle tangent X (direction component) |
| *(*(this+0x4400)+0x114) | 0x14 | R | — | lead vehicle tangent Y (direction component) |
| *(*(this+0x4400)+0x114) | 0x94 | R | — | lead vehicle / waypoint position X |
| *(*(this+0x4400)+0x114) | 0x9C | R | — | lead vehicle / waypoint position Y |
| *(this+0x4354) | 0x50 | R | — | waypoint track boundary X (right edge) |
| *(this+0x4354) | 0x54 | R | — | waypoint track boundary Y (left edge) |
| *(this+0x4400) | 0x0 | R | — | current waypoint position X |
| *(this+0x4400) | 0x8 | R | — | current waypoint position Y |
| *(this+0x4400) | 0x18 | R | — | waypoint radius / width property |
| *(this+0x4400) | 0x114 | R | — | pointer to next connected waypoint (lead vehicle link) |
| this | 0x34F8 | RW | 0 | speed profile index / waypoint counter | RenderZ [FACT] |
| this | 0x34FC | RW | 0 | secondary waypoint counter |
| this | 0x3500 | RW | 0 | tertiary waypoint counter |
| this | 0x4354 | R | — | pointer to current racing-line waypoint |
| this | 0x43A4 | RW | — | speed-profile array start (20 floats, remaining speed per waypoint) |
| this | 0x43F8 | RW | 0 | target waypoint pointer (set to next waypoint or cleared) |
| this | 0x43FC | RW | 1176255488 → 9999.0f | target waypoint speed (default max, overwritten by pass score) |
| this | 0x4400 | R | — | pointer to current waypoint data block (position, radius, links) |
| this | 0x4424 | RW | 0 | collision-avoidance distance (set from waypoint radius) |
| this | 0x4428 | R | — | track-boundary tolerance (off-track detection threshold) |
| this | 0x4434 | RW | 0 | brake target (0..1, computed from brake thermal model) |
| this | 0x4438 | RW | 0 | throttle target / grip coefficient (1.0 = full grip, 0 = idle) |
| this | 0x443C | RW | 0 | waypoint-reached flag (non-zero = active approach, cleared on pass) |
| this | 0x4440 | R | — | current speed (also: actualSpeed) | Speed [FACT] |
| this | 0x445C | RW | — | off-track flag (boolean: true when outside track boundaries) |
| this | 0x4468 | RW | 0 | waypoint-pass state flag (cleared when passing waypoint) |
| this | 0x446C | R | — | overtake-blocked flag (non-zero prevents overtake attempt) |
| this | 0x44B8 | R | — | brake-smoothing config value (max delta when track-config active) |
| this | 0x44C4 | R | — | brake-smoothing config value (max delta when track-config inactive) |
| this | 0x44CC | R | — | tire-energy consumption multiplier (applied to speed decay) |
| this | 0x4510 | RW | 5 | driver status (4 = race session, 5 = non-race) | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | distance to next waypoint (computed from 3D transform) |
| this | 0x454C | RW | 0 | lead vehicle ID / pointer (target vehicle for overtaking) | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 1 | waypoint-search reset flag (1 = reinitialize search) |
| this | 0x4554 | R | — | overtake-difficulty multiplier (scales pass-score threshold) |
| this | 0x45F4 | RW | 0 | some boolean state flag (cleared when behind waypoint) | ActiveFlag [FACT] |

**Written-by note (persistence):**
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x43A4: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x43FC: recalc every frame — external poke does NOT persist
- this 0x4424: recalc every frame — external poke does NOT persist
- this 0x4434: recalc every frame — external poke does NOT persist
- this 0x4438: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x445C: recalc every frame — external poke does NOT persist
- this 0x4468: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e854 | flt_59E854 | R | Flt_Physics_AI_Threshold [DERIVED] |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e8a8 | flt_59E8A8 | R | AIOvertakeThreshold [DERIVED] |
| 0059e8ac | flt_59E8AC | R | Unknown_Float_Physics [DERIVED] |
| 0059e8b0 | flt_59E8B0 | R | AIOvertakeDistThreshold [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8b8 | flt_59E8B8 | R | AI_VehicleDistanceThreshold [DERIVED] |
| 0059e8bc | flt_59E8BC | R | PhysicsConstant_59E8BC [DERIVED] |
| 0059e8c0 | flt_59E8C0 | R | AIVisionDistanceMult [DERIVED] |
| 0059e8c4 | flt_59E8C4 | R | SteeringDeltaThreshold [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 005c3160 | byte_5C3160 | RW | TrackConfigByte_5C3160 [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | session type (7 = race, determines driver status 4 vs 5) | SessionType [FACT] |
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403aa0 | SpatialTreeNearestNeighborSearch | finds nearest racing-line waypoint/segment to car position |
| 00426430 | sub_426430 | AI state reset / post-waypoint-pass cleanup subroutine |
| 0042a780 | AIComputePassScore | computes overtaking-feasibility score for a given waypoint/vehicle |
| 0042ae00 | AIClearStateFlags | clears AI state flags (resets overtake/blocking state) |
| 004e87e0 | BrakeThermalModel | computes brake thermal target from temperature model |
| 004e88b0 | TireGripCoefficient | returns tire grip coefficient for current conditions |
| 004e8b80 | AerodynamicForceCalc | computes aerodynamic drag force (slipstream effect from lead car) |
| 004e9100 | TireForce | computes tire force / energy consumption for speed-profile decay |
| 004efb20 | F_3DTransformWithMatrixMultiplication | transforms car-relative position to world coordinates |

**Guard conditions:** Multiple branches gate execution:

1. **Waypoint lookup guard** (line 67-70): if lead-vehicle ID (`this+0x454C`) is zero, or the nearest-neighbor result's linked vehicle doesn't match, fall back to alternate waypoint link. PASSES: matching vehicle ID found in waypoint chain.

2. **Active-approach guard** (line 71): both `this+0x443C` (waypoint-reached flag) and `this+0x4400` (waypoint pointer) must be non-null to enter 3D transform / aero-drag block. BLOCKED if either is zero.

3. **Aero-drag distance check** (line 80): if drag force (`v8 > 0.0`), clears waypoint-reached flag and records distance to lead car at `this+0x4524`. Below threshold the approach continues.

4. **Collision-avoidance distance** (lines 85-113): if `this+0x4424 == 0.0`, computes distance to lead vehicle. Three tiers: (a) if distance < 0.67 * threshold → too close, set avoidance radius to full waypoint width; (b) if 0.67*threshold ≤ distance < threshold → set avoidance radius to half; (c) if distance ≥ threshold → no action. Threshold capped at 28.0.

5. **Overtake distance check** (lines 116-143): similar three-tier distance check with different threshold formula (`radius * 1.2 + 17.0`, capped at 28.0). Sets avoidance radius and clears state flags.

6. **Behind-waypoint check** (lines 149-183): if dot product with waypoint tangent ≤ 0.0 (car behind the waypoint), enters full reset (LABEL_38): clears counters, resets driver status (4 for race session, 5 otherwise), resets waypoint search. Also triggers if distance < 5.0 → clears byte flag at `this+0x45F4`.

7. **Far-from-waypoint check** (line 184): if distance to waypoint > 0.5, applies aerodynamic drag force and sets throttle/brake targets. If speed * 0.3 > 0 → throttle mode (grip = 1.0), else → brake mode.

8. **Overtake-feasibility gate** (lines 205-206): if AI pass score < current speed * 1.05, sets `v26 = true`. Then checks waypoint type: if type == 1, uses fixed idle speed target; otherwise computes pass score.

9. **Speed-profile loop** (lines 214-276): fills 20-element speed array at `this+0x43A4`, iterating through waypoint chain. Stops when pass score ≥ current speed or speed decays to ≤ 0.0 via tire-force consumption model. BLOCKED if `this+0x454C` matches a waypoint's link (vehicle ahead on same chain).

10. **Brake/throttle decision** (lines 304-348): if speed ≤ 0.0 → brake mode. Sub-branches: (a) if overtake feasible (`v26`), use full brake thermal; (b) if off-track (`this+0x445C`), check overtake-blocked flag for brake vs coast; (c) otherwise, use 0.4 if speed ≤ 25.0, else 0.5. Brake target smoothed by configurable delta (`this+0x44B8` or `this+0x44C4` based on track config). If speed > 0.0 → throttle mode: tire grip coefficient clamped to previous + 0.2 max delta.
