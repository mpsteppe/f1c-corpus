## CollisionSpeedSetter_00498720 — Physics/Collision Parameter Setter

**Summary:** Stores a global double value (dbl_8AFE90) into the float field at offset 0xC0, updating a collision or physics parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC0 | RW | — | Physics/collision parameter (likely speed or damping factor) |

**Written-by note (persistence):**
- this 0xC0: Overwritten unconditionally each call with global dbl_8AFE90; persists until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe90 | dbl_8AFE90 | R | Source value for the physics parameter (cooling rate or speed constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** (none — always executes)
