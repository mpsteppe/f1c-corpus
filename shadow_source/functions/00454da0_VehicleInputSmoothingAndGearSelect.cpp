// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00454DA0
// Canonical corpus name: sub_454DA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_454DA0_00454da0.c

void UnknownObject::VehicleInputSmoothingAndGearSelect()
{
    // Per-frame vehicle input processor. For each axis (throttle, brake, clutch, steering, handbrake) it either copies a direct target value when the mode field == 2, or ramps a smoothed accumulator toward 1.0 / 0.0 using a per-axis decay constant times the input scalar a2 times 10.0, clamped to the float 1.0 / 0.0 bit patterns. Steering adds a sign-aware return-to-center ramp gated by an input-active flag and a neutral flag. Writes the six smoothed outputs back through output pointers a3 (steering), a4 (throttle), a5 (brake), a6 (clutch), a7 (handbrake), a8 (gear). The gear output is selected from a ladder of seven gear-input flags (reverse -1, gears 1..7) gated by a byte flag at this+0x2428 and a neutral override at 0x20F0 == 0, with a global byte_7D1370 == 1 forcing neutral. Called per frame from VehicleMainPhysicsUpdate and CollisionConfigurationSync.
    // GUARD: Throttle mode gate: if this+0x1B20 == 2 (guard:0) take the direct-passthrough path, bypassing the smoothing ramp. [field:this:0x00001B20, guard:0]
    // ASSIGNMENT: Throttle direct target: this+0x2410 (float) = this+0x1B48. [field:this:0x00002410, field:this:0x00001B48]
    // CALCULATION: Throttle decay step: v8 = flt_7D12C8 * a2 * 10.0. [global:0x007D12C8, source:raw]
    // GUARD: Throttle input-active check: if this+0x1B44 is nonzero the throttle ramps upward, otherwise it decays. [field:this:0x00001B44]
    // CALCULATION: Throttle ramp up: this+0x2410 (float) += v8; if the result exceeds 1.0 force the dword 1065353216 (float 1.0 bit pattern). [field:this:0x00002410, source:raw]
    // CALCULATION: Throttle decay: if this+0x1B70 is nonzero subtract v8 * 1.5 from this+0x2410, else subtract v8; if the result is below 0.0 force the dword 0. [field:this:0x00002410, field:this:0x00001B70, source:raw]
    // ASSIGNMENT: Commit throttle output: *a4 = this+0x2410. [field:this:0x00002410, source:raw]
    // GUARD: Brake mode gate: if this+0x1B4C == 2 (guard:1) take the direct-passthrough path. [field:this:0x00001B4C, guard:1]
    // ASSIGNMENT: Brake direct target: this+0x2414 (float) = this+0x1B74. [field:this:0x00002414, field:this:0x00001B74]
    // CALCULATION: Brake decay step: v10 = flt_7D12EC * a2 * 10.0. [global:0x007D12EC, source:raw]
    // GUARD: Brake input-active check: if this+0x1B70 is nonzero the brake ramps upward, otherwise it decays. [field:this:0x00001B70]
    // CALCULATION: Brake ramp up: this+0x2414 (float) += v10; clamp above 1.0 to dword 1065353216. [field:this:0x00002414, source:raw]
    // CALCULATION: Brake decay: this+0x2414 (float) -= v10; clamp below 0.0 to dword 0. [field:this:0x00002414, source:raw]
    // ASSIGNMENT: Commit brake output: *a5 = this+0x2414. [field:this:0x00002414, source:raw]
    // GUARD: Clutch mode gate: if this+0x21D4 == 2 (guard:6) take the direct-passthrough path. [field:this:0x000021D4, guard:6]
    // ASSIGNMENT: Clutch direct target: this+0x2418 (float) = this+0x21FC. [field:this:0x00002418, field:this:0x000021FC]
    // CALCULATION: Clutch decay step: v13 = flt_7D12EC * a2 * 10.0. [global:0x007D12EC, source:raw]
    // GUARD: Clutch input-active check: if this+0x21F8 is nonzero the clutch ramps upward, otherwise it decays. [field:this:0x000021F8]
    // CALCULATION: Clutch ramp: if active this+0x2418 (float) += v13 with a 1.0 clamp (dword 1065353216); else this+0x2418 -= v13 with a 0.0 clamp. [field:this:0x00002418, source:raw]
    // ASSIGNMENT: Commit clutch output: *a6 = this+0x2418. [field:this:0x00002418, source:raw]
    // GUARD: Steering direct gate: if this+0x1B78 == 2 AND this+0x1BA4 == 2 (guards:2 and 3) copy the steering target directly and skip the smoothing ramp. [field:this:0x00001B78, field:this:0x00001BA4, guard:2, guard:3]
    // ASSIGNMENT: Steering direct value: if float this+0x1BA0 <= 0.0 then this+0x241C = float this+0x1BCC, else this+0x241C = -(float this+0x1BA0); then jump to the steering commit label. [field:this:0x0000241C, field:this:0x00001BA0, field:this:0x00001BCC]
    // CALCULATION: Steering decay step: v17 = flt_7D12A4 * a2 * 10.0; snapshot current steering v19 = float this+0x241C and its sign flags v20 (negative) / v22 (zero). [global:0x007D12A4, field:this:0x0000241C, source:raw]
    // GUARD: Steering input-active check: if this+0x1B9C is nonzero the steering is being driven by input; otherwise it returns toward center. [field:this:0x00001B9C]
    // CALCULATION: Steering ramp while input active and neutral flag clear: if this+0x1BC8 (v16) == 0 and the current value is positive, subtract 3.0 * v17 then v17, clamping below -1.0 to dword -1082130432 (float -1.0 bit pattern). [field:this:0x0000241C, field:this:0x00001BC8, source:raw]
    // CALCULATION: Steering return-to-center while input inactive and neutral flag set: if this+0x1BC8 (v16) != 0 and the current value is negative, add 3.0 * v17 then v17, clamping above 1.0 to dword 1065353216. [field:this:0x0000241C, field:this:0x00001BC8, source:raw]
    // CALCULATION: Steering fallthrough ramp: when input is active with the neutral flag set, or inactive without it, apply a sign-dependent v17 ramp toward zero; when the accumulator crosses its sign boundary force this+0x241C = 0. The ramp direction is chosen by a decompiler FPU-status flag (v24 & 0x41) whose origin is ambiguous (see unresolved). [field:this:0x0000241C, source:raw]
    // ASSIGNMENT: Commit steering output: *a3 = this+0x241C. [field:this:0x0000241C, source:raw]
    // GUARD: Gear-selection gate: the gear ladder only runs when byte this+0x2428 is nonzero. [field:this:0x00002428]
    // ASSIGNMENT: Gear ladder init: this+0x2424 = -2; if this+0x20F0 == 0 (guard:5) the ladder chooses a gear from the gear-input flags, otherwise this+0x2424 = 7. [field:this:0x00002424, field:this:0x000020F0, guard:5]
    // GUARD: Gear-flag ladder (descending if/else chain): this+0x20C4 set -> gear 6; this+0x2098 -> 5; this+0x206C -> 4; this+0x2040 -> 3; this+0x2014 -> 2; this+0x1FE8 -> 1; this+0x1FBC -> reverse -1; none set leaves the initial -2. [field:this:0x000020C4, field:this:0x00002098, field:this:0x0000206C, field:this:0x00002040, field:this:0x00002014, field:this:0x00001FE8, field:this:0x00001FBC]
    // CALCULATION: Gear neutral override: if this+0x2424 still == -2 (dword 0xFFFFFFFE, guard:7) and global byte_7D1370 == 1, force this+0x2424 = 0 (neutral). [field:this:0x00002424, global:0x007D1370, guard:7]
    // ASSIGNMENT: Commit gear output: *a8 = this+0x2424. [field:this:0x00002424, source:raw]
    // GUARD: Handbrake mode gate: if this+0x1C54 == 2 (guard:4) take the direct-passthrough path. [field:this:0x00001C54, guard:4]
    // ASSIGNMENT: Handbrake direct target: this+0x2420 (float) = this+0x1C7C; *a7 = this+0x2420 and return. [field:this:0x00002420, field:this:0x00001C7C, source:raw]
    // GUARD: Handbrake engage: if this+0x1C78 is nonzero set this+0x2420 = dword 1065353216 (float 1.0), write *a7 = same. [field:this:0x00001C78, field:this:0x00002420, source:raw]
    // CALCULATION: Handbrake decay: v29 = float this+0x2420 - flt_7D1310 * a2 * 10.0; if >= 0.0 commit and *a7 = this+0x2420, else set this+0x2420 = 0 and *a7 = 0. [field:this:0x00002420, global:0x007D1310, source:raw]

    // Conservative worker pseudocode:
    //   if this[0x1B20] == 2: this[0x2410] = this[0x1B48];
    //   else: step = flt_7D12C8 * a2 * 10.0; if this[0x1B44]: this[0x2410] += step clamp 1.0; else: this[0x2410] -= (this[0x1B70] ? step*1.5 : step) clamp 0.0;
    //   *a4 = this[0x2410];   // throttle
    //   if this[0x1B4C] == 2: this[0x2414] = this[0x1B74];
    //   else: step = flt_7D12EC * a2 * 10.0; if this[0x1B70]: this[0x2414] += step clamp 1.0; else: this[0x2414] -= step clamp 0.0;
    //   *a5 = this[0x2414];   // brake
    //   if this[0x21D4] == 2: this[0x2418] = this[0x21FC];
    //   else: step = flt_7D12EC * a2 * 10.0; if this[0x21F8]: this[0x2418] += step clamp 1.0; else: this[0x2418] -= step clamp 0.0;
    //   *a6 = this[0x2418];   // clutch
    //   if this[0x1B78] == 2 and this[0x1BA4] == 2: this[0x241C] = (this[0x1BA0] <= 0.0) ? this[0x1BCC] : -this[0x1BA0];
    //   else: ramp this[0x241C] by flt_7D12A4 * a2 * 10.0 toward 0, sign-aware, clamp to +-1.0;
    //   *a3 = this[0x241C];   // steering
    //   if this[0x2428]: this[0x2424] = -2; if this[0x20F0] == 0: pick gear from flag ladder (0x1FBC=-1, 0x1FE8=1, 0x2014=2, 0x2040=3, 0x206C=4, 0x2098=5, 0x20C4=6) else 7; if == -2 and byte_7D1370 == 1: 0;
    //   *a8 = this[0x2424];   // gear
    //   if this[0x1C54] == 2: this[0x2420] = this[0x1C7C];
    //   else if this[0x1C78]: this[0x2420] = 1.0;
    //   else: this[0x2420] -= flt_7D1310 * a2 * 10.0 clamp 0.0;
    //   *a7 = this[0x2420];   // handbrake
    // UNRESOLVED: Six read-only globals (0x0059E43C, 0x0059E440, 0x0059E478, 0x0059E5FC, 0x0059E670, 0x0059E8A4) appear in the fact table as read but Hex-Rays folds them into FPU instructions, so they never appear as named references in the .c.
    // UNRESOLVED: The steering fallthrough branch tests (v24 & 0x41) on the decompiler artifact char v18 (an FPU status byte carried over from a prior compare); its origin is unverifiable in the .c, so the exact ramp direction in that path is ambiguous.
    // UNRESOLVED: The float bit-pattern dword literals 1065353216 (1.0f) and -1082130432 (-1.0f) are preserved as written; the gear-field semantics (which of this+0x1FBC/0x1FE8/0x2014/0x2040/0x206C/0x2098/0x20C4 maps to which gear) come from the fills' DERIVED naming, not from the .c.
}
