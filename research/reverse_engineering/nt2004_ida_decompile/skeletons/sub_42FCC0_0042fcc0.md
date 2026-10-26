## sub_42FCC0_0042fcc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** GameMainEntry [structural] (0045c460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fd62c | aDDevNascar2004_2 | R | [LLM] |
| 005fd6ac | aEnteredGameEnt | R | [LLM] |
| 0062bf64 | unk_62BF64 | R | [LLM] |
| 00761d78 | ppvOut | R | [LLM] |
| 00764d70 | dword_764D70 | R | [LLM] |
| 00765e70 | dword_765E70 | R | [LLM] |
| 0076612c | unk_76612C | R | [LLM] |
| 007663e0 | byte_7663E0 | R | [LLM] |
| 007d5da4 | dword_7D5DA4 | R | [LLM] |
| 007d6b5c | unk_7D6B5C | R | [LLM] |
| 007d6b78 | byte_7D6B78 | R | [LLM] |
| 007d73d0 | dword_7D73D0 | R | [LLM] |
| 007d7428 | byte_7D7428 | R | [LLM] |
| 007d7920 | unk_7D7920 | R | [LLM] |
| 007da938 | unk_7DA938 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e110 | SystemOSAPICall [structural] | [LLM] |
| 0042fab0 | sub_42FAB0 | [LLM] |
| 00458310 | sub_458310 | [LLM] |
| 00465d30 | sub_465D30 | [LLM] |
| 004b7960 | sub_4B7960 | [LLM] |
| 004ce9e0 | sub_4CE9E0 | [LLM] |
| 004cf510 | nullsub_6 | [LLM] |
| 004e9710 | sub_4E9710 | [LLM] |
| 004efef0 | sub_4EFEF0 | [LLM] |
| 004f69b0 | sub_4F69B0 | [LLM] |
| 00500f90 | sub_500F90 | [LLM] |
| 00500fe0 | sub_500FE0 | [LLM] |
| 00527b50 | sub_527B50 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `D:\dev\NASCAR_2004\Source\game.cpp`
- `Entered Game::Enter()`
