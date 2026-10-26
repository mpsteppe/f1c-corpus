// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599B86
// Canonical corpus name: ObjectConstructorWithVtableSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVtableSetup_00599b86.c

void UnknownObject::OStreamObjectConstructWithVtable()
{
    // Object constructor with SEH and vtable chain setup. Registers the frame SEH handler, saves the ecx-passed this pointer (v3) to the frame, then only when the guard field at this+0xC is non-zero applies the base vtable chain: *v3 = unk_5B9C54, v3[10] = 0, v3[1] = basic_ios vftable, and sets frame completion flags. Regardless of the guard, writes the basic_ostream vftable at this + *(*(this)+4) (the multi-inheritance vtable-adjustment offset), then calls sub_59A8FA on that adjusted pointer and returns this.
    // CALL: SEHHandlerInit() registers the frame exception handler located at loc_59D3C2 [callee:0x0058A5D8, global:0x0059D3C2, source:raw]
    // GUARD: v4 = (*(this + 0xC) == 0); a zero field means the vtable-chain init block is skipped, a non-zero field means it runs [field:this:0x0000000C, guard:0, source:raw]
    // ASSIGNMENT: Save this (v3) into frame slot a1-20 and clear frame slot a1-16 (init-in-progress flag) [source:raw]
    // GUARD: When v4 is false (field 0xC non-zero), enter the conditional vtable-chain init block [field:this:0x0000000C, guard:0]
    // ASSIGNMENT: Set the base vtable pointer: *v3 = unk_5B9C54, and clear v3[10] [global:0x005B9C54, source:raw]
    // ASSIGNMENT: Set v3[1] = std::basic_ios vftable (0x005B9C50), the next level of the chain [global:0x005B9C50, source:raw]
    // ASSIGNMENT: Mark init complete: frame slot a1-16 = 1 and clear frame slot a1-4 [source:raw]
    // ASSIGNMENT: Write std::basic_ostream vftable (0x005B9C48) at this + *(*(this)+4); the slot read from the vtable is a multi-inheritance vtable-adjustment offset [global:0x005B9C48, source:raw]
    // CALL: sub_59A8FA(this + *(*(this)+4)) completes construction of the vtable-adjusted subobject [callee:0x0059A8FA, source:raw]
    // RETURN: Return v5 (this pointer) from the constructor [source:raw]
    // CALL: Called by sub_5998C0, DelegationWithFixedArgs_9904, and SingleFunctionCallWrapper_9933 [caller:0x005998C0, caller:0x00599904, caller:0x00599933]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   v5 = v3;
    //   *(a1 - 20) = v3;
    //   *(a1 - 16) = 0;
    //   if (*(this + 0xC) != 0) {
    //     *v3 = &unk_5B9C54;
    //     v3[10] = 0;
    //     v3[1] = &basic_ios_vftable;
    //     *(a1 - 16) = 1;
    //     *(a1 - 4) = 0;
    //   }
    //   *(v3 + *(*(v3) + 4)) = &basic_ostream_vftable;
    //   sub_59A8FA(v3 + *(*(v3) + 4));
    //   return v5;
    // UNRESOLVED: Owner object identity is not established by the packet; only that it is an ostream-family object with a multi-inheritance vtable layout
    // UNRESOLVED: Semantics of v3[10] (cleared to 0) and of the frame slots a1-20/a1-16/a1-4 are inferred from MSVC constructor/SEH conventions, not documented
    // UNRESOLVED: Meaning of the guard field at this+0xC (whether re-init is allowed) is unconfirmed
    // UNRESOLVED: The adjustment offset loaded from *(*(this)+4) and the vtable slot semantics are derived from the raw source text only
}
