## NetworkConnectionListDuplication_0057b330 — DuplicateNetworkConnectionLists

**Summary:** Clones source object's two linked lists (socket address entries and opaque data entries) into destination object. Frees destination's existing nodes first, then allocates fresh copies from source.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x4) | 0x4 | R | — | linked list node next pointer |
| *(this+0x18) | 0x8 | R | — | second sub-list head pointer value |
| *(this+0x1C) | 0x4 | RW | — | second sub-list tail pointer |
| *(this+0x8) | 0x0 | R | — | first sub-list head pointer value |
| *(this+0x8) | 0x8 | R | — | linked list node flag byte (checked before free) |
| *(this+0xC) | 0x4 | RW | — | first sub-list tail pointer |
| this | 0x4 | RW | — | connection byte flag copied from source |
| this | 0x8 | RW | 0 | first sub-list head pointer |
| this | 0xC | RW | 0 | first sub-list tail pointer |
| this | 0x10 | RW | 0 | first sub-list first/sentinel node pointer |
| this | 0x14 | RW | 0 | first sub-list entry count |
| this | 0x18 | RW | 0 | second sub-list head pointer |
| this | 0x1C | RW | 0 | second sub-list tail pointer |
| this | 0x20 | RW | 0 | second sub-list first/sentinel node pointer |
| this | 0x24 | RW | 0 | second sub-list entry count |

**Written-by note (persistence):**
- *(this+0x1C) 0x4: overwritten each time function runs; external poke replaced
- *(this+0xC) 0x4: overwritten each time function runs; external poke replaced
- this 0x4: set once per call from source; external poke replaced
- this 0x8: initialized to 0 then repopulated; external poke replaced
- this 0xC: initialized to 0 then repopulated; external poke replaced
- this 0x10: initialized to 0 then repopulated; external poke replaced
- this 0x14: initialized to 0 then repopulated; external poke replaced
- this 0x18: initialized to 0 then repopulated; external poke replaced
- this 0x1C: initialized to 0 then repopulated; external poke replaced
- this 0x20: initialized to 0 then repopulated; external poke replaced
- this 0x24: initialized to 0 then repopulated; external poke replaced

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c7bb | SEH_57B330 | R | SEH handler registration for exception safety |
| 0059e2d8 | __imp_htonl | R | convert IP address to network byte order |
| 0059e2f4 | __imp_htons | R | convert port to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bac20 | ShortComputation_ac20 | allocate and initialize a 12-byte linked list node wrapper (stores data pointer + flag) |
| 00581780 | LinkedListNodeAdvance | advance iterator to next node in linked list |
| 00582290 | ConditionalFreeByFlagCheck | conditionally free node memory based on its flag byte |
| 00587bcf | FreeWrapper_7bcf | free heap-allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate heap memory |

**Guard conditions:** if a2 (source pointer) is NULL → return 0 early (blocks duplication). If *(this+8) (first list head) is non-null → walk and free entire list before repopulating. If *(this+0x18) (second list head) is non-null → walk and free entire list before repopulating.
