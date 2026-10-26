// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581E80
// Canonical corpus name: AudioStreamConstructWithVTableInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioStreamConstructWithVTableInit_00581e80.c

void UnknownObject::AudioStreamConstructWithVTableInit()
{
    // __thiscall constructor for an audio stream object: installs the generic constructor base, assigns the audio stream vtable off_5B8B3C to the object, zeroes a WORD at +0x12C and a DWORD at +0x130, then runs the small-struct field initializer over the object. Returns the this pointer.
    // CALL: Run the generic constructor prologue ConstructorVTableSetInit over the object to initialize base fields. [callee:0x0057A160]
    // ASSIGNMENT: Install the audio stream vtable off_5B8B3C into the vtable slot at this+0x0. [field:this:0x00000000, global:0x005B8B3C]
    // ASSIGNMENT: Zero the WORD-sized field at this+0x12C (offset 300); possibly stream state or flags. [field:this:0x0000012C]
    // ASSIGNMENT: Zero the DWORD-sized field at this+0x130 (offset 304); possibly buffer size or timer. [field:this:0x00000130]
    // CALL: Call SmallStructFieldInit over the object to initialize additional small-struct fields to zero/defaults. [callee:0x0057A1E0]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int AudioStreamConstructWithVTableInit(int this) {
    //     ConstructorVTableSetInit((_DWORD*)this);
    //     *(_DWORD*)this = &off_5B8B3C;
    //     *(_WORD*)(this + 300) = 0;
    //     *(_DWORD*)(this + 304) = 0;
    //     SmallStructFieldInit(this);
    //     return this;
    //   }
    // UNRESOLVED: The global 0x0059CBC8 (SEH_581E80) is a compiler-generated exception-handler registration and does not appear in the visible function body.
    // UNRESOLVED: Semantics of the zeroed fields at +0x12C and +0x130 depend on the audio stream object layout, which is not established here.
}
