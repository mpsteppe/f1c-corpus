## PitCrewInstanceSetup_004ddad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ZeroInitWrapper (004ddf70), sub_4E2A60 (004e2a60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ddf4c | jpt_4DDC40 | R | [LLM] |
| 005c6984 | aTrackname | R | StrTrackName [DERIVED] |
| 005cd5d8 | aTeamMas | R | sTeamMass [DERIVED] |
| 005d4c0c | aBmp | R | String_Bmp [DERIVED] |
| 005d4c14 | aRefueler | R | RefuelerString [DERIVED] |
| 005d4c20 | aWcrefueler | R | WcrefuelerString [DERIVED] |
| 005d4c2c | aLollipop_0 | R | LollipopString [DERIVED] |
| 005d4c38 | aWclollipop | R | String_WcLollipop [DERIVED] |
| 005d4c44 | aPithelmet | R | PitHelmetString [DERIVED] |
| 005d4c50 | aWcpithelmet | R | WcPitHelmet [DERIVED] |
| 005d4c5c | aPitbody | R | PitBodyField [DERIVED] |
| 005d4c64 | aWcpitbody | R | WcPitBodyString [DERIVED] |
| 005d4c70 | aHelmet_0 | R | HelmetString [DERIVED] |
| 005d4c78 | aWchelmet | R | WchelmetString [DERIVED] |
| 005d4c84 | aWing | R | Str_Wing [DERIVED] |
| 005d4c8c | aWcwing | R | StringWcWing [DERIVED] |
| 005d4c94 | aArms_0 | R | ArmsString [DERIVED] |
| 005d4c9c | aWcarms | R | WCarMSString [DERIVED] |
| 005d4ca4 | aDriver | R | DriverString [DERIVED] |
| 005d4cac | aWcdriver | R | WcdriverStr [DERIVED] |
| 005d4cb8 | aWccarbody | R | WCCarBodyString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c58a0 | StringCopyWithValidation | [LLM] |
| 004dc770 | TextureAdjuster | [LLM] |
| 0053cbc0 | sub_53CBC0 | [LLM] |
| 0053ce40 | PhysicsObjectLinkedListRemoval | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 00589db0 | sub_589DB0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
