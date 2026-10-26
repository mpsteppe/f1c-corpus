## WheelContactForceSolver_00443150 — WheelContactNormalForceSolver

**Summary:** Solves contact normal force for a wheel contact: transforms contact position to world space via body rotation matrix, computes slip-based force reduction using friction model (cubic falloff), and accumulates resulting angular momentum into the body. Part of wheel collision response system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** DamperSpringForceComputationWithAntiRoll (004432f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15F0 | R | — | pointer to rigid body state |
| this | 0x160C | R | — | body rotation matrix start (+28 from body state) |
| this | 0x1614 | R | — | body rotation matrix element |
| this | 0x161C | R | — | body rotation matrix element |
| this | 0x1624 | R | — | body rotation matrix element |
| this | 0x162C | R | — | body rotation matrix element |
| this | 0x1634 | R | — | body force accumulator X |
| this | 0x163C | R | — | body force accumulator Y |
| this | 0x1644 | R | — | body force accumulator Z |
| this | 0x164C | R | — | body torque accumulator X |
| this | 0x1654 | R | — | body torque accumulator Y |
| this | 0x165C | R | — | body torque accumulator Z |
| this | 0x1664 | R | — | body dynamics parameter |
| this | 0x166C | R | — | body dynamics parameter |
| this | 0x1674 | R | — | body dynamics parameter |
| this | 0x167C | R | — | body dynamics parameter |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | multiplies 3x3 rotation matrix by 3D vector |
| 004388d0 | Mat3x3MulVec | rotates force vector from local to world space |
| 00569ad0 | AccumulateAngularMomentum | accumulates angular momentum from contact force |

**Guard conditions:** if first byte of contact data (a2) is zero, skip entire function (contact inactive). If contact normal penetration depth (v6 = v18[2] - a3[2]) >= 0.0, skip force computation (no penetration).
