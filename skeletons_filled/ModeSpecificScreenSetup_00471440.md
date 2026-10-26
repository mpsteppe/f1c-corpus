## ModeSpecificScreenSetup_00471440 — ModeSpecificScreenSetup

**Summary:** Sets up a UI screen element indexed by race mode. Computes list pointer from dword_7D0410, formats indexed value as string, and updates display buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | RW | — | Pointer to mode-specific data list (derived from race mode enum) |

**Written-by note (persistence):**
- this 0x320: Written once per setup call; overwritten each time screen changes mode

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | Get indexed entry from a UI list |
| 0048b810 | EditBufferStringUpdate | Format buffer and update UI string display |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting with overflow check |

**Guard conditions:** No guard conditions. Always executes: computes list offset from global race mode, sets pointer, formats string, updates display.
