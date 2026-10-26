// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FDF0
// Canonical corpus name: ConditionalDispatchWithCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatchWithCleanup_0048fdf0.c

void UnknownObject::ConditionalDispatchWithCleanup()
{
    // Conditional delegation dispatch. Loads the sub-object pointer at this+0x30; when non-null it calls ConditionalDelegation_6460 passing the sub-object's dword index 33 (byte offset 0x84) as the parameter, calls OffsetAccumulator with the incoming a2/a3 offsets, then invokes the vtable slot at byte offset 0x2C on the sub-object with the literal argument 1 and returns that result. When this+0x30 is null the function returns an uninitialized result value.
    // GUARD: Load the sub-object pointer from this+0x30 into v4; the delegation body runs only when it is non-null [field:this:0x00000030, source:raw]
    // CALL: ConditionalDelegation_6460 invoked on the sub-object with its dword index 33 (byte offset 0x84) value as the second argument [callee:0x00486460, source:raw]
    // CALL: OffsetAccumulator invoked with the incoming a2 and a3 offsets to accumulate positional data [callee:0x0049AA30, source:raw]
    // CALL: Indirect call through the sub-object vtable: entry at byte offset 0x2C (dword entry 11) called with the sub-object and literal 1, its result returned [field:*(this+0x30):0x0000002C, source:raw]
    // RETURN: On the null-guard path the function returns the uninitialized result variable without touching the sub-object [source:raw]

    // Conservative worker pseudocode:
    //   DWORD* v4 = (DWORD*)this[12];               // *(this + 0x30)
    //   if (v4) {
    //       ConditionalDelegation_6460(v4, v4[33]);  // index 33 = byte offset 0x84
    //       OffsetAccumulator(a2, a3);
    //       return (*(int (__thiscall **)(DWORD, int))(*(DWORD*)v4 + 44))(v4, 1);  // vtable slot at byte offset 0x2C
    //   }
    //   return result;  // uninitialized on this path
    // UNRESOLVED: Field this+0xB4 is recorded as read for the delegation parameter by the deterministic facts, but the raw source passes v4[33] (offset 0x84) instead; the two cannot be reconciled from this packet alone
    // UNRESOLVED: The null-guard path returns an uninitialized result value, which suggests the caller only reads the return when the sub-object existed
    // UNRESOLVED: The purpose of the literal argument 1 to the vtable slot and the semantics of OffsetAccumulator's a2/a3 are not established here
}
