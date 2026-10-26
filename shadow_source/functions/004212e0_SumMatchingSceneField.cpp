// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004212E0
// Canonical corpus name: ShortComputation_12e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_12e0_004212e0.c

void UnknownObject::SumMatchingSceneField()
{
    // Iterates the active entity list anchored at dword_7D2DB0, resolving each entity pointer with ShortComputation_13a0(index). For each entity whose current scene name (filled into a 80-byte buffer by SceneNameLookupBySeason) compares equal to the `this` parameter via sub_566810, adds the DWORD field at offset 416 of the entity pointer to the running sum. Returns 0 when `this` is null or the entity counter is not greater than 0.
    // ASSIGNMENT: Initialize the sum accumulator v2 to 0. [source:raw]
    // GUARD: When `this` is null, return 0 immediately without scanning the entity list. [function:0x004212E0, source:raw]
    // ASSIGNMENT: Initialize the entity index counter v4 to 0. [source:raw]
    // CALL: Dereference the linked list at dword_7D2DB0 with LinkedListDereference and keep the working data pointer in v5. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: When ActiveEntityCounter(v5) is not greater than 0, skip the loop body entirely and return the sum (0). [callee:0x004C1370, source:raw]
    // LOOP: Loop while the entity index v4 is less than the active entity count; the count is refreshed each iteration from a fresh LinkedListDereference of dword_7D2DB0. [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: Re-dereference the linked list at dword_7D2DB0 with LinkedListDereference at the top of the loop body; the returned pointer is discarded. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: Resolve the entity pointer for index v4 via ShortComputation_13a0; the returned pointer is discarded on this call. [callee:0x004C13A0, source:raw]
    // CALL: Fill the 80-byte local buffer v7 with the scene name for the current season via SceneNameLookupBySeason(v7, 80). [callee:0x004C0A20, source:raw]
    // GUARD: When sub_566810(v7, this) is false (scene name does not match the target), skip the accumulation for this entity. [callee:0x00566810, source:raw]
    // CALL: Re-dereference the linked list at dword_7D2DB0 with LinkedListDereference inside the matching branch; the returned pointer is discarded. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALCULATION: Add the DWORD stored at offset 416 of the entity pointer (resolved again via ShortComputation_13a0(v4)) to the sum accumulator v2. [callee:0x004C13A0, source:raw]
    // ASSIGNMENT: Increment the entity index counter v4 by 1. [source:raw]
    // CALL: Refresh the linked-list working data pointer v6 via LinkedListDereference of dword_7D2DB0 for the loop continuation test. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // RETURN: Return the accumulated sum v2 after the loop completes. [source:raw]
    // RETURN: Function 0x004212E0 is called by GdbSeasonSelector to compute the summed field for the selected season. [caller:0x00420CF0, function:0x004212E0]

    // Conservative worker pseudocode:
    //   int SumMatchingSceneField(void *targetSceneName) {
    //     int sum = 0;
    //     if (!targetSceneName) return 0;
    //     int i = 0;
    //     void *list = LinkedListDereference(&dword_7D2DB0);
    //     if (ActiveEntityCounter(list) > 0) {
    //       do {
    //         LinkedListDereference(&dword_7D2DB0);
    //         ShortComputation_13a0(i);
    //         char sceneName[80];
    //         SceneNameLookupBySeason(sceneName, 80);
    //         if (sub_566810(sceneName, targetSceneName)) {
    //           LinkedListDereference(&dword_7D2DB0);
    //           sum += *(DWORD *)(ShortComputation_13a0(i) + 416);
    //         }
    //         i++;
    //         list = LinkedListDereference(&dword_7D2DB0);
    //       } while (i < ActiveEntityCounter(list));
    //     }
    //     return sum;
    //   }
    // UNRESOLVED: The semantic meaning of the DWORD field at entity offset 416 that is accumulated is not recoverable from this function alone.
    // UNRESOLVED: Several LinkedListDereference calls inside the loop discard their returned pointer; their intended side effects are unknown.
    // UNRESOLVED: The exact comparison semantics of sub_566810 (string equality vs prefix/containment) are not proven by this function.
}
