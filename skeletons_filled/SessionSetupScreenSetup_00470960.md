## SessionSetupScreenSetup_00470960 — SessionSetupParameterInit

**Summary:** Initializes session setup display parameters: stores RaceMode (dword_7D0410) at 0x324 and index pointer at 0x320, formats display string from UI list item indexed by dword_7CEAA4, updates edit buffer, and optionally compares object name via dispatch interface lookup (type 19). Called from SelectedSeasonUIInit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SelectedSeasonUIInit (00470850)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | RW | — | pointer field, set to address of dword_7CEAA4 (index source for UI list) |
| this | 0x324 | RW | — | stores dword_7D0410 (RaceMode) |

**Written-by note (persistence):**
- this 0x320: set once to address of dword_7CEAA4; overwritten if external code writes to this field
- this 0x324: set once from RaceMode value; overwritten if external code modifies it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] — used to create/look up object by type 19 |
| 007ceaa4 | dword_7CEAA4 | R | index value for UI list accessor |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] — RaceMode stored at 0x324 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477280 | ObjectNameComparison | compare created object's name with this (conditional on non-null) |
| 00487010 | UIListIndexedAccessor | get UI list element indexed by dword_7CEAA4 |
| 0048b810 | EditBufferStringUpdate | update edit buffer with formatted display string |
| 0058815f | StringFormatWithBufferOverflowCheck | safe formatted string construction |

**Guard conditions:** Guard on dispatch interface result (v3): only calls ObjectNameComparison if the looked-up object pointer is non-null.
