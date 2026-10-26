// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587A90
// Canonical corpus name: SingleFunctionCallWrapper_7a90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_7a90_00587a90.c

void UnknownObject::localeStaticsInit()
{
    // One-time thread-safe initialization of global locale/CEH runtime objects. Installs an SEH handler over unk_8D3E3C, uses the dword_5EA04C guard counter to detect the first call (negative becomes 1 and construction runs; otherwise it is incremented), then constructs a chain of locale/CEH static objects inside a protected critical section.
    // CALL: Install SEH handler over global unk_8D3E3C: SEHHandlerInit(&unk_8D3E3C). [global:0x008D3E3C, source:raw]
    // ASSIGNMENT: Save the incoming ecx value (v1) into caller slot a1-20 and zero the a1-16 slot used as the protected object. [source:raw]
    // CALL: Enter the one-time-init critical section: sub_59A54D(a1-16). [source:raw]
    // GUARD: Guard dword_5EA04C: if negative (first call) set it to 1 and mark construction path (v2=1); otherwise increment it and skip construction (v2=0). [source:raw]
    // CALL: Leave the one-time-init critical section: sub_59A5E9(a1-16). [source:raw]
    // GUARD: If v2 (first-call flag) run the static-locale construction block. [source:raw]
    // CALL: Construct static locale/CEH objects: LocaleObjectConstructorWithVTableSetup for unk_8D4510/off_5E6748, unk_8D44B8/unk_5E6768 and unk_8D45A0/unk_5E6788; LocaleObjectAllocAndVtableSetup for dword_8D4478; CEHFrameSetup frames for byte_8D4568, dword_8D4400 and dword_8D4440; links CEH frames into the dword_8D4478/dword_8D4400/dword_8D4440 slots, sets a flag bit (|= 2) on dword_8D4400's CEH word and records the dword_8D446C chain terminator. [source:raw]
    // RETURN: Return the saved a1-20 slot value. [source:raw]

    // Conservative worker pseudocode:
    //   static void localeStaticsInit() {
    //     SEHHandlerInit(&unk_8D3E3C);
    //     enter_once_init(); // sub_59A54D
    //     if (dword_5EA04C < 0) {
    //       dword_5EA04C = 1;
    //       construct_locale_static_objects(); // LocaleObject* /CEHFrameSetup chain
    //     } else {
    //       ++dword_5EA04C;
    //     }
    //     leave_once_init(); // sub_59A5E9
    //   }
    // UNRESOLVED: Callees sub_59A54D, sub_59A5E9, LocaleObjectConstructorWithVTableSetup, LocaleObjectAllocAndVtableSetup, CEHFrameSetup and the guard dword_5EA04C appear in the raw source but are absent from the packet deterministic evidence lists.
    // UNRESOLVED: Exact identity of the CRT-style one-time initializer (dword_5EA04C guard semantics) is inferred from the guard pattern, not independently confirmed.
    // UNRESOLVED: unk_8D3E3C is used only as the SEHHandlerInit payload; its contents and the wider locale/CEH object graph are not described by this packet.
}
