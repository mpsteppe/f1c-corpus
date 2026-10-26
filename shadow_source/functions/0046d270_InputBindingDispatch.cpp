// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046D270
// Canonical corpus name: InputBindingDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputBindingDispatch_0046d270.c

void UnknownObject::InputBindingDispatch()
{
    // Input binding dispatch: refreshes the sound system, re-initializes the input buffer with default values, creates two UI binding objects by ID (39 and 41) through a vtable factory on this[16], activates one and deactivates the other, then invokes a game-state refresh at loc_41C540 and returns 0.
    // GUARD: If the sound system pointer global dword_5EB10C is non-null, call its vtable method at offset 12 to refresh it. [global:0x005EB10C, source:raw]
    // CALL: Re-initialize the input buffer at global flt_5EA618 with default values via BufferInitWith10fDefaults. [callee:0x004186A0, global:0x005EA618]
    // CALL: Resolve UI binding object ID 39 by calling the vtable factory at offset 28 on the object stored at this[16]; store result in v2. [field:this:0x00000040, field:*(this+0x40):0x0000001C]
    // CALL: Resolve UI binding object ID 41 by calling the same vtable factory at offset 28 on this[16]; store result in v3. [field:this:0x00000040, field:*(this+0x40):0x0000001C]
    // GUARD: If v2 (binding object for ID 39) is non-null, call sub_47C360 on it with parameter 1 to activate it. [callee:0x0047C360]
    // GUARD: If v3 (binding object for ID 41) is non-null, call sub_47C360 on it with parameter 0 to deactivate it. [callee:0x0047C360]
    // CALL: Invoke code location loc_41C540 with the game state pointer global dword_5EB978. [global:0x005EB978, source:raw]
    // RETURN: Return 0 as success. [function:0x0046D270, source:raw]

    // Conservative worker pseudocode:
    //   int InputBindingDispatch(void** this) {
    //     if (dword_5EB10C) {
    //       (*(void (__thiscall **)(int))(*(int*)dword_5EB10C + 12))(dword_5EB10C);
    //     }
    //     BufferInitWith10fDefaults(flt_5EA618);
    //     void* v2 = (*(void* (__thiscall **)(void*, int))(*(void**)this[16] + 28))(this[16], 39);
    //     void* v3 = (*(void* (__thiscall **)(void*, int))(*(void**)this[16] + 28))(this[16], 41);
    //     if (v2) sub_47C360(v2, 1);
    //     if (v3) sub_47C360(v3, 0);
    //     loc_41C540(dword_5EB978);
    //     return 0;
    //   }
    // UNRESOLVED: Identity and behavior of code location loc_41C540 is unknown; it is only observed to receive the global dword_5EB978.
    // UNRESOLVED: Interpretation of sub_47C360 parameter (1 = activate, 0 = deactivate) is inferred from call context, not proven.
    // UNRESOLVED: Meaning of binding IDs 39 and 41 depends on the factory object at this[16] and is not resolved here.
}
