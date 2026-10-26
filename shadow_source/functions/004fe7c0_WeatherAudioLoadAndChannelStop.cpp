// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FE7C0
// Canonical corpus name: sub_4FE7C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FE7C0_004fe7c0.c

void UnknownObject::WeatherAudioLoadAndChannelStop()
{
    // Loads an audio file by resource ID (AudioFileLoadDecode(a2, 0)), stops the weather audio channel identified by global aWeather_1 (AudioChannelStop), and, when the stop succeeds, processes the stopped channel handle through sub_4FE350 into the caller's buffer. Cleans up a local linked-list buffer on every path. Returns the sub_4FE350 result on success or -1 when the channel stop returns NULL. Called by sub_4FCC30 (004fcc30).
    // CALL: StructZeroInit_7a00(v6): zero-initialize the local 56-byte audio processing struct [callee:0x00567A00, function:0x004FE7C0, source:raw]
    // CALL: AudioFileLoadDecode(a2, 0): load and decode the audio file identified by a2 with literal argument 0; return value unused [callee:0x00567F40, source:raw]
    // CALL: AudioChannelStop(aWeather_1): stop the weather audio channel referenced by global aWeather_1 and capture the resulting channel handle into v3 [callee:0x00568210, global:0x005D173C, source:raw]
    // GUARD: Branch on v3: if the channel handle is non-NULL take the processing path, otherwise the failure path [function:0x004FE7C0, source:raw]
    // CALL: sub_4FE350(this, v3): process the stopped channel data into the caller's float buffer; result captured into v5 [callee:0x004FE350, source:raw]
    // CALL: LinkedListDestructorWithInnerFree(v6): free the temporary audio buffer linked list [callee:0x00567A30, source:raw]
    // RETURN: Return v5 (the sub_4FE350 processing result) on the success path [callee:0x004FE350, source:raw]
    // CALL: LinkedListDestructorWithInnerFree(v6): free the temporary audio buffer linked list on the failure path as well [callee:0x00567A30, source:raw]
    // RETURN: Return -1 when AudioChannelStop returned NULL (failure path) [function:0x004FE7C0, source:raw]

    // Conservative worker pseudocode:
    //   StructZeroInit_7a00(v6);
    //   AudioFileLoadDecode(a2, 0);
    //   v3 = AudioChannelStop(aWeather_1);
    //   if (v3) {
    //     v5 = sub_4FE350(this, v3);
    //     LinkedListDestructorWithInnerFree(v6);
    //     return v5;
    //   }
    //   LinkedListDestructorWithInnerFree(v6);
    //   return -1;
    // UNRESOLVED: sub_4FE350's internal channel-processing semantics are not defined within this packet
    // UNRESOLVED: The v6 buffer layout (56 bytes) and how sub_4FE350 consumes it are not described by this packet
    // UNRESOLVED: The return value of AudioFileLoadDecode is discarded; its error handling is unknown
    // UNRESOLVED: aWeather_1 is a global but its owning subsystem (weather audio) is inferred only from the existing analysis, not from packet evidence
    // UNRESOLVED: Owner object identity is not established by the packet
}
