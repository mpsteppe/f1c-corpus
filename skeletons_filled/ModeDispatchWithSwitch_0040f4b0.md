## ModeDispatchWithSwitch_0040f4b0 — ModeDispatchWithSwitch

**Summary:** Dispatches collision processing based on mode: runs computation + collision impulse for modes 0-5, or vehicle contact force accumulation for mode 6. Part of collision/physics response system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | Mode selector (this[7], values 0-6) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f52c | jpt_40F4BB | R | Jump table for 7-case mode dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f0d0 | ShortComputation_f0d0 | Guarded computation (if ID != -1) |
| 004599c0 | CollisionContactImpulse | Computes collision contact impulse response |
| 004ebc60 | VehicleContactForceAccumulation | Accumulates vehicle contact forces |

**Guard conditions:** this[7] (mode) 0-5 → ShortComputation_f0d0 + CollisionContactImpulse. Mode 6 → VehicleContactForceAccumulation. default → skip/return.
