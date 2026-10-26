## TrackTemperatureDisplay_004d37b0 — Session state handler with telemetry logging

**Summary:** Handles session state transitions for current vehicle: dispatches AI commands (command 5 for active state, command 4 for pit/transition state), updates vehicle telemetry substate, and periodically (every 3s) logs progress bar telemetry events for the player vehicle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Buffer handle/pointer passed to BufferEntryClear for cleanup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager — passed to StateResetOnCondition |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput — base for vehicle pointer calculation |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr — checked to identify player vehicle for special handling |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount — ring buffer entry counter |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr — ring buffer write offset |
| 008ac4b0 | flt_8AC4B0 | RW | SceneCameraParam — last telemetry log timestamp for rate limiting |
| 008afea0 | dbl_8AFEA0 | R | SessionTime — current time for telemetry event and rate check |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d450 | StateResetOnCondition | Resets session manager state conditionally |
| 0041a160 | pfnAPC | APC call — toggles player vehicle state (0=enter, 1=exit) |
| 00424cd0 | AICommandMessageQueueDispatcher | Dispatches AI command (4 or 5) to vehicle queue |
| 004a5ea0 | sub_4A5EA0 | Updates vehicle telemetry for pit/transition state |
| 004a5f20 | sub_4A5F20 | Updates vehicle telemetry for active state |
| 004b33b0 | ProgressBarEventEncode | Encodes telemetry progress event (type 3, subtype 7) |
| 0054c150 | FlagPropertyGetter | Gets driver/vehicle ID from flag property index 2048 |
| 0054fae0 | BufferEntryClear | Clears buffer entry at this+0x14 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| v7 (state) | — | == | -11 | Session state sentinel — branches to pit/transition path |
| v2 | — | == | dword_7C54E8 | Player vehicle check |
| | — | fabs(delta) | <= 3.0 | Telemetry rate limit — time since last progress bar event |
| dword_83EE60 | — | < | 1023 | Ring buffer capacity check |

**Guard interpretation:** If v7 == -11, take pit/transition path (AI command 4, sub_4A5EA0, pfnAPC(1)); else take active path (AI command 5, sub_4A5F20, pfnAPC(0) + StateResetOnCondition). Telemetry progress bar event is logged only when rate limit (3s since last) is exceeded. Ring buffer advance is gated on capacity < 1023.
