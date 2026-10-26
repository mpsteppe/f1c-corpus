## PhysicsSubObjectFree_00441450 — PhysicsSubObjectDataCopy

**Summary:** Copies suspension data between physics sub-object slots (front/rear left/right) using SuspensionDataCopyToPhysicsEngine. Branches based on whether a shared suspension ID is set — either copies 4 times using the shared ID, or uses individual wheel suspension IDs. Part of vehicle suspension data management.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelDataCopy (004414d0), PhysicsStepFrame (00441600), VehiclePhysicsIntegrationStep (00441650), SteeringGeometryUpdate (00442060), sub_447780 (00447780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3EC | R | — | wheel 0 suspension data pointer (this+163*4) |
| this | 0x850 | R | — | wheel 1 suspension data pointer (this+532*4) |
| this | 0xCB4 | R | — | wheel 2 suspension data pointer (this+813*4) |
| this | 0x1118 | R | — | wheel 3 suspension data pointer (this+1094*4) |
| this | 0x141C | R | — | shared suspension ID selector (this+1287*4) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004389b0 | SuspensionDataCopyToPhysicsEngine | copies one wheel's suspension data to physics engine |

**Guard conditions:** if shared suspension ID (this+0x141C) is non-zero, use it for all 4 wheels; otherwise use individual wheel suspension pointers (this+813 and this+1094 for wheels 2,3).
