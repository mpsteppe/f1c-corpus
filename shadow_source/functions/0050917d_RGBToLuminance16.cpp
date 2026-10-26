// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050917D
// Canonical corpus name: TextureColorSpaceTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureColorSpaceTransform_0050917d.c

void UnknownObject::RGBToLuminance16()
{
    // Texture color-space transform helper (__thiscall): converts a run of float RGBA vertex data into a single 16-bit luminance value per sample using BT.709 coefficients (0.21250001 R + 0.71539998 G + 0.072099999 B) scaled by 65535.0 plus a per-sample palette/table offset. If the format-conversion flag this[1042] (byte 0x1048) is set, first remaps the vertex buffer through DirectXVertexBufferFormatConversion; computes a source pointer from this[11] (byte 0x2C) indexed by the a2/a3 block coordinates, calls UtilityFunction_7473, then loops over this[1046] (byte 0x1058) samples with a 16-byte stride writing 16-bit words and returning dword_8B009C.
    // ASSIGNMENT: Preserve the original this pointer in v11 and initialize source offset v4 to zero. [source:raw]
    // GUARD: Guard on the format-conversion flag this[1042] (byte 0x1048); when non-zero the input vertex buffer is remapped before sampling. [field:this:0x00001048, source:raw]
    // CALL: Invoke DirectXVertexBufferFormatConversion(this, a4), replace a4 with the returned converted buffer, then restore this from v11. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // CALCULATION: Compute the palette/source pointer v6 = this[11] (byte 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)), selecting the entry addressed by a2/a3. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the sampling loop. [callee:0x00507473, source:raw]
    // LOOP: for loop over i < this[1046] (byte 0x1058), advancing source offset v4 by 16 bytes per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Per sample, luminance = (B(+8)*0.072099999 + G(+4)*0.71539998 + R(+0)*0.21250001) * 65535.0 + palette sample at v6 + 4*(i&3). Coefficient constants originate from the coefficient globals in the deterministic fact table. [global:0x0059F120, global:0x005ADB18, global:0x005ADB1C, global:0x005ADB20, source:raw]
    // ASSIGNMENT: Write the truncated integer (int)v10 as a 16-bit word into the output stream and advance v7. [source:raw]
    // RETURN: Return dword_8B009C as the function result. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50917D(_DWORD* this, char a2, char a3, int a4) {
    //     if (this[1042]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int src = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     int i = 0; int off = 0;
    //     for (i = 0; i < this[1046]; off += 16, i++) {
    //       float v = (f32(a4+off+8)*0.072099999 + f32(a4+off+4)*0.71539998 + f32(a4+off)*0.21250001) * 65535.0f + f32(src + 4*(i&3));
    //       *out16++ = (short)(int)v;
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Exact mapping of the coefficient globals (flt_59F120, flt_5ADB18, flt_5ADB1C, flt_5ADB20) to the literal constants 0.21250001, 0.71539998, 0.072099999 and 65535.0 is not established by the packet; the raw source inlines the values.
    // UNRESOLVED: Purpose and side effects of UtilityFunction_7473 (0x00507473) are unknown.
    // UNRESOLVED: Meaning of the returned global dword_8B009C is unknown.
    // UNRESOLVED: The owning object type and the meaning of the a2/a3 block coordinate space are unknown.
}
