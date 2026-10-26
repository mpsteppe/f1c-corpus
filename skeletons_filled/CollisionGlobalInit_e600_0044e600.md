## CollisionGlobalInit_e600_0044e600 — CollisionGlobalsInitBlockB

**Summary:** Initializes second block of collision globals (dword_7CCA2C–7CCA40). Sets system block tag to 83, zeros state fields, sets max distance to 9000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cca2c | dword_7CCA2C | W | CollisionContactCount [DERIVED] |
| 007cca30 | dword_7CCA30 | W | Zeroed collision state field |
| 007cca34 | dword_7CCA34 | W | Zeroed collision state field |
| 007cca38 | dword_7CCA38 | W | Zeroed collision state field |
| 007cca3c | dword_7CCA3C | W | ControlStateStore [DERIVED] |
| 007cca40 | dword_7CCA40 | W | CollisionMaxDistance [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
