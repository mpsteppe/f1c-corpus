// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C91D0
// Canonical corpus name: TripleVTableDestructorRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleVTableDestructorRelease_004c91d0.c

void UnknownObject::TripleVTableDestructorRelease()
{
    // Releases up to three vtable-based sub-objects held at this+0x20, this+0x24 and this+0x28. For each non-null slot, calls the sub-object's vtable[0] method with flag 1 (Release-like final release), then nulls the slot pointer. Returns the result of the last executed release; result is never written when all three slots are null.
    // GUARD: Read the first sub-object pointer from this+0x20; release only proceeds when it is non-null. [field:this:0x00000020, source:raw]
    // CALL: Call vtable[0] of the first sub-object with flag 1 (Release with final-release flag) and keep its return value as result. [field:*(this+0x20):0x00000000, source:raw]
    // ASSIGNMENT: Null the first slot at this+0x20 after releasing it. [field:this:0x00000020, source:raw]
    // GUARD: Read the second sub-object pointer from this+0x24; release only proceeds when it is non-null. [field:this:0x00000024, source:raw]
    // CALL: Call vtable[0] of the second sub-object with flag 1 (Release) and keep its return value as result. [field:*(this+0x24):0x00000000, source:raw]
    // ASSIGNMENT: Null the second slot at this+0x24 after releasing it. [field:this:0x00000024, source:raw]
    // GUARD: Read the third sub-object pointer from this+0x28; release only proceeds when it is non-null. [field:this:0x00000028, source:raw]
    // CALL: Call vtable[0] of the third sub-object with flag 1 (Release) and keep its return value as result. [field:*(this+0x28):0x00000000, source:raw]
    // ASSIGNMENT: Null the third slot at this+0x28 after releasing it. [field:this:0x00000028, source:raw]
    // RETURN: Return the last vtable release result; the single static caller is sub_4C9060. [function:0x004C91D0, caller:0x004C9060, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C91D0(void **this) {
    //     if (this[8])  { result = (*(void (**)(void *, int))this[8][0])(this[8], 1);  this[8] = 0; }
    //     if (this[9])  { result = (*(void (**)(void *, int))this[9][0])(this[9], 1);  this[9] = 0; }
    //     if (this[10]) { result = (*(void (**)(void *, int))this[10][0])(this[10], 1); this[10] = 0; }
    //     return result;
    //   }
    // UNRESOLVED: The concrete vtable[0] target of each sub-object is an indirect call resolved at runtime; the Release implementations themselves are unknown from this packet.
    // UNRESOLVED: The meaning of the flag argument 1 passed to vtable[0] (assumed final-release flag) is inferred from the destructor context, not proven.
    // UNRESOLVED: result is read uninitialized when all three slots are null; the caller's tolerance for that path is unknown.
}
