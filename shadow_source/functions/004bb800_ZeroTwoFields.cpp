// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB800
// Canonical corpus name: ZeroTwoFields
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroTwoFields_004bb800.c

void UnknownObject::ZeroTwoFields()
{
    // Two-field zero initializer for an unknown __thiscall object. Writes 0 to this[12] (offset 0x30) and this[41] (offset 0xA4), then returns 0. Called by VehgenScnFileLoader (0x004C6C40), so the target object is created/initialized along the vehicle-gen scene-file load path, but the owning class is unknown.
    // ASSIGNMENT: Write 0 to this[12], the DWORD field at offset 0x30. [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write 0 to this[41], the DWORD field at offset 0xA4. [field:this:0x000000A4, source:raw]
    // RETURN: Return 0; the function has no further effect and contains no guards. [function:0x004BB800, source:raw]

    // Conservative worker pseudocode:
    //   int ZeroTwoFields(int *this) {
    //     this[12] = 0;
    //     this[41] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Owning class and the purpose of the two zeroed fields (offsets 0x30 and 0xA4) are unknown from this packet.
    // UNRESOLVED: The function is only reached from VehgenScnFileLoader (0x004C6C40); the exact point in scene-file parsing is not established.
}
