## EditBufferStringUpdate_0048b810 — EditBufferStringReplace

**Summary:** Replaces text edit buffer content with a new string. Copies string via sub_587DD0, filters out invalid chars, resets cursor to end, and calls vtable[11] render update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceModeScreenSetup (004707c0), SessionSetupScreenSetup (00470960), RaceSessionModeDataLoader (00470f20), UIToggleIncrementDecrementHandler (004713e0), ModeSpecificScreenSetup (00471440), TransmissionAIDifficultyScreenSetup (00471dc0), VirtualFactoryPathFormat (00472400), sub_472510 (00472510), sub_472630 (00472630), sub_472930 (00472930), UIStringFormatDisplay (00472cc0), sub_4732D0 (004732d0), UIFrontendCounterDisplayUpdate (004735b0), sub_474510 (00474510), sub_474AB0 (00474ab0), UIFPSPerformanceSettingDisplay (0047c770), StringCursorReset (0048b950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | unknown |
| this | 0x0 | R | — | VTable pointer |
| this | 0x2F0 | RW | 0 | Buffer start pointer for edit text |
| this | 0x2F4 | RW | — | Cursor position pointer (reset to buffer start, then advanced to end) |
| this | 0x2F5 | R | — | unknown |
| this | 0x2F8 | R | — | Buffer end limit (used for truncation) |

**Written-by note (persistence):**
- this 0x2F0: not written here (buffer content written, pointer unchanged). Persists.
- this 0x2F4: reset to buffer start then advanced to string end on each call. Volatile — cursor position.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b560 | sub_48B560 | InputCharFilterByFieldType — validates each char; blocks chars that fail filter |
| 00587dd0 | sub_587DD0 | String copy with length limit (strncpy-style) |

**Guard conditions:** If a2 (new string) is null → BLOCKED (returns -1, no change). If new string equals current buffer content → BLOCKED (returns -1, no change). Otherwise PASSES: copies string, filters, updates cursor, calls vtable update.
