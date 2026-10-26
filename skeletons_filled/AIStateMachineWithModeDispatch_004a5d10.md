## AIStateMachineWithModeDispatch_004a5d10 — AIStateMachineDispatch

**Summary:** Main AI state machine dispatcher. Reads state from ring buffer entry `a2` (byte at +8 = mode, float at +4 = value). Updates internal mode (offset 0x184), calls AIPitStrategyState on mode change. Based on vehicle sub-state (offset 0x32C8 == 2/3) and mode, dispatches to sub_4A5EA0 (mode 2, pits-under-red) or sub_4A5F20 (mode 0). Then dispatches steering/physics via ConditionalDelegateDispatch + sub_4A3320 for modes 1/2, or FlagBasedLoopConditionalCall for mode 0.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** StateChangeNotify (004a5c80), sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | Vehicle sub-state; values 2 or 3 trigger pits-under-red handlers |
| this | 0x0 | R | — | Pointer to the associated vehicle object |
| this | 0x8 | R | — | Flag-based loop target (used when mode=0) |
| this | 0xC | R | — | Second animation/steering target for sub_4A3320 |
| this | 0x10 | R | — | First animation/steering target for sub_4A3320 |
| this | 0x184 | RW | — | AI mode: 0=inactive, 1=active, 2=pits-under-red |
| this | 0x188 | RW | — | Stored float value copied from ring buffer entry +4 |

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
| 0041a200 | AIPitStrategyState | Updates AI pit strategy state on mode change |
| 004a3320 | sub_4A3320 | Applies delegate dispatch results to steering/physics targets |
| 004a3390 | sub_4A3390 | (Re)initializes a sub-object with a boolean parameter |
| 004a3440 | FlagBasedLoopConditionalCall | Processes flagged array (mode 0 idle dispatch) |
| 004a55e0 | ConditionalDispatch_55e0 | Selects between two pitstop transition targets |
| 004a5ea0 | sub_4A5EA0 | Pits-under-red handler (mode 2) |
| 004a5f20 | sub_4A5F20 | Mode-0 handler |
| 004a6db0 | VehicleControlEnabled | Checks whether vehicle controls are active |
| 004d1100 | ConditionalDelegateDispatch | Dispatches steering/physics via delegate system |

**Guard conditions:** Multiple guards: (1) mode change detected → update and call AIPitStrategyState. (2) Vehicle sub-state at offset 0x32C8 ∈ {2,3} AND mode ∈ {0,2} → dispatch to sub-handlers. (3) Mode ∈ {0,1,2} selects different dispatch paths: mode 0 → FlagBasedLoopConditionalCall; modes 1/2 → ConditionalDelegateDispatch + sub_4A3320 chain.