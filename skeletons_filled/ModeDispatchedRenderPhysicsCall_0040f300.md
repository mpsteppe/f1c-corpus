## ModeDispatchedRenderPhysicsCall_0040f300 — ModeDispatchedRenderPhysicsCall

**Summary:** Dispatches vehicle physics processing based on mode: angular velocity integration for modes 0-5, sub-call + wheel contact transform for mode 6. Part of vehicle physics / render sync system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PerVehicleCameraUpdateIterator (004109d0), SessionStructureCleanup (00411120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | Mode selector (this[7], values 0-6) |
| this | 0x20 | R | — | Sub-object pointer (this[8]) passed to WheelContactTransform |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f360 | jpt_40F30B | R | Jump table for 7-case mode dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ae00 | VehicleOrientationFromAngularVelocityIntegration | Integrates angular velocity to update vehicle orientation |
| 004ef180 | WheelContactTransform | Computes wheel contact transform from sub-object data |
| 004f0430 | sub_4F0430 | Sub-call with float parameter (mode 6 only) |

**Guard conditions:** this[7] (mode) 0-5 → VehicleOrientationFromAngularVelocityIntegration. Mode 6 → sub_4F0430 + WheelContactTransform. default → skip/return.
