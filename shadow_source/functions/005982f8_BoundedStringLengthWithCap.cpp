// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005982F8
// Canonical corpus name: BoundedStringLengthWithCap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedStringLengthWithCap_005982f8.c

void UnknownObject::BoundedStringLengthWithCap()
{
    // Scans the byte string at a1 for a NUL terminator, reading at most a2 bytes. Returns the string length (pointer difference) when a terminator is found, or the cap a2 cast to a pointer when the scan exhausts the cap without a NUL. On-frame-path bounded string-length helper.
    // GUARD: If the cap a2 is zero, skip the scan loop entirely. [source:raw]
    // LOOP: Scan up to a2 bytes from a1 for a NUL terminator, breaking on NUL or when the cap is exhausted (countdown v3 seeded from a2 - 1). [field:this:0x00000000, source:raw]
    // RETURN: If a NUL terminator was found, return the string length (v2 - a1). [field:this:0x00000000, source:raw]
    // RETURN: If the scan reached the cap without a NUL (term at *v2 nonzero), return the cap value a2 cast to a pointer. [source:raw]
    // CALL: Called by sub_591FA1 (0x00591FA1) and sub_59807B (0x0059807B). [caller:0x00591FA1, caller:0x0059807B, source:raw]

    // Conservative worker pseudocode:
    //   _BYTE* sub_5982F8(_BYTE* s, int cap) {
    //     _BYTE* p = s;
    //     int n = cap - 1;
    //     if (cap) {
    //       do { if (!*p) break; ++p; } while (n--);
    //     }
    //     return *p ? (_BYTE*)cap : (p - s);
    //   }
    // UNRESOLVED: The cap-exceeding return is the integer a2 cast to a pointer; callers likely compare it against a1 to detect truncation.
    // UNRESOLVED: The prelabel getter template (DERIVED: 'returns field 0x0, no side effects') does not match the raw source, which is a bounded NUL scan; the raw source is authoritative here.
}
