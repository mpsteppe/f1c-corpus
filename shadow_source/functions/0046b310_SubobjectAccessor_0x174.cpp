// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046B310
// Canonical corpus name: sub_46B310
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46B310_0046b310.c

void UnknownObject::SubobjectAccessor_0x174()
{
    // Trivial offset accessor: returns a pointer 372 bytes (0x174) into the object referenced by this. No calls, field metadata, globals, or guards are present in this packet, so the referenced sub-object's type and purpose are unknown. The legacy ABI label Offset_Accessor is consistent with this behavior.
    // CALCULATION: Pointer arithmetic: add the constant byte offset 372 (0x174) to the this pointer. [abi:lead, function:0x0046B310, source:raw]
    // RETURN: Return the computed pointer this + 0x174. [function:0x0046B310, source:raw]

    // Conservative worker pseudocode:
    //   char* __thiscall sub_46B310(char* this) {
    //     return this + 0x174;
    //   }
    // UNRESOLVED: The packet provides no field evidence for offset 0x174; the sub-object type and the meaning of the 372-byte displacement are unknown.
    // UNRESOLVED: The Offset_Accessor ABI label is a legacy, low-trust naming with no prototype; it confirms accessor shape but not the field semantics.
}
