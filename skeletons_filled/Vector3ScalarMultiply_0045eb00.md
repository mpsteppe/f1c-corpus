## Vector3ScalarMultiply_0045eb00 — Vector3ScalarMultiply

**Summary:** Multiplies a 3-component vector by a scalar: computes this * a3 for each of three float components and stores result in output vector a2. Simple 3D vector scale operation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep_e620 (0045e620), VehicleContactForceAccumulation (004ebc60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Input vector X component |
| this | 0x4 | R | — | Input vector Y component |
| this | 0x8 | R | — | Input vector Z component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — always computes and stores all three components.
