## ConditionalVirtualCallTriplet_0040be20 — VirtualTripleRelease

**Summary:** Calls virtual method at vtable[0] with argument 1 on up to three stored interface pointers (offsets 0x18, 0x1C, 0x20), then nulls each. Used for releasing/chaining cleanup of three polymorphic objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18) | 0x0 | R | — | pointer to first virtual object to release |
| *(this+0x1C) | 0x0 | R | — | pointer to second virtual object to release |
| *(this+0x20) | 0x0 | R | — | pointer to third virtual object to release |
| this | 0x18 | RW | 0 | storage for first virtual object pointer, zeroed after release |
| this | 0x1C | RW | 0 | storage for second virtual object pointer, zeroed after release |
| this | 0x20 | RW | 0 | storage for third virtual object pointer, zeroed after release |

**Written-by note (persistence):**
- this 0x18: set once (init 0), consumed and restored to 0 each call
- this 0x1C: set once (init 0), consumed and restored to 0 each call
- this 0x20: set once (init 0), consumed and restored to 0 each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — all three slots processed unconditionally; each non-null slot triggers vtable[0] call then zeroed
