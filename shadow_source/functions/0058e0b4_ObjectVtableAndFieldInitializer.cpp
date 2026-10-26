// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E0B4
// Canonical corpus name: TwoFieldInitializer_e0b4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldInitializer_e0b4_0058e0b4.c

void UnknownObject::ObjectVtableAndFieldInitializer()
{
    // Constructor-style initializer for a C++ object: stores the vtable/function-pointer block address unk_5E7810 at offset +80 and sets the dword field at offset +20 to 1, then returns the object pointer unchanged. No guards. Invoked by TLSAllocationThreadIDInit (0058e060) and TLSValueRetrievalWithInit (0058e0c7).
    // ASSIGNMENT: *(a1 + 80) = &unk_5E7810 installs the vtable/function-pointer block address into the object at offset +0x50 [field:this:0x00000050, global:0x005E7810, source:raw]
    // ASSIGNMENT: *(a1 + 20) = 1 sets the dword field at offset +0x14 to the literal 1 [field:this:0x00000014, source:raw]
    // RETURN: Returns a1, the initialized object pointer (constructor idiom) [source:raw]
    // CALL: Invoked by TLSAllocationThreadIDInit (0058e060) and TLSValueRetrievalWithInit (0058e0c7) during thread/TLS object setup [caller:0x0058E060, caller:0x0058E0C7]

    // Conservative worker pseudocode:
    //   *(a1 + 80) = &unk_5E7810;
    //   *(a1 + 20) = 1;
    //   return a1;
    // UNRESOLVED: The object type and the exact meaning of the field at offset +0x14 (set to 1) are unknown; interpreted as a state flag or count on the basis of the literal
    // UNRESOLVED: Whether unk_5E7810 is a genuine C++ vtable or a plain function-pointer block is unconfirmed; the packet only records that its address is stored at +0x50
}
