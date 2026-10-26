// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058F4F2
// Canonical corpus name: AudioCodecBufferAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioCodecBufferAllocation_0058f4f2.c

void UnknownObject::LocaleDataBufferInit()
{
    // Initializes three locale formatting buffers (digit grouping, leading zero, decimal separator) stored as an array of three pointers in off_5E9AC0. When the locale flag dword_8D3F40 is nonzero it queries system locale data via sub_5968F6 for LCTYPE-style indices 0xE, 0xF and 0x10, strips semicolons from the decimal separator string via InPlaceDigitCharConversionStripSemicolons, then stores the three allocated buffers into off_5E9AC0 and publishes the first byte of the first buffer into byte_5E6BD8 with dword_5E6BDC set to 1. When the flag is zero it allocates empty two-byte buffers through MallocWrapperForNhMalloc and initializes them. Returns 0 on success and -1 on any allocation failure.
    // GUARD: Branch on locale flag dword_8D3F40: nonzero path queries system locale data, zero path allocates empty default buffers. Locale ID seed v0 is read from word_8D3F8E. [global:0x008D3F40, global:0x008D3F8E, source:raw]
    // CALL: Query locale data with sub_5968F6 for indices 0xE, 0xF and 0x10 into dword_8D3F5C, dword_8D3F60 and dword_8D3F64; the OR of the three results becomes the failure flag v3. [callee:0x005968F6, global:0x008D3F5C, global:0x008D3F60, global:0x008D3F64, source:raw]
    // CALL: Normalize the decimal separator buffer dword_8D3F64 in place with InPlaceDigitCharConversionStripSemicolons. [callee:0x0058F6C7, global:0x008D3F64, source:raw]
    // GUARD: If the locale query failed (v3 nonzero), free the three buffers with sub_58AA6F, clear dword_8D3F5C/60/64 and return -1. [callee:0x0058AA6F, global:0x008D3F5C, global:0x008D3F60, global:0x008D3F64, source:raw]
    // GUARD: If off_5E9AC0[0] does not equal the sentinel unk_5E9A88, free the three previously stored buffers via sub_58AA6F before replacing them. [global:0x005E9AC0, global:0x005E9A88, callee:0x0058AA6F, source:raw]
    // ASSIGNMENT: Publish the three freshly queried buffers into the off_5E9AC0 pointer array. [global:0x005E9AC0, global:0x008D3F5C, global:0x008D3F60, global:0x008D3F64, source:raw]
    // ASSIGNMENT: Store the first byte of the first buffer into byte_5E6BD8 and set the init flag dword_5E6BDC to 1. [global:0x005E6BD8, global:0x005E6BDC, global:0x005E9AC0, source:raw]
    // CALL: Default-flag path: allocate three two-byte buffers with MallocWrapperForNhMalloc, initialize the first via sub_58FCA0, zero the remaining two, then set byte_5E6BD8 and dword_5E6BDC as above. Each failed allocation returns -1. [callee:0x0058A935, callee:0x0058FCA0, global:0x005E9AC0, source:raw]
    // RETURN: Return 0 on success or -1 when a buffer allocation failed. [function:0x0058F4F2, source:raw]

    // Conservative worker pseudocode:
    //   int sub_58F4F2(void) {
    //     LCID localeId = word_8D3F8E;
    //     if (dword_8D3F40) {
    //       int fail = sub_5968F6(1, localeId, 0xE, &dword_8D3F5C)
    //                 | sub_5968F6(1, localeId, 0xF, &dword_8D3F60)
    //                 | sub_5968F6(1, localeId, 0x10, &dword_8D3F64);
    //       InPlaceDigitCharConversionStripSemicolons(dword_8D3F64);
    //       if (fail) { sub_58AA6F(dword_8D3F5C); sub_58AA6F(dword_8D3F60); sub_58AA6F(dword_8D3F64);
    //                    dword_8D3F5C = dword_8D3F60 = dword_8D3F64 = 0; return -1; }
    //       if (*off_5E9AC0 != &unk_5E9A88) { sub_58AA6F(off_5E9AC0[0]); sub_58AA6F(off_5E9AC0[1]); sub_58AA6F(off_5E9AC0[2]); }
    //       off_5E9AC0[0] = dword_8D3F5C; off_5E9AC0[1] = dword_8D3F60; off_5E9AC0[2] = dword_8D3F64;
    //     } else {
    //       sub_58AA6F(dword_8D3F5C); sub_58AA6F(dword_8D3F60); sub_58AA6F(dword_8D3F64);
    //       dword_8D3F5C = dword_8D3F60 = dword_8D3F64 = 0;
    //       off_5E9AC0[0] = MallocWrapperForNhMalloc(2); if (!off_5E9AC0[0]) return -1;
    //       sub_58FCA0(off_5E9AC0[0]);
    //       off_5E9AC0[1] = MallocWrapperForNhMalloc(2); if (!off_5E9AC0[1]) return -1; *(char*)off_5E9AC0[1] = 0;
    //       off_5E9AC0[2] = MallocWrapperForNhMalloc(2); if (!off_5E9AC0[2]) return -1; *(char*)off_5E9AC0[2] = 0;
    //     }
    //     byte_5E6BD8 = *(char*)*off_5E9AC0;
    //     dword_5E6BDC = 1;
    //     return 0;
    //   }
    // UNRESOLVED: The ABI legacy name Audio_Codec_Buffer_Allocation suggests an audio codec role, while the raw source (locale query indices 0xE/0xF/0x10 and digit conversion) indicates CRT locale number-formatting initialization; the two interpretations conflict.
    // UNRESOLVED: Exact semantics of sub_5968F6 (presumed GetLocaleInfo-style query), sub_58AA6F (presumed free) and sub_58FCA0 (buffer initialization) are not established here.
    // UNRESOLVED: word_5BEB48 is listed in the packet globals but never referenced by the raw source of this function; its role here is unknown.
    // UNRESOLVED: Constant 0xE, 0xF, 0x10 are treated as LCTYPE-style indices by DERIVED analysis but are not labeled by the raw source.
}
