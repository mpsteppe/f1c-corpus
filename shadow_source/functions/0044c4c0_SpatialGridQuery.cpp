// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C4C0
// Canonical corpus name: SpatialGridQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialGridQuery_0044c4c0.c

void UnknownObject::SpatialGridQuery()
{
    // 2D spatial-grid collision query. Reads the cached surface pointer at a2+48; when it is invalid (NULL, validity byte at +88 set, or QuadraticSurfaceCollisionTest failing) the cached pointer is cleared and the world position (a2+0, a2+16) is mapped through the grid origin/scale doubles into cell indices. In-bounds cells (both indices < 0x20) that hold a BVH pointer get BVHTreeTraversal called. Returns the final cached-surface pointer at a2+48. Part of the collision detection system, called from suspension, contact generation and camera paths.
    // CALCULATION: Load the cached surface pointer v4 from a2+48 [source:raw]
    // GUARD: Grid re-query path runs only when the cache misses: v4 is NULL, or the byte at v4+88 is non-zero, or QuadraticSurfaceCollisionTest on the cached surface fails [callee:0x0044A070, source:raw]
    // CALL: QuadraticSurfaceCollisionTest((double *)v4, a2) re-validates the cached surface against the query position [callee:0x0044A070]
    // ASSIGNMENT: Clear the cached surface pointer at a2+48 to 0 before recomputing the grid lookup [source:raw]
    // CALCULATION: Map world position to cell indices: v9 = (int)((a2_x - this[1]) * this[2]) and v8 = (int)((a2_z - this[3]) * this[4]) using the grid origin and inverse cell-size doubles [field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020]
    // GUARD: Proceed only when both cell indices are below 0x20, i.e. the position maps inside the 32x32 grid bounds [source:raw]
    // CALCULATION: Look up the BVH pointer v6 at the cell slot addressed from the grid base (this[16*v9+5] indexed by v8) [source:raw]
    // GUARD: BVHTreeTraversal is invoked only when the grid cell holds a non-NULL BVH tree pointer [source:raw]
    // CALL: BVHTreeTraversal(v6, (double *)a2) traverses the cell's BVH tree to find the closest colliding surface [callee:0x0044AA30]
    // RETURN: Return the cached-surface pointer stored at a2+48 (unchanged on a cache hit, updated by the traversal otherwise); used by suspension, contact-generation and camera collision callers [function:0x0044C4C0, caller:0x00401340, caller:0x00436870, caller:0x004A3B50, source:raw]

    // Conservative worker pseudocode:
    //   v4 = *(a2 + 48);
    //   if (!v4 || *(v4 + 88) || !QuadraticSurfaceCollisionTest(v4, a2)) {
    //     *(a2 + 48) = 0;
    //     v9 = (int)((*a2 - this[1]) * this[2]);
    //     v8 = (int)((*(a2 + 16) - this[3]) * this[4]);
    //     if (v9 < 0x20 && v8 < 0x20) {
    //       v6 = *((double **)*((_DWORD *)&this[16 * v9 + 5] + v8));
    //       if (v6) BVHTreeTraversal(v6, a2);
    //     }
    //   }
    //   return *(a2 + 48);
    // UNRESOLVED: The query-struct layout (a2+0 position X, a2+16 position Z, a2+48 cached surface, a2+88 validity byte) is not enumerated as packet fields because a2 is an argument, not a 'this'/'obj' base
    // UNRESOLVED: Semantics of the validity byte at v4+88 (dirty/invalid marker) is undocumented
    // UNRESOLVED: The grid cell array addressed from this[16*v9+5] is not enumerated as packet fields; only the origin/scale doubles at 0x8..0x20 are
    // UNRESOLVED: The exact cache invalidation contract between QuadraticSurfaceCollisionTest and the +88 byte is not fully determined
}
