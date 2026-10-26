// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C470
// Canonical corpus name: CollisionTreeNodeCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionTreeNodeCleanup_0044c470.c

void UnknownObject::CollisionTreeNodeCleanup()
{
    // Collision-tree node cleanup. Frees two owned allocations held at this+0x0 and this+0x4 (the second with a 4-byte header adjustment), zeroes the eight scalar fields of the node, clears the trailing 0x1000-byte block at this+0x28 via memset, and returns 0.
    // GUARD: If the pointer stored at this+0x0 is non-zero, free it via FreeWrapper_7bcf and clear this+0x0 [field:this:0x00000000, callee:0x00587BCF, source:raw]
    // GUARD: If the pointer value at this+0x4 is non-zero, free the address 4 bytes before it (v2 - 4) via FreeWrapper_7bcf and clear this+0x4 [field:this:0x00000004, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the six scalar fields this+0x8, this+0xC, this+0x10, this+0x14, this+0x18 and this+0x1C [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: memset the trailing block at this+0x28 (this+40) to zero over 0x1000 bytes [source:raw]
    // RETURN: Return 0; the packet's template prelabel classes this as ctor_init but the raw body performs frees and zeroing (cleanup/destructor shape). Recorded callers: SceneTrackFileLoader (0044c0e0) and SpecialFX_Post (004cfed0) [function:0x0044C470, caller:0x0044C0E0, caller:0x004CFED0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[0x0/4]) {
    //     FreeWrapper_7bcf(this[0x0/4]);
    //     this[0x0/4] = 0;
    //   }
    //   v2 = this[0x4/4];
    //   if (v2) {
    //     FreeWrapper_7bcf(v2 - 4);
    //     this[0x4/4] = 0;
    //   }
    //   this[0x8/4] = this[0xC/4] = this[0x10/4] = this[0x14/4] = 0;
    //   this[0x18/4] = this[0x1C/4] = 0;
    //   memset(this + 0x28, 0, 0x1000);
    //   return 0;
    // UNRESOLVED: The free of v2 - 4 implies the allocation at this+0x4 carries a 4-byte header before the stored pointer; that allocation layout is not visible in this packet
    // UNRESOLVED: The trailing 0x1000-byte region at this+0x28 is a fixed-size block whose element type and purpose are unknown from this packet
    // UNRESOLVED: The template prelabel ctor_init conflicts with the observed free/zero cleanup shape; the caller-scoped lifecycle is not resolved here
}
