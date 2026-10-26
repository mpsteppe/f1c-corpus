## LoadingPhase1_004b87c0 — LoadingPhase1SessionInit

**Summary:** First phase of session loading: pops queue, validates range width, loads resources, initialises vehicle effect tables and state visibility, sets angle clamp mode to hard clamp, and runs state trigger checks. Part of session/loading state machine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9890 (004b9890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x734 | RW | — | resource lookup path/offset for loading |
| this | 0x93C | RW | — | per-vehicle state byte (synced from vehicle+4189) |
| this | 0xF30 | R | — | lower bound of angle/range |
| this | 0xF34 | R | — | upper bound of angle/range |
| this | 0xF40 | RW | — | loaded resource handle |
| this | 0xF80 | RW | 1 | loading phase flag (set to 1) |
| this | 0xF81 | RW | 1 | angle clamp mode (set to 1 = hard clamp) |

**Written-by note (persistence):**
- this 0x734: set per vehicle in loop; last vehicle's value persists
- this 0x93C: set per vehicle in loop; last vehicle's byte persists
- this 0xF40: set once from ResourceLookupDispatcher; persists until released
- this 0xF80: set to 1; persists as loading phase marker
- this 0xF81: set to 1; persists as clamp mode

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acd1c | flt_5ACD1C | R | AIFollowDistThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408420 | ReciprocalWithSignCheck | computes reciprocal of random offset flag |
| 004b7a00 | QueuePop | advances the queue pointer |
| 004b86e0 | AngleClampWrap | clamps session time angle to range |
| 004b8ae0 | StateTriggerCheck | runs state trigger checks in a loop |
| 004d8840 | ConditionalIndexSetter | sets index to 0 |
| 004e1970 | EffectDataTableInitialization | initialises vehicle effect data tables |
| 004e3a50 | MultiObjectRemove | removes objects at given position |
| 004ef5a0 | SessionStateTransition | transitions session state |
| 00566e20 | ResourceLookupDispatcher | looks up resource by path offset |

**Guard conditions:** If upper bound minus lower bound (range width) <= 0.0, returns 0 immediately — invalid range. Otherwise executes full loading phase.
