## ConstraintEnforce_004380b0 — Constraint enforcement evaluation

**Summary:** Computes constraint displacement and velocity error, then evaluates the piecewise constraint response function. Stores the resulting constraint force. Part of the constraint solver feedback loop.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_442C90 (00442c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E8 | RW | — | Computed position error (displacement) |
| this | 0x1F0 | RW | — | Computed velocity error |
| this | 0x1F8 | R | — | Reference/rest position for error computation |

**Written-by note (persistence):**
- this 0x1E8: recalc every frame — external poke does NOT persist
- this 0x1F0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00436610 | PiecewiseFunctionEval | Evaluates constraint force from position and velocity errors |

**Guard conditions:** None — always executes.
