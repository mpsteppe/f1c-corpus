// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585E50
// Canonical corpus name: sub_585E50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585E50_00585e50.c

void UnknownObject::GuardedStaticObjectInit()
{
    // Compiler-style guarded static-initialization wrapper. Registers an SEH frame (reading the exception-handler table at unk_8D3E2C), runs a one-time guard on the global init counter dword_5EA04C, and when the guard passes constructs seven static objects (vtable-setup, allocation, and CEH-frame-setup helpers) linking them into parent frame slots. Returns a saved context value.
    // CALL: Set up the SEH frame for this function; the function reads the exception-handler table at unk_8D3E2C. [global:0x008D3E2C, source:raw]
    // ASSIGNMENT: Store the incoming context value into the caller-provided return slot at (a1 - 20) and clear the object slot at (a1 - 16). [function:0x00585E50, source:raw]
    // CALL: Enter the guarded region with helper sub_59A54D(a1 - 16). [source:raw]
    // GUARD: Once-guard on the global init counter dword_5EA04C: when the counter is negative take the construction branch and set the local flag v2, otherwise increment the counter and skip construction. [source:raw]
    // CALL: Leave the guarded region with helper sub_59A5E9. [source:raw]
    // ASSIGNMENT: For each of seven static objects, store the object pointer at (a1 - 16) and its construction index (0 through 6) at (a1 - 4). [source:raw]
    // GUARD: Guard each object pointer for non-null before invoking its constructor, allocation, or SEH-frame-setup helper. [source:raw]
    // CALL: Construct the static objects through the vtable-setup, allocation, and CEH-frame-setup helpers. [source:raw]
    // ASSIGNMENT: Link constructed objects into the parent exception-handling frame: store child-object pointers (for example byte_8D4568) into slots derived from each object's embedded offset table at byte offsets 44 and 12, and OR state flag bit 2 into one frame's state word at byte offset 12. [source:raw]
    // RETURN: Return the saved context value read back from (a1 - 20). [source:raw]

    // Conservative worker pseudocode:
    //   // Guarded construction of a fixed set of static objects inside an SEH frame.
    //   int sub_585E50(int ctx) {
    //     SEHHandlerInit();
    //     *(ctx - 20) = ctx; *(ctx - 16) = 0;
    //     sub_59A54D(ctx - 16);
    //     bool first = false;
    //     if (g_init_counter < 0) { g_init_counter = 1; first = true; }
    //     else { ++g_init_counter; }
    //     sub_59A5E9();
    //     if (first) {
    //       for (i = 0; i < 7; ++i) {
    //         obj = &static_objects[i];
    //         *(ctx - 16) = obj; *(ctx - 4) = i;
    //         if (obj) ConstructHelper(obj);
    //       }
    //       LinkChildObjectsIntoParentFrames();
    //     }
    //     return *(ctx - 20);
    //   }
    // UNRESOLVED: Identity and purpose of the seven constructed static objects (unk_8D4510, unk_8D44B8, unk_8D45A0, dword_8D4478, byte_8D4568, dword_8D4400, dword_8D4440, dword_8D446C) and the one-time guard counter dword_5EA04C are unresolved; the object layouts and vtable targets are opaque at this scope.
    // UNRESOLVED: Helpers sub_59A54D and sub_59A5E9 bracket the guarded region; their exact roles (SEH enter/leave with refcount) are unverified.
    // UNRESOLVED: Caller identity and the meaning of the return slot (a1 - 20) are unknown; the function reads like compiler-generated guarded static-initialization scaffolding.
}
