// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466300
// Canonical corpus name: StateInitializerWithFlagCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateInitializerWithFlagCheck_00466300.c

void UnknownObject::VehicleScenePostInit()
{
    // Post-initialization pass run after a scene load for a vehicle. Resets field 0x124 to the float -1.0 (packet literal 18446744072627421184 / -1082130432) as a disabled sentinel, calls CUBESceneLoaderEntry() and FieldSetterCall(2), runs two update helpers sub_466350 and sub_466650 on this, then conditionally calls sub_541CA0(1) when the flag at field 0xEC is non-zero. Always returns 0.
    // ASSIGNMENT: Write this[73] = -1082130432, the bit pattern of -1.0f, to field 0x124; used as a disabled/reset sentinel [field:this:0x00000124, source:raw]
    // CALL: CUBESceneLoaderEntry() invoked with no arguments as part of post-load scene wiring [callee:0x0048E8D0, source:raw]
    // CALL: FieldSetterCall(2) sets a field/state with literal argument 2 [callee:0x004988A0, source:raw]
    // CALL: sub_466350(this) runs a position/velocity update helper on the scene state object [callee:0x00466350, source:raw]
    // CALL: sub_466650(this) runs a secondary physics/state update helper on the scene state object [callee:0x00466650, source:raw]
    // GUARD: Read flag at this[59] (field 0xEC); if non-zero the conditional init below runs, otherwise it is skipped [field:this:0x000000EC, source:raw]
    // CALL: sub_541CA0(1) extra initialization called only when the flag at field 0xEC is set; argument 1 [callee:0x00541CA0, field:this:0x000000EC, source:raw]
    // RETURN: Return 0 (success indicator); invoked by VehicleSceneLoadAndPositionTires (004681B0) during vehicle scene setup [function:0x00466300, caller:0x004681B0, source:raw]

    // Conservative worker pseudocode:
    //   this[0x124/4] = -1082130432;   // -1.0f disabled sentinel
    //   CUBESceneLoaderEntry();
    //   FieldSetterCall(2);
    //   sub_466350(this);
    //   sub_466650(this);
    //   if (this[0xEC/4]) sub_541CA0(1);
    //   return 0;
    // UNRESOLVED: The meaning of the flag at field 0xEC (which condition gates the sub_541CA0 call) is not established by this packet
    // UNRESOLVED: The interpretation of field 0x124 as a disabled timer is a skeleton-fill suggestion, not independently verified here
    // UNRESOLVED: What sub_466350, sub_466650, and sub_541CA0(1) mutate internally is outside this packet's scope
}
