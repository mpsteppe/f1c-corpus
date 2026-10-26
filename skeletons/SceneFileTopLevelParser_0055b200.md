## SceneFileTopLevelParser_0055b200 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55B6B0 (0055b6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x188 | RW | — | [LLM] |
| this | 0x18A | RW | — | [LLM] |
| this | 0x18C | RW | — | [LLM] |
| this | 0x190 | RW | — | [LLM] |
| this | 0x194 | RW | — | [LLM] |
| this | 0x198 | RW | — | [LLM] |
| this | 0x19C | RW | 524288 | [LLM] |

**Written-by note (persistence):**
- this 0x188: [LLM: once/conditional? does external poke survive?]
- this 0x18A: [LLM: once/conditional? does external poke survive?]
- this 0x18C: [LLM: once/conditional? does external poke survive?]
- this 0x190: [LLM: once/conditional? does external poke survive?]
- this 0x194: [LLM: once/conditional? does external poke survive?]
- this 0x198: [LLM: once/conditional? does external poke survive?]
- this 0x19C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd620 | aInstance | R | StringInstance [DERIVED] |
| 005d3960 | aMasfile | R | StringMasFile [DERIVED] |
| 005d3968 | aSearchpath | R | Str_SearchPath [DERIVED] |
| 005dc234 | aView | R | StrView [DERIVED] |
| 005dc298 | aLight | R | Str_Light [DERIVED] |
| 005dc3a0 | aGroup | R | GroupString [DERIVED] |
| 005dc3a8 | aFogdensity | R | FogDensityString [DERIVED] |
| 005dc3b4 | aFogout | R | FogoutString [DERIVED] |
| 005dc3bc | aFogin | R | FogInStr [DERIVED] |
| 005dc3c4 | aFogcolor | R | FogColorString [DERIVED] |
| 005dc3d0 | aExp2 | R | Exp2Field [DERIVED] |
| 005dc3d8 | aExp | R | StrExp [DERIVED] |
| 005dc3dc | aLinear | R | String_Linear [DERIVED] |
| 005dc3e4 | aFogmode | R | FogModeString [DERIVED] |
| 005dc3ec | aAmbientcolor | R | AmbientcolorString [DERIVED] |
| 005dc3fc | aFontfile | R | FontFileString [DERIVED] |
| 005dc408 | aLinksingle | R | String_LinkSingle [DERIVED] |
| 005dc414 | aDynamic | R | aDynamic [DERIVED] |
| 005dc41c | aGroupmethod | R | GroupMethod [DERIVED] |
| 005dc428 | aIncludefile | R | IncludeFileField [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c6f0 | sub_53C6F0 | [LLM] |
| 0053ce10 | ErrorHandlerSet | [LLM] |
| 0053cfe0 | sub_53CFE0 | [LLM] |
| 0053d340 | LinkedListAppend_d340 | [LLM] |
| 00543800 | F_3DPositionSetWithUIRefresh | [LLM] |
| 0054a160 | FlagBitSetter_a160 | [LLM] |
| 00559a40 | LargeBufferZeroInit_9a40 | [LLM] |
| 00559a70 | LineReaderFromBuffer | [LLM] |
| 00559e20 | sub_559E20 | [LLM] |
| 00559f00 | sub_559F00 | [LLM] |
| 00559fb0 | PRNG4UniformFloatsFromSeed | [LLM] |
| 0055a060 | sub_55A060 | [LLM] |
| 0055a500 | sub_55A500 | [LLM] |
| 0055a790 | sub_55A790 | [LLM] |
| 0055a910 | SceneNode | [LLM] |
| 0055b6b0 | sub_55B6B0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058803f | ThreadSafeReadWrapper_803f | [LLM] |
| 00588640 | sub_588640 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
