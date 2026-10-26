## SessionStateCheck_00461cd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScoringGateCheck (0042bc10), GamePostMainLoop (0042d8a0), YouHaveBeenBootedHandler (00461d20), SessionStateCheckWrapper (00461db0), StateCheckWrapper (00461dc0), DriverEntrantSetupEntry (00462550), AutoJoinRetryLoop (004637a0), GameMode (0046d6d0), MultiplayerSessionJoinHandler (0046de10), StateDependentVirtualDispatch (004780d0), VirtualDispatchWithConditionalArgBasedOnState (004781a0), ShortComputation_f070 (0049f070), sub_49F870 (0049f870), SessionStateDispatch (004a0df0), sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | [LLM] |
| obj | 0x3FC4 | RW | 3 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x3FC4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a900 | SingleDelegationCall_a900 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x3FC4 | != | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
