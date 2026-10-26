// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BD77
// Canonical corpus name: sub_58BD77
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BD77_0058bd77.c

void UnknownObject::DoubleIsNonNegative()
{
    // Returns TRUE when the double value pointed to by the argument is non-negative, FALSE otherwise. A minimal predicate comparing the 64-bit IEEE-754 value at offset +0 against the constant 0.0.
    // GUARD: Compare the double read from the argument pointer against the 0.0 boundary constant. [field:this:0x00000000, global:0x005B8CC8, source:raw]
    // RETURN: Return TRUE if the value is >= 0.0, otherwise return FALSE. [field:this:0x00000000, global:0x005B8CC8, function:0x0058BD77, source:raw]

    // Conservative worker pseudocode:
    //   return *valuePtr >= 0.0;
    // UNRESOLVED: The meaning of the caller context is unknown; the predicate may guard negative physical quantities (e.g. signed forces or deltas) but no caller is statically known.
}
