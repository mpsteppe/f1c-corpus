## SuspensionWheelDynamicsSolver_0043f7f0 — VehicleSuspensionConstraintSolver

**Summary:** Core per-frame vehicle suspension and wheel dynamics solver — computes constraint forces via an LCP (Linear Complementarity Problem) approach with Gram-Schmidt projection, evaluates suspension spring/damper curves from lookup tables, and integrates velocity states for 4 wheels across multiple suspension modes. Vehicle physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelDataCopy (004414d0), PhysicsStepFrame (00441600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1114) | 0x1C | R | — | wheel-3 constraint projection coefficient |
| *(this+0x1114) | 0x34 | R | — | wheel-3 constraint projection coefficient |
| *(this+0x1114) | 0x4C | R | — | wheel-3 constraint projection coefficient |
| *(this+0x141C) | 0x2C | R | — | wheel-3 body force accumulator (fx) |
| *(this+0x141C) | 0x44 | R | — | wheel-3 body force accumulator (fy) |
| *(this+0x141C) | 0x5C | R | — | wheel-3 body force accumulator (fz) |
| *(this+0x141C) | 0x14C | RW | — | wheel-3 accumulated impulse/velocity delta |
| *(this+0x141C) | 0x154 | RW | — | wheel-3 accumulated impulse/velocity delta |
| *(this+0x141C) | 0x15C | RW | — | wheel-3 accumulated impulse/velocity delta |
| *(this+0x15F0) | 0x2C | R | — | wheel-4 body force accumulator (fx) |
| *(this+0x15F0) | 0x44 | R | — | wheel-4 body force accumulator (fy) |
| *(this+0x15F0) | 0x5C | R | — | wheel-4 body force accumulator (fz) |
| *(this+0x15F0) | 0x14C | RW | — | wheel-4 accumulated impulse/velocity delta |
| *(this+0x15F0) | 0x154 | RW | — | wheel-4 accumulated impulse/velocity delta |
| *(this+0x15F0) | 0x15C | RW | — | wheel-4 accumulated impulse/velocity delta |
| *(this+0x3E8) | 0x1C | R | — | wheel-0 constraint projection coefficient |
| *(this+0x3E8) | 0x34 | R | — | wheel-0 constraint projection coefficient |
| *(this+0x3E8) | 0x4C | R | — | wheel-0 constraint projection coefficient |
| *(this+0x84C) | 0x1C | R | — | wheel-1 constraint projection coefficient |
| *(this+0x84C) | 0x34 | R | — | wheel-1 constraint projection coefficient |
| *(this+0x84C) | 0x4C | R | — | wheel-1 constraint projection coefficient |
| *(this+0xCB0) | 0x1C | R | — | wheel-2 constraint projection coefficient |
| *(this+0xCB0) | 0x34 | R | — | wheel-2 constraint projection coefficient |
| *(this+0xCB0) | 0x4C | R | — | wheel-2 constraint projection coefficient |
| this | 0x8 | R | — | time step / delta-time |
| this | 0x18 | R | — | vehicle body velocity x |
| this | 0x20 | R | — | vehicle body velocity y |
| this | 0x348 | RW | 0 | bump-stop state: per-wheel travel limit accumulator (wheel 0) |
| this | 0x34C | RW | 0 | bump-stop state: per-wheel travel limit accumulator (wheel 1) |
| this | 0x360 | R | — | suspension spring force lookup table pointer |
| this | 0x364 | R | — | suspension damper force lookup table pointer |
| this | 0x368 | R | — | auxiliary suspension parameter table pointer |
| this | 0x3E8 | R | — | wheel-0 dynamics struct base |
| this | 0x3EC | R | — | wheel-0 next dynamics struct link |
| this | 0x660 | RW | 0 | bump-stop state accumulator (wheel 2) |
| this | 0x664 | RW | 0 | bump-stop state accumulator (wheel 3) |
| this | 0x668 | R | — | auxiliary constraint parameter |
| this | 0x7AC | R | — | suspension travel limit / bump-stop position |
| this | 0x7C4 | R | — | suspension travel lower limit |
| this | 0x84C | R | — | wheel-1 dynamics struct base |
| this | 0xC10 | R | — | wheel-2 constraint projection |
| this | 0xC28 | R | — | wheel-2 constraint projection |
| this | 0xC2C | R | — | wheel-2 constraint projection |
| this | 0xC30 | R | — | wheel-2 constraint projection |
| this | 0xCB0 | R | — | wheel-2 dynamics struct base |
| this | 0x1074 | R | — | wheel-3 constraint projection |
| this | 0x108C | R | — | wheel-3 constraint projection |
| this | 0x1114 | R | — | wheel-3 dynamics struct base |
| this | 0x141C | R | — | wheel-3 body dynamics struct base |
| this | 0x15F0 | R | — | wheel-4 body dynamics struct base |
| this | 0x1C5C | RW | — | solved constraint force (axle 0) |
| this | 0x1C60 | RW | — | solved constraint force (axle 1) |
| this | 0x1C74 | R | — | suspension mode flag (0=standard, 1=per-wheel, 2=per-axle) |
| this | 0x1CF4 | R | — | bump-stop stiffness coefficient |
| this | 0x1CFC | R | — | bump-stop damping coefficient |
| this | 0x1D00 | RW | — | accumulated normal force (axle 1) |
| this | 0x1D04 | RW | — | accumulated normal force (axle 2) |
| this | 0x1E14 | R | — | wheel vertical velocity (W0) |
| this | 0x1E18 | R | — | wheel vertical velocity (W1) |
| this | 0x1E20 | R | — | wheel vertical velocity (W2) |
| this | 0x1E28 | R | — | wheel vertical velocity (W3) |
| this | 0x1E30 | R | — | body vertical velocity input |
| this | 0x1E38 | RW | — | accumulated constraint impulse |
| this | 0x1E3C | R | — | LCP constraint RHS (target velocity) |
| this | 0x1E50 | R | — | constraint Jacobian coefficient (W0) |
| this | 0x1E54 | R | — | constraint Jacobian coefficient (W1) |
| this | 0x1E58 | R | — | constraint Jacobian coefficient (W2) |
| this | 0x1E68 | R | — | effective inverse mass diagonal |
| this | 0x1E6C | R | — | effective inverse mass diagonal |
| this | 0x1E70 | R | — | effective inverse mass diagonal |
| this | 0x1EA4 | R | — | bump-stop activation threshold |
| this | 0x1EF0 | R | — | suspension mode 1 spring preload |

