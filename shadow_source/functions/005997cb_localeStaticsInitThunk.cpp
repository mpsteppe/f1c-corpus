// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005997CB
// Canonical corpus name: ThunkToFUN00599958
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN00599958_005997cb.c

void UnknownObject::localeStaticsInitThunk()
{
    // Near-identical twin of the sibling one-time locale/CEH static initializer in its own wave. Installs an SEH handler (payload not visible in the decompiled body), uses the dword_5EA04C guard counter to detect the first call, then constructs a chain of locale/CEH static objects once. Deterministic facts also record a read of global unk_8D4438 whose site is not visible in the raw body.
    // CALL: Install SEH handler via SEHHandlerInit() with no explicit payload argument shown in the decompiled body. [source:raw]
    // UNKNOWN: Deterministic facts record a read of global unk_8D4438 (likely SEH/dispatch payload); the read is not visible in the raw body, so its exact role is unresolved. [global:0x008D4438, source:raw]
    // ASSIGNMENT: Save the incoming ecx value (v1) into caller slot a1-20 and zero the a1-16 slot used as the protected object. [source:raw]
    // CALL: Enter the one-time-init critical section: sub_59A54D(a1-16). [source:raw]
    // GUARD: Guard dword_5EA04C: if negative (first call) set it to 1 and mark construction path (v2=1); otherwise increment it and skip construction (v2=0). [source:raw]
    // CALL: Leave the one-time-init critical section: sub_59A5E9(a1-16). [source:raw]
    // GUARD: If v2 (first-call flag) run the static-locale construction block. [source:raw]
    // CALL: Construct static locale/CEH objects: LocaleObjectConstructorWithVTableSetup for unk_8D4510/off_5E6748, unk_8D44B8/unk_5E6768 and unk_8D45A0/unk_5E6788; LocaleObjectAllocAndVtableSetup for dword_8D4478; CEHFrameSetup frames for byte_8D4568, dword_8D4400 and dword_8D4440; links CEH frames into the dword_8D4478/dword_8D4400/dword_8D4440 slots, sets a flag bit (|= 2) on dword_8D4400's CEH word and records the dword_8D446C chain terminator. [source:raw]
    // RETURN: Return the saved a1-20 slot value. [source:raw]

    // Conservative worker pseudocode:
    //   static void localeStaticsInitThunk() {
    //     SEHHandlerInit();
    //     enter_once_init(); // sub_59A54D
    //     if (dword_5EA04C < 0) {
    //       dword_5EA04C = 1;
    //       construct_locale_static_objects(); // LocaleObject* /CEHFrameSetup chain
    //     } else {
    //       ++dword_5EA04C;
    //     }
    //     leave_once_init(); // sub_59A5E9
    //   }
    // UNRESOLVED: Global unk_8D4438 is read per deterministic facts but its reference site does not appear in the raw body; role unknown.
    // UNRESOLVED: Callees sub_59A54D, sub_59A5E9, LocaleObjectConstructorWithVTableSetup, LocaleObjectAllocAndVtableSetup, CEHFrameSetup and the guard dword_5EA04C appear in the raw source but are absent from the packet deterministic evidence lists.
    // UNRESOLVED: This function mirrors the sibling one-time initializer in its own wave; whether both are distinct one-time initializer copies or one is a thunk into shared construction is unresolved at this trust level.
    // UNRESOLVED: Exact identity of the CRT-style one-time initializer (dword_5EA04C guard semantics) is inferred from the guard pattern, not independently confirmed.
}
