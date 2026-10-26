## SetPhysicsStateFieldToZero_005593c6 — SetPhysicsStateFieldToZero

**Summary:** Zero the dword at offset 0x1C. Parameters a2 and a3 are unused.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | 0 | State/counter field, unconditionally zeroed |

**Written-by note (persistence):**
- this 0x1C: Written unconditionally to 0 each call; external pokes between calls survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None (unconditional write).
