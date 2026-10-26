## ChassisWorldTransform_004e2130 — ChassisWorldTransform

**Summary:** Transforms 3D point by chassis rotation matrix (this+0x14, component scale at this[584]) and adds chassis position offset (this+0x918). Outputs transformed point to a2 and copies rotation quaternion to a3. Camera tracking transform for vehicle chassis.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraModeViewportUpdate (00409a00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | chassis rotation matrix row 0 element 0 |
| this | 0x18 | R | — | chassis rotation matrix row 0 element 1 |
| this | 0x1C | R | — | chassis rotation matrix row 0 element 2 |
| this | 0x20 | R | — | chassis rotation matrix row 1 element 0 |
| this | 0x24 | R | — | chassis rotation matrix row 1 element 1 |
| this | 0x28 | R | — | chassis rotation matrix row 1 element 2 |
| this | 0x2C | R | — | chassis rotation matrix row 2 element 0 |
| this | 0x30 | R | — | chassis rotation matrix row 2 element 1 |
| this | 0x34 | R | — | chassis rotation matrix row 2 element 2 |
| this | 0x38 | R | — | chassis rotation quaternion x |
| this | 0x3C | R | — | chassis rotation quaternion y |
| this | 0x40 | R | — | chassis rotation quaternion z |
| this | 0x918 | R | — | chassis position offset X |
| this | 0x91C | R | — | chassis position offset Y |
| this | 0x920 | R | — | chassis position offset Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — full transform always applied.
