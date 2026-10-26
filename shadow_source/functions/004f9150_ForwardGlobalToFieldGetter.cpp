// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9150
// Canonical corpus name: ShortComputation_9150
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_9150_004f9150.c

void UnknownObject::ForwardGlobalToFieldGetter()
{
    // Thin no-argument wrapper: passes the global dword_8AFE64 as the argument to the field getter SimpleFieldGetter_bfc0 and returns its result. No local state. Called by MultiTableCoordinateSearch (0x004F9240).
    // CALL: Call SimpleFieldGetter_bfc0 with dword_8AFE64 as its argument. [global:0x008AFE64, source:raw]
    // RETURN: Return the getter's result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4F9150() {
    //       return SimpleFieldGetter_bfc0(dword_8AFE64);
    //   }
    // UNRESOLVED: Meaning of the global dword_8AFE64 unknown.
    // UNRESOLVED: Callee SimpleFieldGetter_bfc0 reads a field of its argument (see functions corpus); it is not listed in this packet's callees.
}
