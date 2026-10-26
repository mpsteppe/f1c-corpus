// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00507BC5
// Canonical corpus name: ColorVertexTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ColorVertexTransform_00507bc5.c

void UnknownObject::ColorVertexTransform()
{
    // Transforms floating-point vertex colors into packed 16-bit RGB565 words. Optionally converts the input vertex buffer format first (flag at 0x1048), computes a per-row/column source pointer, then for each vertex scales the R/B channels by 31.0 and the G channel by 63.0 and packs into (R<<11)|(G<<5)|B. Returns the global conversion state.
    // GUARD: If the format-conversion flag this[1042] (offset 0x1048) is non-zero, the input vertex buffer format needs conversion first. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion (0x00506CE2) with this and the input a4, replacing a4 with its result. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute the source color pointer v5 = this[11] (offset 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)), indexing a color grid by the low two bits of a2 and a3. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction (0x00507473) unconditionally before the packing loop. [callee:0x00507473, source:raw]
    // GUARD: Only enter the packing loop when the vertex count this[1046] (offset 0x1058) is non-zero. [field:this:0x00001058, source:raw]
    // LOOP: do-while loop over v16[1046] vertices with counter v7 advancing from 0. [field:this:0x00001058, source:raw]
    // CALCULATION: Load the base color value v15 = *(float *)(v5 + 4 * (v7 & 3)), cycling through four stored base components. [source:raw]
    // CALCULATION: R channel: v12 = *(float *)(v8 + a4) * 31.0 + v15, truncated to v9 = (int)v12; scale factor 31.0 backed by flt_5ACCD0. [global:0x005ACCD0, source:raw]
    // CALCULATION: G channel: v13 = *(float *)(v8 + a4 + 4) * 63.0 + v15, truncated to v11 = (int)v13; scale factor 63.0 backed by flt_5ACCD8. [global:0x005ACCD8, source:raw]
    // CALCULATION: B channel: v14 = *(float *)(v8 + a4 + 8) * 31.0 + v15, truncated; scale factor 31.0 backed by flt_5ACCD0. [global:0x005ACCD0, source:raw]
    // ASSIGNMENT: Pack RGB565: *v6++ = (int)v14 | (32 * (v11 | (v9 << 6))) yielding (R<<11)|(G<<5)|B, and advance the input stride v8 by 16 bytes per vertex. [source:raw]
    // RETURN: Return the global conversion state dword_8B009C (0x008B009C). [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_507BC5(_DWORD *self, char a2, char a3, int a4) {
    //     if (self[1042]) a4 = DirectXVertexBufferFormatConversion(self, a4);
    //     int src = self[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     for (unsigned int i = 0; i < self[1046]; ++i) {
    //       float base = *(float *)(src + 4 * (i & 3));
    //       int r = (int)(*(float *)(a4) * 31.0f + base);
    //       int g = (int)(*(float *)(a4 + 4) * 63.0f + base);
    //       int b = (int)(*(float *)(a4 + 8) * 31.0f + base);
    //       *dst++ = (_WORD)(b | (32 * (g | (r << 6))));
    //       a4 += 16;
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: The destination pointer v6 is read before any write in the raw source (decompiler artifact); the output buffer is not evidenced.
    // UNRESOLVED: Purpose of UtilityFunction_7473 (0x00507473) is unknown.
    // UNRESOLVED: Meaning of the returned global dword_8B009C (conversion state) is unknown.
    // UNRESOLVED: The role of the four stored base components and the low-two-bit grid indexing of a2/a3 are inferred, not proven.
}
