## ConditionalRenderingCall_0048d6f0 — ConditionalRenderDispatch

**Summary:** Conditionally dispatches UI rendering. If the screen pointer at this+0xEC is non-null, retrieves a UI string and passes it to sub_498560 for resource lookup, then delegates to UILargeRenderDispatcher for the actual render.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | Screen object pointer (this[16]) |
| this | 0xEC | R | — | Stored screen identifier, guard for rendering |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004862c0 | UIStringAccessor_62c0 | Get UI string from object |
| 00488be0 | UILargeRenderDispatcher | Dispatch rendering command with parameters |
| 00498560 | sub_498560 | Resource lookup/submit with string key |

**Guard conditions:** PASS: this+0xEC is non-zero → proceed with rendering. BLOCKED: this+0xEC is 0 → return 0 immediately.
