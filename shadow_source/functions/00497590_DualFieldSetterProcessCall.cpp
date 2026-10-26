// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497590
// Canonical corpus name: DualFieldSetterProcessCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldSetterProcessCall_00497590.c

void UnknownObject::DualFieldSetterProcessCall()
{
    // Initializer/finalizer helper: writes the __thiscall receiver pointer into a2 + 0x40 and argument a3 into a2 + 0x98, then passes a2 to ObjectRegistration (0x00499360) and returns its result. Callers/callees suggest a setup step that registers an object after filling two of its fields.
    // ASSIGNMENT: Store the receiver pointer this into the dword at a2 + 0x40. [source:raw]
    // ASSIGNMENT: Store argument a3 into the dword at a2 + 0x98. [source:raw]
    // CALL: Call ObjectRegistration(a2) and return its result. [callee:0x00499360, source:raw]
    // RETURN: Return the ObjectRegistration result. [callee:0x00499360, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_497590(void *this, void *a2, int a3, int a4) {
    //     *(void **)((char *)a2 + 0x40) = this;
    //     *(int *)((char *)a2 + 0x98) = a3;
    //     return ObjectRegistration(a2);
    //   }
    // UNRESOLVED: The object layout of a2 (fields at 0x40 and 0x98) and the meaning of the stored values are not known from this packet; a4 is unused in the raw body.
    // UNRESOLVED: The semantics of ObjectRegistration and the identity of the registered object type are caller/callee context not established here.
}
