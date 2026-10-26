## UIClickEventDispatch_004957a0 — UIClickEventDispatch

**Summary:** Dispatches click/input events (type 1 = left click, type 28 = right click/context) by reading handler strings from nested pointer chain and forwarding to sub_4988D0. After processing events, calls virtual method (vtable slot 8) for default event forwarding. Part of the UI widget event system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x68) | 0x58 | R | — | String pointer for event type 28 (right click/context) read from nested handler chain |
| *(this+0x68) | 0x60 | R | — | String pointer for event type 1 (left click/select) read from nested handler chain |
| obj | 0x20 | R | — | unknown |
| this | 0x0 | R | — | Vtable pointer; slot 8 (offset 32) called after event dispatch |
| this | 0x18 | R | — | Pointer to intermediate handler/manager object (chained from caller) |
| this | 0x68 | R | — | Pointer to handler object with event-specific string slots |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default application directory path — fallback when handler string is NULL |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004988d0 | sub_4988D0 | Process event string — likely plays UI sound, executes action, or navigates based on the resolved name |

**Guard conditions:** Loop over all WORD events at a3 (count = a2). For each event: if event == 1 or 28, check nested pointer chain (this+0x18 → +0x50) for non-NULL before reading the handler string and dispatching. Events that don't match 1 or 28 are silently ignored. NULL handler string falls back to byte_5EA438.
