## VehicleRespawnReset_004e0800 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SceneRenderUpdate (004c6d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| obj | 0x4894 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x898 | R | — | [LLM] |
| this | 0x8A4 | R | — | [LLM] |
| this | 0x8B4 | R | — | [LLM] |
| this | 0x8B8 | R | — | [LLM] |
| this | 0x8C4 | R | — | [LLM] |
| this | 0x934 | RW | 0 | [LLM] |
| this | 0x938 | RW | 0 | [LLM] |
| this | 0x93C | RW | 0 | [LLM] |
| this | 0x940 | RW | 0 | [LLM] |
| this | 0x944 | RW | 0 | [LLM] |
| this | 0x948 | RW | 0 | [LLM] |
| this | 0x94C | RW | — | [LLM] |
| this | 0x964 | R | — | [LLM] |
| this | 0x96C | RW | 1 | [LLM] |
| this | 0x96D | RW | 1 | [LLM] |
| this | 0x974 | RW | 0 | [LLM] |
| this | 0x979 | RW | 0 | [LLM] |
| this | 0x980 | RW | 18446744073709551615 | [LLM] |
| this | 0x984 | RW | 18446744073701163007 | [LLM] |
| this | 0x988 | RW | — | [LLM] |
| this | 0x98C | RW | 0 | [LLM] |
| this | 0x990 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x934: recalc every frame — external poke does NOT persist
- this 0x938: recalc every frame — external poke does NOT persist
- this 0x93C: recalc every frame — external poke does NOT persist
- this 0x940: recalc every frame — external poke does NOT persist
- this 0x944: recalc every frame — external poke does NOT persist
- this 0x948: recalc every frame — external poke does NOT persist
- this 0x94C: recalc every frame — external poke does NOT persist
- this 0x96C: recalc every frame — external poke does NOT persist
- this 0x96D: recalc every frame — external poke does NOT persist
- this 0x974: recalc every frame — external poke does NOT persist
- this 0x979: recalc every frame — external poke does NOT persist
- this 0x980: recalc every frame — external poke does NOT persist
- this 0x984: recalc every frame — external poke does NOT persist
- this 0x988: recalc every frame — external poke does NOT persist
- this 0x98C: recalc every frame — external poke does NOT persist
- this 0x990: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059ec20 | flt_59EC20 | R | ForceClampMax [DERIVED] |
| 005ad150 | flt_5AD150 | R | AITimerRandomScale [DERIVED] |
| 007cf740 | flt_7CF740 | R | GearChangeAnimDuration [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004e0db0 | MultiSystemStructInitializer | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |
| 004e2ca0 | ScalePropagate | [LLM] |
| 004e3890 | StateArrayReset | [LLM] |
| 005506a0 | sub_5506A0 | [LLM] |
| 00551810 | ConditionalDispatchByFlag | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | <= | 1 | [LLM] |
| this | 0x8B4 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
