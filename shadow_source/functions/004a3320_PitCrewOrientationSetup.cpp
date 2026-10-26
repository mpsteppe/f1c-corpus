// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A3320
// Canonical corpus name: sub_4A3320
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A3320_004a3320.c

void UnknownObject::PitCrewOrientationSetup()
{
    // Sets up a pit-crew member's orientation. Guarded by activation field this[5] (offset +0x14); when non-zero the function converts Euler angles a3 into a rotation matrix (EulerToRotationMatrix), builds a 180-degree Y-axis rotation (RotationMatrixY with 3.1415927), forwards the three transform fields read from a2 via ThreeFieldSetterWithSubCall, applies the Y rotation to the orientation through sub_54B450, and sets the state flag this[2] (offset +0x8) to 2. Returns the activation-field value or the result of sub_54B450.
    // ASSIGNMENT: Read the activation guard into result: result = this[5] (offset +0x14). [field:this:0x00000014, source:raw]
    // GUARD: If this[5] (offset +0x14) is zero, skip the entire orientation setup and return immediately. [field:this:0x00000014, source:raw]
    // CALL: Convert Euler angles a3 into a rotation matrix stored in the local buffer v6 via EulerToRotationMatrix(a3, v6). [callee:0x00566E40, source:raw]
    // CALL: Build a 180-degree Y-axis rotation matrix (pi) into the local buffer v5 via RotationMatrixY(3.1415927, v5). [callee:0x00567400, source:raw]
    // CALL: Forward the three transform fields read from a2 (a2[0], a2[1], a2[2]) via ThreeFieldSetterWithSubCall. [callee:0x0054B3B0, source:raw]
    // CALL: Apply the Y-rotation matrix to the orientation: result = sub_54B450(v5[0], v5[1], v5[2]). [callee:0x0054B450, source:raw]
    // ASSIGNMENT: Set the state flag: this[2] (offset +0x8) = 2 after orientation setup. [field:this:0x00000008, source:raw]
    // RETURN: Return the guard value or the sub_54B450 result (activation field value when setup is skipped). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A3320(State* this, float* a2, float* euler) {
    //     int result = this->active;                 // this[5] / +0x14
    //     if (!result) return result;
    //     float matrix[9]; float yrot[3];
    //     EulerToRotationMatrix(euler, matrix);
    //     RotationMatrixY(3.1415927f, yrot);
    //     ThreeFieldSetterWithSubCall(a2[0], a2[1], a2[2]);
    //     result = sub_54B450(yrot[0], yrot[1], yrot[2]);
    //     this->state = 2;                           // this[2] / +0x8
    //     return result;
    //   }
    // UNRESOLVED: The function is called from pit-crew animation and AI-state paths (PitCrewAnimationLoader, AIStateMachineWithModeDispatch, PitStopReadyCheck), supporting a pit-crew orientation role, but the owning class is unidentified (abi is LEGACY Unidentified_Logic).
    // UNRESOLVED: Whether sub_54B450 writes the resulting orientation into a member of this (beyond the local v5) is not visible in the raw source.
    // UNRESOLVED: Whether a2 is a full transform (3 floats forwarded verbatim) or a position/heading vector feeding the rotation is unclear.
    // UNRESOLVED: The intermediate buffers v5/v6 are locals; the rotation-matrix layout and element order produced by EulerToRotationMatrix/RotationMatrixY are not shown.
}
