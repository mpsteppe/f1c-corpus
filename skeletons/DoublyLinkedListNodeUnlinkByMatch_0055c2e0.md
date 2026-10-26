## DoublyLinkedListNodeUnlinkByMatch_0055c2e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceCascadeCleanup (005539f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1538)+0x1C) | 0x20 | RW | — | [LLM] |
| *(*(this+0x1538)+0x20) | 0x1C | RW | — | [LLM] |
| *(*(this+0x1538)+0x20) | 0x20 | R | — | [LLM] |
| *(this+0x1538) | 0x1C | R | — | [LLM] |
| *(this+0x1538) | 0x20 | R | — | [LLM] |
| this | 0x1518 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x1538)+0x1C) 0x20: [LLM: once/conditional? does external poke survive?]
- *(*(this+0x1538)+0x20) 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x1518: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
