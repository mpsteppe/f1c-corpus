## CleanupWrapper_00433eb0 — CleanupWrapper

**Summary:** Cleans up AI state buffer and resets a path string in the object to default directory. Thin wrapper around AIStateBufferInitialize and StringCopyWithBufferRealloc.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProcessingDispatch (0046e590)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path — copied to object field |
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer — AI state buffer to initialize |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ec60 | AIStateBufferInitialize | initialize/reset AI state buffer |
| 00566650 | StringCopyWithBufferRealloc | copy default directory path into this+8 |

**Guard conditions:** No guard conditions — function always executes both calls unconditionally.
