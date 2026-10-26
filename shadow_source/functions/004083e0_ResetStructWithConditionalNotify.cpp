// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004083E0
// Canonical corpus name: StructInitWithConditionalNotify
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithConditionalNotify_004083e0.c

void UnknownObject::ResetStructWithConditionalNotify()
{
    // Struct reset routine: reads the byte flag at offset 0x15 before the reset, then zeroes the DWORD fields at offsets 0x0, 0x4, 0xC and 0x10, sets the DWORD at offset 0x8 to 1.0f, zeroes the byte at offset 0x14, and finally clears the flag at offset 0x15. If the flag was non-zero before the reset (previously active), ConditionalBranchByFlag is called with 1 as a deactivation notification before the flag is cleared.
    // GUARD: Capture the prior state of the byte flag at offset 0x15: v2 = (this[21] == 0), evaluated BEFORE any field is reset. [guard:0, field:this:0x00000015]
    // ASSIGNMENT: Zero the DWORD at offset 0x0. [field:this:0x00000000]
    // ASSIGNMENT: Zero the DWORD at offset 0x4. [field:this:0x00000004]
    // ASSIGNMENT: Set the DWORD at offset 0x8 to 1065353216, i.e. the float value 1.0f. [field:this:0x00000008]
    // ASSIGNMENT: Zero the DWORD at offset 0xC. [field:this:0x0000000C]
    // ASSIGNMENT: Zero the DWORD at offset 0x10. [field:this:0x00000010]
    // ASSIGNMENT: Zero the byte flag at offset 0x14. [field:this:0x00000014]
    // CALL: When the captured flag was non-zero (v2 false), call ConditionalBranchByFlag with the constant 1 as a deactivation notification. [callee:0x004D8860, field:this:0x00000015, guard:0]
    // ASSIGNMENT: Clear the byte flag at offset 0x15 to 0 after the conditional notification. [field:this:0x00000015]
    // RETURN: Return the call result; on the path where the flag was already 0 the returned result is uninitialized (decompiler artifact). Invoked by DelegationWrapperToFUN00408280, StateInitWithGlobalConstants and CamMan_Post. [function:0x004083E0, caller:0x00408210, caller:0x00408290, caller:0x0040CCE0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4083E0(BYTE* this) {
    //     bool wasActive = (this[21] == 0) == false;
    //     *(DWORD*)this = 0;
    //     *(DWORD*)this + 1 = 0;
    //     *(DWORD*)this + 2 = 1065353216;
    //     *(DWORD*)this + 3 = 0;
    //     *(DWORD*)this + 4 = 0;
    //     this[20] = 0;
    //     if (wasActive) {
    //       int result = ConditionalBranchByFlag(1);
    //       this[21] = 0;
    //       return result;
    //     }
    //   }
    // UNRESOLVED: Return value is uninitialized on the path where the flag at offset 0x15 was already 0; Hex-Rays shows an undefined result.
    // UNRESOLVED: The read-only global dword_8AD298 is flagged by packet facts but appears nowhere in the raw source; its role cannot be grounded here.
}
