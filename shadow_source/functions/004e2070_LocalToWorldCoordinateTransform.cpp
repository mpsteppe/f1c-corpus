// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2070
// Canonical corpus name: LocalToWorldCoordinateTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocalToWorldCoordinateTransform_004e2070.c

void UnknownObject::LocalToWorldCoordinateTransform()
{
    // 3D local-to-world coordinate transform on a camera-like object. Builds a combined offset vector by adding the camera-relative offset (this[573..575]) to an additional position offset (this[576..578]), multiplies it by a 3x3 rotation matrix (this[8..16], byte offset 0x20-0x40) into the output vector a2, adds the base position (this[2..4], byte offset 0x8-0x10), copies the 3x3 matrix block into a local buffer, then calls sub_567120(this+579, a3) whose return value is passed through. Invoked by CameraModeViewportUpdate (00409A00).
    // CALCULATION: Computes the combined offset vector: v4 = this[573]+this[576], v5 = this[574]+this[577], v6 = this[575]+this[578] (camera-relative offset 0x8F4/0x8F8/0x8FC summed with additional offset 0x900/0x904/0x908) [field:this:0x000008F4, field:this:0x000008F8, field:this:0x000008FC, field:this:0x00000900, field:this:0x00000904, field:this:0x00000908, source:raw]
    // CALCULATION: Applies the 3x3 rotation matrix: output a2[0..2] = each row of this[8..16] (offsets 0x20-0x40) dotted with the combined offset vector (v4, v5, v6) [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, source:raw]
    // CALCULATION: Translates the rotated vector by the base position: a2[0] += this[2], a2[1] += this[3], a2[2] += this[4] (offsets 0x8/0xC/0x10) [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALCULATION: Copies the 3x3 matrix block from this+8 (36 bytes, offsets 0x20-0x40) into a local 36-byte stack buffer v8; the buffer is never read afterward [field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, source:raw]
    // CALL: Calls sub_567120 with the pointer to this[579] (the combined offset vector) and forwards a3; result is returned to the caller [callee:0x00567120, source:raw]
    // RETURN: Returns the int result produced by sub_567120 [source:raw]
    // CALL: Invoked by CameraModeViewportUpdate (00409A00), indicating a camera-viewport path [caller:0x00409A00, source:raw]

    // Conservative worker pseudocode:
    //   ox = this[573] + this[576];  // combined offset X
    //   oy = this[574] + this[577];
    //   oz = this[575] + this[578];
    //   a2[0] = oz*this[16] + oy*this[15] + ox*this[14];
    //   a2[1] = oz*this[13] + oy*this[12] + ox*this[11];
    //   a2[2] = oz*this[10] + oy*this[9] + ox*this[8];
    //   a2[0] += this[2]; a2[1] += this[3]; a2[2] += this[4];
    //   copy 36 bytes from this+8 into local buffer;
    //   return sub_567120(this + 579, a3);
    // UNRESOLVED: The 36-byte matrix copy into v8 has no observable effect; possibly leftover from an original source variant
    // UNRESOLVED: Semantics of a3 and of sub_567120's second argument are unknown
    // UNRESOLVED: The relationship between the camera-relative offset (this[573..575]) and the additional offset (this[576..578]) is not established by this function alone
}
