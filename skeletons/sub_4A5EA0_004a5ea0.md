## sub_4A5EA0_004a5ea0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIStateMachineWithModeDispatch (004a5d10), TrackTemperatureDisplay (004d37b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x180 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x180: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd680 | aEnteringPitsUn | R | EnteringPitsUnString [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cef84 | dword_7CEF84 | R | PenaltiesEnabled [DERIVED] |
| 008acfc8 | dword_8ACFC8 | R | RaceStartGateFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041a2b0 | AISessionPhaseChange | [LLM] |
| 004a5c80 | StateChangeNotify | [LLM] |
| 004bba90 | sub_4BBA90 | [LLM] |
| 004bc0e0 | DisqualificationHandler | [LLM] |
| 004bc240 | sub_4BC240 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
