## KeyEventDispatchToSubHandlers_0055c7f0 — Dispatches key events to input-state sub-handlers

**Summary:** Filters key events by message type (0x200000) and key code; routes space key (32) to InputStateQueryWrapper and shift key (16) to sub_55C7B0. Part of input/UI event processing system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DTextureCreation (00550080)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1544 | R | — | Buffer or configuration passed to sub_55C650 for key event processing |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055c450 | sub_55C450 | Input state query — resolves key state into v4 |
| 0055c650 | sub_55C650 | Prepares/dispatches key event buffer from field at 0x1544 |
| 0055c7b0 | sub_55C7B0 | Handler for shift key (16) action |
| 0055c7d0 | InputStateQueryWrapper | Handler for space key (32) action |

**Guard conditions:** If a2 (key event message type) != 0x200000, returns -1 (blocked). Only 0x200000 passes. Then checks v4 (key code): 32 passes to InputStateQueryWrapper, 16 passes to sub_55C7B0, all other values blocked (return -1).
