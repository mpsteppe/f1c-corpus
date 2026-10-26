## HUDVenue_004d99e0 — Venue/track name HUD display

**Summary:** Renders venue name, decorative separator bar, and additional race info at fixed HUD positions. Timer-gated (this[4] decrements each frame; hides when expired). Looks up venue name and secondary string from race data tables via linked-list searches.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | Display timer (float, seconds); decremented by dbl_8AFE98 each call; < 0 hides venue HUD |

**Written-by note (persistence):**
- this 0x10: Decremented each call. External poke survives (incremental). Display remains active while >= 0.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4aec | byte_5D4AEC | R | Character used to construct decorative separator bar (rendered 16 times) |
| 005d4af8 | off_5D4AF8 | R | Pointer to venue name string data in race database |
| 005d4afc | off_5D4AFC | R | Pointer to secondary/extra info string data |
| 005ea438 | byte_5EA438 | R | Path prefix prepended to separator string |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — base for string table check |
| 005ec4cc | byte_5EC4CC | R | MessageDisplayBuffer [DERIVED] — working buffer for rendered text |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] — delta time subtracted each frame |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Checks if venue name is already in display buffer; if not, copies it in |
| 004c5840 | SeasonRacesSectionFinder | Looks up current race section data (returns 0 if unavailable) |
| 004d7e40 | UITextRenderWithScale | Renders venue name, separator bar, and extra info at HUD positions |
| 00567970 | DataEntryAccessor | Extracts string data from a race database entry |
| 005679c0 | StringKeyedLinkedListSearch | Searches for venue/extra info entry by key string pointer |
| 00587dd0 | sub_587DD0 | Copies string into local buffer with max length 127 |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats separator character for decorative bar construction |

**Guard conditions:** `this[4] < 0.0` (offset 0x10) → BLOCKED entire display (return 1, timer expired). `SeasonRacesSectionFinder(0) == 0` → BLOCKED venue name render (no race data). `v2` (venue name) == NULL → skip venue text. `v10` (extra info) == NULL → skip extra text line. `BinarySearchInStringTable` false → string copied into buffer before render.
