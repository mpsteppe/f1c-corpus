## TrackSurfaceMaterialLoader_004cdd80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | 11 | [LLM] |
| this | 0x34 | RW | 21 | [LLM] |
| this | 0x38 | RW | 27 | [LLM] |
| this | 0x60 | RW | 1 | [LLM] |
| this | 0x64 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059ed28 | dbl_59ED28 | R | PhysicsMinDeltaThreshold [DERIVED] |
| 005c596c | aTrue | R | sTrue [DERIVED] |
| 005d3838 | aMaterials | R | MaterialsString [DERIVED] |
| 005d3844 | aGuardrail | R | Str_Guardrail [DERIVED] |
| 005d3850 | aSolidwall | R | StringSolidWall [DERIVED] |
| 005d385c | aTirewall | R | TirewallString [DERIVED] |
| 005d3868 | aRumble | R | RumbleString [DERIVED] |
| 005d3870 | aGravel | R | GravelString [DERIVED] |
| 005d3878 | aGrass | R | GrassStr [DERIVED] |
| 005d3880 | aDirt | R | DirtString [DERIVED] |
| 005d3888 | aSound | R | SoundField [DERIVED] |
| 005d3890 | aSink | R | SinkKeyword [DERIVED] |
| 005d3898 | aScraping | R | String_Scraping [DERIVED] |
| 005d38a4 | aSparks | R | SparksString [DERIVED] |
| 005d38ac | aCollfrict | R | CollfrictString [DERIVED] |
| 005d38b8 | aDamper | R | DamperString [DERIVED] |
| 005d38c0 | aSpring_0 | R | String_Spring [DERIVED] |
| 005d38c8 | aBumpwavelen | R | BumpWaveLenString [DERIVED] |
| 005d38d4 | aBumpamp | R | BumpAmp [DERIVED] |
| 005d38dc | aResistance | R | ResistanceField [DERIVED] |
| 005d38e8 | aWet | R | WetString [DERIVED] |
| 005d38ec | off_5D38EC | R | VTablePtr5 [DERIVED] |
| 005d38f0 | aLegal | R | LegalString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cdc70 | sub_4CDC70 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00565760 | sub_565760 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
