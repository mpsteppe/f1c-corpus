## TextLineWrappingAndRendering_0045bd10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIShiftPattern (0042b8d0), sub_42D140 (0042d140), BrakeBiasAdjustmentControl (00447d00), NetCommSessionMessageDispatcher (0045d890), MouseInputHandler (0045f030), SessionSynchronizer (0045f950), NetCommPlayerSlotSync (0045fc50), ServerOpenedClosedNotification (00461190), YouHaveBeenBootedHandler (00461d20), RenderScreenSave (004b40a0), sub_4B9FD0 (004b9fd0), sub_4BA460 (004ba460), sub_4BBA90 (004bba90), WarningHandler (004bbc60), StopGoPenaltyHandler (004bbd60), DisqualificationHandler (004bc0e0), sub_4BC9B0 (004bc9b0), sub_4BCCC0 (004bccc0), sub_4D11D0 (004d11d0), PitTimer (004d2e50), sub_4D8450 (004d8450), sub_4FA7E0 (004fa7e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f07c | dword_59F07C | R | RenderContextParameter [DERIVED] (also: ` — rendering context/parameter) |
| 007d02e4 | dword_7D02E4 | R | UIControl_RefStore [DERIVED] (also: ` — global reference stored in object) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b9c0 | UtilityFunction_b9c0 | [LLM] |
| 0045bb60 | IDToColorMaskMapper | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
