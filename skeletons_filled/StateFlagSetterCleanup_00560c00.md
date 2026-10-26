## StateFlagSetterCleanup_00560c00 — StateFlagSet2

**Summary:** Set state/flag field at this[9] to 2 and call empty stub. Called during 3D sound source destruction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundSourceDestructor (00545150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | 2 | State/flag field (set to 2) |

**Written-by note (persistence):**
- this 0x24: set to 2; may be read elsewhere as state indicator

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None
