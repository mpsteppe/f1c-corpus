// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D0A0
// Canonical corpus name: sub_48D0A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_48D0A0_0048d0a0.c

void UnknownObject::CollisionStepperAndVtable43()
{
    // Collision position stepper wrapper. Reads a float through the pointer at this+0x40 via FloatFieldAccessor, passes it together with this to CollisionPositionStepper, then calls vtable entry 43 (offset 0xAC) on this. Linear, always returns 0.
    // ASSIGNMENT: Reads the float via FloatFieldAccessor from the pointer stored at this+0x40 into v3 [callee:0x00498730, field:this:0x00000040, source:raw]
    // CALL: Calls CollisionPositionStepper with this (cast to float pointer) and v3 [callee:0x0048CB00, field:this:0x00000000, source:raw]
    // CALL: Virtual dispatch through vtable entry 43 (offset 0xAC on obj) with this [field:obj:0x000000AC, field:this:0x00000000, source:raw]
    // RETURN: Returns 0 [function:0x0048D0A0, source:raw]

    // Conservative worker pseudocode:
    //   v3 = FloatFieldAccessor(*(float**)(this + 0x40));
    //   CollisionPositionStepper((float*)this, v3);
    //   (*(this->vtable[43]))(this);
    //   return 0;
    // UNRESOLVED: The exact transform applied by FloatFieldAccessor and the meaning of the float at this+0x40 (time, force or scale input to the stepper) are not independently confirmed; the canonical_name remains the raw sub_48D0A0
}
