// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005423C0
// Canonical corpus name: TwoFieldSetterCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldSetterCall_005423c0.c

void UnknownObject::TwoFieldSetterCall()
{
    // Small thiscall setter. Stores the first argument a2 into this+0x4 and the second argument a3 into this+0x8, then calls sub_542050 passing the two floats read from this+0x6C and this+0x70 together with the constant 1, and returns that call's result. No guards, no locals of interest.
    // ASSIGNMENT: Write a2 into this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write a3 into this+0x8. [field:this:0x00000008, source:raw]
    // CALL: Call sub_542050(this, float at this+0x6C, float at this+0x70, 1); the float arguments are the object's own fields and the last argument is the constant 1. [callee:0x00542050, field:this:0x0000006C, field:this:0x00000070, source:raw]
    // RETURN: Return the result of the sub_542050 call. [source:raw, function:0x005423C0]
    // CALL: Called by CameraModeViewportUpdate (00409a00), CameraShake (0040adb0), CameraTransformComputation (0040b710), CarSelectionStateMachine (00434460), sub_548AD0, sub_5550E0, sub_55A060, sub_560C10 and sub_560FE0 to store two fields and trigger the update call. [caller:0x00409A00, caller:0x0040ADB0, caller:0x0040B710, caller:0x00434460, caller:0x00548AD0, caller:0x005550E0, caller:0x0055A060, caller:0x00560C10, caller:0x00560FE0, source:raw]

    // Conservative worker pseudocode:
    //   char StoreTwoFieldsAndApply(int this, int a2, int a3) {
    //     *(this + 4) = a2;
    //     *(this + 8) = a3;
    //     return sub_542050(this, *(float*)(this + 0x6C), *(float*)(this + 0x70), 1);
    //   }
    // UNRESOLVED: The meaning of the two stored fields (this+0x4, this+0x8) and of the two float arguments (this+0x6C, this+0x70) depends on the enclosing camera/car-selection context, which this function does not reveal.
    // UNRESOLVED: The purpose of sub_542050 and the semantics of the constant 1 flag are external to this packet.
}
