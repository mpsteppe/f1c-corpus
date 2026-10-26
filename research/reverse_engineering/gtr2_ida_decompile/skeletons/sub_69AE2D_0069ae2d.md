## sub_69AE2D_0069ae2d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_69EB7F (0069eb7f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x29 | R | — | [LLM] |
| this | 0x2A | R | — | [LLM] |
| this | 0x40 | RW | 1 | [LLM] |
| this | 0x48 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0069b8f4 | jpt_69AE62 | R | [LLM] |
| 0069b92c | jpt_69AFB1 | R | [LLM] |
| 006f1b40 | aTrue | R | [LLM] |
| 006f3eb8 | aIn | R | [LLM] |
| 006f5fd8 | aTexture_1 | R | [LLM] |
| 006ff740 | dword_6FF740 | R | [LLM] |
| 00700f9c | aPass_0 | R | [LLM] |
| 00720110 | aLong | R | [LLM] |
| 0072d0fc | off_72D0FC | R | [LLM] |
| 0072d324 | aDefault_0 | R | [LLM] |
| 00737918 | aColumnMajor | R | [LLM] |
| 00737928 | aRowMajor | R | [LLM] |
| 00737ab0 | aElse | R | [LLM] |
| 00737ad8 | aIf | R | [LLM] |
| 00739c94 | aBreak | R | [LLM] |
| 0073a558 | aFalse_0 | R | [LLM] |
| 0074131c | aStateblock | R | [LLM] |
| 00741328 | aVertexfragment | R | [LLM] |
| 00741338 | aPixelfragment | R | [LLM] |
| 00741348 | aVertexshader_0 | R | [LLM] |
| 00741358 | aPixelshader_0 | R | [LLM] |
| 00741364 | aSamplercube | R | [LLM] |
| 00741370 | aSampler3d | R | [LLM] |
| 0074137c | aSampler2d | R | [LLM] |
| 00741388 | aSampler1d | R | [LLM] |
| 00741394 | aSampler | R | [LLM] |
| 0074139c | aTexturecube | R | [LLM] |
| 007413a8 | aTexture3d | R | [LLM] |
| 007413b4 | aTexture2d | R | [LLM] |
| 007413c0 | aTexture1d | R | [LLM] |
| 007413cc | aString | R | [LLM] |
| 007413d4 | aDouble | R | [LLM] |
| 007413dc | aFloat | R | [LLM] |
| 007413e4 | aHalf | R | [LLM] |
| 007413ec | off_7413EC | R | [LLM] |
| 007413f0 | aBool | R | [LLM] |
| 00741408 | aVoid | R | [LLM] |
| 00741764 | aMatrix | R | [LLM] |
| 0074176c | aVector | R | [LLM] |
| 0074198c | aDecl | R | [LLM] |
| 00741994 | aWhile | R | [LLM] |
| 0074199c | aVolatile | R | [LLM] |
| 007419a8 | aVirtual | R | [LLM] |
| 007419b0 | aUsing | R | [LLM] |
| 007419b8 | aUnsigned | R | [LLM] |
| 007419c4 | aUnion | R | [LLM] |
| 007419cc | aUniform | R | [LLM] |
| 007419d4 | aTypename | R | [LLM] |
| 007419e0 | aTypedef | R | [LLM] |
| 007419e8 | off_7419E8 | R | [LLM] |
| 007419ec | aThrow | R | [LLM] |
| 007419f4 | aThis | R | [LLM] |
| 007419fc | aTemplate | R | [LLM] |
| 00741a08 | aSwitch | R | [LLM] |
| 00741a10 | aStruct | R | [LLM] |
| 00741a18 | aStaticCast | R | [LLM] |
| 00741a24 | aStatic_0 | R | [LLM] |
| 00741a2c | aStateblockStat | R | [LLM] |
| 00741a40 | aSizeof | R | [LLM] |
| 00741a48 | aSigned | R | [LLM] |
| 00741a50 | aShort | R | [LLM] |
| 00741a58 | aShared | R | [LLM] |
| 00741a60 | aSamplerState | R | [LLM] |
| 00741a70 | aReturn | R | [LLM] |
| 00741a78 | aReinterpretCas | R | [LLM] |
| 00741a8c | aRegister | R | [LLM] |
| 00741a98 | aPublic | R | [LLM] |
| 00741aa0 | aProtected | R | [LLM] |
| 00741aac | aPrivate | R | [LLM] |
| 00741ab4 | aOperator | R | [LLM] |
| 00741ac0 | off_741AC0 | R | [LLM] |
| 00741ac4 | off_741AC4 | R | [LLM] |
| 00741ac8 | aNamespace | R | [LLM] |
| 00741ad4 | aMutable | R | [LLM] |
| 00741adc | aInout | R | [LLM] |
| 00741ae4 | aInline | R | [LLM] |
| 00741aec | aGoto | R | [LLM] |
| 00741af4 | aFriend | R | [LLM] |
| 00741afc | off_741AFC | R | [LLM] |
| 00741b00 | aExtern | R | [LLM] |
| 00741b08 | aExplicit | R | [LLM] |
| 00741b14 | aEnum | R | [LLM] |
| 00741b1c | aTechnique | R | [LLM] |
| 00741b28 | aDynamicCast | R | [LLM] |
| 00741b38 | aDo | R | [LLM] |
| 00741b3c | aDiscard | R | [LLM] |
| 00741b44 | aDelete | R | [LLM] |
| 00741b4c | aContinue_0 | R | [LLM] |
| 00741b58 | aConstCast | R | [LLM] |
| 00741b64 | aConst_0 | R | [LLM] |
| 00741b6c | aCompileFragmen | R | [LLM] |
| 00741b80 | aCompile | R | [LLM] |
| 00741b88 | aChar | R | [LLM] |
| 00741b90 | aCatch | R | [LLM] |
| 00741b98 | aCase | R | [LLM] |
| 00741ba0 | aAsmFragment | R | [LLM] |
| 00741bb0 | aAuto | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631c0d | __stricmp | [LLM] |
| 00635155 | sub_635155 | [LLM] |
| 0065d1e3 | sub_65D1E3 | [LLM] |
| 0069974c | sub_69974C | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `true`
- `texture`
- `pass`
- `long`
- `asm`
- `default`
- `column_major`
- `row_major`
- `else`
- `break`
- `false`
- `stateblock`
- `vertexfragment`
- `pixelfragment`
- `vertexshader`
- `pixelshader`
- `samplerCUBE`
- `sampler3D`
- `sampler2D`
- `sampler1D`
- … +71 more
