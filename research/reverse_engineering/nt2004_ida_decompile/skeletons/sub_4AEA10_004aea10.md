## sub_4AEA10_004aea10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AD050 (004ad050), sub_4BA730 (004ba730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x16C) | 0x10 | R | — | [LLM] |
| this | 0x16C | R | — | [LLM] |
| this | 0x494 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x494: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5580 | flt_5D5580 | R | [LLM] |
| 005d6498 | flt_5D6498 | R | [LLM] |
| 005ea25c | flt_5EA25C | R | [LLM] |
| 005ea260 | flt_5EA260 | R | [LLM] |
| 005fb7e8 | Format | R | [LLM] |
| 00601114 | aOptionsMas | R | [LLM] |
| 00608ff0 | a2003euro24 | R | [LLM] |
| 00608ffc | aSavingreplay00 | R | [LLM] |
| 006152e8 | dword_6152E8 | R | [LLM] |
| 006152ec | dword_6152EC | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a098 | dword_62A098 | R | [LLM] |
| 00765b00 | unk_765B00 | R | [LLM] |
| 007d4458 | byte_7D4458 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004aaf50 | sub_4AAF50 | [LLM] |
| 004ab0e0 | sub_4AB0E0 | [LLM] |
| 004ab400 | sub_4AB400 | [LLM] |
| 004ab570 | sub_4AB570 | [LLM] |
| 004ad050 | sub_4AD050 | [LLM] |
| 004ad970 | sub_4AD970 | [LLM] |
| 004b07c0 | sub_4B07C0 | [LLM] |
| 004cf510 | nullsub_6 | [LLM] |
| 004d20d0 | sub_4D20D0 | [LLM] |
| 00505d00 | sub_505D00 | [LLM] |
| 0057b5d0 | StructZeroInit_8ba0 [exact] | [LLM] |
| 0057b610 | QPCTimerInitialization [exact] | [LLM] |
| 0057b690 | TimerResetUsingQueryPerformanceCounter [exact] | [LLM] |
| 0057b7c0 | sub_57B7C0 | [LLM] |
| 005924d0 | sub_5924D0 | [LLM] |
| 00592750 | sub_592750 | [LLM] |
| 00592cd0 | F_3DVectorBlend [structural] | [LLM] |
| 005a3ff0 | sub_5A3FF0 | [LLM] |
| 005a41f0 | sub_5A41F0 | [LLM] |
| 005be8bc | __ftol | [LLM] |
| 005beab0 | _strncpy | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `Options.mas`
- `2003Euro24`
- `Savingreplay0000.tga`
- `Savingreplay0000.tga`
