## PitStopOperationTimer_004a6340 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopReadyCheck (004a6200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xCD4 | R | — | [LLM] |
| obj | 0x1054 | R | — | [LLM] |
| obj | 0x105C | RW | 0 | [LLM] |
| obj | 0x32C8 | R | — | [LLM] |
| obj | 0x403C | R | — | [LLM] |
| obj | 0x4040 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xD8 | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF0 | RW | — | [LLM] |
| this | 0x12C | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x164 | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |
| this | 0x1B0 | RW | — | [LLM] |
| this | 0x1B4 | RW | — | [LLM] |
| this | 0x1B8 | RW | — | [LLM] |
| this | 0x1BC | RW | 1 | [LLM] |
| this | 0x1C0 | RW | 0 | [LLM] |
| this | 0x1C4 | RW | 0 | [LLM] |
| this | 0x1C8 | RW | 0 | [LLM] |
| this | 0x1CC | RW | 0 | [LLM] |
| this | 0x1D0 | RW | — | [LLM] |
| this | 0x1D4 | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x105C: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist
- this 0x1B0: recalc every frame — external poke does NOT persist
- this 0x1B4: recalc every frame — external poke does NOT persist
- this 0x1B8: recalc every frame — external poke does NOT persist
- this 0x1BC: recalc every frame — external poke does NOT persist
- this 0x1C0: recalc every frame — external poke does NOT persist
- this 0x1C4: recalc every frame — external poke does NOT persist
- this 0x1C8: recalc every frame — external poke does NOT persist
- this 0x1CC: recalc every frame — external poke does NOT persist
- this 0x1D0: recalc every frame — external poke does NOT persist
- this 0x1D4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e918 | flt_59E918 | R | ProximityDistThreshold [DERIVED] |
| 0059e960 | flt_59E960 | R | BrakeBiasThreshold [DERIVED] |
| 0059e994 | flt_59E994 | R | AIPerfThreshold [DERIVED] |
| 005acb54 | flt_5ACB54 | R | ScoringTimeTolerance [DERIVED] |
| 005acb58 | flt_5ACB58 | R | FloatConstantPair [DERIVED] |
| 005acb5c | flt_5ACB5C | R | ToleranceOffset [DERIVED] (also: ` — float, tolerance offset) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042aee0 | PitStopBlockingCondition | [LLM] |
| 004a34a0 | PerElementConditionalActionDispatcher | [LLM] |
| 004a3560 | FlagSetterWithOR | [LLM] |
| 004a35f0 | sub_4A35F0 | [LLM] |
| 004a3820 | PhysicsChannelProcessingWithLocals | [LLM] |
| 004a5820 | NthValidPartLookup | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004bbf20 | ProgressBarIncrement | [LLM] |
| 004d7570 | CompoundIndexLookup | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |
| 004f1860 | ConditionalMathDispatch | [LLM] |
| 004f1890 | SpeedValueSetterWithGlobalMirror | [LLM] |
| 004f1a60 | LoopWithConditionalSubCall | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | == | 1 | [LLM] |
| obj | 0x4040 | == | 2 | [LLM] |
| this | 0x164 | >= | 0 | [LLM] |
| this | 0x168 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
