## PathRegisterFieldSet_00498d00 — Path Register Field Setter

**Summary:** Copies a path string into an internal buffer via StringCopyWithBufferRealloc and stores an associated integer value in the adjacent field at offset 0x44.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProcessingDispatch (0046e590)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | RW | — | Associated integer value for the registered path (from parameter a3) |

**Written-by note (persistence):**
- this 0x44: Overwritten unconditionally each call; persists until next call overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies string a2 into the internal buffer at this+0x3C |

**Guard conditions:** (none — always executes unconditionally)
