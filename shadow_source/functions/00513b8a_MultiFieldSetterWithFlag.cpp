// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513B8A
// Canonical corpus name: MultiFieldSetterWithFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldSetterWithFlag_00513b8a.c

void UnknownObject::MultiFieldSetterWithFlag()
{
    // Gated multi-field setter on object a2. If a1 and a2 are both non-null, conditionally stores a3 into the DWORD at a2+48 (only when a3 is non-zero); when a5 is non-null copies a 12-byte structure from a5 into a2+52..a2+60 (DWORD at +52, DWORD at +56, WORD at +60) and defaults a4 to 1 if it is zero; finally ORs bit 0x10 into the DWORD flag at a2+8 and stores a4 into the WORD at a2+22. Returns nothing. Called only from sub_518E18.
    // GUARD: If a1 is null or a2 (the target object) is null the function returns immediately without any writes. [source:raw]
    // ASSIGNMENT: If a3 is non-zero, store a3 into the DWORD at a2+48. [source:raw]
    // GUARD: The block copying the structure and applying the a4 default is entered only when a5 (a source structure pointer) is non-null. [source:raw]
    // ASSIGNMENT: Copy the DWORD at a5 into the DWORD at a2+52. [source:raw]
    // ASSIGNMENT: Copy the DWORD at a5+4 into the DWORD at a2+56. [source:raw]
    // ASSIGNMENT: Copy the WORD at a5+8 into the WORD at a2+60. [source:raw]
    // STATE_TRANSITION: If a4 is zero, set its low word to 1 as a default value. [source:raw]
    // ASSIGNMENT: OR bit 0x10 into the DWORD at a2+8, marking a state flag on the target object. [source:raw]
    // ASSIGNMENT: Store a4 into the WORD at a2+22. [source:raw]
    // CALL: Invoked from sub_518E18 (0x00518E18). [caller:0x00518E18, source:raw]

    // Conservative worker pseudocode:
    //   void MultiFieldSetterWithFlag(int a1, int a2, int a3, int a4, int a5) {
    //     if (!a1 || !a2) return;
    //     if (a3) *(unsigned int*)(a2 + 48) = a3;
    //     if (a5) {
    //       *(unsigned int*)(a2 + 52) = *(unsigned int*)a5;
    //       *(unsigned int*)(a2 + 56) = *(unsigned int*)(a5 + 4);
    //       *(unsigned short*)(a2 + 60) = *(unsigned short*)(a5 + 8);
    //       if (!a4) a4 = 1;
    //     }
    //     *(unsigned int*)(a2 + 8) |= 0x10u;
    //     *(unsigned short*)(a2 + 22) = a4;
    //   }
    // UNRESOLVED: The identity of the a1 guard object, the target object a2 and the source structure a5 is unknown.
    // UNRESOLVED: The semantics of the fields at a2+48..a2+60 and the meaning of the copied structure from a5 are unproven.
    // UNRESOLVED: The meaning of the flag bit at a2+8 and the default-value behavior of a4 are unknown.
    // UNRESOLVED: The condition on a3 (write only when non-zero) suggests an optional parameter, but its purpose is not established.
}
