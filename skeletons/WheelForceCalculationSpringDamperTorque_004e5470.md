## WheelForceCalculationSpringDamperTorque_004e5470 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStateMachine (004e4e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x34F8 | R | — | RenderZ [FACT] |
| this | 0x34FC | R | — | [LLM] |
| this | 0x3500 | R | — | [LLM] |
| this | 0x3504 | R | — | [LLM] |
| this | 0x3508 | R | — | [LLM] |
| this | 0x350C | R | — | [LLM] |
| this | 0x354C | RW | — | [LLM] |
| this | 0x3550 | RW | — | [LLM] |
| this | 0x3554 | RW | — | [LLM] |
| this | 0x3558 | RW | — | [LLM] |
| this | 0x355C | RW | — | [LLM] |
| this | 0x3560 | RW | — | [LLM] |
| this | 0x3574 | R | — | [LLM] |
| this | 0x3588 | RW | — | [LLM] |
| this | 0x358C | R | — | [LLM] |
| this | 0x3594 | R | — | [LLM] |
| this | 0x3598 | RW | — | [LLM] |
| this | 0x359C | RW | — | [LLM] |
| this | 0x35A0 | RW | — | [LLM] |
| this | 0x35A8 | RW | — | [LLM] |
| this | 0x35B4 | R | — | [LLM] |
| this | 0x35C4 | RW | — | [LLM] |
| this | 0x35E0 | R | — | [LLM] |
| this | 0x35F4 | R | — | [LLM] |
| this | 0x3600 | R | — | [LLM] |
| this | 0x363C | RW | — | tirePuncture_RR [CONFIRMED] |
| this | 0x3640 | RW | — | [LLM] |
| this | 0x36A0 | RW | — | [LLM] |
| this | 0x36AC | R | — | [LLM] |
| this | 0x36BC | RW | — | [LLM] |
| this | 0x3734 | RW | — | tirePuncture_RL [CONFIRMED] |
| this | 0x3738 | RW | — | [LLM] |
| this | 0x37A4 | R | — | [LLM] |
| this | 0x37B4 | RW | — | [LLM] |
| this | 0x389C | R | — | [LLM] |
| this | 0x38AC | RW | — | [LLM] |
| this | 0x3960 | R | — | [LLM] |
| this | 0x3974 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x354C: recalc every frame — external poke does NOT persist
- this 0x3550: recalc every frame — external poke does NOT persist
- this 0x3554: recalc every frame — external poke does NOT persist
- this 0x3558: recalc every frame — external poke does NOT persist
- this 0x355C: recalc every frame — external poke does NOT persist
- this 0x3560: recalc every frame — external poke does NOT persist
- this 0x3588: recalc every frame — external poke does NOT persist
- this 0x3598: recalc every frame — external poke does NOT persist
- this 0x359C: recalc every frame — external poke does NOT persist
- this 0x35A0: recalc every frame — external poke does NOT persist
- this 0x35A8: recalc every frame — external poke does NOT persist
- this 0x35C4: recalc every frame — external poke does NOT persist
- this 0x363C: recalc every frame — external poke does NOT persist
- this 0x3640: recalc every frame — external poke does NOT persist
- this 0x36A0: recalc every frame — external poke does NOT persist
- this 0x36BC: recalc every frame — external poke does NOT persist
- this 0x3734: recalc every frame — external poke does NOT persist
- this 0x3738: recalc every frame — external poke does NOT persist
- this 0x37B4: recalc every frame — external poke does NOT persist
- this 0x38AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e664 | flt_59E664 | R | RenderTransformScale [DERIVED] |
| 0059e6e8 | flt_59E6E8 | R | TireDampingBlendFactor [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e3aa0 | TireContactForceComputation | [LLM] |
| 004e3d00 | WheelSpringDamperForceAndSteering | [LLM] |
| 0053ac70 | EmptyStubWithFlagCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
