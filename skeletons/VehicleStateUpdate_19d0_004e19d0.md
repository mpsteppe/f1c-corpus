## VehicleStateUpdate_19d0_004e19d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x1C8 | R | — | [LLM] |
| this | 0x1E0 | R | — | [LLM] |
| this | 0x1E4 | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |
| this | 0x898 | R | — | [LLM] |
| this | 0x8A0 | R | — | [LLM] |
| this | 0x8A4 | R | — | [LLM] |
| this | 0x8A8 | R | — | [LLM] |
| this | 0x8AC | R | — | [LLM] |
| this | 0x8B0 | R | — | [LLM] |
| this | 0x8B4 | R | — | [LLM] |
| this | 0x8B8 | R | — | [LLM] |
| this | 0x8C4 | R | — | [LLM] |
| this | 0x94C | R | — | [LLM] |
| this | 0x950 | R | — | [LLM] |
| this | 0x958 | R | — | [LLM] |
| this | 0x95C | R | — | [LLM] |
| this | 0x960 | R | — | [LLM] |
| this | 0x964 | R | — | [LLM] |
| this | 0x96D | R | — | [LLM] |
| this | 0x974 | RW | — | [LLM] |
| this | 0x975 | R | — | [LLM] |
| this | 0x976 | RW | — | [LLM] |
| this | 0x977 | R | — | [LLM] |
| this | 0x978 | RW | — | [LLM] |
| this | 0x979 | R | — | [LLM] |
| this | 0x980 | RW | — | [LLM] |
| this | 0x984 | R | — | [LLM] |
| this | 0x988 | R | — | [LLM] |
| this | 0xB6C | R | — | [LLM] |
| this | 0x2BD0 | R | — | [LLM] |
| this | 0x2BD4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x974: recalc every frame — external poke does NOT persist
- this 0x976: recalc every frame — external poke does NOT persist
- this 0x978: recalc every frame — external poke does NOT persist
- this 0x980: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059f110 | flt_59F110 | R | PhysicsBrakeBias [DERIVED] |
| 005ad154 | flt_5AD154 | R | Flt_Unknown_Render5 [DERIVED] |
| 005ad158 | flt_5AD158 | R | Unknown_Float_5AD158 [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ea518 | dword_5EA518 | R | ActiveControlProfilePtr [DERIVED] |
| 005ea528 | dword_5EA528 | R | AudioDeviceState [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cf740 | flt_7CF740 | R | GearChangeAnimDuration [DERIVED] |
| 007cf7f4 | dword_7CF7F4 | R | PhysicsFlag [DERIVED] |
| 007cfcc8 | dword_7CFCC8 | R | QueuedModeFlag [DERIVED] (also: ` — queued mode flag (docs/09) |
| 007cfcec | dword_7CFCEC | R | PitControlFlag [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ad3ec | dword_8AD3EC | R | SoundEffectArray [DERIVED] |
| 008ad3f8 | unk_8AD3F8 | R | slot table base (stride 14 [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | [LLM] |
| 004b9ce0 | Delegation | [LLM] |
| 004e21d0 | ColorAlphaUpdateFlagSet | [LLM] |
| 004e3090 | sub_4E3090 | [LLM] |
| 0054b450 | sub_54B450 | [LLM] |
| 0054b4d0 | sub_54B4D0 | [LLM] |
| 0054c030 | FlagFieldBitManipulation | [LLM] |
| 0054c0b0 | BitFlagReader | [LLM] |
| 005506a0 | sub_5506A0 | [LLM] |
| 00551810 | ConditionalDispatchByFlag | [LLM] |
| 00567120 | sub_567120 | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2BD0 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
