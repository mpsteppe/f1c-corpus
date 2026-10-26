// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515EBC
// Canonical corpus name: VtableFunctionPointerWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VtableFunctionPointerWrite_00515ebc.c

void UnknownObject::VtableFunctionPointerWrite()
{
    // Reads the sub-object pointer stored at this+0x18C, writes the global UIScreenStateMachine pointer (0x00515DF2) into that sub-object's first dword (offset 0x0), and returns the sub-object pointer. Unconditional, no branches.
    // ASSIGNMENT: Read the sub-object pointer at this+0x18C. [field:this:0x0000018C, source:raw]
    // ASSIGNMENT: Write the UIScreenStateMachine global pointer into the first dword (offset 0x0) of the sub-object. [field:*(this+0x18C):0x00000000, global:0x00515DF2, source:raw]
    // RETURN: Return the sub-object pointer. [function:0x00515EBC, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_515EBC(int this) {
    //     _DWORD* sub = *(_DWORD**)(this + 0x18C);
    //     sub[0] = UIScreenStateMachine;
    //     return sub;
    //   }
    // UNRESOLVED: Semantic role of the sub-object and of storing the UI screen state machine pointer into its first dword depend on the caller and the receiving UI object, which are not visible in this packet.
    // UNRESOLVED: Purpose of the returned sub-object pointer is unresolved from this packet alone.
}
