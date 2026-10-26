## GameStateBranchDispatch_0040d100 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_40C140 (0040c140), NetCommPlayerSlotSync (0045fc50), sub_4A00A0 (004a00a0), sub_4C6B60 (004c6b60), PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040d198 | jpt_40D118 | R | [LLM] |
| 007cfdc4 | dword_7CFDC4 | R | DispatchModeSelector [CONFIRMED] (also: Dispatch mode selector (0-3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409440 | ViewCameraModeDispatch | [LLM] |
| 0040cde0 | GameActionStateMachine | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
