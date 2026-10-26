// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465430
// Canonical corpus name: ShortComputation_5430
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_5430_00465430.c

void UnknownObject::StorePlayerControlFloat()
{
    // Computes a slot-based storage index as 560 * a1 + 140 (with a register-sourced third term), converts argument a2 to a value via BufferSizeLookup, and stores that value at the computed location through FloatStoreWithConversion, returning the store result. Called from NetCommPlayerSlotSync, suggesting a per-player-slot control value being synced from the network layer.
    // CALL: v2 = BufferSizeLookup(a2) converts/looks up argument a2 into the value that will be stored. [callee:0x00464E90, source:raw]
    // CALCULATION: Index expression 560 * a1 + v3 + 140: a 140-byte base within a 560-byte-stride per-slot structure selected by a1. [source:raw]
    // CALL: FloatStoreWithConversion(index, v2) stores value v2 at the computed location, applying its float/type conversion. [callee:0x00464A60, source:raw]
    // RETURN: Return the result of FloatStoreWithConversion. [source:raw]
    // STATE_TRANSITION: Invoked from NetCommPlayerSlotSync (0x0045FC50), implying the stored value participates in per-slot network synchronisation. [caller:0x0045FC50]

    // Conservative worker pseudocode:
    //   int __stdcall sub_465430(int a1, int a2) {
    //     int v2 = BufferSizeLookup(a2);
    //     return FloatStoreWithConversion(560 * a1 + v3 + 140, v2);
    //   }
    // UNRESOLVED: v3 (ecx) is read uninitialised in the decompiled source; it is likely a hidden __fastcall register parameter or this-pointer artifact of the original calling convention, and its value is undefined from this packet alone.
    // UNRESOLVED: The 560-byte stride per a1 slot and the +140 base are sourced from the packet's arithmetic but the array/object they address is not identified.
    // UNRESOLVED: Whether the stored operand is a float, integer bits, or converted between types depends on FloatStoreWithConversion's contract, which is not in this packet.
    // UNRESOLVED: The per-player-slot reading is inferred from the ABI lead name (Player_Control_Set) and the NetCommPlayerSlotSync caller; it is not confirmed.
}
