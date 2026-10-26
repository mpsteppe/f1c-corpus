## PhysicsGearShiftLogicWithThresholds_00426330 — PhysicsGearShiftLogic

**Summary:** AI gear shift logic with multiple guard conditions. Handles upshifting (with traction check), downshifting, reverse gear (driverStatus 6), pit mode (carConditions 2), and a shift timer delay. Calls RaceStartCountdownStateUpdate to perform the actual gear change.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x37CC | R | — | traction X threshold (compared to 0.8 — must exceed for upshift) |
| this | 0x38C4 | R | — | traction Y threshold (compared to 0.8 — must exceed for upshift) |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] — compared to shift RPM threshold |
| this | 0x39FC | R | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x3A04 | R | — | maximum gear count (upper bound for upshift) |
| this | 0x3A10 | R | — | shift timer — if > 0.0, blocks all shifts (shift cooldown) |
| this | 0x3A18 | R | — | shift RPM threshold — current RPM compared against this for upshift decision |
| this | 0x3D6C | R | — | carConditions [CONFIRMED] == 2 (pit mode) |
| this | 0x4510 | R | — | driverStatus [CONFIRMED] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ef930 | RaceStartCountdownStateUpdate | performs actual gear change (upshift/downshift/neutral) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3D6C | == | 2 | carConditions [CONFIRMED] — car in pit lane / special mode |
| this | 0x4510 | == | 6 | driverStatus [CONFIRMED] — reversing |

**Guard interpretation:** BLOCKED (early return) if: shift timer (0x3A10) > 0.0, OR driverStatus == 6 (reverse — forces neutral via RaceStartCountdownStateUpdate(-1)), OR carConditions == 2 (pit mode — forces neutral gear), OR gear is neutral (0) or reverse (-1) and goes to upshift check, OR RPM below threshold AND traction insufficient (either X or Y <= 0.8). Upshift proceeds only when RPM < threshold AND traction adequate; downshift when RPM >= threshold AND gear > 1.
