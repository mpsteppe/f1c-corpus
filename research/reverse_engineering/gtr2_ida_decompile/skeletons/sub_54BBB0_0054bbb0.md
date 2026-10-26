## sub_54BBB0_0054bbb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_430B40 (00430b40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3CB578 | RW | 0 | [LLM] |
| this | 0x3CB579 | R | — | [LLM] |
| this | 0x3CB57C | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x3CB584 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3CB578: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3CB57C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006fd9d0 | aMonitorSingle | R | [LLM] |
| 0071361c | aPostRaceMonito | R | [LLM] |
| 00713630 | aEndurancePostR | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 0075b17c | dword_75B17C | W | [LLM] |
| 0091e084 | dword_91E084 | R | [LLM] |
| 00b640c0 | dword_B640C0 | R | [LLM] |
| 00b640c8 | dword_B640C8 | R | [LLM] |
| 00b64150 | byte_B64150 | W | [LLM] |
| 00b66000 | dword_B66000 | R | [LLM] |
| 00b66040 | dbl_B66040 | R | [LLM] |
| 00b6e090 | dword_B6E090 | R | [LLM] |
| 00b6e4d0 | dword_B6E4D0 | R | [LLM] |
| 00b6f135 | unk_B6F135 | R | [LLM] |
| 00b70900 | byte_B70900 | R | [LLM] |
| 00b70918 | byte_B70918 | R | [LLM] |
| 00b722cc | byte_B722CC | R | [LLM] |
| 00b722e4 | byte_B722E4 | R | [LLM] |
| 00be1204 | dword_BE1204 | R | [LLM] |
| 00be1d30 | byte_BE1D30 | R | [LLM] |
| 00fade1c | flt_FADE1C | R | [LLM] |
| 00fb1d18 | dbl_FB1D18 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004304c0 | sub_4304C0 | [LLM] |
| 004363e0 | sub_4363E0 | [LLM] |
| 0044a5b0 | sub_44A5B0 | [LLM] |
| 004e1810 | sub_4E1810 | [LLM] |
| 004e5fc0 | sub_4E5FC0 | [LLM] |
| 004eab20 | sub_4EAB20 | [LLM] |
| 00521110 | sub_521110 | [LLM] |
| 0053e6a0 | sub_53E6A0 | [LLM] |
| 00540ac0 | ConditionalRatioCompute [exact] | [LLM] |
| 0054b5a0 | sub_54B5A0 | [LLM] |
| 0054bab0 | sub_54BAB0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `MONITOR_SINGLE`
- `POST RACE MONITOR`
- `ENDURANCE POST RACE MONITOR`
