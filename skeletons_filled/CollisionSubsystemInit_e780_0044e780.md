## CollisionSubsystemInit_e780_0044e780 — CollisionInitBlockE

**Summary:** Initializes fifth collision block (dword_7CCFEC–7CD000). Sets tag to 87, zeros grid ptr/effect fields, sets render state to 9000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccfec | dword_7CCFEC | W | CollisionGridDataPtr [DERIVED] |
| 007ccff0 | dword_7CCFF0 | W | Zeroed collision state field |
| 007ccff4 | dword_7CCFF4 | W | Zeroed collision state field |
| 007ccff8 | dword_7CCFF8 | W | Zeroed collision state field |
| 007ccffc | dword_7CCFFC | W | CameraEffectOffset2 [DERIVED] |
| 007cd000 | dword_7CD000 | W | RenderState_7CD000 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
