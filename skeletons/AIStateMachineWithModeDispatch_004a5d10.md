## AIStateMachineWithModeDispatch_004a5d10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StateChangeNotify (004a5c80), sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x184 | RW | — | [LLM] |
| this | 0x188 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x184: recalc every frame — external poke does NOT persist
- this 0x188: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041a200 | AIPitStrategyState | [LLM] |
| 004a3320 | sub_4A3320 | [LLM] |
| 004a3390 | sub_4A3390 | [LLM] |
| 004a3440 | FlagBasedLoopConditionalCall | [LLM] |
| 004a55e0 | ConditionalDispatch_55e0 | [LLM] |
| 004a5ea0 | sub_4A5EA0 | [LLM] |
| 004a5f20 | sub_4A5F20 | [LLM] |
| 004a6db0 | VehicleControlEnabled | [LLM] |
| 004d1100 | ConditionalDelegateDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
