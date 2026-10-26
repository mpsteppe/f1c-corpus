// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044B040
// Canonical corpus name: CollisionCapsuleShapeCopyToPipeline
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionCapsuleShapeCopyToPipeline_0044b040.c

void UnknownObject::CollisionCapsuleShapeCopyToPipeline()
{
    // Copies a capsule/collision shape payload (0x18 bytes from a1) into a stack AABB collision body initialized by AABBCollisionBodyInitializer, applies a small-struct copy from a2 into the same buffer, then fits a HAT polygon surface onto the result and returns the fit result. Called from sub_44B110 and BezierPatchTessellation.
    // CALL: Initialize the local AABB collision body buffer v4 via AABBCollisionBodyInitializer(v4). [callee:0x00448E90]
    // ASSIGNMENT: qmemcpy copies 0x18 bytes from the source payload a1 into the initialized AABB body buffer v4. [source:raw]
    // CALL: SmallStructCopy(v4, a2) copies the small struct at a2 into the buffer v4, overlaying the copied payload. [callee:0x00448EC0]
    // CALL: HATPolygonSurfaceFit(a3, v4, 0) fits a HAT polygon surface to the assembled collision body; a3 receives the fit output. [callee:0x00449A80]
    // RETURN: Return the integer result of HATPolygonSurfaceFit(a3, v4, 0). [callee:0x00449A80]

    // Conservative worker pseudocode:
    //   int sub_44B040(const void *a1, int a2, _DWORD *a3) {
    //       AABB u8 v4[32];
    //       AABBCollisionBodyInitializer(v4);
    //       memcpy(v4, a1, 0x18);
    //       SmallStructCopy(v4, a2);
    //       return HATPolygonSurfaceFit(a3, v4, 0);
    //   }
    // UNRESOLVED: Purpose of the 0x18-byte capsule payload copied from a1 is unlabeled beyond the function name.
    // UNRESOLVED: Semantic of the third HATPolygonSurfaceFit argument 0 is not established.
}
