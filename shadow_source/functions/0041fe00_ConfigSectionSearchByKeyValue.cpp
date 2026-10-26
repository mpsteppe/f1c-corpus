// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041FE00
// Canonical corpus name: ConfigSectionSearchByKeyValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConfigSectionSearchByKeyValue_0041fe00.c

void UnknownObject::ConfigSectionSearchByKeyValue()
{
    // __thiscall that searches a global linked list of config sections (root dword_7D2DB0) for the first section whose type tag at a backwards-walked offset equals 10 and whose associated scene/season name matches the target. Two name-acquisition paths exist: the single-name path reads the section's scene name directly via SceneNamePointer, while the multi-name path loops over entries with SceneNameLookupBySeason into a local 80-byte buffer. Both paths run the same match test through sub_588410, and the function returns the index of the first matching section, or 0 when none matches.
    // CALL: Query section count: v2 = sub_4C2990(&dword_7D2DB0) reads the number of sections held by the global list rooted at dword_7D2DB0. [callee:0x004C2990, global:0x007D2DB0, source:raw]
    // GUARD: If v2 is zero the search ends immediately, leaving the result v1 at 0 (no sections to scan). [source:raw]
    // CALCULATION: Compute the last section index v3 = v2 - 1 and the per-section byte offset v4 = 4 * v3 + 216; the search walks section entries backwards from the last one. [source:raw]
    // LOOP: Outer do-while over sections: repeat while v3 >= 0; each iteration increments result index v1, decrements v3, and subtracts 4 from the section offset v4 (backwards walk through the section table). [source:raw, function:0x0041FE00]
    // CALL: Fetch current section node: LinkedListDereference(&dword_7D2DB0) returns the current list node and FixedOffsetReturn(v5) yields the node base used for the type-tag read. [callee:0x004C2850, callee:0x004C1390, global:0x007D2DB0]
    // GUARD: Section type check: *(DWORD*)(v4 + FixedOffsetReturn(v5)) == 10 selects which name-lookup path runs for this section. [callee:0x004C1390, source:raw]
    // CALL: Single-name path: SceneNamePointer(v7) obtains the section's scene name (stored as v13), then sub_588410(this, v13) tests whether the target matches it. [callee:0x004C0A80, callee:0x00588410]
    // CALL: Multi-name path setup: resets entry counter v9 = 0, re-fetches the node via LinkedListDereference, and bails out returning v1 when ActiveEntityCounter(v10) <= 0 (no entries to scan). [callee:0x004C2850, callee:0x004C1370, source:raw]
    // LOOP: Inner while loop over section entries: for each entry index v9, ShortComputation_13a0(v9) computes the entry offset, SceneNameLookupBySeason(v15, 80) fills the local 80-byte name buffer, and the section is accepted when *(DWORD*)(v4 + ShortComputation_13a0(v9)) == 10. [callee:0x004C13A0, callee:0x004C0A20, callee:0x004C2850, source:raw]
    // STATE_TRANSITION: Advance the entry counter: ++v9, then stop and return v1 when v9 >= ActiveEntityCounter(v11). [callee:0x004C1370, source:raw]
    // CALL: Multi-name match: sub_588410(v15, this) tests the season-name buffer filled by SceneNameLookupBySeason against the target. [callee:0x00588410]
    // GUARD: Match test: if v8 is nonzero, break the outer loop (matching section found); otherwise continue walking to the previous section. [source:raw]
    // RETURN: Return v1, the index of the first matching section (or 0 when nothing matches); thiscall contract per the ABI lead name ConfigSectionSearchByKeyValue. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   index = 0;
    //   count = sub_4C2990(&dword_7D2DB0);
    //   if (count != 0) {
    //     last = count - 1;
    //     off = 4 * last + 216;
    //     do {
    //       node = LinkedListDereference(&dword_7D2DB0);
    //       if (*(DWORD*)(off + FixedOffsetReturn(node)) == 10) {
    //         name = SceneNamePointer(FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0)));
    //         matched = sub_588410(this, name);
    //       } else {
    //         i = 0;
    //         if (ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)) <= 0) return index;
    //         while (1) {
    //           LinkedListDereference(&dword_7D2DB0);
    //           ShortComputation_13a0(i);
    //           SceneNameLookupBySeason(nameBuffer80, 80);
    //           LinkedListDereference(&dword_7D2DB0);
    //           if (*(DWORD*)(off + ShortComputation_13a0(i)) == 10) break;
    //           ++i;
    //           if (i >= ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0))) return index;
    //         }
    //         matched = sub_588410(nameBuffer80, this);
    //       }
    //       if (matched) break;
    //       ++index;
    //       --last;
    //       off -= 4;
    //     } while (last >= 0);
    //   }
    //   return index;
    // UNRESOLVED: Exact semantics of sub_4C2990 (returns the count that bounds the section walk) are not established.
    // UNRESOLVED: Exact semantics of sub_588410 (the match test) and of its two argument orders (this, name) vs (buffer, this) are not established.
    // UNRESOLVED: Meaning of the section type tag 10 and of the entry stride/base computation 4 * v3 + 216 are not established.
    // UNRESOLVED: Legacy helper labels FixedOffsetReturn, ShortComputation_13a0, ActiveEntityCounter, SceneNameLookupBySeason and LinkedListDereference carry unknown exact semantics.
    // UNRESOLVED: Only caller CompareResultTo2 (0x0041FDF0) is known; it suggests the return value is consumed as a comparison outcome.
}
