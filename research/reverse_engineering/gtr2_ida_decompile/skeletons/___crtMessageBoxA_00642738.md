## ___crtMessageBoxA_00642738 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __NMSG_WRITE (0063f0db), ___security_error_handler (00640437)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f10e0 | GetProcAddress | R | [LLM] |
| 006f1148 | LoadLibraryA | R | [LLM] |
| 00735ef4 | aGetprocesswind | R | [LLM] |
| 00735f0c | aGetuserobjecti | R | [LLM] |
| 00735f28 | aGetlastactivep | R | [LLM] |
| 00735f3c | aGetactivewindo | R | [LLM] |
| 00735f4c | aMessageboxa | R | [LLM] |
| 00735f58 | aUser32Dll_0 | R | [LLM] |
| 00fb8194 | dword_FB8194 | R | [LLM] |
| 00fb81a0 | dword_FB81A0 | R | [LLM] |
| 00fb8630 | MessageBoxA_0 | RW | [LLM] |
| 00fb8634 | GetActiveWindow | RW | [LLM] |
| 00fb8638 | GetLastActivePopup | RW | [LLM] |
| 00fb863c | GetProcessWindowStation | RW | [LLM] |
| 00fb8640 | GetUserObjectInformationA | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `GetProcessWindowStation`
- `GetUserObjectInformationA`
- `GetLastActivePopup`
- `GetActiveWindow`
- `MessageBoxA`
- `user32.dll`
