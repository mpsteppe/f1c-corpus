// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563DC0
// Canonical corpus name: NetworkSocketArrayCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkSocketArrayCleanup_00563dc0.c

void UnknownObject::NetworkSocketArrayCleanup()
{
    // Closes every socket in a network socket array. Reads the entry count from this+0x6C; when positive, iterates the array whose base pointer is this+0x8, calling closesocket on the socket handle at each entry and advancing by a fixed 28-byte stride per entry. Always returns 0. Called by sub_563AB0.
    // ASSIGNMENT: i = 0; initialize the loop counter. [function:0x00563DC0, source:raw]
    // GUARD: Enter the loop only when the signed count at this+0x6C is greater than 0; otherwise skip and return 0. [guard:0, field:this:0x0000006C, function:0x00563DC0, source:raw]
    // LOOP: do/while loop running exactly count times; each pass closes one socket and advances the byte offset by 28. [field:this:0x0000006C, function:0x00563DC0, source:raw]
    // CALL: closesocket(*(_DWORD *)(base + off)); dereference the array entry at this+0x8 plus the running offset and close the socket handle stored at entry offset 0. [callee:0x0059865A, field:this:0x00000008, function:0x00563DC0, source:raw]
    // ASSIGNMENT: Per iteration: i += 1 and off += 28; continue while i < count. [field:this:0x0000006C, function:0x00563DC0, source:raw]
    // RETURN: Return 0 in both the empty and non-empty cases. [function:0x00563DC0, source:raw]

    // Conservative worker pseudocode:
    //   int NetworkSocketArrayCleanup(void *this) {
    //     int i = 0;
    //     if (this[27] > 0) {
    //       int off = 0;
    //       do {
    //         closesocket(*(_DWORD *)(this[2] + off));
    //         i++;
    //         off += 28;
    //       } while (i < this[27]);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The owning object type is unidentified; this+0x8 array base and this+0x6C count belong to an unknown network container class.
    // UNRESOLVED: The socket entry is 28 bytes wide and the handle sits at entry offset 0, but the remaining 24 bytes of each entry are not described by the packet.
    // UNRESOLVED: The closesocket return value is ignored.
    // UNRESOLVED: Caller sub_563AB0 (0x00563AB0) is the only known caller; the teardown context around it is unknown.
}
