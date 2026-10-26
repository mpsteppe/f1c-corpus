// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00457B60
// Canonical corpus name: F_2DTransformStructCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DTransformStructCopy_00457b60.c

void UnknownObject::F_2DTransformStructCopy()
{
    // Field-by-field copy of a 2D transform/viewport struct. The source pointer arrives through the float-typed parameter a2. Copies an embedded string via a null-safe dereference plus a buffer-reallocating string copy, copies two 3-float vectors via F_3VectorCopyToStruct and VectorCopy, then fills the destination fields from a series of paired-field getter helpers (offsets 0x30..0x58), a few direct float/byte copies, a three-field getter result, a block of direct DWORD copies (0x70..0x84), and finally writes the square of the source value at byte offset 136 into destination byte offset 140.
    // CALL: Null-safe dereference of the string pointer field at source+4. [callee:0x00415C30, source:raw]
    // CALL: Copy the dereferenced string with buffer reallocation. [callee:0x00566650, source:raw]
    // CALL: Copy a 3-float vector from source+12 into the destination this struct. [callee:0x00456110, source:raw]
    // CALL: Copy a second 3-float vector from source+144 into the destination this struct. [callee:0x00456130, source:raw]
    // ASSIGNMENT: Copy DWORDs at destination offsets 0x90, 0x94 and 0x98 from the same source offsets. [field:this:0x00000090, field:this:0x00000094, field:this:0x00000098, source:raw]
    // CALL: Getter helper reads two float fields from the source struct at offsets 0x30 and 0x34. [callee:0x00456040, source:raw]
    // ASSIGNMENT: Store the getter result pair into destination offsets 0x30 and 0x34. [field:this:0x00000030, field:this:0x00000034]
    // CALL: Getter helper reads two float fields from the source struct (DualFieldGetter). [callee:0x00456060, source:raw]
    // ASSIGNMENT: Store the getter result pair into destination offsets 0x38 and 0x3C. [field:this:0x00000038, field:this:0x0000003C]
    // CALL: Getter helper reads two float fields from the source struct (ShortComputation_6080). [callee:0x00456080, source:raw]
    // ASSIGNMENT: Store the getter result pair into destination offsets 0x40 and 0x44. [field:this:0x00000040, field:this:0x00000044]
    // ASSIGNMENT: Direct copy of the single float at source+72 into destination offset 0x48. [field:this:0x00000048, source:raw]
    // CALL: Getter helper reads two float fields from the source struct (DualFieldGetter_60a0). [callee:0x004560A0, source:raw]
    // ASSIGNMENT: Store the getter result pair into destination offsets 0x4C and 0x50. [field:this:0x0000004C, field:this:0x00000050]
    // CALL: Getter helper reads two float viewport fields from the source struct (RectViewportDimensionGetter). [callee:0x004560C0, source:raw]
    // ASSIGNMENT: Store the getter result pair into destination offsets 0x54 and 0x58. [field:this:0x00000054, field:this:0x00000058]
    // ASSIGNMENT: Direct copy of the single float at source+92 into destination offset 0x5C. [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Direct copy of the single byte at source+96 into destination offset 0x60. [field:this:0x00000060, source:raw]
    // CALL: Getter helper reads three fields (two floats and one int) from the source struct (MultiFieldGetter). [callee:0x004560E0, source:raw]
    // ASSIGNMENT: Store the three-field getter result into destination offsets 0x64, 0x68 and 0x6C. [field:this:0x00000064, field:this:0x00000068, field:this:0x0000006C]
    // ASSIGNMENT: Copy DWORDs at destination offsets 0x70, 0x74, 0x78, 0x7C, 0x80 and 0x84 from the same source offsets. [field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084, source:raw]
    // ASSIGNMENT: Direct copy of the float at source+136 into destination offset 0x88. [field:this:0x00000088, source:raw]
    // CALCULATION: Compute destination offset 0x8C as the square of the source value read at byte offset 136. [field:this:0x0000008C, source:raw]
    // RETURN: Return the destination this pointer as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int F_2DTransformStructCopy(char *dst, char *src) {
    //     char *s = NullSafePointerDereference((char **)(src + 4));
    //     StringCopyWithBufferRealloc(s);
    //     F_3VectorCopyToStruct(dst, src + 12);
    //     VectorCopy(dst, src + 144);
    //     for (int o = 0x90; o <= 0x98; o += 4) *(int *)(dst + o) = *(int *)(src + o);
    //     float a, b; int c;
    //     DoubleFieldGetterAt0x300x34(src, &a, &b); *(float *)(dst + 0x30) = a; *(float *)(dst + 0x34) = b;
    //     DualFieldGetter(src, &a, &b);          *(float *)(dst + 0x38) = a; *(float *)(dst + 0x3C) = b;
    //     ShortComputation_6080(src, &a, &b);    *(float *)(dst + 0x40) = a; *(float *)(dst + 0x44) = b;
    //     *(float *)(dst + 0x48) = *(float *)(src + 0x48);
    //     DualFieldGetter_60a0(src, &a, &b);     *(float *)(dst + 0x4C) = a; *(float *)(dst + 0x50) = b;
    //     RectViewportDimensionGetter(src, &a, &b); *(float *)(dst + 0x54) = a; *(float *)(dst + 0x58) = b;
    //     *(float *)(dst + 0x5C) = *(float *)(src + 0x5C);
    //     *(char *)(dst + 0x60) = *(char *)(src + 0x60);
    //     MultiFieldGetter(src, &a, &b, &c); *(float *)(dst + 0x64) = a; *(float *)(dst + 0x68) = b; *(int *)(dst + 0x6C) = c;
    //     for (int o = 0x70; o <= 0x84; o += 4) *(int *)(dst + o) = *(int *)(src + o);
    //     *(float *)(dst + 0x88) = *(float *)(src + 0x88);
    //     float v = *(float *)(src + 0x88);
    //     *(float *)(dst + 0x8C) = v * v;
    //     return (int)dst;
    //   }
    // UNRESOLVED: The exact semantic roles of the many copied float/pair fields (position vs scale vs viewport/clip vs transform parameters) are not established; the getter helpers read them from fixed source offsets but their meaning is context-dependent.
    // UNRESOLVED: The string field at source+4 and the value at source+136 (which is squared into destination+140) have unknown meaning.
    // UNRESOLVED: The destination+0 vector is written twice (by F_3VectorCopyToStruct and VectorCopy); the second write is the effective value, which suggests a position followed by an override/direction vector, unproven here.
}
