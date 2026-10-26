// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005876C0
// Canonical corpus name: SingleFunctionCallWrapper_76c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_76c0_005876c0.c

void UnknownObject::GuardedStaticObjectInit()
{
    // Compiler-style guarded static-initialization wrapper. Registers an SEH frame against the exception-handler table at unk_8D3E38, runs a one-time guard on a global init counter, and when the guard passes constructs a fixed set of static objects through vtable-setup, allocation, and SEH-frame-setup helpers, linking them into parent frames. Returns a saved context value.
    // CALL: Set up the SEH frame by registering the global exception-handler table at unk_8D3E38. [global:0x008D3E38, source:raw]
    // ASSIGNMENT: Store the incoming context value v1 into the caller-provided return slot at (a1 - 20) and clear the object slot at (a1 - 16). [function:0x005876C0, source:raw]
    // CALL: Enter the guarded region with helper sub_59A54D(a1 - 16). [source:raw]
    // GUARD: Once-guard on the global init counter dword_5EA04C: when it is negative take the construction branch and set the local flag v2, otherwise increment the counter and skip construction. [source:raw]
    // CALL: Leave the guarded region with helper sub_59A5E9(a1 - 16). [source:raw]
    // ASSIGNMENT: For each of the six static objects store the object pointer at (a1 - 16) and its construction index (0 through 5) at (a1 - 4). [source:raw]
    // GUARD: Guard each object pointer for non-null before invoking its constructor or allocation helper. [source:raw]
    // CALL: Construct the static objects through the vtable-setup, allocation, and SEH-frame-setup helpers (LocaleObjectConstructorWithVTableSetup, LocaleObjectAllocAndVtableSetup, CEHFrameSetup). [source:raw]
    // ASSIGNMENT: Link constructed objects into parent frames: store child-object pointers into parent slots at byte offsets 44 and 12 and OR the state flag bit 2 onto one frame's state. [source:raw]
    // RETURN: Return the saved context value read back from (a1 - 20). [source:raw]

    // Conservative worker pseudocode:
    //   // Guarded construction of a fixed set of static objects inside an SEH frame.
    //   int sub_5876C0(int ctx) {
    //     SEHHandlerInit(&unk_8D3E38);
    //     *(ctx - 20) = ctx; *(ctx - 16) = 0;
    //     sub_59A54D(ctx - 16);
    //     bool first = false;
    //     if (dword_5EA04C < 0) { dword_5EA04C = 1; first = true; }
    //     else { ++dword_5EA04C; }
    //     sub_59A5E9(ctx - 16);
    //     if (first) {
    //       for (i = 0; i < 6; ++i) {
    //         obj = &static_objects[i];
    //         *(ctx - 16) = obj; *(ctx - 4) = i;
    //         if (obj) ConstructHelper(obj);
    //       }
    //     }
    //     return *(ctx - 20);
    //   }
    // UNRESOLVED: Identity and purpose of the six constructed static objects (unk_8D4510, unk_8D44B8, unk_8D45A0, dword_8D4478, byte_8D4568, dword_8D4400, dword_8D4440, dword_8D446C) and the one-time guard counter dword_5EA04C are unresolved; the object layouts and vtable targets are opaque at this scope.
    // UNRESOLVED: Helpers sub_59A54D and sub_59A5E9 bracket the guarded region; their exact roles (SEH enter/leave) are unverified.
    // UNRESOLVED: Caller identity and the meaning of the return slot (a1 - 20) are unknown; the function reads like compiler-generated guarded static-initialization scaffolding.
}
