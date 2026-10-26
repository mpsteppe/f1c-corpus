# Worker H — Cross-Validation Audit Results

Results for functions 1444–1649.

---

## FUN_004A5FA0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_GLOBAL] .c references DAT_007ce7a8 (line 109) not mentioned in entry

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_004a5fa0 — Proximity Collision Detection

Source: unknown. Checks proximity between two entities using distance and dot-product contact tests.

**Key logic:**
- Transforms entity position via FUN_00403f70 (world transform) and FUN_004efb20 (velocity transform)
- Computes distance^2 between two points, checks against _DAT_0059e8a0 (contact threshold)
- If within range: computes dot product of approach direction with surface normal; checks thresholds _DAT_0059e8a4 and _DAT_0059f11c
- Checks relative velocity magnitude against _DAT_0059e46c or _DAT_005acb50 (speed-dependent thresholds)
- Cross-entity velocity check at param_1 offsets +0x34c4/0x34d0/0x34dc (spin axis component)
- Checks entity mode at offset 13000 (sleeping entities trigger FUN_004a5c80 when DAT_007ce7a8 != 0)
- Returns combined status flags

**Globals:**
- `DAT_007ce7a8` — enables sleeping entity collision processing

**Calls:** FUN_00403f70 (transform), FUN_004efb20 (velocity), FUN_00566e40, FUN_0042adb0, FUN_004a5c80

**Moddability:** hardcoded

---

## FUN_004FB2E0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_GLOBAL] .c references _DAT_005ad280 and _DAT_005ad278 (lines 29, 64) not mentioned in entry

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_004fb2e0 — Vehicle Closest-Approach Distance

Source: unknown. Computes minimum separation distance between two moving vehicles.

**Key logic:**
- Reads pointer to other vehicle (param_1[0x43]), validates both structs are active
- Computes relative velocity dot product to determine approaching vs separating
- Checks against threshold globals _DAT_005ad280 (lower) and _DAT_005ad278 (upper)
- If separating: stores sentinel values (0.0 or 999999.0)
- If approaching: computes closest point on each vehicle's trajectory using line intersection formula
- Stores result for primary (param_1[0x2c]) and secondary entities (param_1[0x2d])

**Globals:**
- `_DAT_005ad280` — lower separation threshold
- `_DAT_005ad278` — upper separation threshold

**Calls:** none (leaf function, uses SQRT)

**Moddability:** hardcoded

---

## FUN_0044DFD0 — PASS

## FUN_0044BC10 — PASS

## FUN_0044CDA0 — PASS

## FUN_0044E8D0 — PASS

## FUN_0044C740 — PASS

## FUN_0047C960 — PASS

## FUN_0044EA50 — PASS

## FUN_0044DDC0 — PASS

## FUN_0044C5E0 — PASS

## FUN_0044EBD0 — PASS

## FUN_0044DF40 — PASS

## FUN_0044C710 — PASS

## FUN_0044F050 — PASS

## FUN_0044DF10 — PASS

## FUN_0044C7D0 — PASS

## FUN_00491C70 — PASS

---

## FUN_0056C830 — PASS

## FUN_00459AE0 — PASS

## FUN_004B2DD0 — PASS

## FUN_00435E60 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_CALL] Entry claims calls FUN_00569ad0 but .c does not call it

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00435e60 — Wheel Hub Position & Orientation from Setup

Source: vehicle dynamics. Computes wheel hub world position and orientation from suspension setup parameters (ride height, camber, toe, caster). Outputs 3D position + 3-float orientation.

**Key logic:**
- If no setup (param_1=0): zeros all output (param_3 position, param_4 orientation)
- Transforms wheel hub to world frame via FUN_004361d0
- Substracts chassis position (param_1[1], [3], [5]) from hub position
- Scales by _DAT_007cfb48 (suspension scale factor)
- Clamps X/Y/Z to setup bounds (min/max from param_1[7..13], [9..15], [11..17])
- Calls FUN_0056c740 to get orientation matrix
- Calls FUN_00588570 for time-dependent perturbation
- Computes euler angles from matrix using atan2
- Scales orientation by _DAT_007cfb6c * _DAT_007cfb48
- Clamps orientation components to setup bounds (param_1[25..26], [27..28], [29..30])

**Calls:** FUN_004361d0, FUN_0056c740, FUN_00588570

**Moddability:** configurable (all parameters driven by setup: camber, toe, caster, ride height bounds)

---

## FUN_0040EF70 — PASS

## FUN_00448330 — PASS

## FUN_00448EC0 — PASS

## FUN_0043EBD0 — PASS

## FUN_00449EB7 — PASS

## FUN_004390A0 — PASS

## FUN_004482D0 — PASS

## FUN_0043BBD0 — PASS

## FUN_004E4570 — PASS

## FUN_00569860 — PASS

## FUN_0056A240 — PASS

---

## FUN_00411840 — PASS

## FUN_00486240 — PASS

## FUN_00489A10 — PASS

## FUN_0048FEE0 — PASS

## FUN_004986A0 — PASS

## FUN_0055DA50 — PASS

## FUN_0050B8A9 — PASS

## FUN_0048A240 — PASS

## FUN_0051941D — PASS

## FUN_00543FA0 — PASS

## FUN_00512ACC — PASS

## FUN_00548190 — PASS

## FUN_005159F5 — PASS

## FUN_0050E6D3 — PASS

## FUN_0050696C — PASS

## FUN_0051E0DC — PASS

## FUN_0050D9A5 — PASS

## FUN_00586D70 — PASS

## FUN_004993D0 — PASS

## FUN_004742A0 — PASS

## FUN_004DC1A0 — PASS

---

