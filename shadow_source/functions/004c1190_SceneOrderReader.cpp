// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C1190
// Canonical corpus name: SceneOrderReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneOrderReader_004c1190.c

void UnknownObject::SceneOrderReader()
{
    // Scene-order helper (cdecl): stops the scene-order audio channel by calling AudioChannelStop on the global aSceneorder handle, then returns the number of elements in the resulting list via LinkedListCount, or 0 when the stop did not produce a list.
    // CALL: Stop the scene-order audio channel by calling AudioChannelStop(aSceneorder) with the global scene-order handle; its return value v0 is kept as the potential list head. [callee:0x00568210, global:0x005D28B4]
    // GUARD: Branch on the result: when v0 is non-zero continue to count the list, otherwise return 0. [source:raw]
    // CALL: Count the linked list headed by v0 by calling LinkedListCount(v0). [source:raw]
    // RETURN: Return the linked-list count, or 0 when the audio-channel stop yielded no list. [source:raw]
    // CALL: Called by PerDriverRaceCommentary (0x00419C50), sub_4203F0 (0x004203F0) and TimerCountdownWithStateTransition (0x004C1670) to obtain the scene-order list size. [caller:0x00419C50, caller:0x004203F0, caller:0x004C1670, source:raw]

    // Conservative worker pseudocode:
    //   int SceneOrderReader() {
    //     int v0 = AudioChannelStop(aSceneorder);
    //     if (v0) return LinkedListCount(v0);
    //     return 0;
    //   }
    // UNRESOLVED: The scene-order list element type and the meaning of its count are determined by the caller's consumption of the value.
    // UNRESOLVED: LinkedListCount is referenced only in the raw source text and is not listed as a callee in this packet; its address is resolved elsewhere.
    // UNRESOLVED: global:0x008AD3B4 (dword_8AD3B4) is listed as a read global but does not appear in the raw source text; its role is undetermined here.
}
