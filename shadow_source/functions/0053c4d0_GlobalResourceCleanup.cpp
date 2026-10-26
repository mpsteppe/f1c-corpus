// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C4D0
// Canonical corpus name: GlobalResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalResourceCleanup_0053c4d0.c

void UnknownObject::GlobalResourceCleanup()
{
    // Shutdown cleanup for a batch of global resources. Cleans pointer arrays in the member structure, releases a sound-manager-style object referenced by dword_8B78A0 via a vtable call, then for each of several global handles/handles performs an optional pre-cleanup handler, a heap free, and zeroing of the global. Returns 0.
    // CALL: Array-of-pointers cleanup with a per-element free loop over the `this` structure. [callee:0x0055BF70]
    // CALL: Release the object referenced by global dword_8B78A0 via a vtable call. [callee:0x0053D850, global:0x008B78A0]
    // GUARD: If dword_8B8F2C is non-null: invoke the empty-stub hook, free the heap block, then zero the global. [global:0x008B8F2C, callee:0x00557470, callee:0x00587BCF]
    // GUARD: If dword_8B8F04 is non-null: invoke the empty-stub hook, free the heap block, then zero the global. [global:0x008B8F04, callee:0x00557470, callee:0x00587BCF]
    // CALL: Two empty-stub invocations (debug/logging hooks). [callee:0x004B0170]
    // GUARD: If dword_8B8F18 is non-null: free the heap block and zero the global. [global:0x008B8F18, callee:0x00587BCF]
    // GUARD: If dword_8B8F1C is non-null: run the pre-cleanup handler, free the heap block, then zero the global. [global:0x008B8F1C, callee:0x0053AD50, callee:0x00587BCF]
    // GUARD: If dword_8B8F20 is non-null: free the heap block and zero the global. [global:0x008B8F20, callee:0x00587BCF]
    // RETURN: Return 0. [function:0x0053C4D0]

    // Conservative worker pseudocode:
    //   if (dword_8B8F2C) { EmptyStub(dword_8B8F2C); Free(dword_8B8F2C); dword_8B8F2C = 0; }
    //   CleanupPointerArrays(this); ReleaseObjectViaVtable(&dword_8B78A0);
    //   if (dword_8B8F04) { EmptyStub(dword_8B8F04); Free(dword_8B8F04); dword_8B8F04 = 0; }
    //   EmptyStub(); EmptyStub();
    //   if (dword_8B8F18) { Free(dword_8B8F18); dword_8B8F18 = 0; }
    //   if (dword_8B8F1C) { PreCleanup(dword_8B8F1C); Free(dword_8B8F1C); dword_8B8F1C = 0; }
    //   if (dword_8B8F20) { Free(dword_8B8F20); dword_8B8F20 = 0; }
    //   return 0;
    // UNRESOLVED: The exact resource kinds behind the globals (render handles, network config, sound manager) are labelled DERIVED in the existing analysis; the vtable-release path means dword_8B78A0 is read indirectly and only its address is passed to the release call.
}
