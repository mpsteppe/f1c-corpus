## LargeConfigFunctionWithPhysicsConstants_004e45b0 — VehiclePhysicsConfigAndStep

**Summary:** Initializes and runs one physics time step — initializes tire model, parses vehicle HDV file, computes integration sub-step parameters, executes suspension and tire force solvers, and frees temporary allocations. Part of vehicle physics update.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4898 | R | — | Object pointer for vehicle data access |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | R | — | Mode/state flag: 0 = needs init, 1-3 = active modes |
| this | 0x3498 | RW | 64 | Integration sub-step count (clamped 1-64) |
| this | 0x349C | RW | — | Step size squared for threshold comparison |
| this | 0x34A0 | RW | — | pitTime[0] [CONFIRMED] — primary physics time step |
| this | 0x34A4 | RW | — | Alternate step size for low-speed integration |
| this | 0x34A8 | RW | — | Current integration step value for sub-iterations |
| this | 0x34AC | RW | — | Session/race time at this physics step |

**Written-by note (persistence):**
- this 0x3498: recalc every frame — external poke does NOT persist
- this 0x349C: recalc every frame — external poke does NOT persist
- this 0x34A0: recalc every frame — external poke does NOT persist
- this 0x34A4: recalc every frame — external poke does NOT persist
- this 0x34A8: recalc every frame — external poke does NOT persist
- this 0x34AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ddd0 | ScoreSlotDeallocator | Deallocates temporary score/slot allocations |
| 0042e320 | SessionStructInit | Initializes session structure for physics |
| 0043e050 | TireModelInit | Initializes tire model with race time parameter |
| 004e4790 | sub_4E4790 | Performs config/state initialization for physics step |
| 004e5f60 | SuspensionAndWheelPhysics | Runs suspension force computation for all wheels |
| 004e8010 | TireBrushModelForceSolver | Runs brush tire model force solver |
| 004f34e0 | TireModelDataInit | Allocates and initializes tire model data buffers |
| 004f4270 | TheSvmHdvVehicleFileParser | Parses vehicle HDV setup file for physics parameters |
| 00587bcf | FreeWrapper_7bcf | Frees temporary memory allocations |
| 005881c0 | __alloca_probe | Stack probe for large alloca allocation |

**Guard conditions:** Checks this+0x32BC (mode flag). If non-zero and in range 1-3, skips TireModelInit. If zero, calls TireModelInit first. Checks result range 1-3 for early return if invalid. Clamps iteration count to [1, 64].
