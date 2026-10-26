// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051C237
// Canonical corpus name: PixelBlendFilterHorizontal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PixelBlendFilterHorizontal_0051c237.c

void UnknownObject::PixelBlendFilterHorizontal()
{
    // Horizontal 2x interpolating pixel filter. For each of the row-count rows (field +0x110 on a1), reads an input row pointer from array a3[i] and an output row pointer from (*a4)[i], then writes 2*count output bytes per row from count input bytes using weighted kernel arithmetic ((3a+b+2)>>2, (a+3b+1)>>2 etc.): first output byte copied through, interior runs as a (count-2)-iteration loop when the channel count at a2+40 differs from 2, and the trailing boundary always emitted. Returns a1. The a2+40 != 2 guard skips the interior loop for the 2-channel case, leaving only boundary pixels processed.
    // ASSIGNMENT: initialize row counter v18 = 0 and load the output row-pointer array v5 = *a4 [source:raw]
    // GUARD: enter the per-row loop only when the row count at a1 + 272 (> 0x110) is greater than 0; otherwise return a1 unchanged [guard:0, field:this:0x00000110, source:raw]
    // CALCULATION: precompute v7 = a3 - v5 once; per row, v8 = *(BYTE**)(v5 + v7) resolves to the input row pointer a3[rowIndex] as v5 advances [source:raw]
    // LOOP: iterate rows while v18 < row count at a1+272; per row write the leading boundary pixels out[0] = in[0] and out[1] = (3*in[0] + in[1] + 2) >> 2 [field:this:0x00000110, source:raw]
    // GUARD: when the channel count at a2 + 40 is not 2, process the interior pixels with the weighted blend loop [source:raw]
    // LOOP: interior loop of (channel count - 2) iterations; each iteration emits two outputs from three adjacent inputs: out[2k] = (in[k-1] + 3*in[k] + 1) >> 2 and out[2k+1] = (in[k+1] + 3*in[k] + 2) >> 2 [source:raw]
    // ASSIGNMENT: emit the trailing boundary pixels out[2*count-2] = (in[count-2] + 3*in[count-1] + 1) >> 2 and out[2*count-1] = in[count-1] [source:raw]
    // RETURN: return a1 [source:raw]

    // Conservative worker pseudocode:
    //   int PixelBlendFilterHorizontal(int self, int channelObj, int srcTable, BYTE*** dstRows) {
    //       int row = 0;
    //       BYTE** outRows = *dstRows;
    //       int delta = srcTable - outRows;
    //       if (*(int*)(self + 0x110) <= 0) return self;
    //       do {
    //           BYTE* in = *(BYTE**)(outRows + delta);   /* = srcTable[row] * /
    //           BYTE* out = *outRows;
    //           int c0 = *in;
    //           out[0] = c0;
    //           out[1] = (3*c0 + in[1] + 2) >> 2;
    //           BYTE* ip = in + 1;
    //           BYTE* op = out + 2;
    //           if (*(int*)(channelObj + 40) != 2) {
    //               int n = *(int*)(channelObj + 40) - 2;
    //               do {
    //                   int ck = *ip;
    //                   int prev = *(ip++ - 1);
    //                   ck *= 3;
    //                   op[0] = (prev + ck + 1) >> 2;
    //                   op[1] = (*ip + ck + 2) >> 2;
    //                   op += 2;
    //               } while (--n);
    //           }
    //           int last = *ip;
    //           op[0] = (*(ip - 1) + 3*last + 1) >> 2;
    //           op[1] = last;
    //           outRows++;
    //       } while (++row < *(int*)(self + 0x110));
    //       return self;
    //   }
    // UNRESOLVED: the channel count at a2 + 40 is read on an argument object, not on this; it has no packet field evidence ref and its object type is unknown
    // UNRESOLVED: the filter kernel weights (3-1 / 1-3) and the 2-channel special case are DERIVED from the shift-divide arithmetic, not from an authoritative label
    // UNRESOLVED: a3 and a4 are treated as arrays of row pointers; that layout is DERIVED from the pointer dereference pattern (a3 + rowIndex dereferenced to a byte pointer)
}
