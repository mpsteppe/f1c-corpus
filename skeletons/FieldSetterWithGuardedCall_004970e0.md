## FieldSetterWithGuardedCall_004970e0 — SetFieldAndConditionallyDispatchRender

**Summary:** Stores parameter to field at 0x1918. If guard field at 0x30 is non-zero, calls RenderDispatchWithIteration. Returns either the stored parameter or the render dispatch result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F9480 (004f9480)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R | — | Guard flag — when non-zero enables render dispatch call |
| this | 0x1918 | RW | — | Stores incoming parameter a2 |

**Written-by note (persistence):**
- this 0x1918: Written unconditionally each call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004993d0 | RenderDispatchWithIteration | Called when guard flag enabled; triggers render iteration |

**Guard conditions:** Field at this+0x30 (this[12]) — non-zero PASSES (calls RenderDispatchWithIteration), zero BLOCKS (skips call, returns stored param directly).
