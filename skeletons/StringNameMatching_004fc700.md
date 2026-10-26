## StringNameMatching_004fc700 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | RW | — | [LLM] |
| this | 0x6F | RW | 0 | [LLM] |
| this | 0xA3 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x6F: [LLM: once/conditional? does external poke survive?]
- this 0xA3: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a0 | dword_7C56A0 | R | MultiplayerFlags [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9a00 | PackedFlagRead_9a00 | [LLM] |
| 004fc550 | sub_4FC550 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x44 | != | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
