## CarPositionTargetCheck_004fe060 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 007c56a0 | dword_7C56A0 | R | MultiplayerFlags [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9a00 | PackedFlagRead_9a00 | [LLM] |
| 004fc910 | sub_4FC910 | [LLM] |
| 004fd6f0 | RangeInterpolationTable | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
