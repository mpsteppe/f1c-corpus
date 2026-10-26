## StringSplitLoop_004d7a50 — DebugLogPathValidator

**Summary:** Checks if this[0] >= a2 (minimum level threshold), then iterates through a path string via sub_587C20 splitting on backslashes. After iteration, writes a formatted debug log entry. Returns 1 if validation passes, 0 if level too low.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** (extensive list — called from throughout the game)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | log level / severity threshold |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005d4a38 | a1212s5d | R | String_1212s5d [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7aa0 | DebugLogWrite | writes formatted debug log entry |
| 00587c20 | sub_587C20 | finds next backslash in path string (path split iteration) |

**Guard conditions:** If *this < a2 (log level below threshold), returns 0 immediately (skip logging).
