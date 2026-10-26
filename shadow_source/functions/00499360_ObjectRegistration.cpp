// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499360
// Canonical corpus name: ObjectRegistration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectRegistration_00499360.c

void UnknownObject::ObjectRegistration()
{
    // Registers a new object a2 into a parent-owned linked list. Stores the parent pointer into a2[39], then dispatches to MultiRegionOffsetAccumulationWithVTableDispatch with the parent's offsets at this+0x4 and this+0xC. When the list head at this+0x44 is empty the new object becomes the head; otherwise the tail is found by walking via StructFieldAccessor and the new object is linked in through FieldSetterAt0x8c. The registration counter at this+0x54 is incremented in both branches and a2 is returned.
    // ASSIGNMENT: Store the parent pointer into the new object: a2[39] = this (a2 + 0x9C). [source:raw]
    // CALL: Dispatch to MultiRegionOffsetAccumulationWithVTableDispatch with the new object a2 and the parent offset fields this+0xC (second argument) and this+0x4 (third argument). [callee:0x004869E0, field:this:0x00000004, field:this:0x0000000C, source:raw]
    // GUARD: Branch on the list head at this+0x44: null means the list is empty and the new object becomes the head; non-null means the tail must be located. [field:this:0x00000044, source:raw]
    // LOOP: Walk the non-empty list to its tail: if StructFieldAccessor on the head yields a node, keep following StructFieldAccessor until it returns null. [callee:0x00486320, field:this:0x00000044, source:raw]
    // CALL: Link the new object into the list: FieldSetterAt0x8c writes a2 into the tail node's 0x8C field. [callee:0x00486330, source:raw]
    // STATE_TRANSITION: Increment the registration counter at this+0x54 on the tail-append path. [field:this:0x00000054, source:raw]
    // ASSIGNMENT: Empty-list path: set the head at this+0x44 to a2 and store the incremented counter (this+0x54 + 1) back to this+0x54. [field:this:0x00000044, field:this:0x00000054, source:raw]
    // RETURN: Return the registered object a2 from both the empty-list and tail-append paths. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_499360(int *this, DWORD *a2) {
    //     a2[39] = this;                                  // parent pointer at a2+0x9C
    //     MultiRegionOffsetAccumulationWithVTableDispatch(a2, this[3], this[1]);
    //     if (this[17] != 0) {                            // list head at this+0x44
    //       if (StructFieldAccessor(this[17]) != 0)
    //         do v3 = StructFieldAccessor(v3);
    //         while (StructFieldAccessor(v3) != 0);
    //       FieldSetterAt0x8c(v3, a2);                    // link tail 0x8C -> a2
    //       ++this[21];                                   // counter at this+0x54
    //       return a2;
    //     }
    //     this[17] = a2;
    //     this[21] = this[21] + 1;
    //     return a2;
    //   }
    // UNRESOLVED: The meaning of the parent offsets this+0x4 and this+0xC passed to MultiRegionOffsetAccumulationWithVTableDispatch (interpreted as coordinate offsets in prior analysis) depends on the callee and is not verifiable from this packet alone.
    // UNRESOLVED: The node layout traversed by StructFieldAccessor and the 0x8C field written by FieldSetterAt0x8c are not evidenced in this packet; their exact structure is supplied by the callees.
}
