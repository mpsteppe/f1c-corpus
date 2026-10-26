// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589DB0
// Canonical corpus name: sub_589DB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589DB0_00589db0.c

void UnknownObject::FindByteInString()
{
    // strchr-like scan: searches the byte string a1 for the byte value a2, returning a pointer to the first match or NULL. Uses an unaligned byte-wise head scan, then an aligned DWORD scan with a 0x81010100 zero-byte detection trick and a per-byte tail check. The template prelabel ('getter, field 0x0 of this') is contradicted by the raw source, which is cdecl with (a1, a2) string/byte arguments and no `this`; the raw source wins.
    // GUARD: If the low two bits of a1 are nonzero (pointer not 4-byte aligned), take the unaligned byte-scan path. [source:raw]
    // LOOP: Unaligned head scan: reads one byte at a time, advancing v2, until a byte equals a2, a NUL byte is found, or the pointer becomes 4-byte aligned. [source:raw]
    // GUARD: If the scanned byte equals a2, return a pointer one position back (v2 - 1). [source:raw]
    // GUARD: If the scanned byte is zero (end of string), return NULL. [source:raw]
    // CALCULATION: Builds a 32-bit pattern with a2 replicated in all four bytes: v4 = ((a2 << 8) | a2 | (((a2 << 8) | a2) << 16)) XOR *(DWORD*)v2, and computes v5 = *(DWORD*)v2 + 2130640639 and v6 = v5 XOR ~*(DWORD*)v2 for the zero-byte test. [source:raw]
    // LOOP: Aligned scan: reads one DWORD per iteration (v2 += 4); breaks when the hasless test (((v4 + 2130640639) XOR ~v4) & 0x81010100) != 0 signals a zero byte in the word, or returns NULL when v6's 0x81010100 bits indicate an early NUL. [source:raw]
    // GUARD: Low byte of the DWORD equals a2: match found, breaks to the tail check. [source:raw]
    // GUARD: Low byte is zero: return NULL. [source:raw]
    // GUARD: Second byte of the DWORD equals a2: return v2 - 3 (pointer to that byte). [source:raw]
    // GUARD: Second byte is zero: return NULL. [source:raw]
    // GUARD: Third byte of the DWORD equals a2: return v2 - 2. [source:raw]
    // GUARD: Third byte is zero: return NULL. [source:raw]
    // GUARD: Fourth byte equals a2: return v2 - 1. [source:raw]
    // GUARD: Fourth byte is zero: return NULL. [source:raw]
    // RETURN: Returns v2 - 4 when the aligned loop exits without a match or NUL, and NULL on any NUL byte. [source:raw]

    // Conservative worker pseudocode:
    //   for (p = a1; (int)p & 3; p++) { if (*p == a2) return p; if (*p == 0) return NULL; }
    //   pattern = a2 replicated across 4 bytes;
    //   while (1) { w = *(DWORD*)p; if (hasnullbyte(w ^ pattern)) break; if (nullbyte_detected_early(w)) return NULL; p += 4; }
    //   return byte-level scan of final DWORD (offsets v2-4, v2-3, v2-2, v2-1).
    // UNRESOLVED: Constant 2130640639 in the aligned word test is preserved verbatim from the raw source; its derivation is not asserted.
    // UNRESOLVED: Template prelabel claimed a getter over field this+0x0 with no side effects; the raw source is a cdecl byte-scan (a1, a2), so that reading is rejected and the field evidence is parked.
}
