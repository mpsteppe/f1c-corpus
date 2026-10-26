// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00459830
// Canonical corpus name: FloatDoubleCoordinateTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatDoubleCoordinateTransform_00459830.c

void UnknownObject::FloatDoubleCoordinateTransform()
{
    // Converts float-precision position (this+0x4/+0x8/+0xC) and rotation (this+0x10/+0x14/+0x18) into a double-precision representation. Stores position as three doubles at this+0xD8 (0x18 bytes) and the computed 3x3 rotation tensor matrix at this+0x138 (0x18 bytes), then copies the float position as three dwords into this+0xC0/+0xC4/+0xC8 and into the caller-provided output a2. When the trigger flag at this+0xD0 is non-zero, an external processing call sub_54B4D0 and a BufferEntryClear(0x8000000) run before the conversion. Called from StateDependentUpdateDispatch (0x0040F130).
    // GUARD: When the trigger flag at this+0xD0 (this+208) is non-zero, run the external-processing path before conversion. [field:this:0x000000D0, source:raw]
    // CALL: Call sub_54B4D0 with the float position (this+0x4/+0x8/+0xC) and float rotation (this+0x10/+0x14/+0x18) as six scalar arguments. [callee:0x0054B4D0, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // CALL: Call BufferEntryClear(0x8000000) to clear the buffer entry identified by 0x8000000. [callee:0x0054FAE0, source:raw]
    // ASSIGNMENT: Read the float position components at this+0x4/+0x8/+0xC and promote them into the local double[3] v10. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the double-precision position (0x18 bytes from v10) at this+0xD8 (this+216). [source:raw]
    // ASSIGNMENT: Read the float rotation components at this+0x10/+0x14/+0x18 and promote them into the local double[3] v11. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // CALCULATION: Zero-fill the local 24-byte buffer v9 (three dwords of 8 bytes each). [source:raw]
    // CALL: Call F_3x3RotationTensorMatrixTransform(v11) to compute the 3x3 rotation tensor matrix into v9 from the double rotation components. [callee:0x005691D0, source:raw]
    // ASSIGNMENT: Copy the computed 3x3 rotation tensor (0x18 bytes from v9) into this+0x138 (this+312). [source:raw]
    // CALL: Call Copy6DwordsToStructCall(v9) to propagate the six computed dwords into an external struct. [callee:0x00569280, source:raw]
    // ASSIGNMENT: Copy the float position as three dwords into this+0xC0 (this+192), this+0xC4 and this+0xC8 (this+192 dword slot 1 and 2). [field:this:0x000000C0, field:this:0x000000C4, field:this:0x000000C8, source:raw]
    // ASSIGNMENT: Copy the float position as three dwords into the caller-provided output a2 (a2[0..2]). [source:raw]
    // RETURN: Return the output pointer a2. [source:raw]
    // CALL: Invoked by StateDependentUpdateDispatch (0x0040F130). [caller:0x0040F130, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* FloatDoubleCoordinateTransform(int this, DWORD* a2) {
    //     if (*(DWORD*)(this + 0xD0)) {
    //       sub_54B4D0(*(this+0x4), *(this+0x8), *(this+0xC),
    //                   *(float*)(this+0x10), *(float*)(this+0x14), *(float*)(this+0x18));
    //       BufferEntryClear(0x8000000);
    //     }
    //     double pos[3] = { *(float*)(this+0x4), *(float*)(this+0x8), *(float*)(this+0xC) };
    //     memcpy(this + 0xD8, pos, 0x18);
    //     double rot[3] = { *(float*)(this+0x10), *(float*)(this+0x14), *(float*)(this+0x18) };
    //     memset(v9, 0, 0x18);
    //     F_3x3RotationTensorMatrixTransform(rot);
    //     memcpy(this + 0x138, v9, 0x18);
    //     Copy6DwordsToStructCall(v9);
    //     memcpy(this + 0xC0, this + 0x4, 0xC);
    //     a2[0] = *(DWORD*)(this+0x4); a2[1] = *(DWORD*)(this+0x8); a2[2] = *(DWORD*)(this+0xC);
    //     return a2;
    //   }
    // UNRESOLVED: The semantics of the trigger flag at this+0xD0 and the buffer identifier 0x8000000 are not established by the packet alone.
    // UNRESOLVED: The destination struct written by Copy6DwordsToStructCall(v9) is not evidenced in this packet.
    // UNRESOLVED: The object type behind `this` and the meaning of the double storage at this+0xD8 and this+0x138 are not established by the packet alone.
}
