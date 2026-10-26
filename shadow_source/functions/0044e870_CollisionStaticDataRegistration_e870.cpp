// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E870
// Canonical corpus name: CollisionStaticDataRegistration_e870
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionStaticDataRegistration_e870_0044e870.c

void UnknownObject::CollisionStaticDataRegistration_e870()
{
    // Minimal wrapper: returns BooleanToIntConversion((int)nullsub_186). The nullsub_186 global (a stub function pointer at 0x0044E880) is read, cast to an integer, and passed to the BooleanToIntConversion helper, whose normalized result is returned directly. The canonical/abi name suggests a collision static-data registration, but the stub target has no body to analyze.
    // CALL: Read the nullsub_186 function pointer at 0x0044E880, cast it to an int, and pass it as the argument to BooleanToIntConversion. [source:raw, global:0x0044E880, callee:0x00587B3E]
    // RETURN: Return the integer produced by BooleanToIntConversion. [source:raw, callee:0x00587B3E]

    // Conservative worker pseudocode:
    //   int CollisionStaticDataRegistration_e870() {
    //     return BooleanToIntConversion((int)nullsub_186);
    //   }
    // UNRESOLVED: nullsub_186 is an empty stub (its target contains no executable body); the static data handler it would register is unrecoverable from this packet.
    // UNRESOLVED: The registration role is carried only by the canonical/abi name (LEGACY trust); no caller or field evidence grounds which static collision data is being registered.
}
