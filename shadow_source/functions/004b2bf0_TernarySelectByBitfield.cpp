// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2BF0
// Canonical corpus name: TernarySelectByBitfield
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TernarySelectByBitfield_004b2bf0.c

void UnknownObject::TernarySelectByBitfield()
{
    // Selector that reads a 2-bit classification field at this+0xF, masks it with 3, and returns one of four double constants: mask 0 returns 0.69999999, mask 1 returns 0.80000001, mask 2 returns 0.89999998, mask 3 returns 1.0. Called by VehicleOrientationFromEulerAngles (004b2dd0) and sub_4B32A0 (004b32a0) as a scalar blend/threshold factor.
    // CALCULATION: Reads the 2-bit field at this+0xF and masks it with 3 to select among the four return constants [field:this:0x0000000F, source:raw]
    // RETURN: Mask value 0 (default case) returns the constant 0.69999999 [source:raw]
    // RETURN: Mask value 1 returns the constant 0.80000001 [source:raw]
    // RETURN: Mask value 2 returns the constant 0.89999998 [source:raw]
    // RETURN: Mask value 3 returns the constant 1.0 [source:raw]
    // CALL: Invoked by VehicleOrientationFromEulerAngles (004b2dd0) and sub_4B32A0 (004b32a0) to obtain the scalar factor [caller:0x004B2DD0, caller:0x004B32A0, source:raw]

    // Conservative worker pseudocode:
    //   mask = (*(int*)((char*)this + 0xF)) & 3;
    //   switch (mask) {
    //     case 1: return 0.80000001;
    //     case 2: return 0.89999998;
    //     case 3: return 1.0;
    //     default: return 0.69999999;
    //   }
    // UNRESOLVED: Four read-only globals flagged by packet facts (flt_59E43C, flt_59E6E8, flt_59E824, flt_59E8CC) never appear in the raw decompiled source; the skeleton fill labels them physics thresholds, unverifiable from this packet
}
