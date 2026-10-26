## sub_4EADE0_004eade0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EAD30 (004ead30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x84)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x94)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x94)+0x0) | 0x14 | R | — | [LLM] |
| *(*(this+0xA4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0xA4)+0x0) | 0x8 | R | — | [LLM] |
| *(*(this+0xA4)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0x8 | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0x10 | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0x14 | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0x1C | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0x20 | R | — | [LLM] |
| *(*(this+0xB4)+0x0) | 0x24 | R | — | [LLM] |
| *(this+0x84) | 0x0 | R | — | [LLM] |
| *(this+0x8C) | 0x4 | R | — | [LLM] |
| *(this+0x94) | 0x0 | R | — | [LLM] |
| *(this+0x9C) | 0x0 | R | — | [LLM] |
| *(this+0x9C) | 0x4 | R | — | [LLM] |
| *(this+0xA4) | 0x0 | R | — | [LLM] |
| *(this+0xAC) | 0x4 | R | — | [LLM] |
| *(this+0xB4) | 0x0 | R | — | [LLM] |
| *(this+0xBC) | 0x0 | R | — | [LLM] |
| *(this+0xBC) | 0x4 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x8C | RW | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x9C | RW | — | [LLM] |
| this | 0xA4 | R | — | [LLM] |
| this | 0xAC | RW | — | [LLM] |
| this | 0xB4 | R | — | [LLM] |
| this | 0xBC | RW | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x9C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xAC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xBC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fb9d8 | asc_5FB9D8 | R | [LLM] |
| 005fbf2c | asc_5FBF2C | R | [LLM] |
| 005fc03c | asc_5FC03C | R | [LLM] |
| 005fc484 | asc_5FC484 | R | [LLM] |
| 00610f8c | aAlphastampS | R | [LLM] |
| 00610fa0 | aStampS | R | [LLM] |
| 00610fb0 | aDecalS | R | [LLM] |
| 00610fc0 | aSize2f2f | R | [LLM] |
| 00610fd8 | aOri2f | R | [LLM] |
| 00610fe8 | aPos2f2f | R | [LLM] |
| 00611000 | aFontS | R | [LLM] |
| 00611010 | aWordS | R | [LLM] |
| 00611020 | asc_611020 | R | [LLM] |
| 00611028 | aColorDDD | R | [LLM] |
| 00611040 | aLayerS | R | [LLM] |
| 00611050 | aMasfileS | R | [LLM] |
| 00611060 | aStyleS | R | [LLM] |
| 00611070 | aModelS | R | [LLM] |
| 00611080 | aSkinS | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a080 | ZeroInitSmallStruct [exact] | [LLM] |
| 0057a0a0 | sub_57A0A0 | [LLM] |
| 0057a110 | sub_57A110 | [LLM] |
| 0057a360 | ConditionalFileHandleCloseWithFlagDispatch [structural] | [LLM] |
| 0057a400 | BufferWriteWithStringLengthCheck [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `  {
`
- `  {
`
- `  AlphaStamp="%s"
`
- `  Stamp="%s"
`
- `  Decal="%s"
`
- `    Size=(%.2f, %.2f)
`
- `    Ori=(%.2f)
`
- `    Pos=(%.2f, %.2f)
`
- `    Font="%s"
`
- `  Word="%s"
`
- `  }

`
- `  }

`
- `    Color=(%d, %d, %d)
`
- `    Color=(%d, %d, %d)
`
- `  Layer="%s"
`
- `  MASFile="%s"
`
- `  Style="%s"

`
- `  Model="%s"

`
- `Skin="%s"
`
