## PitTimingUpdate_004b7a90 — Pit Timing Update

**Summary:** Main pit timing tick function: updates per-vehicle pit timers, triggers pit stall proximity checks, dispatches pit crew allocation across 104 vehicle slots (round-robin 12 per frame), processes session data messages, and manages pit stop actions based on timing thresholds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | R | — | Pointer to pit stall circular buffer data array |
| this | 0x9B8 | R | — | Circular buffer write index |
| this | 0xD28 | RW | — | Round-robin step counter (0-11, advances by 1 per frame mod 12) |
| this | 0xD78 | RW | — | Previous a4 value store (compared for delta check) |
| this | 0xD7C | RW | — | Per-vehicle timer accumulator array (reset when threshold exceeded) |
| this | 0xF78 | R | — | Disable flag byte (if non-zero, skip entire update) |
| this | 0xF7C | R | — | Per-vehicle time threshold (compared against accumulated timer) |

**Written-by note (persistence):**
- this 0xD28: Incremented by 1 per frame, wrapped mod 12; persists.
- this 0xD78: Set to a4 each call; overwritten each frame.
- this 0xD7C: Accumulated per frame, reset to 0 on threshold exceed; persists.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b7c60 | jpt_4B7BDF | R | Jump table for session message type switch |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: clock sync tolerance) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: VehicleCount) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3af0 | AdvanceRingBuffer | Advance to next entry in session data ring buffer |
| 004b3b30 | SessionDataCopy | Copy session data buffer for processing |
| 004b5c50 | VehicleInstanceListBuilder | Build per-slot vehicle instance lists |
| 004b5da0 | PitStallProximityCheck | Check vehicle proximity to pit stalls |
| 004b6190 | sub_4B6190 | Pit crew worker allocation for a vehicle slot |
| 004b6940 | PitstopActionSet | Set pit stop action entry in buffer |
| 004c71c0 | SetupCarLightingAndRender | Set up vehicle lighting/render state |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | Reset per-frame timing counter |
| 00568d90 | PerformanceCounterDiffWithScaling | Get scaled time delta from performance counter |

**Guard conditions:** If *(this+0xF78) (disable flag) is non-zero, return 0 — entire update skipped. Time check: only proceed if performance delta > 0.025 AND |a4 - previous_a4| > 0.001. Session data loop: process only if *a2 > 0.
