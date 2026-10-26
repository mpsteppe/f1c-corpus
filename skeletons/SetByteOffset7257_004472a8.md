## SetByteOffset7257_004472a8 — Byte flag clear at offset 0x1C59

**Summary:** Clears a single byte flag at this[7257] (offset 0x1C59) to zero. Minimal state reset within a larger physics/vehicle object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C59 | RW | 0 | single-byte flag/boolean reset to 0 |

**Written-by note (persistence):**
- this 0x1C59: unconditional — external poke overwritten every call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — single unconditional byte write, no branches.
