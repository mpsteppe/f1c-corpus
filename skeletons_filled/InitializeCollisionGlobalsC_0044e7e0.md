## InitializeCollisionGlobalsC_0044e7e0 — CollisionInitBlockF

**Summary:** Initializes sixth collision block (dword_7CD080–7CD094). Sets tag to 88, zeros render/state fields, sets audio shared gain to 18000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd080 | dword_7CD080 | W | Dword_Unknown_Render2 [DERIVED] |
| 007cd084 | dword_7CD084 | W | Zeroed collision state field |
| 007cd088 | dword_7CD088 | W | Zeroed collision state field |
| 007cd08c | dword_7CD08C | W | Zeroed collision state field |
| 007cd090 | dword_7CD090 | W | Zeroed collision state field |
| 007cd094 | dword_7CD094 | W | AudioEngine_SharedGain2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
