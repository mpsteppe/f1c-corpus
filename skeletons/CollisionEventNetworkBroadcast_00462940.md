## CollisionEventNetworkBroadcast_00462940 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_13e0 (004613e0), DeferredTextureObjectLoader (0046e1b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | R | — | [LLM] |
| obj | 0x3FC4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 0057a680 | COMVTableCallVia0x60 | [LLM] |
| 0057a690 | VirtualMethodDispatch | [LLM] |
| 0057a6a0 | NetworkSendDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
