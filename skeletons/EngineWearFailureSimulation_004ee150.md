## EngineWearFailureSimulation_004ee150 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3D64 | RW | 2139095039 | [LLM] |
| this | 0x3D68 | RW | 2139095039 | [LLM] |
| this | 0x3D6C | RW | 2139095039 | carConditions [CONFIRMED] |
| this | 0x3D70 | RW | 2139095039 | [LLM] |

**Written-by note (persistence):**
- this 0x3D64: recalc every frame — external poke does NOT persist
- this 0x3D68: recalc every frame — external poke does NOT persist
- this 0x3D6C: recalc every frame — external poke does NOT persist
- this 0x3D70: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7e0 | dbl_59E7E0 | R | LookupThreshold_14 [DERIVED] |
| 005ad208 | dbl_5AD208 | R | LifetimeClampThreshold [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |
| 008aae70 | dword_8AAE70 | R | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008acf9c | flt_8ACF9C | R | TotalRaceLaps [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3ce0 | RandomNoiseValueGenerator | [LLM] |
| 0053ac70 | EmptyStubWithFlagCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
