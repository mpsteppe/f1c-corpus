## ViewCameraModeDispatch_00409440 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MenuSlotActionDispatch (0040a910), GameActionStateMachine (0040cde0), GameStateBranchDispatch (0040d100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x30)+0x0) | 0x1C | R | — | [LLM] |
| *(this+0x2C) | 0xBC | RW | — | [LLM] |
| *(this+0x2C) | 0xC0 | RW | — | [LLM] |
| *(this+0x2C) | 0xC4 | RW | — | [LLM] |
| *(this+0x30) | 0x0 | R | — | [LLM] |
| *(this+0x30) | 0xBC | RW | — | [LLM] |
| *(this+0x30) | 0xC0 | RW | — | [LLM] |
| *(this+0x30) | 0xC4 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x34 | RW | 4 | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x3C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x2C) 0xBC: recalc every frame — external poke does NOT persist
- *(this+0x2C) 0xC0: recalc every frame — external poke does NOT persist
- *(this+0x2C) 0xC4: recalc every frame — external poke does NOT persist
- *(this+0x30) 0xBC: recalc every frame — external poke does NOT persist
- *(this+0x30) 0xC0: recalc every frame — external poke does NOT persist
- *(this+0x30) 0xC4: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004096ac | jpt_409487 | R | [LLM] |
| 005be900 | dword_5BE900 | W | Int_GameStateSubmode [DERIVED] |
| 005ea500 | dword_5EA500 | R | GameStateFlag_5EA500 [DERIVED] |
| 005ea504 | dword_5EA504 | R | UIMenuState [DERIVED] |
| 005ea508 | dword_5EA508 | R | UIDispatchTable [DERIVED] |
| 005ea550 | dword_5EA550 | R | Unknown_GameState_5EA550 [DERIVED] |
| 005ea554 | dword_5EA554 | R | Unknown_Flag_5EA554 [DERIVED] |
| 005ea558 | dword_5EA558 | R | Unknown_SetupFlag [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cf680 | dword_7CF680 | R | CameraCenterTargetPos [DERIVED] (also: ` — camera center/target position) |
| 007cfcc8 | dword_7CFCC8 | R | QueuedModeFlag [DERIVED] (also: ` — queued mode flag (docs/09) |
| 007cfe88 | byte_7CFE88 | R | unknown (found in 0x0040cde0) [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408740 | FloatKeyedFieldSelector | [LLM] |
| 00408de0 | ConditionalSubsystemCallWithParameter | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x34 | <= | 2 | [LLM] |
| this | 0x34 | == | 4 | [LLM] |
| this | 0x38 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
