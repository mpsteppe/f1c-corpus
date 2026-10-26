// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004034D0
// Canonical corpus name: ObjectReleaseArrayIterator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectReleaseArrayIterator_004034d0.c

void UnknownObject::ReleaseSubObjectArray()
{
    // Releases the sub-object array referenced by this[77] (field 0x134). If the pointer is non-null, reads the element count from the dword 4 bytes before the array, iterates backward over count elements (316-byte stride) calling EmptyStub_0170 on each, then frees the allocation base via FreeWrapper_7bcf. Both branches zero the count field (this+0x130) and the pointer field (this+0x134). Returns 0.
    // GUARD: If this[77] (array pointer at field 0x134) is non-null, proceed with array release. [field:this:0x00000134, source:raw]
    // CALCULATION: Read the element count from the dword at array_ptr minus 4 and compute the last element address as array_ptr plus count times 316. [field:this:0x00000134, source:raw]
    // LOOP: Iterate backward over count elements, decrementing by the 316-byte stride and calling EmptyStub_0170 on each element. [callee:0x004B0170, field:this:0x00000134, source:raw]
    // CALL: Free the sub-object array allocation base (array_ptr minus 4) via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the pointer field this+0x134 and the count field this+0x130 after releasing the array. [field:this:0x00000134, field:this:0x00000130, source:raw]
    // GUARD: If this[77] is null, skip the array release and only zero the count and pointer fields. [field:this:0x00000134, source:raw]
    // RETURN: Return 0. [function:0x004034D0, source:raw]

    // Conservative worker pseudocode:
    //   ptr = this[77];
    //   if (ptr) {
    //     count = *(int*)(ptr - 4);
    //     cur = ptr + 316 * count;
    //     while (count-- > 0) { cur -= 316; EmptyStub_0170(cur); }
    //     FreeWrapper_7bcf(ptr - 4);
    //   }
    //   this[77] = 0;
    //   this[76] = 0;
    //   return 0;
    // UNRESOLVED: The element type (316-byte stride) and the meaning of the dword stored 4 bytes before the array are not evidenced by the packet.
    // UNRESOLVED: EmptyStub_0170 is a decompiler-named stub; whether it performs per-element teardown is not evidenced by this function alone.
}
