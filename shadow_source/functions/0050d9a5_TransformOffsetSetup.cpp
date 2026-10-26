// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050D9A5
// Canonical corpus name: TransformOffsetSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TransformOffsetSetup_0050d9a5.c

void UnknownObject::TransformOffsetSetup()
{
    // Builds a 4x4 affine matrix at a1 (16 floats): zeros the off-diagonal and translation-row entries, sets the scale on the diagonal (a1[0], a1[5], a1[10]) to a2 and the homogeneous element a1[15] to 1.0. When the flag a4 is set it invokes an indirect transform thunk; if an offset vector a3 is supplied it subtracts the offset before the transform and adds it back after, otherwise the transform thunk is still called. Finally, if a5 is supplied, its three components are added to the translation row (a1[12], a1[13], a1[14]). Returns the matrix pointer.
    // CALCULATION: Zero the off-diagonal and translation-row entries: a1[1], a1[2], a1[3], a1[4], a1[6], a1[7], a1[8], a1[9], a1[11], a1[12], a1[13], a1[14] = 0.0 [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // ASSIGNMENT: Set the diagonal scale entries: *a1 (offset +0x0) = a2, a1[5] (offset +0x14) = a2, a1[10] (offset +0x28) = a2 [field:this:0x00000000, field:this:0x00000014, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Set the homogeneous element a1[15] (offset +0x3C) = 1.0 [field:this:0x0000003C, source:raw]
    // GUARD: Guard on flag a4: when nonzero the transform thunk path runs [source:raw]
    // CALL: Call ThunkToIndirectCallViaDAT005d7860 (0050D857) inside the a4 branch [callee:0x0050D857, source:raw]
    // GUARD: Guard on a3 being non-null inside the a4 branch [source:raw]
    // CALCULATION: Subtract the offset vector from the translation row: a1[12] (offset +0x30) -= *a3; a1[13] (offset +0x34) -= a3[1]; a1[14] (offset +0x38) -= a3[2] [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // CALL: Call ThunkToFUN0050cba3 (0050CBB0) after the offset is subtracted (a3 non-null branch) [callee:0x0050CBB0, source:raw]
    // CALCULATION: Add the offset vector back to the translation row: a1[12] (offset +0x30) = *a3 + a1[12]; a1[13] (offset +0x34) = a1[13] + a3[1]; a1[14] (offset +0x38) = a3[2] + a1[14] [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // CALL: Call ThunkToFUN0050cba3 (0050CBB0) in the a3 null branch, with no offset applied [callee:0x0050CBB0, source:raw]
    // GUARD: Guard on a5 being non-null: when set, its components are added to the translation row [source:raw]
    // CALCULATION: Add the a5 vector to the translation row: a1[12] (offset +0x30) = *a5 + a1[12]; a1[13] (offset +0x34) = a5[1] + a1[13]; a1[14] (offset +0x38) = a5[2] + a1[14] [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, source:raw]
    // RETURN: Return the filled matrix pointer a1 [function:0x0050D9A5, source:raw]

    // Conservative worker pseudocode:
    //   a1[1]=0.0; a1[2]=0.0; a1[3]=0.0; a1[4]=0.0; a1[6]=0.0; a1[7]=0.0;
    //   a1[8]=0.0; a1[9]=0.0; a1[11]=0.0; a1[12]=0.0; a1[13]=0.0; a1[14]=0.0;
    //   a1[0]=a2; a1[5]=a2; a1[10]=a2; a1[15]=1.0;
    //   if (a4) {
    //     ThunkToIndirectCallViaDAT005d7860();
    //     if (a3) {
    //       a1[12]-=*a3; a1[13]-=a3[1]; a1[14]-=a3[2];
    //       ThunkToFUN0050cba3();
    //       a1[12]=*a3+a1[12]; a1[13]=a1[13]+a3[1]; a1[14]=a3[2]+a1[14];
    //     } else {
    //       ThunkToFUN0050cba3();
    //     }
    //   }
    //   if (a5) {
    //     a1[12]=*a5+a1[12]; a1[13]=a5[1]+a1[13]; a1[14]=a5[2]+a1[14];
    //   }
    //   return a1;
    // UNRESOLVED: The concrete matrix/transform class owning this setup routine is unknown; a1 is accessed only as a float array
    // UNRESOLVED: The purpose of ThunkToIndirectCallViaDAT005d7860 and of the flag a4 (context setup before applying the transform) is not documented in this function
    // UNRESOLVED: What transform ThunkToFUN0050cba3 applies is not verifiable here; the subtract-before/add-back-after of a3 implies a centered or offset transform
}
