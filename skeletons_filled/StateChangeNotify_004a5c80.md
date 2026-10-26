## StateChangeNotify_004a5c80 — StateChangeRecorderWithRingBuffer

**Summary:** Records a state change event into a ring buffer for replay/progress bar. On state transitions to 1 or 2 (with specific conditions), saves the session timestamp. Increments a ring buffer counter (max 1023 entries, each 432 bytes), encodes a progress bar event (type 6), and dispatches AI state machine processing on the new entry.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AICommandMessageQueueDispatcher (00424cd0), AIStateReset (0042af40), SessionTransitionDispatch (004a5e10), StateConditionalAction (004a5e40), sub_4A5EA0 (004a5ea0), sub_4A5F20 (004a5f20), VehicleProximityCollisionDetection (004a5fa0), PitStopProgress (004a68b0), sub_4A6D50 (004a6d50), PitStateUpdateMachine (004a6e50), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Event identifier logged into ring buffer entry |
| this | 0x184 | R | — | Current state value (compared against new state `a2`) |
| this | 0x18C | RW | — | Timestamp of state change (recorded session time on specific transitions) |

**Written-by note (persistence):**
- this 0x18C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5d10 | AIStateMachineWithModeDispatch | Processes AI state machine from the ring buffer entry |
| 004b33b0 | ProgressBarEventEncode | Encodes a progress bar/replay event (type 6) with identifier and timestamp |

**Guard conditions:** Checks `a2 != *(_DWORD *)(this + 388)` (offset 0x184). PASSES when new state differs from current state. BLOCKED entirely when a2 equals current state (no redundant notification).