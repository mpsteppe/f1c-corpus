// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050F9AB
// Canonical corpus name: StateMachineDispatch_f9ab
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateMachineDispatch_f9ab_0050f9ab.c

void UnknownObject::StateMachineDispatch_f9ab()
{
    // State-machine dispatch wrapper with extended result handling. Reads the state value at this+0x10; when the state is neither 200 nor 201, writes opcode 18 to the target object's code slot (obj+0x14) with the state as its argument (obj+0x18) and dispatches it through the target vtable before delegating to StateMachineDispatch (0x0050F86A). When the inner dispatch returns 1, returns 1. When it returns 2 and the flag a2 is set, writes opcode 50 to obj+0x14, dispatches it, then calls VirtualDispatchConditionalValue (0x00516937) and returns 2. Other inner results are propagated unchanged.
    // CALCULATION: Read the state machine's own vtable pointer at this+0x0 (used as the target base for opcode dispatch) and the current state value v2 = a1[4] (this+0x10) before any dispatch decisions. [field:this:0x00000000, field:this:0x00000010, source:raw]
    // GUARD: State guard: when v2 equals 200 or 201, skip the initial vtable opcode-18 dispatch entirely and go straight to the inner StateMachineDispatch. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write opcode 18 to the target object's operation-code slot at obj+0x14 (target base from the state machine vtable *a1). [field:obj:0x00000014, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Write the current state value a1[4] into the target object's argument slot at obj+0x18 as the parameter for the opcode-18 dispatch. [field:obj:0x00000018, field:obj:0x00000000, field:this:0x00000010, source:raw]
    // CALL: Dispatch opcode 18 through the target object's vtable: indirect call (*a1)(a1). [field:obj:0x00000000, source:raw]
    // CALL: Delegate to the inner state machine: result = StateMachineDispatch(a1) (0x0050F86A). [callee:0x0050F86A, source:raw]
    // GUARD: Completion guard: when the inner dispatch returns 1, return 1 immediately without further handling. [source:raw]
    // GUARD: Result-2 guard: when the inner dispatch returns 2, enter the extended completion path; the path is further gated on the flag a2. [source:raw]
    // GUARD: Flag guard: on the result-2 path, when a2 is non-zero write opcode 50 to the target's code slot at obj+0x14 and dispatch it through the target vtable (*a1)(a1). [field:obj:0x00000014, field:obj:0x00000000, source:raw]
    // CALL: Call VirtualDispatchConditionalValue(a1) (0x00516937) on the result-2 completion path. [callee:0x00516937, source:raw]
    // RETURN: Return 2 on the result-2 path; otherwise return the inner StateMachineDispatch result (1 or the raw result). [abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int StateMachineDispatch_f9ab(_DWORD* a1, char a2) {
    //     int v2 = a1[4];
    //     if (v2 != 200 && v2 != 201) {
    //       *(_DWORD*)(*a1 + 20) = 18;
    //       *(_DWORD*)(*a1 + 24) = a1[4];
    //       (*(void (__cdecl**)(_DWORD*))*a1)(a1);
    //     }
    //     int result = StateMachineDispatch(a1);
    //     if (result == 1) return 1;
    //     if (result == 2) {
    //       if (a2) {
    //         *(_DWORD*)(*a1 + 20) = 50;
    //         (*(void (__cdecl**)(_DWORD*))*a1)(a1);
    //       }
    //       VirtualDispatchConditionalValue(a1);
    //       return 2;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of states 200 and 201 (the values that bypass the opcode-18 pre-dispatch) is not in the packet.
    // UNRESOLVED: Semantic meaning of opcodes 18 and 50 written to the target object's code slot is not in the packet.
    // UNRESOLVED: The purpose of VirtualDispatchConditionalValue (0x00516937) is not in the packet.
    // UNRESOLVED: The class identities behind the state machine vtable (this) and the target object vtable (obj) are unverified; owner is unknown.
}
