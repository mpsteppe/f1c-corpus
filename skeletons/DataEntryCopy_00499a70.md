## DataEntryCopy_00499a70 — Data entry copy with self-assignment guard

**Summary:** Copies string pointer and field at this+0x8 from source a2 to destination this. Falls back to default directory (byte_5EA438) when source string is NULL. Part of data entry assignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_495B60 (00495b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | field copied from source a2+0x8 (data value/identifier) |

**Written-by note (persistence):**
- this 0x8: written from a2+0x8 during copy; persists until next assignment

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory — fallback when source string is NULL |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies source string with buffer reallocation |

**Guard conditions:** Guard: `a2 == this` — BLOCKED returns -1 (self-assignment prevention). If source string pointer is NULL, falls back to byte_5EA438 default path.
