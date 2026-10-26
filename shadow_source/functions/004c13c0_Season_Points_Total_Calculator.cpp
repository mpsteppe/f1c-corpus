// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C13C0
// Canonical corpus name: sub_4C13C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C13C0_004c13c0.c

void UnknownObject::Season_Points_Total_Calculator()
{
    // this-call method over an entity collection. Reads active entity count plus one (ActiveEntityCounter), then walks indices 0..count-1 resolving each entity pointer (first entry via FixedOffsetReturn, later entries via ShortComputation_13a0 with index-1). For each non-null entity, looks up its scene name into a 32-byte buffer with size 0x20 (SceneNameLookupBySeason) and compares it against argument a2 (sub_566810). On a match, accumulates dword element 102 of the entity into the total and returns it. ABI legacy name 'Season_Points_Total_Calculator' suggests a season-points summation; the prelabel notes a structural twin relationship to 00405160.
    // ASSIGNMENT: Initialize accumulator v8 to 0. [source:raw]
    // GUARD: Early-return 0 when name argument a2 is null/zero. [source:raw]
    // CALL: Read active entity count via ActiveEntityCounter(this) and add 1 to form loop bound v3. [callee:0x004C1370, function:0x004C13C0]
    // GUARD: Early-return 0 when loop bound v3 <= 0. [source:raw]
    // LOOP: Iterate index v4 from 0 while v4 < v3, incrementing v4 each pass. [source:raw]
    // CALL: For the first entry (v4 == 0), resolve entity pointer v5 = FixedOffsetReturn(this). [callee:0x004C1390]
    // CALL: For subsequent entries (v4 != 0), resolve entity pointer v5 = ShortComputation_13a0(this, v4 - 1). [callee:0x004C13A0]
    // GUARD: Skip iteration when the resolved entity pointer v5 is null. [source:raw]
    // CALL: Look up the entity's scene name into 32-byte buffer v9 with size 0x20 via SceneNameLookupBySeason(v5, v9, 0x20). [callee:0x004C0A20]
    // CALL: Compare the looked-up name buffer v9 against argument a2 via sub_566810. [callee:0x00566810]
    // CALCULATION: When the names match, accumulate dword element 102 of the entity into total v8. [source:raw]
    // RETURN: Return the accumulated total v8; consumed by ChampionshipPointsAccumulator, sub_47C360 and PathFileComparisonCounter. [source:raw, caller:0x0041F220, caller:0x0047C360, caller:0x004C1450]

    // Conservative worker pseudocode:
    //   int total = 0;
    //   if (a2 == 0) return 0;
    //   int count = ActiveEntityCounter(this) + 1;
    //   if (count <= 0) return 0;
    //   for (int i = 0; i < count; i++) {
    //       char* entity = (i == 0) ? FixedOffsetReturn(this) : ShortComputation_13a0(this, i - 1);
    //       if (entity == 0) continue;
    //       char name[32];
    //       SceneNameLookupBySeason(entity, name, 0x20);
    //       if (sub_566810(name, a2)) total += ((unsigned int*)entity)[102];
    //   }
    //   return total;
    // UNRESOLVED: Owner class unknown: packet fields list is empty; this points at an entity collection but no named type is evidenced.
    // UNRESOLVED: Meaning of dword element 102 of the entity not established; no field evidence in the packet.
    // UNRESOLVED: sub_566810 semantics unconfirmed; assumed name comparison against a2.
    // UNRESOLVED: Naming conflict: ABI legacy name 'Season_Points_Total_Calculator' versus prelabel cluster-twin note referencing MemoryAllocation_5160 (00405160).
    // UNRESOLVED: Guard only checks a2 for null/zero; whether a2 is a name string or an index is unresolved.
}
