## F_3x3MatrixTransform_004e23d0 — Transform3x3WithTranslation

**Summary:** Applies 3x3 rotation matrix and translation to a 3D vector. Stores rotation angles, rotation matrix, input vector, and transformed result in output struct. Part of physics/transform system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), SuspensionStateUpdate (004e9600), VehicleTelemetryPositionAccumulator (004ec080), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Result position X (transformed) |
| this | 0xC | RW | — | Result position Y (transformed) |
| this | 0x10 | RW | — | Result position Z (transformed) |
| this | 0x14 | RW | — | Rotation angle X (from a3) |
| this | 0x18 | RW | — | Rotation angle Y (from a3) |
| this | 0x1C | RW | — | Rotation angle Z (from a3) |
| this | 0x20 | R | — | Rotation matrix row 0 col 0 |
| this | 0x24 | R | — | Rotation matrix row 0 col 1 |
| this | 0x28 | R | — | Rotation matrix row 0 col 2 |
| this | 0x2C | R | — | Rotation matrix row 1 col 0 |
| this | 0x30 | R | — | Rotation matrix row 1 col 1 |
| this | 0x34 | R | — | Rotation matrix row 1 col 2 |
| this | 0x38 | R | — | Rotation matrix row 2 col 0 |
| this | 0x3C | R | — | Rotation matrix row 2 col 1 |
| this | 0x40 | R | — | Rotation matrix row 2 col 2 |
| this | 0x48 | R | — | Input vector X being transformed |
| this | 0x4C | R | — | Input vector Y being transformed |
| this | 0x50 | R | — | Input vector Z being transformed |
| this | 0x54 | RW | — | Stored translation X (from a2) |
| this | 0x58 | RW | — | Stored translation Y (from a2) |
| this | 0x5C | RW | — | Stored translation Z (from a2) |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x5C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always copies rotation angles and matrix, then computes and stores transformed position.
