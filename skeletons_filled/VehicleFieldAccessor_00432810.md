## VehicleFieldAccessor_00432810 — VehicleFieldAt2CAccessor

**Summary:** Simple accessor that dereferences `this` as a pointer, then reads the DWORD at offset 0x2C from the target. Returns the vehicle identifier or configuration field at that offset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HTMLSeasonOutput (0046ee60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | Vehicle struct field at offset 0x2C (identifier or configuration value) |
| this | 0x0 | R | — | Pointer to vehicle struct (first field of this object) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional dereference and field read. Assumes this->field0 is a valid pointer.
