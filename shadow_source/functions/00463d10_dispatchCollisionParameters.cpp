// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463D10
// Canonical corpus name: CollisionParameterDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionParameterDispatch_00463d10.c

void UnknownObject::dispatchCollisionParameters()
{
    // Loads a collision parameter from the global dbl_8AFEA0, then calls CollisionStateUpdate passing that value, an opaque argument a2, and the float at the vehicle-indexed offset (unk_5F0708 base + 4656*a1), where a1 selects a vehicle slot. Always returns 1.
    // ASSIGNMENT: Load dbl_8AFEA0 into a float local (the double constant is read through its LODWORD). [global:0x008AFEA0, source:raw]
    // CALL: Call CollisionStateUpdate(LODWORD(dbl_8AFEA0), a2, float at unk_5F0708 + 4656*a1), forwarding the loaded parameter plus the two call arguments. [callee:0x00500010, global:0x008AFEA0, source:raw]
    // RETURN: Return constant 1 (success). [source:raw]

    // Conservative worker pseudocode:
    //   param = dbl_8AFEA0;
    //   CollisionStateUpdate((int)param, a2, vehicle[4656*a1].collisionParam);
    //   return 1;
    // UNRESOLVED: The array base unk_5F0708 is not present in the packet's allowed evidence refs; only the 4656 stride is derived from the raw source, so the vehicle-slot interpretation is a GUESS.
    // UNRESOLVED: Semantics of a2 and of the float passed to CollisionStateUpdate are unknown.
    // UNRESOLVED: dbl_8AFEA0 is typed double but consumed through LODWORD as a float; the intended numeric meaning is unresolved.
    // UNRESOLVED: CollisionStateUpdate at 0x00500010 has no source or signature evidence in this packet.
}
