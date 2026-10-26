## TextOverlayDisplayTimer_004186f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Options_Setup (004a0eb0), RenderTickUpdate (004c8b70), sub_4F9480 (004f9480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAF4)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0xAF4)+0x0) | 0x8 | R | — | [LLM] |
| *(*(this+0xAF4)+0x0) | 0x18 | R | — | [LLM] |
| *(this+0xAF4) | 0x0 | R | — | [LLM] |
| this | 0x864 | R | — | [LLM] |
| this | 0x86C | R | — | [LLM] |
| this | 0xAE4 | RW | 1 | [LLM] |
| this | 0xAE8 | RW | — | [LLM] |
| this | 0xAEC | RW | 18446744073709551615 | [LLM] |
| this | 0xAF0 | R | — | [LLM] |
| this | 0xAF4 | R | — | [LLM] |
| this | 0x135C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xAE4: [LLM: once/conditional? does external poke survive?]
- this 0xAE8: [LLM: once/conditional? does external poke survive?]
- this 0xAEC: [LLM: once/conditional? does external poke survive?]
- this 0x135C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005bf9ac | flt_5BF9AC | R | AnimationTimingFloats [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cf278 | dword_7CF278 | R | PitWindowTimeThreshold [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008afea8 | dbl_8AFEA8 | R | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411840 | FontRenderingPrep | [LLM] |
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 00418ac0 | ArraySlotCompactionWithGapFilling | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x864 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
