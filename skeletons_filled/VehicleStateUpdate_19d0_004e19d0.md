## VehicleStateUpdate_19d0_004e19d0 — Vehicle Dashboard & HUD State Update

**Summary:** Per-frame vehicle dashboard/HUD update — propagates position/rotation transforms to wheel sub-objects and active components, detects state changes (low-grip warning, gear changes, byte flags), and dispatches sound/visual cues via sub_5506A0.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | player ID field on external object (compared for player match) |
| this | 0x0 | R | — | pointer to external object for player-ID lookup |
| this | 0x8 | R | — | vehicle world position X (float) |
| this | 0xC | R | — | vehicle world position Y (float) |
| this | 0x10 | R | — | vehicle world position Z (float) |
| this | 0x14 | R | — | vehicle rotation/velocity component X (float) |
| this | 0x18 | R | — | vehicle rotation/velocity component Y (float) |
| this | 0x1C | R | — | vehicle rotation/velocity component Z (float) |
| this | 0x1C8 | R | — | wheel sub-object array start (4 wheels × 296 bytes each) |
| this | 0x1E0 | R | — | wheel position X (float, within wheel sub-object) |
| this | 0x1E4 | R | — | wheel position Y (float) |
| this | 0x1E8 | R | — | wheel position Z (float) |
| this | 0x898 | R | — | suspension travel / wheel offset data |
| this | 0x8A0 | R | — | suspension travel / wheel offset data |
| this | 0x8A4 | R | — | suspension travel / wheel offset data |
| this | 0x8A8 | R | — | suspension position data |
| this | 0x8AC | R | — | suspension position data |
| this | 0x8B0 | R | — | suspension position data |
| this | 0x8B4 | R | — | suspension rotation data |
| this | 0x8B8 | R | — | suspension rotation data |
| this | 0x8C4 | R | — | color/alpha value (float, shared across wheel sub-objects) |
| this | 0x94C | R | — | track grip reference (compared with track-grip average) |
| this | 0x950 | R | — | timer/value for rotation computation |
| this | 0x958 | R | — | rotation axis X (float) |
| this | 0x95C | R | — | rotation axis Y (float) |
| this | 0x960 | R | — | rotation axis Z (float) |
| this | 0x964 | R | — | mode/state selector (0=all wheels, 1=front-rear split, 2=queued mode) |
| this | 0x96D | R | — | byte flag enabling conditional dispatch (checked with mode flag) |
| this | 0x974 | RW | — | low-grip warning flag (byte: set when track grip low or forced) |
| this | 0x975 | R | — | byte flag source value (compared with shadow at 0x976) |
| this | 0x976 | RW | — | byte flag shadow (previous value for change detection) |
| this | 0x977 | R | — | byte flag source value (compared with shadow at 0x978) |
| this | 0x978 | RW | — | byte flag shadow (previous value for change detection) |
| this | 0x979 | R | — | byte flag: forces low-grip mode when set |
| this | 0x980 | RW | — | gear-change indicator (integer: 0 = no change, N = gear step) |
| this | 0x984 | R | — | reference time for gear-change comparison (float) |
| this | 0x988 | R | — | gear-change time threshold (float) |
| this | 0xB6C | R | — | sound-effect handle (passed to sub_5506A0 for audio dispatch) |
| this | 0x2BD0 | R | — | active sub-component count (number of entries to process) |
| this | 0x2BD4 | R | — | pointer to active sub-component list (20-byte stride) |

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
| 005ea510 | dword_5EA510 | R | session manager object (virtual dispatch target) | SessionManager [DERIVED] |
| 005ea518 | dword_5EA518 | R | active control profile pointer (compared to AudioDeviceState for owned-vehicle check) | ActiveControlProfilePtr [DERIVED] |
| 005ea528 | dword_5EA528 | R | audio device state pointer (compared to control profile for ownership) | AudioDeviceState [DERIVED] |
| 007c54dc | dword_7C54DC | R | current player index (used to index vehicle pointer array) | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | vehicle pointer array (indexed by player index for player vehicle) | VehiclePtrArray [FACT] |
| 007cf740 | flt_7CF740 | R | gear-change animation duration (scales indicator step) | GearChangeAnimDuration [DERIVED] |
| 007cf7f4 | dword_7CF7F4 | R | physics flag (>0 enables player-vehicle comparison) | PhysicsFlag [DERIVED] |
| 007cfcc8 | dword_7CFCC8 | R | queued mode flag (affects sub_4E3090 dispatch pattern) | QueuedModeFlag [DERIVED] (also: ` — queued mode flag (docs/09) |
| 007cfcec | dword_7CFCEC | R | pit control flag (when set, skips owned-vehicle check) | PitControlFlag [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | scoring gate / mode (2 = special scoring mode) | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | scoring data pointer (delegation target when scoring mode active) | ScoringDataPtr [DERIVED] |
| 008ad3ec | dword_8AD3EC | R | sound effect handle array start (iterated for audio dispatch) | SoundEffectArray [DERIVED] |
| 008ad3f8 | unk_8AD3F8 | R | end of sound effect array (loop boundary) | slot table base (stride 14 [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | current session time (used for low-grip timing and gear timing) | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |
| 008afee8 | flt_8AFEE8 | R | track grip base value (component of grip average) | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | track grip comparison value (component of grip average) | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | dispatches virtual method on session manager object |
| 004b9ce0 | Delegation | delegates call to scoring data object |
| 004e21d0 | ColorAlphaUpdateFlagSet | updates color/alpha flags on a sub-object with a float value |
| 004e3090 | sub_4E3090 | updates individual wheel/dashboard sub-component state |
| 0054b450 | sub_54B450 | companion transform operation (rotation-only variant of sub_54B4D0) |
| 0054b4d0 | sub_54B4D0 | applies position (XYZ) + rotation (3 floats) transform to sub-object |
| 0054c030 | FlagFieldBitManipulation | manipulates bit flags in a flag field |
| 0054c0b0 | BitFlagReader | reads bit flags from a packed field into separate values |
| 005506a0 | sub_5506A0 | dispatches sound/visual event (takes sound handle, flag, and parameter) |
| 00551810 | ConditionalDispatchByFlag | conditionally dispatches based on flag value |
| 00567120 | sub_567120 | matrix/vector math operation (transform + matrix multiply) |
| 0058957a | InterruptDispatch | interrupt-based dispatch using session time |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2BD0 | > | 0 | active sub-component count: processes component list only when > 0 |

**Guard interpretation:** Additional guards: (1) Each wheel sub-object processed only if its DWORD flag pointer and byte flag are both non-zero (lines 60, 68). (2) Virtual dispatch block (lines 125-166) enters only when: pit-control is off, control profile matches audio state, profile mode == 1 (owned vehicle), OR player vehicle matches + physics flag > 0, AND scoring gate == 2 alternate path. Then dispatches sub_4E3090 with pattern varying by mode selector (0=all 4 wheels, 1=front-rear split, 2=queued-mode dependent). (3) Rotation transform block (line 168) only if this+0x898 pointer non-null. (4) Conditional dispatch (line 185) only if this+0x898 non-null AND byte flag at this+0x96D is set. (5) Low-grip warning (line 213): triggered if byte at this+0x979 is set OR (track-grip average * 0.5 > grip reference at this+0x94C) AND session time < 0.335. (6) Byte-flag change detection: compares source/sink pairs and dispatches only on value change.
