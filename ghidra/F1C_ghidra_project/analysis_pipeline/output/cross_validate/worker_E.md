# Worker E — Cross-Validation Audit Results

## FUN_004EFBD0 — PASS

## FUN_00402220 — PASS

## FUN_0044C8F0 — PASS

## FUN_0044A430 — PASS

## FUN_0044E2A0 — PASS

## FUN_0044D1F0 — PASS

## FUN_0044DC40 — PASS

## FUN_0044EBA0 — PASS

## FUN_0044D370 — PASS

## FUN_004962C0 — PASS

## FUN_0044F010 — PASS

## FUN_0044D550 — PASS

## FUN_004584C0 — PASS

## FUN_0044E720 — PASS

## FUN_0044D6D0 — PASS

## FUN_0044C830 — PASS

## FUN_0044E6F0 — PASS

## FUN_00491AD0 — PASS

## FUN_004F6AB0 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_CALL] .c calls FUN_00566650(&DAT_005ea438) not mentioned in entry

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004F6AB0 — Tire/Grip Data Array Init (Front)

Source: tire_data.cpp. Initializes 45-entry tire/grip data array at DAT_008af8f8. Each entry: stride 5 ints (20 bytes), string index cleared, IDs set to -1.

**Globals:** DAT_008af8f8, DAT_005ea438

**Calls:** FUN_00566650 (string/path init)

## FUN_00583700 — PASS

## FUN_0045E620 — PASS

## FUN_00447160 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_MODDABILITY] Entry says `configurable` but _DAT_0059e420 is a hardcoded float constant — no config string in .c

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00447160 — Pit Lane Speed Limiter Check

Source: pit_limiter.cpp. Checks if vehicle exceeds pit lane speed limit and if pit limiter status is active.

**Key logic:**
- Compares speed magnitude (param_1+0x1db4) against zero threshold _DAT_0059e430
- If speed near zero, checks engine speed RPM (param_1+0x19c)
- If engine also near zero, reads pit limiter flag (param_1+0x1c59)
- If pit limiter active, checks pit limiter engaged flag (param_1+0x1d0c)
- If engaged: returns 1 (speed limited)
- Otherwise dereferences param_1+0x1f00 → +0x344c for vehicle state, then reads body velocity from param_1+0x15f0 → +0x74/+0x6c/+100
- If velocity^2 < _DAT_0059e420 (speed limit threshold): returns 1 (under limit)
- Returns 0 (no limit active)

**Calls:** none

**Moddability:** `hardcoded` — speed limit threshold _DAT_0059e420 is a compile-time constant

## FUN_00459070 — PASS

## FUN_00431820 — PASS

## FUN_004347C0 — PASS

## FUN_004364A0 — PASS

## FUN_0056BD40 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_CONST] Matrix entry formulas in doc do not match source. Doc claims R[0][0]=cos_yaw*cos_roll, source computes sin(pitch)*sin(yaw)*sin(roll)+cos(roll)*cos(pitch)

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_0056BD40 — Euler Angles to Rotation Matrix

Source: math utility. Converts 3 Euler angles to a 3x3 rotation matrix using double precision.

**Key logic:**
- Takes param_2 as 3 Euler angles (double[3]): yaw, pitch, roll
- Computes sin/cos of each angle
- Fills 3x3 rotation matrix at param_1 (double[9]):
  - R[0][0] = sin(pitch)*sin(yaw)*sin(roll) + cos(roll)*cos(pitch)
  - R[0][1] = sin(pitch)*sin(yaw)*cos(roll) - sin(roll)*cos(pitch)
  - R[0][2] = sin(pitch)*cos(yaw)
  - R[1][0] = sin(roll)*cos(yaw)
  - R[1][1] = cos(roll)*cos(yaw)
  - R[1][2] = -sin(yaw)
  - R[2][0] = sin(roll)*cos(pitch)*sin(yaw) - cos(roll)*sin(pitch)
  - R[2][1] = cos(roll)*cos(pitch)*sin(yaw) + sin(roll)*sin(pitch)
  - R[2][2] = cos(pitch)*cos(yaw)

**Moddability:** hardcoded

## FUN_0056C540 — PASS

## FUN_0043AEE0 — PASS

## FUN_00434860 — PASS

## FUN_004CC840 — PASS

## FUN_00569410 — PASS

## FUN_0053B240 — PASS

