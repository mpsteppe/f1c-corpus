// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B28F0
// Canonical corpus name: sub_4B28F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B28F0_004b28f0.c

void UnknownObject::ScaledByteShortRead()
{
    // Reads two packed scalar fields out of an entry of the container selected by a2 and writes them scaled to float output pointers. The byte field at byte-index a2+18 is scaled by 0.00390625 (1/256) into *a3; the signed 16-bit field at byte-index 2*a2+22 is scaled by 0.0099999998 (1/100) into *a4, and the raw 16-bit value is returned. Called per physics timestep from VehiclePhysicsTimeStep.
    // CALCULATION: Write *a3 = (double)this[a2 + 18] * scale, scaling the 8-bit field by 0.00390625 (1/256); the scale constant is a read-only float backed by a module global [global:0x0059E444, source:raw]
    // CALCULATION: Read a signed 16-bit value at byte-index 2*a2+22 and write *a4 = (double)result * scale, scaling by 0.0099999998 (1/100); the scale constant is a read-only float backed by a module global [global:0x005AC988, source:raw]
    // RETURN: Return the raw signed 16-bit value read from the short field; invoked each timestep by VehiclePhysicsTimeStep [caller:0x004C73F0, function:0x004B28F0, source:raw]

    // Conservative worker pseudocode:
    //   *a3 = (double)this[a2 + 18] * 0.00390625;
    //   short_val = *(signed short*)&this[2 * a2 + 22];
    //   *a4 = (double)short_val * 0.0099999998;
    //   return short_val;
    // UNRESOLVED: Which module global (flt_59E444 or flt_5AC988) backs which of the two scale constants (0.00390625 vs 0.0099999998) cannot be determined from this packet alone
    // UNRESOLVED: The meaning of the a2 entry selector and what array the byte/short fields belong to is not documented
}
