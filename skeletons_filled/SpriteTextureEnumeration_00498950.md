## SpriteTextureEnumeration_00498950 — Sprite/Texture Entry Selector

**Summary:** Iterates through up to 4 sprite/texture entries, comparing the input against each entry's string. If a match is found, returns immediately. Has special-case handling when exactly 3 entries are valid and the 4th is inactive.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** KeyBindingUIPressKeyOrController (0046b0c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD8 | R | — | Value passed as second argument to final StringFieldSetter call |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Global string buffer reset by StringFieldSetter in the 3-entries-active case |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495b60 | sub_495B60 | Callback invoked when exactly 3 entries are valid and 4th is inactive |
| 00499a30 | StringFieldSetter | Sets a string field on a target (resets global or sets a2 with value from this[54]) |
| 00499a50 | FloatThresholdCheck | Checks if an entry is valid/active (returns false/non-zero based on float threshold) |
| 0049a2b0 | StringPointerDereference | Gets the string pointer from an entry structure |
| 00588410 | sub_588410 | Compares input a2 against entry string; returns 0 on match |

**Guard conditions:**
- `a2 == 0` → return 0 immediately (BLOCKED: null/zero input key)
- `a2 != 0` → iterate entries, check for match, handle special case, finalize (PASSES)
- Within loop: FloatThresholdCheck returning 0 (false) → break loop early (BLOCKED: entry inactive)
- Within loop: sub_588410 returning 0 → match found, return immediately (PASSES: match)
- After loop, `v4 == 3` → special case: reset global string, call callback, then set a2 with this[54] (PASSES: 3 active entries, 4th inactive)
- After loop, `v4 != 3` → just set a2 with this[54] (PASSES: normal path)
