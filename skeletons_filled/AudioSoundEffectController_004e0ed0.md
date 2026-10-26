## AudioSoundEffectController_004e0ed0 — Audio UI Widget State Controller

> **PROSE CORRECTED 2026-07-24 (live evidence — fact table below is untouched).**
> This function is **misnamed**: it is the per-car **render-state update**, not an
> audio controller. Its `this` is the render object EMBEDDED at `veh+0x6F0`
> (live-verified: `*(veh+0x6F0)` == vehicle base). It renders/hides the scene nodes
> filled in by `VehicleGraphicsSceneLoader_004dfce0`: `this[547]`=COCKPIT,
> `[548]`=SUSPENSION, `[549]`=HELMET, `[550]`=ARMS, `[551]`=BODY, `[552]`=WHEEL.
> `this+2413` (`=veh+0x105D`) is **DriverModelVisible** and gates HELMET/ARMS/BODY;
> `this[601]` (`=veh+0x1054`) is the render mode 0..3.
> Detail: `mods/ai_pit_retire/RETIRE_SOLVED_2026-07-24.md`.


**Summary:** Per-frame audio/UI widget visibility controller that manages which HUD widgets are shown/hidden based on the current game mode (view=0, replay=1, driving=2, default=3). Handles session phase transitions for audio state changes and pit-control widget toggling.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ViewCameraModeDispatch (00409440), CameraTargetUpdateOnPlayerChange (0040c7a0), GameActionStateMachine (0040cde0), NetCommPlayerSlotSync (0045fc50), PitStopOperationTimer (004a6340), VehicleVisibilityCulling (004b3dc0), LoadingPhase2 (004b8940), PitCrewStateMachine (004bbfc0), VehiclePhysicsTimeStep (004c73f0), SetDriverVisibility (004c7aa0), VehicleRespawnReset (004e0800), LazyInitCallback (004e0d00), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC4 | R | — | audio playback state byte (compared to 1 for active audio check) |
| obj | 0x4894 | R | — | team/manufacturer ID (compared for same-team widget visibility) |
| obj | 0x48BC | R | — | mode selection flags (bit 1 set = use alternate mode from a2, else mode 3) |
| this | 0x0 | R | — | postProcessInput pointer (used for player-vehicle identity check) |
| this | 0x4 | R | — | active widget flag (non-zero = widget system active, gate for many conditions) |
| this | 0x144 | R | — | widget group 1 active flag (this[81], checked for pit-control visibility) |
| this | 0x184 | R | — | widget group 1 sub-flag (this[97]=sub_98, byte at this+388, pit-specific) |
| this | 0x188 | R | — | widget group 2 active flag (this[98], checked with byte at this+456) |
| this | 0x1C8 | R | — | widget group 2 sub-flag (byte at this+456, checked for pit crew visibility) |
| this | 0x26C | R | — | widget group 3 active flag (this[155], checked with byte at this+684) |
| this | 0x2AC | R | — | widget group 3 sub-flag (byte at this+684, checked for pit crew visibility) |
| this | 0x2B0 | R | — | widget group 4 active flag (this[172], checked with byte at this+752) |
| this | 0x2F0 | R | — | widget group 4 sub-flag (byte at this+752, checked for pit crew visibility) |
| this | 0x394 | R | — | widget group 5 active flag (this[229], replay/tv camera HUD widget) |
| this | 0x3D4 | R | — | widget group 5 sub-flag (byte at this+980, gate for replay HUD visibility) |
| this | 0x4BC | R | — | widget group 6 active flag (this[303], replay/tv camera HUD widget 2) |
| this | 0x4FC | R | — | widget group 6 sub-flag (byte at this+1276, gate for replay HUD visibility) |
| this | 0x5E4 | R | — | widget group 7 active flag (this[377], HUD widget for special modes) |
| this | 0x624 | R | — | widget group 7 sub-flag (byte at this+1572, gate for HUD widget) |
| this | 0x628 | R | — | widget group 8 active flag (this[394], HUD widget with byte at this+1640 gate) |
| this | 0x668 | R | — | widget group 8 sub-flag (byte at this+1640, HUD visibility gate) |
| this | 0x66C | R | — | widget array entry 0: active flag (this[411], per-widget struct base) |
| this | 0x6AC | R | — | widget array entry 0: byte at offset 0x40 within entry (gate for FlagFieldBitManipulation) |
| this | 0x6AD | R | — | widget array entry 0: byte at offset 0x41 within entry (second gate) |
| this | 0x88C | R | — | widget standalone flag 1 (this[547], checked in all modes for toggle) |
| this | 0x890 | R | — | widget standalone flag 2 (this[548], pit crew widget) |
| this | 0x894 | R | — | widget standalone flag 3 (this[549], conditional in mode 0) |
| this | 0x898 | R | — | widget standalone flag 4 (this[550], conditional widget) |
| this | 0x89C | R | — | widget standalone flag 5 (this[551], conditional widget) |
| this | 0x8A0 | R | — | widget standalone flag 6 (this[552], checked in modes 1/2) |
| this | 0x964 | RW | — | stored audio mode (this[601], written at entry from mode selection logic) |
| this | 0x96C | R | — | HUD visibility master flag (byte at this+2412, gates many widget visibility checks) |
| this | 0x96D | R | — | HUD sub-visibility flag (byte at this+2413, gates widget toggles in mode 0) |

