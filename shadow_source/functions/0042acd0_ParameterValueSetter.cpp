// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042ACD0
// Canonical corpus name: ParameterValueSetter
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/ParameterValueSetter_0042acd0.c

void F1CVehicle::ParameterValueSetter()
{
    // Sets the vehicle maxSpeed field (this+0x4538, CONFIRMED) from an int parameter. Parameter value 18 selects the idle/reverse speed target constant flt_8ACFB4; any other value is cast directly to float and stored. Called per frame from AICommandMessageQueueDispatcher (0x00424CD0), AIAbility (0x00429470) and CommandQueueResponseHandler (0x00429EE0). maxSpeed is recalculated every frame, so an external poke does not persist.
    // GUARD: Branch on the parameter value a2: the special idle-speed-target path is taken only when a2 == 18. [source:raw, abi:reviewed]
    // ASSIGNMENT: When a2 == 18: set maxSpeed at this+0x4538 to the idle/reverse speed target constant flt_8ACFB4 (read-only global). [field:this:0x00004538, global:0x008ACFB4, source:raw]
    // ASSIGNMENT: Otherwise: set maxSpeed at this+0x4538 to the raw parameter value cast to float ((float)a2). [field:this:0x00004538, source:raw, function:0x0042ACD0]

    // Conservative worker pseudocode:
    //   if (value == 18)
    //       vehicle->maxSpeed(0x4538) = flt_8ACFB4;
    //   else
    //       vehicle->maxSpeed(0x4538) = (float)value;
    // UNRESOLVED: What parameter id 18 denotes (an idle/reverse speed target) comes from the DERIVED global name for flt_8ACFB4 in prior analysis, not from this packet's raw source.
}
