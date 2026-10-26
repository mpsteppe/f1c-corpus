// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7D90
// Canonical corpus name: CallWrapper_7d90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CallWrapper_7d90_004d7d90.c

void UnknownObject::InitSlotArrayGlobal()
{
    // Thin wrapper over InitializeSlotArray (004D7AD0): passes the address of global dword_8AD264 as the slot array base and returns the initializer's _DWORD* result unchanged. Reads dword_8AD264 without writing it.
    // CALL: Call InitializeSlotArray (abi lead Call_FUN_004d7ad0) with the address of global dword_8AD264 as the slot array base; dword_8AD264 is read for its address [abi:lead, global:0x008AD264, source:raw]
    // RETURN: Return the _DWORD* result produced by InitializeSlotArray [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* InitSlotArrayGlobal() {
    //       return InitializeSlotArray((_DWORD*)&dword_8AD264);
    //   }
    // UNRESOLVED: dword_8AD264 is read only for its address here; its size and slot layout are not recorded in this packet
    // UNRESOLVED: No static callers are recorded, so the call site that triggers this initialization is unknown
}
