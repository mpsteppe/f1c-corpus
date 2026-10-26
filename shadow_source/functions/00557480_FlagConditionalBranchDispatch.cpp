// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00557480
// Canonical corpus name: FlagConditionalBranchDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagConditionalBranchDispatch_00557480.c

void UnknownObject::FlagConditionalBranchDispatch()
{
    // __thiscall dispatcher that selects one of two guarded subroutines based on a flag bit (0x8) at byte offset +32 of argument a2. When the bit is set it calls sub_557670(a2); otherwise it calls sub_557CE0(this, a2). Either callee returning non-zero makes the function return -1; otherwise it returns 0. The 'this' pointer is forwarded only to the else-branch callee.
    // GUARD: Read the byte at a2 + 32 and test bit 0x8 to choose between the two branches. [source:raw]
    // CALL: When flag bit 0x8 is set, call sub_557670(a2); a non-zero return value causes the function to return -1. [callee:0x00557670]
    // CALL: When flag bit 0x8 is clear, call sub_557CE0(this, a2); a non-zero return value causes the function to return -1. [callee:0x00557CE0]
    // RETURN: Return -1 if the selected guarded callee reported failure, otherwise return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_557480(const CHAR *this, int a2) {
    //     if ((*(BYTE*)(a2 + 32) & 8) != 0) {
    //       if (sub_557670(a2)) return -1;
    //     } else if (sub_557CE0(this, a2)) {
    //       return -1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of argument a2 and the flag semantics of bit 0x8 at a2 + 32.
    // UNRESOLVED: Semantics of the two callees sub_557670 and sub_557CE0 and why only the else branch receives 'this'.
    // UNRESOLVED: Role of the __thiscall 'this' pointer given the function body only forwards it.
}
