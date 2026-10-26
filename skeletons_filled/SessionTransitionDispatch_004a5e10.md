## SessionTransitionDispatch_004a5e10 — AIModeTransitionSwitch

**Summary:** Drives AI mode transitions: state 0→1 (activate), state 1→0 (deactivate), state 4→1 (reactivate). Routes each transition through StateChangeNotify for ring-buffer recording and dispatch. Other states produce no transition.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x184 | R | — | Current AI mode state (checked for values 0, 1, 4) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5c80 | StateChangeNotify | Records state change event into ring buffer and dispatches AI state machine |

**Guard conditions:** Switch on `this[97]` (offset 0x184): state 0 → transition to 1; state 1 → transition to 0; state 4 → transition to 1; all other states → no transition, returns immediately.