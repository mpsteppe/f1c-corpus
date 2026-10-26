// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059994E
// Canonical corpus name: ThinForwardingWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThinForwardingWrapper_0059994e.c

void UnknownObject::VTableSetSubCallForwarder()
{
    // Thin __stdcall wrapper loading dword_8D4440 as the first VTableSetSubCall argument and forwarding a1-a4.
    // CALL: Calls VTableSetSubCall with dword_8D4440 as first argument plus forwarded a1-a4. [source:raw, global:0x008D4440]

    // Conservative worker pseudocode:
    //   void VTableSetSubCallForwarder(int a1, int a2, int a3, int a4) {
    //       VTableSetSubCall((char *)dword_8D4440, a1, a2, a3, a4);
    //   }
    // UNRESOLVED: VTableSetSubCall callee address is not present in the packet.
    // UNRESOLVED: Role of dword_8D4440 (likely a this-like pointer) is not independently confirmed.
}
