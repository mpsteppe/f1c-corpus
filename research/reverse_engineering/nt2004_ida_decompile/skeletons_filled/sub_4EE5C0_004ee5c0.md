## sub_4EE5C0_004ee5c0 — UpdateVehiclePhysics

**Summary:** Per-frame vehicle physics update: computes delta time, transforms chassis orientation matrix, clamps steering input to [-1,1], iterates 4 wheels for suspension, copies position/velocity/rotation into the vehicle object, and handles state-dependent logic (mode 2 for normal driving, mode 3 for alternate physics).

**Called by:** sub_51CC60 (0051cc60), sub_51CDC0 (0051cdc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | RW | — | Position X (copied from a2+36) |
| this | 0x68 | RW | — | Position Y (copied from a2+40) |
| this | 0x6C | RW | — | Position Z (copied from a2+44) |
| this | 0xA0 | RW | — | Velocity X (from v46[0]) |
| this | 0xA4 | RW | — | Velocity Y (from v46[1]) |
| this | 0xA8 | RW | — | Velocity Z (from v46[2]) |
| this | 0xE8 | RW | — | Physics param from sub_4D0310 (wheel-related) |
| this | 0xEC | RW | — | Physics param from sub_4D0370 (wheel-related) |
| this | 0x944 | R | — | Suspension data base pointer (array stride 304 bytes, indexed 0-3 for 4 wheels) |
| this | 0x1268 | RW | — | Steering input value clamped to [-1.0, 1.0] |
| this | 0x1270 | R | — | Scaling factor multiplied by steering for front-wheel suspension |
| this | 0x1298 | R | — | Parameter passed to sub_50B4E0 when flag changes (likely gear/transmission state) |
| this | 0x12A1 | RW | — | Flag derived from a2+12 bit 0x8000000 — triggers sub_50B4E0 on change |
| this | 0x12A9 | RW | — | Flag derived from a2+12 bit 0x4000000 |
| this | 0x40C8 | R | — | Vehicle physics mode: 2 = normal driving, 3 = alternate handling |
| this | 0x4404 | RW | — | Flag from a2+12 bit 0x2000000 (likely handbrake or special input) |
| this | 0x4564 | RW | — | Stored steering value when mode == 2 |
| this | 0x514C | RW | — | Flag from a2+10 bit 0 (lowest bit of a2+10 byte) |
| this | 0x5281 | RW | — | Flag from input struct v5 bit 0x80 |
| this | 0x62BC | RW | — | Value from sub_4D0550 (likely RPM or wheel speed, stored as 16-bit) |
| this | 0x62C0 | RW | — | Last timestamp when large delta (>15.0) triggered full recalculation |
| this | 0x62C4 | RW | — | Previous frame timestamp a3, updated every call |

**Written-by note (persistence):**
- this 0x64: recalc every frame — external poke overwritten next physics tick
- this 0x68: recalc every frame — external poke overwritten next physics tick
- this 0x6C: recalc every frame — external poke overwritten next physics tick
- this 0xA0: recalc every frame — external poke overwritten next physics tick
- this 0xA4: recalc every frame — external poke overwritten next physics tick
- this 0xA8: recalc every frame — external poke overwritten next physics tick
- this 0xE8: recalc every frame — external poke overwritten next physics tick
- this 0xEC: recalc every frame — external poke overwritten next physics tick
- this 0x1268: recalc every frame (clamped from input) — overwritten
- this 0x12A1: conditional — only written when flag differs from input; poke survives until next mismatch
- this 0x12A9: recalc every frame — overwritten
- this 0x4404: conditional — only written in mode 2; poke may survive in mode 3
- this 0x4564: conditional — only written in mode 2; poke may survive in mode 3
- this 0x514C: recalc every frame — overwritten
- this 0x5281: conditional — only written in mode 2; poke may survive in mode 3
- this 0x62BC: recalc every frame — overwritten
- this 0x62C0: conditional — only written when |delta| > 15.0 in mode 2; poke survives most frames
- this 0x62C4: recalc every frame — overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | Constant multiplier for suspension calculations |
| 005d56c4 | flt_5D56C4 | R | Constant for physics parameter |
| 005d5b78 | flt_5D5B78 | R | Constant for physics parameter |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cfba0 | sub_4CFBA0 | Extract velocity vector from a2+24 into v46 |
| 004cfd10 | sub_4CFD10 | Extract additional vector from a2+24 into v48 |
| 004cff40 | sub_4CFF40 | Process wheel-related data from v5 into v47 array |
| 004d0130 | sub_4D0130 | Compute per-wheel suspension parameters for wheel index v13 |
| 004d0310 | sub_4D0310 | Compute physics scalar from input (stored at this+0xE8) |
| 004d0370 | sub_4D0370 | Compute physics scalar from input (stored at this+0xEC) |
| 004d03b0 | sub_4D03B0 | Compute value from v5 for sub_51E230 call |
| 004d03f0 | sub_4D03F0 | Extract steering/input value from v5, clamped to [-1,1] |
| 004d04f0 | sub_4D04F0 | Query per-index value from v5 for recalculation loop |
| 004d0520 | sub_4D0520 | Extract value from v5 fed to sub_4EED80 |
| 004d0550 | sub_4D0550 | Extract 16-bit value from v5 (RPM/speed) stored at this+0x62BC |
| 004dea70 | sub_4DEA70 | Update flag at this+0x20836 based on sign of a2+12 |
| 004eec20 | sub_4EEC20 | Handle mode-3 specific update with a2+15 bit 0 |
| 004eec50 | sub_4EEC50 | Handle mode-3 specific update with a2+15 bit 0 |
| 004eed80 | sub_4EED80 | Process output of sub_4D0520 |
| 0050b4e0 | sub_50B4E0 | Triggered when flag at this+0x12A1 changes — likely gear-change or state transition |
| 0050bdd0 | sub_50BDD0 | Recalculate per-index wheel parameter (called in loops of 18) |
| 0050c860 | sub_50C860 | Store per-wheel value in mode 3 path (loop of 4) |
| 0050caa0 | F_3x3MatrixTransform [exact] | Apply rotation matrix to position/offset vector |
| 0050cb70 | SuspensionParamUpdate [structural] | Update suspension physics for each wheel with spring/damper values |
| 0051e230 | sub_51E230 | Mode-2 specific physics processing with full state |
| 0051e380 | sub_51E380 | Mode-2 additional processing with clamped params |
| 0051e3b0 | sub_51E3B0 | Mode-3 alternative physics processing |
| 00579100 | EulerToRotationMatrix [exact] | Convert Euler angles from input to rotation matrix v49 |

**Guard conditions:** Steering clamp: value from sub_4D03F0 clamped to [-1.0, 1.0] before storing at this+0x1268. Mode branch: this+0x40C8 (v19) checked — if 2 runs normal driving path with 18-index recalculation when |delta_timestamp| > 15.0, if 3 runs alternate physics path. Flag change guard: this+0x12A1 compared to input bit 0x8000000 — sub_50B4E0 only called on change.
