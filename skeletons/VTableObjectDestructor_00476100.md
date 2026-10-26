## VTableObjectDestructor_00476100 — UIDatabaseObjectDestructor

**Summary:** Multi-phase destructor for a UI database object: sets DB-object vtable, frees child resource at 0x50, destroys linked list at 0x3C (calling per-node destructors), zeroes list fields, then transitions through HUD and base control vtables freeing owned resources, and optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x3C)+0x0) | 0x0 | R | — | Interface/vtable pointer of linked list node |
| *(this+0x3C) | 0x0 | R | — | Head of linked list (next pointer) |
| this | 0x0 | RW | — | Vtable pointer (switched through 3 vtables during destruction) |
| this | 0x4 | R | — | Owned resource/child pointer to free |
| this | 0x30 | R | — | Child HUD node pointer to free |
| this | 0x3C | RW | 0 | Linked list head pointer (zeroed after destruction) |
| this | 0x40 | RW | 0 | Linked list field (zeroed after destruction) |
| this | 0x44 | RW | 0 | Linked list field (zeroed after destruction) |
| this | 0x48 | RW | 0 | Linked list field (zeroed after destruction) |
| this | 0x50 | R | — | DB child resource pointer to free |

**Written-by note (persistence):**
- this 0x0: vtable swapped during destructor; object invalid after
- this 0x3C-0x48: zeroed after linked list destruction; object invalid after

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a443c | off_5A443C | R | VTable_ControlBase [DERIVED] |
| 005a4450 | off_5A4450 | R | VTable_HUDTextNode [DERIVED] |
| 005a4464 | off_5A4464 | R | VTable_DBObject_5A4464 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper (free with null check) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x48 | == | 0 | Not a guard — written to 0 after linked list cleanup |

**Guard interpretation:** Field at 0x48 is written (zeroed), not read as a guard. Linked list iteration at 0x3C continues while node pointer is non-null. Each resource free is guarded by null check on the pointer.
