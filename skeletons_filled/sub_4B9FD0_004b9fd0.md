## sub_4B9FD0_004b9fd0 — Replay activation message display

**Summary:** Builds and displays a replay activation status message once. Checks session state, formats path+string, and renders via TextLineWrappingAndRendering. Sets completion flag to prevent re-display.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A00A0 (004a00a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Replay recording active flag (DWORD == 1 means active) |
| this | 0x4 | RW | 1 | Already-displayed flag; set to 1 after first render |

**Written-by note (persistence):**
- this 0x4: set to 1 on first call; prevents re-display on subsequent calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005d2480 | aReplayActivati | R | String_ReplayActivati [DERIVED] |
| 005d2494 | aReplayRecordin | R | ReplayRecordingString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007d1d8c | dword_7D1D8C | R | Unknown_7D1D8C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Look up string in table (used to copy "ReplayRecording" / "ReplayActivati" into buffer) |
| 00455260 | sub_455260 | Retrieve module path string from game module manager |
| 0045bd10 | TextLineWrappingAndRendering | Render wrapped text line to display |
| 00461db0 | SessionStateCheckWrapper | Check current game session state |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | Replay recording active flag |

**Guard interpretation:** PASSES when this[0] == 1 (replay recording active) AND this[4] == 0 (not yet displayed). BLOCKS (early return) if already displayed or replay not active.
