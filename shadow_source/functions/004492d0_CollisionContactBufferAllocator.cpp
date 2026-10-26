// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004492D0
// Canonical corpus name: CollisionContactBufferAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionContactBufferAllocator_004492d0.c

void UnknownObject::CollisionContactBufferAllocator()
{
    // Allocates a heap buffer for a2 AABB collision bodies (each 32 bytes). Precedes the allocation with PhysicsBufferFree. When a2 > 0, stores the requested count at this+0x4, allocates 32*a2+4 bytes via OperatorNewNhMallocWrapper, initializes each 32-byte body slot with AABBCollisionBodyInitializer, and stores the buffer pointer at this+0x8 (null on allocation failure).
    // CALL: Call PhysicsBufferFree to free/reset the existing physics buffer before allocation. [callee:0x00449340, source:raw]
    // GUARD: Guard on a2 > 0; when no bodies are requested, allocation and buffer setup are skipped. [source:raw]
    // ASSIGNMENT: Store the requested count a2 at this+0x4. [field:this:0x00000004, source:raw]
    // CALL: Allocate 32*a2+4 bytes (count header plus body array) via OperatorNewNhMallocWrapper; the pointer becomes the result. [callee:0x00587C03, source:raw]
    // GUARD: Guard on the allocation result being non-null; on null, set this+0x8 to 0. [field:this:0x00000008, source:raw]
    // CALCULATION: Set v5 to the slot pointer one element past the header (result+1), store a2 into the header slot, and seed the loop counter with a2-1. [source:raw]
    // LOOP: do-while loop over a2 iterations using a countdown counter, iterating body slots by a 32-byte stride. [source:raw]
    // CALL: Call AABBCollisionBodyInitializer(v6) to initialize each 32-byte AABB body slot. [callee:0x00448E90, source:raw]
    // ASSIGNMENT: Store the allocated body array pointer v5 at this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Return the loop/guard result value. [source:raw]

    // Conservative worker pseudocode:
    //   int *sub_4492D0(_DWORD *this, int a2) {
    //     int *result = (int *)PhysicsBufferFree();
    //     if (a2 > 0) {
    //       this[1] = a2;
    //       result = (int *)OperatorNewNhMallocWrapper(32 * a2 + 4);
    //       if (result) {
    //         _DWORD *v5 = result + 1;
    //         *result = a2;
    //         result = (int *)(a2 - 1);
    //         int v6 = (int)v5;
    //         if (a2 - 1 >= 0) {
    //           do { result = (int *)AABBCollisionBodyInitializer(v6); v6 += 32; --a2; } while (a2);
    //         }
    //         this[2] = v5;
    //       } else {
    //         this[2] = 0;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner object of this+0x4 and this+0x8 is unidentified; only the collision-subsystem context is known.
    // UNRESOLVED: Meaning of the returned pointer value (last AABBCollisionBodyInitializer result or a2-1) for the caller is unknown.
}
