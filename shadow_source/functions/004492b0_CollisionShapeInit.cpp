// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004492B0
// Canonical corpus name: CollisionShapeInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionShapeInit_004492b0.c

void UnknownObject::CollisionShapeInit()
{
    // Initializes a collision shape object: clears three integer fields at this+0x8, this+0xC and this+0x10 to 0, calls PhysicsBufferFree() to reset the physics buffer, and returns the this pointer. Called by BezierPatchTessellation (0x0044B370), CollisionGeometryOperationSelector (0x0044BB60) and SceneTrackFileLoader (0x0044C0E0).
    // ASSIGNMENT: Clear the first collision shape field: this[2] (offset 0x8) = 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Clear the second collision shape field: this[3] (offset 0xC) = 0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear the third collision shape field: this[4] (offset 0x10) = 0. [field:this:0x00000010, source:raw]
    // CALL: Call PhysicsBufferFree() with no arguments to deallocate or reset the physics buffer. [callee:0x00449340, source:raw]
    // RETURN: Return the this pointer, making the function a constructor-style initializer. [source:raw]
    // CALL: Invoked by BezierPatchTessellation (0x0044B370), CollisionGeometryOperationSelector (0x0044BB60) and SceneTrackFileLoader (0x0044C0E0) when preparing collision shapes. [caller:0x0044B370, caller:0x0044BB60, caller:0x0044C0E0]

    // Conservative worker pseudocode:
    //   _DWORD *__thiscall CollisionShapeInit(_DWORD *this) {
    //     this[2] = 0;
    //     this[3] = 0;
    //     this[4] = 0;
    //     PhysicsBufferFree();
    //     return this;
    //   }
    // UNRESOLVED: The exact roles of the cleared fields at 0x8, 0xC and 0x10 in the collision shape structure are DERIVED prose (buffer pointer, bounds, flags); they are not packet evidence.
    // UNRESOLVED: PhysicsBufferFree is called with no explicit argument, so its association with this shape object's buffer is unproven.
}
