// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508105
// Canonical corpus name: ByteColorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteColorTransform_00508105.c

void UnknownObject::FloatColorToByte()
{
    // Converts one floating-point vertex color channel into a byte. For each vertex, the base color float is added to the scaled (255.0) fourth channel float of the input vertex, the sum is truncated to an integer, and the resulting byte is written through an advancing destination pointer. A format-conversion call may rewrite the input pointer first, and an unconditional utility call runs before the vertex loop.
    // GUARD: If this[1042] (byte offset 0x1048) is non-zero, transform the input buffer format before processing. [field:this:0x00001048, callee:0x00506CE2]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4) and adopt its return value as the new input pointer a4. [callee:0x00506CE2]
    // CALCULATION: Compute the base color source offset v6 = this[11] (byte offset 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)) from sub-cell coordinates a2, a3. [field:this:0x0000002C]
    // CALL: Call UtilityFunction_7473() unconditionally before the vertex loop. [callee:0x00507473]
    // LOOP: for loop over i from 0 while i < this[1046], advancing the input pointer by 16 bytes each iteration. [field:this:0x00001058]
    // CALCULATION: Compute v10 = base float at v6 + 4 * (i & 3) + channel float at (v4 + a4 + 12) * 255.0, then truncate to an integer. [source:raw]
    // ASSIGNMENT: Write the computed byte through the advancing destination pointer *v7++. [source:raw]
    // RETURN: Return dword_8B009C. [global:0x008B009C]

    // Conservative worker pseudocode:
    //   int FloatColorToByte(int *this, char a2, char a3, int a4) {
    //     int base, i, src, dst;
    //     if (this[1042]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     base = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     i = 0;
    //     for (src = 0; i < this[1046]; src += 16) {
    //       float v = *(float *)(base + 4 * (i & 3)) + *(float *)(src + a4 + 12) * 255.0;
    //       *(_BYTE *)dst++ = (int)v;
    //       ++i;
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Destination byte pointer v7 has no visible initialization in the raw source; it is a register-derived value (likely pre-loaded by the caller or from object state).
    // UNRESOLVED: Read global flt_59FEC8 (0x0059FEC8) does not appear as a symbol in the supplied raw source text; its role is unproven (possibly a data-resident constant or shared state).
    // UNRESOLVED: Prelabel identifies this function as a structural twin of VertexColorFloatToByte (005078b5); not independently verified here.
}
