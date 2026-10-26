## UICleanupIterator_00554d70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GuardedSubsystemRelease (00495060), ShortComputation_50c0 (004950c0), RenderTargetCleanup (0053f270), ConditionalUICleanupDispatch (005528f0), D3DResourceRelease (00554cc0), D3DResourceListCleanup (00554e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1100)+0x0) | 0xF0 | R | — | [LLM] |
| *(this+0x1100) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1100 | R | — | [LLM] |
| this | 0x13B0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00554610 | StateParameterSetterWithVirtualDeviceNotify | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x13B0 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
