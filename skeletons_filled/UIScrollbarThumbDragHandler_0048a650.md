## UIScrollbarThumbDragHandler_0048a650 — UI scrollbar thumb drag and click handler

**Summary:** Handles mouse input on a scrollbar element: determines whether the click landed on the scroll-up arrow, scroll-down arrow, thumb (drag zone), or track area; dispatches navigation (increment/decrement) or thumb-drag state changes; and triggers string lookup/rendering updates for the scrolled content. Part of the UI scrollbar system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | scrollbar track start boundary (x or y) |
| obj | 0x1C | R | — | scrollbar track end boundary |
| obj | 0x20 | R | — | scroll-up arrow zone boundary |
| obj | 0x24 | R | — | scroll-down arrow zone boundary |
| obj | 0x2C | R | — | thumb size/dimension |
| obj | 0x40 | R | — | scrolled content item string buffer |
| obj | 0x98 | R | — | content item index or reference |
| obj | 0xA8 | R | — | sub-element pointer for deeper lookup |
| this | 0x0 | R | — | vtable pointer (for virtual calls: +24, +28, +32, +36, +44) |
| this | 0x10 | R | — | scroll offset/position value |
| this | 0x90 | R | — | scrollbar track offset |
| this | 0xA0 | R | — | thumb position reference |
| this | 0xE0 | R | — | scrolled content item count or index limit |
| this | 0x130 | R | — | content pointer (used for string lookup) |
| this | 0x138 | R | — | additional content pointer |
| this | 0x140 | R | — | additional content reference |
| this | 0x144 | RW | 1 | scroll-up arrow click flag (byte) |
| this | 0x145 | RW | 1 | scroll-down arrow click flag (byte) |
| this | 0x146 | RW | 1 | thumb-drag active flag (byte) |
| this | 0x148 | R | — | vtable function pointer (+148 = get state) |
| this | 0x150 | R | — | vtable function pointer (+152 = finalize/return) |
| this | 0x158 | R | — | vtable function pointer (+168 = content update callback) |
| this | 0x15C | R | — | content item list length |
| this | 0x168 | RW | — | computed target index for content navigation |
| this | 0x1A8 | R | — | scrollbar element flags |

**Written-by note (persistence):**
- this 0x144: set each input event — external poke does NOT persist across frames
- this 0x145: set each input event — external poke does NOT persist across frames
- this 0x146: set each input event — external poke does NOT persist across frames
- this 0x168: set each input event — external poke does NOT persist across frames

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489500 | DecrementCounterVirtualCall | handle scroll-up (decrement) navigation |
| 00489530 | UINavigationAdvanceHandler | handle scroll-down (advance) navigation |
| 00489560 | StateUpdateWithDecrement | update scroll state when clicking above thumb |
| 004895b0 | sub_4895B0 | update scroll state when clicking below thumb |
| 00489e90 | FloatToIntConversion | recalculate scroll position after state change |
| 00489f40 | sub_489F40 | compute target content index from click position |
| 00498880 | DualFieldRead | read dual input fields (mouse x, y) |
| 0049a490 | StringReverseCopyLookup | lookup and copy string for content display |

**Guard conditions:** Mouse click position (`v19` = x, `v18` = y) is checked against scrollbar geometry:
- `v19 > v4` (x beyond track start) AND `v19 <= v3` (x within track end): click is inside scrollbar track
  - `v18 >= v5` (y at or below up-arrow zone): check further
    - `v18 >= v6` (y at or below down-arrow zone): thumb drag zone → set flag 0x145 and advance
    - `v18 < v7` (y above thumb): page-up zone → decrement state
    - `v18 > v7 + thumb_size` (y below thumb): page-down zone → advance state
    - between thumb top and thumb bottom: thumb drag active → set flag 0x146
  - `v18 < v5` (y in up-arrow zone): scroll-up → set flag 0x144 and decrement
- Outside track: if byte at 0xE0 (224) is set AND thumb size > 0, attempt content navigation via `sub_489F40` and `StringReverseCopyLookup`
