## RelativeVelocityCompute_0056d1c0 — RelativeVelocityCompute

**Summary:** Computes relative velocity magnitude between two points/objects in vehicle physics. Transforms each local velocity through its 3x3 rotation matrix + translation to world space, then computes Euclidean distance (sqrt of squared differences). Result stored at two output locations.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210), ConstraintForceSolver (0043ba20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Pointer to transform data for body A (3x3 rotation matrix at +28, translation at +4) |
| this | 0x8 | R | — | Pointer to body A local velocity vector (3 doubles) |
| this | 0xC | R | — | Pointer to transform data for body B |
| this | 0x10 | R | — | Pointer to body B local velocity vector (3 doubles) |
| this | 0x18 | R | — | Padding/header in body A transform block before matrix |
| this | 0x20 | R | — | Padding/header in body A transform block before matrix |
| this | 0x28 | R | — | Body A rotation matrix element [0][0] |
| this | 0x30 | R | — | Body A rotation matrix element [0][1] |
| this | 0x38 | R | — | Body A rotation matrix element [0][2] |
| this | 0x40 | RW | — | Relative velocity magnitude written to v2[7] (body A velocity buffer +56) |
| this | 0x48 | RW | — | Relative velocity magnitude also written to result+56 (body B velocity buffer +56) |
| this | 0x50 | R | — | Body A rotation matrix element [1][0] |
| this | 0x58 | R | — | Body A rotation matrix element [1][1] |
| this | 0x60 | R | — | Body A rotation matrix element [1][2] |
| this | 0x68 | R | — | Body A rotation matrix element [2][0] |

**Written-by note (persistence):**
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no conditional branches; always computes relative velocity.
