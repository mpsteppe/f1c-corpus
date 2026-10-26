## SuspensionSpringDamperForceComputationWithClampi_00435e60 — Suspension spring-damper force with clamping

**Summary:** Computes suspension spring-damper force and torque for a wheel assembly, with min/max clamping on all axes. Transforms forces from suspension local frame to chassis frame and applies scaling/clamping. Part of vehicle suspension physics.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GetBodyMotionState (00447100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Pointer to chassis body data (null check) |
| this | 0x4 | R | — | Suspension attach point offset X in chassis frame |
| this | 0xC | R | — | Suspension attach point offset Y in chassis frame |
| this | 0x14 | R | — | Suspension attach point offset Z in chassis frame |
| this | 0x1C | R | — | Min clamp value for suspension force X |
| this | 0x24 | R | — | Min clamp value for suspension force Y |
| this | 0x2C | R | — | Min clamp value for suspension force Z |
| this | 0x34 | R | — | Max clamp value for suspension force X |
| this | 0x3C | R | — | Max clamp value for suspension force Y |
| this | 0x44 | R | — | Max clamp value for suspension force Z |
| this | 0x64 | R | — | Min clamp value for output torque X |
| this | 0x68 | R | — | (hi dword of torque limit double) |
| this | 0x6C | R | — | Min clamp value for output torque Y |
| this | 0x74 | R | — | Min clamp value for output torque Z |
| this | 0x7C | R | — | Max clamp value for output torque X |
| this | 0x80 | R | — | (hi dword of torque limit double) |
| this | 0x84 | R | — | Max clamp value for output torque Y |
| this | 0x8C | R | — | Max clamp value for output torque Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 007cfb48 | flt_7CFB48 | R | CollisionForceClampFactor [DERIVED] |
| 007cfb6c | flt_7CFB6C | R | Flt_PhysicsClamp [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004361d0 | F_3DVectorTransformBy33Matrix | Transforms suspension force vector from local to chassis frame |
| 0056c740 | F_33MatrixMultiply | Multiplies orientation matrices for coordinate frame conversion |
| 00588570 | FloatConvertWrapper | Converts float to double or double to float for clamp factor |

**Guard conditions:** If this->bodyPointer (offset 0x0) is null, zero out output force (a3) and torque (a4) arrays and return immediately.
