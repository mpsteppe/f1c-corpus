// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004328E0
// Canonical corpus name: PathAccessor_28e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathAccessor_28e0_004328e0.c

void UnknownObject::FirstStringInArrayGetter()
{
    // Returns the first string of a string array: dereferences this to the array, then reads the first element (this[0][0]). If the first element is null, returns the address of the global byte_5EA438 default string instead. Invoked by PathDirectoryExtractionAndComparison (00433290).
    // ASSIGNMENT: Read the string array pointer from the field at this+0 (the this base), then load the first array element as the result string. [field:this:0x00000000, source:raw]
    // GUARD: Guard on the first string element at this[0][0]: when null, fall back to the global byte_5EA438 default string. [field:obj:0x00000000, global:0x005EA438, source:raw]
    // RETURN: Return the address of the global byte_5EA438 default string when the first element is null. [global:0x005EA438, source:raw]
    // RETURN: Return the non-null first string element otherwise. [source:raw]
    // CALL: Invoked by PathDirectoryExtractionAndComparison (00433290) to obtain the leading path/name string for directory comparison. [caller:0x00433290, source:raw]

    // Conservative worker pseudocode:
    //   char *sub_4328E0(char ***this) {
    //     char *result = **this;
    //     if (!result) return (char *)&byte_5EA438;
    //     return result;
    //   }
    // UNRESOLVED: Content and meaning of the global byte_5EA438 default string (e.g. default application directory) are DERIVED from caller context and not confirmed here.
    // UNRESOLVED: Termination and length of the string array behind this are not established by this function alone.
}
