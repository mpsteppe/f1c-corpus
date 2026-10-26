## MenuItemLayoutCalculator_0047b850 — MenuItemLayoutCalculator

**Summary:** Calculates which menu item to display based on scroll offset and cursor position: validates item height, clamps index within bounds, navigates wrapped items via MenuCursorNavigationHelper, then renders via MenuItemRenderHelper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIComponentScrollUpdate (0047b1e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Top margin/padding (subtracted from height) |
| this | 0xC | R | — | Left margin/padding (subtracted from width) |
| this | 0xC8 | R | — | Pointer to an object for resource path setup (sub_498560) |
| this | 0xEC | R | — | Scroll offset (base index for visible item range) |
| this | 0xF0 | R | — | Max visible item count (clamp ceiling) |
| this | 0xF4 | R | — | Item height / line spacing (divisor for vertical position) |
| this | 0xF8 | R | — | Right margin/padding space |
| this | 0xFC | R | — | Bottom margin/padding space |
| this | 0x108 | R | — | DWORD field read (accessed indirectly via called functions) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default fallback directory path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047b730 | MenuCursorNavigationHelper | Navigates wrapped text to find next visible item boundary |
| 0047b910 | MenuItemRenderHelper | Renders the calculated menu item at the computed position |
| 00498560 | sub_498560 | Processes resource directory path before rendering |

**Guard conditions:** Three guards: (1) this+0xF4 (item height) must be > 0, else return 0; (2) cursor line is clamped to [0, this+0xF0-1]; (3) loop breaks when MenuCursorNavigationHelper returns same position (i == v10), meaning no more items to display.
