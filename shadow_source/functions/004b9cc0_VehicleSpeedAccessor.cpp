// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9CC0
// Canonical corpus name: VehicleSpeedAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleSpeedAccessor_004b9cc0.c

void UnknownObject::VehicleSpeedAccessor()
{
    // Read accessor: loads an object pointer from this[0] (offset 0x0), reads a float at offset 0xF34 (3892) of that nested object, and returns it widened to double.
    // CALCULATION: Load object pointer from this[0] (offset 0x0), then read the float at offset 0xF34 of the nested object (0xF34 = 3892). [field:this:0x00000000, field:obj:0x00000F34, source:raw]
    // RETURN: Return the loaded float value widened to double. [source:raw, function:0x004B9CC0]

    // Conservative worker pseudocode:
    //   double VehicleSpeedAccessor(void *this) {
    //     return *(float *)(*(_DWORD*)this + 3892);
    //   }
    // UNRESOLVED: Type and identity of the nested object behind this[0] are unknown; confirmation that the float at 0xF34 represents vehicle speed is not established by this packet.
}
