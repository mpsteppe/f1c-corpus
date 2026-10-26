## StateChangeNotify_004a5c80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AICommandMessageQueueDispatcher (00424cd0), AIStateReset (0042af40), SessionTransitionDispatch (004a5e10), StateConditionalAction (004a5e40), sub_4A5EA0 (004a5ea0), sub_4A5F20 (004a5f20), VehicleProximityCollisionDetection (004a5fa0), PitStopProgress (004a68b0), sub_4A6D50 (004a6d50), PitStateUpdateMachine (004a6e50), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x18C | RW | — | [LLM] |

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
| 004a5d10 | AIStateMachineWithModeDispatch | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
