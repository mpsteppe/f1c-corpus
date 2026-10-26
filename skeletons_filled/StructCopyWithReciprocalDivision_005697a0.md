## StructCopyWithReciprocalDivision_005697a0 — CopyInertiaDiagonalsAndReciprocals

**Summary:** Copies 3 inertia tensor diagonal components (3 doubles) from a2 to offset 0xBC, computes their reciprocals at offsets 0xD4/0xDC/0xE4, then calls InertiaTensorWorldSpaceTransform to update world-space inertia.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionSetupSectionReader (00435410), PhysicsCollisionDamageDNFDetection (00438690), VehiclePhysicsInitializer (00439210), sub_43C250 (0043c250), CollisionInvMassStore (00459950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD4 | RW | — | reciprocal of inertia X (1.0 / a2[0]) |
| this | 0xDC | RW | — | reciprocal of inertia Y (1.0 / a2[1]) |
| this | 0xE4 | RW | — | reciprocal of inertia Z (1.0 / a2[2]) |

**Written-by note (persistence):**
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist
- this 0xE4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00569410 | InertiaTensorWorldSpaceTransform | transforms inertia to world space after updating diagonal values |

**Guard conditions:** None — unconditional copy, reciprocal computation, and call.
