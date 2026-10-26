## ObjectDestructorWithArrayCleanup_005511a0 — ObjectAndArrayDestructor

**Summary:** Frees a single allocated object at this+0x0, then destroys a counted array of 136-byte elements at this+0x18 using backward iteration, and zeros both pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** QueueResourceCleanup (0054c410)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Pointer to single allocated object (freed and zeroed) |
| this | 0x18 | RW | 0 | Pointer to counted array of 136-byte elements (freed and zeroed) |

**Written-by note (persistence):**
- this 0x0: Set to 0 after free; external poke survives only before next destruct call
- this 0x18: Set to 0 after array free; external poke overwritten on destruct

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00557470 | EmptyStub_7470 | Stub called before each free (debug/sentinel) |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation |

**Guard conditions:** 
- this+0x0 == 0: skip single-object free. PASS when non-null.
- this[6] (offset 0x18) == 0: skip array free entirely. PASS when non-null.
