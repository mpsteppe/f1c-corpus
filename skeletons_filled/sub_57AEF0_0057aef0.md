## sub_57AEF0_0057aef0 — DynamicsSolverObjectCleanup

**Summary:** Destructor for dynamics solver object. Frees two embedded linked lists (heads at offsets 0x18 and 0x8): walks each, frees data pointer if node flag at offset 8 set, frees node. Zeroes all fields. Switches vtable from DynamicsSolverObj_VTable to PTR_VTABLE_5B8A40.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FlaggedDestructor (00583150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4 | R | — | linked list 1 node->next pointer (node+4) |
| *(this+0xC) | 0x4 | R | — | linked list 2 node->next pointer (node+4) |
| this | 0x0 | RW | — | vtable pointer, switched from off_5B8A1C to off_5B8A40 |
| this | 0x8 | RW | 0 | list 2 head (this[2]), zeroed after freeing |
| this | 0xC | RW | 0 | list 2 tail/state (this[3]), zeroed |
| this | 0x10 | RW | 0 | DWORD field (this[4]), zeroed |
| this | 0x14 | RW | 0 | DWORD field (this[5]), zeroed |
| this | 0x18 | RW | 0 | list 1 head (this[6]), zeroed after freeing |
| this | 0x1C | RW | 0 | list 1 tail/state (this[7]), zeroed |
| this | 0x20 | RW | 0 | DWORD field (this[8]), zeroed |
| this | 0x24 | RW | 0 | DWORD field (this[9]), zeroed |

**Written-by note (persistence):**
- this 0x0: written twice per call (first to off_5B8A1C, then to off_5B8A40); final value survives
- this 0x8: written once (0); survives
- this 0xC: written once (0); survives
- this 0x10: written once (0); survives
- this 0x14: written once (0); survives
- this 0x18: written once (0); survives
- this 0x1C: written once (0); survives
- this 0x20: written once (0); survives
- this 0x24: written once (0); survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8a1c | off_5B8A1C | R | DynamicsSolverObj_VTable [DERIVED] — initial vtable set during cleanup |
| 005b8a40 | off_5B8A40 | R | PTR_VTABLE_5B8A40 [DERIVED] — final vtable after cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees node and optionally data pointer |

**Guard conditions:** none — for loops terminate naturally on null node pointer; no early return

