## PhysicsObjectStateSetter_0051cd3e — Physics sub-struct state initialization

**Summary:** Initializes a physics-related sub-struct by clearing a byte state flag to 0 and copying a parameter value from the main struct offset 0x60 to the sub-struct offset 0x2C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x19C) | 0x24 | RW | 0 | Byte state flag at sub-struct offset 0x24 — cleared to 0 |
| *(this+0x19C) | 0x2C | RW | — | DWORD field at sub-struct offset 0x2C — receives value from main struct 0x60 |
| this | 0x60 | R | — | Source parameter value copied into sub-struct |
| this | 0x19C | R | — | Pointer to physics/vehicle sub-struct being initialized |

**Written-by note (persistence):**
- *(this+0x19C) 0x24: Set to 0 unconditionally. External pokes survive until next call.
- *(this+0x19C) 0x2C: Written with value from offset 0x60 each call. External pokes overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guards — unconditional field writes.
