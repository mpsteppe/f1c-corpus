// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040F300
// Canonical corpus name: ModeDispatchedRenderPhysicsCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModeDispatchedRenderPhysicsCall_0040f300.c

void UnknownObject::ModeDispatchedRenderPhysicsCall()
{
    // Mode-dispatched physics/render helper on an owning object. Reads a mode selector from this[7] (offset 0x1C) and branches through jump table jpt_40F30B: for modes 0-5 it calls VehicleOrientationFromAngularVelocityIntegration with the float argument and returns its result; for mode 6 it calls sub_4F0430 with the same float argument and then WheelContactTransform with the sub-object pointer at this[8] (offset 0x20), returning the transform result; any other mode returns the raw mode value unchanged.
    // ASSIGNMENT: Load the mode selector from this[7] (byte offset 0x1C) into the switch variable result. [field:this:0x0000001C, source:raw]
    // GUARD: Switch dispatch on the mode value via jump table jpt_40F30B: cases 0-5 take the orientation-integration path, case 6 takes the wheel-contact path, and the default branch returns the raw mode value. [global:0x0040F360, source:raw]
    // CALL: Modes 0-5: call VehicleOrientationFromAngularVelocityIntegration(a2); its return value becomes this function's result. [callee:0x0045AE00, source:raw]
    // CALL: Mode 6: call sub_4F0430(a2) with the same float argument. [callee:0x004F0430, source:raw]
    // CALL: Mode 6: call WheelContactTransform(this[8]) where this[8] is the sub-object pointer at byte offset 0x20; its return value becomes this function's result. [callee:0x004EF180, field:this:0x00000020, source:raw]
    // RETURN: Return the dispatch result: the orientation-integration result for modes 0-5, the wheel-contact transform for mode 6, or the raw mode value on the default branch. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40F300(void* this, float a2) {
    //     int result = this[7];
    //     switch (result) {
    //       case 0: case 1: case 2: case 3: case 4: case 5:
    //         result = VehicleOrientationFromAngularVelocityIntegration(a2);
    //         break;
    //       case 6:
    //         sub_4F0430(a2);
    //         result = WheelContactTransform(this[8]);
    //         break;
    //       default:
    //         return result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantic meaning of mode values 0-6 and the identity of the owning object are unresolved.
    // UNRESOLVED: The type of the sub-object pointer at this[8] (offset 0x20) is unknown; WheelContactTransform's input contract is outside this function.
    // UNRESOLVED: Why SessionStructureCleanup reaches this render/physics dispatch is not established from this function alone.
}
