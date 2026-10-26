// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5760
// Canonical corpus name: LinkedListIteratorWithStateUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListIteratorWithStateUpdate_004b5760.c

void UnknownObject::LinkedListIteratorWithStateUpdate()
{
    // Walks a singly-linked list whose head lives at this+0x20 and whose current walk position is tracked at this+0x28. For each node the loop reads the node's first dword as the item, tests it against three gates (FieldCompareConstant, FloatComparisonCheck, and an audio-sample playback query fed with the float at this+0x30), and on a match writes the audio-state buffer's +4 float into the item at +880 (0x370) and passes the buffer to SceneNodeDecoder with the global dword_5EA560. Advances through the next link stored at node+4 and returns the final walk position.
    // ASSIGNMENT: Load the list head pointer from this+0x20 and store it as the current walk position at this+0x28 [field:this:0x00000020, field:this:0x00000028, source:raw]
    // GUARD: If the head pointer is null, skip the loop and return it immediately [field:this:0x00000020, source:raw]
    // LOOP: Iterate over the list: i takes the first dword of the current node (node+0), and the loop condition tests that same first dword for non-null while advancing through the next link stored at node+4 read via this+0x28 [field:*(this+0x20):0x00000000, field:*(this+0x28):0x00000004, field:this:0x00000028, source:raw]
    // CALCULATION: The second dword of each node (node+8) is read as part of the node structure but does not participate in the shown control flow [field:*(this+0x28):0x00000008, source:raw]
    // GUARD: Per-node gate: proceed only when FieldCompareConstant(i) and FloatComparisonCheck(i) both pass and AudioSamplePlaybackWithPitchModulationAndStereoP(*(float*)(this+0x30), v4) returns true [callee:0x005001D0, callee:0x005001F0, callee:0x00500210, field:this:0x00000030, source:raw]
    // ASSIGNMENT: On a gate match, write the audio-state buffer's float at +4 into the item at +880 (0x370) [field:*(*(this+0x20)+0x0):0x00000370, source:raw]
    // CALL: On a gate match, SceneNodeDecoder(dword_5EA560, v4) processes the scene node with the audio-state buffer [callee:0x00410F60, global:0x005EA560, source:raw]
    // ASSIGNMENT: Advance the walk: reload the cursor from this+0x28, follow the next link at node+4, write the next node back to this+0x28, and stop when it becomes null [field:this:0x00000028, field:*(this+0x28):0x00000004, source:raw]
    // RETURN: Return the final walk position (the last non-null next pointer, or null when the walk ended) [source:raw]
    // CALL: Invoked from sub_4B9000 as a list traversal with per-node audio-state updates [caller:0x004B9000, source:raw]

    // Conservative worker pseudocode:
    //   int* sub_4B5760(this) {
    //     result = *(this + 0x20);
    //     *(this + 0x28) = result;
    //     if (result) {
    //       for (i = *result; *result; i = *result) {
    //         if (FieldCompareConstant(i) && FloatComparisonCheck(i) &&
    //             AudioSamplePlaybackWithPitchModulationAndStereoP(*(float*)(this + 0x30), v4)) {
    //           *(float*)(i + 0x370) = *(float*)&v4[1];
    //           SceneNodeDecoder(dword_5EA560, (int)v4);
    //         }
    //         result = *(this + 0x28);
    //         if (!result) break;
    //         result = result[1];
    //         *(this + 0x28) = result;
    //         if (!result) break;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The concrete type of the node's first dword (node+0) is unresolved: it is both the loop item i and the pointer whose +880 field is written.
    // UNRESOLVED: The layout and purpose of the audio-state buffer v4 are unresolved; only its +4 float feeds node+880, while SceneNodeDecoder consumes the whole buffer.
    // UNRESOLVED: The exact predicates implemented by the three gates (field compare, float compare, audio playback query) are unknown; they only gate the state update in this function.
    // UNRESOLVED: The role of dword_5EA560 as the context passed to SceneNodeDecoder is inherited from the corpus name, not confirmed here.
}