**Written-by note (persistence):**
- *(this+0x141C) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x141C) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x141C) 0x15C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x15C: recalc every frame — external poke does NOT persist
- this 0x348: recalc every frame — external poke does NOT persist
- this 0x34C: recalc every frame — external poke does NOT persist
- this 0x660: recalc every frame — external poke does NOT persist
- this 0x664: recalc every frame — external poke does NOT persist
- this 0x1C5C: recalc every frame — external poke does NOT persist
- this 0x1C60: recalc every frame — external poke does NOT persist
- this 0x1D00: recalc every frame — external poke does NOT persist
- this 0x1D04: recalc every frame — external poke does NOT persist
- this 0x1E38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e900 | dbl_59E900 | R | Physics_Double_59E900 [DERIVED] |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059ec10 | dbl_59EC10 | R | DoublePhysicsZero [DERIVED] |
| 0059ed08 | dbl_59ED08 | R | DissipationConstant [DERIVED] (also: ` — type 1 dissipation) |
| 0059ed10 | dbl_59ED10 | R | TimeStepScale [DERIVED] (also: time-step scaling factor) |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 0059ed20 | dbl_59ED20 | R | EnergyDissipationMult [DERIVED] (also: ` — energy dissipation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435290 | FloatEpsilonCompare | compares two doubles for near-equality (used for LCP complementarity check) |
| 00438930 | ConstraintProjectGramSchmidt | computes Gram-Schmidt projection coefficient for constraint direction |
| 005677b0 | sub_5677B0 | solves the 6x6 LCP system for constraint impulses |
| 005895a2 | sub_5895A2 | float-to-int truncation helper for lookup table indexing |

**Guard conditions:** The solver operates in a time-stepping loop (`while(2)` nested loops) driven by `a2` (time step remaining). Guard logic checks:
- Suspension travel bounds: if `*(this+0x7736) <= 2.0 && >= -2.0` — normal range, compute spring force; if outside ±2.0 — bump-stop limiting applies
- LCP convergence: `if (!v119) continue;` — if any wheel violated its constraint, re-solve
- Time step exhaustion: `if (v149 != a2) { a2 = a2 - v149; continue; }` — partial step taken, iterate remainder
- Constraint activation: determined by sign of wheel vertical velocity vs contact normal, driving the LCP active set
