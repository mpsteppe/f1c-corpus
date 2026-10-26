## CollisionDetectionInit_0044e9c0 — CollisionInitBlockK

**Summary:** Initializes eleventh collision block (dword_7CCA54–7CCA68). Sets tag to 93, zeros control/audio fields, sets front camber static to 27000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cca54 | dword_7CCA54 | W | ControlBindingIndex [DERIVED] |
| 007cca58 | dword_7CCA58 | W | Zeroed collision state field |
| 007cca5c | dword_7CCA5C | W | Zeroed collision state field |
| 007cca60 | dword_7CCA60 | W | Zeroed collision state field |
| 007cca64 | dword_7CCA64 | W | AudioMixFloat [DERIVED] |
| 007cca68 | dword_7CCA68 | W | FrontCamberStatic [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
