## RecursiveNodeDeletion_00434240 — RecursiveNodeDeletion

**Summary:** Destroys a linked list node's data struct. If flag byte is set and data pointer is non-null, calls SessionConfigDefaultInit, frees three internal pointer fields (at offsets 0x0, 0x8, 0x14), then frees the data struct itself.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsShutdown (00431c70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | data struct field at offset 0 (first string pointer, freed if non-null) |
| obj | 0x8 | R | — | data struct field at offset 8 (second string pointer, freed if non-null) |
| obj | 0x14 | R | — | data struct field at offset 20 (third string pointer, freed if non-null) |
| this | 0x0 | R | — | node's data pointer (checked for non-null before operations) |
| this | 0x8 | R | — | node's flag byte (guards entire delete operation) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432cc0 | SessionConfigDefaultInit | reset/reset data struct fields to default state |
| 00587bcf | FreeWrapper_7bcf | free heap-allocated memory (field strings + data struct) |

**Guard conditions:** Flag byte at `this[8]` must be non-zero to proceed. Data pointer at `*(this)` must be non-null to enter destruction; if null, function returns the flag value immediately. Each of the three fields (0x0, 0x8, 0x14) within the data struct is individually checked for non-null before freeing.
