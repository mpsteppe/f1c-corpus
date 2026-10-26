## RaceSessionModeDataLoader_00470f20 — RaceSessionModeDataLookup

**Summary:** Looks up session mode data from a computed table address (36 * RaceMode + 0x7CF200), stores the address at 0x338 and RaceMode at 0x320, then dereferences the table entry to get a UI list item, formats a string, and updates edit buffer. Returns the computed address or 0 if null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | RW | — | stores dword_7D0410 (RaceMode) |
| this | 0x338 | RW | — | stores computed table address (36 * RaceMode + 0x7CF200) |

**Written-by note (persistence):**
- this 0x320: set from dword_7D0410; overwritten on each call
- this 0x338: set to table lookup address; overwritten on each call (may be 0)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] — used to compute table index (36 * value + 0x7CF200) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | get UI list entry from dereferenced table address |
| 0048b810 | EditBufferStringUpdate | update edit buffer with formatted string |
| 0058815f | StringFormatWithBufferOverflowCheck | safe formatted string construction |

**Guard conditions:** Guard: computed table address (result) must be non-null; if null, function returns immediately without accessing UI list.
