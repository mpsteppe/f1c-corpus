// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCD10
// Canonical corpus name: ResourceCleanup_cd10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceCleanup_cd10_004dcd10.c

void UnknownObject::ResourceCleanup_cd10()
{
    // Dual-resource cleanup: if secondary resource pointer at this+0x4 is non-null, run its destructor (clearing a free flag) then, after re-checking non-null, call an empty stub and free the pointer. If primary resource pointer at this+0x0 is non-null, run cascade cleanup on it. Returns the result of a computation helper on this.
    // ASSIGNMENT: Load secondary resource pointer stored at this+0x4. [field:this:0x00000004]
    // GUARD: If secondary resource pointer is non-null, enter destructor/free sequence. [field:this:0x00000004, source:raw]
    // CALL: Run DestructorWithConditionalFreeFlagClear on secondary resource pointer. [callee:0x005502C0]
    // GUARD: Re-load this+0x4 and check it is still non-null before free sequence. [field:this:0x00000004, source:raw]
    // CALL: Call EmptyStub_7470 with the secondary resource pointer. [callee:0x00557470]
    // CALL: Call FreeWrapper_7bcf to free the secondary resource pointer. [callee:0x00587BCF]
    // GUARD: If primary resource pointer at this+0x0 is non-null, run cascade cleanup. [field:this:0x00000000, source:raw]
    // CALL: Call ResourceCascadeCleanup on the primary resource pointer. [callee:0x005539F0]
    // RETURN: Return the result of the computation helper called on this. [source:raw, function:0x004DCD10]

    // Conservative worker pseudocode:
    //   p = this->secondary;
    //   if (p) { DestructorWithConditionalFreeFlagClear(p); if (this->secondary) { EmptyStub_7470(this->secondary); FreeWrapper_7bcf(this->secondary); } }
    //   if (this->primary) ResourceCascadeCleanup(this->primary);
    //   return Computation(this);
    // UNRESOLVED: Final return calls a computation helper named ShortComputation_cb70 in the raw source, but no corresponding callee evidence reference exists in the packet; the helper's identity and purpose are unverified.
    // UNRESOLVED: Purpose of the EmptyStub_7470 call within the free sequence is unclear.
}
