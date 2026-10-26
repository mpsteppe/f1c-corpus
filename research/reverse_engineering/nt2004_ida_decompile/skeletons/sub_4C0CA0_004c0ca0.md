## sub_4C0CA0_004c0ca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B75A0 (004b75a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x51A8 | R | — | [LLM] |
| obj | 0x51AC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x14C | R | — | [LLM] |
| this | 0x154 | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x164 | R | — | [LLM] |
| this | 0x24C | R | — | [LLM] |
| this | 0x254 | R | — | [LLM] |
| this | 0x260 | R | — | [LLM] |
| this | 0x28C | R | — | [LLM] |
| this | 0x294 | R | — | [LLM] |
| this | 0x2A0 | R | — | [LLM] |
| this | 0x2A4 | R | — | [LLM] |
| this | 0x2CC | R | — | [LLM] |
| this | 0x2D4 | R | — | [LLM] |
| this | 0x2DC | R | — | [LLM] |
| this | 0x2E0 | R | — | [LLM] |
| this | 0x2E4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004c16e0 | jpt_4C0CBB | R | [LLM] |
| 004c16f8 | jpt_4C0E83 | R | [LLM] |
| 005d5e28 | dbl_5D5E28 | R | [LLM] |
| 005d5e30 | dbl_5D5E30 | R | [LLM] |
| 005d5e38 | dbl_5D5E38 | R | [LLM] |
| 005fc194 | aD_4 | R | [LLM] |
| 005fcc0c | aS_0 | R | [LLM] |
| 005fd838 | aS_1 | R | [LLM] |
| 005fd8ac | aD | R | [LLM] |
| 005fd8e4 | off_5FD8E4 | R | [LLM] |
| 005fd8f4 | a2fS | R | [LLM] |
| 005fd8fc | aTurns | R | [LLM] |
| 00601c20 | a1f | R | [LLM] |
| 00601d08 | aNone_0 | R | [LLM] |
| 00601e40 | aNo_1 | R | [LLM] |
| 00601e44 | off_601E44 | R | [LLM] |
| 006094bc | aLongestLine | R | [LLM] |
| 0060a290 | aDD_4 | R | [LLM] |
| 0060a2a0 | aDD_3 | R | [LLM] |
| 0060a2b0 | a2f2f_1 | R | [LLM] |
| 0060a2c0 | a2f2f_0 | R | [LLM] |
| 0060a2d0 | a2f | R | [LLM] |
| 0060a2d8 | a1f1f_0 | R | [LLM] |
| 0060a2e8 | a1f1f | R | [LLM] |
| 0060a2f8 | aDD_2 | R | [LLM] |
| 0060a304 | aDD_1 | R | [LLM] |
| 0060a310 | aSDLapSLeft | R | [LLM] |
| 0060a324 | aDoNotRepair | R | [LLM] |
| 0060a334 | aRepair | R | [LLM] |
| 0060a33c | aChangeBoth | R | [LLM] |
| 0060a348 | aChangeRight | R | [LLM] |
| 0060a358 | aChangeLeft | R | [LLM] |
| 0060a364 | aNoChange | R | [LLM] |
| 0060a370 | a2Cans | R | [LLM] |
| 0060a378 | a15Cans | R | [LLM] |
| 0060a384 | a1Can | R | [LLM] |
| 0060a38c | a05Cans | R | [LLM] |
| 0060a398 | aSplash | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0062a170 | dword_62A170 | R | [LLM] |
| 0062a17c | Destination | RW | [LLM] |
| 0062a37b | byte_62A37B | W | [LLM] |
| 007689f0 | dword_7689F0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041f230 | BinarySearchInStringTable [structural] | [LLM] |
| 004c0c70 | sub_4C0C70 | [LLM] |
| 005beab0 | _strncpy | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x51A8 | == | 3 | [LLM] |
| this | 0x1C | == | 1 | [LLM] |
| this | 0xDC | == | 1 | [LLM] |
| this | 0x11C | == | 1 | [LLM] |
| this | 0x2DC | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%d%%`
- `N/A`
- `N/A`
- `N/A`
- `N/A`
- `N/A`
- `N/A`
- `N/A`
- `N/A`
- `%.2f %s`
- `turns`
- `turns`
- `%.1f`
- `%.1f`
- `None`
- `None`
- `None`
- `None`
- `Yes`
- `Longest Line`
- … +32 more
