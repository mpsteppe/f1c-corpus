## ConditionalDelegationViaVTable_0046e6f0 — Conditional delegation via vtable

**Summary:** Creates UI element ID 44 via vtable dispatch, retrieves its text content, and delegates to InitWithStackBuffer for stack-buffer initialization. Chains UI element creation to buffer initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | vtable offset 28 — function that creates/gets UI objects by ID |
| this | 0x40 | R | — | pointer to vtable-based object for creating UI elements |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0046e5c0 | InitWithStackBuffer | initializes stack buffer from string content |
| 00489920 | UIScreenTextAccessor | retrieves text content from UI screen element |

**Guard conditions:** No entry guard. If UI element ID 44 creation fails (returns null), skips body, returns 0. If UIScreenTextAccessor returns null, skips InitWithStackBuffer call. Always returns 0.
