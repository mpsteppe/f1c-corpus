# Chain: Aero/Engine Parameter Setup — Aerodynamics Computation

Seed: FUN_004f18c0  |  System: docs/18-physics-dynamics.md  |  Depth: 2  |  Functions: 9

---

## Overview

Computes aerodynamic and engine parameters from vehicle setup data. Reads setup type, resolves setup configuration, then computes engine braking torque, drag coefficient, front/rear downforce, and center of pressure. Applies setup to vehicle dynamics and optionally initializes physics subsystem.

## Call Tree

```
FUN_004f18c0 — Aero/Engine Parameter Setup  [vehicle setup load]
  +-- FUN_004d7570 — resolve setup [undocumented]
  +-- FUN_004a4830 — Tire Compound Name → ID Mapping [get vehicle ctx]
  |     +-- FUN_00588410 — name match
  +-- FUN_004e2370 — MultiplayerSessionType [setup]
  |     +-- FUN_004e23ad — session type check
  |     +-- FUN_0059db09 — assert
  +-- FUN_004d6ae0 — Vehicle Suspension Force Helper [aero lookup]
  +-- FUN_004d5ea0 — Computes ratio with divisor clamped [aero balance]
  +-- FUN_004e8010 — Tire Brush Model Force Solver [apply setup]
  |     +-- FUN_005895a2 — math/solver
  |     +-- FUN_004e8200 — brush model apply
  +-- FUN_0043da10 — physics init [undocumented]
```

## Step-by-Step Trace

### Level 0: FUN_004f18c0 — Aero/Engine Parameter Setup

**Trigger:** Called during vehicle setup loading (no callers in knowledge graph).
**Called by:** No callers in knowledge graph (likely called from vehicle setup chain).
**Purpose:** Computes aero parameters from setup data and applies to vehicle.

**Key actions:**
1. Reads setup type (param_3), resolves via FUN_004d7570
2. Distinguishes vehicle index 0 vs 1 for aero parameter selection
3. Computes engine braking torque from aero map data
4. Computes drag coefficient from setup CdA and air density
5. Computes front downforce = CdA_front * air_density * speed² / 2
6. Computes rear downforce as sum of front/rear CdA * multiplier
7. Sets center of pressure: if aero_map[0x21] > 0, CoP = 1.0 / aero_map[0x21], else 16.0
8. Calls FUN_004d5ea0 with aero balance values
9. If setup enabled: calls FUN_004e8010 to apply
10. If no wheel controller: calls FUN_0043da10 to init physics

### Level 1: FUN_004d7570 — Resolve Setup [undocumented]

**Trigger:** Resolves setup type and config.
**Purpose:** Reads setup configuration data for aero parameter computation.

### Level 1: FUN_004a4830 — Tire Compound Name → ID Mapping

**Trigger:** Gets vehicle context for aero setup.
**Purpose:** Maps tire compound name string to numeric compound ID.

### Level 1: FUN_004e2370 — MultiplayerSessionType

**Trigger:** Checks session type during setup.
**Purpose:** Determines if current session is multiplayer, affects aero setup.

### Level 1: FUN_004d6ae0 — Vehicle Suspension Force Helper [aero lookup]

**Trigger:** Looks up aero map data.
**Purpose:** Reads aerodynamic map data from vehicle setup struct.

### Level 1: FUN_004d5ea0 — Ratio Computation [aero balance]

**Trigger:** Computes aero balance ratio.
**Purpose:** Computes front/rear aero balance with divisor clamped to minimum threshold.

### Level 1: FUN_004e8010 — Tire Brush Model Force Solver [apply setup]

**Trigger:** Applies computed aero parameters to vehicle.
**Purpose:** Applies new aero setup to vehicle dynamics model.

### Level 1: FUN_0043da10 — Physics Init [undocumented]

**Trigger:** Initializes physics subsystem if needed.
**Purpose:** First-time physics system initialization for new vehicle.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Setup type | param_3 | FUN_004d7570 | resolved config |
| Drag | CdA, air density | drag = CdA * rho | drag coefficient |
| Front downforce | CdA_front, speed | downforce = CdA*rho*v²/2 | front downforce |
| Rear downforce | CdA_rear, mult | sum * mult | rear downforce |
| CoP | aero_map[0x21] | 1/val or 16.0 | center of pressure |
| Apply | all computed | FUN_004e8010 | vehicle dynamics updated |

## Notes

- 7 callees, all shallow (depth 1-2).
- Two documented functions in depth: FUN_004a4830 and FUN_004e8010.
- FUN_004d7570 and FUN_0043da10 are [undocumented].
- Cross-system: FUN_004e8010 is in docs/06 (session logic) but used for aero apply.

---
