## PhysicsCollisionDamageDNFDetection_00438690 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBC | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0xD4 | RW | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x3D4 | R | — | [LLM] |
| this | 0x3E4 | RW | 0 | [LLM] |
| this | 0x3E8 | RW | 0 | [LLM] |
| this | 0x3EC | R | — | [LLM] |
| this | 0x3F4 | R | — | [LLM] |
| this | 0x3FC | R | — | [LLM] |
| this | 0x404 | RW | — | [LLM] |
| this | 0x40C | R | — | [LLM] |
| this | 0x414 | R | — | [LLM] |
| this | 0x41C | R | — | [LLM] |
| this | 0x424 | R | — | [LLM] |
| this | 0x42C | RW | 0 | [LLM] |
| this | 0x430 | RW | 0 | [LLM] |
| this | 0x434 | R | — | [LLM] |
| this | 0x43C | R | — | [LLM] |
| this | 0x444 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0x3E4: recalc every frame — external poke does NOT persist
- this 0x3E8: recalc every frame — external poke does NOT persist
- this 0x404: recalc every frame — external poke does NOT persist
- this 0x42C: recalc every frame — external poke does NOT persist
- this 0x430: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — global force/torque reference) |
| 008afef4 | flt_8AFEF4 | R | Flt_PhysicsBrakeBalance [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041b200 | DisplayMessage0x4a | [LLM] |
| 004388d0 | Mat3x3MulVec | [LLM] |
| 005697a0 | StructCopyWithReciprocalDivision | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
