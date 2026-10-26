## RaceModeScreenSetup_004707c0 — RaceModeParameterSetup

**Summary:** Sets up race mode display parameter: stores RaceMode (dword_7D0410) as float at 0x324 and float pointer at 0x320, then formats display string from UI list (if float value is 0) or from float value with "%.1f" format, and updates edit buffer. Called from UIListOptionsConstructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIListOptionsConstructor (004706f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | RW | — | pointer field, set to address of flt_7D122C |
| this | 0x324 | RW | — | float field, set from dword_7D0410 (RaceMode) cast to float |

**Written-by note (persistence):**
- this 0x320: set once to address of flt_7D122C; overwritten if external code writes to this pointer field
- this 0x324: set once from RaceMode value; overwritten if external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c6e50 | a1f | R | format string "%.1f" for float display |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] — RaceMode value stored as float at 0x324 |
| 007d122c | flt_7D122C | R | parameter float — checked against 0.0 to select display format source |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | get UI list element at index 0 (used when float value is 0) |
| 0048b810 | EditBufferStringUpdate | update edit buffer with formatted display string |
| 0058815f | StringFormatWithBufferOverflowCheck | safe formatted string construction |

**Guard conditions:** Checks flt_7D122C == 0.0: if zero, formats string from UI list entry (index 0); if non-zero, formats float value directly with "%.1f".
