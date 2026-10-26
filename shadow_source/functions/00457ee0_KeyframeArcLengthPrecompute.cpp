// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457EE0
// Canonical corpus name: sub_457EE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_457EE0_00457ee0.c

void UnknownObject::KeyframeArcLengthPrecompute()
{
    // Pre-computes cumulative arc length over a 3D keyframe array. The array base pointer is read from this+0x0 and the keyframe count from this+0x4; keyframes use a 28-byte stride (7 floats: 3D position at elements 0..2, accumulated distance at element 6). The first keyframe has its element at +0x18 (accumulated distance) set to 0; each later keyframe writes element +0x18 as the 3D Euclidean distance from the previous keyframe added to the previous keyframe's accumulated value. After the loop this+0x8 is assigned from the array at byte offset 28*i-60 (i being the loop-exit count), and the keyframe array pointer is returned. Called by sub_457F90 (00457f90) and BufferAllocCopy (004582e0).
    // LOOP: Walks the keyframe array pointed to by this+0x0, once per keyframe for the count in this+0x4 [field:this:0x00000000, field:this:0x00000004, source:raw]
    // GUARD: First keyframe (index 0) takes the separate zero-initialization branch because it has no predecessor; later keyframes take the distance-accumulation branch [field:obj:0x00000018, source:raw]
    // ASSIGNMENT: First keyframe's element at +0x18 (6th float of the 28-byte stride) is set to 0 [field:obj:0x00000018, source:raw]
    // CALCULATION: For each later keyframe, computes the 3D deltas against the previous keyframe: differences of the x/y/z floats at the current element minus the preceding 28-byte stride [source:raw]
    // CALCULATION: Writes the keyframe element at +0x18 as the 3D Euclidean distance (square root of the summed squared deltas) added to the previous keyframe's accumulated value at the same relative slot [field:obj:0x00000018, source:raw]
    // ASSIGNMENT: After the loop, assigns this+0x8 from the keyframe array at byte offset 28*i-60 where i is the loop-exit count; the skeleton fill reads this as the total accumulated path length [field:this:0x00000008, source:raw]
    // RETURN: Returns the keyframe array pointer read from this+0x0 [field:this:0x00000000, source:raw]
    // CALL: Invoked by sub_457F90 (00457f90) and BufferAllocCopy (004582e0) to pre-compute cumulative keyframe distances [caller:0x00457F90, caller:0x004582E0, source:raw]

    // Conservative worker pseudocode:
    //   base = *(_DWORD*)this;            // keyframe array, 28-byte stride
    //   count = *((_DWORD*)this + 1);     // keyframe count
    //   for (i = 0; i < count; ++i) {
    //     if (i == 0) {
    //       *(base + 24) = 0;             // first keyframe accumulated distance = 0
    //     } else {
    //       k = base + 28*i;
    //       dx = k[0] - (k-7)[0];
    //       dy = k[1] - (k-6)[1];
    //       dz = k[2] - (k-5)[2];
    //       k[6] = sqrt(dx*dx + dy*dy + dz*dz) + (k-1)[6];
    //     }
    //   }
    //   this[2] = *(float*)(base + 28*i - 60);   // i is the loop-exit count
    //   return base;
    // UNRESOLVED: The final read at byte offset 28*i-60 (i = loop-exit count) lands on a keyframe element whose exact meaning is ambiguous: it is not the last keyframe's +0x18 slot (which would sit at 28*i-4); the skeleton fill claims it stores the total path length, unverifiable from the raw expression
    // UNRESOLVED: The keyframe element layout beyond the 7-float stride (3D position + accumulated distance) is not defined by this packet; the x/y/z and accumulated slots are inferred only from the raw arithmetic
}
