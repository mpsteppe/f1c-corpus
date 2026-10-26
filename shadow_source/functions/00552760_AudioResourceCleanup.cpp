// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00552760
// Canonical corpus name: AudioResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioResourceCleanup_00552760.c

void UnknownObject::AudioResourceCleanup()
{
    // Audio/font resource cleanup (audio subsystem). Always releases the source surface at this + 100 via sub_53CB90 and clears the pointer. When the flag bit 0x20000 at this + 36 is set, additionally resets the object at this + 12 through the SoundManager global dword_8B78A0, frees the pointer at this + 12, and frees the object at this + 2152 (via the EmptyStub_7470 no-op then FreeWrapper_7bcf). Returns 0. Called by StringCompareLinkedListSearch.
    // CALL: Release/dereference the source surface: sub_53CB90(*(this + 100)). [callee:0x0053CB90, field:this:0x00000064, source:raw]
    // CALCULATION: Read the flag word at this + 36 and test bit 0x20000: v2 = (*(this + 36) & 0x20000) == 0, controlling whether the full cleanup path runs. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Clear the source surface pointer: *(this + 100) = 0. [field:this:0x00000064, source:raw]
    // GUARD: If the bit 0x20000 flag at this + 36 is set, enter the full cleanup path. [field:this:0x00000024, source:raw]
    // CALL: Reset the object at this + 12 using the SoundManager global: ObjectResetWithVirtualRelease(dword_8B78A0, *(this + 12)). [callee:0x00540EB0, global:0x008B78A0, field:this:0x0000000C, source:raw]
    // GUARD: If the pointer at this + 12 is nonzero, free it via FreeWrapper_7bcf. [field:this:0x0000000C, callee:0x00587BCF, source:raw]
    // GUARD: Read the object pointer at this + 2152; if nonzero, call EmptyStub_7470 on it and free it via FreeWrapper_7bcf. [field:this:0x00000868, callee:0x00557470, callee:0x00587BCF, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_552760(int this) {
    //     sub_53CB90(*(void**)(this + 100));
    //     bool full = (*(_DWORD*)(this + 36) & 0x20000) != 0;
    //     *(_DWORD*)(this + 100) = 0;
    //     if (full) {
    //       ObjectResetWithVirtualRelease(dword_8B78A0, *(_DWORD*)(this + 12));
    //       if (*(_DWORD*)(this + 12)) FreeWrapper_7bcf(*(LPVOID*)(this + 12));
    //       void* v3 = *(void**)(this + 2152);
    //       if (v3) { EmptyStub_7470(v3); FreeWrapper_7bcf(v3); }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Exact role of sub_53CB90 (inferred as release/dereference of the source surface at this + 100) is not stated in the packet.
    // UNRESOLVED: Semantics of ObjectResetWithVirtualRelease and of the SoundManager global dword_8B78A0 are not defined by this packet.
    // UNRESOLVED: EmptyStub_7470 is described as a no-op stub, so the cleanup of the object at this + 2152 only performs the free via FreeWrapper_7bcf.
}
