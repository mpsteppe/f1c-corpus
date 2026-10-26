## LoadingPhase2_004b8940 — LoadingPhase2SessionFinalise

**Summary:** Second phase of session loading: runs state trigger checks, sets angle clamp to wrap mode, finalises per-vehicle state (visibility, audio effects, UI), cleans up session structure, and releases the loaded resource handle. Part of session/loading state machine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9890 (004b9890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x734 | R | — | resource lookup path/offset (read, not modified) |
| this | 0x93C | R | — | per-vehicle state byte (read for comparison) |
| this | 0xF40 | RW | 18446744073709551615 | loaded resource handle (set to -1 after release) |
| this | 0xF80 | RW | 1 | loading phase flag (set to 1) |
| this | 0xF81 | RW | 0 | angle clamp mode (set to 0 = wrap) |

**Written-by note (persistence):**
- this 0xF40: set to -1 after sub_566DB0 resource release; persists until next load
- this 0xF80: set to 1; persists as loading phase marker
- this 0xF81: set to 0; persists as wrap mode

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` — reverse gear throttle multiplier) |
| 005acd1c | flt_5ACD1C | R | AIFollowDistThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408450 | SafeDivisionWithZeroGuard | safe division of random offset flag |
| 00411120 | SessionStructureCleanup | cleans up session data structures |
| 004b86e0 | AngleClampWrap | clamps session time angle with wrap mode |
| 004b8ae0 | StateTriggerCheck | runs state trigger checks |
| 004c7aa0 | SetDriverVisibility | sets driver visibility per vehicle |
| 004c8dc0 | GuardedVirtualCall | guarded virtual dispatch |
| 004e0ed0 | AudioSoundEffectController | triggers audio effect for vehicle state change |
| 004e19a0 | UIElementIterateUpdate | updates UI elements per vehicle |
| 004e3a50 | MultiObjectRemove | removes objects at session time position |
| 004ef5a0 | SessionStateTransition | transitions session state |
| 00566db0 | sub_566DB0 | releases loaded resource handle |

**Guard conditions:** State trigger loop runs while accumulator < 1.125 (0.75 * 1.5). Per-vehicle loop runs for each entry in vehicle count. Always returns 1.
