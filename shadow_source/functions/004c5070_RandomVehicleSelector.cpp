// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5070
// Canonical corpus name: RandomVehicleSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomVehicleSelector_004c5070.c

void UnknownObject::RandomVehicleSelector()
{
    // Selects a random vehicle entry from a filtered, singly-linked candidate list owned by `this`. Derives a random index from a 64-bit random state read at `this`+0x14, uses BoundsCheckedIndexSetter_6760 to turn the high dword into an index against the list, walks the list to the indexed node, and returns the corresponding vehicle array entry (dword_8AC394 + 1060 * vehicleIndex) when the vehicle index is within the global vehicle count dword_8AC390. Aborts with 0 on a negative requested index a2, an invalid random state, an out-of-range list index, or an invalid vehicle index.
    // GUARD: Return 0 immediately when the requested index a2 is negative. [source:raw]
    // CALL: Read a 64-bit random state from offset 0x14 of `this` via ReadFieldAtOffset0x14; the low dword and high dword (SHIDWORD/HIDWORD) are compared and indexed separately. [callee:0x005871F0, source:raw]
    // GUARD: Return 0 when the signed high 32-bit half of the random state is not below the low 32-bit half, i.e. the RNG range looks invalid. [source:raw]
    // CALL: Pass the high 32-bit half of the random state to BoundsCheckedIndexSetter_6760; the helper's register outputs feed the following list walk (index in v3, list pointer in v4). [callee:0x004C6760, source:raw]
    // GUARD: Proceed with the list walk only when the derived index v3 is below the list count stored at v4 + 20. [source:raw]
    // ASSIGNMENT: Load the linked-list head pointer stored at v4 + 8 into v5. [source:raw]
    // LOOP: Walk the singly-linked list from the head following next pointers at node + 4, consuming v3 steps; stop when the index is exhausted or the list ends. [source:raw]
    // ASSIGNMENT: Resolve the selected node pointer v6; v6 becomes 0 when the list is empty, the walk ran out, or the index was out of range. [source:raw]
    // ASSIGNMENT: Read the vehicle index v7 from the first dword of the selected list node. [source:raw]
    // GUARD: Accept the vehicle index only when v7 lies in the valid global range [0, dword_8AC390). [global:0x008AC390, source:raw]
    // RETURN: Return the vehicle entry pointer dword_8AC394 + 1060 * v7 (global vehicle-array base plus 1060-byte stride per index), or return 0 when the index is rejected. [global:0x008AC394, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C5070(void* this, int a2) {
    //     if (a2 < 0) return 0;
    //     __int64 rng = ReadFieldAtOffset0x14(this);
    //     if (SHIDWORD(rng) >= (int)rng) return 0;
    //     BoundsCheckedIndexSetter_6760(HIDWORD(rng));   // leaves index in v3, list in v4
    //     if (v3 < *(int*)(v4 + 20)) {
    //       v5 = *(int*)(v4 + 8);
    //       if (v3 <= 0) { if (v5) v6 = *(int**)v5; else v6 = 0; }
    //       else { while (v5) { v5 = *(int*)(v5 + 4); if (--v3 <= 0) { v6 = *(int**)v5; break; } } }
    //     } else { v6 = 0; }
    //     if (!v6) return 0;
    //     int v7 = *v6;
    //     if (v7 >= 0 && v7 < dword_8AC390) return dword_8AC394 + 1060 * v7;
    //     return 0;
    //   }
    // UNRESOLVED: Exact register-return contract of BoundsCheckedIndexSetter_6760 (index in v3, list pointer in v4) is inferred from subsequent use, not confirmed.
    // UNRESOLVED: Vehicle entry layout behind dword_8AC394 + 1060 * v7 and list-node contents beyond the first dword are unknown.
    // UNRESOLVED: Meaning of a2 and why a negative value aborts selection are unconfirmed.
    // UNRESOLVED: The 64-bit random state layout and the source of the low/high range check are unconfirmed.
}
