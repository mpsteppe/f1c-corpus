## ConstraintProjectGramSchmidt_00438930 — Constraint direction Gram-Schmidt orthogonalization

**Summary:** Performs Gram-Schmidt orthogonalization on constraint direction vectors. Computes the dot product between a reference direction and another vector, then subtracts the projected component to produce an orthogonal constraint basis. Part of the constraint solver setup.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionWheelDynamicsSolver (0043f7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15C | R | — | Pointer to constraint data (via this[87]) |
| this | 0x178 | R | — | Constraint direction vector component |
| this | 0x190 | R | — | Constraint direction vector component |
| this | 0x1A8 | R | — | Constraint direction vector component |
| this | 0x2A8 | RW | — | Orthogonalized constraint basis vector component (written) |
| this | 0x2B0 | RW | — | Orthogonalized constraint basis vector component (written) |
| this | 0x2B8 | RW | — | Orthogonalized constraint basis vector component (written) |

**Written-by note (persistence):**
- this 0x2A8: recalc every frame — external poke does NOT persist
- this 0x2B0: recalc every frame — external poke does NOT persist
- this 0x2B8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes.
