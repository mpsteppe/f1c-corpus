// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059991F
// Canonical corpus name: ThunkToSub5998E5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToSub5998E5_0059991f.c

void UnknownObject::VTableSetSubCallThunk()
{
    // Thin __stdcall thunk loading dword_8D4400 as the first VTableSetSubCall argument and forwarding a1-a4.
    // CALL: Calls VTableSetSubCall with dword_8D4400 as first argument plus forwarded a1-a4. [source:raw, global:0x008D4400]

    // Conservative worker pseudocode:
    //   void VTableSetSubCallThunk(int a1, int a2, int a3, int a4) {
    //       VTableSetSubCall((char *)dword_8D4400, a1, a2, a3, a4);
    //   }
    // UNRESOLVED: VTableSetSubCall callee address is not present in the packet.
    // UNRESOLVED: Role of dword_8D4400 (likely a this-like pointer) is not independently confirmed.
}
