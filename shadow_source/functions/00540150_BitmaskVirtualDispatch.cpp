// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540150
// Canonical corpus name: BitmaskVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitmaskVirtualDispatch_00540150.c

void UnknownObject::BitmaskVirtualDispatch()
{
    // Bitmask-based virtual dispatch to surface accessors. Selects among three sub-object pointers of a1 based on the lower three bits of a selector (a3, or a1+0x18 when a3 is 0): bit 1 selects a1+0x8, bit 2 selects a1+0xC, and bit 4 dispatches through a1+0x10. A non-null result from the bit-1/bit-2 path is called through its vtable entry at offset 40; the bit-4 path calls the vtable[17] entry of a1+0x10 with a2 as an argument. Called by ArgumentReorderWrapper_3230 (00543230).
    // ASSIGNMENT: result initialized to a3 and v4 low byte to a3; if a3 is 0, v4 is reloaded from the default selector field at a1+0x18 [field:this:0x00000018, source:raw]
    // GUARD: When bit 1 of v4 is set, result = the direct pointer at a1+0x8 [field:this:0x00000008, source:raw]
    // GUARD: When bit 2 of v4 is set (and bit 1 clear), result = the second sub-object pointer at a1+0xC [field:this:0x0000000C, source:raw]
    // CALL: If the bit-1/bit-2 result is non-null, call its vtable entry at offset 40 (vtable[10]) with the result pointer itself as the only argument; the call return replaces result [field:*(*(this+0xC)+0x0):0x00000028, field:*(this+0xC):0x00000000, source:raw]
    // GUARD: When bit 4 of v4 is set, dispatch via the third sub-object at a1+0x10: call its vtable entry at offset 68 (vtable[17]) with a1+0x10 as this and a2 as the forwarded argument, and return the result [field:*(*(this+0x10)+0x0):0x00000044, field:*(this+0x10):0x00000000, field:this:0x00000010, source:raw]
    // RETURN: Fallthrough path: return the (possibly null, possibly vtable-call-derived) result when bit 4 is clear [function:0x00540150, source:raw]
    // CALL: Invoked by ArgumentReorderWrapper_3230 (00543230) as the selected surface accessor [caller:0x00543230, source:raw]

    // Conservative worker pseudocode:
    //   result = a3;
    //   v4 = a3;
    //   LOBYTE(v4) = a3;
    //   if (a3 == 0) v4 = *(a1 + 24);
    //   if (v4 & 1) {
    //     result = *(a1 + 8);
    //   } else if (v4 & 2) {
    //     result = *(a1 + 12);
    //   }
    //   if (result) result = (*(int(**)(int))(*(_DWORD*)result + 40))(result);
    //   if (v4 & 4)
    //     return (*(int(**)(_DWORD,int))(*(*(_DWORD**)(a1 + 16)) + 68))(*(_DWORD*)(a1 + 16), a2);
    //   return result;
    // UNRESOLVED: The owner type is unknown; the three sub-object pointers at a1+0x8, a1+0xC and a1+0x10 are only known as vtable-bearing objects, not as a named class
    // UNRESOLVED: Why the selector is reduced to its low byte (LOBYTE(v4)) and how the lower-3-bit mask corresponds to a documented surface bitfield is not determinable from this packet
    // UNRESOLVED: The vtable[17] dispatch re-reads the a1+0x10 pointer rather than using the prior result variable; whether that reflects two distinct objects or a decompiler artifact is unresolved
}
