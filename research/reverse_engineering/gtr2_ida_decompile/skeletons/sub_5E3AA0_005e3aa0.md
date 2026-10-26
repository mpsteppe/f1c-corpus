## sub_5E3AA0_005e3aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5E6040 (005e6040), sub_5E9420 (005e9420), sub_5E9C00 (005e9c00), sub_5FF950 (005ff950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xDC) | 0x6C | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x88 | RW | 0 | [LLM] |
| this | 0xDC | RW | 0 | [LLM] |
| this | 0xE0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x88: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xDC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xE0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e2ac0 | sub_5E2AC0 | R | [LLM] |
| 005e2b00 | j_j_nullsub_7 | R | [LLM] |
| 005e43b4 | jpt_5E4022 | R | [LLM] |
| 005e43c4 | byte_5E43C4 | R | [LLM] |
| 006ec6a8 | SEH_5E3AA0 | R | [LLM] |
| 006f1f34 | aSS | R | [LLM] |
| 006f2a98 | aS_2 | R | [LLM] |
| 006f5fec | flt_6F5FEC | R | [LLM] |
| 006f6048 | dbl_6F6048 | R | [LLM] |
| 00712ee0 | aDds | R | [LLM] |
| 0072bc08 | aErrorInitializ | R | [LLM] |
| 0072bd18 | aErrorLoadingTe_0 | R | [LLM] |
| 0072bd34 | aErrorLoadingTe | R | [LLM] |
| 0072bd60 | aErrorInitializ_1 | R | [LLM] |
| 0072bd8c | aS4sSC | R | [LLM] |
| 0072bd98 | aS2dS | R | [LLM] |
| 0072bda4 | word_72BDA4 | R | [LLM] |
| 0072bda6 | byte_72BDA6 | R | [LLM] |
| 0072bda8 | aErrorInitializ_0 | R | [LLM] |
| 0072bdcc | aSpecpower1f | R | [LLM] |
| 0072bddc | aCubenormalizer | R | [LLM] |
| 00fb2754 | byte_FB2754 | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |
| 00fb27f8 | dword_FB27F8 | R | [LLM] |
| 00fb2d78 | dword_FB2D78 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | [LLM] |
| 005d8ce0 | sub_5D8CE0 | [LLM] |
| 005e2e70 | sub_5E2E70 | [LLM] |
| 005e30c0 | sub_5E30C0 | [LLM] |
| 005e6dd0 | sub_5E6DD0 | [LLM] |
| 005e6e70 | sub_5E6E70 | [LLM] |
| 005e6ea0 | sub_5E6EA0 | [LLM] |
| 005e72d0 | sub_5E72D0 | [LLM] |
| 005e7fb0 | sub_5E7FB0 | [LLM] |
| 005e9100 | sub_5E9100 | [LLM] |
| 005e9670 | sub_5E9670 | [LLM] |
| 005f2f60 | j_nullsub_7 | [LLM] |
| 005f4570 | sub_5F4570 | [LLM] |
| 005f4580 | DoubleFieldGetter [structural] | [LLM] |
| 005f4610 | sub_5F4610 | [LLM] |
| 005f4640 | sub_5F4640 | [LLM] |
| 005fdfb0 | sub_5FDFB0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | [LLM] |
| 0063099c | __ftol2 | [LLM] |
| 00630a11 | sub_630A11 | [LLM] |
| 00631761 | _sprintf | [LLM] |
| 00633410 | BitfieldManager [structural] | [LLM] |
| 00633686 | __strupr | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | <= | 1 | [LLM] |
| this | 0x4 | > | 1 | [LLM] |
| this | 0x54 | == | 7 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s%s`
- `%s%s`
- `.DDS`
- `Error loading texture %s`
- `Error loading texture %s for material %s`
- `Error initializing video file texture %s`
- `%s%4s%s%c`
- `%s%.2d%s`
- `%s%.2d%s`
- `Error initializing video file %s`
- `SPECPOWER%.1f`
- `SPECPOWER%.1f`
- `CUBENORMALIZER`
- `CUBENORMALIZER`
