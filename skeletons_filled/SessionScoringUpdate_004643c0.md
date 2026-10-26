## SessionScoringUpdate_004643c0 — Per-frame session state manager and scoring update

**Summary:** Core per-frame update for race session state machine — advances timers, dispatches linked-list session-state messages, manages server communication (OK request, track-open signal), and triggers scoring/timing subsystems. Part of the session lifecycle management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x1B770) | 0x0 | R | — | Session object base pointer (dereferenced from this) |
| obj | 0x28 | RW | 0 | ServerOK requested flag — set after SendServerOKRequest, then cleared |
| obj | 0x29 | R | — | TrackOpen guard — prevents duplicate ServerOpenTrackSignal calls |
| obj | 0x37C | RW | — | Session countdown timer (float) — decremented each tick; triggers state transition when <0 |
| obj | 0x384 | RW | — | Session elapsed time accumulator (float) — incremented when not in transition state |
| obj | 0x388 | RW | — | Secondary elapsed-time accumulator (float) — always incremented |
| obj | 0x3FB8 | R | — | Field read by StructFieldReadAt0x3e14 sub-call (likely session metadata) |
| obj | 0x3FC4 | R | — | Field read by sub-call (likely session metadata) |
| obj | 0x1B770 | RW | — | Session phase/state ID (0=idle, 1/2=transition/active) — guard and dispatch key |
| obj | 0x1B774 | RW | — | Network-comm ready flag — tested by SingleDelegationCall_a900 to gate comm updates |
| obj | 0x1B778 | RW | 0 | Linked-list head for pending session-state dispatch messages |
| obj | 0x1B77C | R | — | Pointer/length for StringLengthCheckDispatch (likely string buffer) |
| this | 0x0 | R | — | `this` pointer to session scoring object |

**Written-by note (persistence):**
- obj 0x28: conditional write (set to 0 after sending OK) — external poke overwritten each tick when flag is true
- obj 0x37C: conditional — decremented only in non-transition states; external poke survives until next non-transition tick
- obj 0x384: conditional — incremented only in non-transition states; value accumulates across calls
- obj 0x388: unconditional — always incremented each tick; value is effectively monotonic
- obj 0x1B770: read-only guard in this function — written externally by state machine
- obj 0x1B774: read-only in this function — written externally
- obj 0x1B778: conditional — linked-list head updated when messages exist; external poke survives until next message dispatch

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c7e0 | CollisionContactBufferTimestepUpdate | Advances collision contact buffer timestep with delta time |
| 0045d4e0 | StringLengthCheckDispatch | Dispatches string-length-check logic on session string buffer (called only in transition states) |
| 0045fc50 | NetCommPlayerSlotSync | Synchronizes player slot state over network communication |
| 00460380 | ClientGridDisplayTimer | Updates client-side grid display timer for race start |
| 00460470 | SendServerOKRequest | Sends "OK" acknowledgement request to server |
| 00460cb0 | ClearPlayerSlots | Clears/resets player slot data |
| 00460dd0 | CollisionContactIteration | Iterates collision contacts for the current frame |
| 00460e90 | ServerOpenTrackSignal | Signals server that track is open (sent only on transition, guarded by byte flag) |
| 004612e0 | TrackOpeningProgressTimer | Updates track-opening progress timer |
| 00462370 | StructFieldReadAt0x3e14 | Reads a field from this object at or near offset 0x3E14 |
| 00464740 | LinkedListNodeRemoval | Removes a node from the linked-list message queue |
| 004a0490 | sub_4A0490 | Operates on unk_7CE24C (session data object) during state transition |
| 004a0d30 | GlobalStateSetter | Sets a global state variable (called with value 1 on timer expiry) |
| 004a0db0 | sub_4A0DB0 | Operates on unk_7CE24D (session transition flag) during state transition |
| 004a0df0 | SessionStateDispatch | Dispatches a session-state message string to the appropriate handler |
| 0057a900 | SingleDelegationCall_a900 | Single-delegation call — gates communication block based on network-ready flag |
| 00587bcf | FreeWrapper_7bcf | Frees allocated memory (wraps operator delete/free) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x1B770 | == | 0 | Session phase/state ID |

**Guard interpretation:** Field `obj+0x1B770` (session phase/state ID) tested against 0. **BLOCKED (early return):** when state == 0 — session is idle/inactive, no processing occurs. **PASSES:** when state != 0 — session is active (values 1 or 2 trigger transition logic; values >2 use non-transition path). All further branching within the function depends on this guard being passed.
