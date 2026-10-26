// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553980
// Canonical corpus name: ObjectConstructorWithAllocationAndSubInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithAllocationAndSubInit_00553980.c

void UnknownObject::ObjectConstructorWithAllocationAndSubInit()
{
    // stdcall constructor for a 36-byte heap object. Allocates via OperatorNewNhMallocWrapper(36), zero-initializes it through ObjectAllocationWithZeroInit (falling back to null on allocation failure), then conditionally configures it: sub_553370(v6, a2) when a2 is nonzero, SetterWrites0x10Returns0(v6, a3) when a3 is nonzero, TwoFieldSetter_3630(v6, a4, a5) unconditionally, and sub_55C2A0(v6) as a post-init hook. If the output pointer a1 is nonzero, stores the constructed object there; returns 0.
    // CALL: OperatorNewNhMallocWrapper(36) allocates the 36-byte object. [callee:0x00587C03]
    // GUARD: If the allocation returned a pointer, v6 becomes the zero-initialized object; otherwise v6 is null. [source:raw]
    // CALL: ObjectAllocationWithZeroInit(v5) zero-initializes the new object's memory (first field at offset 0 included). [callee:0x005532A0, field:this:0x00000000]
    // GUARD: sub_553370(v6, a2) runs only when the a2 parameter is nonzero. [callee:0x00553370]
    // CALL: sub_553370(v6, a2) sets a sub-object field from parameter a2. [callee:0x00553370]
    // GUARD: SetterWrites0x10Returns0(v6, a3) runs only when the a3 parameter is nonzero. [callee:0x00553620]
    // CALL: SetterWrites0x10Returns0(v6, a3) writes a3 into the object's field at offset 0x10. [callee:0x00553620]
    // CALL: TwoFieldSetter_3630(v6, a4, a5) unconditionally sets two fields of the object from a4 and a5. [callee:0x00553630]
    // CALL: sub_55C2A0(v6) performs post-initialization finalization on the constructed object. [callee:0x0055C2A0]
    // GUARD: If the a1 output pointer is nonzero, the constructed object pointer is written through it. [source:raw]
    // ASSIGNMENT: Store the constructed object pointer v6 into *a1. [source:raw]
    // RETURN: Function always returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   int ObjectConstructorWithAllocationAndSubInit(unsigned int** a1, int a2, int a3, int a4, int a5) {
    //     unsigned int* obj = OperatorNewNhMallocWrapper(36);
    //     if (obj) obj = ObjectAllocationWithZeroInit(obj);
    //     if (a2) sub_553370(obj, a2);
    //     if (a3) SetterWrites0x10Returns0(obj, a3);
    //     TwoFieldSetter_3630(obj, a4, a5);
    //     sub_55C2A0(obj);
    //     if (a1) *a1 = obj;
    //     return 0;
    //   }
    // UNRESOLVED: The exact meaning of fields written by sub_553370, SetterWrites0x10Returns0, and TwoFieldSetter_3630 depends on their callees; only the field at offset 0x10 is named by SetterWrites0x10Returns0.
    // UNRESOLVED: Field this+0x0 is evidenced only through the zero-initialization path and the conditional setters; the raw body performs no direct store to offset 0x0.
    // UNRESOLVED: Global dword_8B78A0 is listed in the packet but does not appear in this function's raw body; it is likely read by one of the callees.
    // UNRESOLVED: Object identity (which heap object this constructs) is unknown; the owner is not established.
}
