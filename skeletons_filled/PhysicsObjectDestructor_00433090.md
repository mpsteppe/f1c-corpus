## PhysicsObjectDestructor_00433090 — PhysicsObjectDestructor

**Summary:** Destructor for a physics object struct. Calls session config default init, then frees three heap-allocated pointer fields at offsets 0x0, 0x8, 0x14 if non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoLoadEntryListLoader (00432e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first heap-allocated data pointer field |
| this | 0x8 | R | — | second heap-allocated data pointer field |
| this | 0x14 | R | — | third heap-allocated data pointer field |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432cc0 | SessionConfigDefaultInit | reset physics config struct fields to default/zero |
| 00587bcf | FreeWrapper_7bcf | free heap memory |

**Guard conditions:** Each of the three pointer fields (0x0, 0x8, 0x14) is checked for non-null before calling FreeWrapper_7bcf. If a field is null, the free for that field is skipped.
