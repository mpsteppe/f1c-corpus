## PlayerFile_Enter_004b1820 — PlayerFileEnter

**Summary:** Logs debug message when entering player file handler. Sets player data pointer (this+0x49B0) to global vehicle data structure (unk_5EC6D8), then calls PlayerNameNeverUsedProfileFileCreateRead to initialize profile.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x49B0 | RW | — | player data pointer, set to unk_5EC6D8 (vehicle data) |

**Written-by note (persistence):**
- this 0x49B0: set to global unk_5EC6D8 on each call; survives until next call overwrites or object destroyed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d22e0 | aDDevF119992002_20 | R | SourcePath_F1_1999_2002_20 [DERIVED] |
| 005d2334 | aEnteredPlayerf | R | EnteredPlayerField [DERIVED] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | checks debug verbosity flag for conditional logging |
| 004d7aa0 | DebugLogWrite | writes debug log message "Entered player file" |

**Guard conditions:** Debug log only: if StringSplitLoop returns non-zero (verbose debug enabled), write log. Main operation always executes unconditionally.
