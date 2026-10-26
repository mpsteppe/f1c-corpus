// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC330
// Canonical corpus name: FieldCopy_c330
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldCopy_c330_004bc330.c

void UnknownObject::CopyField24To2C()
{
    // Unconditional field copy: reads the int at this+0x24 (dword index 9), writes it to this+0x2C (dword index 11), and returns the copied value. Invoked by MultiplayerVehiclePlacement and RestartGate.
    // CALCULATION: Reads the int at this+0x24 (dword index 9) as result [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Writes result to this+0x2C (dword index 11), the destination field [field:this:0x0000002C, source:raw]
    // RETURN: Returns result, the copied value [source:raw]
    // CALL: Invoked by MultiplayerVehiclePlacement and RestartGate to copy the field pair [caller:0x0042CF10, caller:0x004A0FD0, abi:lead]

    // Conservative worker pseudocode:
    //   result = this[9];
    //   this[11] = result;
    //   return result;
    // UNRESOLVED: The meaning of the 0x24/0x2C field pair and the owner class of this are unknown
}
