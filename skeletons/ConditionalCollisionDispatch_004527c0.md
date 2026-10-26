## ConditionalCollisionDispatch_004527c0 — Conditional collision property dispatch

**Summary:** If the guard field at offset 0x0 is zero, calls CollisionNodePropertySetter with the two property values at offsets 0x4 and 0x8. Otherwise returns 0 (no-op). Called from camera viewport configuration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewportConfigBatch (00453560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Guard/flag field — property setter called only when 0 |
| this | 0x4 | R | — | First parameter for CollisionNodePropertySetter |
| this | 0x8 | R | — | Second parameter for CollisionNodePropertySetter |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca594 | byte_7CA594 | R | WheelBrakeBiasThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f050 | CollisionNodePropertySetter | Applies collision node property with guard and two parameters |

**Guard conditions:** BLOCKED if this[0] is non-zero → skip property setter, return 0. PASSES (dispatches setter) only when this[0] == 0.
