## StateResetOnCondition_0040d450 — StateResetOnCondition

**Summary:** Checks if state field equals 3; if so, resets to -1 and triggers GameActionStateMachine with action code 3. Used by TrackTemperatureDisplay for temperature state transitions (e.g., resetting overheated state).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackTemperatureDisplay (004d37b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | 18446744073709551615 | State field — compared against 3 for conditional reset, restored to -1 |

**Written-by note (persistence):**
- this 0x14: conditional reset — only written when value == 3. External poke persists unless it equals 3.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cde0 | GameActionStateMachine | Handle game action state transition with given action (3) and sub-action (0) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | == | 3 | State field being checked for reset condition |

**Guard interpretation:** this[0x14] == 3 → PASS: reset to -1 and call state machine. this[0x14] != 3 → BLOCKED: return without action.
