// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A700
// Canonical corpus name: CollisionTreeNodeDeserializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionTreeNodeDeserializer_0044a700.c

void UnknownObject::CollisionTreeNodeDeserializer()
{
    // Recursively deserializes one collision tree node from a file stream. Reads a header, then a signed node-type byte stored at offset 8: internal types 0/1 read a subtype byte at offset 10 and recurse into two children (offset 12 = child-slot arena pointer v2[12] + 16*v2[10]); negative leaf types (-1 = single, -2 = pair) allocate a 92-byte vertex output region (offset 12 = v2[9] + 92*v2[7]) and read v7 indexed vertices via IndexedVertexLookupFromStream. Called by HTreeTerrainFileFormatLoader while loading a terrain file.
    // GUARD: First file read: FileWriteWithBackendDispatch(this, 4) must return exactly 4, otherwise fail with -1. [callee:0x00566C00]
    // GUARD: Second file read: FileWriteWithBackendDispatch(this + 4, 4) must return 4, otherwise fail with -1. [callee:0x00566C00]
    // GUARD: Third file read: read a single type byte into the low byte of the a2 argument; must return 1, otherwise fail with -1. [callee:0x00566C00]
    // ASSIGNMENT: Store the signed type byte as a word at field offset 8 (node type). [field:this:0x00000008, source:raw]
    // GUARD: Reject node type <= -3 as invalid; return -1. [source:raw]
    // GUARD: Reject node type >= 2 as invalid; return -1. [source:raw]
    // ASSIGNMENT: Choose vertex count v7: default 2; -1 (single leaf) sets v7 = 1; -2 (pair leaf) keeps v7 = 2; any other negative value uses v7 = (int)a2. [source:raw]
    // ASSIGNMENT: Leaf storage: compute vertex output pointer at offset 12 as v2[9] + 92 * v2[7], and advance the arena cursor v2[7] by v7. [field:this:0x0000000C, source:raw]
    // LOOP: Read v7 indexed vertices: repeatedly call IndexedVertexLookupFromStream on advancing 92-byte slots; when all are read return 0, and if a lookup reports failure return -1. [callee:0x00449F60, source:raw]
    // CALL: Internal node: read one subtype byte via FileWriteWithBackendDispatch into a local; failure returns -1. [callee:0x00566C00]
    // ASSIGNMENT: Store the subtype byte at field offset 10. [field:this:0x0000000A]
    // ASSIGNMENT: Internal storage: set offset 12 to v2[12] + 16 * v2[10] (child-slot arena) and advance v2[10] by 2. [field:this:0x0000000C, source:raw]
    // CALL: Recurse to deserialize the first child; a nonzero result fails the node. [callee:0x0044A700]
    // CALL: Recurse to deserialize the second child; a nonzero result fails the node, otherwise the node is a success. [callee:0x0044A700]
    // RETURN: Failure paths return -1; leaf success returns 0; internal success returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_44A700(int this, _DWORD *a2) {
    //     if (FileWriteWithBackendDispatch(this, 4) != 4) return -1;
    //     if (FileWriteWithBackendDispatch(this + 4, 4) != 4) return -1;
    //     if (FileWriteWithBackendDispatch(&a2, 1) != 1) return -1;
    //     char type = (char)a2;
    //     *(WORD *)(this + 8) = type;
    //     if (type <= -3 || type >= 2) return -1;
    //     if (type < 0) {
    //       int count = (type == -1) ? 1 : (type == -2 ? 2 : (int)a2);
    //       *(DWORD *)(this + 12) = a2[9] + 92 * a2[7];
    //       a2[7] += count;
    //       for (int i = 0; i < count; ++i) {
    //         if (IndexedVertexLookupFromStream((DWORD *)(*(DWORD *)(this + 12)) + 23 * i, (int)a2)) return -1;
    //       }
    //       return 0;
    //     }
    //     BYTE sub;
    //     if (FileWriteWithBackendDispatch(&sub, 1) != 1) return -1;
    //     *(WORD *)(this + 10) = sub;
    //     *(DWORD *)(this + 12) = a2[12] + 16 * a2[10];
    //     a2[10] += 2;
    //     if (CollisionTreeNodeDeserializer(a2)) return -1;
    //     return CollisionTreeNodeDeserializer(a2) ? -1 : 0;
    //   }
    // UNRESOLVED: The a2 arena cursor block layout (indices 7, 9, 10, 12) and the exact meaning of the offset-8 type byte are not defined by this packet; they are imposed by the terrain-file format owned by the caller.
    // UNRESOLVED: The relationship between the 92-byte leaf stride and the 16-byte internal child stride is presumed from the offsets in the raw source and is unconfirmed by independent evidence.
    // UNRESOLVED: Vertex-count path (int)a2 for negative types other than -1/-2 is decompiler-derived and its real format meaning is unknown.
}
