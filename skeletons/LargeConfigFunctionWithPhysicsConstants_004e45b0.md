## LargeConfigFunctionWithPhysicsConstants_004e45b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4898 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | R | — | [LLM] |
| this | 0x3498 | RW | 64 | [LLM] |
| this | 0x349C | RW | — | [LLM] |
| this | 0x34A0 | RW | — | pitTime[0] [CONFIRMED] |
| this | 0x34A4 | RW | — | [LLM] |
| this | 0x34A8 | RW | — | [LLM] |
| this | 0x34AC | RW | — | [LLM] |

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
| 0042ddd0 | ScoreSlotDeallocator | [LLM] |
| 0042e320 | SessionStructInit | [LLM] |
| 0043e050 | TireModelInit | [LLM] |
| 004e4790 | sub_4E4790 | [LLM] |
| 004e5f60 | SuspensionAndWheelPhysics | [LLM] |
| 004e8010 | TireBrushModelForceSolver | [LLM] |
| 004f34e0 | TireModelDataInit | [LLM] |
| 004f4270 | TheSvmHdvVehicleFileParser | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 005881c0 | __alloca_probe | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
