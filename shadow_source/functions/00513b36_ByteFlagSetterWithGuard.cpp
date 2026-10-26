// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513B36
// Canonical corpus name: FlagSetterWithGuard_3b36
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetterWithGuard_3b36_00513b36.c

void UnknownObject::ByteFlagSetterWithGuard()
{
    // Gated byte-flag setter on object a2. If a1 (a guard object) is non-null and a2 (the target object) is non-null, ORs bit 8 into the BYTE at a2+9 and stores the byte a3 into the BYTE at a2+44. Returns nothing. Called from sub_50210E and from sub_513B51.
    // GUARD: If a1 is null the function returns immediately without touching the target object. [source:raw]
    // GUARD: If a2 (the target object) is null the writes are skipped entirely. [source:raw]
    // ASSIGNMENT: OR the value 8 into the BYTE at a2+9, marking a state flag on the target object. [source:raw]
    // ASSIGNMENT: Store the byte a3 into the BYTE at a2+44. [source:raw]
    // CALL: Invoked from sub_50210E (0x0050210E). [caller:0x0050210E, source:raw]
    // CALL: Invoked from sub_513B51 (0x00513B51). [caller:0x00513B51, source:raw]

    // Conservative worker pseudocode:
    //   void ByteFlagSetterWithGuard(int a1, int a2, char a3) {
    //     if (!a1 || !a2) return;
    //     *(unsigned char*)(a2 + 9) |= 8u;
    //     *(unsigned char*)(a2 + 44) = a3;
    //   }
    // UNRESOLVED: The identity of the a1 guard object and the target object a2 is unknown; a2 is not established as a vehicle or generic object.
    // UNRESOLVED: The semantic meaning of the flag bit at a2+9 and the value stored at a2+44 is unknown.
    // UNRESOLVED: Whether the two callers exercise different flag/value meanings is not determinable from this packet.
}
