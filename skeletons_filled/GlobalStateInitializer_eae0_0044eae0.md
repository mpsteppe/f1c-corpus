## GlobalStateInitializer_eae0_0044eae0 — CollisionInitBlockN

**Summary:** Initializes fourteenth collision block (dword_7CA54C–7CA560). Sets tag to 96, zeros sound/state fields, sets throttle pedal range to 18000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca54c | dword_7CA54C | W | CollisionConfigId_7CA54C [DERIVED] |
| 007ca550 | dword_7CA550 | W | Zeroed global state field |
| 007ca554 | dword_7CA554 | W | Zeroed global state field |
| 007ca558 | dword_7CA558 | W | Zeroed global state field |
| 007ca55c | dword_7CA55C | W | SoundBank_VolumeFL_Alt [DERIVED] |
| 007ca560 | dword_7CA560 | W | ThrottlePedalRange [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
