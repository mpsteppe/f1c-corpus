// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005000C0
// Canonical corpus name: PassthroughWrapper_00c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PassthroughWrapper_00c0_005000c0.c

void UnknownObject::AudioParameterInterpolationWrapper()
{
    // Forwarding wrapper for the audio parameter interpolation routine. Passes a1 (float), a2 and a3 (int) plus the constant 0.0 to AudioParameterInterpolation (0x004FF680) and returns its char result unchanged.
    // CALL: Calls AudioParameterInterpolation(a1, a2, a3, 0.0), forwarding the three arguments and appending the constant 0.0 as a fourth argument. [callee:0x004FF680, source:raw]
    // RETURN: Returns the char result of the forwarded call unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_5000C0(float a1, int a2, int a3) {
    //       return AudioParameterInterpolation(a1, a2, a3, 0.0);
    //   }
    // UNRESOLVED: The role of the constant fourth argument 0.0 to AudioParameterInterpolation (interpolation factor/target) is not grounded in this packet.
    // UNRESOLVED: Owner is UnknownObject; the single caller sub_4B9AC0 (0x004B9AC0) is not analyzed.
}
