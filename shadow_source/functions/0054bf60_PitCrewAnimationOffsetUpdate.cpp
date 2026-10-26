// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054BF60
// Canonical corpus name: PitCrewAnimationOffsetUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitCrewAnimationOffsetUpdate_0054bf60.c

void UnknownObject::PitCrewAnimationOffsetUpdate()
{
    // Walks a linked list of animation elements (head at this+0x204, next pointer at node+0x10) and, for each entry matching type id a2, adds an (a4, a5) offset to the X/Y position components of every vertex in the entry's vertex array, using a 48-byte stride. The vertex component base is a3-selectable: a3==0 updates components at data+32/+36, a3==1 updates at data+40/+44. Each updated entry has dirty bit 0x800 set at its flags field (v7[12]). Part of the pit crew animation update path invoked during camera/viewport render setup.
    // LOOP: Outer traversal of the animation element linked list: start at the head this[129] (this+0x204) and follow the next pointer i[4] until null. [field:this:0x00000204, source:raw]
    // GUARD: Per-node guard: the node's entry count i[70] must be > 0 before any entry records are walked (packet guard 0, this+0x32C). [guard:0, field:this:0x0000032C, source:raw]
    // LOOP: Inner do-while over the node's entry records: advance v7 by 16 dwords per iteration, comparing each record's type id *(v7-1) against a2 to find matches. [field:this:0x00000330, source:raw]
    // GUARD: Per-entry guard: the matched entry's vertex count *v7 must be > 0 before the vertex loop runs (packet guard 1, this+0x338). [guard:1, field:this:0x00000338, source:raw]
    // LOOP: Vertex update loop (a3==0 branch): iterate over the vertex array pointed to by the entry (this+0x33C) with a 48-byte stride, adding a4 to the X component (base data+32) and a5 to the Y component (base data+36). [field:this:0x0000033C, source:raw]
    // LOOP: Vertex update loop (a3==1 branch): same 48-byte-stride iteration but the X component base is data+40 and the Y component base is data+44. [field:this:0x0000033C, source:raw]
    // ASSIGNMENT: Mark the entry dirty: set bit 0x800 in v7[12] (entry+0x30 flags; packet this+0x368) after its vertex offsets are updated. [field:this:0x00000368, source:raw]
    // CALL: Invoked by CameraViewportRenderSetup (0x004FBD70) as part of pit crew animation offset refresh during viewport render setup. [caller:0x004FBD70, source:raw]

    // Conservative worker pseudocode:
    //   for (node = this[129]; node; node = node[4]) {
    //     if (node[70] <= 0) continue;
    //     entry = (node[71] + 8);
    //     for (k = 0; k < node[70]; ++k, entry += 16) {
    //       if (entry[-1] != a2) continue;
    //       data = entry[1];
    //       if (a3 == 1) {
    //         for (n = 0; n < entry[0]; ++n)
    //           { data[40 + 48*n] += a4; data[44 + 48*n] += a5; }
    //       } else if (a3 == 0) {
    //         for (n = 0; n < entry[0]; ++n)
    //           { data[32 + 48*n] += a4; data[36 + 48*n] += a5; }
    //       }
    //       entry[12] |= 0x800;
    //     }
    //   }
    // UNRESOLVED: The packet field table expresses the node/entry accesses as this-relative offsets (this+0x32C entry count, this+0x330 type id, this+0x338 vertex count, this+0x33C vertex data pointer, this+0x368 dirty flag) whereas the raw source accesses them relative to the node pointer i and the entry pointer v7; the exact relationship between `i`/`v7` and the `this` base is not proven here.
    // UNRESOLVED: The read of this+0x224 reported by the packet is not visible as a distinct access in the raw decompiled source.
    // UNRESOLVED: The vertex struct layout (48-byte stride, X/Y components at the a3-selected bases) is inferred from the update pattern, not from a named type.
}
