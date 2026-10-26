## InertiaTensorWorldSpaceTransform_00569410 — ComputeAngularAccelerationFromTorque

**Summary:** Computes world-space angular acceleration from torque using rotation matrix and diagonal inverse inertia: alpha = R * I_body^(-1) * R^T * torque. Reads torque vector (0x7C/0x84/0x8C), rotation matrix (0x1C-0x5C), and inertia reciprocals (0xBC/0xC4/0xCC); writes angular acceleration result (0x94/0x9C/0xA4).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionDataCopyToPhysicsEngine (004389b0), VehiclePhysicsIntegrationStep (00441650), sub_447780 (00447780), sub_568E70 (00568e70), Copy6DwordsToStructCall (00569280), StructCopyWithReciprocalDivision (005697a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | rotation matrix row 0 col 0 |
| this | 0x24 | R | — | rotation matrix row 0 col 1 |
| this | 0x2C | R | — | rotation matrix row 0 col 2 |
| this | 0x34 | R | — | rotation matrix row 1 col 0 |
| this | 0x3C | R | — | rotation matrix row 1 col 1 |
| this | 0x44 | R | — | rotation matrix row 1 col 2 |
| this | 0x4C | R | — | rotation matrix row 2 col 0 |
| this | 0x54 | R | — | rotation matrix row 2 col 1 |
| this | 0x5C | R | — | rotation matrix row 2 col 2 |
| this | 0x7C | R | — | input torque X component |
| this | 0x84 | R | — | input torque Y component |
| this | 0x8C | R | — | input torque Z component |
| this | 0x94 | RW | — | output angular acceleration X component |
| this | 0x9C | RW | — | output angular acceleration Y component |
| this | 0xA4 | RW | — | output angular acceleration Z component |
| this | 0xBC | R | — | reciprocal of inertia diagonal X (1/Ixx) |
| this | 0xC4 | R | — | reciprocal of inertia diagonal Y (1/Iyy) |
| this | 0xCC | R | — | reciprocal of inertia diagonal Z (1/Izz) |

**Written-by note (persistence):**
- this 0x94: recalc every frame — external poke does NOT persist
- this 0x9C: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional computation, no branches or early returns.
