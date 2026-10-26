## PhysicsStepFrame_00441600 — PhysicsStepFrame

**Summary:** Executes one physics step frame: shifts wheel state history, runs suspension wheel dynamics solver, processes two batch iteration helpers, finds minimum value via iteration function, and copies suspension data to physics sub-objects. Core per-frame physics step.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043f7f0 | SuspensionWheelDynamicsSolver | solves wheel suspension dynamics |
| 004412f0 | WheelStateHistoryShift | shifts wheel state history buffers |
| 00441450 | PhysicsSubObjectFree | copies suspension data to physics sub-objects |
| 0056ecf0 | sub_56ECF0 | batch iteration helper (unknown) |
| 0056ee40 | sub_56EE40 | batch iteration helper (unknown) |
| 0056f090 | IterateAndFindMinimumValueFromFunction | finds minimum value via iteration function |

**Guard conditions:** no branches — always executes full step sequence
