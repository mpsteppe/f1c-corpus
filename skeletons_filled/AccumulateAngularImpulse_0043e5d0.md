## AccumulateAngularImpulse_0043e5d0 — ImpulseAndTorqueAccumulator

**Summary:** Accumulates linear impulse and computed torque (cross product of relative position × impulse) from a collision contact into the vehicle's accumulator buffers. Part of vehicle physics collision response.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleContactForceAccumulation (004ebc60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x4 | R | — | contact point position X (collision data struct) |
| *(this+0x15F0) | 0xC | R | — | contact point position Y |
| *(this+0x15F0) | 0x14 | R | — | contact point position Z |
| this | 0x15F0 | R | — | pointer to collision contact data struct |
| this | 0x1F04 | RW | — | accumulated linear impulse X component |
| this | 0x1F0C | RW | — | accumulated linear impulse Y component |
| this | 0x1F14 | RW | — | accumulated linear impulse Z component |
| this | 0x1F1C | RW | — | accumulated angular impulse (torque) X component |
| this | 0x1F24 | RW | — | accumulated angular impulse (torque) Y component |
| this | 0x1F2C | RW | — | accumulated angular impulse (torque) Z component |

**Written-by note (persistence):**
- this 0x1F04: recalc every frame — external poke does NOT persist
- this 0x1F0C: recalc every frame — external poke does NOT persist
- this 0x1F14: recalc every frame — external poke does NOT persist
- this 0x1F1C: recalc every frame — external poke does NOT persist
- this 0x1F24: recalc every frame — external poke does NOT persist
- this 0x1F2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cbb10 | unk_7CBB10 | R | Collision_ContactBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044fee0 | CollisionImpulseAccumulator | resolves accumulated impulse against contact constraint |

**Guard conditions:** no branches — always executes full accumulation path
