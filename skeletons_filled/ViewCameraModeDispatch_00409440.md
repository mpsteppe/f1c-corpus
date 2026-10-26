## ViewCameraModeDispatch_00409440 — CameraViewModeDispatcher

**Summary:** Dispatches camera/view mode changes based on player input — handles cycling through cockpit/TV/external views (modes 0-2), direct mode jumps (3-8), sub-option cycling within modes (case 4), and copies UI state globals into sub-objects for replay/monitor modes (7-8). Triggers audio feedback on mode switch. Camera/UI system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MenuSlotActionDispatch (0040a910), GameActionStateMachine (0040cde0), GameStateBranchDispatch (0040d100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x30)+0x0) | 0x1C | R | — | sub-object vtable dispatch (mode 8: calls vtable+28) |
| *(this+0x2C) | 0xBC | RW | — | sub-object (mode 7): copies dword_5EA550 into offset 0xBC |
| *(this+0x2C) | 0xC0 | RW | — | sub-object (mode 7): copies dword_5EA554 into offset 0xC0 |
| *(this+0x2C) | 0xC4 | RW | — | sub-object (mode 7): copies dword_5EA558 into offset 0xC4 |
| *(this+0x30) | 0x0 | R | — | sub-object pointer (mode 8): vtable dereference |
| *(this+0x30) | 0xBC | RW | — | sub-object (mode 8): copies dword_5EA500 into offset 0xBC |
| *(this+0x30) | 0xC0 | RW | — | sub-object (mode 8): copies dword_5EA504 into offset 0xC0 |
| *(this+0x30) | 0xC4 | RW | — | sub-object (mode 8): copies dword_5EA508 into offset 0xC4 |
| this | 0x2C | R | — | mode-7 sub-object pointer |
| this | 0x30 | R | — | mode-8 sub-object pointer |
| this | 0x34 | RW | 4 | current camera mode (0=cockpit, 1=T-cam, 2=external, 3=TV, 4=sub-mode, 5-8=special) |
| this | 0x38 | R | — | sub-mode option count (for mode 4 cycling) |
| this | 0x3C | RW | 0 | sub-mode current index (for mode 4 cycling) |
| this | 0x50 | RW | 0 | cycling position within modes 0-2 (0=cockpit, 1=T-cam, 2=external) |

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
| 004096ac | jpt_409487 | R | jump table for switch dispatch (IDA artifact, unused in decompiled C) |
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
| 00408740 | FloatKeyedFieldSelector | applies the selected camera mode (stored as float) to the view subsystem |
| 00408de0 | ConditionalSubsystemCallWithParameter | triggers camera/view subsystem update with current target position |
| 004e0ed0 | AudioSoundEffectController | plays UI sound effect on camera mode change (parameter = mode ID) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x34 | <= | 2 | current mode is in cycling range (0-2) — if true, PASSES: directional input cycles position; else BLOCKED: cycling skipped |
| this | 0x34 | == | 4 | current mode is sub-mode (4) — if true, PASSES: sub-option index cycles; else BLOCKED |
| this | 0x38 | <= | 0 | sub-mode option count — if <=0, BLOCKED: no sub-options, mode 4 skipped; if >0, PASSES |

**Guard interpretation:**
- Mode override gate (top): If `byte_7CFE88` is set, OR `a2 != 3`, OR postProcessInput byte at +13388 is zero, OR ScoringGate == 2, then BLOCKED — request passes through unchanged. Only when all conditions align (no override flag, mode is 3, post-process input active, scoring gate not 2) PASSES — mode forced to 2 with direction=0.
- Mode cycling (0x34 <= 2): When current mode is 0,1,2, directional input (a3) adjusts the cycling position at offset 0x50, wrapping 0→1→2→0. If current mode > 2, cycling logic is skipped.
- Sub-mode cycling (0x34 == 4): When mode 4 is active and direction is given, the sub-index (0x3C) increments/decrements modulo the option count (0x38).
- Cross-vehicle check: If player's and target's vehicle IDs match (via VehiclePtrArray), mode cycling proceeds normally; otherwise, position wraps differently when dword_7CFCC8 (queued mode flag) is set.
