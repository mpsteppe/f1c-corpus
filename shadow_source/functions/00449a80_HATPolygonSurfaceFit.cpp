// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449A80
// Canonical corpus name: HATPolygonSurfaceFit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HATPolygonSurfaceFit_00449a80.c

void UnknownObject::HATPolygonSurfaceFit()
{
    // Fits a quadratic surface to a set of 6 input points and writes the 6 solved coefficients into this+0x0..0x2C. Reads the point buffer through pointer pairs at a2+8*i (x, y implied, z at +12, measured value as double at +16), builds three pairwise edge vectors stored at this+0x30..0x50, sorts them by a scalar, assembles a 6x6 linear system from the points, and solves it via sub_5677B0 (Gaussian elimination). Residuals of the first 3 points are checked against threshold 0.001; if the full fit fails, a fallback 3-point solve populates the coefficients and zeroes the first three. On failure logs via DebugLogWrite and returns -1; on success optionally subtracts a double from the stored coefficient at this+0x28 when this+0x54 (this[21]) is set, then returns 0. Conditional debug logging uses StringSplitLoop gates and the aDDevF119992002_0 format string.
    // CALL: Loads an indexed value through IndexedArrayAccess from the unsigned 16-bit value at a2+26 and stores it into this+0x54 (this[21]). [callee:0x004CE8D0, field:this:0x00000054]
    // ASSIGNMENT: Copies the byte at a2+24 into this+0x58 (byte at this+88). [field:this:0x00000058]
    // LOOP: For each i in 0..2 builds an edge vector at this[12+3i] (offsets this+0x30, 0x3C, 0x48) from a pair of input points (pointer pairs at a2+8*i), computes its squared length and orientation dot-product, and flips the vector's sign when it does not align with the third reference point. Touches this[12..20], i.e. this+0x30..0x50. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // LOOP: Sorts the three edge vectors by the scalar values held in the v54/v55/v56/v57 locals, swapping the stored dwords among this[12..20] so the vectors are ordered by that quantity. [field:this:0x00000030, field:this:0x0000003C, field:this:0x00000048, source:raw]
    // LOOP: Assembles the 6x6 linear system for Gaussian elimination (v64/v66/v65/v67) from the 6 input points, using the point coordinates and the measured double value at point+16; the identity lagrange terms are written with the double 1.0 split across two dwords. [source:raw]
    // CALL: Solves the 6-point system via sub_5677B0(v64, 6); when it succeeds and StringSplitLoop(1, aDDevF119992002_0, 290) is truthy, calls DebugLogWrite(&dword_8AD25C, aGaussianElimin) to log the elimination. [callee:0x005677B0, callee:0x004D7A50, callee:0x004D7AA0, global:0x005C4434, global:0x005C4404, global:0x008AD25C]
    // ASSIGNMENT: Stores the six solved double coefficients (from v67/v70/v73/v74/v75/v76) into this+0x0..0x2C, i.e. this[0..11], as three dword pairs per coefficient (A through F). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // LOOP: Residual check over the first 3 points: evaluates the fitted quadratic at each point and breaks out of the check when the residual magnitude exceeds 0.001, triggering the 3-point fallback solve. [source:raw]
    // CALCULATION: Rebuilds the system from the first 3 points (v65/v66) and solves it with sub_5677B0(v64, 3); when the 3-point solve fails, zeroes this[0..5] and copies fallback coefficient dwords from the locals into this[0..11]. [callee:0x005677B0, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C]
    // GUARD: When the a3 flag is set and this+0x54 (this[21]) is non-zero, subtracts the double at (this[21]+100) from the stored coefficient double at this+0x28. [field:this:0x00000054, field:this:0x00000028]
    // CALL: On the second debug gate, StringSplitLoop(1, aDDevF119992002_0, 328) enables DebugLogWrite(&dword_8AD25C, aGaussianElimin_0) logging the fallback elimination, after which the function returns -1. [callee:0x004D7A50, callee:0x004D7AA0, global:0x005C4434, global:0x005C43D4, global:0x008AD25C]
    // RETURN: Returns 0 when the fit succeeded (LABEL_37) and -1 when the elimination path failed. [source:raw]

    // Conservative worker pseudocode:
    //   this[21] = IndexedArrayAccess(*(u16*)(a2 + 26));
    //   *(u8*)this + 88 = *(u8*)(a2 + 24);
    //   for i in 0..2: build edge vector at this[12 + 3i] from points a2[8*i], a2[8*next], a2[8*prev];
    //   flip sign when v52[3]*v5[1] + *v5**v52 < v11;
    //   sort the three edge vectors by scalar locals v54/v55/v56/v57;
    //   assemble 6x6 system v64/v66/v65/v67 from the 6 points (z at +12, value double at +16);
    //   if sub_5677B0(v64, 6) and StringSplitLoop(1, aDDevF119992002_0, 290): DebugLogWrite(&dword_8AD25C, aGaussianElimin);
    //   copy solved doubles into this[0..11];
    //   if any of first 3 point residuals > 0.001: re-solve with 3 points;
    //   if sub_5677B0(v64, 3) fails: zero this[0..5], copy fallback dwords into this[0..11];
    //   if a3 and this[21]: *((double*)this + 5) -= *(double*)(this[21] + 100);
    //   if StringSplitLoop(1, aDDevF119992002_0, 328): DebugLogWrite(&dword_8AD25C, aGaussianElimin_0);
    //   return 0 on success, -1 on elimination failure;
    // UNRESOLVED: Read globals dbl_59E880 and dbl_59EA08 are reported by deterministic facts but do not appear in the decompiled text; their role (likely surface-fit constants) is ungrounded.
    // UNRESOLVED: Read global dword_8ACEA0 is reported by deterministic facts but is not visible in the decompiled text.
    // UNRESOLVED: Field this+0xB8 is read per deterministic facts but its use is not visible in the decompiled text.
    // UNRESOLVED: The meaning of the value at (this[21]+100) subtracted in the a3-guarded path is DERIVED, not confirmed.
    // UNRESOLVED: The fallback 3-point coefficient layout and the exact meaning of the 1.0 dword-split lagrange terms are inferred from Gaussian-elimination structure.
}
