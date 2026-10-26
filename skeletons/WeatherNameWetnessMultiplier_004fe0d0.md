## WeatherNameWetnessMultiplier_004fe0d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FE350 (004fe350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8f8 | flt_59E8F8 | R | PhysicsConst_59E8F8 [DERIVED] |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 005ad31c | flt_5AD31C | R | CameraFOVScale [DERIVED] |
| 005ad320 | flt_5AD320 | R | WetnessGainFloat [DERIVED] |
| 005ad324 | flt_5AD324 | R | CameraDistanceScale [DERIVED] |
| 005c6e7c | aMonsoon | R | String_Monsoon [DERIVED] |
| 005c6e8c | aOvercast | R | StringOvercast [DERIVED] |
| 005d6f84 | aRain_0 | R | RainString [DERIVED] |
| 005d6f8c | aDrizzle | R | Str_Drizzle [DERIVED] |
| 005d6f94 | aClear_0 | R | ClearString [DERIVED] |
| 005d6f9c | aNice | R | NiceString [DERIVED] |
| 005d6fa4 | aBest | R | BestStr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | [LLM] |
| 0058850f | sub_58850F | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
