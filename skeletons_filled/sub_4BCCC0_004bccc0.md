## sub_4BCCC0_004bccc0 — AI Race Penalty and Track Position Update

**Summary:** Per-frame AI race driving logic: updates track distance projection, enforces pit lane speed limits with stop-go penalties, detects corner cutting and wrong-way driving violations, manages blue flag penalty timers, and handles pit entry selection based on nearby vehicle proximity.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x3AA8)+0x110) | 0x0 | R | — | vehicle forward-direction vector X component (used in force projection) |
| *(*(obj+0x3AA8)+0x110) | 0x4 | R | — | vehicle forward-direction vector Y component |
| *(*(obj+0x3AA8)+0x110) | 0x8 | R | — | vehicle forward-direction vector Z component |
| *(obj+0x3AA8) | 0x0 | R | — | vehicle world position X |
| *(obj+0x3AA8) | 0x4 | R | — | vehicle world position Y |
| *(obj+0x3AA8) | 0x8 | R | — | vehicle world position Z |
| *(obj+0x3AA8) | 0x20 | R | — | vehicle velocity/speed X component |
| *(obj+0x3AA8) | 0x24 | R | — | vehicle velocity/speed Y component |
| *(obj+0x3AA8) | 0x28 | R | — | vehicle velocity/speed Z component |
| *(obj+0x3AA8) | 0x68 | R | — | vehicle orientation/rotation matrix element |
| *(obj+0x3AA8) | 0x6C | R | — | vehicle orientation/rotation matrix element |
| *(obj+0x3AA8) | 0xA4 | R | — | track segment direction vector X |
| *(obj+0x3AA8) | 0xA8 | R | — | track segment direction vector Y |
| *(obj+0x3AA8) | 0xAC | R | — | track segment direction vector Z |
| *(obj+0x3AA8) | 0x110 | R | — | pointer to vehicle direction/force data block |
| *(obj+0x3AA8) | 0x12C | R | — | pointer to waypoint/segment direction vector block |
| obj | 0x344C | R | — | track segment rightward/normal vector X |
| obj | 0x34E0 | R | — | track segment rightward/normal vector X (per-vehicle) |
| obj | 0x34E4 | R | — | track segment rightward/normal vector Y (per-vehicle) |
| obj | 0x34E8 | R | — | track segment rightward/normal vector Z (per-vehicle) |
| obj | 0x34F8 | R | — | vehicle velocity X (world-space) |
| obj | 0x34FC | R | — | vehicle velocity Y (world-space) |
| obj | 0x3500 | R | — | vehicle velocity Z (world-space) |
| obj | 0x3AA8 | R | — | pointer to vehicle physics/track-position data block |
| this | 0x0 | R | — | pointer to AI driver's vehicle object (dereferenced for position data) |
| this | 0x4 | R | — | AI driver index (used to skip self in vehicle loop) |
| this | 0x8 | R | — | current lap number or sector index |
| this | 0xC | R | — | sector/segment identifier |
| this | 0x14 | RW | — | current track distance projection (float, updated from DistanceProjectionCalc) |
| this | 0x2C | R | — | current waypoint index or lap progress |
| this | 0x60 | RW | 1 | AI state/mode flag (initialized to 1; checked for != 2 in pit selection logic) |
| this | 0xA8 | RW | 0 | pit lane speed accumulator (float, rolling sum of speed excess) |
| this | 0xAC | RW | — | pit speeding distance counter (this[43], accumulated when in pit lane) |
| this | 0xB0 | RW | — | wrong-way distance accumulator (this[44], increases when facing wrong direction) |
| this | 0xB4 | RW | 0 | corner cutting state parameter (speed/angle component) |
| this | 0xB8 | RW | — | stored vehicle position/lap index at cut entry (this[46]) |
| this | 0xBC | RW | — | stored waypoint index at cut entry (this[47]) |
| this | 0xC0 | RW | — | stored vehicle state/mode flag at cut entry (this[48]) |
| this | 0xC4 | RW | — | stored distance projection at cut entry (this[49]) |
| this | 0xC8 | RW | — | time accumulator during corner cut (this[50], incremented by frame delta) |
| this | 0xCC | RW | — | minimum force projection during corner cut (this[51], tracked downward) |
| this | 0xD0 | R | — | corner cut violation count (this[52], used to escalate penalty) |
| this | 0xD4 | RW | 1 | pit proximity check flag/state (byte at this+212, set when vehicle nearby) |
| this | 0xD8 | RW | — | closest vehicle index for pit selection (this[54]) |
| this | 0xDC | RW | — | blue flag timer accumulator (this[55], increments each frame near blue-flag vehicle) |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0xB8: recalc every frame — external poke does NOT persist
- this 0xBC: recalc every frame — external poke does NOT persist
- this 0xC0: recalc every frame — external poke does NOT persist
- this 0xC4: recalc every frame — external poke does NOT persist
- this 0xC8: recalc every frame — external poke does NOT persist
- this 0xCC: recalc every frame — external poke does NOT persist
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0xD8: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e468 | flt_59E468 | R | BrakingZoneSpeedThreshold2 [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e8e4 | flt_59E8E4 | R | WetGripThreshold [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e8f4 | flt_59E8F4 | R | PhysicsThreshold_59E8F4 [DERIVED] |
| 0059e91c | flt_59E91C | R | ShortConversionMult [DERIVED] (also: conversion multipliers) |
| 0059e944 | flt_59E944 | R | Physics_Float_59E944 [DERIVED] |
| 0059eb48 | dbl_59EB48 | R | RideHeightThreshold [DERIVED] |
| 005acb30 | flt_5ACB30 | R | PhysicsForceThreshold [DERIVED] |
| 005acd7c | flt_5ACD7C | R | Flt_5ACD7C_Race [DERIVED] |
| 005acd80 | flt_5ACD80 | R | Unknown_Float_5ACD80 [DERIVED] |
| 005acd84 | flt_5ACD84 | R | DepthOfFieldScale [DERIVED] |
| 005acd88 | dbl_5ACD88 | R | UnknownDoubleConst3 [DERIVED] |
| 005acd90 | flt_5ACD90 | R | Flt_Unknown_Display [DERIVED] |
| 005acd94 | flt_5ACD94 | R | Flt_AiAudioFreqGain_CD94 [DERIVED] |
| 005acd98 | flt_5ACD98 | R | Unknown_Float_5ACD98 [DERIVED] |
| 005acd9c | flt_5ACD9C | R | UnknownFloat_5ACD9C [DERIVED] |
| 005acda0 | dbl_5ACDA0 | R | WheelContactForceThreshold [DERIVED] |
| 005c26ec | aIgnoredBlueFla | R | IgnoredBlueFlag [DERIVED] — "Ignored Blue Flag" penalty message string |
| 005c2710 | aCutTrack | R | StringCutTrack [DERIVED] — "Cut Track" warning/penalty message string |
| 005c271c | aSpeedingInPitl | R | Str_SpeedingInPitL [DERIVED] — "Speeding in Pit Lane" penalty message string |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005d25b0 | aWrongWay | R | WrongWayString [DERIVED] — "Wrong Way" warning message string |
| 005d25bc | aLapWillNotCoun | R | Str_LapWillNotCount [DERIVED] — "Lap Will Not Count" penalty message string |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` â€” waypoint accumulation weight) |
| 005ea408 | flt_5EA408 | R | SessionMaxTime [DERIVED] (also: ` — threshold) |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — empty string for comparison before writing message |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) — buffer for on-screen penalty messages |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — session type (5 = ?, 7 = race) |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cef84 | dword_7CEF84 | R | PenaltiesEnabled [DERIVED] — flag enabling penalty enforcement |
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |
| 008ad264 | dword_8AD264 | R | PenaltyMessageQueue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004193a0 | AISessionModeTransition | handles AI session mode transitions (practice/qualify/race state changes) |
| 0041a4a0 | DisplayMessage0x11c | displays on-screen message at specific screen position/layer |
| 0041a720 | sub_41A720 | records penalty event in AI driver log/message queue |
| 0041b3c0 | PitSelectionStateMachine | manages pit entry selection state machine transitions |
| 0041b910 | ClearPitSelectionFlags | clears pit selection state flags for AI driver |
| 00423a00 | BinarySearchInStringTable | searches for string in table using binary search |
| 0045bd10 | TextLineWrappingAndRendering | renders wrapped text line to screen with given color |
| 004bba90 | sub_4BBA90 | issues time-based penalty to AI driver with custom duration |
| 004bbc60 | WarningHandler | issues warning (non-penalty) notification to AI driver |
| 004bbd60 | StopGoPenaltyHandler | issues stop-go penalty (10 second default) for violations |
| 004bc0e0 | DisqualificationHandler | handles driver disqualification for severe violations |
| 004bc340 | sub_4BC340 | checks if AI driver is in race session (returns boolean) |
| 004d7c10 | FloatRangeIndexLookup | looks up float value in range table, returns index |
| 004d7cf0 | FloatWrapTableInterpolation | interpolates float value from wrap-around lookup table |
| 004eff00 | ForceDirectionProjection | projects force vector onto track/vehicle direction |
| 004f0050 | DistanceProjectionCalc | calculates distance projection along track for given vehicle |
| 004f01b0 | sub_4F01B0 | computes track distance or position metric for checkpoint |
| 00587bdc | CRTFtol | C runtime: float-to-long conversion |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | == | 18446744072627421184 → -1.0f | track distance projection uninitialized sentinel |
| this | 0x60 | != | 2 | AI driver state/mode flag (2 = active racing mode) |
| this | 0xD0 | > | 1 | corner cut violation count exceeded threshold |

**Guard interpretation:**
- **0x14 == -1.0f:** When track distance projection is uninitialized (-1.0f sentinel), BLOCKED: FloatWrapTableInterpolation is skipped (no valid distance data). When initialized to a real value, PASSES: interpolation proceeds using the current distance.
- **0x60 != 2:** When AI driver is NOT in mode 2 (racing), PASSES: pit selection proximity logic is enabled (checking nearby vehicles for pit entry). When mode IS 2, BLOCKED: pit selection logic bypassed (driver is actively racing).
- **0xD0 > 1:** When corner cut violation count exceeds 1 in a race session (session type 7), PASSES: triggers stop-go penalty. Additionally checked in combination: if count > 1 OR corner deviation > 2.75 AND session is race → penalty issued. Otherwise BLOCKED: only a warning is issued.
