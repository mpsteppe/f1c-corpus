## sub_4AFA80_004afa80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x30) | 0x1C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004afd14 | jpt_4AFB4A | R | [LLM] |
| 004afd28 | byte_4AFD28 | R | [LLM] |
| 004afd38 | jpt_4AFCBC | R | [LLM] |
| 004afd50 | byte_4AFD50 | R | [LLM] |
| 006f1304 | ?Connect@CGarageOnline@@QAE_NXZ | R | [LLM] |
| 006f130c | ?CanUploadFile@CGarageOnline@@QAEHPAD0@Z | R | [LLM] |
| 006f1310 | ?UploadFile@CGarageOnline@@QAEHPAD00@Z | R | [LLM] |
| 006f1314 | ?FileExists@CGarageOnline@@QAE_NPAD@Z | R | [LLM] |
| 006f1318 | ?AddTimeTrialInfo@CGarageOnline@@QAE_NPADPBD111MMMHHMHHHHHH@Z | R | [LLM] |
| 006f1368 | ?GetFileList@CGarageOnline@@QAE_NPBD@Z | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006fc64c | aJoinFailurePag_0 | R | [LLM] |
| 006fcce0 | aReadingFolder | R | [LLM] |
| 006ffb00 | aCannotOverwrit_0 | R | [LLM] |
| 006ffb40 | aTimetrialUploa_3 | R | [LLM] |
| 006ffb70 | aTimetrialUploa_2 | R | [LLM] |
| 006ffb98 | aTimetrialUploa | R | [LLM] |
| 006ffbc4 | aTimetrialSaveF | R | [LLM] |
| 006ffbf8 | aTimetrialUploa_1 | R | [LLM] |
| 006ffc2c | aTimetrialUploa_0 | R | [LLM] |
| 006ffc5c | aUploadingTimet | R | [LLM] |
| 00759f44 | dword_759F44 | R | [LLM] |
| 0091cc38 | byte_91CC38 | R | [LLM] |
| 00b6cbb0 | dword_B6CBB0 | R | [LLM] |
| 00b6cbb4 | dword_B6CBB4 | R | [LLM] |
| 00b6cbb8 | dword_B6CBB8 | R | [LLM] |
| 00b6dcf0 | byte_B6DCF0 | R | [LLM] |
| 00b6f68c | dword_B6F68C | R | [LLM] |
| 00be1210 | dword_BE1210 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d7b0 | ReversePathSearchForBackslash [exact] | [LLM] |
| 0041d840 | sub_41D840 | [LLM] |
| 004abbb0 | sub_4ABBB0 | [LLM] |
| 004cd6d0 | sub_4CD6D0 | [LLM] |
| 004ce170 | sub_4CE170 | [LLM] |
| 004d0ac0 | sub_4D0AC0 | [LLM] |
| 004d93b0 | sub_4D93B0 | [LLM] |
| 004df020 | sub_4DF020 | [LLM] |
| 004eb900 | sub_4EB900 | [LLM] |
| 00523d70 | sub_523D70 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `JOIN FAILURE PAGE`
- `Reading Folder...`
- `Cannot overwrite TimeTrial. You are not the owner of this file.`
- `TimeTrial Upload Failed. Could not read file.`
- `TimeTrial Upload Failed. Invalid File.`
- `TimeTrial Upload Failed. File too large.`
- `TIMETRIAL_SAVE_FILE_OVERWRITE_CONFIRMATION_ONLINE`
- `TimeTrial Upload Failed. Could not read setup file.`
- `TimeTrial Upload Failed. Invalid Setup File.`
- `Uploading TimeTrial...`