## FUN_00448300 — PASS
## FUN_00595801 — PASS
## FUN_00556760 — PASS
## FUN_00585130 — PASS
## FUN_0058BCCF — PASS
## FUN_0058CA19 — PASS
## FUN_005574B0 — PASS
## FUN_0058F362 — PASS
## FUN_0058C724 — PASS
## FUN_00558CB0 — PASS
## FUN_0045CBF0 — PASS
## FUN_0050D748 — PASS
## FUN_005992D3 — PASS
## FUN_0041F180 — PASS
## FUN_004781A0 — PASS
## FUN_004910D0 — PASS
## FUN_004B46F0 — PASS
## FUN_004F8280 — PASS
## FUN_005355A0 — PASS
## FUN_00587880 — PASS
## FUN_00599D17 — PASS
## FUN_0045B360 — PASS
## FUN_0047C910 — PASS
## FUN_004A03F0 — PASS
## FUN_004D0EC0 — PASS
## FUN_0051212E — PASS
## FUN_0055BDD0 — PASS
## FUN_00568CF0 — PASS
## FUN_004797F0 — PASS
## FUN_004D7BF0 — PASS
## FUN_00586E50 — PASS
## FUN_00404790 — PASS
## FUN_00461470 — PASS
## FUN_004868C0 — PASS
## FUN_0049EC60 — PASS
## FUN_004C9B70 — PASS
## FUN_0050B830 — PASS
## FUN_005622B0 — PASS
## FUN_00467260 — PASS
## FUN_0040D450 — PASS
## FUN_00568E60 — PASS
## FUN_0049D150 — PASS
## FUN_004C8D90 — PASS
## FUN_0050B37D — PASS
## FUN_00541090 — PASS
## FUN_005975F4 — PASS
## FUN_0040E8B0 — PASS
## FUN_0046D6A0 — PASS
## FUN_00490250 — PASS
## FUN_004B2A80 — PASS
## FUN_004DFA60 — PASS
## FUN_0054E0E0 — PASS
## FUN_0058A5D8 — PASS
## FUN_0056F090 — PASS
## FUN_00466050 — PASS
## FUN_0048CA50 — PASS
## FUN_004A5C10 — PASS
## FUN_004D7CF0 — PASS
## FUN_005111D3 — PASS
## FUN_0054B3F0 — PASS
## FUN_0059D4C0 — PASS
## FUN_00463C40 — PASS
## FUN_00513E5D — PASS
## FUN_005972BD — PASS
## FUN_00457EE0 — PASS
## FUN_0047BB40 — PASS
## FUN_00499E00 — PASS
## FUN_004C2D30 — PASS
## FUN_0050210E — PASS
## FUN_0053C150 — PASS
## FUN_0058A870 — PASS
## FUN_0040DBC0 — PASS
## FUN_00557280 — PASS
## FUN_0051166B — PASS
## FUN_004D8A30 — PASS
## FUN_004B19F0 — PASS
## FUN_0048E300 — PASS
## FUN_004623B0 — PASS
## FUN_004BA790 — PASS
## FUN_004F62E6 — PASS
## FUN_00527EED — PASS
## FUN_00579FB0 — PASS
## FUN_00564640 — PASS
## FUN_0059CE8C — PASS
## FUN_0045BA60 — PASS
## FUN_0047F180 — PASS
## FUN_0049A2F0 — PASS
## FUN_004C6760 — PASS
## FUN_00504640 — PASS
## FUN_0053CED0 — PASS
## FUN_0059532B — PASS
## FUN_004010B0 — PASS
## FUN_0045E5B0 — PASS
## FUN_00486480 — PASS
## FUN_0049E170 — PASS
## FUN_004C9260 — PASS
## FUN_0050B462 — PASS
## FUN_005423E0 — PASS
## FUN_00598750 — PASS
## FUN_00401130 — PASS
## FUN_00462530 — PASS
## FUN_00487F10 — PASS
## FUN_004A2220 — PASS
## FUN_004D47C0 — PASS
## FUN_0050F9AB — PASS
## FUN_00549380 — PASS
## FUN_0050E3DA — PASS
## FUN_0041EF00 — PASS
## FUN_00487330 — PASS
## FUN_0049F790 — PASS
## FUN_004CB4F0 — PASS
## FUN_0050D5F9 — PASS
## FUN_00547140 — PASS
## FUN_005668B0 — PASS
## FUN_004646C0 — PASS
## FUN_004BF630 — PASS
## FUN_005487E0 — PASS
## FUN_00591E89 — PASS
## FUN_004D7920 — PASS
## FUN_0058A2CB — PASS
## FUN_00460710 — PASS
## FUN_004881F0 — PASS
## FUN_004A2840 — PASS
## FUN_004D4860 — PASS
## FUN_0050E342 — PASS
## FUN_00548850 — PASS
## FUN_0059CA30 — PASS
## FUN_0040F380 — PASS
## FUN_0046F490 — PASS
## FUN_00490B90 — PASS
## FUN_004B2C80 — PASS
## FUN_004DCF20 — PASS
## FUN_00516974 — PASS
## FUN_00559FB0 — PASS
## FUN_0040EBD0 — PASS
## FUN_00475140 — PASS
## FUN_00497890 — PASS
## FUN_0059C5F8 — PASS
## FUN_0059D4E0 — PASS
## FUN_0059D5BC — PASS
## FUN_0058A7EC — PASS
## FUN_0059CF4B — PASS
## FUN_0059D130 — PASS

---

## FUN_00581070 — PASS
## FUN_0059A5E9 — PASS
## FUN_004F12E0 — PASS
## FUN_0051E3E7 — PASS
## FUN_00568210 — PASS
## FUN_00563080 — PASS
## FUN_0057D8D0 — PASS
## FUN_004C8D70 — PASS
## FUN_00405B50 — PASS


