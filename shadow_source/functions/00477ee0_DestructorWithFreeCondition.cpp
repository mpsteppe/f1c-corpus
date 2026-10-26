// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477EE0
// Canonical corpus name: DestructorWithFreeCondition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithFreeCondition_00477ee0.c

void UnknownObject::DestructorWithFreeCondition()
{
    // Destructor: if the pointer at this+0x158 is non-null, free that inner buffer with FreeWrapper_7bcf; run ConditionalDualCleanup on the sub-objects at this+0x124 and this+0xE0; run base cleanup via sub_485EB0(this); then, if the flag parameter a2 has bit 0 set, free the instance itself. Returns this.
    // GUARD: If the pointer at this+0x158 is non-null, free the inner heap buffer. [field:this:0x00000158]
    // CALL: Free the heap buffer stored at this+0x158 via FreeWrapper_7bcf. [field:this:0x00000158, callee:0x00587BCF]
    // CALL: Run ConditionalDualCleanup on the sub-object at this+0x124 (first paired-allocation sub-object). [source:raw, callee:0x00499B50]
    // CALL: Run ConditionalDualCleanup on the sub-object at this+0xE0 (second paired-allocation sub-object). [source:raw, callee:0x00499B50]
    // CALL: Run base/container cleanup by calling sub_485EB0 on the instance. [callee:0x00485EB0]
    // GUARD: If flag parameter a2 has bit 0 set, free the instance itself. [source:raw]
    // CALL: Free the instance via FreeWrapper_7bcf when a2 bit 0 is set. [callee:0x00587BCF]
    // RETURN: Return the instance pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   int DestructorWithFreeCondition(int this, char a2) {
    //     if (*(_DWORD *)(this + 344))
    //       FreeWrapper_7bcf(*(LPVOID *)(this + 344));
    //     ConditionalDualCleanup((_DWORD *)(this + 292));
    //     ConditionalDualCleanup((_DWORD *)(this + 224));
    //     sub_485EB0((LPVOID *)this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf((LPVOID)this);
    //     return this;
    //   }
    // UNRESOLVED: Semantics and type of the two paired-allocation sub-objects at this+0x124 and this+0xE0 are not separately evidenced in this packet (no field evidence refs for them).
    // UNRESOLVED: Caller of this destructor is unknown statically; the a2 flag's broader meaning (delete-this behavior) is only the decompiler-visible bit test.
    // UNRESOLVED: Semantics of sub_485EB0 base cleanup are unknown beyond being called on this.
}
