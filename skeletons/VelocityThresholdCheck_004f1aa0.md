## VelocityThresholdCheck_004f1aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_49B7A0 (0049b7a0), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | [LLM] |
| this | 0x3444 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 007c9080 | byte_7C9080 | R | SystemDefaultReturnValue [DERIVED] (also: ` -- default return value) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004effd0 | DistanceComparison | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
