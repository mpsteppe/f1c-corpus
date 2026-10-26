// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005968F6
// Canonical corpus name: sub_5968F6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5968F6_005968f6.c

void UnknownObject::LocaleInfoRetrieval()
{
    // CRT locale-info retrieval with two modes selected by a1. Mode 1 (string) fetches an LCTYPE string via sub_597E4F into a 128-byte stack buffer, growing to a heap buffer when GetLastError() == 122, then allocates a result buffer and copies the data with sub_587DD0; all heap temporaries are freed with sub_58AA6F. Mode 0 (numeric) reads 4 bytes of raw locale data via sub_597D3C into the global LCData buffer and accumulates digits into *(BYTE*)a4, breaking on the first non-numeric byte (classification via off_5E69C8 when cbMultiByte <= 1, else CharacterEncodingConvertViaLookupTableFallback). Returns 0 on success and -1 on query, allocation, or mode failure.
    // GUARD: Mode dispatch: a1 == 1 selects string retrieval, a1 == 0 selects numeric parsing, and any other a1 returns -1 [source:raw]
    // CALL: sub_597E4F(Locale, LCType, LCData, 128, 0) fetches the locale string into the 128-byte stack buffer [callee:0x00597E4F, source:raw]
    // GUARD: On an empty first fetch, GetLastError() must be 122 (ERROR_INSUFFICIENT_BUFFER) to continue with the size query; otherwise return -1 [global:0x0059E188, source:raw]
    // CALL: sub_597E4F(Locale, LCType, 0, 0, 0) queries the required buffer size [callee:0x00597E4F, source:raw]
    // CALL: MallocWrapperForNhMalloc(v6) allocates the required temporary heap buffer; failure returns -1 [callee:0x0058A935, source:raw]
    // ASSIGNMENT: v15 is set to 1 to flag the temporary buffer as heap-allocated (must be freed on cleanup) [source:raw]
    // CALL: sub_597E4F(Locale, LCType, v8, v7, 0) fetches the locale string into the heap temporary [callee:0x00597E4F, source:raw]
    // CALL: MallocWrapperForNhMalloc(v5) allocates the result buffer and *a4 is set to it; a null result triggers error cleanup [callee:0x0058A935, source:raw]
    // CALL: sub_587DD0(v9, v4, v5) copies the locale string from the source buffer to the result buffer [callee:0x00587DD0, source:raw]
    // CALL: sub_58AA6F(v4) frees the heap-allocated temporary buffer when v15 is set [callee:0x0058AA6F, source:raw]
    // GUARD: A failed fetch or null result buffer after the size query jumps to the shared error cleanup (sub_58AA6F(v4) + return -1) [callee:0x0058AA6F, source:raw]
    // CALL: sub_597D3C(Locale, LCType, &LCData, 4, 0) reads 4 bytes of raw locale data into the global LCData buffer; a null result returns -1 [callee:0x00597D3C, global:0x008D41C4, source:raw]
    // ASSIGNMENT: *(_BYTE *)a4 = 0 initializes the numeric accumulator before the parse loop [source:raw]
    // LOOP: Iterates over the LCData bytes from the global buffer start up to the word_8D41CC bound, accumulating one digit per iteration [global:0x008D41CC, source:raw]
    // GUARD: Character classification: when cbMultiByte <= 1 the table lookup off_5E69C8[0][v12] & 4 is used, otherwise CharacterEncodingConvertViaLookupTableFallback(v12, 4); a non-numeric class result breaks the loop [global:0x005E6BD4, global:0x005E69C8, callee:0x0058C674, source:raw]
    // ASSIGNMENT: *(_BYTE *)a4 = v12 + 10 * *(_BYTE *)a4 - 48 accumulates each decimal digit into the result byte [source:raw]
    // RETURN: Returns 0 on success, -1 on locale query failure, allocation failure, or an invalid mode [source:raw]
    // CALL: Invoked by sub_58F014, AudioCodecBufferAllocation, sub_58F7C9 and sub_58F939 [caller:0x0058F014, caller:0x0058F4F2, caller:0x0058F7C9, caller:0x0058F939]

    // Conservative worker pseudocode:
    //   if (a1 == 1) {
    //       v4 = LCData; v15 = 0;
    //       v5 = sub_597E4F(Locale, LCType, LCData, 128, 0);
    //       if (!v5) {
    //           if (GetLastError() != 122) return -1;
    //           v6 = sub_597E4F(Locale, LCType, 0, 0, 0);
    //           if (!v6) return -1;
    //           v4 = MallocWrapperForNhMalloc(v6);
    //           if (!v4) return -1;
    //           v15 = 1;
    //           v5 = sub_597E4F(Locale, LCType, v4, v6, 0);
    //           if (!v5) goto cleanup;
    //       }
    //       v9 = MallocWrapperForNhMalloc(v5);
    //       *a4 = v9;
    //       if (!v9) {
    //           if (!v15) return -1;
    //   cleanup:
    //           sub_58AA6F(v4);
    //           return -1;
    //       }
    //       sub_587DD0(v9, v4, v5);
    //       if (v15) sub_58AA6F(v4);
    //   } else if (a1 == 0) {
    //       if (!sub_597D3C(Locale, LCType, &LCData, 4, 0)) return -1;
    //       *(_BYTE *)a4 = 0;
    //       v11 = (BYTE*)&LCData;
    //       do {
    //           v12 = *v11;
    //           v13 = (cbMultiByte <= 1) ? (off_5E69C8[0][v12] & 4)
    //                                   : CharacterEncodingConvertViaLookupTableFallback(v12, 4);
    //           if (!v13) break;
    //           ++v11;
    //           *(_BYTE *)a4 = v12 + 10 * *(_BYTE *)a4 - 48;
    //       } while ((int)v11 < (int)word_8D41CC);
    //   } else {
    //       return -1;
    //   }
    //   return 0;
    // UNRESOLVED: The exact semantics of mode-0 digit parsing (leading zeros, sign handling, and the terminating condition at word_8D41CC) are inferred from the loop shape
    // UNRESOLVED: The cbMultiByte / off_5E69C8 relationship is a character-classification table with a version switch; the exact table layout is unknown
    // UNRESOLVED: The a4 output contract differs per mode (allocated string pointer vs byte accumulator); the caller expectations are not documented
}
