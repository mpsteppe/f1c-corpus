## sub_4FB6D0_004fb6d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_403640 (00403640)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10C) | 0x0 | R | — | [LLM] |
| *(this+0x10C) | 0x4 | R | — | [LLM] |
| *(this+0x10C) | 0x8 | R | — | [LLM] |
| *(this+0x110) | 0x0 | R | — | [LLM] |
| *(this+0x110) | 0x4 | R | — | [LLM] |
| *(this+0x110) | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
