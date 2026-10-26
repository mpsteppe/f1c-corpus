## ConditionalStateMachineDispatch_00487830 — Conditional state-machine dispatch with boolean input

**Summary:** Switch-dispatches on state from ShortComputation_6720 (0-4): maps boolean a2 and state to vtable+64 argument, with case 4 additionally checking ByteFieldGetterAt100 and ShortComputation_7720 for path selection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateChangeHandlerWithSubscriberNotification (00487900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004878e0 | jpt_48783E | R | jump table pointer for switch dispatch on state (0-4) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486710 | ByteFieldGetterAt100 | retrieves current UI state byte for case 4 guard check |
| 00486720 | ShortComputation_6720 | computes current state (0-4) for switch dispatch |
| 00487720 | ShortComputation_7720 | computes secondary condition for case 4 path selection |

**Guard conditions:** Switch on ShortComputation_6720 result. States 0-1: fire when a2 != 0 (args 2,3); a2==0 skips. States 2-3: fire when a2 == 0 (args 0,1); a2!=0 skips. Case 4: ByteFieldGetterAt100 returns non-zero — BLOCKS entire case 4. ShortComputation_7720 result selects between two argument mappings. Default — returns state value unchanged with no vtable call.
