// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044ACB0
// Canonical corpus name: AnimationPlaybackSequence
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AnimationPlaybackSequence_0044acb0.c

void UnknownObject::AnimationPlaybackSequence()
{
    // Iterates the audio/animation network node list and, for each scene-graph child flagged with bit 0x100 set at +20, scans its camera-distance entries, matches each entry's candidate name (built by ArithmeticComparison_7370) against a cached name buffer seeded from byte_5EA438, and for entries with valid animation float data computes the triangle normal, assembles vertex triples, and calls RecursiveTriangleEdgeSubdivisionForCollision to generate collision geometry. Returns the final node count.
    // ASSIGNMENT: Seed the 61-byte name buffer v38: first byte from byte_5EA438, remaining 0x3C bytes zeroed via memset, terminator fields v39/v40 cleared. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Save this as v25; seed the cached lookup index v18 = -1 and the cached value v20 = 0. [source:raw]
    // CALL: AudioNetworkNodeCount(a2) returns the audio/animation network node count, stored in v26. [callee:0x005452F0, source:raw]
    // LOOP: Outer do-while over the node count v26; LinkedListNodeFinder(v3) retrieves the network node at index v3. [callee:0x00545340, source:raw]
    // CALL: SceneGraphChildCount(v24) returns the scene-graph child count v23 for the node. [callee:0x0054C210, source:raw]
    // LOOP: Middle do-while over v23 children; LinkedListIndexedAccessor_c230(v5) yields each child entry v6. [callee:0x0054C230, source:raw]
    // GUARD: Select only children whose dword field at +20 has bit 0x100 set (animation-driven mesh flag). [source:raw]
    // CALL: CameraDistanceGetter(v6) returns the camera-distance entry count v22 for the child. [callee:0x0054E190, source:raw]
    // LOOP: Innermost do-while over v22 entries; ArrayIndexRead(v7) indexes the current entry by v7. [callee:0x0054E240, source:raw]
    // CALL: ArithmeticComparison_7370(v37) fills the candidate name string v37 for the current entry. [callee:0x00547370, source:raw]
    // GUARD: If v37 equals the cached name v38, reuse cached index v18 and value v20; otherwise perform a fresh lookup. [source:raw]
    // CALL: StringListLookup(v37) resolves the candidate name to a cached string id v8. [callee:0x004CE860, source:raw]
    // CALL: IndexedArrayAccess(v8) returns the animation metadata entry v9 for the resolved id. [callee:0x004CE8D0, source:raw]
    // ASSIGNMENT: Copy v37 into the cached name buffer v38 via a do-while string copy and update the cache: v18 = v8, v20 = v9. [source:raw]
    // GUARD: Accept the entry only when its float fields differ: *(float*)(v9+8) - *(float*)(v9+12) * 0.0 != 0.0. [source:raw]
    // CALL: IndexedTransformRead(v7, v27, v29, v30) reads the transform for entry v7 into output buffers. [callee:0x0054E1A0, source:raw]
    // CALL: TriangleNormalComputation(v30, v31) computes the triangle normal from the transform data. [callee:0x004DD9F0, source:raw]
    // GUARD: Emit geometry only when the normal computation succeeds (zero return) and area value v32 >= 0.001. [source:raw]
    // CALCULATION: Assemble vertex triples: three-iteration copy loop scattering float values from the v28 source group into the v34 destination group. [source:raw]
    // CALL: RecursiveTriangleEdgeSubdivisionForCollision(v33, v35, v36, v16, a3) generates collision geometry from the assembled triangle. [callee:0x0044AAE0, source:raw]
    // RETURN: Return the last node count value held in result (v26). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_44ACB0(void *this, int a2, char **a3) {
    //     char name[61]; name[0] = byte_5EA438; memset(name + 1, 0, 0x3C);
    //     int cachedIndex = -1, cachedValue = 0;
    //     int nodeCount = AudioNetworkNodeCount(a2);
    //     for (int n = 0; n < nodeCount; ++n) {
    //       void *node = LinkedListNodeFinder(n);
    //       int childCount = SceneGraphChildCount(node);
    //       for (int c = 0; c < childCount; ++c) {
    //         void *child = LinkedListIndexedAccessor_c230(c);
    //         if ((*(int*)((char*)child + 20) & 0x100) == 0x100) {
    //           int camCount = CameraDistanceGetter(child);
    //           for (int k = 0; k < camCount; ++k) {
    //             ArrayIndexRead(k);
    //             ArithmeticComparison_7370(candidate);
    //             int id, entry;
    //             if (strcmp(candidate, name) == 0) { id = cachedIndex; entry = cachedValue; }
    //             else { id = StringListLookup(candidate); entry = IndexedArrayAccess(id);
    //                    copyName(name, candidate); cachedIndex = id; cachedValue = entry; }
    //             if (entry) {
    //               if (*(float*)((char*)entry + 8) - *(float*)((char*)entry + 12) * 0.0f != 0.0f) {
    //                 IndexedTransformRead(k, bufA, bufB, bufC);
    //                 if (TriangleNormalComputation(bufC, normal) == 0 && area >= 0.001) {
    //                   RecursiveTriangleEdgeSubdivisionForCollision(v33, v35, v36, v16, a3);
    //                 }
    //               }
    //             }
    //           }
    //         }
    //       }
    //     }
    //     return nodeCount;
    //   }
    // UNRESOLVED: Packet lists globals flt_59E440, dbl_59EA08 and dword_8ACEA0 as read, but none appears in the raw source text; their role here is unresolved.
    // UNRESOLVED: Semantics of the child field bit 0x100 and the camera-distance entry selection are not resolved from this scope.
    // UNRESOLVED: Exact layout and meaning of the v30/v31 transform buffers shared by IndexedTransformRead and TriangleNormalComputation is unresolved.
    // UNRESOLVED: Owning object is UnknownObject; the only known caller is CollisionGeometryOperationSelector (0x0044BB60).
}
