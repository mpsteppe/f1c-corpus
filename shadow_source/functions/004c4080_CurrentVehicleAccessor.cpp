// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C4080
// Canonical corpus name: CurrentVehicleAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CurrentVehicleAccessor_004c4080.c

void UnknownObject::CurrentVehicleAccessor()
{
    // Bounds-checked index accessor. Reads an index (dword_8AC38C), its upper bound (dword_8AC390), and a base pointer (dword_8AC394). If the index is out of range (index >= bound or index < 0) returns 0; otherwise returns base + 1060 * index, i.e. a pointer to array element [index] in an array of 1060-byte stride.
    // GUARD: Bounds guard: return 0 when index dword_8AC38C is >= upper bound dword_8AC390 or negative. [global:0x008AC38C, global:0x008AC390, function:0x004C4080, source:raw]
    // RETURN: Return 0 for an out-of-range index. [function:0x004C4080, source:raw]
    // CALCULATION: Compute element offset 1060 * dword_8AC38C (array stride 1060 bytes). [global:0x008AC38C, function:0x004C4080, source:raw]
    // CALCULATION: Add the computed offset to base dword_8AC394 to form the element address. [global:0x008AC394, function:0x004C4080, source:raw]
    // RETURN: Return base dword_8AC394 + 1060 * index for a valid index. [global:0x008AC38C, global:0x008AC394, function:0x004C4080, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C4080() {
    //     if (dword_8AC38C >= dword_8AC390 || dword_8AC38C < 0)
    //       return 0;
    //     return dword_8AC394 + 1060 * dword_8AC38C;
    //   }
    // UNRESOLVED: The referenced array has 1060-byte stride, not the known vehicle-struct stride, so the element type here is unconfirmed.
    // UNRESOLVED: Semantic meaning of the three globals (index, bound, base) beyond their mechanical roles is not in the packet.
    // UNRESOLVED: Which object owns the globals is unknown; owner kept UNKNOWN.
}
