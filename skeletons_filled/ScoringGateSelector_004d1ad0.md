## ScoringGateSelector_004d1ad0 — PenaltyGatePrioritySelector

**Summary:** Scans a scoring/penalty gate list at this[68] with given range, selecting the highest-priority gate type (3 > 8 > 2 > 0). Returns 3 for invalid/out-of-range, or the best match.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISessionModeTransition (004193a0), PitSelectionStateMachine (0041b3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x110 | R | — | pointer to array of gate entries (8-byte stride), accessed at this[68] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ad264 | dword_8AD264 | R | PenaltyMessageQueue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7bf0 | ShortComputation_7bf0 | computes start index bound for the gate range |
| 004d7c00 | ArrayAccessAt0xcIndex4 | computes end index bound for the gate range (paired with start) |

**Guard conditions:** If start index > end index, returns 0 (no gate selected). If a gate value == 3 encountered, immediately returns 3 (highest priority, short-circuit). Values 8 and 2 are accumulated as fallback priorities.
