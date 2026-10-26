## PlayerFile_Post_004b1900 — Player file post-processing

**Summary:** Called from Game_Post to handle player file post-update. Logs debug message, runs player data init (sub_4B0770), then conditionally calls additional setup based on a state field at this+0x1F78.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F78 | R | — | State field checked against value 4 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d22e0 | aDDevF119992002_20 | R | SourcePath_F1_1999_2002_20 [DERIVED] |
| 005d238c | aEnteredPlayerf_2 | R | EnteredPlayerfString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0770 | sub_4B0770 | Reset/initialize player data state |
| 004d7a50 | StringSplitLoop | Parse debug path string, return success flag |
| 004d7aa0 | DebugLogWrite | Write debug log message to debug buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F78 | != | 4 | State field — 4 = ready/completed state |

**Guard interpretation:** If this+0x1F78 != 4 (not in ready/completed state), calls additional setup. If == 4 (already ready), skips that call.
