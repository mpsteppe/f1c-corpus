// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053FC30
// Canonical corpus name: sub_53FC30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53FC30_0053fc30.c

void UnknownObject::SurfacePairBlit()
{
    // Surface blit helper for a pair of surface descriptors. Each of a2/a3 selects a surface by flags at +6 words: flags 0x4/0x8 resolve an object through its vtable method at offset 60 (backed by +4/+5), while flags 0x1/0x2 use a direct pointer at +2/+3. After resolving both surfaces, calls SurfaceBlitOperation and stores its result in *this, returning -1 on any non-zero error. When the descriptor flags include 0xC the resolved surface is released through its vtable release method at offset 8. Returns 0 on success. Called by sub_5429B0 (005429B0).
    // ASSIGNMENT: Resolve the source surface from a2: when flags a2[6] & 0x4 and a2[4] is non-null, or a2[6] & 0x8 and a2[5] is non-null, invoke the vtable method at offset 60 on the resolved object to produce a4, store the result in *this, and return -1 when it is non-zero. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Else when a2[6] & 0x1 and a2[2] is non-null, use a4 = a2[2] directly as the source surface pointer. [source:raw]
    // ASSIGNMENT: Else when a2[6] & 0x2 and a2[3] is non-null, use a4 = a2[3]; otherwise return -1. [source:raw]
    // ASSIGNMENT: Resolve the destination surface from a3 identically: vtable method at offset 60 when flags a3[6] & 0x4/0x8 back a3[4]/a3[5] (result stored in *this, -1 on error), else a3[2], else a3[3]; no valid pointer returns -1, otherwise v15 holds the resolved destination. [field:this:0x00000000, source:raw]
    // CALL: SurfaceBlitOperation(v15, 0, 0, a4, 0, 0, 1, 0) blits the source surface onto the destination; store its result in *this and return -1 when non-zero. [callee:0x0050099C, field:this:0x00000000, source:raw]
    // GUARD: When a2[6] & 0xC, release the resolved source a4 through its vtable release method at offset 8. [source:raw]
    // GUARD: When a3[6] & 0xC, release the resolved destination v15 through its vtable release method at offset 8. [source:raw]
    // RETURN: Return 0 on successful blit after any required releases. [source:raw]
    // CALL: Invoked by sub_5429B0 (005429B0) to perform the paired surface blit. [caller:0x005429B0, source:raw]

    // Conservative worker pseudocode:
    //   if ((a2[6] & 0x4 && (obj = a2[4])) || (a2[6] & 0x8 && (obj = a2[5]))) {
    //     *this = obj->vtable[15](obj, a4, &a4);  /* vtable method at +60 * /
    //     if (*this) return -1;
    //   } else if (a2[6] & 0x1 && a2[2]) {
    //     a4 = a2[2];
    //   } else {
    //     if (!(a2[6] & 0x2) || !a2[3]) return -1;
    //     a4 = a2[3];
    //   }
    //   /* same resolution for a3 into v15 * /
    //   *this = SurfaceBlitOperation(v15, 0, 0, a4, 0, 0, 1, 0);
    //   if (*this) return -1;
    //   if (a2[6] & 0xC) a4->vtable[2](a4);  /* vtable release at +8 * /
    //   if (a3[6] & 0xC) v15->vtable[2](v15);
    //   return 0;
    // UNRESOLVED: The exact semantics of the flag bits 0x1/0x2 (direct pointer) versus 0x4/0x8 (object resolved through vtable+60) are inferred from the branch structure, not stated in the packet.
    // UNRESOLVED: The contract of the vtable method at offset 60 (surface pointer retrieval vs error code) is inferred from how its result is tested and stored.
    // UNRESOLVED: The argument semantics of SurfaceBlitOperation (0050099C) are not established in this packet.
}
