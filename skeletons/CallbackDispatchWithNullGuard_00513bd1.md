## CallbackDispatchWithNullGuard_00513bd1 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9), sub_511B7C (00511b7c), sub_517F58 (00517f58), AnimationStateCheck (00517f72), sub_519019 (00519019)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af4d0 | aCallToNullRead | R | StringCallToNullRead [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00511869 | GuardedCallWithLongjmp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
