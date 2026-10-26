## VehFileParser_004c3200 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleFileLoader (004c3d80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x3D4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x3D4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acb28 | flt_5ACB28 | R | AISteerAngleThreshold [DERIVED] |
| 005bea08 | aDriver_0 | R | sDriver [DERIVED] |
| 005c316c | aEngine | R | ComponentNameEngine [DERIVED] |
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005c401c | aClasses | R | ClassesString [DERIVED] |
| 005c6810 | aCouldNotOpenS | R | Str_CouldNotOpenS [DERIVED] |
| 005d251c | asc_5D251C | R | IniKeyValueDelim [DERIVED] |
| 005d2e94 | aSfx | R | SfxString [DERIVED] |
| 005d2e9c | aGen | R | GenString [DERIVED] |
| 005d2ea4 | aIni | R | StringDotIni [DERIVED] |
| 005d2eac | aHdv | R | String_Hdv [DERIVED] |
| 005d2eb4 | a4s50s | R | TimeFormat4s50s [DERIVED] |
| 005d2ec0 | aFormatIsTrackl | R | FormatIsTrackL [DERIVED] |
| 005d2f00 | aTracklivery | R | TrackLiveryField [DERIVED] |
| 005d2f0c | aPitcrewlivery | R | PitcrewLiveryString [DERIVED] |
| 005d2f1c | aDefaultlivery | R | DefaultliveryString [DERIVED] |
| 005d2f2c | aTeamworldchamp | R | TeamworldchampString [DERIVED] |
| 005d2f44 | aTeamwins | R | Str_TeamWins [DERIVED] |
| 005d2f50 | aTeampoles | R | StringTeamPoles [DERIVED] |
| 005d2f5c | aTeamstarts | R | TeamStartsString [DERIVED] |
| 005d2f68 | aTeamheadquarte | R | TeamHeadquartersString [DERIVED] |
| 005d2f7c | aTeamfounded | R | TeamFoundedString [DERIVED] |
| 005d2f88 | aFullteamname | R | FullTeamNameStr [DERIVED] |
| 005d2f98 | aManufacturer | R | ManufacturerField [DERIVED] |
| 005d2fa8 | aDescription | R | Description [DERIVED] |
| 005d2fb4 | aTeam_0 | R | String_Team_0 [DERIVED] |
| 005d2fbc | aNumber | R | NumberString [DERIVED] |
| 005d2fc4 | aSteeringwheela | R | SteeringwheelaString [DERIVED] |
| 005d2fd8 | aMirrornorm | R | MirrorNormString [DERIVED] |
| 005d2fe4 | aMirrorpos | R | String_MirrorPos [DERIVED] |
| 005d2ff0 | aCameratarget | R | CameraTargetString [DERIVED] |
| 005d3000 | aEyepoint | R | Eyepoint [DERIVED] |
| 005d300c | aGenstring | R | GenstringField [DERIVED] |
| 005d3018 | aGraphics | R | GraphicsString [DERIVED] |
| 005d3024 | aSounds | R | SoundsString [DERIVED] |
| 005d302c | aHeadphysics | R | HeadphysicsString [DERIVED] |
| 005d3038 | aHdvehicle | R | Str_Hdvehicle [DERIVED] |
| 005d3044 | aDDevF119992002_8 | R | StringDevF119992002_8 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c38d0 | FileINILoader | [LLM] |
| 004c40d0 | FileFinder | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00565870 | sub_565870 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ca0 | FileReadUntilNewline | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
