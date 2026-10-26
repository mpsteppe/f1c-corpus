// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405A30
// Canonical corpus name: sub_405A30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_405A30_00405a30.c

void UnknownObject::AudioSampleStop()
{
    // Stops a Miles audio sample. Reads the sample-handle-struct pointer at this+0x58; if non-null, dereferences its +0x10 sample handle, and if that is also non-null passes it to AIL_stop_sample (0x0059E3FC). Returns the final sample handle value (0 when either level is null).
    // ASSIGNMENT: Read this[22] (offset 0x58) as the sample-handle-struct pointer and seed result with it. [field:this:0x00000058, source:raw]
    // GUARD: Null guard on the sample-handle-struct pointer: when result is null the function is blocked and returns 0. [field:this:0x00000058, source:raw]
    // ASSIGNMENT: Dereference the struct at +0x10 to obtain the Miles sample handle (field base *(this+0x68), offset 0x10). [field:*(this+0x68):0x00000010, source:raw]
    // GUARD: Null guard on the sample handle: when it is null the function is blocked and returns 0. [field:*(this+0x68):0x00000010, source:raw]
    // CALL: Call AIL_stop_sample with the sample handle to stop sample playback. [global:0x0059E3FC, source:raw]
    // RETURN: Return the sample handle value (or 0 when any null guard blocked). [function:0x00405A30, source:raw]

    // Conservative worker pseudocode:
    //   int sub_405A30(DWORD *this) {
    //     DWORD *h = this[22];            // offset 0x58
    //     if (!h) return 0;
    //     DWORD *sample = *(DWORD **)(h + 0x10);
    //     if (!sample) return (int)sample;
    //     return AIL_stop_sample(sample); // 0x0059E3FC
    //   }
    // UNRESOLVED: The owning class of this method is unknown; the packet labels it UnknownObject.
    // UNRESOLVED: The structure that this+0x58 points to and its +0x10 sample handle are only characterized as Miles sample state.
    // UNRESOLVED: Callers are not present in the packet, so when and why this sample-stop path runs is unknown.
}
