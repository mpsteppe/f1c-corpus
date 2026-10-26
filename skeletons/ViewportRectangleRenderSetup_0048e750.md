## ViewportRectangleRenderSetup_0048e750 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a68e8 | flt_5A68E8 | R | ScreenScaleFactors [DERIVED] (also: ` � screen scaling factors) |
| 005a68ec | flt_5A68EC | R | AudioMixConstant_5A68EC [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9f00 | ConditionalInit | [LLM] |
| 004f9f30 | ConditionalStateReset | [LLM] |
| 00541b70 | CameraProjectionUpdate | [LLM] |
| 00542200 | sub_542200 | [LLM] |
| 00546200 | ArithmeticComparison_6200 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x78 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
