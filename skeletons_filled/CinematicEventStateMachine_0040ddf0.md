## CinematicEventStateMachine_0040ddf0 — CinematicEventStateMachine

**Summary:** State machine for cinematic event playback: states -1/0/1 blocked; states 2-5 search the "CinematicEvent" string-linked-list and attempt to start the race commentary director system. On success resets to state 2 and clears counters; on failure sets error state -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineInitializer (0040dcd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 2 on success, -1 on failure | state field, inspected via switch and updated |
| this | 0x88 | R | — | pointer to sub-struct passed to RaceCommentaryDirectorSystem |
| this | 0x98 | RW | 0 | counter cleared on successful cinematic start |
| this | 0x9C | RW | 0 | counter cleared on successful cinematic start |

**Written-by note (persistence):**
- this 0x0: written unconditionally on success (2) or failure (-1) when in states 2-5 — final value persists
- this 0x98: written only on success (states 2-5, RaceCommentaryDirectorSystem returns non-zero) — 0 — persists
- this 0x9C: written only on success — 0 — persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040de4c | jpt_40DE02 | R | jump table for switch statement |
| 0040de54 | byte_40DE54 | R | unknown lookup table for switch |
| 005beb50 | aCinematicevent | R | CinematicEventField [DERIVED], string key passed to StringKeyedLinkedListSearch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d4c0 | RaceCommentaryDirectorSystem | manages race commentary director, called with this+0x88 and search result |
| 005679c0 | StringKeyedLinkedListSearch | searches string-keyed linked list for "CinematicEvent" key |

**Guard conditions:**
- *this == -1, 0, 1 → BLOCKED (return 0, state unchanged).
- *this == 2, 3, 4, 5 → ATTEMPT:
  - StringKeyedLinkedListSearch(aCinematicevent) searches for key.
  - RaceCommentaryDirectorSystem returns 0 → BLOCKED (*this = -1, return 0).
  - RaceCommentaryDirectorSystem returns non-zero → PASSES (clear counters, *this = 2, return 1).
- *this == any other value → BLOCKED (*this = -1, return 0).
