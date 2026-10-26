## ShortComputation_f0d0_0040f0d0 — ShortComputation_f0d0

**Summary:** Guarded chain: if ID field is not -1, inserts node into linked list, processes nested loop, and runs cleanup subroutine. Part of scene graph / widget management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsStateVectorConversion (0040ef70), ModeDispatchWithSwitch (0040f4b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | ID/identifier field; -1 (0xFFFFFFFF) = skip/blocked |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410ad0 | LinkedListNodeInsert_0ad0 | Inserts this node into linked list |
| 004bde20 | sub_4BDE20 | Cleanup subroutine after processing |
| 004be180 | NestedLoopCall | Processes nested loop on this node |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 18446744073709551615 | ID field; -1 (0xFFFFFFFF) |

**Guard interpretation:** this[0] == -1 (0xFFFFFFFF) → skip (blocked). this[0] != -1 → linked list insert + nested loop + cleanup (passes through).
