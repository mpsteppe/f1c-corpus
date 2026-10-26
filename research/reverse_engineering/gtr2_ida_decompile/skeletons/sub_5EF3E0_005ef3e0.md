## sub_5EF3E0_005ef3e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5F0760 (005f0760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB0) | 0x4 | R | — | [LLM] |
| *(this+0xB0) | 0x8 | R | — | [LLM] |
| *(this+0xB0) | 0x10 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | RW | 127 | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xBF | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x64: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x68: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x7C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xBF: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1064 | SetTextColor | R | [LLM] |
| 006f1070 | GetCharWidth32A | R | [LLM] |
| 006f107c | DeleteDC | R | [LLM] |
| 006f1080 | DeleteObject | R | [LLM] |
| 006f1084 | CreateDIBSection | R | [LLM] |
| 006f108c | GetTextExtentPoint32A | R | [LLM] |
| 006f1090 | SetTextAlign | R | [LLM] |
| 006f1094 | SetBkColor | R | [LLM] |
| 006f1098 | SetMapMode | R | [LLM] |
| 006f109c | SelectObject | R | [LLM] |
| 006f10a4 | CreateCompatibleDC | R | [LLM] |
| 006f10a8 | GetCharABCWidthsFloatA | R | [LLM] |
| 006f14f8 | DrawTextA | R | [LLM] |
| 006f16dc | flt_6F16DC | R | [LLM] |
| 006f4ba8 | dbl_6F4BA8 | R | [LLM] |
| 00714748 | flt_714748 | R | [LLM] |
| 0071bf38 | dbl_71BF38 | R | [LLM] |
| 0072c568 | dbl_72C568 | R | [LLM] |
| 0072c570 | aErrorCreatingS | R | [LLM] |
| 0072c5a0 | dbl_72C5A0 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00ffffff | byte_FFFFFF | R | [LLM] |
| ff0000000000a597 | byte_FF0000000000A597 | RW | [LLM] |
| ff0000000000a598 | byte_FF0000000000A598 | RW | [LLM] |
| ff0000000000a599 | byte_FF0000000000A599 | RW | [LLM] |
| ff0000000000a59a | byte_FF0000000000A59A | RW | [LLM] |
| ff0000000000a5b8 | byte_FF0000000000A5B8 | R | [LLM] |
| ff0000000000a5b9 | byte_FF0000000000A5B9 | R | [LLM] |
| ff0000000000a5be | byte_FF0000000000A5BE | W | [LLM] |
| ff0000000000a5bf | byte_FF0000000000A5BF | W | [LLM] |
| ff0000000000a5c0 | byte_FF0000000000A5C0 | W | [LLM] |
| ff0000000000a5c1 | byte_FF0000000000A5C1 | W | [LLM] |
| ff0000000000a5c2 | byte_FF0000000000A5C2 | W | [LLM] |
| ff0000000000a5c3 | byte_FF0000000000A5C3 | W | [LLM] |
| ff0000000000a5c4 | byte_FF0000000000A5C4 | W | [LLM] |
| ff0000000000a5c5 | byte_FF0000000000A5C5 | W | [LLM] |
| ff0000000000a5c6 | byte_FF0000000000A5C6 | W | [LLM] |
| ff0000000000a5c7 | byte_FF0000000000A5C7 | W | [LLM] |
| ff0000000000a5c8 | byte_FF0000000000A5C8 | W | [LLM] |
| ff0000000000a5cf | byte_FF0000000000A5CF | W | [LLM] |
| ff0000000000a5d7 | byte_FF0000000000A5D7 | RW | [LLM] |
| ff0000000000a5d8 | byte_FF0000000000A5D8 | W | [LLM] |
| ff0000000000a5d9 | byte_FF0000000000A5D9 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | [LLM] |
| 005e47e0 | sub_5E47E0 | [LLM] |
| 005e6e70 | sub_5E6E70 | [LLM] |
| 005e6ea0 | sub_5E6EA0 | [LLM] |
| 0063099c | __ftol2 | [LLM] |
| 00634d10 | _ceil | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
