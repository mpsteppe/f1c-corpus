## UIFPSPerformanceSettingDisplay_0047c770 — FPSDisplayTextUpdate

**Summary:** Reads global framerate counter, selects performance tier (0 if <=16fps else 2), formats FPS as decimal string, and updates the edit buffer with the formatted value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x310 | RW | 2 | performance setting tier; 0=low (<16fps), 2=normal |

**Written-by note (persistence):**
- this 0x310: written conditionally based on framerate; external poke overwritten each update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] — "%d" format string for integer-to-string conversion |
| 007cf230 | dword_7CF230 | R | FramerateCounter [DERIVED] — current frames-per-second value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b810 | EditBufferStringUpdate | update UI edit/display buffer with formatted FPS string |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string formatting: "%d" with framerate value |

**Guard conditions:** No early return guard. If framerate counter <= 16, sets performance tier to 0 (low); otherwise sets tier to 2 (normal). Always formats and updates display buffer regardless of tier.
