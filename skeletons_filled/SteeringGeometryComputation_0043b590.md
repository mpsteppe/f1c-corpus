## SteeringGeometryComputation_0043b590 — Steering Geometry / Ackermann Computation

**Summary:** Computes steering geometry for both front wheels: looks up suspension bar positions from named config strings, transforms them through the vehicle's rotation matrix, calculates steering offsets using trig (sin, sqrt, cross-product), and derives left/right Ackermann steering angles. Part of vehicle physics per-frame pipeline.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1630) | 0x0 | R | — | left suspension data element 0 (float, from lookup pointer) |
| *(this+0x1630) | 0x4 | R | — | left suspension data element 1 (float, from lookup pointer) |
| *(this+0x1644) | 0x0 | R | — | right suspension data element 0 (float, from lookup pointer) |
| *(this+0x1644) | 0x4 | R | — | right suspension data element 1 (float, from lookup pointer) |
| this | 0x84 | RW | 0 | steering reciprocal factor (1/angle or 0 if angle <= 0) |
| this | 0x88 | RW | 0 | steering reciprocal factor (second component) |
| this | 0x8C | RW | 0 | steering ratio factor (angle ratio or 0) |
| this | 0x90 | RW | 0 | steering ratio factor (second component) |
| this | 0x94 | RW | — | half-angle offset (angle * -0.5) for further steering computation |
| this | 0xA4 | RW | 0 | steering zero-init (wheel offset) |
| this | 0xA8 | RW | 0 | steering zero-init (wheel offset) |
| this | 0x3EC | R | — | suspension bar lookup ID for left front steering (FlSteering) |
| this | 0x850 | R | — | suspension bar lookup ID for right front steering (FrSteering) |
| this | 0x15F0 | R | — | pointer to steering geometry matrix data block (contains rotation matrix at +4, position at +28) |
| this | 0x1630 | R | — | pointer to left steering suspension data (dereferenced for 2 floats) |
| this | 0x1634 | RW | — | copied left suspension value 0 (from *(*this+0x1630)) |
| this | 0x1638 | RW | — | copied left suspension value 1 (from *(*this+0x1630)[1]) |
| this | 0x163C | RW | — | left front steering offset (computed signed distance from suspension geometry, negated) |
| this | 0x1644 | R | — | pointer to right steering suspension data (dereferenced for 2 floats) |
| this | 0x1648 | RW | — | copied right suspension value 0 (from *(*this+0x1644)) |
| this | 0x164C | RW | — | copied right suspension value 1 (from *(*this+0x1644)[1]) |
| this | 0x1650 | RW | — | right front steering offset (computed signed distance from suspension geometry, negated) |

**Written-by note (persistence):**
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x88: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist
- this 0x90: recalc every frame — external poke does NOT persist
- this 0x94: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0x1634: recalc every frame — external poke does NOT persist
- this 0x1638: recalc every frame — external poke does NOT persist
- this 0x163C: recalc every frame — external poke does NOT persist
- this 0x1648: recalc every frame — external poke does NOT persist
- this 0x164C: recalc every frame — external poke does NOT persist
- this 0x1650: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e428 | dbl_59E428 | R | NaNInvalidSentinel [DERIVED] (also: NaN sentinel constant) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ec10 | dbl_59EC10 | R | DoublePhysicsZero [DERIVED] |
| 005c41bc | aFrSteering | R | ParamName_FrSteering [DERIVED] |
| 005c41c8 | aFlSteering | R | StrFLSteering [DERIVED] |
| 005c42b4 | aFrForeLower | R | String_FrForeLower [DERIVED] |
| 005c42c4 | aFrForeUpper | R | FrForeUpperString [DERIVED] |
| 005c42d4 | aFlForeLower | R | FlForeLowerString [DERIVED] |
| 005c42e4 | aFlForeUpper | R | FlForeUpperString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004361d0 | F_3DVectorTransformBy33Matrix | transforms a 3D vector by a 3×3 rotation matrix (used to rotate suspension points into world space) |
| 0043af50 | SuspensionBarLookup | looks up suspension bar position by string name from vehicle config data, returns 3D vector (x,y,z) |

**Guard conditions:** Steering angle from a2+5188 * a2+5176 + a2+5168: if <= 0, sets reciprocals at this+0x84/0x88 to 0. Ratio denominator (a2+5184-1 scaled): if <= 0, sets ratio at this+0x8C/0x90 to 0. No other guard — always computes both left and right steering offsets via cross-product math with the normalized upper-to-lower suspension bar direction vector.