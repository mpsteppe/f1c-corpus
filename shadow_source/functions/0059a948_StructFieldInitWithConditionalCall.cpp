// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A948
// Canonical corpus name: StructFieldInitWithConditionalCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldInitWithConditionalCall_0059a948.c

void UnknownObject::StructFieldInitWithConditionalCall()
{
    // Constructor/initializer: computes v3 as the pointer to this+0x8 and, guarded on v3 being non-null, calls LocaleRefcountAcquireUnderLock(v3); then writes the six dword fields at offsets 0x8, 0xC, 0x10, 0x14, 0x18 and 0x1C to the literals 0, 513, 6, 0, 0 and 0 respectively; finally returns sub_59A5FE(a2, 0, 0). ABI lead name Initialize_struct_fields_at_offsets_0x08_to_0x1c.
    // CALCULATION: Compute v3 as a1 + 8, a dword pointer into this at offset 0x8. [field:this:0x00000008, source:raw]
    // GUARD: Guard on v3 (this+0x8) being non-null before acquiring the locale refcount; since v3 derives from the this pointer a1 the check always passes in practice. [field:this:0x00000008, callee:0x00598C1C, source:raw]
    // CALL: When the guard passes, call LocaleRefcountAcquireUnderLock(v3) with the pointer at this+0x8. [callee:0x00598C1C, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the dword at this+0x8 (a1[2]) to 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the dword at this+0xC (a1[3]) to 513. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write the dword at this+0x10 (a1[4]) to 6. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write the dword at this+0x14 (a1[5]) to 0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write the dword at this+0x18 (a1[6]) to 0. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write the dword at this+0x1C (a1[7]) to 0. [field:this:0x0000001C, source:raw]
    // CALL: Call sub_59A5FE with arguments a2, 0, 0. [callee:0x0059A5FE, source:raw]
    // RETURN: Return the result of sub_59A5FE(a2, 0, 0). [callee:0x0059A5FE, source:raw]

    // Conservative worker pseudocode:
    //   int StructFieldInitWithConditionalCall(_DWORD* a1, int a2) {
    //     _DWORD* v3 = a1 + 8;
    //     if (v3) LocaleRefcountAcquireUnderLock(v3);
    //     a1[2] = 0;
    //     a1[3] = 513;
    //     a1[4] = 6;
    //     a1[5] = 0;
    //     a1[6] = 0;
    //     a1[7] = 0;
    //     return sub_59A5FE(a2, 0, 0);
    //   }
    // UNRESOLVED: The object whose locale refcount is acquired at this+0x8, and why the dword is re-zeroed immediately after the acquire, is unknown.
    // UNRESOLVED: sub_59A5FE's contract is not in the packet; it is called with a2, 0, 0 and its return value becomes this function's result.
    // UNRESOLVED: The literal 513 at this+0xC and the literal 6 at this+0x10 are likely flag/state values; their meanings are not established.
    // UNRESOLVED: Owner is unknown; the raw source has no this-carrying class evidence beyond the __usercall a1 pointer.
    // UNRESOLVED: Both callers (ObjectInitWithVTableFlagSet, StreamCreationWithFlagInit) are recorded but their construction context is not in the packet.
}