**Written-by note (persistence):**
- this 0x964: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004e169c | jpt_4E0F1D | R | switch jump table for session phase decode (case 2,4,7,8) |
| 004e16ac | jpt_4E1029 | R | switch jump table for mode dispatch (0,1,2,3) |
| 004e16b4 | byte_4E16B4 | R | fallback mode value (read for default case) |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ea518 | dword_5EA518 | R | ActiveControlProfilePtr [DERIVED] |
| 005ea528 | dword_5EA528 | R | AudioDeviceState [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007cf710 | byte_7CF710 | R | SkipIntroFlag [DERIVED] |
| 007cf860 | dword_7CF860 | R | Unknown_AiTeamCount_F860 [DERIVED] |
| 007cfcec | dword_7CFCEC | R | PitControlFlag [DERIVED] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cd60 | SessionPhaseDecode | decodes current session phase (2/4/7/8 = active race phases) for audio state transitions |
| 004f7010 | StateHandlerDispatch | dispatches audio state transition (arg 0 = disable, 1 = enable audio state) |
| 0054c030 | FlagFieldBitManipulation | sets/clears widget visibility flags (arg1: enable, arg2: show, arg3: fade, arg4: immediate) |
| 0054c1b0 | UIWidgetRecursiveStateUpdate | recursively updates widget visibility for a widget group and its children |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0xC4 | != | 1 | audio playback state: if audio is NOT in state 1 (active), BLOCKED from entering state; if == 1 (active), PASSES and StateHandlerDispatch(1) is called to enable audio |

**Guard interpretation:** 
- Mode selection: `(*(_DWORD *)(*this + 18620) & 2) != 0` → if bit 1 is set in mode flags, use `a2` as mode; otherwise default to mode 3.
- `byte_7CE254`: If HUD disable flag is set, `v9` is true only when `dword_7D0410 == 6` (championship mode). Otherwise `v9` is always true. This gates whether StateHandlerDispatch is called.
- `dword_7C54E0 == *this`: If this is the player's vehicle, session phase decode runs and specific phase cases (2,4,7,8) are handled with audio state transitions. Otherwise (AI vehicle), session phase is decoded but the transition logic is simpler.
- Widget visibility conditions: Each `this[N] && *((_BYTE *)this + M)` pattern requires both the widget flag AND the sub-condition byte to be non-zero before calling FlagFieldBitManipulation. Widgets in mode 0 are hidden (all args 0), in modes 1/2/3 they are shown (args 1,1,0,0).
- `dword_5EA518 == dword_5EA528 && *(_DWORD *)(dword_5EA528 + 52) == 2 && !byte_7CF710`: In mode 0, if control profile matches audio device, device state is 2, and skip intro is false → hide specific replay/tv widgets.
- `dword_7CFCEC`: Pit control flag — when set in modes 1/2, enables pit-crew related widgets that would otherwise be hidden.
- Per-widget array loop (this+411, 8 entries): Each widget entry is checked for `*v4 && *((_BYTE *)v4 + 64) && *((_BYTE *)v4 + 65)` — widget must exist and both byte gates must be non-zero for visibility to be enabled.
