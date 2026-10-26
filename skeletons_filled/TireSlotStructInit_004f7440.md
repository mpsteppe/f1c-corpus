## TireSlotStructInit_004f7440 — TireSlotStructInit

**Summary:** Initializes a tire-slot struct: copies default directory path via StringCopyWithBufferRealloc, sets slot IDs at offsets 8 and 12 to -1 (invalid/unused), and clears active flag at offset 16 to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F70C0 (004f70c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 18446744073709551615 | Tire slot identifier 1 (set to -1 = unused) |
| this | 0xC | RW | 18446744073709551615 | Tire slot identifier 2 (set to -1 = unused) |
| this | 0x10 | RW | 0 | Active/used flag (0 = inactive at init) |

**Written-by note (persistence):**
- this 0x8: Set once at init to -1; overwritten later when slot assigned
- this 0xC: Set once at init to -1; overwritten later when slot assigned
- this 0x10: Set once at init to 0; set to 1 when slot becomes active

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies string from default directory path to this struct |

**Guard conditions:** None.
