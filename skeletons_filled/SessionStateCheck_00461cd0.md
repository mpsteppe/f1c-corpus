## SessionStateCheck_00461cd0 — SessionStateCheckAndTransition

**Summary:** Returns current session state; transitions state from 4 to 3 if delegated call indicates ready (returns 3).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScoringGateCheck (0042bc10), GamePostMainLoop (0042d8a0), YouHaveBeenBootedHandler (00461d20), SessionStateCheckWrapper (00461db0), StateCheckWrapper (00461dc0), DriverEntrantSetupEntry (00462550), AutoJoinRetryLoop (004637a0), GameMode (0046d6d0), MultiplayerSessionJoinHandler (0046de10), StateDependentVirtualDispatch (004780d0), VirtualDispatchWithConditionalArgBasedOnState (004781a0), ShortComputation_f070 (0049f070), sub_49F870 (0049f870), SessionStateDispatch (004a0df0), sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | COM interface pointer used for delegation call |
| obj | 0x3FC4 | RW | 3 | Session phase/state field (4=loading, 3=ready) |
| this | 0x0 | R | — | This pointer dereference to access struct fields |

**Written-by note (persistence):**
- obj 0x3FC4: written from 4 to 3 conditionally; persists until next state change

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a900 | SingleDelegationCall_a900 | Query COM object for readiness state |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3FC4 | != | 4 | Session state field — skip transition when not 4 |

**Guard interpretation:** State transitions from 4→3 only when current state == 4 and delegation call returns 3. All other states (1,2,3,5+) return current value unchanged.
