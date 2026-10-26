// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463CA0
// Canonical corpus name: sub_463CA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_463CA0_00463ca0.c

void UnknownObject::processTeamRadioMessagesIfReady()
{
    // Guarded radio-message pump called by GamePostMainLoop (0x0042D8A0): when the state flag at +0x3FC4 of the dereferenced object is non-zero, calls sub_57A730 with literal 256 and then TeamRadioNetworkMessageProcessing with the object pointer, returning its result; otherwise returns the object primary pointer unchanged.
    // CALCULATION: Dereferences this (offset +0) to obtain the object primary pointer. [field:this:0x00000000, source:raw]
    // GUARD: Tests the state flag at +0x3FC4 of the dereferenced object; radio processing only runs while it is non-zero. [field:obj:0x00003FC4, source:raw]
    // CALL: Calls sub_57A730 with the literal 256 as its argument (typically a buffer request for message processing). [callee:0x0057A730, source:raw]
    // CALL: Calls TeamRadioNetworkMessageProcessing with the object primary pointer as its argument; its result becomes the return value. [source:raw]
    // RETURN: Returns the TeamRadioNetworkMessageProcessing result when the guard passes, otherwise the object primary pointer. [source:raw]

    // Conservative worker pseudocode:
    //   char* primary = *this;
    //   if (*(DWORD*)(primary + 16324))
    //   {
    //       sub_57A730(256);
    //       return (char*)TeamRadioNetworkMessageProcessing(primary);
    //   }
    //   return primary;
    // UNRESOLVED: The target address of TeamRadioNetworkMessageProcessing is not given in the packet; only its source-level name.
    // UNRESOLVED: The semantics of the state flag at +0x3FC4 are not established by this function alone.
}
