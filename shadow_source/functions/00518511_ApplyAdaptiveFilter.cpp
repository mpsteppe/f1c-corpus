// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00518511
// Canonical corpus name: sub_518511
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_518511_00518511.c

void UnknownObject::ApplyAdaptiveFilter()
{
    // Row-wise adaptive-filter dispatcher (cdecl). Applies one of four predictor modes, selected by a5, to a byte row a3 using the predictor row a4 and a row descriptor a2 whose +4 field holds the byte count and whose +11 field holds the bit depth (bytes-per-pixel = (depth+7)>>3). Modes: 1 extends the leading block across the row, 2 adds the predictor, 3 averages, 4 applies a three-sample minimizer. Unrecognized modes report 'Ignoring bad adaptive filter type' through CallbackDispatch and zero the first output byte.
    // GUARD: Dispatch guard: if a5 (filter mode) is nonzero the function enters a switch over the four adaptive-filter cases; when a5 is zero the buffers are left untouched and the function returns zero. [source:raw]
    // LOOP: Case 1 (extend leading block): with byte-depth offset off=(*(a2+11)+7)>>3 and row length len=*(a2+4), copy-add the first off bytes of a3 onto the trailing len-off bytes (a3[i+off] += a3[i]), duplicating the first block across the rest of the row. [source:raw]
    // LOOP: Case 2 (add predictor): for i in 0..len-1 over *(a2+4) bytes, accumulate the predictor row: a3[i] += a4[i]. [source:raw]
    // LOOP: Case 3 (average predictor): for the first off bytes add a3[i] += a4[i]>>1; for the remaining bytes add a3[i] += (a4[i] + a3[i-off])/2. [source:raw]
    // LOOP: Case 4 (three-sample minimizer): for the first off bytes add a3[i] += a4[i]; for the remaining bytes select the sample among a3[i], a4[i], a4[i+1] that minimizes a pair-difference metric and accumulate it into a3[i]. [source:raw]
    // GUARD: Default case (invalid filter type): guard that routes unrecognized modes to the error path. [source:raw]
    // CALL: Call CallbackDispatch(a1, aIgnoringBadAda) with the 'Ignoring bad adaptive filter type' message string on the invalid-mode path. [callee:0x00511887, global:0x005AFB2C, source:raw]
    // ASSIGNMENT: On the invalid-mode path, zero the first destination byte: *a3 = 0. [source:raw]
    // RETURN: Return the byte value accumulated in v5 (zero on the invalid-mode path and when a5 is zero). [source:raw]
    // CALL: Invoked by sub_511B7C (0x00511B7C) as the row adaptive-filter stage. [caller:0x00511B7C, source:raw]

    // Conservative worker pseudocode:
    //   char sub_518511(int a1, int a2, byte *dst, const byte *pred, int mode) {
    //     unsigned char r = (unsigned char)mode;
    //     if (mode) {
    //       int len = *(int *)(a2 + 4);
    //       int off = (*(byte *)(a2 + 11) + 7) >> 3;
    //       switch (mode) {
    //         case 1: for (i = off; i < len; ++i) dst[i] += dst[i - off]; break;
    //         case 2: for (i = 0; i < len; ++i) dst[i] += pred[i]; break;
    //         case 3:
    //           for (i = 0; i < off; ++i) dst[i] += pred[i] >> 1;
    //           for (; i < len; ++i) dst[i] += (pred[i] + dst[i - off]) / 2;
    //           break;
    //         case 4:
    //           for (i = 0; i < off; ++i) dst[i] += pred[i];
    //           for (; i < len; ++i) dst[i] += pick3(dst[i - off], pred[i], pred[i + 1]);
    //           break;
    //         default:
    //           CallbackDispatch(a1, "Ignoring bad adaptive filter type");
    //           dst[0] = 0;
    //           r = 0;
    //       }
    //     }
    //     return r;
    //   }
    // UNRESOLVED: a2 is treated as a row descriptor (+4 byte count, +11 bit depth); its full struct layout and owner class are unknown.
    // UNRESOLVED: The four modes resemble PNG-style adaptive filter predictors (Sub/Up/Average/Paeth-like), but the exact filter family and bit-depth scaling are unverified.
    // UNRESOLVED: Case 4's three-sample minimizer is median-like but not provably a standard Paeth predictor.
    // UNRESOLVED: Meaning of a1 in the CallbackDispatch error path is unknown.
}
