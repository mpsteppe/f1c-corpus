## RenderTargetCleanup_0053f270 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RendererResourceCleanup (0053ead0), sub_555E50 (00555e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x1580)+0x870)+0x868) | 0x54 | R | — | [LLM] |
| *(*(this+0x1580)+0x870) | 0x868 | R | — | [LLM] |
| *(*(this+0x1580)+0x870) | 0x870 | R | — | [LLM] |
| *(this+0x1518) | 0x30 | R | — | [LLM] |
| *(this+0x1518) | 0x34 | RW | 0 | [LLM] |
| *(this+0x1518) | 0x40 | R | — | [LLM] |
| *(this+0x1518) | 0x84 | R | — | [LLM] |
| this | 0x113C | RW | 0 | [LLM] |
| this | 0x1140 | RW | 0 | [LLM] |
| this | 0x1144 | RW | 0 | [LLM] |
| this | 0x13A0 | RW | 1 | [LLM] |
| this | 0x13A8 | RW | — | [LLM] |
| this | 0x14F0 | RW | 0 | [LLM] |
| this | 0x14F4 | RW | 0 | [LLM] |
| this | 0x14F8 | RW | 0 | [LLM] |
| this | 0x14FC | RW | 0 | [LLM] |
| this | 0x1500 | RW | 0 | [LLM] |
| this | 0x1504 | RW | 0 | [LLM] |
| this | 0x1518 | R | — | [LLM] |
| this | 0x1580 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1518) 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x113C: [LLM: once/conditional? does external poke survive?]
- this 0x1140: [LLM: once/conditional? does external poke survive?]
- this 0x1144: [LLM: once/conditional? does external poke survive?]
- this 0x13A0: [LLM: once/conditional? does external poke survive?]
- this 0x13A8: [LLM: once/conditional? does external poke survive?]
- this 0x14F0: [LLM: once/conditional? does external poke survive?]
- this 0x14F4: [LLM: once/conditional? does external poke survive?]
- this 0x14F8: [LLM: once/conditional? does external poke survive?]
- this 0x14FC: [LLM: once/conditional? does external poke survive?]
- this 0x1500: [LLM: once/conditional? does external poke survive?]
- this 0x1504: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | [LLM] |
| 00541040 | DrainingLoopFinalizer | [LLM] |
| 00544af0 | AudioNetworkStreamCleanup | [LLM] |
| 00545f40 | ValueGetter | [LLM] |
| 005528b0 | ConditionalFreeByFlag_28b0 | [LLM] |
| 00554cc0 | D3DResourceRelease | [LLM] |
| 00554d70 | UICleanupIterator | [LLM] |
| 00554e10 | D3DResourceListCleanup | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
