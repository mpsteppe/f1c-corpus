## StateDependentVTableDispatch_00487330 — RadioCheckStateDispatchType2

**Summary:** Dispatches to vtable offset 64 based on widget mode (from ShortComputation_6720). Similar structure to sub_487260 but with different parameter mapping per state. Case 4 uses ShortComputation_7720 instead of RangeCheck. Part of radio/checkbox state machine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIWidgetPropagateState (0048741b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004873e0 | jpt_48733E | R | jump table for switch on ShortComputation_6720 result |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486710 | ByteFieldGetterAt100 | read byte at this+100 (current state) used in case 4 |
| 00486720 | ShortComputation_6720 | get current widget mode/state (switch selector) |
| 00487720 | ShortComputation_7720 | range/mode check influencing case 4 sub-dispatch |

**Guard conditions:** Switch on ShortComputation_6720 result (0-4). Cases 0,1: execute only when a2 != 0. Cases 2,3: execute only when a2 == 0. Case 4: execute only when ByteFieldGetterAt100 returns 0; then further branches on ShortComputation_7720 to select vtable parameter (0/2 or 1/3). Default: returns v2 unchanged (no-op).
