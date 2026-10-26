// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516937
// Canonical corpus name: VirtualDispatchConditionalValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualDispatchConditionalValue_00516937.c

void UnknownObject::VirtualDispatchConditionalValue()
{
    // Calls the virtual method at slot 0x24 of the dispatch object pointed to by this+0x4 with arguments (a1, 1), then reads the byte flag at this+0xC to pick a result value (200 when non-zero, 100 when zero), stores it at this+0x10 and returns it. Called by StateMachineDispatcher (0050F904) and StateMachineDispatch_f9ab (0050F9AB).
    // CALL: Indirect call through *(this+0x4) + 0x24, the virtual slot of the dispatch object pointed to by this+0x4, with arguments (a1, 1); the packet carries no callee address [field:*(this+0x4):0x00000024, field:this:0x00000004, source:raw]
    // GUARD: Branch on the byte flag at this+0xC: non-zero selects 200, zero selects 100 [field:this:0x0000000C, guard:0, source:raw]
    // ASSIGNMENT: Store the selected result value (200 or 100) at this+0x10 (dword) [field:this:0x00000010, source:raw]
    // RETURN: Return the stored result; called by StateMachineDispatcher (0050F904) and StateMachineDispatch_f9ab (0050F9AB) [function:0x00516937, caller:0x0050F904, caller:0x0050F9AB, source:raw]

    // Conservative worker pseudocode:
    //   (*((void (__cdecl **)(int, int))*(_DWORD*)(a1 + 4) + 36))(a1, 1);
    //   result = *(_BYTE*)(a1 + 12) != 0 ? 200 : 100;
    //   *(_DWORD*)(a1 + 16) = result;
    //   return result;
    // UNRESOLVED: The method called through slot +0x24 and the semantics of its argument 1 are unknown; the packet lists no callee address
    // UNRESOLVED: The meaning of the flag at this+0xC and the 200/100 result values (the existing analysis reads them as a dispatch priority) is DERIVED and not provable from this packet alone
    // UNRESOLVED: Owner object identity is not established by the packet
}
