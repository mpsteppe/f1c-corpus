// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513B12
// Canonical corpus name: FlagSetterWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetterWithGuard_00513b12.c

void UnknownObject::FlagSetterWithGuard()
{
    // Gated flag-and-value setter on object a2. If a1 (a guard object) is non-null and a2 (the target object) is non-null, ORs bit 8 into the DWORD flag at a2+8, stores a3 into the DWORD at a2+16 and stores the 16-bit a4 into the WORD at a2+20. Returns nothing. Called only from sub_518AAA.
    // GUARD: If a1 is null the function returns immediately without touching the target object. [source:raw]
    // GUARD: If a2 (the target object) is null the writes are skipped entirely. [source:raw]
    // ASSIGNMENT: OR bit 0x08 into the DWORD at a2+8, marking a state flag on the target object. [source:raw]
    // ASSIGNMENT: Store a3 into the DWORD at a2+16. [source:raw]
    // ASSIGNMENT: Store a4 as a 16-bit value into the WORD at a2+20. [source:raw]
    // CALL: Invoked from sub_518AAA (0x00518AAA). [caller:0x00518AAA, source:raw]

    // Conservative worker pseudocode:
    //   void FlagSetterWithGuard(int a1, int a2, int a3, __int16 a4) {
    //     if (!a1 || !a2) return;
    //     *(unsigned int*)(a2 + 8) |= 8u;
    //     *(unsigned int*)(a2 + 16) = a3;
    //     *(unsigned short*)(a2 + 20) = a4;
    //   }
    // UNRESOLVED: The identity of the a1 guard object and the target object a2 is unknown; a2 is not established as a vehicle or generic object.
    // UNRESOLVED: The semantic meaning of the flag bit at a2+8 and the values stored at a2+16 and a2+20 are unknown.
    // UNRESOLVED: The role of the 16-bit a4 parameter and the purpose of the flag OR operation are unproven.
}
