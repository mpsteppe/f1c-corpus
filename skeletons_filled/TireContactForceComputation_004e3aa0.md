## TireContactForceComputation_004e3aa0 — TireContactForceComputation

**Summary:** Computes tire contact forces — queries collision normal from track surface, calculates contact penetration depth, spring/damper force, and lateral/longitudinal friction forces. Core of tire-ground interaction model.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceCalculationSpringDamperTorque (004e5470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Tire contact position X |
| this | 0x4 | R | — | Tire contact position Y |
| this | 0x8 | R | — | Tire contact position Z |
| this | 0xC | R | — | Contact normal / surface orientation X |
| this | 0x14 | R | — | Suspension force direction X |
| this | 0x18 | R | — | Suspension force direction Y |
| this | 0x1C | R | — | Suspension force direction Z |
| this | 0x20 | R | — | Tire travel/deflection |
| this | 0x34 | RW | — | Contact velocity / slip velocity X |
| this | 0x38 | RW | — | Contact velocity / slip velocity Y |
| this | 0x3C | RW | — | Contact velocity / slip velocity Z |
| this | 0x40 | RW | — | Contact force result X |
| this | 0x44 | RW | — | Contact force result Y |
| this | 0x60 | R | — | Tire radius |
| this | 0x74 | RW | — | Tire contact patch depth / penetration |
| this | 0x78 | R | — | Tire stiffness coefficient |
| this | 0x7C | R | — | Tire damping coefficient |
| this | 0x90 | R | — | Friction coefficient |
| this | 0xCC | RW | — | Lateral force X |
| this | 0xD0 | RW | — | Lateral force Y |
| this | 0xD4 | RW | — | Lateral force Z |
| this | 0xE4 | R | — | Wheel angular velocity |
| this | 0xE8 | RW | — | Longitudinal force |
| this | 0xEC | R | — | Load sensitivity parameter |
| this | 0xF0 | R | — | Camber angle parameter |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0xCC: recalc every frame — external poke does NOT persist
- this 0xD0: recalc every frame — external poke does NOT persist
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0xE8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ad168 | flt_5AD168 | R | DWLimitThreshold [DERIVED] (also: ` — suspension type threshold (double-wishbone limit) |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c550 | CollisionNormalFromFeature | Queries collision/track surface normal at contact point |

**Guard conditions:** Checks CollisionNormalFromFeature return value. If NULL (no collision surface), sets default normal (0,1,0) and infinite penetration. Then checks penetration depth (this[29]) >= 0. If negative (no contact), zeroes spring and damper forces. Within contact, checks this[15] (directional cosine) <= 0.985 to select between full friction model and simplified model.
