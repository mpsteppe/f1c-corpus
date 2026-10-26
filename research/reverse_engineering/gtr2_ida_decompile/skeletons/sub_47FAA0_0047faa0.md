## sub_47FAA0_0047faa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_484200 (00484200), sub_488A20 (00488a20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x364 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f14ac | GetDlgItem | R | [LLM] |
| 006f14b0 | SendDlgItemMessageA | R | [LLM] |
| 006f14b4 | EnableWindow | R | [LLM] |
| 006f14c4 | SetWindowTextA | R | [LLM] |
| 006f14d0 | IsWindowVisible | R | [LLM] |
| 006f3140 | flt_6F3140 | R | [LLM] |
| 006f6d40 | aNextSession | R | [LLM] |
| 006f6e10 | aRestartRace | R | [LLM] |
| 00757c10 | dword_757C10 | R | [LLM] |
| 0091cc38 | byte_91CC38 | R | [LLM] |
| 00b640c8 | dword_B640C8 | R | [LLM] |
| 00b6ce70 | hDlg | R | [LLM] |
| 00b6ce74 | hWnd | R | [LLM] |
| 00b6ce78 | dword_B6CE78 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d840 | sub_41D840 | [LLM] |
| 00617e70 | sub_617E70 | [LLM] |
| 00617f80 | sub_617F80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Next Session`
- `Restart Race`
