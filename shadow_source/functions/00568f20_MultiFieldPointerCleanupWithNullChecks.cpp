// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00568F20
// Canonical corpus name: MultiFieldPointerCleanupWithNullChecks
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldPointerCleanupWithNullChecks_00568f20.c

void UnknownObject::MultiFieldPointerCleanupWithNullChecks()
{
    // Destructor-style cleanup: frees up to four owned pointers (this+0x0, this+0x230, this+0x238, this+0x240) via FreeWrapper_7bcf when non-null and nulls them, and unconditionally zeroes the companion dwords this+0x224, this+0x228, this+0x22C, this+0x234, this+0x23C. Returns the nulled pointer formerly at this+0x240. No globals; invoked from ShortComputation_8e30 on the frame path.
    // GUARD: Guard: if the first pointer field at this+0x0 is non-null, proceed to free it. [field:this:0x00000000, source:raw]
    // CALL: Free the object referenced by this+0x0 via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the first pointer field: this+0x0 = 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Load v2 = this+0x230 and unconditionally zero the three dwords this+0x224, this+0x228, this+0x22C. [field:this:0x00000230, field:this:0x00000224, field:this:0x00000228, field:this:0x0000022C, source:raw]
    // GUARD: Guard: if v2 (pointer at this+0x230) is non-null, proceed to free it. [field:this:0x00000230, source:raw]
    // CALL: Free v2 via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the pointer field: this+0x230 = 0. [field:this:0x00000230, source:raw]
    // ASSIGNMENT: Load v3 = this+0x238 and unconditionally zero this+0x234. [field:this:0x00000238, field:this:0x00000234, source:raw]
    // GUARD: Guard: if v3 (pointer at this+0x238) is non-null, proceed to free it. [field:this:0x00000238, source:raw]
    // CALL: Free v3 via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the pointer field: this+0x238 = 0. [field:this:0x00000238, source:raw]
    // ASSIGNMENT: Load result = this+0x240 and unconditionally zero this+0x23C. [field:this:0x00000240, field:this:0x0000023C, source:raw]
    // GUARD: Guard: if result (pointer at this+0x240) is non-null, proceed to free it. [field:this:0x00000240, source:raw]
    // CALL: Free result via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Null the pointer field: this+0x240 = 0. [field:this:0x00000240, source:raw]
    // CALL: Invoked from ShortComputation_8e30 during its per-frame processing. [caller:0x00568E30]
    // RETURN: Return result (the now-null pointer formerly at this+0x240). [function:0x00568F20, source:raw]

    // Conservative worker pseudocode:
    //   void *MultiFieldPointerCleanupWithNullChecks(int this) {
    //     if (*(void **)this) { FreeWrapper_7bcf(*(void **)this); *(void **)this = 0; }
    //     v2 = *(void **)(this + 560);
    //     *(_DWORD *)(this + 548) = 0; *(_DWORD *)(this + 552) = 0; *(_DWORD *)(this + 556) = 0;
    //     if (v2) { FreeWrapper_7bcf(v2); *(void **)(this + 560) = 0; }
    //     v3 = *(void **)(this + 568); *(_DWORD *)(this + 564) = 0;
    //     if (v3) { FreeWrapper_7bcf(v3); *(void **)(this + 568) = 0; }
    //     result = *(void **)(this + 576); *(_DWORD *)(this + 572) = 0;
    //     if (result) { result = FreeWrapper_7bcf(result); *(void **)(this + 576) = 0; }
    //     return result;
    //   }
    // UNRESOLVED: Each freed pointer (this+0x0, +0x230, +0x238, +0x240) pairs with a preceding dword that is zeroed unconditionally (+0x224, +0x234, +0x23C); the pairing suggests handle/count records, but the owning class and the meaning of the zeroed dwords are not established.
    // UNRESOLVED: The DERIVED prelabel 'ctor_init' is contradicted by the raw source: this frees owned pointers and clears fields (cleanup), not construction.
    // UNRESOLVED: The return value is the nulled pointer formerly at this+0x240; no caller-consumed meaning is evident from the packet.
}
