## CallFlagSet_00479ed0 — Flag clear at 0x100 to 0

**Summary:** Calls Return0Stub (no-op), sets byte flag at offset 0x100 to 0, returns 0. Inverse of FlagSetInit_00479eb0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x100 | RW | 0 | boolean/enable flag; cleared to 0 (inactive) |

**Written-by note (persistence):**
- this 0x100: written once to 0; may be toggled externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047abb0 | Return0Stub | stub function called before flag clear; likely no-op |

**Guard conditions:** none — unconditional straight-line init
