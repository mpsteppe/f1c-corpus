## ListIndexedAccessor_004c5130 — Access linked list element by stored index

**Summary:** Reads an index from field 0x18, validates it against list count, walks the linked list to that position, and returns the data value (int pointer dereferenced from node). Falls back to first element if index is out of bounds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackSceneConfigLoader (00477680)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | Data pointer in head node (first node's int value) |
| this | 0x8 | R | — | Head pointer of linked list |
| this | 0x10 | RW | — | Iterator pointer; reset to head on out-of-bounds fallback |
| this | 0x14 | R | — | Count of items in list (upper bound for index check) |
| this | 0x18 | R | — | Index to access (stored position in list) |

**Written-by note (persistence):**
- this 0x10: reset to head pointer on out-of-bounds fallback; persists until next traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[6]` (index at 0x18) >= 0 AND < `this[5]` (count at 0x14), walk list to that index and return node's data. Otherwise, reset iterator to head and return first element's data (or 0 if list empty).
