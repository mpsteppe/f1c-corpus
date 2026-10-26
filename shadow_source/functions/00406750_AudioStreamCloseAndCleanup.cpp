// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406750
// Canonical corpus name: AudioStreamCloseAndCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioStreamCloseAndCleanup_00406750.c

void UnknownObject::AudioStreamCloseAndCleanup()
{
    // Audio stream teardown helper: closes the Miles audio stream handle at this+0xC (AIL_close_stream, cleared to 0) when non-null; runs slot cleanup via sub_406A70 when the slot index at this+0x5C is not -1; obtains a sub-struct from the slot at this+0x1C via sub_4080B0 and, when it is non-null, initializes it through a vtable dispatch / zero-fill path before returning that pointer.
    // GUARD: If this[3] (audio stream handle at this+0xC) is non-zero, enter the stream-close branch. [field:this:0x0000000C, source:raw, function:0x00406750]
    // CALL: Call AIL_close_stream(this[3]) to close the Miles audio stream handle. [global:0x0059E37C, field:this:0x0000000C]
    // ASSIGNMENT: Set this[3] (this+0xC) to 0 after closing the stream. [field:this:0x0000000C]
    // GUARD: If this[23] (slot index at this+0x5C) != -1 (0xFFFFFFFF), call sub_406A70(this) for additional slot cleanup; otherwise skip it. [guard:0, field:this:0x0000005C]
    // CALL: Call sub_406A70(this) as the additional cleanup step for a live slot. [callee:0x00406A70, field:this:0x0000005C]
    // CALL: Call sub_4080B0(this[7]) to obtain a sub-struct from the slot at this+0x1C; store the returned pointer. [callee:0x004080B0, field:this:0x0000001C]
    // GUARD: If the sub_4080B0 result is non-zero, return the value of StructInitWithVTableDispatchAndZeroFill(result) (vtable dispatch with zero-fill init). [source:raw]
    // RETURN: Return the sub_4080B0 result (null when the preceding guard was false). [source:raw]
    // CALL: Invoked from SortedStringListInsert (0x004062B0) and ViewCameraReset (0x004064C0). [caller:0x004062B0, caller:0x004064C0]

    // Conservative worker pseudocode:
    //   int AudioStreamCloseAndCleanup(_DWORD *this) {
    //     int result;
    //     if (this[3] != 0) {
    //       AIL_close_stream(this[3]);
    //       this[3] = 0;
    //     }
    //     if (this[23] != -1)
    //       sub_406A70(this);
    //     result = sub_4080B0(this[7]);
    //     if (result)
    //       return StructInitWithVTableDispatchAndZeroFill(result);
    //     return result;
    //   }
    // UNRESOLVED: StructInitWithVTableDispatchAndZeroFill is named in the raw source but has no callee evidence reference in the packet; its address and semantics are not independently attested.
    // UNRESOLVED: sub_406A70 cleanup semantics and the meaning of the slot index at this+0x5C are unknown.
    // UNRESOLVED: Object type for `this` is unconfirmed (UnknownObject).
}
