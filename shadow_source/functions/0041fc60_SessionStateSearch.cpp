// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041FC60
// Canonical corpus name: SessionStateSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionStateSearch_0041fc60.c

void UnknownObject::SessionStateSearch()
{
    // Search for a session state whose scene name matches `this` and whose state table (dword array at byte offset 216, stride 4) contains the value 10; return 1 when found, 0 otherwise. Tries the current session list first, then each active entity.
    // CALL: SceneNameLookupBySeason(v16, 80) fills the 80-byte local scene-name buffer v16 for the current season. [callee:0x004C0A20, source:raw]
    // CALL: sub_566810(v16, this) compares the looked-up scene name against the session object `this`. [callee:0x00566810, source:raw]
    // GUARD: Enter the first scan path when the scene comparison succeeds and the flag-table count over the list at 0x7D2DB0 (LinkedListDereference then FlagsGetter) is greater than 0. [global:0x007D2DB0, callee:0x004C2850, callee:0x004C11D0, source:raw]
    // ASSIGNMENT: v3 (scan index) initialized to 0 and v5 to 216 (byte offset of the per-session state table). [source:raw]
    // LOOP: Scan dwords at byte offset 216 (stride 4) from the record base FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0)); stop when a dword equals 10, or when v3 reaches the FlagsGetter count (fall through to LABEL_6). [callee:0x004C2850, callee:0x004C1390, callee:0x004C11D0, global:0x007D2DB0, source:raw]
    // RETURN: Return 1 when a dword equal to 10 is found in the first scan path. [source:raw]
    // GUARD: LABEL_6 second path: return 0 immediately when ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)) is <= 0. [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // RETURN: Return 0 when there are no active entities to search. [source:raw]
    // LOOP: Iterate active entities v8 from 0 while v8 < ActiveEntityCounter; for each entity get its record base via ShortComputation_13a0(v8), rebuild the scene name with SceneNameLookupBySeason, and test it with sub_566810. [callee:0x004C13A0, callee:0x004C0A20, callee:0x00566810, callee:0x004C1370, callee:0x004C2850, source:raw]
    // GUARD: When an entity scene matches and its FlagsGetter count is greater than 0, begin that entity's inner flag scan; otherwise continue the outer loop (LABEL_12). [callee:0x004C11D0, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // LOOP: Inner scan: read dwords at byte offset 216 (stride 4) from the entity record returned by ShortComputation_13a0(v8); stop when a dword equals 10 (return 1) or v10 reaches the FlagsGetter count (resume outer loop at LABEL_12). [callee:0x004C13A0, callee:0x004C11D0, callee:0x004C2850, source:raw]
    // CALCULATION: Table element address computed as base + 216 + index * 4, where base is the record pointer from FixedOffsetReturn (first path) or ShortComputation_13a0 (second path) and index is v3 or v10. [callee:0x004C1390, callee:0x004C13A0, source:raw]
    // RETURN: Return 1 when the inner scan finds value 10; return 0 when the outer entity scan exhausts all active entities. [source:raw]

    // Conservative worker pseudocode:
    //   SceneNameLookupBySeason(v16, 80);
    //   if (sub_566810(v16, this) && FlagsGetter(LinkedListDereference(&dword_7D2DB0)) > 0) {
    //       for (index = 0, offset = 216; index < FlagsGetter(...); ++index, offset += 4) {
    //           if (*(DWORD*)(FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0)) + offset) == 10) return 1;
    //       }
    //   }
    //   if (ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)) <= 0) return 0;
    //   for (entity = 0; entity < ActiveEntityCounter(...); ++entity) {
    //       SceneNameLookupBySeason(v16, 80);
    //       if (sub_566810(v16, this) && FlagsGetter(...) > 0) {
    //           for (index = 0, offset = 216; index < FlagsGetter(...); ++index, offset += 4) {
    //               if (*(DWORD*)(ShortComputation_13a0(entity) + offset) == 10) return 1;
    //           }
    //       }
    //   }
    //   return 0;
    // UNRESOLVED: Exact meaning of the table value 10 (session-state enum) is not recoverable from this packet.
    // UNRESOLVED: Purpose and name of sub_566810 (scene-name equality test) are inferred from usage only; the packet provides no contract for it.
    // UNRESOLVED: Semantic relationship between the first (current-session list, offset via FixedOffsetReturn) and second (per-entity, offset via ShortComputation_13a0) scan paths is not fully resolved.
    // UNRESOLVED: Owner type is unknown; the prelabel cluster_copy to 0041fb10 is DERIVED and does not establish a class.
}
