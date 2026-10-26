// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044BB60
// Canonical corpus name: CollisionGeometryOperationSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGeometryOperationSelector_0044bb60.c

void UnknownObject::CollisionGeometryOperationSelector()
{
    // Dispatches a collision-geometry processing pipeline on the current global collision geometry handle (dword_8AFE88) based on an operation id in a2. When the handle is null, only the final sweep-and-prune is run on a3. With a2==0 the animation playback path alone runs on a3. With a2==1 the animation path is followed by contact response then sweep-and-prune on a3. With a2==2 a full pipeline runs: shape init into a local buffer v6, animation playback on v6, contact response on v6, bezier patch tessellation from v6 into a3, physics buffer free of v6, then sweep-and-prune on a3. Every path converges on returning the sweep-and-prune overlap-detection result on a3.
    // ASSIGNMENT: v3 = dword_8AFE88: cache the global collision geometry handle into the register variable used by the a2==2 path. [global:0x008AFE88, source:raw]
    // GUARD: Guard on dword_8AFE88 != 0: when the global collision geometry handle is null, skip all pipeline calls and fall through to the final sweep-and-prune on a3. [global:0x008AFE88, source:raw]
    // GUARD: When the handle is present, branch on a2: a2==0 takes the animation-only path; a2==1 takes the animation+contact+sweep path; a2==2 takes the full bezier-tessellation pipeline. [source:raw]
    // CALL: a2==1 path: AnimationPlaybackSequence(this, dword_8AFE88, a3) - run the animation-driven collision mesh generation on the global geometry handle, writing to a3. [callee:0x0044ACB0, global:0x008AFE88, source:raw]
    // CALL: a2==1 path: CollisionContactResponse((int*)a3) - compute the contact response from the animation output in a3. [callee:0x00449700, source:raw]
    // RETURN: a2==1 path: return SweepAndPruneAABBOverlapDetection((int*)a3). [callee:0x004497E0, source:raw]
    // CALL: a2==2 path: CollisionShapeInit(v6) - initialize the local collision shape structure for the bezier pipeline. [callee:0x004492B0, source:raw]
    // CALL: a2==2 path: AnimationPlaybackSequence(this, v3, v6) - run the animation-driven collision mesh generation on the cached handle, writing into the local shape buffer v6. [callee:0x0044ACB0, global:0x008AFE88, source:raw]
    // CALL: a2==2 path: CollisionContactResponse((int*)v6) - compute the contact response from the shape buffer v6. [callee:0x00449700, source:raw]
    // CALL: a2==2 path: BezierPatchTessellation(this, (int*)v6, a3) - tessellate bezier patches from the shape buffer v6 into the output a3. [callee:0x0044B370, source:raw]
    // CALL: a2==2 path: PhysicsBufferFree(v6) - free the local physics pipeline buffer after tessellation. [callee:0x00449340, source:raw]
    // RETURN: a2==2 path: return SweepAndPruneAABBOverlapDetection((int*)a3). [callee:0x004497E0, source:raw]
    // CALL: a2==0 path: AnimationPlaybackSequence(this, dword_8AFE88, a3) - run animation-only collision mesh generation. [callee:0x0044ACB0, global:0x008AFE88, source:raw]
    // RETURN: Fall-through (a2==0 and null-handle paths): return SweepAndPruneAABBOverlapDetection((int*)a3). [callee:0x004497E0, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionGeometryOperationSelector(void* this, int op, void** a3) {
    //     int handle = dword_8AFE88;
    //     if (handle) {
    //       if (op == 1) {
    //         AnimationPlaybackSequence(this, handle, a3);
    //         CollisionContactResponse(a3);
    //         return SweepAndPruneAABBOverlapDetection(a3);
    //       }
    //       if (op == 2) {
    //         void* shape[5];
    //         CollisionShapeInit(shape);
    //         AnimationPlaybackSequence(this, handle, shape);
    //         CollisionContactResponse(shape);
    //         BezierPatchTessellation(this, shape, a3);
    //         PhysicsBufferFree(shape);
    //         return SweepAndPruneAABBOverlapDetection(a3);
    //       }
    //       if (op == 0) AnimationPlaybackSequence(this, handle, a3);
    //     }
    //     return SweepAndPruneAABBOverlapDetection(a3);
    //   }
    // UNRESOLVED: The nature of the a3 pointer (collision output buffer, world geometry set, or scalar result holder) is not established by the packet; each callee consumes it as an int*.
    // UNRESOLVED: The semantic meaning of the operation ids 0/1/2 (animation-only, contact+sweep, full bezier pipeline) comes from the existing analysis prose and is not independently provable from the raw source.
    // UNRESOLVED: The owning object is not established; the packet's known caller SceneTrackFileLoader (0x0044C0E0) does not reveal the dispatch context.
    // UNRESOLVED: The shape buffer v6 element layout passed to CollisionShapeInit / PhysicsBufferFree is not described by the packet.
}
