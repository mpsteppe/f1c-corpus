## sub_50FDB0_0050fdb0 — Vehicle Physics Transform Update

**Summary:** Updates a vehicle's 3D orientation and physics state from a transform matrix. Computes position, rotation angles (via asin/atan2), velocity vectors, wheel positions, and suspension/damper state using the global vehicle transform at dword_760144.

**Called by:** sub_50FD30 (0050fd30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x444C | R | — | Transform matrix element (row 0, col 0) |
| this | 0x4450 | R | — | Transform matrix element (row 0, col 1) |
| this | 0x4454 | R | — | Transform matrix element (row 0, col 2) |
| this | 0x4458 | R | — | Transform matrix element (row 1, col 0) |
| this | 0x445C | R | — | Transform matrix element (row 1, col 1) |
| this | 0x4460 | R | — | Transform matrix element (row 1, col 2) |
| this | 0x4464 | R | — | Transform matrix element (row 2, col 0) |
| this | 0x4468 | R | — | Transform matrix element (row 2, col 1) |
| this | 0x446C | R | — | Transform matrix element (row 2, col 2) |
| this | 0x4470 | RW | — | Vehicle position X |
| this | 0x4474 | RW | — | Vehicle position Y |
| this | 0x4478 | RW | — | Vehicle position Z |
| this | 0x447C | RW | — | Orientation matrix element [0][0] |
| this | 0x4480 | RW | — | Orientation matrix element [0][1] |
| this | 0x4484 | RW | 0 | Orientation matrix element [0][2] |
| this | 0x4488 | RW | — | Orientation matrix element [1][0] |
| this | 0x448C | RW | — | Orientation matrix element [1][1] |
| this | 0x4490 | RW | — | Orientation matrix element [1][2] |
| this | 0x4494 | RW | — | Orientation matrix element [2][0] |
| this | 0x4498 | RW | — | Orientation matrix element [2][1] |
| this | 0x449C | RW | — | Orientation matrix element [2][2] |
| this | 0x44A0 | RW | — | Yaw angle (atan2 result) |
| this | 0x44A4 | RW | — | Pitch angle (asin result) |
| this | 0x44A8 | RW | — | Roll angle (atan2 result) |
| this | 0x44AC | R | — | Some vehicle dimension |
| this | 0x44B0 | RW | — | Direction vector X (normalized) |
| this | 0x44B4 | RW | — | Direction vector Y (normalized) |
| this | 0x44D0 | RW | — | Direction vector Z (normalized) |
| this | 0x44D4 | RW | — | Velocity projection X |
| this | 0x44D8 | RW | — | Velocity projection Y |
| this | 0x44DC | RW | — | Velocity projection Z |
| this | 0x44E0 | RW | — | Lateral velocity X |
| this | 0x44E4 | RW | — | Lateral velocity Y |
| this | 0x450C | RW | — | Lateral velocity Z |
| this | 0x4510 | RW | — | World-space center offset X |
| this | 0x4514 | RW | — | World-space center offset Y |
| this | 0x454C | R | — | World-space center offset Z |
| this | 0x4644 | R | — | Wheel 0 position X |
| this | 0x473C | R | — | Wheel 1 position X |
| this | 0x4834 | R | — | Wheel 2 position X |
| this | 0x4900 | RW | — | Wheel 3 position X |
| this | 0x4914 | RW | — | Wheel radii array element |
| this | 0x4930 | RW | — | Wheel/suspension travel |
| this | 0x4950 | R | — | Wheel count/index |
| this | 0x498C | RW | — | Suspension spring rate array |
| this | 0x4CF0 | RW | — | Rear axle position X |
| this | 0x4CF4 | RW | — | Rear axle position Y |
| this | 0x4CF8 | RW | — | Rear axle position Z |
| this | 0x4D0C | RW | 18446744072627421184 → -1.0f | Suspension init sentinel value |

**Written-by note (persistence):**
- this 0x4470: recalculated every physics frame from transform; external poke overwritten next frame
- this 0x4474: recalculated every physics frame; external poke overwritten next frame
- this 0x4478: recalculated every physics frame; external poke overwritten next frame
- this 0x447C: recalculated every physics frame; external poke overwritten next frame
- this 0x4480: recalculated every physics frame; external poke overwritten next frame
- this 0x4484: recalculated every physics frame; external poke overwritten next frame
- this 0x4488: recalculated every physics frame; external poke overwritten next frame
- this 0x448C: recalculated every physics frame; external poke overwritten next frame
- this 0x4490: recalculated every physics frame; external poke overwritten next frame
- this 0x4494: recalculated every physics frame; external poke overwritten next frame
- this 0x4498: recalculated every physics frame; external poke overwritten next frame
- this 0x449C: recalculated every physics frame; external poke overwritten next frame
- this 0x44A0: recalculated every physics frame; external poke overwritten next frame
- this 0x44A4: recalculated every physics frame; external poke overwritten next frame
- this 0x44A8: recalculated every physics frame; external poke overwritten next frame
- this 0x44B0: recalculated every physics frame; external poke overwritten next frame
- this 0x44B4: recalculated every physics frame; external poke overwritten next frame
- this 0x44D0: recalculated every physics frame; external poke overwritten next frame
- this 0x44D4: recalculated every physics frame; external poke overwritten next frame
- this 0x44D8: recalculated every physics frame; external poke overwritten next frame
- this 0x44DC: recalculated every physics frame; external poke overwritten next frame
- this 0x44E0: recalculated every physics frame; external poke overwritten next frame
- this 0x44E4: recalculated every physics frame; external poke overwritten next frame
- this 0x450C: recalculated every physics frame; external poke overwritten next frame
- this 0x4510: recalculated every physics frame; external poke overwritten next frame
- this 0x4514: recalculated every physics frame; external poke overwritten next frame
- this 0x4900: recalculated every physics frame; external poke overwritten next frame
- this 0x4914: recalculated every physics frame; external poke overwritten next frame
- this 0x4930: recalculated every physics frame; external poke overwritten next frame
- this 0x498C: recalculated every physics frame; external poke overwritten next frame
- this 0x4CF0: recalculated every physics frame; external poke overwritten next frame
- this 0x4CF4: recalculated every physics frame; external poke overwritten next frame
- this 0x4CF8: recalculated every physics frame; external poke overwritten next frame
- this 0x4D0C: set once with -1.0f sentinel; may survive if not re-entered

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54c0 | dbl_5D54C0 | R | Physics constant (0.726) |
| 005d54d0 | dbl_5D54D0 | R | Physics constant |
| 005d54dc | flt_5D54DC | R | Delta time |
| 005d54e0 | flt_5D54E0 | R | Physics constant |
| 005d54f0 | flt_5D54F0 | R | Physics constant |
| 005d54f8 | flt_5D54F8 | R | Physics constant |
| 005eaa74 | flt_5EAA74 | R | Threshold constant |
| 0075e930 | dbl_75E930 | R | Vehicle mass/inertia parameter |
| 0075e938 | dbl_75E938 | R | Speed scalar |
| 0075e940 | dbl_75E940 | R | Speed scalar 2 |
| 0075e9a8 | dbl_75E9A8 | R | Acceleration constant |
| 0075eadc | dbl_75EADC | R | Gear ratio constant |
| 0075ee68 | unk_75EE68 | R | Wheel transform data array |
| 00760144 | dword_760144 | R | Base pointer to vehicle transform matrix |
| 00760150 | dbl_760150 | R | Transform translation vector element |
| 00760830 | dbl_760830 | R | Suspension travel input |
| 007608c8 | dbl_7608C8 | R | Suspension travel max |
| 00760988 | dbl_760988 | R | Suspension state flag |
| 007609b8 | dbl_7609B8 | R | Suspension parameter X |
| 007609c0 | dbl_7609C0 | R | Suspension parameter Y |
| 007609c8 | dbl_7609C8 | R | Suspension parameter Z |
| 00760acc | dword_760ACC | R | Wheel count/layout flag |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043d900 | TransformApply3D [exact] | Apply 4x4 transform to position vector |
| 005c05d0 | __CIasin | Compute asin for pitch angle from matrix |

**Guard conditions:** No branching guards; pure linear computation per physics frame. The only conditional is the `fabs == 1.0` check for gimbal lock case where pitch is ±90° (uses alternate atan2 formula).
