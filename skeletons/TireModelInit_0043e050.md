## TireModelInit_0043e050 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LargeConfigFunctionWithPhysicsConstants (004e45b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | 0 | [LLM] |
| this | 0x64 | RW | 0 | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x1F00 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x64: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x1F00: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059ec70 | dbl_59EC70 | R | TireMultiplierFactor [DERIVED] |
| 005e5238 | dbl_5E5238 | W | TireTractionConstantSq [DERIVED] (also: ` — Tire traction constant squared) |
| 005e5240 | dbl_5E5240 | W | TireTractionConstant [DERIVED] (also: ` — Tire traction constant (computed) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ddd0 | ScoreSlotDeallocator | [LLM] |
| 0042e320 | SessionStructInit | [LLM] |
| 00438cc0 | BrakeBiasSetup | [LLM] |
| 00438da0 | VehiclePhysicsBodyNameMapping | [LLM] |
| 00438f00 | sub_438F00 | [LLM] |
| 00439210 | VehiclePhysicsInitializer | [LLM] |
| 0043c250 | sub_43C250 | [LLM] |
| 004f34e0 | TireModelDataInit | [LLM] |
| 004f4270 | TheSvmHdvVehicleFileParser | [LLM] |
| 00567740 | FPUControlWordMaskExtract | [LLM] |
| 00567780 | EmptyStub_7780 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 005881c0 | __alloca_probe | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
