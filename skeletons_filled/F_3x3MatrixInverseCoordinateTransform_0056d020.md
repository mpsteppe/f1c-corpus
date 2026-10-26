## F_3x3MatrixInverseCoordinateTransform_0056d020 — Matrix3x3InverseCoordinateTransform

**Summary:** Computes 3x3 inverse coordinate transform for vehicle physics. Transforms two vectors via Matrix3x3VectorMultiply, computes cross products and cofactor-based inverse matrix, then applies additional matrix-vector multiplies. Transforms forces/torques between coordinate frames (chassis-local to world).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210), SteeringGeometryUpdate (00442060), VehiclePhysicsJointSystemLoader (0056d930), BatchProcessingLoop3Passes (0056ec00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Pointer to 3x3 rotation matrix data block (matrix at +28 inside block) |
| this | 0x8 | R | — | Pointer to workspace buffer (input vectors at +24/+48, transform results at +72/+96) |
| this | 0xC | R | — | Pointer to second matrix data block (for inverse/cofactor computation) |
| this | 0x10 | R | — | Pointer to result buffer (holds inverse matrix rows, cross products, final vectors) |
| this | 0x18 | R | — | Header/padding within pointed-to data block before matrix doubles |
| this | 0x20 | R | — | Header/padding within pointed-to data block before matrix doubles |
| this | 0x28 | RW | — | Result buffer — first vector component or matrix row element |
| this | 0x30 | RW | — | Result buffer — second vector component or matrix row element |
| this | 0x38 | RW | — | Result buffer — third vector component or matrix row element |
| this | 0x40 | RW | — | Result buffer — fourth vector component or matrix row element |
| this | 0x48 | RW | — | Result buffer — fifth vector component or matrix row element |
| this | 0x50 | RW | — | Result buffer — sixth vector component or matrix row element |
| this | 0x58 | RW | — | Result buffer — cross product Z component |
| this | 0x60 | RW | — | Result buffer — cross product Y component |
| this | 0x68 | RW | — | Result buffer — cross product X component |
| this | 0x70 | RW | — | Result buffer — inverse matrix row 2 element |
| this | 0x78 | RW | — | Result buffer — inverse matrix row 1 element |
| this | 0x80 | RW | — | Result buffer — inverse matrix row 0 element |

**Written-by note (persistence):**
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x70: recalc every frame — external poke does NOT persist
- this 0x78: recalc every frame — external poke does NOT persist
- this 0x80: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | Multiply 3x3 matrix by 3-component vector; called twice to transform two input vectors |

**Guard conditions:** none — no conditional branches; always computes full transform.
