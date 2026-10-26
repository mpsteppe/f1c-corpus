// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AEB0
// Canonical corpus name: DriverSetupParamLookupByID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverSetupParamLookupByID_0042aeb0.c

void UnknownObject::DriverSetupParamLookupByID()
{
    // Linear lookup over five two-dword setup-param records on the receiver, starting at element 4177 (byte offset 0x4144). Scans the first dword of each record for the key a2, stepping two elements per record; on a match returns the paired second dword (element 2*v2 + 4178), or -1 after five records with no match. Read-only; no globals or callees. Called by AICollision (0x004BEF60).
    // ASSIGNMENT: Seed the record index v2 to 0 before the scan [source:raw]
    // LOOP: Scan up to five records: pointer i starts at this + 4177 (byte offset 0x4144) and advances by two dwords per iteration [field:this:0x00004144, source:raw]
    // GUARD: Exit the loop when the first dword of the current record (*i) equals the key a2 [field:this:0x00004144, source:raw]
    // GUARD: After incrementing v2, if v2 reaches 5 the key was not found and the function returns -1 [function:0x0042AEB0, source:raw]
    // RETURN: On a match return the paired second dword of the matched record, element 2*v2 + 4178 [field:this:0x00004144, function:0x0042AEB0, source:raw]
    // CALL: Invoked by AICollision (0x004BEF60) to resolve a setup parameter from a keyed id [caller:0x004BEF60, source:raw]

    // Conservative worker pseudocode:
    //   v2 = 0;
    //   for (i = this + 4177; *i != a2; i += 2) {
    //     if (++v2 >= 5)
    //       return -1;
    //   }
    //   return this[2*v2 + 4178];
    // UNRESOLVED: The meaning of the key a2 and of the returned paired value is caller-dependent; AICollision (0x004BEF60) is the only known caller
    // UNRESOLVED: Only the record start field (this+0x4144) is evidenced; the receiver type is not identified
    // UNRESOLVED: The paired element 2*v2 + 4178 (byte offset 0x4148 onward) is not listed as a separate field in packet facts
}
