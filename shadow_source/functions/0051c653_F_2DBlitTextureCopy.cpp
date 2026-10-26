// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C653
// Canonical corpus name: F_2DBlitTextureCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DBlitTextureCopy_0051c653.c

void UnknownObject::F_2DBlitTextureCopy()
{
    // 2D texture copy with column-wise output placement. Reads column count (field +0x20) and per-segment byte length (field +0x5C) from the surface object a1, then for each of a5 output rows and each column i in [0, column count) copies the byte segment addressed through a DWORD index table a2 (source pointer = v8 + a2[i], with v8 advancing by 4 per output row) into the output column starting at *a4 + i using a vertical stride of column count. Guarded by output row count a5 being at least 1.
    // ASSIGNMENT: load v5 = *(a1 + 92) (segment byte length, field +0x5C) and v13 = *(a1 + 32) (column count / vertical stride, field +0x20); keep a saved copy v11 of v5 [field:this:0x0000005C, field:this:0x00000020, source:raw]
    // GUARD: proceed only when the output row count a5 - 1 is >= 0, i.e. a5 >= 1; otherwise return [source:raw]
    // LOOP: outer loop over a5 output rows; per row recompute the source table byte offset v8 += 4 and advance the output base pointer a4 [source:raw]
    // LOOP: inner loop over i in [0, v13): resolve the source pointer v10 = *(BYTE**)(v8 + *(DWORD*)(a2 + 4*i)) from the index table a2 and compute the output address *a4 + i [field:this:0x00000020, source:raw]
    // LOOP: copy the v5-byte segment: repeat *result = *v10; result += v13; ++v10 until the segment byte count is exhausted, writing down the output column with vertical stride v13 while reading the source row contiguously [field:this:0x0000005C, field:this:0x00000020, source:raw]
    // RETURN: return result, which after the final copy points just past the last written byte; the value is a leftover pointer and carries no caller contract [source:raw]

    // Conservative worker pseudocode:
    //   BYTE* F_2DBlitTextureCopy(int surf, DWORD* indexTable, int baseCol, DWORD* dstRows, BYTE* rowCount) {
    //       int segLen = *(int*)(surf + 0x5C);
    //       int cols = *(int*)(surf + 0x20);
    //       if ((int)(rowCount - 1) < 0) return rowCount - 1;
    //       BYTE* dstRow = rowCount;
    //       int off = 4 * baseCol;
    //       do {
    //           for (int i = 0; i < cols; ++i) {
    //               BYTE* src = *(BYTE**)(off + indexTable[i]);
    //               BYTE* out = (BYTE*)(*dstRows + i);
    //               int n = segLen;
    //               if (n) {
    //                   do {
    //                       *out = *src;
    //                       out += cols;
    //                       ++src;
    //                   } while (--n);
    //               }
    //           }
    //           off += 4;
    //           ++dstRows;
    //       } while (--dstRow);
    //       return dstRow;
    //   }
    // UNRESOLVED: the role of a3 is DERIVED from its use as 4*a3 initial source byte offset; its exact meaning (e.g. starting column index) is not established
    // UNRESOLVED: the index table a2 stores DWORD offsets added to v8; the table contents and object owning it are unknown
    // UNRESOLVED: the output placement (column stride = column count, producing a transposed layout) is DERIVED from the address arithmetic
    // UNRESOLVED: the returned pointer has no apparent contract; no callers are known in the packet
}
