## UIScrollAreaAutoScrollManager_0048d850 — ScrollAutoScrollManager

**Summary:** Manages auto-scroll behavior for a UI scroll area based on input state. Reads mouse/touch position and scroll state via ShortComputation_6720 and DualFieldRead, then dispatches scroll commands (0=none, 6=scroll up, 7=scroll up fast, 8=scroll down, 9=scroll down fast, 3=stop) via virtual call at vtable+64 depending on which region the cursor is in.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | Vtable offset 64 — set scroll command method |
| obj | 0xA8 | R | — | Vtable offset 168 — refresh/update method |
| this | 0x0 | R | — | Vtable pointer |
| this | 0xC8 | R | — | Unknown field this[50] used for size calculation |
| this | 0xF8 | R | — | Scroll area size (this[62]) |
| this | 0x100 | RW | — | Auto-scroll counter/debounce (this[64]), decremented in case 4 |
| this | 0x108 | R | — | Scroll boundary top (this[66]) |
| this | 0x10C | R | — | Scroll boundary upper threshold (this[67]) |
| this | 0x110 | R | — | Scroll boundary lower threshold (this[68]) |
| this | 0x118 | R | — | Scroll area inner top (this[70]) |
| this | 0x11C | R | — | Scroll area inner bottom (this[71]) |
| this | 0x120 | R | — | Scroll area outer limit (this[72]) |

**Written-by note (persistence):**
- this 0x100: conditionally decremented in case 4; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0048d9b8 | jpt_48D880 | R | Jump table for scroll state switch |
| 0048d9c4 | byte_48D9C4 | R | Jump table index data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Get current scroll/mouse state enum |
| 00498880 | DualFieldRead | Read mouse/touch position (x, y) |
| 0049adb0 | ShortComputation_adb0 | Calculate scroll area geometry |

**Guard conditions:** Switch on scroll state (0-9). For cases 0/6/7: checks if cursor Y > upper threshold, between thresholds for scroll-up, or below lower threshold for scroll-stop. For cases 3/8/9: similar but with different inner-region thresholds. Cases 4 and 5 handle auto-scroll counter increment/decrement. Default: no-op.
