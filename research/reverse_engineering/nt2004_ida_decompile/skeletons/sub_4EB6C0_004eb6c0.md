## sub_4EB6C0_004eb6c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EABE0 (004eabe0), sub_4EC870 (004ec870), sub_4ECA90 (004eca90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x20) | 0x1C | R | — | [LLM] |
| *(this+0x28) | 0x0 | R | — | [LLM] |
| *(this+0x28) | 0x8 | R | — | [LLM] |
| *(this+0x28) | 0xC | R | — | [LLM] |
| *(this+0x28) | 0x14 | R | — | [LLM] |
| *(this+0x28) | 0x18 | R | — | [LLM] |
| *(this+0x28) | 0x1C | R | — | [LLM] |
| *(this+0x28) | 0x24 | R | — | [LLM] |
| *(this+0x28) | 0x28 | RW | 0 | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x28) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fc19c | aSponsor | R | [LLM] |
| 00608b30 | aLayer | R | [LLM] |
| 00608bd8 | aName_0 | R | [LLM] |
| 00608df4 | aFont | R | [LLM] |
| 00608e18 | aSize | R | [LLM] |
| 00609e84 | aDetail | R | [LLM] |
| 00610f40 | aModel | R | [LLM] |
| 00610f48 | aDecal | R | [LLM] |
| 00610f50 | aMasfile | R | [LLM] |
| 0061108c | aSkin | R | [LLM] |
| 00611094 | aAlphastamp | R | [LLM] |
| 006110a0 | off_6110A0 | R | [LLM] |
| 006110a4 | off_6110A4 | R | [LLM] |
| 006110a8 | aWord | R | [LLM] |
| 006110b0 | aStamp | R | [LLM] |
| 006110b8 | aType | R | [LLM] |
| 006110c0 | EndPtr | R | [LLM] |
| 006110c8 | aStyle | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414400 | sub_414400 | [LLM] |
| 004e9bb0 | sub_4E9BB0 | [LLM] |
| 004ebfe0 | sub_4EBFE0 | [LLM] |
| 00577b60 | sub_577B60 | [LLM] |
| 00577e50 | sub_577E50 | [LLM] |
| 00578110 | sub_578110 | [LLM] |
| 00578220 | sub_578220 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 0057a080 | ZeroInitSmallStruct [exact] | [LLM] |
| 0057a0a0 | sub_57A0A0 | [LLM] |
| 0057a2f0 | AudioStreamOpen [structural] | [LLM] |
| 0057a360 | ConditionalFileHandleCloseWithFlagDispatch [structural] | [LLM] |
| 0057a490 | sub_57A490 | [LLM] |
| 00592310 | DestroyFree [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `SPONSOR`
- `LAYER`
- `NAME`
- `FONT`
- `SIZE`
- `DETAIL`
- `MODEL`
- `DECAL`
- `DECAL`
- `MASFILE`
- `SKIN`
- `ALPHASTAMP`
- `ORI`
- `POS`
- `WORD`
- `STAMP`
- `TYPE`
- `COLOR`
- `COLOR`
- `STYLE`
