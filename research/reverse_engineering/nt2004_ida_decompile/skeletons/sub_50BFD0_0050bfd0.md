## sub_50BFD0_0050bfd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_51CDC0 (0051cdc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x62A0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x1D8 | R | — | [LLM] |
| this | 0x1F0 | R | — | [LLM] |
| this | 0x1F4 | R | — | [LLM] |
| this | 0x1F8 | R | — | [LLM] |
| this | 0x9F0 | R | — | [LLM] |
| this | 0x9F4 | R | — | [LLM] |
| this | 0x9FC | R | — | [LLM] |
| this | 0xA00 | R | — | [LLM] |
| this | 0xA04 | R | — | [LLM] |
| this | 0xA08 | R | — | [LLM] |
| this | 0xA28 | R | — | [LLM] |
| this | 0xA2C | R | — | [LLM] |
| this | 0xA38 | R | — | [LLM] |
| this | 0xA60 | R | — | [LLM] |
| this | 0xA64 | R | — | [LLM] |
| this | 0xA70 | R | — | [LLM] |
| this | 0xA98 | RW | 1 | [LLM] |
| this | 0xB00 | R | — | [LLM] |
| this | 0xB04 | R | — | [LLM] |
| this | 0xB08 | RW | — | [LLM] |
| this | 0xB10 | R | — | [LLM] |
| this | 0xB14 | R | — | [LLM] |
| this | 0xB18 | R | — | [LLM] |
| this | 0xB34 | R | — | [LLM] |
| this | 0xB3D | R | — | [LLM] |
| this | 0xB44 | RW | — | [LLM] |
| this | 0xB45 | R | — | [LLM] |
| this | 0xB46 | R | — | [LLM] |
| this | 0xB47 | RW | — | [LLM] |
| this | 0xB48 | R | — | [LLM] |
| this | 0xB4C | R | — | [LLM] |
| this | 0xB54 | RW | — | [LLM] |
| this | 0xB58 | R | — | [LLM] |
| this | 0xB5C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA98: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB08: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB47: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d54f0 | flt_5D54F0 | R | [LLM] |
| 005d5bf4 | flt_5D5BF4 | R | [LLM] |
| 005d5c94 | flt_5D5C94 | R | [LLM] |
| 005d6490 | flt_5D6490 | R | [LLM] |
| 005eaa40 | flt_5EAA40 | R | [LLM] |
| 005eaa44 | flt_5EAA44 | R | [LLM] |
| 005eaa48 | flt_5EAA48 | R | [LLM] |
| 005fb99c | aCockpit | R | [LLM] |
| 006291cc | dword_6291CC | R | [LLM] |
| 0075aac0 | dword_75AAC0 | R | [LLM] |
| 0075aad0 | dword_75AAD0 | R | [LLM] |
| 00767b5c | flt_767B5C | R | [LLM] |
| 00767bec | dword_767BEC | R | [LLM] |
| 007680e4 | dword_7680E4 | R | [LLM] |
| 00768108 | dword_768108 | R | [LLM] |
| 007d5da4 | dword_7D5DA4 | R | [LLM] |
| 007d5dac | dword_7D5DAC | R | [LLM] |
| 007da9d0 | dbl_7DA9D0 | R | [LLM] |
| 007dab04 | flt_7DAB04 | R | [LLM] |
| 007dab08 | flt_7DAB08 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c460 | sub_40C460 | [LLM] |
| 00459b80 | PathAccessor_28e0 [structural] | [LLM] |
| 00459bc0 | sub_459BC0 | [LLM] |
| 004d9e20 | sub_4D9E20 | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |
| 0050c800 | sub_50C800 | [LLM] |
| 0050e400 | sub_50E400 | [LLM] |
| 00579930 | sub_579930 | [LLM] |
| 0059e0f0 | sub_59E0F0 | [LLM] |
| 0059e170 | sub_59E170 | [LLM] |
| 005a2930 | sub_5A2930 | [LLM] |
| 005adbf0 | ConditionalDispatchByFlag [exact] | [LLM] |
| 005bf290 | __strcmpi | [LLM] |
| 005c057a | __CIfmod | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xA28 | > | 0 | [LLM] |
| this | 0xA60 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Cockpit`
