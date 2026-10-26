## DriverNameStringHandler_00497ec0 — Driver Name String Parser/Storer

**Summary:** Parses a driver name string from a path-like string: normalizes it, checks against a blacklist, and if it is not a known registered key, extracts the component up to a path separator and stores it in an internal array. Returns the lookup index or -1 on failure/blacklist match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UICustomRenderDispatch (00489fd0), sub_493060 (00493060), UIComboListRender (00495580), sub_498440 (00498440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1514 | R | — | Counter/index for driver name storage array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005beb48 | word_5BEB48 | R | Path separator character (e.g. '/') used to split driver name |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495810 | StringNormalizeLookup | Normalizes string and looks up in a registered-key table; returns non-zero index if found, 0 if not present |
| 00497f90 | StringArrayMatchSearch | Checks string against a blacklist/blocked-name array; returns non-zero if matched |
| 00587c20 | sub_587C20 | Finds first occurrence of path separator character in string (strchr-like) |
| 00589901 | sub_589901 | Normalizes string (lowercase, path separator normalization) |

**Guard conditions:**
- `a2 == NULL` → return -1 (BLOCKED: null pointer)
- `strlen(a2) == 0` → skip body, return -1 (BLOCKED: empty string)
- `StringArrayMatchSearch(SrcStr) != 0` → return -1 (BLOCKED: string matches blacklist)
- `StringNormalizeLookup(SrcStr) != 0` → skip extraction/storage (PASSES but no store needed; already a known registered key, return its index)
- `StringNormalizeLookup(SrcStr) == 0` → extract driver name portion (up to path separator) and store in array at `this[20 * counter++ + 69]` (PASSES: new driver name, store it)
