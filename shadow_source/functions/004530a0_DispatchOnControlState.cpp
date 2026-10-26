// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004530A0
// Canonical corpus name: ShortComputation_30a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_30a0_004530a0.c

void UnknownObject::DispatchOnControlState()
{
    // Small thiscall dispatcher keyed on the control value *a2. When *a2 is 0, forwards to StructInitWithSubCall(this, a2[1], a3) and returns its result immediately. When *a2 is 1, calls sub_452B10(this, a2[1], a3 == 2); if that returns non-zero, returns DeviceObjectSelector(this, a2[1]). Otherwise returns *a2 - 1.
    // GUARD: Dispatch on *a2: a zero control value selects the initialization path, a value of 1 selects the compute-and-select path. [source:raw]
    // CALL: When *a2 == 0, call StructInitWithSubCall(this, a2[1], a3) and return its result immediately. [callee:0x004527E0, source:raw]
    // CALCULATION: Fallback result initialized to *a2 - 1; this is also the default return when neither dispatch branch fires. [source:raw]
    // GUARD: Only when *a2 == 1 does the compute-and-select branch execute. [source:raw]
    // CALL: Call sub_452B10(this, a2[1], a3 == 2), coercing the comparison a3 == 2 into a boolean third argument. [callee:0x00452B10, source:raw]
    // GUARD: The device-selection step only runs when sub_452B10 returned non-zero. [callee:0x00452B10, source:raw]
    // CALL: When the sub_452B10 result is non-zero, return DeviceObjectSelector(this, a2[1]). [callee:0x00452810, source:raw]
    // RETURN: Return the computed result (the initialization call result, the selector result, or *a2 - 1). [function:0x004530A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4530A0(int *this, _DWORD *a2, int a3) {
    //     if (!*a2)
    //       return StructInitWithSubCall(this, a2[1], a3);
    //     int result = *a2 - 1;
    //     if (*a2 == 1) {
    //       result = sub_452B10(this, a2[1], a3 == 2);
    //       if (result)
    //         return DeviceObjectSelector(this, a2[1]);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the control values in a2[0] (0 = init, 1 = compute-and-select) and the payload a2[1] is not established by this packet.
    // UNRESOLVED: Why the a3 == 2 comparison is coerced to a boolean for sub_452B10 is unknown.
    // UNRESOLVED: The owning object and the device-selection domain are unidentified.
}
