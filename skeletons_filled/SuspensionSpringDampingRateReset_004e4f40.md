## SuspensionSpringDampingRateReset_004e4f40 — SuspensionSpringDampingRateReset

**Summary:** Resets spring/damper forces to zero for all wheels, applies brake cooling post-treatment, and recomputes damping rates based on suspension type (0=push-rod, 1=double-wishbone, 2=third-spring). Core of per-frame suspension force initialization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStateMachine (004e4e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x354C | RW | 0 | Wheel 0 spring force accumulator |
| this | 0x3550 | RW | 0 | Wheel 1 spring force accumulator |
| this | 0x3554 | RW | 0 | Wheel 2 spring force accumulator |
| this | 0x3558 | RW | 0 | Wheel 3 spring force accumulator |
| this | 0x355C | RW | 0 | Wheel 0 damper force accumulator |
| this | 0x3560 | RW | 0 | Wheel 1 damper force accumulator |
| this | 0x35E4 | R | — | Wheel 2 damper rate |
| this | 0x35E8 | RW | — | Wheel 3 damper rate (updated) |
| this | 0x35EC | RW | — | Wheel 4 damper rate (updated) |
| this | 0x36E0 | RW | — | Computed spring rate for suspension type 0/1 |
| this | 0x36E4 | RW | — | Computed inv spring rate for suspension type 0/1 |
| this | 0x37D4 | R | — | Base spring rate parameter |
| this | 0x37D8 | RW | — | Computed spring rate for suspension type 2 |
| this | 0x37DC | RW | — | Computed inv spring rate for suspension type 2 |
| this | 0x38D0 | RW | — | Spring rate for wheel pair A |
| this | 0x38D4 | RW | — | Inv spring rate for wheel pair A |
| this | 0x3988 | R | — | Suspension type selector (0/1/2) |
| this | 0x39B4 | R | — | Motion ratio / leverage factor |
| this | 0x39C8 | RW | 0 | Damper force for additional damper |
| this | 0x39F0 | R | — | Third spring rate parameter |
| this | 0x39F4 | RW | — | Needle valve / bump rubber force |
| this | 0x3A04 | R | — | Anti-roll bar stiffness |

**Written-by note (persistence):**
- this 0x354C: recalc every frame — external poke does NOT persist
- this 0x3550: recalc every frame — external poke does NOT persist
- this 0x3554: recalc every frame — external poke does NOT persist
- this 0x3558: recalc every frame — external poke does NOT persist
- this 0x355C: recalc every frame — external poke does NOT persist
- this 0x3560: recalc every frame — external poke does NOT persist
- this 0x35E8: recalc every frame — external poke does NOT persist
- this 0x35EC: recalc every frame — external poke does NOT persist
- this 0x36E0: recalc every frame — external poke does NOT persist
- this 0x36E4: recalc every frame — external poke does NOT persist
- this 0x37D8: recalc every frame — external poke does NOT persist
- this 0x37DC: recalc every frame — external poke does NOT persist
- this 0x38D0: recalc every frame — external poke does NOT persist
- this 0x38D4: recalc every frame — external poke does NOT persist
- this 0x39C8: recalc every frame — external poke does NOT persist
- this 0x39F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e5080 | BrakeCoolingPostTreatment | Applies brake cooling and temperature decay when brake temp > 0 |

**Guard conditions:** Checks brake temperature (this+14852) > 0 to conditionally call BrakeCoolingPostTreatment. Checks this+14832 (suspension type ID) != this+14836 (cached type) to detect type change and recompute damping. On type change, checks result (new type): 0 -> compute standard spring rate; 1 -> compute with 0.25 factor for 4 wheels; 2 -> compute with 0.5 factor.
