## SessionConfigDefaultInit_00432cc0 — SessionConfigDefaultInit

**Summary:** Initializes a session configuration structure to defaults: copies the default application directory string three times via StringCopyWithBufferRealloc and sets the field at offset 0x10 to the literal value 7.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AutoLoadEntryListLoader (00432e70), PhysicsObjectDestructor (00433090), DualLinkedListCleanup (004331a0), AddVehicleConfigEntryToLinkedList (00433b60), PhysicsObjectDestructor_3e60 (00433e60), RecursiveNodeDeletion (00434240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 7 | Default session config flag/counter (initialized to 7) |

**Written-by note (persistence):**
- this 0x10: set to 7 every call. Always re-initialized; external poke overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies default directory string with buffer reallocation |

**Guard conditions:** None — unconditional initialization of all fields.
