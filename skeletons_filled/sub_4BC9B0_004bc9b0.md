## sub_4BC9B0_004bc9b0 — GridAlignmentAndJumpStartValidator

**Summary:** Validates grid position alignment and detects jump-start violations — computes velocity magnitude, transforms vehicle orientation vectors, and checks distance/angle thresholds to determine if the car is properly lined up; triggers stop-go penalty or disqualification for jump starts when penalties are enabled.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4C6B60 (004c6b60), sub_4D2170 (004d2170), PitCloseTeamReadyCheck (004d2210), PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | penalty state flag (checked != 1 to allow new penalty) |
| obj | 0x34C4 | R | — | alignment / orientation matrix element (v5[3377], used in dot product) |
| obj | 0x34D0 | R | — | alignment / orientation matrix element (v5[3380], used in dot product) |
| obj | 0x34DC | R | — | alignment / orientation matrix element (v5[3374], used in dot product) |
| obj | 0x34F8 | R | — | velocity / acceleration X component (v4[3390]) |
| obj | 0x34FC | R | — | velocity / acceleration Y component (v4[3391]) |
| obj | 0x3500 | R | — | velocity / acceleration Z component (v4[3392]) |
| this | 0x0 | R | — | pointer to vehicle / driver object (dereferenced for all field access) |

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
| 00423a00 | BinarySearchInStringTable | searches for a string in a table and copies the match to the output buffer |
| 0045bd10 | TextLineWrappingAndRendering | renders wrapped text lines to the screen with a given color |
| 0045bde0 | ShortComputation_bde0 | sets up / dispatches a message display event |
| 004bbd60 | StopGoPenaltyHandler | applies a stop-go penalty to the driver with specified duration |
| 004bc0e0 | DisqualificationHandler | disqualifies the driver from the session |
| 004d10e0 | SingleFunctionDispatch_10e0 | retrieves position and orientation vectors via function dispatch |
| 004efb20 | F_3DTransformWithMatrixMultiplication | transforms a 3D vector by a rotation matrix |
| 00566e40 | EulerToRotationMatrix | converts euler angles to a 3x3 rotation matrix |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | != | 1 | penalty state flag — if not equal to 1, no active penalty exists yet |

**Guard interpretation:** When penalty state (obj+0x32C8) != 1, the car has no active penalty — the penalty path is enabled and a stop-go or disqualification can be applied. When == 1, a penalty is already active so the function skips issuing a new one (returns 0). Additionally, the function gates on parameter `a2`: when `a2` is true (jump-start detection mode), it checks tighter thresholds (speed > 1.0, distance > 5.0625, dot products); when false (grid alignment mode), it uses relaxed thresholds (distance <= 3.0625, dot1 <= 1.25, dot2 >= 0.85) and returns 1 (properly aligned) on pass.
