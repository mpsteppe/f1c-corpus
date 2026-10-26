## sub_4AA1E0_004aa1e0 — GameModeToPathFormatter

**Summary:** Maps a game mode index (0-6) to a mode string prefix, then formats "%s%s" (mode prefix + name) into output buffer via StringFormatWithBufferOverflowCheck. Returns 1 for valid modes, 0 for invalid.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOptionsInitializer (004aa270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004aa248 | jpt_4AA1EB | R | jump table for switch on mode index |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005cd6cc | aRplay | R | RPlayString [DERIVED] |
| 005cd6d4 | aMulti | R | MultiString [DERIVED] |
| 005cd6dc | aChamp | R | ChampString [DERIVED] |
| 005cd6e4 | aGprix | R | Str_GPrix [DERIVED] |
| 005cd6ec | aQuick | R | StringQuick [DERIVED] |
| 005cd6f4 | aPract | R | PractString [DERIVED] |
| 005cd6fc | aCurnt | R | CurntString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | safe sprintf, builds "prefix+suffix" path string |

**Guard conditions:** Switch on arg1 (mode index). Cases 0-6: select mode string, format output, return 1. Default: set output[0]=0, return 0. Blocked: index <0 or >6.
