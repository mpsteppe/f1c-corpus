## AIDriverStructInit_00424790 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48A4 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x396C | R | — | [LLM] |
| this | 0x413C | RW | 2139095039 | [LLM] |
| this | 0x4140 | RW | 0 | [LLM] |
| this | 0x4144 | RW | 18446744073709551615 | [LLM] |
| this | 0x4170 | RW | 2139095039 | [LLM] |
| this | 0x41B4 | RW | 18446744073709551615 | [LLM] |
| this | 0x42D8 | RW | 18446744072710897664 → -999.0f | [LLM] |
| this | 0x43F8 | RW | 0 | [LLM] |
| this | 0x4400 | RW | — | [LLM] |
| this | 0x4404 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x4410 | RW | 0 | RetiredFlag [FACT] |
| this | 0x4420 | RW | 0 | [LLM] |
| this | 0x442C | RW | 0 | [LLM] |
| this | 0x4430 | RW | 0 | [LLM] |
| this | 0x443C | RW | 0 | [LLM] |
| this | 0x444C | RW | 0 | [LLM] |
| this | 0x4454 | RW | — | [LLM] |
| this | 0x4458 | RW | 18446744073709551615 | [LLM] |
| this | 0x4460 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x4464 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x446C | RW | 0 | [LLM] |
| this | 0x447C | RW | 0 | [LLM] |
| this | 0x4484 | RW | 1232348144 → 999999.0f | [LLM] |
| this | 0x44A8 | RW | — | [LLM] |
| this | 0x44AC | RW | 10 | [LLM] |
| this | 0x44B0 | RW | 18446744073709551615 | [LLM] |
| this | 0x44B4 | RW | — | [LLM] |
| this | 0x44CC | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x44F8 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x4508 | RW | 0 | [LLM] |
| this | 0x450C | RW | 0 | [LLM] |
| this | 0x4510 | RW | 0 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | [LLM] |
| this | 0x4534 | RW | 0 | timeOfNextExit [CONFIRMED] |
| this | 0x4538 | RW | 1232348144 → 999999.0f | maxSpeed [CONFIRMED] |
| this | 0x453C | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x4540 | RW | 1086324736 → 6.0f | [LLM] |
| this | 0x4544 | RW | 1 | [LLM] |
| this | 0x4548 | RW | 0 | [LLM] |
| this | 0x454C | RW | 0 | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 0 | [LLM] |
| this | 0x4554 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x4558 | RW | 50 | [LLM] |
| this | 0x455C | RW | 0 | [LLM] |
| this | 0x4560 | RW | 0 | [LLM] |
| this | 0x4564 | RW | 0 | [LLM] |
| this | 0x4578 | RW | 1 | [LLM] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x45F8 | RW | 0 | [LLM] |
| this | 0x45FC | RW | 0 | [LLM] |
| this | 0x461C | RW | 1232348144 → 999999.0f | [LLM] |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x413C: recalc every frame — external poke does NOT persist
- this 0x4140: recalc every frame — external poke does NOT persist
- this 0x4144: recalc every frame — external poke does NOT persist
- this 0x4170: recalc every frame — external poke does NOT persist
- this 0x41B4: recalc every frame — external poke does NOT persist
- this 0x42D8: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x4400: recalc every frame — external poke does NOT persist
- this 0x4404: recalc every frame — external poke does NOT persist
- this 0x4410: recalc every frame — external poke does NOT persist
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x442C: recalc every frame — external poke does NOT persist
- this 0x4430: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x444C: recalc every frame — external poke does NOT persist
- this 0x4454: recalc every frame — external poke does NOT persist
- this 0x4458: recalc every frame — external poke does NOT persist
- this 0x4460: recalc every frame — external poke does NOT persist
- this 0x4464: recalc every frame — external poke does NOT persist
- this 0x446C: recalc every frame — external poke does NOT persist
- this 0x447C: recalc every frame — external poke does NOT persist
- this 0x4484: recalc every frame — external poke does NOT persist
- this 0x44A8: recalc every frame — external poke does NOT persist
- this 0x44AC: recalc every frame — external poke does NOT persist
- this 0x44B0: recalc every frame — external poke does NOT persist
- this 0x44B4: recalc every frame — external poke does NOT persist
- this 0x44CC: recalc every frame — external poke does NOT persist
- this 0x44F8: recalc every frame — external poke does NOT persist
- this 0x4508: recalc every frame — external poke does NOT persist
- this 0x450C: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x4534: recalc every frame — external poke does NOT persist
- this 0x4538: recalc every frame — external poke does NOT persist
- this 0x453C: recalc every frame — external poke does NOT persist
- this 0x4540: recalc every frame — external poke does NOT persist
- this 0x4544: recalc every frame — external poke does NOT persist
- this 0x4548: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x4554: recalc every frame — external poke does NOT persist
- this 0x4558: recalc every frame — external poke does NOT persist
- this 0x455C: recalc every frame — external poke does NOT persist
- this 0x4560: recalc every frame — external poke does NOT persist
- this 0x4564: recalc every frame — external poke does NOT persist
- this 0x4578: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist
- this 0x45F8: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist
- this 0x461C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea2d0 | dword_5EA2D0 | R | AIConfigZeroFloat [DERIVED] |
| 005ea3e8 | flt_5EA3E8 | R | AIInitTractionControl [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403aa0 | SpatialTreeNearestNeighborSearch | [LLM] |
| 00403f70 | ArrayOfStructIndexedFieldCopy | [LLM] |
| 00424080 | sub_424080 | [LLM] |
| 00424ac0 | AIDifficultyInterpolation | [LLM] |
| 00424cd0 | AICommandMessageQueueDispatcher | [LLM] |
| 00429960 | sub_429960 | [LLM] |
| 0042ae00 | AIClearStateFlags | [LLM] |
| 004a5c10 | GuardedCallWithCheck | [LLM] |
| 004f1510 | ScaleAudioPitch | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
