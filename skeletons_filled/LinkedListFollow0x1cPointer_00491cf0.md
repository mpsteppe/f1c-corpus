## LinkedListFollow0x1cPointer_00491cf0 — FollowPointerAndStore

**Summary:** Reads pointer at struct offset 0x1C, copies it to offset 0x24, then dereferences it and returns the first DWORD. Simple linked-list node follower.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderDispatchWithIteration (004993d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x1C) | 0x0 | R | — | First DWORD of the object pointed to by offset 0x1C (dereferenced return value) |
| obj | 0x1C | R | — | Source pointer field — read and copied to offset 0x24 |
| obj | 0x24 | RW | — | Destination copy — receives value from offset 0x1C |
| this | 0x0 | R | — | Pointer to struct; *this contains the fields |

**Written-by note (persistence):**
- obj 0x24: written each call with value from offset 0x1C; overwritten on next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If source pointer at offset 0x1C is null → return 0 (destination set to 0 as well). If non-null → return first DWORD of pointed-to object.
