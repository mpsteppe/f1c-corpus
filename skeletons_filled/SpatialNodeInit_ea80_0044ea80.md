## SpatialNodeInit_ea80_0044ea80 — CollisionInitBlockM

**Summary:** Initializes thirteenth collision block (dword_7CA4E0–7CA4F4). Sets tag to 95, zeros node/wheel fields, sets max search distance to 9000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca4e0 | dword_7CA4E0 | W | NodeElementCount [DERIVED] |
| 007ca4e4 | dword_7CA4E4 | W | Zeroed spatial node field |
| 007ca4e8 | dword_7CA4E8 | W | Zeroed spatial node field |
| 007ca4ec | dword_7CA4EC | W | Zeroed spatial node field |
| 007ca4f0 | dword_7CA4F0 | W | WheelSettingCopy_7CA4F0 [DERIVED] |
| 007ca4f4 | dword_7CA4F4 | W | MaxSearchDistance [DERIVED] (also: ` — max search distance (9000) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
