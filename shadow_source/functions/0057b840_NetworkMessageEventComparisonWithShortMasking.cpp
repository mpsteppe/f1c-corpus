// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B840
// Canonical corpus name: NetworkMessageEventComparisonWithShortMasking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkMessageEventComparisonWithShortMasking_0057b840.c

void UnknownObject::NetworkMessageEventComparisonWithShortMasking()
{
    // Dereferences the network-event comparison structure stored at this[7] (this+0x1C) and tests it against a two-component query key in a2. Two alternative match patterns inside the event structure are tried: (v2+4 DWORD equal to a2[1] AND the WORD at v2+2 equal to the high half of *a2), or (v2+20 DWORD equal to a2[1] AND the WORD at v2+18 equal to the high half of *a2). Returns false immediately when the event pointer is NULL; otherwise true if either pattern matches.
    // ASSIGNMENT: v2 = this[7]: load the network event comparison structure pointer from this+0x1C [field:this:0x0000001C, source:raw]
    // GUARD: If v2 (the event pointer) is NULL, return false immediately (blocked match) [field:this:0x0000001C, function:0x0057B840, source:raw]
    // CALCULATION: First match pattern: the DWORD at v2+4 (this+0x20) must equal a2[1] AND the WORD at v2+2 (this+0x1E) must equal the high half of *a2 (short-masked key comparison) [field:this:0x0000001E, field:this:0x00000020, source:raw]
    // CALCULATION: Second match pattern: the DWORD at v2+20 (this+0x30) must equal a2[1] AND the WORD at v2+18 (this+0x2E) must equal the high half of *a2 [field:this:0x0000002E, field:this:0x00000030, source:raw]
    // RETURN: Return true when either the first or the second pattern matches, otherwise false [function:0x0057B840, source:raw]
    // CALL: Invoked by three network message paths: sub_57CB50 (0057CB50), NetworkReceivePacket (0057E940) and ThreadSafeMutexQueueWithTimedWait (0057EE80), to match received network events against an event query key [caller:0x0057CB50, caller:0x0057E940, caller:0x0057EE80, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this[7];
    //   if (!v2) return false;
    //   return (*(DWORD*)(v2+4) == a2[1] && *(WORD*)(v2+2) == HIWORD(a2[0]))
    //       || (*(DWORD*)(v2+20) == a2[1] && *(WORD*)(v2+18) == HIWORD(a2[0]));
    // UNRESOLVED: The two-component query key semantics in a2 (what the high-half WORD mask of *a2 selects) are not defined by this function alone
    // UNRESOLVED: Whether the two patterns represent different event record layouts or two variants of the same record is not determinable from the raw source
    // UNRESOLVED: The meaning of this[7] (the event structure) relative to the caller's network objects is unknown
}
