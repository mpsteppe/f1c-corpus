## Steward_Setup_004d36d0 — Steward subsystem setup and registration

**Summary:** Registers Steward subsystems: Vehicle (via sub_5599D0), Timing and Pitstop (via sub_559A00) with TimerFrameRateThrottle and TrackTemperatureDisplay as handler callbacks. Logs debug entry message.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d3740 | TimerFrameRateThrottle | R | Function pointer — registered as Timing handler callback |
| 004d37b0 | TrackTemperatureDisplay | R | Function pointer — registered as Pitstop handler callback |
| 005d3b6c | aDDevF119992002_3 | R | Scene path string for debug logging |
| 005d41d4 | aPitstop | R | "Pitstop" subsystem name string |
| 005d41dc | aTiming | R | "Timing" subsystem name string |
| 005d41e4 | aVehicle | R | "Vehicle" subsystem name string |
| 005d41ec | aEnteredSteward | R | "Entered Steward" debug message string |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer — target for debug log write |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Splits path string for debug message control (line 2330) |
| 004d7aa0 | DebugLogWrite | Writes "Entered Steward" debug message |
| 005599d0 | sub_5599D0 | Registers Vehicle subsystem with handler |
| 00559a00 | sub_559A00 | Registers Timing/Pitstop subsystem with handler callback |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| StringSplitLoop | — | != | 0 | Debug message gate |

**Guard interpretation:** Debug "Entered Steward" message is written only if StringSplitLoop returns non-zero. Subsystem registration calls are unconditional.
