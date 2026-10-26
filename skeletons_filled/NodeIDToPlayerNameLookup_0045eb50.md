## NodeIDToPlayerNameLookup_0045eb50 — NodeIDToPlayerNameLookup

**Summary:** Looks up a player name string by node ID in a session player array. Returns pointer to name entry if found, or empty name string on failure with optional debug log.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C74 | R | — | Start of node ID array (DWORDs), 3973 entries max |
| this | 0x3E14 | R | — | Number of active entries in the node ID array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c5dbc | asc_5C5DBC | R | EmptyNodeNameString [DERIVED] — default empty name returned on failure |
| 005c5dc0 | aCouldNotFindNa | R | CouldNotFindNameString [DERIVED] — "could not find name" log message |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] — guards dev logging |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Sanitize/format debug message string before logging |
| 004d7aa0 | DebugLogWrite | Write "could not find name" debug message |

**Guard conditions:**
- this[0x3E14/4] (count) <= 0 → skip lookup, go to failure path (log + empty name return).
- Linear search through node ID array at this+0x3C74: element == a2 → found, return name at this + 35*v3 + 230 (140-byte per-entry structure at this + 0x398 + v3*140).
- Element != a2 → continue; if v3 >= count → fall through to failure path (log if dword_7C569C != 5, return empty name).
- Debug logging only fires when dword_7C569C != 5 (session type is not server).
