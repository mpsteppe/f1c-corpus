// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004084A0
// Canonical corpus name: ShortComputation_84a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_84a0_004084a0.c

void UnknownObject::ShortComputation_84a0()
{
    // No-argument cdecl reader that returns the double-precision value stored at the global dbl_8AFE90 (0x008AFE90). Read-only accessor; it performs no computation or side effects. Called from camera-related paths.
    // RETURN: Load the double value at global dbl_8AFE90 (0x008AFE90) and return it as the function result. [global:0x008AFE90, source:raw]
    // UNKNOWN: Consumed by camera-related code paths: sub_4085F0 (0x004085F0), CameraModeViewportUpdate (0x00409A00), CameraShake (0x0040ADB0) and CameraTransformComputation (0x0040B710), suggesting a camera configuration constant. [caller:0x004085F0, caller:0x00409A00, caller:0x0040ADB0, caller:0x0040B710, source:raw]

    // Conservative worker pseudocode:
    //   double ShortComputation_84a0() {
    //     return dbl_8AFE90;
    //   }
    // UNRESOLVED: Meaning and initializer of the global dbl_8AFE90 are unknown; the read-only accessor pattern suggests it is a shared configuration constant.
    // UNRESOLVED: Why the value is stored as a double and which camera property it feeds are not evidenced by the packet.
    // UNRESOLVED: The proposed name carries no semantic weight beyond 'reads a global float'.
}
