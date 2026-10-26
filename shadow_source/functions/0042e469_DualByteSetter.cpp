// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E469
// Canonical corpus name: sub_42E469
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_42E469_0042e469.c

void UnknownObject::DualByteSetter()
{
    // Convenience setter: writes the same byte value a2 into two consecutive byte fields at offsets 0x1D and 0x1E of the object, then returns the object pointer unchanged. Likely sets a pair of related state/flag bytes together.
    // ASSIGNMENT: Write byte a2 into the field at offset 0x1D (byte at result + 29). [field:this:0x0000001D, source:raw]
    // ASSIGNMENT: Write byte a2 into the field at offset 0x1E (byte at result + 30). [field:this:0x0000001E, source:raw]
    // RETURN: Return the original object pointer (result) unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_42E469(int obj, char value) {
    //     *(char *)(obj + 29) = value;
    //     *(char *)(obj + 30) = value;
    //     return obj;
    //   }
    // UNRESOLVED: Identity and purpose of the object are unknown; existing analysis suggests a pair of related flags or state bytes.
    // UNRESOLVED: No static path from the tick root reaches this function, so its call context is unknown.
}
