// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041FF10
// Canonical corpus name: SceneElementScanWithConditionCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneElementScanWithConditionCheck_0041ff10.c

void UnknownObject::SceneElementScanWithConditionCheck()
{
    // Scans the global scene-element list (dword_7D2DB0) for an element whose season-resolved scene name (80-byte buffer filled by SceneNameLookupBySeason) matches the caller-supplied string and whose per-index dword field at offset 212 + 4*v2 equals 10, where v2 is an index returned by sub_4C2990. The head element (FixedOffsetReturn) is checked first; on no match the active elements are iterated from index 0 via ShortComputation_13a0 until ActiveEntityCounter is exhausted. Returns 1 only when both conditions (name match AND field value 10) hold, otherwise 0.
    // CALL: Compute v2 = sub_4C2990(dword_7D2DB0), the index later used to select the per-element dword field at offset 212 + 4*v2. [callee:0x004C2990, global:0x007D2DB0, source:raw]
    // CALL: v3 = LinkedListDereference(dword_7D2DB0): dereference the global scene-element list handle to its backing array. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: v4 = FixedOffsetReturn(v3): head-element accessor into the backing array. [callee:0x004C1390, source:raw]
    // CALL: SceneNameLookupBySeason(v4, v13, 0x50): fill the 80-byte scene-name buffer for the head element under the current season. [callee:0x004C0A20, source:raw]
    // GUARD: If sub_566810(v13, this) is nonzero, the head element's season-resolved scene name matches the caller-supplied string. [callee:0x00566810, source:raw]
    // GUARD: On a name match, re-dereference dword_7D2DB0 and read the dword at FixedOffsetReturn(...) + 212 + 4*v2; if it equals 10, return 1. [callee:0x004C1390, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // ASSIGNMENT: Initialize the active-element index v7 to 0 before the scan loop. [source:raw]
    // GUARD: If ActiveEntityCounter(LinkedListDereference(dword_7D2DB0)) is not greater than 0, return 0 (no active elements to scan). [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // LOOP: Iterate active elements while v7 stays below ActiveEntityCounter, testing each element for the name-and-field condition. [callee:0x004C1370, source:raw]
    // CALL: v10 = ShortComputation_13a0(LinkedListDereference(dword_7D2DB0), v7): indexed element accessor for the current loop index. [callee:0x004C13A0, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: SceneNameLookupBySeason(v10, v13, 0x50): fill the scene-name buffer for the current element under the current season. [callee:0x004C0A20, source:raw]
    // GUARD: If sub_566810(v13, this) is nonzero, the current element's season-resolved scene name matches the caller-supplied string. [callee:0x00566810, source:raw]
    // GUARD: On a name match, re-dereference dword_7D2DB0 and read the dword at ShortComputation_13a0(...) + 212 + 4*v2; if it equals 10, break out of the loop. [callee:0x004C13A0, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // ASSIGNMENT: Increment the active-element index v7 by 1 at the end of each iteration. [source:raw]
    // GUARD: If v7 now reaches ActiveEntityCounter(LinkedListDereference(dword_7D2DB0)), return 0 (no matching element found). [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // RETURN: Return 1 when a matching element (season-resolved name match and field value 10) was found; return 0 in all other cases. [source:raw]

    // Conservative worker pseudocode:
    //   int SceneElementScanWithConditionCheck(const char *name) {
    //       int idx = sub_4C2990(dword_7D2DB0);
    //       char scene_name[80];
    //       char *head = FixedOffsetReturn(LinkedListDereference(dword_7D2DB0));
    //       SceneNameLookupBySeason(head, scene_name, 0x50);
    //       if (sub_566810(scene_name, name)) {
    //           if (*(int *)(FixedOffsetReturn(LinkedListDereference(dword_7D2DB0)) + 4 * idx + 212) == 10)
    //               return 1;
    //       }
    //       for (int i = 0; i < ActiveEntityCounter(LinkedListDereference(dword_7D2DB0)); ++i) {
    //           char *elem = ShortComputation_13a0(LinkedListDereference(dword_7D2DB0), i);
    //           SceneNameLookupBySeason(elem, scene_name, 0x50);
    //           if (sub_566810(scene_name, name)) {
    //               if (*(int *)(ShortComputation_13a0(LinkedListDereference(dword_7D2DB0), i) + 4 * idx + 212) == 10)
    //                   return 1;
    //           }
    //       }
    //       return 0;
    //   }
    // UNRESOLVED: The exact comparison performed by sub_566810(v13, this) (name equality versus prefix/pattern matching) is not established from this packet.
    // UNRESOLVED: The meaning of the field at offset 212 + 4*v2 and of the constant value 10 is unknown; v2 comes from sub_4C2990 and likely selects a per-season/per-category entry, but the field's role (scene type/state selector) is not confirmed.
    // UNRESOLVED: dword_7D2DB0 is used as a global scene-element list handle, but the underlying object layout and the relationship between the FixedOffsetReturn (head element) and ShortComputation_13a0 (indexed element) accessors are not confirmed.
    // UNRESOLVED: The head element is checked before the loop; whether the loop would re-test the same element at index 0 depends on the two accessors addressing the same backing array.
}
