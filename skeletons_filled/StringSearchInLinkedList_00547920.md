## StringSearchInLinkedList_00547920 — String search in linked list with normalization

**Summary:** Searches linked list (rooted at this+0x28 via node[23] at offset 0x5C) for node matching string a2. For single-string nodes (count == 1), compares directly. For multi-string nodes (count > 1), iterates 96-byte stride sub-entries. Uses sub_589901 for string normalization and StringDotFinder for dot-extension matching. Returns matching node pointer or 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409890 (00409890), CockpitDashboardLEDGaugeSetup (0049ca00), sub_49CD80 (0049cd80), sub_546450 (00546450), sub_546AA0 (00546aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x84) | 0x4 | R | — | first string field in node (offset +4) |
| *(this+0x84) | 0x4C | R | — | array element count for multi-entry nodes (offset +76) |
| *(this+0x84) | 0x5C | R | — | next node pointer for linked list traversal (offset +92) |
| this | 0x28 | R | — | linked list head pointer (this[10]) |
| this | 0x2C | R | — | linked list metadata pointer |
| this | 0x74 | R | — | unknown field read |
| this | 0x84 | R | — | pointer to linked list metadata structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00547af0 | StringDotFinder | find/extract dot extension in filename string |
| 00589901 | sub_589901 | string normalization/lowercase conversion |

**Guard conditions:** (1) If this+0x28 (list head) is null, BLOCKED: return 0 immediately. (2) For each node: if node[+76] (count) == 1: normalize single string and compare via strcmp. If match, return node. (3) If node[+76] > 1: iterate 96-byte stride entries, normalize each string, compare via strcmp. If match, return node + 96*index. (4) If node[+76] <= 0: skip to next node. Traversal ends when node[+92] (next) is null.
