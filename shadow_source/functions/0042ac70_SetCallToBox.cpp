// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042AC70
// Canonical corpus name: AIStateFlagSetter
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/AIStateFlagSetter_0042ac70.c

void F1CVehicle::SetCallToBox()
{
    // Sets the vehicle AI callToBox flag (vehicle+0x454C) to the input value when it is 0 or 1; larger values are ignored. Returns the input unchanged. Called per-frame from the AI main update and related AI callbacks.
    // GUARD: Only performs the field write when a2 <= 1; values greater than 1 are silently ignored and the field keeps its prior value. [source:raw, field:this:0x0000454C]
    // ASSIGNMENT: this[4435] = a2 writes the callToBox flag at vehicle+0x454C (AI command_input) to 0 or 1. [field:this:0x0000454C, source:raw]
    // RETURN: Returns the input value a2 unchanged (result = a2). [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 <= 1)
    //       vehicle->CallToBox = a2;
    //   return a2;
}
