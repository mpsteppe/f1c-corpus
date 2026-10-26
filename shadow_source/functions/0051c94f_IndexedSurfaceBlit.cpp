// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C94F
// Canonical corpus name: sub_51C94F
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51C94F_0051c94f.c

void UnknownObject::IndexedSurfaceBlit()
{
    // Row-wise per-pixel color transformation using four lookup tables. Dual path selected by global rendering-mode flag byte_5D79DC: SIMD path (8-pixel groups via sub_51C813 plus scalar remainder) and a pure scalar path. Each pixel writes 3 output bytes indexed from source channel bytes against lookup tables with a base offset.
    // ASSIGNMENT: Load v5 = a1[104] (color lookup sub-struct pointer, this+0x1A0), v6 = a1[71] (base value, this+0x11C), v7 = a1[23] (row width, this+0x5C), and the four lookup tables v5[2..5] (this+0x1A8, this+0x1AC, this+0x1B0, this+0x1B4). [field:this:0x000001A0, field:this:0x0000011C, field:this:0x0000005C, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B0, field:this:0x000001B4]
    // CALCULATION: Compute v10 = v7 & 0xFFFFFFF8: the row width aligned down to whole 8-pixel SIMD groups. [source:raw]
    // GUARD: Branch on rendering-mode flag byte_5D79DC (global): non-zero selects the SIMD+scalar hybrid path, zero selects the pure scalar path. [global:0x005D79DC]
    // GUARD: Both paths require a5-1 >= 0 (row count guard) before processing any row. [source:raw]
    // LOOP: SIMD path: iterate over rows while row counter a5 decrements to zero; each row resolves three source plane pointers from a2 plus 4*a3 and advances the output row pointer a4. [source:raw]
    // CALL: SIMD path: call sub_51C813 with the 8-pixel group count v10 and the three plane pointers to process aligned 8-pixel groups. [callee:0x0051C813]
    // GUARD: SIMD path remainder: when the 8-pixel group count v10 is less than the full width v42, process the remaining pixels with a scalar loop. [source:raw]
    // LOOP: SIMD-path scalar remainder: per-pixel, read source channel bytes, index lookup tables with the base offset v6, and write three output bytes per pixel. [source:raw]
    // LOOP: Scalar path: per-row per-pixel loop gated on width v7 != 0, performing the same three-byte table-indexed color write as the SIMD remainder path. [source:raw]
    // RETURN: Return the final result pointer (last pixel/output pointer used). __cdecl ABI as recorded in the legacy ABI lead. [abi:lead, function:0x0051C94F]

    // Conservative worker pseudocode:
    //   v5 = this->colorTables;           // this+0x1A0
    //   base = this->tableBase;           // this+0x11C
    //   width = this->rowWidth;           // this+0x5C
    //   tA = v5[2]; tB = v5[3]; tC = v5[4]; tD = v5[5];
    //   groups = width & ~7;
    //   if (byte_5D79DC) {
    //     if (a5-1 < 0) return result;
    //     for (row = 0; row < a5; row++) {
    //       p0 = a2[0] + 4*a3; p1 = a2[1] + 4*a3; p2 = a2[2] + 4*a3;
    //       sub_51C813(groups, p0, p1, p2, *a4);
    //       // scalar remainder for pixels [groups, width)
    //       a4++;
    //     }
    //   } else {
    //     if (a5-1 >= 0)
    //       for (row = 0; row < a5; row++)
    //         if (width) per-pixel table lookup using tA/tB/tC/tD + base;
    //   }
    //   return result;
    // UNRESOLVED: Field this+0x1B5 is listed in the packet but not referenced in the raw source.
    // UNRESOLVED: The exact color-space meaning of the four lookup tables and the base offset v6 is not established from the packet alone.
    // UNRESOLVED: Plane pointer semantics of a2 (three-plane source layout) are inferred from indexing, not confirmed.
}
