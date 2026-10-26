## UIFrontendCounterDisplayUpdate_004735b0 — FrontendCounterDisplayUpdate

**Summary:** Checks if CurrentCarDisplayIndex global changed from cached value (this+0x31C); returns early if unchanged. Otherwise updates cache, then displays either a list-based string (for index 0 or special value) or the raw numeric index depending on comparison with another threshold global.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x31C | RW | — | cached copy of CurrentCarDisplayIndex (dword_7D0110) |

**Written-by note (persistence):**
- this 0x31C: written each call when index changed; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList — used as format/list reference |
| 007d0110 | dword_7D0110 | R | CurrentCarDisplayIndex — current selection index |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | retrieve display string from UI list |
| 0048b810 | EditBufferStringUpdate | update UI edit/display buffer with formatted string |
| 0058815f | StringFormatWithBufferOverflowCheck | format string with overflow protection |

**Guard conditions:**
- `dword_7D0110 == this[199]` (cached index unchanged) → **BLOCKED**: returns 0 immediately, no display update
- Otherwise: updates cache and continues to display logic:
  - If `v1 == 0`: uses list accessor(0) for display
  - If `v1 != dword_7D011C` (referenced in code, not in globals table): formats and displays `v1` as raw number
  - Else (`v1 == dword_7D011C`): uses list accessor(1) for display
