// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004670E0
// Canonical corpus name: SwitchOnActionIDVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwitchOnActionIDVirtualCall_004670e0.c

void UnknownObject::SwitchOnActionIDVirtualCall()
{
    // Dispatches on an action ID derived from this[205] minus 236. When the value is at most 0xB1, a jump table (byte_46713C) selects the case: case 0 and case 1 invoke a virtual method at vtable+28 on the dword_7CD8C0 dispatch interface with argument 14 or 11 respectively, and when the call returns nonzero ObjectNameComparison runs on this; case 2 returns 0 immediately. All other paths return 0.
    // CALCULATION: v2 = this[205] - 236: compute the action index from the field at this+0x334. [field:this:0x00000334, source:raw]
    // GUARD: if ( v2 <= 0xB1 ) enter the switch dispatch; larger values fall through to return 0. [source:raw]
    // STATE_TRANSITION: Switch on byte_46713C[v2] using jump table base jpt_4670FC to select case 0, 1, or 2. [global:0x00467130, global:0x0046713C, source:raw]
    // CALL: Case 0: invoke the virtual method at vtable+28 on dword_7CD8C0 with argument 14. [global:0x007CD8C0, source:raw]
    // CALL: Case 1: invoke the virtual method at vtable+28 on dword_7CD8C0 with argument 11. [global:0x007CD8C0, source:raw]
    // GUARD: if ( v3 ) (the shared path after cases 0 and 1) call ObjectNameComparison(this). [callee:0x00477280, source:raw]
    // CALL: Call ObjectNameComparison(this) when the dispatch returned nonzero. [callee:0x00477280, source:raw]
    // RETURN: Case 2 and the fall-through path both return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int SwitchOnActionIDVirtualCall(_DWORD *this) {
    //     unsigned int v2 = this[205] - 236;
    //     if ( v2 <= 0xB1 ) {
    //       switch ( byte_46713C[v2] ) {
    //         case 0:
    //           v3 = vtableMethod(dword_7CD8C0, 14);
    //           goto check;
    //         case 1:
    //           v3 = vtableMethod(dword_7CD8C0, 11);
    //         check:
    //           if ( v3 )
    //             ObjectNameComparison(this);
    //           break;
    //         case 2:
    //           return 0;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the argument codes 14 and 11 passed to the dword_7CD8C0 virtual method is unknown.
    // UNRESOLVED: Identity of the vtable+28 method on dword_7CD8C0 and what ObjectNameComparison validates is unknown.
    // UNRESOLVED: jpt_4670FC (0x00467130) is referenced only as the jump-table base for byte_46713C indexing; its full contents are not evidenced here.
}
