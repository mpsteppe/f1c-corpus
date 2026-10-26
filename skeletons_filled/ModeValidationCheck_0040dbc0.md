## ModeValidationCheck_0040dbc0 — ModeValidationCheck

**Summary:** Returns TRUE if the current mode (this+0x0) equals 3 or 4, FALSE otherwise. Acts as a gate to allow processing only in specific modes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | mode/state field, checked against 3 and 4 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 3 | valid mode value (replay or cinematic) |
| this | 0x0 | == | 4 | valid mode value (replay or cinematic) |

**Guard interpretation:** PASSES (returns TRUE) if this+0x0 == 3 OR this+0x0 == 4. BLOCKED (returns FALSE) for any other value.
