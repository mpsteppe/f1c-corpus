## sub_40CEE0_0040cee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_40D380 (0040d380), sub_40D430 (0040d430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x58 | R | — | [LLM] |
| *(this+0x54) | 0x5C | R | — | [LLM] |
| *(this+0x54) | 0x60 | R | — | [LLM] |
| *(this+0x54) | 0x70 | R | — | [LLM] |
| *(this+0x54) | 0x74 | R | — | [LLM] |
| *(this+0x54) | 0x78 | R | — | [LLM] |
| *(this+0x54) | 0x8C | R | — | [LLM] |
| *(this+0x58) | 0x10 | R | — | [LLM] |
| obj | 0x1C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1644 | _AIL_set_sample_volume_levels@12 | R | [LLM] |
| 006f1648 | _AIL_set_sample_playback_rate@8 | R | [LLM] |
| 006f16b8 | flt_6F16B8 | R | [LLM] |
| 006f16c8 | flt_6F16C8 | R | [LLM] |
| 006f1e84 | flt_6F1E84 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00be08a0 | dword_BE08A0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004015c0 | sub_4015C0 | [LLM] |
| 0040ac90 | ScaledDotProductWithClamp [structural] | [LLM] |
| 0040c340 | sub_40C340 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
