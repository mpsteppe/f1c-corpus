## VehicleControlEnabled_004a6db0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIStateMachineWithModeDispatch (004a5d10), PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x834 | R | — | [LLM] |
| obj | 0x874 | R | — | [LLM] |
| obj | 0x95C | R | — | [LLM] |
| obj | 0x99C | R | — | [LLM] |
| obj | 0xA84 | R | — | [LLM] |
| obj | 0xAC4 | R | — | [LLM] |
| obj | 0xBAC | R | — | [LLM] |
| obj | 0xBEC | R | — | [LLM] |
| obj | 0x4064 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d21d0 | sub_4D21D0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
