// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569990
// Canonical corpus name: F_3DVectorTransformWithBufferWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DVectorTransformWithBufferWrite_00569990.c

void UnknownObject::WriteRelativeTransformedPosition()
{
    // Transforms a world-space position a2 into the object-local frame using the object position and rotation matrix, then appends an 88-byte entry (transformed vector plus four metadata fields) to a ring buffer, post-incrementing the write index. Vehicle physics constraint point batching.
    // ASSIGNMENT: Compute append target as buffer base at this+0x240 plus 88 times the post-incremented write index at this+0x23C. [field:this:0x0000023C, field:this:0x00000240, source:raw]
    // CALCULATION: delta.x = a2[0] minus object position X at this+0x4. [field:this:0x00000004, source:raw]
    // CALCULATION: delta.y = a2[1] minus object position Y at this+0xC. [field:this:0x0000000C, source:raw]
    // CALCULATION: delta.z = a2[2] minus object position Z at this+0x14. [field:this:0x00000014, source:raw]
    // CALCULATION: Local-space X = delta dotted with rotation matrix row 0 (this+0x1C, this+0x34, this+0x4C); stored as first double of the entry. [field:this:0x0000001C, field:this:0x00000034, field:this:0x0000004C, source:raw]
    // CALCULATION: Local-space Y = delta dotted with rotation matrix row 1 (this+0x24, this+0x3C, this+0x54); stored at entry offset 8. [field:this:0x00000024, field:this:0x0000003C, field:this:0x00000054, source:raw]
    // CALCULATION: Local-space Z = delta dotted with rotation matrix row 2 (this+0x2C, this+0x44, this+0x5C); stored at entry offset 16. [field:this:0x0000002C, field:this:0x00000044, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Store metadata dword a3 at entry offset 48 and metadata byte a4 at entry offset 52. [source:raw]
    // ASSIGNMENT: Store additional metadata dword a5 at entry offset 56 and metadata dword a6 at entry offset 60. [source:raw]
    // RETURN: Return the pointer to the appended entry. [source:raw]

    // Conservative worker pseudocode:
    //   entry = this.buffer_base(0x240) + 88 * this.write_index(0x23C)++
    //   delta = a2 - this.position(0x4, 0xC, 0x14)
    //   entry[0..16] = delta dot rotation_matrix_rows(0x1C..0x5C)
    //   entry.meta32(48) = a3; entry.meta8(52) = a4
    //   entry.meta32(56) = a5; entry.meta32(60) = a6
    //   return entry
    // UNRESOLVED: Semantic roles of the four metadata words (a3, a4, a5, a6) are not established.
    // UNRESOLVED: Owner identity is UNKNOWN; shares its caller with the 56-byte-stride sibling append function.
}
