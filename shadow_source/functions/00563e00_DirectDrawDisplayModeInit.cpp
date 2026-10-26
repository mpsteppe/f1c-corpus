// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563E00
// Canonical corpus name: DirectDrawDisplayModeInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectDrawDisplayModeInit_00563e00.c

void UnknownObject::DirectDrawDisplayModeInit()
{
    // Reinitializes the session's internal sub-objects. If the initialized flag at this+0x0 is already set, returns 4 without touching anything. Otherwise cleans up the existing batch at this+0x4 via BatchLoopWithMemoryCleanup, allocates a new 0x18-byte inner-buffer struct via Malloc0x18ByteStructWithInnerBuffer(sub_5640F0), frees the existing audio array at this+0x94 via DestroyAudioArrayFreeElementsThenContainer, allocates a fresh typed array via AllocateIntArrayViaFactory(4, sub_5645A0, IndirectDwordCompare, sub_564630), resets this+0x98 to 0, and returns 0. Called by StartNetworkUpdate (0x00461DE0).
    // GUARD: Guard: if the initialized flag at this+0x0 is non-zero, return 4 immediately (already-initialized early exit). [field:this:0x00000000, source:raw]
    // CALL: Call BatchLoopWithMemoryCleanup on the existing batch pointer stored at this+0x4 to tear down its sub-objects before replacement. [callee:0x00564860, field:this:0x00000004, source:raw]
    // CALL: Call Malloc0x18ByteStructWithInnerBuffer(sub_5640F0) to allocate the new 0x18-byte sub-struct; sub_5640F0 is the callback that builds its inner buffer. [callee:0x00564810, global:0x005640F0, source:raw]
    // ASSIGNMENT: Store the newly allocated sub-struct into the batch slot at this+0x4. [field:this:0x00000004, source:raw]
    // CALL: Call DestroyAudioArrayFreeElementsThenContainer on the old audio-array pointer at this+0x94 to free its elements and container. [callee:0x00564740, field:this:0x00000094, source:raw]
    // CALL: Call AllocateIntArrayViaFactory(4, sub_5645A0, IndirectDwordCompare, sub_564630): allocates a typed array with element count 4, element factory sub_5645A0, comparison callback IndirectDwordCompare, and management callback sub_564630. [callee:0x005646D0, global:0x005645A0, global:0x00564600, global:0x00564630, source:raw]
    // ASSIGNMENT: Store the newly allocated typed array into the audio-array slot at this+0x94. [field:this:0x00000094, source:raw]
    // ASSIGNMENT: Reset the counter at this+0x98 to 0. [field:this:0x00000098, source:raw]
    // RETURN: Return 0 on success (4 on the already-initialized early exit). [source:raw]
    // CALL: Called by StartNetworkUpdate (0x00461DE0) during session/sub-object reinitialization. [caller:0x00461DE0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_563E00(LPVOID *this) {
    //     if (*this) return 4;
    //     BatchLoopWithMemoryCleanup(this[1]);
    //     this[1] = Malloc0x18ByteStructWithInnerBuffer(sub_5640F0);
    //     DestroyAudioArrayFreeElementsThenContainer(this[37]);
    //     this[37] = AllocateIntArrayViaFactory(4, sub_5645A0, IndirectDwordCompare, sub_564630);
    //     this[38] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of the non-zero early-exit return value 4 and the exact initialization state it represents.
    // UNRESOLVED: Identity of the owning session object (this), and what the 0x18-byte sub-struct at this+0x4 semantically holds.
    // UNRESOLVED: Semantics of the counter at this+0x98 beyond being reset to zero here.
    // UNRESOLVED: What inner-buffer callback sub_5640F0 builds and what the typed-array slots at this+0x94 are used for.
}
