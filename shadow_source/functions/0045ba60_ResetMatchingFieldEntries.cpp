// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BA60
// Canonical corpus name: StringMatchingWithCaseSensitiveCaseInsensitiveMo
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringMatchingWithCaseSensitiveCaseInsensitiveMo_0045ba60.c

void UnknownObject::ResetMatchingFieldEntries()
{
    // Iterates the eight 92-byte struct entries beginning at this+15 dwords (this+0x3C). Each entry's leading string is compared with a2 — case-insensitively via sub_566810 when a3 is non-zero, case-sensitively via strcmp when a3 is zero — and on a match the whole entry is reset through PerIndexStructFieldResetter(this, index). No-op when a2 is null or empty.
    // GUARD: The matching loop only runs when a2 is non-null and strlen(a2) is non-zero [source:raw]
    // LOOP: Walk indices 0..7 over the eight 92-byte entries whose string base is v3+15 (this+15 dwords), advancing v5 by 92 bytes per iteration [source:raw]
    // GUARD: When a3 is non-zero the comparison is case-insensitive, evaluated as sub_566810(v5, a2) != 0 [callee:0x00566810, source:raw]
    // CALCULATION: When a3 is zero the comparison is case-sensitive, evaluated as strcmp(v5, a2) == 0 [source:raw]
    // CALL: On a match, PerIndexStructFieldResetter(v3, v4) resets the matched entry at the current index [callee:0x0045B430, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 && strlen(a2) != 0) {
    //     for (idx = 0; idx < 8; ++idx) {
    //       entry = (const char*)this + 15*4 + idx*92;
    //       match = a3 ? (sub_566810(entry, a2) != 0) : (strcmp(entry, a2) == 0);
    //       if (match)
    //         PerIndexStructFieldResetter(this, idx);
    //     }
    //   }
    // UNRESOLVED: sub_566810 is assumed to be a case-insensitive string comparison but its exact contract is not visible in this packet
    // UNRESOLVED: The type and layout of the 92-byte entries at this+0x3C are not defined by packet fields
    // UNRESOLVED: What PerIndexStructFieldResetter zeroes or restores inside a matched entry is not visible in this packet
}
