## TimerResetUsingQueryPerformanceCounter_00568c60 — HighResTimerReset

**Summary:** Resets the high-resolution timer by capturing a new QPC timestamp and zeroing all timing accumulators. If the timer mode bit 0 is set, reads a fresh QPC value; otherwise reuses the existing counter snapshot. Returns the current counter LowPart.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RunCollisionDetectionLoop (0045f390), AutoJoinRetryLoop (004637a0), sub_464D30 (00464d30), sub_4989E0 (004989e0), CarPhysicsStateInitializer (004b57f0), PitTimingUpdate (004b7a90), sub_4F9FC0 (004f9fc0), sub_4FA7E0 (004fa7e0), FloatSetWithTimingCall (00583660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency LowPart (non-zero indicates initialized) |
| this | 0x10 | RW | 0 | accumulated time low part (zeroed on reset) |
| this | 0x14 | RW | 0 | accumulated time high part (zeroed on reset) |
| this | 0x18 | RW | — | last QPC counter LowPart snapshot (updated with new value) |
| this | 0x1C | RW | — | last QPC counter HighPart snapshot (updated with new value) |
| this | 0x20 | RW | — | working QPC counter LowPart copy (set to snapshot) |
| this | 0x24 | RW | — | working QPC counter HighPart copy (set to snapshot) |
| this | 0x28 | RW | 0 | tick accumulator low part (zeroed on reset) |
| this | 0x2C | RW | 0 | tick accumulator high part (zeroed on reset) |
| this | 0x30 | RW | 0 | second tick accumulator low part (zeroed on reset) |
| this | 0x34 | RW | 0 | second tick accumulator high part (zeroed on reset) |
| this | 0x48 | R | — | timer mode/flags (bit 0 controls QPC re-read) |

**Written-by note (persistence):**
- this 0x10: zeroed unconditionally; reset on each reset call
- this 0x14: zeroed unconditionally; reset on each reset call
- this 0x18: written (new QPC value or preserved); snapshot updates
- this 0x1C: written (new QPC value or preserved); snapshot updates
- this 0x20: written unconditionally; working copy updates
- this 0x24: written unconditionally; working copy updates
- this 0x28: zeroed unconditionally; reset on each reset call
- this 0x2C: zeroed unconditionally; reset on each reset call
- this 0x30: zeroed unconditionally; reset on each reset call
- this 0x34: zeroed unconditionally; reset on each reset call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | Win32 QPC API pointer to get current performance counter |
| ff00000000005406 | byte_FF00000000005406 | R | unknown timer-related byte |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if *this (frequency field at offset 0) is zero, the timer was never initialized and the entire reset is skipped — returns stale result.
