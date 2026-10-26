## WheelContactTransform_004ef180 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ModeDispatchedRenderPhysicsCall (0040f300), PerVehicleCameraUpdateIterator (004109d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x704 | R | — | [LLM] |
| this | 0x708 | R | — | [LLM] |
| this | 0x70C | R | — | [LLM] |
| this | 0x710 | R | — | directionInTrack.x [CONFIRMED] |
| this | 0x714 | R | — | [LLM] |
| this | 0x718 | R | — | directionInTrack.y [CONFIRMED] |
| this | 0x71C | R | — | [LLM] |
| this | 0x720 | R | — | [LLM] |
| this | 0x724 | R | — | [LLM] |
| this | 0x3668 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3668: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c550 | CollisionNormalFromFeature | [LLM] |
| 004ce110 | WheelSurfaceContactFriction | [LLM] |
| 004ec020 | F_3DVectorAddition | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
