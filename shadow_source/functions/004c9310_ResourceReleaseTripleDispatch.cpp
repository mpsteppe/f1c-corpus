// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9310
// Canonical corpus name: ResourceReleaseTripleDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceReleaseTripleDispatch_004c9310.c

void UnknownObject::ResourceReleaseTripleDispatch()
{
    // Dispatches the vtable+8 (third-slot) method on up to three sub-objects held at this+0x20, this+0x24 and this+0x28. Each non-null slot is dispatched in order; the third dispatch's result is returned directly, otherwise the last executed dispatch result is returned. Unlike a destructor, it never nulls or frees the slot pointers.
    // GUARD: Read the first sub-object pointer from this+0x20; dispatch only proceeds when it is non-null. [field:this:0x00000020, source:raw]
    // CALL: Call the vtable+8 (third-slot) method of the first sub-object and keep its return value as result. [field:*(this+0x20):0x00000008, source:raw]
    // GUARD: Read the second sub-object pointer from this+0x24; dispatch only proceeds when it is non-null. [field:this:0x00000024, source:raw]
    // CALL: Call the vtable+8 (third-slot) method of the second sub-object and keep its return value as result. [field:*(this+0x24):0x00000008, source:raw]
    // GUARD: Read the third sub-object pointer from this+0x28; dispatch only proceeds when it is non-null. [field:this:0x00000028, source:raw]
    // CALL: Call the vtable+8 (third-slot) method of the third sub-object; its return value is returned directly. [field:*(this+0x28):0x00000008, source:raw]
    // RETURN: Return the last executed dispatch result: from the third slot when non-null, otherwise from the second or first, otherwise an uninitialized value. [function:0x004C9310, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C9310(void **this) {
    //     if (this[8])  result = (*(void (**)(void *))(*((void **)this[8]) + 8))(this[8]);
    //     if (this[9])  result = (*(void (**)(void *))(*((void **)this[9]) + 8))(this[9]);
    //     if (this[10]) return (*(void (**)(void *))(*((void **)this[10]) + 8))(this[10]);
    //     return result;
    //   }
    // UNRESOLVED: The concrete vtable+8 (third-slot) method of each sub-object is an indirect call resolved at runtime; its identity and resource-releasing semantics are unknown from this packet.
    // UNRESOLVED: This function never releases ownership by nulling the slots; who owns the pointers after dispatch is unknown.
    // UNRESOLVED: result can be read uninitialized when all three slots are null.
}
