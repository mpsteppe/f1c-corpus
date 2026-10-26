## VehicleSpeedAccessor_004b9cc0 — Speed read accessor

**Summary:** Reads a float speed value from a nested pointer chain (this->ptr->field at offset 0xF34). Returns as double.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF34 | R | — | Vehicle speed value (float, e.g. m/s) |
| this | 0x0 | R | — | Pointer to vehicle dynamics data struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None (unconditional dereference — always reads)