## FUN_004CCE90 — FAIL
Source: docs/19-renderer.md

**Errors:**
- [MISSING_CALL] .c calls FUN_004b9cf0 (line 58) not mentioned in entry

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004CCE90 — ParticleEffectEmitter

Source: renderer/particle. Emits directional particle effects (sparks, spray).

**Key logic:**
- Returns if object count <= 0
- Computes forward/up velocity from param_5 * constants
- Branches on `DAT_008ab6e4 == 2` for spread factor
- Projects position to camera via FUN_0044c550
- Gets camera position via FUN_0040c870
- Loops param_3 times (particle count):
  - Allocates via FUN_004cb540
  - Sets position with random jitter in velocity cone
  - Sets velocity with random variation
  - Stores projection results at +0x54/0x58/0x5c/0x64
  - Calls FUN_004cc500 for orientation

**Globals:** DAT_008aae70, DAT_008ab274, DAT_008ab6e4

**Calls:** FUN_004b9e30, FUN_004b9cf0, FUN_004b9ce0, FUN_0044c550, FUN_0040c870, FUN_004cb540, FUN_004cc500

**Moddability:** particle count, cone angle, velocity magnitude, jitter

## FUN_00456170 — FAIL
Source: docs/19-renderer.md

**Errors:**
- [WRONG_CONST] Entry claims pos=510.0f (0x43fa0000) but 0x43fa0000 = 500.0f
- [MISSING_CALL] .c calls FUN_00566650(&DAT_005ea438) and FUN_00456280 not mentioned in entry

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00456170 — 3D Transform Object Init

Source: render_transform.cpp. Initializes 3D transform object (200 bytes = 50 ints). Sets vtable PTR_LAB_0059efac, calls string init, position (500.0f), near clip (60.0f), far clip (45.0f), scale (1.0f), rotation (0.5f). Zeroes remaining fields.

**Key values:** pos=500.0f (0x43fa0000), near=60.0f (0x42700000), far=45.0f (0x42340000), scale=1.0f, rot=0.5f

**Calls:** FUN_00566650 (string/path init), FUN_00456280 (sub-init)

## FUN_00489920 — PASS

## FUN_0048E9E0 — PASS

## FUN_004981F0 — PASS

## FUN_0047BC30 — PASS

## FUN_00586800 — PASS

## FUN_005416A0 — PASS

## FUN_00497100 — PASS

## FUN_005105BF — PASS

## FUN_00507079 — PASS

## FUN_005147EA — PASS

## FUN_00534F90 — PASS

## FUN_00506CCC — PASS

## FUN_00540F00 — PASS

## FUN_00515F0E — PASS

## FUN_0050B399 — PASS

## FUN_004CEF30 — PASS

## FUN_00494470 — PASS

## FUN_004662E0 — PASS

## FUN_004C9360 — PASS

## FUN_0041EF40 — PASS

## FUN_005567F5 — PASS

## FUN_00596716 — PASS

## FUN_005608F6 — PASS

## FUN_0057ACB0 — PASS

## FUN_00575882 — PASS

## FUN_0058FFEC — PASS

## FUN_00581B30 — PASS

## FUN_00568B00 — PASS

## FUN_00443150 — PASS

## FUN_0040E6A0 — PASS

## FUN_004DC2D0 — PASS

## FUN_00587720 — PASS

## FUN_0040E6D0 — PASS

## FUN_00472D00 — PASS

## FUN_0048D660 — PASS

## FUN_004B1F50 — PASS

## FUN_004DCF50 — PASS

## FUN_0052466C — PASS

## FUN_0057A760 — PASS

## FUN_0058A380 — PASS

## FUN_00421990 — PASS

## FUN_004797C0 — PASS

## FUN_0049A110 — PASS

## FUN_004C7DE0 — PASS

## FUN_0050D857 — PASS

## FUN_0054A5B0 — PASS

## FUN_00550300 — PASS

## FUN_0046D610 — PASS

## FUN_004C2C00 — PASS

## FUN_00556260 — PASS

## FUN_00595F82 — PASS

## FUN_0045B400 — PASS

## FUN_0047C9D0 — PASS

## FUN_0049A180 — PASS

## FUN_004C4BB0 — PASS

## FUN_00503B94 — PASS

## FUN_0054C2F0 — PASS

## FUN_00598FD4 — PASS

