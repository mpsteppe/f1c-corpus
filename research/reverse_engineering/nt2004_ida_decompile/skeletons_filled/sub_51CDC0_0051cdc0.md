## sub_51CDC0_0051cdc0 — VehicleTickUpdate

**Summary:** Per-frame vehicle tick update dispatching on physics mode (0-3). Modes 0/2 compute position from velocity and rotation matrix, update 4-wheel suspension/steering, and clamp steering input. Mode 3 delegates to sub_4EE5C0 (UpdateVehiclePhysics). Mode 1 falls through to mode 2. Increments a frame counter and periodically calls sub_51D5A0 every 16 frames.

**Called by:** sub_416400 (00416400), sub_417AA0 (00417aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x62A0 | R | — | Compared to this+0x62A0 for equality check (likely vehicle ID) |
| this | 0x0 | R | — | Vehicle index/ID used to index into dword_75AAD0 array |
| this | 0x4 | R | — | Vehicle index/ID parameter passed to sub_4D9BA0 in case 3 |
| this | 0x10 | RW | — | Computed position X (this+4) |
| this | 0x14 | RW | — | Computed position Y (this+5) |
| this | 0x18 | RW | — | Computed position Z (this+6) |
| this | 0x4C | RW | — | Velocity/rotation component X (copy of this+4386) |
| this | 0x50 | RW | — | Velocity/rotation component Y (copy of this+4387) |
| this | 0x54 | RW | — | Velocity/rotation component Z (copy of this+4388) |
| this | 0x58 | RW | — | Physics scalar (from this+4684) |
| this | 0x5C | RW | — | Physics scalar (from this+4419) |
| this | 0x60 | RW | — | Combined scalar value |
| this | 0x94 | RW | — | Computed steering/input value clamped to [-1,1] (stored as dword 37) |
| this | 0x98 | RW | — | Physics threshold value (stored as dword 38) |
| this | 0x738 | R | — | Velocity direction X component for speed projection |
| this | 0x744 | R | — | Velocity direction Y component for speed projection |
| this | 0x750 | R | — | Velocity direction Z component for speed projection |
| this | 0x8A4 | R | — | Per-wheel active flags (byte array at this+2212, stride 304, 4 wheels) |
| this | 0x11C8 | RW | — | Clamped steering input value from dbl_75E930 |
| this | 0x11CC | RW | — | Vector component from sub_449750 output |
| this | 0x11D0 | RW | — | Vector component from sub_449750 output |
| this | 0x11D4 | RW | — | Vector component from sub_449750 output |
| this | 0x11D8 | RW | — | Vector component from sub_449750 output (v80[0]) |
| this | 0x11DC | RW | — | Vector component from sub_449750 output (v80[1]) |
| this | 0x1214 | RW | — | Clamped steering value [-1,1] written in case 2 |
| this | 0x1255 | RW | — | Flag: this+4421 > 0.01 (threshold exceeded) |
| this | 0x1258 | RW | — | Flag: byte_76082D & byte_76082C (combined input flags) |
| this | 0x4074 | R | — | Physics mode switch: 0=spline-follow, 1=fallthrough-to-2, 2=normal-driving, 3=delegated-physics |
| this | 0x4448 | R | — | Base position offset X (this+4380) |
| this | 0x4470 | R | — | Velocity X component (this+4386) |
| this | 0x4474 | R | — | Velocity Y component (this+4387) |
| this | 0x4478 | R | — | Velocity Z component (this+4388) |
| this | 0x4488 | R | — | Steering/rotation parameter passed to sub_50CA00 |
| this | 0x448C | R | — | Rotation matrix element for X axis |
| this | 0x4490 | R | — | Rotation matrix element for Y axis |
| this | 0x449C | R | — | Rotation matrix element for Z axis |
| this | 0x44A0 | R | — | Physics threshold stored at this+0x5C |
| this | 0x44A4 | R | — | Steering input value (clamped to [-1,1] in case 2) |
| this | 0x44A8 | R | — | Threshold value checked > 0.01 for flag at this+0x1255 |
| this | 0x450C | R | — | Computed wheel steering factor (multiplied by steering in case 2) |
| this | 0x4510 | R | — | Steering multiplier factor for wheel rotation |
| this | 0x4514 | R | — | Value checked <= 0.0 in case 0 to select physics scalar |
| this | 0x4540 | RW | — | Wheel data array element (at this+17728 + wheel*248) |
| this | 0x4544 | RW | — | Same as 0x450C — stored wheel steering factor |
| this | 0x454C | R | — | Wheel steering factor (duplicate of 0x450C for another path) |
| this | 0x463C | RW | — | Physics scalar stored at this+0x58 |
| this | 0x48FC | R | — | Physics mode-check value used in case 0 |
| this | 0x4914 | R | — | Physics scalar for this+0x58 |
| this | 0x4930 | R | — | Physics scalar for this+0x58 |
| this | 0x50F8 | RW | — | Frame counter incremented each successful tick (this+5184) |
| this | 0x5100 | R | — | Flag at this+20728 — if set, triggers sub_526050 (sound/effect) |

**Written-by note (persistence):**
- this 0x10: recalc every frame in modes 0/2 — overwritten
- this 0x14: recalc every frame in modes 0/2 — overwritten
- this 0x18: recalc every frame in modes 0/2 — overwritten
- this 0x4C: recalc every frame in modes 0/2 — overwritten
- this 0x50: recalc every frame in modes 0/2 — overwritten
- this 0x54: recalc every frame in modes 0/2 — overwritten
- this 0x58: recalc every frame — overwritten
- this 0x5C: recalc every frame — overwritten
- this 0x60: recalc every frame — overwritten
- this 0x94: recalc every frame in modes 0/2 — overwritten
- this 0x98: recalc every frame in modes 0/2 — overwritten
- this 0x11C8: recalc every frame in mode 0, conditional in mode 2 — may survive
- this 0x11CC: recalc every frame in mode 0 — overwritten
- this 0x11D0: recalc every frame in mode 0 — overwritten
- this 0x11D4: recalc every frame in mode 0 — overwritten
- this 0x11D8: recalc every frame in mode 0 — overwritten
- this 0x11DC: recalc every frame in mode 0 — overwritten
- this 0x1214: conditional — only written in mode 2 when value outside [-1,1]; poke may survive
- this 0x1255: recalc every frame — overwritten
- this 0x1258: recalc every frame — overwritten
- this 0x4540: recalc in wheel loops for modes 0/2 — overwritten
- this 0x4544: conditional — only written in mode 2; poke may survive in other modes
- this 0x463C: recalc every frame — overwritten
- this 0x50F8: increment-only — poke survives until next tick

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051d590 | jpt_51CDE5 | R | Jump table for switch on physics mode (4 entries: case 0-3) |
| 005d54dc | flt_5D54DC | R | Physics constant for suspension |
| 005d54e0 | flt_5D54E0 | R | Physics constant |
| 005d54e4 | flt_5D54E4 | R | Physics constant |
| 005d56c4 | flt_5D56C4 | R | Physics constant |
| 005d5c00 | dbl_5D5C00 | R | Constant 50.265484 (16*PI) for fmod wrap check |
| 005eaa54 | flt_5EAA54 | R | Constant for sound/effect sub_526050 |
| 005eaa70 | flt_5EAA70 | R | Constant for sound/effect sub_526050 |
| 0062bf68 | unk_62BF68 | R | Base address for vehicle physics data array (indexed by vehicle ID * 25304) |
| 0075aac0 | dword_75AAC0 | R | Active vehicle index into dword_75AAD0 array |
| 0075aad0 | dword_75AAD0 | R | Vehicle object array indexed by dword_75AAC0 |
| 0075e930 | dbl_75E930 | R | Input device value (steering/controller axis) clamped to [-1,1] |
| 00760270 | dword_760270 | W | Reset to 0 in case 0 |
| 00760274 | dword_760274 | W | Reset to 0 in case 0 |
| 0076082c | byte_76082C | R | Input flag combined with byte_76082D |
| 0076082d | byte_76082D | R | Input flag combined with byte_76082C |
| 00764104 | dword_764104 | R | Flag controlling this+20728 and sound trigger |
| 007d5dac | dword_7D5DAC | R | Physics data container passed to sub_4D9BA0 in case 3 |
| 007da9c8 | dbl_7DA9C8 | R | Wheel rotation delta constant multiplied per wheel in case 2 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00449620 | sub_449620 | Compute per-wheel transform matrix from input device value |
| 00449750 | sub_449750 | Convert input device value to orientation vectors |
| 004d9ba0 | sub_4D9BA0 | Look up physics data for vehicle in case 3 |
| 004d9e20 | sub_4D9E20 | Extract float parameter from physics data container |
| 004ee5c0 | sub_4EE5C0 | UpdateVehiclePhysics — called in case 3 with vehicle-specific data |
| 0050bfd0 | sub_50BFD0 | Post-tick processing on vehicle sub-struct at this+1808 |
| 0050c860 | sub_50C860 | Store per-wheel value in wheel data array |
| 0050ca00 | sub_50CA00 | Apply steering/rotation to vehicle sub-struct at this+1808 |
| 0050caa0 | F_3x3MatrixTransform [exact] | Apply rotation matrix to position offset |
| 0050cb70 | SuspensionParamUpdate [structural] | Update per-wheel suspension physics |
| 0050cce0 | sub_50CCE0 | Compute per-wheel position transform from input data |
| 0051d5a0 | sub_51D5A0 | Periodic update called every 16 frames |
| 0051d720 | sub_51D720 | Post-switch vehicle update (always called) |
| 0051dec0 | sub_51DEC0 | Finalize vehicle state after mode 0/2 processing |
| 0051e6b0 | sub_51E6B0 | Mode 1 entry — returns flag and falls through to mode 2 |
| 00526050 | sub_526050 | Trigger sound/effect when this+20728 flag is set |
| 00579930 | sub_579930 | Convert rotation matrix to Euler angles or similar transform |
| 005c057a | __CIfmod | Floating-point modulo for wheel angle wrap |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4074 | == | 2 | Physics mode 2: enables wheel rotation accumulation with fmod wrap |

**Guard interpretation:** Switch on this+0x4074: case 0 = spline-follow mode with external input, case 1 = falls through to case 2, case 2 = normal driving with steering clamp and wheel angle accumulation (wraps at 2*PI), case 3 = delegated physics via sub_4EE5C0. Default sets v52=0 (failure). After switch, sub_51D5A0 is called every 16 frames (when frame counter & 0xF == 0).
