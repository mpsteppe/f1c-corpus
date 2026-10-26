## GlobalVariableZeroInit_00418db0 — GlobalStateVarsReset

**Summary:** Zeros four consecutive global dword variables (dword_5EBB18 through dword_5EBB24). Unconditional global state reset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ebb18 | dword_5EBB18 | W | ResetStateCounter0 [DERIVED] (also: ` — zeroed (unknown purpose) |
| 005ebb1c | dword_5EBB1C | W | ZeroedGlobal [DERIVED] (also: ` — zeroed) |
| 005ebb20 | dword_5EBB20 | W | ZeroedInitState [DERIVED] (also: ` — zeroed) |
| 005ebb24 | dword_5EBB24 | W | ZeroedFloat4 [DERIVED] (also: ` — zeroed) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional zeroing of all four globals.
