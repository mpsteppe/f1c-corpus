// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599BF0
// Canonical corpus name: LocaleObjectAllocAndVtableSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocaleObjectAllocAndVtableSetup_00599bf0.c

void UnknownObject::LocaleObjectAllocAndVtableSetup()
{
    // Locale/istream object construction with conditional vtable-chain setup. Registers the frame SEH handler, saves the ecx-passed this pointer (v4/v6) to the frame, and only when the guard field at this+0x10 is non-zero applies the base vtable chain: *v4 = unk_5B9C5C, v4[11] = 0, v4[2] = basic_ios vftable, and sets frame completion flags. Regardless of the guard, writes v4[1] = 0 and then the std::basic_istream vftable at v4 + *(*(v4)+4) (the multi-inheritance vtable-adjustment offset), then calls StreamCreationWithFlagInit with the fields at this+0x8 and this+0xC and returns this. Invoked through ten callers.
    // CALL: SEHHandlerInit() registers the frame exception handler located at loc_59D3E6 [callee:0x0058A5D8, global:0x0059D3E6, source:raw]
    // GUARD: v5 = (field at this+0x10 == 0); a zero field means the vtable-chain init block is skipped, a non-zero field means it runs [field:this:0x00000010, guard:0, source:raw]
    // ASSIGNMENT: Save this (v4) into frame slot a1-20 and clear frame slot a1-16 (init-in-progress flag) [source:raw]
    // GUARD: When v5 is false (field 0x10 non-zero), enter the conditional vtable-chain init block [field:this:0x00000010, guard:0, source:raw]
    // ASSIGNMENT: Set the base vtable pointer: *v4 = unk_5B9C5C, clear v4[11], and set v4[2] = std::basic_ios vftable (0x005B9C50), the next level of the chain [global:0x005B9C5C, global:0x005B9C50, source:raw]
    // ASSIGNMENT: Mark init complete: frame slot a1-16 = 1 and clear frame slot a1-4 [source:raw]
    // ASSIGNMENT: Clear v4[1] unconditionally [source:raw]
    // ASSIGNMENT: Load v9 = a1[3] (field at this+0xC) and v8 = a1[2] (field at this+0x8) as the stream-creation parameters [field:this:0x0000000C, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write std::basic_istream vftable (0x005B9C40) at v4 + *(*(v4)+4); the slot read from the vtable is a multi-inheritance vtable-adjustment offset [global:0x005B9C40, source:raw]
    // CALL: StreamCreationWithFlagInit(v8, v9) completes construction of the stream using the parameters at this+0x8 and this+0xC [callee:0x0059A3A9, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return v6 (this pointer) from the constructor [source:raw]
    // CALL: Called by sub_579FF0 (0x00579FF0) [caller:0x00579FF0]
    // CALL: Called by EntityConstructorWrapper (0x0057A980) [caller:0x0057A980]
    // CALL: Called by SingleFunctionCallWrapper_adf0 (0x0057ADF0) [caller:0x0057ADF0]
    // CALL: Called by SingleFunctionCallWrapper_ae70 (0x0057AE70) [caller:0x0057AE70]
    // CALL: Called by sub_585E50 (0x00585E50) [caller:0x00585E50]
    // CALL: Called by SingleFunctionCallWrapper_6f10 (0x00586F10) [caller:0x00586F10]
    // CALL: Called by SingleFunctionCallWrapper_7430 (0x00587430) [caller:0x00587430]
    // CALL: Called by SingleFunctionCallWrapper_76c0 (0x005876C0) [caller:0x005876C0]
    // CALL: Called by SingleFunctionCallWrapper_7a90 (0x00587A90) [caller:0x00587A90]
    // CALL: Called by ThunkToFUN00599958 (0x005997CB) [caller:0x005997CB]

    // Conservative worker pseudocode:
    //   LocaleObjectAllocAndVtableSetup() {
    //     SEHHandlerInit();
    //     v6 = v4;
    //     *(a1 - 20) = v4;
    //     *(a1 - 16) = 0;
    //     if (*(this + 0x10) != 0) {
    //       *v4 = &unk_5B9C5C;
    //       v4[11] = 0;
    //       v4[2] = &basic_ios_vftable;
    //       *(a1 - 16) = 1;
    //       *(a1 - 4) = 0;
    //     }
    //     v4[1] = 0;
    //     v9 = *(this + 0xC);
    //     v8 = *(this + 0x8);
    //     *(v4 + *(*(v4) + 4)) = &basic_istream_vftable;
    //     StreamCreationWithFlagInit(v8, v9);
    //     return v6;
    //   }
    // UNRESOLVED: Owner object identity is not established by the packet; only that it is a locale/istream-family object with a multi-inheritance vtable layout
    // UNRESOLVED: Semantics of v4[11] (cleared to 0) and v4[1] (cleared unconditionally) are inferred from MSVC constructor conventions, not documented
    // UNRESOLVED: Meaning of the guard field at this+0x10 (whether re-init is allowed) is unconfirmed
    // UNRESOLVED: The adjustment offset loaded from *(*(this)+4) and the vtable slot semantics are derived from the raw source text only
}
