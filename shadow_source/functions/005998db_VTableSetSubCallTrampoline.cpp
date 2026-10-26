// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005998DB
// Canonical corpus name: TrampolineToFUN005998E5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrampolineToFUN005998E5_005998db.c

void UnknownObject::VTableSetSubCallTrampoline()
{
    // Thin __stdcall trampoline forwarding a1-a4 to VTableSetSubCall and returning its result unchanged.
    // CALL: Calls VTableSetSubCall with a1, a2, a3, a4. [source:raw, abi:lead]
    // RETURN: Returns the VTableSetSubCall result to the caller as an int. [source:raw]

    // Conservative worker pseudocode:
    //   int VTableSetSubCallTrampoline(int a1, int a2, int a3, int a4) {
    //       return VTableSetSubCall(a1, a2, a3, a4);
    //   }
    // UNRESOLVED: VTableSetSubCall callee address is not present in the packet.
    // UNRESOLVED: Read of byte_8D4568 is not visible in the raw source text.
}
