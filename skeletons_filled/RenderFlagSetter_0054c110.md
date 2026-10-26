## RenderFlagSetter_0054c110 — Render flag field selector

**Summary:** Selects between two render flag fields (0x800 or 0x1000) on a scene/render node, sets the corresponding field from an input value, and records the flag bit in a flags word at +0x3C. Part of the scene graph rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkMessageReceiveAndDispatch (004c7ca0), Steward_Init (004d38f0), VehicleGraphicsSceneLoader (004dfce0), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | RW | — | Accumulated render flag bits (ORed with 0x800 or 0x1000) |
| this | 0x234 | RW | — | Render value for flag 0x800 mode |
| this | 0x238 | RW | — | Render value for flag 0x1000 mode |

**Written-by note (persistence):**
- this 0x3C: ORed with 0x800 or 0x1000; survives until cleared externally
- this 0x234: written when flag 0x800 is set; survives until overwritten
- this 0x238: written when flag 0x1000 is set; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `a3 & 0x800` is nonzero, PASSES: sets this[141]=a2 and ORs 0x800 into this[15]. Else if `a3 & 0x1000` is nonzero, PASSES: sets this[142]=a2 and ORs 0x1000 into this[15]. If neither flag bit is set, BLOCKED: function returns a3 unchanged with no writes.
