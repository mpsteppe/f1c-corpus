## SessionSynchronizer_0045f950 — SessionSyncAndTimerUpdate

**Summary:** Per-frame session synchronization and timing update: in terrain-sampling mode (states 1/2) accumulates delta time and triggers per-player terrain-height samples; otherwise runs a countdown timer for network session-type polling, detects session changes, and displays "Synchronizing Game" with millisecond drift when the client clock diverges beyond 100 ms from the server.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionResponseStatus (00463cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | base timer reload value (reset interval for session-sync polling, in seconds) |
| this | 0x10 | RW | 1073741824 → 2.0f | countdown timer (decremented each frame by delta time a2) |
| this | 0x14 | RW | 0 | byte flag: set to 1 when countdown expires AND previously set, then immediately cleared; triggers a one-shot utility action |
| this | 0x374 | RW | 1 | session-change detected flag: set to 1 when multiplayer session type changes (triggers HUD-disable action and vehicle-placement switch) |
| this | 0x38C | RW | 0 | time accumulator for terrain-sampling burst (only used when state at 0x3FC4 is 1 or 2) |
| this | 0x410 | R | — | unknown (session state field, not visible in decompilation) |
| this | 0x3C74 | R | — | pointer to start of player-slot array (each entry 140 bytes apart, used for terrain sampling) |
| this | 0x3E14 | R | — | count of player entries to iterate in the terrain-sampling loop |
| this | 0x3FC4 | R | — | sync-state mode: 1 or 2 = terrain-sampling burst path; otherwise = timer-based session-type polling path |

**Written-by note (persistence):**
- this 0x10: written every frame in sync path (decremented by a2); overwritten unconditionally, external poke would not survive
- this 0x14: written only when countdown expires AND flag was set; cleared immediately after use, external poke survives only until next expiry
- this 0x374: set once when a session-type change is detected (dword_7C56A4 != v13); external poke would survive until next type change
- this 0x38C: accumulated every frame when state is 1 or 2; reset to 0 after burst completes (>5.0 threshold); external poke would not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) |
| 0059f094 | flt_59F094 | R | PhysicsConstant_59F094 [DERIVED] |
| 0059f11c | flt_59F11C | R | ContactNormalDotThreshold [DERIVED] |
| 005c5e74 | aSDMs | R | SDMsFormat [DERIVED] |
| 005c5e80 | aSynchronizingG | R | SynchronizingGameString [DERIVED] — "Synchronizing Game" message text |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — lookup table for BinarySearchInStringTable |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) — scratch buffer for sync message |
| 005ec6d0 | unk_5EC6D0 | R | unknown (referenced but role unclear from decompilation) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — current session type ID; change detected by comparison |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] — reference timer for TimeOffsetGetter |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) — current session time used in ProgressBarEventEncode |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | lookup "Synchronizing Game" string in translation table |
| 0042bda0 | TimerConversionWithSin | hard-resync game timer using animation value and sine-based correction |
| 0042cf10 | MultiplayerVehiclePlacement | switch multiplayer vehicle placement logic when session type changes |
| 0045bd10 | TextLineWrappingAndRendering | render "Synchronizing Game (%d ms)" drift message on screen |
| 0045ca20 | TerrainSurfaceRoughnessHeightSampling | sample terrain height at a player position for damage/roughness events |
| 0045e570 | UtilityFunction_e570 | one-shot utility action triggered when countdown timer expires |
| 00461530 | FlagBitTest | test a specific bit in a global flag word |
| 00462250 | TextureCreationWrapper | create a 2D texture resource from sampled terrain data |
| 004a0250 | sub_4A0250 | trigger session-state action (HUD disable path) |
| 004a0da0 | GlobalFlagSetter | set a global flag byte |
| 004b33b0 | ProgressBarEventEncode | encode a terrain-sampling result as a progress-bar event (type 4, event 42) |
| 004f9f60 | TimeOffsetGetter | retrieve current time offset from the race-phase timer |
| 004f9fc0 | sub_4F9FC0 | handle time-synchronization action after drift detection |
| 0057a610 | AnimationValueFetchWithTiming | fetch animation-driven value and timing metadata for session polling |
| 00587bdc | CRTFtol | convert float to integer (used for millisecond formatting) |
| 0058815f | StringFormatWithBufferOverflowCheck | safe sprintf into fixed-size buffer with overflow protection |

**Guard conditions:** The function branches on `this+0x3FC4`: if equal to 1 or 2, enters terrain-sampling burst path (accumulates time at this+0x38C, once >5.0s, iterates player slots and samples terrain per player). Otherwise enters timer-decrement path: countdown at this+0x10 is reduced by a2 each call; when it drops below 0.0, resets from this+0xC and checks this+0x14 for a one-shot utility trigger. Session-type polling via AnimationValueFetchWithTiming: if the fetched session type differs from dword_7C56A4 and is less than 8, sets this+0x374=1 and calls MultiplayerVehiclePlacement. Time-drift check: if absolute difference between fetched time and current session time exceeds 0.001s, and then >0.1s triggers "Synchronizing Game" HUD text, and >0.5s triggers a hard timer resync via TimerConversionWithSin.
