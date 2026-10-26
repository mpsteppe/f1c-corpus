## PerVehicleCameraUpdateIterator_004109d0 — PerVehicleCameraUpdateIterator

**Summary:** Iterates per-vehicle camera/physics update based on scoring gate mode: direct wheel contact (gate 2), mode-dispatched render physics + camera shake (gate 1 or other). Part of vehicle/camera/physics update tick.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of elements in array (loop bound) |
| this | 0x8 | R | — | Array pointer (this[2]) containing vehicle camera struct pointers |
| this | 0x6C | RW | — | Timestamp/last-update float compared against a2 for camera shake timing |

**Written-by note (persistence):**
- this 0x6C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f300 | ModeDispatchedRenderPhysicsCall | Dispatches physics/render processing based on mode |
| 0040f600 | CameraShakeRingBufferWrite | Writes camera shake data to ring buffer |
| 004ef180 | WheelContactTransform | Computes wheel contact transform from vehicle data |
| 004f0430 | sub_4F0430 | Sub-call with float parameter |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | <= | 0 | Element count; if <= 0, first loop is skipped entirely |

**Guard interpretation:** dword_8AB6E4 == 2 → wheel contact loop on all vehicles (by global count). dword_8AB6E4 != 2 → iterate array calling ModeDispatchedRenderPhysicsCall. Then if dword_8AB6E4 == 1 AND timestamp + 1.0 < a2 → camera shake for all elements where mode != 6. Otherwise → camera shake only for elements where mode != 6 AND flag at +0xA is set.
