## TwoLevelWideStringSearch_00544f50 — TwoLevelWideStringSearch

**Summary:** Searches a two-level linked list for a node matching a given string. Iterates through first-level nodes (next at +440/0x1B8), comparing strings at +140. Each first-level node may have a second-level child at +432/0x1B0 that is also compared before advancing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409890 (00409890), StaticCameraSceneLoader (0040b030), MainView (0040b850), CamMan_Init (0040c920)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x2B0) | 0x1B0 | R | — | second-level child pointer (+432) from first-level node, checked for string match |
| *(this+0x2B0) | 0x1B8 | R | — | next pointer (+440) within first-level linked list |
| this | 0xF8 | R | — | head pointer (this[62]) of first-level linked list |
| this | 0x2A8 | R | — | additional pointer (this[170]) not directly used in search logic |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** BLOCKED when this[62] is 0 (empty list) → return 0 (not found). Returns the matching node pointer when strcmp at +140 matches (either first level or second level at +432).
