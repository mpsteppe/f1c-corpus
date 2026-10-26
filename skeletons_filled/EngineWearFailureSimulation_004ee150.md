## EngineWearFailureSimulation_004ee150 — engine wear/failure simulation

**Summary:** Initializes 4 engine wear values to FLT_MAX, optionally computes wear using noise generator and session parameters when engine wear mode is active (1 or 2). Part of engine damage/wear system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3D64 | RW | 2139095039 | engine wear value slot 0 (initialized to FLT_MAX) |
| this | 0x3D68 | RW | 2139095039 | engine wear value slot 1 (initialized to FLT_MAX) |
| this | 0x3D6C | RW | 2139095039 | carConditions [CONFIRMED] — engine wear value slot 2 |
| this | 0x3D70 | RW | 2139095039 | engine wear value slot 3 (initialized to FLT_MAX) |

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
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3ce0 | RandomNoiseValueGenerator | generates noise value for engine wear randomization |
| 0053ac70 | EmptyStubWithFlagCheck | checks engine wear mode flags (called with 2 on enter, 1 on exit) |

**Guard conditions:** dword_7CEA5C (EngineWearMode) > 0 AND <= 2 → PASS (compute 4 wear values with noise). BLOCKED: otherwise → skip wear computation, return initialized FLT_MAX values.
