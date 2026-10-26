// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418D60
// Canonical corpus name: DestructorWithDoubleFreePattern
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithDoubleFreePattern_00418d60.c

void UnknownObject::DestructorWithDoubleFreePattern()
{
    // Thiscall destructor-like cleanup for a pointer container. If the byte flag at this+0x8 is non-zero and the data block *this is non-null, frees the first internal pointer stored in *v3, then frees the data block v3 itself. If a2 bit 0 is set, additionally frees the container this. Returns this. Called by NameListBuilderFromVehicleArray, sub_45D730, and HTMLOutputSectionProcessor.
    // GUARD: Guard on byte flag at this+0x8; cleanup path only runs when it is non-zero. [field:this:0x00000008]
    // ASSIGNMENT: Load the data block pointer v3 = *this. [field:this:0x00000000]
    // GUARD: Guard on v3 (the data block) being non-null before freeing its contents. [field:obj:0x00000000, source:raw]
    // GUARD: Guard on the first internal pointer *v3 being non-null before freeing it. [field:obj:0x00000000, source:raw]
    // CALL: Free the first internal pointer *v3 via FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000000]
    // CALL: Free the data block v3 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000000]
    // GUARD: Guard on a2 bit 0; the container itself is only freed when it is set. [source:raw]
    // CALL: Free the container this via FreeWrapper_7bcf when a2 bit 0 is set. [callee:0x00587BCF]
    // RETURN: Return the container pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_418D60(LPVOID **this, char a2) {
    //     if (*((_BYTE *)this + 8)) {
    //       LPVOID *v3 = *this;
    //       if (v3) {
    //         if (*v3) FreeWrapper_7bcf(*v3);
    //         FreeWrapper_7bcf(v3);
    //       }
    //     }
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Element type of the pointer container and the meaning of the internal pointer *v3 are unknown.
    // UNRESOLVED: Whether the double-free pattern is intended (bit 0 of a2 freeing the container after its contents were freed) depends on the caller contract.
}
