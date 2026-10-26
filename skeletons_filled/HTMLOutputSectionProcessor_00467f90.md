## HTMLOutputSectionProcessor_00467f90 — HTMLOutputSectionProcessor

**Summary:** Processes parsed credits/HTML data: destroys a secondary linked list, then walks the primary list filtering strings for "Header" content. Non-"Header" strings cause traversal to the next node, whose content is inserted via LinkedListInsertWithNodeAllocation. Belongs to HTML/results output section processing system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuLayoutCalculator (00467dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x100) | 0x0 | R | — | current node's data pointer (string payload) |
| *(this+0x48) | 0x4 | R | — | secondary list node's next pointer |
| *(this+0xF8) | 0x0 | R | — | primary list head node's data pointer |
| this | 0x44 | RW | 0 | secondary list head pointer (this[17]); cleared after destruction |
| this | 0x48 | RW | 0 | secondary list tail pointer (this[18]); cleared after destruction |
| this | 0x4C | RW | 0 | secondary list node count (this[19]); cleared after destruction |
| this | 0x50 | RW | 0 | secondary list capacity (this[20]); cleared after destruction |
| this | 0xF8 | R | — | primary linked list head pointer (this[62]) |
| this | 0x100 | RW | — | current traversal pointer (this[64]); advanced through list |
| this | 0x104 | R | — | count/limit field (this[65]) |

**Written-by note (persistence):**
- this 0x44: set to 0 after destroying secondary list; overwritten on each call.
- this 0x48: set to 0 after destroying secondary list; overwritten on each call.
- this 0x4C: set to 0 after destroying secondary list; overwritten on each call.
- this 0x50: set to 0 after destroying secondary list; overwritten on each call.
- this 0x100: advanced through primary list during traversal; reset to head on each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6714 | aHeader2 | R | Header2String [DERIVED] |
| 005c6720 | aHeader_0 | R | String_Header [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00418d60 | DestructorWithDoubleFreePattern | destructor for secondary list nodes (frees each node) |
| 00486f30 | LinkedListInsertWithNodeAllocation | inserts a string into an output linked list with node allocation |
| 00588410 | sub_588410 | compares string against a literal (for "Header" detection) |

**Guard conditions:** Checks this[62] (head, offset 0xF8) for null; if null, no initial data. For each string in primary list: checks if it matches "Header" (sub_588410 call). If match (PASSES) and NOT "header2", inserts string into output list. If NOT a match (BLOCKED), advances to next node (this[64] = next) and inserts that node's string instead. Loop exits when this[64] becomes null.
