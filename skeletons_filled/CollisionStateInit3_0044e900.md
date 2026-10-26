## CollisionStateInit3_0044e900 — CollisionInitBlockI

**Summary:** Initializes ninth collision block (dword_7CA564–7CA578). Sets tag to 91, zeros audio/vehicle fields, sets render state to 9000.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca564 | dword_7CA564 | W | AudioBufferPointer [DERIVED] |
| 007ca568 | dword_7CA568 | W | Zeroed collision state field |
| 007ca56c | dword_7CA56C | W | Zeroed collision state field |
| 007ca570 | dword_7CA570 | W | Zeroed collision state field |
| 007ca574 | dword_7CA574 | W | VehicleSetupFloat_7CA574 [DERIVED] |
| 007ca578 | dword_7CA578 | W | RenderState_A578 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional init, no branches.
