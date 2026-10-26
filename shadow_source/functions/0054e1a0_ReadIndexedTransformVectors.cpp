// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054E1A0
// Canonical corpus name: IndexedTransformRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedTransformRead_0054e1a0.c

void UnknownObject::ReadIndexedTransformVectors()
{
    // Bounds-checked reader that copies three 3-vector (three dword) values from an indexed array into the optional output pointers a3/a4/a5. Guarded by a2 < this[72] (element count); each 36-byte entry at this[73] + 36*a2 holds three 16-bit sub-indices and a base pointer used to reach a 48-byte-stride transform array. Returns a5 when in bounds, otherwise the untouched a2.
    // GUARD: Guard on a2 < this[72] (element count at this+0x120); when it fails, all output pointers are left unchanged and a2 is returned. [field:this:0x00000120, source:raw]
    // CALCULATION: Locate the indexed entry v6 = this[73] + 36*a2; the entry supplies three WORD sub-indices and a DWORD base pointer. [field:this:0x00000124, source:raw]
    // CALCULATION: Resolve the transform element for the first sub-index: address = *(*(v6+2*4) + 12) + 48 * v6[0], a 48-byte-stride array access. [source:raw]
    // GUARD: Guard on output pointer a3 being non-null. [source:raw]
    // ASSIGNMENT: Copy three dwords (one vector) from the first resolved element into a3[0..2]. [source:raw]
    // CALCULATION: Resolve the transform element for the second sub-index v6[1] using the same base pointer and 48-byte stride. [source:raw]
    // GUARD: Guard on output pointer a4 being non-null. [source:raw]
    // ASSIGNMENT: Copy three dwords (one vector) from the second resolved element into a4[0..2]. [source:raw]
    // CALCULATION: Resolve the transform element for the third sub-index v6[2] using the same base pointer and 48-byte stride. [source:raw]
    // GUARD: Guard on output pointer a5 being non-null. [source:raw]
    // ASSIGNMENT: Copy three dwords (one vector) from the third resolved element into a5[0..2]. [source:raw]
    // RETURN: Return a5 when the outer bounds guard passed (the return value was set to a5), otherwise the original a2. [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_54E1A0(int* this, int index, int* out1, int* out2, int* out3) {
    //     if (index < this[72]) {
    //       unsigned short* entry = (unsigned short*)(this[73] + 36*index);
    //       int* base = *(int*)(*(int*)(((int*)entry)[2]) + 12);
    //       if (out1) { int* p = (int*)(base + 48*entry[0]); out1[0]=p[0]; out1[1]=p[1]; out1[2]=p[2]; }
    //       if (out2) { int* p = (int*)(base + 48*entry[1]); out2[0]=p[0]; out2[1]=p[1]; out2[2]=p[2]; }
    //       if (out3) { int* p = (int*)(base + 48*entry[2]); out3[0]=p[0]; out3[1]=p[1]; out3[2]=p[2]; }
    //       return out3;
    //     }
    //     return (void*)index;
    //   }
    // UNRESOLVED: Semantics of the three vectors (e.g. position/rotation/scale) are unconfirmed; existing analysis suggests a bone/transform lookup consumed by AnimationPlaybackSequence (0x0044ACB0).
    // UNRESOLVED: Layout of the 36-byte entry and of the 48-byte-stride element beyond the exercised sub-indices and base pointer is unknown.
    // UNRESOLVED: No callee evidence is present in the packet, so the transform source object is fully opaque.
}
