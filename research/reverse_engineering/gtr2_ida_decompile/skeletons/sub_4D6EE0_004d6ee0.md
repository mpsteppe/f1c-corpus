## sub_4D6EE0_004d6ee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x210 | RW | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x21C | R | — | [LLM] |
| this | 0x220 | R | — | [LLM] |
| this | 0x22C | R | — | [LLM] |
| this | 0x238 | R | — | [LLM] |
| this | 0x24C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x210: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006fe938 | aLogo | R | [LLM] |
| 006ff678 | aLogoCenter | R | [LLM] |
| 006ff688 | aLogoRight | R | [LLM] |
| 00711874 | aLogo_0 | R | [LLM] |
| 00b6e2a0 | unk_B6E2A0 | R | [LLM] |
| 00fb1ce0 | dword_FB1CE0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cfcc0 | sub_4CFCC0 | [LLM] |
| 004cfd30 | sub_4CFD30 | [LLM] |
| 004d5e10 | sub_4D5E10 | [LLM] |
| 004ddfe0 | sub_4DDFE0 | [LLM] |
| 004e0080 | sub_4E0080 | [LLM] |
| 004e0240 | sub_4E0240 | [LLM] |
| 005ee940 | sub_5EE940 | [LLM] |
| 005eea30 | sub_5EEA30 | [LLM] |
| 00612eb0 | sub_612EB0 | [LLM] |
| 00630a80 | _strstr | [LLM] |
| 00630fe0 | sub_630FE0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x238 | >= | 1 | [LLM] |
| this | 0x24C | >= | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `<LOGO>`
- `<LOGO_CENTER>`
- `<LOGO_RIGHT>`
- `<LOGO`
