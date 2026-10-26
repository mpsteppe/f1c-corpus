// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044BC50
// Canonical corpus name: sub_44BC50
// Owner: CollisionSceneDataLoader [DERIVED]
// Raw source: functions/sub_44BC50_0044bc50.c

void CollisionSceneDataLoader::LoadCollisionSceneData()
{
    // Loads collision geometry for a track scene file. Reads a header/version string from the global version file constant, reads an object count from the caller's scene-data struct, allocates and fills a 92-byte-per-object collision object buffer (stored at this+0) and a 16-byte-per-node array (stored at this+1), counts and linearizes a BVH/dynamics tree into a temporary pointer array, links contact pairs into the node array, then frees temporaries and performs conditional file-handle and field cleanup. Called by SceneTrackFileLoader (0044C0E0).
    // CALL: Zero-initialize the stack tracking struct v24 used later by the conditional cleanup helpers [callee:0x005668B0, source:raw]
    // CALL: FileAttributesExistenceCheck(a2): verify the scene file at path a2 exists before loading [callee:0x00568540, source:raw]
    // CALL: sub_566940(a2, 4, 0, 1): open/parse the scene file with a 4-byte element size [callee:0x00566940, source:raw]
    // CALL: ConditionalDispatch_6bd0(aVer006ThisFile, 46): read the 46-byte version/header string from the global version-file constant 005C445C [callee:0x00566BD0, global:0x005C445C, source:raw]
    // CALL: ConditionalDispatch_6bd0 on this+2, this+4, this+6, this+8 with size 8: read four 8-byte header values at this byte offsets 8, 16, 24, 32 [callee:0x00566BD0, source:raw]
    // ASSIGNMENT: v21 = *a3: read the collision object count from the first dword of the caller scene-data struct [source:raw]
    // CALL: ConditionalDispatch_6bd0(&v21, 4): read the 4-byte object count [callee:0x00566BD0, source:raw]
    // CALL: v4 = OperatorNewNhMallocWrapper(92 * v21): allocate 92 bytes per collision object [callee:0x00587C03, source:raw]
    // ASSIGNMENT: *this = v4: store the collision object data buffer pointer at this+0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Record the allocation in the tracking struct: v24[9] = v4 (buffer), v24[8] = v21 (object count), v24[7] = 0 [source:raw]
    // CALL: v28 = OperatorNewNhMallocWrapper(16 * v21): allocate a temporary 16-byte-per-object buffer [callee:0x00587C03, source:raw]
    // CALL: v23 = RecursiveNodeCount(v21): count total collision nodes derived from the object count [callee:0x0044BC10, source:raw]
    // CALL: ConditionalDispatch_6bd0(&v23, 4): read the 4-byte node count [callee:0x00566BD0, source:raw]
    // CALL: v6 = OperatorNewNhMallocWrapper(16 * v23 + 4): allocate a 4-byte count header plus 16 bytes per collision node [callee:0x00587C03, source:raw]
    // GUARD: if (v6) branch on allocation success; on failure v10 = 0 and the node array pointer is stored as null [source:raw]
    // ASSIGNMENT: On success store the node count in the header *v6 = v5 and advance v8 = v6 + 1 to the first node slot [source:raw]
    // LOOP: do { CollisionObjectInit(v8); v8 += 16 bytes; } while (--v5): initialize each 16-byte collision node in the array [callee:0x0044A430, source:raw]
    // ASSIGNMENT: this[1] = v10: store the initialized collision node array pointer at this+4 (v27 also keeps a copy on the stack) [field:this:0x00000004, source:raw]
    // CALL: v12 = DynamicsNodeCountRecursive(a3[3]): when a3[3] is non-null, recursively count the dynamics/BVH tree nodes [callee:0x004486A0, source:raw]
    // CALL: ConditionalDispatch_6bd0(&v22, 4): read the 4-byte dynamics/BVH node count [callee:0x00566BD0, source:raw]
    // CALL: v14 = OperatorNewNhMallocWrapper(4 * v22): allocate a 4-byte-per-node pointer array for the linearized BVH [callee:0x00587C03, source:raw]
    // CALL: BVHTreeLinearize(a3[3], v14, 0): when a3[3] is non-null, flatten the BVH tree into the v14 pointer array [callee:0x004486E0, source:raw]
    // LOOP: for i in 0..v22: read each linearized node pointer v18 = v16[i] and ConditionalDispatch_6bd0 its fields at v18+0 (4 bytes), v18+16 (8 bytes), v18+12 (4 bytes) [callee:0x00566BD0, source:raw]
    // CALL: v19 = ContactPairLinkedListBuilder(a3): build the linked list of contact pairs from the scene data struct [callee:0x004496D0, source:raw]
    // GUARD: if (v19) non-null contact-pair list: set v25 = 1 and run sub_44A4B0(v27, *(float*)&v19, v24) to link contact pairs against the collision node array [source:raw]
    // CALL: sub_44A4B0(v27, *(float*)&v19, v24): process contact pair data against the initialized node array at v27 [callee:0x0044A4B0, source:raw]
    // CALL: if (v16) FreeWrapper_7bcf(v16): free the linearized BVH pointer array [callee:0x00587BCF, source:raw]
    // CALL: if (v28) FreeWrapper_7bcf(v28): free the temporary 16-byte-per-object buffer [callee:0x00587BCF, source:raw]
    // CALL: ConditionalFileHandleCloseWithFlagDispatch(v24): conditionally close the scene file handle tracked in v24 [callee:0x00566B90, source:raw]
    // CALL: SubCallWithConditionalFieldFree(v24): perform the conditional field free of the tracking struct v24 [callee:0x005668D0, source:raw]
    // RETURN: return 0: function always returns success (0) [function:0x0044BC50, source:raw]

    // Conservative worker pseudocode:
    //   ZeroInitSmallStruct(track);
    //   FileAttributesExistenceCheck(filePath);
    //   sub_566940(filePath, 4, 0, 1);
    //   ConditionalDispatch_6bd0(aVer006ThisFile, 46);
    //   ConditionalDispatch_6bd0(this+2, 8);
    //   ConditionalDispatch_6bd0(this+4, 8);
    //   ConditionalDispatch_6bd0(this+6, 8);
    //   ConditionalDispatch_6bd0(this+8, 8);
    //   objectCount = *sceneData;
    //   ConditionalDispatch_6bd0(&objectCount, 4);
    //   this[0] = alloc(92 * objectCount);
    //   track[9] = this[0]; track[8] = objectCount; track[7] = 0;
    //   tempBuffer = alloc(16 * objectCount);
    //   nodeCount = RecursiveNodeCount(objectCount);
    //   ConditionalDispatch_6bd0(&nodeCount, 4);
    //   nodeArray = alloc(16 * nodeCount + 4);
    //   if (nodeArray) {
    //     nodeArray[0] = nodeCount;
    //     p = nodeArray + 1;
    //     while (nodeCount) { CollisionObjectInit(p); p += 16; --nodeCount; }
    //   }
    //   this[1] = nodeArray;
    //   if (sceneData[3])
    //     dynamicsCount = DynamicsNodeCountRecursive(sceneData[3]);
    //   ConditionalDispatch_6bd0(&dynamicsCount, 4);
    //   bvArray = alloc(4 * dynamicsCount);
    //   if (sceneData[3])
    //     BVHTreeLinearize(sceneData[3], bvArray, 0);
    //   for (i = 0; i < dynamicsCount; ++i) {
    //     node = bvArray[i];
    //     ConditionalDispatch_6bd0(node, 4);
    //     ConditionalDispatch_6bd0(node + 16, 8);
    //     ConditionalDispatch_6bd0(node + 12, 4);
    //   }
    //   pairs = ContactPairLinkedListBuilder(sceneData);
    //   if (pairs) {
    //     hasPairs = 1;
    //     sub_44A4B0(this[1], pairs, track);
    //   }
    //   if (bvArray) FreeWrapper_7bcf(bvArray);
    //   if (tempBuffer) FreeWrapper_7bcf(tempBuffer);
    //   ConditionalFileHandleCloseWithFlagDispatch(track);
    //   SubCallWithConditionalFieldFree(track);
    //   return 0;
    // UNRESOLVED: The raw source dispatches on this byte offsets 8, 16, 24 and 32 (this+2..this+8), but the packet declares fields only for this+0 and this+4, so no field evidence refs exist for those reads
    // UNRESOLVED: The exact role of sub_566940(a2, 4, 0, 1) and the meaning of its constant arguments is unknown
    // UNRESOLVED: The 16-byte-per-object temporary v28 is allocated and later freed but never dereferenced inside this function; its intermediate purpose is unclear
    // UNRESOLVED: The return value of ContactPairLinkedListBuilder is reinterpreted as a float (*(float*)&v19) when passed to sub_44A4B0; the float contract of the pair-list pointer is unverified
    // UNRESOLVED: The meaning of the flag v25 set to 1 when contact-pair processing ran is not evidenced
    // UNRESOLVED: The proposed owner name CollisionSceneDataLoader is DERIVED from the caller SceneTrackFileLoader and the collision callee set; it is not confirmed by any runtime evidence
}
