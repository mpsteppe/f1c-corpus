## FloatToBitfieldEncoder_004b2a40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SetupCarLightingAndRender (004c71c0), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accd8 | flt_5ACCD8 | R | DXT_GreenChannelScale [DERIVED] (also: ` — G channel scale factor (different precision) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
