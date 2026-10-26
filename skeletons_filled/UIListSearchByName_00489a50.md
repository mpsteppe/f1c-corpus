## UIListSearchByName_00489a50 — Linked-list search by string name

**Summary:** Traverses linked list starting from this[0x90], compares each node's string (offset 0xB0) against a2 using sub_588410. Returns 1 with index in *a3 on match, 0 on miss or null inputs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47C360 (0047c360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | next node link pointer in linked list |
| this | 0x90 | R | — | linked list head pointer (first node) |
| this | 0x140 | R | — | unknown — not directly referenced in this function |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | string comparison — returns 0 on match (used in `!sub_588410(v5, a2)` to break loop) |

**Guard conditions:** a2 (search string) must be non-null; this[0x90] (head pointer) must be non-null. If either is null, returns 0 immediately. Loop terminates and returns 0 if traversal reaches end without match.
