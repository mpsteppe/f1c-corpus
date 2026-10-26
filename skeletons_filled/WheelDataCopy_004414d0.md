## WheelDataCopy_004414d0 — WheelStateCopyAndPhysicsDispatch

**Summary:** Copies wheel state history forward (current→previous), copies delta state buffers for each wheel from the previous-state buffer into the current-state buffer, then runs the suspension wheel dynamics solver, two batch iterators, a per-body update function, and the sub-object data copy. Main wheel physics dispatch function.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x340 | RW | — | wheel state history slot 1 (copied to current) |
| this | 0x344 | RW | — | wheel state history slot 1 second field |
| this | 0x348 | R | — | wheel state history slot 2 (source) |
| this | 0x34C | R | — | wheel state history slot 2 second field |
| this | 0x350 | RW | — | wheel state history slot 3 (copied to current) |
| this | 0x354 | RW | — | wheel state history slot 3 second field |
| this | 0x15AC | R | — | current wheel state array pointer |
| this | 0x15B0 | R | — | previous wheel state array pointer |
| this | 0x162C | R | — | wheel state count |
| this | 0x1C5C | R | — | second buffer slot 0 (source for copy) |
| this | 0x1C60 | R | — | second buffer slot 0 second field |
| this | 0x1C64 | RW | — | second buffer slot 1 (target for copy) |
| this | 0x1C68 | RW | — | second buffer slot 1 second field |
| this | 0x1E38 | R | — | third buffer slot 0 (source) |
| this | 0x1E3C | R | — | third buffer slot 0 second field |
| this | 0x1E40 | RW | — | third buffer slot 1 (target) |
| this | 0x1E44 | RW | — | third buffer slot 1 second field |

**Written-by note (persistence):**
- this 0x340: recalc every frame — external poke does NOT persist
- this 0x344: recalc every frame — external poke does NOT persist
- this 0x350: recalc every frame — external poke does NOT persist
- this 0x354: recalc every frame — external poke does NOT persist
- this 0x1C64: recalc every frame — external poke does NOT persist
- this 0x1C68: recalc every frame — external poke does NOT persist
- this 0x1E40: recalc every frame — external poke does NOT persist
- this 0x1E44: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043f7f0 | SuspensionWheelDynamicsSolver | solves wheel suspension dynamics per frame |
| 00441450 | PhysicsSubObjectFree | copies suspension data to physics engine sub-objects |
| 0056ecf0 | sub_56ECF0 | batch iteration helper (unknown) |
| 0056ee40 | sub_56EE40 | batch iteration helper (unknown) |
| 0056f020 | IteratePhysicsBodiesCallUpdateFunction | iterates physics bodies calling per-body update |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15AC | > | 0 | wheel count — non-zero means wheels exist to process |

**Guard interpretation:** If wheel count (this+0x15AC) > 0, copy delta state buffers for each wheel. If 0 or negative, skip delta buffer copy step.
