// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7C50
// Canonical corpus name: PhysicsVectorGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsVectorGetter_004c7c50.c

void UnknownObject::getPhysicsVector()
{
    // Forwards to sub_4C7E80 with the address of the global float flt_8AC4B0 and returns the callee's result.
    // CALL: Call sub_4C7E80, passing the address of the global float flt_8AC4B0 at 0x008AC4B0. [source:raw, function:0x004C7C50, global:0x008AC4B0]
    // RETURN: Return whatever sub_4C7E80 returned. [function:0x004C7C50, source:raw]

    // Conservative worker pseudocode:
    //   int getPhysicsVector()
    //   {
    //       return sub_4C7E80(&flt_8AC4B0);
    //   }
    // UNRESOLVED: Raw source calls sub_4C7E80, but the packet lists no callees, so the callee's identity and contract are unknown.
    // UNRESOLVED: flt_8AC4B0 is read as a float, but the packet carries no type contract beyond the ABI lead name.
}
