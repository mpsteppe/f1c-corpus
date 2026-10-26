## FloatToRGBColorConversion_004b21f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraShakeRingBufferWrite (0040f600), VectorToShort3Conversion (004b2c80), AudioSamplePlaybackWithPitchModulationAndStereoP (00500210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acc84 | flt_5ACC84 | R | ColorChannelMultiplier [DERIVED] (also: ` — color multiplier (float) |
| 005acc88 | flt_5ACC88 | R | ColorConvClampLower [DERIVED] |
| 005acc8c | flt_5ACC8C | R | ColorQuantize_Max [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
