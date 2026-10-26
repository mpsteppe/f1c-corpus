## sub_5A2CE0_005a2ce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_592910 (00592910), sub_592A60 (00592a60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10B8) | 0x10 | R | — | [LLM] |
| *(this+0xB4) | 0x1C | R | — | [LLM] |
| *(this+0xB4) | 0x20 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x64 | RW | 1179648 | [LLM] |
| this | 0x6C | RW | 18446744073709551615 | [LLM] |
| this | 0x90 | RW | — | [LLM] |
| this | 0x98 | RW | — | [LLM] |
| this | 0x9B | R | — | [LLM] |
| this | 0x9C | RW | — | [LLM] |
| this | 0xA0 | RW | — | [LLM] |
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB4 | RW | — | [LLM] |
| this | 0x10B8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x64: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x6C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x90: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x98: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x9C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10B8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5060 | DeleteObject | R | [LLM] |
| 005d5064 | DeleteDC | R | [LLM] |
| 005d5068 | CreateFontIndirectA | R | [LLM] |
| 005d506c | GetDeviceCaps | R | [LLM] |
| 005d5070 | SetMapMode | R | [LLM] |
| 005d5074 | CreateCompatibleDC | R | [LLM] |
| 005d525c | MulDiv | R | [LLM] |
| 0061b970 | aFonttex | R | [LLM] |
| 0061b978 | aTtf_0 | R | [LLM] |
| 0061b980 | aTtf | R | [LLM] |
| 007e6b48 | dword_7E6B48 | R | [LLM] |
| 007e8cf0 | dword_7E8CF0 | R | [LLM] |
| ff00000000005ea3 | byte_FF00000000005EA3 | W | [LLM] |
| ff00000000005ea4 | byte_FF00000000005EA4 | W | [LLM] |
| ff00000000005ea5 | byte_FF00000000005EA5 | W | [LLM] |
| ff00000000005ea6 | byte_FF00000000005EA6 | W | [LLM] |
| ff00000000005ea7 | byte_FF00000000005EA7 | W | [LLM] |
| ff00000000005ea8 | byte_FF00000000005EA8 | W | [LLM] |
| ff00000000005ea9 | byte_FF00000000005EA9 | W | [LLM] |
| ff00000000005eaa | byte_FF00000000005EAA | W | [LLM] |
| ff00000000005eab | byte_FF00000000005EAB | W | [LLM] |
| ff00000000005eac | byte_FF00000000005EAC | W | [LLM] |
| ff00000000005ead | byte_FF00000000005EAD | W | [LLM] |
| ff00000000005eae | byte_FF00000000005EAE | W | [LLM] |
| ff00000000005eaf | byte_FF00000000005EAF | W | [LLM] |
| ff00000000005eb0 | byte_FF00000000005EB0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005922a0 | sub_5922A0 | [LLM] |
| 0059fa90 | sub_59FA90 | [LLM] |
| 0059fdc0 | ClippedRenderRegion [structural] | [LLM] |
| 005a1d10 | sub_5A1D10 | [LLM] |
| 005a1dc0 | sub_5A1DC0 | [LLM] |
| 005a3200 | sub_5A3200 | [LLM] |
| 005a36b0 | sub_5A36B0 | [LLM] |
| 005a3ea0 | sub_5A3EA0 | [LLM] |
| 005a4720 | sub_5A4720 | [LLM] |
| 005a4740 | sub_5A4740 | [LLM] |
| 005a4750 | sub_5A4750 | [LLM] |
| 005b5940 | j_nullsub_6 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8bc | __ftol | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005be900 | _strstr | [LLM] |
| 005c0803 | __strupr | [LLM] |
| 005c24b0 | _strrchr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `FONTTEX`
- `.ttf`
- `.TTF`
