## RenderObjectUpdateDispatch_004c99d0 — RenderDeviceStatePollAndTrigger

**Summary:** Polls render device state via method call (vtable offset 36) on the InitStatus object. If status flags indicate a pending update, triggers render operation (vtable offset 40) with parameters (1, 1.0f, ~0.33f).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ace20 | flt_5ACE20 | R | Unknown_Float_5ACE20 [DERIVED] |
| 005ace24 | dword_5ACE24 | R | RenderDevicePtr [DERIVED] |
| 005ace28 | dword_5ACE28 | R | TriggerFunctionPtr [DERIVED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `dword_8AC4C4` (InitStatus) — if zero, returns 0 immediately (not initialized). After state check via vtable[36], conditionally proceeds to trigger if carry/parity flags set.
