// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411570
// Canonical corpus name: StatusFieldCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StatusFieldCopy_00411570.c

void UnknownObject::StatusFieldCopy()
{
    // Copies status field values from the global vehicle block array (base 0x005ECDC8, 18624-byte stride indexed by a2) into three target field arrays carried on this (this+0x4C, this+0x58, this+0x64), each value stored through ShortComputation_e710. The a3 flag selects the source: non-zero reads the vehicle block, zero writes a 0 (reset). Copies 4 fields from block+324 (74-dword stride), 2 fields from block dword indices 377/394, and 8 fields from block+1644 (17-dword stride).
    // ASSIGNMENT: v3 = &unk_5ECDC8 + 18624*a2: base of the selected vehicle status block, striding the global array at 0x005ECDC8 by 18624 bytes per vehicle index [global:0x005ECDC8, source:raw]
    // LOOP: Group 1: do-while of 4 iterations; source pointer starts at block+324 and steps 74 dwords per iteration; target pointer starts at this+0x4C + 144*a2 and steps 36 bytes per iteration [field:this:0x0000004C, global:0x005ECDC8, source:raw]
    // GUARD: Per-copy guard on a3 within group 1: non-zero reads the source field value, zero forces the copied value to 0 (reset) [source:raw]
    // CALL: ShortComputation_e710((this[19] + running offset), value) stores each group-1 status value into the target field array at this+0x4C [callee:0x0040E710, field:this:0x0000004C, source:raw]
    // LOOP: Group 2: for-loop of 2 iterations over the target array at this+0x58; target index is (i + 2*a2) * 36 bytes; source is block dword 377 for i==0 and block dword 394 for i==1 [field:this:0x00000058, global:0x005ECDC8, source:raw]
    // GUARD: Per-copy guard on a3 within group 2: non-zero reads the block field (dword 377/394), zero forces the copied value to 0 [source:raw]
    // CALL: ShortComputation_e710((this[22] + 36*(i + 2*a2)), value) stores each group-2 status value into the target field array at this+0x58 [callee:0x0040E710, field:this:0x00000058, source:raw]
    // LOOP: Group 3: do-while of 8 iterations; source pointer starts at block+1644 and steps 17 dwords per iteration; target pointer starts at this+0x64 + 288*a2 and steps 36 bytes per iteration [field:this:0x00000064, global:0x005ECDC8, source:raw]
    // GUARD: Per-copy guard on a3 within group 3: non-zero reads the source field value, zero forces the copied value to 0 [source:raw]
    // CALL: ShortComputation_e710((this[25] + running offset), value) stores each group-3 status value into the target field array at this+0x64; the last call's result becomes the function return value [callee:0x0040E710, field:this:0x00000064, source:raw]
    // RETURN: Returns the final ShortComputation_e710 result; the function is invoked by VehicleGraphicsSceneLoader (0x004DFCE0) and VehicleResetClear (0x004E09E0) [function:0x00411570, caller:0x004DFCE0, caller:0x004E09E0, source:raw]

    // Conservative worker pseudocode:
    //   base = &unk_5ECDC8 + 18624 * a2;
    //   target1 = this[0x4C/4] + 144 * a2;
    //   src = base + 324;
    //   for (n = 0; n < 4; ++n) {
    //     value = a3 ? *src : 0;
    //     ShortComputation_e710(target1, value);
    //     target1 += 36; src += 74;
    //   }
    //   for (i = 0; i < 2; ++i) {
    //     value = a3 ? ((i == 0) ? base[377] : base[394]) : 0;
    //     ShortComputation_e710(this[0x58/4] + 36 * (i + 2 * a2), value);
    //   }
    //   target3 = this[0x64/4] + 288 * a2;
    //   src = base + 1644;
    //   for (n = 0; n < 8; ++n) {
    //     value = a3 ? *src : 0;
    //     result = ShortComputation_e710(target3, value);
    //     target3 += 36; src += 17;
    //   }
    //   return result;
    // UNRESOLVED: The three groups use different source strides (74 dwords, fixed dword indices 377/394, 17 dwords) and target arrays (this+0x4C, this+0x58, this+0x64); the identity of each individual status field within the vehicle block is not documented
    // UNRESOLVED: Group-2 source dword indices 377 and 394 do not fall on the same layout grid as groups 1 and 3, so the block element semantics remain unknown
}
