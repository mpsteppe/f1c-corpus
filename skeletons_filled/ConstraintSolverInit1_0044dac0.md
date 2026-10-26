## ConstraintSolverInit1_0044dac0 — InitializeConstraintCount45

**Summary:** Sets ConstraintCount to 45 and zeroes five adjacent constraint solver parameter fields. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cceb8 | dword_7CCEB8 | W | ConstraintCount [DERIVED] (also: ` — constraint count/size) |
| 007ccebc | dword_7CCEBC | W | Constraint solver field slot 2 (zeroed) |
| 007ccec0 | dword_7CCEC0 | W | Constraint solver field slot 3 (zeroed) |
| 007ccec4 | dword_7CCEC4 | W | Constraint solver field slot 4 (zeroed) |
| 007ccec8 | dword_7CCEC8 | W | Constraint solver field slot 5 (zeroed) |
| 007ccecc | dword_7CCECC | W | Constraint solver field slot 6 (zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional write of six globals.
