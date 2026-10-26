## TireModelInit_0043e050 — Tire model initialization

**Summary:** Initializes tire physics model: sets up tire parameters, parses vehicle HDV file, maps body names, initializes vehicle physics, sets brake bias, and cleans up allocated resources. Part of vehicle physics initialization pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LargeConfigFunctionWithPhysicsConstants (004e45b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | 0 | Cleared field (initialized to zero) |
| this | 0x64 | RW | 0 | Cleared field (initialized to zero) |
| this | 0x68 | RW | — | Computed from tire mode: 1.0 / (400 >> TireModelMode) |
| this | 0x1F00 | RW | — | Stores input parameter a2 (context handle) |

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
| 0042ddd0 | ScoreSlotDeallocator | Cleanup score slot allocator |
| 0042e320 | SessionStructInit | Initialize session data structure |
| 00438cc0 | BrakeBiasSetup | Setup brake bias parameters |
| 00438da0 | VehiclePhysicsBodyNameMapping | Map physics body names to entities |
| 00438f00 | sub_438F00 | Suspension geometry setup and body attachment |
| 00439210 | VehiclePhysicsInitializer | Main vehicle physics initialization |
| 0043c250 | sub_43C250 | Additional constraint setup |
| 004f34e0 | TireModelDataInit | Initialize tire model data structures |
| 004f4270 | TheSvmHdvVehicleFileParser | Parse HDV vehicle file for tire parameters |
| 00567740 | FPUControlWordMaskExtract | Save FPU control word for later restore |
| 00567780 | EmptyStub_7780 | Restore FPU control word if changed |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory resources |
| 005881c0 | __alloca_probe | Stack probe for large stack allocation |

**Guard conditions:** If file path string pointer is null, use default directory path (byte_5EA438). If FPU control word changed (!= 512), restore via EmptyStub_7780.
