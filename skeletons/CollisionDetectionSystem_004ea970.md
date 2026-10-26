## CollisionDetectionSystem_004ea970 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0xA4 | RW | — | [LLM] |
| this | 0xA8 | RW | — | [LLM] |
| this | 0xAC | RW | — | [LLM] |
| this | 0xB0 | RW | — | [LLM] |
| this | 0xB4 | RW | — | [LLM] |
| this | 0xD0C | R | — | [LLM] |
| this | 0xD4C | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x3590 | R | — | [LLM] |
| this | 0x3594 | R | — | [LLM] |
| this | 0x3ABC | R | — | [LLM] |
| this | 0x3AC0 | R | — | [LLM] |
| this | 0x3B74 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e774 | flt_59E774 | R | ShortToFloatScale [DERIVED] (also: ` — position scale factor) |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 005ad1dc | flt_5AD1DC | R | SuspensionDampingMult [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 005ea570 | dword_5EA570 | R | InitStateFlag2 [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410b80 | ArrayOfStructLinearSearchByID | [LLM] |
| 0041ad80 | sub_41AD80 | [LLM] |
| 004ea010 | ArithmeticComparison_a010 | [LLM] |
| 004ed420 | VehicleGeometryProximityTest | [LLM] |
| 00547390 | ArithmeticComparison_7390 | [LLM] |
| 0054fa90 | NetworkPacketDataReader | [LLM] |
| 0054fae0 | BufferEntryClear | [LLM] |
| 005694e0 | VehicleProjectedPosition | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
