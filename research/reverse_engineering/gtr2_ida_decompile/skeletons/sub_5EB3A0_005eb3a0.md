## sub_5EB3A0_005eb3a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5DC7E0 (005dc7e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x188)+0x26C)+0x1D4) | 0x4 | R | — | [LLM] |
| *(*(*(this+0x188)+0x26C)+0x1D4) | 0x8 | R | — | [LLM] |
| *(*(*(this+0x188)+0x26C)+0x1E4) | 0x4 | R | — | [LLM] |
| *(*(*(this+0x188)+0x26C)+0x1E4) | 0x8 | R | — | [LLM] |
| *(*(*(this+0x188)+0x26C)+0x204) | 0x4 | R | — | [LLM] |
| *(*(*(this+0x188)+0x26C)+0x204) | 0x8 | R | — | [LLM] |
| *(*(this+0x188)+0x26C) | 0x0 | R | — | [LLM] |
| *(*(this+0x188)+0x26C) | 0x3 | R | — | [LLM] |
| *(*(this+0x188)+0x26C) | 0x1D4 | R | — | [LLM] |
| *(*(this+0x188)+0x26C) | 0x1E4 | R | — | [LLM] |
| *(*(this+0x188)+0x26C) | 0x204 | R | — | [LLM] |
| *(this+0x188) | 0x0 | RW | — | [LLM] |
| *(this+0x188) | 0x38 | RW | — | [LLM] |
| *(this+0x188) | 0x3C | RW | — | [LLM] |
| *(this+0x188) | 0x44 | RW | — | [LLM] |
| *(this+0x188) | 0x26C | R | — | [LLM] |
| *(this+0x188) | 0x270 | R | — | [LLM] |
| *(this+0x1DC) | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0xF8 | RW | 6 | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x16C | RW | — | [LLM] |
| this | 0x170 | R | — | [LLM] |
| this | 0x174 | RW | — | [LLM] |
| this | 0x17C | RW | — | [LLM] |
| this | 0x184 | RW | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x1D4 | RW | 0 | [LLM] |
| this | 0x1DC | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x188) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x188) 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x188) 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x188) 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x16C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x174: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x17C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x184: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1D4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1DC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f3088 | aRainlight | R | [LLM] |
| 006f3094 | aBrakelight | R | [LLM] |
| 006f30a0 | aHeadlight | R | [LLM] |
| 00721cd0 | aRainAnim | R | [LLM] |
| 00721ce8 | aScreenDirt | R | [LLM] |
| 00721d04 | aBackfire | R | [LLM] |
| 0072c22c | aErrorLoadingGl | R | [LLM] |
| 0072c250 | aCouldNotFindSh | R | [LLM] |
| 0072c278 | aMaterialGlobal | R | [LLM] |
| 0072c298 | aGhostMaterialG | R | [LLM] |
| 0072c2c0 | aInteriorBanner | R | [LLM] |
| 0072c2d0 | aL0diffuset0 | R | [LLM] |
| 0072c2dc | aL0nolightingt0 | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |
| 00fb27ac | dword_FB27AC | R | [LLM] |
| 00fb27b0 | dword_FB27B0 | R | [LLM] |
| 00fb27f8 | dword_FB27F8 | R | [LLM] |
| 00fb2804 | dword_FB2804 | W | [LLM] |
| 00fb2814 | dword_FB2814 | W | [LLM] |
| 00ffffff | byte_FFFFFF | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | [LLM] |
| 005d8ce0 | sub_5D8CE0 | [LLM] |
| 005d8dd0 | sub_5D8DD0 | [LLM] |
| 005e2a20 | sub_5E2A20 | [LLM] |
| 005e80d0 | sub_5E80D0 | [LLM] |
| 005e8220 | sub_5E8220 | [LLM] |
| 005e82a0 | sub_5E82A0 | [LLM] |
| 005e8320 | sub_5E8320 | [LLM] |
| 005e8580 | sub_5E8580 | [LLM] |
| 005e8870 | sub_5E8870 | [LLM] |
| 005e8d90 | sub_5E8D90 | [LLM] |
| 005e8e90 | sub_5E8E90 | [LLM] |
| 005e9070 | sub_5E9070 | [LLM] |
| 005e9300 | sub_5E9300 | [LLM] |
| 005e9420 | sub_5E9420 | [LLM] |
| 005e9620 | sub_5E9620 | [LLM] |
| 005ea670 | sub_5EA670 | [LLM] |
| 005f6520 | sub_5F6520 | [LLM] |
| 005f7bf0 | sub_5F7BF0 | [LLM] |
| 005f7c20 | sub_5F7C20 | [LLM] |
| 005fdfb0 | sub_5FDFB0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 00630a80 | _strstr | [LLM] |
| 00633686 | __strupr | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | < | 0 | [LLM] |
| this | 0x170 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `RAINLIGHT`
- `BRAKELIGHT`
- `HEADLIGHT`
- `RAIN_ANIM`
- `SCREEN_DIRT`
- `SCREEN_DIRT`
- `BACKFIRE`
- `Error loading global material %s`
- `Could not find shader %s for mesh %s`
- `Material global/local mismatch.`
- `Ghost material global/local mismatch.`
- `INTERIOR_BANNER`
- `L0DIFFUSET0`
- `L0NOLIGHTINGT0`
