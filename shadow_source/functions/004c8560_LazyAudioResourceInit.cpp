// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8560
// Canonical corpus name: LazyAudioResourceInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LazyAudioResourceInit_004c8560.c

void UnknownObject::LazyAudioResourceInit()
{
    // Lazily initializes an audio resource: if the interface pointer global dword_8AC4C4 is set and the cached result global dword_8AC4CC is still zero, calls the object's vtable method located 96 bytes past the vtable base and stores its return value into dword_8AC4CC. Runs once per process lifetime in practice. Invoked by Sound_Enter.
    // GUARD: Guard on dword_8AC4C4 being nonzero; the whole body is skipped when the interface pointer is not yet established. [global:0x008AC4C4, source:raw]
    // GUARD: Guard on dword_8AC4CC being zero; the initialization runs only once and is skipped once a result has been cached. [global:0x008AC4CC, source:raw]
    // CALL: Indirect call through the vtable of the object referenced by dword_8AC4C4; the target is read at 96 bytes past the vtable base (slot for the lazy-create entry point). [global:0x008AC4C4, source:raw]
    // ASSIGNMENT: Store the method return value into dword_8AC4CC, memoizing the result. [global:0x008AC4CC, source:raw]
    // CALL: Invoked by Sound_Enter during sound subsystem entry. [caller:0x004C8A20]

    // Conservative worker pseudocode:
    //   if (dword_8AC4C4) {
    //     if (!dword_8AC4CC)
    //       dword_8AC4CC = (*(int (**)(void))(*(_DWORD *)dword_8AC4C4 + 96))();
    //   }
    // UNRESOLVED: The concrete object type behind dword_8AC4C4 is unknown; only its vtable indirection is visible.
    // UNRESOLVED: The purpose of the vtable method at offset 96 and the meaning of its integer return value are undocumented here.
}
