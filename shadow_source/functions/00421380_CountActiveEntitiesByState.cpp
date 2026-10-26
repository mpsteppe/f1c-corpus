// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421380
// Canonical corpus name: CountActiveEntitiesByState
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CountActiveEntitiesByState_00421380.c

void UnknownObject::CountActiveEntitiesByState()
{
    // Counts active entities whose scene matches the receiver and whose state dword (read at offset 216 plus a per-entity base) equals 10. Outer loop walks active entities, resolves each scene name, and for matching scenes walks the flag array; inner loop increments the accumulator whenever the state dword at (216 + base) is 10. Returns 0 immediately on a null receiver.
    // GUARD: Early-exit when this == null: return 0. [abi:lead, source:raw, function:0x00421380]
    // ASSIGNMENT: v1 = 0 (outer index) and v10 = 0 (accumulator) initialization. [source:raw]
    // CALL: LinkedListDereference(&dword_7D2DB0) refreshes the list pointer global; result feeds the counter checks. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: Outer loop proceeds only if ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)) > 0. [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // LOOP: Outer do/while: iterate v1 from 0 while v1 < ActiveEntityCounter(list). [callee:0x004C1370, source:raw]
    // CALL: LinkedListDereference(&dword_7D2DB0) re-read at the top of each outer iteration (result discarded). [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: ShortComputation_13a0(v1) derives a per-entity base used later for the state-dword address. [callee:0x004C13A0, source:raw]
    // CALL: SceneNameLookupBySeason(v11, 80) fills the 80-byte scene-name buffer. [callee:0x004C0A20, source:raw]
    // GUARD: Proceed into the flag walk only if sub_566810(sceneNameBuf, this) is nonzero (scene matches receiver). [callee:0x00566810, callee:0x004C0A20, source:raw]
    // ASSIGNMENT: v5 = 0 (inner index) and v7 = 216 (state-dword byte base) initialization. [source:raw]
    // GUARD: Inner loop proceeds only if FlagsGetter(LinkedListDereference(&dword_7D2DB0)) > 0. [callee:0x004C11D0, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // LOOP: Inner do/while: iterate v5 from 0 while v5 < FlagsGetter(list), advancing v7 by 4 each pass. [callee:0x004C11D0, source:raw]
    // CALL: LinkedListDereference(&dword_7D2DB0) re-read at the top of each inner iteration (result discarded). [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALCULATION: Address = v7 + ShortComputation_13a0(v1); reads the state dword and increments the accumulator when it equals 10. [callee:0x004C13A0, source:raw]
    // STATE_TRANSITION: Accumulator increment (++v10) when the state dword at the computed address equals 10. [source:raw]
    // ASSIGNMENT: ++v5 and v7 += 4 advance the inner walk (dword stride of the state array). [source:raw]
    // CALL: FlagsGetter(LinkedListDereference(&dword_7D2DB0)) re-evaluated each inner iteration for the loop bound. [callee:0x004C11D0, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)) re-evaluated each outer iteration for the loop bound. [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // RETURN: return v10 — the number of matching entities. [source:raw]

    // Conservative worker pseudocode:
    //   int CountActiveEntitiesByState(this) {
    //     entityIndex = 0;
    //     matchCount = 0;
    //     if (this == null) return 0;
    //     if (ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)) > 0) {
    //       do {
    //         LinkedListDereference(&dword_7D2DB0);
    //         base = ShortComputation_13a0(entityIndex);
    //         SceneNameLookupBySeason(sceneNameBuf, 80);
    //         if (sub_566810(sceneNameBuf, this)) {
    //           flagIndex = 0;
    //           stateBaseOffset = 216;
    //           if (FlagsGetter(LinkedListDereference(&dword_7D2DB0)) > 0) {
    //             do {
    //               LinkedListDereference(&dword_7D2DB0);
    //               if (*(dword*)(stateBaseOffset + base) == 10)
    //                 ++matchCount;
    //               ++flagIndex;
    //               stateBaseOffset += 4;
    //             } while (flagIndex < FlagsGetter(LinkedListDereference(&dword_7D2DB0)));
    //           }
    //         }
    //         ++entityIndex;
    //       } while (entityIndex < ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)));
    //     }
    //     return matchCount;
    //   }
    // UNRESOLVED: Semantics of the counted state value 10 (likely an enum) are unknown.
    // UNRESOLVED: Meaning of the 216 byte base and ShortComputation_13a0(v1) transformation are unknown.
    // UNRESOLVED: Exact scene-match semantics of sub_566810(sceneNameBuf, this) are unknown.
    // UNRESOLVED: dword_7D2DB0 is re-dereferenced every iteration with the result discarded, suggesting a mutable list pointer; exact type unknown.
    // UNRESOLVED: SceneNameLookupBySeason fills an 80-byte buffer; season-name format is unknown.
    // UNRESOLVED: Sole caller is GdbSeasonSelector (0x00420CF0); how the count feeds it is unknown.
}
