## HUDVenue_004d99e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4aec | byte_5D4AEC | R | DefaultTextColor [DERIVED] (also: ` — frame counter value) |
| 005d4af8 | off_5D4AF8 | R | VenueNamePtr [DERIVED] |
| 005d4afc | off_5D4AFC | R | Unknown_StringPtr_5D4AFC [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | R | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004c5840 | SeasonRacesSectionFinder | [LLM] |
| 004d7e40 | UITextRenderWithScale | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
