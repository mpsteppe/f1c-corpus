## PhysicsForceVelocityClamping_0043ec80 — Velocity clamp and hybrid force-torque evaluation

**Summary:** Clamps two velocity state values (0x17A8, 0x17C0) against reference limits, evaluates quadratic force function, applies spring-damper computation with bias offsets, and computes quadratic torque. Part of vehicle wheel physics update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17A8 | RW | — | primary velocity/state value being clamped |
| this | 0x17C0 | RW | — | secondary velocity/state value being clamped |
| this | 0x1C00 | R | — | reference input to QuadFunctionEval |
| this | 0x1C08 | R | — | upper limit/reference for clamping 0x17A8 |
| this | 0x1C10 | R | — | upper limit/reference for clamping 0x17C0 |

**Written-by note (persistence):**
- this 0x17A8: conditional clamp — external poke survives only if within reference limit
- this 0x17C0: conditional clamp — external poke survives only if within reference limit

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059ec60 | dbl_59EC60 | R | SuspensionTravelOffset [DERIVED] |
| 0059ec90 | dbl_59EC90 | R | WearAccumulationRate [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043bb30 | QuadFunctionEval | evaluates quadratic function for force component from reference input |
| 0043bb80 | QuadraticForceTorqueCalculator | computes quadratic force/torque output |
| 0043bbd0 | SpringDamperCompute | computes spring-damper force with bias offsets |

**Guard conditions:** Two-branch clamping pattern: if value ≤ reference, assign value directly; else assign reference (upper limit). Additional second-stage clamps apply reference + bias offset (0.15, 0.12, 0.25) for intermediate computed values. No early return — all callees execute unconditionally.
