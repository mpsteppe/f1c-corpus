// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046F490
// Canonical corpus name: ClearBufferAndInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ClearBufferAndInit_0046f490.c

void UnknownObject::ClearBufferAndInit()
{
    // stdcall helper. Builds a path for the caller-supplied value a1 via PathBuilderWithBackslash using a 256-byte local buffer, then appends a new vehicle-config entry to the linked list rooted at the global dword_7C73E8 by calling AddVehicleConfigEntryToLinkedList(&dword_7C73E8, (int)buffer, 0, 1). Returns that call's result.
    // CALL: Call PathBuilderWithBackslash(a1, 256) to construct a path string for a1 into the local 256-byte buffer v2. [callee:0x0046E600, source:raw]
    // CALL: Call AddVehicleConfigEntryToLinkedList(&dword_7C73E8, (int)v2, 0, 1) to add an entry built from the buffer into the linked list rooted at global dword_7C73E8. [callee:0x00433B60, global:0x007C73E8, source:raw]
    // RETURN: Return the result of AddVehicleConfigEntryToLinkedList. [source:raw]

    // Conservative worker pseudocode:
    //   int ClearBufferAndInit(void* a1) {
    //     _BYTE buffer[256];
    //     PathBuilderWithBackslash(a1, 256);
    //     return AddVehicleConfigEntryToLinkedList(&dword_7C73E8, (int)buffer, 0, 1);
    //   }
    // UNRESOLVED: The decompiler passes a1 to PathBuilderWithBackslash but the local v2 to AddVehicleConfigEntryToLinkedList; whether the built path lands in v2 or in a1 is ambiguous without caller evidence.
    // UNRESOLVED: Meaning of the trailing constants 0 and 1 passed to AddVehicleConfigEntryToLinkedList is unknown.
    // UNRESOLVED: Caller InputBindingDispatch_f4d0 provides context not present in this packet.
}
