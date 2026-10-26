## DriverAbbreviationNameFormatter_004c6a10 — FormatDriverAbbreviationName

**Summary:** Formats a driver name into abbreviated display string (e.g., initial-dot + truncated name) using "Abbreviation" section lookup or fallback extension-strip. Part of driver name/HUD display system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SetDriverName (004c6980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4707 | RW | 0 | null terminator for output name buffer at this+0x46F8 |

**Written-by note (persistence):**
- this 0x4707: written unconditionally as 0 at end — overwritten every call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005d3200 | aC11s | R | AbbreviationFormat ("%c. %-11s") [DERIVED] |
| 005d320c | a13s | R | FullNameFormatString [DERIVED] (also: ` — `"%-13s"` full-name format) |
| 005d3214 | aAbbreviation | R | AbbreviationSectionName [DERIVED] (also: ` — "Abbreviation" section name constant) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | searches string table for abbreviation match |
| 00567970 | DataEntryAccessor | accesses data entry from linked list result |
| 005679c0 | StringKeyedLinkedListSearch | searches linked list for "Abbreviation" section key |
| 00568210 | AudioChannelStop | stops audio channel at this+0x4620 (used as validity check) |
| 00587c20 | sub_587C20 | finds substring/extracts data after extension marker |
| 00587dd0 | sub_587DD0 | copies string with length limit |
| 0058815f | StringFormatWithBufferOverflowCheck | safe snprintf-style string formatting |
| 00589901 | sub_589901 | finalizes/stores formatted string to display buffer |

**Guard conditions:** Checks `this != (const char*)-17952` (sentinel/null pointer check). If this equals the sentinel value, entire function is skipped (early exit). Secondary check: `AudioChannelStop(this+17952)` must succeed for the abbreviation-lookup path.
