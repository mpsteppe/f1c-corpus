## ShortComputation_f070_0049f070 — PostFrameUpdateDispatch

**Summary:** Main per-frame update dispatcher called from GamePostMainLoop. Runs mode dispatch, clamps camera shake, checks boot/kick status, updates steering wheel animation, conditionally dispatches resource thunk, then evaluates session state to conditionally render position/speed UI overlay.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce058 | dword_7CE058 | R | Unknown_UI_Singleton [DERIVED] (also: ` — UI context object) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004082b0 | FloatClampWithEventDispatch | Clamps camera shake multiplier and dispatches on threshold |
| 0045bc00 | ThunkToFUN0045b840 | Resource dispatch thunk (called when scoring gate != 2) |
| 00461d20 | YouHaveBeenBootedHandler | Checks if player has been booted/kicked from session |
| 0049d070 | SteeringWheelAnimation | Updates steering wheel animation |
| 0049f790 | ModeBasedDispatch | Dispatches to mode-specific update logic |
| 0049f870 | sub_49F870 | Post-frame sub-handler |
| 004d8450 | sub_4D8450 | Session-mode-specific update |

**Guard conditions:** byte_7CE254 early-return guard; then session state check — state==3 or sub_462380>1 PASSES into UI overlay rendering path, else BLOCKED; nested checks: ShortComputation_36e0, FloatComparisonAgainstThreshold, CollisionThresholdCheck select which position data to use for overlay positioning
