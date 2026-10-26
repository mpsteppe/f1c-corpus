## StringTableLookup_004cdbf0 — StringTableLookup

**Summary:** Searches a key=value formatted INI-style string table for a matching key string. Copies base path, then iterates through lines parsed by sub_5897CA, comparing each key against the target using sub_587C20.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringListLookup (004ce860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to base path / file path string |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d251c | asc_5D251C | R | IniKeyValueDelim [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c20 | sub_587C20 | compare key string against parsed token |
| 005897ca | sub_5897CA | parse next line/token from string table delimited by '=' |

**Guard conditions:** If *this is null, uses default directory (byte_5EA438). If sub_5897CA returns 0 (no more lines in table) → return 0 (not found). Loop continues while sub_587C20(a2, token) != a2; if sub_5897CA returns 0 before match → return 0.
