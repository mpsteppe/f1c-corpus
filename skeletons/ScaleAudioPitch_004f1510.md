## ScaleAudioPitch_004f1510 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIDriverStructInit (00424790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3984 | RW | — | [LLM] |
| this | 0x39A4 | R | — | EngineMaxRPM [CONFIRMED] |
| this | 0x39B0 | R | — | [LLM] |
| this | 0x39F8 | R | — | [LLM] |
| this | 0x3BF4 | RW | — | [LLM] |
| this | 0x4824 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3984: recalc every frame — external poke does NOT persist
- this 0x3BF4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 005ad240 | dbl_5AD240 | R | VehicleSimTickScale [DERIVED] |
| 005ad248 | dbl_5AD248 | R | DamageResponseScale [DERIVED] |
| 007d01c4 | byte_7D01C4 | R | PhysicsRandomFlags [DERIVED] (also: ` — Physics randomization flags (bit 2 = enable random speed noise) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e8010 | TireBrushModelForceSolver | [LLM] |
| 005881f0 | sub_5881F0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x39F8 | >= | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
