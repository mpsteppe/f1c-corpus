// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460770
// Canonical corpus name: HashChecksumComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashChecksumComputation_00460770.c

void UnknownObject::HashChecksumComputation()
{
    // Computes an affine hash checksum from two byte inputs, a global seed dword_7C56B8, and two constants; result is returned as int.
    // CALCULATION: Reads global dword_7C56B8 and adds it into the running checksum. [global:0x007C56B8, source:raw]
    // CALCULATION: Forms the checksum 304444136 * a1 - 79767 * a2 + dword_7C56B8 + 468717489. [source:raw]
    // RETURN: Returns the computed checksum as int. [source:raw]

    // Conservative worker pseudocode:
    //   return 304444136 * a1 - 79767 * a2 + dword_7C56B8 + 468717489;
}
