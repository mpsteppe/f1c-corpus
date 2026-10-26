// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499F00
// Canonical corpus name: TwoChannel16BitReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoChannel16BitReader_00499f00.c

void UnknownObject::TwoChannel16BitReader()
{
    // Conditional two-channel 16-bit read. Calls ShortComputation_adb0(this + 108) and only proceeds when that result is greater than 2. Then performs two indexed reads through LinkedListIndexedFieldReader: channel index 0 writes two shorts to *a2/*a3, channel index 1 writes two shorts to *a4/*a5. Each pair of output writes is gated on the corresponding read returning nonzero.
    // CALL: Call ShortComputation_adb0(this + 108) to obtain a gating value. [callee:0x0049ADB0, source:raw]
    // GUARD: Guard: only proceed when the ShortComputation result is greater than 2. [callee:0x0049ADB0, source:raw]
    // CALL: First channel read: LinkedListIndexedFieldReader(0, &v8, &v9) fills two 16-bit locals. [callee:0x0049AEC0, source:raw]
    // GUARD: Guard: when the first channel read returns nonzero, publish its two shorts. [callee:0x0049AEC0, source:raw]
    // ASSIGNMENT: Publish first-channel values: *a2 = v8 and *a3 = v9. [source:raw]
    // CALL: Second channel read: LinkedListIndexedFieldReader(1, &v8, &v9) refills the two 16-bit locals. [callee:0x0049AEC0, source:raw]
    // GUARD: Guard: when the second channel read returns nonzero, publish its two shorts. [callee:0x0049AEC0, source:raw]
    // ASSIGNMENT: Publish second-channel values: *a4 = v8 and *a5 = v9. [source:raw]
    // RETURN: Return result, which after a successful second read is set to the address of a4 rather than a value from the reads. [source:raw]
    // CALL: Called by ConditionalMultiParamDispatch (0x004861A0) as the two-channel 16-bit reader variant. [caller:0x004861A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_499F00(char *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5) {
    //     __int16 v8, v9;
    //     int result = ShortComputation_adb0(this + 108);
    //     if (result > 2) {
    //       if (LinkedListIndexedFieldReader(0, &v8, &v9)) {
    //         *a2 = v8; *a3 = v9;
    //       }
    //       result = LinkedListIndexedFieldReader(1, &v8, &v9);
    //       if (result) {
    //         result = (int)a4; *a4 = v8; *a5 = v9;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Return value semantics are ambiguous: after a successful second read the function returns the a4 output pointer, otherwise it returns the initial ShortComputation result or the second read result.
    // UNRESOLVED: Meaning of the ShortComputation_adb0(this + 108) > 2 gate is unknown.
    // UNRESOLVED: Semantics of the two channels and the meaning of the two 16-bit values produced per channel are unknown.
}
