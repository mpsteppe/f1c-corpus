## ShortComputation_9960_004c9960 — StopAndReleaseOwnedObject

**Summary:** Calls the "stop" method (vtable[0] with arg=1) on an owned object at this+0x1C, then clears the handle to 0. Object cleanup/release helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | vtable pointer of the owned object; first method called with arg=1 to stop/release |
| this | 0x1C | RW | 0 | Pointer to an owned playable object; cleared to 0 after stop call |

**Written-by note (persistence):**
- this 0x1C: Written to 0 every time the function runs and the pointer was non-null. Does not survive external poke (explicitly cleared).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `this[7]` (this+0x1C) for non-null. If null, function returns 0 without action. If non-null, calls stop method then clears pointer.
