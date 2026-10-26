## StructCopyWithReciprocalDivision_005697a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionSetupSectionReader (00435410), PhysicsCollisionDamageDNFDetection (00438690), VehiclePhysicsInitializer (00439210), sub_43C250 (0043c250), CollisionInvMassStore (00459950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD4 | RW | — | [LLM] |
| this | 0xDC | RW | — | [LLM] |
| this | 0xE4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist
- this 0xE4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00569410 | InertiaTensorWorldSpaceTransform | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
