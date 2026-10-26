// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00519375
// Canonical corpus name: VertexBufferOffsetSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexBufferOffsetSetup_00519375.c

void UnknownObject::VertexBufferOffsetSetup()
{
    // Allocates and populates two parallel vertex-buffer offset arrays (start and end offsets) hanging off an output descriptor, one entry per animation/render element. Reserves the array storage up front via a vtable allocation call sized by element count, then loops the element descriptors, deriving each element's byte span from its width, a stride field and a divisor, allocating per-element sub-buffer space and recording start/end offsets. Called by MediaBufferAlloc.
    // ASSIGNMENT: Load the output descriptor (this+0x180) into v1 and the divisor (this+0x114) into v2. [field:this:0x00000180, field:this:0x00000114]
    // CALL: Call the allocation function through the vtable at this+0x4 with (this, 1, 8 * element count), reserving the offset-array storage. [field:this:0x00000004, field:*(this+0x4):0x00000000, field:this:0x00000020]
    // ASSIGNMENT: Seed loop counter to 0, store the allocated base at out+0x38 and the end pointer (base + 4 * element count) at out+0x3C of the output descriptor. [field:*(this+0x180):0x00000038, field:*(this+0x180):0x0000003C, field:this:0x00000020]
    // GUARD: Only iterate when the element count at this+0x20 is greater than 0; otherwise return the count unchanged. [guard:0, field:this:0x00000020]
    // LOOP: Walk the element descriptor array at this+0xC4 starting at descriptor+0xC, advancing 21 dwords (84 bytes) per element. [field:this:0x000000C4, field:*(this+0xC4):0x0000000C]
    // CALCULATION: Per element compute span v6 = width * stride / this+0x114 * (divisor + 4) and v9 = width * stride / this+0x114, where width is at descriptor+0xC and stride at descriptor+0x24. [field:*(this+0xC4):0x0000000C, field:*(this+0xC4):0x00000024, field:this:0x00000114]
    // CALL: Call the allocation function through the vtable at this+0x4 again with (this, 1, 8 * span) and add 4 * v9 to obtain this element's buffer start offset. [field:this:0x00000004, field:*(this+0x4):0x00000000]
    // ASSIGNMENT: Write the element start offset into the out+0x38 array at index counter, and the element end offset (start + 4 * span) into the out+0x3C array at the same index; increment the counter. [field:*(this+0x180):0x00000038, field:*(this+0x180):0x0000003C]
    // CALCULATION: Advance the element pointer by 21 dwords; the loop terminates once the counter reaches the element count at this+0x20. [field:this:0x00000020]
    // RETURN: Return the final element counter value. [source:raw]

    // Conservative worker pseudocode:
    //   int VertexBufferOffsetSetup(int this) {
    //     int out = *(int*)(this + 384);
    //     int divisor = *(int*)(this + 276);
    //     int base = (**(int(__cdecl***)(int,int,int))(this + 4))(this, 1, 8 * *(int*)(this + 32));
    //     int counter = 0;
    //     *(int*)(out + 56) = base;
    //     *(int*)(out + 60) = base + 4 * *(int*)(this + 32);
    //     if (*(int*)(this + 32) > 0) {
    //       int* elem = (int*)(*(int*)(this + 196) + 12);
    //       do {
    //         int width = elem[0];
    //         int stride = elem[6];
    //         int v9 = width * stride / divisor;
    //         int span = v9 * (divisor + 4);
    //         int start = (**(int(__cdecl***)(int,int,int))(this + 4))(this, 1, 8 * span) + 4 * v9;
    //         *(int*)(4 * counter + *(int*)(out + 56)) = start;
    //         *(int*)(4 * counter + *(int*)(out + 60)) = start + 4 * span;
    //         counter += 1;
    //         elem += 21;
    //       } while (counter < *(int*)(this + 32));
    //     }
    //     return counter;
    //   }
    // UNRESOLVED: Meaning of the this+0x114 divisor and of the width/stride element fields is inferred only from arithmetic shape; exact units unknown.
    // UNRESOLVED: The allocation-call semantics (what 8 * size and the second argument 1 select) depend on the vtable implementation at this+0x4.
    // UNRESOLVED: The (divisor + 4) factor in the span computation is a raw product of the decompiled expression, not a confirmed layout constant.
}
