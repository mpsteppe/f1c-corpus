// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050895D
// Canonical corpus name: DXTColorEncoder_895d
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DXTColorEncoder_895d_0050895d.c

void UnknownObject::LuminanceAlphaToByte()
{
    // DXT color encoder helper (__thiscall): converts a run of float RGBA vertex data into 4-bit luminance (BT.709 coefficients) plus 4-bit alpha packed into one byte per output sample (low nibble luminance, high nibble alpha). If the format-conversion flag this[1042] (byte 0x1048) is set, first remaps the vertex buffer through DirectXVertexBufferFormatConversion; computes a source pointer from this[11] (byte 0x2C) indexed by the a2/a3 4x4 block coordinates, then loops over this[1046] (byte 0x1058) samples with a 16-byte stride, writing packed bytes and returning dword_8B009C.
    // ASSIGNMENT: Preserve the original this pointer in v12 and initialize the sample counter v4 to zero. [source:raw]
    // GUARD: Guard on the format-conversion flag this[1042] (byte 0x1048); when non-zero the input vertex buffer is remapped before sampling. [field:this:0x00001048, source:raw]
    // CALL: Invoke DirectXVertexBufferFormatConversion(this, a4), replace a4 with the returned converted buffer, then restore this from v12. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // CALCULATION: Compute the sample source pointer v6 = this[11] (byte 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)), selecting the 4x4 block entry addressed by a2/a3. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the sampling loop. [callee:0x00507473, source:raw]
    // GUARD: Guard on vertex count this[1046] (byte 0x1058); when zero the do-while loop body is skipped. [field:this:0x00001058, source:raw]
    // LOOP: do-while loop over this[1046] samples, incrementing counter v4 and advancing the source pointer v8 by 16 bytes per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Per sample, luminance = (B(+8)*0.072099999 + G(+4)*0.71539998 + R(+0)*0.21250001) * 15.0 + palette sample at v6 + 4*(v4&3); alpha = A(+12)*15.0 + same palette sample. Coefficient constants originate from the coefficient globals in the deterministic fact table. [global:0x0059E8D8, global:0x005ADB18, global:0x005ADB1C, global:0x005ADB20, source:raw]
    // ASSIGNMENT: Write packed byte (int)luminance | (16 * (int)alpha) into the output stream and advance v7. [source:raw]
    // RETURN: Return dword_8B009C as the function result. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50895D(_DWORD* this, char a2, char a3, int a4) {
    //     int count = 0;
    //     if (this[1042]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int src = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     int idx = 0; int off = 0;
    //     while (idx < this[1046]) {
    //       float lum = (f32(a4+off+8)*0.072099999 + f32(a4+off+4)*0.71539998 + f32(a4+off)*0.21250001) * 15.0f + f32(src + 4*(idx&3));
    //       float alp = f32(a4+off+12) * 15.0f + f32(src + 4*(idx&3));
    //       *out++ = (int)lum | (16 * (int)alp);
    //       idx++; off += 16;
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Exact mapping of the coefficient globals (flt_59E8D8, flt_5ADB18, flt_5ADB1C, flt_5ADB20) to the literal constants 0.21250001, 0.71539998, 0.072099999, 15.0 and 16 is not established by the packet; the raw source inlines the values.
    // UNRESOLVED: Purpose and side effects of UtilityFunction_7473 (0x00507473) are unknown.
    // UNRESOLVED: Meaning of the returned global dword_8B009C is unknown.
    // UNRESOLVED: The owning object type and the layout of the a2/a3 4x4 block coordinate space are unknown.
}
