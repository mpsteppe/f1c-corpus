// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050930B
// Canonical corpus name: FloatToByteColorConverter_930b
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToByteColorConverter_930b_0050930b.c

void UnknownObject::FloatToByteColorConverter()
{
    // Converts a run of floating-point vertex colors into a packed byte-color format: computes a luminance-weighted value (weights 0.2125, 0.7154, 0.0721) and an alpha value, scales both by 65535.0, adds a per-vertex bias float from the this+0x2C bias array, and packs the two 16-bit quantities into a 32-bit dword per texel. Optionally converts the input vertex buffer format via DirectXVertexBufferFormatConversion when the this+0x1048 flag is set, calls UtilityFunction_7473 before the texel loop, and returns the global dword_8B009C.
    // GUARD: When the format-conversion flag at this+0x1048 is non-zero, convert the input vertex buffer format before processing; otherwise a4 is used as-is. [field:this:0x00001048, function:0x0050930B, source:raw]
    // CALL: DirectXVertexBufferFormatConversion(this, a4) is called on the flag path and its return value replaces the working input pointer a4. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // CALCULATION: Bias pointer v5 = *(this+0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)) selects the 4-float bias entry for the texel. [field:this:0x0000002C, source:raw]
    // CALL: UtilityFunction_7473() runs unconditionally before the texel loop. [callee:0x00507473, source:raw]
    // GUARD: Enter the texel loop only when the texel count at this+0x1058 is non-zero. [field:this:0x00001058, source:raw]
    // LOOP: Iterate v7 = 0 .. count-1; each step reads four consecutive floats (16 bytes) from the input pointer a4 and advances the output dword pointer. [field:this:0x00001058, source:raw]
    // CALCULATION: Luminance v11 = (R*0.2125 + G*0.7154 + B*0.0721) * 65535.0 + bias[v7 & 3]; the three luminance weight globals are flt_5ADB18, flt_5ADB1C, flt_5ADB20 and the scale is flt_59F120. [global:0x005ADB18, global:0x005ADB1C, global:0x005ADB20, global:0x0059F120, field:this:0x0000002C, source:raw]
    // CALCULATION: Alpha v10 = A * 65535.0 + bias[v7 & 3] uses the same global scale flt_59F120. [global:0x0059F120, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Store the 32-bit packed value (int)v11 | ((int)v10 << 16) to the next output dword and advance the output pointer. [source:raw]
    // RETURN: Return the read global dword_8B009C. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int FloatToByteColorConverter(DWORD* this, int x, int y, int a4) {
    //       if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //       float* bias = (float*)(this[0x2C] + 4 * ((y & 3) + 8 * (x & 3)));
    //       UtilityFunction_7473();
    //       for (unsigned i = 0; i < this[0x1058]; i++) {
    //           float lum   = (R * 0.2125f + G * 0.7154f + B * 0.0721f) * 65535.0f + bias[i & 3];
    //           float alpha = A * 65535.0f + bias[i & 3];
    //           *out++ = ((DWORD)(int)alpha << 16) | (DWORD)(int)lum;
    //       }
    //       return dword_8B009C;
    //   }
    // UNRESOLVED: The output dword pointer v6 (edx) is never initialized in the displayed body; its backing field offset is not grounded by any packet field evidence.
    // UNRESOLVED: The exact pairing of flt_5ADB18 / flt_5ADB1C / flt_5ADB20 with the individual luminance weights, and of flt_59F120 with the 65535.0 scale, is DERIVED from the read-only global list rather than proven by a write site.
    // UNRESOLVED: Channel order (which input float is alpha versus red/green/blue) is not deterministically established; the 0.2125 / 0.7154 / 0.0721 weights imply a luminance-weighted grayscale conversion.
}
