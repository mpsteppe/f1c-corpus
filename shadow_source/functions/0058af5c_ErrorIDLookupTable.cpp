// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058AF5C
// Canonical corpus name: ErrorIDLookupTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ErrorIDLookupTable_0058af5c.c

void UnknownObject::ErrorIDLookupTable()
{
    // CRT error-code mapper: stores the input OS error code a1 into the TLS slot returned by TLSOffsetGetter_afd8 (the _doserrno slot), then searches the DWORD-pair table starting at unk_5E65C0 and bounded by dword_5E6728 (error-code column at each entry, errno value at entry +4). On an exact match it writes the mapped errno via TLSOffsetGetter and returns the TLS pointer. On no match it applies range fallbacks: 0x13..0x24 -> errno 13, 0xBC..0xCA -> errno 8, otherwise errno 22, each written through TLSOffsetGetter.
    // CALL: Call TLSOffsetGetter_afd8() and store a1 (the input OS error code) into the returned TLS slot, preserving the original code before mapping. [callee:0x0058AFD8, source:raw]
    // LOOP: Scan the DWORD-pair lookup table: start v2 at unk_5E65C0 and advance two DWORDs per entry while v2 stays below the dword_5E6728 end bound, tracking the entry index in v1. [global:0x005E65C0, global:0x005E6728, source:raw]
    // GUARD: If the current entry's first DWORD (*v2, the error-code column) equals a1, the code is found in the table. [global:0x005E65C0, source:raw]
    // CALL: Call TLSOffsetGetter() and write dword_5E65C4[2 * v1] (the mapped errno, the entry +4 column of the matching row) into the returned TLS slot. [callee:0x0058AFCF, global:0x005E65C4, source:raw]
    // RETURN: Return the TLS slot pointer written with the mapped errno on the table-match path. [source:raw]
    // GUARD: If a1 is outside 0x13..0x24 and outside 0xBC..0xCA, call TLSOffsetGetter() and write errno 22 into the TLS slot. [callee:0x0058AFCF, source:raw]
    // GUARD: If a1 is in 0xBC..0xCA, call TLSOffsetGetter() and write errno 8 into the TLS slot. [callee:0x0058AFCF, source:raw]
    // GUARD: If a1 is in 0x13..0x24, call TLSOffsetGetter() and write errno 13 into the TLS slot. [callee:0x0058AFCF, source:raw]
    // RETURN: Return the TLS slot pointer written on the range-fallback path. [source:raw]

    // Conservative worker pseudocode:
    //   *TLSOffsetGetter_afd8() = a1;
    //   v2 = &unk_5E65C0;
    //   for (v1 = 0; (int)v2 < (int)dword_5E6728; v2 += 2, ++v1) {
    //       if (a1 == *v2) { *TLSOffsetGetter() = dword_5E65C4[2 * v1]; return TLSOffsetGetter(); }
    //   }
    //   if (a1 < 0x13 || a1 > 0x24) {
    //       if (a1 < 0xBC || a1 > 0xCA) { *TLSOffsetGetter() = 22; }
    //       else { *TLSOffsetGetter() = 8; }
    //   } else {
    //       *TLSOffsetGetter() = 13;
    //   }
    //   return TLSOffsetGetter();
    // UNRESOLVED: errno meanings of 13/8/22 come from existing analysis (EACCES, ENOEXEC-like, EINVAL); not independently verified within this packet.
    // UNRESOLVED: The exact TLS slot semantics of TLSOffsetGetter vs TLSOffsetGetter_afd8 live in those callees, outside this function body.
}
