## sub_4BC9B0_004bc9b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60), sub_4D2170 (004d2170), PitCloseTeamReadyCheck (004d2210), PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| obj | 0x34C4 | R | — | [LLM] |
| obj | 0x34D0 | R | — | [LLM] |
| obj | 0x34DC | R | — | [LLM] |
| obj | 0x34F8 | R | — | [LLM] |
| obj | 0x34FC | R | — | [LLM] |
| obj | 0x3500 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 0059e920 | flt_59E920 | R | SuspensionAntirollFactor [DERIVED] |
| 0059f124 | flt_59F124 | R | UILayoutOffset [DERIVED] (also: ` � layout constants) |
| 005acd70 | flt_5ACD70 | R | Unknown_Float_5ACD70 [DERIVED] |
| 005acd74 | flt_5ACD74 | R | Float5ACD74 [DERIVED] |
| 005acd78 | flt_5ACD78 | R | Float_5ACD78 [DERIVED] |
| 005c2700 | aJumpedStart | R | StringJumpedStart [DERIVED] |
| 005d2598 | aNotLinedUpProp | R | NotLinedUpPropStr [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cef84 | dword_7CEF84 | R | PenaltiesEnabled [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 0045bde0 | ShortComputation_bde0 | [LLM] |
| 004bbd60 | StopGoPenaltyHandler | [LLM] |
| 004bc0e0 | DisqualificationHandler | [LLM] |
| 004d10e0 | SingleFunctionDispatch_10e0 | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
