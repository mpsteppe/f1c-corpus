## sub_4BFD80_004bfd80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BF1F0 (004bf1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006011d8 | aSSSS | R | [LLM] |
| 00609de8 | aPits_0 | R | [LLM] |
| 0060a018 | off_60A018 | R | [LLM] |
| 0060a140 | aSPitcrewScr | R | [LLM] |
| 0060a150 | word_60A150 | R | [LLM] |
| 0060a152 | byte_60A152 | R | [LLM] |
| 0060a154 | aSSpits | R | [LLM] |
| 00628f60 | flt_628F60 | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a068 | dword_62A068 | R | [LLM] |
| 0062a0b0 | dword_62A0B0 | R | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 00766238 | dword_766238 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f90 | sub_404F90 | [LLM] |
| 0042dba0 | sub_42DBA0 | [LLM] |
| 004bd290 | sub_4BD290 | [LLM] |
| 004bddb0 | sub_4BDDB0 | [LLM] |
| 004be8c0 | sub_4BE8C0 | [LLM] |
| 00591f10 | sub_591F10 | [LLM] |
| 00592030 | StringMatchWithFlagSet [structural] | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s%s%s`
- `PITS\`
- `%s\PITCREW.SCR`
- `%s%sPITS\`
