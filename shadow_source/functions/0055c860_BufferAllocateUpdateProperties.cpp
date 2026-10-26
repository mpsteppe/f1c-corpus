// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C860
// Canonical corpus name: sub_55C860
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55C860_0055c860.c

void UnknownObject::BufferAllocateUpdateProperties()
{
    // Allocates a 64-byte buffer through BufferLockAllocate, copies caller-supplied data (a3, a4, a5) into it, then drives a sequence of vtable-backed property updates on the owning UI object. Conditionally initializes the 0x13C4 state flag to 1 and, at the end, calls the vtable entry at 0x8C when the ready flag at 0x1550 is zero.
    // CALL: Initialize the local v12 buffer via StructInitWithDefaultValues before it is used as a multi-field payload. [callee:0x00553DB0]
    // CALL: Allocate a 64-byte buffer with BufferLockAllocate(this, *(this+0x1140), 64, 0, 2), using the stored buffer handle at this+0x1140. [callee:0x00540F00, field:this:0x00001140]
    // ASSIGNMENT: Copy caller data into the freshly allocated buffer: a3[0] and a3[1] to slots 0 and 1, a5 to slots 4 and 11, and a4[0] and a4[1] to slots 7 and 8. [source:raw]
    // CALL: Call ArithmeticComparison_0f90(this, *(this+4416)) against the same buffer handle the allocation used. [callee:0x00540F90]
    // GUARD: If the ready flag at this+0x1550 is zero, invoke vtable entry 136 (offset 0x88) to obtain a handle and store its result at this. [field:*(*(this+0x1100)+0x0):0x00000088, field:this:0x00001550]
    // CALL: Resolve the property owner through this+0x1100 and its vtable at offset 0, then call vtable entry 200 (offset 0xC8) with arguments (7, 0), storing the result at this. [field:this:0x00001100, field:*(this+0x1100):0x00000000, field:*(*(this+0x1100)+0x0):0x000000C8, field:this:0x00000000]
    // ASSIGNMENT: Zero local v12 slot 8 and dispatch it with MultiFieldSetterDispatchingTo7SubSetters on the object region at this+4472. [callee:0x005546A0]
    // CALL: Call sub_554790(this, 256, 0, 0) as part of the property update sequence. [callee:0x00554790]
    // GUARD: Guard on this+0x13C4 not equal to 1: when not yet initialized, call vtable entry 200 with (136, 1) and set this+0x13C4 to 1. [guard:0, field:this:0x000013C4, field:*(*(this+0x1100)+0x0):0x000000C8]
    // CALL: Call PropertyValueSetterWithRefreshOnChange(this, *(this+4416)) to apply the updated property value. [callee:0x00554700]
    // CALL: Call vtable entry 280 (offset 0x118) with (2, 0, 1) storing the result at this, read the stored value at this+0x13B8, then call vtable entry 200 with (7, that value). [field:*(*(this+0x1100)+0x0):0x00000118, field:this:0x000013B8, field:this:0x00000000]
    // GUARD: If the ready flag at this+0x1550 is zero, invoke vtable entry 140 (offset 0x8C), store its result at this, and return it. [field:*(*(this+0x1100)+0x0):0x0000008C, field:this:0x00001550, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   int BufferAllocateUpdateProperties(int a2, DWORD* a3, DWORD* a4, int a5) {
    //     DWORD payload[16]; StructInitWithDefaultValues(payload);
    //     DWORD* buf = BufferLockAllocate(this, *(this+0x1140), 64, 0, 2);
    //     buf[0]=a3[0]; buf[1]=a3[1]; buf[4]=a5; buf[7]=a4[0]; buf[8]=a4[1]; buf[11]=a5;
    //     ArithmeticComparison_0f90(this, *(this+4416));
    //     if (*(this+0x1550) == 0) *(int*)this = VTable(this+0x1100)->entry136(*(this+4352));
    //     *(int*)this = VTable(this+0x1100)->entry200(*(this+4352), 7, 0);
    //     payload[8]=0; MultiFieldSetterDispatchingTo7SubSetters(this+4472, payload, 0);
    //     sub_554790(this, 256, 0, 0);
    //     if (*(this+0x13C4) != 1) { VTable(this+0x1100)->entry200(*(this+4352), 136, 1); *(this+0x13C4)=1; }
    //     PropertyValueSetterWithRefreshOnChange(this, *(this+4416));
    //     int v = *(this+0x13B8);
    //     *(int*)this = VTable(this+0x1100)->entry280(*(this+4352), 2, 0, 1);
    //     *(int*)this = VTable(this+0x1100)->entry200(*(this+4352), 7, v);
    //     if (*(this+0x1550) == 0) { int r = VTable(this+0x1100)->entry140(*(this+4352)); *(int*)this = r; return r; }
    //   }
    // UNRESOLVED: Meaning of the vtable slots (offsets 0x88, 0x8C, 0xC8, 0x118 on the sub-struct at this+0x1100) is not established; they appear to be property get/set hooks but their exact roles are unknown.
    // UNRESOLVED: Semantics of the 64-byte buffer layout (which slots correspond to which caller properties) is unverified.
    // UNRESOLVED: The two this+0x1550 checks are near-identical; whether one is a duplicated decompiler artifact or two genuinely distinct branches is unclear.
}
