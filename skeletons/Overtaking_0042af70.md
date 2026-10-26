## Overtaking_0042af70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteering (004270a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48A8 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3984 | R | — | [LLM] |
| this | 0x3D6C | R | — | carConditions [CONFIRMED] |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x409C | R | — | bestLap [CONFIRMED] |
| this | 0x4420 | RW | — | [LLM] |
| this | 0x450C | RW | — | [LLM] |
| this | 0x45F8 | R | — | [LLM] |
| this | 0x45FC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x450C: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ae60 | ServerSessionGateCheck | [LLM] |
| 004f1c20 | ReplayAIStateCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3D6C | != | 2 | carConditions [CONFIRMED] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
