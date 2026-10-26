## StringTableLookup_9d10_00559d10 — StringSplitLookupByPrefix

**Summary:** Copies a string from offset 0xC to 0x18C, splits it by delimiter ".", and checks if the result matches a given key. Part of scene file property lookup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_559E20 (00559e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Source string to look up (input line/key) |
| this | 0x18C | RW | — | Working copy of string (destination for copy + split) |
| this | 0x30C | RW | — | Pointer to delimiter "." found in string |

**Written-by note (persistence):**
- this 0x18C: overwritten each call with copy of this+0xC string. External poke does not survive next call.
- this 0x30C: set to pointer to "." delimiter found by sub_5897CA. Overwritten each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30ac | asc_5C30AC | R | StrDelimiter_Period [DERIVED] (also: ` — first lookup key string or identifier) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | String comparison function (compare against key a2) |
| 005897ca | sub_5897CA | String tokenizer/searcher (find next segment by delimiter) |

**Guard conditions:** If sub_5897CA returns null (no delimiter found) OR sub_588410 returns match (string equals a2), returns 0 (failure). If sub_5897CA on second call (with byte_5EA438) returns non-null, returns 1 (success). Otherwise returns 0.
