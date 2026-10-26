// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CB00
// Canonical corpus name: CollisionSubsystemInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionSubsystemInit_0044cb00.c

void UnknownObject::CollisionSubsystemInit()
{
    // Vehicle/collision subsystem initializer: seeds two globals with default values (dword_7CCFDC at 0x007CCFDC set to 103, flt_7CCFE0 at 0x007CCFE0 set to 0.0) and then invokes GlobalInitializer() to run the shared initialization path. Returns void.
    // ASSIGNMENT: Seed global dword_7CCFDC (0x007CCFDC) with the decimal value 103. [global:0x007CCFDC, source:raw]
    // ASSIGNMENT: Seed global flt_7CCFE0 (0x007CCFE0) with the float value 0.0. [global:0x007CCFE0, source:raw]
    // CALL: Call GlobalInitializer() (present in raw source; no callee record is carried in this packet). [source:raw]
    // RETURN: Return void; no explicit value is produced. [source:raw, function:0x0044CB00]

    // Conservative worker pseudocode:
    //   void CollisionSubsystemInit() {
    //     dword_7CCFDC = 103;
    //     flt_7CCFE0 = 0.0;
    //     GlobalInitializer();
    //   }
    // UNRESOLVED: GlobalInitializer is invoked per raw source but has no callee evidence record; its target address and semantics are unknown from this packet.
    // UNRESOLVED: Meaning of the seeded values (103 for dword_7CCFDC, 0.0 for flt_7CCFE0) is unknown; 0x007CCFDC may be a subsystem configuration default and 0x007CCFE0 a float state field.
    // UNRESOLVED: The packet labels this CollisionSubsystemInit under the vehicle subsystem, but the owning class is not recorded.
}