## FUN_00407EF0 — PASS

## FUN_00464A10 — PASS

## FUN_00499CC0 — PASS

## FUN_004C2C20 — PASS

## FUN_005016E0 — PASS

## FUN_0053B6F0 — PASS

## FUN_0058A32A — PASS

## FUN_00408520 — PASS

## FUN_00465FF0 — PASS

## FUN_0048CA30 — PASS

## FUN_004A5BD0 — PASS

## FUN_004DB4E0 — PASS

## FUN_0053BCE0 — PASS

## FUN_00550760 — PASS

## FUN_00408740 — PASS

## FUN_00462330 — PASS

## FUN_00487900 — PASS

## FUN_004A0D90 — PASS

## FUN_004CE860 — PASS

## FUN_0050C9A9 — PASS

## FUN_00546430 — PASS

## FUN_0059AF50 — PASS

## FUN_00425660 — PASS

## FUN_004F3190 — PASS

## FUN_0058BD8F — PASS

## FUN_00421A70 — PASS

## FUN_00478350 — PASS

## FUN_004988C0 — PASS

## FUN_004BC270 — PASS

## FUN_004F9420 — PASS

## FUN_00534B00 — PASS

## FUN_00584110 — PASS

## FUN_00406A90 — PASS

## FUN_0054B4A0 — PASS

## FUN_00534D50 — PASS

## FUN_004D2E20 — PASS

## FUN_004A1F80 — PASS

## FUN_004893C0 — PASS

## FUN_0046B580 — PASS

## FUN_0057B0D0 — PASS

## FUN_004DD4E0 — PASS

## FUN_00517AC5 — PASS

## FUN_0055C7B0 — PASS

## FUN_0050DD3A — PASS

## FUN_0059C8D0 — PASS

## FUN_00426CC0 — PASS

## FUN_004799A0 — PASS

## FUN_00499260 — PASS

## FUN_004BE180 — PASS

## FUN_004FC9A0 — PASS

## FUN_00536FD0 — PASS

## FUN_005883E5 — PASS

## FUN_0059C504 — PASS

## FUN_004582C0 — PASS

## FUN_0047BE70 — PASS

## FUN_00499E50 — PASS

## FUN_004C2FB0 — PASS

## FUN_00502C28 — PASS

## FUN_0053C210 — PASS

## FUN_0058A9DA — PASS

## FUN_00597568 — PASS

## FUN_0045C400 — PASS

## FUN_004858E0 — PASS

## FUN_0049AF30 — PASS

## FUN_004C9280 — PASS

## FUN_0050B727 — PASS

## FUN_00543A80 — PASS

## FUN_00599B1C — PASS

## FUN_00411570 — PASS

## FUN_0047F370 — PASS

## FUN_0049A3B0 — PASS

## FUN_004C7C00 — PASS

## FUN_0050AE76 — PASS

## FUN_00540150 — PASS

## FUN_0059D99E — PASS

## FUN_00423459 — PASS

## FUN_004B4460 — PASS

## FUN_00542490 — PASS

## FUN_005884ED — PASS

## FUN_004B0170 — PASS

## FUN_00563230 — PASS

## FUN_00459990 — PASS

## FUN_00485A90 — PASS

## FUN_0049B020 — PASS

## FUN_004C94D0 — PASS

## FUN_0050B797 — PASS

## FUN_005424E0 — PASS

## FUN_00598E07 — PASS

## FUN_0040B450 — PASS

## FUN_004668E0 — PASS

## FUN_0048D4B0 — PASS

## FUN_004B0220 — PASS

## FUN_004D7FF0 — PASS

## FUN_00511F70 — PASS

## FUN_0054C190 — PASS

## FUN_0040A610 — PASS

## FUN_0046B5C0 — PASS

## FUN_00491E80 — PASS

## FUN_0059C45A — PASS

## FUN_0059D1D8 — PASS

## FUN_0058C07F — PASS

## FUN_0059D414 — PASS

## FUN_0059CE76 — PASS

## FUN_0059CC93 — PASS

## FUN_00581D40 — PASS

## FUN_00582190 — PASS

## FUN_00500210 — PASS

## FUN_0051BAD1 — PASS

## FUN_00515BB0 — PASS

## FUN_00561E30 — PASS

## FUN_0059869C — PASS

## FUN_0057B840 — PASS

## FUN_00406CC0 — PASS
