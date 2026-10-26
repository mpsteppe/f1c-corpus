## MouseInputHandler_0045f030 — MouseInputTooltipRenderer

**Summary:** Processes mouse button inputs when hover timer exceeds threshold and HUD is enabled. Maps action codes to button indices, traverses button state list, formats and renders UI text labels, then resets hover timer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x1B780)+0x4)+0x0) | 0x0 | R | — | Button state data pointer dereferenced from list node |
| *(*(this+0x1B780)+0x4) | 0x0 | R | — | List node's data pointer (start of button state) |
| *(*(this+0x1B780)+0x4) | 0x4 | R | — | List node's next pointer (traversal) |
| this | 0x384 | RW | — | Hover timer float (resets to 0.0 after rendering, threshold >= 0.667) |
| this | 0x1B780 | R | — | Head of button state linked list |
| this | 0x1B78C | R | — | Number of entries/buttons in the list |

**Written-by note (persistence):**
- this 0x384: conditional — reset to 0.0 after each successful render; accumulates over time otherwise

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045f278 | jpt_45F095 | R | Jump table for action code switch (cases 4098-4107) |
| 0059f114 | flt_59F114 | R | AIOvertakeDetection [DERIVED] |
| 005ea438 | byte_5EA438 | R | Default directory/fallback string for empty labels |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] — number of input action entries |
| 007cb21c | word_7CB21C | R | InputActionMap [DERIVED] — array of action codes |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] — when set, skip all rendering |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] — current session time for progress bar encoding |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bc50 | StringCopyWithFormatQuery | Format and copy string with query parameters |
| 0045bd10 | TextLineWrappingAndRendering | Render text line with word wrapping |
| 00462250 | TextureCreationWrapper | Create or get texture for rendering |
| 004a0df0 | SessionStateDispatch | Dispatch session state update |
| 004b0b20 | sub_4B0B20 | String buffer initialization/clear |
| 004b33b0 | ProgressBarEventEncode | Encode progress bar event with string length |
| 00587dd0 | sub_587DD0 | Copy string with length limit |

**Guard conditions:**
- this[225] (timer at 0x384) < 0.667 → skip entirely.
- byte_7CE254 (DisableHUDFlag) != 0 → skip entirely.
- dword_7CB218 (input count) <= 0 → skip loop.
- For each action code in word_7CB21C:
  - Action code not in {4098..4107} → skip (default case).
  - Mapped button index > this[28131] (list count) → skip.
  - Button index < 0 or >= list count → skip.
  - List traversal: node at this[28128] (head) starting point, walk by next pointers.
  - If target node or its data pointer null → skip rendering.
  - If label string null → fall back to byte_5EA438 (default path).
  - String length clamped to 0-159 characters.
  - On success: encode progress event, copy string, create texture, render text, reset timer to 0.0.
