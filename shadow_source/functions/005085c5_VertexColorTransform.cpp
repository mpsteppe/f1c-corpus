// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005085C5
// Canonical corpus name: VertexColorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexColorTransform_005085c5.c

void UnknownObject::VertexColorTransform()
{
    // Per-vertex color transform that, for each vertex, scans a 256-entry (0x100) table anchored 14 dwords into this, keeping the last index where an FPU condition (unrendered c0/c2 flags) held, then emits a 16-bit word combining that index in the low byte with a per-vertex alpha value (float *255.0 plus a base color component) in the high byte. When the format-conversion flag at this+0x1048 is set, first transforms the vertex buffer via DirectXVertexBufferFormatConversion. Reads the vertex-data base at this+0x2C and the vertex count at this+0x1058, then returns the global conversion-state dword at 0x008B009C.
    // ASSIGNMENT: Save original this into v19 and initialize the vertex counter v8 to 0 [source:raw]
    // GUARD: Format-conversion flag this[1042] (offset 0x1048) gates whether the vertex buffer is transformed first [field:this:0x00001048, source:raw]
    // CALL: DirectXVertexBufferFormatConversion(this, a4) transforms the vertex buffer; the returned address replaces a4 as the source base [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // ASSIGNMENT: Compute the source color-data base v5 = this[11] (offset 0x2C) + 4*((a3&3)+8*(a2&3)) from the grid indices a2/a3 [field:this:0x0000002C, source:raw]
    // CALL: UtilityFunction_7473() invoked unconditionally before the per-vertex loop [callee:0x00507473, source:raw]
    // GUARD: Per-vertex loop executes only while the vertex count v19[1046] (offset 0x1058) is non-zero [field:this:0x00001058, source:raw]
    // LOOP: One iteration per vertex, bounded by the vertex count read at this+0x1058 [field:this:0x00001058, source:raw]
    // LOOP: Inner 256-iteration (0x100) scan over table entries at v9 (this + 14 dwords, advancing 4 bytes per entry); records the current index v17 into v15 whenever the FPU condition v11|v12 holds, so v15 ends as the last matching index [source:raw]
    // CALCULATION: v18 = alpha float at (v16+a4+12) * 255.0 plus the base color component at (v5 + 4*(v8&3)), truncated to int for the high byte [source:raw]
    // ASSIGNMENT: Pack one 16-bit word and write through the output pointer v6: v15 | ((int)v18 << 8) — scan index in the low byte, alpha in the high byte [source:raw]
    // LOOP: Advance the source by 16 bytes per vertex, increment the output pointer and vertex counter, and restore v7 to v19 each iteration [source:raw]
    // RETURN: Return the global conversion-state dword_8B009C [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   v19 = this;
    //   if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //   v5 = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //   UtilityFunction_7473();
    //   for (v8 = 0; v8 < v19[0x1058]; ++v8) {
    //       idx = 0;
    //       p = v19 + 14;
    //       for (v17 = 0; v17 < 0x100; ++v17) {
    //           if (c0 | c2) idx = v17;   /* FPU compare condition flags, unrendered * /
    //           p += 4;
    //       }
    //       alpha = (int)(*(float*)(v16 + a4 + 12) * 255.0 + *(float*)(v5 + 4 * (v8 & 3)));
    //       *out16++ = idx | (alpha << 8);
    //       v16 += 16;
    //   }
    //   return dword_8B009C;
    // UNRESOLVED: v11/v12 (FPU condition-code flags c0/c2) are never assigned in the decompiled text, so the inner scan's comparison condition cannot be reconstructed from evidence; the nearest-index interpretation of the recorded v15 is inferred
    // UNRESOLVED: The output 16-bit word pointer v6 (edx) is never assigned in the decompiled text; the real prototype must deliver the output buffer through a register or a hidden argument
    // UNRESOLVED: flt_59EAE0 and flt_59FEC8 are reported as referenced globals by the packet but never appear in the decompiled text, so the 255.0 literal and the inner comparison source cannot be tied to them
    // UNRESOLVED: Meaning of the 256-entry table anchored 14 dwords into this (weight/lookup role) is unconfirmed
}
