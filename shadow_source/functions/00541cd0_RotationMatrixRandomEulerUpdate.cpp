// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541CD0
// Canonical corpus name: UtilityFunction_1cd0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_1cd0_00541cd0.c

void UnknownObject::RotationMatrixRandomEulerUpdate()
{
    // Two-step rotation helper: first calls RandomRotationMatrixFromEulerAngles(a4, a5, a6) to build a random rotation matrix from three Euler-angle floats (return value ignored), then calls OrientationRotationMatrixUpdate(a1, a2, a3) and returns its result. Widely called from camera, car-selection, scene-loader and sound paths.
    // CALL: RandomRotationMatrixFromEulerAngles(a4, a5, a6) builds a random rotation matrix from three Euler-angle float arguments; its return value is ignored. [callee:0x00541DB0, source:raw]
    // CALL: OrientationRotationMatrixUpdate(a1, a2, a3) updates an orientation/rotation matrix from three float arguments; its result becomes this function's return value. [callee:0x00541D10, source:raw]
    // RETURN: Returns the OrientationRotationMatrixUpdate result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_541CD0(int a1, int a2, float a3, float a4, float a5, float a6) {
    //     RandomRotationMatrixFromEulerAngles(a4, a5, a6);
    //     return OrientationRotationMatrixUpdate(a1, a2, a3);
    //   }
    // UNRESOLVED: Meaning of a1, a2, a3 for OrientationRotationMatrixUpdate and of a3/a4/a5/a6 float split between the two callees is unknown.
    // UNRESOLVED: Where the random rotation matrix produced by the first call is stored is not visible from this function.
    // UNRESOLVED: The wide caller set (camera, car selection, scene loading, sound) suggests a shared orientation utility, but the owning object is unknown.
}
