## UIMenuItemCreator_00489600 — Menu item creator

**Summary:** Creates and initializes a new UI menu item struct (232 bytes). Allocates via heap, sets vtable, copies text strings, inserts into list. Returns 0 on success, -1 if text argument null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuCommandDispatcher (004674e0), sub_468BF0 (00468bf0), sub_469900 (00469900), ResultsPageBuilder (00469fb0), StandingsDisplay (0046a560), MessageNameBufferUpdate (0046ad50), sub_46B9B0 (0046b9b0), sub_46BA20 (0046ba20), sub_46BC20 (0046bc20), HTMLSeasonOutput (0046ee60), ExtensionStripperForAllListEntries (0046f170), sub_470190 (00470190), sub_475150 (00475150), sub_47BF30 (0047bf30), sub_47C360 (0047c360), sub_47D800 (0047d800), DriverCareerStatsHTMLWriter (0047dd10), sub_47E0A0 (0047e0a0), UITextInputHandler (004896c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | vtable method offset 44 — called with arg 1 to register/activate item |
| obj | 0xAC | R | — | vtable method offset 172 — called to set item text/name from a2 |
| this | 0x0 | R | — | vtable pointer (first field of list controller) |
| this | 0xB8 | R | — | fallback string pointer used when a3 is null |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486340 | sub_486340 | registers/inserts item v8 into the list with flag a6 |
| 00488f90 | VTableSetWithFlag | allocates and initializes 232-byte object with vtable, returns pointer |
| 00489480 | PopListWithDestructor | pops item from internal list (possibly removal or iteration step) |
| 00566650 | StringCopyWithBufferRealloc | copies/reallocates a string buffer into target |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation (232 bytes for menu item struct) |

**Guard conditions:** a2 (item text/name) must be non-null; if null, function returns -1 immediately without allocation or list operations. a3 can be null — falls back to this[0xB8] then byte_5EA438.
