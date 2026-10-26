## sub_4BCED0_004bced0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BD350 (004bd350)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2 | RW | 0 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x2: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00609d3c | aRrwheelonMts | R | [LLM] |
| 00609d4c | aRrwheeloffMts | R | [LLM] |
| 00609d5c | aLrwheelonMts | R | [LLM] |
| 00609d6c | off_609D6C | R | [LLM] |
| 00609d70 | aLrwheeloffMts | R | [LLM] |
| 00609d80 | aRfwheelonMts | R | [LLM] |
| 00609d90 | aRfwheeloffMts | R | [LLM] |
| 00609da0 | aLfwheelonMts | R | [LLM] |
| 00609db0 | off_609DB0 | R | [LLM] |
| 00609db4 | aLfwheeloffMts | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bcde0 | sub_4BCDE0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `RRWHEELON.MTS`
- `RRWHEELOFF.MTS`
- `LRWHEELON.MTS`
- `TLR`
- `TLR`
- `TLR`
- `TLR`
- `TLR`
- `TLR`
- `TLR`
- `TLR`
- `LRWHEELOFF.MTS`
- `RFWHEELON.MTS`
- `RFWHEELOFF.MTS`
- `LFWHEELON.MTS`
- `TRF`
- `TRF`
- `TRF`
- `TRF`
- `TRF`
- … +4 more
