## sub_4DCEB0_004dceb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4F7F20 (004f7f20), sub_4F84C0 (004f84c0), sub_4F8900 (004f8900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x148 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x148: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0061016c | aSStayBehindThe_0 | R | [LLM] |
| 00610198 | aSStayBehindThe | R | [LLM] |
| 006101b4 | aSStayBehindCar_0 | R | [LLM] |
| 006101dc | aSStayBehindCar | R | [LLM] |
| 006101f4 | aUnderCaution | R | [LLM] |
| 00610204 | aPaceLap | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 00629328 | flt_629328 | R | [LLM] |
| 0062bf68 | unk_62BF68 | R | [LLM] |
| 006310d8 | dword_6310D8 | R | [LLM] |
| 0075cbb4 | dword_75CBB4 | R | [LLM] |
| 00764d68 | byte_764D68 | R | [LLM] |
| 00766220 | unk_766220 | R | [LLM] |
| 007d7428 | byte_7D7428 | R | [LLM] |
| 007d74b8 | dword_7D74B8 | R | [LLM] |
| 007d758c | byte_7D758C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405480 | sub_405480 | [LLM] |
| 0041bb40 | sub_41BB40 | [LLM] |
| 0045d100 | sub_45D100 | [LLM] |
| 004bbf20 | sub_4BBF20 | [LLM] |
| 004ede00 | sub_4EDE00 | [LLM] |
| 004f83b0 | sub_4F83B0 | [LLM] |
| 004fa870 | sub_4FA870 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s Stay Behind the Pace Car On Inside Line`
- `%s Stay Behind the Pace Car`
- `%s Stay Behind Car #%s On Inside Line`
- `%s Stay Behind Car #%s`
- `Under Caution:`
- `Pace Lap:`
