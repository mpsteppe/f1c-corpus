// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464AE0
// Canonical corpus name: CharacterRangeCheckWithSignFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharacterRangeCheckWithSignFlag_00464ae0.c

void UnknownObject::CharacterRangeCheckWithSignFlag()
{
    // Loads the byte at this[a2]; returns true iff the byte has its sign bit clear (v3 >= 0) and its 0x7F-masked value is >= a3. Single caller is EntityVisibilityGridManager (0x00465460); the byte array likely holds a character/text buffer, but the owning object is not identified by the packet.
    // ASSIGNMENT: Read the byte at index a2 of the this byte array into v3. [source:raw]
    // GUARD: Require v3's sign bit to be clear (v3 >= 0). [source:raw]
    // CALCULATION: Mask v3 with 0x7F and compare the resulting value against threshold a3. [source:raw]
    // RETURN: Return true iff both the sign-bit guard and the 0x7F-masked range check against a3 pass. [source:raw]

    // Conservative worker pseudocode:
    //   bool CharacterRangeCheckWithSignFlag(byte* bytes, int index, int minValue) {
    //       char value = bytes[index];
    //       return value >= 0 && (value & 0x7F) >= minValue;
    //   }
    // UNRESOLVED: Which character/text buffer the this byte array represents is unknown; the only caller evidence is EntityVisibilityGridManager (0x00465460).
    // UNRESOLVED: Meaning of threshold a3 (minimum masked value) is unproven.
}
