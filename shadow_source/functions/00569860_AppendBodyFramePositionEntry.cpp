// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569860
// Canonical corpus name: F_3DPositionDeltaToBodyFrameVectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DPositionDeltaToBodyFrameVectorTransform_00569860.c

void UnknownObject::AppendBodyFramePositionEntry()
{
    // Appends a 56-byte entry holding a body-frame transformed world position delta plus metadata to a per-object ring buffer, post-incrementing the element count. Called from the vehicle physics joint system loader.
    // ASSIGNMENT: Compute append target as buffer base at this+0x230 plus 56 times the post-incremented element count at this+0x22C. [field:this:0x0000022C, field:this:0x00000230, source:raw]
    // CALCULATION: delta.x = a2[0] minus vehicle world position X at this+0x4. [field:this:0x00000004, source:raw]
    // CALCULATION: delta.y = a2[1] minus vehicle world position Y at this+0xC. [field:this:0x0000000C, source:raw]
    // CALCULATION: delta.z = a2[2] minus vehicle world position Z at this+0x14. [field:this:0x00000014, source:raw]
    // CALCULATION: Body-frame X = delta dotted with rotation matrix row 0 (this+0x1C, this+0x34, this+0x4C); stored as first double of the entry. [field:this:0x0000001C, field:this:0x00000034, field:this:0x0000004C, source:raw]
    // CALCULATION: Body-frame Y = delta dotted with rotation matrix row 1 (this+0x24, this+0x3C, this+0x54); stored at entry offset 8. [field:this:0x00000024, field:this:0x0000003C, field:this:0x00000054, source:raw]
    // CALCULATION: Body-frame Z = delta dotted with rotation matrix row 2 (this+0x2C, this+0x44, this+0x5C); stored at entry offset 16. [field:this:0x0000002C, field:this:0x00000044, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Store metadata dword a3 at entry offset 48 and metadata byte a4 at entry offset 52. [source:raw]
    // RETURN: Return the pointer to the appended entry. [source:raw]

    // Conservative worker pseudocode:
    //   entry = this.buffer_base(0x230) + 56 * this.count(0x22C)++
    //   delta = a2 - this.world_position(0x4, 0xC, 0x14)
    //   entry[0..16] = delta dot rotation_matrix_rows(0x1C..0x5C)
    //   entry.meta32(48) = a3; entry.meta8(52) = a4
    //   return entry
    // UNRESOLVED: Semantic meaning of the stored metadata dword a3 and byte a4 is not established.
    // UNRESOLVED: Caller VehiclePhysicsJointSystemLoader passes this as a physics-context object; owner identity is UNKNOWN.
}
