// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449ED0
// Canonical corpus name: SpatialHashKeyGeneration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialHashKeyGeneration_00449ed0.c

void UnknownObject::ComputeSpatialHashKey()
{
    // Builds an 8-DWORD spatial-hash key block from three referenced objects reached through the a2 descriptor, composes two packed hash words with bit-shift fields, and submits the block to ConditionalDispatch_6bd0 with an opcode of 34; finally returns HATPolygonSurfaceFit(this, a2, 1). The this pointer and a3 are not otherwise consumed.
    // LOOP: Iterate three times over pointer pairs starting at a2+4 with stride 8; for each pair, dereference the pointer and read fields at +16 and +20 into v12[0]..v12[5]. [source:raw]
    // LOOP: Iterate i over 0..2 reading *( *(a2 + 8*i) + 72 ) into the locals v9, v10, v11. [source:raw]
    // CALCULATION: Compose the packed hash words: v12[6] = v9 + (v10 << 21); v12[7] = (v11 << 10) + (v10 >> 11). [source:raw]
    // ASSIGNMENT: Store the word at a2+26 into v13. [source:raw]
    // CALL: Call ConditionalDispatch_6bd0 (0x00566BD0) with the v12 key block and the value 34. [callee:0x00566BD0, source:raw]
    // RETURN: Return the result of HATPolygonSurfaceFit(this, a2, 1). [callee:0x00449A80, source:raw]
    // CALL: Invoked by sub_44A4B0 (0x0044A4B0). [caller:0x0044A4B0, abi:lead]

    // Conservative worker pseudocode:
    //   int ComputeSpatialHashKey(int this, int a2, int a3) {
    //     int v12[8];
    //     for (int j = 0; j < 3; j++) {
    //       int* p = *(int**)(a2 + 4 + 8*j);
    //       v12[2*j] = *(int*)(p + 4);  /* +16 * /
    //       v12[2*j+1] = *(int*)(p + 5); /* +20 * /
    //     }
    //     int v9, v10, v11;
    //     for (int i = 0; i < 3; i++) {
    //       (&v9)[i] = *(*(int**)(a2 + 8*i) + 72);
    //     }
    //     v12[6] = v9 + (v10 << 21);
    //     v12[7] = (v11 << 10) + (v10 >> 11);
    //     __int16 v13 = *(short*)(a2 + 26);
    //     ConditionalDispatch_6bd0(v12, 34);
    //     return HATPolygonSurfaceFit(this, a2, 1);
    //   }
    // UNRESOLVED: Semantic meaning of the three referenced objects and the exact spatial-hash layout of v12[6]/v12[7] is not established by packet evidence.
    // UNRESOLVED: v13 (word at a2+26) is stored but not read afterwards in this function.
    // UNRESOLVED: Arguments this and a3 are accepted but unused; class identity of this is unknown.
}
