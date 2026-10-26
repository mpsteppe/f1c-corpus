## __Mbrtowc_lk_005d256d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** TLSAllocationThreadIDInit [structural] (005d250a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d519c | MultiByteToWideChar | R | [LLM] |
| 00625680 | off_625680 | R | [LLM] |
| 0062588c | SrcSizeInBytes | R | [LLM] |
| 007ff1e8 | dword_7FF1E8 | R | [LLM] |
| 007ff1f8 | CodePage | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1a3c | __errno | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
