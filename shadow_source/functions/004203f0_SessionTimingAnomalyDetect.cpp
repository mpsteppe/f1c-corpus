// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004203F0
// Canonical corpus name: sub_4203F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4203F0_004203f0.c

void UnknownObject::SessionTimingAnomalyDetect()
{
    // Session timing/session-state check over entrant records: fetches two entrant records via BestLapEntrantFinder, reads a threshold from the first record and a base value at byte offset 408 of the second, then derives result = base + 10 * (sceneOrder - flags) from two dereferences of the linked list dword_7D2DB0. When the derived value falls in a small window starting at the threshold, a sentinel-initialized structure is returned instead of the derived pointer.
    // CALL: Fetch the first entrant record via BestLapEntrantFinder(0, 0). [source:raw, callee:0x0041E920]
    // GUARD: Continue only when the first entrant record result is non-null. [source:raw]
    // ASSIGNMENT: Dereference the record's first element; when it is null, use the global buffer byte_5EA438 as the default string. [source:raw, global:0x005EA438]
    // CALL: Fetch a second entrant record via BestLapEntrantFinder((int)v2, 1) keyed on the string v2. [source:raw, callee:0x0041E920]
    // CALCULATION: Read the threshold v4 from element index 102 (dword stride) of the first entrant record. [source:raw]
    // CALCULATION: Read v5 as the dword at byte offset 408 of the second entrant record. [source:raw]
    // CALL: Dereference the linked-list head dword_7D2DB0 via LinkedListDereference. [source:raw, callee:0x004C2850, global:0x007D2DB0]
    // CALL: Read session flags from the dereferenced list node via FlagsGetter. [source:raw, callee:0x004C11D0]
    // CALL: Dereference the linked-list head dword_7D2DB0 a second time via LinkedListDereference. [source:raw, callee:0x004C2850, global:0x007D2DB0]
    // CALL: Read the current scene order from the second dereferenced node via SceneOrderReader. [source:raw, callee:0x004C1190]
    // CALCULATION: Compute result = v5 + 10 * (sceneOrder - flags), an offset depending on flag and scene-order state. [source:raw]
    // GUARD: When the derived value is at or above the threshold v4 and below one of v4 + 1, v4 + 2, v4 + 3, v4 + 4 or v4 + 6, take the sentinel path. [source:raw]
    // RETURN: Return a sentinel-initialized structure via StructInitWithSentinelValues when the window guard passes. [source:raw, callee:0x004144D0]
    // RETURN: Return the derived result otherwise, or the null record when the first entrant lookup failed. [source:raw]

    // Conservative worker pseudocode:
    //   char **sub_4203F0() {
    //     _DWORD v9[8];
    //     char **result = BestLapEntrantFinder(0, 0);
    //     char **v1 = result;
    //     if (result) {
    //       char *v2 = *result ? *result : &byte_5EA438;
    //       int v3 = BestLapEntrantFinder((int)v2, 1);
    //       int v4 = (int)v1[102];
    //       int v5 = *(_DWORD *)(v3 + 408);
    //       int v6 = LinkedListDereference(&dword_7D2DB0);
    //       int v7 = FlagsGetter(v6);
    //       int v8 = LinkedListDereference(&dword_7D2DB0);
    //       result = (char **)(v5 + 10 * (SceneOrderReader(v8) - v7));
    //       if ((int)result >= v4 && ((int)result < v4 + 1 || (int)result < v4 + 2 ||
    //           (int)result < v4 + 3 || (int)result < v4 + 4 || (int)result < v4 + 6)) {
    //         return (char **)StructInitWithSentinelValues(v9);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Field meanings of v1[102], the dword at offset 408, and the v5 + 10 * (sceneOrder - flags) formula depend on the entrant record layout, which is unresolved.
    // UNRESOLVED: The OR chain over v4 + 1..v4 + 6 (skipping v4 + 5) is a Hex-Rays collapse of a relational expression; the exact intended comparison set is ambiguous.
    // UNRESOLVED: Relationship to the structural twin BestLapEntrantFinder (0x0041E920) beyond the cluster hint is unresolved.
}
