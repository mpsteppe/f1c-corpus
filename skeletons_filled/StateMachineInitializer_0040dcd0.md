## StateMachineInitializer_0040dcd0 — StateMachineInitializer

**Summary:** Two-phase state machine init: phase 1 (state=1) initializes a sub-struct and stops audio, storing audio result; phase 2 (state=2) runs cinematic event state machine. Returns success only if both phases pass, else reverts to error state -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Restart (004d3cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1, then 2, then possibly -1 | state machine phase: 1=init, 2=cinematic, -1=error |
| this | 0x84 | RW | 0, then AudioChannelStop return | result/status of audio channel stop operation |
| this | 0x88 | R | — | pointer to sub-struct passed to StructFieldInit |

**Written-by note (persistence):**
- this 0x0: written unconditionally multiple times (1, then 2 or -1) — final value depends on CinematicEventStateMachine result
- this 0x84: written unconditionally, first 0 then AudioChannelStop return value — survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d490 | StructFieldInit | initializes sub-struct pointed by this+0x88 |
| 0040ddf0 | CinematicEventStateMachine | runs cinematic event state machine in phase 2 |
| 00568210 | AudioChannelStop | stops audio channel for the given parameter a2 |

**Guard conditions:**
- AudioChannelStop return value: 0 → BLOCKED (return 0, stays in state 1). Non-zero → PASSES (advances to state 2).
- CinematicEventStateMachine return value: 0 → sets *this = -1, BLOCKED (return 0). Non-zero → PASSES (return 1, success).
