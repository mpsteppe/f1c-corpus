// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585E80
// Canonical corpus name: IndexToBitmaskConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexToBitmaskConversion_00585e80.c

void UnknownObject::IndexToBitmaskConversion()
{
    // Utility that converts a bit index into a bitmask byte pair: writes the byte offset (a1 >> 3) through output pointer a2, computes the single-bit mask 1 << (a1 & 7), stores that mask through output byte a3, and returns it. Callers such as sub_584230, sub_586800 and sub_586AA0 (e.g. the MultiBlockBitfieldEncoder bitmap loop) use it to map a linear bit index onto a caller-owned bitmap byte array.
    // ASSIGNMENT: Writes the byte offset of the bit: *a2 = a1 >> 3, i.e. the high bits of the bit index select the target byte within the caller's bitmap array [source:raw]
    // CALCULATION: Builds the single-bit mask: result = 1 << (a1 & 7), i.e. the low 3 bits of the bit index select the bit position inside the byte [source:raw]
    // ASSIGNMENT: Stores the computed mask into the output byte: *a3 = result [source:raw]
    // RETURN: Returns the bit mask byte; callers include sub_584230 (0x00584230), sub_586800 (0x00586800) and sub_586AA0 (0x00586AA0) [function:0x00585E80, caller:0x00584230, caller:0x00586800, caller:0x00586AA0, source:raw]

    // Conservative worker pseudocode:
    //   *a2 = a1 >> 3;
    //   result = (char)(1 << (a1 & 7));
    //   *a3 = result;
    //   return result;
    // UNRESOLVED: Whether a2/a3 point into a caller-owned bitmap byte array (suggested by a1 >> 3) is DERIVED from usage, not stated by packet facts
    // UNRESOLVED: The signed char return value and the *a3 output are the same mask, so callers may consume either
}
