// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056C3A0
// Canonical corpus name: sub_56C3A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56C3A0_0056c3a0.c

void UnknownObject::BuildOrthonormalBasisFromQuaternion()
{
    // Copies an input 4-DWORD plus double structure, normalizes the 3-vector formed by the doubles at offsets 0x0, 0x8 and 0x10, selects a perpendicular construction path based on a fabs(x) >= 0.7 threshold, builds two orthonormal basis vectors (the second as a cross product) and normalizes both outputs. Used for constraint-axis construction; called by BufferEntryAppendWithMatrixInit.
    // GUARD: If output pointer a2 is null, substitute a stack temporary [source:raw]
    // GUARD: If output basis-vector pointer a3 is null, substitute a stack temporary [source:raw]
    // GUARD: If output basis-vector pointer a4 is null, substitute a stack temporary [source:raw]
    // ASSIGNMENT: Copy four DWORDs from input a1 (offsets 0x0, 0x4, 0x8, 0xC) into a2 and the double at a1+0x10 into a2+0x10 [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // CALCULATION: Normalize the 3-vector read as doubles from a2 (components at offsets 0x0, 0x8, 0x10): divide each component by sqrt(x^2 + y^2 + z^2) [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // GUARD: Choose the perpendicular construction branch: if fabs(x) >= 0.7 (the dbl_59E830 threshold) build (-z, 0, x), else build (0, z, -y); the 1.0 and 0.0 selection constants match the read-only globals dbl_59E420 (1.0) and dbl_59E430 (0.0) listed by deterministic facts, though the raw body inlines them as literals [global:0x0059E420, global:0x0059E430, global:0x0059E830, source:raw]
    // CALCULATION: Build the first basis vector in a3 (offsets 0x0, 0x4, 0x8) from the chosen perpendicular combination of the normalized components [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Build the second basis vector in a4 (offsets 0x0, 0x4, 0x8) as the cross product of the first basis vector and the normalized input vector [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Normalize the first basis vector (a3) [source:raw]
    // CALCULATION: Normalize the second basis vector (a4) [source:raw]

    // Conservative worker pseudocode:
    //   // Build orthonormal basis from a normalized 3-vector input.
    //   if (a2 == NULL) a2 = stackTmpA2;
    //   if (a3 == NULL) a3 = stackTmpA3;
    //   if (a4 == NULL) a4 = stackTmpA4;
    //   copy4DWORDS(a1, a2);          /* a2+0x0..0xC * /
    //   a2->scalar(0x10) = a1->scalar(0x10);
    //   len = sqrt(x*x + y*y + z*z);  /* x,y,z = doubles at a2+0x0, a2+0x8, a2+0x10 * /
    //   x /= len; y /= len; z /= len;
    //   if (fabs(x) >= 0.7) { v4 = (-z, 0, x); }
    //   else                { v4 = (0, z, -y); }
    //   a3 = v4;                      /* first basis vector * /
    //   a4 = cross(v4, u);            /* second basis vector * /
    //   normalize(a3);
    //   normalize(a4);
    // UNRESOLVED: The exact layout of the input structure at a1 (four DWORDs plus a double) is not asserted beyond the copied offsets.
    // UNRESOLVED: The literal-to-global mapping for 1.0 (dbl_59E420) and 0.0 (dbl_59E430) is DERIVED from existing analysis; the raw source inlines the literals directly.
    // UNRESOLVED: The naming of the two constructed vectors as constraint axes is DERIVED from the caller context (BufferEntryAppendWithMatrixInit); the raw body itself only shows vector construction and normalization.
}
