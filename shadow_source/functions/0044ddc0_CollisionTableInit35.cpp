// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044DDC0
// Canonical corpus name: CollisionTableInit35
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionTableInit35_0044ddc0.c

void UnknownObject::CollisionTableInit35()
{
    // Initializes a collision table entry: stores ID value 53 in the first dword of the entry (dword_7CCDF8) and zeroes the five following table fields (dword_7CCDFC through dword_7CCE0C). All writes are unconditional; the function returns 0.
    // ASSIGNMENT: Write the literal 53 (table entry ID) to dword_7CCDF8[0]. [global:0x007CCDF8, source:raw]
    // ASSIGNMENT: Zero dword_7CCDFC. [global:0x007CCDFC, source:raw]
    // ASSIGNMENT: Zero dword_7CCE00. [global:0x007CCE00, source:raw]
    // ASSIGNMENT: Zero dword_7CCE04. [global:0x007CCE04, source:raw]
    // ASSIGNMENT: Zero dword_7CCE08. [global:0x007CCE08, source:raw]
    // ASSIGNMENT: Zero dword_7CCE0C. [global:0x007CCE0C, source:raw]
    // RETURN: Return 0 (result initialized to 0 and never modified). [source:raw]

    // Conservative worker pseudocode:
    //   int CollisionTableInit35() {
    //     int result = 0;
    //     dword_7CCDF8[0] = 53;
    //     dword_7CCDFC = 0;
    //     dword_7CCE00 = 0;
    //     dword_7CCE04 = 0;
    //     dword_7CCE08 = 0;
    //     dword_7CCE0C = 0;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the 53 literal (fill labels dword_7CCDF8 'SteeringSensitivity', which conflicts with the canonical table-entry interpretation; unverified either way).
    // UNRESOLVED: Meaning of the five zeroed table fields; no reader evidence in this packet.
}
