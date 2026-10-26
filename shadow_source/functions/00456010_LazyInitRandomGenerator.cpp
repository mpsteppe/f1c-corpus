// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456010
// Canonical corpus name: UtilityFunction_6010
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_6010_00456010.c

void UnknownObject::LazyInitRandomGenerator()
{
    // One-time module initialization followed by delegation to a random-number generator entry. When the module-global flag byte_7CD1FC is zero, builds a value with sub_5896EE(0), stores it through TLSFieldSetter, and sets the flag to 1. Always finishes by delegating to the random generator entry rendered as RandLCGRandomNumberGenerator(this).
    // GUARD: If byte_7CD1FC is zero, run the one-time initialization block [global:0x007CD1FC, source:raw]
    // CALL: sub_5896EE(0) produces a value used to initialize the TLS-backed field [callee:0x005896EE, source:raw]
    // CALL: TLSFieldSetter(v1) stores the produced value into the thread-local/global field [callee:0x005884E0, source:raw]
    // ASSIGNMENT: Set byte_7CD1FC = 1 to mark the initialization as done [global:0x007CD1FC, source:raw]
    // CALL: Delegate to the random-number generator entry rendered as RandLCGRandomNumberGenerator(this); the resolved target is not present in the deterministic callee facts [function:0x00456010, source:raw]
    // CALL: Invoked by CollisionResponseWithRandomPerturbation (00457A00) as the source of random perturbation in collision response [caller:0x00457A00, source:raw]

    // Conservative worker pseudocode:
    //   if (!byte_7CD1FC) {
    //     v1 = sub_5896EE(0);
    //     TLSFieldSetter(v1);
    //     byte_7CD1FC = 1;
    //   }
    //   return RandLCGRandomNumberGenerator(this);
    // UNRESOLVED: RandLCGRandomNumberGenerator appears in the raw source but is absent from the deterministic callee list; its resolved target address could not be confirmed
    // UNRESOLVED: The owner (this) is an unknown object passed only to the random generator delegation
    // UNRESOLVED: byte_7CD1FC is flagged DERIVED as RandomInit_Flag elsewhere in the corpus, but that name is not part of this packet's evidence
}
