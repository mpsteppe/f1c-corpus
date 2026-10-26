// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553FA0
// Canonical corpus name: StateFieldSetWithChainedInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFieldSetWithChainedInit_00553fa0.c

void UnknownObject::StateFieldSetWithChainedInit()
{
    // Stores the second argument a2 into the receiver's first dword field (byte offset 0), then chains through sub_553FC0(0) and finally StateParameterSetterWithVirtualDeviceNotify(0), returning the latter's result. The intermediate sub_553FC0 return value is discarded. Called by AudioBufferFormatSetup (00541120), sub_5550E0 and sub_55CF50.
    // ASSIGNMENT: Write a2 into the receiver's first dword at byte offset 0 (*this = a2). [field:this:0x00000000, source:raw]
    // CALL: sub_553FC0(0) invoked after the store; its return value is ignored. [callee:0x00553FC0, source:raw]
    // CALL: StateParameterSetterWithVirtualDeviceNotify(0) invoked and its return value becomes the function result. [callee:0x00554610, source:raw]
    // RETURN: Return the result of StateParameterSetterWithVirtualDeviceNotify(0). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_553FA0(int* this, int a2) {
    //     *this = a2;
    //     sub_553FC0(0);
    //     return StateParameterSetterWithVirtualDeviceNotify(0);
    //   }
    // UNRESOLVED: Meaning of the literal 0 passed to both sub_553FC0 and StateParameterSetterWithVirtualDeviceNotify is unknown.
    // UNRESOLVED: The dependency between the stored field and the two chained calls (why they run after the store) is not established by this packet.
}
