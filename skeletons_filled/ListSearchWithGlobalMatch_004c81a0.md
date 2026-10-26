## ListSearchWithGlobalMatch_004c81a0 — Search linked list for matching global value

**Summary:** Searches a linked list at this+0xC for an entry whose second DWORD (+4) matches the global dword_8ACFCC. Iterates from current cursor position; when a match is found, sets entry's field at +0x18 to 0. If no match, returns without modification. Advances cursor after each non-matching entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x14)+0x0) | 0x4 | R | — | next pointer of current cursor entry |
| *(*(this+0x14)+0x0) | 0x18 | RW | 0 | match flag field, zeroed when match found |
| *(this+0x14) | 0x0 | R | — | head pointer of linked list |
| *(this+0x14) | 0x4 | R | — | tail pointer of linked list |
| *(this+0xC) | 0x0 | R | — | list header at this+0xC, first field head pointer |
| this | 0xC | R | — | pointer to linked list header struct |
| this | 0x14 | RW | — | pointer to second linked list header struct |

**Written-by note (persistence):**
- *(*(this+0x14)+0x0) 0x18: set to 0 on match; persists
- this 0x14: cursor updated as iteration advances; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008acfcc | dword_8ACFCC | R | ComparisonValue (sentinel) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | linked list header pointer at this+0xC — if NULL, skip entire search |

**Guard interpretation:** BLOCKED: this[3] (header at +0xC) is NULL, no list to search. PASSES: list exists, proceed to iterate and search for matching entry.
