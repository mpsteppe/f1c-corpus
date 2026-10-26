// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5CB0
// Canonical corpus name: SceneOrderSlotFinder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneOrderSlotFinder_004c5cb0.c

void UnknownObject::SceneOrderSlotFinder()
{
    // Finds the position of a scene in the SceneOrder list: initializes this[3] (offset 0xC) to 0x7FFFFFFF as a sentinel, invokes AudioChannelStop with the game-data global and the "SceneOrder" name, computes the scene entry address as dword_8AC490 + 396 * this[0] (offset 0x0), and when the entry is non-null scans the SceneOrder list comparing each node name against the entry's name at offset 260. On the first matching node it stores the node index into this[3]; it stops early returning null when the list is exhausted. Return value varies by path.
    // ASSIGNMENT: this[3] = 0x7FFFFFFF; initialize the stored slot position at offset 0xC to the maximum sentinel. [field:this:0x0000000C, source:raw]
    // CALL: AudioChannelStop(dword_8AD3B4, aSceneorder); invoke with the game-data global dword_8AD3B4 and the "SceneOrder" name string constant. [callee:0x00568210, global:0x008AD3B4, global:0x005D28B4, source:raw]
    // CALCULATION: v4 = dword_8AC490 + 396 * this[0]; compute the scene entry address from the array base dword_8AC490 using this[0] (offset 0x0) as the scene index with a 396-byte stride. [field:this:0x00000000, global:0x008AC490, source:raw]
    // GUARD: If v4 (the scene entry) is non-null, proceed with the scan; otherwise skip it and fall through to the final return. [source:raw]
    // CALL: result = NullCheckWrapper(0); retrieve the first SceneOrder list node by index 0. [callee:0x005679A0, source:raw]
    // GUARD: If the first list node is null, skip the scan. [callee:0x005679A0, source:raw]
    // ASSIGNMENT: v5 = v4 + 260; point at the scene name field of the scene entry. [source:raw]
    // LOOP: Scan the SceneOrder list nodes starting at index 0, advancing v3 each iteration, until a name match is found or the list ends. [callee:0x005679A0, source:raw]
    // CALL: v6 = StringPointerAccessor(result); extract the name string pointer from the current list node. [callee:0x00499E20, source:raw]
    // CALL: result = sub_588410(v6, v5); compare the node name against the scene name; a zero/null result is treated as the match. [callee:0x00588410, source:raw]
    // GUARD: If the comparison result is null (match found), break out of the loop. [callee:0x00588410, source:raw]
    // CALL: result = NullCheckWrapper(++v3); advance the index and fetch the next list node. [callee:0x005679A0, source:raw]
    // GUARD: If the next node is null (list exhausted), return null immediately. [callee:0x005679A0, source:raw]
    // ASSIGNMENT: this[3] = v3; store the matching node index at offset 0xC, replacing the sentinel. [field:this:0x0000000C, source:raw]
    // RETURN: Return the final result value. [source:raw]

    // Conservative worker pseudocode:
    //   this[3] = 0x7FFFFFFF;
    //   AudioChannelStop(dword_8AD3B4, aSceneorder);
    //   v4 = dword_8AC490 + 396 * this[0];
    //   if (v4) {
    //       result = NullCheckWrapper(0);
    //       if (result) {
    //           v5 = v4 + 260;
    //           while (1) {
    //               v6 = StringPointerAccessor(result);
    //               result = sub_588410(v6, v5);
    //               if (!result) break;
    //               result = NullCheckWrapper(++v3);
    //               if (!result) return result;
    //           }
    //           this[3] = v3;
    //       }
    //   }
    //   return result;
    // UNRESOLVED: sub_588410 is treated as a name comparison where a zero result means a match; that semantic is DERIVED from existing analysis, not directly evidenced in this body.
    // UNRESOLVED: AudioChannelStop is invoked with the "SceneOrder" name, but the name is a legacy label and the operation actually performed is not observable from this function alone.
    // UNRESOLVED: The 396-byte stride and the +260 name offset describe the SceneArray layout in existing analysis, but the record layout is not otherwise evidenced.
    // UNRESOLVED: The return value varies by path (scan outcome, null, or the array base) and is not a single status code.
    // UNRESOLVED: Called by sub_4C5C80 (0x004C5C80); the caller's purpose is not established here.
}
