// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423490
// Canonical corpus name: SingleFunctionCallWrapper_3490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_3490_00423490.c

void UnknownObject::ClearEmptyStringBuffer()
{
    // Zeroes the 13-byte global buffer at 0x5EC4C0 (byte_5EC4C0) by clearing bytes 0-3, 4-7, 8-11 and byte 12, then returns a pointer to the buffer base.
    // ASSIGNMENT: Zero bytes 0-3 of the 13-byte buffer at 0x5EC4C0 via a 4-byte write. [global:0x005EC4C0, source:raw, function:0x00423490]
    // ASSIGNMENT: Zero bytes 4-7 of the buffer at 0x5EC4C0. [global:0x005EC4C0, source:raw]
    // ASSIGNMENT: Zero bytes 8-11 of the buffer at 0x5EC4C0. [global:0x005EC4C0, source:raw]
    // ASSIGNMENT: Zero byte 12 of the buffer at 0x5EC4C0. [global:0x005EC4C0, source:raw]
    // RETURN: Return a pointer to the cleared buffer base at 0x5EC4C0. [global:0x005EC4C0, source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   // Clear a 13-byte global string buffer at 0x5EC4C0 and return its address.
    //   buffer_5EC4C0[0..3] = 0;
    //   buffer_5EC4C0[4..7] = 0;
    //   buffer_5EC4C0[8..11] = 0;
    //   buffer_5EC4C0[12] = 0;
    //   return &buffer_5EC4C0;
    // UNRESOLVED: Callees 0x00587B3E (BooleanToIntConversion) and 0x00587BCF (FreeWrapper_7bcf) are listed in the packet but are not called in this function body; their relation to this function is unknown.
    // UNRESOLVED: global:0x004234B0 (loc_4234B0) is read but its role is not described by the packet; likely the return point after the function body.
}
