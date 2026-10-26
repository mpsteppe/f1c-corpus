// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB100
// Canonical corpus name: ConstantReturnSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstantReturnSetter_004db100.c

void UnknownObject::FloatFourInitializer()
{
    // Thiscall constant-field initializer. Writes the raw float bit pattern 1082130432 (4.0f) into this[4], i.e. the dword at byte offset 0x10, and returns the same raw constant as the int result. No guards, no calls, no other field writes. Existing analysis labels this FloatFourInitializer.
    // ASSIGNMENT: Write 1082130432 (4.0f) into this[4], i.e. the dword at byte offset 0x10. [field:this:0x00000010, source:raw]
    // RETURN: Return the stored constant 1082130432 as the int result. [function:0x004DB100, source:raw]

    // Conservative worker pseudocode:
    //   int FloatFourInitializer(_DWORD *this) {
    //     this[4] = 1082130432; // 4.0f
    //     return 1082130432;
    //   }
    // UNRESOLVED: dword_5ACF5C is listed as a read global by the deterministic fact table but does not appear in the decompiled body; existing analysis notes the xref exists in the IDB without direct use in this function.
    // UNRESOLVED: The class owning the field at byte offset 0x10 is not identified; owner remains UnknownObject/UNKNOWN.
}
