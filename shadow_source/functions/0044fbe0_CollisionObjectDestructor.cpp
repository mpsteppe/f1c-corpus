// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044FBE0
// Canonical corpus name: CollisionObjectDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionObjectDestructor_0044fbe0.c

void UnknownObject::CollisionObjectDestructor()
{
    // Releases a held object. Unconditionally zeroes the version/count field at this+0x2F4, then, if the object pointer at this+0x80 is non-null, calls its vtable method at offset +0x20, calls its vtable method at offset +0x8, and clears the pointer at this+0x80 to null. Returns the value of the last vtable +0x8 call.
    // ASSIGNMENT: result = this[32], i.e. read the object pointer stored at this+0x80. [field:this:0x00000080]
    // ASSIGNMENT: this[189] = 0, i.e. zero the field at this+0x2F4 unconditionally. [field:this:0x000002F4]
    // GUARD: If the object pointer at this+0x80 (result) is non-null, proceed with the release calls; otherwise skip the block. [field:this:0x00000080]
    // CALL: Call the object's vtable method at offset +0x20 on the object at this+0x80 (indirect stdcall call). [field:*(this+0x80):0x00000020]
    // CALL: Call the object's vtable method at offset +0x8 on this[32] (indirect stdcall call); its result is stored into result. [field:*(this+0x80):0x00000008]
    // ASSIGNMENT: this[32] = 0, i.e. clear the object pointer at this+0x80 to null. [field:this:0x00000080]
    // RETURN: Return result, the return value of the vtable +0x8 call (or the original pointer if the guard failed). [field:this:0x00000080, source:raw]

    // Conservative worker pseudocode:
    //   result = this[32];            // this+0x80
    //   this[189] = 0;                // this+0x2F4
    //   if (result) {
    //       result->vtable[+0x20](result);
    //       result = this[32]->vtable[+8](this[32]);
    //       this[32] = 0;
    //   }
    //   return result;
    // UNRESOLVED: Owner object is unknown; the canonical name suggests a collision object while the existing analysis interprets the vtable release as a Direct3D device (unacquire at +0x20, Release at +0x8).
    // UNRESOLVED: Semantics of the fields at this+0x2F4 and the object at this+0x80 are not confirmed.
}
