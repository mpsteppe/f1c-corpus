// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464B40
// Canonical corpus name: FloatComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatComputation_00464b40.c

void UnknownObject::CollisionResponseDispatch()
{
    // Collision response dispatch: when the sensor float at this+0x71 is below a2+4, or the XOR of the flag byte at this+0x70 with a2+3 has any of bits 0-2 set, routes to VehicleOrientationFromEulerAngles (type field 7) or ArithmeticComparison_3a90 (type field 0) based on the collision-type field in a2, then clears 104 per-byte bit flags with BitFlagSetter. Called from sub_465300.
    // GUARD: Enter the response body when float at this+0x71 < float at a2+4, or when (byte at this+0x70 XOR byte at a2+3) AND 7 is non-zero. [field:this:0x00000071, field:this:0x00000070, source:raw]
    // CALCULATION: Extract the collision-type field from a2: (a2 >> 18) AND 0x3F. [source:raw]
    // GUARD: Only dispatch when the collision-type field is non-zero. [source:raw]
    // GUARD: Type field value 7 selects the Euler-angle orientation path. [source:raw]
    // CALL: When the type field equals 7, set vehicle orientation from the Euler angles at this+109 using the float at a2+4. [callee:0x004B2DD0, source:raw]
    // CALL: When the type field is zero, run the arithmetic comparison operation on a2. [callee:0x004B3A90, source:raw]
    // LOOP: Loop over 104 consecutive flag bytes beginning at this. [source:raw]
    // CALL: Clear each flag byte in the 104-byte range via BitFlagSetter(this + i, 0). [callee:0x004649F0, source:raw]
    // RETURN: Return the XOR comparison value computed by the guard (result). [source:raw]

    // Conservative worker pseudocode:
    //   char sub_464B40(int this, int a2) {
    //     char result;
    //     if (*(float *)(this + 113) < *(float *)(a2 + 4)
    //         || ((result = *(_BYTE *)(a2 + 3) ^ *(_BYTE *)(this + 112)) & 7) != 0) {
    //       if (((*(_DWORD *)a2 >> 18) & 0x3F) != 0) {
    //         if (((*(_DWORD *)a2 >> 18) & 0x3F) == 7)
    //           VehicleOrientationFromEulerAngles(this + 109, *(float *)(a2 + 4));
    //       } else {
    //         ArithmeticComparison_3a90(a2);
    //       }
    //       for (int i = 0; i < 104; i++)
    //         BitFlagSetter((_BYTE *)(i + this), 0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the collision-type field ((a2 >> 18) & 0x3F) and its values 0 and 7 is not established.
    // UNRESOLVED: What the 104 per-byte bit flags at this represent is unknown.
    // UNRESOLVED: Which bits BitFlagSetter clears (flag argument 0) is not resolved here.
}
