## UIWidgetDragHandler_0048df40 — ScrollDragHandler

**Summary:** Handles mouse/touch drag input for a scroll area. Reads cursor position via DualFieldRead and current scroll state via ShortComputation_6720, then changes scroll state (3=start drag, 0=stop drag) based on which region the cursor occupies.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | Vtable offset 64 — set scroll command method |
| this | 0x0 | R | — | Vtable pointer |
| this | 0x10C | R | — | Scroll boundary upper threshold (this[67]) |
| this | 0x110 | R | — | Scroll boundary lower threshold (this[68]) |
| this | 0x11C | R | — | Scroll area inner bottom (this[71]) |
| this | 0x120 | R | — | Scroll area outer limit (this[72]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Get current scroll state enum |
| 00498880 | DualFieldRead | Read mouse/touch cursor position (x, y) |

**Guard conditions:** For state 0/6/7: if cursor within scroll region (between upper/lower and inner/outer bounds) → set state to 3 (start drag). For state 3/8/9: if cursor within same region → set state to 0 (stop drag). Otherwise no change.
