## StateDependentVTableDispatch_7760_00487760 — State-machine dispatch with boolean input

**Summary:** Switch-dispatches on state from ShortComputation_6720 (0-4): maps boolean a2 and state to different vtable+64 argument values, with case 4 additionally checking ByteFieldGetterAt100 and RangeCheck.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIControlStateChangeHandler (00487960), InitDispatchWithVTableCheck (004879e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00487810 | jpt_48776F | R | jump table pointer for switch dispatch on state (0-4) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486710 | ByteFieldGetterAt100 | retrieves current UI state byte for case 4 guard check |
| 00486720 | ShortComputation_6720 | computes current state (0-4) for switch dispatch |
| 00487740 | RangeCheck | validates range for case 4 dispatch path selection |

**Guard conditions:** Switch on ShortComputation_6720 result. States 0-3: each maps a2==0/non-zero to specific vtable+64 argument; unmatched a2 value within a state skips vtable call. Case 4: ByteFieldGetterAt100 returns non-zero — BLOCKS entire case 4 body. RangeCheck(false) — selects argument 0/1 vs 2/3 path in case 4. Default — returns state value unchanged with no vtable call.
