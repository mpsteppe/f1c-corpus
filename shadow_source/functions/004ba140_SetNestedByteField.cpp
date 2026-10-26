// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA140
// Canonical corpus name: ArithmeticComparison_a140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_a140_004ba140.c

void UnknownObject::SetNestedByteField()
{
    // Loads the pointer stored at this+8, writes the byte argument a2 into the nested struct's byte field at offset 3960 (0xF80) relative to that pointer, and returns the intermediate pointer. Unconditional write; the field is likely a per-object flag or state byte for an AI behavior, set by AIBehaviorInitialization.
    // ASSIGNMENT: Load the target data-struct pointer from this+8 into result. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write byte a2 into the nested struct field at offset 3960 (0xF80) relative to the loaded pointer. [field:this:0x00000F80, source:raw]
    // RETURN: Return the intermediate pointer loaded from this+8. [function:0x004BA140, source:raw]

    // Conservative worker pseudocode:
    //   int SetNestedByteField(_DWORD *this, char a2) {
    //     int result = this[2];
    //     *(BYTE *)(result + 3960) = a2;
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the byte written at offset 3960 (0xF80) and its enum values are unresolved; a2 is caller-supplied by AIBehaviorInitialization.
    // UNRESOLVED: Type of the object reached through this+8 is unknown; only a byte at 0xF80 relative to it is written.
}
