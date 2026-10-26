## RestartGate_004a0fd0 — Session Restart and Menu Transition Gate

**Summary:** Central gatekeeper for session restart and main-menu transitions. Evaluates global flags (mini-restart, full-restart, init-guard), a countdown timer, scoring state, and input-device actions to decide whether to return 4 (mini-restart with cleanup), return 6 (full restart), transition to main menu, or continue normal execution.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | unknown (not visible in decompiled code; likely referenced indirectly via callee or internal data structure) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | RW | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging); also used as return value — 6 triggers restart/menu transition |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cb21c | word_7CB21C | R | InputActionMap [DERIVED] |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce250 | dword_7CE250 | RW | CollisionConfigVersion [DERIVED] (also: ` — frame counter); used as tick argument to sub_485B90 |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED]; when non-zero (HUD enabled), skips sub_485B90 restart check and input-device polling |
| 007ce258 | dword_7CE258 | RW | InitZeroFieldSet [DERIVED]; state variable: 0=uninit, 1=initialized, 2=transitioning |
| 007ce25d | byte_7CE25D | RW | GlobalFlagA0DA0 [DERIVED] (also: ` -- global flag); mini-restart trigger — causes vehicle state reset and scoring re-eval, returns 4 |
| 007ce25e | byte_7CE25E | RW | SessionRequestFlag [DERIVED]; full-restart trigger — returns 6 immediately |
| 007ce25f | byte_7CE25F | R | SessionPauseFlag [DERIVED]; passed as argument to sub_485B90 for restart-decision logic |
| 007ce260 | byte_7CE260 | R | InitGuard_45d500 [DERIVED] (also: ` -- init guard flag); full-restart trigger — returns 6 when set |
| 007ce264 | dword_7CE264 | R | SessionStateFlag [DERIVED] (also: ` — sub-mode selector); value 1 triggers special path: return 6 if dword_7CE258==1, else set dword_7C569C=6 or call ConditionalInitGuard |
| 007ce269 | byte_7CE269 | RW | SessionInitGate [DERIVED] (also: Init flag (char); enables countdown timer — when set, dword_7CE26C decrements each frame |
| 007ce26c | dword_7CE26C | RW | RaceTimerValue [DERIVED] (also: Initialized to 5.0f); countdown timer float, decremented by dbl_8AFE98 each frame when byte_7CE269 is set |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float)); delta-time step used to decrement RaceTimerValue |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404b60 | sub_404B60 | initializes/resets setup directory suffix data (&dword_5EA43C) before input polling |
| 00404f00 | ByteFieldExtractorWithShift | extracts a bitfield from setup data to check if the "restart" input action is currently active on a given device |
| 00404f30 | MainMenuTransition | triggers transition to the main menu |
| 0042bc10 | ScoringGateCheck | checks whether scoring/gameplay conditions allow restart; returns boolean |
| 00485b90 | sub_485B90 | core restart decision: processes frame counter and pause flag, returns -1 (error/restart), 3 (restart), or 4 (special restart) — return values drive the gate's output |
| 004a0cb0 | sub_4A0CB0 | post-restart cleanup or state finalization, called unconditionally before returning |
| 004a0cf0 | ConditionalInitGuard | conditional initialization guard; called when dword_7CE264 != 1 during timer-expiry path |
| 004bc330 | FieldCopy_c330 | copies/resets vehicle state data block at vehicle+16436 (likely physics or setup state) for each vehicle |
| 004ef5a0 | SessionStateTransition | transitions player vehicle session state (passes player+12 as float* state pointer) |

**Guard conditions (deterministic — field vs literal):**

| Check | Condition | Action | Meaning |
|-------|-----------|--------|---------|
| byte_7CE25D | != 0 | reset flag, vehicle cleanup, scoring re-eval → return 4 | mini-restart: resets per-vehicle state, optionally transitions player, returns 4 |
| byte_7CE25E | != 0 | reset flag → return 6 | full restart requested externally |
| byte_7CE260 | != 0 | return 6 | init-guard triggered restart |
| dword_7CE264 | == 1 | if dword_7CE258 == 1: return 6; else: skip to LABEL_18 | session sub-mode 1 with init complete forces restart |
| sub_485B90 result | == -1 or 3 | return 6 | restart decision: -1 or 3 means full restart |
| sub_485B90 result | == 4 | return 4 | restart decision: 4 means mini-restart |
| byte_7CE254 | == 0 (HUD disabled) | skips sub_485B90 call | when HUD is disabled, skip the tick-based restart decision logic |
| byte_7CE254 | == 0 (HUD disabled) | skips input-device polling | when HUD is disabled, do not check controller input for restart/menu |
| byte_7CE269 | != 0 and timer > 0 | decrement timer, continue | countdown active but not yet expired |
| byte_7CE269 | != 0 and timer <= 0 | reset timer, set dword_7CE258 = 1 | countdown expired → init state complete |
| Input action map[*v5] | == 1 | check ByteFieldExtractorWithShift | specific input device action active |
| ByteFieldExtractorWithShift | returns true | set dword_7C569C = 6, call MainMenuTransition | player pressed restart → go to main menu |
| ByteFieldExtractorWithShift | returns false | set dword_7CE258 = 1 | input action not restart, mark as initialized |

**Guard interpretation:** The function implements a priority-ordered decision chain. Mini-restart (byte_7CE25D, return 4) has highest priority — it runs vehicle cleanup and scoring re-evaluation. Full restart (byte_7CE25E or byte_7CE260, return 6) has second priority — it returns immediately with no cleanup. Session sub-mode 1 with init-state 1 (return 6) is third. The tick-based restart check (sub_485B90) runs only when HUD is enabled (byte_7CE254 != 0). The countdown timer (byte_7CE269/dword_7CE26C) acts as a delayed init gate. Input polling (checking each controller for restart action) runs only when HUD is enabled. The function always calls sub_4A0CB0 (post-processing) before returning dword_7C569C as the final session-type/restart-type indicator.
