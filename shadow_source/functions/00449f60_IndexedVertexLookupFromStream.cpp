// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449F60
// Canonical corpus name: IndexedVertexLookupFromStream
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedVertexLookupFromStream_00449f60.c

void UnknownObject::IndexedVertexLookupFromStream()
{
    // Builds a triangle work set from stream data and packed vertex indices. Reads 34 bytes from the stream via FileWriteWithBackendDispatch and, only when exactly 34 bytes are obtained, initializes a collision body with AABBCollisionBodyInitializer, fills a six-entry pointer array with 96-byte-strided work structs, unpacks three vertex indices from two packed dwords, and for each valid index copies a 16-byte vertex record from the caller's array (count at a2+52, records at a2+56) into the matching work struct. When all three indices resolve it calls HATPolygonSurfaceFit(this, &v15, 1) and returns its result; any read failure or out-of-range index returns -1.
    // GUARD: Read 34 bytes of stream data into the local buffer via FileWriteWithBackendDispatch; proceed only when the byte count returned is exactly 34. [callee:0x00566C00, source:raw]
    // CALL: Initialize the collision-body structure v15 via AABBCollisionBodyInitializer. [callee:0x00448E90, source:raw]
    // LOOP: Fill a six-entry pointer array anchored at v15, storing pointers spaced 96 bytes apart that reference the per-triangle work structs. [source:raw]
    // ASSIGNMENT: Copy the short value v21 into v17 as a local copy. [source:raw]
    // LOOP: Iterate three times over pointers taken from the local pointer array, writing two dwords from the stream buffer into each pointed struct at byte offsets 16 and 20. [source:raw]
    // CALCULATION: Unpack three packed vertex indices from the two stream dwords: the first is the low 21 bits of the first dword, the second combines the high 11 bits of the first dword with the low 10 bits of the second, and the third is the remaining high bits of the second dword. [source:raw]
    // LOOP: Iterate over the three unpacked indices, resolving each against the caller's vertex array. [source:raw]
    // GUARD: Abort the loop when an index is negative or not less than the vertex count stored at a2+52. [source:raw]
    // CALCULATION: Compute the vertex record pointer as the record-array base at a2+56 plus 16 bytes per index. [source:raw]
    // ASSIGNMENT: Copy the four dwords of the 16-byte vertex record into the target work struct at byte offsets 0, 16, 20 and 12. [source:raw]
    // CALL: Once all three indices have been resolved, call HATPolygonSurfaceFit(this, &v15, 1) and return its result. [callee:0x00449A80, source:raw]
    // RETURN: Return -1 when the stream read did not return exactly 34 bytes or an index is out of range. [source:raw]

    // Conservative worker pseudocode:
    //   if (FileWriteWithBackendDispatch(v18, 34) != 34) return -1;
    //   AABBCollisionBodyInitializer(&v15);
    //   for (v4 = 0, v5 = &v22; v4 < 6; ++v4, v5 += 96) *(&v15 + v4) = v5;
    //   v17 = v21;
    //   for (v6 = 0, v7 = (int*)&v16; v6 < 3; ++v6, v7 += 2) {
    //       v8 = *v7;
    //       *(_DWORD*)(v8 + 16) = v18[2 * v6];
    //       *(_DWORD*)(v8 + 20) = v18[2 * v6 + 1];
    //   }
    //   v14[0] = v19 & 0x1FFFFF;
    //   v14[1] = (v19 >> 21) + ((v20 & 0x3FF) << 11);
    //   v14[2] = v20 >> 10;
    //   for (v10 = 0; v10 < 3; ++v10) {
    //       v11 = v14[v10];
    //       if (v11 < 0 || v11 >= *(int*)(a2 + 52)) return -1;
    //       v13 = (int*)(*(int*)(a2 + 56) + 16 * v11);
    //       v12 = *(&v15 + 2 * v10);
    //       v12[0] = v13[0]; v12[4] = v13[1]; v12[5] = v13[2]; v12[3] = v13[3];
    //   }
    //   return HATPolygonSurfaceFit(this, (int)&v15, 1);
    // UNRESOLVED: The local buffer layout (the pointer array at v15, the pointer array at v16, and the stream fields v18/v19/v20/v21) is decompiler-stack derived; the identities and sizes of the underlying structs are not evidenced.
    // UNRESOLVED: The fields at a2+52 and a2+56 are interpreted as vertex count and vertex-record-array base respectively; that interpretation is DERIVED from the index/record usage and not independently proven.
    // UNRESOLVED: FileWriteWithBackendDispatch is named as a write helper but is invoked to read stream bytes; its exact semantics are unproven.
    // UNRESOLVED: The two dwords written into each pointed struct at byte offsets 16 and 20, and the four-dword record copy, have no named field evidence.
}
