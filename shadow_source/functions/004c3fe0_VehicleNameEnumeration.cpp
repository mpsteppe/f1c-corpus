// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C3FE0
// Canonical corpus name: VehicleNameEnumeration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleNameEnumeration_004c3fe0.c

void UnknownObject::VehicleNameEnumeration()
{
    // Searches a string table for a query name. Walks dword_8AC390 entries at dword_8AC394 (1060-byte stride), taking the basename of each entry (segment after the final backslash), defaulting null entries to byte_5EA438, and comparing the basename against a1 via sub_596C80 with length strlen(a1). On a match it stores the matched index in dword_8AC38C and returns the comparison result; on exhaustion or an empty table it sets dword_8AC38C = 0 and returns the entry count. Called by TwoCallDelegation (004C7B20). Prelabel marks it a structural twin of VehicleLookupByName (004c3f80).
    // CALCULATION: v1 = strlen(a1) + 1, the query length including terminator used for the comparison [source:raw]
    // GUARD: If dword_8AC390 (entry count) is zero or negative, sets dword_8AC38C = 0 and returns the count [global:0x008AC390, global:0x008AC38C, source:raw]
    // LOOP: Walks the string table at dword_8AC394 from index 0 up to dword_8AC390, advancing 1060 bytes per entry [global:0x008AC394, global:0x008AC390, source:raw]
    // ASSIGNMENT: v5 = entry string at dword_8AC394 + index*1060; null entries fall back to byte_5EA438 [global:0x005EA438, source:raw]
    // CALCULATION: Extracts the basename by scanning to the end of the string and back to the final backslash (0x5C), then advancing past it [source:raw]
    // CALL: sub_596C80(basename, a1, v1 - 1) compares the basename with the query string; a zero result is a match [callee:0x00596C80, source:raw]
    // ASSIGNMENT: On a match dword_8AC38C = matched index v3; on table exhaustion or an empty table it is set to 0 [global:0x008AC38C, source:raw]
    // RETURN: Returns the comparison result (0) when a match was found, or the entry count dword_8AC390 when none matched [global:0x008AC390, callee:0x00596C80, source:raw]
    // CALL: Invoked by TwoCallDelegation as one of the vehicle name lookup paths [caller:0x004C7B20, source:raw]

    // Conservative worker pseudocode:
    //   queryLen = strlen(a1) + 1;
    //   count = dword_8AC390;
    //   if (count <= 0) {
    //       dword_8AC38C = 0;
    //       return count;
    //   }
    //   for (idx = 0; idx < count; ++idx) {
    //       name = *(const char**)(dword_8AC394 + idx * 1060);
    //       if (name == NULL) name = &byte_5EA438;
    //       end = name + strlen(name);
    //       base = end;
    //       if (end > name) {
    //           while (*base != '\\') {
    //               if (--base <= name) break;
    //           }
    //           ++base;
    //       }
    //       cmp = sub_596C80(base, a1, queryLen - 1);
    //       if (cmp == 0) {
    //           dword_8AC38C = idx;
    //           return cmp;
    //       }
    //   }
    //   dword_8AC38C = 0;
    //   return count;
    // UNRESOLVED: The string table stride (1060 bytes) and entry layout at dword_8AC394 are not evidenced; dword_8AC38C as matched-index vs zero is inferred from control flow
    // UNRESOLVED: sub_596C80's exact comparison semantics (case sensitivity, length handling) are unproven
    // UNRESOLVED: Prelabel cluster_copy identifies 004c3f80 (VehicleLookupByName) as a structural twin; the shared behavior is not independently verified
}
