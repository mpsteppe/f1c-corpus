## TransmissionAIDifficultyScreenSetup_00471dc0 — TransmissionAIDifficultyScreenSetup

**Summary:** Sets up UI screen element for transmission/AI difficulty. Stores race mode to field 0x324, binds audio race mode flag pointer at 0x320, then formats and displays the indexed list value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | RW | — | Pointer to audio race mode flag data |
| this | 0x324 | RW | — | Race mode value from global |

**Written-by note (persistence):**
- this 0x320: Written each time screen is set up; pointer to external flag
- this 0x324: Written each time screen is set up; derived from global race mode

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 007d1fd8 | dword_7D1FD8 | R | AudioRaceModeFlag [DERIVED] (also: ` — flag for race-mode audio (higher gain heads) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | Get indexed entry from a UI list |
| 0048b810 | EditBufferStringUpdate | Format buffer and update UI string display |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting with overflow check |

**Guard conditions:** No guard conditions. Always executes: stores race mode, stores audio flag pointer, formats string, updates display.
