## StringLookupInLinkedDictionary_0054a2d0 — Look up string in linked dictionary by linear search

**Summary:** Searches a linked dictionary for a matching string. Reads head at this+0x100, then walks nodes via next pointer at node+0x104 comparing each node's string (at node+0x08) against the input using strcmp. Returns node pointer on match or 0 if not found. Called by LinkedListUpdate and AudioNodeUpdateWalk to resolve string names to dictionary entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListUpdate (00549380), AudioNodeUpdateWalk (00549440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x204) | 0x104 | R | — | Next pointer linking dictionary nodes |
| this | 0x100 | R | — | Head of linked dictionary chain |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x100]` (head) is null → return 0 immediately (dictionary empty). Walk loop checks node+0x104 next pointer; if null → return 0 (end of chain without match). strcmp match against node+0x08 PASSES and returns node pointer.
