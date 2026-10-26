// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048F300
// Canonical corpus name: StateResetConditionalVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateResetConditionalVirtualCall_0048f300.c

void UnknownObject::StateResetConditionalVirtualCall()
{
    // Unconditionally zeroes two byte flags (this+0x17D, this+0x17E). Reads a state field (this+0x104); if it is not 4, resets it to 0 and dispatches a virtual call through the object vtable (slot at vtable+0x40) with argument 0. Returns 0. Called by LinkedListTraversalVirtualCall (00477160).
    // ASSIGNMENT: Zero byte flag at this+0x17D [field:this:0x0000017D]
    // ASSIGNMENT: Zero byte flag at this+0x17E [field:this:0x0000017E]
    // GUARD: If state field this+0x104 is not equal to 4, proceed with state reset and virtual dispatch; if equal to 4, skip both [field:this:0x00000104]
    // ASSIGNMENT: Reset state field this+0x104 to 0 when it was not 4 [field:this:0x00000104]
    // CALCULATION: Read the vtable pointer from this+0x0 to resolve the virtual dispatch slot [field:this:0x00000000]
    // CALL: Call the virtual method at vtable+0x40 (slot read through obj+0x40) with argument 0 [field:obj:0x00000040, field:this:0x00000000]
    // RETURN: Return 0 [function:0x0048F300, source:raw]

    // Conservative worker pseudocode:
    //   *(byte*)(this+0x17D) = 0;
    //   *(byte*)(this+0x17E) = 0;
    //   if (this[65] != 4) {
    //     this[65] = 0;
    //     (*(void (__stdcall **)(int))(*(int*)this + 0x40))(0);
    //   }
    //   return 0;
    // UNRESOLVED: The virtual method dispatched at vtable+0x40 is dynamic; its concrete target and the meaning of the constant 4 in the state comparison are not resolvable from this packet
}
