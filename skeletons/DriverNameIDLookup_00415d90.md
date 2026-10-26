## DriverNameIDLookup_00415d90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_414600 (00414600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2418 | aToranosukeT | R | ToranosukeTString [DERIVED] |
| 005c2428 | aPedroDi | R | PedroDiString [DERIVED] |
| 005c2434 | aMarcG | R | DriverName_MarcG [DERIVED] |
| 005c243c | aLucaB | R | String_LucaB [DERIVED] |
| 005c2444 | aJohnnyH | R | s_DriverNameJohnnyH [DERIVED] |
| 005c2450 | aDamonH | R | DamonH [DERIVED] |
| 005c2458 | aAlessandroZana | R | DriverName_AlessandroZana_String [DERIVED] |
| 005c246c | aAlexanderW | R | DriverNameAlexanderW [DERIVED] |
| 005c2478 | aMarkW | R | MarkWString [DERIVED] |
| 005c2480 | aTakumaS | R | TakumaSString [DERIVED] |
| 005c248c | aThomasE | R | Str_ThomasE [DERIVED] |
| 005c2498 | aMikaS | R | StringMikaS [DERIVED] |
| 005c24a0 | aFelipeM | R | FelipeMassaName [DERIVED] |
| 005c24ac | aAlexY | R | AlexYString [DERIVED] |
| 005c24b4 | aAllanM | R | AllanMString [DERIVED] |
| 005c24bc | aTarsoM | R | TarsoMFormatString [DERIVED] |
| 005c24c4 | aFernandoA | R | DriverNameFernandoA [DERIVED] |
| 005c24d0 | aJensonB | R | JensonBField [DERIVED] |
| 005c24dc | aGiancarloF | R | DriverName_GiancarloF [DERIVED] |
| 005c24e8 | aEnriqueB | R | String_EnriqueB [DERIVED] |
| 005c24f4 | aJosV | R | JosVString [DERIVED] |
| 005c24fc | aGastonM | R | GastonMString [DERIVED] |
| 005c2508 | aLucianoB | R | DriverName_LucianoBurti [DERIVED] |
| 005c2514 | aJeanA | R | String_JeanA [DERIVED] |
| 005c251c | aKimiR | R | s_DriverNameKimiR [DERIVED] |
| 005c2524 | aNickH | R | NickH [DERIVED] |
| 005c252c | aPedroDe | R | DriverName_PedroDe_String [DERIVED] |
| 005c2538 | aEddieI | R | DriverNameEddieI [DERIVED] |
| 005c2540 | aOlivierP | R | OlivierPString [DERIVED] |
| 005c254c | aJacquesV | R | JacquesVString [DERIVED] |
| 005c2558 | aRicardoZ | R | Str_RicardoZ [DERIVED] |
| 005c2564 | aJarnoT | R | StringJarnoT [DERIVED] |
| 005c256c | aHeinzHaraldF | R | HeinzHaraldFrentzenName [DERIVED] |
| 005c257c | aJuan | R | JuanString [DERIVED] |
| 005c2584 | aRalfS | R | RalfSString [DERIVED] |
| 005c258c | aDavidC | R | DavidCFormatString [DERIVED] |
| 005c2594 | aMikaH | R | DriverNameMikaH [DERIVED] |
| 005c259c | aRubensB | R | RubensBField [DERIVED] |
| 005c25a8 | aMichaelS | R | DriverName_MichaelS [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004141a0 | ShortComputation_41a0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566810 | sub_566810 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
