## sub_4A9DB0_004a9db0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4A8E80 (004a8e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1DC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fc184 | aFocus | R | [LLM] |
| 00608ab4 | asc_608AB4 | R | [LLM] |
| 00608e48 | aLostfocus | R | [LLM] |
| 00608e54 | aRelease | R | [LLM] |
| 00608e5c | aClick | R | [LLM] |
| 00608e64 | aSimulateclick | R | [LLM] |
| 00608e74 | aExitGame | R | [LLM] |
| 00608e80 | aDoLastPage | R | [LLM] |
| 00608e90 | aDropPopups | R | [LLM] |
| 00608e9c | aDoLayer | R | [LLM] |
| 00608ea8 | aDoPage | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 007656e8 | byte_7656E8 | R | [LLM] |
| 00765880 | Str | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049cf70 | sub_49CF70 | [LLM] |
| 0049cfb0 | sub_49CFB0 | [LLM] |
| 0049cff0 | sub_49CFF0 | [LLM] |
| 0049d030 | sub_49D030 | [LLM] |
| 004a84a0 | sub_4A84A0 | [LLM] |
| 004b1260 | F_7FieldSentineInit [exact] | [LLM] |
| 00577e50 | sub_577E50 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005be900 | _strstr | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `FOCUS`
- `LOSTFOCUS`
- `RELEASE`
- `CLICK`
- `SIMULATECLICK`
- `EXIT_GAME`
- `DO_LAST_PAGE`
- `DROP_POPUPS`
- `DO_LAYER`
- `DO_PAGE`
