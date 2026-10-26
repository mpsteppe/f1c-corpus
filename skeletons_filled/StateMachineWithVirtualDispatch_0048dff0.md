## StateMachineWithVirtualDispatch_0048dff0 — ScrollStateDispatch

**Summary:** Dispatches scroll behavior based on state from ShortComputation_6720. States 1→scroll up (cmd 6), 2→scroll down (cmd 7), 4→scroll left (cmd 8), 5→scroll right (cmd 9). Each state sets a scroll command via vtable+64 and calls refresh via vtable+156.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | R | — | Vtable offset 64 — set scroll command method |
| obj | 0x9C | R | — | Vtable offset 156 — refresh/repaint method |
| this | 0x0 | R | — | Vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0048e050 | jpt_48DFFE | R | Jump table for state switch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486720 | ShortComputation_6720 | Get current scroll/mouse state enum |

**Guard conditions:** Switch on state (1, 2, 4, 5). All other values fall through to default (refresh only, no scroll command). State 1 and 4 additionally trigger refresh after the command.
