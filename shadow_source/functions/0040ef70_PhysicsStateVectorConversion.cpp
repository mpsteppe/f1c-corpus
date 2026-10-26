// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040EF70
// Canonical corpus name: PhysicsStateVectorConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsStateVectorConversion_0040ef70.c

void UnknownObject::PhysicsStateVectorConversion()
{
    // Converts a 13-float physics state vector a2 into owner and sub-object state: dispatches on mode this+0x1C (this[7], cases 0-5), writes an offset-scaled position into the sub-object at this+0x20 (this[8], floats at +32/+36, with +100.0 offset), copies position components into this+0xC/0x10/0x14, forwards three position dwords and three velocity floats to sub_54B4D0, copies vector groups into the sub-object output buffer (this+0x20 + 212 bytes), transforms vectors via F_3x3RotationTensorMatrixTransform and Copy6DwordsToStructCall, and returns the result of ShortComputation_f0d0(this).
    // STATE_TRANSITION: Mode dispatch on this+0x1C (this[7]) via jump table 0x0040F0B0; cases 0,2,4 and 1,3,5 follow the same write path; default falls through with a2 unrebound. [field:this:0x0000001C, global:0x0040F0B0, source:raw]
    // ASSIGNMENT: Write to the sub-object pointed at by this+0x20 (this[8]): float at +36 = a2[0]; float at +32 = a2[0] + 100.0. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Rebind the destination pointer a2 to the sub-object buffer offset by 212 bytes (this+0x20 + 212). [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Copy position components into this+0xC/0x10/0x14 from input vector entries v2[1]/v2[2]/v2[3]. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: Call sub_54B4D0 with the three position dwords and three velocity floats v2[4..6]. [callee:0x0054B4D0, source:raw]
    // ASSIGNMENT: Stage v2[1..3] as doubles and copy 24 bytes into the output buffer at a2+1 (float stride). [source:raw]
    // CALL: Call F_3x3RotationTensorMatrixTransform on the vector v2[4..6]. [callee:0x005691D0, source:raw]
    // ASSIGNMENT: Stage v2[7..9] as doubles and copy 24 bytes into the output buffer at a2+25 (float stride). [source:raw]
    // CALL: Call Copy6DwordsToStructCall on the vector v2[10..12]. [callee:0x00569280, source:raw]
    // RETURN: Return the result of ShortComputation_f0d0(this). [callee:0x0040F0D0, source:raw]

    // Conservative worker pseudocode:
    //   // this[7] = mode selector; this[8] = sub-object pointer
    //   switch (this[7]) {
    //     case 0: case 2: case 4:
    //     case 1: case 3: case 5:
    //       *((float*)this[8] + 9) = a2[0];             // sub-object +36
    //       *((float*)this[8] + 8) = a2[0] + 100.0f;    // sub-object +32
    //       a2 = (float*)(this[8] + 212);
    //     default: break;
    //   }
    //   this[3] = v2[1];  this[4] = v2[2];  this[5] = v2[3];
    //   sub_54B4D0(v2[1], v2[2], v2[3], v2[4], v2[5], v2[6]);
    //   copy 24 bytes: a2+1  <- v2[1..3] as doubles;
    //   F_3x3RotationTensorMatrixTransform(v2[4..6]);
    //   copy 24 bytes: a2+25 <- v2[7..9] as doubles;
    //   Copy6DwordsToStructCall(v2[10..12]);
    //   return ShortComputation_f0d0(this);
    // UNRESOLVED: Fields this+0x40, this+0x44 and this+0xF4 are listed as accessed by the packet but do not appear as explicit reads in the visible function body; they are most plausibly consumed by the conversion-pipeline callees (e.g. ShortComputation_f0d0), which is not confirmed here.
    // UNRESOLVED: Global flt_59E6F8 (0x0059E6F8) is listed as read but is not visible in the decompiled body; its role (SignedShortScale per existing analysis) is DERIVED and unconfirmed.
    // UNRESOLVED: The sub-object layout (offset 212 region, floats at +32/+36) is not evidenced beyond this function's own writes; the destination buffer element type is unresolved.
}
