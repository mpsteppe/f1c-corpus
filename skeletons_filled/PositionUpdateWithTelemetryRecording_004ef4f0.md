## PositionUpdateWithTelemetryRecording_004ef4f0 — TelemetryRecordingTick

**Summary:** Records position telemetry data to ring buffer when session time exceeds last recording time by 4.5s threshold. Part of telemetry/event recording system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Gearbox (00443b70), RaceStartCountdownStateUpdate (004ef930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Unit or vehicle identifier passed to telemetry event |
| this | 0x34AC | R | — | Telemetry data payload value |
| this | 0x4014 | RW | — | Last telemetry recording timestamp |

**Written-by note (persistence):**
- this 0x4014: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acb5c | flt_5ACB5C | R | ToleranceOffset [DERIVED] (also: ` — float, tolerance offset) |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | Encodes telemetry/event entry into ring buffer |

**Guard conditions:** Checks if session time (dbl_8AFEA0) exceeds last recording timestamp (this+0x4014) + 4.5s. PASSES (records telemetry) when condition true; BLOCKED (no recording) when insufficient time elapsed since last record.
