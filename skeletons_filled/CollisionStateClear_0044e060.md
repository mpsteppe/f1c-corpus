## CollisionStateClear_0044e060 — clear collision state / set version

**Summary:** Sets collision version/magic to 68 and zeroes five reset fields to clear state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccd68 | dword_7CCD68 | W | CollisionMagicVersion [DERIVED] (also: ` — version/magic byte) |
| 007ccd6c | dword_7CCD6C | W | CollisionResetField2 [DERIVED] (also: ` through `_DAT_007ccd7c` — 5 reset fields) |
| 007ccd70 | dword_7CCD70 | W | unknown — zeroed reset field |
| 007ccd74 | dword_7CCD74 | W | unknown — zeroed reset field |
| 007ccd78 | dword_7CCD78 | W | unknown — zeroed reset field |
| 007ccd7c | dword_7CCD7C | W | CollisionResetFields [DERIVED] (also: ` — 5 reset fields) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — function always executes all writes unconditionally
