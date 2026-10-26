## ObjectBufferCopyWithValidation_00515d26 — ObjectBufferAllocAndCopy

**Summary:** Iterate array of object descriptors, allocate 130-byte buffers for unallocated entries, copy data from source pool. Updates parent object fields with type ID and fires vtable callback on new allocations.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VtableDelegateDispatch (00515db8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x10 | R | — | object type/format ID |
| *(this+0x124) | 0x4C | RW | — | allocated buffer pointer — checked null, set to new alloc |
| *(this+0x4) | 0x0 | R | — | vtable[1] function — allocation callback (a1, 1, 130) |
| obj | 0x0 | R | — | obj vtable base (first word of object chain pointed by this[0]) |
| obj | 0x14 | RW | 51 | set to literal 51 on first allocation (init marker) |
| obj | 0x18 | RW | — | set to object type ID on first allocation |
| this | 0x0 | R | — | vtable base pointer — obj pointer (this[0]) |
| this | 0x4 | R | — | vtable[1] — allocator function pointer |
| this | 0x120 | R | — | array element count |
| this | 0x124 | R | — | pointer to array of object descriptors |

**Written-by note (persistence):**
- *(this+0x124) 0x4C: written once per unallocated element; persists until freed
- obj 0x14: written once (set to 51); persists until overwritten
- obj 0x18: written once (set to type ID); persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | > | 0 | element count — zero or negative skips entire loop |
| *(this+0x124) | 0x4C | == | 0 | allocation slot — only allocates/copies if null (unallocated) |

**Guard interpretation:** Outer guard: count at 0x120 must be > 0 or function does nothing. Per-element guard: skip already-allocated entries (0x4C != NULL). PASSES when count > 0 and slot is null → allocate 130 bytes, copy source data, update obj fields, fire vtable callback.
