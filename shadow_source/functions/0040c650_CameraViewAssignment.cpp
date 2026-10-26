// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C650
// Canonical corpus name: CameraViewAssignment
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraViewAssignment_0040c650.c

void UnknownObject::CameraViewAssignment()
{
    // Assigns the camera view mode based on whether the target entity a2 matches the current vehicle occupant at VehiclePtrArray[CurrentVehicleIndex]+18580. On a match it re-applies the stored mode at this+0x14 through the action state machine and clears it to -1; otherwise modes 1-2 dispatch through the mode gate and any other mode clears the stored mode to -1. A mode-3 request gated on the player flag byte at dword_7C54E0+13388 drives the state machine to state 2 (same occupant) or state 5 (other) and stores 3 at this+0x14. Returns either the mode-gate dispatch result or the current vehicle pointer.
    // GUARD: Compare a2 against the current occupant id at VehiclePtrArray[CurrentVehicleIndex]+18580 to select the same-occupant branch. [global:0x007C54E4, global:0x007C54F0, source:raw]
    // GUARD: If the stored mode at this+0x14 is not -1, re-apply it through the action state machine. [field:this:0x00000014, source:raw]
    // CALL: GameActionStateMachine(this+0x14 mode, 0) transitions the camera action state using the stored mode with immediate flag 0. [callee:0x0040CDE0, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Clear the stored mode: this+0x14 = -1 (deactivate). [field:this:0x00000014, source:raw]
    // GUARD: Else branch: the requested mode at this+0xC is <= 2 (modes 1-2). [guard:0, field:this:0x0000000C, source:raw]
    // CALL: Dispatch modes 1-2 through the conditional mode gate with global gate check. [callee:0x0040C610, source:raw]
    // ASSIGNMENT: Else (requested mode outside 1-2): clear the stored mode this+0x14 = -1. [field:this:0x00000014, source:raw]
    // GUARD: Mode-3 handling guard: the requested mode at this+0xC == 3 and the player flag byte at dword_7C54E0+13388 is non-zero. [guard:1, field:this:0x0000000C, global:0x007C54E0, source:raw]
    // CALL: When a2 matches the current occupant, GameActionStateMachine(2, 0). [callee:0x0040CDE0, global:0x007C54E4, global:0x007C54F0, source:raw]
    // CALL: Otherwise GameActionStateMachine(5, 0). [callee:0x0040CDE0, source:raw]
    // ASSIGNMENT: Store mode 3 at this+0x14. [field:this:0x00000014, source:raw]
    // RETURN: Return the current vehicle pointer VehiclePtrArray[CurrentVehicleIndex]; when a2 differs from the occupant and the mode at this+0xC is <= 2, instead return the mode-gate dispatch result. [global:0x007C54E4, global:0x007C54F0, guard:0, field:this:0x0000000C, callee:0x0040C610, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == VehiclePtrArray[CurrentVehicleIndex]->occupant) { // +18580
    //     if (this->appliedMode != -1) {          // this+0x14
    //       GameActionStateMachine(this->appliedMode, 0);
    //       this->appliedMode = -1;
    //     }
    //   } else if (this->requestedMode <= 2) {    // this+0xC
    //     ConditionalModeDispatchWithGlobalGate(this);
    //   } else {
    //     this->appliedMode = -1;
    //   }
    //   if (this->requestedMode == 3 && *(byte*)(dword_7C54E0 + 13388)) {
    //     if (a2 == VehiclePtrArray[CurrentVehicleIndex]->occupant)
    //       GameActionStateMachine(2, 0);
    //     else
    //       GameActionStateMachine(5, 0);
    //     this->appliedMode = 3;
    //   }
    //   result = VehiclePtrArray[CurrentVehicleIndex];
    //   if (a2 != *(int*)(result + 18580)) {
    //     if (this->requestedMode <= 2)
    //       return ConditionalModeDispatchWithGlobalGate(this);
    //   }
    //   return result;
    // UNRESOLVED: Field this+0x48A0 is listed in the packet facts but is not accessed by the shown raw pseudocode; its role is unknown.
    // UNRESOLVED: Meaning of the state-machine constants 2 and 5 and of the immediate flag 0 is unknown.
    // UNRESOLVED: Identity of the this object (camera view controller) is unconfirmed; owner stays UnknownObject despite the LEGACY ABI label Camera_View_Assignment.
}
