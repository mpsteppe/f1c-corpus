// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054C190
// Canonical corpus name: BitClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitClear_0054c190.c

void UnknownObject::BitClear()
{
    // Clears the low two flag bits (bit 1, value 0x2, and bit 2, value 0x4) of the flag dword at this+0x3C by AND-ing it with 0xFFFFFFF9. Unconditional thiscall with no guards and no callees; runs on the frame path and is dispatched per element by two caller objects.
    // ASSIGNMENT: AND the flag dword at this+0x3C with mask 0xFFFFFFF9, clearing flag bits 1 (0x2) and 2 (0x4). [field:this:0x0000003C, source:raw]
    // CALL: Invoked on the frame path by sub_4A3390 and PerElementConditionalActionDispatcher (0x004A34A0), which dispatch this per-element clear. [caller:0x004A3390, caller:0x004A34A0]

    // Conservative worker pseudocode:
    //   void __thiscall BitClear(DWORD* this) {
    //     this[15] &= 0xFFFFFFF9;
    //   }
    // UNRESOLVED: The owning class is unknown; packet marks owner as UnknownObject/UNKNOWN.
    // UNRESOLVED: The meaning of the two cleared flag bits (which state they reset) is not evidenced by the packet.
    // UNRESOLVED: The skeleton fill notes the field at this+0x3C is recalculated every frame; that persistence claim is not independently verified here.
}
