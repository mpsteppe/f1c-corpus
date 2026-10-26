# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Two functions. ParseSvmHdvVehicleConfigFile (0x004F4270) is a line-by-line .SVM/.HDV parser owned by TheSvmHdvVehicleFileParser (DERIVED from the legacy ABI lead): it opens the file in binary-read mode, validates the format on a first pass, dispatches each named section (General, FrontWing, LeftFender, RightFender, RearWing, BodyAero, Diffuser, Suspension, Controls, Engine, Driveline, per-wheel corners, Basic) to a section reader, resolves secondary files (damage model, engine, gear file, physical model, tire compound) relative to the config path, and normalizes range/setting pairs into the output vehicle state. InitPhysicsTransformIdentity (0x00578F76) is a selector dispatch (0..33) that initializes one row of a large double-precision physics dynamics matrix block (0x008D2120..0x008D3978) to an identity row (diagonal 1.0, off-diagonals 0.0), returning the selector argument.

## Function roles

- `0x004F4270` **TheSvmHdvVehicleFileParser** — Line-by-line parser and section dispatcher for .SVM/.HDV vehicle configuration files; validates format, parses named sections, resolves secondary files, and normalizes range/setting pairs into the output vehicle-state struct.
- `0x00578F76` **UnknownObject** — Initialize one row of the double-precision physics dynamics matrix to an identity row; dispatch on selector argument a1 (0..33) via the jump table at 0x00579C47 and return the selector.

## Proposed classes

### TheSvmHdvVehicleFileParser

Parse .SVM/.HDV vehicle configuration files into an internal setup struct (this) and produce a normalized output vehicle-state struct (a3); dispatch named sections to section readers and resolve secondary files relative to the config path.

Methods: `0x004F4270`

- `this+0x00000008` `float tire_compound_rpm_multiplier` (write, DERIVED)
- `this+0x00000034` `int rules_setting` (write, DERIVED)
- `this+0x00000038` `int garage_display_flags` (write, DERIVED)
- `this+0x00000068` `float wedge_pushrod_setting` (read, DERIVED)
- `this+0x000001EC` `byte front_wing_drag_params_loaded` (write, DERIVED)
- `this+0x000002F8` `byte rear_wing_drag_params_loaded` (write, DERIVED)
- `this+0x000004D4` `byte diffuser_base_loaded` (write, DERIVED)
- `this+0x00000548` `byte suspension_setting_a` (write, GUESS)
- `this+0x0000056C` `byte suspension_setting_b` (write, GUESS)
- `this+0x00000674` `double engine_map_scale_a` (read, DERIVED)
- `this+0x0000067C` `double engine_map_scale_b` (read, DERIVED)
- `this+0x000013C0` `int wheel_drive_classification` (write, DERIVED)
- `this+0x000013C4` `int forward_gear_count` (write, DERIVED)

## Compatibility contracts

- **SvmHdvConfigFileFormat** — Line-based '='-delimited configuration files with named sections (General, FrontWing, LeftFender, RightFender, RearWing, BodyAero, Diffuser, Suspension, Controls, Engine, Driveline, Frontleft/Frontright/Rearleft/Rearright, Basic). Recognized header keywords include Setting/Notes/Downforce/Balance/Ride/Gearing/Custom/Symmetric. In non-server sessions a file with no recognized header is rejected as an illegal .SVM file. A replacement executable must preserve '=' delimiter handling, section dispatch, and the rejection path.
- **PhysicsMatrixRowIdentity** — 0x00578F76 must set exactly one row of the double-precision dynamics matrix to an identity row (diagonal element 1.0, all other stored elements of that row 0.0), selected by argument 0..33, and return the selector argument unchanged on every path.

## Unresolved

- The four read-only data globals dbl_59E420/dbl_59E430/flt_59E440/flt_59E450 are not visible as direct references in the ParseSvmHdvVehicleConfigFile decompiled body; likely constant operands forwarded into CRTMathHelper/ArithmeticComparison helpers, role unconfirmed.
- unk_8AC368 and unk_8AC388 appear as read-only data in the packet but not in this function's decompiled body; carried because the packet lists them as referenced globals.
- The output struct (a3) layout is only partially mapped: byte flags 6540/6544/6556/6565/6536/6537/6564 and engine-scale doubles 6548/6552 are visible; names and sizes inferred from usage.
- Engine-map scale factor semantics: the 1.0/product reciprocal written at a3+6548/6552 (this+0x674 * this+0x67C * flt_5EA40C * dword_7D0B64) is DERIVED from arithmetic; physical meaning unconfirmed.
- Owner identity of 0x004F4270 is DERIVED from the LEGACY ABI lead The_svm_hdv_Vehicle_File_Parser; no confirmed class symbol in the packet.
- Whether sub_58BB10's third argument is a byte count (odd multiples of 8) or an element count is not resolvable from this packet.
- Exact matrix/array dimensionality and row ordering of the 0x008D2120..0x008D3978 double-precision block is not derivable from 0x00578F76 alone.
- Purpose of the per-row extra element stored in the 0x008D3870..0x008D3978 trailing column is unresolved.
- Selector source and call sites of 0x00578F76 are unknown (no static callers); the object owning the matrix block is unknown.
