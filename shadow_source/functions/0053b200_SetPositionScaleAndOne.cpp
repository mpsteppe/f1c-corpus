// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B200
// Canonical corpus name: MultiFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldSetter_0053b200.c

void UnknownObject::SetPositionScaleAndOne()
{
    // Per-frame setter (thiscall) that copies three inputs into primary fields at offsets 0x4, 0x8, 0xC, mirrors them into duplicate reference fields at 0x58, 0x5C, 0x60, sets the field at 0x64 to 1065353216 (1.0f), and returns the middle input (this[2], originally a3) as the result. Interpreted as position/scale component initialization for a 3D transformation object; the 1.0f write acts as an identity scale or w-component default.
    // ASSIGNMENT: Store a2 into this[1] (offset 0x4). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store a3 into this[2] (offset 0x8). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store a4 into this[3] (offset 0xC). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Mirror a2 into this[22] (offset 0x58). [field:this:0x00000058, source:raw]
    // ASSIGNMENT: Read back result = this[2], then store it into this[23] (offset 0x5C). [field:this:0x00000008, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Mirror this[3] into this[24] (offset 0x60). [field:this:0x00000060, source:raw]
    // ASSIGNMENT: Initialize this[25] (offset 0x64) to the literal 1065353216, the bit pattern of 1.0f. [field:this:0x00000064, source:raw]
    // RETURN: Return result, which equals a3 as stored in this[2]. [field:this:0x00000008, source:raw]
    // CALL: Called by sub_54B570 (0054b570), VertexBufferTransform (0054c6c0), TextureLayerFlagSet (00558c60) and sub_558E70 (00558e70) to set transformation fields. [caller:0x0054B570, caller:0x0054C6C0, caller:0x00558C60, caller:0x00558E70, source:raw]

    // Conservative worker pseudocode:
    //   this[1] = a2; this[2] = a3; this[3] = a4;
    //   this[22] = a2;
    //   result = this[2]; this[23] = result;
    //   this[24] = this[3];
    //   this[25] = 1065353216;
    //   return result;
    // UNRESOLVED: The concrete meaning of the mirrored pair (offsets 0x4/0x58, 0x8/0x5C, 0xC/0x60) is not established by this function alone; interpretation as position plus a duplicate reference copy is derived from the caller context.
    // UNRESOLVED: Whether the 1.0f literal at 0x64 is a scale or a homogeneous w component cannot be decided from this packet.
}
