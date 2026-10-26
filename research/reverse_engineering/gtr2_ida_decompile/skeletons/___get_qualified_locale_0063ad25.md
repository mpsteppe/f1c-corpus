## ___get_qualified_locale_0063ad25 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __expandlocale (006324c7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0063a6f4 | _crtGetLocaleInfoA@16 | R | [LLM] |
| 006f1144 | GetLocaleInfoA | R | [LLM] |
| 006f1288 | IsValidLocale | R | [LLM] |
| 006f128c | IsValidCodePage | R | [LLM] |
| 00731500 | off_731500 | R | [LLM] |
| 007316b0 | off_7316B0 | R | [LLM] |
| 00731cd4 | aNorwegianNynor | R | [LLM] |
| 00fb8194 | dword_FB8194 | R | [LLM] |
| 00fb83b8 | dword_FB83B8 | RW | [LLM] |
| 00fb83bc | Locale | R | [LLM] |
| 00fb83c0 | dword_FB83C0 | R | [LLM] |
| 00fb83cc | dword_FB83CC | RW | [LLM] |
| 00fb83d4 | dword_FB83D4 | RW | [LLM] |
| 00fb83d8 | dword_FB83D8 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00633b19 | __itoa | [LLM] |
| 00636a70 | _strcpy | [LLM] |
| 0063a5e6 | _TranslateName | [LLM] |
| 0063a646 | _GetLcidFromDefault | [LLM] |
| 0063a660 | _ProcessCodePage | [LLM] |
| 0063ac13 | _GetLcidFromCountry | [LLM] |
| 0063ac4a | _GetLcidFromLangCountry | [LLM] |
| 0063acd0 | _GetLcidFromLanguage | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Norwegian-Nynorsk`
