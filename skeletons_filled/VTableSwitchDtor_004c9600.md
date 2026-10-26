## VTableSwitchDtor_004c9600 — VTableSwitchDtor

**Summary:** Destructor with vtable switching: sets to destructor vtable (off_5ACE5C), calls VtableDestructorNull body, restores original vtable (off_5ACE2C), optionally frees memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (switched during destruction) |

**Written-by note (persistence):**
- this 0x0: Set to off_5ACE5C then off_5ACE2C during destruction; no persistence after free

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ace2c | off_5ACE2C | R | VTableRef_5ACE2C [DERIVED] |
| 005ace5c | off_5ACE5C | R | SoundObjVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c9790 | VtableDestructorNull | Destructor body for this object type |
| 00587bcf | FreeWrapper_7bcf | Frees heap memory if a2 & 1 (final release) |

**Guard conditions:** a2 & 1 gates the FreeWrapper_7bcf call (free only on final release).
