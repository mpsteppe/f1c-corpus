## LinkedListPoolDestructor_0048aaa0 — Pooled linked-list destructor

**Summary:** Frees all nodes in linked pool: walks list, frees node data (and inner data if flag byte set), frees each node struct, zeros pool fields (0xEC-0xF8), reinitializes via ConstructorWithVTableSet. Frees self if a2 bit 0 set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xEC)+0x0) | 0x0 | R | — | first field of node data (freed via FreeWrapper if non-null) |
| *(*(this+0xEC)+0x4) | 0x4 | R | — | second field of node data (not directly accessed in this function) |
| *(this+0xEC) | 0x0 | R | — | v4[0] — data pointer within node struct |
| *(this+0xEC) | 0x8 | R | — | flag byte (v5) — if set, data needs deep freeing |
| this | 0xEC | RW | 0 | pool head pointer — zeroed after cleanup |
| this | 0xF0 | RW | 0 | pool field 2 — zeroed after cleanup |
| this | 0xF4 | RW | 0 | pool field 3 — zeroed after cleanup |
| this | 0xF8 | RW | 0 | pool field 4 — zeroed after cleanup |

**Written-by note (persistence):**
- this 0xEC: zeroed on every call unconditionally
- this 0xF0: zeroed on every call unconditionally
- this 0xF4: zeroed on every call unconditionally
- this 0xF8: zeroed on every call unconditionally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00488b30 | ConstructorWithVTableSet | reinitializes pool vtable after cleanup |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory (node, data, inner data) |

**Guard conditions:** No guard — runs unconditionally. If pool head (this[0xEC]) is null, only zeros fields and reinitializes.
