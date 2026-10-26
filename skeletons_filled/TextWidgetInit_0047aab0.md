## TextWidgetInit_0047aab0 — TextWidgetInit

**Summary:** Initializes a text widget: sets score DB pointer, zeros fields, optionally processes a directory path string via sub_498560, renders text using key aTtgjz, sets padding/margins to 5, and returns AIOvertakeGapCalc result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC8 | R | — | Pointer to an optional source object (checked for null before path processing) |
| this | 0xE0 | RW | — | ScoreDB base pointer (set to dword_7C5728) |
| this | 0xE4 | RW | 0 | DWORD field zeroed |
| this | 0xE8 | RW | 0 | DWORD field zeroed |
| this | 0xEC | RW | 0 | DWORD field zeroed |
| this | 0xF8 | RW | 5 | Padding/margin X dimension |
| this | 0xFC | RW | 5 | Padding/margin Y dimension |
| this | 0x108 | R | — | DWORD field read (accessed indirectly via called functions) |
| this | 0x110 | RW | 0 | DWORD field zeroed |

**Written-by note (persistence):**
- this 0xE0: Written once with score DB pointer; persists until overridden
- this 0xE4: Written to 0 once; persists until modified
- this 0xE8: Written to 0 once; persists until modified
- this 0xEC: Written to 0 once; persists until modified
- this 0xF8: Written to 5 once; persists until modified
- this 0xFC: Written to 5 once; persists until modified
- this 0x110: Written to 0 once; persists until modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c71cc | aTtgjz | R | Text key/code for rendering (TTGJZ) |
| 005ea438 | byte_5EA438 | R | Default application directory path |
| 007c5728 | dword_7C5728 | R | Score database base pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004983b0 | TextRenderToSurface | Renders text string with key aTtgjz to a surface/buffer |
| 00498560 | sub_498560 | Processes a directory path string (file I/O or resource loading) |

**Guard conditions:** Checks this+0xC8 (this[50]) — if non-null, reads char* at offset +64 from that object (falls back to byte_5EA438 if null) and calls sub_498560. The path processing is skipped entirely if this+0xC8 is null.
