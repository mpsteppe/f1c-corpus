// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BF0A0
// Canonical corpus name: AIBehaviorInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIBehaviorInitialization_004bf0a0.c

void UnknownObject::AIBehaviorInitialization()
{
    // Initializes per-vehicle AI performance offsets for a race session: stores a session-time base and caller identifier, wires vehicle behavior parameters through sub_4BE760, sets the animation state by engine-wear/session-type mode, then loops over the active vehicle grid assigning randomized speed/time biases via RandomVariationScaler, accumulating the session time offset, updating per-vehicle speed and top-speed fields, and re-sorting AI drivers. Invoked from AIOvertake.
    // ASSIGNMENT: Snapshot vehicle count into v3 and v26 from dword_5C329C for the grid loops. [global:0x005C329C]
    // CALL: Call ArithmeticComparison_a140(&dword_8AB6E4, 1) as an arithmetic comparison helper on a shared global. [callee:0x004BA140, global:0x008AB6E4]
    // ASSIGNMENT: Store the session-time base: this+852 (0x354) = dbl_8AFEA0. [field:this:0x00000354, global:0x008AFEA0]
    // ASSIGNMENT: Store the caller-supplied session identifier: this+856 (0x358) = a2. [field:this:0x00000358, source:raw]
    // GUARD: Select the config/path string source: dword_7CE5EC when non-null, else fallback byte_5EA438. [global:0x007CE5EC, global:0x005EA438]
    // CALCULATION: Compute v24 = dword_7D01A0 * 0.0083333338, a frame-time conversion factor passed into the vehicle behavior setup. [global:0x007D01A0]
    // CALL: Call sub_4BE760(this, *(this + 864), v5, v24) to set up vehicle behavior parameters for this AI session. [callee:0x004BE760, field:this:0x00000360]
    // GUARD: Switch on dword_7CEA5C engine-wear mode: case 1 (with dword_7C56A4 == 7) computes 1.0 / flt_8ACF9C as a time-scaling factor; case 2 takes the animation-setter path directly. [global:0x007CEA5C, global:0x004BF380, global:0x007C56A4, global:0x008ACF9C]
    // CALL: Call AnimationStateSetter(this, 1, state, arg, 1110704128) for both the case-2 branch (state 1, arg 1065353216) and the default branch (state from v6, arg from v22). [callee:0x004BE9E0]
    // LOOP: Zero the 104-entry v27 buffer, then initialize 104 per-slot entries: this + 4*i = -1082130432 and this + 4*i + 416 = 0. [source:raw]
    // GUARD: Per-vehicle guard over the active grid dword_7C54F0: require live slot (state + 13000 != -1 and != 0), lap count state + 16444 below this+860 (0x35C), session/state condition (dword_7C56A4 == 7 or StateFlagsLookup passes), and state + 16484 != 1. [global:0x007C54F0, global:0x007C56A4, callee:0x0042AE90, field:this:0x0000035C]
    // CALL: Call RandomVariationScaler(this, v7, v9, *(float *)(this + 844)) to compute a per-vehicle speed bias stored at this + 4*v8. [callee:0x004BEA10, field:this:0x0000034C]
    // CALCULATION: Offset math: v13 from state + 16452 (zeroed when state + 16532 <= 1), then v14 = (flt_5EA3FC - v13) * (bias / flt_5EA3FC), stored to v27[v8]. [global:0x005EA3FC, source:raw]
    // ASSIGNMENT: Accumulate session time: this+852 (0x354) receives v14 (clamped to >= 0.0), and state + 16536 is set to the clamped sum. [field:this:0x00000354, source:raw]
    // CALCULATION: Track best/top-speed values: state + 16540 is replaced by the slot bias unless it is a smaller positive value; state + 16568 = this+852 - flt_8ACF90 + v27[v8]. [global:0x008ACF90, source:raw]
    // CALL: Call AIDriverSorting(v9) to re-sort the AI driver after updating its timing/performance offsets. [callee:0x004BF390]
    // GUARD: If the processed count state + 16444 reaches this+860 (0x35C) or the a3 flag is set, reset the slot bias to -1082130432 and set state + 16484 to 1 unless it is 3. [field:this:0x0000035C, source:raw]
    // CALCULATION: Final pass: this+852 (0x354) += v23, then write this + 416 + 4*(i-1) = v23 - v27[i-1] for each processed driver; return the processed count. [field:this:0x00000354, source:raw]
    // CALL: Invoked from AIOvertake as the AI performance initialization step for a session. [caller:0x004BEB10]

    // Conservative worker pseudocode:
    //   // Session-time and per-vehicle AI performance initialization for a race session.
    //   v3 = dword_5C329C;
    //   ArithmeticComparison_a140(&dword_8AB6E4, 1);
    //   this[852] = dbl_8AFEA0;
    //   this[856] = a2;
    //   sub_4BE760(this, this[864], dword_7CE5EC ? (char*)dword_7CE5EC : (char*)byte_5EA438, dword_7D01A0 * 0.0083333338);
    //   switch (dword_7CEA5C) {
    //     case 1:
    //       if (dword_7C56A4 == 7) {
    //         v22 = 1.0 / flt_8ACF9C;
    //         if (v22 != 0.0) { v6 = 1; goto setter; }
    //       } else goto case2;
    //       break;
    //     case 2:
    //   case2:
    //       AnimationStateSetter(this, 1, 1, 1065353216, 1110704128); break;
    //     default:
    //       v22 = 0.0; v6 = 0;
    //   setter:
    //       AnimationStateSetter(this, 1, v6, *((unsigned int*)&v22), 1110704128); break;
    //   }
    //   memset(v27, 0, sizeof(v27));
    //   for (i = 0; i < 104; ++i) { this[4*i] = -1082130432; this[4*i + 416] = 0; }
    //   for (v8 = 0; v8 < v26; ++v8) {
    //     v9 = dword_7C54F0[v8];
    //     if (v9[13000] != -1 && v9[13000]) {
    //       v11 = v9[16444];
    //       if (v11 < this[860] && (dword_7C56A4 == 7 || v11 <= StateFlagsLookup(dword_7C54F0[v8])) && v9[16484] != 1) {
    //         v12 = v9[16484];
    //         if (v12 != 3 && v12 != 2) {
    //           this[4*v8] = RandomVariationScaler(this, v7, v9, this[844]);
    //           v13 = v9[16452]; if (v9[16532] <= 1) v13 = 0.0;
    //           ++v9[16444];
    //           v14 = (flt_5EA3FC - v13) * (this[4*v8] / flt_5EA3FC);
    //           v27[v8] = v14; if (!overflow) v23 = v14;
    //           v18 = v14 + this[852]; if (v18 < 0.0) v18 = 0.0;
    //           v9[16536] = v18;
    //           if (v9[16540] <= 0.0 || v9[16540] > this[4*v8]) v9[16540] = this[4*v8];
    //           v9[16568] = this[852] - flt_8ACF90 + v27[v8];
    //           AIDriverSorting(v9);
    //           v7 = v9[16444];
    //           if (v7 >= this[860] || a3) {
    //             this[4*v8] = -1082130432;
    //             if (v9[16484] != 3) v9[16484] = 1;
    //           }
    //         }
    //       }
    //     }
    //   }
    //   this[852] += v23;
    //   for (i = 1; i <= v3; ++i) this[416 + 4*(i-1)] = v23 - v27[i-1];
    //   return v3;
    // UNRESOLVED: Globals flt_59E43C, flt_59E440, dword_5ACDB0 and flt_5ACDE0 are listed in the packet but not referenced by the raw body; roles unresolved.
    // UNRESOLVED: a3 flag semantic (forces the reset path when set) is caller-specific.
    // UNRESOLVED: Per-vehicle state offsets (13000, 16444, 16452, 16484, 16532, 16536, 16540, 16568) reference another object's layout not declared as fields here.
    // UNRESOLVED: The v27 buffer and the this+4*i and this+4*i+416 arrays are per-slot scratch; the this+4*i+416 array byte range is not in the packet field list.
    // UNRESOLVED: The literal values 1065353216 and 1110704128 are preserved as-is; their bit-level float decoding is not asserted.
}
