// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404FE0
// Canonical corpus name: OneTimeInitializationWithAtexitStyleRegistration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OneTimeInitializationWithAtexitStyleRegistration_00404fe0.c

void UnknownObject::OneTimeInitializationWithAtexitStyleRegistration()
{
    // One-time static singleton initializer. Guards on the bit-0 init gate byte_5EA4E0: on first call it sets the gate bit, constructs a generic vtable-backed object into the static buffer unk_5EA440, and runs the load-path wrapper registration through BooleanToIntConversion. Every call returns the static buffer handle &unk_5EA440.
    // GUARD: Check init gate byte_5EA4E0 bit 0; when clear, the one-time initialization block runs. [global:0x005EA4E0, source:raw]
    // ASSIGNMENT: Set the initialized bit of the gate: byte_5EA4E0 |= 1. [global:0x005EA4E0, source:raw]
    // CALL: Construct a generic vtable-backed object into the static buffer unk_5EA440 via GenericObjectConstructorWithVTable. [callee:0x00406AB0, global:0x005EA440, source:raw]
    // CALL: Register the load-path wrapper InitLoadPathWrapper through BooleanToIntConversion. [callee:0x00587B3E, global:0x00405020, source:raw]
    // RETURN: Return the static buffer handle &unk_5EA440. [global:0x005EA440, source:raw]

    // Conservative worker pseudocode:
    //   void *sub_404FE0() {
    //     if (!(byte_5EA4E0 & 1)) {
    //       byte_5EA4E0 |= 1;
    //       GenericObjectConstructorWithVTable(&unk_5EA440);
    //       BooleanToIntConversion(InitLoadPathWrapper);
    //     }
    //     return &unk_5EA440;
    //   }
    // UNRESOLVED: Semantics of the BooleanToIntConversion(InitLoadPathWrapper) atexit-style registration are not grounded by the raw source.
    // UNRESOLVED: unk_5EA440 is an untyped static buffer; the concrete object type is unknown.
    // UNRESOLVED: Callers (settings, allocation, deserialization, file-load paths) share the singleton but their specific uses are outside this function.
}
