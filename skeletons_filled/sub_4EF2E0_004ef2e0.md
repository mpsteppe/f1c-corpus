## sub_4EF2E0_004ef2e0 — ForceFeedbackEventLogger

**Summary:** Monitors force feedback state changes and logs events to ring buffer via ProgressBarEventEncode. Throttled to ~8Hz (0.125s debounce) with forced-flush path when delta > 4.0s.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Unit/object identifier passed to ProgressBarEventEncode |
| this | 0x1018 | RW | — | Timestamp of last force feedback event (session time) |
| this | 0x101C | R | — | Previously stored force feedback state word 0 |
| this | 0x1020 | R | — | Previously stored force feedback state word 1 |
| this | 0x1024 | R | — | Previously stored force feedback state word 2 |
| this | 0x1028 | R | — | Previously stored force feedback state word 3 |
| this | 0x102C | R | — | Previously stored force feedback state field (short) |

**Written-by note (persistence):**
- this 0x1018: Written each time an event is logged (both paths); updated to current session time

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e4e0 | flt_59E4E0 | R | ForceIncrementClamp [DERIVED] (also: ` — scroll auto-repeat threshold (delta time gate) |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | Encodes and stores event data into ring buffer at given write pointer |
| 004e2760 | ForceFeedback | Returns pointer to force feedback state struct at given offset from this |

**Guard conditions:** Three gates: (1) `v2 >= 0.125` — PASSES if time from last event >= 0.125s (debounce), BLOCKED if < 0.125s; (2) `v2 <= 4.0` — PASSES if delta <= 4.0s (compare state & log on change), BLOCKED if > 4.0s (force-log without compare); (3) `!v16` (compare mismatch) — PASSES if force feedback state changed, BLOCKED if state unchanged.
