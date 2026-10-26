## NetworkFilterSort_00462160 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_475150 (00475150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC4 | RW | — | [LLM] |
| obj | 0x1B79C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0xC4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5c14 | aNumplayers | R | ConfigKeyNumPlayers [DERIVED] |
| 005c5c20 | aMapname | R | aMapname [DERIVED] |
| 005c5c34 | aHostname | R | StringHostname [DERIVED] |
| 005c61ec | aPing | R | Str_Ping [DERIVED] |
| 007cd2a0 | byte_7CD2A0 | W | TrackSceneRefreshFlag [DERIVED] (also: ` — track/scene refresh flag (0 = no refresh needed) |
| 007d1020 | dword_7D1020 | RW | Unknown_Dword_7D1020 [DERIVED] |
| 007d1028 | dword_7D1028 | R | RaceSetupParam [DERIVED] |
| 007d102c | dword_7D102C | R | Unknown_Int_7D102C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461fc0 | VehicleStateQueryAtLargeOffset | [LLM] |
| 00563ec0 | SwitchParamStoreGlobalSet | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0xC4 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
