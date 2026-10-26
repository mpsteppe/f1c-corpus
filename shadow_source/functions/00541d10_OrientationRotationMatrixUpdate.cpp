// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541D10
// Canonical corpus name: OrientationRotationMatrixUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OrientationRotationMatrixUpdate_00541d10.c

void UnknownObject::OrientationRotationMatrixUpdate()
{
    // Stores the orientation input vector (a2,a3,a4) into this+0x24/0x28/0x2C, then transforms it through a 3x3 rotation matrix stored at this+0x15C-0x184 using three dot products written to this+0x18C/0x190/0x194, writes the constant dword 1065353216 (1.0f) to this+0x198, and returns the raw bit pattern of a4 (LODWORD). Straight-line method with no branches, calls, or globals.
    // ASSIGNMENT: Store the input component a2 into the orientation vector field at this+0x24. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Store the input component a3 into the orientation vector field at this+0x28. [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Store the input component a4 into the orientation vector field at this+0x2C. [field:this:0x0000002C, source:raw]
    // CALCULATION: Compute result X: sum of a4 times matrix element at this+0x17C, a3 times this+0x16C, and a2 times this+0x15C; store the float result at this+0x18C. [field:this:0x0000015C, field:this:0x0000016C, field:this:0x0000017C, field:this:0x0000018C, source:raw]
    // CALCULATION: Compute result Y: sum of a4 times matrix element at this+0x180, a3 times this+0x170, and a2 times this+0x160; store the float result at this+0x190. [field:this:0x00000160, field:this:0x00000170, field:this:0x00000180, field:this:0x00000190, source:raw]
    // CALCULATION: Compute result Z: accumulate a4 times matrix element at this+0x184 plus a3 times this+0x174, then add a2 times this+0x164; store the float result at this+0x194. [field:this:0x00000164, field:this:0x00000174, field:this:0x00000184, field:this:0x00000194, source:raw]
    // ASSIGNMENT: Write the constant dword 1065353216 (the bit pattern of 1.0f) into this+0x198. [field:this:0x00000198, source:raw]
    // RETURN: Return the raw bit pattern (LODWORD) of a4 to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   int OrientationRotationMatrixUpdate(int this, float a2, float a3, float a4) {
    //     *(float*)(this + 0x24) = a2;
    //     *(float*)(this + 0x28) = a3;
    //     *(float*)(this + 0x2C) = a4;
    //     *(float*)(this + 0x18C) = a4**(float*)(this + 0x17C) + a3**(float*)(this + 0x16C) + a2**(float*)(this + 0x15C);
    //     *(float*)(this + 0x190) = a4**(float*)(this + 0x180) + a3**(float*)(this + 0x170) + a2**(float*)(this + 0x160);
    //     *(float*)(this + 0x194) = a4**(float*)(this + 0x184) + a3**(float*)(this + 0x174) + a2**(float*)(this + 0x164);
    //     *(int*)(this + 0x198) = 1065353216; // 1.0f
    //     return LODWORD(a4);
    //   }
    // UNRESOLVED: The object type is unknown (owner unproven); callers are UtilityFunction_1cd0, SceneRenderTransform, sub_55A060 and sub_560FE0.
    // UNRESOLVED: The row/column layout of the 3x3 matrix at this+0x15C-0x184 is inferred from existing analysis (column-major with rows 0x15C/0x16C/0x17C, 0x160/0x170/0x180, 0x164/0x174/0x184); not independently proven by this function.
    // UNRESOLVED: Writing 1.0f to this+0x198 is consistent with a 4x4 homogeneous element per existing analysis, but its exact role is not evidenced here.
    // UNRESOLVED: Why the function returns the raw bit pattern of a4 (rather than a success code or the computed vector) is unexplained by this function alone.
}
