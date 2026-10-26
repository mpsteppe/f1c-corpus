## StringLengthCheckDispatch_0045d4e0 — ByteFlagNetworkDispatch

**Summary:** Checks two byte flags on object; based on their values, conditionally calls inactivity timeout handler then dispatches network packet receive, or dispatches directly.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Primary flag byte: if nonzero, proceed with dispatch |
| this | 0x1 | R | — | Secondary flag: if nonzero, trigger inactivity timeout check before receive |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** 
- this[0] == 0 → early return (no dispatch).
- this[0] != 0:
  - this[1] != 0 → call TickCountComparisonHandleInactivityTimeout, then call NetworkPacketReceive.
  - this[1] == 0 → call NetworkPacketReceive directly (skip inactivity check).
