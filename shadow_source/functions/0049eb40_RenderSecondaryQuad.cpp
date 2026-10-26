// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049EB40
// Canonical corpus name: FloatComputation_eb40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatComputation_eb40_0049eb40.c

void UnknownObject::RenderSecondaryQuad()
{
    // Renders a second 2D textured quad. Guards on the resource node pointer at this+0xC being non-null, releases the previous single field via SingleFieldFreeWrapper, re-initializes the sub-object at this+4 via ObjectConstructorWithAllocationAndSubInit, and when that constructor reports failure (returns 0) stores the four rectangle parameters into this+0x3C/+0x40/+0x44/+0x48 and emits four vertices through sub_553650 with UV and color arguments.
    // GUARD: Read the resource node pointer at this+0xC; if it is null the whole body is skipped and the read value is returned directly [field:this:0x0000000C, source:raw]
    // CALL: SingleFieldFreeWrapper(this) releases the previous single field resource before re-rendering [callee:0x0049ECA0, source:raw]
    // CALL: ObjectConstructorWithAllocationAndSubInit(this+4, a6, *(this+12), 32, 192) re-initializes the sub-object; a non-zero (success) return skips the quad render path and returns early [callee:0x00553980, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the quad parameters into the object: this+0x3C = a2 (X), this+0x40 = a3 (Y), this+0x44 = a4 (Width), this+0x48 = a5 (Height) [field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, source:raw]
    // CALCULATION: Derive the second/third vertex coordinates: v12 = a5 + a3 and v13 = a4 + a2, combining the stored height and width into the remaining quad corners [source:raw]
    // CALL: sub_553650 invoked four times, once per quad vertex, each with a vertex index (0..3), x/y position, RGB color and a -1 trailing argument; the four calls emit the quad corners [callee:0x00553650, source:raw]
    // RETURN: Returns the result of the fourth sub_553650 call (vertex 3) on the render path, the constructor result when it succeeds, or the null resource read on the early-exit path; invoked from sub_49CD80 (0049cd80) [callee:0x00553650, function:0x0049EB40, caller:0x0049CD80, source:raw]

    // Conservative worker pseudocode:
    //   resource = *(this + 0xC);
    //   if (resource == 0) return resource;
    //   SingleFieldFreeWrapper(this);
    //   if (ObjectConstructorWithAllocationAndSubInit(this + 4, a6, resource, 32, 192) == 0) {
    //     *(float*)(this + 0x3C) = a2;
    //     *(this + 0x40) = a3;
    //     *(this + 0x44) = a4;
    //     *(this + 0x48) = a5;
    //     sub_553650(0, a2, a3, 1.0, 0.0, 0.0, -1);
    //     sub_553650(1, a2, a5 + a3, 1.0, 0.0, 1.0, -1);
    //     sub_553650(2, a4 + a2, a5 + a3, 1.0, 1.0, 1.0, -1);
    //     return sub_553650(3, a4 + a2, a3, 1.0, 1.0, 0.0, -1);
    //   }
    //   return <constructor result>;
    // UNRESOLVED: The read-only global dword_8AFE64 (0x008AFE64) is flagged by packet facts but appears nowhere in the raw decompiled source; the skeleton fill labels it RaceTimeDelta [DERIVED], unverifiable from this packet
    // UNRESOLVED: The meaning of the literal constructor arguments 32 and 192, and the role of the trailing -1 passed to every sub_553650 call, are not documented in this function
}
